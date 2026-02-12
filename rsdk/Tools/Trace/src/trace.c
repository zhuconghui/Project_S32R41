/*
 * Copyright 2017-2018,2020-2021,2023 NXP
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
*                                        INCLUDE FILES
==================================================================================================*/
#if defined(TRACE_KERNEL)
#include <linux/types.h>
#include <linux/string.h>
#include <linux/module.h>
#else
#include <stdint.h>
#include <string.h>
#endif

#include "trace.h"
#include "trace_internals.h"
#include "trace_internal_api.h"
#include "timer_platform.h"
#ifdef __LAX__
#include "lax_lib_functions.h"
#endif
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
#if defined(__LAX__)
static logRecord_t _VECTOR_ALIGN gsRBufLogData[NUM_LOG_DATA];
unsigned int gsRemoteBufferAddr;
#endif

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
traceRecord_t gTraceRecord = {      /* Variable that holds all trace related information. */
    .pTraceBuffer = NULL,
    .traceBufferSize = 0,
    .wrapFlag = 0,
};

#if defined(__LAX__)
extern unsigned int gLaxArgs[];
#endif

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
* @brief          Initialize trace system
* @details        This function will check & initialize the variables needed to log information.
*                 It will also configure a platform specific timer and set its counter to 0.
*
* @note           This should be called only ONCE per application. This means that if the application is
*                 multithreaded RsdkTraceInit must be called before other threads have been created.
*/
rsdkStatus_t RsdkTraceInit(char *pTraceBuffer, uint16_t buffSize)
{
#ifndef __LAX__
    if ((pTraceBuffer == NULL) || (buffSize <= 0) || ((buffSize % sizeof(logRecord_t)) != 0))
    {
        return RSDK_SPT_RET_ERR_INVALID_PARAM;
    }

    /* Initialize trace record structure */
    InitRecord(&gTraceRecord, pTraceBuffer, buffSize, 1);
#else
    InitRecord(&gTraceRecord, (char *)gsRBufLogData, NUM_LOG_DATA * sizeof(logRecord_t), 0);
#endif

#ifndef TRACE_KERNEL
    /* Initialize platform dependent timer */
    TimerInit();
#endif

    return RSDK_SUCCESS;
}
#if defined(TRACE_KERNEL)
EXPORT_SYMBOL(RsdkTraceInit);
#endif

/**
* @brief          Log event
* @details        This function will record a new event.
*
* @pre            RsdkTraceInit() must be called beforehand.
*/
void RsdkTraceLogEvent(rsdkTraceEventType_t eventType, uint16_t extra1, uint32_t extra2)
{
    int enable;

    enable = TraceAtomicValueGet(&gTraceRecord.enable);

    if ((enable == 1) && (gTraceRecord.traceBufferSize != 0))
    {
        uint32_t     timestamp;
        uint16_t     index;
        logRecord_t *buffer;

        /* Get timestamp of event */
        timestamp = TimerRead();

        /* Get corresponding index in buffer and increment it atomically */
        index = (uint16_t)(NextRecord(&gTraceRecord));

        /* Get pointer to buffer */
        buffer = gTraceRecord.pTraceBuffer;

        /* Write needed information in buffer */
        buffer[index].timestamp = timestamp;
        buffer[index].coreID = CoreIdRead();
        buffer[index].eventType = (uint8_t)eventType;
        buffer[index].extraInfo1 = extra1;
        buffer[index].extraInfo2 = extra2;

#if defined (__XTENSA__)
        xthal_dcache_block_writeback(&buffer[index], sizeof(logRecord_t));
#endif

    }
    else
    {
        // If trace has not been initialized by a previous call to RsdkTraceInit() then don't
        // log any data in order to avoid any errors or undefined behaviour.
    }
}
#if defined(TRACE_KERNEL)
EXPORT_SYMBOL(RsdkTraceLogEvent);
#endif

/**
* @brief          Dump log events
* @details        This function will dump log events into a file.
*
* @note           This should be called only ONCE per application. This means that if the application is
*                 multithreaded RsdkTraceDump must be called only after all threads have been joined.
*/
void RsdkTraceDump(char *fileName, traceTransferCb_t transferCb)
{
    int index;

    RotateBuff(&gTraceRecord);  // Rearrange logs records in chronological order if buffer was rotated

#if defined(__LAX__)
    Rsdk_DT_sysMemWriteSync((unsigned int)gsRBufLogData, gsRemoteBufferAddr, NUM_LOG_DATA * sizeof(logRecord_t));
    TimerEnd(NULL);
#else
#ifndef TRACE_KERNEL
    index = IndexRead(&gTraceRecord.traceBufferIndex, gTraceRecord.traceBufferSize + 1);

#if defined (__XTENSA__)
    xthal_dcache_block_writeback(gTraceRecord.pTraceBuffer, (uint32_t)(sizeof(logRecord_t) * (unsigned int)index));
#endif

    /* Dump trace buffer in a file */
    transferCb(fileName, (const char *)gTraceRecord.pTraceBuffer, (int)(sizeof(logRecord_t) * (unsigned int)index));

    /* Do cleanup or any last platform specific actions if necessary */
    TimerEnd(fileName);
#endif
#endif /* __LAX__ */
}

/**
* @brief          Stops the tracing of new events
*
* @pre            It must only be called after RsdkTraceInit()
*/
void RsdkTraceStop(void)
{
    TraceAtomicValueSet(&gTraceRecord.enable, 0);
}

/**
* @brief          Resumes tracinf of new events
*
* @pre            It must only be called after RsdkTraceInit()
*/
void RsdkTraceStart(void)
{
#if defined(__LAX__)
    gsRemoteBufferAddr = gLaxArgs[0];
#endif
    TraceAtomicValueSet(&gTraceRecord.enable, 1);
}

#if defined(TRACE_KERNEL)
EXPORT_SYMBOL(RsdkTraceDump);
#endif

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
