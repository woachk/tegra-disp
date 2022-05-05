/*
 * SPDX-FileCopyrightText: Copyright (c) 2006-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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
// Source file: ctrl/ctrl2080/ctrl2080gpu.finn
//




#include "ctrl/ctrl2080/ctrl2080base.h"
#include "ctrl/ctrl2080/ctrl2080gr.h"

/* NV20_SUBDEVICE_XX gpu control commands and parameters */

/* Valid feature values */
#define NV2080_CTRL_GPU_GET_FEATURES_CLK_ARCH_DOMAINS                     0:0
#define NV2080_CTRL_GPU_GET_FEATURES_CLK_ARCH_DOMAINS_FALSE (0x00000000)
#define NV2080_CTRL_GPU_GET_FEATURES_CLK_ARCH_DOMAINS_TRUE  (0x00000001)



typedef struct NV2080_CTRL_GPU_INFO {
    NvU32 index;
    NvU32 data;
} NV2080_CTRL_GPU_INFO;


#define NV2080_CTRL_GPU_INFO_INDEX_MINOR_REVISION_EXT                  (0x00000004)


#define NV2080_CTRL_GPU_INFO_INDEX_4K_PAGE_ISOLATION_REQUIRED          (0x00000033)
#define NV2080_CTRL_GPU_INFO_INDEX_DISPLAY_ENABLED                     (0x00000034)
#define NV2080_CTRL_GPU_INFO_INDEX_MOBILE_CONFIG_ENABLED               (0x00000035)


#define NV2080_CTRL_GPU_INFO_MAX_LIST_SIZE                             (0x0000003d)

/* valid minor revision extended values */
#define NV2080_CTRL_GPU_INFO_MINOR_REVISION_EXT_NONE                   (0x00000000)
#define NV2080_CTRL_GPU_INFO_MINOR_REVISION_EXT_P                      (0x00000001)
#define NV2080_CTRL_GPU_INFO_MINOR_REVISION_EXT_V                      (0x00000002)
#define NV2080_CTRL_GPU_INFO_MINOR_REVISION_EXT_PV                     (0x00000003)


/* valid 4K PAGE isolation requirement values */
#define NV2080_CTRL_GPU_INFO_INDEX_4K_PAGE_ISOLATION_REQUIRED_NO       (0x00000000)
#define NV2080_CTRL_GPU_INFO_INDEX_4K_PAGE_ISOLATION_REQUIRED_YES      (0x00000001)

/* valid display enabled values */
#define NV2080_CTRL_GPU_INFO_DISPLAY_ENABLED_NO                        (0x00000000)
#define NV2080_CTRL_GPU_INFO_DISPLAY_ENABLED_YES                       (0x00000001)

/* valid mobile config enabled values */
#define NV2080_CTRL_GPU_INFO_INDEX_MOBILE_CONFIG_ENABLED_NO            (0x00000000)
#define NV2080_CTRL_GPU_INFO_INDEX_MOBILE_CONFIG_ENABLED_YES           (0x00000001)



/*
 * NV2080_CTRL_CMD_GPU_GET_INFO
 *
 * This command returns gpu information for the associated GPU.  Requests
 * to retrieve gpu information use a list of one or more NV2080_CTRL_GPU_INFO
 * structures.
 *
 *   gpuInfoListSize
 *     This field specifies the number of entries on the caller's
 *     gpuInfoList.
 *   gpuInfoList
 *     This field specifies a pointer in the caller's address space
 *     to the buffer into which the gpu information is to be returned.
 *     This buffer must be at least as big as gpuInfoListSize multiplied
 *     by the size of the NV2080_CTRL_GPU_INFO structure.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_NOT_SUPPORTED
 *   NV_ERR_OPERATING_SYSTEM
 */
#define NV2080_CTRL_CMD_GPU_GET_INFO                                   (0x20800101) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_INFO_PARAMS_MESSAGE_ID (0x1U)

typedef struct NV2080_CTRL_GPU_GET_INFO_PARAMS {
    NvU32 gpuInfoListSize;
    NV_DECLARE_ALIGNED(NvP64 gpuInfoList, 8);
} NV2080_CTRL_GPU_GET_INFO_PARAMS;

#define NV2080_CTRL_CMD_GPU_GET_INFO_V2 (0x20800102) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | 0x2" */

typedef struct NV2080_CTRL_GPU_GET_INFO_V2_PARAMS {
    NvU32                gpuInfoListSize;
    NV2080_CTRL_GPU_INFO gpuInfoList[NV2080_CTRL_GPU_INFO_MAX_LIST_SIZE];
} NV2080_CTRL_GPU_GET_INFO_V2_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_GET_NAME_STRING
 *
 * This command returns the name of the GPU in string form in either ASCII
 * or UNICODE format.
 *
 *   gpuNameStringFlags
 *     This field specifies flags to use while creating the GPU name string.
 *     Valid flags values:
 *       NV2080_CTRL_GPU_GET_NAME_STRING_FLAGS_TYPE_ASCII
 *         The returned name string should be in standard ASCII format.
 *       NV2080_CTRL_GPU_GET_NAME_STRING_FLAGS_TYPE_UNICODE
 *         The returned name string should be in unicode format.
 *   gpuNameString
 *     This field contains the buffer into which the name string should be
 *     returned.  The length of the returned string will be no more than
 *     NV2080_CTRL_GPU_MAX_NAME_STRING_LENGTH bytes in size.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_OPERATING_SYSTEM
 */
#define NV2080_CTRL_CMD_GPU_GET_NAME_STRING                (0x20800110) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_NAME_STRING_PARAMS_MESSAGE_ID" */

#define NV2080_GPU_MAX_NAME_STRING_LENGTH                  (0x0000040)

// This field is deprecated - 'gpuNameStringFlags' is now a simple scalar.
// Field maintained (and extended from 0:0) for compile-time compatibility.
#define NV2080_CTRL_GPU_GET_NAME_STRING_FLAGS_TYPE                    31:0

/* valid gpu name string flags */
#define NV2080_CTRL_GPU_GET_NAME_STRING_FLAGS_TYPE_ASCII   (0x00000000)
#define NV2080_CTRL_GPU_GET_NAME_STRING_FLAGS_TYPE_UNICODE (0x00000001)

#define NV2080_CTRL_GPU_GET_NAME_STRING_PARAMS_MESSAGE_ID (0x10U)

typedef struct NV2080_CTRL_GPU_GET_NAME_STRING_PARAMS {
    NvU32 gpuNameStringFlags;
    union {
        NvU8  ascii[NV2080_GPU_MAX_NAME_STRING_LENGTH];
        NvU16 unicode[NV2080_GPU_MAX_NAME_STRING_LENGTH];
    } gpuNameString;
} NV2080_CTRL_GPU_GET_NAME_STRING_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_GET_SHORT_NAME_STRING
 *
 * This command returns the short name of the GPU in ASCII string form.
 *
 *   gpuShortNameString
 *     This field contains the buffer into which the short name string should
 *     be returned.  The length of the returned string will be no more than
 *     NV2080_MAX_NAME_STRING_LENGTH bytes in size.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_OPERATING_SYSTEM
 */
#define NV2080_CTRL_CMD_GPU_GET_SHORT_NAME_STRING (0x20800111) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_SHORT_NAME_STRING_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_SHORT_NAME_STRING_PARAMS_MESSAGE_ID (0x11U)

typedef struct NV2080_CTRL_GPU_GET_SHORT_NAME_STRING_PARAMS {
    NvU8 gpuShortNameString[NV2080_GPU_MAX_NAME_STRING_LENGTH];
} NV2080_CTRL_GPU_GET_SHORT_NAME_STRING_PARAMS;



/*
 * NV2080_CTRL_CMD_GPU_GET_SDM
 *
 * This command returns the subdevice mask value for the associated subdevice.
 * The subdevice mask value can be used with the SET_SUBDEVICE_MASK instruction
 * provided by the NV36_CHANNEL_DMA and newer channel dma classes.
 *
 *   subdeviceMask [out]
 *     This field return the subdevice mask value.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV2080_CTRL_CMD_GPU_GET_SDM                            (0x20800118) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_SDM_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_SDM_PARAMS_MESSAGE_ID (0x18U)

typedef struct NV2080_CTRL_GPU_GET_SDM_PARAMS {
    NvU32 subdeviceMask;
} NV2080_CTRL_GPU_GET_SDM_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_SET_SDM
 *
 * This command sets the subdevice instance and mask value for the associated subdevice.
 * The subdevice mask value can be used with the SET_SUBDEVICE_MASK instruction
 * provided by the NV36_CHANNEL_DMA and newer channel dma classes.
 * It must be called before the GPU HW is initialized otherwise 
 * NV_ERR_INVALID_STATE is being returned.
 *
 *   subdeviceMask [in]
 *     This field configures the subdevice mask value for the GPU/Subdevice
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_STATE
 *   NV_ERR_INVALID_DATA
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV2080_CTRL_CMD_GPU_SET_SDM (0x20800120) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_SET_SDM_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_SET_SDM_PARAMS_MESSAGE_ID (0x20U)

typedef struct NV2080_CTRL_GPU_SET_SDM_PARAMS {
    NvU32 subdeviceMask;
} NV2080_CTRL_GPU_SET_SDM_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO
 *
 * This command returns the associated subdevices' simulation information.
 *
 *   type
 *     This field returns the simulation type.
 *     One of NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_*
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 */
#define NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO (0x20800119) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_SIMULATION_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_PARAMS_MESSAGE_ID (0x19U)

typedef struct NV2080_CTRL_GPU_GET_SIMULATION_INFO_PARAMS {
    NvU32 type;
} NV2080_CTRL_GPU_GET_SIMULATION_INFO_PARAMS;

#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_NONE          (0x00000000)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_MODS_AMODEL   (0x00000001)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_LIVE_AMODEL   (0x00000002)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_FMODEL        (0x00000003)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_RTL           (0x00000004)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_EMU           (0x00000005)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_EMU_LOW_POWER (0x00000006)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_DFPGA         (0x00000007)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_DFPGA_RTL     (0x00000008)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_DFPGA_FMODEL  (0x00000009)
#define NV2080_CTRL_GPU_GET_SIMULATION_INFO_TYPE_UNKNOWN       (0xFFFFFFFF)



/*
 * NV2080_CTRL_CMD_GPU_GET_ENGINES
 *
 * Returns a list of supported engine types along with the number of instances
 * of each type. Querying with engineList NULL returns engineCount.
 *
 *   engineCount
 *     This field specifies the number of entries on the caller's engineList
 *     field.
 *   engineList
 *     This field is a pointer to a buffer of NvU32 values representing the
 *     set of engines supported by the associated subdevice.  Refer to cl2080.h
 *     for the complete set of supported engine types.
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV2080_CTRL_CMD_GPU_GET_ENGINES (0x20800123) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_ENGINES_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_ENGINES_PARAMS_MESSAGE_ID (0x23U)

typedef struct NV2080_CTRL_GPU_GET_ENGINES_PARAMS {
    NvU32 engineCount;
    NV_DECLARE_ALIGNED(NvP64 engineList, 8);
} NV2080_CTRL_GPU_GET_ENGINES_PARAMS;

#define NV2080_CTRL_CMD_GPU_GET_ENGINES_V2 (0x20800170) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS_MESSAGE_ID" */

/* Must match NV2080_ENGINE_TYPE_LAST from cl2080.h */
#define NV2080_GPU_MAX_ENGINES_LIST_SIZE   0x34

#define NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS_MESSAGE_ID (0x70U)

typedef struct NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS {
    NvU32 engineCount;
    NvU32 engineList[NV2080_GPU_MAX_ENGINES_LIST_SIZE];
} NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_GET_ENGINE_CLASSLIST
 *
 * Returns a list of classes supported by a given engine type.
 *
 *   engineType
 *     This field specifies the engine type being queried.
 *     NV2080_CTRL_ENGINE_TYPE_ALLENGINES will return  classes
 *     supported by all engines.
 *
 *   numClasses
 *     This field specifies the number of classes supported by
 *     engineType.
 *
 *   classList
 *     This field is an array containing the list of supported
 *     classes. Is of type (NvU32*)
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV2080_CTRL_CMD_GPU_GET_ENGINE_CLASSLIST (0x20800124) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_ENGINE_CLASSLIST_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_ENGINE_CLASSLIST_PARAMS_MESSAGE_ID (0x24U)

typedef struct NV2080_CTRL_GPU_GET_ENGINE_CLASSLIST_PARAMS {
    NvU32 engineType;
    NvU32 numClasses;
    NV_DECLARE_ALIGNED(NvP64 classList, 8);
} NV2080_CTRL_GPU_GET_ENGINE_CLASSLIST_PARAMS;



/*
 * NV2080_CTRL_CMD_GPU_QUERY_MODE
 *
 * This command is used to detect the mode of the GPU associated with the
 * subdevice.
 *
 *   mode
 *     This parameter returns the current mode of GPU.  Legal values for
 *     this parameter include:
 *       NV2080_CTRL_GPU_QUERY_MODE_GRAPHICS_MODE
 *         The GPU is currently operating in graphics mode.
 *       NV2080_CTRL_GPU_QUERY_MODE_COMPUTE_MODE
 *         The GPU is currently operating in compute mode.
 *       NV2080_CTRL_GPU_QUERY_MODE_UNKNOWN_MODE
 *         The current mode of the GPU could not be determined.
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV2080_CTRL_CMD_GPU_QUERY_MODE           (0x20800128) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_QUERY_MODE_PARAMS_MESSAGE_ID" */

/* valid mode parameter values */
#define NV2080_CTRL_GPU_QUERY_MODE_UNKNOWN_MODE  (0x00000000)
#define NV2080_CTRL_GPU_QUERY_MODE_GRAPHICS_MODE (0x00000001)
#define NV2080_CTRL_GPU_QUERY_MODE_COMPUTE_MODE  (0x00000002)

#define NV2080_CTRL_GPU_QUERY_MODE_PARAMS_MESSAGE_ID (0x28U)

typedef struct NV2080_CTRL_GPU_QUERY_MODE_PARAMS {
    NvU32 mode;
} NV2080_CTRL_GPU_QUERY_MODE_PARAMS;



/*!
 * NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ENTRY
 * Data block describing a virtual context buffer to be promoted
 *
 *  gpuPhysAddr [IN]
 *    GPU Physical Address for the buffer
 *  gpuVirtAddr [IN]
 *    GPU Virtual Address for the buffer
 *   size[IN]
 *    Size of this virtual context buffer
 *  physAttr [IN]
 *    Physical memory attributes (aperture, cacheable)
 *  bufferId [IN]
 *    Virtual context buffer type, data type NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_*
 *  bInitialize [IN]
 *   Flag indicating that this virtual context buffer should be initialized prior to promotion.
 *   The client must clear (memset) the buffer to 0x0 prior to initialization.
 *   Following buffers need initialization:
 *    1. NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_MAIN
 *    2. NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_PATCH
 *    3. NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_PRIV_ACCESS_MAP
 *    4. NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_UNRESTRICTED_PRIV_ACCESS_MAP
 *  bNonmapped [IN]
 *   Flag indicating that the virtual address is not to be promoted with this
 *   call. It is illegal to set this flag and not set bInitialize.
 */
typedef struct NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ENTRY {
    NV_DECLARE_ALIGNED(NvU64 gpuPhysAddr, 8);
    NV_DECLARE_ALIGNED(NvU64 gpuVirtAddr, 8);
    NV_DECLARE_ALIGNED(NvU64 size, 8);
    NvU32 physAttr;
    NvU16 bufferId;
    NvU8  bInitialize;
    NvU8  bNonmapped;
} NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ENTRY;

#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_MAIN                         0
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_PM                           1
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_PATCH                        2
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_BUFFER_BUNDLE_CB             3
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_PAGEPOOL                     4
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_ATTRIBUTE_CB                 5
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_RTV_CB_GLOBAL                6
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_GFXP_POOL                    7
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_GFXP_CTRL_BLK                8
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_FECS_EVENT                   9
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_PRIV_ACCESS_MAP              10
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_UNRESTRICTED_PRIV_ACCESS_MAP 11
#define NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_GLOBAL_PRIV_ACCESS_MAP       12

#define NV2080_CTRL_GPU_PROMOTE_CONTEXT_MAX_ENTRIES                        16

/*
 * NV2080_CTRL_CMD_GPU_PROMOTE_CTX
 *
 * This command is used to promote a Virtual Context
 *
 *   engineType
 *     Engine Virtual Context is for
 *   hClient
 *     Client Handle for hVirtMemory
 *   ChID
 *     Hw Channel -- Actually hw index for channel (deprecated)
 *   hChanClient
 *     The client handle for hObject
 *   hObject
 *     Passed in object handle for either a single channel or a channel group
 *   hVirtMemory
 *     Virtual Address handle to map Virtual Context to
 *   virtAddress
 *     Virtual Address to map Virtual Context to
 *   size
 *     size of the Virtual Context
 *   entryCount
 *     Number of valid entries in the promotion entry list
 *   promoteEntry
 *     List of context buffer entries to issue promotions for.
 *
 *   When not using promoteEntry, only hVirtMemory or (virtAddress, size) should be 
 *   specified, the code cases based on hVirtMemory(NULL vs non-NULL) so 
 *   if both are specified, hVirtMemory has precedence. 
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED    - The Class does not support version info retrieval
 *   NV_ERR_INVALID_DEVICE   - The Class/Device is not yet ready to provide this info.
 *   NV_ERR_INVALID_ARGUMENT - Bad/Unknown Class ID specified.
 */
#define NV2080_CTRL_CMD_GPU_PROMOTE_CTX                                    (0x2080012b) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_PROMOTE_CTX_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_PROMOTE_CTX_PARAMS_MESSAGE_ID (0x2BU)

typedef struct NV2080_CTRL_GPU_PROMOTE_CTX_PARAMS {
    NvU32    engineType;
    NvHandle hClient;
    NvU32    ChID;
    NvHandle hChanClient;
    NvHandle hObject;
    NvHandle hVirtMemory;
    NV_DECLARE_ALIGNED(NvU64 virtAddress, 8);
    NV_DECLARE_ALIGNED(NvU64 size, 8);
    NvU32    entryCount;
    // C form: NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ENTRY promoteEntry[NV2080_CTRL_GPU_PROMOTE_CONTEXT_MAX_ENTRIES];
    NV_DECLARE_ALIGNED(NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ENTRY promoteEntry[NV2080_CTRL_GPU_PROMOTE_CONTEXT_MAX_ENTRIES], 8);
} NV2080_CTRL_GPU_PROMOTE_CTX_PARAMS;
typedef struct NV2080_CTRL_GPU_PROMOTE_CTX_PARAMS *PNV2080_CTRL_GPU_PROMOTE_CTX_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_EVICT_CTX
 *
 * This command is used to evict a Virtual Context
 *
 *   engineType
 *     Engine Virtual Context is for
 *   hClient
 *     Client Handle
 *   ChID
 *     Hw Channel -- Actually hw index for channel (deprecated)
 *   hChanClient
 *     Client handle for hObject
 *   hObject
 *     Passed in object handle for either a single channel or a channel group
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED    - The Class does not support version info retrieval
 *   NV_ERR_INVALID_DEVICE   - The Class/Device is not yet ready to provide this info.
 *   NV_ERR_INVALID_ARGUMENT - Bad/Unknown Class ID specified.
 */
#define NV2080_CTRL_CMD_GPU_EVICT_CTX (0x2080012c) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_EVICT_CTX_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_EVICT_CTX_PARAMS_MESSAGE_ID (0x2CU)

typedef struct NV2080_CTRL_GPU_EVICT_CTX_PARAMS {
    NvU32    engineType;
    NvHandle hClient;
    NvU32    ChID;
    NvHandle hChanClient;
    NvHandle hObject;
} NV2080_CTRL_GPU_EVICT_CTX_PARAMS;
typedef struct NV2080_CTRL_GPU_EVICT_CTX_PARAMS *PNV2080_CTRL_GPU_EVICT_CTX_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_INITIALIZE_CTX
 *
 * This command is used to initialize a Virtual Context. The ctx buffer must be
 * cleared (zerod) by the caller prior to invoking this method.
 *
 *   engineType
 *     Engine Virtual Context is for
 *   hClient
 *     Client Handle for the hVirtMemory
 *   ChID
 *      Hw channel -- Actually channel index (deprecated)
 *   hChanClient
 *     The client handle for hObject
 *   hObject
 *     Passed in object handle for either a single channel or a channel group
 *   hVirtMemory
 *     Virtual Address where to map Virtual Context to
 *   physAddress
 *     Physical offset in FB to use as Virtual Context
 *   physAttr
 *     Physical memory attributes
 *   hDmaHandle
 *     Dma Handle when using discontiguous context buffers
 *   index
 *     Start offset in Virtual DMA Context
 *   size
 *     Size of the Virtual Context
 *
 *   Only hVirtMemory or size should be specified, the code cases based on hVirtMemory
 *   (NULL vs non-NULL) so if both are specified, hVirtMemory has precedence.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED    - The Class does not support version info retrieval
 *   NV_ERR_INVALID_DEVICE   - The Class/Device is not yet ready to provide this info.
 *   NV_ERR_INVALID_ARGUMENT - Bad/Unknown Class ID specified.
 */
#define NV2080_CTRL_CMD_GPU_INITIALIZE_CTX (0x2080012d) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_INITIALIZE_CTX_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_INITIALIZE_CTX_PARAMS_MESSAGE_ID (0x2DU)

typedef struct NV2080_CTRL_GPU_INITIALIZE_CTX_PARAMS {
    NvU32    engineType;
    NvHandle hClient;
    NvU32    ChID;
    NvHandle hChanClient;
    NvHandle hObject;
    NvHandle hVirtMemory;
    NV_DECLARE_ALIGNED(NvU64 physAddress, 8);
    NvU32    physAttr;
    NvHandle hDmaHandle;
    NvU32    index;
    NV_DECLARE_ALIGNED(NvU64 size, 8);
} NV2080_CTRL_GPU_INITIALIZE_CTX_PARAMS;
typedef struct NV2080_CTRL_GPU_INITIALIZE_CTX_PARAMS *PNV2080_CTRL_GPU_INITIALIZE_CTX_PARAMS;

#define NV2080_CTRL_GPU_INITIALIZE_CTX_APERTURE              1:0
#define NV2080_CTRL_GPU_INITIALIZE_CTX_APERTURE_VIDMEM   (0x00000000)
#define NV2080_CTRL_GPU_INITIALIZE_CTX_APERTURE_COH_SYS  (0x00000001)
#define NV2080_CTRL_GPU_INITIALIZE_CTX_APERTURE_NCOH_SYS (0x00000002)

#define NV2080_CTRL_GPU_INITIALIZE_CTX_GPU_CACHEABLE         2:2
#define NV2080_CTRL_GPU_INITIALIZE_CTX_GPU_CACHEABLE_YES (0x00000000)
#define NV2080_CTRL_GPU_INITIALIZE_CTX_GPU_CACHEABLE_NO  (0x00000001)

/*
 * NV2080_CTRL_GPU_INITIALIZE_CTX_PRESERVE_CTX - Tells RM Whether this Ctx buffer needs to
 * do a full initialization (Load the golden image). When a context is promoted on a different
 * channel than it was originally inited, the client can use this flag to tell RM
 * that this is an already inited Context. In such cases RM will update the internal state
 * to update the context address and state variables.
 */

#define NV2080_CTRL_GPU_INITIALIZE_CTX_PRESERVE_CTX              3:3
#define NV2080_CTRL_GPU_INITIALIZE_CTX_PRESERVE_CTX_NO   (0x00000000)
#define NV2080_CTRL_GPU_INITIALIZE_CTX_PRESERVE_CTX_YES  (0x00000001)

/*
 * NV2080_CTRL_CMD_CPU_QUERY_ECC_INTR
 * Queries the top level ECC PMC PRI register
 * TODO remove these parameters, tracked in bug #1975721
 */
#define NV2080_CTRL_CMD_GPU_QUERY_ECC_INTR               (0x2080012e) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | 0x2E" */

typedef struct NV2080_CTRL_GPU_QUERY_ECC_INTR_PARAMS {
    NvU32 eccIntrStatus;
} NV2080_CTRL_GPU_QUERY_ECC_INTR_PARAMS;



/*
 * NV2080_CTRL_CMD_GPU_GET_OEM_BOARD_INFO
 *
 * If an InfoROM with a valid OEM Board Object is present, this
 * command returns relevant information from the object to the
 * caller.
 *
 * The following data are currently reported:
 *
 * buildDate
 *   The board's build date (8 digit BCD in format YYYYMMDD).
 *
 * marketingName
 *   The board's marketing name (24 ASCII letters e.g. "Quadro FX5800").
 *
 * boardSerialNumber
 *   The board's serial number.
 *
 * memoryManufacturer
 *   The board's memory manufacturer ('S'amsung/'H'ynix/'I'nfineon).
 *
 * memoryDateCode
 *   The board's memory datecode (LSB justified ASCII field with 0x00
 *   denoting empty space).
 *
 * productPartNumber
 *   The board's 900 product part number (LSB justified ASCII field with 0x00
 *   denoting empty space e.g. "900-21228-0208-200").
 *
 * boardRevision
 *   The board's revision (for e.g. A02, B01)
 *
 * boardType
 *   The board's type ('E'ngineering/'P'roduction)
 *
 * board699PartNumber
 *   The board's 699 product part number (LSB justified ASCII field with 0x00
 *   denoting empty space e.g. "699-21228-0208-200").
 *
 * Possible status return values are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 */
#define NV2080_CTRL_CMD_GPU_GET_OEM_BOARD_INFO    (0x2080013f) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_OEM_BOARD_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_GPU_MAX_MARKETING_NAME_LENGTH      (0x00000018)
#define NV2080_GPU_MAX_SERIAL_NUMBER_LENGTH       (0x00000010)
#define NV2080_GPU_MAX_MEMORY_PART_ID_LENGTH      (0x00000014)
#define NV2080_GPU_MAX_MEMORY_DATE_CODE_LENGTH    (0x00000006)
#define NV2080_GPU_MAX_PRODUCT_PART_NUMBER_LENGTH (0x00000014)

#define NV2080_CTRL_GPU_GET_OEM_BOARD_INFO_PARAMS_MESSAGE_ID (0x3FU)

typedef struct NV2080_CTRL_GPU_GET_OEM_BOARD_INFO_PARAMS {
    NvU32 buildDate;
    NvU8  marketingName[NV2080_GPU_MAX_MARKETING_NAME_LENGTH];
    NvU8  serialNumber[NV2080_GPU_MAX_SERIAL_NUMBER_LENGTH];
    NvU8  memoryManufacturer;
    NvU8  memoryPartID[NV2080_GPU_MAX_MEMORY_PART_ID_LENGTH];
    NvU8  memoryDateCode[NV2080_GPU_MAX_MEMORY_DATE_CODE_LENGTH];
    NvU8  productPartNumber[NV2080_GPU_MAX_PRODUCT_PART_NUMBER_LENGTH];
    NvU8  boardRevision[3];
    NvU8  boardType;
    NvU8  board699PartNumber[NV2080_GPU_MAX_PRODUCT_PART_NUMBER_LENGTH];
} NV2080_CTRL_GPU_GET_OEM_BOARD_INFO_PARAMS;



/*
 * NV2080_CTRL_CMD_GPU_GET_ID
 *
 * This command returns the gpuId of the associated object.
 *
 *   gpuId
 *     This field return the gpuId.
 *
 * Possible status return values are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 */
#define NV2080_CTRL_CMD_GPU_GET_ID (0x20800142) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_ID_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_ID_PARAMS_MESSAGE_ID (0x42U)

typedef struct NV2080_CTRL_GPU_GET_ID_PARAMS {
    NvU32 gpuId;
} NV2080_CTRL_GPU_GET_ID_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_SET_GPU_DEBUG_MODE
 *
 * This command is used to enable or disable GPU debug mode. While this mode
 * is enabled,  some client RM calls that can potentially timeout return
 * NV_ERR_BUSY_RETRY, signalling the client to try again once GPU
 * debug mode is disabled.
 *
 * mode
 *   This parameter specifies whether GPU debug mode is to be enabled or
 *   disabled. Possible values are:
 *
 *     NV2080_CTRL_GPU_DEBUG_MODE_ENABLED
 *     NV2080_CTRL_GPU_DEBUG_MODE_DISABLED
 *
 * Possible return status values are
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *
 */
#define NV2080_CTRL_CMD_GPU_SET_GPU_DEBUG_MODE (0x20800143) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_SET_GPU_DEBUG_MODE_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_SET_GPU_DEBUG_MODE_PARAMS_MESSAGE_ID (0x43U)

typedef struct NV2080_CTRL_GPU_SET_GPU_DEBUG_MODE_PARAMS {
    NvU32 mode;
} NV2080_CTRL_GPU_SET_GPU_DEBUG_MODE_PARAMS;

#define NV2080_CTRL_GPU_DEBUG_MODE_ENABLED     (0x00000001)
#define NV2080_CTRL_GPU_DEBUG_MODE_DISABLED    (0x00000002)

/*
 * NV2080_CTRL_CMD_GPU_GET_GPU_DEBUG_MODE
 *
 * This command is used to query whether debug mode is enabled on the current
 * GPU. Please see the description of NV2080_CTRL_CMD_GPU_SET_GPU_DEBUG_MODE
 * for more details on GPU debug mode.
 *
 * currentMode
 *   This parameter returns the state of GPU debug mode for the current GPU.
 *   Possible values are:
 *
 *     NV2080_CTRL_GPU_DEBUG_MODE_ENABLED
 *     NV2080_CTRL_GPU_DEBUG_MODE_DISABLED
 *
 * Possible return status values are
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *
 */
#define NV2080_CTRL_CMD_GPU_GET_GPU_DEBUG_MODE (0x20800144) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_GPU_DEBUG_MODE_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_GPU_DEBUG_MODE_PARAMS_MESSAGE_ID (0x44U)

typedef struct NV2080_CTRL_GPU_GET_GPU_DEBUG_MODE_PARAMS {
    NvU32 currentMode;
} NV2080_CTRL_GPU_GET_GPU_DEBUG_MODE_PARAMS;



/*
 * NV2080_CTRL_CMD_GPU_GET_ENGINE_PARTNERLIST
 *
 * Returns a list of engines that can partner or coexist
 * when using the target channel or partnership class.
 * This list may include all engines (pre-Kepler), or as few
 * as 1 engine (Kepler and beyond).
 *
 *   engineType
 *     This field specifies the target engine type.
 *     See cl2080.h for a list of valid engines.
 *
 *   partnershipClassId
 *     This field specifies the target channel
 *     or partnership class ID.
 *     An example of such a class is GF100_CHANNEL_GPFIFO.
 *
 *   runqueue
 *     This field is an index which indicates the runqueue to
 *     return the list of supported engines for. This is the
 *     same field as what NVOS04_FLAGS_GROUP_CHANNEL_RUNQUEUE
 *     specifies. This is only valid for TSG.
 *
 *   numPartners;
 *     This field returns the number of
 *     valid entries in the partnersList array
 *
 *   partnerList
 *     This field is an array containing the list of supported
 *     partner engines types, in no particular order, and
 *     may even be empty (numPartners = 0).
 *     See cl2080.h for a list of possible engines.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_PARAM_STRUCT
 */

#define NV2080_CTRL_CMD_GPU_GET_ENGINE_PARTNERLIST           (0x20800147) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_ENGINE_PARTNERLIST_PARAMS_MESSAGE_ID" */

/* this macro specifies the maximum number of partner entries */
#define NV2080_CTRL_GPU_MAX_ENGINE_PARTNERS                  (0x00000020)

#define NV2080_CTRL_GPU_GET_ENGINE_PARTNERLIST_PARAMS_MESSAGE_ID (0x47U)

typedef struct NV2080_CTRL_GPU_GET_ENGINE_PARTNERLIST_PARAMS {
    NvU32   engineType;
    NvU32   partnershipClassId;
    NvU32   runqueue;
    NvU32   numPartners;
    // C form: NvU32 partnerList[NV2080_CTRL_GPU_MAX_ENGINE_PARTNERS];
    NvU32   partnerList[NV2080_CTRL_GPU_MAX_ENGINE_PARTNERS];
} NV2080_CTRL_GPU_GET_ENGINE_PARTNERLIST_PARAMS;



/*
 * NV2080_CTRL_CMD_GPU_GET_GID_INFO
 *
 * This command returns the GPU ID (GID) string for the associated
 * GPU.  This value can be useful for GPU identification and security
 * system validation.
 *
 * The GPU ID is a SHA-1 based 16 byte ID, formatted as a 32 character
 *      hexadecimal string as "GPU-%08x-%04x-%04x-%04x-%012x" (the
 *      canonical format of a UUID)
 *
 * The GPU IDs are generated using the ECID, PMC_BOOT_0, and
 * PMC_BOOT_42 of the GPU as the hash message.
 *
 *   index
 *     (Input) "Select which GID set to get." Or so the original documentation
 *     said. In reality, there is only one GID per GPU, and the implementation
 *     completely ignores this parameter. You can too.
 *
 *   flags (Input) The _FORMAT* flags designate ascii or binary format. Binary
 *     format returns the raw bytes of either the 16-byte SHA-1 ID or the
 *     32-byte SHA-256 ID.
 *
 *     The _TYPE* flags needs to specify the _SHA1 type.
 *
 *   length
 *     (Output) Actual GID length, in bytes.
 *
 *   data[NV2080_BUS_MAX_GID_LENGTH]
 *     (Output) Result buffer: the GID itself, in a format that is determined by
 *     the "flags" field (described above).
 *
 * Possible status return values are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 *   NV_ERR_INVALID_STATE
 */
#define NV2080_CTRL_CMD_GPU_GET_GID_INFO (0x2080014a) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_GID_INFO_PARAMS_MESSAGE_ID" */

/* maximum possible number of bytes of GID information returned */
#define NV2080_GPU_MAX_GID_LENGTH        (0x000000100)

#define NV2080_CTRL_GPU_GET_GID_INFO_PARAMS_MESSAGE_ID (0x4AU)

typedef struct NV2080_CTRL_GPU_GET_GID_INFO_PARAMS {
    NvU32 index;
    NvU32 flags;
    NvU32 length;
    NvU8  data[NV2080_GPU_MAX_GID_LENGTH];
} NV2080_CTRL_GPU_GET_GID_INFO_PARAMS;

/* valid flags values */
#define NV2080_GPU_CMD_GPU_GET_GID_FLAGS_FORMAT                  1:0
#define NV2080_GPU_CMD_GPU_GET_GID_FLAGS_FORMAT_ASCII  (0x00000000)
#define NV2080_GPU_CMD_GPU_GET_GID_FLAGS_FORMAT_BINARY (0x00000002)

#define NV2080_GPU_CMD_GPU_GET_GID_FLAGS_TYPE                    2:2
#define NV2080_GPU_CMD_GPU_GET_GID_FLAGS_TYPE_SHA1     (0x00000000)



/*
 * NV2080_CTRL_CMD_SET_GPU_OPTIMUS_INFO
 *
 * This command will specify that system is Optimus enabled.
 *
 * isOptimusEnabled
 *     Set NV_TRUE if system is Optimus enabled.
 *
 * Possible status return values are:
 *      NV_OK
 */
#define NV2080_CTRL_CMD_SET_GPU_OPTIMUS_INFO (0x2080014c) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_OPTIMUS_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_OPTIMUS_INFO_PARAMS_MESSAGE_ID (0x4CU)

typedef struct NV2080_CTRL_GPU_OPTIMUS_INFO_PARAMS {
    NvBool isOptimusEnabled;
} NV2080_CTRL_GPU_OPTIMUS_INFO_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_GET_IP_VERSION
 *
 * Will return the IP VERSION on the given engine for engines that support
 * this capability.
 *
 *   targetEngine
 *     This parameter specifies the target engine type to query for IP_VERSION.
 *
 *   ipVersion
 *     This parameter returns the IP VERSION read from the unit's IP_VER
 *     register.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_NOT_SUPPORTED
 */

#define NV2080_CTRL_CMD_GPU_GET_IP_VERSION (0x2080014d) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_IP_VERSION_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_IP_VERSION_PARAMS_MESSAGE_ID (0x4DU)

typedef struct NV2080_CTRL_GPU_GET_IP_VERSION_PARAMS {
    NvU32 targetEngine;
    NvU32 ipVersion;
} NV2080_CTRL_GPU_GET_IP_VERSION_PARAMS;

#define NV2080_CTRL_GPU_GET_IP_VERSION_DISPLAY     (0x00000001)
#define NV2080_CTRL_GPU_GET_IP_VERSION_HDACODEC    (0x00000002)
#define NV2080_CTRL_GPU_GET_IP_VERSION_PMGR        (0x00000003)
#define NV2080_CTRL_GPU_GET_IP_VERSION_PPWR_PMU    (0x00000004)
#define NV2080_CTRL_GPU_GET_IP_VERSION_DISP_FALCON (0x00000005)



/*
 * NV2080_CTRL_CMD_GPU_HANDLE_GPU_SR
 *
 * Communicates to RM to handle GPU Surprise Removal
 * Called from client when it receives SR IRP from OS
 * Possible status values returned are:
 *   NVOS_STATUS_SUCCESS
 */
#define NV2080_CTRL_CMD_GPU_HANDLE_GPU_SR                      (0x20800167) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | 0x67" */



/* NV2080_CTRL_CMD_GPU_GET_OEM_INFO
 *
 * If an InfoROM with a valid OEM Object is present, this
 * command returns relevant information from the object to the
 * caller.
 *
 * oemInfo
 *  This array stores information specifically for OEM use
 *  (e.g. "their own serial number", "lot codes", etc)
 *  "The byte definition is up to the OEM"
 *
 * Possible status return values are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 */

#define NV2080_CTRL_CMD_GPU_GET_OEM_INFO (0x20800169) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_OEM_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_GPU_MAX_OEM_INFO_LENGTH   (0x000001F8)

#define NV2080_CTRL_GPU_GET_OEM_INFO_PARAMS_MESSAGE_ID (0x69U)

typedef struct NV2080_CTRL_GPU_GET_OEM_INFO_PARAMS {
    NvU8 oemInfo[NV2080_GPU_MAX_OEM_INFO_LENGTH];
} NV2080_CTRL_GPU_GET_OEM_INFO_PARAMS;



#define NV2080_CTRL_CMD_GPU_QUERY_FUNCTION_STATUS_PARAMS_MESSAGE_ID (0x73U)

typedef struct NV2080_CTRL_CMD_GPU_QUERY_FUNCTION_STATUS_PARAMS {
    NvU32 statusMask;
    NvU32 xusbData;
    NvU32 ppcData;
} NV2080_CTRL_CMD_GPU_QUERY_FUNCTION_STATUS_PARAMS;

#define NV2080_CTRL_CMD_GPU_QUERY_FUNCTION_STATUS (0x20800173) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_CMD_GPU_QUERY_FUNCTION_STATUS_PARAMS_MESSAGE_ID" */



/*
 * NV2080_CTRL_CMD_GPU_GET_VMMU_SEGMENT_SIZE
 *
 * This command returns the VMMU page size
 *
 *   vmmuSegmentSize
 *     Output parameter.
 *     Returns the VMMU segment size (in bytes)
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 */
#define NV2080_CTRL_CMD_GPU_GET_VMMU_SEGMENT_SIZE (0x2080017e) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_VMMU_SEGMENT_SIZE_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_VMMU_SEGMENT_SIZE_PARAMS_MESSAGE_ID (0x7EU)

typedef struct NV2080_CTRL_GPU_GET_VMMU_SEGMENT_SIZE_PARAMS {
    NV_DECLARE_ALIGNED(NvU64 vmmuSegmentSize, 8);
} NV2080_CTRL_GPU_GET_VMMU_SEGMENT_SIZE_PARAMS;

#define NV2080_CTRL_GPU_VMMU_SEGMENT_SIZE_32MB     0x02000000
#define NV2080_CTRL_GPU_VMMU_SEGMENT_SIZE_64MB     0x04000000
#define NV2080_CTRL_GPU_VMMU_SEGMENT_SIZE_128MB    0x08000000
#define NV2080_CTRL_GPU_VMMU_SEGMENT_SIZE_256MB    0x10000000
#define NV2080_CTRL_GPU_VMMU_SEGMENT_SIZE_512MB    0x20000000


/*
 * NV2080_CTRL_CMD_GPU_GET_MAX_SUPPORTED_PAGE_SIZE
 *
 * This command returns information regarding maximum page size supported
 * by GMMU on the platform on which RM is running.
 *
 * [OUT] maxSupportedPageSize
 *      - Maximum local vidmem page size supported by GMMU of a given GPU (HW)
 *        on a given platform (OS)
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 */
#define NV2080_CTRL_CMD_GPU_GET_MAX_SUPPORTED_PAGE_SIZE (0x20800188) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_MAX_SUPPORTED_PAGE_SIZE_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_MAX_SUPPORTED_PAGE_SIZE_PARAMS_MESSAGE_ID (0x88U)

typedef struct NV2080_CTRL_GPU_GET_MAX_SUPPORTED_PAGE_SIZE_PARAMS {
    NvU32 maxSupportedPageSize;
} NV2080_CTRL_GPU_GET_MAX_SUPPORTED_PAGE_SIZE_PARAMS;



/*
 * NV2080_CTRL_CMD_GPU_GET_PIDS
 *
 * Given a resource identifier and its type, this command returns a set of
 * process identifiers (PIDs) of processes that have instantiated this resource.
 * For example, given a class number, this command returns a list of all
 * processes with clients that have matching object allocations.
 * This is a SMC aware call and the scope of the information gets restricted
 * based on partition subscription.
 * The call enforces partition subscription if SMC is enabled, and client is not
 * a monitoring client.
 * Monitoring clients get global information without any scope based filtering.
 * Monitoring clients are also not expected to subscribe to a partition when
 * SMC is enabled.
 *
 *   idType
 *     Type of the resource identifier. See below for a list of valid types.
 *   id
 *     Resource identifier.
 *   pidTblCount
 *      Number of entries in the PID table.
 *   pidTbl
 *     Table which will contain the PIDs. Each table entry is of type NvU32.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 */
#define NV2080_CTRL_CMD_GPU_GET_PIDS       (0x2080018d) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_PIDS_PARAMS_MESSAGE_ID" */

/* max size of pidTable */
#define NV2080_CTRL_GPU_GET_PIDS_MAX_COUNT 950

#define NV2080_CTRL_GPU_GET_PIDS_PARAMS_MESSAGE_ID (0x8DU)

typedef struct NV2080_CTRL_GPU_GET_PIDS_PARAMS {
    NvU32 idType;
    NvU32 id;
    NvU32 pidTblCount;
    NvU32 pidTbl[NV2080_CTRL_GPU_GET_PIDS_MAX_COUNT];
} NV2080_CTRL_GPU_GET_PIDS_PARAMS;

/*
 * Use class NV20_SUBDEVICE_0 with NV2080_CTRL_GPU_GET_PIDS_ID_TYPE_CLASS to query
 * PIDs with or without GPU contexts. For any other class id, PIDs only with GPU
 * contexts are returned.
 */
#define NV2080_CTRL_GPU_GET_PIDS_ID_TYPE_CLASS      (0x00000000)
#define NV2080_CTRL_GPU_GET_PIDS_ID_TYPE_VGPU_GUEST (0x00000001)

/*
 * NV2080_CTRL_SMC_SUBSCRIPTION_INFO
 *
 * This structure contains information about the SMC subscription type.
 * If MIG is enabled a valid ID is returned, it is set to PARTITIONID_INVALID otherwise.
 *
 *  computeInstanceId
 *      This parameter returns a valid compute instance ID
 *  gpuInstanceId
 *      This parameter returns a valid GPU instance ID
 */
typedef struct NV2080_CTRL_SMC_SUBSCRIPTION_INFO {
    NvU32 computeInstanceId;
    NvU32 gpuInstanceId;
} NV2080_CTRL_SMC_SUBSCRIPTION_INFO;

/*
 * NV2080_CTRL_GPU_PID_INFO_VIDEO_MEMORY_USAGE_DATA
 *
 * This structure contains the video memory usage information.
 *
 *   memPrivate
 *     This parameter returns the amount of memory exclusively owned
 *     (i.e. private) to the client
 *   memSharedOwned
 *     This parameter returns the amount of shared memory owned by the client
 *   memSharedDuped
 *     This parameter returns the amount of shared memory duped by the client
 *   protectedMemPrivate
 *     This parameter returns the amount of protected memory exclusively owned
 *     (i.e. private) to the client whenever memory protection is enabled
 *   protectedMemSharedOwned
 *     This parameter returns the amount of shared protected memory owned by the
 *     client whenever memory protection is enabled
 *   protectedMemSharedDuped
 *     This parameter returns the amount of shared protected memory duped by the
 *     client whenever memory protection is enabled
 */
typedef struct NV2080_CTRL_GPU_PID_INFO_VIDEO_MEMORY_USAGE_DATA {
    NV_DECLARE_ALIGNED(NvU64 memPrivate, 8);
    NV_DECLARE_ALIGNED(NvU64 memSharedOwned, 8);
    NV_DECLARE_ALIGNED(NvU64 memSharedDuped, 8);
    NV_DECLARE_ALIGNED(NvU64 protectedMemPrivate, 8);
    NV_DECLARE_ALIGNED(NvU64 protectedMemSharedOwned, 8);
    NV_DECLARE_ALIGNED(NvU64 protectedMemSharedDuped, 8);
} NV2080_CTRL_GPU_PID_INFO_VIDEO_MEMORY_USAGE_DATA;

#define NV2080_CTRL_GPU_PID_INFO_INDEX_VIDEO_MEMORY_USAGE (0x00000000)

#define NV2080_CTRL_GPU_PID_INFO_INDEX_MAX                NV2080_CTRL_GPU_PID_INFO_INDEX_VIDEO_MEMORY_USAGE

typedef union NV2080_CTRL_GPU_PID_INFO_DATA {
    NV_DECLARE_ALIGNED(NV2080_CTRL_GPU_PID_INFO_VIDEO_MEMORY_USAGE_DATA vidMemUsage, 8);
} NV2080_CTRL_GPU_PID_INFO_DATA;


/*
 * NV2080_CTRL_GPU_PID_INFO
 *
 * This structure contains the per pid information. Each type of information
 * retrievable via NV2080_CTRL_CMD_GET_PID_INFO is assigned a unique index
 * below. In addition the process for which the lookup is for is also defined.
 * This is a SMC aware call and the scope of the information gets restricted
 * based on partition subscription.
 * The call enforces partition subscription if SMC is enabled, and client is not
 * a monitoring client.
 * Monitoring clients get global information without any scope based filtering.
 * Monitoring clients are also not expected to subscribe to a partition when
 * SMC is enabled.
 *
 *   pid
 *     This parameter specifies the PID of the process for which information is
 *     to be queried.
 *   index
 *     This parameter specifies the type of information being queried for the
 *     process of interest.
 *   result
 *     This parameter returns the result of the instruction's execution.
 *   data
 *     This parameter returns the data corresponding to the information which is
 *     being queried.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_PARAM_STRUCT
 *
 * Valid PID information indices are:
 *
 *   NV2080_CTRL_GPU_PID_INFO_INDEX_VIDEO_MEMORY_USAGE
 *     This index is used to request the amount of video memory on this GPU
 *     allocated to the process.
 */
typedef struct NV2080_CTRL_GPU_PID_INFO {
    NvU32                             pid;
    NvU32                             index;
    NvU32                             result;
    NV_DECLARE_ALIGNED(NV2080_CTRL_GPU_PID_INFO_DATA data, 8);
    NV2080_CTRL_SMC_SUBSCRIPTION_INFO smcSubscription;
} NV2080_CTRL_GPU_PID_INFO;

/*
 * NV2080_CTRL_CMD_GPU_GET_PID_INFO
 *
 * This command allows querying per-process information from the RM. Clients
 * request information by specifying a unique informational index and the
 * Process ID of the process in question. The result is set to indicate success
 * and the information queried (if available) is returned in the data parameter.
 *
 *   pidInfoListCount
 *     The number of valid entries in the pidInfoList array.
 *   pidInfoList
 *     An array of NV2080_CTRL_GPU_PID_INFO of maximum length
 *     NV2080_CTRL_GPU_GET_PID_INFO_MAX_COUNT.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 */
#define NV2080_CTRL_CMD_GPU_GET_PID_INFO       (0x2080018e) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_PID_INFO_PARAMS_MESSAGE_ID" */

/* max size of pidInfoList */
#define NV2080_CTRL_GPU_GET_PID_INFO_MAX_COUNT 200

#define NV2080_CTRL_GPU_GET_PID_INFO_PARAMS_MESSAGE_ID (0x8EU)

typedef struct NV2080_CTRL_GPU_GET_PID_INFO_PARAMS {
    NvU32 pidInfoListCount;
    NV_DECLARE_ALIGNED(NV2080_CTRL_GPU_PID_INFO pidInfoList[NV2080_CTRL_GPU_GET_PID_INFO_MAX_COUNT], 8);
} NV2080_CTRL_GPU_GET_PID_INFO_PARAMS;


/*!
 * Compute policy types to be specified by callers to set a config.
 *
 * _TIMESLICE
 *     Set the timeslice config for the requested GPU.
 *     Check @ref NV2080_CTRL_GPU_COMPUTE_POLICY_CONFIG_DATA_TIMESLICE for
 *     permissible timeslice values.
 */
#define NV2080_CTRL_GPU_COMPUTE_POLICY_TIMESLICE      0
#define NV2080_CTRL_GPU_COMPUTE_POLICY_MAX            1

/*!
 * Enum consisting of permissible timeslice options that can configured
 * for a GPU. These can be queried by compute clients and the exact
 * timeslice values can be chosen appropriately as per GPU support
 */
typedef enum NV2080_CTRL_GPU_COMPUTE_POLICY_CONFIG_DATA_TIMESLICE {
    NV2080_CTRL_CMD_GPU_COMPUTE_TIMESLICE_DEFAULT = 0,
    NV2080_CTRL_CMD_GPU_COMPUTE_TIMESLICE_SHORT = 1,
    NV2080_CTRL_CMD_GPU_COMPUTE_TIMESLICE_MEDIUM = 2,
    NV2080_CTRL_CMD_GPU_COMPUTE_TIMESLICE_LONG = 3,
    NV2080_CTRL_CMD_GPU_COMPUTE_TIMESLICE_MAX = 4,
} NV2080_CTRL_GPU_COMPUTE_POLICY_CONFIG_DATA_TIMESLICE;


/*!
 * NV2080_CTRL_CMD_GPU_VALIDATE_MEM_MAP_REQUEST
 *
 * @brief Validate the address range for memory map request by comparing the
 *        user supplied address range with GPU BAR0/BAR1 range.
 *
 * @param[in]   addressStart    Start address for memory map request
 * @param[in]   addressLength   Length for for memory map request
 * @param[out]  protection      NV_PROTECT_READ_WRITE, if both read/write is allowed
 *                              NV_PROTECT_READABLE, if only read is allowed
 *
 * Possible status values returned are:
 *     NV_OK
 *     NV_ERR_PROTECTION_FAULT
 *
 */
#define NV2080_CTRL_CMD_GPU_VALIDATE_MEM_MAP_REQUEST (0x20800198) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_VALIDATE_MEM_MAP_REQUEST_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_VALIDATE_MEM_MAP_REQUEST_PARAMS_MESSAGE_ID (0x98U)

typedef struct NV2080_CTRL_GPU_VALIDATE_MEM_MAP_REQUEST_PARAMS {
    NV_DECLARE_ALIGNED(NvU64 addressStart, 8);
    NV_DECLARE_ALIGNED(NvU64 addressLength, 8);
    NvU32 protection;
} NV2080_CTRL_GPU_VALIDATE_MEM_MAP_REQUEST_PARAMS;



/*
 * NV2080_CTRL_CMD_GPU_GET_ENGINE_LOAD_TIMES
 *
 * This command is used to retrieve the load time (latency) of each engine.
 *  
 *   engineCount
 *     This field specifies the number of entries of the following
 *     three arrays.
 *
 *   engineList[NV2080_GPU_MAX_ENGINE_OBJECTS]
 *     An array of NvU32 which stores each engine's descriptor.
 *
 *   engineStateLoadTime[NV2080_GPU_MAX_ENGINE_OBJECTS]
 *     A array of NvU64 which stores each engine's load time.
 *
 *   engineIsInit[NV2080_GPU_MAX_ENGINE_OBJECTS]
 *     A array of NvBool which stores each engine's initialization status.
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV2080_CTRL_CMD_GPU_GET_ENGINE_LOAD_TIMES (0x2080019b) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_ENGINE_LOAD_TIMES_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_MAX_ENGINE_OBJECTS        0x8a

#define NV2080_CTRL_GPU_GET_ENGINE_LOAD_TIMES_PARAMS_MESSAGE_ID (0x9BU)

typedef struct NV2080_CTRL_GPU_GET_ENGINE_LOAD_TIMES_PARAMS {
    NvU32  engineCount;
    NvU32  engineList[NV2080_CTRL_GPU_MAX_ENGINE_OBJECTS];
    NV_DECLARE_ALIGNED(NvU64 engineStateLoadTime[NV2080_CTRL_GPU_MAX_ENGINE_OBJECTS], 8);
    NvBool engineIsInit[NV2080_CTRL_GPU_MAX_ENGINE_OBJECTS];
} NV2080_CTRL_GPU_GET_ENGINE_LOAD_TIMES_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_GET_ID_NAME_MAPPING
 *
 * This command is used to retrieve the mapping of engine ID and engine Name.
 * 
 *   engineCount
 *     This field specifies the size of the mapping.
 *   
 *   engineID
 *     An array of NvU32 which stores each engine's descriptor.
 *
 *   engineName
 *     An array of char[100] which stores each engine's name.
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV2080_CTRL_CMD_GPU_GET_ID_NAME_MAPPING (0x2080019c) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_ID_NAME_MAPPING_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_GPU_GET_ID_NAME_MAPPING_PARAMS_MESSAGE_ID (0x9CU)

typedef struct NV2080_CTRL_GPU_GET_ID_NAME_MAPPING_PARAMS {
    NvU32 engineCount;
    NvU32 engineID[NV2080_CTRL_GPU_MAX_ENGINE_OBJECTS];
    char  engineName[NV2080_CTRL_GPU_MAX_ENGINE_OBJECTS][100];
} NV2080_CTRL_GPU_GET_ID_NAME_MAPPING_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_EXEC_REG_OPS_NOPTRS
 *
 * Same as above NV2080_CTRL_CMD_GPU_EXEC_REG_OPS except that this CTRL CMD will
 * not allow any embedded pointers. The regOps array is inlined as part of the
 * struct. 
 * NOTE: This intended for gsp plugin only as it may override regOp access
 *       restrictions
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_NOT_SUPPORTED
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV2080_CTRL_CMD_GPU_EXEC_REG_OPS_NOPTRS (0x2080019d) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_EXEC_REG_OPS_NOPTRS_PARAMS_MESSAGE_ID" */

/* setting this to 100 keeps it right below 4k in size */
#define NV2080_CTRL_REG_OPS_ARRAY_MAX           100
#define NV2080_CTRL_GPU_EXEC_REG_OPS_NOPTRS_PARAMS_MESSAGE_ID (0x9DU)

typedef struct NV2080_CTRL_GPU_EXEC_REG_OPS_NOPTRS_PARAMS {
    NvHandle               hClientTarget;
    NvHandle               hChannelTarget;
    NvU32                  bNonTransactional;
    NvU32                  reserved00[2];
    NvU32                  regOpCount;

} NV2080_CTRL_GPU_EXEC_REG_OPS_NOPTRS_PARAMS;

#define NV2080_CTRL_GPU_SKYLINE_INFO_MAX_SKYLINES            8
#define NV2080_CTRL_GPU_SKYLINE_INFO_MAX_NON_SINGLETON_VGPCS 8
/*!
 * NV2080_CTRL_GPU_SKYLINE_INFO
 * skylineVgpcSize[OUT]
 *      - TPC count of non-singleton VGPCs
 * singletonVgpcMask[OUT]
 *      - Mask of active Singletons
 * maxInstances[OUT]
 *      - Max allowed instances of this skyline concurrently on a GPU
 * computeSizeFlag
 *      - One of NV2080_CTRL_GPU_PARTITION_FLAG_COMPUTE_SIZE_* flags which is associated with this skyline
 */
typedef struct NV2080_CTRL_GPU_SKYLINE_INFO {
    NvU8  skylineVgpcSize[NV2080_CTRL_GPU_SKYLINE_INFO_MAX_NON_SINGLETON_VGPCS];
    NvU32 singletonVgpcMask;
    NvU32 maxInstances;
    NvU32 computeSizeFlag;
} NV2080_CTRL_GPU_SKYLINE_INFO;

/*!
 * NV2080_CTRL_GPU_GET_SKYLINE_INFO_PARAMS
 * skylineTable[OUT]
 *      - TPC count of non-singleton VGPCs
 *      - Mask of singleton vGPC IDs active
 *      - Max Instances of this skyline possible concurrently
 *      - Associated compute size with the indexed skyline
 * validEntries[OUT]
 *      - Number of entries which contain valid info in skylineInfo
 */
#define NV2080_CTRL_GPU_GET_SKYLINE_INFO_PARAMS_MESSAGE_ID (0x9FU)

typedef struct NV2080_CTRL_GPU_GET_SKYLINE_INFO_PARAMS {
    NV2080_CTRL_GPU_SKYLINE_INFO skylineTable[NV2080_CTRL_GPU_SKYLINE_INFO_MAX_SKYLINES];
    NvU32                        validEntries;
} NV2080_CTRL_GPU_GET_SKYLINE_INFO_PARAMS;

/*
 * NV2080_CTRL_CMD_GPU_GET_SKYLINE_INFO
 *
 * Retrieves skyline information about the GPU. Params are sized to currently known max
 * values, but will need to be modified in the future should that change.
 */
#define NV2080_CTRL_CMD_GPU_GET_SKYLINE_INFO (0x2080019f) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_GPU_INTERFACE_ID << 8) | NV2080_CTRL_GPU_GET_SKYLINE_INFO_PARAMS_MESSAGE_ID" */

/* _ctrl2080gpu_h_ */
