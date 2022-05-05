/*
 * Copyright (c) 2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * NVIDIA CORPORATION and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA CORPORATION is strictly prohibited.
 */

#ifndef nvidia_softfloat_platform_h
#define nvidia_softfloat_platform_h 1

#include "nvtypes.h"

/*
 * Build softfloat for little endian CPUs: all NVIDIA target platforms are
 * little endian.
 */
#define LITTLEENDIAN 1

/*
 * "INLINE" is used by softfloat like this:
 *
 *  INLINE uint32_t softfloat_foo(...)
 *  {
 *      ...
 *  }
 */
#define INLINE static NV_INLINE

#if !defined(nvAssert)
#define nvAssert(x)
#endif

/*
 * softfloat will use THREAD_LOCAL to tag variables that should be per-thread;
 * it could be set to, e.g., gcc's "__thread" keyword.  If THREAD_LOCAL is left
 * undefined, these variables will default to being ordinary global variables.
 */
#undef THREAD_LOCAL

#endif /* nvidia_softfloat_platform_h */
