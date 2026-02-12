/**************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2022 NXP
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
#include "rsdk_system_timer_cm7.h"
#include "ARMCM7_SP.h"
#include "interrupts_cm7.h"
#include "rsdk_status.h"

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
static volatile uint32_t gSysTimerUs = 0;
static volatile uint32_t gSysTimerUsTimeout = 0;
/*==================================================================================================
*                                    LOCAL FUNCTION
==================================================================================================*/
static void TimerTick(void)
{
	gSysTimerUs++;
	if (gSysTimerUsTimeout)
	{
		gSysTimerUsTimeout--;
	}
}
/*==================================================================================================
*                                    GLOBAL FUNCTION
==================================================================================================*/
rsdkStatus_t RsdkSysTimerCm7Init(void)
{
	rsdkStatus_t ret = RSDK_SUCCESS;
	uint32_t     sysConfRet;
	ret = interrupts_cm7_install(SysTick_IRQn, CM7_SYS_TIMER_IRQ_PRIORITY, TimerTick, CM7_ID_NUMBER);
    sysConfRet = SysTick_Config(SYS_TIMER_TICKS); // 1us
    if (sysConfRet)
	{
		ret = RSDK_ERROR;
	}
	return ret;
}

rsdkStatus_t RsdkSysTimerCm7DelayMs(uint32_t ms)
{
	while(ms--)
	{
		RsdkSysTimerCm7DelayUs(1000);
	}
	return RSDK_SUCCESS;
}

rsdkStatus_t RsdkSysTimerCm7DelayUs(uint32_t us)
{
	volatile uint32_t initialSysTimerUs = gSysTimerUs;
	volatile uint32_t targetSysTimerUs = initialSysTimerUs + us;
	while(gSysTimerUs != targetSysTimerUs)
	{
	}
	return RSDK_SUCCESS;
}

rsdkStatus_t RsdkSysTimerCm7SetTimeOutUs(uint32_t us)
{
	gSysTimerUsTimeout = us;
	return RSDK_SUCCESS;
}

bool RsdkSysTimerCm7TimeOut(void)
{
	return (bool) (!gSysTimerUsTimeout);
}

uint32_t RsdkSysTimerCm7GetCounterUs(void)
{
	return gSysTimerUs;
}
