/*
 * SPDX-FileCopyrightText: Copyright (c) 2017-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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
// Source file: ctrl/ctrl2080/ctrl2080ecc.finn
//




#include "ctrl/ctrl2080/ctrl2080base.h"

/*
 * NV2080_CTRL_CMD_ECC_GET_AGGREGATE_ERROR_COUNTS
 *
 * eccCounts [out]
 *      Reports the error counters for all the units.
 */

#define NV2080_CTRL_CMD_ECC_GET_AGGREGATE_ERROR_COUNTS (0x20803401) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_ECC_INTERFACE_ID << 8) | NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_COUNTS_PARAMS_MESSAGE_ID" */

typedef enum NV2080_ECC_UNITS {
    ECC_UNIT_LRF = 0,
    ECC_UNIT_CBU = 1,
    ECC_UNIT_L1 = 2,
    ECC_UNIT_L1DATA = 3,
    ECC_UNIT_L1TAG = 4,
    ECC_UNIT_SHM = 5,
    ECC_UNIT_TEX = 6,
    ECC_UNIT_SM_ICACHE = 7,
    ECC_UNIT_LTC = 8,
    ECC_UNIT_DRAM = 9,
    ECC_UNIT_GCC_L15 = 10,
    ECC_UNIT_GPCMMU = 11,
    ECC_UNIT_HUBMMU_L2TLB = 12,
    ECC_UNIT_HUBMMU_HUBTLB = 13,
    ECC_UNIT_HUBMMU_FILLUNIT = 14,
    ECC_UNIT_GPCCS = 15,
    ECC_UNIT_FECS = 16,
    ECC_UNIT_PMU = 17,
    ECC_UNIT_SM_RAMS = 18,
    ECC_UNIT_HSHUB = 19,
    ECC_UNIT_PCIE_REORDER = 20,
    ECC_UNIT_PCIE_P2PREQ = 21,
    ECC_UNIT_MAX = 22,
    ECC_UNIT_GR = 23, // ECC_UNIT_GR isn't an actual unit (see comment below)
} NV2080_ECC_UNITS;
/*
 * Because most GR units use the grEccLocation struct, it's helpful to expose
 * this struct directly so clients have a generic way to refer to any unit
 * location that uses grEccLocation.
 */

typedef struct NV2080_ECC_COUNTS {
    //
    // Indicates whether this entry is valid. This is required as ECC support
    // for units can change between architectures.
    // Deprecated in favor of the flags field.
    //
    NvU8 flags;

    NV_DECLARE_ALIGNED(NvU64 correctedTotalCounts, 8);
    NV_DECLARE_ALIGNED(NvU64 correctedUniqueCounts, 8);
    NV_DECLARE_ALIGNED(NvU64 uncorrectedTotalCounts, 8);
    NV_DECLARE_ALIGNED(NvU64 uncorrectedUniqueCounts, 8);
} NV2080_ECC_COUNTS;

// Legal flag values
#define NV2080_ECC_COUNTS_FLAGS_VALID               0:0
#define NV2080_ECC_COUNTS_FLAGS_VALID_TRUE         1
#define NV2080_ECC_COUNTS_FLAGS_VALID_FALSE        0

#define NV2080_ECC_COUNTS_FLAGS_UNIQUE_VALID        1:1
#define NV2080_ECC_COUNTS_FLAGS_UNIQUE_VALID_TRUE  1
#define NV2080_ECC_COUNTS_FLAGS_UNIQUE_VALID_FALSE 0

#define NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_COUNTS_PARAMS_MESSAGE_ID (0x1U)

typedef struct NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_COUNTS_PARAMS {
    NV_DECLARE_ALIGNED(NV2080_ECC_COUNTS eccCounts[ECC_UNIT_MAX], 8);
} NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_COUNTS_PARAMS;

/*
 * NV2080_CTRL_CMD_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS
 *
 * unit [in]:
 *      The ECC protected unit for which the counts are being requested.
 *
 * location [in]:
 *      The detailed location information for which the counters are requested.
 *      The unit field will determine if the locations are gpc-tpc or
 *      partition-subpartition.
 *
 * eccCounts [out]:
 *      The counters for the errors seen in the requested location.
 *
 * Return values:
 *      NV_OK on success
 *      NV_ERR_INVALID_ARGUMENT if the requested unit or the location is invalid.
 *      NV_ERR_NOT_SUPPORTED otherwise
 */

#define NV2080_CTRL_CMD_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS (0x20803402) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_ECC_INTERFACE_ID << 8) | NV2080_CTRL_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS_PARAMS_MESSAGE_ID" */

typedef struct grEccLocation {
    NvU32 location;
    NvU32 sublocation;
} grEccLocation;

typedef struct ltcEccLocation {
    NvU32 partition;
    NvU32 slice;
} ltcEccLocation;

typedef struct dramEccLocation {
    NvU32 partition;
    NvU32 sublocation;
} dramEccLocation;

typedef struct texEccLocation {
    grEccLocation grLocation;
    NvU32         texId;
} texEccLocation;

typedef struct falconEccLocation {
    //
    // Currently this is unused and RM does not check the contents
    // Added for future proofing and makes integration with eccInjection SRTs easier
    //
    NvU8 falconLocation;
} falconEccLocation;

typedef struct busEccLocation {
    //
    // Currently this is unused and RM does not check the contents
    // Added for future proofing and makes integration with eccInjection SRTs easier
    //
    NvU8 busLocation;
} busEccLocation;

typedef union NV2080_ECC_LOCATION_INFO {
    grEccLocation     lrf;

    grEccLocation     cbu;

    grEccLocation     l1;

    grEccLocation     l1Data;

    grEccLocation     l1Tag;

    grEccLocation     shm;

    texEccLocation    tex;

    grEccLocation     smIcache;

    ltcEccLocation    ltc;

    dramEccLocation   dram;

    grEccLocation     gr;

    grEccLocation     gccl15;

    grEccLocation     gpcmmu;

    grEccLocation     l2tlb;

    grEccLocation     hubtlb;

    grEccLocation     fillunit;

    grEccLocation     gpccs;

    grEccLocation     fecs;

    falconEccLocation pmu;

    grEccLocation     smRams;

    grEccLocation     hshub;

    busEccLocation    pcie_reorder;

    busEccLocation    pcie_p2preq;
} NV2080_ECC_LOCATION_INFO;


#define NV2080_CTRL_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS_PARAMS_MESSAGE_ID (0x2U)

typedef struct NV2080_CTRL_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS_PARAMS {
    NV2080_ECC_UNITS         unit;
    NV2080_ECC_LOCATION_INFO location;
    NV_DECLARE_ALIGNED(NV2080_ECC_COUNTS eccCounts, 8);
} NV2080_CTRL_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS_PARAMS;

/*
 * NV2080_CTRL_CMD_ECC_GET_DETAILED_ERROR_COUNTS
 *
 * Similar to NV2080_CTRL_CMD_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS except used
 * for getting ECC counters in the current driver run.
 *
 * Refer to NV2080_CTRL_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS_PARAMS
 * details for usage.
 */

#define NV2080_CTRL_CMD_ECC_GET_DETAILED_ERROR_COUNTS (0x20803403) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_ECC_INTERFACE_ID << 8) | 0x3" */

typedef NV2080_CTRL_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS_PARAMS NV2080_CTRL_ECC_GET_DETAILED_ERROR_COUNTS_PARAMS;

// FINN PORT: The below type was generated by the FINN port to
// ensure that all API's have a unique structure associated
// with them!
#define NV2080_CTRL_CMD_ECC_GET_DETAILED_ERROR_COUNTS_FINN_PARAMS_MESSAGE_ID (0x3U)

typedef struct NV2080_CTRL_CMD_ECC_GET_DETAILED_ERROR_COUNTS_FINN_PARAMS {
    NV_DECLARE_ALIGNED(NV2080_CTRL_ECC_GET_DETAILED_ERROR_COUNTS_PARAMS params, 8);
} NV2080_CTRL_CMD_ECC_GET_DETAILED_ERROR_COUNTS_FINN_PARAMS;



/*
 * NV2080_CTRL_CMD_ECC_GET_AGGREGATE_DRAM_ERROR_ADDRESSES
 *
 * Reports the ECC DRAM addresses stored on the InfoROM.
 *
 * flags [out]:
 *
 * addressCount [out]:
 *      Number of valid entries in the NV2080_ECC_AGGREGATE_DRAM_ADDRESS array.
 *
 * NV2080_ECC_AGGREGATE_DRAM_ADDRESS [out]:
 *      Contains the address information for the ECC errors that have occurred
 *      over the life of the board.
 *
 * Possible status values returned are:
 *      NV_OK
 *      NV_ERR_INVALID_POINTER
 *      NV_ERR_INVALID_STATE
 *      NV_ERR_NOT_SUPPORTED
 */

#define NV2080_CTRL_CMD_ECC_GET_AGGREGATE_DRAM_ERROR_ADDRESSES                  (0x20803404) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_ECC_INTERFACE_ID << 8) | NV2080_CTRL_ECC_GET_AGGREGATE_DRAM_ERROR_ADDRESSES_PARAMS_MESSAGE_ID" */

#define NV2080_ECC_AGGREGATE_DRAM_ADDRESS_MAX_COUNT                             600

#define NV2080_CTRL_ECC_GET_AGGREGATE_DRAM_ERROR_ADDRESSES_FLAGS_OVERFLOW        0:0
#define NV2080_CTRL_ECC_GET_AGGREGATE_DRAM_ERROR_ADDRESSES_FLAGS_OVERFLOW_FLASE 0
#define NV2080_CTRL_ECC_GET_AGGREGATE_DRAM_ERROR_ADDRESSES_FLAGS_OVERFLOW_TRUE  1

#define NV2080_ECC_AGGREGATE_DRAM_ADDRESS_ERROR_TYPE_SBE        0:0
#define NV2080_ECC_AGGREGATE_DRAM_ADDRESS_ERROR_TYPE_SBE_FALSE                  0
#define NV2080_ECC_AGGREGATE_DRAM_ADDRESS_ERROR_TYPE_SBE_TRUE                   1

#define NV2080_ECC_AGGREGATE_DRAM_ADDRESS_ERROR_TYPE_DBE        1:1
#define NV2080_ECC_AGGREGATE_DRAM_ADDRESS_ERROR_TYPE_DBE_FALSE                  0
#define NV2080_ECC_AGGREGATE_DRAM_ADDRESS_ERROR_TYPE_DBE_TRUE                   1

typedef struct ECC_DRAM_ADDRESS_RBC {
    NvU32 row;
    NvU32 bank;
    NvU32 column;
    NvU32 extBank;
} ECC_DRAM_ADDRESS_RBC;

typedef struct NV2080_ECC_AGGREGATE_DRAM_ADDRESS {
    NvU8                 errorType;
    dramEccLocation      location;
    ECC_DRAM_ADDRESS_RBC rbc;
} NV2080_ECC_AGGREGATE_DRAM_ADDRESS;

#define NV2080_CTRL_ECC_GET_AGGREGATE_DRAM_ERROR_ADDRESSES_PARAMS_MESSAGE_ID (0x4U)

typedef struct NV2080_CTRL_ECC_GET_AGGREGATE_DRAM_ERROR_ADDRESSES_PARAMS {
    NvU32                             flags;
    NvU32                             addressCount;
    NV2080_ECC_AGGREGATE_DRAM_ADDRESS address[NV2080_ECC_AGGREGATE_DRAM_ADDRESS_MAX_COUNT];
} NV2080_CTRL_ECC_GET_AGGREGATE_DRAM_ERROR_ADDRESSES_PARAMS;

/*
 * NV2080_CTRL_CMD_ECC_GET_SRAM_ERROR_BUFFER
 *
 * Reports the SRAM round robin buffer stored on the InfoROM.
 *
 * NV2080_CTRL_ECC_SRAM_ERROR_BUFFER_ENTRY [out]:
 *      Contains the SRAM error buffer stored on the InfoROM.
 *
 * Possible status values returned are:
 *      NV_OK
 *      NV_ERR_INVALID_STATE
 *      NV_ERR_NOT_SUPPORTED
 */

#define NV2080_CTRL_CMD_ECC_GET_SRAM_ERROR_BUFFER                        (0x20803405) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_ECC_INTERFACE_ID << 8) | NV2080_CTRL_ECC_GET_SRAM_ERROR_BUFFER_PARAMS_MESSAGE_ID" */

#define NV2080_ECC_SRAM_ERROR_MAX_COUNT                                  16

#define NV2080_CTRL_ECC_SRAM_ERROR_BUFFER_ENTRY_ERROR_TYPE_UNCORRECTABLE 0x0
#define NV2080_CTRL_ECC_SRAM_ERROR_BUFFER_ENTRY_ERROR_TYPE_CORRECTABLE   0x1

typedef struct NV2080_CTRL_ECC_SRAM_ERROR_BUFFER_ENTRY {
    NV2080_ECC_UNITS         unit;
    NV2080_ECC_LOCATION_INFO location;

    NvU8                     errorType;
    NvU32                    timestamp;
    NvU32                    address;
} NV2080_CTRL_ECC_SRAM_ERROR_BUFFER_ENTRY;

#define NV2080_CTRL_ECC_GET_SRAM_ERROR_BUFFER_PARAMS_MESSAGE_ID (0x5U)

typedef struct NV2080_CTRL_ECC_GET_SRAM_ERROR_BUFFER_PARAMS {
    NvU32                                   entryCount;
    NV2080_CTRL_ECC_SRAM_ERROR_BUFFER_ENTRY sramError[NV2080_ECC_SRAM_ERROR_MAX_COUNT];
} NV2080_CTRL_ECC_GET_SRAM_ERROR_BUFFER_PARAMS;

/*
 * NV2080_CTRL_CMD_ECC_GET_AGGREGATE_ERROR_ADDRESSES
 *
 * Reports the ECC addresses stored on the InfoROM.
 *
 * addressCount [out]:
 *      Number of valid entries in the NV2080_ECC_AGGREGATE_ADDRESS array.
 *
 * NV2080_ECC_AGGREGATE_ADDRESS [out]:
 *      Contains the address information for the ECC errors that have occurred
 *      over the life of the board.
 *
 * Possible status values returned are:
 *      NV_OK
 *      NV_ERR_INVALID_POINTER
 *      NV_ERR_INVALID_STATE
 *      NV_ERR_NOT_SUPPORTED
 */

#define NV2080_CTRL_CMD_ECC_GET_AGGREGATE_ERROR_ADDRESSES                  (0x20803406) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_ECC_INTERFACE_ID << 8) | NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_ADDRESSES_PARAMS_MESSAGE_ID" */

#define NV2080_ECC_AGGREGATE_ADDRESS_MAX_COUNT                             600

#define NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_ADDRESSES_FLAGS_OVERFLOW        0:0
#define NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_ADDRESSES_FLAGS_OVERFLOW_FLASE 0
#define NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_ADDRESSES_FLAGS_OVERFLOW_TRUE  1

#define NV2080_ECC_AGGREGATE_ADDRESS_ERROR_TYPE_CORR                    0:0
#define NV2080_ECC_AGGREGATE_ADDRESS_ERROR_TYPE_CORR_FALSE                 0
#define NV2080_ECC_AGGREGATE_ADDRESS_ERROR_TYPE_CORR_TRUE                  1

#define NV2080_ECC_AGGREGATE_ADDRESS_ERROR_TYPE_UNCORR                  1:1
#define NV2080_ECC_AGGREGATE_ADDRESS_ERROR_TYPE_UNCORR_FALSE               0
#define NV2080_ECC_AGGREGATE_ADDRESS_ERROR_TYPE_UNCORR_TRUE                1



typedef struct NV2080_ECC_AGGREGATE_ADDRESS {
    NvU8                     errorType;
    NV2080_ECC_UNITS         unit;
    NV2080_ECC_LOCATION_INFO location;
    union {
        NvU32                rawAddress;

        ECC_DRAM_ADDRESS_RBC rbc;
    } address;
} NV2080_ECC_AGGREGATE_ADDRESS;

#define NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_ADDRESSES_PARAMS_MESSAGE_ID (0x6U)

typedef struct NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_ADDRESSES_PARAMS {
    NvU8                         flags;
    NvU32                        addressCount;
    NV2080_ECC_AGGREGATE_ADDRESS entry[NV2080_ECC_AGGREGATE_ADDRESS_MAX_COUNT];
} NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_ADDRESSES_PARAMS;

/*
 * NV2080_CTRL_CMD_ECC_GET_LATEST_ECC_ADDRESSES
 *
 * This command is used to query FB addresses of the latest ECC memory events
 * since last driver restart.
 *
 *   addressCount
 *     This parameter is the number of valid addresses in the list
 *     returned by the physAddresses parameter.
 *
 *   totalAddressCount
 *     This parameter is the total number of addresses that has been
 *     added to the list since driver initialization. If the total
 *     number of addresses is greater than
 *     NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_MAX_COUNT,
 *     the earliest addresses are discarded from the list.
 *
 *   addresses
 *     This parameter stores the RBC (Row/Bank/Column) address. See
 *     documentation for NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ADDRESS.
 *
 *   Possible return status values are
 *     NV_OK
 *     NV_ERR_NOT_SUPPORTED
 *
 */

#define NV2080_CTRL_CMD_ECC_GET_LATEST_ECC_ADDRESSES               (0x20803407) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_ECC_INTERFACE_ID << 8) | NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_MAX_COUNT         (32)

#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ERROR_TYPE        0:0
#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ERROR_TYPE_SBE    (0x00000000)
#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ERROR_TYPE_DBE    (0x00000001)

#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ERROR_SRC         0:0
#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ERROR_SRC_DEFAULT (0x00000000)
#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ERROR_SRC_DATA    (0x00000000)
#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ERROR_SRC_CHECK   (0x00000001)

/*
 * NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ADDRESS
 *
 *   physAddress
 *     This parameter is the physical address of the error, as calculated
 *     by the reverse mapping of the Row/Bank/Column address identified by
 *     the GPU.
 *
 *   rbcAddress
 *     This parameter is the row, bank, column address as directly reported
 *     by the GPU.
 *
 *   rbcAddressExt
 *     This parameter is the extended row, bank, column address as directly
 *     reported by the GPU.
 *
 *   rbcAddressExt2
 *     This parameter is additional information about the address reported in
 *     rbcAddress and rbcAddressExt
 *
 *   partitionNumber
 *     This parameter is partition number in which the ECC error occurred.
 *
 *   subPartitionNumber
 *     This parameter is the subpartition number in which the ECC error
 *     occurred.
 *
 *   errorType
 *     This parameter is the type of ECC error that occurred, either single
 *     bit error (SBE) or double bit error (DBE).
 *
 *   sbeBitPosition
 *     This parameter is the corrected bit position for SBE
 *     Supported on VOLTA+, do not use otherwise
 *
 *   sbeErrorSrc
 *     NOTE: Not supported yet, do not use
 *     This parameter indicates whether the SBE is from the ECC check bits or
 *     the actual data.
 *     0 - ECC error from data
 *     1 - ECC error from check-bits
 */
typedef struct NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ADDRESS {
    NV_DECLARE_ALIGNED(NvU64 physAddress, 8);
    NvU32 rbcAddress;
    NvU32 rbcAddressExt;
    NvU32 rbcAddressExt2;
    NvU32 partitionNumber;
    NvU32 subPartitionNumber;
    NvU32 errorType;
    NvU32 sbeBitPosition;
    NvU32 sbeErrorSrc;
} NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ADDRESS;

#define NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_PARAMS_MESSAGE_ID (0x7U)

typedef struct NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_PARAMS {
    NvU32 addressCount;
    NvU32 totalAddressCount;
    NV_DECLARE_ALIGNED(NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_ADDRESS addresses[NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_MAX_COUNT], 8);
} NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_PARAMS;

#define NV2080_CTRL_CMD_ECC_GET_CLIENT_EXPOSED_COUNTERS (0x20803408) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_ECC_INTERFACE_ID << 8) | NV2080_CTRL_ECC_GET_CLIENT_EXPOSED_COUNTERS_PARAMS_MESSAGE_ID" */

/*
 * NV2080_CTRL_ECC_GET_CLIENT_EXPOSED_COUNTERS_PARAMS
 *
 * sramLastClearedTimestamp [out]
 * dramLastClearedTimestamp [out]
 *      unix-epoch based timestamp. These fields indicate when the error counters
 *      were last cleared by the user.
 *
 * sramErrorCounts [out]
 * dramErrorCounts [out]
 *      Aggregate error counts for SRAM and DRAM
 */

#define NV2080_CTRL_ECC_GET_CLIENT_EXPOSED_COUNTERS_PARAMS_MESSAGE_ID (0x8U)

typedef struct NV2080_CTRL_ECC_GET_CLIENT_EXPOSED_COUNTERS_PARAMS {
    NvU32 sramLastClearedTimestamp;
    NvU32 dramLastClearedTimestamp;

    NV_DECLARE_ALIGNED(NvU64 sramCorrectedTotalCounts, 8);
    NV_DECLARE_ALIGNED(NvU64 sramUncorrectedTotalCounts, 8);
    NV_DECLARE_ALIGNED(NvU64 dramCorrectedTotalCounts, 8);
    NV_DECLARE_ALIGNED(NvU64 dramUncorrectedTotalCounts, 8);
} NV2080_CTRL_ECC_GET_CLIENT_EXPOSED_COUNTERS_PARAMS;
/* _ctrl2080ecc_h_ */
