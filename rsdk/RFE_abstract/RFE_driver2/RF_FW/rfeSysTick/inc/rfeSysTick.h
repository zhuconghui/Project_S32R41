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

/**
 * \file
 *
 *  \brief pre-requisit:  rsdk_system_timer_cm7 should be initialized and enabled : RsdkSysTimerCm7Init
 *                         SysTick functions implemented using CM7 System timer
 *
 */
 
/**
 *     
 * 
 *  \brief
 *        
 *  \detail
 *
 *
 *
 */

#ifndef RFE_SYS_TICK_H
#define RFE_SYS_TICK_H

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "rfe_error.h"
#include "rfe_types.h"
#include "rfeHwLink.h"

 /**
 *  
 *  \brief
 *  
 *  \detail  We need a systick counter at 25 Mhz
 *
 */

/**
 * \def  RFE_SYSTICK_FREQUENCY
 *  \brief RFE_SYSTICK_FREQUENCY  
 */
#define RFE_SYSTICK_FREQUENCY ( 1000000000UL / RFE_NS_PER_TIME_TICK )

/**
 * \def  RFE_SYSTICK_TICKS_PER_USEC
 *  \brief RFE_SYSTICK_TICKS_PER_USEC  
 */
#define RFE_SYSTICK_TICKS_PER_USEC ( RFE_SYSTICK_FREQUENCY / 1000000UL )


 
/**
 * \def RFE_SYSTICK_CHANNEL_MAXTIMEOUT
 *
 * \brief RFE_SYSTICK_CHANNEL_MAXTIMEOUT   Maximum allowed time-out value for a channel
 * 
 * \detail  Limit chosen to limit the number of the timers needed for this function
 *
 */

typedef uint32_t rfeSysTick_tick_t;          

/**
 * This enumerated type defines the PIT timer indices to be used for compare channels
 *
 * When a timer is used to trigger the TE (timing engine) using a hardware signal
 * The PIT[ RFE_SYSTICK_RESERVED_PIT_INDEX_CHANNEL0 ] or 
 *   the PIT[ RFE_SYSTICK_RESERVED_PIT_INDEX_CHANNEL1 ] 
 *          should be selected
 *
 */
 
 
/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

/**
 * \brief Initializes the unit 
 *
 * \param [inout] rfe___error___pointerError parameter.
 *
 *    
 */
 void rfeSysTick_init(rfe_error_t* rfe___error___pointer);
 
  
/**
 * \brief Gets current systick value
 *
 * \param [inout] rfe___error___pointerError parameter.
 *        
 * \return the actual value
 *
 */
static inline rfeSysTick_tick_t rfeSysTick_getTick(rfe_error_t* rfe___error___pointer)
{
	return ((rfeSysTick_tick_t) ( RfeHwHeartBeatTimerGetValue(rfe___error___pointer) ) );
}

/**
 * \brief Gets duration from one startTick to one endTick, which is not more than 4G ticks.
 *
 * \param [in] startTick  Starting time in ticks.
 * \param [in] endTick    Ending time in ticks.
 *        
 * \return Duration in ticks
 *
 */
static inline rfeSysTick_tick_t rfeSysTick_calculateDurationTicks( rfeSysTick_tick_t startTick, rfeSysTick_tick_t endTick )
{
    return ( startTick <= endTick )? ( endTick - startTick ) : ( ( 0xffffffffUL - startTick ) + endTick );
}
    
#endif //!RFE_SYS_TICK_H
