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
#include "app_mem_mgr.h"
#include "oal_memory_allocator.h"
#include "debug_tools.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
rsdkStatus_t AppMemInit(rsdkAppMemMgr_t heapMem, uint8_t* heapBuffer, int32_t heapSize)
{
    //nothing to do here when we have OAL support
    return RSDK_SUCCESS;
}

rsdkStatus_t AppMemAllocBuffer(rsdkAppMemMgr_t heapMem, rsdkBufHandle_t *bufH, uint32_t numBytes, uint32_t alignBytes, uint8_t chunkId)
{
    rsdkStatus_t    retval = RSDK_SUCCESS;
    OAL_MEMORY_FLAG memFlags = OAL_MEMORY_FLAG_CONTIGUOUS | ((chunkId + 1) << 24) | OAL_MEMORY_FLAG_ALIGN(alignBytes);

    bufH->numBytes = numBytes;
    bufH->oalMemHandle = OAL_AllocMemory(bufH->numBytes, memFlags);
	if(gDebugLogEn)
    {
		DbgPrintMsg("oalMemHandle = %lx\n", (uintptr_t)bufH->oalMemHandle);
	}
	
    bufH->phyAddr = (int8_t *)OAL_GetReturnAddress(bufH->oalMemHandle, OAL_ACCESS_PHY);
    //All buffers are allocated as "non-cacheable" by default, since the ARM core does not process the data,
    //but only passes the pointers to SPT, BBE32, LAX etc. 
	//The cache policy could be passed as a parameter through the function interface, if needed.
    bufH->virtAddr = (int8_t *)OAL_GetReturnAddress(bufH->oalMemHandle, OAL_ACCESS_NCH_B);

    if ((bufH->phyAddr == NULL) || (bufH->virtAddr == NULL))
    {
        retval = RSDK_HEAP_MEM_ALLOC_ERROR;
		DbgPrintMsg("AppMemAllocBuffer: failed to alloc %d bytes.  \n", bufH->numBytes);
        HALT_HERE;
    }
    else
    {
		if(gDebugLogEn)
        {
			DbgPrintMsg("AppMemAllocBuffer: allocated %d bytes at phyAddr=0x%lX virtAddr=0x%lX \n", bufH->numBytes, (uintptr_t)bufH->phyAddr, (uintptr_t)bufH->virtAddr);
		}
	}

    //callNo++;
    return retval;
}

rsdkStatus_t AppMemFreeBuffer(rsdkAppMemMgr_t heapMem, rsdkBufHandle_t *bufH)
{
    rsdkStatus_t retval = RSDK_SUCCESS;

    if (OAL_FreeMemory(bufH->oalMemHandle) != OAL_SUCCESS)
    {
		if(gDebugLogEn)
		{
			DbgPrintMsg("AppMemFreeBuffer error: Memory free failed! \n");
		}
        retval = RSDK_HEAP_MEM_FREE_ERROR;
    }
    else
    {
		if(gDebugLogEn)
		{
			DbgPrintMsg("AppMemFreeBuffer: freeing memory phyAddr=0x%lX virtAddr=0x%lX \n", (uintptr_t)bufH->phyAddr, (uintptr_t)bufH->virtAddr);
		}
    }

    return retval;
}

#ifdef __cplusplus
}
#endif

#endif //USING_PLATFORM_SDK
