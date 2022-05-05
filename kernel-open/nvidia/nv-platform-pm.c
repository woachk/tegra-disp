/*
 * SPDX-FileCopyrightText: Copyright (c) 2020 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

#define  __NO_VERSION__

#include "os-interface.h"
#include "nv-linux.h"

/*!
 * @brief Unpowergate the display.
 *
 * Increment the device's usage counter, run pm_request_resume(dev)
 * and return its result.
 *
 * For more details on runtime pm functions, please check the below
 * files in the Linux kernel:
 *
 * include/linux/pm_runtime.h
 * include/linux/pm.h
 * or
 * https://www.kernel.org/doc/Documentation/power/runtime_pm.txt
 *
 * @param[in]  nv      Per gpu linux state
 *
 * @returns NV_STATUS
 */
NV_STATUS NV_API_CALL nv_soc_pm_unpowergate(
    nv_state_t *nv)
{
    NV_STATUS status      = NV_ERR_GENERIC;
    nv_linux_state_t *nvl = NV_GET_NVL_FROM_NV_STATE(nv);
    NvS32 ret             = -EBUSY;

    ret = pm_runtime_get(nvl->dev);

    if (ret == 0)
    {
        status = NV_OK;
    }
    else
    {
        nv_printf(NV_DBG_ERRORS, "NVRM: unpowergate unsuccessful. ret: %d\n", ret);
    }

    return status;
}

/*!
 * @brief Powergate the display.
 *
 * Decrement the device's usage counter; if the result is 0 then run
 * pm_request_idle(dev) and return its result.
 *
 * For more details on runtime pm functions, please check the below
 * files in the Linux kernel:
 *
 * include/linux/pm_runtime.h
 * include/linux/pm.h
 * or
 * https://www.kernel.org/doc/Documentation/power/runtime_pm.txt
 *
 * @param[in]  nv      Per gpu linux state
 *
 * @returns NV_STATUS
 */
NV_STATUS NV_API_CALL nv_soc_pm_powergate(
    nv_state_t *nv)
{
    NV_STATUS status      = NV_ERR_GENERIC;
    nv_linux_state_t *nvl = NV_GET_NVL_FROM_NV_STATE(nv);
    NvS32 ret             = -EBUSY;

    ret = pm_runtime_put(nvl->dev);

    if (ret == 0)
    {
        status = NV_OK;
    }
    else
    {
        nv_printf(NV_DBG_ERRORS, "NVRM: powergate unsuccessful. ret: %d\n", ret);
    }

    return status;
}

