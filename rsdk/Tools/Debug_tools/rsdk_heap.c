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

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/

#include <stdio.h>
#include "rsdk_heap.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                           FUNCTIONS
==================================================================================================*/

/* Initialize the heap memory
   Input  : memory heap handler pointer, memory start address, memory size
   Return : 0 = success, else a wrong parameter */
rsdkStatus_t rsdkHeapInit(rsdk_heap_t *heap, void *base, int32_t size)
{
    rsdkStatus_t retval = RSDK_ERROR;

    if ((heap == NULL) || (base == NULL) || (size < 0) || ((uintptr_t)base & (HEAP_ALIGN - 1)))
    {
        retval = RSDK_INVALID_PARAMETER;
    }
    else
    {
        heap->baseAdd = base;
        heap->topAdd = heap->baseAdd;
        heap->buffSize = size;

        retval = RSDK_SUCCESS;
    }

    return retval;
}

/*====================================================
  Initialize the heap memory with a uint32_t watermark
  Input  : memory heap handler, watermark
  Return : 0 = success, else a wrong parameter
  =================================================== */
rsdkStatus_t rsdkHeapMark(rsdk_heap_t *heap, uint32_t watermark)
{
    uint32_t   i;
    uint32_t *p;

    rsdkStatus_t retval = RSDK_ERROR;

    if (heap == NULL)
    {
        retval = RSDK_INVALID_PARAMETER;
    }
    else
    {
        p = (uint32_t *)heap->baseAdd;
        for (i = 0; i < (heap->buffSize / sizeof(watermark)); i++)
        {
            p[i] = watermark;
        }
        retval = RSDK_SUCCESS;
    }

    return retval;
}

/*====================================================
  Count the unused heap memory
  Check the memory amount to still have the watermark value.
  Input  : memory heap handler, watermark, counted value pointer
  Return : 0 = success, else a wrong parameter
  ==================================================== */
rsdkStatus_t rsdkHeapMeasure(rsdk_heap_t *heap, uint32_t watermark, uint32_t *usedHeap)
{
    int32_t   i, meas;
    uint32_t *p;

    rsdkStatus_t retval = RSDK_ERROR;

    if ((heap == NULL) || (heap->baseAdd == NULL) || (usedHeap == NULL))
    {
        retval = RSDK_INVALID_PARAMETER;
    }
    else
    {
        i = (int32_t)(heap->buffSize / sizeof(watermark) - 1);
        p = (uint32_t *)(heap->baseAdd);

        while ((i >= 0) && (p[i] == watermark))
        {
            i--;
        }

        meas = i * sizeof(watermark);
        *usedHeap = meas;

        retval = RSDK_SUCCESS;
    }

    return retval;
}

/*====================================================
  Allocate memory from heap
  The allocation mechanism is like a variable stack.
  So, for correct memory management, the last allocated memory must be first  deallocated.
  Input  : memory heap handler, memory size, pointer to returned heap pointer
   Return : 0 = success, else a wrong parameter
  ==================================================== */
rsdkStatus_t rsdkHeapAlloc(rsdk_heap_t *heap, int32_t size, void **buffer)
{
    int32_t allocSize, sizeLeft;

    rsdkStatus_t retval = RSDK_ERROR;

    if ((heap == NULL) || (heap->baseAdd == NULL) || (heap->topAdd == NULL) || (buffer == NULL) || (size < 0))
    {
        retval = RSDK_INVALID_PARAMETER;
    }
    else
    {
        allocSize = ((size - 1) / HEAP_ALIGN + 1) * HEAP_ALIGN;
        sizeLeft = (heap->buffSize - (int32_t)((char *)heap->topAdd - (char *)heap->baseAdd));

        if (allocSize > sizeLeft)
        {
            retval = RSDK_HEAP_MEM_ALLOC_ERROR;
        }
        else
        {
            *buffer = heap->topAdd;
            heap->topAdd = (void *)((uintptr_t)heap->topAdd + allocSize);

            retval = RSDK_SUCCESS;
        }
    }

    return retval;
}

/*====================================================
  Deallocate memory from heap
  The allocation mechanism is like a variable stack.
  So, for correct memory management, the last allocated memory must be first  deallocated.
  Input  : memory heap handler, memory size, heap memory pointer to free
  Return : 0 = success, else a wrong parameter or not the last allocated memory to free
  ==================================================== */
rsdkStatus_t rsdkHeapFreeLast(rsdk_heap_t *heap, int32_t size, void *buffer)
{
    int32_t freeSize;
    void *  p;

    rsdkStatus_t retval = RSDK_ERROR;

    if ((heap == NULL) || (heap->baseAdd == NULL) || (heap->topAdd == NULL) || (buffer == NULL) || (size < 0))
    {
        retval = RSDK_INVALID_PARAMETER;
    }
    else
    {
        freeSize = ((size - 1) / HEAP_ALIGN + 1) * HEAP_ALIGN;

        p = (void *)((uintptr_t)buffer + freeSize);
        if (p != heap->topAdd)
        {
            retval = RSDK_HEAP_MEM_FREE_ERROR;
        }
        else
        {
            heap->topAdd = buffer;

            retval = RSDK_SUCCESS;
        }
    }

    return retval;
}

/*====================================================
  Free the entire heap
  Input  : memory heap handler
  Return : 0 = success, else a wrong parameter
  ====================================================*/
rsdkStatus_t rsdkHeapClear(rsdk_heap_t *heap)
{
    rsdkStatus_t retval;

    if ((heap == NULL) || (heap->baseAdd == NULL))
    {
        retval = RSDK_INVALID_PARAMETER;
    }
    else
    {
        heap->topAdd = heap->baseAdd;

        retval = RSDK_SUCCESS;
    }

    return retval;
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
