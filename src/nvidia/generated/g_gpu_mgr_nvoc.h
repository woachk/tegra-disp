#ifndef _G_GPU_MGR_NVOC_H_
#define _G_GPU_MGR_NVOC_H_
#include "nvoc/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * SPDX-FileCopyrightText: Copyright (c) 2005-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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
#include "g_gpu_mgr_nvoc.h"

#ifndef _GPUMGR_H_
#define _GPUMGR_H_

//
// GPU Manager Defines and Structures
//

struct OBJGPU;
#include "core/core.h"
#include "core/system.h"
#include "nvlimits.h"
#include "gpu_mgr/gpu_group.h"
#include "gpu/gpu_uuid.h"
#include "gpu/gpu_device_mapping.h"
#include "gpu/gpu_access.h"
#include "ctrl/ctrl0000/ctrl0000gpu.h"
#include "ctrl/ctrl2080/ctrl2080grmgr.h"
#include "nvoc/utility.h"
#include "nv_firmware_types.h"

#include "class/cl2080.h" // NV2080_ENGINE_TYPE_*

#include "utils/nvbitvector.h"
TYPEDEF_BITVECTOR(MC_ENGINE_BITVECTOR);

#define GPUMGR_MAX_GPU_INSTANCES        8
#define GPUMGR_MAX_COMPUTE_INSTANCES    8

MAKE_BITVECTOR(ENGTYPE_BIT_VECTOR, NV2080_ENGINE_TYPE_LAST);
typedef ENGTYPE_BIT_VECTOR *PENGTYPE_BIT_VECTOR;

//
// Terminology:
//    GPU         -> entity sitting on the bus
//    Device      -> broadcast semantics; maps to one or more GPUs
//    Subdevice   -> unicast semantics; maps to a single GPU
//


////////////////////////////////////////////////////////////////////////////////
//                         DO NOT ADD NEW STUBS HERE                          //
////////////////////////////////////////////////////////////////////////////////
#define gpumgrGetGpuLinkCount(deviceInstance)                   ((NvU32) 0)
#define gpumgrGetSliLinkOutputMaskFromGpu(pGpu)                 ((NvU32) 0)
#define gpumgrGetVidLinkOutputMaskFromGpu(pGpu)                 ((NvU32) 0)
#define gpumgrGetSliLinkOrderCount(pGpu)                        ((NvU32) 0)
#define gpumgrGetSliLinkConnectionCount(pGpu)                   ((NvU32) 0)
#define gpumgrGetSLIConfig(gpuInstance, onlyWithSliLink)        ((NvU32) 0)
#define gpumgrDisableVidLink(pGpu, head, max_dr_port)
#define gpumgrGetGpuVidLinkMaxPixelClock(pGpu, pMaxPclkMhz)     (NV_ERR_NOT_SUPPORTED)
#define gpumgrPinsetToPinsetTableIndex(pinset, pPinsetIndex)    (NV_ERR_NOT_SUPPORTED)
#define gpumgrGetBcEnabledStatus(g)                             (NV_FALSE)
#define gpumgrGetBcEnabledStatusEx(g, t)                        (NV_FALSE)
#define gpumgrSetBcEnabledStatus(g, b)                          do { NvBool b2 = b; (void)b2; } while (0)
#define gpumgrSLILoopReentrancy(pGpu, l, r, i, pFuncStr)
#define gpumgrSLILoopReentrancyPop(pGpu)                        ((NvU32)0)
#define gpumgrSLILoopReentrancyPush(pGpu, sliLoopReentrancy)    do { NvU32 x = sliLoopReentrancy; (void)x; } while(0)


typedef struct
{
    NvU32     gpuId;
    NvU64     gpuDomainBusDevice;
    NvBool    bInitAttempted;
    NvBool    bDrainState;  // no new client connections to this GPU
    NvBool    bRemoveIdle;  // remove this GPU once it's idle (detached)
    NvBool    bExcluded;    // this gpu is marked as excluded; do not use
    NvBool    bUuidValid;   // cached uuid is valid
    NvBool    bSkipHwNvlinkDisable; //skip HW registers configuration for disabled links
    NvU32     initDisabledNvlinksMask;
    NV_STATUS initStatus;
    NvU8      uuid[RM_SHA1_GID_SIZE];
    OS_RM_CAPS *pOsRmCaps;    // "Opaque" pointer to os-specific capabilities
} PROBEDGPU;

#define NV_DEVICE_DISPLAY_FLAGS_AFR_FRAME_FLIPS                   11:4
#define NV_DEVICE_DISPLAY_FLAGS_AFR_FRAME_TIME                   12:12
#define NV_DEVICE_DISPLAY_FLAGS_AFR_FRAME_TIME_INVALID       0x0000000
#define NV_DEVICE_DISPLAY_FLAGS_AFR_FRAME_TIME_VALID         0x0000001

/*!
 * Structure for tracking resources allocated for saving primary GPU's VBIOS
 * state.  This is used for TDR/fullchip reset recovery.  The GPU object gets
 * destroyed, so the data belongs here.
 */
typedef struct _def_gpumgr_save_vbios_state
{
    RmPhysAddr vgaWorkspaceVidMemBase;        //<! Base address of the VGA workspace
    struct MEMORY_DESCRIPTOR *pSaveToMemDesc; //<! Where VGA workspace is saved to
    void *pSaveRegsOpaque;                    //<! Saved values of VGA registers
} GPUMGRSAVEVBIOSSTATE, *PGPUMGRSAVEVBIOSSTATE;

//
// types of bridges supported.
// These defines are inices for the types of bridges supported.
// preference for a given bridge type is determined by the lower value index.
// I.E. Video Link has the lower value index, so in the event that both NvLink & video link is
// detected, the video link will be used.
//
#define SLI_MAX_BRIDGE_TYPES    2
#define SLI_BT_VIDLINK          0
#define SLI_BT_NVLINK           1

//
// This is the same as what is maintained in gpu/ce/ce.h
// Make sure to update/match these defines in both the files.
// We had to re-define here instead of using gpu/ce/ce.h directly
// because there were compilation dependencies that prevented us
// from adding gpu/ce/ce.h
//
#define NV_CE_PCE2LCE_CONFIG__SIZE_1_MAX 18
#define NV_CE_GRCE_CONFIG__SIZE_1 2
#define NV_CE_MAX_HSHUBS 5 // Same as GPU_MAX_HSHUBS


typedef struct NVLINK_TOPOLOGY_PARAMS
{
    NvU32   sysmemLinks;
    NvU32   maxLinksPerPeer;
    NvBool  bSymmetric;
    // Pascal only
    NvU32   numLinks;
    // Volta +
    NvU32   numPeers;
    NvBool  bSwitchConfig;
    // Ampere +
    NvU32   pceAvailableMaskPerHshub[NV_CE_MAX_HSHUBS];
    NvU32   maxPceLceMap[NV_CE_PCE2LCE_CONFIG__SIZE_1_MAX];
    NvU32   maxGrceConfig[NV_CE_GRCE_CONFIG__SIZE_1];
    NvU32   maxExposeCeMask;
    NvU32   maxTopoIdx;       // For table configs only; not applicable for algorithm
} NVLINK_TOPOLOGY_PARAMS, *PNVLINK_TOPOLOGY_PARAMS;

typedef struct _def_gpu_nvlink_topology_info
{
    NvBool  valid;
    NvU64   DomainBusDevice;
    NVLINK_TOPOLOGY_PARAMS params;
} NVLINK_TOPOLOGY_INFO, *PNVLINK_TOPOLOGY_INFO;

typedef struct
{
    OBJGPU     *pGpu;
    NvU32       gpuInstance;
} GPU_HANDLE_ID;

struct GPUMGR_SAVE_MIG_INSTANCE_TOPOLOGY;


struct OBJGPUMGR {
    const struct NVOC_RTTI *__nvoc_rtti;
    struct Object __nvoc_base_Object;
    struct Object *__nvoc_pbase_Object;
    struct OBJGPUMGR *__nvoc_pbase_OBJGPUMGR;
    PROBEDGPU probedGpus[32];
    void *probedGpusLock;
    NvU32 gpuAttachCount;
    NvU32 gpuAttachMask;
    NvU32 persistentSwStateGpuMask;
    NvU32 deviceCount;
    struct OBJGPUGRP *pGpuGrpTable[32];
    NvU32 gpuInstMaskTable[32];
    NvU8 gpuBridgeType;
    GPUMGRSAVEVBIOSSTATE primaryVbiosState;
    NvU8 powerDisconnectedGpuCount;
    NvU8 powerDisconnectedGpuBus[32];
    GPU_HANDLE_ID gpuHandleIDList[32];
    NvU32 numGpuHandles;
};

#ifndef __NVOC_CLASS_OBJGPUMGR_TYPEDEF__
#define __NVOC_CLASS_OBJGPUMGR_TYPEDEF__
typedef struct OBJGPUMGR OBJGPUMGR;
#endif /* __NVOC_CLASS_OBJGPUMGR_TYPEDEF__ */

#ifndef __nvoc_class_id_OBJGPUMGR
#define __nvoc_class_id_OBJGPUMGR 0xcf1b25
#endif /* __nvoc_class_id_OBJGPUMGR */

extern const struct NVOC_CLASS_DEF __nvoc_class_def_OBJGPUMGR;

#define __staticCast_OBJGPUMGR(pThis) \
    ((pThis)->__nvoc_pbase_OBJGPUMGR)

#ifdef __nvoc_gpu_mgr_h_disabled
#define __dynamicCast_OBJGPUMGR(pThis) ((OBJGPUMGR*)NULL)
#else //__nvoc_gpu_mgr_h_disabled
#define __dynamicCast_OBJGPUMGR(pThis) \
    ((OBJGPUMGR*)__nvoc_dynamicCast(staticCast((pThis), Dynamic), classInfo(OBJGPUMGR)))
#endif //__nvoc_gpu_mgr_h_disabled


NV_STATUS __nvoc_objCreateDynamic_OBJGPUMGR(OBJGPUMGR**, Dynamic*, NvU32, va_list);

NV_STATUS __nvoc_objCreate_OBJGPUMGR(OBJGPUMGR**, Dynamic*, NvU32);
#define __objCreate_OBJGPUMGR(ppNewObj, pParent, createFlags) \
    __nvoc_objCreate_OBJGPUMGR((ppNewObj), staticCast((pParent), Dynamic), (createFlags))

static inline void gpumgrAddSystemNvlinkTopo(NvU64 DomainBusDevice) {
    return;
}

static inline NvBool gpumgrGetSystemNvlinkTopo(NvU64 DomainBusDevice, struct NVLINK_TOPOLOGY_PARAMS *pTopoParams) {
    return ((NvBool)(0 != 0));
}

static inline void gpumgrUpdateSystemNvlinkTopo(NvU64 DomainBusDevice, struct NVLINK_TOPOLOGY_PARAMS *pTopoParams) {
    return;
}

static inline NV_STATUS gpumgrSetGpuInitDisabledNvlinks(NvU32 gpuId, NvU32 mask, NvBool bSkipHwNvlinkDisable) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NV_STATUS gpumgrGetGpuInitDisabledNvlinks(NvU32 gpuId, NvU32 *pMask, NvBool *pbSkipHwNvlinkDisable) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NvBool gpumgrCheckIndirectPeer(struct OBJGPU *pGpu, struct OBJGPU *pRemoteGpu) {
    return ((NvBool)(0 != 0));
}

static inline void gpumgrAddSystemMIGInstanceTopo(NvU64 domainBusDevice) {
    return;
}

static inline NvBool gpumgrGetSystemMIGInstanceTopo(NvU64 domainBusDevice, struct GPUMGR_SAVE_MIG_INSTANCE_TOPOLOGY **ppTopoParams) {
    return ((NvBool)(0 != 0));
}

static inline void gpumgrUnregisterRmCapsForMIGGI(NvU64 gpuDomainBusDevice) {
    return;
}

static inline void gpumgrUpdateBoardId(struct OBJGPU *arg0) {
    return;
}

static inline void gpumgrServiceInterrupts(NvU32 arg0, MC_ENGINE_BITVECTOR *arg1, NvBool arg2) {
    return;
}

NV_STATUS gpumgrConstruct_IMPL(struct OBJGPUMGR *arg_);
#define __nvoc_gpumgrConstruct(arg_) gpumgrConstruct_IMPL(__staticCast_OBJGPUMGR(arg_))
void gpumgrDestruct_IMPL(struct OBJGPUMGR *arg0);
#define __nvoc_gpumgrDestruct(arg0) gpumgrDestruct_IMPL(__staticCast_OBJGPUMGR(arg0))


typedef struct {
    NvBool         specified;                           // Set this flag when using this struct

    DEVICE_MAPPING deviceMapping[SOC_DEV_MAPPING_MAX];  // Register Aperture mapping
    NvU32          socChipId0;                          // Chip ID used for HAL binding
    NvU32          iovaspaceId;                         // SMMU client ID
} SOCGPUATTACHARG;

//
// Packages up system/bus state for attach process.
//
typedef struct GPUATTACHARG
{
    GPUHWREG   *regBaseAddr;
    GPUHWREG   *fbBaseAddr;
    GPUHWREG   *instBaseAddr;
    RmPhysAddr  devPhysAddr;
    RmPhysAddr  fbPhysAddr;
    RmPhysAddr  instPhysAddr;
    RmPhysAddr  ioPhysAddr;
    NvU64       nvDomainBusDeviceFunc;
    NvU32       regLength;
    NvU64       fbLength;
    NvU32       instLength;
    NvU32       intLine;
    void        *pOsAttachArg;
    NvBool      bIsSOC;
    NvU32       socDeviceCount;
    DEVICE_MAPPING socDeviceMappings[GPU_MAX_DEVICE_MAPPINGS];
    NvU32       socId;
    NvU32       socSubId;
    NvU32       socChipId0;
    NvU32       iovaspaceId;
    NvBool      bRequestFwClientRm;

    //
    // The SOC-specific fields above are legacy fields that were added for
    // ARCH MODS iGPU verification. There is a plan to deprecate these fields as
    // part of an effort to clean up the existing iGPU code in RM.
    //
    // Starting with T234D+, the SOCGPUATTACHARG field below will be used to
    // pass the required attach info for a single SOC device from the RM OS
    // layer to core RM.
    //
    SOCGPUATTACHARG socDeviceArgs;
} GPUATTACHARG;

NV_STATUS   gpumgrGetGpuAttachInfo(NvU32 *pGpuCnt, NvU32 *pGpuMask);
NV_STATUS   gpumgrGetProbedGpuIds(NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS *);
NV_STATUS   gpumgrGetProbedGpuDomainBusDevice(NvU32 gpuId, NvU64 *gpuDomainBusDevice);
NV_STATUS   gpumgrGetAttachedGpuIds(NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS *);
NV_STATUS   gpumgrGetGpuIdInfo(NV0000_CTRL_GPU_GET_ID_INFO_PARAMS *);
NV_STATUS   gpumgrGetGpuIdInfoV2(NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS *);
void        gpumgrSetGpuId(OBJGPU*, NvU32 gpuId);
NV_STATUS   gpumgrGetGpuInitStatus(NV0000_CTRL_GPU_GET_INIT_STATUS_PARAMS *);
void        gpumgrSetGpuInitStatus(NvU32 gpuId, NV_STATUS status);
OBJGPU*     gpumgrGetGpuFromId(NvU32 gpuId);
OBJGPU*     gpumgrGetGpuFromUuid(const NvU8 *pGpuUuid, NvU32 flags);
OBJGPU*     gpumgrGetGpuFromBusInfo(NvU32 domain, NvU8 bus, NvU8 device);
NvU32       gpumgrGetDefaultPrimaryGpu(NvU32 gpuMask);
NV_STATUS   gpumgrAllocGpuInstance(NvU32 *pDeviceInstance);
NV_STATUS   gpumgrRegisterGpuId(NvU32 gpuId, NvU64 gpuDomainBusDevice);
NV_STATUS   gpumgrUnregisterGpuId(NvU32 gpuId);
NV_STATUS   gpumgrExcludeGpuId(NvU32 gpuId);
NV_STATUS   gpumgrSetUuid(NvU32 gpuId, NvU8 *uuid);
NV_STATUS   gpumgrGetGpuUuidInfo(NvU32 gpuId, NvU8 **ppUuidStr, NvU32 *pUuidStrLen, NvU32 uuidFlags);
NV_STATUS   gpumgrAttachGpu(NvU32 deviceInstance, GPUATTACHARG *);
NV_STATUS   gpumgrDetachGpu(NvU32 deviceInstance);
OBJGPU*     gpumgrGetNextGpu(NvU32 gpuMask, NvU32 *pStartIndex);
NV_STATUS   gpumgrStatePreInitGpu(OBJGPU*);
NV_STATUS   gpumgrStateInitGpu(OBJGPU*);
NV_STATUS   gpumgrStateLoadGpu(OBJGPU*, NvU32);
NV_STATUS   gpumgrAllocDeviceInstance(NvU32 *pDeviceInstance);
NV_STATUS   gpumgrCreateDevice(NvU32 *pDeviceInstance, NvU32 gpuMask, NvU32 *pGpuIdsOrdinal);
NV_STATUS   gpumgrDestroyDevice(NvU32 deviceInstance);
NvU32       gpumgrGetDeviceInstanceMask(void);
NvU32       gpumgrGetDeviceGpuMask(NvU32 deviceInstance);
NV_STATUS   gpumgrIsDeviceInstanceValid(NvU32 deviceInstance);
NvU32       gpumgrGetPrimaryForDevice(NvU32 deviceInstance);
NvBool      gpumgrIsSubDeviceInstanceValid(NvU32 subDeviceInstance);
NvBool      gpumgrIsDeviceEnabled(NvU32 deviceInstance);
NvU32       gpumgrGetGpuMask(OBJGPU *pGpu);
OBJGPU*     gpumgrGetGpu(NvU32 deviceInstance);
OBJGPU*     gpumgrGetSomeGpu(void);
NvU32       gpumgrGetSubDeviceCount(NvU32 gpuMask);
NvU32       gpumgrGetSubDeviceCountFromGpu(OBJGPU *pGpu);
NvU32       gpumgrGetSubDeviceMaxValuePlus1(OBJGPU *pGpu);
NvU32       gpumgrGetSubDeviceInstanceFromGpu(OBJGPU *pGpu);
OBJGPU*     gpumgrGetParentGPU(OBJGPU *pGpu);
void        gpumgrSetParentGPU(OBJGPU *pGpu, OBJGPU *pParentGpu);
NvBool      gpumgrIsGpuDisplayParent(OBJGPU*);
OBJGPU*     gpumgrGetDisplayParent(OBJGPU*);
NV_STATUS   gpumgrGetGpuLockAndDrPorts(OBJGPU*, OBJGPU*, NvU32 *, NvU32 *);
NV_STATUS   gpumgrGetBootPrimary(OBJGPU **ppGpu);
OBJGPU*     gpumgrGetMGpu(void);
RmPhysAddr  gpumgrGetGpuPhysFbAddr(OBJGPU*);
OBJGPU*     gpumgrGetGpuFromSubDeviceInst(NvU32, NvU32);
NV_STATUS   gpumgrAddDeviceInstanceToGpus(NvU32 gpuMask);
NV_STATUS   gpumgrRemoveDeviceInstanceFromGpus(NvU32 gpuMask);
NV_STATUS   gpumgrConstructGpuGrpObject(struct OBJGPUMGR *pGpuMgr, NvU32 gpuMask, struct OBJGPUGRP **ppGpuGrp);
struct OBJGPUGRP*  gpumgrGetGpuGrpFromGpu(OBJGPU *pGpu);
struct OBJGPUGRP*  gpumgrGetGpuGrpFromInstance(NvU32 gpugrpInstance);
NV_STATUS   gpumgrModifyGpuDrainState(NvU32 gpuId, NvBool bEnable, NvBool bRemove, NvBool bLinkDisable);
NV_STATUS   gpumgrQueryGpuDrainState(NvU32 gpuId, NvBool *pBEnable, NvBool *pBRemove);
NvBool      gpumgrIsGpuPointerValid(OBJGPU *pGpu);
NvU32       gpumgrGetGrpMaskFromGpuInst(NvU32 gpuInst);
void        gpumgrAddDeviceMaskToGpuInstTable(NvU32 gpuMask);
void        gpumgrClearDeviceMaskFromGpuInstTable(NvU32 gpuMask);
NvBool      gpumgrSetGpuAcquire(OBJGPU *pGpu);
void        gpumgrSetGpuRelease(void);

//
// gpumgrIsSubDeviceCountOne
//
static NV_INLINE NvBool
gpumgrIsSubDeviceCountOne(NvU32 gpuMask)
{
    //
    // A fast version of gpumgrGetSubDeviceCount(gpumask) == 1.
    // Make sure it returns 0 for gpuMask==0, just like gpumgrGetSubDeviceCount(0)!!!
    //
    return gpuMask != 0 && (gpuMask&(gpuMask-1)) == 0;
}

//
// gpumgrIsParentGPU
//
static NV_INLINE NvBool
gpumgrIsParentGPU(OBJGPU *pGpu)
{
    return gpumgrGetParentGPU(pGpu) == pGpu;
}

#endif // _GPUMGR_H_

#ifdef __cplusplus
} // extern "C"
#endif
#endif // _G_GPU_MGR_NVOC_H_
