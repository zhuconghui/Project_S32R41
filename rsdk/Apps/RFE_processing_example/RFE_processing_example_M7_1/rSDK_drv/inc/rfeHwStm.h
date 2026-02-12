/**************************************************************************************************
* Copyright 2022 - 2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_HW_STM_H
#define RFE_HW_STM_H

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
#define TIMER_SUCCESS                  0u  // timer call was successful
#define TIMER_ERR_NOT_INIT             10u // timer driver not initialized
#define TIMER_ERR_INIT_FAILURE         11u // timer driver not initialized
#define TIMER_ERR_DELAY                20u // wrong delay value used
#define TIMER_ERR_CHANNEL              30u // incorrect channel used
#define TIMER_ERR_RUNNING              40u // timer was already busy waiting (e.g. called from an interrupt?)
#define TIMER_ERR_ARMED                50u // timer not armed before
#define TIMER_ERR_ALARM_INVALID        60u // alarm setting invalid
#define TIMER_ERR_ALARM_NOT_SUPPORTED  61u // alarm setting invalid
#define TIMER_ERR                      90u // alarm setting invalid

#define TIMER_EXPIRED 0xffu  // the timer has expired
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/** @brief      Init STM_0
  * @details    STM_0 init for 25ns tick  
  * @param[in] 	None 
  * @return     TIMER_SUCESS
  * @pre        STM0 clocked by SYS_CLK/2 = 200 MHz
  */
uint32_t RfeHwStmInit(void);

/** @brief      Delay execution with us microseconds.
  * @details    STM_0 used to create a bussy waiting function that delays with us microseconds
  * @param[in]  us delay time in microseconds
  * @return     TIMER_SUCESS for success or other positive value in case of error
  * @pre        Invoke RfeHwStmInit() as initialization code, prior to calling this function for the first time
  */
uint32_t RfeHwStmDelayUs(uint32_t us);

/** @brief      Delay execution with ms milliseconds.
  * @details    STM_0 used to create a bussy waiting function that delays with ms milliseconds
  * @param[in]  ms delay time in milliseconds
  * @return     TIMER_SUCESS for success or other positive value in case of error
  * @pre        Invoke RfeHwStmInit() as initialization code, prior to calling this function for the first time
  */
uint32_t RfeHwStmDelayMs(uint32_t ms);

/** @brief      Get measured time in 25ns units.
  * @return     measured time in 25ns units from the moment when the timer's counter is 0
  * @pre        RfeHwStmInit() must be called before
  */
uint32_t RfeHwStmTimerGetValue(void);

/** @brief      Arm a timer with value in microseconds.
  * @details    STM_0 used for a timeout mechanism functions
  * @param[in]  us timout value in microseconds
  * @param[in]  channel can be only 1...3
  * @return     TIMER_SUCESS for success or other positive value in case of error
  * @pre        Invoke RfeHwStmInit() as initialization code, prior to calling this function for the first time
  * @post       RfeHwStmTimeOutDisarm() must be called after the time processing was done
  */
uint32_t RfeHwStmTimeOutArmUs(uint32_t us, uint32_t channel);

/** @brief      Disarm a previously-armed timer.
  * @param[in]  channel can be only 1...3
  * @return     TIMER_SUCESS for success or other positive value in case of error
  * @pre        RfeHwStmTimeOutArmUs() must be called before, using the same channel
  */
uint32_t RfeHwStmTimeOutDisarm(uint32_t channel);

/** @brief      Check whether a previously-armed timer has expired.
  * @param[in]  channel can be only 1...3
  * @return     TIMER_EXPIRED if timer has expired, TIMER_SUCESS if still ticking and
  *             other positive value in case of error
  * @pre        RfeHwStmTimeOutArmUs() must be called before, using the same channel
  */
uint32_t RfeHwStmTimeOutHasExpired(uint32_t channel);

#ifdef __cplusplus
}
#endif

#endif /* RFE_HW_STM_H */

/** @} */
