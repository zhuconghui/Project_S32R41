/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_P03_D2404_ASR_REL_4_7_REV_0000_20240405
*
*   Copyright 2021 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file       Power_Ip_PMC_SUPPORT.c
*   @version    2.0.0
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif




/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Private.h"
#include "Power_Ip_PMC_SUPPORT.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_PMC_SUPPORT_VENDOR_ID_C                      43
#define POWER_IP_PMC_SUPPORT_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_PMC_SUPPORT_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_PMC_SUPPORT_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_PMC_SUPPORT_SW_MAJOR_VERSION_C               2
#define POWER_IP_PMC_SUPPORT_SW_MINOR_VERSION_C               0
#define POWER_IP_PMC_SUPPORT_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_PMC_SUPPORT.c file and Power_Ip_Private.h file are of the same vendor */
#if (POWER_IP_PMC_SUPPORT_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip_PMC_SUPPORT.c and Power_Ip_Private.h have different vendor ids"
#endif

/* Check if Power_Ip_PMC_SUPPORT.c file and Power_Ip_Private.h file are of the same Autosar version */
#if ((POWER_IP_PMC_SUPPORT_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_SUPPORT_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PMC_SUPPORT_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_PMC_SUPPORT.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_PMC_SUPPORT.c file and Power_Ip_Private.h file are of the same Software version */
#if ((POWER_IP_PMC_SUPPORT_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_PMC_SUPPORT_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_PMC_SUPPORT_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_PMC_SUPPORT.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_PMC_SUPPORT.c file and Power_Ip_PMC_SUPPORT.h file are of the same vendor */
#if (POWER_IP_PMC_SUPPORT_VENDOR_ID_C != POWER_IP_PMC_SUPPORT_VENDOR_ID)
    #error "Power_Ip_PMC_SUPPORT.c and Power_Ip_PMC_SUPPORT.h have different vendor ids"
#endif

/* Check if Power_Ip_PMC_SUPPORT.c file and Power_Ip_PMC_SUPPORT.h file are of the same Autosar version */
#if ((POWER_IP_PMC_SUPPORT_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PMC_SUPPORT_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_SUPPORT_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PMC_SUPPORT_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PMC_SUPPORT_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PMC_SUPPORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_PMC_SUPPORT.c and Power_Ip_PMC_SUPPORT.h are different"
#endif

/* Check if Power_Ip_PMC_SUPPORT.c file and Power_Ip_PMC_SUPPORT.h file are of the same Software version */
#if ((POWER_IP_PMC_SUPPORT_SW_MAJOR_VERSION_C != POWER_IP_PMC_SUPPORT_SW_MAJOR_VERSION) || \
     (POWER_IP_PMC_SUPPORT_SW_MINOR_VERSION_C != POWER_IP_PMC_SUPPORT_SW_MINOR_VERSION) || \
     (POWER_IP_PMC_SUPPORT_SW_PATCH_VERSION_C != POWER_IP_PMC_SUPPORT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_PMC_SUPPORT.c and Power_Ip_PMC_SUPPORT.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (defined(POWER_IP_PMC_SUPPORT_SUPPORTED) && (STD_ON == POWER_IP_PMC_SUPPORT_SUPPORTED))
/**
* @brief            This function configure the Power Management Controller
* @details          The operating voltages are monitored by a set of on-chip supervisory circuits
*                   to ensure that this device works within the correct voltage range.
*
* @param[in]        ConfigPtr   Pointer to PMC configuration structure.
*
* @return           void
*
*/
void Power_Ip_PMC_SUPPORT_Init(const Power_Ip_PMC_SUPPORT_ConfigType * ConfigPtr)
{
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;
    uint32 ConfigValue = 0;
    uint32 NcspdStatus = 0;
    if (PMC_SUPPORT_BG_HLD_CTL_BG_TRIM_ENABLE == (ConfigPtr->BandGapEnable & PMC_SUPPORT_BG_HLD_CTL_BG_TRIM_EN_MASK))
    {
        Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

            NcspdStatus = IP_PMC->NCSPD_STAT;
        } while ( (PMC_NCSPD_STAT_NCSPD_STAT1_NO_ERROR != (NcspdStatus & PMC_NCSPD_STAT_NCSPD_STAT1_MASK)) && (!TimeoutOccurred) );

        if (!TimeoutOccurred)
        {
            ConfigValue = IP_PMC_SUPPORT->BG_HLD_CTL;
            ConfigValue = (uint32)(ConfigValue & (~((uint32)PMC_SUPPORT_BG_HLD_CTL_BG_TRIM_EN_MASK | (uint32)PMC_SUPPORT_BG_HLD_CTL_BG_RES_HLD1V8_MASK)));
            ConfigValue = (uint32)(ConfigValue | (uint32)(PMC_SUPPORT_BG_HLD_CTL_BG_TRIM_ENABLE));
            IP_PMC_SUPPORT->BG_HLD_CTL = ConfigValue;
            IP_PMC_SUPPORT->OVUV_HLD1V8 = ConfigPtr->HLD1v8Ctrl;
            IP_PMC_SUPPORT->OVUV_PMIC0V9 = ConfigPtr->PMIC0v9Ctrl;
        }
        else
        {
            Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
        }
    }
}
#endif

#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
