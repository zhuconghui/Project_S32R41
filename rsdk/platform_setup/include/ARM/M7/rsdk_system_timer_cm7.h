/*
 * Copyright 2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

/*
 * Cortex M7 System timer, SysTick
 * please see https://developer.arm.com/documentation/dui0646/c/Cortex-M7-Peripherals/System-timer--SysTick
 */
 
#ifndef RSDK_SYSTEM_TIMER_CM7_H
#define RSDK_SYSTEM_TIMER_CM7_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "stdbool.h"
#include "typedefs.h"
#include "rsdk_status.h"
/* Define in your project CM7_CLOCK_FREQ (in Mhz) and CM7_ID_NUMBER (0 or 1 for S32R41)
 * please see rsdk_cm7_settings.h as example
#include "rsdk_cm7_settings.h"
 */
 
#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define SYS_TIMER_CLOCK_PERIOD					(1.0 / CM7_CLOCK_FREQ)	// in microseconds
#define SYS_TIMER_TICKS							(CM7_CLOCK_FREQ)		// (1 / SYS_TIMER_CLOCK_PERIOD) in us
#define CM7_SYS_TIMER_IRQ_PRIORITY				0						// 0 - 15

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/** @brief       Application provided function to initialize timer-related glue layer.
  * @return      RSDK_SUCCESS for success or other positive value in case of error
  */
rsdkStatus_t RsdkSysTimerCm7Init(void);

/** @brief       Application provided function to delay execution with ms milliseconds.
  * @param[in]   ms delay time in milliseconds
  * @return      RSDK_SUCCESS for success or other positive value in case of error
  * @pre         Invoke RsdkSysTimerCm7Init() as initialization code, prior to calling this function for the first time
  */
rsdkStatus_t RsdkSysTimerCm7DelayMs(uint32_t ms);

/** @brief      Application provided function to delay execution with us microseconds.
  * @param[in]  us delay time in microseconds
  * @return     RSDK_SUCCESS for success or other positive value in case of error
  * @pre        Invoke RsdkSysTimerCm7Init() as initialization code, prior to calling this function for the first time
  */
rsdkStatus_t RsdkSysTimerCm7DelayUs(uint32_t us);

/** @brief      Application provided function to set a timeout with value in microseconds.
  * @param[in]  us timeout value in microseconds
  * @return     RSDK_SUCCESS for success or other positive value in case of error
  * @pre        Invoke RsdkSysTimerCm7Init() as initialization code, prior to calling this function for the first time
  */
rsdkStatus_t RsdkSysTimerCm7SetTimeOutUs(uint32_t us);

/** @brief      Application provided function to check whether a previously timeout has expired.
  * @return     true if timer has expired, false if still ticking
  * @pre        RsdkSysTimerCm7SetTimeOutUs() must be called before, otherwise the function will return true
  */
bool RsdkSysTimerCm7TimeOut(void);

/** @brief      Application provided function to get measured time in microseconds.
  * @return     measured time in us from the moment when the timer's counter is 0
  * @pre        RsdkSysTimerCm7Init() must be called before
  */
uint32_t RsdkSysTimerCm7GetCounterUs(void);

#ifdef __cplusplus
}
#endif

#endif /* RSDK_SYSTEM_TIMER_CM7_H */

/** @} */
