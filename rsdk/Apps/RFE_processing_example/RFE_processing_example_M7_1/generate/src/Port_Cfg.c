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
*   @file    Port_Cfg.c
*
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
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_CFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        7
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define PORT_SW_MAJOR_VERSION_CFG_C                2
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                0

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
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
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of elements storing indexes in Port_<SIUL2 Instance>_aInMuxSettings table where IN settings for each pad reside on first SIUL2 instance
*/
static const uint16 Port_SIUL2_0_au16InMuxSettingsIndex[92] =
{
    /* Index to address the input settings for pad 0 */
    (uint16)1,
    /* Index to address the input settings for pad 1 */
    (uint16)2,
    /* Index to address the input settings for pad 2 */
    (uint16)3,
    /* Index to address the input settings for pad 3 */
    (uint16)4,
    /* Index to address the input settings for pad 4 */
    (uint16)5,
    /* Index to address the input settings for pad 5 */
    (uint16)6,
    /* Index to address the input settings for pad 6 */
    (uint16)7,
    /* Index to address the input settings for pad 7 */
    (uint16)8,
    /* Index to address the input settings for pad 8 */
    (uint16)9,
    /* Index to address the input settings for pad 9 */
    (uint16)10,
    /* Index to address the input settings for pad 10 */
    (uint16)11,
    /* Index to address the input settings for pad 11 */
    (uint16)12,
    /* Index to address the input settings for pad 12 */
    (uint16)13,
    /* Index to address the input settings for pad 13 */
    (uint16)14,
    /* Index to address the input settings for pad 14 */
    (uint16)15,
    /* Index to address the input settings for pad 15 */
    (uint16)16,
    /* Index to address the input settings for pad 16 */
    (uint16)17,
    /* Index to address the input settings for pad 17 */
    (uint16)0,
    /* Index to address the input settings for pad 18 */
    (uint16)18,
    /* Index to address the input settings for pad 19 */
    (uint16)0,
    /* Index to address the input settings for pad 20 */
    (uint16)21,
    /* Index to address the input settings for pad 21 */
    (uint16)22,
    /* Index to address the input settings for pad 22 */
    (uint16)0,
    /* Index to address the input settings for pad 23 */
    (uint16)0,
    /* Index to address the input settings for pad 24 */
    (uint16)23,
    /* Index to address the input settings for pad 25 */
    (uint16)0,
    /* Index to address the input settings for pad 26 */
    (uint16)0,
    /* Index to address the input settings for pad 27 */
    (uint16)0,
    /* Index to address the input settings for pad 28 */
    (uint16)0,
    /* Index to address the input settings for pad 29 */
    (uint16)24,
    /* Index to address the input settings for pad 30 */
    (uint16)26,
    /* Index to address the input settings for pad 31 */
    (uint16)27,
    /* Index to address the input settings for pad 32 */
    (uint16)29,
    /* Index to address the input settings for pad 33 */
    (uint16)30,
    /* Index to address the input settings for pad 34 */
    (uint16)32,
    /* Index to address the input settings for pad 35 */
    (uint16)34,
    /* Index to address the input settings for pad 36 */
    (uint16)35,
    /* Index to address the input settings for pad 37 */
    (uint16)38,
    /* Index to address the input settings for pad 38 */
    (uint16)39,
    /* Index to address the input settings for pad 39 */
    (uint16)40,
    /* Index to address the input settings for pad 40 */
    (uint16)41,
    /* Index to address the input settings for pad 41 */
    (uint16)42,
    /* Index to address the input settings for pad 42 */
    (uint16)44,
    /* Index to address the input settings for pad 43 */
    (uint16)45,
    /* Index to address the input settings for pad 44 */
    (uint16)0,
    /* Index to address the input settings for pad 45 */
    (uint16)46,
    /* Index to address the input settings for pad 46 */
    (uint16)47,
    /* Index to address the input settings for pad 47 */
    (uint16)48,
    /* Index to address the input settings for pad 48 */
    (uint16)51,
    /* Index to address the input settings for pad 49 */
    (uint16)0,
    /* Index to address the input settings for pad 50 */
    (uint16)52,
    /* Index to address the input settings for pad 51 */
    (uint16)53,
    /* Index to address the input settings for pad 52 */
    (uint16)54,
    /* Index to address the input settings for pad 53 */
    (uint16)0,
    /* Index to address the input settings for pad 54 */
    (uint16)55,
    /* Index to address the input settings for pad 55 */
    (uint16)57,
    /* Index to address the input settings for pad 56 */
    (uint16)59,
    /* Index to address the input settings for pad 57 */
    (uint16)61,
    /* Index to address the input settings for pad 58 */
    (uint16)63,
    /* Index to address the input settings for pad 59 */
    (uint16)64,
    /* Index to address the input settings for pad 60 */
    (uint16)0,
    /* Index to address the input settings for pad 61 */
    (uint16)67,
    /* Index to address the input settings for pad 62 */
    (uint16)71,
    /* Index to address the input settings for pad 63 */
    (uint16)74,
    /* Index to address the input settings for pad 64 */
    (uint16)76,
    /* Index to address the input settings for pad 65 */
    (uint16)77,
    /* Index to address the input settings for pad 66 */
    (uint16)78,
    /* Index to address the input settings for pad 67 */
    (uint16)79,
    /* Index to address the input settings for pad 68 */
    (uint16)80,
    /* Index to address the input settings for pad 69 */
    (uint16)81,
    /* Index to address the input settings for pad 70 */
    (uint16)82,
    /* Index to address the input settings for pad 71 */
    (uint16)83,
    /* Index to address the input settings for pad 72 */
    (uint16)84,
    /* Index to address the input settings for pad 73 */
    (uint16)85,
    /* Index to address the input settings for pad 74 */
    (uint16)86,
    /* Index to address the input settings for pad 75 */
    (uint16)87,
    /* Index to address the input settings for pad 76 */
    (uint16)88,
    /* Index to address the input settings for pad 77 */
    (uint16)89,
    /* Index to address the input settings for pad 78 */
    (uint16)92,
    /* Index to address the input settings for pad 79 */
    (uint16)94,
    /* Index to address the input settings for pad 80 */
    (uint16)95,
    /* Index to address the input settings for pad 81 */
    (uint16)0,
    /* Index to address the input settings for pad 82 */
    (uint16)96,
    /* Index to address the input settings for pad 83 */
    (uint16)97,
    /* Index to address the input settings for pad 84 */
    (uint16)0,
    /* Index to address the input settings for pad 85 */
    (uint16)0,
    /* Index to address the input settings for pad 86 */
    (uint16)99,
    /* Index to address the input settings for pad 87 */
    (uint16)100,
    /* Index to address the input settings for pad 88 */
    (uint16)101,
    /* Index to address the input settings for pad 89 */
    (uint16)0,
    /* Index to address the input settings for pad 90 */
    (uint16)102,
    /* Index to address the input settings for pad 91 */
    (uint16)103
};

/**
* @brief Array of elements storing indexes in Port_<SIUL2 Instance>_aInMuxSettings table where IN settings for each pad reside on second SIUL2 instance
*/

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of bits storing availability of PortPinModes for MSCRs on first SIUL2 instance
*/
static const Port_PinModeAvailabilityArrayType Port_SIUL2_0_au16PinModeAvailability =
{

    /*  Mode PORT_GPIO_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_GPIO |
        SIUL2_0_PORT1_GPIO |
        SIUL2_0_PORT2_GPIO |
        SIUL2_0_PORT3_GPIO |
        SIUL2_0_PORT4_GPIO |
        SIUL2_0_PORT5_GPIO |
        SIUL2_0_PORT6_GPIO |
        SIUL2_0_PORT7_GPIO |
        SIUL2_0_PORT8_GPIO |
        SIUL2_0_PORT9_GPIO |
        SIUL2_0_PORT10_GPIO |
        SIUL2_0_PORT11_GPIO |
        SIUL2_0_PORT12_GPIO |
        SIUL2_0_PORT13_GPIO |
        SIUL2_0_PORT14_GPIO |
        SIUL2_0_PORT15_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_GPIO |
        SIUL2_0_PORT17_GPIO |
        SIUL2_0_PORT18_GPIO |
        SIUL2_0_PORT19_GPIO |
        SIUL2_0_PORT20_GPIO |
        SIUL2_0_PORT21_GPIO |
        SIUL2_0_PORT22_GPIO |
        SIUL2_0_PORT23_GPIO |
        SIUL2_0_PORT24_GPIO |
        SIUL2_0_PORT25_GPIO |
        SIUL2_0_PORT26_GPIO |
        SIUL2_0_PORT27_GPIO |
        SIUL2_0_PORT28_GPIO |
        SIUL2_0_PORT29_GPIO |
        SIUL2_0_PORT30_GPIO |
        SIUL2_0_PORT31_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_GPIO |
        SIUL2_0_PORT33_GPIO |
        SIUL2_0_PORT34_GPIO |
        SIUL2_0_PORT35_GPIO |
        SIUL2_0_PORT36_GPIO |
        SIUL2_0_PORT37_GPIO |
        SIUL2_0_PORT38_GPIO |
        SIUL2_0_PORT39_GPIO |
        SIUL2_0_PORT40_GPIO |
        SIUL2_0_PORT41_GPIO |
        SIUL2_0_PORT42_GPIO |
        SIUL2_0_PORT43_GPIO |
        SIUL2_0_PORT44_GPIO |
        SIUL2_0_PORT45_GPIO |
        SIUL2_0_PORT46_GPIO |
        SIUL2_0_PORT47_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_GPIO |
        SIUL2_0_PORT49_GPIO |
        SIUL2_0_PORT50_GPIO |
        SIUL2_0_PORT51_GPIO |
        SIUL2_0_PORT52_GPIO |
        SIUL2_0_PORT53_GPIO |
        SIUL2_0_PORT54_GPIO |
        SIUL2_0_PORT55_GPIO |
        SIUL2_0_PORT56_GPIO |
        SIUL2_0_PORT57_GPIO |
        SIUL2_0_PORT58_GPIO |
        SIUL2_0_PORT59_GPIO |
        SIUL2_0_PORT60_GPIO |
        SIUL2_0_PORT61_GPIO |
        SIUL2_0_PORT62_GPIO |
        SIUL2_0_PORT63_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_GPIO |
        SIUL2_0_PORT65_GPIO |
        SIUL2_0_PORT66_GPIO |
        SIUL2_0_PORT67_GPIO |
        SIUL2_0_PORT68_GPIO |
        SIUL2_0_PORT69_GPIO |
        SIUL2_0_PORT70_GPIO |
        SIUL2_0_PORT71_GPIO |
        SIUL2_0_PORT72_GPIO |
        SIUL2_0_PORT73_GPIO |
        SIUL2_0_PORT74_GPIO |
        SIUL2_0_PORT75_GPIO |
        SIUL2_0_PORT76_GPIO |
        SIUL2_0_PORT77_GPIO |
        SIUL2_0_PORT78_GPIO |
        SIUL2_0_PORT79_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_GPIO |
        SIUL2_0_PORT81_GPIO |
        SIUL2_0_PORT82_GPIO |
        SIUL2_0_PORT83_GPIO |
        SIUL2_0_PORT84_GPIO |
        SIUL2_0_PORT85_GPIO |
        SIUL2_0_PORT86_GPIO |
        SIUL2_0_PORT87_GPIO |
        SIUL2_0_PORT88_GPIO |
        SIUL2_0_PORT89_GPIO |
        SIUL2_0_PORT90_GPIO |
        SIUL2_0_PORT91_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT1_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_GMAC_1_GMAC_1_TX_CLK_OUT |
        SIUL2_0_PORT1_GMAC_1_GMAC_1_TX_EN_OUT |
        SIUL2_0_PORT2_GMAC_1_GMAC_1_TXD0_OUT |
        SIUL2_0_PORT3_GMAC_1_GMAC_1_TXD1_OUT |
        SIUL2_0_PORT4_GMAC_1_GMAC_1_TXD2_OUT |
        SIUL2_0_PORT5_GMAC_1_GMAC_1_TXD3_OUT |
        SIUL2_0_PORT6_GMAC_1_GMAC_1_RX_CLK_OUT |
        SIUL2_0_PORT7_GMAC_1_GMAC_1_RXDV_OUT |
        SIUL2_0_PORT8_GMAC_1_GMAC_1_RXD0_OUT |
        SIUL2_0_PORT9_GMAC_1_GMAC_1_RXD1_OUT |
        SIUL2_0_PORT10_GMAC_1_GMAC_1_RXD2_OUT |
        SIUL2_0_PORT11_GMAC_1_GMAC_1_RXD3_OUT |
        SIUL2_0_PORT12_GMAC_1_GMAC_1_RMII_REF_CLK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_GMAC_1_GMAC_1_MD_OUT |
        SIUL2_0_PORT17_GMAC_1_GMAC_1_MDC_OUT |
        SIUL2_0_PORT19_GMAC_1_GMAC_1_PPS2_OUT |
        SIUL2_0_PORT20_GMAC_1_GMAC_1_TS_CLK_OUT |
        SIUL2_0_PORT31_DSPI_0_DSPI_0_SCK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_DSPI_0_DSPI_0_SOUT_OUT |
        SIUL2_0_PORT34_DSPI_0_DSPI_0_PCS0_OUT |
        SIUL2_0_PORT35_DSPI_0_DSPI_0_PCS2_OUT |
        SIUL2_0_PORT36_DSPI_0_DSPI_0_PCS1_OUT |
        SIUL2_0_PORT40_CAN_0_CAN_0_TX_OUT |
        SIUL2_0_PORT42_CAN_1_CAN_1_TX_OUT |
        SIUL2_0_PORT43_DSPI_1_DSPI_1_SCK_OUT |
        SIUL2_0_PORT44_DSPI_1_DSPI_1_SOUT_OUT |
        SIUL2_0_PORT46_DSPI_1_DSPI_1_PCS0_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT52_DSPI_1_DSPI_1_PCS1_OUT |
        SIUL2_0_PORT53_DSPI_1_DSPI_1_PCS2_OUT |
        SIUL2_0_PORT58_LIN_0_LIN_0_TX_OUT |
        SIUL2_0_PORT61_I2C_0_I2C_0_SCL_OUT |
        SIUL2_0_PORT62_I2C_0_I2C_0_SDA_OUT */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT2_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT22_CTI_CTI_TRIG_I_ACK_1_OUT |
        SIUL2_0_PORT23_CTI_CTI_TRIG_O_1_OUT |
        SIUL2_0_PORT29_FTM_0_FTM_0_CH6_OUT |
        SIUL2_0_PORT30_FTM_0_FTM_0_CH7_OUT |
        SIUL2_0_PORT31_I2C_1_I2C_1_SCL_OUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FTM_0_FTM_0_CH0_OUT |
        SIUL2_0_PORT33_FTM_0_FTM_0_CH1_OUT |
        SIUL2_0_PORT34_I2C_1_I2C_1_SDA_OUT |
        SIUL2_0_PORT35_LIN_0_LIN_0_TX_OUT |
        SIUL2_0_PORT36_FTM_0_FTM_0_CH2_OUT |
        SIUL2_0_PORT40_FTM_0_FTM_0_CH5_OUT |
        SIUL2_0_PORT42_FTM_0_FTM_0_CH4_OUT |
        SIUL2_0_PORT47_DSPI_2_DSPI_2_PCS3_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_DSPI_2_DSPI_2_SCK_OUT |
        SIUL2_0_PORT49_DSPI_2_DSPI_2_SOUT_OUT |
        SIUL2_0_PORT51_DSPI_2_DSPI_2_PCS0_OUT |
        SIUL2_0_PORT52_DSPI_2_DSPI_2_PCS1_OUT |
        SIUL2_0_PORT53_DSPI_2_DSPI_2_PCS2_OUT |
        SIUL2_0_PORT54_I2C_0_I2C_0_SDA_OUT |
        SIUL2_0_PORT55_I2C_0_I2C_0_SCL_OUT |
        SIUL2_0_PORT56_I2C_1_I2C_1_SCL_OUT |
        SIUL2_0_PORT57_I2C_1_I2C_1_SDA_OUT |
        SIUL2_0_PORT58_CAN_1_CAN_1_TX_OUT |
        SIUL2_0_PORT61_DSPI_1_DSPI_1_SCK_OUT |
        SIUL2_0_PORT62_DSPI_1_DSPI_1_PCS0_OUT |
        SIUL2_0_PORT63_DSPI_1_DSPI_1_SOUT_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT78_DSPI_1_DSPI_1_PCS1_OUT */
        (uint16)( SHL_PAD_U32(14U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT84_CTI_CTI_TRIG_I_ACK_0_OUT |
        SIUL2_0_PORT85_CTI_CTI_TRIG_O_0_OUT |
        SIUL2_0_PORT88_DSPI_3_DSPI_3_SCK_OUT |
        SIUL2_0_PORT89_DSPI_3_DSPI_3_SOUT_OUT |
        SIUL2_0_PORT91_DSPI_3_DSPI_3_PCS0_OUT */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT3_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT18_CTE_0_CTE_0_RCS_OUT |
        SIUL2_0_PORT21_CTE_0_CTE_0_CTEP0_OUT |
        SIUL2_0_PORT22_CTE_0_CTE_0_CTEP1_OUT |
        SIUL2_0_PORT23_CTE_0_CTE_0_CTEP2_OUT |
        SIUL2_0_PORT24_CTE_0_CTE_0_CTEP3_OUT |
        SIUL2_0_PORT25_CTE_0_CTE_0_CTEP4_OUT |
        SIUL2_0_PORT26_CTE_0_CTE_0_CTEP5_OUT |
        SIUL2_0_PORT27_CTE_0_CTE_0_CTEP6_OUT |
        SIUL2_0_PORT28_CTE_0_CTE_0_CTEP7_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT35_I2C_1_I2C_1_SCL_OUT |
        SIUL2_0_PORT36_I2C_1_I2C_1_SDA_OUT |
        SIUL2_0_PORT38_FTM_0_FTM_0_CH2_OUT |
        SIUL2_0_PORT41_FTM_0_FTM_0_CH5_OUT |
        SIUL2_0_PORT47_FTM_0_FTM_0_CH3_OUT */
        (uint16)( SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT52_FTM_0_FTM_0_CH4_OUT |
        SIUL2_0_PORT54_FTM_0_FTM_0_CH6_OUT |
        SIUL2_0_PORT55_FTM_0_FTM_0_CH7_OUT |
        SIUL2_0_PORT58_FTM_0_FTM_0_CH0_OUT |
        SIUL2_0_PORT59_FTM_0_FTM_0_CH1_OUT |
        SIUL2_0_PORT63_FTM_0_FTM_0_CH3_OUT */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT78_FTM_0_FTM_0_CH4_OUT */
        (uint16)( SHL_PAD_U32(14U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT83_CTE_0_CTE_0_RFS_OUT |
        SIUL2_0_PORT87_CTE_0_CTE_0_RCS_OUT */
        (uint16)( SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT4_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63
        SIUL2_0_PORT62_GMAC_0_GMAC_0_PPS2_OUT |
        SIUL2_0_PORT63_GMAC_0_GMAC_0_TS_CLK_OUT */
        (uint16)( SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_GMAC_0_GMAC_0_TX_CLK_OUT |
        SIUL2_0_PORT65_GMAC_0_GMAC_0_TX_EN_OUT |
        SIUL2_0_PORT66_GMAC_0_GMAC_0_TXD0_OUT |
        SIUL2_0_PORT67_GMAC_0_GMAC_0_TXD1_OUT |
        SIUL2_0_PORT68_GMAC_0_GMAC_0_TXD2_OUT |
        SIUL2_0_PORT69_GMAC_0_GMAC_0_TXD3_OUT |
        SIUL2_0_PORT70_GMAC_0_GMAC_0_RX_CLK_OUT |
        SIUL2_0_PORT71_GMAC_0_GMAC_0_RXDV_OUT |
        SIUL2_0_PORT72_GMAC_0_GMAC_0_RXD0_OUT |
        SIUL2_0_PORT73_GMAC_0_GMAC_0_RXD1_OUT |
        SIUL2_0_PORT74_GMAC_0_GMAC_0_RXD2_OUT |
        SIUL2_0_PORT75_GMAC_0_GMAC_0_RXD3_OUT |
        SIUL2_0_PORT76_GMAC_0_GMAC_0_RMII_REF_CLK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_GMAC_0_GMAC_0_MD_OUT |
        SIUL2_0_PORT81_GMAC_0_GMAC_0_MDC_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT5_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT27_MIPICSI_1_MIPICSI_1_TRIG_OUT |
        SIUL2_0_PORT28_MIPICSI_0_MIPICSI_0_TRIG_OUT |
        SIUL2_0_PORT29_MC_CGL_0_MC_CGL_0_CLK_OUT0_OUT |
        SIUL2_0_PORT30_MC_CGL_0_MC_CGL_0_CLK_OUT1_OUT */
        (uint16)( SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63
        SIUL2_0_PORT60_MC_CGL_0_MC_CGL_0_CLK_OUT0_OUT */
        (uint16)( SHL_PAD_U32(12U)
                ),
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT6_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT7_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ONLY_OUTPUT_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95
        SIUL2_0_PORT93_JTAG_0_JTAG_0_TDO_OUT */
        (uint16)( SHL_PAD_U32(13U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT100_QSPI_0_QSPI_0_CK_OUT |
        SIUL2_0_PORT101_QSPI_0_QSPI_0_CS_0_OUT |
        SIUL2_0_PORT102_QSPI_0_QSPI_0_DATA_0_OUT |
        SIUL2_0_PORT103_QSPI_0_QSPI_0_DATA_1_OUT |
        SIUL2_0_PORT104_QSPI_0_QSPI_0_DATA_2_OUT |
        SIUL2_0_PORT105_QSPI_0_QSPI_0_DATA_3_OUT */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U)
                )
    }
    ,
    /*  Mode PORT_ONLY_INPUT_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT29_SIUL_0_SIUL_0_EIRQ0_IN |
        SIUL2_0_PORT30_SIUL_0_SIUL_0_EIRQ1_IN |
        SIUL2_0_PORT31_SIUL_0_SIUL_0_EIRQ2_IN */
        (uint16)( SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_SIUL_0_SIUL_0_EIRQ3_IN |
        SIUL2_0_PORT33_SIUL_0_SIUL_0_EIRQ4_IN |
        SIUL2_0_PORT34_SIUL_0_SIUL_0_EIRQ5_IN |
        SIUL2_0_PORT35_SIUL_0_SIUL_0_EIRQ6_IN |
        SIUL2_0_PORT36_SIUL_0_SIUL_0_EIRQ7_IN |
        SIUL2_0_PORT38_SIUL_0_SIUL_0_EIRQ8_IN |
        SIUL2_0_PORT39_SIUL_0_SIUL_0_EIRQ26_IN |
        SIUL2_0_PORT41_SIUL_0_SIUL_0_EIRQ9_IN |
        SIUL2_0_PORT42_SIUL_0_SIUL_0_EIRQ10_IN |
        SIUL2_0_PORT43_BOOT_0_BOOT_0_RCON0_IN |
        SIUL2_0_PORT43_SIUL_0_SIUL_0_EIRQ11_IN |
        SIUL2_0_PORT44_BOOT_0_BOOT_0_RCON1_IN |
        SIUL2_0_PORT44_SIUL_0_SIUL_0_EIRQ12_IN |
        SIUL2_0_PORT45_BOOT_0_BOOT_0_RCON2_IN |
        SIUL2_0_PORT45_SIUL_0_SIUL_0_EIRQ13_IN |
        SIUL2_0_PORT46_BOOT_0_BOOT_0_RCON3_IN |
        SIUL2_0_PORT46_SIUL_0_SIUL_0_EIRQ14_IN |
        SIUL2_0_PORT47_BOOT_0_BOOT_0_RCON4_IN |
        SIUL2_0_PORT47_SIUL_0_SIUL_0_EIRQ15_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_BOOT_0_BOOT_0_RCON5_IN |
        SIUL2_0_PORT48_SIUL_0_SIUL_0_EIRQ16_IN |
        SIUL2_0_PORT49_BOOT_0_BOOT_0_RCON6_IN |
        SIUL2_0_PORT49_SIUL_0_SIUL_0_EIRQ17_IN |
        SIUL2_0_PORT50_SIUL_0_SIUL_0_EIRQ18_IN |
        SIUL2_0_PORT50_BOOT_0_BOOT_0_RCON11_IN |
        SIUL2_0_PORT51_SIUL_0_SIUL_0_EIRQ19_IN |
        SIUL2_0_PORT51_BOOT_0_BOOT_0_RCON12_IN |
        SIUL2_0_PORT52_BOOT_0_BOOT_0_RCON9_IN |
        SIUL2_0_PORT52_SIUL_0_SIUL_0_EIRQ20_IN |
        SIUL2_0_PORT53_BOOT_0_BOOT_0_RCON10_IN |
        SIUL2_0_PORT53_SIUL_0_SIUL_0_EIRQ21_IN |
        SIUL2_0_PORT54_SIUL_0_SIUL_0_EIRQ22_IN |
        SIUL2_0_PORT54_BOOT_0_BOOT_0_RCON7_IN |
        SIUL2_0_PORT55_SIUL_0_SIUL_0_EIRQ23_IN |
        SIUL2_0_PORT55_BOOT_0_BOOT_0_RCON8_IN |
        SIUL2_0_PORT56_BOOT_0_BOOT_0_RCON13_IN |
        SIUL2_0_PORT56_SIUL_0_SIUL_0_EIRQ24_IN |
        SIUL2_0_PORT57_BOOT_0_BOOT_0_RCON14_IN |
        SIUL2_0_PORT57_SIUL_0_SIUL_0_EIRQ25_IN |
        SIUL2_0_PORT58_BOOT_0_BOOT_0_RCON15_IN |
        SIUL2_0_PORT59_SIUL_0_SIUL_0_EIRQ27_IN |
        SIUL2_0_PORT60_SIUL_0_SIUL_0_EIRQ28_IN |
        SIUL2_0_PORT61_SIUL_0_SIUL_0_EIRQ29_IN |
        SIUL2_0_PORT62_SIUL_0_SIUL_0_EIRQ30_IN |
        SIUL2_0_PORT63_SIUL_0_SIUL_0_EIRQ31_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95
        SIUL2_0_PORT92_JTAG_0_JTAG_0_TDI_IN |
        SIUL2_0_PORT94_MISC_TEST_MODE_IN |
        SIUL2_0_PORT95_JTAG_0_JTAG_0_TMS_IN */
        (uint16)( SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_BOOT_0_BOOT_0_BMODE1_IN |
        SIUL2_0_PORT97_BOOT_0_BOOT_0_BMODE2_IN |
        SIUL2_0_PORT98_JTAG_0_JTAG_0_JCOMP_IN |
        SIUL2_0_PORT99_JTAG_0_JTAG_0_TCK_IN |
        SIUL2_0_PORT102_QSPI_0_QSPI_0_DATA_0_IN |
        SIUL2_0_PORT103_QSPI_0_QSPI_0_DATA_1_IN |
        SIUL2_0_PORT104_QSPI_0_QSPI_0_DATA_2_IN |
        SIUL2_0_PORT105_QSPI_0_QSPI_0_DATA_3_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U)
                )
    }
    ,
    /*  Mode PORT_INPUT1_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_GMAC_1_GMAC_1_TX_CLK_IN |
        SIUL2_0_PORT1_GMAC_1_GMAC_1_TX_EN_IN |
        SIUL2_0_PORT2_GMAC_1_GMAC_1_TXD0_IN |
        SIUL2_0_PORT3_GMAC_1_GMAC_1_TXD1_IN |
        SIUL2_0_PORT4_GMAC_1_GMAC_1_TXD2_IN |
        SIUL2_0_PORT5_GMAC_1_GMAC_1_TXD3_IN |
        SIUL2_0_PORT6_GMAC_1_GMAC_1_RX_CLK_IN |
        SIUL2_0_PORT7_GMAC_1_GMAC_1_RXDV_IN |
        SIUL2_0_PORT8_GMAC_1_GMAC_1_RXD0_IN |
        SIUL2_0_PORT9_GMAC_1_GMAC_1_RXD1_IN |
        SIUL2_0_PORT10_GMAC_1_GMAC_1_RXD2_IN |
        SIUL2_0_PORT11_GMAC_1_GMAC_1_RXD3_IN |
        SIUL2_0_PORT12_GMAC_1_GMAC_1_RMII_REF_CLK_IN |
        SIUL2_0_PORT13_GMAC_1_GMAC_1_COL_IN |
        SIUL2_0_PORT14_GMAC_1_GMAC_1_CRS_IN |
        SIUL2_0_PORT15_GMAC_1_GMAC_1_RX_ER_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_GMAC_1_GMAC_1_MD_IN |
        SIUL2_0_PORT18_CTE_0_CTE_0_RCS_IN |
        SIUL2_0_PORT20_GMAC_1_GMAC_1_TS_CLK_IN |
        SIUL2_0_PORT21_CTI_CTI_TRIG_I_1_IN |
        SIUL2_0_PORT24_CTI_CTI_TRIG_O_ACK_1_IN |
        SIUL2_0_PORT29_CTU_0_CTU_0_EXT_IN_IN |
        SIUL2_0_PORT30_FTM_0_FTM_0_CH7_IN |
        SIUL2_0_PORT31_DSPI_0_DSPI_0_SCK_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FTM_0_FTM_0_CH0_IN |
        SIUL2_0_PORT33_DSPI_0_DSPI_0_SIN_IN |
        SIUL2_0_PORT34_DSPI_0_DSPI_0_PCS0_IN |
        SIUL2_0_PORT35_I2C_1_I2C_1_SCL_IN |
        SIUL2_0_PORT36_FTM_0_FTM_0_CH2_IN |
        SIUL2_0_PORT37_QSPI_0_QSPI_0_INT_B_IN |
        SIUL2_0_PORT38_FTM_0_FTM_0_CH2_IN |
        SIUL2_0_PORT39_CAN_0_CAN_0_RX_IN |
        SIUL2_0_PORT40_FTM_0_FTM_0_CH5_IN |
        SIUL2_0_PORT41_CAN_1_CAN_1_RX_IN |
        SIUL2_0_PORT42_FTM_0_FTM_0_CH4_IN |
        SIUL2_0_PORT43_DSPI_1_DSPI_1_SCK_IN |
        SIUL2_0_PORT45_DSPI_1_DSPI_1_SIN_IN |
        SIUL2_0_PORT46_DSPI_1_DSPI_1_PCS0_IN |
        SIUL2_0_PORT47_ADC_0_ADC_0_INJ_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_DSPI_2_DSPI_2_SCK_IN |
        SIUL2_0_PORT50_DSPI_2_DSPI_2_SIN_IN |
        SIUL2_0_PORT51_DSPI_2_DSPI_2_PCS0_IN |
        SIUL2_0_PORT52_FTM_0_FTM_0_CH4_IN |
        SIUL2_0_PORT54_FTM_0_FTM_0_CH6_IN |
        SIUL2_0_PORT55_FTM_0_FTM_0_CH7_IN |
        SIUL2_0_PORT56_FTM_0_FTM_0_TRIG_1_IN |
        SIUL2_0_PORT57_FTM_0_FTM_0_EXT_CLK_IN |
        SIUL2_0_PORT58_FTM_0_FTM_0_CH0_IN |
        SIUL2_0_PORT59_CAN_1_CAN_1_RX_IN |
        SIUL2_0_PORT61_DSPI_1_DSPI_1_SCK_IN |
        SIUL2_0_PORT62_DSPI_1_DSPI_1_PCS0_IN |
        SIUL2_0_PORT63_FTM_0_FTM_0_CH3_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_GMAC_0_GMAC_0_TX_CLK_IN |
        SIUL2_0_PORT65_GMAC_0_GMAC_0_TX_EN_IN |
        SIUL2_0_PORT66_GMAC_0_GMAC_0_TXD0_IN |
        SIUL2_0_PORT67_GMAC_0_GMAC_0_TXD1_IN |
        SIUL2_0_PORT68_GMAC_0_GMAC_0_TXD2_IN |
        SIUL2_0_PORT69_GMAC_0_GMAC_0_TXD3_IN |
        SIUL2_0_PORT70_GMAC_0_GMAC_0_RX_CLK_IN |
        SIUL2_0_PORT71_GMAC_0_GMAC_0_RXDV_IN |
        SIUL2_0_PORT72_GMAC_0_GMAC_0_RXD0_IN |
        SIUL2_0_PORT73_GMAC_0_GMAC_0_RXD1_IN |
        SIUL2_0_PORT74_GMAC_0_GMAC_0_RXD2_IN |
        SIUL2_0_PORT75_GMAC_0_GMAC_0_RXD3_IN |
        SIUL2_0_PORT76_GMAC_0_GMAC_0_RMII_REF_CLK_IN |
        SIUL2_0_PORT77_DSPI_1_DSPI_1_SIN_IN |
        SIUL2_0_PORT78_FTM_0_FTM_0_CH4_IN |
        SIUL2_0_PORT79_GMAC_0_GMAC_0_RX_ER_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_GMAC_0_GMAC_0_MD_IN |
        SIUL2_0_PORT82_PLATFORM_NMI_IN |
        SIUL2_0_PORT83_CTE_0_CTE_0_RFS_IN |
        SIUL2_0_PORT86_CTI_CTI_TRIG_O_ACK_0_IN |
        SIUL2_0_PORT87_CTE_0_CTE_0_RCS_IN |
        SIUL2_0_PORT88_DSPI_3_DSPI_3_SCK_IN |
        SIUL2_0_PORT90_DSPI_3_DSPI_3_SIN_IN |
        SIUL2_0_PORT91_DSPI_3_DSPI_3_PCS0_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT2_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT18_GMAC_1_GMAC_1_PST_TS_TRIG0_IN |
        SIUL2_0_PORT29_FTM_0_FTM_0_CH6_IN |
        SIUL2_0_PORT31_I2C_1_I2C_1_SCL_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT33_FTM_0_FTM_0_CH1_IN |
        SIUL2_0_PORT34_I2C_1_I2C_1_SDA_IN |
        SIUL2_0_PORT36_I2C_1_I2C_1_SDA_IN |
        SIUL2_0_PORT41_FTM_0_FTM_0_CH5_IN |
        SIUL2_0_PORT47_ADC_0_ADC_0_TRIG_IN */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT54_I2C_0_I2C_0_SDA_IN |
        SIUL2_0_PORT55_I2C_0_I2C_0_SCL_IN |
        SIUL2_0_PORT56_I2C_1_I2C_1_SCL_IN |
        SIUL2_0_PORT57_I2C_1_I2C_1_SDA_IN |
        SIUL2_0_PORT59_FTM_0_FTM_0_CH1_IN |
        SIUL2_0_PORT61_GMAC_0_GMAC_0_PST_TS_TRIG0_IN |
        SIUL2_0_PORT62_FTM_0_FTM_0_PHB_IN |
        SIUL2_0_PORT63_GMAC_0_GMAC_0_TS_CLK_IN */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT77_FTM_0_FTM_0_PHA_IN |
        SIUL2_0_PORT78_GMAC_0_GMAC_0_CRS_IN */
        (uint16)( SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT83_CTI_CTI_TRIG_I_0_IN */
        (uint16)( SHL_PAD_U32(3U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT3_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT18_GMAC_1_GMAC_1_AUX_TRIG2_IN */
        (uint16)( SHL_PAD_U32(2U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT36_LIN_0_LIN_0_RX_IN |
        SIUL2_0_PORT47_FTM_0_FTM_0_CH3_IN */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT59_LIN_0_LIN_0_RX_IN |
        SIUL2_0_PORT61_GMAC_0_GMAC_0_AUX_TRIG2_IN |
        SIUL2_0_PORT62_I2C_0_I2C_0_SDA_IN */
        (uint16)( SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT77_GMAC_0_GMAC_0_COL_IN */
        (uint16)( SHL_PAD_U32(13U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT4_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63
        SIUL2_0_PORT61_I2C_0_I2C_0_SCL_IN */
        (uint16)( SHL_PAD_U32(13U)
                ),
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT5_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT1_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_GMAC_1_GMAC_1_TX_CLK_INOUT |
        SIUL2_0_PORT1_GMAC_1_GMAC_1_TX_EN_INOUT |
        SIUL2_0_PORT2_GMAC_1_GMAC_1_TXD0_INOUT |
        SIUL2_0_PORT3_GMAC_1_GMAC_1_TXD1_INOUT |
        SIUL2_0_PORT4_GMAC_1_GMAC_1_TXD2_INOUT |
        SIUL2_0_PORT5_GMAC_1_GMAC_1_TXD3_INOUT |
        SIUL2_0_PORT6_GMAC_1_GMAC_1_RX_CLK_INOUT |
        SIUL2_0_PORT7_GMAC_1_GMAC_1_RXDV_INOUT |
        SIUL2_0_PORT8_GMAC_1_GMAC_1_RXD0_INOUT |
        SIUL2_0_PORT9_GMAC_1_GMAC_1_RXD1_INOUT |
        SIUL2_0_PORT10_GMAC_1_GMAC_1_RXD2_INOUT |
        SIUL2_0_PORT11_GMAC_1_GMAC_1_RXD3_INOUT |
        SIUL2_0_PORT12_GMAC_1_GMAC_1_RMII_REF_CLK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_GMAC_1_GMAC_1_MD_INOUT |
        SIUL2_0_PORT20_GMAC_1_GMAC_1_TS_CLK_INOUT |
        SIUL2_0_PORT31_DSPI_0_DSPI_0_SCK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT34_DSPI_0_DSPI_0_PCS0_INOUT |
        SIUL2_0_PORT43_DSPI_1_DSPI_1_SCK_INOUT |
        SIUL2_0_PORT46_DSPI_1_DSPI_1_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT61_I2C_0_I2C_0_SCL_INOUT |
        SIUL2_0_PORT62_I2C_0_I2C_0_SDA_INOUT */
        (uint16)( SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT2_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT29_FTM_0_FTM_0_CH6_INOUT |
        SIUL2_0_PORT30_FTM_0_FTM_0_CH7_INOUT |
        SIUL2_0_PORT31_I2C_1_I2C_1_SCL_INOUT */
        (uint16)( SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FTM_0_FTM_0_CH0_INOUT |
        SIUL2_0_PORT33_FTM_0_FTM_0_CH1_INOUT |
        SIUL2_0_PORT34_I2C_1_I2C_1_SDA_INOUT |
        SIUL2_0_PORT36_FTM_0_FTM_0_CH2_INOUT |
        SIUL2_0_PORT40_FTM_0_FTM_0_CH5_INOUT |
        SIUL2_0_PORT42_FTM_0_FTM_0_CH4_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_DSPI_2_DSPI_2_SCK_INOUT |
        SIUL2_0_PORT51_DSPI_2_DSPI_2_PCS0_INOUT |
        SIUL2_0_PORT54_I2C_0_I2C_0_SDA_INOUT |
        SIUL2_0_PORT55_I2C_0_I2C_0_SCL_INOUT |
        SIUL2_0_PORT56_I2C_1_I2C_1_SCL_INOUT |
        SIUL2_0_PORT57_I2C_1_I2C_1_SDA_INOUT |
        SIUL2_0_PORT61_DSPI_1_DSPI_1_SCK_INOUT |
        SIUL2_0_PORT62_DSPI_1_DSPI_1_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95
        SIUL2_0_PORT88_DSPI_3_DSPI_3_SCK_INOUT |
        SIUL2_0_PORT91_DSPI_3_DSPI_3_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT3_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT18_CTE_0_CTE_0_RCS_INOUT */
        (uint16)( SHL_PAD_U32(2U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT35_I2C_1_I2C_1_SCL_INOUT |
        SIUL2_0_PORT36_I2C_1_I2C_1_SDA_INOUT |
        SIUL2_0_PORT38_FTM_0_FTM_0_CH2_INOUT |
        SIUL2_0_PORT41_FTM_0_FTM_0_CH5_INOUT |
        SIUL2_0_PORT47_FTM_0_FTM_0_CH3_INOUT */
        (uint16)( SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT52_FTM_0_FTM_0_CH4_INOUT |
        SIUL2_0_PORT54_FTM_0_FTM_0_CH6_INOUT |
        SIUL2_0_PORT55_FTM_0_FTM_0_CH7_INOUT |
        SIUL2_0_PORT58_FTM_0_FTM_0_CH0_INOUT |
        SIUL2_0_PORT59_FTM_0_FTM_0_CH1_INOUT |
        SIUL2_0_PORT63_FTM_0_FTM_0_CH3_INOUT */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT78_FTM_0_FTM_0_CH4_INOUT */
        (uint16)( SHL_PAD_U32(14U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT83_CTE_0_CTE_0_RFS_INOUT |
        SIUL2_0_PORT87_CTE_0_CTE_0_RCS_INOUT */
        (uint16)( SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT4_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63
        SIUL2_0_PORT63_GMAC_0_GMAC_0_TS_CLK_INOUT */
        (uint16)( SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_GMAC_0_GMAC_0_TX_CLK_INOUT |
        SIUL2_0_PORT65_GMAC_0_GMAC_0_TX_EN_INOUT |
        SIUL2_0_PORT66_GMAC_0_GMAC_0_TXD0_INOUT |
        SIUL2_0_PORT67_GMAC_0_GMAC_0_TXD1_INOUT |
        SIUL2_0_PORT68_GMAC_0_GMAC_0_TXD2_INOUT |
        SIUL2_0_PORT69_GMAC_0_GMAC_0_TXD3_INOUT |
        SIUL2_0_PORT70_GMAC_0_GMAC_0_RX_CLK_INOUT |
        SIUL2_0_PORT71_GMAC_0_GMAC_0_RXDV_INOUT |
        SIUL2_0_PORT72_GMAC_0_GMAC_0_RXD0_INOUT |
        SIUL2_0_PORT73_GMAC_0_GMAC_0_RXD1_INOUT |
        SIUL2_0_PORT74_GMAC_0_GMAC_0_RXD2_INOUT |
        SIUL2_0_PORT75_GMAC_0_GMAC_0_RXD3_INOUT |
        SIUL2_0_PORT76_GMAC_0_GMAC_0_RMII_REF_CLK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_GMAC_0_GMAC_0_MD_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT5_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT6_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT7_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ONLY_INOUT_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111
        SIUL2_0_PORT102_QSPI_0_QSPI_0_DATA_0_INOUT |
        SIUL2_0_PORT103_QSPI_0_QSPI_0_DATA_1_INOUT |
        SIUL2_0_PORT104_QSPI_0_QSPI_0_DATA_2_INOUT |
        SIUL2_0_PORT105_QSPI_0_QSPI_0_DATA_3_INOUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U)
                )
    }

};

/**
* @brief Array of bits storing availability of PortPinModes for MSCRs on second SIUL2 instance
*/

/**
* @brief Array of elements storing information about IN functionalities on the first SIUL2 instance
*/
static const Port_InMuxSettingType Port_SIUL2_0_aInMuxSettings[104] =
{
    /* INMUX settings for pad not available: */
    { NO_INPUTMUX_U16, 0U, 0U},
    /* INMUX settings for pad PORT0:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_TX_CLK_IN input func */
    {73U, 1U, 0U},
    /* INMUX settings for pad PORT1:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_TX_EN_IN input func */
    {74U, 1U, 0U},
    /* INMUX settings for pad PORT2:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_TXD0_IN input func */
    {75U, 1U, 0U},
    /* INMUX settings for pad PORT3:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_TXD1_IN input func */
    {76U, 1U, 0U},
    /* INMUX settings for pad PORT4:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_TXD2_IN input func */
    {77U, 1U, 0U},
    /* INMUX settings for pad PORT5:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_TXD3_IN input func */
    {78U, 1U, 0U},
    /* INMUX settings for pad PORT6:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_RX_CLK_IN input func */
    {79U, 1U, 0U},
    /* INMUX settings for pad PORT7:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_RXDV_IN input func */
    {80U, 1U, 0U},
    /* INMUX settings for pad PORT8:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_RXD0_IN input func */
    {81U, 1U, 0U},
    /* INMUX settings for pad PORT9:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_RXD1_IN input func */
    {82U, 1U, 0U},
    /* INMUX settings for pad PORT10:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_RXD2_IN input func */
    {83U, 1U, 0U},
    /* INMUX settings for pad PORT11:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_RXD3_IN input func */
    {84U, 1U, 0U},
    /* INMUX settings for pad PORT12:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_RMII_REF_CLK_IN input func */
    {85U, 1U, 0U},
    /* INMUX settings for pad PORT13:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_COL_IN input func */
    {86U, 1U, 0U},
    /* INMUX settings for pad PORT14:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_CRS_IN input func */
    {87U, 1U, 0U},
    /* INMUX settings for pad PORT15:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_RX_ER_IN input func */
    {88U, 1U, 0U},
    /* INMUX settings for pad PORT16:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_MD_IN input func */
    {89U, 1U, 0U},
    /* INMUX settings for pad PORT18:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CTE_0_CTE_0_RCS_IN input func */
    {18U, 2U, 0U},
    /* GMAC_1_GMAC_1_PST_TS_TRIG0_IN input func */
    {104U, 1U, 0U},
    /* GMAC_1_GMAC_1_AUX_TRIG2_IN input func */
    {90U, 1U, 0U},
    /* INMUX settings for pad PORT20:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_1_GMAC_1_TS_CLK_IN input func */
    {91U, 1U, 0U},
    /* INMUX settings for pad PORT21:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CTI_CTI_TRIG_I_1_IN input func */
    {23U, 1U, 0U},
    /* INMUX settings for pad PORT24:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CTI_CTI_TRIG_O_ACK_1_IN input func */
    {20U, 1U, 0U},
    /* INMUX settings for pad PORT29:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CTU_0_CTU_0_EXT_IN_IN input func */
    {24U, 1U, 0U},
    /* FTM_0_FTM_0_CH6_IN input func */
    {40U, 2U, 0U},
    /* INMUX settings for pad PORT30:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH7_IN input func */
    {41U, 2U, 0U},
    /* INMUX settings for pad PORT31:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_0_DSPI_0_SCK_IN input func */
    {25U, 1U, 0U},
    /* I2C_1_I2C_1_SCL_IN input func */
    {94U, 3U, 0U},
    /* INMUX settings for pad PORT32:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH0_IN input func */
    {34U, 1U, 0U},
    /* INMUX settings for pad PORT33:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_0_DSPI_0_SIN_IN input func */
    {26U, 1U, 0U},
    /* FTM_0_FTM_0_CH1_IN input func */
    {35U, 1U, 0U},
    /* INMUX settings for pad PORT34:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_0_DSPI_0_PCS0_IN input func */
    {27U, 1U, 0U},
    /* I2C_1_I2C_1_SDA_IN input func */
    {95U, 3U, 0U},
    /* INMUX settings for pad PORT35:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_1_I2C_1_SCL_IN input func */
    {94U, 1U, 0U},
    /* INMUX settings for pad PORT36:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH2_IN input func */
    {36U, 1U, 0U},
    /* I2C_1_I2C_1_SDA_IN input func */
    {95U, 1U, 0U},
    /* LIN_0_LIN_0_RX_IN input func */
    {96U, 1U, 0U},
    /* INMUX settings for pad PORT37:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QSPI_0_QSPI_0_INT_B_IN input func */
    {97U, 1U, 0U},
    /* INMUX settings for pad PORT38:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH2_IN input func */
    {36U, 2U, 0U},
    /* INMUX settings for pad PORT39:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN_0_CAN_0_RX_IN input func */
    {16U, 1U, 0U},
    /* INMUX settings for pad PORT40:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH5_IN input func */
    {39U, 1U, 0U},
    /* INMUX settings for pad PORT41:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN_1_CAN_1_RX_IN input func */
    {17U, 1U, 0U},
    /* FTM_0_FTM_0_CH5_IN input func */
    {39U, 2U, 0U},
    /* INMUX settings for pad PORT42:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH4_IN input func */
    {38U, 3U, 0U},
    /* INMUX settings for pad PORT43:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_1_DSPI_1_SCK_IN input func */
    {28U, 1U, 0U},
    /* INMUX settings for pad PORT45:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_1_DSPI_1_SIN_IN input func */
    {29U, 1U, 0U},
    /* INMUX settings for pad PORT46:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_1_DSPI_1_PCS0_IN input func */
    {30U, 1U, 0U},
    /* INMUX settings for pad PORT47:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* ADC_0_ADC_0_INJ_IN input func */
    {98U, 1U, 0U},
    /* ADC_0_ADC_0_TRIG_IN input func */
    {99U, 1U, 0U},
    /* FTM_0_FTM_0_CH3_IN input func */
    {37U, 2U, 0U},
    /* INMUX settings for pad PORT48:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_2_DSPI_2_SCK_IN input func */
    {31U, 1U, 0U},
    /* INMUX settings for pad PORT50:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_2_DSPI_2_SIN_IN input func */
    {32U, 1U, 0U},
    /* INMUX settings for pad PORT51:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_2_DSPI_2_PCS0_IN input func */
    {33U, 1U, 0U},
    /* INMUX settings for pad PORT52:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH4_IN input func */
    {38U, 1U, 0U},
    /* INMUX settings for pad PORT54:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH6_IN input func */
    {40U, 1U, 0U},
    /* I2C_0_I2C_0_SDA_IN input func */
    {92U, 1U, 0U},
    /* INMUX settings for pad PORT55:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH7_IN input func */
    {41U, 1U, 0U},
    /* I2C_0_I2C_0_SCL_IN input func */
    {93U, 1U, 0U},
    /* INMUX settings for pad PORT56:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_TRIG_1_IN input func */
    {42U, 1U, 0U},
    /* I2C_1_I2C_1_SCL_IN input func */
    {94U, 2U, 0U},
    /* INMUX settings for pad PORT57:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_EXT_CLK_IN input func */
    {43U, 1U, 0U},
    /* I2C_1_I2C_1_SDA_IN input func */
    {95U, 2U, 0U},
    /* INMUX settings for pad PORT58:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH0_IN input func */
    {34U, 2U, 0U},
    /* INMUX settings for pad PORT59:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN_1_CAN_1_RX_IN input func */
    {17U, 2U, 0U},
    /* FTM_0_FTM_0_CH1_IN input func */
    {35U, 2U, 0U},
    /* LIN_0_LIN_0_RX_IN input func */
    {96U, 2U, 0U},
    /* INMUX settings for pad PORT61:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_1_DSPI_1_SCK_IN input func */
    {28U, 2U, 0U},
    /* GMAC_0_GMAC_0_PST_TS_TRIG0_IN input func */
    {105U, 1U, 0U},
    /* GMAC_0_GMAC_0_AUX_TRIG2_IN input func */
    {54U, 1U, 0U},
    /* I2C_0_I2C_0_SCL_IN input func */
    {93U, 2U, 0U},
    /* INMUX settings for pad PORT62:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_1_DSPI_1_PCS0_IN input func */
    {30U, 2U, 0U},
    /* FTM_0_FTM_0_PHB_IN input func */
    {107U, 1U, 0U},
    /* I2C_0_I2C_0_SDA_IN input func */
    {92U, 2U, 0U},
    /* INMUX settings for pad PORT63:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH3_IN input func */
    {37U, 1U, 0U},
    /* GMAC_0_GMAC_0_TS_CLK_IN input func */
    {55U, 1U, 0U},
    /* INMUX settings for pad PORT64:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_TX_CLK_IN input func */
    {56U, 1U, 0U},
    /* INMUX settings for pad PORT65:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_TX_EN_IN input func */
    {57U, 1U, 0U},
    /* INMUX settings for pad PORT66:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_TXD0_IN input func */
    {58U, 1U, 0U},
    /* INMUX settings for pad PORT67:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_TXD1_IN input func */
    {59U, 1U, 0U},
    /* INMUX settings for pad PORT68:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_TXD2_IN input func */
    {60U, 1U, 0U},
    /* INMUX settings for pad PORT69:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_TXD3_IN input func */
    {61U, 1U, 0U},
    /* INMUX settings for pad PORT70:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_RX_CLK_IN input func */
    {62U, 1U, 0U},
    /* INMUX settings for pad PORT71:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_RXDV_IN input func */
    {63U, 1U, 0U},
    /* INMUX settings for pad PORT72:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_RXD0_IN input func */
    {64U, 1U, 0U},
    /* INMUX settings for pad PORT73:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_RXD1_IN input func */
    {65U, 1U, 0U},
    /* INMUX settings for pad PORT74:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_RXD2_IN input func */
    {66U, 1U, 0U},
    /* INMUX settings for pad PORT75:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_RXD3_IN input func */
    {67U, 1U, 0U},
    /* INMUX settings for pad PORT76:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_RMII_REF_CLK_IN input func */
    {68U, 1U, 0U},
    /* INMUX settings for pad PORT77:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_1_DSPI_1_SIN_IN input func */
    {29U, 2U, 0U},
    /* FTM_0_FTM_0_PHA_IN input func */
    {106U, 1U, 0U},
    /* GMAC_0_GMAC_0_COL_IN input func */
    {69U, 1U, 0U},
    /* INMUX settings for pad PORT78:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FTM_0_FTM_0_CH4_IN input func */
    {38U, 2U, 0U},
    /* GMAC_0_GMAC_0_CRS_IN input func */
    {70U, 1U, 0U},
    /* INMUX settings for pad PORT79:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_RX_ER_IN input func */
    {71U, 1U, 0U},
    /* INMUX settings for pad PORT80:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC_0_MD_IN input func */
    {72U, 1U, 0U},
    /* INMUX settings for pad PORT82:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PLATFORM_NMI_IN input func */
    {100U, 1U, 0U},
    /* INMUX settings for pad PORT83:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CTE_0_CTE_0_RFS_IN input func */
    {19U, 1U, 0U},
    /* CTI_CTI_TRIG_I_0_IN input func */
    {21U, 1U, 0U},
    /* INMUX settings for pad PORT86:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CTI_CTI_TRIG_O_ACK_0_IN input func */
    {22U, 1U, 0U},
    /* INMUX settings for pad PORT87:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CTE_0_CTE_0_RCS_IN input func */
    {18U, 1U, 0U},
    /* INMUX settings for pad PORT88:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_3_DSPI_3_SCK_IN input func */
    {101U, 1U, 0U},
    /* INMUX settings for pad PORT90:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_3_DSPI_3_SIN_IN input func */
    {102U, 1U, 0U},
    /* INMUX settings for pad PORT91:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_3_DSPI_3_PCS0_IN input func */
    {103U, 1U, 0U}

};

/**
* @brief Array of elements storing information about IN functionalities on the second SIUL2 instance
*/

/**
* @brief Array of elements storing information about INOUT functionalities on the first SIUL2 instance
*/
static const Port_InoutSettingType Port_SIUL2_0_aInoutMuxSettings[PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16] =
{
    /* Inout settings for pad PORT0 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_TX_CLK_INOUT inout functionality */
    {0U, 15U, 73U, 1U, 0U}, 
    /* Inout settings for pad PORT1 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_TX_EN_INOUT inout functionality */
    {1U, 15U, 74U, 1U, 0U}, 
    /* Inout settings for pad PORT2 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_TXD0_INOUT inout functionality */
    {2U, 15U, 75U, 1U, 0U}, 
    /* Inout settings for pad PORT3 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_TXD1_INOUT inout functionality */
    {3U, 15U, 76U, 1U, 0U}, 
    /* Inout settings for pad PORT4 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_TXD2_INOUT inout functionality */
    {4U, 15U, 77U, 1U, 0U}, 
    /* Inout settings for pad PORT5 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_TXD3_INOUT inout functionality */
    {5U, 15U, 78U, 1U, 0U}, 
    /* Inout settings for pad PORT6 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_RX_CLK_INOUT inout functionality */
    {6U, 15U, 79U, 1U, 0U}, 
    /* Inout settings for pad PORT7 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_RXDV_INOUT inout functionality */
    {7U, 15U, 80U, 1U, 0U}, 
    /* Inout settings for pad PORT8 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_RXD0_INOUT inout functionality */
    {8U, 15U, 81U, 1U, 0U}, 
    /* Inout settings for pad PORT9 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_RXD1_INOUT inout functionality */
    {9U, 15U, 82U, 1U, 0U}, 
    /* Inout settings for pad PORT10 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_RXD2_INOUT inout functionality */
    {10U, 15U, 83U, 1U, 0U}, 
    /* Inout settings for pad PORT11 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_RXD3_INOUT inout functionality */
    {11U, 15U, 84U, 1U, 0U}, 
    /* Inout settings for pad PORT12 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_RMII_REF_CLK_INOUT inout functionality */
    {12U, 15U, 85U, 1U, 0U}, 
    /* Inout settings for pad PORT16 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_MD_INOUT inout functionality */
    {16U, 15U, 89U, 1U, 0U}, 
    /* Inout settings for pad PORT18 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* CTE_0_CTE_0_RCS_INOUT inout functionality */
    {18U, 17U, 18U, 2U, 0U}, 
    /* Inout settings for pad PORT20 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_1_GMAC_1_TS_CLK_INOUT inout functionality */
    {20U, 15U, 91U, 1U, 0U}, 
    /* Inout settings for pad PORT29 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH6_INOUT inout functionality */
    {29U, 16U, 40U, 2U, 0U}, 
    /* Inout settings for pad PORT30 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH7_INOUT inout functionality */
    {30U, 16U, 41U, 2U, 0U}, 
    /* Inout settings for pad PORT31 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_0_DSPI_0_SCK_INOUT inout functionality */
    {31U, 15U, 25U, 1U, 0U}, 
    /* I2C_1_I2C_1_SCL_INOUT inout functionality */
    {31U, 16U, 94U, 3U, 0U}, 
    /* Inout settings for pad PORT32 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH0_INOUT inout functionality */
    {32U, 16U, 34U, 1U, 0U}, 
    /* Inout settings for pad PORT33 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH1_INOUT inout functionality */
    {33U, 16U, 35U, 1U, 0U}, 
    /* Inout settings for pad PORT34 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_0_DSPI_0_PCS0_INOUT inout functionality */
    {34U, 15U, 27U, 1U, 0U}, 
    /* I2C_1_I2C_1_SDA_INOUT inout functionality */
    {34U, 16U, 95U, 3U, 0U}, 
    /* Inout settings for pad PORT35 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_1_I2C_1_SCL_INOUT inout functionality */
    {35U, 17U, 94U, 1U, 0U}, 
    /* Inout settings for pad PORT36 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH2_INOUT inout functionality */
    {36U, 16U, 36U, 1U, 0U}, 
    /* I2C_1_I2C_1_SDA_INOUT inout functionality */
    {36U, 17U, 95U, 1U, 0U}, 
    /* Inout settings for pad PORT38 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH2_INOUT inout functionality */
    {38U, 17U, 36U, 2U, 0U}, 
    /* Inout settings for pad PORT40 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH5_INOUT inout functionality */
    {40U, 16U, 39U, 1U, 0U}, 
    /* Inout settings for pad PORT41 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH5_INOUT inout functionality */
    {41U, 17U, 39U, 2U, 0U}, 
    /* Inout settings for pad PORT42 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH4_INOUT inout functionality */
    {42U, 16U, 38U, 3U, 0U}, 
    /* Inout settings for pad PORT43 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_1_DSPI_1_SCK_INOUT inout functionality */
    {43U, 15U, 28U, 1U, 0U}, 
    /* Inout settings for pad PORT46 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_1_DSPI_1_PCS0_INOUT inout functionality */
    {46U, 15U, 30U, 1U, 0U}, 
    /* Inout settings for pad PORT47 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH3_INOUT inout functionality */
    {47U, 17U, 37U, 2U, 0U}, 
    /* Inout settings for pad PORT48 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_2_DSPI_2_SCK_INOUT inout functionality */
    {48U, 16U, 31U, 1U, 0U}, 
    /* Inout settings for pad PORT51 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_2_DSPI_2_PCS0_INOUT inout functionality */
    {51U, 16U, 33U, 1U, 0U}, 
    /* Inout settings for pad PORT52 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH4_INOUT inout functionality */
    {52U, 17U, 38U, 1U, 0U}, 
    /* Inout settings for pad PORT54 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_0_I2C_0_SDA_INOUT inout functionality */
    {54U, 16U, 92U, 1U, 0U}, 
    /* FTM_0_FTM_0_CH6_INOUT inout functionality */
    {54U, 17U, 40U, 1U, 0U}, 
    /* Inout settings for pad PORT55 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_0_I2C_0_SCL_INOUT inout functionality */
    {55U, 16U, 93U, 1U, 0U}, 
    /* FTM_0_FTM_0_CH7_INOUT inout functionality */
    {55U, 17U, 41U, 1U, 0U}, 
    /* Inout settings for pad PORT56 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_1_I2C_1_SCL_INOUT inout functionality */
    {56U, 16U, 94U, 2U, 0U}, 
    /* Inout settings for pad PORT57 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_1_I2C_1_SDA_INOUT inout functionality */
    {57U, 16U, 95U, 2U, 0U}, 
    /* Inout settings for pad PORT58 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH0_INOUT inout functionality */
    {58U, 17U, 34U, 2U, 0U}, 
    /* Inout settings for pad PORT59 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH1_INOUT inout functionality */
    {59U, 17U, 35U, 2U, 0U}, 
    /* Inout settings for pad PORT61 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_0_I2C_0_SCL_INOUT inout functionality */
    {61U, 15U, 93U, 2U, 0U}, 
    /* DSPI_1_DSPI_1_SCK_INOUT inout functionality */
    {61U, 16U, 28U, 2U, 0U}, 
    /* Inout settings for pad PORT62 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_0_I2C_0_SDA_INOUT inout functionality */
    {62U, 15U, 92U, 2U, 0U}, 
    /* DSPI_1_DSPI_1_PCS0_INOUT inout functionality */
    {62U, 16U, 30U, 2U, 0U}, 
    /* Inout settings for pad PORT63 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH3_INOUT inout functionality */
    {63U, 17U, 37U, 1U, 0U}, 
    /* GMAC_0_GMAC_0_TS_CLK_INOUT inout functionality */
    {63U, 18U, 55U, 1U, 0U}, 
    /* Inout settings for pad PORT64 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_TX_CLK_INOUT inout functionality */
    {64U, 18U, 56U, 1U, 0U}, 
    /* Inout settings for pad PORT65 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_TX_EN_INOUT inout functionality */
    {65U, 18U, 57U, 1U, 0U}, 
    /* Inout settings for pad PORT66 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_TXD0_INOUT inout functionality */
    {66U, 18U, 58U, 1U, 0U}, 
    /* Inout settings for pad PORT67 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_TXD1_INOUT inout functionality */
    {67U, 18U, 59U, 1U, 0U}, 
    /* Inout settings for pad PORT68 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_TXD2_INOUT inout functionality */
    {68U, 18U, 60U, 1U, 0U}, 
    /* Inout settings for pad PORT69 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_TXD3_INOUT inout functionality */
    {69U, 18U, 61U, 1U, 0U}, 
    /* Inout settings for pad PORT70 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_RX_CLK_INOUT inout functionality */
    {70U, 18U, 62U, 1U, 0U}, 
    /* Inout settings for pad PORT71 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_RXDV_INOUT inout functionality */
    {71U, 18U, 63U, 1U, 0U}, 
    /* Inout settings for pad PORT72 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_RXD0_INOUT inout functionality */
    {72U, 18U, 64U, 1U, 0U}, 
    /* Inout settings for pad PORT73 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_RXD1_INOUT inout functionality */
    {73U, 18U, 65U, 1U, 0U}, 
    /* Inout settings for pad PORT74 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_RXD2_INOUT inout functionality */
    {74U, 18U, 66U, 1U, 0U}, 
    /* Inout settings for pad PORT75 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_RXD3_INOUT inout functionality */
    {75U, 18U, 67U, 1U, 0U}, 
    /* Inout settings for pad PORT76 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_RMII_REF_CLK_INOUT inout functionality */
    {76U, 18U, 68U, 1U, 0U}, 
    /* Inout settings for pad PORT78 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FTM_0_FTM_0_CH4_INOUT inout functionality */
    {78U, 17U, 38U, 2U, 0U}, 
    /* Inout settings for pad PORT80 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC_0_MD_INOUT inout functionality */
    {80U, 18U, 72U, 1U, 0U}, 
    /* Inout settings for pad PORT83 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* CTE_0_CTE_0_RFS_INOUT inout functionality */
    {83U, 17U, 19U, 1U, 0U}, 
    /* Inout settings for pad PORT87 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* CTE_0_CTE_0_RCS_INOUT inout functionality */
    {87U, 17U, 18U, 1U, 0U}, 
    /* Inout settings for pad PORT88 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_3_DSPI_3_SCK_INOUT inout functionality */
    {88U, 16U, 101U, 1U, 0U}, 
    /* Inout settings for pad PORT91 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_3_DSPI_3_PCS0_INOUT inout functionality */
    {91U, 16U, 103U, 1U, 0U}

};

/**
* @brief Array of elements storing information about INOUT functionalities on the second SIUL2 instance
*/

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* PORT_SET_PIN_MODE_API */

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of values storing the length of tables with INOUT functionality information on each of the SIUL2 instance on the platform
*/
const uint16 Port_au16NumInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about pin availability on each of the SIUL2 instance on the platform
*/
const Port_PinModeAvailabilityArrayType * const Port_apSiul2InstancePinModeAvailability[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    &Port_SIUL2_0_au16PinModeAvailability
};

/**
* @brief Array of pointers to the tables storing information about IN functionality on each of the SIUL2 instance on the platform
*/
const Port_InMuxSettingType * const Port_apInMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_aInMuxSettings
};

/**
* @brief Array of pointers to the tables storing information about indexes in the IN functionality tables on each of the SIUL2 instance on the platform
*/
const uint16 * const Port_apInMuxSettingsIndex[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_au16InMuxSettingsIndex
};

/**
* @brief Array of pointers to the tables storing information about INOUT functionality on each of the SIUL2 instance on the platform
*/
const Port_InoutSettingType * const Port_apInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_aInoutMuxSettings
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* PORT_SET_PIN_MODE_API */

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

