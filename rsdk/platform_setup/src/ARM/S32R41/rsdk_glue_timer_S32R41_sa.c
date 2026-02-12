/**************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2021 NXP
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

#include "rsdk_S32R41.h"
#include "rsdk_glue_timer_api.h"
#include "platform_setup_basic.h"
#include "interrupts.h"

uint32_t RsdkGlueTimerInit(void)
{
    return RsdkSTMInit();
}

//prerequisite: call RsdkGlueTimerInit() before using this function

uint32_t RsdkGlueTimerDelayMs(uint32_t ms)
{
    return RsdkDelayMs(ms);
}
//prerequisite: call RsdkGlueTimerInit() before using this function

uint32_t RsdkGlueTimerDelayUs(uint32_t us)
{
    return RsdkDelayUs(us);
}
//prerequisite: call RsdkGlueTimerInit() before using this function

uint32_t RsdkGlueTimeOutArmUs(uint32_t us, uint32_t channel)
{
    return RsdkTimeOutArmUs(us, channel);
}
//prerequisite: call RsdkGlueTimerInit() before using this function

uint32_t RsdkGlueTimeOutDisarm(uint32_t channel)
{
    return RsdkTimeOutDisarm(channel);
}
//prerequisite: call RsdkGlueTimerInit() before using this function

uint32_t RsdkGlueTimeOutHasExpired(uint32_t channel)
{
    return RsdkTimeOutHasExpired(channel);
}

uint32_t RsdkGlueTimerGetCounterUs(void)
{
    return RsdkTimerGetValue();
}
