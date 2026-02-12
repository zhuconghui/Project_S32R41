/*
 * Copyright 2021-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef USING_PLATFORM_SDK
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "app_cond_flag.h"
#include "debug_tools.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void AppCondFlagInit(rsdkAppCondFlag_t *apFlag)
{
	apFlag->value = FLAG_WAIT_VALUE; 		/* RSDK in ascii used as watermark. */
	apFlag->initialized = FLAG_INIT_VALUE; 	/* INIT in ascii used as watermark. */
}

void AppCondFlagSignal(rsdkAppCondFlag_t *apFlag)
{
	apFlag->value = 1;
}

void AppCondFlagWait(rsdkAppCondFlag_t *apFlag)
{
	if (apFlag->initialized != FLAG_INIT_VALUE)
	{
		DbgPrintMsg("apFlag value not initialized! Application will halt!");
		HALT_HERE;
	}
	else
	{
		while (apFlag->value != 1);
		apFlag->value = FLAG_WAIT_VALUE;
	}
}

void AppCondFlagDestroy(rsdkAppCondFlag_t *apFlag)
{

}

#ifdef __cplusplus
}
#endif

#endif  /* USING_PLATFORM_SDK */
