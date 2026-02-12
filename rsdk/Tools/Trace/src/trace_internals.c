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

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#if defined(TRACE_KERNEL)
#include <linux/string.h>
#else
#include <string.h>
#include <stdint.h>
#endif

#include "trace.h"
#include "trace_internals.h"
#include "timer_platform.h"
#include "trace_internal_api.h"
#if defined (__XTENSA__)
#include <xtensa/hal.h>
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
static int gsFirst;  /* Used to avoid confusion between 0 as first index or wraparound index */

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          Rotate log records ring buffer by current index
* @details        This function will rotate the log records ring buffer by current index.
*                 Is used only when you dump the trace log in order to have log data in chronological
*                 order if circular buffer rotates.
*
* @param[inout]   traceRecord_t structure that holds buffer to be rotated.
*/
void RotateBuff(traceRecord_t *pTraceRecord)
{
    // Check if circular buffer was rotated
    if (pTraceRecord->wrapFlag != 0)
    {
        int shift = IndexRead(&pTraceRecord->traceBufferIndex, pTraceRecord->traceBufferSize);

        while (shift > 0)
        {
            logRecord_t tmp;
            int         i;
#if defined (__XTENSA__)
            xthal_dcache_block_invalidate(&pTraceRecord->pTraceBuffer[0], sizeof(logRecord_t));
#endif
            memcpy(&tmp, &pTraceRecord->pTraceBuffer[0], sizeof(logRecord_t));
            for (i = 0; i < (pTraceRecord->traceBufferSize - 1); i++)
            {
#if defined (__XTENSA__)
            xthal_dcache_block_invalidate(&pTraceRecord->pTraceBuffer[i + 1], sizeof(logRecord_t));
#endif
                pTraceRecord->pTraceBuffer[i] = pTraceRecord->pTraceBuffer[i + 1];
#if defined (__XTENSA__)
            xthal_dcache_block_writeback(&pTraceRecord->pTraceBuffer[i], sizeof(logRecord_t));
#endif
            }
            memcpy(&pTraceRecord->pTraceBuffer[i], &tmp, sizeof(logRecord_t));
#if defined (__XTENSA__)
            xthal_dcache_block_writeback(&pTraceRecord->pTraceBuffer[i], sizeof(logRecord_t));
#endif
            shift--;
        }
        IndexWrite(&pTraceRecord->traceBufferIndex, pTraceRecord->traceBufferSize);
        pTraceRecord->wrapFlag = 0;
    }
}

/**
* @brief          Go to next log record
* @details        This function will update indexes and state variables for ring buffer.
*
* @param[inout]   traceRecord_t structure that holds buffer to be moved to next record.
*/
int NextRecord(traceRecord_t *pTraceRecord)
{
    int index = IndexReadIncrement(&pTraceRecord->traceBufferIndex, pTraceRecord->traceBufferSize);  //atomic operation

    /* Flag the need for rotating the buffer */
    if (index == 0 && gsFirst == 1)
    {
        gsFirst = 0;
    }
    else if (index == 0)
    {
        pTraceRecord->wrapFlag = 1;
    }

    return index;
}

/**
* @brief          Init trace record (go to first)
* @details        This function will initialize indexes, state variables and the ring buffer.
*
* @param[inout]   traceRecord_t structure to be initialized
*/
void InitRecord(traceRecord_t *pTraceRecord, char *pTraceBuffer, uint16_t buffSize, int traceEnable)
{
    (void)memset(pTraceBuffer, 0, buffSize);
    pTraceRecord->pTraceBuffer = (logRecord_t *)pTraceBuffer;
    pTraceRecord->traceBufferSize = buffSize / sizeof(logRecord_t);
    pTraceRecord->wrapFlag = 0;
#if defined (__XTENSA__)
    xthal_dcache_block_writeback(&pTraceBuffer, sizeof(buffSize));
#endif
    IndexWrite(&pTraceRecord->traceBufferIndex, 0);
    TraceAtomicValueSet(&pTraceRecord->enable, traceEnable);
    gsFirst = 1;
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
