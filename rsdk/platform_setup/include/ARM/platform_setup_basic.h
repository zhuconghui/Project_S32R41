/*
 * Copyright 2018-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef PLATFORM_SETUP_BASIC_H
#define PLATFORM_SETUP_BASIC_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#if defined(RSDK_AUTOSAR)
#include "Std_Types.h"
#else
#include "typedefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum return_value
{
    APP_STATUS_SUCCESS = 0,
	APP_STATUS_ERROR                           = 0x001U,    /*!< Generic operation failure status */
	APP_STATUS_BUSY                            = 0x002U,    /*!< Generic operation busy status */
	APP_STATUS_TIMEOUT                         = 0x003U,    /*!< Generic operation timeout status */
	APP_STATUS_UNSUPPORTED                     = 0x004U,    /*!< Generic operation unsupported status */
} appStatus_t;

/*  Boards supported by platform setup */
typedef enum
{
    PLAT_TYPE_S32R45_EVB = 0,
    PLAT_TYPE_S32R41_EVB,
    PLAT_TYPE_SAF85XX_DIG_V1,
	PLAT_TYPE_SAF86XX_DIG_SKT,
    PLAT_TYPE_LAST_PAD_DEF
} platformType_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
appStatus_t RsdkPlatformSetup(platformType_t platformType);

appStatus_t RsdkPlatfromRfeExtErrorIntClear(uint32_t frontendId);

/* Must be used after platform setup, as it assumes XBAR_DIV3_CLK clock of value STM_CLOCK_MHZ
   return 0 for success
   see also RsdkDelayMs(), RsdkDelayUs() and RsdkTimeOutArmUs() */
uint32_t RsdkSTMInit(void);
/* Core will busy wait delayMs miliseconds
   return 0 for success
   Attn: this function distructively uses of STM counter of current core.
         Must be used after platform setup and after calling RsdkSTMInit() */
uint32_t RsdkDelayMs(uint32_t delayMs);

/* Core will busy wait delayUs microseconds
   return 0 for success
   see notes on RsdkDelayMs() and RsdkSTMInit() */
uint32_t RsdkDelayUs(uint32_t delayUs);

/* Set of function providing timeout polling mechanism via STM counter of current core
   return 0 for success
   see also RsdkSTMInit() */
uint32_t RsdkTimeOutArmUs(uint32_t us, uint32_t channel);
uint32_t RsdkTimeOutDisarm(uint32_t channel);
uint32_t RsdkTimeOutHasExpired(uint32_t channel);

/* Get time value (in useconds) of STM counter of current core
   see also RsdkSTMInit() and STM_CLOCK_MHZ */
uint32_t RsdkTimerGetValue(void);

#ifdef __cplusplus
}
#endif

#endif  /* PLATFORM_SETUP_BASIC_H */
