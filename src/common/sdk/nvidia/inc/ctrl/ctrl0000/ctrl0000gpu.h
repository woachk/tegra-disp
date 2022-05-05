/*
 * SPDX-FileCopyrightText: Copyright (c) 2005-2019 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

#pragma once

#include <nvtypes.h>
#if defined(_MSC_VER)
#pragma warning(disable:4324)
#endif

//
// This file was generated with FINN, an NVIDIA coding tool.
// Source file: ctrl/ctrl0000/ctrl0000gpu.finn
//




#include "ctrl/ctrl0000/ctrl0000base.h"
#include "ctrl/ctrl0000/ctrl0000system.h"
#include "ctrl/ctrlxxxx.h"
#include "nvlimits.h"

/* NV01_ROOT (client) GPU control commands and parameters */

/*
 * NV0000_CTRL_CMD_GPU_GET_ATTACHED_IDS
 *
 * This command returns a table of attached gpuId values.
 * The table is NV0000_CTRL_GPU_MAX_ATTACHED_GPUS entries in size.
 *
 *   gpuIds[]
 *     This parameter returns the table of attached GPU IDs.
 *     The GPU ID is an opaque platform-dependent value that can be used
 *     with the NV0000_CTRL_CMD_GPU_GET_ID_INFO command to retrieve
 *     additional information about the GPU.  The valid entries in gpuIds[]
 *     are contiguous, with a value of NV0000_CTRL_GPU_INVALID_ID indicating
 *     the invalid entries.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_OPERATING_SYSTEM
 */
#define NV0000_CTRL_CMD_GPU_GET_ATTACHED_IDS (0x201) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_MAX_ATTACHED_GPUS    32
#define NV0000_CTRL_GPU_INVALID_ID           (0xffffffff)

#define NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS_MESSAGE_ID (0x1U)

typedef struct NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS {
    NvU32 gpuIds[NV0000_CTRL_GPU_MAX_ATTACHED_GPUS];
} NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS;

/*
 * Deprecated. Please use NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2 instead.
 */
#define NV0000_CTRL_CMD_GPU_GET_ID_INFO (0x202) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_ID_INFO_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_MAX_SZNAME      128

#define NV0000_CTRL_NO_NUMA_NODE        (-1)

#define NV0000_CTRL_GPU_GET_ID_INFO_PARAMS_MESSAGE_ID (0x2U)

typedef struct NV0000_CTRL_GPU_GET_ID_INFO_PARAMS {
    NvU32 gpuId;
    NvU32 gpuFlags;
    NvU32 deviceInstance;
    NvU32 subDeviceInstance;
    NV_DECLARE_ALIGNED(NvP64 szName, 8);
    NvU32 sliStatus;
    NvU32 boardId;
    NvU32 gpuInstance;
    NvS32 numaId;
} NV0000_CTRL_GPU_GET_ID_INFO_PARAMS;

/*
 * NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2
 * This command returns GPU instance information for the specified GPU.
 *
 *   [in] gpuId
 *     This parameter should specify a valid GPU ID value.  If there
 *     is no GPU present with the specified ID, a status of
 *     NV_ERR_INVALID_ARGUMENT is returned.
 *   [out] gpuFlags
 *     This parameter returns various flags values for the specified GPU.
 *     Valid flag values include:
 *       NV0000_CTRL_GPU_ID_INFO_IN_USE
 *         When true this flag indicates there are client references
 *         to the GPU in the form of device class instantiations (see
 *         NV01_DEVICE or NV03_DEVICE descriptions for details).
 *       NV0000_CTRL_GPU_ID_INFO_LINKED_INTO_SLI_DEVICE
 *         When true this flag indicates the GPU is linked into an
 *         active SLI device.
 *       NV0000_CTRL_GPU_ID_INFO_MOBILE
 *         When true this flag indicates the GPU is a mobile GPU.
 *       NV0000_CTRL_GPU_ID_BOOT_MASTER
 *         When true this flag indicates the GPU is the boot master GPU.
 *       NV0000_CTRL_GPU_ID_INFO_QUADRO
 *         When true this flag indicates the GPU is a Quadro GPU.
 *       NV0000_CTRL_GPU_ID_INFO_SOC
 *         When true this flag indicates the GPU is part of a
 *         System-on-Chip (SOC).
 *       NV0000_CTRL_GPU_ID_INFO_ATS_ENABLED
 *         When ATS is enabled on the system.
 *   [out] deviceInstance
 *     This parameter returns the broadcast device instance number associated
 *     with the specified GPU.  This value can be used to instantiate
 *     a broadcast reference to the GPU using the NV01_DEVICE classes.
 *   [out] subDeviceInstance
 *     This parameter returns the unicast subdevice instance number
 *     associated with the specified GPU.  This value can be used to
 *     instantiate a unicast reference to the GPU using the NV20_SUBDEVICE
 *     classes.
 *   [out] sliStatus
 *     This parameters returns the SLI status for the specified GPU.
 *     Legal values for this member are described by NV0000_CTRL_SLI_STATUS.
 *   [out] boardId
 *     This parameter returns the board ID value with which the
 *     specified GPU is associated.  Multiple GPUs can share the
 *     same board ID in multi-GPU configurations.
 *   [out] gpuInstance
 *     This parameter returns the GPU instance number for the specified GPU.
 *     GPU instance numbers are assigned in bus-probe order beginning with
 *     zero and are limited to one less the number of GPUs in the system.
 *   [out] numaId
 *     This parameter returns the ID of NUMA node for the specified GPU.
 *     In case there is no NUMA node, NV0000_CTRL_NO_NUMA_NODE is returned.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 */
#define NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2 (0x205) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS_MESSAGE_ID (0x5U)

typedef struct NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS {
    NvU32 gpuId;
    NvU32 gpuFlags;
    NvU32 deviceInstance;
    NvU32 subDeviceInstance;
    NvU32 sliStatus;
    NvU32 boardId;
    NvU32 gpuInstance;
    NvS32 numaId;
} NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS;


/* valid flags values */
#define NV0000_CTRL_GPU_ID_INFO_IN_USE                             0:0
#define NV0000_CTRL_GPU_ID_INFO_IN_USE_FALSE                 (0x00000000)
#define NV0000_CTRL_GPU_ID_INFO_IN_USE_TRUE                  (0x00000001)
#define NV0000_CTRL_GPU_ID_INFO_LINKED_INTO_SLI_DEVICE             1:1
#define NV0000_CTRL_GPU_ID_INFO_LINKED_INTO_SLI_DEVICE_FALSE (0x00000000)
#define NV0000_CTRL_GPU_ID_INFO_LINKED_INTO_SLI_DEVICE_TRUE  (0x00000001)
#define NV0000_CTRL_GPU_ID_INFO_MOBILE                             2:2
#define NV0000_CTRL_GPU_ID_INFO_MOBILE_FALSE                 (0x00000000)
#define NV0000_CTRL_GPU_ID_INFO_MOBILE_TRUE                  (0x00000001)
#define NV0000_CTRL_GPU_ID_INFO_BOOT_MASTER                        3:3
#define NV0000_CTRL_GPU_ID_INFO_BOOT_MASTER_FALSE            (0x00000000)
#define NV0000_CTRL_GPU_ID_INFO_BOOT_MASTER_TRUE             (0x00000001)
#define NV0000_CTRL_GPU_ID_INFO_QUADRO                             4:4
#define NV0000_CTRL_GPU_ID_INFO_QUADRO_FALSE                 (0x00000000)
#define NV0000_CTRL_GPU_ID_INFO_QUADRO_TRUE                  (0x00000001)
#define NV0000_CTRL_GPU_ID_INFO_SOC                                5:5
#define NV0000_CTRL_GPU_ID_INFO_SOC_FALSE                    (0x00000000)
#define NV0000_CTRL_GPU_ID_INFO_SOC_TRUE                     (0x00000001)
#define NV0000_CTRL_GPU_ID_INFO_ATS_ENABLED                        6:6
#define NV0000_CTRL_GPU_ID_INFO_ATS_ENABLED_FALSE            (0x00000000)
#define NV0000_CTRL_GPU_ID_INFO_ATS_ENABLED_TRUE             (0x00000001)

/*
 * NV0000_CTRL_CMD_GPU_GET_INIT_STATUS
 *
 * This command returns the initialization status for the specified GPU, and
 * will return NV_ERR_INVALID_STATE if called prior to GPU
 * initialization.
 *
 *   gpuId
 *     This parameter should specify a valid GPU ID value.  If there
 *     is no GPU present with the specified ID, a status of
 *     NV_ERR_INVALID_ARGUMENT is returned.
 *   status
 *     This parameter returns the status code identifying the initialization
 *     state of the GPU. If this parameter has the value NV_OK,
 *     then no errors were detected during GPU initialization. Otherwise, this
 *     parameter specifies the top-level error that was detected during GPU
 *     initialization. Note that a value of NV_OK only means that
 *     no errors were detected during the actual GPU initialization, and other
 *     errors may have occurred that prevent the GPU from being attached or
 *     accessible via the NV01_DEVICE or NV20_SUBDEVICE classes.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_STATE
 */
#define NV0000_CTRL_CMD_GPU_GET_INIT_STATUS                  (0x203) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_INIT_STATUS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_GET_INIT_STATUS_PARAMS_MESSAGE_ID (0x3U)

typedef struct NV0000_CTRL_GPU_GET_INIT_STATUS_PARAMS {
    NvU32 gpuId;
    NvU32 status;
} NV0000_CTRL_GPU_GET_INIT_STATUS_PARAMS;

/*
 * NV0000_CTRL_CMD_GPU_GET_DEVICE_IDS
 *
 * This command returns a mask of valid device IDs.  These device IDs
 * can be used to instantiate the NV01_DEVICE_0 class (see NV01_DEVICE_0
 * for more information).
 *
 *   deviceIds
 *     This parameter returns the mask of valid device IDs.  Each enabled bit
 *     in the mask corresponds to a valid device instance.  Valid device
 *     instances can be used to initialize the NV0080_ALLOC_PARAMETERS
 *     structure when using NvRmAlloc to instantiate device handles.  The
 *     number of device IDs will not exceed NV_MAX_DEVICES in number.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV0000_CTRL_CMD_GPU_GET_DEVICE_IDS (0x204) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_DEVICE_IDS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_GET_DEVICE_IDS_PARAMS_MESSAGE_ID (0x4U)

typedef struct NV0000_CTRL_GPU_GET_DEVICE_IDS_PARAMS {
    NvU32 deviceIds;
} NV0000_CTRL_GPU_GET_DEVICE_IDS_PARAMS;

/*
 * NV0000_CTRL_GPU_SLI_CONFIG
 *
 * This structure describes a single SLI configuration.
 *
 *   sliInfo
 *     This parameter contains any flags associated with the configuration.
 *     Valid info values include:
 *       NV0000_CTRL_GPU_SLI_INFO_ACTIVE (out)
 *         When set to _TRUE this flag indicates that the configuration has
 *         been activated by a call to NV0000_CTRL_CMD_GPU_LINK_SLI_DEVICE.
 *         When set to _FALSE this flag indicates that the configuration
 *         is inactive.
 *       NV0000_CTRL_GPU_SLI_INFO_VIDLINK (out)
 *         When set to _PRESENT this flag indicates that the configuration
 *         has a video link (or bridge).  When set to _NOT_PRESENT this flag
 *         indicates the configuration does not have a video link.
 *       NV0000_CTRL_GPU_SLI_INFO_ENABLE_SLI_BY_DEFAULT (out)
 *         When set to _TRUE this flag indicates that the SLI configuration
 *         must be enabled by default.  When to set to _FALSE this flag
 *         indicates that the SLI configuration can be optionally enabled.
 *       NV0000_CTRL_GPU_SLI_INFO_MULTI_GPU (out)
 *         When set to _TRUE this flag indicates that this is a
 *         "Multi-GPU"-labeled configuration.
 *       NV0000_CTRL_GPU_SLI_INFO_GX2_BOARD (out)
 *         When set to _TRUE this flag indicates that the GPUs comprising
 *         this SLI configuration are Dagwoods.
 *       NV0000_CTRL_GPU_SLI_INFO_DYNAMIC_ALLOWED (out)
 *         When set to _TRUE this flag indicates that a Dynamic SLI
 *         transition is allowed.  When _FALSE a reboot is required.
 *       NV0000_CTRL_GPU_SLI_INFO_VIDLINK_CONNECTOR (out)
 *         When set to _PRESENT this flag indicates that the configuration
 *         has video link (or bridge) connectors on all GPUs.
 *         When set to _NOT_PRESENT this flag indicates the configuration does
 *         does not have video link connctors on all GPUs.
 *       NV0000_CTRL_GPU_SLI_INFO_BROADCAST - DEPRECATED (out)
 *         When set to _TRUE this flag indicates that broadcast mode is
 *         supported by this SLI configuration.  When set to _FALSE this flag
 *         indicates that broadcast mode is not supported by this SLI
 *         configuration.
 *       NV0000_CTRL_GPU_SLI_INFO_UNICAST - DEPRECATED (out)
 *         When set to _TRUE this flag indicates that unicast mode is
 *         supported by this SLI configuration.  When set to _FALSE this flag
 *         indicates that unicast mode is not supported by this SLI
 *         configuration.
 *       NV0000_CTRL_GPU_SLI_INFO_SLI_MOSAIC_ONLY (out)
 *         When set to _TRUE this flag indicates that only a
 *         Mosaic mode is supported by this configuration.
 *       NV0000_CTRL_GPU_SLI_INFO_4_WAY_SLI (out)
 *         When set to _TRUE this flag indicates that this is a
 *         "4-Way-SLI" labeled configuration - four discrete boards.
 *       NV0000_CTRL_GPU_SLI_INFO_BASE_MOSAIC_ONLY (out)
 *         When set to _TRUE this flag indicates that base mosaic is
 *         only supported.  That is, from an end-user point of view,
 *         SLI is not allowed.
 *       NV0000_CTRL_GPU_SLI_INFO_ALLOW_SLI_MOSAIC (out)
 *         When set to _TRUE this flag indicates that in addition to
 *         SLI support, the topology supports SLI Mosaic.
 *       NV0000_CTRL_GPU_SLI_INFO_ALLOW_SLI_BASE_MOSAIC (out)
 *         When set to _TRUE this flag indicates that in addition to
 *         SLI support, the topology supports SLI BaseMosaic.
 *       NV0000_CTRL_GPU_SLI_INFO_DUAL_MIO (out)
 *         When set to _TRUE this flag indicates that Dual MIO has been
 *         activated in this GPU topology.
 *       NV0000_CTRL_GPU_SLI_INFO_GPUS_DUAL_MIO_CAPABLE (out)
 *         When set to _TRUE this flag indicates that all GPUs this topology
 *         support Dual MIO
 *       NV0000_CTRL_GPU_SLI_INFO_NVLINK (out)
 *         When set to _PRESENT this flag indicates that the configuration
 *         has Nvlink on all GPUs
 *         When set to _NOT_PRESENT this flag indicates the configuration
 *         does not have Nvlink on all GPUs.
 *       NV0000_CTRL_GPU_SLI_INFO_NVLINK_CONNECTOR (out)
 *         When set to _PRESENT this flag indicates that the configuration
 *         has Nvlink connectors on all GPUs
 *         When set to _NOT_PRESENT this flag indicates the configuration
 *         does not have Nvlink connctors on all GPUs.
 *       NV0000_CTRL_GPU_SLI_INFO_DUAL_MIO_POSSIBLE  (out)
 *         When set to _TRUE this flag indicates that Dual Mio is possible
 *         with this topology.
 *       NV0000_CTRL_GPU_SLI_INFO_HIGH_SPEED_VIDLINK  (out)
 *         When set to _TRUE this flag indicates that all GPUs in this topology are
 *         connected with one or two high speed video bridges.
 *       NV0000_CTRL_GPU_SLI_INFO_WS_OVERRIDE (out)
 *         When set to _TRUE this flag indicates that the GPU is internal, for which
 *         the SLI rules are relaxed: do not check for Quadro/Mobile restrictions
 *         related to the platform.
 *       NV0000_CTRL_GPU_SLI_INFO_PREPASCAL (out)
 *         When set to _TRUE this flag indicates that the GPU family is Maxwell
 *         or below.
 *       NV0000_CTRL_GPU_SLI_INFO_DD_ALT_SET_VIDLINK (in)
 *         This flag is an input and can be set by the client.
 *         When set to _TRUE this flag indicates the client will call NV0080_CTRL_GPU_SET_VIDLINK
 *         before modeset. If this flag is enabled, RM tracks any additional states required to ensure
 *         MIO power is enabled during SV2 for all necessary conditions. Client would call
 *         NV0080_CTRL_GPU_SET_VIDLINK after modeset only for power saving tweaks.
 *       NV0000_CTRL_GPU_SLI_INFO_NO_BRIDGE_REQUIRED (out)
 *         When set to _TRUE this flag indicates that no bridge is required
 *
 *   displayGpuIndex
 *     This member contains the index into the gpuIds[] array pointing to
 *     the display GPU.
 *   gpuCount
 *     This member contains the number of GPU IDs comprising the SLI device
 *     and stored in the gpuIds[] array.
 *   gpuIds
 *     This member contains the array of GPU IDs comprising the SLI device.
 *     Valid entries are contiguous, beginning with the first entry in the
 *     list.  Invalid entries contain NV0000_CTRL_GPU_INVALID_ID.
 *   masterGpuIndex
 *     This member contains the index into the gpuIds[] array pointing to
 *     the master GPU.
 *   noDisplayGpuMask
 *     This member contains an index mask into the gpuIds[] array pointing to
 *     the GPUs that cannot have active displays when SLI is enabled.
 */
typedef struct NV0000_CTRL_GPU_SLI_CONFIG {
    NvU32 sliInfo;
    NvU32 displayGpuIndex;
    NvU32 gpuCount;
    NvU32 gpuIds[NV_MAX_SUBDEVICES];
    NvU32 masterGpuIndex;
    NvU32 noDisplayGpuMask;
} NV0000_CTRL_GPU_SLI_CONFIG;

/* valid flags values */
#define NV0000_CTRL_GPU_SLI_INFO_ACTIVE                            0:0
#define NV0000_CTRL_GPU_SLI_INFO_ACTIVE_FALSE                     (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_ACTIVE_TRUE                      (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_VIDLINK                           1:1
#define NV0000_CTRL_GPU_SLI_INFO_VIDLINK_NOT_PRESENT              (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_VIDLINK_PRESENT                  (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_ENABLE_SLI_BY_DEFAULT             2:2
#define NV0000_CTRL_GPU_SLI_INFO_ENABLE_SLI_BY_DEFAULT_FALSE      (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_ENABLE_SLI_BY_DEFAULT_TRUE       (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_MULTI_GPU                         3:3
#define NV0000_CTRL_GPU_SLI_INFO_MULTI_GPU_FALSE                  (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_MULTI_GPU_TRUE                   (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_ENABLE_CORELOGIC_BROADCAST        4:4          // DEPRECATED
#define NV0000_CTRL_GPU_SLI_INFO_ENABLE_CORELOGIC_BROADCAST_FALSE (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_ENABLE_CORELOGIC_BROADCAST_TRUE  (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_IMPLICIT_SLI                      5:5
#define NV0000_CTRL_GPU_SLI_INFO_IMPLICIT_SLI_FALSE               (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_IMPLICIT_SLI_TRUE                (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_GX2_BOARD                         6:6
#define NV0000_CTRL_GPU_SLI_INFO_GX2_BOARD_FALSE                  (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_GX2_BOARD_TRUE                   (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_DYNAMIC_ALLOWED                   7:7
#define NV0000_CTRL_GPU_SLI_INFO_DYNAMIC_ALLOWED_FALSE            (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_DYNAMIC_ALLOWED_TRUE             (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_VIDLINK_CONNECTOR                 8:8
#define NV0000_CTRL_GPU_SLI_INFO_VIDLINK_CONNECTOR_NOT_PRESENT    (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_VIDLINK_CONNECTOR_PRESENT        (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_BROADCAST                          9:9         // DEPRECATED
#define NV0000_CTRL_GPU_SLI_INFO_BROADCAST_FALSE                  (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_BROADCAST_TRUE                   (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_UNICAST                           10:10        // DEPRECATED
#define NV0000_CTRL_GPU_SLI_INFO_UNICAST_FALSE                    (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_UNICAST_TRUE                     (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_SLI_MOSAIC_ONLY                   11:11
#define NV0000_CTRL_GPU_SLI_INFO_SLI_MOSAIC_ONLY_FALSE            (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_SLI_MOSAIC_ONLY_TRUE             (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_4_WAY_SLI                         12:12
#define NV0000_CTRL_GPU_SLI_INFO_4_WAY_SLI_FALSE                  (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_4_WAY_SLI_TRUE                   (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_BASE_MOSAIC_ONLY                  13:13
#define NV0000_CTRL_GPU_SLI_INFO_BASE_MOSAIC_ONLY_FALSE           (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_BASE_MOSAIC_ONLY_TRUE            (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_ALLOW_SLI_MOSAIC                  14:14
#define NV0000_CTRL_GPU_SLI_INFO_ALLOW_SLI_MOSAIC_FALSE           (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_ALLOW_SLI_MOSAIC_TRUE            (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_ALLOW_SLI_BASE_MOSAIC             15:15
#define NV0000_CTRL_GPU_SLI_INFO_ALLOW_SLI_BASE_MOSAIC_FALSE      (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_ALLOW_SLI_BASE_MOSAIC_TRUE       (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_DUAL_MIO                          16:16
#define NV0000_CTRL_GPU_SLI_INFO_DUAL_MIO_FALSE                   (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_DUAL_MIO_TRUE                    (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_GPUS_DUAL_MIO_CAPABLE             17:17
#define NV0000_CTRL_GPU_SLI_INFO_GPUS_DUAL_MIO_CAPABLE_FALSE      (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_GPUS_DUAL_MIO_CAPABLE_TRUE       (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_NVLINK                            18:18
#define NV0000_CTRL_GPU_SLI_INFO_NVLINK_NOT_PRESENT               (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_NVLINK_PRESENT                   (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_NVLINK_CONNECTOR                  19:19
#define NV0000_CTRL_GPU_SLI_INFO_NVLINK_CONNECTOR_NOT_PRESENT     (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_NVLINK_CONNECTOR_PRESENT         (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_DUAL_MIO_POSSIBLE                 21:21
#define NV0000_CTRL_GPU_SLI_INFO_DUAL_MIO_POSSIBLE_FALSE          (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_DUAL_MIO_POSSIBLE_TRUE           (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_HIGH_SPEED_VIDLINK                22:22
#define NV0000_CTRL_GPU_SLI_INFO_HIGH_SPEED_VIDLINK_FALSE         (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_HIGH_SPEED_VIDLINK_TRUE          (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_WS_OVERRIDE                       23:23
#define NV0000_CTRL_GPU_SLI_INFO_WS_OVERRIDE_FALSE                (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_WS_OVERRIDE_TRUE                 (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_NO_BRIDGE_REQUIRED                24:24
#define NV0000_CTRL_GPU_SLI_INFO_NO_BRIDGE_REQUIRED_FALSE         (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_NO_BRIDGE_REQUIRED_TRUE          (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_PREPASCAL                         25:25
#define NV0000_CTRL_GPU_SLI_INFO_PREPASCAL_FALSE                  (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_PREPASCAL_TRUE                   (0x00000001)
#define NV0000_CTRL_GPU_SLI_INFO_DD_ALT_SET_VIDLINK                26:26
#define NV0000_CTRL_GPU_SLI_INFO_DD_ALT_SET_VIDLINK_FALSE         (0x00000000)
#define NV0000_CTRL_GPU_SLI_INFO_DD_ALT_SET_VIDLINK_TRUE          (0x00000001)


/*
 * Deprecated. Please use NV0000_CTRL_CMD_GPU_GET_VALID_SLI_CONFIGS_V2 instead.
 */
#define NV0000_CTRL_CMD_GPU_GET_VALID_SLI_CONFIGS                 (0x210) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_VALID_SLI_CONFIGS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_GET_VALID_SLI_CONFIGS_PARAMS_MESSAGE_ID (0x10U)

typedef struct NV0000_CTRL_GPU_GET_VALID_SLI_CONFIGS_PARAMS {
    NvU32 sliStatus;
    NvU32 sliConfigCount;
    NV_DECLARE_ALIGNED(NvP64 sliConfigList, 8);
    NvU8  bRecheckSliCookie;
} NV0000_CTRL_GPU_GET_VALID_SLI_CONFIGS_PARAMS;

/*
 * NV0000_CTRL_CMD_GPU_GET_VALID_SLI_CONFIGS_V2
 *
 * This command returns the number and specification of valid SLI
 * configurations.  A valid SLI configuration is comprised of two or more GPUs,
 * and can be used to create an SLI device using the
 * NV0000_CTRL_CMD_LINK_SLI_DEVICE command.  The list of entries returned by
 * this command includes all possible SLI configurations, including those that
 * describe active SLI devices.
 *
 *   [out] sliStatus
 *     This parameter returns the system-wide SLI status.  If sliConfigCount
 *     contains 0, this parameter will indicate the reason(s) that
 *     no valid configurations are available.
 *   [out] sliConfigCount
 *     This parameter always returns the total number of valid SLI device
 *     configurations available in the system.  A value of 0 indicates
 *     that there are no valid configurations available.
 *   [out] sliConfigList
 *     RM will copy sliConfigCount entries each describing a configuration into
 *     this buffer.  The fixed size of this array should be able to hold the
 *     maximum possible number of configs, per bug 2010268.
 *   [in] bRecheckSliCookie
 *     Recheck the SLI cookie in case it has not been retrieved correctly
 *     by the driver due to OS timing problems at boot on Windows only.
 *     This flag is not needed on other oses than Windows.
 *     It applies only once, and is set only from the NVAPI interface.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 */
#define NV0000_CTRL_CMD_GPU_GET_VALID_SLI_CONFIGS_V2 (0x21d) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_VALID_SLI_CONFIGS_V2_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SLI_CONFIG_LIST_SIZE             256

#define NV0000_CTRL_GPU_GET_VALID_SLI_CONFIGS_V2_PARAMS_MESSAGE_ID (0x1DU)

typedef struct NV0000_CTRL_GPU_GET_VALID_SLI_CONFIGS_V2_PARAMS {
    NvU32                      sliStatus;
    NvU32                      startingOffset;
    NvU32                      sliConfigCount;
    NV0000_CTRL_GPU_SLI_CONFIG sliConfigList[NV0000_CTRL_SLI_CONFIG_LIST_SIZE];
    NvU8                       bRecheckSliCookie;
} NV0000_CTRL_GPU_GET_VALID_SLI_CONFIGS_V2_PARAMS;

/* sliStatus values */
#define NV0000_CTRL_SLI_STATUS_OK                         (0x00000000)
#define NV0000_CTRL_SLI_STATUS_INVALID_GPU_COUNT          (0x00000001)
#define NV0000_CTRL_SLI_STATUS_OS_NOT_SUPPORTED           (0x00000002)
#define NV0000_CTRL_SLI_STATUS_OS_ERROR                   (0x00000004)
#define NV0000_CTRL_SLI_STATUS_NO_VIDLINK                 (0x00000008)
#define NV0000_CTRL_SLI_STATUS_INSUFFICIENT_LINK_WIDTH    (0x00000010)
#define NV0000_CTRL_SLI_STATUS_CPU_NOT_SUPPORTED          (0x00000020)
#define NV0000_CTRL_SLI_STATUS_GPU_NOT_SUPPORTED          (0x00000040)
#define NV0000_CTRL_SLI_STATUS_BUS_NOT_SUPPORTED          (0x00000080)
#define NV0000_CTRL_SLI_STATUS_CHIPSET_NOT_SUPPORTED      (0x00000100)
#define NV0000_CTRL_SLI_STATUS_GPU_MISMATCH               (0x00000400)
#define NV0000_CTRL_SLI_STATUS_ARCH_MISMATCH              (0x00000800)
#define NV0000_CTRL_SLI_STATUS_IMPL_MISMATCH              (0x00001000)
#define NV0000_CTRL_SLI_STATUS_SLI_WITH_TCC_NOT_SUPPORTED (0x00002000)
#define NV0000_CTRL_SLI_STATUS_PCI_ID_MISMATCH            (0x00004000)
#define NV0000_CTRL_SLI_STATUS_FB_MISMATCH                (0x00008000)
#define NV0000_CTRL_SLI_STATUS_VBIOS_MISMATCH             (0x00010000)
#define NV0000_CTRL_SLI_STATUS_QUADRO_MISMATCH            (0x00020000)
#define NV0000_CTRL_SLI_STATUS_BUS_TOPOLOGY_ERROR         (0x00040000)
#define NV0000_CTRL_SLI_STATUS_CONFIGSPACE_ACCESS_ERROR   (0x00080000)
#define NV0000_CTRL_SLI_STATUS_INCONSISTENT_CONFIG_SPACE  (0x00100000)
#define NV0000_CTRL_SLI_STATUS_CONFIG_NOT_SUPPORTED       (0x00200000)
#define NV0000_CTRL_SLI_STATUS_RM_NOT_SUPPORTED           (0x00400000)
#define NV0000_CTRL_SLI_STATUS_GPU_DRAINING               (0x00800000)
#define NV0000_CTRL_SLI_STATUS_MOBILE_MISMATCH            (0x01000000)
#define NV0000_CTRL_SLI_STATUS_ECC_MISMATCH               (0x02000000)
#define NV0000_CTRL_SLI_STATUS_INSUFFICIENT_FB            (0x04000000)
#define NV0000_CTRL_SLI_STATUS_SLI_COOKIE_NOT_PRESENT     (0x08000000)
#define NV0000_CTRL_SLI_STATUS_SLI_FINGER_NOT_SUPPORTED   (0x10000000)
#define NV0000_CTRL_SLI_STATUS_SLI_WITH_ECC_NOT_SUPPORTED (0x20000000)
#define NV0000_CTRL_SLI_STATUS_GR_MISMATCH                (0x40000000)



/*
 * NV0000_CTRL_CMD_GPU_GET_PROBED_IDS
 *
 * This command returns a table of probed gpuId values.
 * The table is NV0000_CTRL_GPU_MAX_PROBED_GPUS entries in size.
 *
 *   gpuIds[]
 *     This parameter returns the table of probed GPU IDs.
 *     The GPU ID is an opaque platform-dependent value that can
 *     be used with the NV0000_CTRL_CMD_GPU_ATTACH_IDS and
 *     NV0000_CTRL_CMD_GPU_DETACH_ID commands to attach and detach
 *     the GPU.
 *     The valid entries in gpuIds[] are contiguous, with a value
 *     of NV0000_CTRL_GPU_INVALID_ID indicating the invalid entries.
 *   excludedGpuIds[]
 *     This parameter returns the table of excluded GPU IDs.
 *     An excluded GPU ID is an opaque platform-dependent value that
 *     can be used with NV0000_CTRL_CMD_GPU_GET_PCI_INFO and
 *     NV0000_CTRL_CMD_GPU_GET_UUID_INFO.
 *     The valid entries in excludedGpuIds[] are contiguous, with a value
 *     of NV0000_CTRL_GPU_INVALID_ID indicating the invalid entries.
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV0000_CTRL_CMD_GPU_GET_PROBED_IDS (0x214) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_MAX_PROBED_GPUS    NV_MAX_DEVICES

#define NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS_MESSAGE_ID (0x14U)

typedef struct NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS {
    NvU32 gpuIds[NV0000_CTRL_GPU_MAX_PROBED_GPUS];
    NvU32 excludedGpuIds[NV0000_CTRL_GPU_MAX_PROBED_GPUS];
} NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS;

/*
 * NV0000_CTRL_CMD_GPU_GET_PCI_INFO
 *
 * This command takes a gpuId and returns PCI bus information about
 * the device. If the OS does not support returning PCI bus
 * information, this call will return NV_ERR_NOT_SUPPORTED
 *
 *   gpuId
 *     This parameter should specify a valid GPU ID value.  If there
 *     is no GPU present with the specified ID, a status of
 *     NV_ERR_INVALID_ARGUMENT is returned.
 *
 *   domain
 *     This parameter returns the PCI domain of the GPU.
 *
 *   bus
 *     This parameter returns the PCI bus of the GPU.
 *
 *   slot
 *     This parameter returns the PCI slot of the GPU.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 *   NV_ERR_INVALID_ARGUMENT
 */
#define NV0000_CTRL_CMD_GPU_GET_PCI_INFO (0x21b) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_PCI_INFO_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_GET_PCI_INFO_PARAMS_MESSAGE_ID (0x1BU)

typedef struct NV0000_CTRL_GPU_GET_PCI_INFO_PARAMS {
    NvU32 gpuId;
    NvU32 domain;
    NvU16 bus;
    NvU16 slot;
} NV0000_CTRL_GPU_GET_PCI_INFO_PARAMS;

/*
 * NV0000_CTRL_CMD_GPU_ATTACH_IDS
 *
 * This command attaches the GPUs with the gpuIds matching those in
 * the table provided by the client.
 * The table is NV0000_CTRL_GPU_MAX_PROBED_GPUS entries in size.
 *
 *   gpuIds[]
 *     This parameter holds the table of gpuIds to attach. At least
 *     one gpuId must be specified; clients may use the special
 *     gpuId value NV0000_CTRL_GPU_ATTACH_ALL_PROBED_IDS to indicate
 *     that all probed GPUs are to be attached.
 *     The entries in gpuIds[] must be contiguous, with a value of
 *     NV0000_CTRL_GPU_INVALID_ID to indicate the first invalid
 *     entry.
 *     If one or more of the gpuId values do not specify a GPU found
 *     in the system, the NV_ERR_INVALID_ARGUMENT error
 *     status is returned.
 *
 *   failedId
 *     If NV0000_CTRL_GPU_ATTACH_ALL_PROBED_IDS is specified and
 *     a GPU cannot be attached, the NV0000_CTRL_CMD_GPU_ATTACH_IDS
 *     command returns an error code and saves the failing GPU's
 *     gpuId in this field.
 *
 * If a table of gpuIds is provided, these gpuIds will be validated
 * against the RM's table of probed gpuIds and attached in turn,
 * if valid; if NV0000_CTRL_GPU_ATTACH_ALL_PROBED_IDS is used, all
 * probed gpuIds will be attached, in the order the associated GPUs
 * were probed in by the RM.
 *
 * If a gpuId fails to attach, this gpuId is stored in the failedId
 * field. Any GPUs attached by the command prior the failure are
 * detached.
 *
 * If multiple clients use NV0000_CTRL_CMD_GPU_ATTACH_IDS to attach
 * a gpuId, the RM ensures that the gpuId won't be detached until
 * all clients have issued a call to NV0000_CTRL_CMD_GPU_DETACH_IDS
 * to detach the gpuId (or have terminated).
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_OPERATING_SYSTEM
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_IRQ_EDGE_TRIGGERED
 *   NV_ERR_IRQ_NOT_FIRING
 */
#define NV0000_CTRL_CMD_GPU_ATTACH_IDS        (0x215) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_ATTACH_IDS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_ATTACH_ALL_PROBED_IDS (0x0000ffff)

#define NV0000_CTRL_GPU_ATTACH_IDS_PARAMS_MESSAGE_ID (0x15U)

typedef struct NV0000_CTRL_GPU_ATTACH_IDS_PARAMS {
    NvU32 gpuIds[NV0000_CTRL_GPU_MAX_PROBED_GPUS];
    NvU32 failedId;
} NV0000_CTRL_GPU_ATTACH_IDS_PARAMS;

/*
 * NV0000_CTRL_CMD_GPU_DETACH_IDS
 *
 * This command detaches the GPUs with the gpuIds matching those in
 * the table provided by the client.
 * The table is NV0000_CTRL_GPU_MAX_ATTACHED_GPUS entries in size.
 *
 *   gpuIds[]
 *     This parameter holds the table of gpuIds to detach. At least
 *     one gpuId must be specified; clients may use the special
 *     gpuId NV0000_CTRL_GPU_DETACH_ALL_ATTACHED_IDS to indicate that
 *     all attached GPUs are to be detached.
 *     The entries in gpuIds[] must be contiguous, with a value of
 *     NV0000_CTRL_GPU_INVALID_ID to indicate the first invalid
 *     entry.
 *     If one or more of the gpuId values do not specify a GPU found
 *     in the system, the NV_ERR_INVALID_ARGUMENT error
 *     status is returned.
 *
 * If a table of gpuIds is provided, these gpuIds will be validated
 * against the RM's list of attached gpuIds; each valid gpuId is
 * detached immediately if it's no longer in use (i.e. if there are
 * no client references to the associated GPU in the form of
 * device class instantiations (see the NV01_DEVICE or NV03_DEVICE
 * descriptions for details)) and if no other client still requires
 * the associated GPU to be attached.
 *
 * If a given gpuId can't be detached immediately, it will instead
 * be detached when the last client reference is freed or when
 * the last client that issued NV0000_CTRL_CMD_GPU_ATTACH_IDS for
 * this gpuId either issues NV0000_CTRL_CMD_GPU_DETACH_IDS or exits
 * without detaching the gpuId explicitly.
 *
 * Clients may use the NV0000_CTRL_CMD_GPU_GET_ATTACHED_IDS command
 * to obtain a table of the attached gpuIds.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_OPERATING_SYSTEM
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 */
#define NV0000_CTRL_CMD_GPU_DETACH_IDS          (0x216) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_DETACH_IDS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_DETACH_ALL_ATTACHED_IDS (0x0000ffff)

#define NV0000_CTRL_GPU_DETACH_IDS_PARAMS_MESSAGE_ID (0x16U)

typedef struct NV0000_CTRL_GPU_DETACH_IDS_PARAMS {
    NvU32 gpuIds[NV0000_CTRL_GPU_MAX_ATTACHED_GPUS];
} NV0000_CTRL_GPU_DETACH_IDS_PARAMS;



/*
 * NV0000_CTRL_CMD_GPU_GET_SVM_SIZE
 *
 * This command is used to get the SVM size.
 *
 *   gpuId
 *     This parameter uniquely identifies the GPU whose associated
 *     SVM size is to be returned. The value of this field must
 *     match one of those in the table returned by
 *     NV0000_CTRL_CMD_GPU_GET_ATTACHED_IDS
 *
 *   SvmSize
 *     SVM size is returned in this.
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_STATE
 *
 */
#define NV0000_CTRL_CMD_GPU_GET_SVM_SIZE (0x240) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_SVM_SIZE_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_GET_SVM_SIZE_PARAMS_MESSAGE_ID (0x40U)

typedef struct NV0000_CTRL_GPU_GET_SVM_SIZE_PARAMS {
    NvU32 gpuId;
    NvU32 svmSize;
} NV0000_CTRL_GPU_GET_SVM_SIZE_PARAMS;



/*
 * NV0000_CTRL_CMD_GPU_GET_UUID_INFO
 *
 * This command returns requested information pertaining to the GPU
 * specified by the GPU UUID passed in.
 *
 * Generally only GPUs that have been attached are visible to this call. Therefore
 * queries on unattached GPUs will fail with NV_ERR_OBJECT_NOT_FOUND.  However, 
 * a query for a SHA1 UUID may succeed for an unattached GPU in cases where the GID
 * is cached, such as an excluded GPU.
 *
 *   gpuGuid (INPUT)
 *     The GPU UUID of the gpu whose parameters are to be returned. Refer to
 *     NV0000_CTRL_CMD_GPU_GET_ID_INFO for more information.
 *
 *   flags (INPUT)
 *     The _FORMAT* flags designate ascii string format or a binary format.
 *
 *     The _TYPE* flags designate either SHA-1-based (32-hex-character) or
 *     SHA-256-based (64-hex-character).
 *
 *   gpuId (OUTPUT)
 *     The GPU ID of the GPU identified by gpuGuid. Refer to
 *     NV0000_CTRL_CMD_GPU_GET_ID_INFO for more information.
 *
 *   deviceInstance (OUTPUT)
 *     The device instance of the GPU identified by gpuGuid. Refer to
 *     NV0000_CTRL_CMD_GPU_GET_ID_INFO for more information.
 *
 *   subdeviceInstance (OUTPUT)
 *     The subdevice instance of the GPU identified by gpuGuid. Refer to
 *     NV0000_CTRL_CMD_GPU_GET_ID_INFO for more information.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_OBJECT_NOT_FOUND
 *
 */
#define NV0000_CTRL_CMD_GPU_GET_UUID_INFO                                   (0x274) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_UUID_INFO_PARAMS_MESSAGE_ID" */

/* maximum possible number of bytes of GID information */
#define NV0000_GPU_MAX_GID_LENGTH                                           (0x00000100)

#define NV0000_CTRL_GPU_GET_UUID_INFO_PARAMS_MESSAGE_ID (0x74U)

typedef struct NV0000_CTRL_GPU_GET_UUID_INFO_PARAMS {
    NvU8  gpuUuid[NV0000_GPU_MAX_GID_LENGTH];
    NvU32 flags;
    NvU32 gpuId;
    NvU32 deviceInstance;
    NvU32 subdeviceInstance;
} NV0000_CTRL_GPU_GET_UUID_INFO_PARAMS;

#define NV0000_CTRL_CMD_GPU_GET_UUID_INFO_FLAGS_FORMAT                       1:0
#define NV0000_CTRL_CMD_GPU_GET_UUID_INFO_FLAGS_FORMAT_ASCII  (0x00000000)
#define NV0000_CTRL_CMD_GPU_GET_UUID_INFO_FLAGS_FORMAT_BINARY (0x00000002)

#define NV0000_CTRL_CMD_GPU_GET_UUID_INFO_FLAGS_TYPE                         2:2
#define NV0000_CTRL_CMD_GPU_GET_UUID_INFO_FLAGS_TYPE_SHA1     (0x00000000)
#define NV0000_CTRL_CMD_GPU_GET_UUID_INFO_FLAGS_TYPE_SHA256   (0x00000001)

/*
 * NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID
 *
 * This command returns the GPU UUID for the provided GPU ID.
 * Note that only GPUs that have been attached are visible to this call.
 * Therefore queries on unattached GPUs will fail
 * with NV_ERR_OBJECT_NOT_FOUND.
 *
 *   gpuId (INPUT)
 *     The GPU ID whose parameters are to be returned. Refer to
 *     NV0000_CTRL_CMD_GPU_GET_ID_INFO for more information.
 *
 *   flags (INPUT)
 *
 *     NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_FORMAT_ASCII
 *       This value is used to request the GPU UUID in ASCII format.
 *     NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_FORMAT_BINARY
 *       This value is used to request the GPU UUID in binary format.
 *
 *     NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_TYPE_SHA1
 *       This value is used to request that the GPU UUID value
 *       be SHA1-based (32-hex-character).
 *     NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_TYPE_SHA256
 *       This value is used to request that the GPU UUID value
 *       be SHA256-based (64-hex-character).
 *
 *   gpuUuid[NV0000_GPU_MAX_GID_LENGTH] (OUTPUT)
 *     The GPU UUID of the GPU identified by GPU ID. Refer to
 *     NV0000_CTRL_CMD_GPU_GET_ID_INFO for more information.
 *
 *   uuidStrLen (OUTPUT)
 *     The length of the UUID returned which is related to the format that
 *     was requested using flags.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_OBJECT_NOT_FOUND
 *   NV_ERR_OPERATING_SYSTEM
 */
#define NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID              (0x275) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_UUID_FROM_GPU_ID_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_GET_UUID_FROM_GPU_ID_PARAMS_MESSAGE_ID (0x75U)

typedef struct NV0000_CTRL_GPU_GET_UUID_FROM_GPU_ID_PARAMS {
    NvU32 gpuId;
    NvU32 flags;
    NvU8  gpuUuid[NV0000_GPU_MAX_GID_LENGTH];
    NvU32 uuidStrLen;
} NV0000_CTRL_GPU_GET_UUID_FROM_GPU_ID_PARAMS;

/* valid format values */
#define NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_FORMAT                       1:0
#define NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_FORMAT_ASCII  (0x00000000)
#define NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_FORMAT_BINARY (0x00000002)

/*valid type values*/
#define NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_TYPE                         2:2
#define NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_TYPE_SHA1     (0x00000000)
#define NV0000_CTRL_CMD_GPU_GET_UUID_FROM_GPU_ID_FLAGS_TYPE_SHA256   (0x00000001)



/*
 * NV0000_CTRL_CMD_GPU_MODIFY_DRAIN_STATE
 *
 * This command is used to enter or exit the so called "drain" state.
 * When this state is enabled, the existing clients continue executing
 * as usual, however no new client connections are allowed.
 * This is done in order to "drain" the system of the running clients
 * in preparation to selectively powering down the GPU.
 * No GPU can enter a bleed state if that GPU is in an SLI group.
 * In that case, NV_ERR_IN_USE is returned.
 * Requires administrator privileges.
 *
 * It is expected, that the "drain" state will be eventually deprecated
 * and replaced with another mechanism to quiesce a GPU (Bug 1718113).
 *
 *  gpuId (INPUT)
 *    This parameter should specify a valid GPU ID value.  If there
 *    is no GPU present with the specified ID, a status of
 *    NV_ERR_INVALID_ARGUMENT is returned.
 *  newState (INPUT)
 *    This input parameter is used to enter or exit the "drain"
 *    software state of the GPU specified by the gpuId parameter.
 *    Possible values are:
 *      NV0000_CTRL_GPU_DRAIN_STATE_ENABLED
 *      NV0000_CTRL_GPU_DRAIN_STATE_DISABLED
 *  flags (INPUT)
 *    NV0000_CTRL_GPU_DRAIN_STATE_FLAG_REMOVE_DEVICE
 *      if set, upon reaching quiescence, a request will be made to
 *      the OS to "forget" the PCI device associated with the
 *      GPU specified by the gpuId parameter, in case such a request
 *      is supported by the OS. Otherwise, NV_ERR_NOT_SUPPORTED
 *      will be returned.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INSUFFICIENT_PERMISSIONS
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_NOT_SUPPORTED
 *   NV_ERR_IN_USE
 */

#define NV0000_CTRL_CMD_GPU_MODIFY_DRAIN_STATE         (0x278) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_MODIFY_DRAIN_STATE_PARAMS_MESSAGE_ID" */

/* Possible values of newState */
#define NV0000_CTRL_GPU_DRAIN_STATE_DISABLED           (0x00000000)
#define NV0000_CTRL_GPU_DRAIN_STATE_ENABLED            (0x00000001)

/* Defined bits for the "flags" argument */
#define NV0000_CTRL_GPU_DRAIN_STATE_FLAG_REMOVE_DEVICE (0x00000001)
#define NV0000_CTRL_GPU_DRAIN_STATE_FLAG_LINK_DISABLE  (0x00000002)

#define NV0000_CTRL_GPU_MODIFY_DRAIN_STATE_PARAMS_MESSAGE_ID (0x78U)

typedef struct NV0000_CTRL_GPU_MODIFY_DRAIN_STATE_PARAMS {
    NvU32 gpuId;
    NvU32 newState;
    NvU32 flags;
} NV0000_CTRL_GPU_MODIFY_DRAIN_STATE_PARAMS;

/*
 * NV0000_CTRL_CMD_GPU_QUERY_DRAIN_STATE
 *
 *  gpuId (INPUT)
 *    This parameter should specify a valid GPU ID value.  If there
 *    is no GPU present with the specified ID, a status of
 *    NVOS_STATUS_ERROR_INVALID_ARGUMENT is returned.
 *  drainState (OUTPUT)
 *    This parameter returns a value indicating if the "drain"
 *    state is currently enabled or not for the specified GPU. See the
 *    description of NV0000_CTRL_CMD_GPU_MODIFY_DRAIN_STATE.
 *    Possible values are:
 *      NV0000_CTRL_GPU_DRAIN_STATE_ENABLED
 *      NV0000_CTRL_GPU_DRAIN_STATE_DISABLED
 *  flags (OUTPUT)
 *    NV0000_CTRL_GPU_DRAIN_STATE_FLAG_REMOVE_DEVICE
 *      if set, upon reaching quiesence, the GPU device will be
 *      removed automatically from the kernel space, similar
 *      to what writing "1" to the sysfs "remove" node does.
 *    NV0000_CTRL_GPU_DRAIN_STATE_FLAG_LINK_DISABLE
 *      after removing the GPU, also disable the parent bridge's
 *      PCIe link. This flag can only be set in conjunction with
 *      NV0000_CTRL_GPU_DRAIN_STATE_FLAG_REMOVE_DEVICE, and then
 *      only when the GPU is already idle (not attached).
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 */

#define NV0000_CTRL_CMD_GPU_QUERY_DRAIN_STATE (0x279) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_QUERY_DRAIN_STATE_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_QUERY_DRAIN_STATE_PARAMS_MESSAGE_ID (0x79U)

typedef struct NV0000_CTRL_GPU_QUERY_DRAIN_STATE_PARAMS {
    NvU32 gpuId;
    NvU32 drainState;
    NvU32 flags;
} NV0000_CTRL_GPU_QUERY_DRAIN_STATE_PARAMS;

/*
 * NV0000_CTRL_CMD_GPU_DISCOVER
 *
 * This request asks the OS to scan the PCI tree or a sub-tree for GPUs,
 * that are not yet known to the OS, and to make them available for use.
 * If all of domain:bus:slot.function are zeros, the entire tree is scanned,
 * otherwise the parameters identify the bridge device, that roots the
 * subtree to be scanned.
 * Requires administrator privileges.
 *
 *  domain (INPUT)
 *    PCI domain of the bridge
 *  bus (INPUT)
 *    PCI bus of the bridge
 *  slot (INPUT)
 *    PCI slot of the bridge
 *  function (INPUT)
 *    PCI function of the bridge
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_DEVICE
 *   NV_ERR_INSUFFICIENT_PERMISSIONS
 *   NV_ERR_OPERATING_SYSTEM
 *   NV_ERR_NOT_SUPPORTED
 */

#define NV0000_CTRL_CMD_GPU_DISCOVER (0x27a) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | 0x7A" */

typedef struct NV0000_CTRL_GPU_DISCOVER_PARAMS {
    NvU32 domain;
    NvU8  bus;
    NvU8  slot;
    NvU8  function;
} NV0000_CTRL_GPU_DISCOVER_PARAMS;

/*
 * NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE
 *
 * This command is used to get the content of the MemOp (CUDA Memory Operation)
 * enablement mask, which can be overridden by using the MemOpOverride RegKey.
 *
 * The enableMask member must be treated as a bitmask, where each bit controls
 * the enablement of a feature.
 *
 * So far, the only feature which is defined controls to whole MemOp APIs.
 *
 * Possible status values returned are:
 *   NV_OK
 *
 */
#define NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE (0x27b) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS_MESSAGE_ID (0x7BU)

typedef struct NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS {
    NvU32 enableMask;
} NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS;

#define NV0000_CTRL_GPU_FLAGS_MEMOP_ENABLE   (0x00000001)



/*
 * NV0000_CTRL_CMD_GPU_DISABLE_NVLINK_INIT
 *
 * This privileged command is used to disable initialization for the NVLinks
 * provided in the mask.
 *
 * The mask must be applied before the GPU is attached. DISABLE_NVLINK_INIT
 * is an NOP for non-NVLink GPUs.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_DEVICE
 *   NV_ERR_INSUFFICIENT_PERMISSIONS
 *   NV_ERR_INVALID_STATE
 *   NV_ERR_IN_USE
 *
 */
#define NV0000_CTRL_CMD_GPU_DISABLE_NVLINK_INIT (0x281) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_DISABLE_NVLINK_INIT_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_DISABLE_NVLINK_INIT_PARAMS_MESSAGE_ID (0x81U)

typedef struct NV0000_CTRL_GPU_DISABLE_NVLINK_INIT_PARAMS {
    NvU32  gpuId;
    NvU32  mask;
    NvBool bSkipHwNvlinkDisable;
} NV0000_CTRL_GPU_DISABLE_NVLINK_INIT_PARAMS;


#define NV0000_CTRL_GPU_LEGACY_CONFIG_MAX_PARAM_DATA     0x00000175
#define NV0000_CTRL_GPU_LEGACY_CONFIG_MAX_PROPERTIES_IN  6
#define NV0000_CTRL_GPU_LEGACY_CONFIG_MAX_PROPERTIES_OUT 5

/*
 * NV0000_CTRL_CMD_GPU_LEGACY_CONFIG
 *
 * Path to use legacy RM GetConfig/Set API. This API is being phased out.
 */
#define NV0000_CTRL_CMD_GPU_LEGACY_CONFIG                (0x282) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_LEGACY_CONFIG_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_LEGACY_CONFIG_PARAMS_MESSAGE_ID (0x82U)

typedef struct NV0000_CTRL_GPU_LEGACY_CONFIG_PARAMS {
    NvHandle hContext;    /* [in]  - Handle of object to perform operation on (Device, Subdevice, etc) */
    NvU32    opType;      /* [in]  - Type of API */
    NvV32    index;       /* [in]  - command type */
    NvU32    dataType;    /* [out] - data union type */

    union {
        struct {
            NvV32 value;
        } configGet;
        struct {
            NvU32 newValue;
            NvU32 oldValue;
        } configSet;
        struct {
            NvU8  paramData[NV0000_CTRL_GPU_LEGACY_CONFIG_MAX_PARAM_DATA];
            NvU32 paramSize;
        } configEx;
        struct {
            NvU32 propertyId;
            NvU32 propertyIn[NV0000_CTRL_GPU_LEGACY_CONFIG_MAX_PROPERTIES_IN];
            NvU32 propertyOut[NV0000_CTRL_GPU_LEGACY_CONFIG_MAX_PROPERTIES_OUT];
        } reservedProperty;
    } data;
} NV0000_CTRL_GPU_LEGACY_CONFIG_PARAMS;

#define NV0000_CTRL_GPU_LEGACY_CONFIG_OP_TYPE_GET      (0x00000000)
#define NV0000_CTRL_GPU_LEGACY_CONFIG_OP_TYPE_SET      (0x00000001)
#define NV0000_CTRL_GPU_LEGACY_CONFIG_OP_TYPE_GET_EX   (0x00000002)
#define NV0000_CTRL_GPU_LEGACY_CONFIG_OP_TYPE_SET_EX   (0x00000003)
#define NV0000_CTRL_GPU_LEGACY_CONFIG_OP_TYPE_RESERVED (0x00000004)

/*
 * NV0000_CTRL_CMD_IDLE_CHANNELS
 */
#define NV0000_CTRL_CMD_IDLE_CHANNELS                  (0x283) /* finn: Evaluated from "(FINN_NV01_ROOT_GPU_INTERFACE_ID << 8) | NV0000_CTRL_GPU_IDLE_CHANNELS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_GPU_IDLE_CHANNELS_PARAMS_MESSAGE_ID (0x83U)

typedef struct NV0000_CTRL_GPU_IDLE_CHANNELS_PARAMS {
    NvHandle hDevice;
    NvHandle hChannel;
    NvU32    numChannels;
    /* C form: NvP64 phClients NV_ALIGN_BYTES(8); */
    NV_DECLARE_ALIGNED(NvP64 phClients, 8);
    /* C form: NvP64 phDevices NV_ALIGN_BYTES(8); */
    NV_DECLARE_ALIGNED(NvP64 phDevices, 8);
    /* C form: NvP64 phChannels NV_ALIGN_BYTES(8); */
    NV_DECLARE_ALIGNED(NvP64 phChannels, 8);
    NvV32    flags;
    NvV32    timeout;
} NV0000_CTRL_GPU_IDLE_CHANNELS_PARAMS;

/* _ctrl0000gpu_h_ */

