/*
 * SPDX-FileCopyrightText: Copyright (c) 2019-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

/***************************** HW State Routines ***************************\
*                                                                           *
*         Implementation specific Descriptor List management functions      *
*                                                                           *
\***************************************************************************/

#include "core/core.h"
#include "gpu/gpu.h"
#include "gpu/eng_desc.h"
#include "g_allclasses.h"

// See gpuChildOrderList_GM200 for documentation
static const GPUCHILDORDER
gpuChildOrderList_T234D[] =
{
    {classId(OBJDCECLIENTRM),       GCO_ALL},
    {classId(MemorySystem),         GCO_ALL},
    {classId(KernelMemorySystem),   GCO_ALL},
    {classId(MemoryManager),        GCO_ALL},
    {classId(OBJDCB),               GCO_ALL},
    {classId(OBJDISP),              GCO_ALL},
    {classId(KernelDisplay),        GCO_ALL},
    {classId(OBJDPAUX),             GCO_ALL},
    {classId(OBJI2C),               GCO_ALL},
    {classId(OBJGPIO),              GCO_ALL},
    {classId(OBJHDACODEC),          GCO_ALL},
};

// See gpuChildrenPresent_GM200 for documentation on GPUCHILDPRESENT
static const GPUCHILDPRESENT gpuChildrenPresent_T234D[] =
{
    {classId(OBJDCECLIENTRM), 1},
    {classId(OBJDISP), 1},
    {classId(KernelDisplay), 1},
    {classId(MemorySystem), 1},
    {classId(KernelMemorySystem), 1},
    {classId(MemoryManager), 1},
    {classId(OBJDPAUX), 1},
    {classId(OBJI2C), 1},
    {classId(OBJGPIO), 1},
    {classId(OBJTMR), 1},
    {classId(OBJHDACODEC), 1},
    {classId(OBJDCB), 1},
};


const GPUCHILDORDER *
gpuGetChildrenOrder_T234D(OBJGPU *pGpu, NvU32 *pNumEntries)
{
    *pNumEntries = NV_ARRAY_ELEMENTS32(gpuChildOrderList_T234D);
    return gpuChildOrderList_T234D;
}

const GPUCHILDPRESENT *
gpuGetChildrenPresent_T234D(OBJGPU *pGpu, NvU32 *pNumEntries)
{
    *pNumEntries = NV_ARRAY_ELEMENTS32(gpuChildrenPresent_T234D);
     return gpuChildrenPresent_T234D;
}

static const CLASSDESCRIPTOR halT234DClassDescriptorList[] =
{
    {NVC670_DISPLAY,                 ENG_KERNEL_DISPLAY},
    {NVC671_DISP_SF_USER,            ENG_KERNEL_DISPLAY},
    {NVC372_DISPLAY_SW,              ENG_KERNEL_DISPLAY},
    {NVC673_DISP_CAPABILITIES,       ENG_KERNEL_DISPLAY},
    {NVC67A_CURSOR_IMM_CHANNEL_PIO,  ENG_KERNEL_DISPLAY},
    {NVC67B_WINDOW_IMM_CHANNEL_DMA,  ENG_KERNEL_DISPLAY},
    {NVC67D_CORE_CHANNEL_DMA,        ENG_KERNEL_DISPLAY},
    {NVC67E_WINDOW_CHANNEL_DMA,      ENG_KERNEL_DISPLAY},
    {GF100_HDACODEC,                 ENG_HDACODEC},
    {NV04_DISPLAY_COMMON,            ENG_KERNEL_DISPLAY},
    {NV01_MEMORY_SYNCPOINT,          ENG_DMA},
    {(NvU32)~0, (ENGDESCRIPTOR)~0}
};

#define HALT234D_NUM_CLASS_DESCS (sizeof(halT234DClassDescriptorList) / sizeof(CLASSDESCRIPTOR))

//
// Static Asserts for the NV0080_CTRL_CMD_GPU_GET_CLASSLIST_V2 CTRL calls
//
ct_assert(NV0080_CTRL_GPU_CLASSLIST_MAX_SIZE >= HALT234D_NUM_CLASS_DESCS);

const CLASSDESCRIPTOR *
gpuGetClassDescriptorList_T234D(OBJGPU *pGpu, NvU32 *pNumClasses)
{
    *pNumClasses = HALT234D_NUM_CLASS_DESCS;
    return halT234DClassDescriptorList;
}

