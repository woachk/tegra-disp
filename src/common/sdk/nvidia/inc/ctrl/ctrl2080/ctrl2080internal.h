/*
 * SPDX-FileCopyrightText: Copyright (c) 2020-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

//
// This file was generated with FINN, an NVIDIA coding tool.
// Source file: ctrl/ctrl2080/ctrl2080internal.finn
//

#include "nvimpshared.h"



#include "ctrl/ctrl2080/ctrl2080base.h"

#include "ctrl/ctrl2080/ctrl2080gpu.h"
#include "ctrl/ctrl2080/ctrl2080gr.h"        /* Some controls derivative of 2080gr */
#include "ctrl/ctrl0080/ctrl0080msenc.h"     /* NV0080_CTRL_MSENC_CAPS_TBL_SIZE    */
#include "ctrl/ctrl0080/ctrl0080bsp.h"       /* NV0080_CTRL_BSP_CAPS_TBL_SIZE      */
#include "ctrl/ctrl2080/ctrl2080fifo.h"      /* NV2080_CTRL_FIFO_UPDATE_CHANNEL_INFO */
/*!
 * NV2080_CTRL_CMD_INTERNAL_DISPLAY_GET_STATIC_INFO
 *
 *    This command obtains information from physical RM for use by CPU-RM.
 *
 *   feHwSysCap
 *     Display IP v03_00 and later.
 *     Contents of capability register.
 *
 *   windowPresentMask
 *     Display IP v03_00 and later.
 *     Mask for the present WINDOWs actually on the current chip.
 *   bFbRemapperEnabled
 *     Display IP v02_01 and later.
 *     Indicates that the display remapper HW exists and is enabled.
 */

#define NV2080_CTRL_CMD_INTERNAL_DISPLAY_GET_STATIC_INFO (0x20800a01) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_DISPLAY_GET_STATIC_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_DISPLAY_GET_STATIC_INFO_PARAMS_MESSAGE_ID (0x1U)

typedef struct NV2080_CTRL_INTERNAL_DISPLAY_GET_STATIC_INFO_PARAMS {
    NvU32  feHwSysCap;
    NvU32  windowPresentMask;
    NvBool bFbRemapperEnabled;
} NV2080_CTRL_INTERNAL_DISPLAY_GET_STATIC_INFO_PARAMS;



/*
 * NV2080_CTRL_INTERNAL_GPU_GET_CHIP_INFO_PARAMS
 *
 * This command obtains information from physical RM for use by CPU-RM.
 */

#define NV2080_CTRL_CMD_INTERNAL_GPU_GET_CHIP_INFO (0x20800a36) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_GPU_GET_CHIP_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_GPU_GET_CHIP_INFO_PARAMS_MESSAGE_ID (0x36U)

typedef struct NV2080_CTRL_INTERNAL_GPU_GET_CHIP_INFO_PARAMS {
    NvU8   chipSubRev;
    NvU32  emulationRev1;
    NvBool isCmpSku;
} NV2080_CTRL_INTERNAL_GPU_GET_CHIP_INFO_PARAMS;


/**
 * NV2080_CTRL_CMD_INTERNAL_GET_DEVICE_INFO_TABLE
 * 
 * Parse the DEVICE_INFO2_TABLE on the physical side and return it to kernel.
 */
typedef struct NV2080_CTRL_INTERNAL_DEVICE_INFO {
    NvU32 faultId;
    NvU32 instanceId;
    NvU32 typeEnum;
    NvU32 resetId;
    NvU32 devicePriBase;
    NvU32 isEngine;
    NvU32 rlEngId;
    NvU32 runlistPriBase;
} NV2080_CTRL_INTERNAL_DEVICE_INFO;
#define NV2080_CTRL_CMD_INTERNAL_DEVICE_INFO_MAX_ENTRIES 88

#define NV2080_CTRL_CMD_INTERNAL_GET_DEVICE_INFO_TABLE   (0x20800a40) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_MESSAGE_ID (0x40U)

typedef struct NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS {
    NvU32                            numEntries;
    NV2080_CTRL_INTERNAL_DEVICE_INFO deviceInfoTable[NV2080_CTRL_CMD_INTERNAL_DEVICE_INFO_MAX_ENTRIES];
} NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS;



/*!
 * NV2080_CTRL_CMD_INTERNAL_DISPLAY_WRITE_INST_MEM
 *
 *   This command writes instance memory information in the display hardware registers.
 *
 *   instMemPhysAddr
 *     GPU physical address or IOVA address of the display instance memory.
 *
 *   instMemSize
 *     Size of the display instance memory.
 *
 *   instMemAddrSpace
 *     Address space of the display instance memory.
 *
 *   instMemCpuCacheAttr
 *     Cache attribute of the display instance memory.
 */
#define NV2080_CTRL_CMD_INTERNAL_DISPLAY_WRITE_INST_MEM (0x20800a49) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_DISPLAY_WRITE_INST_MEM_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_DISPLAY_WRITE_INST_MEM_PARAMS_MESSAGE_ID (0x49U)

typedef struct NV2080_CTRL_INTERNAL_DISPLAY_WRITE_INST_MEM_PARAMS {
    NV_DECLARE_ALIGNED(NvU64 instMemPhysAddr, 8);
    NV_DECLARE_ALIGNED(NvU64 instMemSize, 8);
    NvU32 instMemAddrSpace;
    NvU32 instMemCpuCacheAttr;
} NV2080_CTRL_INTERNAL_DISPLAY_WRITE_INST_MEM_PARAMS;

/*
 * NV2080_CTRL_INTERNAL_GPU_RECOVER_ALL_COMPUTE_CONTEXTS
 *
 * This command issues RC recovery for all compute contexts running on the given GPU.
 */
#define NV2080_CTRL_CMD_INTERNAL_RECOVER_ALL_COMPUTE_CONTEXTS (0x20800a4a) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x4A" */

/*!
 * NV2080_CTRL_CMD_INTERNAL_DISPLAY_GET_IP_VERSION
 *
 *    This command obtains IP version of display engine for use by Kernel RM.
 *
 *   ipVersion
 *     IP Version of display engine.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED - DISP has been disabled
 */
#define NV2080_CTRL_CMD_INTERNAL_DISPLAY_GET_IP_VERSION       (0x20800a4b) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_DISPLAY_GET_IP_VERSION_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_DISPLAY_GET_IP_VERSION_PARAMS_MESSAGE_ID (0x4BU)

typedef struct NV2080_CTRL_INTERNAL_DISPLAY_GET_IP_VERSION_PARAMS {
    NvU32 ipVersion;
} NV2080_CTRL_INTERNAL_DISPLAY_GET_IP_VERSION_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_GPU_GET_SMC_MODE
 *
 *  This command determines the current status of SMC MODE from Physical RM.
 *
 *  smcMode [OUT]
 *     Current SMC MODE of the GPU. Values range NV2080_CTRL_GPU_INFO_GPU_SMC_MODE*
 */
#define NV2080_CTRL_CMD_INTERNAL_GPU_GET_SMC_MODE (0x20800a4c) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_GPU_GET_SMC_MODE_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_GPU_GET_SMC_MODE_PARAMS_MESSAGE_ID (0x4CU)

typedef struct NV2080_CTRL_INTERNAL_GPU_GET_SMC_MODE_PARAMS {
    NvU32 smcMode;
} NV2080_CTRL_INTERNAL_GPU_GET_SMC_MODE_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_DISPLAY_SETUP_RG_LINE_INTR
 *
 *   head
 *     This parameter specifies the head for which the callback is to be registered/unregistered. This value must be
 *     less than the maximum number of heads supported by the GPU subdevice.
 *
 *   rgLineNum
 *     This indicates the RG scanout line number on which the callback will be executed.
 *
 *   intrLine
 *     Enable: [out] Which interrupt line was allocated for this head.
 *     Disable: [in] Which interrupt line to deallocate.
 *
 *   bEnable
 *     Should we allocate or deallocate an interrupt line?
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_GENERIC - There was no available interrupt to allocate.
 *   NV_ERR_INVALID_ARGUMENT
 */

#define NV2080_CTRL_CMD_INTERNAL_DISPLAY_SETUP_RG_LINE_INTR (0x20800a4d) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_DISPLAY_SETUP_RG_LINE_INTR_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_DISPLAY_SETUP_RG_LINE_INTR_PARAMS_MESSAGE_ID (0x4DU)

typedef struct NV2080_CTRL_INTERNAL_DISPLAY_SETUP_RG_LINE_INTR_PARAMS {
    NvU32  head;
    NvU32  rgLineNum;
    NvU32  intrLine;
    NvBool bEnable;
} NV2080_CTRL_INTERNAL_DISPLAY_SETUP_RG_LINE_INTR_PARAMS;



#define NV2080_CTRL_CMD_INTERNAL_DISPLAY_SET_IMP_INIT_INFO (0x20800a54) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_DISPLAY_SET_IMP_INIT_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_DISPLAY_SET_IMP_INIT_INFO_PARAMS_MESSAGE_ID (0x54U)

typedef struct NV2080_CTRL_INTERNAL_DISPLAY_SET_IMP_INIT_INFO_PARAMS {
    TEGRA_IMP_IMPORT_DATA tegraImpImportData;
} NV2080_CTRL_INTERNAL_DISPLAY_SET_IMP_INIT_INFO_PARAMS;



/*!
 * NV2080_CTRL_CMD_INTERNAL_DISPLAY_CHANNEL_PUSHBUFFER
 *
 * Pass required pushbuffer parameters from kernel RM to Physical RM
 *
 *   addressSpace [IN]
 *     Address space of pushbuffer whtether it is ADDR_SYSMEM or ADDR_FBMEM
 *
 *   physicalAddr [IN]
 *     Physical address of pushbuffer
 *
 *   addressSpace [IN]
 *     Limit of the pushbuffer address, it should be less than 4K
 *
 *   cacheSnoop [IN]
 *     Cachesnoop supported or not
 *
 *   channelInstance [IN]
 *     Channel instance pass by the client to get corresponding dispchannel
 *
 *   hclass [IN]
 *     External class ID pass by the client to get the channel class
 *
 *   valid [IN]
 *     This bit indicates whether pushbuffer parameters are valid or not
 *
 */
#define NV2080_CTRL_CMD_INTERNAL_DISPLAY_CHANNEL_PUSHBUFFER (0x20800a58) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_DISPLAY_CHANNEL_PUSHBUFFER_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_DISPLAY_CHANNEL_PUSHBUFFER_PARAMS_MESSAGE_ID (0x58U)

typedef struct NV2080_CTRL_INTERNAL_DISPLAY_CHANNEL_PUSHBUFFER_PARAMS {
    NvU32  addressSpace;
    NV_DECLARE_ALIGNED(NvU64 physicalAddr, 8);
    NV_DECLARE_ALIGNED(NvU64 limit, 8);
    NvU32  cacheSnoop;
    NvU32  hclass;
    NvU32  channelInstance;
    NvBool valid;
} NV2080_CTRL_INTERNAL_DISPLAY_CHANNEL_PUSHBUFFER_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_GMMU_GET_STATIC_INFO
 *
 *   This command obtains information from physical RM for use by CPU-RM.
 *
 *   replayableFaultBufferSize
 *     Default size of replayable fault buffer
 *
 *   nonReplayableFaultBufferSize
 *     Default size of non-replayable fault buffer
 *
 */

#define NV2080_CTRL_CMD_INTERNAL_GMMU_GET_STATIC_INFO (0x20800a59) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_GMMU_GET_STATIC_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_GMMU_GET_STATIC_INFO_PARAMS_MESSAGE_ID (0x59U)

typedef struct NV2080_CTRL_INTERNAL_GMMU_GET_STATIC_INFO_PARAMS {
    NvU32 replayableFaultBufferSize;
    NvU32 nonReplayableFaultBufferSize;
} NV2080_CTRL_INTERNAL_GMMU_GET_STATIC_INFO_PARAMS;

/*!
 * @ref NV2080_CTRL_CMD_GR_GET_CTXSW_MODES
 */
#define NV2080_CTRL_CMD_INTERNAL_GR_GET_CTXSW_MODES           (0x20800a5a) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x5A" */

/*!
 * NV2080_CTRL_CMD_INTERNAL_FB_GET_HEAP_RESERVATION_SIZE
 *
 * Get heap reservation size needed by different module
 */
#define NV2080_CTRL_CMD_INTERNAL_FB_GET_HEAP_RESERVATION_SIZE (0x20800a5b) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x5B" */

typedef struct NV2080_CTRL_INTERNAL_FB_GET_HEAP_RESERVATION_SIZE_PARAMS {
    NvU32 moduleIndex;
    NvU32 size;
} NV2080_CTRL_INTERNAL_FB_GET_HEAP_RESERVATION_SIZE_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_INTR_GET_KERNEL_TABLE
 *
 *   tableLen [OUT]
 *     Number of valid records in table field.
 *
 *   table    [OUT]
 *     Interrupt table for Kernel RM.
 */
#define NV2080_CTRL_CMD_INTERNAL_INTR_GET_KERNEL_TABLE (0x20800a5c) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x5C" */

#define NV2080_CTRL_INTERNAL_INTR_MAX_TABLE_SIZE       128

typedef struct NV2080_CTRL_INTERNAL_INTR_GET_KERNEL_TABLE_ENTRY {
    NvU16 engineIdx;
    NvU32 pmcIntrMask;
    NvU32 vectorStall;
    NvU32 vectorNonStall;
} NV2080_CTRL_INTERNAL_INTR_GET_KERNEL_TABLE_ENTRY;

#define NV2080_CTRL_INTERNAL_INTR_GET_KERNEL_TABLE_PARAMS_MESSAGE_ID (0x5CU)

typedef struct NV2080_CTRL_INTERNAL_INTR_GET_KERNEL_TABLE_PARAMS {
    NvU32                                            tableLen;
    NV2080_CTRL_INTERNAL_INTR_GET_KERNEL_TABLE_ENTRY table[NV2080_CTRL_INTERNAL_INTR_MAX_TABLE_SIZE];
} NV2080_CTRL_INTERNAL_INTR_GET_KERNEL_TABLE_PARAMS;

/* Index to retrieve the needed heap space for specific module */
#define NV2080_CTRL_INTERNAL_FB_GET_HEAP_RESERVATION_SIZE_GR           (0x00000000)

/*
 * NV2080_CTRL_CMD_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_CHECK
 *
 * Checking if the reservation / release of the PERFMON HW is possible
 *
 *   bReservation [IN]
 *     NV_TRUE -> request for reservation, NV_FALSE -> request for release
 *
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_CHECK (0x20800a98) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_CHECK_PARAMS_MESSAGE_ID" */


#define NV2080_CTRL_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_CHECK_PARAMS_MESSAGE_ID (0x98U)

typedef struct NV2080_CTRL_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_CHECK_PARAMS {
    NvBool bReservation;
} NV2080_CTRL_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_CHECK_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_SET
 *
 * Reserving / Releasing PERFMON HW
 *
 *   bReservation [IN]
 *     NV_TRUE -> request for reservation, NV_FALSE -> request for release
 *
 *   bClientHandlesGrGating [IN]
 *     DM-TODO: Add comment for this
 *
 *   bRmHandlesIdleSlow [IN]
 *     If the IDLE slowdown is required
 *
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_SET (0x20800a99) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_SET_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_SET_PARAMS_MESSAGE_ID (0x99U)

typedef struct NV2080_CTRL_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_SET_PARAMS {
    NvBool bReservation;
    NvBool bClientHandlesGrGating;
    NvBool bRmHandlesIdleSlow;
} NV2080_CTRL_INTERNAL_PERF_PERFMON_CLIENT_RESERVATION_SET_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_DISPLAY_GET_ACTIVE_DISPLAY_DEVICES
 *
 * Get active display devices
 *
 *   displayMask [OUT]
 *     Get the mask of the active display devices in VBIOS
 *
 *   numHeads [OUT]
 *     Number of heads display supported.
 *
 */
#define NV2080_CTRL_CMD_INTERNAL_DISPLAY_GET_ACTIVE_DISPLAY_DEVICES (0x20800a5d) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_DISPLAY_GET_ACTIVE_DISPLAY_DEVICES_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_DISPLAY_GET_ACTIVE_DISPLAY_DEVICES_PARAMS_MESSAGE_ID (0x5DU)

typedef struct NV2080_CTRL_INTERNAL_DISPLAY_GET_ACTIVE_DISPLAY_DEVICES_PARAMS {

    NvU32 displayMask;
    NvU32 numHeads;
} NV2080_CTRL_INTERNAL_DISPLAY_GET_ACTIVE_DISPLAY_DEVICES_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_FIFO_UPDATE_CHANNEL_INFO
 *
 * This command is an internal command sent from Kernel RM to Physical RM
 * to update the channel info params for an existing channel
 *
 * Please see description of NV2080_CTRL_CMD_FIFO_UPDATE_CHANNEL_INFO for more information.

 *   params [IN]
 *      Same input params as used for NV2080_CTRL_CMD_FIFO_UPDATE_CHANNEL_INFO
 */
#define NV2080_CTRL_CMD_INTERNAL_FIFO_UPDATE_CHANNEL_INFO (0x20800a5e) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x5E" */

/*!
 * NV2080_CTRL_CMD_INTERNAL_GR_REGISTER_ACCESS
 *
 * TODO - This ctrl call is only for temporary usage to unblock GR-split work
 * since NVLINK-split is not ready yet. NVLINK team has the AI to remove this
 * call after their split work is done (Should be before GR-split M4 scrubbing)
 *
 *   grIdx   [IN]
 *   regAddr [IN]
 *   data    [IN/OUT]
 *   bRead   [IN]
 */
#define NV2080_CTRL_CMD_INTERNAL_GR_REGISTER_ACCESS       (0x20800a5f) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_GR_REGISTER_ACCESS_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_GR_REGISTER_ACCESS_PARAMS_MESSAGE_ID (0x5FU)

typedef struct NV2080_CTRL_INTERNAL_GR_REGISTER_ACCESS_PARAMS {
    NvU32  grIdx;
    NvU32  regAddr;
    NvU32  data;
    NvBool bRead;
} NV2080_CTRL_INTERNAL_GR_REGISTER_ACCESS_PARAMS;

/*
 * NV2080_CTRL_INTERNAL_STATIC_MIGMGR_GET_SWIZZ_ID_FB_MEM_PAGE_RANGES
 *
 * Get FB Mem page ranges for all possible swizzIds
 *
 *   fbMemPageRanges [OUT]
 *      Mem page ranges for each swizzId in the form of {lo, hi}
 */
#define NV2080_CTRL_CMD_INTERNAL_STATIC_MIGMGR_GET_SWIZZ_ID_FB_MEM_PAGE_RANGES (0x20800a60) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_STATIC_MIGMGR_GET_SWIZZ_ID_FB_MEM_PAGE_RANGES_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_MAX_SWIZZ_ID                                      15

typedef struct NV2080_CTRL_INTERNAL_NV_RANGE {
    NV_DECLARE_ALIGNED(NvU64 lo, 8);
    NV_DECLARE_ALIGNED(NvU64 hi, 8);
} NV2080_CTRL_INTERNAL_NV_RANGE;

#define NV2080_CTRL_INTERNAL_STATIC_MIGMGR_GET_SWIZZ_ID_FB_MEM_PAGE_RANGES_PARAMS_MESSAGE_ID (0x60U)

typedef struct NV2080_CTRL_INTERNAL_STATIC_MIGMGR_GET_SWIZZ_ID_FB_MEM_PAGE_RANGES_PARAMS {
    NV_DECLARE_ALIGNED(NV2080_CTRL_INTERNAL_NV_RANGE fbMemPageRanges[NV2080_CTRL_INTERNAL_MAX_SWIZZ_ID], 8);
} NV2080_CTRL_INTERNAL_STATIC_MIGMGR_GET_SWIZZ_ID_FB_MEM_PAGE_RANGES_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_FIFO_GET_NUM_CHANNELS
 *
 * This command is an internal command sent from Kernel RM to Physical RM
 * to get number of channels for a given runlist ID
 *
 *   runlistId   [IN]
 *   numChannels [OUT]
 */
#define NV2080_CTRL_CMD_INTERNAL_FIFO_GET_NUM_CHANNELS (0x20800a61) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_FIFO_GET_NUM_CHANNELS_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_FIFO_GET_NUM_CHANNELS_PARAMS_MESSAGE_ID (0x61U)

typedef struct NV2080_CTRL_INTERNAL_FIFO_GET_NUM_CHANNELS_PARAMS {
    NvU32 runlistId;
    NvU32 numChannels;
} NV2080_CTRL_INTERNAL_FIFO_GET_NUM_CHANNELS_PARAMS;

/*!
 * @ref NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_FUSE_DATA
 * @ref NV2080_CTRL_CMD_INTERNAL_STATIC_MIGMGR_GET_FUSE_DATA
 */
#define NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_FUSE_DATA                   (0x20800a62) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x62" */

/*!
 * @ref NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_PROFILES
 * @ref NV2080_CTRL_CMD_INTERNAL_STATIC_MIGMGR_GET_PROFILES
 */
#define NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_PROFILES                    (0x20800a63) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x63" */

/*!
 * @ref NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_VALID_SWIZZID_MASK
 * @ref NV2080_CTRL_CMD_INTERNAL_STATIC_MIGMGR_GET_VALID_SWIZZID_MASK
 */
#define NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_VALID_SWIZZID_MASK          (0x20800a64) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x64" */

/*!
 * NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_PARTITIONABLE_ENGINES
 * NV2080_CTRL_CMD_INTERNAL_STATIC_MIGMGR_GET_PARTITIONABLE_ENGINES
 */
#define NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_PARTITIONABLE_ENGINES       (0x20800a65) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x65" */

/*!
 * NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_SWIZZ_ID_FB_MEM_PAGE_RANGES
 * NV2080_CTRL_CMD_INTERNAL_STATIC_MIGMGR_GET_SWIZZ_ID_FB_MEM_PAGE_RANGES
 */
#define NV2080_CTRL_CMD_INTERNAL_STATIC_KMIGMGR_GET_SWIZZ_ID_FB_MEM_PAGE_RANGES (0x20800a66) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x66" */

/*!
 * NV2080_CTRL_CMD_INTERNAL_KMEMSYS_GET_MIG_MEMORY_CONFIG
 * NV2080_CTRL_CMD_INTERNAL_MEMSYS_GET_MIG_MEMORY_CONFIG
 *
 * This command retrieves memory config from HW
 *
 *   memBoundaryCfgA [OUT]
 *      Memory boundary config A (4KB aligned)
 *
 *   memBoundaryCfgB [OUT]
 *      Memory boundary config B (4KB aligned)
 *
 *   memBoundaryCfgC [OUT]
 *      Memory boundary config C (64KB aligned)
 *
 *   memBoundaryCfg [OUT]
 *      Memory boundary config (64KB aligned)
 *      
 *   memBoundaryCfgValInit [OUT]
 *      Memory boundary config initial value (64KB aligned)
 */
#define NV2080_CTRL_CMD_INTERNAL_KMEMSYS_GET_MIG_MEMORY_CONFIG                  (0x20800a67) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x67" */
#define NV2080_CTRL_CMD_INTERNAL_MEMSYS_GET_MIG_MEMORY_CONFIG                   (0x20800a68) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x68" */

typedef struct NV2080_CTRL_INTERNAL_MEMSYS_GET_MIG_MEMORY_CONFIG_PARAMS {
    NV_DECLARE_ALIGNED(NvU64 memBoundaryCfgA, 8);
    NV_DECLARE_ALIGNED(NvU64 memBoundaryCfgB, 8);
    NvU32 memBoundaryCfgC;
    NvU32 memBoundaryCfg;
    NvU32 memBoundaryCfgValInit;
} NV2080_CTRL_INTERNAL_MEMSYS_GET_MIG_MEMORY_CONFIG_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_RC_WATCHDOG_TIMEOUT
 *
 * Invoke RC recovery after watchdog timeout is hit.
 */
#define NV2080_CTRL_CMD_INTERNAL_RC_WATCHDOG_TIMEOUT     (0x20800a6a) /* finn: Evaluated from "((FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x6a)" */

/* !
 *  This command disables cuda limit activation at teardown of the client.
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_CUDA_LIMIT_DISABLE (0x20800a7a) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x7A" */

/*
 *  This command is cleaning up OPTP when a client is found to have
 *  been terminated unexpectedly.
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_OPTP_CLI_CLEAR     (0x20800a7c) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x7C" */


/*!
 * This command can be used to boost P-State up one level or to the highest for a limited
 * duration for the associated subdevice. Boosts from different clients are being tracked
 * independently. Note that there are other factors that can limit P-States so the resulting
 * P-State may differ from expectation.
 *
 *   flags
 *     This parameter specifies the actual command. _CLEAR is to clear existing boost.
 *     _BOOST_1LEVEL is to boost P-State one level higher. _BOOST_TO_MAX is to boost
 *     to the highest P-State.
 *   duration
 *     This parameter specifies the duration of the boost in seconds. This has to be less
 *     than NV2080_CTRL_PERF_BOOST_DURATION_MAX.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_BOOST_SET_2X       (0x20800a9a) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_PERF_BOOST_SET_PARAMS_2X_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_PERF_BOOST_SET_PARAMS_2X_MESSAGE_ID (0x9AU)

typedef struct NV2080_CTRL_INTERNAL_PERF_BOOST_SET_PARAMS_2X {

    NvBool flags;
    NvU32  duration;
} NV2080_CTRL_INTERNAL_PERF_BOOST_SET_PARAMS_2X;

#define NV2080_CTRL_INTERNAL_PERF_SYNC_GPU_BOOST_LIMITS_PSTATE   0U
#define NV2080_CTRL_INTERNAL_PERF_SYNC_GPU_BOOST_LIMITS_GPCCLK   1U
#define NV2080_CTRL_INTERNAL_PERF_SYNC_GPU_BOOST_LIMITS_LAST     NV2080_CTRL_INTERNAL_PERF_SYNC_GPU_BOOST_LIMITS_GPCCLK
#define NV2080_CTRL_INTERNAL_PERF_SYNC_GPU_BOOST_LIMITS_NUM      (0x2U) /* finn: Evaluated from "NV2080_CTRL_INTERNAL_PERF_SYNC_GPU_BOOST_LIMITS_LAST + 1" */

/*!
 * NV2080_CTRL_CMD_INTERNAL_PERF_GPU_BOOST_SYNC_SET_CONTROL
 *
 * Activate/Deactivate GPU Boost Sync algorithm
 *
 *   bActivate [IN]
 *     GPU Boost Sync algorithm:
 *      NV_TRUE  -> activate
 *      NV_FALSE -> deactivate
 *
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_GPU_BOOST_SYNC_SET_CONTROL (0x20800a7e) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_CONTROL_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_CONTROL_PARAMS_MESSAGE_ID (0x7EU)

typedef struct NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_CONTROL_PARAMS {
    NvBool bActivate;
} NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_CONTROL_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_PERF_GPU_BOOST_SYNC_SET_LIMITS
 *
 * Apply given limits to a specific subdevice
 *
 *   flags [IN]
 *     DM-TODO: write description here
 *
 *   bBridgeless [IN]
 *     Bridgeless information, for now supporting only MIO bridges
 * 
 *   currLimits
 *     Array of limits that will be applied
 *
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_GPU_BOOST_SYNC_SET_LIMITS (0x20800a7f) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_SET_LIMITS_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_SET_LIMITS_PARAMS_MESSAGE_ID (0x7FU)

typedef struct NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_SET_LIMITS_PARAMS {
    NvU32  flags;
    NvBool bBridgeless;
    NvU32  currLimits[NV2080_CTRL_INTERNAL_PERF_SYNC_GPU_BOOST_LIMITS_NUM];
} NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_SET_LIMITS_PARAMS;

/*!
 * NV2080_CTRL_CMD_INTERNAL_PERF_GPU_BOOST_SYNC_GET_INFO
 *
 * Data for GPU Boost Sync structure initialization
 *
 *   hysteresisus [OUT]
 *     Hysteresis value for GPU Boost synchronization hysteresis algorithm.
 *
 *   bHystersisEnable [OUT]
 *     hysteresis algorithm for SLI GPU Boost synchronization:
 *      NV_TRUE  -> enabled,
 *      NV_FALSE -> disabled
 * 
 *   bSliGpuBoostSyncEnable [OUT]
 *     SLI GPU Boost feature is:
 *      NV_TRUE  -> enabled,
 *      NV_FALSE -> disabled
 *
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_GPU_BOOST_SYNC_GET_INFO (0x20800a80) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_GET_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_GET_INFO_PARAMS_MESSAGE_ID (0x80U)

typedef struct NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_GET_INFO_PARAMS {
    NV_DECLARE_ALIGNED(NvU64 hysteresisus, 8);
    NvBool bHystersisEnable;
    NvBool bSliGpuBoostSyncEnable;
} NV2080_CTRL_INTERNAL_PERF_GPU_BOOST_SYNC_GET_INFO_PARAMS;

/*
 * NV2080_CTRL_CMD_INTERNAL_GMMU_REGISTER_FAULT_BUFFER
 *
 * This command sends replayable fault buffer pages allocated by CPU-RM
 * to be setup and enabled in physical RM.
 *
 * hClient
 *   Client handle.
 *
 * hObject
 *   Object handle.
 *
 * faultBufferSize
 *   Size of the replayable fault buffer to register.
 *
 * faultBufferPteArray
 *   Pages of replayable fault buffer.
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV2080_CTRL_CMD_INTERNAL_GMMU_REGISTER_FAULT_BUFFER (0x20800a9b) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_GMMU_REGISTER_FAULT_BUFFER_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_GMMU_FAULT_BUFFER_MAX_PAGES    256
#define NV2080_CTRL_INTERNAL_GMMU_REGISTER_FAULT_BUFFER_PARAMS_MESSAGE_ID (0x9BU)

typedef struct NV2080_CTRL_INTERNAL_GMMU_REGISTER_FAULT_BUFFER_PARAMS {
    NvHandle hClient;
    NvHandle hObject;
    NvU32    faultBufferSize;
    NV_DECLARE_ALIGNED(NvU64 faultBufferPteArray[NV2080_CTRL_INTERNAL_GMMU_FAULT_BUFFER_MAX_PAGES], 8);
} NV2080_CTRL_INTERNAL_GMMU_REGISTER_FAULT_BUFFER_PARAMS;

/*
 * NV2080_CTRL_CMD_INTERNAL_GMMU_UNREGISTER_FAULT_BUFFER
 *
 * This command requests physical RM to disable the replayable fault buffer.
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV2080_CTRL_CMD_INTERNAL_GMMU_UNREGISTER_FAULT_BUFFER             (0x20800a9c) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x9C" */

/*
 * NV2080_CTRL_CMD_INTERNAL_GMMU_REGISTER_CLIENT_SHADOW_FAULT_BUFFER
 *
 * This command sends client shadow fault buffer pages allocated by CPU-RM
 * to be setup and enabled in physical RM.
 *
 * shadowFaultBufferQueuePhysAddr
 *   Physical address of shadow fault buffer queue.
 *
 * faultBufferSize
 *   Size of the client shadow fault buffer to register.
 *
 * shadowFaultBufferPteArray
 *   Pages of client shadow fault buffer.
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV2080_CTRL_CMD_INTERNAL_GMMU_REGISTER_CLIENT_SHADOW_FAULT_BUFFER (0x20800a9d) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_GMMU_REGISTER_CLIENT_SHADOW_FAULT_BUFFER_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_GMMU_CLIENT_SHADOW_FAULT_BUFFER_MAX_PAGES    1500
#define NV2080_CTRL_INTERNAL_GMMU_REGISTER_CLIENT_SHADOW_FAULT_BUFFER_PARAMS_MESSAGE_ID (0x9DU)

typedef struct NV2080_CTRL_INTERNAL_GMMU_REGISTER_CLIENT_SHADOW_FAULT_BUFFER_PARAMS {
    NV_DECLARE_ALIGNED(NvU64 shadowFaultBufferQueuePhysAddr, 8);
    NvU32 shadowFaultBufferSize;
    NV_DECLARE_ALIGNED(NvU64 shadowFaultBufferPteArray[NV2080_CTRL_INTERNAL_GMMU_CLIENT_SHADOW_FAULT_BUFFER_MAX_PAGES], 8);
} NV2080_CTRL_INTERNAL_GMMU_REGISTER_CLIENT_SHADOW_FAULT_BUFFER_PARAMS;

/*
 * NV2080_CTRL_CMD_INTERNAL_GMMU_UNREGISTER_CLIENT_SHADOW_FAULT_BUFFER
 *
 * This command requests physical RM to disable the client shadow fault buffer.
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV2080_CTRL_CMD_INTERNAL_GMMU_UNREGISTER_CLIENT_SHADOW_FAULT_BUFFER (0x20800a9e) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0x9E" */

/*!
 * NV2080_CTRL_CMD_INTERNAL_PERF_BOOST_SET_3X
 *
 * This command can be used to boost P-State the highest for a limited
 * duration for the associated subdevice. Boosts from different clients are being tracked
 * independently. Note that there are other factors that can limit P-States so the resulting
 * P-State may differ from expectation.
 *
 *   flags [IN]
 *     This parameter specifies the actual command. _CLEAR is to clear existing boost.
 *     and _BOOST_TO_MAX is to boost to the highest P-State.
 *
 *   boostDuration [IN]
 *     This parameter specifies the duration of the boost in seconds. This has to be less
 *     than NV2080_CTRL_PERF_BOOST_DURATION_MAX.
 *
 *   gfId [IN]
 *     This specifies Id of the Kernel RM that is requesting the Boost
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT *
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_BOOST_SET_3X                          (0x20800aa0) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_PERF_BOOST_SET_PARAMS_3X_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_PERF_BOOST_SET_PARAMS_3X_MESSAGE_ID (0xA0U)

typedef struct NV2080_CTRL_INTERNAL_PERF_BOOST_SET_PARAMS_3X {

    NvU32 flags;
    NvU32 boostDuration;
    NvU32 gfId;
} NV2080_CTRL_INTERNAL_PERF_BOOST_SET_PARAMS_3X;

/*!
 * NV2080_CTRL_CMD_INTERNAL_PERF_BOOST_CLEAR_3X
 *
 * Clear the boost for specific Kernel RM
 *
 *   bIsCudaClient [IN]
 *     Specifies if the request is for clearing the CUDA boost or regular boost
 *     NV_TRUE -> CUDA boost, NV_FALSE otherwise
 *
 *   gfId [IN]
 *     Specifies Id of the Kernel RM that is requesting Boost clear
 *
 */
#define NV2080_CTRL_CMD_INTERNAL_PERF_BOOST_CLEAR_3X (0x20800aa1) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | NV2080_CTRL_INTERNAL_PERF_BOOST_CLEAR_PARAMS_3X_MESSAGE_ID" */

#define NV2080_CTRL_INTERNAL_PERF_BOOST_CLEAR_PARAMS_3X_MESSAGE_ID (0xA1U)

typedef struct NV2080_CTRL_INTERNAL_PERF_BOOST_CLEAR_PARAMS_3X {

    NvBool bIsCudaClient;
    NvU32  gfId;
} NV2080_CTRL_INTERNAL_PERF_BOOST_CLEAR_PARAMS_3X;

/*
 * NV2080_CTRL_CMD_INTERNAL_STATIC_GRMGR_GET_SKYLINE_INFO
 *
 * Retrieves skyline information about the GPU. Params are sized to currently known max
 * values, but will need to be modified in the future should that change.
 */
#define NV2080_CTRL_CMD_INTERNAL_STATIC_GRMGR_GET_SKYLINE_INFO          (0x208038a2) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GRMGR_INTERFACE_ID << 8) | 0xA2" */

#define NV2080_CTRL_INTERNAL_GRMGR_SKYLINE_INFO_MAX_SKYLINES            8
#define NV2080_CTRL_INTERNAL_GRMGR_SKYLINE_INFO_MAX_NON_SINGLETON_VGPCS 8
/*!
 * NV2080_CTRL_INTERNAL_GRMGR_SKYLINE_INFO
 * skylineVgpcSize[OUT]
 *      - TPC count of non-singleton VGPCs
 * singletonVgpcMask[OUT]
 *      - Mask of active Singletons
 * maxInstances[OUT]
 *      - Max allowed instances of this skyline concurrently on a GPU
 * computeSizeFlag
 *      - One of NV2080_CTRL_GPU_PARTITION_FLAG_COMPUTE_SIZE_* flags which is associated with this skyline
 */
typedef struct NV2080_CTRL_INTERNAL_GRMGR_SKYLINE_INFO {
    NvU8  skylineVgpcSize[NV2080_CTRL_INTERNAL_GRMGR_SKYLINE_INFO_MAX_NON_SINGLETON_VGPCS];
    NvU32 singletonVgpcMask;
    NvU32 maxInstances;
    NvU32 computeSizeFlag;
} NV2080_CTRL_INTERNAL_GRMGR_SKYLINE_INFO;

/*!
 * NV2080_CTRL_INTERNAL_STATIC_GRMGR_GET_SKYLINE_INFO_PARAMS
 * skylineTable[OUT]
 *      - TPC count of non-singleton VGPCs
 *      - Mask of singleton vGPC IDs active
 *      - Max Instances of this skyline possible concurrently
 *      - Associated compute size with the indexed skyline
 * validEntries[OUT]
 *      - Number of entries which contain valid info in skylineInfo
 */
typedef struct NV2080_CTRL_INTERNAL_STATIC_GRMGR_GET_SKYLINE_INFO_PARAMS {
    NV2080_CTRL_INTERNAL_GRMGR_SKYLINE_INFO skylineTable[NV2080_CTRL_INTERNAL_GRMGR_SKYLINE_INFO_MAX_SKYLINES];
    NvU32                                   validEntries;
} NV2080_CTRL_INTERNAL_STATIC_GRMGR_GET_SKYLINE_INFO_PARAMS;

/*!
 * @ref NV2080_CTRL_CMD_GPU_SET_PARTITIONING_MODE
 */
#define NV2080_CTRL_CMD_INTERNAL_MIGMGR_SET_PARTITIONING_MODE  (0x20800aa3) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0xA3" */

/*!
 * @ref NV2080_CTRL_CMD_GPU_CONFIGURE_PARTITION
 */
#define NV2080_CTRL_CMD_INTERNAL_MIGMGR_CONFIGURE_GPU_INSTANCE (0x20800aa4) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_INTERNAL_INTERFACE_ID << 8) | 0xA4" */

/* ctrl2080internal_h */
