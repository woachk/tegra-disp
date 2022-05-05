/*
 * SPDX-FileCopyrightText: Copyright (c) 2004-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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
// Source file: ctrl/ctrl0080/ctrl0080gpu.finn
//




#include "ctrl/ctrl0080/ctrl0080base.h"
#include "nvlimits.h"


/* NV01_DEVICE_XX/NV03_DEVICE gpu control commands and parameters */

/*
 * NV0080_CTRL_CMD_GPU_GET_CLASSLIST
 *
 * This command returns supported class information for the specified device.
 * If the device is comprised of more than one GPU, the class list represents
 * the set of supported classes common to all GPUs within the device.
 *
 * It has two modes:
 *
 * If the classList pointer is NULL, then this command returns the number
 * of classes supported by the device in the numClasses field.  The value
 * should then be used by the client to allocate a classList buffer
 * large enough to hold one 32bit value per numClasses entry.
 *
 * If the classList pointer is non-NULL, then this command returns the
 * set of supported class numbers in the specified buffer.
 *
 *   numClasses
 *     If classList is NULL, then this parameter will return the
 *     number of classes supported by the device.  If classList is non-NULL,
 *     then this parameter indicates the number of entries in classList.
 *   classList
 *     This parameter specifies a pointer to the client's buffer into
 *     which the supported class numbers should be returned.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_OPERATING_SYSTEM
 */
#define NV0080_CTRL_CMD_GPU_GET_CLASSLIST (0x800201) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_GET_CLASSLIST_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_GET_CLASSLIST_PARAMS_MESSAGE_ID (0x1U)

typedef struct NV0080_CTRL_GPU_GET_CLASSLIST_PARAMS {
    NvU32 numClasses;
    NV_DECLARE_ALIGNED(NvP64 classList, 8);
} NV0080_CTRL_GPU_GET_CLASSLIST_PARAMS;

/**
 * NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES
 *
 * This command returns the number of subdevices for the device.
 *
 *   numSubDevices
 *     This parameter returns the number of subdevices within the device.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES (0x800280) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_GET_NUM_SUBDEVICES_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_GET_NUM_SUBDEVICES_PARAMS_MESSAGE_ID (0x80U)

typedef struct NV0080_CTRL_GPU_GET_NUM_SUBDEVICES_PARAMS {
    NvU32 numSubDevices;
} NV0080_CTRL_GPU_GET_NUM_SUBDEVICES_PARAMS;

/*
 * NV0080_CTRL_CMD_GPU_GET_VIDLINK_ORDER
 *
 * This command returns the video link order of each subdevice id inside the
 * device.  This call can only be made after SLI is enabled.  This call is
 * intended for 3D clients to use to determine the vidlink order of the
 * devices.  The Display Output Parent will always be the first subdevice
 * mask listed in the array.  Note that this command should not be used in
 * case of bridgeless SLI.  The order of the subdevices returned by this
 * command will not be correct in case of bridgeless SLI.
 *
 *   ConnectionCount
 *     Each HW can provide 1 or 2 links between all GPUs in a device.  This
 *     number tells how many links are available between GPUs.  This data
 *     also represents the number of concurrent SLI heads that can run at
 *     the same time over this one device.
 *
 *   Order
 *     This array returns the order of subdevices that are used through
 *     the vidlink for display output.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV0080_CTRL_CMD_GPU_GET_VIDLINK_ORDER (0x800281) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_GET_VIDLINK_ORDER_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_GET_VIDLINK_ORDER_PARAMS_MESSAGE_ID (0x81U)

typedef struct NV0080_CTRL_GPU_GET_VIDLINK_ORDER_PARAMS {
    NvU32 ConnectionCount;
    NvU32 Order[NV_MAX_SUBDEVICES];
} NV0080_CTRL_GPU_GET_VIDLINK_ORDER_PARAMS;

/*
 * NV0080_CTRL_CMD_GPU_SET_DISPLAY_OWNER
 *
 * This command sets display ownership within the device to the specified
 * subdevice instance.  The actual transfer of display ownership will take
 * place at the next modeset.
 *
 *   subDeviceInstance
 *     This member specifies the subdevice instance of the new display
 *     owner.  The subdevice instance must be in the legal range
 *     indicated by the NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES command.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV0080_CTRL_CMD_GPU_SET_DISPLAY_OWNER (0x800282) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_SET_DISPLAY_OWNER_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_SET_DISPLAY_OWNER_PARAMS_MESSAGE_ID (0x82U)

typedef struct NV0080_CTRL_GPU_SET_DISPLAY_OWNER_PARAMS {
    NvU32 subDeviceInstance;
} NV0080_CTRL_GPU_SET_DISPLAY_OWNER_PARAMS;

/*
 * NV0080_CTRL_CMD_GPU_GET_DISPLAY_OWNER
 *
 * This command returns the subdevice instance of the current display owner
 * within the device.
 *
 *   subDeviceInstance
 *     This member returns the subdevice instance of the current display
 *     owner.  The subdevice instance will be in the legal range
 *     indicated by the NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES command.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV0080_CTRL_CMD_GPU_GET_DISPLAY_OWNER (0x800283) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_GET_DISPLAY_OWNER_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_GET_DISPLAY_OWNER_PARAMS_MESSAGE_ID (0x83U)

typedef struct NV0080_CTRL_GPU_GET_DISPLAY_OWNER_PARAMS {
    NvU32 subDeviceInstance;
} NV0080_CTRL_GPU_GET_DISPLAY_OWNER_PARAMS;

/*
 * NV0080_CTRL_CMD_GPU_SET_VIDLINK
 *
 * This command enables or disables the VIDLINK of all subdevices in the
 * current SLI configuration.
 *
 *   enable
 *     Enables or disables the vidlink
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 */
#define NV0080_CTRL_CMD_GPU_SET_VIDLINK (0x800285) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_SET_VIDLINK_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_SET_VIDLINK_PARAMS_MESSAGE_ID (0x85U)

typedef struct NV0080_CTRL_GPU_SET_VIDLINK_PARAMS {
    NvU32 enable;
} NV0080_CTRL_GPU_SET_VIDLINK_PARAMS;

#define NV0080_CTRL_GPU_SET_VIDLINK_ENABLE_FALSE                 (0x00000000)
#define NV0080_CTRL_GPU_SET_VIDLINK_ENABLE_TRUE                  (0x00000001)

/* commands */
#define NV0080_CTRL_CMD_GPU_VIDEO_POWERGATE_GET_STATUS           0
#define NV0080_CTRL_CMD_GPU_VIDEO_POWERGATE_POWERDOWN            1
#define NV0080_CTRL_CMD_GPU_VIDEO_POWERGATE_POWERUP              2

/* status */
#define NV0080_CTRL_CMD_GPU_VIDEO_POWERGATE_STATUS_POWER_ON      0
#define NV0080_CTRL_CMD_GPU_VIDEO_POWERGATE_STATUS_POWERING_DOWN 1
#define NV0080_CTRL_CMD_GPU_VIDEO_POWERGATE_STATUS_GATED         2
#define NV0080_CTRL_CMD_GPU_VIDEO_POWERGATE_STATUS_POWERING_UP   3

/*
 * NV0080_CTRL_CMD_GPU_MODIFY_SW_STATE_PERSISTENCE
 *
 * This command is used to enable or disable the persistence of a GPU's
 * software state when no clients exist. With persistent software state enabled
 * the GPU's software state is not torn down when the last client exits, but is
 * retained until either the kernel module unloads or persistent software state
 * is disabled.
 *
 *  newState
 *    This input parameter is used to enable or disable the persistence of the
 *    software state of all subdevices within the device.
 *    Possible values are:
 *      NV0080_CTRL_GPU_SW_STATE_PERSISTENCE_ENABLED
 *      NV0080_CTRL_GPU_SW_STATE_PERSISTENCE_DISABLED
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 */

#define NV0080_CTRL_CMD_GPU_MODIFY_SW_STATE_PERSISTENCE          (0x800287) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_MODIFY_SW_STATE_PERSISTENCE_PARAMS_MESSAGE_ID" */

/* Possible values of persistentSwState */
#define NV0080_CTRL_GPU_SW_STATE_PERSISTENCE_ENABLED             (0x00000000)
#define NV0080_CTRL_GPU_SW_STATE_PERSISTENCE_DISABLED            (0x00000001)

#define NV0080_CTRL_GPU_MODIFY_SW_STATE_PERSISTENCE_PARAMS_MESSAGE_ID (0x87U)

typedef struct NV0080_CTRL_GPU_MODIFY_SW_STATE_PERSISTENCE_PARAMS {
    NvU32 newState;
} NV0080_CTRL_GPU_MODIFY_SW_STATE_PERSISTENCE_PARAMS;

/*
 * NV0080_CTRL_CMD_GPU_QUERY_SW_STATE_PERSISTENCE
 *
 *   swStatePersistence
 *     This parameter returns a value indicating if persistent software
 *     state is currently enabled or not for the specified GPU. See the
 *     description of NV0080_CTRL_CMD_GPU_MODIFY_SW_STATE_PERSISTENCE.
 *     Possible values are:
 *       NV0080_CTRL_GPU_SW_STATE_PERSISTENCE_ENABLED
 *       NV0080_CTRL_GPU_SW_STATE_PERSISTENCE_DISABLED
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 */

#define NV0080_CTRL_CMD_GPU_QUERY_SW_STATE_PERSISTENCE (0x800288) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_QUERY_SW_STATE_PERSISTENCE_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_QUERY_SW_STATE_PERSISTENCE_PARAMS_MESSAGE_ID (0x88U)

typedef struct NV0080_CTRL_GPU_QUERY_SW_STATE_PERSISTENCE_PARAMS {
    NvU32 swStatePersistence;
} NV0080_CTRL_GPU_QUERY_SW_STATE_PERSISTENCE_PARAMS;

/**
 * NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE
 *
 * This command returns a value indicating virtualization mode in
 * which the GPU is running.
 *
 *   virtualizationMode
 *     This parameter returns the virtualization mode of the device.
 *     Possible values are:
 *       NV0080_CTRL_GPU_VIRTUALIZATION_MODE_NONE
 *         This value indicates that there is no virtualization mode associated with the
 *         device (i.e. it's a baremetal GPU).
 *       NV0080_CTRL_GPU_VIRTUALIZATION_MODE_NMOS
 *         This value indicates that the device is associated with the NMOS.
 *       NV0080_CTRL_GPU_VIRTUALIZATION_MODE_VGX
 *         This value indicates that the device is associated with VGX(guest GPU).
 *       NV0080_CTRL_GPU_VIRTUALIZATION_MODE_HOST
 *       NV0080_CTRL_GPU_VIRTUALIZATION_MODE_HOST_VGPU
 *         This value indicates that the device is associated with vGPU(host GPU).
 *       NV0080_CTRL_GPU_VIRTUALIZATION_MODE_HOST_VSGA
 *         This value indicates that the device is associated with vSGA(host GPU).
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 */
#define NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE   (0x800289) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_GET_VIRTUALIZATION_MODE_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_VIRTUALIZATION_MODE_NONE      (0x00000000)
#define NV0080_CTRL_GPU_VIRTUALIZATION_MODE_NMOS      (0x00000001)
#define NV0080_CTRL_GPU_VIRTUALIZATION_MODE_VGX       (0x00000002)
#define NV0080_CTRL_GPU_VIRTUALIZATION_MODE_HOST      (0x00000003)
#define NV0080_CTRL_GPU_VIRTUALIZATION_MODE_HOST_VGPU NV0080_CTRL_GPU_VIRTUALIZATION_MODE_HOST
#define NV0080_CTRL_GPU_VIRTUALIZATION_MODE_HOST_VSGA (0x00000004)

#define NV0080_CTRL_GPU_GET_VIRTUALIZATION_MODE_PARAMS_MESSAGE_ID (0x89U)

typedef struct NV0080_CTRL_GPU_GET_VIRTUALIZATION_MODE_PARAMS {
    NvU32 virtualizationMode;
} NV0080_CTRL_GPU_GET_VIRTUALIZATION_MODE_PARAMS;



// Update this macro if new HW exceeds GPU Classlist MAX_SIZE
#define NV0080_CTRL_GPU_CLASSLIST_MAX_SIZE   116

#define NV0080_CTRL_CMD_GPU_GET_CLASSLIST_V2 (0x800292) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS_MESSAGE_ID (0x92U)

typedef struct NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS {
    NvU32 numClasses;                                       // __OUT__
    NvU32 classList[NV0080_CTRL_GPU_CLASSLIST_MAX_SIZE];    // __OUT__
} NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS;

/*
 * NV0080_CTRL_CMD_GPU_FIND_SUBDEVICE_HANDLE
 *
 * Find a subdevice handle allocated under this device
 */
#define NV0080_CTRL_CMD_GPU_FIND_SUBDEVICE_HANDLE (0x800293) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_FIND_SUBDEVICE_HANDLE_PARAM_MESSAGE_ID" */

#define NV0080_CTRL_GPU_FIND_SUBDEVICE_HANDLE_PARAM_MESSAGE_ID (0x93U)

typedef struct NV0080_CTRL_GPU_FIND_SUBDEVICE_HANDLE_PARAM {
    NvU32    subDeviceInst;         // [in]
    NvHandle hSubDevice;            // [out]
} NV0080_CTRL_GPU_FIND_SUBDEVICE_HANDLE_PARAM;

/*
 * NV0080_CTRL_CMD_GPU_GET_BRAND_CAPS
 *
 * This command gets branding information for the device.
 *
 *   brands
 *     Mask containing branding information. A bit in this
 *     mask is set if the GPU has particular branding.
 *
 * Possible status values returned are:
 *   NV_OK
 */

#define NV0080_CTRL_GPU_GET_BRAND_CAPS_QUADRO    NVBIT(0)
#define NV0080_CTRL_GPU_GET_BRAND_CAPS_NVS       NVBIT(1)
#define NV0080_CTRL_GPU_GET_BRAND_CAPS_TITAN     NVBIT(2)

#define NV0080_CTRL_CMD_GPU_GET_BRAND_CAPS (0x800294) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_GPU_INTERFACE_ID << 8) | NV0080_CTRL_GPU_GET_BRAND_CAPS_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_GPU_GET_BRAND_CAPS_PARAMS_MESSAGE_ID (0x94U)

typedef struct NV0080_CTRL_GPU_GET_BRAND_CAPS_PARAMS {
    NvU32 brands;
} NV0080_CTRL_GPU_GET_BRAND_CAPS_PARAMS;

/* _ctrl0080gpu_h_ */
