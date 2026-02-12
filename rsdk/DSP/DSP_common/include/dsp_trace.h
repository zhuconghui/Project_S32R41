/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef DSP_TRACE_H
#define DSP_TRACE_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#if ((defined TRACE_ENABLE) && !defined(S32R45))
#include "trace.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#if ((defined TRACE_ENABLE) && !defined(S32R45))
/* Enums used to add info about specific RSDK components and functions in _FUNC_START, _FUNC_END and Debug events: */
typedef enum
{
    RSDK_TRACE_JOB_DSP_FIRST = RSDK_TRACE_JOB_DSP_BASE,

    RSDK_TRACE_JOB_DSP_LAST
} dispatcherTraceJobType_t;

typedef enum
{
    RSDK_TRACE_DBG_DSP_P1_ITER = RSDK_TRACE_DBG_DSP_BASE,
    RSDK_TRACE_DBG_DSP_P2_ITER,
    RSDK_TRACE_DBG_DSP_P3_ITER,
    RSDK_TRACE_DBG_DSP_P4_ITER,
    RSDK_TRACE_DBG_DSP_P5_ITER,
    RSDK_TRACE_DBG_DSP_P6_ITER,
    
    RSDK_TRACE_DBG_DSP_P1_JOB_LIST_UPDATE,
    RSDK_TRACE_DBG_DSP_P4_JOB_LIST_UPDATE,
    RSDK_TRACE_DBG_DSP_P5_JOB_LIST_UPDATE,
    
    RSDK_TRACE_DBG_DSP_REALTIME_CONFIG_UPDATE,
    
    
    RSDK_TRACE_DBG_DSP_RFS_ISR,
    RSDK_TRACE_DBG_DSP_RCS_ISR,
    RSDK_TRACE_DBG_DSP_SPT_ISR,
    RSDK_TRACE_DBG_DSP_CPU_ISR,
    
    RSDK_TRACE_DBG_DISPATCHER_INIT,
    RSDK_TRACE_DBG_DISPATCHER_RUN,
    
    RSDK_TRACE_DBG_DSP_ERR,

    RSDK_TRACE_DBG_DSP_LAST
} dispatcherTraceDbgType_t;
#else
#define RsdkTraceLogEvent(event, extra1, extra2)
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

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

#endif /*DSP_TRACE_H*/
