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
// Source file: ctrl/ctrl2080/ctrl2080bus.finn
//




#include "ctrl/ctrl2080/ctrl2080base.h"



/*
 * NV2080_CTRL_BUS_INFO
 *
 * This structure represents a single 32bit bus engine value.  Clients
 * request a particular bus engine value by specifying a unique bus
 * information index.
 *
 * Legal bus information index values are:
 *   NV2080_CTRL_BUS_INFO_INDEX_TYPE
 *     This index is used to request the bus type of the GPU.
 *     Legal return values for this index are:
 *       NV2080_CTRL_BUS_INFO_TYPE_PCI
 *       NV2080_CTRL_BUS_INFO_TYPE_PCI_EXPRESS
 *       NV2080_CTRL_BUS_INFO_TYPE_FPCI
 *   NV2080_CTRL_BUS_INFO_INDEX_INTLINE
 *     This index is used to request the interrupt line (or irq) assignment
 *     for the GPU.  The return value is system-dependent.
 *   NV2080_CTRL_BUS_INFO_INDEX_CAPS
 *     This index is used to request the bus engine capabilities for the GPU.
 *     The return value is specified as a mask of capabilities.
 *     Legal return values for this index are:
 *       NV2080_CTRL_BUS_INFO_CAPS_NEED_IO_FLUSH
 *       NV2080_CTRL_BUS_INFO_CAPS_CHIP_INTEGRATED
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CAPS
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_ROOT_LINK_CAPS
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_DOWNSTREAM_LINK_CAPS
 *     These indices are used to request PCI Express link-specific
 *     capabilities values.  A value of zero is returned for non-PCIE GPUs.
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CTRL_STATUS
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_ROOT_LINK_CTRL_STATUS
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_DOWNSTREAM_LINK_CTRL_STATUS
 *     These indices are used to request PCI Express link-specific
 *     control status values.  A value of zero is returned for non-PCIE GPUs.
 *   NV2080_CTRL_BUS_INFO_INDEX_COHERENT_DMA_FLAGS
 *     This index is used to request coherent dma transfer flags.
 *     Valid coherent dma transfer flags include:
 *       NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_CTXDMA
 *       NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_GPUGART
 *   NV2080_CTRL_BUS_INFO_INDEX_NONCOHERENT_DMA_FLAGS
 *     This index is used to request noncoherent dma transfer flags.
 *     Valid noncoherent dma transfer flags include:
 *       NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_CTXDMA
 *       NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_GPUGART
 *       NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_COH_MODE
 *   NV2080_CTRL_BUS_INFO_INDEX_GPU_GART_SIZE
 *     This index is used to request the size of the GPU GART in MBytes.
 *   NV2080_CTRL_BUS_INFO_INDEX_GPU_GART_FLAGS
 *     This index is used to request GPU GART flags.
 *     Valid gart flags include:
 *       NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_REQFLUSH
 *         This flag indicates that GPU GART clients need to do an explicit
 *         flush via an appropriate SetContextDma method.
 *       NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_UNIFIED
 *         This flag indicates that the GART address range includes both
 *         system and video memory.
 *   NV2080_CTRL_BUS_INFO_INDEX_BUS_NUMBER
 *     This index is used to request the PCI-based bus number of the GPU.
 *     Support for this index is platform-dependent.
 *   NV2080_CTRL_BUS_INFO_INDEX_DEVICE_NUMBER
 *     This index is used to request the PCI-based device number of the GPU.
 *     Support for this index is platform-dependent.
 *   NV2080_CTRL_BUS_INFO_INDEX_DOMAIN_NUMBER
 *     This index is used to request the PCI-based domain number of the GPU.
 *     Support for this index is platform-dependent.
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_ERRORS
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_ROOT_LINK_ERRORS
 *     These indices are used to request PCI Express error status.
 *     The current status is cleared as part of these requests.
 *     Valid PCI Express error status values include:
 *       NV2080_CTRL_BUS_INFO_PCIE_LINK_ERRORS_CORR_ERROR
 *       NV2080_CTRL_BUS_INFO_PCIE_LINK_ERRORS_NON_FATAL_ERROR
 *       NV2080_CTRL_BUS_INFO_PCIE_LINK_ERRORS_FATAL_ERROR
 *       NV2080_CTRL_BUS_INFO_PCIE_LINK_ERRORS_UNSUPP_REQUEST
 *   NV2080_CTRL_BUS_INFO_INDEX_INTERFACE_TYPE
 *     This index is used to request the bus interface type of the GPU.
 *     Legal return values for this index are:
 *       NV2080_CTRL_BUS_INFO_TYPE_PCI
 *       NV2080_CTRL_BUS_INFO_TYPE_PCI_EXPRESS
 *       NV2080_CTRL_BUS_INFO_TYPE_FPCI
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GEN2_INFO // DEPRECATED
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GEN_INFO  // REPLACES "GEN2" variant
 *     This index is used to retrieve PCI Express Gen configuration support
 *     This index is used to retrieve PCI Express Gen2 configuration support 
 *     for the GPU.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN1
 *          The GPU is PCI Express Gen1 capable.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN2
 *          The GPU is PCI Express Gen2 capable.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN3
 *          The GPU is PCI Express Gen3 capable.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN4
 *          The GPU is PCI Express Gen4 capable.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN5
 *          The GPU is PCI Express Gen5 capable.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN1
 *          The GPU is configured in PCI Express Gen1 mode.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN2
 *          The GPU is configured in PCI Express Gen2 mode.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN3
 *          The GPU is configured in PCI Express Gen3 mode.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN4
 *          The GPU is configured in PCI Express Gen4 mode.
 *      NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN5
 *          The GPU is configured in PCI Express Gen5 mode.
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_AER
 *     This index retrieves PCI Express Advanced Error Reporting (AER) errors 
 *     for the GPU.
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_BOARD_LINK_CAPS
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_UPSTREAM_LINK_CAPS
 *     This index retrieves the PCI Express link capabilities for the
 *     board.  For example, a Quadro FX4700X2 has two GPUs and PCIe
 *     switch.  With this board, this index returns the link
 *     capabilities of the PCIe switch.  In a single GPU board, this
 *     index returns the link capabilities of the GPU.  A value of
 *     zero is returned for non-PCIE GPUs.
 *     UPSTREAM_LINK_CAPS is kept for backwards compatibility.
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_BOARD_LINK_CTRL_STATUS
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_UPSTREAM_LINK_CTRL_STATUS
 *     This index retrieves the PCI Express link status for the board.
 *     For example, a Quadro FX4700X2 has two GPUs and PCIe switch.
 *     With this board, this index returns the link capabilities of
 *     the PCIe switch.  In a single GPU board, this index returns the
 *     link status of the GPU.  A value of zero is returned for
 *     non-PCIE GPUs.
 *     UPSTREAM_LINK_CTRL_STATUS is kept for backwards compatibility.
 *   NV2080_CTRL_BUS_INFO_INDEX_ASLM_STATUS
 *     This index is used to request the PCI Express ASLM settings.
 *     This index is only valid when NV2080_CTRL_BUS_INFO_TYPE indicates PCIE.
 *     A value of zero is returned for non-PCI Express bus type.
 *     _ASLM_STATUS_PCIE is always _PRESENT if PCI Express bus type.
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_LINK_WIDTH_SWITCH_ERROR_COUNT
 *     This index is used to get the ASLM switching error count.
 *     A value of zero will be returned if no errors occurs while
 *     ASLM switching
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GEN2_SWITCH_ERROR_COUNT
 *     This index is used to get the Gen1<-->Gen2 switching error count
 *     A value of zero will be returned in case speed change from Gen1 to
 *     Gen2 is clean or if chipset is not gen2 capable or if gen1<-->gen2 
 *     switching is disabled.
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_CYA_ASPM
 *     This index is used to get the ASPM CYA L0s\L1 enable\disable status.
 *     Legal return value is specified as a mask of valid and data field
 *     possible return values are:
 *      NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_VALID_NO
 *      NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_VALID_YES
 *      NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_DISABLED
 *      NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_L0S
 *      NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_L1
 *      NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_L0S_L1
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_LINECODE_ERRORS
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CRC_ERRORS
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_NAKS_RECEIVED
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_FAILED_L0S_EXITS
 *     These indices are used to request detailed PCI Express error counters.
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_LINECODE_ERRORS_CLEAR
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CRC_ERRORS_CLEAR
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_NAKS_RECEIVED_CLEAR
 *   NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_FAILED_L0S_EXITS_CLEAR
 *     These indices are used to clear detailed PCI Express error counters.
 *   NV2080_CTRL_BUS_INFO_INDEX_GPU_INTERFACE_TYPE
 *     This index is used to request the internal interface type of the GPU.
 *     Legal return values for this index are:
 *       NV2080_CTRL_BUS_INFO_TYPE_PCI
 *       NV2080_CTRL_BUS_INFO_TYPE_PCI_EXPRESS
 *       NV2080_CTRL_BUS_INFO_TYPE_FPCI
 *   NV2080_CTRL_BUS_INFO_INDEX_SYSMEM_CONNECTION_TYPE
 *     This index queries the type of sysmem connection to CPU
 *     NV2080_CTRL_BUS_INFO_INDEX_SYSMEM_CONNECTION_TYPE_PCIE
 *     NV2080_CTRL_BUS_INFO_INDEX_SYSMEM_CONNECTION_TYPE_NVLINK
 *     NV2080_CTRL_BUS_INFO_INDEX_SYSMEM_CONNECTION_TYPE_C2C
 *
 */

typedef struct NV2080_CTRL_BUS_INFO {
    NvU32 index;
    NvU32 data;
} NV2080_CTRL_BUS_INFO;

/* valid bus info index values */

/**
 *  This index is used to request the bus type of the GPU.
 *  Legal return values for this index are:
 *    NV2080_CTRL_BUS_INFO_TYPE_PCI
 *    NV2080_CTRL_BUS_INFO_TYPE_PCI_EXPRESS
 *    NV2080_CTRL_BUS_INFO_TYPE_FPCI
 */
#define NV2080_CTRL_BUS_INFO_INDEX_TYPE                                     (0x00000000)
#define NV2080_CTRL_BUS_INFO_INDEX_INTLINE                                  (0x00000001)
#define NV2080_CTRL_BUS_INFO_INDEX_CAPS                                     (0x00000002)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CAPS                       (0x00000003)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_ROOT_LINK_CAPS                      (0x00000004)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_UPSTREAM_LINK_CAPS                  (0x00000005)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_DOWNSTREAM_LINK_CAPS                (0x00000006)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CTRL_STATUS                (0x00000007)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_ROOT_LINK_CTRL_STATUS               (0x00000008)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_UPSTREAM_LINK_CTRL_STATUS           (0x00000009)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_DOWNSTREAM_LINK_CTRL_STATUS         (0x0000000A)
/**
 * This index is used to request coherent dma transfer flags.
 * Valid coherent dma transfer flags include:
 *   NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_CTXDMA
 *   NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_GPUGART
 */
#define NV2080_CTRL_BUS_INFO_INDEX_COHERENT_DMA_FLAGS                       (0x0000000B)
/**
 * This index is used to request noncoherent dma transfer flags.
 * Valid noncoherent dma transfer flags include:
 *   NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_CTXDMA
 *   NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_GPUGART
 *   NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_COH_MODE
 */
#define NV2080_CTRL_BUS_INFO_INDEX_NONCOHERENT_DMA_FLAGS                    (0x0000000C)
/**
 * This index is used to request the size of the GPU GART in MBytes.
 */
#define NV2080_CTRL_BUS_INFO_INDEX_GPU_GART_SIZE                            (0x0000000D)
/**
 * This index is used to request GPU GART flags.
 * Valid gart flags include:
 *   NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_REQFLUSH
 *     This flag indicates that GPU GART clients need to do an explicit
 *     flush via an appropriate SetContextDma method.
 *   NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_UNIFIED
 *     This flag indicates that the GART address range includes both
 *     system and video memory.
 */
#define NV2080_CTRL_BUS_INFO_INDEX_GPU_GART_FLAGS                           (0x0000000E)
#define NV2080_CTRL_BUS_INFO_INDEX_BUS_NUMBER                               (0x0000000F)
#define NV2080_CTRL_BUS_INFO_INDEX_DEVICE_NUMBER                            (0x00000010)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_ERRORS                     (0x00000011)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_ROOT_LINK_ERRORS                    (0x00000012)
#define NV2080_CTRL_BUS_INFO_INDEX_INTERFACE_TYPE                           (0x00000013)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GEN2_INFO                           (0x00000014)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_AER                        (0x00000015)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_BOARD_LINK_CAPS                     (0x00000016)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_BOARD_LINK_CTRL_STATUS              (0x00000017)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_ASLM_STATUS                         (0x00000018)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_LINK_WIDTH_SWITCH_ERROR_COUNT       (0x00000019)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_LINK_SPEED_SWITCH_ERROR_COUNT       (0x0000001A)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_CYA_ASPM                        (0x0000001B)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_LINECODE_ERRORS            (0x0000001C)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CRC_ERRORS                 (0x0000001D)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_NAKS_RECEIVED              (0x0000001E)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_FAILED_L0S_EXITS           (0x0000001F)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_LINECODE_ERRORS_CLEAR      (0x00000020)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CRC_ERRORS_CLEAR           (0x00000021)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_NAKS_RECEIVED_CLEAR        (0x00000022)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_FAILED_L0S_EXITS_CLEAR     (0x00000023)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CORRECTABLE_ERRORS         (0x00000024)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_NONFATAL_ERRORS            (0x00000025)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_FATAL_ERRORS               (0x00000026)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_UNSUPPORTED_REQUESTS       (0x00000027)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_CORRECTABLE_ERRORS_CLEAR   (0x00000028)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_NONFATAL_ERRORS_CLEAR      (0x00000029)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_FATAL_ERRORS_CLEAR         (0x0000002A)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GPU_LINK_UNSUPPORTED_REQUESTS_CLEAR (0x0000002B)
#define NV2080_CTRL_BUS_INFO_INDEX_DOMAIN_NUMBER                            (0x0000002C)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_GEN_INFO                            (0x0000002D)
#define NV2080_CTRL_BUS_INFO_INDEX_GPU_INTERFACE_TYPE                       (0x0000002E)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_UPSTREAM_GEN_INFO                   (0x0000002F)
#define NV2080_CTRL_BUS_INFO_INDEX_PCIE_BOARD_GEN_INFO                      (0x00000030)
#define NV2080_CTRL_BUS_INFO_INDEX_MSI_INFO                                 (0x00000031)
/**
 * This index is used to request the top 32 bits of the size of the GPU
 * GART in MBytes.
 */
#define NV2080_CTRL_BUS_INFO_INDEX_GPU_GART_SIZE_HI                         (0x00000032)
#define NV2080_CTRL_BUS_INFO_INDEX_SYSMEM_CONNECTION_TYPE                   (0x00000033)
#define NV2080_CTRL_BUS_INFO_INDEX_MAX                                      NV2080_CTRL_BUS_INFO_INDEX_SYSMEM_CONNECTION_TYPE
#define NV2080_CTRL_BUS_INFO_MAX_LIST_SIZE                                  (0x00000034)

/* valid bus info type return values */
#define NV2080_CTRL_BUS_INFO_TYPE_PCI                                       (0x00000001)
#define NV2080_CTRL_BUS_INFO_TYPE_PCI_EXPRESS                               (0x00000003)
#define NV2080_CTRL_BUS_INFO_TYPE_FPCI                                      (0x00000004)
#define NV2080_CTRL_BUS_INFO_TYPE_AXI                                       (0x00000008)

/* valid bus capability flags */
#define NV2080_CTRL_BUS_INFO_CAPS_NEED_IO_FLUSH                             (0x00000001)
#define NV2080_CTRL_BUS_INFO_CAPS_CHIP_INTEGRATED                           (0x00000002)

/* 
 * Format of PCIE link caps return values
 * Note that Link Capabilities register format is followed only for bits 11:0
 */
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_MAX_SPEED               3:0
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_MAX_SPEED_2500MBPS               (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_MAX_SPEED_5000MBPS               (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_MAX_SPEED_8000MBPS               (0x00000003)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_MAX_SPEED_16000MBPS              (0x00000004)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_MAX_SPEED_32000MBPS              (0x00000005)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_MAX_WIDTH               9:4
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_ASPM                    11:10
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_ASPM_NONE                        (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_ASPM_L0S                         (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_ASPM_L0S_L1                      (0x00000003)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN                     15:12
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN1                         (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN2                         (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN3                         (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN4                         (0x00000003)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GEN_GEN5                         (0x00000004)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL              19:16
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN1                  (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN2                  (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN3                  (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN4                  (0x00000003)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_CURR_LEVEL_GEN5                  (0x00000004)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GPU_GEN                 23:20
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GPU_GEN_GEN1                     (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GPU_GEN_GEN2                     (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GPU_GEN_GEN3                     (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GPU_GEN_GEN4                     (0x00000003)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_GPU_GEN_GEN5                     (0x00000004)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_SPEED_CHANGES           24:24
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_SPEED_CHANGES_ENABLED            (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CAP_SPEED_CHANGES_DISABLED           (0x00000001)

/* format of PCIE control status return values */
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_ASPM                 1:0
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_ASPM_DISABLED            (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_ASPM_L0S                 (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_ASPM_L1                  (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_ASPM_L0S_L1              (0x00000003)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_SPEED           19:16
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_SPEED_2500MBPS      (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_SPEED_5000MBPS      (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_SPEED_8000MBPS      (0x00000003)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_SPEED_16000MBPS     (0x00000004)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_SPEED_32000MBPS     (0x00000005)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_WIDTH           25:20
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_WIDTH_UNDEFINED     (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_WIDTH_X1            (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_WIDTH_X2            (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_WIDTH_X4            (0x00000004)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_WIDTH_X8            (0x00000008)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_WIDTH_X12           (0x0000000C)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_WIDTH_X16           (0x00000010)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_CTRL_STATUS_LINK_WIDTH_X32           (0x00000020)

/* coherent dma transfer flags */
#define NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_CTXDMA             0:0
#define NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_CTXDMA_FALSE                (0x00000000)
#define NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_CTXDMA_TRUE                 (0x00000001)
#define NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_GPUGART            2:2
#define NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_GPUGART_FALSE               (0x00000000)
#define NV2080_CTRL_BUS_INFO_COHERENT_DMA_FLAGS_GPUGART_TRUE                (0x00000001)

/* noncoherent dma transfer flags */
#define NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_CTXDMA          0:0
#define NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_CTXDMA_FALSE             (0x00000000)
#define NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_CTXDMA_TRUE              (0x00000001)
#define NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_GPUGART         2:2
#define NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_GPUGART_FALSE            (0x00000000)
#define NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_GPUGART_TRUE             (0x00000001)
#define NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_COH_MODE        3:3
#define NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_COH_MODE_FALSE           (0x00000000)
#define NV2080_CTRL_BUS_INFO_NONCOHERENT_DMA_FLAGS_COH_MODE_TRUE            (0x00000001)

/* GPU GART flags */
#define NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_REQFLUSH               0:0
#define NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_REQFLUSH_FALSE                  (0x00000000)
#define NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_REQFLUSH_TRUE                   (0x00000001)
#define NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_UNIFIED                1:1
#define NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_UNIFIED_FALSE                   (0x00000000)
#define NV2080_CTRL_BUS_INFO_GPU_GART_FLAGS_UNIFIED_TRUE                    (0x00000001)

/* format of PCIE errors return values */
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_ERRORS_CORR_ERROR                    (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_ERRORS_NON_FATAL_ERROR               (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_ERRORS_FATAL_ERROR                   (0x00000004)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_ERRORS_UNSUPP_REQUEST                (0x00000008)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_ERRORS_ENTERED_RECOVERY              (0x00000010)

/* PCIE Gen2 capability and current level */
#define NV2080_CTRL_BUS_INFO_PCIE_GEN2_INFO_CAP                    0:0
#define NV2080_CTRL_BUS_INFO_PCIE_GEN2_INFO_CAP_FALSE                       (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_GEN2_INFO_CAP_TRUE                        (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_GEN2_INFO_CURR_LEVEL             1:1
#define NV2080_CTRL_BUS_INFO_PCIE_GEN2_INFO_CURR_LEVEL_GEN1                 (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_GEN2_INFO_CURR_LEVEL_GEN2                 (0x00000001)

/* format of PCIE AER return values */
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_TRAINING_ERR              (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_DLINK_PROTO_ERR           (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_POISONED_TLP              (0x00000004)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_FC_PROTO_ERR              (0x00000008)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_CPL_TIMEOUT               (0x00000010)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_CPL_ABORT                 (0x00000020)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_UNEXP_CPL                 (0x00000040)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_RCVR_OVERFLOW             (0x00000080)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_MALFORMED_TLP             (0x00000100)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_ECRC_ERROR                (0x00000200)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_UNCORR_UNSUPPORTED_REQ           (0x00000400)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_CORR_RCV_ERR                     (0x00010000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_CORR_BAD_TLP                     (0x00020000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_CORR_BAD_DLLP                    (0x00040000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_CORR_RPLY_ROLLOVER               (0x00080000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_CORR_RPLY_TIMEOUT                (0x00100000)
#define NV2080_CTRL_BUS_INFO_PCIE_LINK_AER_CORR_ADVISORY_NONFATAL           (0x00200000)

/* format of PCIE ASLM status return value */
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_PCIE                  0:0
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_PCIE_ERROR                    (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_PCIE_PRESENT                  (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_SUPPORTED             1:1
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_SUPPORTED_NO                  (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_SUPPORTED_YES                 (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_CL_CAPABLE            2:2
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_CL_CAPABLE_NO                 (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_CL_CAPABLE_YES                (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_OS_SUPPORTED          3:3
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_OS_SUPPORTED_NO               (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_OS_SUPPORTED_YES              (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_BR04                  4:4
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_BR04_MISSING                  (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_ASLM_STATUS_BR04_PRESENT                  (0x00000001)

/* format of GPU CYA CAPS return value */
#define NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_VALID               0:0
#define NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_VALID_NO                     (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_VALID_YES                    (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM                     2:1
#define NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_DISABLED                     (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_L0S                          (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_L1                           (0x00000002)
#define NV2080_CTRL_BUS_INFO_PCIE_GPU_CYA_ASPM_L0S_L1                       (0x00000003)

/* format of MSI INFO return value */
#define NV2080_CTRL_BUS_INFO_MSI_STATUS                            0:0
#define NV2080_CTRL_BUS_INFO_MSI_STATUS_DISABLED                            (0x00000000)
#define NV2080_CTRL_BUS_INFO_MSI_STATUS_ENABLED                             (0x00000001)

/*format of L1PM Substates capabilities information */
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_PCIPM_L1_2_SUPPORTED         0:0
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_PCIPM_L1_2_SUPPORTED_YES        (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_PCIPM_L1_2_SUPPORTED_NO         (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_PCIPM_L1_1_SUPPORTED         1:1
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_PCIPM_L1_1_SUPPORTED_YES        (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_PCIPM_L1_1_SUPPORTED_NO         (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_ASPM_L1_2_SUPPORTED          2:2
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_ASPM_L1_2_SUPPORTED_YES         (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_ASPM_L1_2_SUPPORTED_NO          (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_ASPM_L1_1_SUPPORTED          3:3
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_ASPM_L1_1_SUPPORTED_YES         (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_ASPM_L1_1_SUPPORTED_NO          (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_L1PM_SUPPORTED               4:4
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_L1PM_SUPPORTED_YES              (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_L1PM_SUPPORTED_NO               (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_RESERVED                     7:5
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_PORT_RESTORE_TIME            15:8
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_T_POWER_ON_SCALE             17:16
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CAP_T_POWER_ON_VALUE             23:19

/*format of L1 PM Substates Control 1 Register */
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_PCIPM_L1_2_ENABLED         0:0
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_PCIPM_L1_2_ENABLED_YES        (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_PCIPM_L1_2_ENABLED_NO         (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_PCIPM_L1_1_ENABLED         1:1
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_PCIPM_L1_1_ENABLED_YES        (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_PCIPM_L1_1_ENABLED_NO         (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_ASPM_L1_2_ENABLED          2:2
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_ASPM_L1_2_ENABLED_YES         (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_ASPM_L1_2_ENABLED_NO          (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_ASPM_L1_1_ENABLED          3:3
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_ASPM_L1_1_ENABLED_YES         (0x00000001)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_ASPM_L1_1_ENABLED_NO          (0x00000000)
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_COMMON_MODE_RESTORE_TIME   15:8
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_LTR_L1_2_THRESHOLD_VALUE   25:16
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL1_LTR_L1_2_THRESHOLD_SCALE   31:29

/*format of L1 PM Substates Control 2 Register */
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL2_T_POWER_ON_SCALE           1:0
#define NV2080_CTRL_BUS_INFO_PCIE_L1_SS_CTRL2_T_POWER_ON_VALUE           7:3

/* valid sysmem connection type values */
#define NV2080_CTRL_BUS_INFO_INDEX_SYSMEM_CONNECTION_TYPE_PCIE              (0x00000000)
#define NV2080_CTRL_BUS_INFO_INDEX_SYSMEM_CONNECTION_TYPE_NVLINK            (0x00000001)
#define NV2080_CTRL_BUS_INFO_INDEX_SYSMEM_CONNECTION_TYPE_C2C               (0x00000002)

/**
 * NV2080_CTRL_CMD_BUS_GET_INFO
 *
 * This command returns bus engine information for the associated GPU.
 * Requests to retrieve bus information use a list of one or more
 * NV2080_CTRL_BUS_INFO structures.
 *
 *   busInfoListSize
 *     This field specifies the number of entries on the caller's
 *     busInfoList.
 *   busInfoList
 *     This field specifies a pointer in the caller's address space
 *     to the buffer into which the bus information is to be returned.
 *     This buffer must be at least as big as busInfoListSize multiplied
 *     by the size of the NV2080_CTRL_BUS_INFO structure.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_OPERATING_SYSTEM
 */
#define NV2080_CTRL_CMD_BUS_GET_INFO                                        (0x20801802) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_BUS_INTERFACE_ID << 8) | NV2080_CTRL_BUS_GET_INFO_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_BUS_GET_INFO_PARAMS_MESSAGE_ID (0x2U)

typedef struct NV2080_CTRL_BUS_GET_INFO_PARAMS {
    NvU32 busInfoListSize;
    NV_DECLARE_ALIGNED(NvP64 busInfoList, 8);
} NV2080_CTRL_BUS_GET_INFO_PARAMS;

#define NV2080_CTRL_CMD_BUS_GET_INFO_V2 (0x20801823) /* finn: Evaluated from "(FINN_NV20_SUBDEVICE_0_BUS_INTERFACE_ID << 8) | NV2080_CTRL_BUS_GET_INFO_V2_PARAMS_MESSAGE_ID" */

#define NV2080_CTRL_BUS_GET_INFO_V2_PARAMS_MESSAGE_ID (0x23U)

typedef struct NV2080_CTRL_BUS_GET_INFO_V2_PARAMS {
    NvU32                busInfoListSize;
    NV2080_CTRL_BUS_INFO busInfoList[NV2080_CTRL_BUS_INFO_MAX_LIST_SIZE];
} NV2080_CTRL_BUS_GET_INFO_V2_PARAMS;



