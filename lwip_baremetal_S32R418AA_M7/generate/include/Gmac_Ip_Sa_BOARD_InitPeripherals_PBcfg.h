/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : GMAC
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

#ifndef GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_H
#define GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_H

/**
*   @file
*
*   @addtogroup GMAC_DRIVER_CONFIGURATION GMAC Driver Configuration
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

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_VENDOR_ID                     43
#define GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_SW_MAJOR_VERSION              2
#define GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_SW_MINOR_VERSION              0
#define GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

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
#define GMAC_CONFIG_SA_BOARD_INITPERIPHERALS_PB \
    extern const Gmac_CtrlConfigType Gmac_0_ConfigPB_BOARD_INITPERIPHERALS; 

/*! @brief Device instance number */
#ifndef INST_GMAC_0
    #define INST_GMAC_0        (0U)
#elif (INST_GMAC_0 != 0)
    #error "[TPS_ECUC_06074] Invalid configuration due to symbolic name values"
#endif

/* Used for allocation of TX buffers */
#ifndef GMAC_0_TXRING_0_DESCR
    #define GMAC_0_TXRING_0_DESCR
#endif

/* Used for allocation of RX buffers */
#ifndef GMAC_0_RXRING_0_DESCR
    #define GMAC_0_RXRING_0_DESCR
#endif


/* Maximum number of configured buffers for a Tx Ring */
#ifndef GMAC_0_MAX_TXBUFF_SUPPORTED
    #define GMAC_0_MAX_TXBUFF_SUPPORTED    (5U)
#elif (GMAC_0_MAX_TXBUFF_SUPPORTED < 5)
    #undef GMAC_0_MAX_TXBUFF_SUPPORTED
    #define GMAC_0_MAX_TXBUFF_SUPPORTED    (5U) 
#endif

/* Maximum number of configured buffers for an Rx Ring */
#ifndef GMAC_0_MAX_RXBUFF_SUPPORTED
    #define GMAC_0_MAX_RXBUFF_SUPPORTED    (5U)
#elif (GMAC_0_MAX_RXBUFF_SUPPORTED < 5)
    #undef GMAC_0_MAX_RXBUFF_SUPPORTED
    #define GMAC_0_MAX_RXBUFF_SUPPORTED    (5U) 
#endif

/* Maximum length of a single buffer across all Tx Rings */
#ifndef GMAC_0_MAX_TXBUFFLEN_SUPPORTED
    #define GMAC_0_MAX_TXBUFFLEN_SUPPORTED	(1536U)
#endif

/* Maximum length of a single buffer across all Rx Rings */
#ifndef GMAC_0_MAX_RXBUFFLEN_SUPPORTED
    #define GMAC_0_MAX_RXBUFFLEN_SUPPORTED	(1536U)
#endif

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GMAC_IP_SA_BOARD_INITPERIPHERALS_PBCFG_H */

