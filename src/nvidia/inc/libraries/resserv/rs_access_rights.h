/*
 * SPDX-FileCopyrightText: Copyright (c) 2019-2020 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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
#ifndef RS_ACCESS_RIGHTS_H
#define RS_ACCESS_RIGHTS_H

#include "nvstatus.h"
#include "nvtypes.h"
#include "nvmisc.h"

// Part of this header in userspace, at sdk/nvidia/inc/rs_access.h
#include "rs_access.h"

#ifdef __cplusplus
extern "C" {
#endif


/****************************************************************************/
/*                          Access right flags                              */
/****************************************************************************/

//
// The meaning of each access right flag is documented in
//   drivers/resman/docs/rmapi/resource_server/rm_capabilities.adoc
//

#define RS_ACCESS_FLAG_NONE                      0U
#define RS_ACCESS_FLAG_ALLOW_KERNEL_PRIVILEGED   NVBIT(1)
#define RS_ACCESS_FLAG_ALLOW_PRIVILEGED          NVBIT(2)
#define RS_ACCESS_FLAG_UNCACHED_CHECK            NVBIT(3)
#define RS_ACCESS_FLAG_ALLOW_OWNER               NVBIT(4)


/****************************************************************************/
/*                         Access right metadata                            */
/****************************************************************************/

/*!
 * @brief Metadata about each access right
 *
 * The ith entry in this array represents access right i.
 */
extern const RS_ACCESS_INFO g_rsAccessMetadata[RS_ACCESS_COUNT];


/****************************************************************************/
/*                           Access right macros                            */
/****************************************************************************/

/*!
 * @brief Initializer for an access mask. Avoid use if possible.
 *
 * To initialize an access mask, if possible, first zero-initialize it then
 * add specific access rights at runtime. Zero-initialization can be performed
 * with the RS_ACCESS_MASK_EMPTY static initializer, the RS_ACCESS_MASK_CLEAR() macro,
 * or a memset.
 *
 * Only use this when a static initializer is TRULY needed, and when the code is
 * generated by a script, not hardcoded. For instance, this is useful when
 * statically initializing control call table entries.
 *
 * The ith argument will directly initialize the ith limb. An access right A
 * should be placed in the limb SDK_RS_ACCESS_LIMB_INDEX(A). Each limb should be a
 * mask of flags, where each flag is in the form SDK_RS_ACCESS_OFFSET_MASK(A), or 0
 * to indicate no flags.
 *
 * For example, suppose we have access righs A, B, and C, where
 *
 *     SDK_RS_ACCESS_LIMB_INDEX(A) == 0
 *     SDK_RS_ACCESS_LIMB_INDEX(B) == 2
 *     SDK_RS_ACCESS_LIMB_INDEX(C) == 2
 *
 * In this case, the appropriate way to initialize a mask containing all
 * three access rights is:
 *
 *     RS_ACCESS_MASK mask = RS_ACCESS_MASK_INITIALIZER
 *     (
 *         SDK_RS_ACCESS_OFFSET_MASK(A),
 *         0,
 *         SDK_RS_ACCESS_OFFSET_MASK(B) | SDK_RS_ACCESS_OFFSET_MASK(C)
 *     );
 */
#define RS_ACCESS_MASK_INITIALIZER(...) { { __VA_ARGS__ } }

/*!
 * @brief Empty initializer for an access mask.
 *
 * An example of usage is as follows:
 *
 *     RS_ACCESS_MASK mask = RS_ACCESS_MASK_EMPTY;
 */
#define RS_ACCESS_MASK_EMPTY RS_ACCESS_MASK_INITIALIZER(0)


/****************************************************************************/
/*                          Access right functions                          */
/****************************************************************************/

/*!
 * @brief Checks if one access rights mask is a subset of another
 *
 * @param[in] pRightsPresent The access rights that are held by some actor
 * @param[in] pRightsRequired The access rights that must be a subset of
 *            the rights in pRightsPresent
 *
 * @return NV_TRUE if each of the access rights in pRightsPresent is also
 *         present in pRightsRequired
 * @return NV_FALSE otherwise
 */
NvBool rsAccessMaskIsSubset(const RS_ACCESS_MASK *pRightsPresent,
                        const RS_ACCESS_MASK *pRightsRequired);

/*!
 * @brief Checks if an access right mask is empty
 *
 * @param[in] pAccessMask The mask to check for emptiness
 *
 * @return NV_TRUE if the mask contains no access rights
 * @return NV_FALSE otherwise
 */
NvBool rsAccessMaskIsEmpty(const RS_ACCESS_MASK *pAccessMask);


/*!
 * @brief Converts an array of access rights into a mask
 *
 * This function is useful for processing a statically-initialized array of
 * access rights, since it is not always desirable to directly statically
 * initialize an access mask. One example of this use is the definitions used
 * in resource_list.h.
 *
 * @param[out] pAccessMask The newly initialized access mask
 * @param[in] pRightsArray An array of access right values
 * @param[in] length The number of elements in pRightsList
 *
 * @return Void
 */
void rsAccessMaskFromArray(RS_ACCESS_MASK *pAccessMask,
                       const RsAccessRight *pRightsArray,
                       NvLength length);


#ifdef __cplusplus
}
#endif

#endif /* RS_ACCESS_RIGHTS_H */
