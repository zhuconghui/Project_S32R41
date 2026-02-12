/*
 * Copyright 2019-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef CTE_DRIVER_PLATFORM_TRACE_H
#define CTE_DRIVER_PLATFORM_TRACE_H

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include "trace.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          CONSTANTS
 ==================================================================================================*/

/*==================================================================================================
 *                                      DEFINES AND MACROS
 ==================================================================================================*/
#define CTE_SEQ_BEGIN   0   // marker for sequence beginning
#define CTE_SEQ_END     1   // marker for sequence end

/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/
//
// Enumerated elements for debug trace of CTE driver functions.
//
typedef enum
{
    // markers for initialization phase
    RSDK_TRACE_DBG_CTE_INIT  // full initialization function
    = RSDK_TRACE_JOB_CTE_BASE,
    RSDK_TRACE_DBG_CTE_STOP,                // RxStop function
    RSDK_TRACE_DBG_CTE_START,               // RxStart function
    RSDK_TRACE_DBG_CTE_RESTART,             // PowerOff function
    RSDK_TRACE_DBG_CTE_RFS_GENERATE,        // PowerOn function
    RSDK_TRACE_DBG_CTE_UPDATE_TABLES,       // GetLaneStatus function
    RSDK_TRACE_DBG_CTE_GET_LUT_CHECKSUM,    // GetInterfaceStatus function

    RSDK_TRACE_DBG_CTE_LAST_EVT
} rsdkTraceDebugCte_t;

/*==================================================================================================
 *                                STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/

/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
 ==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*CTE_DRIVER_PLATFORM_TRACE_H*/
