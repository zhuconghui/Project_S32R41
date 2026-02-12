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
*   @file    Port_PBcfg.c
*
*   @implements Port_PBcfg.c_Artifact
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define PORT_VENDOR_ID_PBCFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C        7
#define PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C     0
#define PORT_SW_MAJOR_VERSION_PBCFG_C                2
#define PORT_SW_MINOR_VERSION_PBCFG_C                0
#define PORT_SW_PATCH_VERSION_PBCFG_C                0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_PBCFG_C != PORT_VENDOR_ID)
    #error "Port_PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_PBcfg.c and Port.h are different"
#endif
/* Check if Port_PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_PBcfg.c and Port.h are different"
#endif
/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

/**
* @brief Array containing list of partition which used in driver
*/
const uint8 au8Port_PartitionList[PORT_MAX_PARTITION] =
{
    1
};

#define PORT_STOP_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"
/**
* @brief Array containing list of mapping information for mappable elements
*/
static const uint32 au32Port_PinToPartitionMap[PORT_MAX_CONFIGURED_PADS_U16] =
{
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001
};

#define PORT_STOP_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"

#if (PORT_MAX_UNUSED_PADS_U16 != 0U)

#define PORT_START_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

/**
* @brief Array containing list of MSCRs that are not used and should be configured with values from NotUsedPortPin container
*/
static const Port_Siul2_UnUsedPinType Port_aUnusedPads[PORT_MAX_UNUSED_PADS_U16] =
{
    { (uint16)0, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)1, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)2, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)3, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)4, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)5, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)6, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)7, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)8, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)9, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)10, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)11, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)12, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)13, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)14, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)15, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)16, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)17, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)19, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)20, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)28, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)29, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)30, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)31, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)32, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)33, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)34, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)35, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)36, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)39, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)40, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)41, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)42, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)54, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)55, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)57, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)59, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)60, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)61, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)62, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)63, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)64, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)65, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)66, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)67, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)68, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)69, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)70, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)71, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)72, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)73, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)74, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)75, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)76, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)77, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)78, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)79, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)80, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)81, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)87, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)88, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)89, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)90, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)91, PORT_SIUL2_0_U8, (boolean)FALSE },
    { (uint16)92, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)93, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)94, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)95, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)96, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)97, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)98, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)99, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)100, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)101, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)102, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)103, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)104, PORT_SIUL2_0_U8, (boolean)TRUE },
    { (uint16)105, PORT_SIUL2_0_U8, (boolean)TRUE }
};

#define PORT_STOP_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

#endif /* (PORT_MAX_UNUSED_PADS_U16 != 0) */

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/**
 * @brief Default Configuration for Pins not initialized
 */
static const Port_Siul2_UnUsedPinConfigType Port_UnusedPinConfig =
{
    /**
    * @note: Configuration of Default pin
    */
    (uint32)0x00080000, (uint8)0
};

/**
* @brief Pin default configuration data for configPB
*/
static const Port_Siul2_PinConfigType Port_aUsedPinConfigs[PORT_MAX_CONFIGURED_PADS_U16] =
{
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)58, (uint32)0x00210001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)46, (uint32)0x00210001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)43, (uint32)0x00210001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)45, (uint32)0x00090000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 29 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)44, (uint32)0x00210001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)51, (uint32)0x00210002, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)48, (uint32)0x00210002, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)50, (uint32)0x00090000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 32 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)49, (uint32)0x00210002, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)18, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)52, (uint32)0x00090000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)47, (uint32)0x00090000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)27, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)21, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)23, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)25, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)22, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)24, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)26, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)82, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)53, (uint32)0x00090000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)56, (uint32)0x00090000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)86, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)84, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)38, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)85, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)83, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)37, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 }
};


/* SIUL2_0 */
/**
* @brief IMCR configuration set by Port_Init() for SIUL2 instance: SIUL2_0
*/
static const Port_Siul2_ImcrConfigType Port_aSIUL2_0_ImcrInitConfig[PORT_SIUL2_0_NUM_IMCRS_U16] =
{
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x01,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x01,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00
};
#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
*/
const Port_ConfigType Port_Config =
{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
    {
        PORT_SIUL2_0_NUM_IMCRS_U16
    },
#if (PORT_MAX_UNUSED_PADS_U16 != 0U)
    Port_aUnusedPads,
#else
    NULL_PTR,
#endif
    &Port_UnusedPinConfig,
    Port_aUsedPinConfigs,
    {
        Port_aSIUL2_0_ImcrInitConfig
    },
    au32Port_PinToPartitionMap,
    au8Port_PartitionList,
    g_pin_mux_InitConfigArr
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */

