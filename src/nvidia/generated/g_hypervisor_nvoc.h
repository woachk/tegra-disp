#ifndef _G_HYPERVISOR_NVOC_H_
#define _G_HYPERVISOR_NVOC_H_
#include "nvoc/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * SPDX-FileCopyrightText: Copyright (c) 2014-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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
#include "g_hypervisor_nvoc.h"

#ifndef HYPERVISOR_H
#define HYPERVISOR_H

/**************** Resource Manager Defines and Structures ******************\
*                                                                           *
* Module: hypervisor.h                                                      *
*       Defines and structures used for the hypervisor object.              *
\***************************************************************************/

#include "core/core.h"
#include "nvoc/utility.h"
#include "nv-hypervisor.h"
#include "mem_mgr/mem.h"

#ifdef HAVE_DESIGNATED_INITIALIZERS
#define SFINIT(f, v) f = v
#else
#define SFINIT(f, v) v
#endif

typedef struct OBJHYPERVISOR *POBJHYPERVISOR;

#ifndef __NVOC_CLASS_OBJHYPERVISOR_TYPEDEF__
#define __NVOC_CLASS_OBJHYPERVISOR_TYPEDEF__
typedef struct OBJHYPERVISOR OBJHYPERVISOR;
#endif /* __NVOC_CLASS_OBJHYPERVISOR_TYPEDEF__ */

#ifndef __nvoc_class_id_OBJHYPERVISOR
#define __nvoc_class_id_OBJHYPERVISOR 0x33c1ba
#endif /* __nvoc_class_id_OBJHYPERVISOR */


typedef struct HOST_VGPU_DEVICE HOST_VGPU_DEVICE;

// OPS for different hypervisor operations at runtime

//
// A hypervisor specific function for post detection (after hypervisor type
// has been identified). As the post detection, there could be hypervisor
// specific requirement to detect root/parent/child partition.
//
typedef NV_STATUS (*HypervisorPostDetection)(OBJOS *, NvBool *);

//
// A hypervisor specific function to identify if a hypervisor
// is allowed to run GPUs present in the mask (in: param) under
// PCI-E P2P configuration
//
typedef NvBool (*HypervisorIsPcieP2PSupported)(NvU32);

typedef struct _hypervisor_ops
{
    const char *hypervisorName;
    const char *hypervisorSig;
    HypervisorPostDetection hypervisorPostDetection;
    HypervisorIsPcieP2PSupported hypervisorIsPcieP2PSupported;
} HYPERVISOR_OPS, *PHYPERVISOR_OPS;

struct OBJHYPERVISOR {
    const struct NVOC_RTTI *__nvoc_rtti;
    struct Object __nvoc_base_Object;
    struct Object *__nvoc_pbase_Object;
    struct OBJHYPERVISOR *__nvoc_pbase_OBJHYPERVISOR;
    NvBool bDetected;
    NvBool bIsHVMGuest;
    HYPERVISOR_TYPE type;
    NvBool bIsHypervHost;
    NvBool bIsHypervVgpuSupported;
};

#ifndef __NVOC_CLASS_OBJHYPERVISOR_TYPEDEF__
#define __NVOC_CLASS_OBJHYPERVISOR_TYPEDEF__
typedef struct OBJHYPERVISOR OBJHYPERVISOR;
#endif /* __NVOC_CLASS_OBJHYPERVISOR_TYPEDEF__ */

#ifndef __nvoc_class_id_OBJHYPERVISOR
#define __nvoc_class_id_OBJHYPERVISOR 0x33c1ba
#endif /* __nvoc_class_id_OBJHYPERVISOR */

extern const struct NVOC_CLASS_DEF __nvoc_class_def_OBJHYPERVISOR;

#define __staticCast_OBJHYPERVISOR(pThis) \
    ((pThis)->__nvoc_pbase_OBJHYPERVISOR)

#ifdef __nvoc_hypervisor_h_disabled
#define __dynamicCast_OBJHYPERVISOR(pThis) ((OBJHYPERVISOR*)NULL)
#else //__nvoc_hypervisor_h_disabled
#define __dynamicCast_OBJHYPERVISOR(pThis) \
    ((OBJHYPERVISOR*)__nvoc_dynamicCast(staticCast((pThis), Dynamic), classInfo(OBJHYPERVISOR)))
#endif //__nvoc_hypervisor_h_disabled


NV_STATUS __nvoc_objCreateDynamic_OBJHYPERVISOR(OBJHYPERVISOR**, Dynamic*, NvU32, va_list);

NV_STATUS __nvoc_objCreate_OBJHYPERVISOR(OBJHYPERVISOR**, Dynamic*, NvU32);
#define __objCreate_OBJHYPERVISOR(ppNewObj, pParent, createFlags) \
    __nvoc_objCreate_OBJHYPERVISOR((ppNewObj), staticCast((pParent), Dynamic), (createFlags))

static inline NvBool hypervisorIsVgxHyper_491d52(void) {
    return ((NvBool)(0 != 0));
}

#define hypervisorIsVgxHyper() hypervisorIsVgxHyper_491d52()
#define hypervisorIsVgxHyper_HAL() hypervisorIsVgxHyper()

NV_STATUS hypervisorInjectInterrupt_IMPL(struct OBJHYPERVISOR *arg0, VGPU_NS_INTR *arg1);

#ifdef __nvoc_hypervisor_h_disabled
static inline NV_STATUS hypervisorInjectInterrupt(struct OBJHYPERVISOR *arg0, VGPU_NS_INTR *arg1) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorInjectInterrupt(arg0, arg1) hypervisorInjectInterrupt_IMPL(__staticCast_OBJHYPERVISOR(arg0), arg1)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorInjectInterrupt_HAL(arg0, arg1) hypervisorInjectInterrupt(__staticCast_OBJHYPERVISOR(arg0), arg1)

void hypervisorSetHypervVgpuSupported_IMPL(struct OBJHYPERVISOR *arg0);

#ifdef __nvoc_hypervisor_h_disabled
static inline void hypervisorSetHypervVgpuSupported(struct OBJHYPERVISOR *arg0) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorSetHypervVgpuSupported(arg0) hypervisorSetHypervVgpuSupported_IMPL(__staticCast_OBJHYPERVISOR(arg0))
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorSetHypervVgpuSupported_HAL(arg0) hypervisorSetHypervVgpuSupported(__staticCast_OBJHYPERVISOR(arg0))

NV_STATUS hypervisorSetupGuestVmBusChannel_IMPL(struct OBJHYPERVISOR *arg0, struct OBJGPU *arg1);

#ifdef __nvoc_hypervisor_h_disabled
static inline NV_STATUS hypervisorSetupGuestVmBusChannel(struct OBJHYPERVISOR *arg0, struct OBJGPU *arg1) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorSetupGuestVmBusChannel(arg0, arg1) hypervisorSetupGuestVmBusChannel_IMPL(__staticCast_OBJHYPERVISOR(arg0), arg1)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorSetupGuestVmBusChannel_HAL(arg0, arg1) hypervisorSetupGuestVmBusChannel(__staticCast_OBJHYPERVISOR(arg0), arg1)

void hypervisorDestroyGuestVmBusChannel_IMPL(struct OBJHYPERVISOR *arg0);

#ifdef __nvoc_hypervisor_h_disabled
static inline void hypervisorDestroyGuestVmBusChannel(struct OBJHYPERVISOR *arg0) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorDestroyGuestVmBusChannel(arg0) hypervisorDestroyGuestVmBusChannel_IMPL(__staticCast_OBJHYPERVISOR(arg0))
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorDestroyGuestVmBusChannel_HAL(arg0) hypervisorDestroyGuestVmBusChannel(__staticCast_OBJHYPERVISOR(arg0))

static inline NV_STATUS hypervisorSetupHostVmBusChannel_56cd7a(struct OBJHYPERVISOR *arg0, NvU64 arg1, struct OBJGPU *arg2, HOST_VGPU_DEVICE *arg3) {
    return NV_OK;
}

#ifdef __nvoc_hypervisor_h_disabled
static inline NV_STATUS hypervisorSetupHostVmBusChannel(struct OBJHYPERVISOR *arg0, NvU64 arg1, struct OBJGPU *arg2, HOST_VGPU_DEVICE *arg3) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorSetupHostVmBusChannel(arg0, arg1, arg2, arg3) hypervisorSetupHostVmBusChannel_56cd7a(__staticCast_OBJHYPERVISOR(arg0), arg1, arg2, arg3)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorSetupHostVmBusChannel_HAL(arg0, arg1, arg2, arg3) hypervisorSetupHostVmBusChannel(__staticCast_OBJHYPERVISOR(arg0), arg1, arg2, arg3)

static inline void hypervisorResetHostVmBusChannel_b3696a(struct OBJHYPERVISOR *arg0, HOST_VGPU_DEVICE *arg1) {
    return;
}

#ifdef __nvoc_hypervisor_h_disabled
static inline void hypervisorResetHostVmBusChannel(struct OBJHYPERVISOR *arg0, HOST_VGPU_DEVICE *arg1) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorResetHostVmBusChannel(arg0, arg1) hypervisorResetHostVmBusChannel_b3696a(__staticCast_OBJHYPERVISOR(arg0), arg1)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorResetHostVmBusChannel_HAL(arg0, arg1) hypervisorResetHostVmBusChannel(__staticCast_OBJHYPERVISOR(arg0), arg1)

NV_STATUS hypervisorGuestPinPages_IMPL(struct OBJHYPERVISOR *arg0, MEMORY_DESCRIPTOR *arg1);

#ifdef __nvoc_hypervisor_h_disabled
static inline NV_STATUS hypervisorGuestPinPages(struct OBJHYPERVISOR *arg0, MEMORY_DESCRIPTOR *arg1) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorGuestPinPages(arg0, arg1) hypervisorGuestPinPages_IMPL(__staticCast_OBJHYPERVISOR(arg0), arg1)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorGuestPinPages_HAL(arg0, arg1) hypervisorGuestPinPages(__staticCast_OBJHYPERVISOR(arg0), arg1)

NV_STATUS hypervisorGuestPinPagesUsingPfns_IMPL(struct OBJHYPERVISOR *arg0, NvU32 arg1, NvU64 *arg2);

#ifdef __nvoc_hypervisor_h_disabled
static inline NV_STATUS hypervisorGuestPinPagesUsingPfns(struct OBJHYPERVISOR *arg0, NvU32 arg1, NvU64 *arg2) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorGuestPinPagesUsingPfns(arg0, arg1, arg2) hypervisorGuestPinPagesUsingPfns_IMPL(__staticCast_OBJHYPERVISOR(arg0), arg1, arg2)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorGuestPinPagesUsingPfns_HAL(arg0, arg1, arg2) hypervisorGuestPinPagesUsingPfns(__staticCast_OBJHYPERVISOR(arg0), arg1, arg2)

static inline NV_STATUS hypervisorSendEventToGuest_56cd7a(struct OBJHYPERVISOR *arg0, void *arg1) {
    return NV_OK;
}

#ifdef __nvoc_hypervisor_h_disabled
static inline NV_STATUS hypervisorSendEventToGuest(struct OBJHYPERVISOR *arg0, void *arg1) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorSendEventToGuest(arg0, arg1) hypervisorSendEventToGuest_56cd7a(__staticCast_OBJHYPERVISOR(arg0), arg1)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorSendEventToGuest_HAL(arg0, arg1) hypervisorSendEventToGuest(__staticCast_OBJHYPERVISOR(arg0), arg1)

static inline NV_STATUS hypervisorAllocHostVmbusChannel_56cd7a(struct OBJHYPERVISOR *arg0, HOST_VGPU_DEVICE *arg1) {
    return NV_OK;
}

#ifdef __nvoc_hypervisor_h_disabled
static inline NV_STATUS hypervisorAllocHostVmbusChannel(struct OBJHYPERVISOR *arg0, HOST_VGPU_DEVICE *arg1) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorAllocHostVmbusChannel(arg0, arg1) hypervisorAllocHostVmbusChannel_56cd7a(__staticCast_OBJHYPERVISOR(arg0), arg1)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorAllocHostVmbusChannel_HAL(arg0, arg1) hypervisorAllocHostVmbusChannel(__staticCast_OBJHYPERVISOR(arg0), arg1)

static inline void hypervisorFreeHostVmbusChannel_b3696a(struct OBJHYPERVISOR *arg0, HOST_VGPU_DEVICE *arg1) {
    return;
}

#ifdef __nvoc_hypervisor_h_disabled
static inline void hypervisorFreeHostVmbusChannel(struct OBJHYPERVISOR *arg0, HOST_VGPU_DEVICE *arg1) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorFreeHostVmbusChannel(arg0, arg1) hypervisorFreeHostVmbusChannel_b3696a(__staticCast_OBJHYPERVISOR(arg0), arg1)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorFreeHostVmbusChannel_HAL(arg0, arg1) hypervisorFreeHostVmbusChannel(__staticCast_OBJHYPERVISOR(arg0), arg1)

static inline NV_STATUS hypervisorVmbusHostCompletePacket_56cd7a(struct OBJHYPERVISOR *arg0, NvU64 arg1, HOST_VGPU_DEVICE *arg2) {
    return NV_OK;
}

#ifdef __nvoc_hypervisor_h_disabled
static inline NV_STATUS hypervisorVmbusHostCompletePacket(struct OBJHYPERVISOR *arg0, NvU64 arg1, HOST_VGPU_DEVICE *arg2) {
    NV_ASSERT_FAILED_PRECOMP("OBJHYPERVISOR was disabled!");
    return NV_ERR_NOT_SUPPORTED;
}
#else //__nvoc_hypervisor_h_disabled
#define hypervisorVmbusHostCompletePacket(arg0, arg1, arg2) hypervisorVmbusHostCompletePacket_56cd7a(__staticCast_OBJHYPERVISOR(arg0), arg1, arg2)
#endif //__nvoc_hypervisor_h_disabled

#define hypervisorVmbusHostCompletePacket_HAL(arg0, arg1, arg2) hypervisorVmbusHostCompletePacket(__staticCast_OBJHYPERVISOR(arg0), arg1, arg2)

static inline NvBool hypervisorCheckForAdminAccess(NvHandle hClient, NvU32 rmCtrlId) {
    return ((NvBool)(0 != 0));
}

static inline NvBool hypervisorCheckForObjectAccess(NvHandle hClient) {
    return ((NvBool)(0 != 0));
}

static inline NV_STATUS hypervisorDetection(struct OBJHYPERVISOR *arg0, OBJOS *arg1) {
    return NV_ERR_NOT_SUPPORTED;
}

static inline NvBool hypervisorPcieP2pDetection(struct OBJHYPERVISOR *arg0, NvU32 arg1) {
    return ((NvBool)(0 != 0));
}

static inline HYPERVISOR_TYPE hypervisorGetHypervisorType(struct OBJHYPERVISOR *arg0) {
    return OS_HYPERVISOR_UNKNOWN;
}

static inline NvBool hypervisorIsType(HYPERVISOR_TYPE hyperType) {
    return ((NvBool)(0 != 0));
}

NV_STATUS hypervisorConstruct_IMPL(struct OBJHYPERVISOR *arg_);
#define __nvoc_hypervisorConstruct(arg_) hypervisorConstruct_IMPL(__staticCast_OBJHYPERVISOR(arg_))
void hypervisorDestruct_IMPL(struct OBJHYPERVISOR *arg0);
#define __nvoc_hypervisorDestruct(arg0) hypervisorDestruct_IMPL(__staticCast_OBJHYPERVISOR(arg0))


#endif // HYPERVISOR_H

#ifdef __cplusplus
} // extern "C"
#endif
#endif // _G_HYPERVISOR_NVOC_H_
