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
/**
*   @file Linflexd_Uart_Ip_PBcfg.c
*   @defgroup linflexd_uart_ip Linflexd UART IPL
*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
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
#include "Linflexd_Uart_Ip_Types.h"
#include "Linflexd_Uart_Ip_Cfg.h"
#include "StandardTypes.h"
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    #include "Dma_Ip.h"
#endif


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_PBCFG_VENDOR_ID_C                     43
#define LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define LINFLEXD_UART_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define LINFLEXD_UART_IP_PBCFG_SW_MAJOR_VERSION_C              2
#define LINFLEXD_UART_IP_PBCFG_SW_MINOR_VERSION_C              0
#define LINFLEXD_UART_IP_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Linflexd_Uart_Ip_Types.h */
#if (LINFLEXD_UART_IP_PBCFG_VENDOR_ID_C != LINFLEXD_UART_IP_TYPES_VENDOR_ID)
    #error "Linflexd_Uart_Ip_PBcfg.c and Linflexd_Uart_Ip_Types.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION)|| \
     (LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION)|| \
     (LINFLEXD_UART_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_PBcfg.c and Linflexd_Uart_Ip_Types.h are different"
#endif
#if ((LINFLEXD_UART_IP_PBCFG_SW_MAJOR_VERSION_C != LINFLEXD_UART_IP_TYPES_SW_MAJOR_VERSION)|| \
     (LINFLEXD_UART_IP_PBCFG_SW_MINOR_VERSION_C != LINFLEXD_UART_IP_TYPES_SW_MINOR_VERSION)|| \
     (LINFLEXD_UART_IP_PBCFG_SW_PATCH_VERSION_C != LINFLEXD_UART_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip_PBcfg.c and Linflexd_Uart_Ip_Types.h are different"
#endif

/* Checks against Linflexd_Uart_Ip_Cfg.h */
#if (LINFLEXD_UART_IP_PBCFG_VENDOR_ID_C != LINFLEXD_UART_IP_CFG_VENDOR_ID)
    #error "Linflexd_Uart_Ip_PBcfg.c and Linflexd_Uart_Ip_Cfg.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_UART_IP_CFG_AR_RELEASE_MAJOR_VERSION)|| \
     (LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_UART_IP_CFG_AR_RELEASE_MINOR_VERSION)|| \
     (LINFLEXD_UART_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_UART_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_PBcfg.c and Linflexd_Uart_Ip_Cfg.h are different"
#endif
#if ((LINFLEXD_UART_IP_PBCFG_SW_MAJOR_VERSION_C != LINFLEXD_UART_IP_CFG_SW_MAJOR_VERSION)|| \
     (LINFLEXD_UART_IP_PBCFG_SW_MINOR_VERSION_C != LINFLEXD_UART_IP_CFG_SW_MINOR_VERSION)|| \
     (LINFLEXD_UART_IP_PBCFG_SW_PATCH_VERSION_C != LINFLEXD_UART_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip_PBcfg.c and Linflexd_Uart_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Linflexd_Uart_Ip_PBcfg.c and StandardTypes.h are different"
    #endif
    /* Checks against Dma_Ip.h */
    #if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
        #if ((LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
             (LINFLEXD_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Linflexd_Uart_Ip_PBcfg.c and Dma_Ip.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

#define UART_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"
extern Linflexd_Uart_Ip_StateStructureType Linflexd_Uart_Ip_apStateStructure[LINFLEXD_UART_IP_NUMBER_OF_INSTANCES];

#define UART_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"
#define UART_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"

/**
* @brief          Hardware configuration for Linflexd Uart Hardware - Configuration:
*
* @api
*/
const Linflexd_Uart_Ip_UserConfigType Linflexd_Uart_Ip_xHwConfigPB_0 =
{
    /* Actual Baud-rate */
    115200,
    /* Baud-rate mantissa */
    54U,
    /* Baud-rate Divisor */
    16U,
    /* Fractional Baud-rate */
    4U,
    /* Parity control */
    (boolean)FALSE,
    /* Parity type */
    LINFLEXD_UART_IP_PARITY_EVEN,
    /* Number of stop bits, 1 stop bit (default) or 2 stop bits */
    LINFLEXD_UART_IP_ONE_STOP_BIT,
    /* Number of bits per transmitted/received word */
    LINFLEXD_UART_IP_8_BITS,
    /* Type of UART transfer (interrupt/dma based) */
    LINFLEXD_UART_IP_USING_INTERRUPTS,
    /* Callback to invoke for Uart events.*/
    NULL_PTR,
    /* User callback parameter pointer.*/
    NULL_PTR,
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    /* DMA channel number for DMA-based rx. */
    255,
    /* DMA channel number for DMA-based tx. */
    255,
#endif
    /* Runtime state structure reference */
    &Linflexd_Uart_Ip_apStateStructure[0U]
};


#define UART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

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

