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

#ifndef PORT_CFG_H
#define PORT_CFG_H

/**
*   @file    Port_Cfg.h
*
*   @implements Port_Cfg.h_Artifact
*   @defgroup   Port_CFG Port CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port_PBcfg.h"
#include "Siul2_Port_Ip_Types.h"
#include "Siul2_Port_Ip_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module description file
* @details The integration of incompatible files shall be avoided.
*/
#define PORT_CFG_VENDOR_ID_H                       43
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION_H        4
#define PORT_CFG_AR_RELEASE_MINOR_VERSION_H        7
#define PORT_CFG_AR_RELEASE_REVISION_VERSION_H     0
#define PORT_CFG_SW_MAJOR_VERSION_H                2
#define PORT_CFG_SW_MINOR_VERSION_H                0
#define PORT_CFG_SW_PATCH_VERSION_H                0

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port_Cfg.h and Port_PBcfg.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != PORT_VENDOR_ID_PBCFG_H)
    #error "Port_Cfg.h and Port_PBcfg.h have different vendor IDs"
#endif
 /* Check if the files Port_Cfg.h and Port_PBcfg.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H != PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_H) ||   \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H != PORT_AR_RELEASE_MINOR_VERSION_PBCFG_H) ||   \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != PORT_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if the files Port_Cfg.h and Port_PBcfg.h are of the same software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != PORT_SW_MAJOR_VERSION_PBCFG_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != PORT_SW_MINOR_VERSION_PBCFG_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != PORT_SW_PATCH_VERSION_PBCFG_H)     \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if the files Port_Cfg.h and Siul2_Port_Ip_Types.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != SIUL2_PORT_IP_TYPES_VENDOR_ID_H)
    #error "Port_Cfg.h and Siul2_Port_Ip_Types.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Types.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H    != SIUL2_PORT_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H    != SIUL2_PORT_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != SIUL2_PORT_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Types.h are different"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Types.h are of the same Software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != SIUL2_PORT_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != SIUL2_PORT_IP_TYPES_SW_MINOR_VERSION_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != SIUL2_PORT_IP_TYPES_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Types.h are different"
#endif

/* Check if the files Port_Cfg.h and Siul2_Port_Ip_Cfg.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != SIUL2_PORT_IP_VENDOR_ID_CFG_H)
    #error "Port_Cfg.h and Siul2_Port_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Cfg.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Cfg.h are different"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Cfg.h are of the same Software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Cfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
/* @implements Port_PinType_typedef */
typedef uint32 Port_PinType;

/**
* @brief Possible directions of a port pin.
* @implements Port_PinDirectionType_enumeration
*/
typedef enum
{
  PORT_PIN_IN = 0,        /**< @brief Sets port pin as input. */
  PORT_PIN_OUT,           /**< @brief Sets port pin as output. */
  PORT_PIN_INOUT,         /**< @brief Sets port pin as bidirectional. */
  PORT_PIN_HIGH_Z         /**< @brief Sets port pin as high_z. */
} Port_PinDirectionType;

/**
* @brief Different port pin modes.
* @details A port pin shall be configurable with a number of port pin modes (type Port_PinModeType).
*        The type Port_PinModeType shall be used with the function call Port_SetPinMode
* @implements Port_PinModeType_typedef
*/
typedef uint8 Port_PinModeType;

/**
* @brief   A SIUL2 register value.
* @details A port register shall be written with a 32 bits value (type Port_RegValueType).
*          The type Port_RegValueType shall be used with the function call Port_SetPinMode
*
*/
typedef uint32 Port_RegValueType;

/**
* @brief Data type used for IMCR Configuration.
* @details This type should be chosen for the specific MCU platform (best performance).
*
* @api
*/
typedef uint8  Port_Siul2_ImcrConfigType;

/**
* @brief   Single pin configuration.
* @details This structure contains all configuration parameters of a single pin
*          identified by @p SIUPin.
*
* @api
*/
typedef struct
{
  uint16 u16MscrIdx;         /**< @brief Index of the pin's Mscr */
  uint32 u32MSCR;            /**< @brief Pad Control Register */
#ifdef IPV_SIUL2_ODC_SUPPORT_U8
  uint32 u32ODC;             /**< @brief Pad Output Driver Control Configuration */
#endif
  uint8 u8MscrSiulInstance; /**< @brief Siul Instance */
  uint8 u8PDO;              /**< @brief Pad Data Output */
  Port_PinDirectionType ePadDir;            /**< @brief Pad Data Direction */
  boolean bGPIO;              /**< @brief GPIO initial mode*/
  boolean bDC;                /**< @brief Direction changebility*/
  boolean bMC;                /**< @brief Mode changebility*/
  boolean bImcr;              /**< @brief Imcr available */
  uint16 u16ImcrIdx;         /**< @brief Index of the pin's Imcr*/
} Port_Siul2_PinConfigType;


/**
* @brief   Default pin.
* @details This structure contains information about Mscr and Siul Instance for unused pins
*
* @api
*/
typedef struct
{
  uint16 u16MscrIdx;           /**< @brief Id of not used Mscr */
  uint8 u8MscrSiulInstance;    /**< @brief Siul Instance of not used Mscr */
  boolean bNoGpio;             /**< @brief Mscr which do not have GPIO mode */
}Port_Siul2_UnUsedPinType;

/**
* @brief   Default pin configuration.
* @details This structure contains all configuration parameters of a Default pin
*
* @api
*/
typedef struct
{
  uint32   u32MSCR;          /**< Content of Mscr Register */
  uint8   u8PDO;            /**< Pad Data Output */
} Port_Siul2_UnUsedPinConfigType;

/**
* @brief   DiPort signal configuration.
* @details This structure contains all configuration parameters of a DiPort Signal pin
*
* @api
*/
typedef struct
{
  uint8 u8MscrSiulInstance;   /**< @brief Siul Instance of the Mscr configuring the DiPort signal */
  uint16 u16MscrIdx;           /**< @brief Index of the Mscr configuring the DiPort signal */
  uint8 u8MscrValue;          /**< @brief Value of the Mscr configuring the DiPort signal */
} Port_DiPort_SignalConfigType;

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @brief Enable/Disable multicore function from the driver
*/
#define PORT_MULTICORE_ENABLED              (STD_OFF)

/**
* @brief The number of SIUL2 instances on the platform
*/
#define PORT_NUM_SIUL2_INSTANCES_U8         ((uint8)1)

/**
* @brief List of identifiers for each of the SIUL2 instances on the platform
*/
#define PORT_SIUL2_0_U8             ((uint8)0)

/**
* @brief Defines specifying number of IMCRs for each of the SIUL2 instances on the platform
*/
#define PORT_SIUL2_0_NUM_IMCRS_U16             ((uint16)108)

#define SHL_PAD_U32(x)                      ((uint32)(((uint32)1) << (x)))

/**
* @brief PSMI setting not available
* @note The current platform does not implement pad selection for multiplexed input for current pin.
*       Used for better readability of PSMI settings.
*
*/
#define NO_INPUTMUX_U16                 ((uint16)0xFFFFU)

/** @brief Port GPIO Mode */
#define PORT_GPIO_MODE                  ((Port_PinModeType)0)
/** @brief Port Alternate 1 Mode */
#define PORT_ALT1_FUNC_MODE             ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_ALT2_FUNC_MODE             ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_ALT3_FUNC_MODE             ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_ALT4_FUNC_MODE             ((Port_PinModeType)4)
/** @brief Port Alternate 5 Mode */
#define PORT_ALT5_FUNC_MODE             ((Port_PinModeType)5)
/** @brief Port Alternate 6 Mode */
#define PORT_ALT6_FUNC_MODE             ((Port_PinModeType)6)
/** @brief Port Alternate 7 Mode */
#define PORT_ALT7_FUNC_MODE             ((Port_PinModeType)7)
/** @brief Port Output Mode */
#define PORT_ONLY_OUTPUT_MODE           ((Port_PinModeType)8)
/** @brief Port Input Mode */
#define PORT_ONLY_INPUT_MODE            ((Port_PinModeType)9)
/** @brief Port Input 1 Mode */
#define PORT_INPUT1_MODE                ((Port_PinModeType)10)
/** @brief Port Input 2 Mode */
#define PORT_INPUT2_MODE                ((Port_PinModeType)11)
/** @brief Port Input 3 Mode */
#define PORT_INPUT3_MODE                ((Port_PinModeType)12)
/** @brief Port Input 4 Mode */
#define PORT_INPUT4_MODE                ((Port_PinModeType)13)
/** @brief Port Input 5 Mode */
#define PORT_INPUT5_MODE                ((Port_PinModeType)14)
/** @brief Port Input/Output 1 Mode */
#define PORT_INOUT1_MODE                ((Port_PinModeType)15)
/** @brief Port Input/Output 2 Mode */
#define PORT_INOUT2_MODE                ((Port_PinModeType)16)
/** @brief Port Input/Output 3 Mode */
#define PORT_INOUT3_MODE                ((Port_PinModeType)17)
/** @brief Port Input/Output 4 Mode */
#define PORT_INOUT4_MODE                ((Port_PinModeType)18)
/** @brief Port Input/Output 5 Mode */
#define PORT_INOUT5_MODE                ((Port_PinModeType)19)
/** @brief Port Input/Output 6 Mode */
#define PORT_INOUT6_MODE                ((Port_PinModeType)20)
/** @brief Port Input/Output 7 Mode */
#define PORT_INOUT7_MODE                ((Port_PinModeType)21)
/** @brief Port Only Input/Output Mode */
#define PORT_ONLY_INOUT_MODE            ((Port_PinModeType)22)

/** @brief Number of distinct pin modes for all pins on the platform */
#define PORT_NUM_PIN_MODES_U8           ((uint8)23)

/** @brief Informs the IP layer that there is no support
*          for ANALOG function on this platform */
#define PORT_NO_ANALOG_MODE             (STD_ON)

/** @brief Number of 16 pins blocks containing all pins on the platform */
#define PORT_NUM_16PIN_BLOCKS_U8         ((uint8)7)

/** @brief Port Abstraction Modes */
#define SIUL2_0_PORT0_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT0_GMAC_1_GMAC_1_TX_CLK_OUT             (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT0_GMAC_1_GMAC_1_TX_CLK_IN              (PORT_INPUT1_MODE)
#define SIUL2_0_PORT0_GMAC_1_GMAC_1_TX_CLK_INOUT           (PORT_INOUT1_MODE)
#define SIUL2_0_PORT1_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT1_GMAC_1_GMAC_1_TX_EN_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT1_GMAC_1_GMAC_1_TX_EN_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT1_GMAC_1_GMAC_1_TX_EN_INOUT            (PORT_INOUT1_MODE)
#define SIUL2_0_PORT2_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT2_GMAC_1_GMAC_1_TXD0_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT2_GMAC_1_GMAC_1_TXD0_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT2_GMAC_1_GMAC_1_TXD0_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT3_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT3_GMAC_1_GMAC_1_TXD1_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT3_GMAC_1_GMAC_1_TXD1_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT3_GMAC_1_GMAC_1_TXD1_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT4_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT4_GMAC_1_GMAC_1_TXD2_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT4_GMAC_1_GMAC_1_TXD2_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT4_GMAC_1_GMAC_1_TXD2_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT5_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT5_GMAC_1_GMAC_1_TXD3_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT5_GMAC_1_GMAC_1_TXD3_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT5_GMAC_1_GMAC_1_TXD3_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT6_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT6_GMAC_1_GMAC_1_RX_CLK_OUT             (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT6_GMAC_1_GMAC_1_RX_CLK_IN              (PORT_INPUT1_MODE)
#define SIUL2_0_PORT6_GMAC_1_GMAC_1_RX_CLK_INOUT           (PORT_INOUT1_MODE)
#define SIUL2_0_PORT7_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT7_GMAC_1_GMAC_1_RXDV_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT7_GMAC_1_GMAC_1_RXDV_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT7_GMAC_1_GMAC_1_RXDV_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT8_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT8_GMAC_1_GMAC_1_RXD0_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT8_GMAC_1_GMAC_1_RXD0_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT8_GMAC_1_GMAC_1_RXD0_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT9_GPIO                                 (PORT_GPIO_MODE)
#define SIUL2_0_PORT9_GMAC_1_GMAC_1_RXD1_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT9_GMAC_1_GMAC_1_RXD1_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT9_GMAC_1_GMAC_1_RXD1_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT10_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT10_GMAC_1_GMAC_1_RXD2_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT10_GMAC_1_GMAC_1_RXD2_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT10_GMAC_1_GMAC_1_RXD2_INOUT            (PORT_INOUT1_MODE)
#define SIUL2_0_PORT11_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT11_GMAC_1_GMAC_1_RXD3_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT11_GMAC_1_GMAC_1_RXD3_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT11_GMAC_1_GMAC_1_RXD3_INOUT            (PORT_INOUT1_MODE)
#define SIUL2_0_PORT12_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT12_GMAC_1_GMAC_1_RMII_REF_CLK_OUT      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT12_GMAC_1_GMAC_1_RMII_REF_CLK_IN       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT12_GMAC_1_GMAC_1_RMII_REF_CLK_INOUT    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT13_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT13_GMAC_1_GMAC_1_COL_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT14_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT14_GMAC_1_GMAC_1_CRS_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT15_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT15_GMAC_1_GMAC_1_RX_ER_IN              (PORT_INPUT1_MODE)
#define SIUL2_0_PORT16_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT16_GMAC_1_GMAC_1_MD_OUT                (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT16_GMAC_1_GMAC_1_MD_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT16_GMAC_1_GMAC_1_MD_INOUT              (PORT_INOUT1_MODE)
#define SIUL2_0_PORT17_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT17_GMAC_1_GMAC_1_MDC_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT18_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT18_CTE_0_CTE_0_RCS_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT18_CTE_0_CTE_0_RCS_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT18_GMAC_1_GMAC_1_PST_TS_TRIG0_IN       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT18_GMAC_1_GMAC_1_AUX_TRIG2_IN          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT18_CTE_0_CTE_0_RCS_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT19_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT19_GMAC_1_GMAC_1_PPS2_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT20_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT20_GMAC_1_GMAC_1_TS_CLK_OUT            (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT20_GMAC_1_GMAC_1_TS_CLK_IN             (PORT_INPUT1_MODE)
#define SIUL2_0_PORT20_GMAC_1_GMAC_1_TS_CLK_INOUT          (PORT_INOUT1_MODE)
#define SIUL2_0_PORT21_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT21_CTE_0_CTE_0_CTEP0_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT21_CTI_CTI_TRIG_I_1_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT22_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT22_CTI_CTI_TRIG_I_ACK_1_OUT            (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT22_CTE_0_CTE_0_CTEP1_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT23_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT23_CTI_CTI_TRIG_O_1_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT23_CTE_0_CTE_0_CTEP2_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT24_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT24_CTE_0_CTE_0_CTEP3_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT24_CTI_CTI_TRIG_O_ACK_1_IN             (PORT_INPUT1_MODE)
#define SIUL2_0_PORT25_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT25_CTE_0_CTE_0_CTEP4_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT26_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT26_CTE_0_CTE_0_CTEP5_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT27_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT27_CTE_0_CTE_0_CTEP6_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT27_MIPICSI_1_MIPICSI_1_TRIG_OUT        (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT28_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT28_CTE_0_CTE_0_CTEP7_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT28_MIPICSI_0_MIPICSI_0_TRIG_OUT        (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT29_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT29_FTM_0_FTM_0_CH6_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT29_MC_CGL_0_MC_CGL_0_CLK_OUT0_OUT      (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT29_SIUL_0_SIUL_0_EIRQ0_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT29_CTU_0_CTU_0_EXT_IN_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT29_FTM_0_FTM_0_CH6_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT29_FTM_0_FTM_0_CH6_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT30_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT30_FTM_0_FTM_0_CH7_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT30_MC_CGL_0_MC_CGL_0_CLK_OUT1_OUT      (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT30_SIUL_0_SIUL_0_EIRQ1_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT30_FTM_0_FTM_0_CH7_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT30_FTM_0_FTM_0_CH7_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT31_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT31_DSPI_0_DSPI_0_SCK_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT31_I2C_1_I2C_1_SCL_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT31_SIUL_0_SIUL_0_EIRQ2_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT31_DSPI_0_DSPI_0_SCK_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT31_I2C_1_I2C_1_SCL_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT31_DSPI_0_DSPI_0_SCK_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT31_I2C_1_I2C_1_SCL_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT32_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT32_DSPI_0_DSPI_0_SOUT_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT32_FTM_0_FTM_0_CH0_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT32_SIUL_0_SIUL_0_EIRQ3_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT32_FTM_0_FTM_0_CH0_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT32_FTM_0_FTM_0_CH0_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT33_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT33_FTM_0_FTM_0_CH1_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT33_SIUL_0_SIUL_0_EIRQ4_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT33_DSPI_0_DSPI_0_SIN_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT33_FTM_0_FTM_0_CH1_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT33_FTM_0_FTM_0_CH1_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT34_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT34_DSPI_0_DSPI_0_PCS0_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT34_I2C_1_I2C_1_SDA_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT34_SIUL_0_SIUL_0_EIRQ5_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT34_DSPI_0_DSPI_0_PCS0_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT34_I2C_1_I2C_1_SDA_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT34_DSPI_0_DSPI_0_PCS0_INOUT            (PORT_INOUT1_MODE)
#define SIUL2_0_PORT34_I2C_1_I2C_1_SDA_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT35_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT35_DSPI_0_DSPI_0_PCS2_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT35_LIN_0_LIN_0_TX_OUT                  (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT35_I2C_1_I2C_1_SCL_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT35_SIUL_0_SIUL_0_EIRQ6_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT35_I2C_1_I2C_1_SCL_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT35_I2C_1_I2C_1_SCL_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT36_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT36_DSPI_0_DSPI_0_PCS1_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT36_FTM_0_FTM_0_CH2_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT36_I2C_1_I2C_1_SDA_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT36_SIUL_0_SIUL_0_EIRQ7_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT36_FTM_0_FTM_0_CH2_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT36_I2C_1_I2C_1_SDA_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT36_LIN_0_LIN_0_RX_IN                   (PORT_INPUT3_MODE)
#define SIUL2_0_PORT36_FTM_0_FTM_0_CH2_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT36_I2C_1_I2C_1_SDA_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT37_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT37_QSPI_0_QSPI_0_INT_B_IN              (PORT_INPUT1_MODE)
#define SIUL2_0_PORT38_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT38_FTM_0_FTM_0_CH2_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT38_SIUL_0_SIUL_0_EIRQ8_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT38_FTM_0_FTM_0_CH2_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT38_FTM_0_FTM_0_CH2_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT39_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT39_SIUL_0_SIUL_0_EIRQ26_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT39_CAN_0_CAN_0_RX_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT40_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT40_CAN_0_CAN_0_TX_OUT                  (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT40_FTM_0_FTM_0_CH5_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT40_FTM_0_FTM_0_CH5_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT40_FTM_0_FTM_0_CH5_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT41_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT41_FTM_0_FTM_0_CH5_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT41_SIUL_0_SIUL_0_EIRQ9_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT41_CAN_1_CAN_1_RX_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT41_FTM_0_FTM_0_CH5_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT41_FTM_0_FTM_0_CH5_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT42_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT42_CAN_1_CAN_1_TX_OUT                  (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT42_FTM_0_FTM_0_CH4_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT42_SIUL_0_SIUL_0_EIRQ10_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT42_FTM_0_FTM_0_CH4_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT42_FTM_0_FTM_0_CH4_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT43_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT43_DSPI_1_DSPI_1_SCK_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT43_BOOT_0_BOOT_0_RCON0_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT43_SIUL_0_SIUL_0_EIRQ11_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT43_DSPI_1_DSPI_1_SCK_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT43_DSPI_1_DSPI_1_SCK_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT44_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT44_DSPI_1_DSPI_1_SOUT_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT44_BOOT_0_BOOT_0_RCON1_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT44_SIUL_0_SIUL_0_EIRQ12_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT45_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT45_BOOT_0_BOOT_0_RCON2_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT45_SIUL_0_SIUL_0_EIRQ13_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT45_DSPI_1_DSPI_1_SIN_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT46_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT46_DSPI_1_DSPI_1_PCS0_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT46_BOOT_0_BOOT_0_RCON3_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT46_SIUL_0_SIUL_0_EIRQ14_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT46_DSPI_1_DSPI_1_PCS0_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT46_DSPI_1_DSPI_1_PCS0_INOUT            (PORT_INOUT1_MODE)
#define SIUL2_0_PORT47_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT47_DSPI_2_DSPI_2_PCS3_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT47_FTM_0_FTM_0_CH3_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT47_BOOT_0_BOOT_0_RCON4_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT47_SIUL_0_SIUL_0_EIRQ15_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT47_ADC_0_ADC_0_INJ_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT47_ADC_0_ADC_0_TRIG_IN                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT47_FTM_0_FTM_0_CH3_IN                  (PORT_INPUT3_MODE)
#define SIUL2_0_PORT47_FTM_0_FTM_0_CH3_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT48_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT48_DSPI_2_DSPI_2_SCK_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT48_BOOT_0_BOOT_0_RCON5_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT48_SIUL_0_SIUL_0_EIRQ16_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT48_DSPI_2_DSPI_2_SCK_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT48_DSPI_2_DSPI_2_SCK_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT49_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT49_DSPI_2_DSPI_2_SOUT_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT49_BOOT_0_BOOT_0_RCON6_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT49_SIUL_0_SIUL_0_EIRQ17_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT50_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT50_SIUL_0_SIUL_0_EIRQ18_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT50_BOOT_0_BOOT_0_RCON11_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT50_DSPI_2_DSPI_2_SIN_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT51_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT51_DSPI_2_DSPI_2_PCS0_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT51_SIUL_0_SIUL_0_EIRQ19_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT51_BOOT_0_BOOT_0_RCON12_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT51_DSPI_2_DSPI_2_PCS0_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT51_DSPI_2_DSPI_2_PCS0_INOUT            (PORT_INOUT2_MODE)
#define SIUL2_0_PORT52_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT52_DSPI_1_DSPI_1_PCS1_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT52_DSPI_2_DSPI_2_PCS1_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT52_FTM_0_FTM_0_CH4_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT52_BOOT_0_BOOT_0_RCON9_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT52_SIUL_0_SIUL_0_EIRQ20_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT52_FTM_0_FTM_0_CH4_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT52_FTM_0_FTM_0_CH4_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT53_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT53_DSPI_1_DSPI_1_PCS2_OUT              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT53_DSPI_2_DSPI_2_PCS2_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT53_BOOT_0_BOOT_0_RCON10_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT53_SIUL_0_SIUL_0_EIRQ21_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT54_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT54_I2C_0_I2C_0_SDA_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT54_FTM_0_FTM_0_CH6_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT54_SIUL_0_SIUL_0_EIRQ22_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT54_BOOT_0_BOOT_0_RCON7_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT54_FTM_0_FTM_0_CH6_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT54_I2C_0_I2C_0_SDA_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT54_I2C_0_I2C_0_SDA_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT54_FTM_0_FTM_0_CH6_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT55_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT55_I2C_0_I2C_0_SCL_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT55_FTM_0_FTM_0_CH7_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT55_SIUL_0_SIUL_0_EIRQ23_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT55_BOOT_0_BOOT_0_RCON8_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT55_FTM_0_FTM_0_CH7_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT55_I2C_0_I2C_0_SCL_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT55_I2C_0_I2C_0_SCL_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT55_FTM_0_FTM_0_CH7_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT56_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT56_I2C_1_I2C_1_SCL_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT56_BOOT_0_BOOT_0_RCON13_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT56_SIUL_0_SIUL_0_EIRQ24_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT56_FTM_0_FTM_0_TRIG_1_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT56_I2C_1_I2C_1_SCL_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT56_I2C_1_I2C_1_SCL_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT57_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT57_I2C_1_I2C_1_SDA_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT57_BOOT_0_BOOT_0_RCON14_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT57_SIUL_0_SIUL_0_EIRQ25_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT57_FTM_0_FTM_0_EXT_CLK_IN              (PORT_INPUT1_MODE)
#define SIUL2_0_PORT57_I2C_1_I2C_1_SDA_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT57_I2C_1_I2C_1_SDA_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT58_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT58_LIN_0_LIN_0_TX_OUT                  (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT58_CAN_1_CAN_1_TX_OUT                  (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT58_FTM_0_FTM_0_CH0_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT58_BOOT_0_BOOT_0_RCON15_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT58_FTM_0_FTM_0_CH0_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT58_FTM_0_FTM_0_CH0_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT59_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT59_FTM_0_FTM_0_CH1_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT59_SIUL_0_SIUL_0_EIRQ27_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT59_CAN_1_CAN_1_RX_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT59_FTM_0_FTM_0_CH1_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT59_LIN_0_LIN_0_RX_IN                   (PORT_INPUT3_MODE)
#define SIUL2_0_PORT59_FTM_0_FTM_0_CH1_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT60_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT60_MC_CGL_0_MC_CGL_0_CLK_OUT0_OUT      (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT60_SIUL_0_SIUL_0_EIRQ28_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT61_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT61_I2C_0_I2C_0_SCL_OUT                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT61_DSPI_1_DSPI_1_SCK_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT61_SIUL_0_SIUL_0_EIRQ29_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT61_DSPI_1_DSPI_1_SCK_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT61_GMAC_0_GMAC_0_PST_TS_TRIG0_IN       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT61_GMAC_0_GMAC_0_AUX_TRIG2_IN          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT61_I2C_0_I2C_0_SCL_IN                  (PORT_INPUT4_MODE)
#define SIUL2_0_PORT61_I2C_0_I2C_0_SCL_INOUT               (PORT_INOUT1_MODE)
#define SIUL2_0_PORT61_DSPI_1_DSPI_1_SCK_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT62_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT62_I2C_0_I2C_0_SDA_OUT                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT62_DSPI_1_DSPI_1_PCS0_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT62_GMAC_0_GMAC_0_PPS2_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT62_SIUL_0_SIUL_0_EIRQ30_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT62_DSPI_1_DSPI_1_PCS0_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT62_FTM_0_FTM_0_PHB_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT62_I2C_0_I2C_0_SDA_IN                  (PORT_INPUT3_MODE)
#define SIUL2_0_PORT62_I2C_0_I2C_0_SDA_INOUT               (PORT_INOUT1_MODE)
#define SIUL2_0_PORT62_DSPI_1_DSPI_1_PCS0_INOUT            (PORT_INOUT2_MODE)
#define SIUL2_0_PORT63_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT63_DSPI_1_DSPI_1_SOUT_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT63_FTM_0_FTM_0_CH3_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT63_GMAC_0_GMAC_0_TS_CLK_OUT            (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT63_SIUL_0_SIUL_0_EIRQ31_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT63_FTM_0_FTM_0_CH3_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT63_GMAC_0_GMAC_0_TS_CLK_IN             (PORT_INPUT2_MODE)
#define SIUL2_0_PORT63_FTM_0_FTM_0_CH3_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT63_GMAC_0_GMAC_0_TS_CLK_INOUT          (PORT_INOUT4_MODE)
#define SIUL2_0_PORT64_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT64_GMAC_0_GMAC_0_TX_CLK_OUT            (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT64_GMAC_0_GMAC_0_TX_CLK_IN             (PORT_INPUT1_MODE)
#define SIUL2_0_PORT64_GMAC_0_GMAC_0_TX_CLK_INOUT          (PORT_INOUT4_MODE)
#define SIUL2_0_PORT65_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT65_GMAC_0_GMAC_0_TX_EN_OUT             (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT65_GMAC_0_GMAC_0_TX_EN_IN              (PORT_INPUT1_MODE)
#define SIUL2_0_PORT65_GMAC_0_GMAC_0_TX_EN_INOUT           (PORT_INOUT4_MODE)
#define SIUL2_0_PORT66_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT66_GMAC_0_GMAC_0_TXD0_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT66_GMAC_0_GMAC_0_TXD0_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT66_GMAC_0_GMAC_0_TXD0_INOUT            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT67_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT67_GMAC_0_GMAC_0_TXD1_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT67_GMAC_0_GMAC_0_TXD1_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT67_GMAC_0_GMAC_0_TXD1_INOUT            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT68_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT68_GMAC_0_GMAC_0_TXD2_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT68_GMAC_0_GMAC_0_TXD2_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT68_GMAC_0_GMAC_0_TXD2_INOUT            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT69_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT69_GMAC_0_GMAC_0_TXD3_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT69_GMAC_0_GMAC_0_TXD3_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT69_GMAC_0_GMAC_0_TXD3_INOUT            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT70_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT70_GMAC_0_GMAC_0_RX_CLK_OUT            (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT70_GMAC_0_GMAC_0_RX_CLK_IN             (PORT_INPUT1_MODE)
#define SIUL2_0_PORT70_GMAC_0_GMAC_0_RX_CLK_INOUT          (PORT_INOUT4_MODE)
#define SIUL2_0_PORT71_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT71_GMAC_0_GMAC_0_RXDV_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT71_GMAC_0_GMAC_0_RXDV_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT71_GMAC_0_GMAC_0_RXDV_INOUT            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT72_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT72_GMAC_0_GMAC_0_RXD0_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT72_GMAC_0_GMAC_0_RXD0_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT72_GMAC_0_GMAC_0_RXD0_INOUT            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT73_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT73_GMAC_0_GMAC_0_RXD1_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT73_GMAC_0_GMAC_0_RXD1_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT73_GMAC_0_GMAC_0_RXD1_INOUT            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT74_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT74_GMAC_0_GMAC_0_RXD2_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT74_GMAC_0_GMAC_0_RXD2_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT74_GMAC_0_GMAC_0_RXD2_INOUT            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT75_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT75_GMAC_0_GMAC_0_RXD3_OUT              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT75_GMAC_0_GMAC_0_RXD3_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT75_GMAC_0_GMAC_0_RXD3_INOUT            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT76_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT76_GMAC_0_GMAC_0_RMII_REF_CLK_OUT      (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT76_GMAC_0_GMAC_0_RMII_REF_CLK_IN       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT76_GMAC_0_GMAC_0_RMII_REF_CLK_INOUT    (PORT_INOUT4_MODE)
#define SIUL2_0_PORT77_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT77_DSPI_1_DSPI_1_SIN_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT77_FTM_0_FTM_0_PHA_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT77_GMAC_0_GMAC_0_COL_IN                (PORT_INPUT3_MODE)
#define SIUL2_0_PORT78_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT78_DSPI_1_DSPI_1_PCS1_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT78_FTM_0_FTM_0_CH4_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT78_FTM_0_FTM_0_CH4_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT78_GMAC_0_GMAC_0_CRS_IN                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT78_FTM_0_FTM_0_CH4_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT79_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT79_GMAC_0_GMAC_0_RX_ER_IN              (PORT_INPUT1_MODE)
#define SIUL2_0_PORT80_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT80_GMAC_0_GMAC_0_MD_OUT                (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT80_GMAC_0_GMAC_0_MD_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT80_GMAC_0_GMAC_0_MD_INOUT              (PORT_INOUT4_MODE)
#define SIUL2_0_PORT81_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT81_GMAC_0_GMAC_0_MDC_OUT               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT82_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT82_PLATFORM_NMI_IN                     (PORT_INPUT1_MODE)
#define SIUL2_0_PORT83_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT83_CTE_0_CTE_0_RFS_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT83_CTE_0_CTE_0_RFS_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT83_CTI_CTI_TRIG_I_0_IN                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT83_CTE_0_CTE_0_RFS_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT84_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT84_CTI_CTI_TRIG_I_ACK_0_OUT            (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT85_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT85_CTI_CTI_TRIG_O_0_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT86_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT86_CTI_CTI_TRIG_O_ACK_0_IN             (PORT_INPUT1_MODE)
#define SIUL2_0_PORT87_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT87_CTE_0_CTE_0_RCS_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT87_CTE_0_CTE_0_RCS_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT87_CTE_0_CTE_0_RCS_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT88_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT88_DSPI_3_DSPI_3_SCK_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT88_DSPI_3_DSPI_3_SCK_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT88_DSPI_3_DSPI_3_SCK_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT89_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT89_DSPI_3_DSPI_3_SOUT_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT90_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT90_DSPI_3_DSPI_3_SIN_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT91_GPIO                                (PORT_GPIO_MODE)
#define SIUL2_0_PORT91_DSPI_3_DSPI_3_PCS0_OUT              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT91_DSPI_3_DSPI_3_PCS0_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT91_DSPI_3_DSPI_3_PCS0_INOUT            (PORT_INOUT2_MODE)
#define SIUL2_0_PORT92_JTAG_0_JTAG_0_TDI_IN                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT96_BOOT_0_BOOT_0_BMODE1_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT93_JTAG_0_JTAG_0_TDO_OUT               (PORT_ONLY_OUTPUT_MODE)
#define SIUL2_0_PORT97_BOOT_0_BOOT_0_BMODE2_IN             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT94_MISC_TEST_MODE_IN                   (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT98_JTAG_0_JTAG_0_JCOMP_IN              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT95_JTAG_0_JTAG_0_TMS_IN                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT99_JTAG_0_JTAG_0_TCK_IN                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT100_QSPI_0_QSPI_0_CK_OUT               (PORT_ONLY_OUTPUT_MODE)
#define SIUL2_0_PORT101_QSPI_0_QSPI_0_CS_0_OUT             (PORT_ONLY_OUTPUT_MODE)
#define SIUL2_0_PORT102_QSPI_0_QSPI_0_DATA_0_IN            (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT102_QSPI_0_QSPI_0_DATA_0_OUT           (PORT_ONLY_OUTPUT_MODE)
#define SIUL2_0_PORT102_QSPI_0_QSPI_0_DATA_0_INOUT         (PORT_ONLY_INOUT_MODE)
#define SIUL2_0_PORT103_QSPI_0_QSPI_0_DATA_1_IN            (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT103_QSPI_0_QSPI_0_DATA_1_OUT           (PORT_ONLY_OUTPUT_MODE)
#define SIUL2_0_PORT103_QSPI_0_QSPI_0_DATA_1_INOUT         (PORT_ONLY_INOUT_MODE)
#define SIUL2_0_PORT104_QSPI_0_QSPI_0_DATA_2_IN            (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT104_QSPI_0_QSPI_0_DATA_2_OUT           (PORT_ONLY_OUTPUT_MODE)
#define SIUL2_0_PORT104_QSPI_0_QSPI_0_DATA_2_INOUT         (PORT_ONLY_INOUT_MODE)
#define SIUL2_0_PORT105_QSPI_0_QSPI_0_DATA_3_IN            (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT105_QSPI_0_QSPI_0_DATA_3_OUT           (PORT_ONLY_OUTPUT_MODE)
#define SIUL2_0_PORT105_QSPI_0_QSPI_0_DATA_3_INOUT         (PORT_ONLY_INOUT_MODE)

/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           (STD_ON)

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)
/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/
#define PORT_SET_PIN_MODE_API           (STD_ON)

/**
* @brief Enable/Disable Port_SetPinMode function updating the output level of the pins configured at runtime as GPIO
*/
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL           (STD_OFF)

/**
* @brief Use/remove Port_SetAsUnusedPin/Port_SetAsUnusedPin function from the compiled driver
*
* @implements
*/
#define PORT_SET_AS_UNUSED_PIN_API           (STD_OFF)

/**
* @brief Use/remove Port_ResetPinMode function from the compiled driver
*
* @implements
*/
#define PORT_RESET_PIN_MODE_API               (STD_OFF)

/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API                 (STD_ON)

/**
* @brief The number of configured partition on the platform
*/
#define PORT_MAX_PARTITION              (1U)

/**
* @brief Port code size optimization macro define.
*
*/
#define PORT_CODE_SIZE_OPTIMIZATION           (STD_OFF)

/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*
*/
#define PortConf_PortPin_Uart_Tx 0
#define PortConf_PortPin_DSPI1_PCS0 1
#define PortConf_PortPin_DSPI1_SCK 2
#define PortConf_PortPin_DSPI1_SIN 3
#define PortConf_PortPin_DSPI1_SOUT 4
#define PortConf_PortPin_DSPI2_PCS0 5
#define PortConf_PortPin_DSPI2_SCK 6
#define PortConf_PortPin_DSPI2_SIN 7
#define PortConf_PortPin_DSPI2_SOUT 8
#define PortConf_PortPin_chirpStartIn 9
#define PortConf_PortPin_mcuIntChirpStartOut 10
#define PortConf_PortPin_errorN 11
#define PortConf_PortPin_errorReset 12
#define PortConf_PortPin_tx1IPs 13
#define PortConf_PortPin_tx2IPs 14
#define PortConf_PortPin_tx3IPs 15
#define PortConf_PortPin_tx1QPs 16
#define PortConf_PortPin_tx2QPs 17
#define PortConf_PortPin_tx3QPs 18
#define PortConf_PortPin_hReset 19
#define PortConf_PortPin_mcuIntChirpStartOut_ 20
#define PortConf_PortPin_errorN_ 21
#define PortConf_PortPin_tx1IPs_ 22
#define PortConf_PortPin_tx2IPs_ 23
#define PortConf_PortPin_tx3IPs_ 24
#define PortConf_PortPin_tx1QPs_ 25
#define PortConf_PortPin_tx2QPs_ 26
#define PortConf_PortPin_tx3QPs_ 27

/**
* @brief The maximum number of configured pins
*/
#define PORT_MAX_CONFIGURED_PADS_U16   ((uint16)28)

/**
* @brief Number of UnUsed pin array
*/
#define PORT_MAX_UNUSED_PADS_U16    (78U)
/**
* @brief Port driver Pre-Compile configuration switch
*/
#define    PORT_PRECOMPILE_SUPPORT      (STD_ON)

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Defines for number of entries in the INOUT tables for each of the SIUL2 instances
*/
#define PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16       ((uint16)70)

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/
/**
* @brief   Type defining the size of the arrays used to keep the information about pin mode availability
* @details
*
* @api
*/
typedef uint16 Port_PinModeAvailabilityArrayType[PORT_NUM_PIN_MODES_U8][PORT_NUM_16PIN_BLOCKS_U8];

/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*/
typedef struct
{
    uint16 u16NumPins;                                                           /**< @brief Number of used pads (to be configured) */
    uint16 u16NumUnusedPins;                                                     /**< @brief Number of unused pads */
    uint16 au16NumImcrs[PORT_NUM_SIUL2_INSTANCES_U8];                            /**< @brief Used pads IMCRs number */
    const Port_Siul2_UnUsedPinType *pUnusedPads;                                 /**< @brief Unused pad id's array and SIUL2 instance */
    const Port_Siul2_UnUsedPinConfigType *pUnusedPadConfig;                      /**< @brief Unused pad configuration */
#ifdef PORT_SIUL2_AE_U8
    const Port_Siul2_UnUsedPinConfigType *pSiul2AEUnusedPadConfig;               /**< @brief Unused pad configuration for SIUL2_AE */
#endif /* PORT_SIUL2_AE_U8 */
    const Port_Siul2_PinConfigType *pUsedPadConfig;                              /**< @brief Used pads data configuration */
    const Port_Siul2_ImcrConfigType *pImcrConfig[PORT_NUM_SIUL2_INSTANCES_U8];   /**< @brief Used pads IMCR configuration */
    const uint32 *pau32Port_PinToPartitionMap;                                   /**< @brief Pointer to pin partition mapping */
    const uint8 *pau8Port_PartitionList;                                         /**< @brief Pointer to used partitions */
    const Siul2_Port_Ip_PinSettingsConfig *IpConfigPtr;                          /**< @brief Ip configuration */
} Port_ConfigType;

/**
* @brief Settings for a INMUX register
* @details The structure @p Port_InMuxSettingType manages ExtraFunctions PinMode.
* @api
*/
typedef struct
{
    uint16 u16ImcrIdx;   /**< @brief The id of the INMUX register to be configured */
    uint8  u8ImcrSSS;    /**< @brief The value of the INMUX reg for signal allocation */
    uint8  u8ImcrSiulInstance;       /**< @brief The mode to be configured */
} Port_InMuxSettingType;

/**
* @brief Settings for a INOUT functionality
* @details The structure @p Port_InoutSettingType manages Inout PinModes.
*
* @api
*/
typedef struct
{
    uint16 u16MscrIdx;               /**< @brief The id of the MSCR register to be configured */
    uint8  u8Mode;                   /**< @brief The mode to be configured */
    uint16 u16ImcrIdx;               /**< @brief The id of the INMUX register to be configured */
    uint8  u8ImcrSSS;                /**< @brief The value of the INMUX reg for signal allocation */
    uint8  u8ImcrSiulInstance;       /**< @brief SIUL2 instance where IMCR resides */
} Port_InoutSettingType;

/*=================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of values storing the length of tables with INOUT functionality information on each of the SIUL2 instance on the platform
*/
extern const uint16 Port_au16NumInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8];

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"


#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about pin availability on each of the SIUL2 instance on the platform
*/
extern const Port_PinModeAvailabilityArrayType * const Port_apSiul2InstancePinModeAvailability[PORT_NUM_SIUL2_INSTANCES_U8];

/**
* @brief Array of pointers to the tables storing information about IN functionality on each of the SIUL2 instance on the platform
*/
extern const Port_InMuxSettingType * const Port_apInMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8];

/**
* @brief Array of pointers to the tables storing information about indexes in the IN functionality tables on each of the SIUL2 instance on the platform
*/
extern const uint16 * const Port_apInMuxSettingsIndex[PORT_NUM_SIUL2_INSTANCES_U8];

/**
* @brief Array of pointers to the tables storing information about INOUT functionality on each of the SIUL2 instance on the platform
*/
extern const Port_InoutSettingType * const Port_apInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8];

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */
/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */

/* End of File */

