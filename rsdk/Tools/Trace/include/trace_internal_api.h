/**************************************************************************************************
 * 
 * Copyright 2020-2021 NXP 
s *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 **************************************************************************************************/

#ifndef TRACE_INTERNAL_API_H
#define TRACE_INTERNAL_API_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if defined(__LAX__)
#define RSDK_LAX_CYC_COUNTER_MSB (0x98 >> 2)
#define RSDK_LAX_CYC_COUNTER_LSB (0x9C >> 2)
#define RSDK_LAX_CYC_COUNTER_ENABLE_MASK (0x1U << 31)
#define RSDK_LAX_CYC_COUNTER_MSB_MASK (0x0000FFFF)
#define RSDK_LAX_CYC_COUNTER_LSB_MASK (0xFFFFFFFF)

#define LAX_CMD_TRIGGER_SHIFT (14U)
#define SWVERSION_ADDR  0x1U                 
#endif /* __LAX__ */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Log record packet definition.
* @details        The trace log record contains details about event timestamp, function name
*                 and misc debug info like values of variables. 
* @note           This structure has strict size and packing constraints, needed for unambiguous decoding
*                 once the trace log is saved on the PC. If the memory size is not 12 bytes for each log entry,
*                 then the trace decoder will not produce correct results.
*                 Also, if the size of this struct changes, the RSDK_TRACE_LOG_ENTRY_SIZE define in trace.h must 
*                 be changed accordingly.
*/
typedef struct
#ifndef __LAX__
__attribute__((packed))
#endif
{
    uint32_t timestamp;  /**< Timestamp associated with the event. This field is set internally by RsdkTraceLogEvent()
							     using a value read from a hardware timer. 
								 <b>Note</b> the timestamp accuracy is limited and architecture-dependent,
								 due to non-zero access time of hardware timers and system memory*/
    uint8_t  coreID;     /**< ID of the CPU core which is adding the event to the trace log. 
								This field is set internally by RsdkTraceLogEvent()*/
    uint8_t  eventType;  /**< Set by the first argument of RsdkTraceLogEvent(), of type rsdkTraceEventType_t */
    uint16_t extraInfo1; /**< Set by the second argument of RsdkTraceLogEvent(). */
    uint32_t extraInfo2; /**< Set by the third argument of RsdkTraceLogEvent(). Freeform information. */
} logRecord_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @brief          Stops the tracing of new events
*
* @pre            It must only be called after RsdkTraceInit()
*
* @note           Currently used internally by the profiling project to limit the number of events generated.
*/
extern void RsdkTraceStop(void);

/**
* @brief          Resumes tracing of new events
*
* @pre            It must only be called after RsdkTraceInit()
*
* @note           Currently used internally by the profiling project to limit the number of events generated.
*/
extern void RsdkTraceStart(void);

#ifdef __cplusplus
}
#endif

#endif /* TRACE_INTERNAL_API_H */

/** @} */
