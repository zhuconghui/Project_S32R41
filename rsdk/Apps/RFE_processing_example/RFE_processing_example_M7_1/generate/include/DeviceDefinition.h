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

#ifndef DEVICEDEFINITION_H
#define DEVICEDEFINITION_H

/**
*   @file   DeviceDefinition.h
*
*   @addtogroup BASENXP_COMPONENT
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEVICEDEFINITION_VENDOR_ID                    43
#define DEVICEDEFINITION_MODULE_ID                    0
#define DEVICEDEFINITION_AR_RELEASE_MAJOR_VERSION     4
#define DEVICEDEFINITION_AR_RELEASE_MINOR_VERSION     7
#define DEVICEDEFINITION_AR_RELEASE_REVISION_VERSION  0
#define DEVICEDEFINITION_SW_MAJOR_VERSION             2
#define DEVICEDEFINITION_SW_MINOR_VERSION             0
#define DEVICEDEFINITION_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** 
* @brief This macro define specific derivative and sub derivative.
*/

#ifndef S32R418AA
#define S32R418AA
#endif

#ifndef DERIVATIVE_S32R418AA
#define DERIVATIVE_S32R418AA
#endif
/** 
* @brief This macro define specific derivative family.
*/

#ifndef S32R41
#define S32R41
#endif
/** 
* @brief This macro define specific platform.
*/
#ifndef S32R
#define S32R
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif


/** @} */

#endif /* DEVICEDEFINITION_H */

