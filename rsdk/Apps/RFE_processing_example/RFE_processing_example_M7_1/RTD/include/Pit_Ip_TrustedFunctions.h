/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Stm Pit Ftm
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

#ifndef PIT_IP_TRUSTEDFUNCTIONS_H
#define PIT_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Pit_Ip_TrustedFunctions.h
*
*   @addtogroup Pit_ip PIT IPL
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pit_Ip_Cfg.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PIT_IP_TRUSTEDFUNCTIONS_VENDOR_ID                           43
#define PIT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION            4
#define PIT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION            7
#define PIT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION         0
#define PIT_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                    2
#define PIT_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                    0
#define PIT_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Define header file are of the same vendor */
#if (PIT_IP_TRUSTEDFUNCTIONS_VENDOR_ID != PIT_IP_VENDOR_ID_CFG)
    #error "Pit_Ip_TrustedFunctions.h and Pit_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if this header  file and Define header file are of the same AutoSar version */
#if ((PIT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION  != PIT_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (PIT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION  != PIT_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (PIT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION   != PIT_IP_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Pit_Ip_TrustedFunctions.h and Pit_Ip_Cfg.h are different"
#endif
/* Check if source file and Define header file are of the same Software version */
#if ((PIT_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION  != PIT_IP_SW_MAJOR_VERSION_CFG) || \
     (PIT_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION  != PIT_IP_SW_MINOR_VERSION_CFG) || \
     (PIT_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION  != PIT_IP_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Pit_Ip_TrustedFunctions.h and Pit_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief      Pit_Ip_SetUserAccessAllowed
 * @details    This function is called externally by OS Application. note: with S32ZE platform only PIT_AE support usermode, so user can only pass base address of PIT_AE.
 * @param[in]  PitBaseAddr - The base address of PIT.
 */
#if (defined(PIT_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PIT_IP_ENABLE_USER_MODE_SUPPORT))
    extern void Pit_Ip_SetUserAccessAllowed(uint32 PitBaseAddr);
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* PIT_IP_TRUSTEDFUNCTIONS_H */
