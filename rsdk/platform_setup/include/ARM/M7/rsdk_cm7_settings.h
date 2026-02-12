/*
 * Copyright 2017-2018,2021-2022 NXP
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
 
#ifndef RSDK_CM7_SETTINGS_H
#define RSDK_CM7_SETTINGS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

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
#define CM7_CLOCK_FREQ						400	// in Mhz
#define CM7_ID_NUMBER						  0	// Core id numeber M7_0 - 0; M7_1 - 1 	
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* RSDK_CM7_SETTINGS_H */

/** @} */
