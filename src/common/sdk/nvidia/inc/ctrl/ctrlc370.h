/*
 * SPDX-FileCopyrightText: Copyright (c) 2015-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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
// Source file: ctrl/ctrlc370.finn
//




#include "ctrl/ctrlxxxx.h"
#include "ctrl/ctrlc370/ctrlc370base.h"

// Below includes are required for 5070 ctrl call aliases
#include "ctrl/ctrl5070/ctrl5070chnc.h"
#include "ctrl/ctrl5070/ctrl5070system.h"
#include "ctrl/ctrl5070/ctrl5070rg.h"
#include "ctrl/ctrl5070/ctrl5070seq.h"
#include "ctrl/ctrl5070/ctrl5070or.h"
#include "ctrl/ctrl5070/ctrl5070verif.h"

#define NVC370_CTRL_CMD_CHANNEL_STATE_IDLE                              NVBIT(0)
#define NVC370_CTRL_CMD_CHANNEL_STATE_QUIESCENT1                        NVBIT(2)
#define NVC370_CTRL_CMD_CHANNEL_STATE_QUIESCENT2                        NVBIT(3)
#define NVC370_CTRL_CMD_CHANNEL_STATE_BUSY                              NVBIT(6)
#define NVC370_CTRL_CMD_CHANNEL_STATE_DEALLOC                           NVBIT(7)
#define NVC370_CTRL_CMD_CHANNEL_STATE_DEALLOC_LIMBO                     NVBIT(8)
#define NVC370_CTRL_CMD_CHANNEL_STATE_EFI_INIT1                         NVBIT(11)
#define NVC370_CTRL_CMD_CHANNEL_STATE_EFI_INIT2                         NVBIT(12)
#define NVC370_CTRL_CMD_CHANNEL_STATE_EFI_OPERATION                     NVBIT(13)
#define NVC370_CTRL_CMD_CHANNEL_STATE_VBIOS_INIT1                       NVBIT(14)
#define NVC370_CTRL_CMD_CHANNEL_STATE_VBIOS_INIT2                       NVBIT(15)
#define NVC370_CTRL_CMD_CHANNEL_STATE_VBIOS_OPERATION                   NVBIT(16)
#define NVC370_CTRL_CMD_CHANNEL_STATE_UNCONNECTED                       NVBIT(17)
#define NVC370_CTRL_CMD_CHANNEL_STATE_INIT1                             NVBIT(18)
#define NVC370_CTRL_CMD_CHANNEL_STATE_INIT2                             NVBIT(19)
#define NVC370_CTRL_CMD_CHANNEL_STATE_SHUTDOWN1                         NVBIT(20)
#define NVC370_CTRL_CMD_CHANNEL_STATE_SHUTDOWN2                         NVBIT(21)

#define NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_CORE        1
#define NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WINDOW      32
#define NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WINDOW_IMM  32
#define NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WRITEBACK   8
#define NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_CURSOR      8

/*
 * NVC370_CTRL_CMD_IDLE_CHANNEL
 *
 * This command tries to wait or forces the desired channel state.
 *
 *      channelClass
 *          This field indicates the hw class number (0xC378 - 0xC37E).
 *          It's defined in the h/w header (i.e. clc37d.h, etc.).
 *
 *      channelInstance
 *          This field indicates which instance of the channelClass the cmd is
 *          meant for. (zero-based)
 *
 *      desiredChannelStateMask
 *          This field indicates the desired channel states. When more than
 *          one bit is set, RM will return whenever it finds hardware on one
 *          of the states in the bistmask.
 *          Normal options are IDLE, QUIESCENT1 and QUIESCENT2.
 *          Verif only option includes BUSY as well.
 *          Note:
 *              (1) When QUIESCENT1 or QUIESCENT2 is chosen only one bit should
 *                  be set in the bitmask. RM will ignore any other state.
 *              (2) Accelerators should not be required for QUIESCENT states as
 *                  RM tries to ensure QUIESCENT forcibly on it's own.
 *
 *      accelerators
 *          What accelerator bits should be used if RM timesout trying to
 *          wait for the desired state. This is not yet implemented since it
 *          should normally not be required to use these. Usage of accelerators
 *          should be restricted and be done very carefully as they may have
 *          undesirable effects.
 *          NOTE: accelerators should not be used directly in production code.
 *
 *      timeout
 *          Timeout to use when waiting for the desired state. This is also for
 *          future expansion and not yet implemented.
 *
 * Possible status values returned are:
 *      NV_OK
 *      NV_ERR_TIMEOUT
 */
#define NVC370_CTRL_CMD_IDLE_CHANNEL                     (0xc3700101) /* finn: Evaluated from "(FINN_NVC370_DISPLAY_CHNCTL_INTERFACE_ID << 8) | NVC370_CTRL_IDLE_CHANNEL_PARAMS_MESSAGE_ID" */

#define NVC370_CTRL_IDLE_CHANNEL_MAX_INSTANCE_CORE       NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_CORE
#define NVC370_CTRL_IDLE_CHANNEL_MAX_INSTANCE_WINDOW     NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WINDOW
#define NVC370_CTRL_IDLE_CHANNEL_MAX_INSTANCE_WINDOW_IMM NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WINDOW_IMM
#define NVC370_CTRL_IDLE_CHANNEL_MAX_INSTANCE_WRITEBACK  NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WRITEBACK
#define NVC370_CTRL_IDLE_CHANNEL_MAX_INSTANCE_CURSOR     NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_CURSOR

#define NVC370_CTRL_IDLE_CHANNEL_STATE_IDLE                 NVC370_CTRL_CMD_CHANNEL_STATE_IDLE
#define NVC370_CTRL_IDLE_CHANNEL_STATE_QUIESCENT1           NVC370_CTRL_CMD_CHANNEL_STATE_QUIESCENT1
#define NVC370_CTRL_IDLE_CHANNEL_STATE_QUIESCENT2           NVC370_CTRL_CMD_CHANNEL_STATE_QUIESCENT2

#define NVC370_CTRL_IDLE_CHANNEL_STATE_BUSY                 NVC370_CTRL_CMD_CHANNEL_STATE_BUSY

#define NVC370_CTRL_IDLE_CHANNEL_ACCL_NONE               (0x00000000)
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_PI             (NVBIT(0))
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_SKIP_NOTIF            (NVBIT(1))
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_SKIP_SEMA             (NVBIT(2))
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_INTERLOCK      (NVBIT(3))
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_FLIPLOCK       (NVBIT(4))
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_TRASH_ONLY            (NVBIT(5))
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_TRASH_AND_ABORT       (NVBIT(6))
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_SKIP_SYNCPOINT        (NVBIT(7))
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_TIMESTAMP      (NVBIT(8))
#define NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_MGI            (NVBIT(9))

#define NVC370_CTRL_IDLE_CHANNEL_PARAMS_MESSAGE_ID (0x1U)

typedef struct NVC370_CTRL_IDLE_CHANNEL_PARAMS {
    NVC370_CTRL_CMD_BASE_PARAMS base;
    NvU32                       channelClass;
    NvU32                       channelInstance;
    NvU32                       desiredChannelStateMask;
    NvU32                       accelerators;        // For future expansion. Not yet implemented
    NvU32                       timeout;             // For future expansion. Not yet implemented
    NvBool                      restoreDebugMode;
} NVC370_CTRL_IDLE_CHANNEL_PARAMS;

/*
 * NVC370_CTRL_CMD_SET_ACCL
 *
 *   This command turns accelerators on and off. The use of this command
 *   should be restricted as it may have undesirable effects. It's
 *   purpose is to provide a mechanism for clients to use the
 *   accelerator bits to get into states that are either not detectable
 *   by the RM or may take longer to reach than we think is reasonable
 *   to wait in the RM.
 *
 * NVC370_CTRL_CMD_GET_ACCL
 *
 *   This command queries the current state of the accelerators.
 *
 *      channelClass
 *          This field indicates the hw class number (0xC378 - 0xC37E).
 *          It's defined in the h/w header (i.e. clc37d.h, etc.).
 *
 *      channelInstance
 *          This field indicates which instance of the channelClass the cmd is
 *          meant for. (zero-based)
 *
 *      accelerators
 *          Accelerators to be set in the SET_ACCEL command. Returns the
 *          currently set accelerators on the GET_ACCEL command.
 */


/*
 *
 *      accelMask
 *          A mask to specify which accelerators to change with the
 *          SET_ACCEL command. This field does nothing in the GET_ACCEL
 *          command.
 *
 * Possible status values returned are:
 *      NV_OK
 *      NV_ERR_INVALID_CHANNEL
 *      NV_ERR_INVALID_OWNER
 *      NV_ERR_GENERIC
 *
 */

#define NVC370_CTRL_CMD_SET_ACCL                 (0xc3700102) /* finn: Evaluated from "(FINN_NVC370_DISPLAY_CHNCTL_INTERFACE_ID << 8) | NVC370_CTRL_SET_ACCL_PARAMS_MESSAGE_ID" */

#define NVC370_CTRL_CMD_GET_ACCL                 (0xc3700103) /* finn: Evaluated from "(FINN_NVC370_DISPLAY_CHNCTL_INTERFACE_ID << 8) | 0x3" */

#define NVC370_CTRL_ACCL_MAX_INSTANCE_CORE       NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_CORE
#define NVC370_CTRL_ACCL_MAX_INSTANCE_WINDOW     NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WINDOW
#define NVC370_CTRL_ACCL_MAX_INSTANCE_WINDOW_IMM NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WINDOW_IMM
#define NVC370_CTRL_ACCL_MAX_INSTANCE_WRITEBACK  NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WRITEBACK
#define NVC370_CTRL_ACCL_MAX_INSTANCE_CURSOR     NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_CURSOR

#define NVC370_CTRL_ACCL_NONE                    NVC370_CTRL_IDLE_CHANNEL_ACCL_NONE
#define NVC370_CTRL_ACCL_IGNORE_PI                  NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_PI
#define NVC370_CTRL_ACCL_SKIP_NOTIF                 NVC370_CTRL_IDLE_CHANNEL_ACCL_SKIP_NOTIF
#define NVC370_CTRL_ACCL_SKIP_SEMA                  NVC370_CTRL_IDLE_CHANNEL_ACCL_SKIP_SEMA
#define NVC370_CTRL_ACCL_IGNORE_INTERLOCK           NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_INTERLOCK
#define NVC370_CTRL_ACCL_IGNORE_FLIPLOCK            NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_FLIPLOCK
#define NVC370_CTRL_ACCL_TRASH_ONLY                 NVC370_CTRL_IDLE_CHANNEL_ACCL_TRASH_ONLY
#define NVC370_CTRL_ACCL_TRASH_AND_ABORT            NVC370_CTRL_IDLE_CHANNEL_ACCL_TRASH_AND_ABORT
#define NVC370_CTRL_ACCL_SKIP_SYNCPOINT             NVC370_CTRL_IDLE_CHANNEL_ACCL_SKIP_SYNCPOINT
#define NVC370_CTRL_ACCL_IGNORE_TIMESTAMP           NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_TIMESTAMP
#define NVC370_CTRL_ACCL_IGNORE_MGI                 NVC370_CTRL_IDLE_CHANNEL_ACCL_IGNORE_MGI
#define NVC370_CTRL_SET_ACCL_PARAMS_MESSAGE_ID (0x2U)

typedef struct NVC370_CTRL_SET_ACCL_PARAMS {
    NVC370_CTRL_CMD_BASE_PARAMS base;
    NvU32                       channelClass;
    NvU32                       channelInstance;
    NvU32                       accelerators;
    NvU32                       accelMask;
} NVC370_CTRL_SET_ACCL_PARAMS;
typedef NVC370_CTRL_SET_ACCL_PARAMS NVC370_CTRL_GET_ACCL_PARAMS;

// FINN PORT: The below type was generated by the FINN port to
// ensure that all API's have a unique structure associated
// with them!
#define NVC370_CTRL_CMD_GET_ACCL_FINN_PARAMS_MESSAGE_ID (0x3U)

typedef struct NVC370_CTRL_CMD_GET_ACCL_FINN_PARAMS {
    NVC370_CTRL_GET_ACCL_PARAMS params;
} NVC370_CTRL_CMD_GET_ACCL_FINN_PARAMS;




/*
 * NVC370_CTRL_CMD_GET_CHANNEL_INFO
 *
 * This command returns the current channel state.
 *
 *      channelClass
 *          This field indicates the hw class number (0xC378 - 0xC37E).
 *          It's defined in the h/w header (i.e. clc37d.h, etc.).
 *
 *      channelInstance
 *          This field indicates which instance of the channelClass the cmd is
 *          meant for. (zero-based)
 *
 *      channelState
 *          This field indicates the desired channel state in a mask form that
 *          is compatible with NVC370_CTRL_CMD_IDLE_CHANNEL. A mask format
 *          allows clients to check for one from a group of states.
 *
 * Possible status values returned are:
 *      NV_OK
 *      NV_ERR_INVALID_ARGUMENT
 *      NV_ERR_GENERIC
 *
 * Display driver uses this call to ensure that all it's methods have
 * propagated through hardware's internal fifo
 * (NVC370_CTRL_GET_CHANNEL_INFO_STATE_NO_METHOD_PENDING) before it calls
 * RM to check whether or not the mode it set up in Assembly State Cache will
 * be possible. Note that display driver can not use completion notifier in
 * this case because completion notifier is associated with Update and Update
 * will propagate the state from Assembly to Armed and when checking the
 * possibility of a mode, display driver wouldn't want Armed state to be
 * affected.
 */



#define NVC370_CTRL_CMD_GET_CHANNEL_INFO                     (0xc3700104) /* finn: Evaluated from "(FINN_NVC370_DISPLAY_CHNCTL_INTERFACE_ID << 8) | NVC370_CTRL_CMD_GET_CHANNEL_INFO_PARAMS_MESSAGE_ID" */

#define NVC370_CTRL_GET_CHANNEL_INFO_MAX_INSTANCE_CORE       NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_CORE
#define NVC370_CTRL_GET_CHANNEL_INFO_MAX_INSTANCE_WINDOW     NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WINDOW
#define NVC370_CTRL_GET_CHANNEL_INFO_MAX_INSTANCE_WINDOW_IMM NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WINDOW_IMM
#define NVC370_CTRL_GET_CHANNEL_INFO_MAX_INSTANCE_WRITEBACK  NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_WRITEBACK
#define NVC370_CTRL_GET_CHANNEL_INFO_MAX_INSTANCE_CURSOR     NVC370_CTRL_CMD_MAX_CHANNEL_INSTANCE_CURSOR

#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_IDLE                 NVC370_CTRL_CMD_CHANNEL_STATE_IDLE
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_BUSY                 NVC370_CTRL_CMD_CHANNEL_STATE_BUSY
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_DEALLOC              NVC370_CTRL_CMD_CHANNEL_STATE_DEALLOC
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_DEALLOC_LIMBO        NVC370_CTRL_CMD_CHANNEL_STATE_DEALLOC_LIMBO
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_EFI_INIT1            NVC370_CTRL_CMD_CHANNEL_STATE_EFI_INIT1
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_EFI_INIT2            NVC370_CTRL_CMD_CHANNEL_STATE_EFI_INIT2
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_EFI_OPERATION        NVC370_CTRL_CMD_CHANNEL_STATE_EFI_OPERATION
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_VBIOS_INIT1          NVC370_CTRL_CMD_CHANNEL_STATE_VBIOS_INIT1
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_VBIOS_INIT2          NVC370_CTRL_CMD_CHANNEL_STATE_VBIOS_INIT2
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_VBIOS_OPERATION      NVC370_CTRL_CMD_CHANNEL_STATE_VBIOS_OPERATION
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_UNCONNECTED          NVC370_CTRL_CMD_CHANNEL_STATE_UNCONNECTED
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_INIT1                NVC370_CTRL_CMD_CHANNEL_STATE_INIT1
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_INIT2                NVC370_CTRL_CMD_CHANNEL_STATE_INIT2
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_SHUTDOWN1            NVC370_CTRL_CMD_CHANNEL_STATE_SHUTDOWN1
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_SHUTDOWN2            NVC370_CTRL_CMD_CHANNEL_STATE_SHUTDOWN2
#define NVC370_CTRL_GET_CHANNEL_INFO_STATE_NO_METHOD_PENDING    NVC370_CTRL_GET_CHANNEL_INFO_STATE_IDLE
#define NVC370_CTRL_CMD_GET_CHANNEL_INFO_PARAMS_MESSAGE_ID (0x4U)

typedef struct NVC370_CTRL_CMD_GET_CHANNEL_INFO_PARAMS {
    NVC370_CTRL_CMD_BASE_PARAMS base;
    NvU32                       channelClass;
    NvU32                       channelInstance;
    NvBool                      IsChannelInDebugMode;
    NvU32                       channelState;
} NVC370_CTRL_CMD_GET_CHANNEL_INFO_PARAMS;




#define NVC370_CTRL_CMD_GET_FORCE_MODESWITCH_FLAGS_OVERRIDES (0xc3700601) /* finn: Evaluated from "(FINN_NVC370_DISPLAY_VERIF_INTERFACE_ID << 8) | NVC370_CTRL_CMD_GET_FORCE_MODESWITCH_FLAGS_OVERRIDES_PARAMS_MESSAGE_ID" */

#define NVC370_CTRL_CMD_GET_FORCE_MODESWITCH_FLAGS_OVERRIDES_PARAMS_MESSAGE_ID (0x1U)

typedef struct NVC370_CTRL_CMD_GET_FORCE_MODESWITCH_FLAGS_OVERRIDES_PARAMS {
    NVC370_CTRL_CMD_BASE_PARAMS base;
    NvU32                       headInstance;
    NvU32                       modesetValue;
} NVC370_CTRL_CMD_GET_FORCE_MODESWITCH_FLAGS_OVERRIDES_PARAMS;

/*
 * NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_OVERRIDES
 *
 * This command sets modeswitch flags, prior to a modeset.  The flags will be
 * automatically cleared at the end of each modeset, so this function must be
 * called for each modeset where overrides are desired.
 *
 *      headInstance
 *          this field specifies the head for which modeswitch flags will be overridden
 *
 *      modesetMaskValid
 *          this field specifies the maskset at which modeswitch flags will be overridden
 *
 *      modesetValue
 *          this field specifies the override value
 *
 * Possible status values returned are:
 *      NV_OK
 *      NV_ERR_INVALID_ARGUMENT
 *
 */
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_OVERRIDES (0xc3700602) /* finn: Evaluated from "(FINN_NVC370_DISPLAY_VERIF_INTERFACE_ID << 8) | NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_OVERRIDES_PARAMS_MESSAGE_ID" */

#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_OVERRIDES_PARAMS_MESSAGE_ID (0x2U)

typedef struct NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_OVERRIDES_PARAMS {
    NVC370_CTRL_CMD_BASE_PARAMS base;
    NvU32                       headInstance;
    NvU32                       modesetMaskValid;
    NvU32                       modesetValue;
} NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_OVERRIDES_PARAMS;

#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_BLANK                       0:0
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_BLANK_VALID              0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_BLANK_INVALID            0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOBLANK                     1:1
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOBLANK_VALID            0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOBLANK_INVALID          0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_SHUTDOWN                    2:2
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_SHUTDOWN_VALID           0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_SHUTDOWN_INVALID         0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOSHUTDOWN                  3:3
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOSHUTDOWN_VALID         0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOSHUTDOWN_INVALID       0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_CHANGE_VPLL                 4:4
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_CHANGE_VPLL_VALID        0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_CHANGE_VPLL_INVALID      0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOCHANGE_VPLL               5:5
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOCHANGE_VPLL_VALID      0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOCHANGE_VPLL_INVALID    0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOBLANK_WAKEUP              6:6
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOBLANK_WAKEUP_VALID     0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOBLANK_WAKEUP_INVALID   0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOBLANK_SHUTDOWN            7:7
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOBLANK_SHUTDOWN_VALID   0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_MASK_VALID_FORCE_NOBLANK_SHUTDOWN_INVALID 0x00000000


#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_BLANK                            0:0
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_BLANK_YES                     0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_BLANK_NO                      0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOBLANK                          1:1
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOBLANK_YES                   0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOBLANK_NO                    0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_SHUTDOWN                         2:2
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_SHUTDOWN_YES                  0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_SHUTDOWN_NO                   0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOSHUTDOWN                       3:3
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOSHUTDOWN_YES                0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOSHUTDOWN_NO                 0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_CHANGE_VPLL                      4:4
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_CHANGE_VPLL_YES               0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_CHANGE_VPLL_NO                0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOCHANGE_VPLL                    5:5
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOCHANGE_VPLL_YES             0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOCHANGE_VPLL_NO              0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOBLANK_WAKEUP                   6:6
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOBLANK_WAKEUP_YES            0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOBLANK_WAKEUP_NO             0x00000000
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOBLANK_SHUTDOWN                 7:7
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOBLANK_SHUTDOWN_YES          0x00000001
#define NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_VALUE_FORCE_NOBLANK_SHUTDOWN_NO           0x00000000

/*
 * NVC370_CTRL_CMD_GET_LOCKPINS_CAPS
 *
 * This command returns lockpins for the specified pinset,
 * as well as lockpins' HW capabilities.
 *
 *   pinset [in]
 *     This parameter takes the pinset whose corresponding 
 *     lockpin numbers need to be determined. This only affects
 *     the return value for the RaterLock and FlipLock pins.
 *
 *   frameLockPin [out]
 *     This parameter returns the FrameLock pin index.
 *
 *   rasterLockPin [out]
 *     This parameter returns the RasterLock pin index.
 *    
 *   flipLockPin [out]
 *     This parameter returns the FlipLock pin index.
 *
 *   stereoPin [out]
 *     This parameter returns the Stereo pin index.
 *
 *   numScanLockPins [out]
 *     This parameter returns the HW capability of ScanLock pins.
 *
 *   numFlipLockPins [out]
 *     This parameter returns the HW capability of FlipLock pins.
 *
 *   numStereoPins [out]
 *     This parameter returns the HW capability of Stereo pins.
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_PARAM_STRUCT
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_NOT_SUPPORTED   
 */



#include "ctrlc370/ctrlc370event.h"


#define NVC370_CTRL_CMD_GET_LOCKPINS_CAPS                  (0xc3700201) /* finn: Evaluated from "(FINN_NVC370_DISPLAY_RG_INTERFACE_ID << 8) | NVC370_CTRL_GET_LOCKPINS_CAPS_PARAMS_MESSAGE_ID" */

#define NVC370_CTRL_GET_LOCKPINS_CAPS_FRAME_LOCK_PIN_NONE  (0xffffffff)
#define NVC370_CTRL_GET_LOCKPINS_CAPS_RASTER_LOCK_PIN_NONE (0xffffffff)
#define NVC370_CTRL_GET_LOCKPINS_CAPS_FLIP_LOCK_PIN_NONE   (0xffffffff)
#define NVC370_CTRL_GET_LOCKPINS_CAPS_STEREO_PIN_NONE      (0xffffffff)
#define NVC370_CTRL_GET_LOCKPINS_CAPS_PARAMS_MESSAGE_ID (0x1U)

typedef struct NVC370_CTRL_GET_LOCKPINS_CAPS_PARAMS {
    NVC370_CTRL_CMD_BASE_PARAMS base;
    NvU32                       pinset;
    NvU32                       frameLockPin;
    NvU32                       rasterLockPin;
    NvU32                       flipLockPin;
    NvU32                       stereoPin;
    NvU32                       numScanLockPins;
    NvU32                       numFlipLockPins;
    NvU32                       numStereoPins;
} NVC370_CTRL_GET_LOCKPINS_CAPS_PARAMS;

/*
 * NVC370_CTRL_CMD_SET_SWAPRDY_GPIO_WAR
 *
 * This command switches SWAP_READY_OUT GPIO between SW
 * and HW control to WAR bug 200374184
 *
 *   bEnable [in]:
 *     This parameter indicates enable/disable external fliplock
 *
 * Possible status values returned are:
 *   NV_OK
 *   NV_ERR_INVALID_ARGUMENT
 *   NV_ERR_GENERIC
 */

#define NVC370_CTRL_CMD_SET_SWAPRDY_GPIO_WAR (0xc3700202) /* finn: Evaluated from "(FINN_NVC370_DISPLAY_RG_INTERFACE_ID << 8) | NVC370_CTRL_SET_SWAPRDY_GPIO_WAR_PARAMS_MESSAGE_ID" */

#define NVC370_CTRL_SET_SWAPRDY_GPIO_WAR_PARAMS_MESSAGE_ID (0x2U)

typedef struct NVC370_CTRL_SET_SWAPRDY_GPIO_WAR_PARAMS {
    NVC370_CTRL_CMD_BASE_PARAMS base;
    NvBool                      bEnable;
} NVC370_CTRL_SET_SWAPRDY_GPIO_WAR_PARAMS;

/* _ctrlc370_h__ */
