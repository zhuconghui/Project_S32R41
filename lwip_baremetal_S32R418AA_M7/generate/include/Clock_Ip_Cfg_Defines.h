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
*   @file       Clock_Ip_Cfg_Defines.h
*   @version    2.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Driver
*   @{
*/

#ifndef CLOCK_IP_CFG_DEFINES_H
#define CLOCK_IP_CFG_DEFINES_H


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include  "S32R41_COMMON.h"
#include  "S32R41_MC_CGM.h"
#include  "S32R41_MC_CGM_0.h"
#include  "S32R41_MC_CGM_2.h"
#include  "S32R41_FXOSC.h"
#include  "S32R41_PLLDIG.h"
#include  "S32R41_MC_ME.h"
#include  "S32R41_MC_RGM.h"
#include  "S32R41_RESET.h"
#include  "S32R41_SRAMC.h"
#include  "S32R41_DFS.h"
#include  "S32R41_CMU_FC.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_CFG_DEFINES_VENDOR_ID                       43
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION                2
#define CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            Derivative used.
*/
#define CLOCK_IP_DERIVATIVE_001

/**
* @brief            Max number of internal oscillators
*/
#define CLOCK_IP_IRCOSCS_COUNT       (1U)

/**
* @brief            Max number of external oscillators
*/
#define CLOCK_IP_XOSCS_COUNT       (1U)

/**
* @brief            Max number of pll devices
*/
#define CLOCK_IP_PLLS_COUNT       (2U)

/**
* @brief            Max number of selectors
*/
#define CLOCK_IP_SELECTORS_COUNT       (25U)

/**
* @brief            Max number of dividers
*/
#define CLOCK_IP_DIVIDERS_COUNT       (36U)

/**
* @brief            Max number of divider triggers
*/
#define CLOCK_IP_DIVIDER_TRIGGERS_COUNT       (0U)

/**
* @brief            Max number of fractional dividers
*/
#define CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT       (2U)

/**
* @brief            Max number of external clocks
*/
#define CLOCK_IP_EXT_CLKS_COUNT       (9U)

/**
* @brief            Max number of pcfs
*/
#define CLOCK_IP_PCFS_COUNT       (3U)

/**
* @brief            Max number of clock gates
*/
#define CLOCK_IP_GATES_COUNT       (4U)

/**
* @brief            Max number of clock monitoring units
*/
#define CLOCK_IP_CMUS_COUNT       (26U)

/**
* @brief            Max number of configured frequencies values
*/
#define CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT       (6U)

/**
* @brief            Number of clock configurations 0
*/
#define CLOCK_IP_CONFIGURED_XOSCS_0_NO       (1U)
#define CLOCK_IP_CONFIGURED_PLLS_0_NO       (2U)
#define CLOCK_IP_CONFIGURED_SELECTORS_0_NO       (25U)
#define CLOCK_IP_CONFIGURED_DIVIDERS_0_NO       (36U)
#define CLOCK_IP_CONFIGURED_FRACTIONAL_DIVIDERS_0_NO       (2U)
#define CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO       (9U)
#define CLOCK_IP_CONFIGURED_GATES_0_NO       (4U)
#define CLOCK_IP_CONFIGURED_CMUS_0_NO       (26U)


/**
* @brief            Supported power mode.
*/
#define CLOCK_IP_HAS_RUN_MODE                0U

/**
* @brief            Firc frequency.
*/
#define CLOCK_IP_FIRC_FREQUENCY                48000000U

/**
* @brief            Clock ip supports clock frequency.
*/
#define CLOCK_IP_GET_FREQUENCY_API                (STD_OFF)

/**
* @brief            Default fxosc frequency.
*/
#define CLOCK_IP_DEFAULT_FXOSC_FREQUENCY                40000000U

/**
* @brief            Clock ip supports ram wait states.
*/
#define CLOCK_IP_HAS_RAM_WAIT_STATES

/**
* @brief            Supported clocks.
*/
#define CLOCK_IP_HAS_FIRC_CLK         1U
#define CLOCK_IP_HAS_FXOSC_CLK         2U
#define CLOCK_IP_HAS_COREPLL_CLK         3U
#define CLOCK_IP_HAS_PERIPHPLL_CLK         4U
#define CLOCK_IP_HAS_COREPLL_PHI0_CLK         5U
#define CLOCK_IP_HAS_COREPLL_PHI1_CLK         6U
#define CLOCK_IP_HAS_COREPLL_PHI2_CLK         7U
#define CLOCK_IP_HAS_COREPLL_PHI3_CLK         8U
#define CLOCK_IP_HAS_COREPLL_PHI4_CLK         9U
#define CLOCK_IP_HAS_COREPLL_PHI5_CLK         10U
#define CLOCK_IP_HAS_COREPLL_PHI6_CLK         11U
#define CLOCK_IP_HAS_COREPLL_PHI8_CLK         12U
#define CLOCK_IP_HAS_COREPLL_PHI9_CLK         13U
#define CLOCK_IP_HAS_PERIPHPLL_PHI0_CLK         14U
#define CLOCK_IP_HAS_PERIPHPLL_PHI1_CLK         15U
#define CLOCK_IP_HAS_PERIPHPLL_PHI2_CLK         16U
#define CLOCK_IP_HAS_PERIPHPLL_PHI3_CLK         17U
#define CLOCK_IP_HAS_PERIPHPLL_PHI4_CLK         18U
#define CLOCK_IP_HAS_PERIPHPLL_PHI5_CLK         19U
#define CLOCK_IP_HAS_PERIPHPLL_PHI6_CLK         20U
#define CLOCK_IP_HAS_PERIPHPLL_PHI7_CLK         21U
#define CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK         22U
#define CLOCK_IP_HAS_PERIPHPLL_PHI9_CLK         23U
#define CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK         24U
#define CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK         25U
#define CLOCK_IP_HAS_FTM_0_EXT_REF_CLK         26U
#define CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK         27U
#define CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK         28U
#define CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK         29U
#define CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK         30U
#define CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK         31U
#define CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK         32U
#define CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK         33U
#define CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK         34U
#define CLOCK_IP_HAS_SYS_CLK         35U
#define CLOCK_IP_HAS_SYS_DIV2_CLK         36U
#define CLOCK_IP_HAS_SYS_DIV4_CLK         37U
#define CLOCK_IP_HAS_SYS_DIV8_CLK         38U
#define CLOCK_IP_HAS_RT_DAPB_CLK         39U
#define CLOCK_IP_HAS_A53_CORE_CLK         40U
#define CLOCK_IP_HAS_A53_CORE_DIV2_CLK         41U
#define CLOCK_IP_HAS_A53_CORE_DIV10_CLK         42U
#define CLOCK_IP_HAS_ACCEL_CLK         43U
#define CLOCK_IP_HAS_ACCEL_DIV3_CLK         44U
#define CLOCK_IP_HAS_ACCEL_XBAR_CLK         45U
#define CLOCK_IP_HAS_ACCEL_XBAR_DIV2_CLK         46U
#define CLOCK_IP_HAS_ACCEL_XBAR_DIV4_CLK         47U
#define CLOCK_IP_HAS_ACCEL_XBAR_DIV8_CLK         48U
#define CLOCK_IP_HAS_AP_DAPB_CLK         49U
#define CLOCK_IP_HAS_GMAC0_REF_CLK         50U
#define CLOCK_IP_HAS_GMAC0_REF_DIV_CLK         51U
#define CLOCK_IP_HAS_GMAC1_REF_CLK         52U
#define CLOCK_IP_HAS_GMAC1_REF_DIV_CLK         53U
#define CLOCK_IP_HAS_GMAC1_INT_CLK         54U
#define CLOCK_IP_HAS_GMAC_1_INT_REF_CLK         55U
#define CLOCK_IP_FEATURE_PRODUCERS_NO         56U
#define CLOCK_IP_HAS_BBE32EP_DSP_CLK         57U
#define CLOCK_IP_HAS_CAN_CHI_CLK         58U
#define CLOCK_IP_HAS_CAN_TS_CLK         59U
#define CLOCK_IP_HAS_CAN_PE_CLK         60U
#define CLOCK_IP_HAS_CAN0_CLK         61U
#define CLOCK_IP_HAS_CAN1_CLK         62U
#define CLOCK_IP_HAS_CLKOUT0_CLK         63U
#define CLOCK_IP_HAS_CLKOUT1_CLK         64U
#define CLOCK_IP_HAS_CORE_A53_CLUSTER_0_CLK         65U
#define CLOCK_IP_HAS_CORE_A53_CLUSTER_1_CLK         66U
#define CLOCK_IP_HAS_CRC_CLK         67U
#define CLOCK_IP_HAS_CSI_CLK         68U
#define CLOCK_IP_HAS_CSI_CFG_CLK         69U
#define CLOCK_IP_HAS_CTE_CLK         70U
#define CLOCK_IP_HAS_CSI_IPS_CLK         71U
#define CLOCK_IP_HAS_CSI_TXCLK_CLK         72U
#define CLOCK_IP_HAS_MC_CLK         73U
#define CLOCK_IP_HAS_CTU_CLK         74U
#define CLOCK_IP_HAS_CTU_IPS_CLK         75U
#define CLOCK_IP_HAS_DAPB_CLK         76U
#define CLOCK_IP_HAS_DMA_CLK         77U
#define CLOCK_IP_HAS_DMA_CRC_CLK         78U
#define CLOCK_IP_HAS_DMA_TCD_CLK         79U
#define CLOCK_IP_HAS_DMAMUX0_CLK         80U
#define CLOCK_IP_HAS_DMAMUX1_CLK         81U
#define CLOCK_IP_HAS_DSPI_SCK_TST_CLK         82U
#define CLOCK_IP_HAS_EIM_AP1_CLK         83U
#define CLOCK_IP_HAS_EIM_CM70_CLK         84U
#define CLOCK_IP_HAS_EIM_CM71_CLK         85U
#define CLOCK_IP_HAS_EIM_DSP_CLK         86U
#define CLOCK_IP_HAS_EIM_RT0_CLK         87U
#define CLOCK_IP_HAS_EIM_RT2_CLK         88U
#define CLOCK_IP_HAS_ERM_AP1_CLK         89U
#define CLOCK_IP_HAS_ERM_RT0_CLK         90U
#define CLOCK_IP_HAS_ERM_RT1_CLK         91U
#define CLOCK_IP_HAS_ERM_RT2_CLK         92U
#define CLOCK_IP_HAS_FCCU_IPS_CLK         93U
#define CLOCK_IP_HAS_FTM0_CLK         94U
#define CLOCK_IP_HAS_FTM0_EXT_CLK         95U
#define CLOCK_IP_HAS_GMAC0_RX_CLK         96U
#define CLOCK_IP_HAS_GMAC0_TS_CLK         97U
#define CLOCK_IP_HAS_GMAC0_TX_CLK         98U
#define CLOCK_IP_HAS_GMAC1_RX_CLK         99U
#define CLOCK_IP_HAS_GMAC1_TS_CLK         100U
#define CLOCK_IP_HAS_GMAC1_TX_CLK         101U
#define CLOCK_IP_HAS_IIC0_CLK         102U
#define CLOCK_IP_HAS_IIC1_CLK         103U
#define CLOCK_IP_HAS_LBIST_CLK         104U
#define CLOCK_IP_HAS_LBIST0_CLK         105U
#define CLOCK_IP_HAS_LBIST1_CLK         106U
#define CLOCK_IP_HAS_LBIST2_CLK         107U
#define CLOCK_IP_HAS_LBIST3_CLK         108U
#define CLOCK_IP_HAS_LBIST4_CLK         109U
#define CLOCK_IP_HAS_LBIST5_CLK         110U
#define CLOCK_IP_HAS_LBIST6_CLK         111U
#define CLOCK_IP_HAS_LBIST7_CLK         112U
#define CLOCK_IP_HAS_LIN_BAUD_CLK         113U
#define CLOCK_IP_HAS_LINFLEXD_CLK         114U
#define CLOCK_IP_HAS_LIN0_CLK         115U
#define CLOCK_IP_HAS_LIN1_CLK         116U
#define CLOCK_IP_HAS_SYS_M7_0_CLK         117U
#define CLOCK_IP_HAS_SYS_M7_1_CLK         118U
#define CLOCK_IP_HAS_SYS_HSE_CLK         119U
#define CLOCK_IP_HAS_MIPICSI2_0_CLK         120U
#define CLOCK_IP_HAS_MIPICSI2_1_CLK         121U
#define CLOCK_IP_HAS_MSCM_CLK         122U
#define CLOCK_IP_HAS_NOC_TRACE_CLK         123U
#define CLOCK_IP_HAS_OCOTP_CLK         124U
#define CLOCK_IP_HAS_PIT0_CLK         125U
#define CLOCK_IP_HAS_PIT2_CLK         126U
#define CLOCK_IP_HAS_QSPI_2X_CLK         127U
#define CLOCK_IP_HAS_QSPI_1X_CLK         128U
#define CLOCK_IP_HAS_QSPI0_CLK         129U
#define CLOCK_IP_HAS_SAR_ADC_CLK         130U
#define CLOCK_IP_HAS_SEMA42_1_CLK         131U
#define CLOCK_IP_HAS_SEMA42_CLK         132U
#define CLOCK_IP_HAS_SIUL2_CLK         133U
#define CLOCK_IP_HAS_SPI_CLK         134U
#define CLOCK_IP_HAS_SPI0_CLK         135U
#define CLOCK_IP_HAS_SPI1_CLK         136U
#define CLOCK_IP_HAS_SPI2_CLK         137U
#define CLOCK_IP_HAS_SPI3_CLK         138U
#define CLOCK_IP_HAS_SPT_CLK         139U
#define CLOCK_IP_HAS_SRAM_CLK         140U
#define CLOCK_IP_HAS_STCU_CLK         141U
#define CLOCK_IP_HAS_STM0_CLK         142U
#define CLOCK_IP_HAS_STM1_CLK         143U
#define CLOCK_IP_HAS_STM2_CLK         144U
#define CLOCK_IP_HAS_SWT0_CLK         145U
#define CLOCK_IP_HAS_SWT1_CLK         146U
#define CLOCK_IP_HAS_SWT2_CLK         147U
#define CLOCK_IP_HAS_SWT3_CLK         148U
#define CLOCK_IP_HAS_TMU_CLK         149U
#define CLOCK_IP_HAS_TCLK_CLK         150U
#define CLOCK_IP_HAS_WKPU_CLK         151U
#define CLOCK_IP_HAS_XRDC0_CLK         152U
#define CLOCK_IP_HAS_XRDC1_CLK         153U
#define CLOCK_IP_FEATURE_NAMES_NO         154U

#if defined(CLOCK_IP_HAS_OCOTP_CLK)

#define HSE_REF_CLK        OCOTP_CLK
#define FCCU_SAFE_CLK      OCOTP_CLK
#define RGM_CLK            OCOTP_CLK
#define PMC_CLK            OCOTP_CLK
#define SIUL_FLT_CLK       OCOTP_CLK
#define SWT_CNT_CLK        OCOTP_CLK

#endif

#if defined(CLOCK_IP_HAS_CAN_TS_CLK)

#define TPIU_TRACE_CLK     CAN_TS_CLK

#endif

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /* #ifndef CLOCK_IP_CFG_DEFINES_H */

/** @} */


