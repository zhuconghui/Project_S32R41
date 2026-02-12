/*
 * Copyright 2017-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef RSDK_HEAP_H
#define RSDK_HEAP_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/
#include "rsdk_status.h"
#if defined(RSDK_AUTOSAR)
#include "Std_Types.h"
#else
#include "typedefs.h"
#endif
#include "cache.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define HEAP_ALIGN (CACHE_LINE_SIZE) /*preference to cache line alignment*/
#define HEAP_WATERMARK (0xC0FFEEBA)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct
{
    void *  baseAdd;
    void *  topAdd;
    int32_t buffSize;
} rsdk_heap_t;

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

rsdkStatus_t rsdkHeapInit(rsdk_heap_t *heap, void *base, int32_t size);

rsdkStatus_t rsdkHeapMark(rsdk_heap_t *heap, uint32_t watermark);

rsdkStatus_t rsdkHeapMeasure(rsdk_heap_t *heap, uint32_t watermark, uint32_t *usedHeap);

rsdkStatus_t rsdkHeapAlloc(rsdk_heap_t *heap, int32_t size, void **buffer);

rsdkStatus_t rsdkHeapFreeLast(rsdk_heap_t *heap, int32_t size, void *buffer);

rsdkStatus_t rsdkHeapClear(rsdk_heap_t *heap);

#ifdef __cplusplus
}
#endif

#endif /*RSDK_HEAP_H*/
