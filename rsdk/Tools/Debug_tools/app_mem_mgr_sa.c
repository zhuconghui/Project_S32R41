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

#ifndef USING_PLATFORM_SDK
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdio.h>
#include "app_mem_mgr.h"
#include "rsdk_heap.h"
#include "debug_tools.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/* ==========================================================
   Heap memory initialization
   Input  : heap handler pointer, heap memory pointer, heap size
   ========================================================== */
rsdkStatus_t AppMemInit(rsdkAppMemMgr_t heapMem, uint8_t *heapBuffer, int32_t heapSize)
{
    return rsdkHeapInit(heapMem, heapBuffer, heapSize);
}

/* ==========================================================
   Allocate from heap the application necessary data buffers
   Input  : heap handler pointer, allocated memory handler, buffer length, alignment, memory space allocation
   ========================================================== */
rsdkStatus_t AppMemAllocBuffer(rsdkAppMemMgr_t heapMem, rsdkBufHandle_t *bufH, uint32_t numBytes, uint32_t alignBytes,
                               uint8_t chunkId)
{
    rsdkStatus_t retval = RSDK_SUCCESS;

    /* alignBytes and chunkId are not used in stand-alone implementation */

    bufH->numBytes = numBytes;
    bufH->oalMemHandle = NULL;  /* only used by OAL */

    retval = rsdkHeapAlloc(heapMem, numBytes, (void *)&bufH->phyAddr);

    bufH->virtAddr = bufH->phyAddr;

    if ((bufH->phyAddr == NULL) || (retval != RSDK_SUCCESS))
    {
        sprintf(gDbgMsg, "AppMemAllocBuffer: failed to alloc %lu bytes.  \n", (long)bufH->numBytes);
        DbgPrintMsg(gDbgMsg);
        HALT_HERE;
    }
    else
    {
        if (gDebugLogEn)
        {
			sprintf(gDbgMsg, "AppMemAllocBuffer: allocated %lu bytes at phyAddr=0x%lX virtAddr=0x%lX \n",
                    (long)bufH->numBytes, (long)bufH->phyAddr, (long)bufH->virtAddr);

            DbgPrintMsg(gDbgMsg);
        }
    }

    return retval;
}

/* ==========================================================
   Free allocated memory from heap
   Input  : heap handler pointer, allocated memory handler
   ========================================================== */
rsdkStatus_t AppMemFreeBuffer(rsdkAppMemMgr_t heapMem, rsdkBufHandle_t *bufH)
{
    rsdkStatus_t retval = RSDK_SUCCESS;

    retval = rsdkHeapFreeLast(heapMem, bufH->numBytes, bufH->phyAddr);

    if (retval != RSDK_SUCCESS)
    {
        if (gDebugLogEn)
        {
            sprintf(gDbgMsg, "AppMemFreeBuffer error: Memory free failed! Status = 0x%X.\n", retval);
            DbgPrintMsg(gDbgMsg);
        }
    }
    else
    {
        if (gDebugLogEn)
        {
            sprintf(gDbgMsg, "AppMemFreeBuffer: freeing memory phyAddr=0x%p virtAddr=0x%p \n", bufH->phyAddr,
                    bufH->virtAddr);
            DbgPrintMsg(gDbgMsg);
        }
    }

    return retval;
}

#ifdef __cplusplus
}
#endif

#endif  /* USING_PLATFORM_SDK */
