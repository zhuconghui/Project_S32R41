/*
 * Copyright 2016,2018-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef APP_MEM_MGR_H
#define APP_MEM_MGR_H

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#if defined(RSDK_AUTOSAR)
#include "Std_Types.h"
#else
#include "typedefs.h"
#endif
#include "rsdk_status.h"
#include "compiler_api.h"
#if (RSDK_OSENV_SA)
#include "rsdk_heap.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
The id of the OAL memory chunk for allocated data buffers.
This must be equal to the oalmem id definition in device tree.
Not used by stand-alone implementation.
*/

#define RSDK_OALMEM_CHUNK_ID_DDR (0)
#define RSDK_OALMEM_CHUNK_ID_SRAM (1)
#define RSDK_OALMEM_CHUNK_ID_TCM_BBE32 (2)

#if (defined SPT_BUFFERS_IN_DDR) && (SPT_BUFFERS_IN_DDR == 0)
#define RSDK_OALMEM_CHUNK_ID_SPT_DATA RSDK_OALMEM_CHUNK_ID_SRAM
#else
#define RSDK_OALMEM_CHUNK_ID_SPT_DATA RSDK_OALMEM_CHUNK_ID_DDR
#endif

/*==================================================================================================
*                          				GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                          TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#if (RSDK_OSENV_SA)
typedef rsdk_heap_t *rsdkAppMemMgr_t;
#else
typedef void *rsdkAppMemMgr_t;
#endif

typedef struct
{
    void *   oalMemHandle;
    int8_t * phyAddr;
    int8_t * virtAddr;
    uint32_t numBytes;
} rsdkBufHandle_t;

rsdkStatus_t AppMemInit(rsdkAppMemMgr_t heapMem, uint8_t *heapBuffer, int32_t heapSize);
rsdkStatus_t AppMemAllocBuffer(rsdkAppMemMgr_t heapMem, rsdkBufHandle_t *bufH, uint32_t numBytes, uint32_t alignBytes,
                               uint8_t chunkId);
rsdkStatus_t AppMemFreeBuffer(rsdkAppMemMgr_t heapMem, rsdkBufHandle_t *bufH);

#ifdef __cplusplus
}
#endif

#endif  /* APP_MEM_MGR_H */
