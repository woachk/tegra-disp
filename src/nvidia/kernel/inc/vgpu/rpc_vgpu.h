/* _NVRM_COPYRIGHT_BEGIN_
 *
 * Copyright 2008-2021 by NVIDIA Corporation.  All rights reserved.  All
 * information contained herein is proprietary and confidential to NVIDIA
 * Corporation.  Any use, reproduction, or disclosure without the written
 * permission of NVIDIA Corporation is prohibited.
 *
 * _NVRM_COPYRIGHT_END_
 */

//******************************************************************************
//
//   Declarations for the RPC VGPU module.
//
//   Description:
//       This module declares the RPC interface functions/macros for VGPU.
//
//******************************************************************************

#ifndef __vgpu_dev_nv_rpc_vgpu_h__
#define __vgpu_dev_nv_rpc_vgpu_h__

static NV_INLINE void NV_RM_RPC_ALLOC_LOCAL_USER(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_ALLOC_VIDMEM(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_ALLOC_VIRTMEM(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_MAP_MEMORY(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_UNMAP_MEMORY(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_READ_EDID(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_DMA_FILL_PTE_MEM(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_CREATE_FB_SEGMENT(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_DESTROY_FB_SEGMENT(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_DEFERRED_API_CONTROL(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_REMOVE_DEFERRED_API(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_FREE_VIDMEM_VIRT(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_LOG(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_SET_GUEST_SYSTEM_INFO_EXT(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_GET_ENGINE_UTILIZATION(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_MAP_SEMA_MEMORY(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_UNMAP_SEMA_MEMORY(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_SET_SURFACE_PROPERTIES(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_CLEANUP_SURFACE(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_SWITCH_TO_VGA(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_TDR_SET_TIMEOUT_STATE(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_GET_CONSOLIDATED_STATIC_INFO(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_GET_CONSOLIDATED_GR_STATIC_INFO(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_GET_STATIC_PSTATE_INFO(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_UPDATE_PDE_2(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_TRANSLATE_GUEST_GPU_PTES(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_SET_LICENSE_INFO(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_SET_SEMA_MEM_VALIDATION_STATE(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_RESET_CURRENT_GR_CONTEXT(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_GET_ENCODER_CAPACITY(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_GET_STATIC_INFO2(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_ALLOC_CONTEXT_DMA(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_GET_PLCABLE_ADDRESS_KIND(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_UPDATE_GPU_PDES(OBJGPU *pGpu, ...) { }
static NV_INLINE void NV_RM_RPC_DISABLE_CHANNELS(OBJGPU *pGpu, ...) { }

#endif // __vgpu_dev_nv_rpc_vgpu_h__
