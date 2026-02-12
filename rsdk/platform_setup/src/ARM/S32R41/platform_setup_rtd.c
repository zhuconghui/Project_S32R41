/*
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/

#ifdef ARMCM7_SP
#include "Platform.h"
#include "Clock_Ip.h"
#include "CDD_Rm.h"
#include "Mcu.h"
#else
#include "interrupts.h"
#endif
#include "platform_setup_basic.h"
#include "debug_tools.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
 ==================================================================================================*/

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
extern void statusCheck(const char *funcName, int status);

/**********************************************************************************************************************
 Constants and Macros
**********************************************************************************************************************/
#define ACCEL_CLOCK_FREQ   600000000U
#define SYS_CLK_FREQ 400000000U

/**********************************************************************************************************************
 User-defined Types
**********************************************************************************************************************/

/**********************************************************************************************************************
 External Objects
**********************************************************************************************************************/

/**********************************************************************************************************************
 Global Variables
**********************************************************************************************************************/

/**********************************************************************************************************************
 Local Function Prototypes
**********************************************************************************************************************/

/**********************************************************************************************************************
 Global Functions
**********************************************************************************************************************/

/**********************************************************************************************************************
 Local Functions
**********************************************************************************************************************/
static void AppMcuInit(void)
{
	Std_ReturnType stdStatus;

#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

    stdStatus = Mcu_InitClock(McuClockSettingConfig_0);/* PLL Source Selection of McuPeriphPLL and McuCorePLL is FIRC_CLK */
	statusCheck("Mcu_InitClock", stdStatus);

#if(MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    stdStatus = Mcu_DistributePllClock();
	statusCheck("Mcu_DistributePllClock", stdStatus);
#endif

    Mcu_SetMode(McuModeSettingConf_0);
    if (Mcu_GetClockFrequency(ACCEL_CLK) != ACCEL_CLOCK_FREQ)
    {
        DbgPrintMsg("Clock init error: ACCEL_CLK frequency not set as expected\n");
    }

    if(Mcu_GetClockFrequency(SYS_CLK) != SYS_CLK_FREQ)
    {
        DbgPrintMsg("Clock init error: SYS_CLK frequency not set as expected\n");
    }
}
/***************************************************************************************************
 Local Function Prototypes
***************************************************************************************************/

appStatus_t RsdkPlatformSetup(platformType_t platformType)
{
    appStatus_t status = APP_STATUS_SUCCESS;

    switch (platformType)
    {
        case PLAT_TYPE_S32R41_EVB:

        	Rm_Init(&Rm_Config);

        	/* RTD_PLATFORM_IM.pdf: The MCU module should be initialized before Platform,
        	 * enabling clock gates for all the IPs accessed by Platform CDD. */
        	AppMcuInit();

#ifndef USING_OS_AUTOSAROS
        	Platform_Init(NULL);
#endif
			break;
        default:
            status = APP_STATUS_ERROR;
            break;
    }

    return status;
}


#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
