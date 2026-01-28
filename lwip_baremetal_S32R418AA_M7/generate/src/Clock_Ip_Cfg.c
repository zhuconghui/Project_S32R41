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
*   @file       Clock_Ip_Cfg.c
*   @version    2.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Driver
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
#include "StandardTypes.h"
#include "Clock_Ip_Private.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_CFG_VENDOR_ID_C                      43
#define CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_CFG_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_CFG_SW_MINOR_VERSION_C               0
#define CLOCK_IP_CFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and StandardTypes.h file are of the same Autosar version */
#if ((CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Cfg.c and StandardTypes.h are different"
#endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/* Check if source file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_CFG_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Cfg.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if source file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Cfg.c and Clock_Ip_Private.h are different"
#endif

/* Check if source file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_CFG_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_CFG_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Cfg.c and Clock_Ip_Private.h are different"
#endif

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


#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"



static const Clock_Ip_XoscConfigType Clock_Ip_XoscConfigurations_0[CLOCK_IP_CONFIGURED_XOSCS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_XOSCS_0_NO > 0U
    {
        FXOSC_CLK,              /* Clock name associated to xosc */
        40000000U,              /* External oscillator frequency. */ 
        1U,                     /* Enable xosc. */
        157U,                    /* Startup stabilization time */
        0U,                     /* bypassOption: Xosc use crystal */ 
        1U,                     /* Comparator is enabled */ 
        12U,                    /* TransConductance */
        0U,                     /* Gain value */
        0U,                     /* Monitor type */
        1U,                    /* Automatic level controller */
    },
    #endif
};


static const Clock_Ip_PllConfigType Clock_Ip_PllConfigurations_0[CLOCK_IP_CONFIGURED_PLLS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_PLLS_0_NO > 0U
    {
        COREPLL_CLK,                /* name */
        1U,                     /* enable */
        FXOSC_CLK,                     /* inputReference */
        0U,                     /* Bypass */
        2U,                      /* predivider */
        0U,                      /* multiplier */
        0U,                      /* postdivider */
        0U,                     /* numeratorFracLoopDiv */
        80U,                   /* mulFactorDiv */
        1U,                     /* ModulationBypass */
        0U,                     /* Modulation type: Spread spectrum modulation bypassed */ 
        0U,                     /* modulationPeriod */
        0U,                     /* incrementStep */
        0U,                     /* sigmaDelta */
        0U,                     /* ditherControl */
        0U,                     /* ditherControlValue */
        0U,                    /* Monitor type */
        {                      /* Dividers */
            0U,
            0U,
            0U,
        },
        0U,                     /* SoftwareDisable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_PLLS_0_NO > 1U
    {
        PERIPHPLL_CLK,                /* name */
        1U,                     /* enable */
        FXOSC_CLK,                     /* inputReference */
        0U,                     /* Bypass */
        2U,                      /* predivider */
        0U,                      /* multiplier */
        0U,                      /* postdivider */
        0U,                     /* numeratorFracLoopDiv */
        100U,                   /* mulFactorDiv */
        0U,                     /* ModulationBypass */
        0U,                     /* Modulation type: Spread spectrum modulation bypassed */
        0U,                     /* modulationPeriod */
        0U,                     /* incrementStep */
        0U,                     /* sigmaDelta */
        0U,                     /* ditherControl */
        0U,                     /* ditherControlValue */
        0U,                    /* Monitor type */
        {                      /* Dividers */
            0U,
            0U,
            0U,
        },
        0U,                     /* SoftwareDisable */
    },
    #endif
};


static const Clock_Ip_SelectorConfigType Clock_Ip_SelectorConfigurations_0[CLOCK_IP_CONFIGURED_SELECTORS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 0U
    {
        SYS_CLK,                    /* Clock name associated to selector */
        PERIPHPLL_PHI0_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 1U
    {
        CLKOUT0_CLK,                    /* Clock name associated to selector */
        FXOSC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 2U
    {
        CLKOUT1_CLK,                    /* Clock name associated to selector */
        FXOSC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 3U
    {
        MC_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 4U
    {
        SPI_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 5U
    {
        QSPI_2X_CLK,                    /* Clock name associated to selector */
        PERIPHPLL_DFS1_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 6U
    {
        GMAC1_INT_CLK,                    /* Clock name associated to selector */
        PERIPHPLL_PHI5_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 7U
    {
        CAN_PE_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 8U
    {
        LIN_BAUD_CLK,                    /* Clock name associated to selector */
        PERIPHPLL_PHI3_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 9U
    {
        A53_CORE_CLK,                    /* Clock name associated to selector */
        COREPLL_PHI0_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 10U
    {
        ACCEL_CLK,                    /* Clock name associated to selector */
        COREPLL_PHI1_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 11U
    {
        ACCEL_XBAR_CLK,                    /* Clock name associated to selector */
        COREPLL_PHI2_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 12U
    {
        CTE_CLK,                    /* Clock name associated to selector */
        COREPLL_PHI3_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 13U
    {
        CSI_CLK,                    /* Clock name associated to selector */
        COREPLL_PHI4_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 14U
    {
        NOC_TRACE_CLK,                    /* Clock name associated to selector */
        PERIPHPLL_DFS2_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 15U
    {
        LBIST_CLK,                    /* Clock name associated to selector */
        COREPLL_PHI9_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 16U
    {
        GMAC1_TS_CLK,                    /* Clock name associated to selector */
        PERIPHPLL_PHI4_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 17U
    {
        GMAC1_TX_CLK,                    /* Clock name associated to selector */
        PERIPHPLL_PHI5_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 18U
    {
        GMAC1_REF_CLK,                    /* Clock name associated to selector */
        GMAC_1_INT_REF_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 19U
    {
        GMAC1_RX_CLK,                    /* Clock name associated to selector */
        GMAC_1_EXT_RX_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 20U
    {
        FTM0_EXT_CLK,                    /* Clock name associated to selector */
        FTM_0_EXT_REF_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 21U
    {
        GMAC0_TS_CLK,                    /* Clock name associated to selector */
        PERIPHPLL_PHI4_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 22U
    {
        GMAC0_TX_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 23U
    {
        GMAC0_REF_CLK,                    /* Clock name associated to selector */
        PERIPHPLL_PHI6_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 24U
    {
        GMAC0_RX_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif
};


static const Clock_Ip_DividerConfigType Clock_Ip_DividerConfigurations_0[CLOCK_IP_CONFIGURED_DIVIDERS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 0U
    {
        COREPLL_PHI0_CLK,                    /* name */
        5U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 1U
    {
        COREPLL_PHI1_CLK,                    /* name */
        5U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 2U
    {
        COREPLL_PHI2_CLK,                    /* name */
        5U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 3U
    {
        COREPLL_PHI3_CLK,                    /* name */
        20U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 4U
    {
        COREPLL_PHI4_CLK,                    /* name */
        40U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 5U
    {
        COREPLL_PHI5_CLK,                    /* name */
        8U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 6U
    {
        COREPLL_PHI6_CLK,                    /* name */
        5U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 7U
    {
        COREPLL_PHI8_CLK,                    /* name */
        2U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 8U
    {
        COREPLL_PHI9_CLK,                    /* name */
        4U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 9U
    {
        PERIPHPLL_PHI0_CLK,                    /* name */
        5U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 10U
    {
        PERIPHPLL_PHI1_CLK,                    /* name */
        25U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 11U
    {
        PERIPHPLL_PHI2_CLK,                    /* name */
        33U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 12U
    {
        PERIPHPLL_PHI3_CLK,                    /* name */
        20U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 13U
    {
        PERIPHPLL_PHI4_CLK,                    /* name */
        10U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 14U
    {
        PERIPHPLL_PHI5_CLK,                    /* name */
        4U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 15U
    {
        PERIPHPLL_PHI6_CLK,                    /* name */
        40U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 16U
    {
        PERIPHPLL_PHI7_CLK,                    /* name */
        65U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 17U
    {
        PERIPHPLL_PHI8_CLK,                    /* name */
        5U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 18U
    {
        PERIPHPLL_PHI9_CLK,                    /* name */
        5U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 19U
    {
        GMAC0_REF_DIV_CLK,                    /* name */
        4U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 20U
    {
        GMAC1_REF_DIV_CLK,                    /* name */
        2U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 21U
    {
        CAN_CHI_CLK,                    /* name */
        4U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 22U
    {
        CAN_TS_CLK,                    /* name */
        4U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 23U
    {
        CLKOUT0_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 24U
    {
        CLKOUT1_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 25U
    {
        CSI_CFG_CLK,                    /* name */
        2U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 26U
    {
        CSI_TXCLK_CLK,                    /* name */
        4U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 27U
    {
        DSPI_SCK_TST_CLK,                    /* name */
        8U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 28U
    {
        FTM0_EXT_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 29U
    {
        GMAC0_TS_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 30U
    {
        GMAC1_TS_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 31U
    {
        GMAC1_TX_CLK,                    /* name */
        4U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 32U
    {
        LBIST_CLK,                    /* name */
        8U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 33U
    {
        QSPI_2X_CLK,                    /* name */
        2U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 34U
    {
        STCU_CLK,                    /* name */
        10U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 35U
    {
        TCLK_CLK,                    /* name */
        5U,                              /* value */
        {
            0U,
        }
    },
    #endif
};


static const Clock_Ip_FracDivConfigType Clock_Ip_FracDivsConfigurations_0[CLOCK_IP_CONFIGURED_FRACTIONAL_DIVIDERS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_FRACTIONAL_DIVIDERS_0_NO > 0U
    {
        PERIPHPLL_DFS1_CLK,                    /* name */
        1U,          /* Enabled */
        {
            2U,          /* integer part */
            0U,          /* fractional part */
        },
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FRACTIONAL_DIVIDERS_0_NO > 1U
    {
        PERIPHPLL_DFS2_CLK,                    /* name */
        1U,          /* Enabled */
        {
            1U,          /* integer part */
            9U,          /* fractional part */
        },
    },
    #endif
};


static const Clock_Ip_ExtClkConfigType Clock_Ip_ExtClkConfigurations_0[CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 0U
    {
        FTM_0_EXT_REF_CLK,                    /* name */
        80000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 1U
    {
        GMAC_0_EXT_REF_CLK,                    /* name */
        50000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 2U
    {
        GMAC_0_EXT_RX_CLK,                    /* name */
        50000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 3U
    {
        GMAC_0_EXT_TX_CLK,                    /* name */
        50000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 4U
    {
        GMAC_0_EXT_TS_CLK,                    /* name */
        200000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 5U
    {
        GMAC_1_EXT_REF_CLK,                    /* name */
        50000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 6U
    {
        GMAC_1_EXT_RX_CLK,                    /* name */
        125000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 7U
    {
        GMAC_1_EXT_TX_CLK,                    /* name */
        125000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 8U
    {
        GMAC_1_EXT_TS_CLK,                    /* name */
        200000000U,                              /* value */
    },
    #endif
};


static const Clock_Ip_GateConfigType Clock_Ip_GatesConfigurations_0[CLOCK_IP_CONFIGURED_GATES_0_NO] = {

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 0U
    {
        BBE32EP_DSP_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 1U
    {
        MIPICSI2_0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 2U
    {
        MIPICSI2_1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 3U
    {
        SPT_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif
};


static const Clock_Ip_CmuConfigType Clock_Ip_CmuConfigurations_0[CLOCK_IP_CONFIGURED_CMUS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 0U
    {
        FXOSC_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_0 */
        (                                           /* IER for CMU_FC_0 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        40000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 1U
    {
        FIRC_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_1 */
        (                                           /* IER for CMU_FC_1 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        48000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 2U
    {
        FTM0_EXT_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_3 */
        (                                           /* IER for CMU_FC_3 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        80000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 3U
    {
        STCU_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_5 */
        (                                           /* IER for CMU_FC_5 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        50000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 4U
    {
        SYS_M7_0_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_6 */
        (                                           /* IER for CMU_FC_6 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        400000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 5U
    {
        SYS_DIV8_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_7 */
        (                                           /* IER for CMU_FC_7 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        50000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 6U
    {
        SYS_M7_1_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_8 */
        (                                           /* IER for CMU_FC_8 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        400000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 7U
    {
        MC_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_10 */
        (                                           /* IER for CMU_FC_10 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        48000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 8U
    {
        CLKOUT0_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_11 */
        (                                           /* IER for CMU_FC_11 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        40000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 9U
    {
        FCCU_IPS_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_12 */
        (                                           /* IER for CMU_FC_12 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        125000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 10U
    {
        CAN_PE_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_13 */
        (                                           /* IER for CMU_FC_13 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        48000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 11U
    {
        GMAC0_TX_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_14 */
        (                                           /* IER for CMU_FC_14 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        48000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 12U
    {
        GMAC0_TS_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_15 */
        (                                           /* IER for CMU_FC_15 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        200000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 13U
    {
        LINFLEXD_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_16 */
        (                                           /* IER for CMU_FC_16 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        50000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 14U
    {
        QSPI_1X_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_17 */
        (                                           /* IER for CMU_FC_17 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        125000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 15U
    {
        GMAC0_RX_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_21 */
        (                                           /* IER for CMU_FC_21 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        48000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 16U
    {
        SPI_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_22 */
        (                                           /* IER for CMU_FC_22 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        48000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 17U
    {
        GMAC1_TX_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_23 */
        (                                           /* IER for CMU_FC_23 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        125000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 18U
    {
        GMAC1_TS_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_24 */
        (                                           /* IER for CMU_FC_24 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        200000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 19U
    {
        GMAC1_RX_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_25 */
        (                                           /* IER for CMU_FC_25 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        125000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 20U
    {
        CTE_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_26 */
        (                                           /* IER for CMU_FC_26 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        80000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 21U
    {
        A53_CORE_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_27 */
        (                                           /* IER for CMU_FC_27 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        320000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 22U
    {
        CSI_CFG_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_28 */
        (                                           /* IER for CMU_FC_28 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        20000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 23U
    {
        ACCEL_XBAR_DIV4_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_29 */
        (                                           /* IER for CMU_FC_29 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        80000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 24U
    {
        ACCEL_XBAR_DIV8_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_30 */
        (                                           /* IER for CMU_FC_30 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        40000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 25U
    {
        ACCEL_DIV3_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_31 */
        (                                           /* IER for CMU_FC_31 */
            CMU_FC_IER_FLLIE(0) |
            CMU_FC_IER_FHHIE(0) |
            CMU_FC_IER_FLLAIE(0) |
            CMU_FC_IER_FHHAIE(0)
        ),
        106666667U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    #endif
};


static const Clock_Ip_ConfiguredFrequencyType Clock_Ip_ConfiguredFrequencyConfigurations_0[CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT] = {

    {
        CLOCK_IS_OFF,
        0U,
    },
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 1U
    {
        FIRC_CLK,
        48000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 2U
    {
        FXOSC_CLK,
        40000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 3U
    {
        SYS_DIV8_CLK,
        50000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 4U
    {
        SYS_CLK,
        400000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 5U
    {
        A53_CORE_CLK,
        320000000U,
    },
    #endif
};


/* *************************************************************************
 * Configuration structure for Clock Configuration 
 * ************************************************************************* */
const Clock_Ip_ClockConfigType Clock_Ip_aClockConfig[1U] = {

    /*! @brief User Configuration structure clock_Cfg_0 */
    {
        0U,                          /* clkConfigId */
        (NULL_PTR),               /* Register data if register value optimization is enabled */

        0U,                       /* ircoscsCount */
        1U,                       /* xoscsCount */
        2U,                       /* pllsCount */
        25U,                       /* selectorsCount */
        36U,                       /* dividersCount */
        0U,                       /* dividerTriggersCount */
        2U,                       /* fracDivsCount */
        9U,                       /* extClksCount */
        4U,                       /* gatesCount */
        0U,                       /* pcfsCount */
        26U,                       /* cmusCount */
        6U,                       /* configureFrequenciesCount */

        (NULL_PTR),                       /* Ircosc configurations */
        (&Clock_Ip_XoscConfigurations_0),                      /* Xosc configurations */
        (&Clock_Ip_PllConfigurations_0),                       /* Pll configurations */
        (&Clock_Ip_SelectorConfigurations_0),                  /* Selectors configurations */
        (&Clock_Ip_DividerConfigurations_0),                   /* dividers configurations */
        (NULL_PTR),                       /* dividerTriggers configurations */
        (&Clock_Ip_FracDivsConfigurations_0),            /* fracDivs configurations */
        (&Clock_Ip_ExtClkConfigurations_0),                    /* extClks configurations */
        (&Clock_Ip_GatesConfigurations_0),                     /* gates configurations */
        (NULL_PTR),                       /* pcfs configurations */
        (&Clock_Ip_CmuConfigurations_0),                       /* cmus configurations */
        (&Clock_Ip_ConfiguredFrequencyConfigurations_0),       /* configureFrequencies configurations */
    },
};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"


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


