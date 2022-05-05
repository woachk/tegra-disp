/*
 * Copyright (c) 1993-2021, NVIDIA CORPORATION. All rights reserved.
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
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef NVERROR_H
#define NVERROR_H
/******************************************************************************
*
*   File:  nverror.h
*
*   Description:
*       This file contains the error codes set when the error notifier
*   is signaled.
*
******************************************************************************/

#define ROBUST_CHANNEL_GPU_HAS_FALLEN_OFF_THE_BUS       (79)

#define ROBUST_CHANNEL_ERROR_STR_PUBLIC_PUBLISHED  \
       {"Unknown Error",                         \
        "DMA Engine Error (FIFO Error 1)",       \
        "DMA Engine Error (FIFO Error 2)",       \
        "DMA Engine Error (FIFO Error 3)",       \
        "DMA Engine Error (FIFO Error 4)",       \
        "DMA Engine Error (FIFO Error 5)",       \
        "DMA Engine Error (FIFO Error 6)",       \
        "DMA Engine Error (FIFO Error 7)",       \
        "DMA Engine Error (FIFO Error 8)",       \
        "Graphics Engine Error (GR Error 1)",    \
        "Graphics Engine Error (GR Error 2)",    \
        "Graphics Engine Error (GR Error 3)",    \
        "Graphics Engine Error (GR Error 4)",    \
        "Graphics Engine Error (GR Exception Error)",\
        "Fake Error",                            \
        "Display Engine Error (CRTC Error 1)",   \
        "Display Engine Error (CRTC Error 2)",   \
        "Display Engine Error (CRTC Error 3)",   \
        "Bus Interface Error (BIF Error)",       \
        "Client Reported Error",                 \
        "Video Engine Error (MPEG Error)",       \
        "Video Engine Error (ME Error)",         \
        "Video Engine Error (VP Error 1)",       \
        "Error Reporting Enabled",               \
        "Graphics Engine Error (GR Error 6)",    \
        "Graphics Engine Error (GR Error 7)",    \
        "DMA Engine Error (FIFO Error 9)",       \
        "Video Engine Error (VP Error 2)",       \
        "Video Engine Error (VP2 Error)",        \
        "Video Engine Error (BSP Error)",        \
        "Access Violation Error (MMU Error 1)",  \
        "Access Violation Error (MMU Error 2)",  \
        "DMA Engine Error (PBDMA Error)",        \
        "Security Engine Error (SEC Error)",     \
        "Video Engine Error (MSVLD Error)",      \
        "Video Engine Error (MSPDEC Error)",     \
        "Video Engine Error (MSPPP Error)",      \
        "Graphics Engine Error (FECS Error 1)",  \
        "Graphics Engine Error (FECS Error 2)",  \
        "DMA Engine Error (CE Error 1)",         \
        "DMA Engine Error (CE Error 2)",         \
        "DMA Engine Error (CE Error 3)",         \
        "Video Engine Error (VIC Error)",        \
        "Verification Error",                    \
        "Access Violation Error (MMU Error 3)",  \
        "Operating System Error (OS Error 1)",   \
        "Operating System Error (OS Error 2)",   \
        "Video Engine Error (MSENC/NVENC0 Error)",\
        "ECC Error (DBE Error)",                 \
        "Power State Locked",                    \
        "Power State Event (RC Error)",          \
        "Power State Event (Stress Test Error)", \
        "Power State Event (Thermal Event 1)",   \
        "Power State Event (Thermal Event 2)",   \
        "Power State Event (Power Event)",       \
        "Power State Event (Thermal Event 3)",   \
        "Display Engine Error (EVO Error)",      \
        "FB Interface Error (FBPA Error 1)",     \
        "FB Interface Error (FBPA Error 2)",     \
        "PMU error",                             \
        "SEC2 error",                            \
        "PMU Breakpoint (non-fatal)",            \
        "PMU Halt Error",                        \
        "INFOROM Page Retirement Event",         \
        "INFOROM Page Retirement Failure",       \
        "Video Engine Error (NVENC1 Error)",     \
        "Graphics Engine Error (FECS Error 3)",  \
        "Graphics Engine Error (FECS Error 4)",  \
        "Video Engine Error (NVDEC0 Error)",     \
        "Graphics Engine Error (GR Class Error)",\
        "DMA Engine Error (CE Error 4)",         \
        "DMA Engine Error (CE Error 5)",         \
        "DMA Engine Error (CE Error 6)",         \
        "Video Engine Error (NVENC2 Error)",     \
        "NVLink Error",                          \
        "DMA Engine Error (CE Error 6)",         \
        "DMA Engine Error (CE Error 7)",         \
        "DMA Engine Error (CE Error 8)",         \
        "vGPU device cannot be started",         \
        "GPU has fallen off the bus",            \
        "DMA Engine Error (Pushbuffer CRC mismatch)",\
        "VGA Subsystem Error",                   \
        "Video JPEG Engine Error (NVJPG Error)", \
        "Video Engine Error (NVDEC1 Error)",     \
        "Video Engine Error (NVDEC2 Error)",     \
        "DMA Engine Error (CE Error 9)",         \
        "Video OFA Engine Error (OFA0 Error)",   \
        "NvTelemetry Driver Reoprt",             \
        "Video Engine Error (NVDEC3 Error)",     \
        "Video Engine Error (NVDEC4 Error)",     \
        "FB Interface Error (FBPA Error 3)",     \
        "Reserved Xid",                          \
        "Excessive SBE interrupts"

#define ROBUST_CHANNEL_ERROR_STR_PUBLIC             \
        ROBUST_CHANNEL_ERROR_STR_PUBLIC_PUBLISHED}

#endif  // NVERROR_H
