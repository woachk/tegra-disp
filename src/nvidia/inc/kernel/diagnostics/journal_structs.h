/* _NVRM_COPYRIGHT_BEGIN_
 *
 * Copyright 1993-2021 by NVIDIA Corporation.  All rights reserved.  All
 * information contained herein is proprietary and confidential to NVIDIA
 * Corporation.  Any use, reproduction, or disclosure without the written
 * permission of NVIDIA Corporation is prohibited.
 *
 * _NVRM_COPYRIGHT_END_
 */

#ifndef JOURNAL_STRUCTS_H
#define JOURNAL_STRUCTS_H 1

#include "nvcd.h"
#include "rmcd.h"

// Meta Data to Describe an error block
typedef struct RMCD_ERROR_BLOCK {
    NvU8 * pBlock;
    NvU32 blockSize;
    struct RMCD_ERROR_BLOCK * pNext;
} RMCD_ERROR_BLOCK;

typedef struct RMERRORHEADER {
    struct RMFIFOERRORELEMENT_V3 *pNextError;
    RMCD_ERROR_BLOCK *pErrorBlock;
    NvU32 GPUTag;
    NvU32 ErrorNumber;
} RMERRORHEADER;

typedef struct {
    RMERRORHEADER ErrorHeader;
    RmPrbInfo_RECORD_V2 RmPrbErrorData;
} RMPRBERRORELEMENT_V2;

typedef struct RMFIFOERRORELEMENT_V3 {
    RMERRORHEADER ErrorHeader;
    RmFifoErrorInfo_RECORD_V4 RmFifoErrorData;
} RMFIFOERRORELEMENT_V3;

#endif /* ifndef JOURNAL_STRUCTS_H */
