/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
*   Dependencies         : 
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

#ifndef LINFLEXD_UART_IP_DEFINES_H
#define LINFLEXD_UART_IP_DEFINES_H

/**
*   @file
*   @defgroup linflexd_uart_ip Linflexd UART IPL
*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
* 4) user callback header files
==================================================================================================*/
#include "S32R41_LINFLEXD.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_DEFINES_VENDOR_ID                     43
#define LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MAJOR_VERSION      4
#define LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MINOR_VERSION      7
#define LINFLEXD_UART_IP_DEFINES_AR_RELEASE_REVISION_VERSION   0
#define LINFLEXD_UART_IP_DEFINES_SW_MAJOR_VERSION              2
#define LINFLEXD_UART_IP_DEFINES_SW_MINOR_VERSION              0
#define LINFLEXD_UART_IP_DEFINES_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
        #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_Defines.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/
/* @Custom baudrate values */
#define LINFLEXD_UART_IP_CUSTOM_BAUDRATE

/* @brief Development error detection */
#define LINFLEXD_UART_IP_DEV_ERROR_DETECT       (STD_ON)

/* @brief Total number of channels configured */
#define LINFLEXD_UART_IP_NUMBER_OF_INSTANCES    (1U)

/* @brief Uart Osif source counter. This parameter is used to select between different OsIf counter implementation */
#define LINFLEXD_UART_IP_TIMEOUT_TYPE           (OSIF_COUNTER_DUMMY)

/* @brief Number of loops before returning STATUS_TIMEOUT.*/
#define LINFLEXD_UART_IP_TIMEOUT_VALUE_US       (1000000)

/* @brief LINFLEXD rx/tx/error interrupt lines ored together. */
#define LINFLEXD_UART_IP_ORED_INT_LINES         (1U)

/* @brief LINFlexD DMA support */
#define LINFLEXD_UART_IP_HAS_DMA_ENABLED        (STD_OFF)

/* @brief LINFlexD User-mode support */
#define LINFLEXD_UART_IP_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/* @brief LINFLEXD DMA enabled instances */
#define LINFLEXD_UART_IP_INST_HAS_DMA   {(boolean)TRUE}

/* @brief Support for Uart Timeout Interrupt. If this parameter has been configured to TRUE, the Uart driver will enable Timeout Interrupt. */
#define LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT  (STD_OFF)

#if (STD_ON == LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT)
    /* @brief Array of instances that have loopback mode enabled. */
    #define LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT_PER_INSTANCE  {(boolean) FALSE}
#endif

/* @brief Support for Internal Loopback. If this parameter has been configured to TRUE, the Uart driver will be executed in Loopback mode. */
#define LINFLEXD_UART_IP_ENABLE_INTERNAL_LOOPBACK  (STD_OFF)

#if (STD_ON == LINFLEXD_UART_IP_ENABLE_INTERNAL_LOOPBACK)
    /* @brief Array of instances that have loopback mode enabled. */
    #define LINFLEXD_UART_IP_ENABLE_INTERNAL_LOOPBACK_PER_INSTANCE  {(boolean) FALSE}
#endif

/* Check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == LINFLEXD_UART_IP_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Uart in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
  #endif /* (STD_ON == LINFLEXD_UART_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

#ifdef MCAL_LINFLEX_REG_PROT_AVAILABLE
    #if ((STD_ON == LINFLEXD_UART_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == MCAL_LINFLEX_REG_PROT_AVAILABLE))
        /* @brief User mode enabled. */
        #define LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_ON)
    #else
        /* @brief User mode disabled. */
        #define LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)
    #endif
#else
    /* @brief User mode disabled. */
    #define LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)
#endif /* MCAL_LINFLEX_REG_PROT_AVAILABLE */
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
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

/** @} */

#endif /* LINFLEXD_UART_IP_DEFINES_H */

