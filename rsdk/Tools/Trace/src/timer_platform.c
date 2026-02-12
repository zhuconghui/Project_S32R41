/*
 * Copyright 2020-2024 NXP
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
#include "timer_platform.h"
#if defined(__LAX__)
#include "avi.h"
#include "trace_internal_api.h"
#elif defined (__XTENSA__)
#include <xtensa/xos.h>
#include "rsdk_toolchain_helper.h"
#else
#if defined(TRACE_KERNEL)
#include <linux/types.h>
#include <linux/smp.h>
#include <linux/atomic.h>
#include "oal_timespec.h"
#include "rsdk_status.h"
#else
#include "compiler_api.h"














#include <stdatomic.h>
#include "sa_arm_counter.h"
#include "rsdk_toolchain_helper.h"







#endif /* TRACE_KERNEL */
#endif /* __LAX__ */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if !defined(__LAX__) && !defined(TRACE_KERNEL)




#endif /* !defined(__LAX__) && !defined(TRACE_KERNEL) */
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

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
#if !defined(__LAX__) && !defined(TRACE_KERNEL)
















#endif /* !defined(__LAX__) && !defined(TRACE_KERNEL) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifndef TRACE_KERNEL
/**
* @brief        Setup for timer use.
* @details      Performs platform specific actions that make retrieving a timestamp possible.
*/
void TimerInit(void)
{
#if defined(__LAX__)
    /* Enable LAX cycle count. */
    __ip_write(RSDK_LAX_CYC_COUNTER_MSB, RSDK_LAX_CYC_COUNTER_ENABLE_MASK, RSDK_LAX_CYC_COUNTER_ENABLE_MASK);
#elif defined (__XTENSA__)
    //nothing to do
#else






    /* DON'T use STM_INSTANCE_0 as it is already in use (glue timer) */
    STM_Init(STM_INSTANCE_1);









#endif /* __LAX__ */
}
#endif /* TRACE_KERNEL */

/**
* @brief        Retrieving timestamp from timer.
* @details      Reads the current timestamp from the platform specific timer.
*
* @return       timestamp value
*
* @pre          TimerInit() must be called beforehand.
*/
uint32_t TimerRead(void)
{
#if defined(__LAX__)
    /* Read the 64-bit counter and return only the lower half. */
    __ip_read(RSDK_LAX_CYC_COUNTER_MSB, RSDK_LAX_CYC_COUNTER_MSB_MASK);

    return __ip_read(RSDK_LAX_CYC_COUNTER_LSB, RSDK_LAX_CYC_COUNTER_LSB_MASK);
#elif defined (__XTENSA__)
    return xos_get_ccount();
#else
#if defined(TRACE_KERNEL)
    rsdkStatus_t    status;
    OAL_Timespec_t  timestamp;
    uint32_t        timestampNs = 0;

    status = OAL_GetTime(&timestamp);

    if (status == RSDK_SUCCESS)
        timestampNs = (uint32_t)(timestamp.mSec * OAL_NSEC_IN_SEC + timestamp.mNsec);

    return timestampNs;
#else












    return STM_GetValue();



#endif /* TRACE_KERNEL */
#endif /* __LAX__ */
}

#ifndef TRACE_KERNEL
/**
* @brief        Cleanup or any last required action at the end of trace.
*
* @param[in]    pArg: Generic pointer to any useful data.
*
* @pre          TimerInit() must be called beforehand.
*/
void TimerEnd(void *pArg)
{
#if defined(__LAX__)
    /* Disable LAX cycle count. */
    __ip_write(RSDK_LAX_CYC_COUNTER_MSB, RSDK_LAX_CYC_COUNTER_ENABLE_MASK, 0x0);
#elif defined (__XTENSA__)
    //nothing to do
    UNUSED_ARG(pArg);
#else
























































    //no cleanup needed
    UNUSED_ARG(pArg);

#endif /* __LAX__ */
}
#endif /* TRACE_KERNEL */

/**
* @brief        Returns the core ID on which the event occured.
*
* @return       core ID
*/
uint8_t CoreIdRead(void)
{
#if defined(__LAX__)
    return ((uint8_t)__ip_read(SWVERSION_ADDR, RSDK_LAX_SWVERSION_LAXID_MASK));
#elif defined (__XTENSA__)
    return 0;
#else
#if defined(TRACE_KERNEL)
    return ((uint8_t)smp_processor_id());
#else
    return ((uint8_t)CompilerGetCoreId());    
#endif
#endif /* __LAX__ */
}

/**
* @brief        Reads current index value atomically.
*
* @param[in]    pTraceBufferIndex: pointer to the atomic variable holding the index
* @param[in]    traceBufferSize: size of trace buffer - used to compute modulo
*
* @return       Current value of the index in the trace buffer.
*/
int IndexRead(traceAtomic_t *pTraceBufferIndex, uint16_t traceBufferSize)
{
    int index;

    index = TraceAtomicValueGet(pTraceBufferIndex);

    return index % (int)traceBufferSize;
}

/**
* @brief        Reads current index value and increments it atomically.
*
* @param[inout] pTraceBufferIndex: pointer to the atomic variable holding the index
* @param[in]    traceBufferSize: size of trace buffer - used to compute modulo
*
* @return       Old value of the index in the trace buffer.
*/
int IndexReadIncrement(traceAtomic_t *pTraceBufferIndex, uint16_t traceBufferSize)
{
    int index;
#if defined(__LAX__)
    /* LAX trace does not require explicit exclusive access */
    index = (*pTraceBufferIndex)++;

    if (*pTraceBufferIndex == traceBufferSize)
        *pTraceBufferIndex = 0;
#elif defined (__XTENSA__)
    index = (*pTraceBufferIndex)++;
#else
#if defined(TRACE_KERNEL)
    index = atomic_inc_return(pTraceBufferIndex);     //returns new value
    index--;
#else



#if defined(__GNUC__)   /* GCC */
    index = atomic_fetch_add(pTraceBufferIndex, 1);   //returns old value
#elif defined(__DCC__)  /* Diab */
    INLINE_ASM("msync       \n\t"
        "lwarx %0, 0, %1    \n\t"
        "e_addi %0, %0, 1   \n\t"
        "stwcx. %0, 0, %1   \n\t"
        : "=&r"(index)
        : "r"(pTraceBufferIndex)
        );
    index--;
#endif

#endif /* TRACE_KERNEL */
#endif /* __LAX__ */

#if !defined(__LAX__)
    /* Compute index to assure buffer circularity */
    index = index % (int)traceBufferSize;
#endif /* __LAX__ */

    return index;
}

/**
* @brief        Writes current index value atomically.
*
* @param[inout] pTraceBufferIndex: pointer to the atomic variable holding the index
* @param[in]    value: new value to be set for the buffer index.
*/
void IndexWrite(traceAtomic_t *pTraceBufferIndex, int value)
{
    TraceAtomicValueSet(pTraceBufferIndex, value);
}

#ifdef __cplusplus
}
#endif
/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
