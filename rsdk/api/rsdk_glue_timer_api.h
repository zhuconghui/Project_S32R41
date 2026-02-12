/**************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2019-2021 NXP
 * All Rights Reserved
 *
 *****************************************************************************
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

#ifndef RSDK_GLUE_TIMER_API_H
#define RSDK_GLUE_TIMER_API_H

/** @addtogroup rsdk_glue_timer
 * @{
 * @brief
 * RadarSDK components depend on application provided API for timer related functions.
 * @details
 * Specifically, delay (microsec and millisec) and timeout functionalities are used. Below specified
 *  function prototypes are to be implemented at application level and linked in the final executable.
 * RadarSDK provide example implementation for these functions for various environments. 
 * @ifnot S32R45_DOCS See @ref rsdk_sa_multi_rfe. @endif
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "typedefs.h"

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
#define GLUE_TIMER_SUCCESS                  0u  // glue timer call was successful
#define GLUE_TIMER_ERR_NOT_INIT             10u  // glue timer driver not initialized
#define GLUE_TIMER_ERR_INIT_FAILURE         11u  // glue timer driver not initialized
#define GLUE_TIMER_ERR_DELAY                20u  // wrong delay value used
#define GLUE_TIMER_ERR_CHANNEL              30u  // incorrect channel used
#define GLUE_TIMER_ERR_RUNNING              40u  // glue timer was already busy waiting (e.g. called from an interrupt?)
#define GLUE_TIMER_ERR_ARMED                50u // glue timer not armed before
#define GLUE_TIMER_ERR_ALARM_INVALID        60u // alarm setting invalid
#define GLUE_TIMER_ERR_ALARM_NOT_SUPPORTED  61u // alarm setting invalid
#define GLUE_TIMER_ERR                      90u // alarm setting invalid

#define GLUE_TIMER_EXPIRED 0xffu  // the timer has expired

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
  * @return      GLUE_TIMER_SUCESS for success or other positive value in case of error
  */
extern uint32_t RsdkGlueTimerInit(void);

/** @brief       Application provided function to delay execution with ms milliseconds.
  * @param[in]   ms delay time in milliseconds
  * @return      GLUE_TIMER_SUCESS for success or other positive value in case of error
  * @pre         Invoke RsdkGlueTimerInit() as initialization code, prior to calling this function for the first time
  */
extern uint32_t RsdkGlueTimerDelayMs(uint32_t ms);

/** @brief      Application provided function to delay execution with us microseconds.
  * @param[in]  us delay time in microseconds
  * @return     GLUE_TIMER_SUCESS for success or other positive value in case of error
  * @pre        Invoke RsdkGlueTimerInit() as initialization code, prior to calling this function for the first time
  */
extern uint32_t RsdkGlueTimerDelayUs(uint32_t us);

/** @brief      Application provided function to arm a timer with value in microseconds.
  * @param[in]  us timout value in microseconds
  * @param[in]  channel can be only 1...3
  * @return     GLUE_TIMER_SUCESS for success or other positive value in case of error
  * @pre        Invoke RsdkGlueTimerInit() as initialization code, prior to calling this function for the first time
  * @post       RsdkGlueTimeOutDisarm() must be called after the time processing was done
  */
extern uint32_t RsdkGlueTimeOutArmUs(uint32_t us, uint32_t channel);

/** @brief      Application provided function to disarm a previously-armed timer.
  * @param[in]  channel can be only 1...3
  * @return     GLUE_TIMER_SUCESS for success or other positive value in case of error
  * @pre        RsdkGlueTimeOutArm() must be called before, using the same channel
  */
extern uint32_t RsdkGlueTimeOutDisarm(uint32_t channel);

/** @brief      Application provided function to check whether a previously-armed timer has expired.
  * @param[in]  channel can be only 1...3
  * @return     GLUE_TIMER_EXPIRED if timer has expired, GLUE_TIMER_SUCESS if still ticking and 
  *             other positive value in case of error
  * @pre        RsdkGlueTimeOutArm() must be called before, using the same channel
  */
extern uint32_t RsdkGlueTimeOutHasExpired(uint32_t channel);

/** @brief      Application provided function to get measured time in microseconds.
  * @return     measured time in us from the moment when the timer's counter is 0
  * @pre        RsdkGlueTimerInit() must be called before
  */
extern uint32_t RsdkGlueTimerGetCounterUs(void);

#ifdef __cplusplus
}
#endif

#endif /* RSDK_GLUE_TIMER_API_H */

/** @} */
