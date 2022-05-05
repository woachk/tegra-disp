/*
 * SPDX-FileCopyrightText: Copyright (c) 1993-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/******************************************************************************
*
*   Description:
*       This module contains contextDma implementation.
*
******************************************************************************/

#include "core/core.h"
#include "gpu/gpu.h"
#include "gpu/mem_mgr/mem_mgr.h"
#include "gpu/mem_mgr/virt_mem_allocator_common.h"
#include "gpu/mem_mgr/context_dma.h"
#include "memdesc.h"
#include "gpu/disp/disp_objs.h"
#include "gpu/disp/disp_channel.h"
#include "gpu/disp/inst_mem/disp_inst_mem.h"
#include "os/os.h"
#include "gpu_mgr/gpu_mgr.h"
#include "vgpu/rpc.h"
#include "gpu/device/device.h"
#include "gpu/subdevice/subdevice.h"
#include "rmapi/rs_utils.h"
#include "rmapi/mapping_list.h"

#include "ctrl/ctrl0002.h"

static NV_STATUS _ctxdmaConstruct(ContextDma *pContextDma, RsClient *, NvHandle, NvU32, NvU32, RsResourceRef *, NvU64, NvU64);
static NV_STATUS _ctxdmaDestruct(ContextDma *pContextDma, NvHandle hClient);
static void _ctxdmaDestroyBindings(RsClient *pClient, ContextDma *pContextDma, OBJGPU *pGpu);

NV_STATUS
ctxdmaConstruct_IMPL
(
    ContextDma                      *pContextDma,
    CALL_CONTEXT                    *pCallContext,
    RS_RES_ALLOC_PARAMS_INTERNAL    *pParams
)
{
    NV_STATUS                         status;
    NV_CONTEXT_DMA_ALLOCATION_PARAMS *pAllocParams = pParams->pAllocParams;
    NvU32                             cachesnoop, type, i;
    NvBool                            bReadOnly;
    RsResourceRef                    *pMemoryRef;
    NvHandle                          hParentFromMemory;
    RsClient                         *pClient = pCallContext->pClient;
    NvHandle                          hSubDevice = pAllocParams->hSubDevice;
    NvU32                             hClass = pParams->externalClassId;
    NvU32                             flags = pAllocParams->flags;
    NvU64                             offset = pAllocParams->offset;
    NvU64                             limit = pAllocParams->limit;

    status = clientGetResourceRef(pClient, pAllocParams->hMemory, &pMemoryRef);
    if (status != NV_OK)
        return status;

    hParentFromMemory = pMemoryRef->pParentRef ? pMemoryRef->pParentRef->hResource : 0;

    if (RES_GET_PARENT_HANDLE(pContextDma) != hParentFromMemory)
        return NV_ERR_INVALID_OBJECT_PARENT;

    // validate the flags
    switch (flags >> DRF_SHIFT(NVOS03_FLAGS_ACCESS) & DRF_MASK(NVOS03_FLAGS_ACCESS))
    {
        case NVOS03_FLAGS_ACCESS_WRITE_ONLY:
            // we don't currently have a need to distinguish write-only
            // permissions; fall through to read/write

        case NVOS03_FLAGS_ACCESS_READ_WRITE:
            bReadOnly = NV_FALSE;
            break;

        case NVOS03_FLAGS_ACCESS_READ_ONLY:
            bReadOnly = NV_TRUE;
            break;

        default:
            return NV_ERR_INVALID_FLAGS;
    }

    switch (DRF_VAL(OS03, _FLAGS, _CACHE_SNOOP, flags))
    {
        case NVOS03_FLAGS_CACHE_SNOOP_ENABLE:
            cachesnoop = NV_TRUE;
            break;

        case NVOS03_FLAGS_CACHE_SNOOP_DISABLE:
            cachesnoop = NV_FALSE;
            break;

        default:
            return NV_ERR_INVALID_FLAGS;
    }

    /*
     * Note that the NV_OS03_FLAGS_MAPPING is an alias to xg
     * the LSB of the NV_OS03_FLAGS_TYPE. And in fact if
     * type is NV_OS03_FLAGS_TYPE_NOTIFIER (bit 20 set)
     * then it implicitly means that NV_OS03_FLAGS_MAPPING
     * is _MAPPING_KERNEL. If the client wants to have a
     * Kernel Mapping, it should use the _MAPPING_KERNEL
     * flag set and the _TYPE_NOTIFIER should be used only
     * with NOTIFIERS.
     */
    type = DRF_VAL(OS03, _FLAGS, _MAPPING, flags);

    // fill in dmaInfo
    pContextDma->Flags                = flags;
    pContextDma->bReadOnly            = bReadOnly;
    pContextDma->CacheSnoop           = cachesnoop;
    pContextDma->Type                 = type;
    pContextDma->Limit                = limit;

    for (i = 0; i < NV_ARRAY_ELEMENTS32(pContextDma->KernelVAddr); i++)
        pContextDma->KernelVAddr[i]   = NULL;

    pContextDma->KernelPriv           = NULL;

    for (i = 0; i < NV_ARRAY_ELEMENTS32(pContextDma->FbAperture); i++)
    {
        pContextDma->FbAperture[i]    = (NvU64)-1;
        pContextDma->FbApertureLen[i] = 0;
    }

    for (i = 0; i < NV_ARRAY_ELEMENTS32(pContextDma->Instance); i++)
    {
        pContextDma->Instance[i]      = 0;
        pContextDma->InstRefCount[i]  = 0;
    }

    pContextDma->pMemDesc             = NULL;
    pContextDma->AddressSpace = ADDR_UNKNOWN;

    // Display context dmas have always been explicitly bound.
    if (DRF_VAL(OS03, _FLAGS, _HASH_TABLE, flags) == NVOS03_FLAGS_HASH_TABLE_ENABLE)
    {
        NV_PRINTF(LEVEL_ERROR, "HASH_TABLE=ENABLE no longer supported!\n");
        return NV_ERR_INVALID_FLAGS;
    }

    status = _ctxdmaConstruct(pContextDma, pClient, hSubDevice, hClass,
                              flags, pMemoryRef, offset, limit);

    if (status == NV_OK)
        refAddDependant(pMemoryRef, RES_GET_REF(pContextDma));

    return status;
}

void
ctxdmaDestruct_IMPL
(
    ContextDma *pContextDma
)
{
    _ctxdmaDestruct(pContextDma, RES_GET_CLIENT_HANDLE(pContextDma));
}

/*!
 * NOTE: this control call may be called at high IRQL with LOCK_BYPASS on WDDM.
 */
NV_STATUS
ctxdmaCtrlCmdUpdateContextdma_IMPL
(
    ContextDma                           *pContextDma,
    NV0002_CTRL_UPDATE_CONTEXTDMA_PARAMS *pUpdateCtxDmaParams
)
{
    RsClient  *pClient = RES_GET_CLIENT(pContextDma);
    OBJGPU    *pGpu;
    KernelDisplay *pKernelDisplay;
    DisplayInstanceMemory *pInstMem;
    NvU64     *pNewAddress = NULL;
    NvU64     *pNewLimit = NULL;
    NvHandle   hMemory = NV01_NULL_OBJECT;
    NvU32      comprInfo;
    NV_STATUS  status = NV_OK;

    //
    // Validate that if hCtxDma is passed in it is the same as the hCtxDma
    // used for the top level RmControl hObject
    //
    if (pUpdateCtxDmaParams->hCtxDma != NV01_NULL_OBJECT)
        NV_ASSERT_OR_RETURN(pUpdateCtxDmaParams->hCtxDma == RES_GET_HANDLE(pContextDma), NV_ERR_INVALID_OBJECT);

    if (pUpdateCtxDmaParams->hSubDevice != NV01_NULL_OBJECT)
    {
        Subdevice *pSubdevice;

        NV_CHECK_OK_OR_RETURN(LEVEL_SILENT,
            subdeviceGetByHandle(pClient, pUpdateCtxDmaParams->hSubDevice, &pSubdevice));

        // Ensure requested hSubDevice is valid for the GPU associated with this contextdma
        NV_CHECK_OR_RETURN(LEVEL_ERROR, pSubdevice->pDevice == pContextDma->pDevice, NV_ERR_INVALID_OBJECT_HANDLE);

        pGpu = GPU_RES_GET_GPU(pSubdevice);
        GPU_RES_SET_THREAD_BC_STATE(pSubdevice);
    }
    else
    {
        pGpu = pContextDma->pGpu;
        gpuSetThreadBcState(pGpu, !pContextDma->bUnicast);
    }

    pKernelDisplay = GPU_GET_KERNEL_DISPLAY(pGpu);
    if (pKernelDisplay == NULL)
        return NV_ERR_GENERIC;

    if (FLD_TEST_DRF(0002_CTRL_CMD, _UPDATE_CONTEXTDMA, _FLAGS_BASEADDRESS, _VALID, pUpdateCtxDmaParams->flags))
        pNewAddress = &pUpdateCtxDmaParams->baseAddress;
    if (FLD_TEST_DRF(0002_CTRL_CMD, _UPDATE_CONTEXTDMA, _FLAGS_LIMIT, _VALID, pUpdateCtxDmaParams->flags))
        pNewLimit = &pUpdateCtxDmaParams->limit;
    if (FLD_TEST_DRF(0002_CTRL_CMD, _UPDATE_CONTEXTDMA, _FLAGS_HINT, _VALID, pUpdateCtxDmaParams->flags))
        hMemory = pUpdateCtxDmaParams->hintHandle;


    comprInfo = DRF_VAL(0002_CTRL_CMD, _UPDATE_CONTEXTDMA_FLAGS, _USE_COMPR_INFO, pUpdateCtxDmaParams->flags);

    SLI_LOOP_START(SLI_LOOP_FLAGS_BC_ONLY)
    pKernelDisplay = GPU_GET_KERNEL_DISPLAY(pGpu);
    pInstMem = KERNEL_DISPLAY_GET_INST_MEM(pKernelDisplay);

    status = instmemUpdateContextDma_HAL(pGpu, pInstMem, pContextDma,
                                         pNewAddress, pNewLimit, hMemory, comprInfo);
    NV_ASSERT(status == NV_OK);

    SLI_LOOP_END

    return status;
}

static NV_STATUS
_ctxdmaDestruct
(
    ContextDma *pContextDma,
    NvHandle    hClient
)
{
    RsClient  *pClient = RES_GET_CLIENT(pContextDma);
    NV_STATUS  rmStatus = NV_OK;
    OBJGPU    *pGpu = NULL;

    pGpu = pContextDma->pGpu;
    NV_ASSERT_OR_RETURN(pGpu != NULL, NV_WARN_NULL_OBJECT);
    gpuSetThreadBcState(pGpu, !pContextDma->bUnicast);

    if (pContextDma->bUnicast || RES_GET_PARENT_HANDLE(pContextDma) == RES_GET_HANDLE(pContextDma->pDevice))
    {
        //
        // vGPU:
        //
        // Since vGPU does all real hardware management in the
        // host, if we are in guest OS (where IS_VIRTUAL(pGpu) is true),
        // do an RPC to the host to do the hardware update.
        //
        if ((IS_VIRTUAL(pGpu) &&
             (!(IS_VIRTUAL_WITH_SRIOV(pGpu) && (!gpuIsWarBug200577889SriovHeavyEnabled(pGpu))))))
        {
            NV_RM_RPC_FREE(pGpu, hClient, RES_GET_HANDLE(pContextDma->pMemory), RES_GET_HANDLE(pContextDma), rmStatus);
        }
    }

    // Clean-up the context, first unbind from display
    _ctxdmaDestroyBindings(pClient, pContextDma, pGpu);

    // Handle unicast sysmem mapping mapping before _ctxdmaDestroyFBMappings()
    if (pContextDma->AddressSpace == ADDR_SYSMEM)
    {
        NvU32 gpuDevInst = gpumgrGetSubDeviceInstanceFromGpu(gpumgrGetParentGPU(pGpu));

        if (pContextDma->KernelVAddr[gpuDevInst])
        {
            memdescUnmapOld(pContextDma->pMemory->pMemDesc, NV_TRUE, 0,
                    pContextDma->KernelVAddr[gpuDevInst],
                    pContextDma->KernelPriv);
            pContextDma->KernelVAddr[gpuDevInst] = NULL;
            pContextDma->KernelPriv = NULL;
        }
    }

    // Ideally we'd do all of the below in RmFreeDeviceContextDma when
    // DeviceRefCount goes to 0 but leaving here because RmFreeDeviceContextDma
    // is also called from other places.
    memdescFree(pContextDma->pMemDesc);
    memdescDestroy(pContextDma->pMemDesc);
    pContextDma->pMemDesc = NULL;

    return rmStatus;
}

static void
_ctxdmaDestroyBindings
(
    RsClient       *pClient,
    ContextDma     *pContextDma,
    OBJGPU         *pGpu
)
{
    NV_STATUS       status;
    DispObject     *pDispObject;
    DispChannel    *pDispChannel;
    RS_ITERATOR     channelIt;
    RsResourceRef  *pResourceRef;

    if (!ctxdmaIsBound(pContextDma))
        return;

    status = dispobjGetByDevice(pClient, pContextDma->pDevice, &pDispObject);
    if (status != NV_OK)
        return;

    pResourceRef = RES_GET_REF(pDispObject);

    // Unbind the ctx dma from all disp channels
    channelIt = clientRefIter(pClient, pResourceRef, classId(DispChannel), RS_ITERATE_CHILDREN, NV_FALSE);

    while (clientRefIterNext(channelIt.pClient, &channelIt))
    {
        pDispChannel = dynamicCast(channelIt.pResourceRef->pResource, DispChannel);

        // Make sure we are not bound. Will return an error if not bound.
        (void)dispchnUnbindCtx(pDispChannel, pGpu, pContextDma);
    }
}

/*!
 * NOTE: this control call may be called at high IRQL with LOCK_BYPASS on WDDM.
 */
NV_STATUS
ctxdmaCtrlCmdBindContextdma_IMPL
(
    ContextDma                         *pContextDma,
    NV0002_CTRL_BIND_CONTEXTDMA_PARAMS *pBindCtxDmaParams
)
{
    DispChannel   *pDispChannel = NULL;
    RsClient      *pClient      = RES_GET_CLIENT(pContextDma);
    NvHandle       hChannel     = pBindCtxDmaParams->hChannel;

    gpuSetThreadBcState(pContextDma->pGpu, !pContextDma->bUnicast);

    // Look-up channel given by client
    NV_CHECK_OK_OR_RETURN(LEVEL_ERROR,
        dispchnGetByHandle(pClient, hChannel, &pDispChannel));

    // Ensure ContextDma and DisplayChannel are on the save device
    NV_CHECK_OR_RETURN(LEVEL_ERROR, pContextDma->pDevice == GPU_RES_GET_DEVICE(pDispChannel),
                       NV_ERR_INVALID_DEVICE);

    API_GPU_FULL_POWER_SANITY_CHECK(pContextDma->pGpu, NV_TRUE, NV_FALSE);

    //
    // Call the hal to alloc inst mem, write the ctxdma data, and write
    // the hash table entry.
    //
    NV_CHECK_OK_OR_RETURN(LEVEL_SILENT, dispchnBindCtx(pDispChannel, pContextDma->pGpu, pContextDma));

    return NV_OK;
}

/*!
 * NOTE: this control call may be called at high IRQL with LOCK_BYPASS on WDDM.
 */
NV_STATUS
ctxdmaCtrlCmdUnbindContextdma_IMPL
(
    ContextDma *pContextDma,
    NV0002_CTRL_UNBIND_CONTEXTDMA_PARAMS *pUnbindCtxDmaParams
)
{
    DispChannel   *pDispChannel = NULL;
    RsClient      *pClient      = RES_GET_CLIENT(pContextDma);
    NvHandle       hChannel     = pUnbindCtxDmaParams->hChannel;

    gpuSetThreadBcState(pContextDma->pGpu, !pContextDma->bUnicast);

    // Look-up channel given by client
    NV_CHECK_OK_OR_RETURN(LEVEL_ERROR,
        dispchnGetByHandle(pClient, hChannel, &pDispChannel));

    // Ensure ContextDma and DisplayChannel are on the save device
    NV_CHECK_OR_RETURN(LEVEL_ERROR, pContextDma->pDevice == GPU_RES_GET_DEVICE(pDispChannel),
                       NV_ERR_INVALID_DEVICE);

    API_GPU_FULL_POWER_SANITY_CHECK(pContextDma->pGpu, NV_TRUE, NV_FALSE);

    NV_CHECK_OK_OR_RETURN(LEVEL_SILENT,
        dispchnUnbindCtx(pDispChannel, pContextDma->pGpu, pContextDma));

    return NV_OK;
}

static NV_STATUS
_ctxdmaConstruct
(
    ContextDma    *pContextDma,
    RsClient      *pClient,
    NvHandle       hSubDevice,
    NvU32          hClass,
    NvU32          flags,
    RsResourceRef *pMemoryRef,
    NvU64          offset,
    NvU64          limit
)
{
    NV_STATUS           rmStatus        = NV_OK;
    Memory             *pMemory         = NULL;
    OBJGPU             *pGpu            = NULL;
    MemoryManager      *pMemoryManager  = NULL;
    MEMORY_DESCRIPTOR  *pMemDesc        = NULL;
    NvHandle            hDevice         = 0;
    NvHandle            hClient         = pClient->hClient;
    Device             *pDevice         = NULL;

    pMemory = dynamicCast(pMemoryRef->pResource, Memory);
    if (pMemory == NULL)
        return NV_ERR_INVALID_OBJECT;

    if (hSubDevice != 0)
    {
        pContextDma->bUnicast = NV_TRUE;
        rmStatus = gpuGetByHandle(pClient, hSubDevice, NULL, &pGpu);
        if (rmStatus != NV_OK)
            return rmStatus;
    }
    else
    {
        pContextDma->bUnicast = NV_FALSE;
        pGpu = pMemory->pGpu;
        if (pGpu == NULL)
            return NV_ERR_INVALID_OBJECT_PARENT;
    }

    gpuSetThreadBcState(pGpu, !pContextDma->bUnicast);

    rmStatus = deviceGetByGpu(pClient, pGpu, NV_TRUE, &pDevice);
    if (rmStatus != NV_OK)
        return NV_ERR_INVALID_OBJECT_PARENT;

    pContextDma->pDevice = pDevice;

    hDevice = RES_GET_HANDLE(pDevice);

    API_GPU_FULL_POWER_SANITY_CHECK(pGpu, NV_TRUE, NV_FALSE);

    pMemoryManager = GPU_GET_MEMORY_MANAGER(pGpu);

    pMemDesc = pMemory->pMemDesc;

    //
    // Validate the offset and limit passed in
    // Check end of contextdma is within the memory object which was created (RmAllocMemory)
    // Since "limit" is inclusive, it should be strictly less than the length
    //
    {
        NvU64 combinedLimit;
        if (!portSafeAddU64(offset, limit, &combinedLimit) ||
            (combinedLimit >= pMemory->Length))
        {
            return NV_ERR_INVALID_LIMIT;
        }
    }

    // The destructor expects the following fields in pContextDma to be set,
    // so do not invoke destructor (goto done) before they are assigned.
    pContextDma->pMemory = pMemory;
    pContextDma->pGpu = pGpu;

    pContextDma->AddressSpace = memdescGetAddressSpace(memdescGetMemDescFromGpu(pMemDesc, pGpu));

    // Fail allocation of virtual ContextDmas. These have moved the DynamicMemory.
    if (pContextDma->AddressSpace == ADDR_VIRTUAL)
    {
        return NV_ERR_OBJECT_TYPE_MISMATCH;
    }

    //
    // Create a MEMORY_DESCRIPTOR describing this region of the memory alloc
    // in question
    //
    rmStatus = memdescCreateSubMem(
        &pContextDma->pMemDesc, pMemDesc, pGpu, offset, limit+1);
    if (rmStatus != NV_OK)
        goto done;

    if (pContextDma->AddressSpace == ADDR_SYSMEM)
    {
        if (pContextDma->Type == NVOS03_FLAGS_MAPPING_KERNEL)
        {
            rmStatus = memdescMapOld(
                pMemDesc,
                offset, limit+1, NV_TRUE, NV_PROTECT_READ_WRITE,
                &pContextDma->KernelVAddr[gpumgrGetSubDeviceInstanceFromGpu(gpumgrGetParentGPU(pGpu))],
                &pContextDma->KernelPriv);
            if (rmStatus != NV_OK)
                goto done;
        }
    }

    if (FLD_TEST_DRF(OS03, _FLAGS, _PTE_KIND, _BL, flags))
    {
        memdescSetPteKind(pContextDma->pMemDesc, memmgrGetPteKindBl_HAL(pGpu, pMemoryManager));
    }
    else if (FLD_TEST_DRF(OS03, _FLAGS, _PTE_KIND, _PITCH, flags))
    {
        memdescSetPteKind(pContextDma->pMemDesc, memmgrGetPteKindPitch_HAL(pGpu, pMemoryManager));
    }

done:

    if (rmStatus == NV_OK)
    {
        if (IS_VIRTUAL(pGpu))
        {
            //
            // vGPU:
            //
            // Since vGPU does all real hardware management in the
            // host, if we are in guest OS (where IS_VIRTUAL(pGpu) is true),
            // do an RPC to the host to do the hardware update.
            //
            NV_RM_RPC_ALLOC_CONTEXT_DMA(pGpu, hClient, hDevice, RES_GET_HANDLE(pContextDma), hClass, 
                                        flags, RES_GET_HANDLE(pMemory), offset, limit, rmStatus);
        }
    }

    if (rmStatus != NV_OK)
    {
        memdescDestroy(pContextDma->pMemDesc);
        pContextDma->pMemDesc = NULL;

        _ctxdmaDestruct(pContextDma, hClient);
    }

    return rmStatus;
}

//
// Fetch ContextDma from resource server
//
NV_STATUS
ctxdmaGetByHandle
(
    RsClient      *pClient,
    NvHandle       hContextDma,
    ContextDma   **ppContextDma
)
{
    RsResourceRef *pResourceRef;
    NV_STATUS status;

    *ppContextDma = NULL;

    status = clientGetResourceRef(pClient, hContextDma, &pResourceRef);
    if (status != NV_OK)
    {
        return status;
    }

    *ppContextDma = dynamicCast(pResourceRef->pResource, ContextDma);

    return (*ppContextDma) ? NV_OK : NV_ERR_INVALID_OBJECT_HANDLE;
}

//
// Validate that the range described by Start+Length is within ContextDma
// limits.
//
NV_STATUS
ctxdmaValidate_IMPL
(
    ContextDma   *pContextDma,
    NvU64         Start,
    NvU64         Length
)
{
    if (pContextDma == NULL)
    {
        NV_PRINTF(LEVEL_ERROR, "Invalid DMA context in ctxdmaValidate\n");
        DBG_BREAKPOINT();
        return NV_ERR_INVALID_XLATE;
    }
    DBG_VAL_PTR(pContextDma);

    if ((Start + Length - 1) > pContextDma->Limit)
        return NV_ERR_INVALID_OFFSET;

    return NV_OK;
}

//
// Return the CPU VA of a DMA buffer.
//
NV_STATUS
ctxdmaGetKernelVA_IMPL
(
    ContextDma *pContextDma,
    NvU64       Start,
    NvU64       Length,
    void      **ppAddress,
    NvU32       VA_idx
)
{
    NV_STATUS status;

    if (pContextDma == NULL)
    {
        NV_PRINTF(LEVEL_ERROR, "Invalid DMA context in ctxdmaGetKernelVA\n");
        DBG_BREAKPOINT();
        return NV_ERR_INVALID_XLATE;
    }
    DBG_VAL_PTR(pContextDma);

    status = ctxdmaValidate(pContextDma, Start, Length);
    if (status != NV_OK)
        return status;

    if (pContextDma->KernelVAddr[VA_idx] == NULL)
        return NV_ERR_DMA_MEM_NOT_LOCKED;

    *ppAddress = (NvU8*)pContextDma->KernelVAddr[VA_idx] + Start;

    return NV_OK;
}

// ****************************************************************************
//                            Deprecated Functions
// ****************************************************************************

/**
 * @warning This function is deprecated! Please use ctxdmaGetByHandle.
 */
NV_STATUS
CliGetContextDma
(
    NvHandle       hClient,
    NvHandle       hContextDma,
    ContextDma   **ppContextDma
)
{
    RsClient   *pClient;
    NV_STATUS   status;

    *ppContextDma = NULL;

    status = serverGetClientUnderLock(&g_resServ, hClient, &pClient);
    if (status != NV_OK)
        return NV_ERR_INVALID_CLIENT;

    return ctxdmaGetByHandle(pClient, hContextDma, ppContextDma);
}

NV_STATUS
ctxdmaMapTo_IMPL
(
    ContextDma *pContextDma,
    RS_RES_MAP_TO_PARAMS *pParams
)
{
    OBJGPU            *pGpu = pParams->pGpu;
    MEMORY_DESCRIPTOR *pSrcMemDesc = pParams->pSrcMemDesc;
    NvU64              offset = pParams->offset;

    //
    // For video memory, provide a way to look up the offset of an FB allocation within
    // the given context target context dma.  This is a pre-nv50 legacy behavior, but it
    // is still useful for dFPGA.  It is used by mods.
    //
    if ((memdescGetAddressSpace(memdescGetMemDescFromGpu(pSrcMemDesc, pGpu)) == ADDR_FBMEM) &&
        (memdescGetAddressSpace(memdescGetMemDescFromGpu(pContextDma->pMemDesc, pGpu)) == ADDR_FBMEM))
    {
        RmPhysAddr physaddr;
        if (!memdescGetContiguity(pSrcMemDesc, AT_GPU))
        {
            NV_PRINTF(LEVEL_ERROR, "Cannot obtain the video memory offset of a noncontiguous vidmem alloc!\n");
            return NV_ERR_GENERIC;
        }

        // Return an Big GPU device physical address, if available
        physaddr = memdescGetPhysAddr(pSrcMemDesc, AT_GPU, offset);
        *pParams->pDmaOffset = physaddr - memdescGetPhysAddr(pContextDma->pMemDesc, AT_GPU, 0);
        return NV_OK;
    }

    // We no longer support tracking mappings on ContextDma. Has moved to DynamicMemory.
    return NV_ERR_INVALID_ARGUMENT;
}

NV_STATUS
ctxdmaUnmapFrom_IMPL
(
    ContextDma *pContextDma,
    RS_RES_UNMAP_FROM_PARAMS *pParams
)
{
    //
    // With ContextDmas only supporting physical (or IOMMU VA) there is
    // nothing to unmap. We silently allow this call for compatibility.
    //
    return NV_OK;
}

/*!
 * @brief Is the ContextDma bound to a display channel?
 *
 * This is a fast check to see if a ContextDma is bound to a display channel.
 */
NvBool
ctxdmaIsBound_IMPL
(
    ContextDma *pContextDma
)
{
    NvU32 refs = 0;
    NvU32 i;

    for (i=0; i < NV_MAX_SUBDEVICES; i++)
        refs += pContextDma->InstRefCount[i];

    return refs != 0;
}
