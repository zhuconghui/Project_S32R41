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
/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/

#include <stdio.h>
#include "rsdk_S32R41.h"
#include "interrupts_cm7.h"
#include "rfeHwStm.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
 ==================================================================================================*/
// STM0 and STM1 are clocked by SYS_CLK/2 = 200 MHz
// STM_2 is clocked by ACCEL_XBAR_CLK/4 = 100 MHz
#define STM_CLOCK_SOURCE_MHZ	200u
// Desired STM Frequency
#define STM_CLOCK_MHZ 			40u
// STM clock divider 
#define STM_CLOCK_DIVIDER 		(((STM_CLOCK_SOURCE_MHZ) / (STM_CLOCK_MHZ)) - 1)

#define DELAY_STM_CHANNEL_NR	0

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL FUNCTIONS
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/

// Must be used after platform setup, as it assumes XBAR_DIV3_CLK clock of value STM_CLOCK_MHZ
// return TIMER_SUCCESS
uint32_t RfeHwStmInit(void)
{
    // set  TEN=1 (enable) and CPS=STM_CLOCK_DIVIDER to enable STM_0
	STM_0.CR.B.TEN = 1;
	STM_0.CR.B.CPS = STM_CLOCK_DIVIDER;

    // zero STM0 count (note: STM_0 increments with time)
    STM_0.CNT.R = 0;

    return TIMER_SUCCESS;
}

/*-------------------------------------------------------------------------------------------------*/

// Core will busy wait delayUs microseconds
uint32_t RfeHwStmDelayUs(uint32_t us)
{
    uint32_t currTimeStamp;
    uint32_t ret = TIMER_SUCCESS;

    if (STM_0.CR.B.TEN != 0x1)  // has timer been started previously
    {
        ret = TIMER_ERR_NOT_INIT;
    }

    if (us >= (UINT32_MAX / STM_CLOCK_MHZ)) // so that multiplication below still fits uint32_t
    {
        ret = TIMER_ERR_DELAY;
    }

    if (ret == TIMER_SUCCESS)
    {
    	__disable_irq();
        currTimeStamp = STM_0.CNT.R;
        STM_0.CHANNEL[DELAY_STM_CHANNEL_NR].CMP.R = currTimeStamp + (us * STM_CLOCK_MHZ); // uint wraps around over UINT32_MAX
        STM_0.CHANNEL[DELAY_STM_CHANNEL_NR].CCR.B.CEN = 1;                                // enable channel
        __enable_irq();
        while (STM_0.CHANNEL[DELAY_STM_CHANNEL_NR].CIR.B.CIF == 0)
        {
        }

        STM_0.CHANNEL[DELAY_STM_CHANNEL_NR].CIR.B.CIF = 1; // clear interrupt
        STM_0.CHANNEL[DELAY_STM_CHANNEL_NR].CCR.B.CEN = 0; // disable channel
    }

    return ret;
}

/*-------------------------------------------------------------------------------------------------*/

// Core will busy wait delayMs miliseconds
uint32_t RfeHwStmDelayMs(uint32_t ms)
{
    if (ms >= (UINT32_MAX / 1000u)) // so that param for RfeHwStmDelayUs() below still fits uint32_t
    {
        return TIMER_ERR_DELAY;
    }
    else
    {
        return RfeHwStmDelayUs(ms * 1000);
    }
}

/*-------------------------------------------------------------------------------------------------*/

// in 25ns units
// Assumes reference clock values in STM_CLOCK_MHZ and STM_CLOCK_SOURCE_MHZ
uint32_t RfeHwStmTimerGetValue(void)
{
    return STM_0.CNT.R;
}

/*-------------------------------------------------------------------------------------------------*/

// Channel must be a positive value (max 4 for STM)
uint32_t RfeHwStmTimeOutArmUs(uint32_t us, uint32_t channel)
{
    uint32_t currTimeStamp;
    uint32_t ret = TIMER_SUCCESS;

    if (STM_0.CR.B.TEN != 0x1)  // has timer been started previously
    {
        ret = TIMER_ERR_NOT_INIT;
    }

    if (ret == TIMER_SUCCESS)
    {
        if ((channel < 1u) || (channel > 4u))
        {
            ret = TIMER_ERR_CHANNEL;
        }
    }

    if (us >= (UINT32_MAX / STM_CLOCK_MHZ)) // so that multiplication below still fits uint32_t
    {
        ret = TIMER_ERR_DELAY;
    }

    if (ret == TIMER_SUCCESS)
    {
    	__disable_irq();
        currTimeStamp = STM_0.CNT.R;
        STM_0.CHANNEL[channel].CMP.R = currTimeStamp + (us * STM_CLOCK_MHZ);
        STM_0.CHANNEL[channel].CCR.B.CEN = 1; // enable channel
        __enable_irq();
    }

    return ret;
}

/*-------------------------------------------------------------------------------------------------*/

// Channel must be a positive value
// Arm the timer with RfeHwStmTimeOutArmUs() on the same channel
uint32_t RfeHwStmTimeOutDisarm(uint32_t channel)
{
    uint32_t ret = TIMER_SUCCESS;

    if (STM_0.CR.B.TEN != 0x1)  // has timer been started previously
    {
        ret = TIMER_ERR_NOT_INIT;
    }

    if (ret == TIMER_SUCCESS)
    {
        if ((channel < 1u) || (channel > 4u))
        {
            ret = TIMER_ERR_CHANNEL;
        }
    }

    if (ret == TIMER_SUCCESS)
    {
        STM_0.CHANNEL[channel].CCR.B.CEN = 0; // disable channel
    }

    return ret;
}

/*-------------------------------------------------------------------------------------------------*/

// Returns TIMER_EXPIRED if timer has expired, TIMER_SUCCESS if still ticking and a positive value in case of error
// Arm the timer with RfeHwStmTimeOutArmUs() on the same channel
uint32_t RfeHwStmTimeOutHasExpired(uint32_t channel)
{
    uint32_t expired = TIMER_SUCCESS;

    if (STM_0.CR.B.TEN != 0x1)  // has timer been started previously
    {
        expired = TIMER_ERR_NOT_INIT;
    }

    if (expired == TIMER_SUCCESS)
    {
        if ((channel < 1u) || (channel > 4u))
        {
            expired = TIMER_ERR_CHANNEL;
        }
    }

    if (expired == TIMER_SUCCESS)
    {
        expired = (STM_0.CHANNEL[channel].CIR.B.CIF != 0) ? TIMER_EXPIRED : TIMER_SUCCESS;
    }

    if (expired == TIMER_EXPIRED)
    {
        STM_0.CHANNEL[channel].CIR.B.CIF = 1; // clear interrupt
    }

    return expired;
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
