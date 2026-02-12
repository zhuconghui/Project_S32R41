/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_P03_D2404_ASR_REL_4_7_REV_0000_20240405
*
*   Copyright 2021 - 2024 NXP NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SPI_IPW_TYPES_H
#define SPI_IPW_TYPES_H

/**
*   @file    Spi_Ipw_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Spi middle level driver header file.
*   @details This file is the header containing all the necessary information for SPI
*            LLD.
*   @addtogroup SPI_DRIVER Spi Driver
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
==================================================================================================*/
#include "Spi_Ip_Types.h"
#include "Spi_Ipw_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_TYPES_VENDOR_ID                       43
#define SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION        7
#define SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION     0
#define SPI_IPW_TYPES_SW_MAJOR_VERSION                2
#define SPI_IPW_TYPES_SW_MINOR_VERSION                0
#define SPI_IPW_TYPES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ipw_Types.h and Spi_Ip_Types.h are of the same vendor */
#if (SPI_IPW_TYPES_VENDOR_ID != SPI_IP_TYPES_VENDOR_ID)
    #error "Spi_Ipw_Types.h and Spi_Ip_Types.h have different vendor ids"
#endif
/* Check if Spi_Ipw_Types.h file and Spi_Ip_Types.h file are of the same Autosar version */
#if ((SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != SPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION != SPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION != SPI_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Ipw_Types.h and Spi_Ip_Types.h are different"
#endif
#if ((SPI_IPW_TYPES_SW_MAJOR_VERSION != SPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_SW_MINOR_VERSION != SPI_IP_TYPES_SW_MINOR_VERSION) || \
     (SPI_IPW_TYPES_SW_PATCH_VERSION != SPI_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Ipw_Types.h and Spi_Ip_Types.h are different"
#endif

/* Check if Spi_Ipw_Types.h and Spi_Ipw_Cfg.h are of the same vendor */
#if (SPI_IPW_TYPES_VENDOR_ID != SPI_IPW_VENDOR_ID_CFG_H)
    #error "Spi_Ipw_Types.h and Spi_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if Spi_Ipw_Types.h file and Spi_Ipw_Cfg.h file are of the same Autosar version */
#if ((SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != SPI_IPW_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION != SPI_IPW_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION != SPI_IPW_AR_RELEASE_REVISION_VERSION_CFG_H))
#error "AutoSar Version Numbers of Spi_Ipw_Types.h and Spi_Ipw_Cfg.h are different"
#endif
#if ((SPI_IPW_TYPES_SW_MAJOR_VERSION != SPI_IPW_SW_MAJOR_VERSION_CFG_H) || \
     (SPI_IPW_TYPES_SW_MINOR_VERSION != SPI_IPW_SW_MINOR_VERSION_CFG_H) || \
     (SPI_IPW_TYPES_SW_PATCH_VERSION != SPI_IPW_SW_PATCH_VERSION_CFG_H))
#error "Software Version Numbers of Spi_Ipw_Types.h and Spi_Ipw_Cfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief This enum contains all IPs which can integrate SPI functionalities
 */
typedef enum
{
    SPI_OVER_SPI = 0
} Spi_Ipw_SupportedIpsType;

/** 
 * @bried This struct contains config structure for all IPs available.
 */
typedef struct
{
    const Spi_Ip_ConfigType *DspiIpConfig;
    #if ((SPI_IPW_DMA_USED == STD_ON) && (SPI_IPW_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
    Spi_Ip_FastTransferType *DspiFastTransferCfg; /* config structure for a sequence transfer with Dma Fast */
    #endif
} Spi_Ipw_IpConfigType;

/** 
 * @bried This struct contains config structure for all external device available.
 */
typedef struct
{
    const Spi_Ip_ExternalDeviceType *DspiExternalDeviceConfig;
} Spi_Ipw_ExternalDeviceType;

/**
* @brief   This structure holds the HWUnit configuration parameters.
*
* @implements Spi_HWUnitConfigType_struct
*/
typedef struct
{
    Spi_Ipw_SupportedIpsType IpType;
    uint8 Instance;
    uint32 SpiCoreUse;
    Spi_Ipw_IpConfigType IpConfig;
    uint32 IsSync;
} Spi_HWUnitConfigType;

/**
* @brief   This structure holds the PhyUnit configuration.
*/
typedef struct
{
    /** @brief Point to PhyUnit configuration. */
    const Spi_HWUnitConfigType * PhyUnitConfig;
} Spi_PhyUnitsConfigType;

/**
* @brief   This structure holds the configuration parameters for each ExternalDevice.
*
*/
typedef struct
{
    Spi_Ipw_SupportedIpsType IpType;
    uint8 Instance;
    Spi_Ipw_ExternalDeviceType ExternalDeviceConfig;
    uint32 SpiCoreUse;
} Spi_ExternalDeviceConfigType;

/**
* @brief   This structure holds the ExternalDevice configuration.
*/
typedef struct
{
    /** @brief Point to ExternalDevice configuration. */
    const Spi_ExternalDeviceConfigType * ExDeviceConfig;
} Spi_ExDevicesConfigType;

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

#endif /*SPI_IPW_TYPES_H*/
