/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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

#ifndef SIUL2_DIO_IP_CFG_H
#define SIUL2_DIO_IP_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "S32R41_SIUL2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_DIO_IP_VENDOR_ID_CFG_H                       43
#define SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_CFG_H        7
#define SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_CFG_H     0
#define SIUL2_DIO_IP_SW_MAJOR_VERSION_CFG_H                2
#define SIUL2_DIO_IP_SW_MINOR_VERSION_CFG_H                0
#define SIUL2_DIO_IP_SW_PATCH_VERSION_CFG_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define DIO_VIRTWRAPPER_SUPPORT        (STD_OFF)

/**
* @brief          Pre-processor switch to enable/disable development error detection for Dio Ip API
*
* @implements     Siul2_Dio_Ip_ErrorDetect_define
*/
#define SIUL2_DIO_IP_DEV_ERROR_DETECT                         (STD_ON)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* SIUL2_DIO_IP_CFG_H */

/** @} */

