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
#pragma once

#include <nvtypes.h>
#if defined(_MSC_VER)
#pragma warning(disable:4324)
#endif

//
// This file was generated with FINN, an NVIDIA coding tool.
// Source file: ctrl/ctrl0000/ctrl0000system.finn
//




#include "ctrl/ctrlxxxx.h"
#include "ctrl/ctrl0000/ctrl0000base.h"

/* NV01_ROOT (client) system control commands and parameters */

/*
 * NV0000_CTRL_CMD_SYSTEM_GET_FEATURES
 *
 * This command returns a mask of supported features for the SYSTEM category
 * of the 0000 class.
 *
 *     Valid features include:
 *         
 *       NV0000_CTRL_GET_FEATURES_SLI
 *         When this bit is set, SLI is supported.
 *       NV0000_CTRL_GET_FEATURES_UEFI
 *         When this bit is set, it is a UEFI system.
 *       NV0000_CTRL_SYSTEM_GET_FEATURES_IS_EFI_INIT
 *         When this bit is set, EFI has initialized core channel 
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_STATE
 */
#define NV0000_CTRL_CMD_SYSTEM_GET_FEATURES (0x1f0) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | 0xF0" */

#define NV0000_CTRL_SYSTEM_GET_FEATURES_PARAMS_MESSAGE_ID (0xF0U)

typedef struct NV0000_CTRL_SYSTEM_GET_FEATURES_PARAMS {
    NvU32 featuresMask;
} NV0000_CTRL_SYSTEM_GET_FEATURES_PARAMS;



/* Valid feature values */
#define NV0000_CTRL_SYSTEM_GET_FEATURES_SLI                                 0:0
#define NV0000_CTRL_SYSTEM_GET_FEATURES_SLI_FALSE         (0x00000000)
#define NV0000_CTRL_SYSTEM_GET_FEATURES_SLI_TRUE          (0x00000001)
#define NV0000_CTRL_SYSTEM_GET_FEATURES_UEFI                                1:1
#define NV0000_CTRL_SYSTEM_GET_FEATURES_UEFI_FALSE        (0x00000000)
#define NV0000_CTRL_SYSTEM_GET_FEATURES_UEFI_TRUE         (0x00000001)
#define NV0000_CTRL_SYSTEM_GET_FEATURES_IS_EFI_INIT                         2:2
#define NV0000_CTRL_SYSTEM_GET_FEATURES_IS_EFI_INIT_FALSE (0x00000000)
#define NV0000_CTRL_SYSTEM_GET_FEATURES_IS_EFI_INIT_TRUE  (0x00000001)
/*
 * NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION
 *
 * This command returns the current driver information.
 * The first time this is called the size of strings is
 * set with the greater of NV_BUILD_BRANCH_VERSION and
 * NV_DISPLAY_DRIVER_TITLE. The client then allocates memory
 * of size sizeOfStrings for pVersionBuffer and pTitleBuffer
 * and calls the command again to receive driver info.
 *
 *   sizeOfStrings
 *       This field returns the size in bytes of the pVersionBuffer and
 *       pTitleBuffer strings.
 *   pDriverVersionBuffer
 *       This field returns the version (NV_VERSION_STRING).
 *   pVersionBuffer
 *       This field returns the version (NV_BUILD_BRANCH_VERSION).
 *   pTitleBuffer
 *       This field returns the title (NV_DISPLAY_DRIVER_TITLE).
 *   changelistNumber
 *       This field returns the changelist value (NV_BUILD_CHANGELIST_NUM).
 *   officialChangelistNumber
 *       This field returns the last official changelist value
 *       (NV_LAST_OFFICIAL_CHANGELIST_NUM).
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 */

#define NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION          (0x101) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_PARAMS_MESSAGE_ID (0x1U)

typedef struct NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_PARAMS {
    NvU32 sizeOfStrings;
    NV_DECLARE_ALIGNED(NvP64 pDriverVersionBuffer, 8);
    NV_DECLARE_ALIGNED(NvP64 pVersionBuffer, 8);
    NV_DECLARE_ALIGNED(NvP64 pTitleBuffer, 8);
    NvU32 changelistNumber;
    NvU32 officialChangelistNumber;
} NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_PARAMS;

/*
 * NV0000_CTRL_CMD_SYSTEM_GET_CPU_INFO
 *
 * This command returns system CPU information.
 *
 *   type
 *     This field returns the processor type.
 *     Legal processor types include:
 *       Intel processors:
 *         P55       : P55C - MMX
 *         P6        : PPro
 *         P2        : PentiumII
 *         P2XC      : Xeon & Celeron
 *         CELA      : Celeron-A
 *         P3        : Pentium-III
 *         P3_INTL2  : Pentium-III w/integrated L2 (fullspeed, on die, 256K)
 *         P4        : Pentium 4
 *         CORE2     : Core2 Duo Conroe
 *       AMD processors
 *         K62       : K6-2 w/ 3DNow
 *       IDT/Centaur processors
 *         C6        : WinChip C6
 *         C62       : WinChip 2 w/ 3DNow
 *       Cyrix processors
 *         GX        : MediaGX
 *         M1        : 6x86
 *         M2        : M2
 *         MGX       : MediaGX w/ MMX
 *       Transmeta processors
 *         TM_CRUSOE : Transmeta Crusoe(tm)
 *       PowerPC processors
 *         PPC603    : PowerPC 603
 *         PPC604    : PowerPC 604
 *         PPC750    : PowerPC 750
 *
 *   capabilities
 *     This field returns the capabilities of the processor.
 *     Legal processor capabilities include:
 *       MMX                 : supports MMX
 *       SSE                 : supports SSE
 *       3DNOW               : supports 3DNow
 *       SSE2                : supports SSE2
 *       SFENCE              : supports SFENCE
 *       WRITE_COMBINING     : supports write-combining
 *       ALTIVEC             : supports ALTIVEC
 *       PUT_NEEDS_IO        : requires OUT inst w/PUT updates
 *       NEEDS_WC_WORKAROUND : requires workaround for P4 write-combining bug
 *       3DNOW_EXT           : supports 3DNow Extensions
 *       MMX_EXT             : supports MMX Extensions
 *       CMOV                : supports CMOV
 *       CLFLUSH             : supports CLFLUSH
 *       SSE3                : supports SSE3
 *       NEEDS_WAR_124888    : requires write to GPU while spinning on
 *                           : GPU value
 *       HT                  : support hyper-threading
 *   clock
 *     This field returns the processor speed in MHz.
 *   L1DataCacheSize
 *     This field returns the level 1 data (or unified) cache size
 *     in kilobytes.
 *   L2DataCacheSize
 *     This field returns the level 2 data (or unified) cache size
 *     in kilobytes.
 *   dataCacheLineSize
 *     This field returns the bytes per line in the level 1 data cache.
 *   numLogicalCpus
 *     This field returns the number of logical processors.  On Intel x86
 *     systems that support it, this value will incorporate the current state
 *     of HyperThreading.
 *   numPhysicalCpus
 *     This field returns the number of physical processors.
 *   name
 *     This field returns the CPU name in ASCII string format.
 *   family
 *     Vendor defined Family and Extended Family combined
 *   model
 *     Vendor defined Model and Extended Model combined
 *   stepping
 *     Silicon stepping
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV0000_CTRL_CMD_SYSTEM_GET_CPU_INFO (0x102) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_GET_CPU_INFO_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SYSTEM_GET_CPU_INFO_PARAMS_MESSAGE_ID (0x2U)

typedef struct NV0000_CTRL_SYSTEM_GET_CPU_INFO_PARAMS {
    NvU32 type;                               /* processor type        */
    NvU32 capabilities;                       /* processor caps        */
    NvU32 clock;                              /* processor speed (MHz) */
    NvU32 L1DataCacheSize;                    /* L1 dcache size (KB)   */
    NvU32 L2DataCacheSize;                    /* L2 dcache size (KB)   */
    NvU32 dataCacheLineSize;                  /* L1 dcache bytes/line  */
    NvU32 numLogicalCpus;                     /* logial processor cnt  */
    NvU32 numPhysicalCpus;                    /* physical processor cnt*/
    NvU8  name[52];                           /* embedded cpu name     */
    NvU32 family;                             /* Vendor defined Family and Extended Family combined */
    NvU32 model;                              /* Vendor defined Model and Extended Model combined   */
    NvU8  stepping;                           /* Silicon stepping      */
    NvU32 coresOnDie;                         /* cpu cores per die     */
} NV0000_CTRL_SYSTEM_GET_CPU_INFO_PARAMS;

/*  processor type values */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_UNKNOWN            (0x00000000)
/* Intel types */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_P5                 (0x00000001)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_P55                (0x00000002)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_P6                 (0x00000003)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_P2                 (0x00000004)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_P2XC               (0x00000005)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_CELA               (0x00000006)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_P3                 (0x00000007)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_P3_INTL2           (0x00000008)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_P4                 (0x00000009)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_CORE2              (0x00000010)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_CELN_M16H          (0x00000011)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_CORE2_EXTRM        (0x00000012)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_ATOM               (0x00000013)
/* AMD types */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_K5                 (0x00000030)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_K6                 (0x00000031)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_K62                (0x00000032)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_K63                (0x00000033)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_K7                 (0x00000034)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_K8                 (0x00000035)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_K10                (0x00000036)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_K11                (0x00000037)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_RYZEN              (0x00000038)
/* IDT/Centaur types */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_C6                 (0x00000060)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_C62                (0x00000061)
/* Cyrix types */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_GX                 (0x00000070)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_M1                 (0x00000071)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_M2                 (0x00000072)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_MGX                (0x00000073)
/* Transmeta types  */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_TM_CRUSOE          (0x00000080)
/* IBM types */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_PPC603             (0x00000090)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_PPC604             (0x00000091)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_PPC750             (0x00000092)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_POWERN             (0x00000093)
/* Unknown ARM architecture CPU type */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_ARM_UNKNOWN        (0xA0000000)
/* ARM Ltd types */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_ARM_A9             (0xA0000009)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_ARM_A15            (0xA000000F)
/* NVIDIA types */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_NV_DENVER_1_0      (0xA0001000)
#define NV0000_CTRL_SYSTEM_CPU_TYPE_NV_DENVER_2_0      (0xA0002000)

/* Generic types */
#define NV0000_CTRL_SYSTEM_CPU_TYPE_ARMV8A_GENERIC     (0xA00FF000)

/* processor capabilities */
#define NV0000_CTRL_SYSTEM_CPU_CAP_MMX                 (0x00000001)
#define NV0000_CTRL_SYSTEM_CPU_CAP_SSE                 (0x00000002)
#define NV0000_CTRL_SYSTEM_CPU_CAP_3DNOW               (0x00000004)
#define NV0000_CTRL_SYSTEM_CPU_CAP_SSE2                (0x00000008)
#define NV0000_CTRL_SYSTEM_CPU_CAP_SFENCE              (0x00000010)
#define NV0000_CTRL_SYSTEM_CPU_CAP_WRITE_COMBINING     (0x00000020)
#define NV0000_CTRL_SYSTEM_CPU_CAP_ALTIVEC             (0x00000040)
#define NV0000_CTRL_SYSTEM_CPU_CAP_PUT_NEEDS_IO        (0x00000080)
#define NV0000_CTRL_SYSTEM_CPU_CAP_NEEDS_WC_WORKAROUND (0x00000100)
#define NV0000_CTRL_SYSTEM_CPU_CAP_3DNOW_EXT           (0x00000200)
#define NV0000_CTRL_SYSTEM_CPU_CAP_MMX_EXT             (0x00000400)
#define NV0000_CTRL_SYSTEM_CPU_CAP_CMOV                (0x00000800)
#define NV0000_CTRL_SYSTEM_CPU_CAP_CLFLUSH             (0x00001000)
#define NV0000_CTRL_SYSTEM_CPU_CAP_NEEDS_WAR_190854    (0x00002000) /* deprecated */
#define NV0000_CTRL_SYSTEM_CPU_CAP_SSE3                (0x00004000)
#define NV0000_CTRL_SYSTEM_CPU_CAP_NEEDS_WAR_124888    (0x00008000)
#define NV0000_CTRL_SYSTEM_CPU_CAP_HT_CAPABLE          (0x00010000)
#define NV0000_CTRL_SYSTEM_CPU_CAP_SSE41               (0x00020000)
#define NV0000_CTRL_SYSTEM_CPU_CAP_SSE42               (0x00040000)
#define NV0000_CTRL_SYSTEM_CPU_CAP_AVX                 (0x00080000)
#define NV0000_CTRL_SYSTEM_CPU_CAP_ERMS                (0x00100000)

/* feature mask (as opposed to bugs, requirements, etc.) */
#define NV0000_CTRL_SYSTEM_CPU_CAP_FEATURE_MASK        (0x1f5e7f) /* finn: Evaluated from "(NV0000_CTRL_SYSTEM_CPU_CAP_MMX | NV0000_CTRL_SYSTEM_CPU_CAP_SSE | NV0000_CTRL_SYSTEM_CPU_CAP_3DNOW | NV0000_CTRL_SYSTEM_CPU_CAP_SSE2 | NV0000_CTRL_SYSTEM_CPU_CAP_SFENCE | NV0000_CTRL_SYSTEM_CPU_CAP_WRITE_COMBINING | NV0000_CTRL_SYSTEM_CPU_CAP_ALTIVEC | NV0000_CTRL_SYSTEM_CPU_CAP_3DNOW_EXT | NV0000_CTRL_SYSTEM_CPU_CAP_MMX_EXT | NV0000_CTRL_SYSTEM_CPU_CAP_CMOV | NV0000_CTRL_SYSTEM_CPU_CAP_CLFLUSH | NV0000_CTRL_SYSTEM_CPU_CAP_SSE3 | NV0000_CTRL_SYSTEM_CPU_CAP_HT_CAPABLE | NV0000_CTRL_SYSTEM_CPU_CAP_SSE41 | NV0000_CTRL_SYSTEM_CPU_CAP_SSE42 | NV0000_CTRL_SYSTEM_CPU_CAP_AVX | NV0000_CTRL_SYSTEM_CPU_CAP_ERMS)" */

/*
 * NV0000_CTRL_CMD_SYSTEM_GET_CAPS
 *
 * This command returns the set of system capabilities in the
 * form of an array of unsigned bytes.  System capabilities include
 * supported features and required workarounds for the system,
 * each represented by a byte offset into the table and a bit
 * position within that byte.
 *
 *   capsTblSize
 *     This parameter specifies the size in bytes of the caps table.
 *     This value should be set to NV0000_CTRL_SYSTEM_CAPS_TBL_SIZE.
 *   capsTbl
 *     This parameter specifies a pointer to the client's caps table buffer
 *     into which the system caps bits will be transferred by the RM.
 *     The caps table is an array of unsigned bytes.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 */
#define NV0000_CTRL_CMD_SYSTEM_GET_CAPS                (0x103) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | 0x3" */

typedef struct NV0000_CTRL_SYSTEM_GET_CAPS_PARAMS {
    NvU32 capsTblSize;
    NV_DECLARE_ALIGNED(NvP64 capsTbl, 8);
} NV0000_CTRL_SYSTEM_GET_CAPS_PARAMS;

/* extract cap bit setting from tbl */
#define NV0000_CTRL_SYSTEM_GET_CAP(tbl,c)           (((NvU8)tbl[(1?c)]) & (0?c))

/* caps format is byte_index:bit_mask */
#define NV0000_CTRL_SYSTEM_CAPS_POWER_SLI_SUPPORTED                 0:0x01

/* size in bytes of system caps table */
#define NV0000_CTRL_SYSTEM_CAPS_TBL_SIZE        1



/*
 * NV0000_CTRL_CMD_SYSTEM_SET_MEMORY_SIZE
 *
 * This command is used to set the system memory size in pages.
 *
 *   memorySize
 *     This parameter specifies the system memory size in pages.  All values
 *     are considered legal.
 *
 * 
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 */
#define NV0000_CTRL_CMD_SYSTEM_SET_MEMORY_SIZE                                         (0x107) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_SET_MEMORY_SIZE_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SYSTEM_SET_MEMORY_SIZE_PARAMS_MESSAGE_ID (0x7U)

typedef struct NV0000_CTRL_SYSTEM_SET_MEMORY_SIZE_PARAMS {
    NvU32 memorySize;
} NV0000_CTRL_SYSTEM_SET_MEMORY_SIZE_PARAMS;

/*
 * NV0000_CTRL_CMD_SYSTEM_GET_CLASSLIST
 *
 * This command is used to retrieve the set of system-level classes
 * supported by the platform.
 *
 *   numClasses
 *     This parameter returns the number of valid entries in the returned
 *     classes[] list.  This parameter will not exceed
 *     Nv0000_CTRL_SYSTEM_MAX_CLASSLIST_SIZE.
 *   classes
 *     This parameter returns the list of supported classes
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 */

#define NV0000_CTRL_CMD_SYSTEM_GET_CLASSLIST  (0x108) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_GET_CLASSLIST_PARAMS_MESSAGE_ID" */

/* maximum number of classes returned in classes[] array */
#define NV0000_CTRL_SYSTEM_MAX_CLASSLIST_SIZE (16)

#define NV0000_CTRL_SYSTEM_GET_CLASSLIST_PARAMS_MESSAGE_ID (0x8U)

typedef struct NV0000_CTRL_SYSTEM_GET_CLASSLIST_PARAMS {
    NvU32 numClasses;
    NvU32 classes[NV0000_CTRL_SYSTEM_MAX_CLASSLIST_SIZE];
} NV0000_CTRL_SYSTEM_GET_CLASSLIST_PARAMS;

/*
 * NV0000_CTRL_CMD_SYSTEM_NOTIFY_EVENT
 *
 * This command is used to send triggered mobile related system events
 * to the RM.
 *
 *   eventType
 *     This parameter indicates the triggered event type.  This parameter
 *     should specify a valid NV0000_CTRL_SYSTEM_EVENT_TYPE value.
 *   eventData
 *     This parameter specifies the type-dependent event data associated
 *     with EventType.  This parameter should specify a valid
 *     NV0000_CTRL_SYSTEM_EVENT_DATA value.
 *   bEventDataForced
 *     This parameter specifies what we have to do, Whether trust current
 *     Lid/Dock state or not. This parameter should specify a valid
 *     NV0000_CTRL_SYSTEM_EVENT_DATA_FORCED value.

 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 *
 * Sync this up (#defines) with one in nvapi.spec!
 * (NV_ACPI_EVENT_TYPE & NV_ACPI_EVENT_DATA)
 */
#define NV0000_CTRL_CMD_SYSTEM_NOTIFY_EVENT (0x110) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_NOTIFY_EVENT_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SYSTEM_NOTIFY_EVENT_PARAMS_MESSAGE_ID (0x10U)

typedef struct NV0000_CTRL_SYSTEM_NOTIFY_EVENT_PARAMS {
    NvU32  eventType;
    NvU32  eventData;
    NvBool bEventDataForced;
} NV0000_CTRL_SYSTEM_NOTIFY_EVENT_PARAMS;

/* valid eventType values */
#define NV0000_CTRL_SYSTEM_EVENT_TYPE_LID_STATE        (0x00000000)
#define NV0000_CTRL_SYSTEM_EVENT_TYPE_POWER_SOURCE     (0x00000001)
#define NV0000_CTRL_SYSTEM_EVENT_TYPE_DOCK_STATE       (0x00000002)
#define NV0000_CTRL_SYSTEM_EVENT_TYPE_TRUST_LID        (0x00000003)
#define NV0000_CTRL_SYSTEM_EVENT_TYPE_TRUST_DOCK       (0x00000004)

/* valid eventData values */
#define NV0000_CTRL_SYSTEM_EVENT_DATA_LID_OPEN         (0x00000000)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_LID_CLOSED       (0x00000001)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_POWER_BATTERY    (0x00000000)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_POWER_AC         (0x00000001)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_UNDOCKED         (0x00000000)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_DOCKED           (0x00000001)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_LID_DSM    (0x00000000)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_LID_DCS    (0x00000001)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_LID_NVIF   (0x00000002)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_LID_ACPI   (0x00000003)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_LID_POLL   (0x00000004)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_LID_COUNT  (0x5) /* finn: Evaluated from "(NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_LID_POLL + 1)" */
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_DOCK_DSM   (0x00000000)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_DOCK_DCS   (0x00000001)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_DOCK_NVIF  (0x00000002)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_DOCK_ACPI  (0x00000003)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_DOCK_POLL  (0x00000004)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_DOCK_COUNT (0x5) /* finn: Evaluated from "(NV0000_CTRL_SYSTEM_EVENT_DATA_TRUST_DOCK_POLL + 1)" */

/* valid bEventDataForced values */
#define NV0000_CTRL_SYSTEM_EVENT_DATA_FORCED_FALSE     (0x00000000)
#define NV0000_CTRL_SYSTEM_EVENT_DATA_FORCED_TRUE      (0x00000001)



/*
 * NV0000_CTRL_CMD_SYSTEM_DEBUG_RMMSG_CTRL
 *
 * This command controls the current RmMsg filters. 
 *
 * It is only supported if RmMsg is enabled (e.g. debug builds).
 *
 *   cmd
 *     GET - Gets the current RmMsg filter string.
 *     SET - Sets the current RmMsg filter string.
 *
 *   count
 *     The length of the RmMsg filter string.
 *
 *   data
 *     The RmMsg filter string.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_NOT_SUPPORTED
 */
#define NV0000_CTRL_CMD_SYSTEM_DEBUG_RMMSG_CTRL     (0x121) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_DEBUG_RMMSG_CTRL_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SYSTEM_DEBUG_RMMSG_SIZE         512

#define NV0000_CTRL_SYSTEM_DEBUG_RMMSG_CTRL_CMD_GET (0x00000000)
#define NV0000_CTRL_SYSTEM_DEBUG_RMMSG_CTRL_CMD_SET (0x00000001)

#define NV0000_CTRL_SYSTEM_DEBUG_RMMSG_CTRL_PARAMS_MESSAGE_ID (0x21U)

typedef struct NV0000_CTRL_SYSTEM_DEBUG_RMMSG_CTRL_PARAMS {
    NvU32 cmd;
    NvU32 count;
    NvU8  data[NV0000_CTRL_SYSTEM_DEBUG_RMMSG_SIZE];
} NV0000_CTRL_SYSTEM_DEBUG_RMMSG_CTRL_PARAMS;



#define NV0000_CTRL_CMD_SYSTEM_GET_PRIVILEGED_STATUS               (0x135) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_PARAMS_MESSAGE_ID (0x35U)

typedef struct NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_PARAMS {
    NvU8 privStatusFlags;
} NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_PARAMS;


/* Valid privStatus values */
#define NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_PRIV_USER_FLAG     (0x00000001)
#define NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_KERNEL_HANDLE_FLAG (0x00000002)
#define NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_PRIV_HANDLE_FLAG   (0x00000004)

/*
 * NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS
 *
 * The fabric manager (FM) notifies RM that fabric (system) is ready for peer to
 * peer (P2P) use or still initializing the fabric. This command allows clients
 * to query fabric status to allow P2P operations.
 *
 * Note, on systems where FM isn't used, RM just returns _SKIP.
 *
 * fabricStatus
 *     This parameter returns current fabric status:
 *          NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS_SKIP
 *          NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS_UNINITIALIZED
 *          NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS_IN_PROGRESS
 *          NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS_INITIALIZED
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_INVALID_OBJECT_HANDLE
 *   NV_ERR_NOT_SUPPORTED
 *   NV_ERR_INSUFFICIENT_PERMISSIONS
 *   NV_ERR_INVALID_PARAM_STRUCT
 */

typedef enum NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS {
    NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS_SKIP = 1,
    NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS_UNINITIALIZED = 2,
    NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS_IN_PROGRESS = 3,
    NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS_INITIALIZED = 4,
} NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS;

#define NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS (0x136) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_GET_FABRIC_STATUS_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SYSTEM_GET_FABRIC_STATUS_PARAMS_MESSAGE_ID (0x36U)

typedef struct NV0000_CTRL_SYSTEM_GET_FABRIC_STATUS_PARAMS {
    NV0000_CTRL_GET_SYSTEM_FABRIC_STATUS fabricStatus;
} NV0000_CTRL_SYSTEM_GET_FABRIC_STATUS_PARAMS;



/*
 * NV0000_CTRL_SYSTEM_GET_RM_INSTANCE_ID
 *
 * This command is used to get a unique identifier for the instance of RM.
 * The returned value will only change when the driver is reloaded. A previous
 * value will never be reused on a given machine.
 *
 *  rm_instance_id;
 *      The instance ID of the current RM instance
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV0000_CTRL_CMD_SYSTEM_GET_RM_INSTANCE_ID (0x139) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_GET_RM_INSTANCE_ID_PARAMS_MESSAGE_ID" */

/*
 * NV0000_CTRL_SYSTEM_GET_RM_INSTANCE_ID_PARAMS
 */
#define NV0000_CTRL_SYSTEM_GET_RM_INSTANCE_ID_PARAMS_MESSAGE_ID (0x39U)

typedef struct NV0000_CTRL_SYSTEM_GET_RM_INSTANCE_ID_PARAMS {
    NV_DECLARE_ALIGNED(NvU64 rm_instance_id, 8);
} NV0000_CTRL_SYSTEM_GET_RM_INSTANCE_ID_PARAMS;



/* Valid NVPCF subfunction case */
#define NVPCF0100_CTRL_CONFIG_DSM_1X_FUNC_GET_SUPPORTED_CASE 0
#define NVPCF0100_CTRL_CONFIG_DSM_1X_FUNC_GET_DYNAMIC_CASE   1
#define NVPCF0100_CTRL_CONFIG_DSM_2X_FUNC_GET_SUPPORTED_CASE 2
#define NVPCF0100_CTRL_CONFIG_DSM_2X_FUNC_GET_DYNAMIC_CASE   3

/* Valid NVPCF subfunction ids */
#define NVPCF0100_CTRL_CONFIG_DSM_1X_FUNC_GET_SUPPORTED      (0x00000000)
#define NVPCF0100_CTRL_CONFIG_DSM_1X_FUNC_GET_DYNAMIC_PARAMS (0x00000002)

/*
 *  Defines for get supported sub functions bit fields
 */
#define NVPCF0100_CTRL_CONFIG_DSM_FUNC_GET_SUPPORTED_IS_SUPPORTED        0:0
#define NVPCF0100_CTRL_CONFIG_DSM_FUNC_GET_SUPPORTED_IS_SUPPORTED_YES    1
#define NVPCF0100_CTRL_CONFIG_DSM_FUNC_GET_SUPPORTED_IS_SUPPORTED_NO     0

/*!
 * Config DSM 2x version specific defines
 */
#define NVPCF0100_CTRL_CONFIG_DSM_2X_VERSION                 (0x00000200)
#define NVPCF0100_CTRL_CONFIG_DSM_2X_FUNC_GET_SUPPORTED      (0x00000000)
#define NVPCF0100_CTRL_CONFIG_DSM_2X_FUNC_GET_DYNAMIC_PARAMS (0x00000002)


/*
 * NV0000_CTRL_CMD_SYSTEM_SYNC_EXTERNAL_FABRIC_MGMT
 *
 * This API is used to sync the external fabric management status with
 * GSP-RM
 *
 *  bExternalFabricMgmt
 *      Whether fabric is externally managed
 *
 * Possible status values returned are:
 *   NV_OK
 */
#define NV0000_CTRL_CMD_SYSTEM_SYNC_EXTERNAL_FABRIC_MGMT     (0x13c) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_CMD_SYSTEM_SYNC_EXTERNAL_FABRIC_MGMT_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_CMD_SYSTEM_SYNC_EXTERNAL_FABRIC_MGMT_PARAMS_MESSAGE_ID (0x3CU)

typedef struct NV0000_CTRL_CMD_SYSTEM_SYNC_EXTERNAL_FABRIC_MGMT_PARAMS {
    NvBool bExternalFabricMgmt;
} NV0000_CTRL_CMD_SYSTEM_SYNC_EXTERNAL_FABRIC_MGMT_PARAMS;

/*
 * NV0000_CTRL_SYSTEM_GET_CLIENT_DATABASE_INFO
 *
 * This API is used to get information about the RM client
 * database.
 *
 * clientCount [OUT]
 *  This field indicates the number of clients currently allocated.
 *
 * resourceCount [OUT]
 *  This field indicates the number of resources currently allocated
 *  across all clients.
 *
 */
#define NV0000_CTRL_CMD_SYSTEM_GET_CLIENT_DATABASE_INFO (0x13d) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_GET_CLIENT_DATABASE_INFO_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SYSTEM_GET_CLIENT_DATABASE_INFO_PARAMS_MESSAGE_ID (0x3DU)

typedef struct NV0000_CTRL_SYSTEM_GET_CLIENT_DATABASE_INFO_PARAMS {
    NvU32 clientCount;
    NV_DECLARE_ALIGNED(NvU64 resourceCount, 8);
} NV0000_CTRL_SYSTEM_GET_CLIENT_DATABASE_INFO_PARAMS;

/*
 * NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION_V2
 *
 * This command returns the current driver information in
 * statically sized character arrays.
 *
 *   driverVersionBuffer
 *       This field returns the version (NV_VERSION_STRING).
 *   versionBuffer
 *       This field returns the version (NV_BUILD_BRANCH_VERSION).
 *   titleBuffer
 *       This field returns the title (NV_DISPLAY_DRIVER_TITLE).
 *   changelistNumber
 *       This field returns the changelist value (NV_BUILD_CHANGELIST_NUM).
 *   officialChangelistNumber
 *       This field returns the last official changelist value
 *       (NV_LAST_OFFICIAL_CHANGELIST_NUM).
 *
 * Possible status values returned are:
 *   NV_OK
 */

#define NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_MAX_STRING_SIZE 256
#define NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION_V2             (0x13e) /* finn: Evaluated from "(FINN_NV01_ROOT_SYSTEM_INTERFACE_ID << 8) | NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_PARAMS_MESSAGE_ID" */

#define NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_PARAMS_MESSAGE_ID (0x3EU)

typedef struct NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_PARAMS {
    char  driverVersionBuffer[NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_MAX_STRING_SIZE];
    char  versionBuffer[NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_MAX_STRING_SIZE];
    char  titleBuffer[NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_MAX_STRING_SIZE];
    NvU32 changelistNumber;
    NvU32 officialChangelistNumber;
} NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_PARAMS;

/* _ctrl0000system_h_ */
