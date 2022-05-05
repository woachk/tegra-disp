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
#if defined(_MSC_VER)
#pragma warning(disable:4324)
#endif

//
// This file was generated with FINN, an NVIDIA coding tool.
// Source file: ctrl/ctrlc370/ctrlc370event.finn
//




#include "ctrl/ctrl5070/ctrl5070event.h"  /* C370 is partially derived from 5070 */
#include "ctrl/ctrlc370/ctrlc370base.h"




/* valid action values */
#define NVC370_CTRL_EVENT_SET_NOTIFICATION_ACTION_DISABLE NV5070_CTRL_EVENT_SET_NOTIFICATION_ACTION_DISABLE
#define NVC370_CTRL_EVENT_SET_NOTIFICATION_ACTION_SINGLE  NV5070_CTRL_EVENT_SET_NOTIFICATION_ACTION_SINGLE
#define NVC370_CTRL_EVENT_SET_NOTIFICATION_ACTION_REPEAT  NV5070_CTRL_EVENT_SET_NOTIFICATION_ACTION_REPEAT

/* _ctrlc370event_h_ */
