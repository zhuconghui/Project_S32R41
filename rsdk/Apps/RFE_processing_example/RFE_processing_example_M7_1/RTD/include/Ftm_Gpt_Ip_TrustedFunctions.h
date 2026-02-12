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

#ifndef FTM_GPT_IP_TRUSTEDFUNCTIONS_H
#define FTM_GPT_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Ftm_Gpt_Ip_TrustedFunctions.h
*
*   @addtogroup ftm_ip Ftm IPL
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
#include "Ftm_Gpt_Ip_Cfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_GPT_IP_TRUSTEDFUNCTIONS_VENDOR_ID                           43
#define FTM_GPT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION            4
#define FTM_GPT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION            7
#define FTM_GPT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION         0
#define FTM_GPT_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                    2
#define FTM_GPT_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                    0
#define FTM_GPT_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Define header file are of the same vendor */
#if (FTM_GPT_IP_TRUSTEDFUNCTIONS_VENDOR_ID != FTM_GPT_IP_VENDOR_ID_CFG)
    #error "Ftm_Gpt_Ip_TrustedFunctions.h and Ftm_Gpt_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if this header  file and Define header file are of the same AutoSar version */
#if ((FTM_GPT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION  != FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FTM_GPT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION  != FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FTM_GPT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION   != FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_TrustedFunctions.h and Ftm_Gpt_Ip_Cfg.h are different"
#endif
/* Check if source file and Define header file are of the same Software version */
#if ((FTM_GPT_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION  != FTM_GPT_IP_SW_MAJOR_VERSION_CFG) || \
     (FTM_GPT_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION  != FTM_GPT_IP_SW_MINOR_VERSION_CFG) || \
     (FTM_GPT_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION  != FTM_GPT_IP_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Ftm_Gpt_Ip_TrustedFunctions.h and Ftm_Gpt_Ip_Cfg.h are different"
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

#if ((defined(MCAL_FTM_REG_PROT_AVAILABLE) && (STD_ON == MCAL_FTM_REG_PROT_AVAILABLE)) && (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief      Ftm_Gpt_Ip_SetUserAccessAllowed
 * @details    This function is called externally by OS Application
 * @param[in]  FtmBaseAddr - The base address of PIT.
 */
    extern void Ftm_Gpt_Ip_SetUserAccessAllowed(uint32 FtmBaseAddr);
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* FTM_GPT_IP_TRUSTEDFUNCTIONS_H */
