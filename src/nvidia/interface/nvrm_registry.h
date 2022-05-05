/*
 * SPDX-FileCopyrightText: Copyright (c) 1997-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

#ifndef NVRM_REGISTRY_H
#define NVRM_REGISTRY_H

#include "nvtypes.h"

//
// Some shared defines with nvReg.h
//
#if defined(NV_UNIX)
#define NV4_REG_GLOBAL_BASE_KEY     ""
#define NV4_REG_GLOBAL_BASE_PATH    "_NV_"
#else
#define NV4_REG_GLOBAL_BASE_KEY     HKEY_LOCAL_MACHINE
#define NV4_REG_GLOBAL_BASE_PATH    "SOFTWARE\\NVIDIA Corporation\\Global"
#endif
#define NV4_REG_SUBKEY                    "NVidia"
#define NV4_REG_DISPLAY_DRIVER_SUBKEY     "Display"
#define NV4_REG_RESOURCE_MANAGER_SUBKEY   "System"


#define NV_REG_STR_RM_OVERRIDE_DEFAULT_TIMEOUT         "RmDefaultTimeout"
// Type Dword
// Override default RM timeout.  Measured in milliseconds.
// Not scaled for emulation

#define NV_REG_STR_RM_OVERRIDE_DEFAULT_TIMEOUT_FLAGS    "RmDefaultTimeoutFlags"
#define NV_REG_STR_RM_OVERRIDE_DEFAULT_TIMEOUT_FLAGS_OSTIMER    4
#define NV_REG_STR_RM_OVERRIDE_DEFAULT_TIMEOUT_FLAGS_OSDELAY    8
// Type Dword
// Override default RM timeout flags to either OSDELAY or OSTIMER.


#define NV_REG_STR_SUPPRESS_CLASS_LIST "SuppressClassList"
// Type String
// A list of comma separated classes to suppress
// examples:
// 5097
// 4097, 5097
// etc


//
// Allow instance memory overrides.  Some fields are chip specific
// and may not apply to all chips.  Since there are many fields,
// this is spread across several DWORD registry keys.
//
// Type DWORD
// Encoding:
//    DEFAULT   RM determines
//    COH       Coherent system memory
//    NCOH      Non-coherent system memory
//    VID       Local video memory
//
#define NV_REG_STR_RM_INST_LOC                              "RMInstLoc"
#define NV_REG_STR_RM_INST_LOC_2                            "RMInstLoc2"
#define NV_REG_STR_RM_INST_LOC_3                            "RMInstLoc3"
#define NV_REG_STR_RM_INST_LOC_4                            "RMInstLoc4"

#define NV_REG_STR_RM_INST_LOC_DEFAULT                      (0x00000000)
#define NV_REG_STR_RM_INST_LOC_COH                          (0x00000001)
#define NV_REG_STR_RM_INST_LOC_NCOH                         (0x00000002)
#define NV_REG_STR_RM_INST_LOC_VID                          (0x00000003)


#define NV_REG_STR_RM_DISABLE_GSP_OFFLOAD                   "RmDisableGspOffload"
#define NV_REG_STR_RM_DISABLE_GSP_OFFLOAD_FALSE             (0x00000000)
#define NV_REG_STR_RM_DISABLE_GSP_OFFLOAD_TRUE              (0x00000001)
// Type DWORD (Boolean)
// Override any other settings and disable GSP-RM offload.


#define NV_REG_STR_RM_MSG                                   "RmMsg"
// Type String: Set parameters for RM DBG_PRINTF.  Only for builds with printfs enabled.
// Encoding:
//    rule = [!][filename|function][:startline][-endline]
//    Format = rule[,rule]


#define NV_REG_STR_RM_THREAD_STATE_SETUP_FLAGS      "RmThreadStateSetupFlags"
// Type DWORD
// Enables or disables various ThreadState features
// See resman/inc/kernel/core/thread_state.h for
// THREAD_STATE_SETUP_FLAGS values.


#define NV_REG_STR_RM_ENABLE_EVENT_TRACER                  "RMEnableEventTracer"
#define NV_REG_STR_RM_ENABLE_EVENT_TRACER_DISABLE          0
#define NV_REG_STR_RM_ENABLE_EVENT_TRACER_ENABLE           1
#define NV_REG_STR_RM_ENABLE_EVENT_TRACER_DEFAULT          NV_REG_STR_RM_ENABLE_EVENT_TRACER_DISABLE
// Type DWORD
// Encoding boolean
// Enable/Disable RM event tracing
// 0 - Disable RM event tracing
// 1 - Enable RM event tracing


#define NV_REG_STR_RM_COMPUTE_MODE_RULES "RmComputeModeRules"
// Type DWORD
// Saves the last compute mode rule set by the client.
// Encoding:
// Bits 31:0 : Last compute mode rule set by the client


#define NV_REG_STR_RM_NVLOG_EXTRA_BUFFER_1        "RMNvLogExtraBuffer1"
// #define NV_REG_STR_RM_NVLOG_EXTRA_BUFFER_2        "RMNvLogExtraBuffer2"
// #define NV_REG_STR_RM_NVLOG_EXTRA_BUFFER_3        "RMNvLogExtraBuffer3"
// #define NV_REG_STR_RM_NVLOG_EXTRA_BUFFER_4        "RMNvLogExtraBuffer4"
// #define NV_REG_STR_RM_NVLOG_EXTRA_BUFFER_5        "RMNvLogExtraBuffer5"
// #define NV_REG_STR_RM_NVLOG_EXTRA_BUFFER_6        "RMNvLogExtraBuffer6"
// Type DWORD
// Used to specify up to 6 additional logging buffers
// Encoding:
//   _BUFFER_FLAGS
//     x: uses NVLOG_BUFFER_FLAGS fields, for main nvlog buffer
//   _BUFFER_SIZE
//     n: Size of main buffer, in kilobytes


// Type DWORD
// This can be used for dumping NvLog buffers (in /var/log/vmkernel.log ), when
// we hit critical XIDs e.g 31/79.
#define NV_REG_STR_RM_DUMP_NVLOG                    "RMDumpNvLog"
#define NV_REG_STR_RM_DUMP_NVLOG_DEFAULT            (0x00000000)
#define NV_REG_STR_RM_DUMP_NVLOG_DISABLE            (0x00000000)
#define NV_REG_STR_RM_DUMP_NVLOG_ENABLE             (0x00000001)


//
// Type DWORD
// RM external fabric management.
//
// RM currently uses nvlink core driver APIs which internally trigger
// link initialization and training. However, nvlink core driver now exposes a
// set of APIs for managing nvlink fabric externally (from user mode).
//
// When the regkey is enabled, RM will skip use of APIs which trigger
// link initialization and training. In that case, link training needs to be
// triggered externally.
//
#define NV_REG_STR_RM_EXTERNAL_FABRIC_MGMT               "RMExternalFabricMgmt"
#define NV_REG_STR_RM_EXTERNAL_FABRIC_MGMT_MODE          0:0
#define NV_REG_STR_RM_EXTERNAL_FABRIC_MGMT_MODE_ENABLE   (0x00000001)
#define NV_REG_STR_RM_EXTERNAL_FABRIC_MGMT_MODE_DISABLE  (0x00000000)


//
// Type DWORD
// BIT 1:0: All Data validation
// 0 - Default
// 1 - Validate the kernel data - enable all below
// 2 - Do not validate the kernel data - disable all below
// BIT 3:2: Buffer validation
// 0 - Default
// 1 - Validate the kernel buffers
// 2 - Do not validate the kernel buffers
// BIT 5:4: Handle validation
// 0 - Default
// 1 - Validate the handles
// 2 - Do not validate the handles
// BIT 7:6: Strict client validation
// 0 - Default
// 1 - Enable strict client validation
// 2 - Do not enable strict client validation
//
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION              "RmValidateClientData"
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_ALL                             1:0
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_ALL_DEFAULT              0x00000000
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_ALL_ENABLED              0x00000001
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_ALL_DISABLED             0x00000002
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_KERNEL_BUFFERS                  3:2
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_KERNEL_BUFFERS_DEFAULT   0x00000000
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_KERNEL_BUFFERS_ENABLED   0x00000001
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_KERNEL_BUFFERS_DISABLED  0x00000002
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_HANDLE                          5:4
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_HANDLE_DEFAULT           0x00000000
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_HANDLE_ENABLED           0x00000001
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_HANDLE_DISABLED          0x00000002
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_STRICT_CLIENT                   7:6
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_STRICT_CLIENT_DEFAULT    0x00000000
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_STRICT_CLIENT_ENABLED    0x00000001
#define NV_REG_STR_RM_CLIENT_DATA_VALIDATION_STRICT_CLIENT_DISABLED   0x00000002


//
// Type: Dword
// Encoding:
// 1 - Enable remote GPU
// 0 - Disable remote GPU
//
#define NV_REG_STR_RM_REMOTE_GPU                           "RMRemoteGpu"
#define NV_REG_STR_RM_REMOTE_GPU_ENABLE                    0x00000001
#define NV_REG_STR_RM_REMOTE_GPU_DISABLE                   0x00000000
#define NV_REG_STR_RM_REMOTE_GPU_DEFAULT                   NV_REG_STR_RM_REMOTE_GPU_DISABLE


//
// Type: DWORD
//
// This regkey configures thread priority boosting whenever
// the thread is holding a GPU lock.
//
#define NV_REG_STR_RM_PRIORITY_BOOST                          "RMPriorityBoost"
#define NV_REG_STR_RM_PRIORITY_BOOST_DISABLE                  0x00000000
#define NV_REG_STR_RM_PRIORITY_BOOST_ENABLE                   0x00000001
#define NV_REG_STR_RM_PRIORITY_BOOST_DEFAULT                  NV_REG_STR_RM_PRIORITY_BOOST_DISABLE


//
// Type: DWORD
//
// This regkey configures the delay (us) before a boosted thread is throttled
// down.
//
// Default value: 0 (Disable)
//
#define NV_REG_STR_RM_PRIORITY_THROTTLE_DELAY                 "RMPriorityThrottleDelay"
#define NV_REG_STR_RM_PRIORITY_THROTTLE_DELAY_DISABLE          0x00000000


//
// Type DWORD
// Enable support for CUDA Stream Memory Operations in user-mode applications.
//
// BIT 0:0 - Feature enablement
//  0 - disable feature (default)
//  1 - enable feature
//
#define NV_REG_STR_RM_STREAM_MEMOPS                 "RmStreamMemOps"
#define NV_REG_STR_RM_STREAM_MEMOPS_ENABLE          0:0
#define NV_REG_STR_RM_STREAM_MEMOPS_ENABLE_YES      1
#define NV_REG_STR_RM_STREAM_MEMOPS_ENABLE_NO       0


//
// Type DWORD: Enable read-only RMAPI locks for select interfaces
//
// Setting an interface to 0 will disable read-only API locks for that interface
// Setting an interface to 1 will enable read-only API locks for that interface,
// however, RM may still choose to take a read-write lock if it needs to.
//
#define NV_REG_STR_RM_READONLY_API_LOCK                            "RmRoApiLock"
#define NV_REG_STR_RM_READONLY_API_LOCK_ALLOC_RESOURCE             1:1
#define NV_REG_STR_RM_READONLY_API_LOCK_ALLOC_RESOURCE_DEFAULT    (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_ALLOC_RESOURCE_DISABLE    (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_ALLOC_RESOURCE_ENABLE     (0x00000001)
#define NV_REG_STR_RM_READONLY_API_LOCK_FREE_RESOURCE              2:2
#define NV_REG_STR_RM_READONLY_API_LOCK_FREE_RESOURCE_DEFAULT     (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_FREE_RESOURCE_DISABLE     (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_FREE_RESOURCE_ENABLE      (0x00000001)
#define NV_REG_STR_RM_READONLY_API_LOCK_MAP                        3:3
#define NV_REG_STR_RM_READONLY_API_LOCK_MAP_DEFAULT               (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_MAP_DISABLE               (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_MAP_ENABLE                (0x00000001)
#define NV_REG_STR_RM_READONLY_API_LOCK_UNMAP                      4:4
#define NV_REG_STR_RM_READONLY_API_LOCK_UNMAP_DEFAULT             (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_UNMAP_DISABLE             (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_UNMAP_ENABLE              (0x00000001)
#define NV_REG_STR_RM_READONLY_API_LOCK_INTER_MAP                  5:5
#define NV_REG_STR_RM_READONLY_API_LOCK_INTER_MAP_DEFAULT         (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_INTER_MAP_DISABLE         (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_INTER_MAP_ENABLE          (0x00000001)
#define NV_REG_STR_RM_READONLY_API_LOCK_INTER_UNMAP                6:6
#define NV_REG_STR_RM_READONLY_API_LOCK_INTER_UNMAP_DEFAULT       (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_INTER_UNMAP_DISABLE       (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_INTER_UNMAP_ENABLE        (0x00000001)
#define NV_REG_STR_RM_READONLY_API_LOCK_COPY                       7:7
#define NV_REG_STR_RM_READONLY_API_LOCK_COPY_DEFAULT              (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_COPY_DISABLE              (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_COPY_ENABLE               (0x00000001)
#define NV_REG_STR_RM_READONLY_API_LOCK_SHARE                      8:8
#define NV_REG_STR_RM_READONLY_API_LOCK_SHARE_DEFAULT             (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_SHARE_DISABLE             (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_SHARE_ENABLE              (0x00000001)
#define NV_REG_STR_RM_READONLY_API_LOCK_CTRL                       9:9
#define NV_REG_STR_RM_READONLY_API_LOCK_CTRL_DEFAULT              (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_CTRL_DISABLE              (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_CTRL_ENABLE               (0x00000001)


//
// Type DWORD: Enable read-only RMAPI locks for select modules
//
// Setting an interface to 0 will disable read-only API locks for that module
// Setting an interface to 1 will enable read-only API locks for that module,
// however, RM may still choose to take a read-write lock if it needs to.
//
#define NV_REG_STR_RM_READONLY_API_LOCK_MODULE                     "RmRoApiLockModule"
#define NV_REG_STR_RM_READONLY_API_LOCK_MODULE_GPU_OPS              0:0
#define NV_REG_STR_RM_READONLY_API_LOCK_MODULE_GPU_OPS_DEFAULT     (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_MODULE_GPU_OPS_DISABLE     (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_MODULE_GPU_OPS_ENABLE      (0x00000001)
#define NV_REG_STR_RM_READONLY_API_LOCK_MODULE_WORKITEM             1:1
#define NV_REG_STR_RM_READONLY_API_LOCK_MODULE_WORKITEM_DEFAULT    (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_MODULE_WORKITEM_DISABLE    (0x00000000)
#define NV_REG_STR_RM_READONLY_API_LOCK_MODULE_WORKITEM_ENABLE     (0x00000001)


//
// Type DWORD: Enable read-only GPU locks for select modules
//
// Setting an interface to 0 will disable read-only GPU locks for that module
// Setting an interface to 1 will enable read-only GPU locks for that module,
// however, RM may still choose to take a read-write lock if it needs to.
//
#define NV_REG_STR_RM_READONLY_GPU_LOCK_MODULE                     "RmRoGpuLockModule"
#define NV_REG_STR_RM_READONLY_GPU_LOCK_MODULE_GPU_OPS              0:0
#define NV_REG_STR_RM_READONLY_GPU_LOCK_MODULE_GPU_OPS_DEFAULT     (0x00000000)
#define NV_REG_STR_RM_READONLY_GPU_LOCK_MODULE_GPU_OPS_DISABLE     (0x00000000)
#define NV_REG_STR_RM_READONLY_GPU_LOCK_MODULE_GPU_OPS_ENABLE      (0x00000001)
#define NV_REG_STR_RM_READONLY_GPU_LOCK_MODULE_WORKITEM             1:1
#define NV_REG_STR_RM_READONLY_GPU_LOCK_MODULE_WORKITEM_DEFAULT    (0x00000000)
#define NV_REG_STR_RM_READONLY_GPU_LOCK_MODULE_WORKITEM_DISABLE    (0x00000000)
#define NV_REG_STR_RM_READONLY_GPU_LOCK_MODULE_WORKITEM_ENABLE     (0x00000001)


// Enable support for CACHEABLE rmapi control flag
// 0: never cache any controls
// 1 (default): cache only ROUTE_TO_PHYSICAL controls, and only if GSP-RM is running
// 2: cache all controls
#define NV_REG_STR_RM_CACHEABLE_CONTROLS             "RmEnableCacheableControls"
#define NV_REG_STR_RM_CACHEABLE_CONTROLS_DISABLE     0
#define NV_REG_STR_RM_CACHEABLE_CONTROLS_GSP_ONLY    1
#define NV_REG_STR_RM_CACHEABLE_CONTROLS_ENABLE      2


// Enable backtrace dumping at assertion failure.
// If physical RM or RCDB is unavailable, then this regkey controls the behaviour of backtrace
// printing.
// 0: disable
// 1 (default): only print unique backtraces, identified by instruction pointer of the failed assert
// 2: print all
#define NV_REG_STR_RM_PRINT_ASSERT_BACKTRACE         "RmPrintAssertBacktrace"
#define NV_REG_STR_RM_PRINT_ASSERT_BACKTRACE_DISABLE 0
#define NV_REG_STR_RM_PRINT_ASSERT_BACKTRACE_UNIQUE  1
#define NV_REG_STR_RM_PRINT_ASSERT_BACKTRACE_ENABLE  2


//
// Type DWORD
// Used to enable no locking on copy
//
#define NV_REG_STR_RM_PARAM_COPY_NO_LOCK                      "RMParamCopyNoLock"

#endif // NVRM_REGISTRY_H
