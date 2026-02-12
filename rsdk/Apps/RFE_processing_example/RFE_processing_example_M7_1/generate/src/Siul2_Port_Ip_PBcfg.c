
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

/**
*   @file    Siul2_Port_Ip_PBcfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Siul2_Port_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_VENDOR_ID_PBCFG_C                       43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C        7
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C     0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_PBCFG_C                2
#define SIUL2_PORT_IP_SW_MINOR_VERSION_PBCFG_C                0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_PBCFG_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are of the same vendor */
#if (SIUL2_PORT_IP_VENDOR_ID_PBCFG_C != SIUL2_PORT_IP_VENDOR_ID_H)
    #error "Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h have different vendor ids"
#endif
/* Check if Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are different"
#endif

/* Check if Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are of the same software version */
#if ((SIUL2_PORT_IP_SW_MAJOR_VERSION_PBCFG_C != SIUL2_PORT_IP_SW_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_MINOR_VERSION_PBCFG_C != SIUL2_PORT_IP_SW_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_PATCH_VERSION_PBCFG_C != SIUL2_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

const Siul2_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr[NUM_OF_CONFIGURED_PINS] =
{
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 58,
        .mux                   = PORT_MUX_ALT1,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 46,
        .mux                   = PORT_MUX_ALT1,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 43,
        .mux                   = PORT_MUX_ALT1,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 45,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .initValue             = 2,
        .inputMuxReg           = {
                                   29
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT1,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 44,
        .mux                   = PORT_MUX_ALT1,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 51,
        .mux                   = PORT_MUX_ALT2,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 48,
        .mux                   = PORT_MUX_ALT2,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 50,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .initValue             = 2,
        .inputMuxReg           = {
                                   32
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT1,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 49,
        .mux                   = PORT_MUX_ALT2,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 18,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 52,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 47,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 27,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 21,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 23,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 25,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 22,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 24,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 26,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 82,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 53,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 56,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 86,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 84,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 38,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 85,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 83,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_NOT_AVAILABLE,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2_0,
        .pinPortIdx            = 37,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_CONTROL4,
        .receiverSel           = PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF,
        .openDrain             = PORT_OPEN_DRAIN_DISABLED,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    }
};
#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

