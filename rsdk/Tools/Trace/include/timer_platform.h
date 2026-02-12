/*
 * Copyright 2020-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef TIMER_PLATFORM_H
#define TIMER_PLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#if defined(__LAX__)
#include <stdint.h>
#include <lax/intrinsics.h>
#include "rsdk_lax_config.h"
#elif defined (__XTENSA__)
#include <stdint.h>
#else
#if defined(TRACE_KERNEL)
#include <linux/types.h>
#include <linux/atomic.h>
#else
#include <stdint.h>



#if defined(__GNUC__) || defined(__ghs__)
#include <stdatomic.h>
#endif

#include "compiler_api.h"
#endif /* TRACE_KERNEL */
#endif /* __LAX__ */

/*==================================================================================================
*                                         TYPEDEFS
==================================================================================================*/
#if defined(__LAX__)
typedef int                 traceAtomic_t;
#elif defined (__XTENSA__)
typedef int                 traceAtomic_t;
#else
#if defined(TRACE_KERNEL)
typedef atomic_t 			traceAtomic_t;
#else



#if defined(__GNUC__) || defined(__ghs__)
typedef atomic_int 			traceAtomic_t;
#elif defined(__DCC__)  	/* Diab */
typedef int 				traceAtomic_t;
#endif

#endif /* TRACE_KERNEL */
#endif /* __LAX__ */

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief        Reads current timestamp from timer.
*
* @return       Timestamp value.
*
* @pre          TimerInit() must be called beforehand.
*/
uint32_t TimerRead(void);

#ifndef TRACE_KERNEL
/**
* @brief        Setup for timer use.
*/
void TimerInit(void);

/**
* @brief        Cleanup or any last required action at the end of trace.
*
* @param[in]    pArg: Generic pointer to any useful data.
*
* @pre          TimerInit() must be called beforehand.
*/
void TimerEnd(void *pArg);
#endif

/**
* @brief        Returns the core ID on which the event occured.
*
* @return       core ID
*/
uint8_t CoreIdRead(void);

/**
* @brief        Reads current index value atomically.
*
* @param[in]    pTraceBufferIndex: pointer to the atomic variable holding the index
* @param[in]    traceBufferSize: size of trace buffer - used to compute modulo
*
* @return       Current value of the index in the trace buffer.
*/
int IndexRead(traceAtomic_t *pTraceBufferIndex, uint16_t traceBufferSize);

/**
* @brief        Reads current index value and increments it atomically.
*
* @param[inout] pTraceBufferIndex: pointer to the atomic variable holding the index
* @param[in]    traceBufferSize: size of trace buffer - used to compute modulo
*
* @return       Old value of the index in the trace buffer.
*/
int IndexReadIncrement(traceAtomic_t *pTraceBufferIndex, uint16_t traceBufferSize);

/**
* @brief        Writes current index value atomically.
*
* @param[inout] pTraceBufferIndex: pointer to the atomic variable holding the index
* @param[in]    value: new value to be set for the buffer index.
*/
void IndexWrite(traceAtomic_t *pTraceBufferIndex, int value);


/**
* @brief        Writes value to the address atomically.
*
* @param[inout] pAddr: pointer to the atomic variable that will be set
* @param[in]    value: the value
*/
static inline void TraceAtomicValueSet(traceAtomic_t *pAddr, int value)
{
#if defined(__LAX__)
    /* LAX trace does not require explicit exclusive access */
    *pAddr = value;
#elif defined (__XTENSA__)
    //atomic_store(pAddr, value); not supported
    *pAddr = value;
#else
#if defined(TRACE_KERNEL)
    atomic_set(pAddr, value);
#else



#if defined(__GNUC__)   /* GCC */
    atomic_store(pAddr, value);
#elif defined(__DCC__)  /* Diab */
    INLINE_ASM("msync       \n\t"
        "se_stw %1, 0(%0)   \n\t"
        :
        : "r"(pAddr), "r"(value)
        );
#endif

#endif /* TRACE_KERNEL */
#endif /* __LAX__ */
}

/**
* @brief        Reads value from the address atomically.
*
* @param[in]    pAddr: pointer to the atomic variable that will be read
*
* @return       The value stored at the address
*/
static inline int TraceAtomicValueGet(traceAtomic_t *pAddr)
{
    int value;

#if defined(__LAX__)
    /* LAX trace does not require explicit exclusive access */
    value = *pAddr;
#elif defined (__XTENSA__)
    //value = atomic_load(pAddr); not supported
    value = *pAddr;
#else
#if defined(TRACE_KERNEL)
    value = atomic_read(pAddr);
#else



#if defined(__GNUC__)   /* GCC */
    value = atomic_load(pAddr);
#elif defined(__DCC__)  /* Diab */
    INLINE_ASM("msync       \n\t"
        "se_lwz %0, 0(%1)   \n\t"
        : "=r"(value)
        : "r"(pAddr)
        );
#endif

#endif /* TRACE_KERNEL */
#endif /* __LAX__ */

    return value;
}

#ifdef __cplusplus
}
#endif

#endif /*TIMER_PLATFORM_H*/

/** @} */
