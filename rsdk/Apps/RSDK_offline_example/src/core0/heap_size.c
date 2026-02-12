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

/**
* @file           heap_size.c
* Description:    SPT Example heap size (stand-alone)
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "heap_size.h"

#ifdef __cplusplus
extern "C" {
#endif

// heap memory buffer definition

uint8_t heapBuffer[HEAP_BUFF_SIZE] __attribute__((section(".radar"))) __attribute__((aligned(CACHE_LINE_SIZE)));




#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
