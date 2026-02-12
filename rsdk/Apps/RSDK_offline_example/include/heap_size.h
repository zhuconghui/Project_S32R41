/**************************************************************************************************
 * 
 * NXP Confidential Proprietary
 *
 * Copyright 2020-2021 NXP
 * All Rights Reserved
 *
 *****************************************************************************
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in accordance with the
 * applicable license terms.  By expressly accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to comply with and are bound by, such
 * license terms.  If you do not agree to be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 *
 **************************************************************************************************/
#ifndef HEAP_SIZE_H
#define HEAP_SIZE_H

/**
* @file           heap_size.h
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_heap.h"
#include "app_mem_mgr.h"

/*==================================================================================================
*                                      MACROS
==================================================================================================*/

#define HEAP_BUFF_SIZE (1024*1024)






/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern rsdk_heap_t heapMem;
extern uint8_t     heapBuffer[HEAP_BUFF_SIZE];

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  //HEAP_SIZE_H
