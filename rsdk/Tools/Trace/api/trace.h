/*
 * Copyright 2017-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef TRACE_H
#define TRACE_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "typedefs.h"
#include "rsdk_status.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup trace_api
* @{
*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Size of a trace log entry in bytes.
* */
#define RSDK_TRACE_LOG_ENTRY_SIZE    (12U)

#define RSDK_TRACE_STRUCT_TIMESTAMP_OFFSET  0
#define RSDK_TRACE_STRUCT_TIMESTAMP_TYPE    uint32_t
#define RSDK_TRACE_STRUCT_TIMESTAMP_LEN     (sizeof(RSDK_TRACE_STRUCT_TIMESTAMP_TYPE))
#define RSDK_TRACE_STRUCT_CORE_OFFSET       (RSDK_TRACE_STRUCT_TIMESTAMP_OFFSET + RSDK_TRACE_STRUCT_TIMESTAMP_LEN)
#define RSDK_TRACE_STRUCT_CORE_TYPE         uint8_t
#define RSDK_TRACE_STRUCT_CORE_LEN          (sizeof(RSDK_TRACE_STRUCT_CORE_TYPE))
#define RSDK_TRACE_STRUCT_TYPE_OFFSET       (RSDK_TRACE_STRUCT_CORE_OFFSET + RSDK_TRACE_STRUCT_CORE_LEN)
#define RSDK_TRACE_STRUCT_TYPE_TYPE         uint8_t
#define RSDK_TRACE_STRUCT_TYPE_LEN          (sizeof(RSDK_TRACE_STRUCT_TYPE_TYPE))
#define RSDK_TRACE_STRUCT_EXTRA1_OFFSET     (RSDK_TRACE_STRUCT_TYPE_OFFSET + RSDK_TRACE_STRUCT_TYPE_LEN)
#define RSDK_TRACE_STRUCT_EXTRA1_TYPE       uint16_t
#define RSDK_TRACE_STRUCT_EXTRA1_LEN        (sizeof(RSDK_TRACE_STRUCT_EXTRA1_TYPE))
#define RSDK_TRACE_STRUCT_EXTRA2_OFFSET     (RSDK_TRACE_STRUCT_EXTRA1_OFFSET + RSDK_TRACE_STRUCT_EXTRA1_LEN)
#define RSDK_TRACE_STRUCT_EXTRA2_TYPE       uint32_t
#define RSDK_TRACE_STRUCT_EXTRA2_LEN        (RSDK_TRACE_LOG_ENTRY_SIZE - (RSDK_TRACE_STRUCT_TIMESTAMP_LEN + \
                                                RSDK_TRACE_STRUCT_CORE_LEN + RSDK_TRACE_STRUCT_TYPE_LEN +   \
                                                RSDK_TRACE_STRUCT_EXTRA1_LEN))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Predefined types of trace events. Intended as the first argument in RsdkTraceLogEvent()
* @details        Used to mark common event types like function start/end, system synchronization 
* 				  or general debug info.
* */
typedef enum
{
    RSDK_TRACE_EVENT_FUNC_START,
    RSDK_TRACE_EVENT_FUNC_END,
    RSDK_TRACE_EVENT_DBG_INFO,
    RSDK_TRACE_EVENT_CHIRP_SYNC,
    RSDK_TRACE_EVENT_FRAME_SYNC,
    RSDK_TRACE_EVENT_LAX_TRACE_SYNC,
    RSDK_TRACE_EVENT_LAST = 255
} rsdkTraceEventType_t;

/**
* @brief          Used to indicate exactly which RSDK modules and functions are signalling _FUNC_START and _FUNC_END events.
* @details        This enum defines only the base indexes for functions associated to the RSDK modules. Each module must define
* 				  its job types in its own header files, strictly within the boundaries defined here. E.g. all SPT-related jobs
*                 must be contained between RSDK_TRACE_JOB_SPT_BASE and RSDK_TRACE_JOB_LAX_BASE.
* */
typedef enum
{
    RSDK_TRACE_JOB_APP_BASE = 0,
    RSDK_TRACE_JOB_SPT_BASE = 100,
    RSDK_TRACE_JOB_LAX_BASE = 200,
    RSDK_TRACE_JOB_RF_BASE = 300,
    RSDK_TRACE_JOB_TFTP_CLIENT_BASE = 400,
    RSDK_TRACE_JOB_CSI2_BASE = 500,
    RSDK_TRACE_JOB_DSP_BASE = 600,
    RSDK_TRACE_JOB_CTE_BASE = 700,
    RSDK_TRACE_JOB_ADDYOURSHERE_BASE = 1000,

    RSDK_TRACE_JOB_LAST,
} rsdkTraceJobType_t;

/**
* @brief          Used to indicate exactly which RSDK modules and functions are logging information related to RSDK_TRACE_EVENT_DBG_INFO.
* @details        This enum defines only the base indexes for debug events associated to the RSDK modules. Each module must define
* 				  its specific debug events in its own header files, strictly within the boundaries defined here. E.g. all SPT-related debug info
*                 must be contained between RSDK_TRACE_DBG_SPT_BASE and RSDK_TRACE_DBG_LAX_BASE.
* */
typedef enum
{
    RSDK_TRACE_DBG_APP_BASE = 0,
    RSDK_TRACE_DBG_SPT_BASE = 100,
    RSDK_TRACE_DBG_LAX_BASE = 200,
    RSDK_TRACE_DBG_RF_BASE = 300,
    RSDK_TRACE_DBG_TFTP_CLIENT_BASE = 400,
    RSDK_TRACE_DBG_CSI2_BASE = 500,
    RSDK_TRACE_DBG_DSP_BASE = 600,
    RSDK_TRACE_DBG_CTE_BASE = 700,
    RSDK_TRACE_DBG_ADDYOURSHERE_BASE = 1000,

    RSDK_TRACE_DBG_LAST,
} rsdkTraceDbgType_t;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Prototype of the method used to transfer the trace buffer to PC.
* @details        The transfer function must be defined at the application level and passed as a 
*                 callback argument to RsdkTraceDump().
* @param[in]      file_name   Trace dump file name
* @param[in]      src_addr    Local memory address from where the data should be copied.
* @param[in]      max_bytes   Size of the data.
*/
typedef void (*traceTransferCb_t)(const char *file_name, const char *src_addr, int max_bytes);

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief          This function initializes the internal state of the Trace module, configures the 
*				  hardware timer to count CPU cycles and resets the trace buffer.
*
* @param[in] traceBuffer - Allocated buffer for trace. Size must be equal with buffSize bytes.
* @param[in] buffSize - Buffer size in bytes. Must be a multiple of RSDK_TRACE_LOG_ENTRY_SIZE
*
* @pre            It must be called after platform setup, before any call to RsdkTraceLogEvent().
*/
extern rsdkStatus_t RsdkTraceInit(char *traceBuffer, uint16_t buffSize);

/**
* @brief          Adds an entry to the trace log.
* @details        It constructs a log record and writes it to the global trace log buffer.
*
* @param[in] eventType - signal generic event types like function start/end, synchronization or debug info
* @param[in] extra1 - Depending on eventType, it is usually of type rsdkTraceJobType_t or rsdkTraceDbgType_t.
* @param[in] extra2 - Freeform information e.g. the instantaneous value of a program variable.
*
*
* @pre            It must only be called after RsdkTraceInit()
*/
extern void RsdkTraceLogEvent(rsdkTraceEventType_t eventType, uint16_t extra1, uint32_t extra2);

/**
* @brief          Unwraps and saves the trace log to a file on the PC.
*
* @param[in] fileName - Name of the log file to be created or overwritten on the PC.
* @param[in] transferCb - Callback method to be used for transferring the trace.
*
* @pre            It must only be called after RsdkTraceInit()
*/
extern void RsdkTraceDump(char *fileName, traceTransferCb_t transferCb);

#ifdef __cplusplus
}
#endif

#endif /*TRACE_H*/

/** @} */
