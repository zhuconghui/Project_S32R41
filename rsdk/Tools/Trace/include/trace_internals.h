/**************************************************************************************************
 * 
 * Copyright 2020-2021 NXP 
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 **************************************************************************************************/

#ifndef TRACE_INTERNALS_H
#define TRACE_INTERNALS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "trace.h"
#include "timer_platform.h"
#include "trace_internal_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define TRACE_GET_BUF_SIZE 1 /* Linux only, used for ioctl call to get kernel trace buffer size*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Structure holding all trace related information.
*/
typedef struct
{
    logRecord_t * pTraceBuffer;     /**< Circular buffer used to store log records. */
    uint16_t      traceBufferSize;  /**< Available number of logRecord_t entries in the circular buffer. */
    traceAtomic_t enable;           /**< Flag to indicate that the trace is enabled, 0 - disabled, 1 - enabled */
    traceAtomic_t traceBufferIndex; /**< Index of first empty entry of the circular buffer. */
    uint8_t       wrapFlag; /**< Used to arrange buffer correctly if more than traceBufferSize events were traced. */
} traceRecord_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief          Rotates a trace buffer in order to arrange the entries in chronological order.
*                 It is needed only if the number of events captured excedes the size of the buffer.
*
* @param[inout]   pTraceRecord - Trace record holding the buffer to be rotated.
*/
void RotateBuff(traceRecord_t *pTraceRecord);

/**
* @brief          Initializes a trace record using the given parameters.
*
* @param[out]     pTraceRecord - Trace record that will be used for trace.
* @param[in]      pTraceBuffer - Previously allocated buffer to be used for trace.
* @param[in]      buffSize - Trace buffer size.
* @param[in]      traceEnable - Option to init with trace enabled(1) or disabled(0).
*/
void InitRecord(traceRecord_t *pTraceRecord, char *pTraceBuffer, uint16_t buffSize, int traceEnable);

/**
* @brief          Increments the index in buffer and checks for overflow.
*
* @param[inout]   pTraceRecord - Trace record holding the buffer to be moved to next empty entry.
*
* @return         Old index in buffer (the value before increment).
*/
int NextRecord(traceRecord_t *pTraceRecord);

#ifdef __cplusplus
}
#endif

#endif /*TRACE_INTERNALS_H*/

/** @} */
