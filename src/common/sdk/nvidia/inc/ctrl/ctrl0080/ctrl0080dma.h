/*
 * SPDX-FileCopyrightText: Copyright (c) 2006-2018 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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
// Source file: ctrl/ctrl0080/ctrl0080dma.finn
//




#include "ctrl/ctrl0080/ctrl0080base.h"

/* NV01_DEVICE_XX/NV03_DEVICE dma control commands and parameters */



/*
 * NV0080_CTRL_DMA_FLUSH
 *
 * This command flushes the specified target unit
 *
 *   targetUnit
 *      The unit to flush, either L2 cache or compression tag cache.
 *      This field is a logical OR of the individual fields such as
 *      L2 cache or compression tag cache. Also L2 invalidation for
 *      either SYSMEM/PEERMEM is triggered. But this invalidation is 
 *      for FERMI.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_GENERIC
 *
 * See Also:
 *   NV2080_CTRL_CMD_FB_FLUSH_GPU_CACHE
 *     Flushes the entire GPU cache or a set of physical addresses (if the
 *     hardware supports it).  Use this call if you want to flush a set of
 *     addresses or the entire GPU cache in unicast mode.
 *   NV0041_CTRL_CMD_SURFACE_FLUSH_GPU_CACHE
 *     Flushes memory associated with a single allocation if the hardware
 *     supports it.  Use this call if you want to flush a single allocation and
 *     you have a memory object describing the physical memory.
 */
#define NV0080_CTRL_CMD_DMA_FLUSH                                                     (0x801805) /* finn: Evaluated from "(FINN_NV01_DEVICE_0_DMA_INTERFACE_ID << 8) | NV0080_CTRL_DMA_FLUSH_PARAMS_MESSAGE_ID" */

#define NV0080_CTRL_DMA_FLUSH_PARAMS_MESSAGE_ID (0x5U)

typedef struct NV0080_CTRL_DMA_FLUSH_PARAMS {
    NvU32 targetUnit;
} NV0080_CTRL_DMA_FLUSH_PARAMS;

#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_L2                         0:0
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_L2_DISABLE            (0x00000000)
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_L2_ENABLE             (0x00000001)
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_COMPTAG                    1:1
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_COMPTAG_DISABLE       (0x00000000)
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_COMPTAG_ENABLE        (0x00000001)
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_FB                         2:2
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_FB_DISABLE            (0x00000000)
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_FB_ENABLE             (0x00000001)

// This is exclusively for Fermi
// The selection of non-zero valued bit-fields avoids the routing 
// into the above cases and vice-versa
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_L2_INVALIDATE              4:3
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_L2_INVALIDATE_SYSMEM  (0x00000001)
#define NV0080_CTRL_DMA_FLUSH_TARGET_UNIT_L2_INVALIDATE_PEERMEM (0x00000002)


/* _ctrl0080dma_h_ */

