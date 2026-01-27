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

#ifndef CLOCK_IP_TRUSTEDFUNCTIONS_H
#define CLOCK_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Clock_Ip_TrustedFunctions.h
*   @version    2.0.0
*
*   @brief   CLOCK IP type header file.
*   @details CLOCK IP type header file.

*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#if defined(__cplusplus)
extern "C"{
#endif
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Clock_Ip_Types.h"
#if defined(CLOCK_IP_PLATFORM_SPECIFIC1)
    #include "Clock_Ip_Specific1.h"
#else
    #include "Clock_Ip_Specific.h"
#endif
#include "Clock_Ip_Cfg.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                2
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_TrustedFunctions.h file and StandardTypes.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and StandardTypes.h are different"
#endif
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Types.h file have same versions */
#if (CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != CLOCK_IP_TYPES_VENDOR_ID)
    #error "Clock_Ip_TrustedFunctions.h and Clock_Ip_Types.h have different vendor IDs"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Types.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CLOCK_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Types.h are different"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Types.h file are of the same Software version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CLOCK_IP_TYPES_SW_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CLOCK_IP_TYPES_SW_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CLOCK_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Types.h are different"
#endif

#if defined(CLOCK_IP_PLATFORM_SPECIFIC1)
    /* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific1.h file have same versions */
    #if (CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != CLOCK_IP_SPECIFIC1_VENDOR_ID)
        #error "Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific1.h have different vendor IDs"
    #endif

    /* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific1.h file are of the same Autosar version */
    #if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_SPECIFIC1_AR_RELEASE_MAJOR_VERSION) || \
         (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_SPECIFIC1_AR_RELEASE_MINOR_VERSION) || \
         (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CLOCK_IP_SPECIFIC1_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific1.h are different"
    #endif

    /* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific1.h file are of the same Software version */
    #if ((CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CLOCK_IP_SPECIFIC1_SW_MAJOR_VERSION) || \
         (CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CLOCK_IP_SPECIFIC1_SW_MINOR_VERSION) || \
         (CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CLOCK_IP_SPECIFIC1_SW_PATCH_VERSION))
        #error "Software Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific1.h are different"
    #endif
#else
    /* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific.h file have same versions */
    #if (CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != CLOCK_IP_SPECIFIC_VENDOR_ID)
        #error "Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific.h have different vendor IDs"
    #endif

    /* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific.h file are of the same Autosar version */
    #if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
         (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
         (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific.h are different"
    #endif

    /* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific.h file are of the same Software version */
    #if ((CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION) || \
         (CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CLOCK_IP_SPECIFIC_SW_MINOR_VERSION) || \
         (CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CLOCK_IP_SPECIFIC_SW_PATCH_VERSION))
        #error "Software Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific.h are different"
    #endif
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Cfg.h file have same versions */
#if (CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != CLOCK_IP_CFG_VENDOR_ID)
    #error "Clock_Ip_TrustedFunctions.h and Clock_Ip_Cfg.h have different vendor IDs"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Cfg.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Cfg.h are different"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Cfg.h file are of the same Software version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CLOCK_IP_CFG_SW_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CLOCK_IP_CFG_SW_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CLOCK_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief        Set user access allowed for some clock registers
 *
 * @param        None
 * @return       None
 *
 */

extern void Clock_Ip_SpecificSetUserAccessAllowed(void);

#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES
/**
 * @brief        Set Ram waitstate value base on core_clk
 *
 * @param        None
 * @return       None
 *
 */
extern void SRAMC_SetRamIWS(void);
#endif

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* CLOCK_IP_TRUSTEDFUNCTIONS_H */


