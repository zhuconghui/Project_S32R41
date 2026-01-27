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
*   Build Version        : S32R_RTD_2_0_0_P03_D2404_ASR_REL_4_7_REV_0000_20240405
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

#ifndef SIUL2_PORT_IP_CFG_H
#define SIUL2_PORT_IP_CFG_H

/**
*   @file      Siul2_Port_Ip_Cfg.h
*
*   @addtogroup Port_CFG
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
#include "S32R41_SIUL2.h"
#include "Siul2_Port_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_VENDOR_ID_CFG_H                       43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H        7
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H     0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_H                2
#define SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_H                0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Siul2_Port_Ip_Cfg.h and Siul2_Port_Ip_Types.h are of the same version */
#if (SIUL2_PORT_IP_VENDOR_ID_CFG_H != SIUL2_PORT_IP_TYPES_VENDOR_ID_H)
    #error "Siul2_Port_Ip_Cfg.h and Siul2_Port_Ip_Types.h have different vendor ids"
#endif
/* Check if Siul2_Port_Ip_Cfg.h and Siul2_Port_Ip_Types.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H    != SIUL2_PORT_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H    != SIUL2_PORT_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H != SIUL2_PORT_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip_Cfg.h and Siul2_Port_Ip_Types.h are different"
#endif
/* Check if Siul2_Port_Ip_Cfg.h and Siul2_Port_Ip_Types.h are of the same Software version */
#if ((SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_H != SIUL2_PORT_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_H != SIUL2_PORT_IP_TYPES_SW_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_H != SIUL2_PORT_IP_TYPES_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip_Cfg.h and Siul2_Port_Ip_Types.h are different"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                      DEFINES AND MACROS
==================================================================================================*/
/*! @brief Definitions for PortContainer_0_BOARD_InitPeripherals Functional Group */

/*! @brief User number of configured pins */
#define NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals 9

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*! @brief User configuration structure */
extern const Siul2_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals[NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals];

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

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

#ifdef __cplusplus
}
#endif

#endif /* SIUL2_PORT_IP_CFG_H */

