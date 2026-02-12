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
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_D2402_ASR_REL_4_7_REV_0000_20240221
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

#ifndef XRDC_IP_CFG_DEFINES_H
#define XRDC_IP_CFG_DEFINES_H

/**
*   @file Xrdc_Ip_Cfg_Defines.h
*
*   @addtogroup XRDC_IP XRDC IPV Driver
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
/**
 * Include specific header file
 */
#include "StandardTypes.h" 
#include "S32R41_XRDC_0.h"
#include "S32R41_XRDC_1.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XRDC_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_XRDC_IP_CFG_DEFINES_SW_MAJOR_VERSION             2
#define RM_XRDC_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_XRDC_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                   FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against StandardTypes.h */
#if ((RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Xrdc_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


#define XRDC_COUNT                                   (uint32)(2UL)

#define XRDC_NUMBER_OF_DOMAINID                      (uint32)(8UL)

#define XRDC_BASE_ADDRS                              { IP_XRDC_0_BASE, IP_XRDC_1_BASE }

#define XRDC_MOD_BASEADDR_ADDR32(instance)           (Xrdc_Ip_InstanceAddress[instance])

#define XRDC_CR_OFFSET                               (uint32)(0x0U)

#define XRDC_HWCFG0_OFFSET                           (uint32)(0xF0U)
#define XRDC_HWCFG1_OFFSET                           (uint32)(0xF4U)
#define XRDC_HWCFG2_OFFSET                           (uint32)(0xF8U)

#define XRDC_MDACFG_OFFSET                           (uint32)(0x100U)

#define XRDC_MRCFG_OFFSET                            (uint32)(0x140U)

#define XRDC_DERRLOC_OFFSET                          (uint32)(0x200U)

#define XRDC_DERR_W_OFFSET                           (uint32)(0x400U)

#define XRDC_PID_OFFSET                              (uint32)(0x700U)

#define XRDC_MDA_W_DFMT0_OFFSET                      (uint32)(0x800U)

#define XRDC_PDAC_W0_OFFSET                          (uint32)(0x1000U)

#define XRDC_PDAC_W1_OFFSET                          (uint32)(0x1004U)

#define XRDC_MRGD_OFFSET                             (uint32)(0x2000U)

#define XRDC_MAX_OF_ERROR_RECORDED                   (uint32)(19UL)

#define XRDC_S32R41

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XRDC_IP_DEVICE_REGISTERS_H */


