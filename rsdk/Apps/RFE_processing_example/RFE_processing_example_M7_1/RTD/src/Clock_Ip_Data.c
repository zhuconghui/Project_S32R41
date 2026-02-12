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
*   @file       Clock_Ip_Data.c
*   @version    2.0.0
*
*   @brief   CLOCK driver implementations.
*   @details CLOCK driver implementations.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
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


#include "Clock_Ip_Private.h"

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_DATA_VENDOR_ID_C                      43
#define CLOCK_IP_DATA_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_DATA_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_DATA_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_DATA_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_DATA_SW_MINOR_VERSION_C               0
#define CLOCK_IP_DATA_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Data.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_DATA_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Data.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Data.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_DATA_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_DATA_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_DATA_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Data.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Data.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_DATA_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_DATA_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_DATA_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Data.c and Clock_Ip_Private.h are different"
#endif

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Clock_Ip_Data.c file and RegLockMacros.h file are of the same Autosar version */
    #if ((CLOCK_IP_DATA_AR_RELEASE_MAJOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (CLOCK_IP_DATA_AR_RELEASE_MINOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Data.c and RegLockMacros.h are different"
    #endif
    #endif
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define CLOCK_IP_NO_CALLBACK                   0U
#define CLOCK_IP_HWMUX_DIV_CMU                 1U
#define CLOCK_IP_PLL_MOD                       1U
#define CLOCK_IP_DFS                           1U
#define CLOCK_IP_GATE                          1U
#define CLOCK_IP_HWMUX_PCFS_DIV                2U
#define CLOCK_IP_CMU                           2U
#define CLOCK_IP_PLL                           2U
#define CLOCK_IP_HWMUX_DIV                     3U
#define CLOCK_IP_FAST_XOSC_CMU                 3U
#define CLOCK_IP_ATP_PLL                       3U
#define CLOCK_IP_SWMUX_DIV_CLKOUT              4U
#define CLOCK_IP_HWMUX_CMU                     5U
#define CLOCK_IP_PLL_OUT                       5U
#define CLOCK_IP_PCFS_PLL_OUT                  5U
#define CLOCK_IP_HWMUX                         6U
#define CLOCK_IP_DIV                           6U
#define CLOCK_IP_HWMUX_PCFS                    7U
#define CLOCK_IP_DIV_CMU                       7U
#define CLOCK_IP_ATP_PLL_OUT                   8U
#define CLOCK_IP_HWMUX_PCFS_CMU                9U
#define CLOCK_IP_SWMUX_DIV_CLKOUT_CMU          10U

#define CLOCK_IP_SYS_EXTENSION                 0U
#define CLOCK_IP_SYS_DIV2_EXTENSION            0U
#define CLOCK_IP_SYS_DIV4_EXTENSION            0U
#define CLOCK_IP_SYS_DIV8_EXTENSION            0U
#define CLOCK_IP_RT_DAPB_EXTENSION             0U
#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
#define CLOCK_IP_A53_CORE_EXTENSION            1U
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV2_CLK)
#define CLOCK_IP_A53_CORE_DIV2_EXTENSION       1U
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
#define CLOCK_IP_A53_CORE_DIV4_EXTENSION       1U
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV10_CLK)
#define CLOCK_IP_A53_CORE_DIV10_EXTENSION      1U
#endif
#define CLOCK_IP_ACCEL_EXTENSION               2U
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
#define CLOCK_IP_ACCEL_DIV3_EXTENSION          2U
#endif
#if defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
#define CLOCK_IP_ACCEL_DIV4_EXTENSION          2U
#endif
#define CLOCK_IP_ACCEL_XBAR_EXTENSION          3U
#define CLOCK_IP_ACCEL_XBAR_DIV2_EXTENSION     3U
#define CLOCK_IP_ACCEL_XBAR_DIV4_EXTENSION     3U
#define CLOCK_IP_ACCEL_XBAR_DIV8_EXTENSION     3U
#define CLOCK_IP_AP_DAPB_EXTENSION             3U
#define CLOCK_IP_GMAC0_REF_EXTENSION           4U
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
#define CLOCK_IP_GMAC0_REF_DIV_EXTENSION       5U
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
#define CLOCK_IP_GMAC1_REF_EXTENSION           6U
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
#define CLOCK_IP_GMAC1_REF_DIV_EXTENSION       7U
#endif
#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
#define CLOCK_IP_GMAC1_INT_EXTENSION           8U
#endif
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
#define CLOCK_IP_AURORA_TRACE_TEST_EXTENSION   9U
#endif
#define CLOCK_IP_CAN_PE_EXTENSION              10U
#define CLOCK_IP_CLKOUT0_EXTENSION             11U
#define CLOCK_IP_CLKOUT1_EXTENSION             12U
#define CLOCK_IP_CSI_EXTENSION                 13U
#if defined(CLOCK_IP_HAS_CSI_CFG_CLK)
#define CLOCK_IP_CSI_CFG_EXTENSION             14U
#endif
#define CLOCK_IP_CTE_EXTENSION                 15U
#if defined(CLOCK_IP_HAS_CSI_TXCLK_CLK)
#define CLOCK_IP_CSI_TXCLK_EXTENSION           16U
#endif
#define CLOCK_IP_MC_EXTENSION                  17U
#define CLOCK_IP_FTM0_EXT_EXTENSION            18U
#define CLOCK_IP_GMAC0_RX_EXTENSION            19U
#define CLOCK_IP_GMAC0_TS_EXTENSION            20U
#define CLOCK_IP_GMAC0_TX_EXTENSION            21U
#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK)
#define CLOCK_IP_GMAC1_RX_EXTENSION            22U
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK)
#define CLOCK_IP_GMAC1_TS_EXTENSION            23U
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK)
#define CLOCK_IP_GMAC1_TX_EXTENSION            24U
#endif
#define CLOCK_IP_LBIST_EXTENSION               25U
#define CLOCK_IP_LIN_BAUD_EXTENSION            26U
#define CLOCK_IP_NOC_TRACE_EXTENSION           27U
#define CLOCK_IP_QSPI_2X_EXTENSION             28U
#define CLOCK_IP_SPI_EXTENSION                 29U
#define CLOCK_IP_CAN_TS_EXTENSION              30U
#define CLOCK_IP_CAN_CHI_EXTENSION             31U
#define CLOCK_IP_TCLK_EXTENSION                32U
#define CLOCK_IP_DSPI_SCK_TST_EXTENSION        33U
#define CLOCK_IP_STCU_EXTENSION                34U


#define CLOCK_IP_FXOSC_INSTANCE            0U

#define CLOCK_IP_COREPLL_INSTANCE                       0U
#define CLOCK_IP_PERIPHPLL_INSTANCE                     1U

#define CLOCK_IP_PERIPHDFS_INSTANCE        0U

#define CLOCK_IP_CGM0_INSTANCE             0U
#define CLOCK_IP_CGM1_INSTANCE             1U
#define CLOCK_IP_CGM2_INSTANCE             2U
#define CLOCK_IP_CGM3_INSTANCE             3U

#define CLOCK_IP_CMU_FC_0_INSTANCE         0U
#define CLOCK_IP_CMU_FC_1_INSTANCE         1U
#define CLOCK_IP_CMU_FC_3_INSTANCE         3U
#define CLOCK_IP_CMU_FC_5_INSTANCE         5U
#define CLOCK_IP_CMU_FC_6_INSTANCE         6U
#define CLOCK_IP_CMU_FC_7_INSTANCE         7U
#define CLOCK_IP_CMU_FC_8_INSTANCE         8U
#define CLOCK_IP_CMU_FC_9_INSTANCE         9U
#define CLOCK_IP_CMU_FC_10_INSTANCE        10U
#define CLOCK_IP_CMU_FC_11_INSTANCE        11U
#define CLOCK_IP_CMU_FC_12_INSTANCE        12U
#define CLOCK_IP_CMU_FC_13_INSTANCE        13U
#define CLOCK_IP_CMU_FC_14_INSTANCE        14U
#define CLOCK_IP_CMU_FC_15_INSTANCE        15U
#define CLOCK_IP_CMU_FC_16_INSTANCE        16U
#define CLOCK_IP_CMU_FC_17_INSTANCE        17U
#define CLOCK_IP_CMU_FC_21_INSTANCE        21U
#define CLOCK_IP_CMU_FC_22_INSTANCE        22U
#define CLOCK_IP_CMU_FC_23_INSTANCE        23U
#define CLOCK_IP_CMU_FC_24_INSTANCE        24U
#define CLOCK_IP_CMU_FC_25_INSTANCE        25U
#define CLOCK_IP_CMU_FC_26_INSTANCE        26U
#define CLOCK_IP_CMU_FC_27_INSTANCE        27U
#define CLOCK_IP_CMU_FC_28_INSTANCE        28U
#define CLOCK_IP_CMU_FC_29_INSTANCE        29U
#define CLOCK_IP_CMU_FC_30_INSTANCE        30U
#define CLOCK_IP_CMU_FC_31_INSTANCE        31U

#define CLOCK_IP_DIV_0_INDEX               0U
#define CLOCK_IP_DIV_1_INDEX               1U
#define CLOCK_IP_DIV_2_INDEX               2U
#define CLOCK_IP_DIV_3_INDEX               3U
#define CLOCK_IP_DIV_4_INDEX               4U
#define CLOCK_IP_DIV_5_INDEX               5U
#define CLOCK_IP_DIV_6_INDEX               6U
#define CLOCK_IP_DIV_7_INDEX               7U
#define CLOCK_IP_DIV_8_INDEX               8U
#define CLOCK_IP_DIV_9_INDEX               9U

#define CLOCK_IP_PCFS_7_INDEX              7U
#define CLOCK_IP_PCFS_3_INDEX              3U
#define CLOCK_IP_PCFS_4_INDEX              4U
#define CLOCK_IP_PCFS_5_INDEX              5U
#define CLOCK_IP_PCFS_6_INDEX              6U
#define CLOCK_IP_PCFS_7_INDEX              7U
#define CLOCK_IP_PCFS_11_INDEX             11U
#define CLOCK_IP_PCFS_12_INDEX             12U
#define CLOCK_IP_PCFS_26_INDEX             26U

#define CLOCK_IP_PRT1_COL0_REQ0_INDEX      0U
#define CLOCK_IP_PRT1_COL0_REQ1_INDEX      1U
#define CLOCK_IP_PRT1_COL0_REQ2_INDEX      2U

#define CLOCK_IP_PARTITION_1_INDEX         1U

#define CLOCK_IP_COLLECTION_0_INDEX        0U

#define CLOCK_IP_SEL_0_INDEX      0U
#define CLOCK_IP_SEL_1_INDEX      1U
#define CLOCK_IP_SEL_2_INDEX      2U
#define CLOCK_IP_SEL_3_INDEX      3U
#define CLOCK_IP_SEL_4_INDEX      4U
#define CLOCK_IP_SEL_5_INDEX      5U
#define CLOCK_IP_SEL_6_INDEX      6U
#define CLOCK_IP_SEL_7_INDEX      7U
#define CLOCK_IP_SEL_8_INDEX      8U


#define PRTN0_COFB0_STAT_ADDRESS     (uint32)(IP_MC_ME_BASE + 0x110U)
#define PRTN0_COFB0_CLKEN_ADDRESS    (uint32)(IP_MC_ME_BASE + 0x130U)

#define CLOCK_IP_COREPLL_DIVIDER_COUNT                      10U
#define CLOCK_IP_PERIPHPLL_DIVIDER_COUNT                    10U

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_8

#include "Mcu_MemMap.h"

const uint8 Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE,                   /* CLOCK_IP_HWMUX_DIV_CMU */
    CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE,                   /* CLOCK_IP_HWMUX_PCFS_DIV */
    CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE,                   /* CLOCK_IP_HWMUX_DIV */
    CLOCK_IP_CGM_X_DE_DIV_WITHOUT_PHASE,                        /* CLOCK_IP_SWMUX_DIV_CLKOUT */
    CLOCK_IP_PLLDIG_PLL0DIV_DE_DIV_OUTPUT,                      /* CLOCK_IP_PLL_OUT */
    CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE,                   /* CLOCK_IP_DIV */
    CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE,                   /* CLOCK_IP_DIV_CMU */
#ifdef CLOCK_IP_AURORA_PLL_ATP_PLL0DIV_DE_DIV_OUTPUT
    CLOCK_IP_AURORA_PLL_ATP_PLL0DIV_DE_DIV_OUTPUT,              /* CLOCK_IP_ATP_PLL_OUT */
#elif defined(CLOCK_IP_AURORA_PLL_ATP_PLL_PLL0DIV_DE_DIV_OUTPUT)
    CLOCK_IP_AURORA_PLL_ATP_PLL_PLL0DIV_DE_DIV_OUTPUT,          /* CLOCK_IP_ATP_PLL_OUT */
#else
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
#endif
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_DE_DIV_WITHOUT_PHASE,                        /* CLOCK_IP_SWMUX_DIV_CLKOUT_CMU */
};
const uint8 Clock_Ip_au8DividerTriggerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8XoscCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
#ifdef CLOCK_IP_FXOSC_CTRL_OSCON_BYP_STATUS_OSC_STAT
    CLOCK_IP_FXOSC_CTRL_OSCON_BYP_STATUS_OSC_STAT,              /* CLOCK_IP_FAST_XOSC_CMU */
#elif defined(CLOCK_IP_FXOSC_OSCON_BYP_EOCV_GM_SEL)
    CLOCK_IP_FXOSC_OSCON_BYP_EOCV_GM_SEL,                       /* CLOCK_IP_FAST_XOSC_CMU */
#else
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
#endif
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8IrcoscCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8GateCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_MC_ME_PARTITION_COFB_ENABLE_REQUEST,               /* CLOCK_IP_GATE */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8FractionalDividerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
#ifdef CLOCK_IP_DFS_MFI_MFN
    CLOCK_IP_DFS_MFI_MFN,                                       /* CLOCK_IP_DFS */
#else
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
#endif
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8PllCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
#ifdef CLOCK_IP_PLLDIG_SW_DIS_PLLPD_RCLKSEL_LOCK
    CLOCK_IP_PLLDIG_SW_DIS_PLLPD_RCLKSEL_LOCK,                  /* CLOCK_IP_PLL_MOD */
#elif defined(CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN_SSCGBYP_SPREADCTL_STEPNO_STEPSIZE)
    CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN_SSCGBYP_SPREADCTL_STEPNO_STEPSIZE,/* CLOCK_IP_PLL_MOD */
#else
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
#endif
#ifdef CLOCK_IP_PLLDIG_SW_DIS_PLLPD_RCLKSEL_LOCK
    CLOCK_IP_PLLDIG_SW_DIS_PLLPD_RCLKSEL_LOCK,                  /* CLOCK_IP_PLL */
#elif defined(CLOCK_IP_PLLDIG_RDIV_MFI)
    CLOCK_IP_PLLDIG_RDIV_MFI,                                   /* CLOCK_IP_PLL */
#else
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
#endif
#ifdef CLOCK_IP_AURORA_PLL_ATP_FNPDIV_NDIV_PDIV_FCW
    CLOCK_IP_AURORA_PLL_ATP_FNPDIV_NDIV_PDIV_FCW,               /* CLOCK_IP_ATP_PLL */
#elif defined(CLOCK_IP_AURORA_PLL_ATP_PLL_FNPDIV_NDIV_PDIV_FCW)
    CLOCK_IP_AURORA_PLL_ATP_PLL_FNPDIV_NDIV_PDIV_FCW,           /* CLOCK_IP_ATP_PLL */
#else
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
#endif
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8SelectorCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_HWMUX_DIV_CMU */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_RAMPDOWN_RAMPUP_SWIP,         /* CLOCK_IP_HWMUX_PCFS_DIV */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_HWMUX_DIV */
    CLOCK_IP_CGM_X_CSC_CSS_CS_GRIP,                             /* CLOCK_IP_SWMUX_DIV_CLKOUT */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_HWMUX_CMU */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_HWMUX */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_RAMPDOWN_RAMPUP_SWIP,         /* CLOCK_IP_HWMUX_PCFS */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_RAMPDOWN_RAMPUP_SWIP,         /* CLOCK_IP_HWMUX_PCFS_CMU */
    CLOCK_IP_CGM_X_CSC_CSS_CS_GRIP,                             /* CLOCK_IP_SWMUX_DIV_CLKOUT_CMU */
};
const uint8 Clock_Ip_au8PcfsCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS,                    /* CLOCK_IP_PCFS_PLL_OUT  */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8CmuCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_HWMUX_DIV_CMU */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_CMU */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_FAST_XOSC_CMU */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_HWMUX_CMU */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_DIV_CMU */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_HWMUX_PCFS_CMU */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_SWMUX_DIV_CLKOUT_CMU */
};




/* Clock features mapping */
const uint8 Clock_Ip_au8ClockFeatures[CLOCK_IP_NAMES_NO][CLOCK_IP_FEATURES_NO] =
/*
***************************************************************************************************************************************************************************************************************************************************************
***********************************     ***********************       ***********************   E   ***************************       *       ****************       *****************       **********************       *****************       *************
***********************************  I  ***********************   C   ***********************   X   ***************************       *   S   ****************   D   *****************       **********************       *****************       *************
***********************************  N  ***********************   A   ***********************   T   ***************************   P   *   E   ****************   I   *****************   G   **********************   P   *****************       *************
***********************************  S  ***********************   L   ***********************   E   ***************************   O   *   L   ****************   V   *****************   A   **********************   C   *****************   C   *************
***********************************  T  ***********************   L   ***********************   N   ***************************   W   *   E   ****************   I   *****************   T   **********************   F   *****************   M   *************
***********************************  A  ***********************   B   ***********************   S   ***************************   E   *   C   ****************   D   *****************   E   **********************   S   *****************   U   *************
***********************************  N  ***********************   A   ***********************   I   ***************************   R   *   T   ****************   E   *****************       **********************       *****************       *************
***********************************  C  ***********************   C   ***********************   O   ***************************       *   O   ****************   R   *****************       **********************       *****************       *************
***********************************  E  ***********************   K   ***********************   N   ***************************       *   R   ****************       *****************       **********************       *****************       *************
***********************************     ***********************       ***********************       ***************************       *       ****************       *****************       **********************       *****************       *************
******************************************************************************************************************************************************************************************************************************************************************/
{
/*   CLOCK_IS_OFF clock         */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   CLOCK_IS_OFF               */
/*   FIRC_CLK clock             */ {0U,                          CLOCK_IP_CMU,                 0U,                               0U,    0U,                     0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_1_INSTANCE}, /*   FIRC_CLK clock             */
/*   FXOSC_CLK clock            */ {0U,                          CLOCK_IP_FAST_XOSC_CMU,       0U,                               0U,    0U,                     0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_0_INSTANCE}, /*   FXOSC_CLK clock            */
#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
/*   AURORAPLL_CLK clock        */ {0U,                          CLOCK_IP_ATP_PLL,             0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   AURORAPLL_CLK clock        */
#endif
/*   COREPLL_CLK clock          */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PLL_MOD,             0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   COREPLL_CLK clock          */
/*   PERIPHPLL_CLK clock        */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL,                 0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   PERIPHPLL_CLK clock        */
/*   COREPLL_PHI0 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PCFS_PLL_OUT,        0U,                               0U,    0U,                     CLOCK_IP_DIV_0_INDEX,   0U,                           CLOCK_IP_PCFS_3_INDEX,  0U},                         /*   COREPLL_PHI0 clock         */
/*   COREPLL_PHI1 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PCFS_PLL_OUT,        0U,                               0U,    0U,                     CLOCK_IP_DIV_1_INDEX,   0U,                           CLOCK_IP_PCFS_4_INDEX,  0U},                         /*   COREPLL_PHI1 clock         */
/*   COREPLL_PHI2 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PCFS_PLL_OUT,        0U,                               0U,    0U,                     CLOCK_IP_DIV_2_INDEX,   0U,                           CLOCK_IP_PCFS_5_INDEX,  0U},                         /*   COREPLL_PHI2 clock         */
/*   COREPLL_PHI3 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_3_INDEX,   0U,                           CLOCK_IP_PCFS_6_INDEX,  0U},                         /*   COREPLL_PHI3 clock         */
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
/*   COREPLL_PHI4 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_4_INDEX,   0U,                           CLOCK_IP_PCFS_7_INDEX,  0U},                         /*   COREPLL_PHI4 clock         */
#endif
/*   COREPLL_PHI5 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_5_INDEX,   0U,                           0U,                     0U},                         /*   COREPLL_PHI5 clock         */
/*   COREPLL_PHI6 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_6_INDEX,   0U,                           0U,                     0U},                         /*   COREPLL_PHI6 clock         */
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
/*   COREPLL_PHI7 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_7_INDEX,   0U,                           0U,                     0U},                         /*   COREPLL_PHI7 clock         */
#endif
/*   COREPLL_PHI8 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_8_INDEX,   0U,                           CLOCK_IP_PCFS_11_INDEX, 0U},                         /*   COREPLL_PHI8 clock         */
/*   COREPLL_PHI9 clock         */ {CLOCK_IP_COREPLL_INSTANCE,   CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_9_INDEX,   0U,                           CLOCK_IP_PCFS_12_INDEX, 0U},                         /*   COREPLL_PHI9 clock         */
/*   PERIPHPLL_PHI0 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI0 clock       */
/*   PERIPHPLL_PHI1 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_1_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI1 clock       */
/*   PERIPHPLL_PHI2 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_2_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI2 clock       */
/*   PERIPHPLL_PHI3 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_3_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI3 clock       */
/*   PERIPHPLL_PHI4 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_4_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI4 clock       */
/*   PERIPHPLL_PHI5 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_5_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI5 clock       */
/*   PERIPHPLL_PHI6 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_6_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI6 clock       */
/*   PERIPHPLL_PHI7 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_7_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI7 clock       */
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
/*   PERIPHPLL_PHI8 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_8_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI8 clock       */
#endif
/*   PERIPHPLL_PHI9 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE, CLOCK_IP_PLL_OUT,             0U,                               0U,    0U,                     CLOCK_IP_DIV_9_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_PHI9 clock       */
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
/*   AURORAPLL_PHI0 clock       */ {0U,                          CLOCK_IP_ATP_PLL_OUT,         0U,                               0U,    0U,                     CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     0U},                         /*   COREPLL_PHI0 clock         */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
/*   AURORAPLL_PHI1 clock       */ {0U,                          CLOCK_IP_ATP_PLL_OUT,         0U,                               0U,    0U,                     CLOCK_IP_DIV_1_INDEX,   0U,                           0U,                     0U},                         /*   COREPLL_PHI0 clock         */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI2_CLK)
/*   AURORAPLL_PHI2 clock       */ {0U,                          CLOCK_IP_ATP_PLL_OUT,         0U,                               0U,    0U,                     CLOCK_IP_DIV_2_INDEX,   0U,                           0U,                     0U},                         /*   COREPLL_PHI0 clock         */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
/*   PERIPHPLL_DFS1 clock       */ {CLOCK_IP_PERIPHDFS_INSTANCE, CLOCK_IP_DFS,                 0U,                               0U,    0U,                     CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     0U},                         /*   PERIPHPLL_DFS1 clock       */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
/*   PERIPHPLL_DFS2 clock       */ {CLOCK_IP_PERIPHDFS_INSTANCE, CLOCK_IP_DFS,                 0U,                               0U,    0U,                     CLOCK_IP_DIV_1_INDEX,   0U,                           CLOCK_IP_PCFS_26_INDEX, 0U},                         /*   PERIPHPLL_DFS2 clock       */
#endif
/*   ftm_0_ext_ref clock        */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   ftm_0_ext_ref clock        */
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
/*   gmac_0_ext_ref clock       */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_0_ext_ref clock       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
/*   gmac_0_ext_rx clock        */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_0_ext_rx clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
/*   gmac_0_ext_tx clock        */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_0_ext_tx clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
/*   gmac_0_ext_ts clock        */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_0_ext_ts clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
/*   gmac_0_sgmii_ref clock     */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_0_sgmii_ref clock     */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
/*   gmac_0_sgmii_rx clock      */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_0_sgmii_rx clock      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
/*   gmac_0_sgmii_tx clock      */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_0_sgmii_tx clock      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
/*   gmac_1_ext_ref clock       */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_1_ext_ref clock       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
/*   gmac_1_ext_rx clock        */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_1_ext_rx clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
/*   gmac_1_ext_tx clock        */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_1_ext_tx clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
/*   gmac_1_ext_ts clock        */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   gmac_1_ext_ts clock        */
#endif
#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
/*   firc_muxed_clk clock       */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   FIRC_MUXED_CLK clock       */
#endif
#if defined(CLOCK_IP_HAS_LVDS_CLK)
/*   lvds clock                 */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LVDS_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
/*   rfe_pll_clk clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   RFE_PLL_CLK clock          */
#endif
/*   SYS_CLK clock              */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_HWMUX,               CLOCK_IP_SYS_EXTENSION,           0U,    CLOCK_IP_SEL_0_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   SYS_CLK clock              */
/*   SYS_DIV2_CLK clock         */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_NO_CALLBACK,         CLOCK_IP_SYS_DIV2_EXTENSION,      0U,    CLOCK_IP_SEL_0_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   SYS_DIV2_CLK clock         */
/*   SYS_DIV4_CLK clock         */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_NO_CALLBACK,         CLOCK_IP_SYS_DIV4_EXTENSION,      0U,    CLOCK_IP_SEL_0_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   SYS_DIV4_CLK clock         */
/*   SYS_DIV8_CLK clock         */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_CMU,                 CLOCK_IP_SYS_DIV8_EXTENSION,      0U,    CLOCK_IP_SEL_0_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_7_INSTANCE}, /*   SYS_DIV8_CLK clock         */
/*   RT_DAPB_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_NO_CALLBACK,         CLOCK_IP_RT_DAPB_EXTENSION,       0U,    CLOCK_IP_SEL_0_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   RT_DAPB_CLK clock          */
#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
/*   A53_CORE_CLK clock         */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_HWMUX_PCFS_CMU,      CLOCK_IP_A53_CORE_EXTENSION,      0U,    CLOCK_IP_SEL_0_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_27_INSTANCE},/*   A53_CORE_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV2_CLK)
/*   A53_CORE_DIV2_CLK clock    */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_NO_CALLBACK,         CLOCK_IP_A53_CORE_DIV2_EXTENSION, 0U,    CLOCK_IP_SEL_0_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   A53_CORE_DIV2_CLK clock    */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
/*   A53_CORE_DIV4_CLK clock   */  {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_NO_CALLBACK,         CLOCK_IP_A53_CORE_DIV4_EXTENSION, 0U,    CLOCK_IP_SEL_0_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   A53_CORE_DIV4_CLK clock   */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV10_CLK)
/*   A53_CORE_DIV10_CLK clock   */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_NO_CALLBACK,         CLOCK_IP_A53_CORE_DIV10_EXTENSION,0U,    CLOCK_IP_SEL_0_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   A53_CORE_DIV10_CLK clock   */
#endif
/*   ACCEL_CLK clock            */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_HWMUX_PCFS_DIV,      CLOCK_IP_ACCEL_EXTENSION,         0U,    CLOCK_IP_SEL_1_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     0U},                         /*   ACCEL_CLK clock            */
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
/*   ACCEL_DIV3_CLK clock       */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_CMU,                 CLOCK_IP_ACCEL_DIV3_EXTENSION,    0U,    CLOCK_IP_SEL_1_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_31_INSTANCE},/*   ACCEL_DIV3_CLK clock       */
#endif
#if defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
/*   ACCEL_DIV4_CLK clock       */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_CMU,                 CLOCK_IP_ACCEL_DIV4_EXTENSION,    0U,    CLOCK_IP_SEL_1_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_31_INSTANCE},/*   ACCEL_DIV4_CLK clock       */
#endif
/*   ACCEL_XBAR_CLK clock       */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_HWMUX_PCFS,          CLOCK_IP_ACCEL_XBAR_EXTENSION,    0U,    CLOCK_IP_SEL_2_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   ACCEL_XBAR_CLK clock       */
/*   ACCEL_XBAR_DIV2_CLK clock  */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_NO_CALLBACK,         CLOCK_IP_ACCEL_XBAR_DIV2_EXTENSION,0U,   CLOCK_IP_SEL_2_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   ACCEL_XBAR_DIV2_CLK clock  */
/*   ACCEL_XBAR_DIV4_CLK clock  */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_CMU,                 CLOCK_IP_ACCEL_XBAR_DIV4_EXTENSION,0U,   CLOCK_IP_SEL_2_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_29_INSTANCE},/*   ACCEL_XBAR_DIV4_CLK clock  */
/*   ACCEL_XBAR_DIV8_CLK clock  */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_CMU,                 CLOCK_IP_ACCEL_XBAR_DIV8_EXTENSION,0U,   CLOCK_IP_SEL_2_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_30_INSTANCE},/*   ACCEL_XBAR_DIV8_CLK clock  */
/*   AP_DAPB_CLK clock          */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_NO_CALLBACK,         CLOCK_IP_AP_DAPB_EXTENSION,       0U,    CLOCK_IP_SEL_2_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   AP_DAPB_CLK clock          */
#if defined(CLOCK_IP_HAS_GMAC0_REF_CLK)
/*   GMAC0_REF_CLK clock        */ {CLOCK_IP_CGM3_INSTANCE,      CLOCK_IP_HWMUX,               CLOCK_IP_GMAC0_REF_EXTENSION,     0U,    CLOCK_IP_SEL_3_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   GMAC0_REF_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
/*   GMAC0_REF_DIV_CLK clock    */ {CLOCK_IP_CGM3_INSTANCE,      CLOCK_IP_DIV,                 CLOCK_IP_GMAC0_REF_DIV_EXTENSION, 0U,    CLOCK_IP_SEL_3_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     0U},                         /*   GMAC0_REF_DIV_CLK clock    */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
/*   GMAC1_REF_CLK clock        */ {CLOCK_IP_CGM2_INSTANCE,      CLOCK_IP_HWMUX,               CLOCK_IP_GMAC1_REF_EXTENSION,     0U,    CLOCK_IP_SEL_3_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   GMAC1_REF_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
/*   GMAC1_REF_DIV_CLK clock    */ {CLOCK_IP_CGM2_INSTANCE,      CLOCK_IP_DIV,                 CLOCK_IP_GMAC1_REF_DIV_EXTENSION, 0U,    CLOCK_IP_SEL_3_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     0U},                         /*   GMAC1_REF_DIV_CLK clock    */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
/*   GMAC1_INT_CLK clock        */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_HWMUX,               CLOCK_IP_GMAC1_INT_EXTENSION,     0U,    CLOCK_IP_SEL_6_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   GMAC1_INT_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
/*   AURORA_TRACE_TEST_CLK clock*/ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_HWMUX,               CLOCK_IP_AURORA_TRACE_TEST_EXTENSION, 0U, CLOCK_IP_SEL_6_INDEX,  0U,                     0U,                           0U,                     0U},                         /*   AURORA_TRACE_TEST_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_DIFF_CLK)
/*   AURORAPLL_DIFF_CLK clock   */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   AURORAPLL_DIFF_CLK clock   */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
/*   GMAC_1_INT_REF_CLK clock   */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   GMAC_1_INT_REF_CLK clock   */
#endif
/*   THE_LAST_PRODUCER_CLK      */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   THE_LAST_PRODUCER_CLK      */
/*   BBE32EP_DSP_CLK clock      */ {0U,                          CLOCK_IP_GATE,                0U,                               0U,    0U,                     0U,                     CLOCK_IP_PRT1_COL0_REQ0_INDEX,0U,                     0U},                         /*   BBE32EP_DSP_CLK clock      */
/*   CAN_CHI_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_DIV,                 CLOCK_IP_CAN_CHI_EXTENSION,       0U,    CLOCK_IP_SEL_6_INDEX,   CLOCK_IP_DIV_1_INDEX,   0U,                           0U,                     0U},                         /*   CAN_CHI_CLK clock          */
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
/*   CAN_TS_CLK clock           */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_DIV,                 CLOCK_IP_CAN_TS_EXTENSION,        0U,    CLOCK_IP_SEL_6_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     0U},                         /*   CAN_TS_CLK clock           */
#else
/*   CAN_TS_CLK clock           */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_HWMUX_DIV,           CLOCK_IP_CAN_TS_EXTENSION,        0U,    CLOCK_IP_SEL_6_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     0U},                         /*   CAN_TS_CLK clock           */
#endif
/*   CAN_PE_CLK clock           */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_HWMUX_CMU,           CLOCK_IP_CAN_PE_EXTENSION,        0U,    CLOCK_IP_SEL_7_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_13_INSTANCE},/*   CAN_PE_CLK clock           */
/*   CAN0_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   CAN0_CLK clock             */
/*   CAN1_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   CAN1_CLK clock             */
/*   CLKOUT0_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_SWMUX_DIV_CLKOUT_CMU,CLOCK_IP_CLKOUT0_EXTENSION,       0U,    CLOCK_IP_SEL_1_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     CLOCK_IP_CMU_FC_11_INSTANCE},/*   CLKOUT0_CLK clock          */
/*   CLKOUT1_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_SWMUX_DIV_CLKOUT,    CLOCK_IP_CLKOUT1_EXTENSION,       0U,    CLOCK_IP_SEL_2_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     0U},                         /*   CLKOUT1_CLK clock          */
#if defined(CLOCK_IP_HAS_CORE_A53_CLUSTER_0_CLK)
/*   CORE_A53_CLUSTER_0_CLK     */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   CORE_A53_CLUSTER_0_CLK     */
#endif
#if defined(CLOCK_IP_HAS_CORE_A53_CLUSTER_1_CLK)
/*   CORE_A53_CLUSTER_1_CLK     */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   CORE_A53_CLUSTER_1_CLK     */
#endif
/*   CRC_CLK clock              */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   CRC_CLK clock              */
#if defined(CLOCK_IP_HAS_CSI_CLK)
/*   CSI_CLK clock              */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_HWMUX,               CLOCK_IP_CSI_EXTENSION,           0U,    CLOCK_IP_SEL_4_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   CSI_CLK clock              */
#endif
#if defined(CLOCK_IP_HAS_CSI_CFG_CLK)
/*   CSI_CFG_CLK clock          */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_DIV_CMU,             CLOCK_IP_CSI_CFG_EXTENSION,       0U,    CLOCK_IP_SEL_4_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     CLOCK_IP_CMU_FC_28_INSTANCE},/*   CSI_CFG_CLK clock          */
#endif
#if defined(CLOCK_IP_HAS_CTE_CLK)
/*   CTE_CLK clock              */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_HWMUX_CMU,           CLOCK_IP_CTE_EXTENSION,           0U,    CLOCK_IP_SEL_3_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_26_INSTANCE},/*   CTE_CLK clock              */
#endif
#if defined(CLOCK_IP_HAS_CSI_IPS_CLK)
/*   CSI_IPS_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   CSI_IPS_CLK clock          */
#endif
#if defined(CLOCK_IP_HAS_CSI_TXCLK_CLK)
/*   CSI_TXCLK_CLK clock        */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_DIV,                 CLOCK_IP_CSI_TXCLK_EXTENSION,     0U,    CLOCK_IP_SEL_4_INDEX,   CLOCK_IP_DIV_1_INDEX,   0U,                           0U,                     0U},                         /*   CSI_TXCLK_CLK clock        */
#endif
/*   MC_CLK clock               */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_HWMUX_CMU,           CLOCK_IP_MC_EXTENSION,            0U,    CLOCK_IP_SEL_3_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_10_INSTANCE},/*   MC_CLK clock               */
/*   CTU_CLK clock              */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   CTU_CLK clock              */
/*   CTU_IPS_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   CTU_IPS_CLK clock          */
/*   DAPB_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   DAPB_CLK clock             */
/*   DMA_CLK clock              */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   DMA_CLK clock              */
/*   DMA_CRC_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   DMA_CRC_CLK clock          */
/*   DMA_TCD_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   DMA_TCD_CLK clock          */
/*   DMAMUX0_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   DMAMUX0_CLK clock          */
/*   DMAMUX1_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   DMAMUX1_CLK clock          */
/*   DSPI_SCK_TST_CLK clock     */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_DIV,                 CLOCK_IP_DSPI_SCK_TST_EXTENSION,  0U,    CLOCK_IP_SEL_6_INDEX,   CLOCK_IP_DIV_3_INDEX,   0U,                           0U,                     0U},                         /*   DSPI_SCK_TST_CLK clock     */
/*   EIM_AP1_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   EIM_AP1_CLK clock          */
/*   EIM_CM70_CLK clock         */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   EIM_CM70_CLK clock         */
#if defined(CLOCK_IP_HAS_EIM_CM71_CLK)
/*   EIM_CM71_CLK clock         */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   EIM_CM71_CLK clock         */
#endif
/*   EIM_DSP_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   EIM_DSP_CLK clock          */
/*   EIM_RT0_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   EIM_RT0_CLK clock          */
/*   EIM_RT2_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   EIM_RT2_CLK clock          */
/*   ERM_AP1_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   ERM_AP1_CLK clock          */
/*   ERM_RT0_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   ERM_RT0_CLK clock          */
/*   ERM_RT1_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   ERM_RT1_CLK clock          */
/*   ERM_RT2_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   ERM_RT2_CLK clock          */
/*   FCCU_IPS_CLK clock         */ {0U,                          CLOCK_IP_CMU,                 0U,                               0U,    0U,                     0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_12_INSTANCE},/*   FCCU_IPS_CLK clock         */
/*   FTM0_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   FTM0_CLK clock             */
/*   FTM0_EXT_CLK clock         */ {CLOCK_IP_CGM3_INSTANCE,      CLOCK_IP_HWMUX_DIV_CMU,       CLOCK_IP_FTM0_EXT_EXTENSION,      0U,    CLOCK_IP_SEL_0_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     CLOCK_IP_CMU_FC_3_INSTANCE },/*   FTM0_EXT_CLK clock         */
/*   GMAC0_RX_CLK clock         */ {CLOCK_IP_CGM3_INSTANCE,      CLOCK_IP_HWMUX_CMU,           CLOCK_IP_GMAC0_RX_EXTENSION,      0U,    CLOCK_IP_SEL_4_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_21_INSTANCE},/*   GMAC0_RX_CLK clock         */
/*   GMAC0_TS_CLK clock         */ {CLOCK_IP_CGM3_INSTANCE,      CLOCK_IP_HWMUX_DIV_CMU,       CLOCK_IP_GMAC0_TS_EXTENSION,      0U,    CLOCK_IP_SEL_1_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     CLOCK_IP_CMU_FC_15_INSTANCE},/*   GMAC0_TS_CLK clock         */
/*   GMAC0_TX_CLK clock         */ {CLOCK_IP_CGM3_INSTANCE,      CLOCK_IP_HWMUX_CMU,           CLOCK_IP_GMAC0_TX_EXTENSION,      0U,    CLOCK_IP_SEL_2_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     CLOCK_IP_CMU_FC_14_INSTANCE},/*   GMAC0_TX_CLK clock         */
#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK)
/*   GMAC1_RX_CLK clock         */ {CLOCK_IP_CGM2_INSTANCE,      CLOCK_IP_HWMUX_CMU,           CLOCK_IP_GMAC1_RX_EXTENSION,      0U,    CLOCK_IP_SEL_4_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_25_INSTANCE},/*   GMAC1_RX_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK)
/*   GMAC1_TS_CLK clock         */ {CLOCK_IP_CGM2_INSTANCE,      CLOCK_IP_HWMUX_DIV_CMU,       CLOCK_IP_GMAC1_TS_EXTENSION,      0U,    CLOCK_IP_SEL_1_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     CLOCK_IP_CMU_FC_24_INSTANCE},/*   GMAC1_TS_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK)
/*   GMAC1_TX_CLK clock         */ {CLOCK_IP_CGM2_INSTANCE,      CLOCK_IP_HWMUX_DIV_CMU,       CLOCK_IP_GMAC1_TX_EXTENSION,      0U,    CLOCK_IP_SEL_2_INDEX,   CLOCK_IP_DIV_0_INDEX,   0U,                           0U,                     CLOCK_IP_CMU_FC_23_INSTANCE},/*   GMAC1_TX_CLK clock         */
#endif
/*   IIC0_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   IIC0_CLK clock             */
/*   IIC1_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   IIC1_CLK clock             */
/*   LBIST_CLK clock            */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_HWMUX_PCFS_DIV,      CLOCK_IP_LBIST_EXTENSION,         0U,    CLOCK_IP_SEL_6_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   LBIST_CLK clock            */
/*   LBIST0_CLK clock           */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LBIST0_CLK clock           */
/*   LBIST1_CLK clock           */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LBIST1_CLK clock           */
/*   LBIST2_CLK clock           */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LBIST2_CLK clock           */
/*   LBIST3_CLK clock           */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LBIST3_CLK clock           */
/*   LBIST4_CLK clock           */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LBIST4_CLK clock           */
/*   LBIST5_CLK clock           */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LBIST5_CLK clock           */
/*   LBIST6_CLK clock           */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LBIST6_CLK clock           */
/*   LBIST7_CLK clock           */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LBIST7_CLK clock           */
/*   LIN_BAUD_CLK clock         */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_HWMUX,               CLOCK_IP_LIN_BAUD_EXTENSION,      0U,    CLOCK_IP_SEL_8_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   LIN_BAUD_CLK clock         */
/*   LINFLEXD_CLK clock         */ {0U,                          CLOCK_IP_CMU,                 0U,                               0U,    0U,                     0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_16_INSTANCE},/*   LINFLEXD_CLK clock         */ \
/*   LIN0_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LIN0_CLK clock             */
#if defined(CLOCK_IP_HAS_LIN1_CLK)
/*   LIN1_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   LIN1_CLK clock             */
#endif
/*   SYS_M7_0_CLK clock         */ {0U,                          CLOCK_IP_CMU,                 0U,                               0U,    0U,                     0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_6_INSTANCE}, /*   SYS_M7_0_CLK clock         */
#if defined(CLOCK_IP_HAS_SYS_M7_1_CLK)
/*   SYS_M7_1_CLK clock         */ {0U,                          CLOCK_IP_CMU,                 0U,                               0U,    0U,                     0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_8_INSTANCE}, /*   SYS_M7_1_CLK clock         */
#endif
/*   SYS_HSE_SYS_CLK clock      */ {0U,                          CLOCK_IP_CMU,                 0U,                               0U,    0U,                     0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_9_INSTANCE}, /*   SYS_HSE_SYS_CLK clock      */
#if defined(CLOCK_IP_HAS_MIPICSI2_0_CLK)
/*   MIPICSI2_0_CLK clock       */ {0U,                          CLOCK_IP_GATE,                0U,                               0U,    0U,                     0U,                     CLOCK_IP_PRT1_COL0_REQ2_INDEX,0U,                     0U},                         /*   MIPICSI2_0_CLK clock       */
#endif
#if defined(CLOCK_IP_HAS_MIPICSI2_1_CLK)
/*   MIPICSI2_1_CLK clock       */ {0U,                          CLOCK_IP_GATE,                0U,                               0U,    0U,                     0U,                     CLOCK_IP_PRT1_COL0_REQ2_INDEX,0U,                     0U},                         /*   MIPICSI2_1_CLK clock       */
#endif
/*   MSCM_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   MSCM_CLK clock             */
/*   NOC_TRACE_CLK clock        */ {CLOCK_IP_CGM1_INSTANCE,      CLOCK_IP_HWMUX,               CLOCK_IP_NOC_TRACE_EXTENSION,     0U,    CLOCK_IP_SEL_5_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   NOC_TRACE_CLK clock        */
/*   OCOTP_CLK clock            */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   OCOTP_CLK clock            */
/*   PIT0_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   PIT0_CLK clock             */
/*   PIT2_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   PIT2_CLK clock             */
/*   QSPI_2X_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_HWMUX_DIV,           CLOCK_IP_QSPI_2X_EXTENSION,       0U,    CLOCK_IP_SEL_5_INDEX,   0U,                     0U,                           0U,                     0U},                         /*   QSPI_2X_CLK clock          */
/*   QSPI_1X_CLK clock          */ {0U,                          CLOCK_IP_CMU,                 0U,                               0U,    0U,                     0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_17_INSTANCE},/*   QSPI_1X_CLK clock          */
/*   QSPI0_CLK clock            */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   QSPI0_CLK clock            */
/*   SAR_ADC_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SAR_ADC_CLK clock          */
/*   SEMA42_1_CLK clock         */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SEMA42_1_CLK clock         */
/*   SEMA42_CLK clock           */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SEMA42_CLK clock           */
/*   SIUL2_CLK clock            */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SIUL2_CLK clock            */
/*   SPI_CLK clock              */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_HWMUX_CMU,           CLOCK_IP_SPI_EXTENSION,           0U,    CLOCK_IP_SEL_4_INDEX,   0U,                     0U,                           0U,                     CLOCK_IP_CMU_FC_22_INSTANCE},/*   SPI_CLK clock              */
/*   SPI0_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SPI0_CLK clock             */
/*   SPI1_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SPI1_CLK clock             */
#if defined(CLOCK_IP_HAS_SPI2_CLK)
/*   SPI2_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SPI2_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_SPI3_CLK)
/*   SPI3_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SPI3_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_SPT_CLK)
/*   SPT_CLK clock              */ {0U,                          CLOCK_IP_GATE,                0U,                               0U,    0U,                     0U,                     CLOCK_IP_PRT1_COL0_REQ1_INDEX,0U,                     0U},                         /*   SPT_CLK clock              */
#endif
/*   SRAM_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SRAM_CLK clock             */
/*   STCU_CLK clock             */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_DIV_CMU,             CLOCK_IP_STCU_EXTENSION,          0U,    CLOCK_IP_SEL_6_INDEX,   CLOCK_IP_DIV_4_INDEX,   0U,                           0U,                     CLOCK_IP_CMU_FC_5_INSTANCE}, /*   STCU_CLK clock             */
/*   STM0_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   STM0_CLK clock             */
/*   STM1_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   STM1_CLK clock             */
/*   STM2_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   STM2_CLK clock             */
/*   SWT0_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SWT0_CLK clock             */
#if defined(CLOCK_IP_HAS_SWT1_CLK)
/*   SWT1_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SWT1_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_SWT2_CLK)
/*   SWT2_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SWT2_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_SWT3_CLK)
/*   SWT3_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   SWT3_CLK clock             */
#endif
/*   TMU_CLK clock              */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   TMU_CLK clock              */
/*   TCLK_CLK clock             */ {CLOCK_IP_CGM0_INSTANCE,      CLOCK_IP_DIV,                 CLOCK_IP_TCLK_EXTENSION,          0U,    CLOCK_IP_SEL_6_INDEX,   CLOCK_IP_DIV_2_INDEX,   0U,                           0U,                     0U},                         /*   TCLK_CLK clock             */
#if defined(CLOCK_IP_HAS_WKPU_CLK)
/*   WKPU_CLK clock             */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   WKPU_CLK clock             */
#endif
/*   XRDC0_CLK clock            */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   XRDC0_CLK clock            */
/*   XRDC1_CLK clock            */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,                               0U,    0U,                     0U,                     0U,                           0U,                     0U},                         /*   XRDC1_CLK clock            */
};

/*!
 * @brief Reset value of a software clock mux associated to a clock name
 */
const uint8 Clock_Ip_au8SoftwareMuxResetValue[CLOCK_IP_NAMES_NO] = {
/*   CLOCK_IS_OFF clock         */ 0U,
/*   FIRC_CLK clock             */ 0U,
/*   FXOSC_CLK clock            */ 0U,
#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
/*   AURORAPLL_CLK clock        */ 0U,
#endif
/*   COREPLL_CLK clock          */ 0U,
/*   PERIPHPLL_CLK clock        */ 0U,
/*   COREPLL_PHI0 clock         */ 0U,
/*   COREPLL_PHI1 clock         */ 0U,
/*   COREPLL_PHI2 clock         */ 0U,
/*   COREPLL_PHI3 clock         */ 0U,
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
/*   COREPLL_PHI4 clock         */ 0U,
#endif
/*   COREPLL_PHI5 clock         */ 0U,
/*   COREPLL_PHI6 clock         */ 0U,
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
/*   COREPLL_PHI7 clock         */ 0U,
#endif
/*   COREPLL_PHI8 clock         */ 0U,
/*   COREPLL_PHI9 clock         */ 0U,
/*   PERIPHPLL_PHI0 clock       */ 0U,
/*   PERIPHPLL_PHI1 clock       */ 0U,
/*   PERIPHPLL_PHI2 clock       */ 0U,
/*   PERIPHPLL_PHI3 clock       */ 0U,
/*   PERIPHPLL_PHI4 clock       */ 0U,
/*   PERIPHPLL_PHI5 clock       */ 0U,
/*   PERIPHPLL_PHI6 clock       */ 0U,
/*   PERIPHPLL_PHI7 clock       */ 0U,
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
/*   PERIPHPLL_PHI8 clock       */ 0U,
#endif
/*   PERIPHPLL_PHI9 clock       */ 0U,
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
/*   AURORAPLL_PHI0 clock       */ 0U,
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
/*   AURORAPLL_PHI1 clock       */ 0U,
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI2_CLK)
/*   AURORAPLL_PHI2 clock       */ 0U,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
/*   PERIPHPLL_DFS1 clock       */ 0U,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
/*   PERIPHPLL_DFS2 clock       */ 0U,
#endif
/*   ftm_0_ext_ref clock        */ 0U,
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
/*   gmac_0_ext_ref clock       */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
/*   gmac_0_ext_rx clock        */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
/*   gmac_0_ext_tx clock        */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
/*   gmac_0_ext_ts clock        */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
/*   gmac_0_sgmii_ref clock     */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
/*   gmac_0_sgmii_rx clock      */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
/*   gmac_0_sgmii_tx clock      */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
/*   gmac_1_ext_ref clock       */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
/*   gmac_1_ext_rx clock        */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
/*   gmac_1_ext_tx clock        */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
/*   gmac_1_ext_ts clock        */ 0U,
#endif
#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
/*   FIRC_MUXED_CLK clock       */ 0U,
#endif
#if defined(CLOCK_IP_HAS_LVDS_CLK)
/*   LVDS_CLK clock             */ 0U,
#endif
#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
/*   RFE_PLL_CLK clock          */ 0U,
#endif
/*   SYS_CLK clock              */ 0U,
/*   SYS_DIV2_CLK clock         */ 0U,
/*   SYS_DIV4_CLK clock         */ 0U,
/*   SYS_DIV8_CLK clock         */ 0U,
/*   RT_DAPB_CLK clock          */ 0U,
#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
/*   A53_CORE_CLK clock         */ 0U,
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV2_CLK)
/*   A53_CORE_DIV2_CLK clock    */ 0U,
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
/*   A53_CORE_DIV4_CLK clock   */ 0U,
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV10_CLK)
/*   A53_CORE_DIV10_CLK clock   */ 0U,
#endif
/*   ACCEL_CLK clock            */ 0U,
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
/*   ACCEL_DIV3_CLK clock       */ 0U,
#endif
#if defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
/*   ACCEL_DIV4_CLK clock       */ 0U,
#endif
/*   ACCEL_XBAR_CLK clock       */ 0U,
/*   ACCEL_XBAR_DIV2_CLK clock  */ 0U,
/*   ACCEL_XBAR_DIV4_CLK clock  */ 0U,
/*   ACCEL_XBAR_DIV8_CLK clock  */ 0U,
/*   AP_DAPB_CLK clock          */ 0U,
#if defined(CLOCK_IP_HAS_GMAC0_REF_CLK)
/*   GMAC0_REF_CLK clock        */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
/*   GMAC0_REF_DIV_CLK clock    */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
/*   GMAC1_REF_CLK clock        */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
/*   GMAC1_REF_DIV_CLK clock    */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
/*   GMAC1_INT_CLK clock        */ 0U,
#endif
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
/*   AURORA_TRACE_TEST_CLK      */ 0U,
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_DIFF_CLK)
/*   AURORAPLL_DIFF_CLK clock   */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
/*   GMAC_1_INT_REF_CLK clock   */ 0U,
#endif
/*   THE_LAST_PRODUCER_CLK      */ 0U,
/*   BBE32EP_DSP_CLK clock      */ 0U,
/*   CAN_CHI_CLK clock          */ 0U,
/*   CAN_TS_CLK clock           */ 0U,
/*   CAN_PE_CLK clock           */ 0U,
/*   CAN0_CLK clock             */ 0U,
/*   CAN1_CLK clock             */ 0U,
/*   CLKOUT0_CLK clock          */ 0U,
/*   CLKOUT1_CLK clock          */ 0U,
#if defined(CLOCK_IP_HAS_CORE_A53_CLUSTER_0_CLK)
/*   CORE_A53_CLUSTER_0_CLK     */ 0U,
#endif
#if defined(CLOCK_IP_HAS_CORE_A53_CLUSTER_1_CLK)
/*   CORE_A53_CLUSTER_1_CLK     */ 0U,
#endif
/*   CRC_CLK clock              */ 0U,
#if defined(CLOCK_IP_HAS_CSI_CLK)
/*   CSI_CLK clock              */ 0U,
#endif
#if defined(CLOCK_IP_HAS_CSI_CFG_CLK)
/*   CSI_CFG_CLK clock          */ 0U,
#endif
#if defined(CLOCK_IP_HAS_CTE_CLK)
/*   CTE_CLK clock              */ 0U,
#endif
#if defined(CLOCK_IP_HAS_CSI_IPS_CLK)
/*   CSI_IPS_CLK clock          */ 0U,
#endif
#if defined(CLOCK_IP_HAS_CSI_TXCLK_CLK)
/*   CSI_TXCLK_CLK clock        */ 0U,
#endif
/*   MC_CLK clock               */ 0U,
/*   CTU_CLK clock              */ 0U,
/*   CTU_IPS_CLK clock          */ 0U,
/*   DAPB_CLK clock             */ 0U,
/*   DMA_CLK clock              */ 0U,
/*   DMA_CRC_CLK clock          */ 0U,
/*   DMA_TCD_CLK clock          */ 0U,
/*   DMAMUX0_CLK clock          */ 0U,
/*   DMAMUX1_CLK clock          */ 0U,
/*   DSPI_SCK_TST_CLK clock     */ 0U,
/*   EIM_AP1_CLK clock          */ 0U,
/*   EIM_CM70_CLK clock         */ 0U,
#if defined(CLOCK_IP_HAS_EIM_CM71_CLK)
/*   EIM_CM71_CLK clock         */ 0U,
#endif
/*   EIM_DSP_CLK clock          */ 0U,
/*   EIM_RT0_CLK clock          */ 0U,
/*   EIM_RT2_CLK clock          */ 0U,
/*   ERM_AP1_CLK clock          */ 0U,
/*   ERM_RT0_CLK clock          */ 0U,
/*   ERM_RT1_CLK clock          */ 0U,
/*   ERM_RT2_CLK clock          */ 0U,
/*   FCCU_IPS_CLK clock         */ 0U,
/*   FTM0_CLK clock             */ 0U,
/*   FTM0_EXT_CLK clock         */ 0U,
/*   GMAC0_RX_CLK clock         */ 0U,
/*   GMAC0_TS_CLK clock         */ 0U,
/*   GMAC0_TX_CLK clock         */ 0U,
#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK)
/*   GMAC1_RX_CLK clock         */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK)
/*   GMAC1_TS_CLK clock         */ 0U,
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK)
/*   GMAC1_TX_CLK clock         */ 0U,
#endif
/*   IIC0_CLK clock             */ 0U,
/*   IIC1_CLK clock             */ 0U,
/*   LBIST_CLK clock            */ 0U,
/*   LBIST0_CLK clock           */ 0U,
/*   LBIST1_CLK clock           */ 0U,
/*   LBIST2_CLK clock           */ 0U,
/*   LBIST3_CLK clock           */ 0U,
/*   LBIST4_CLK clock           */ 0U,
/*   LBIST5_CLK clock           */ 0U,
/*   LBIST6_CLK clock           */ 0U,
/*   LBIST7_CLK clock           */ 0U,
/*   LIN_BAUD_CLK clock         */ 0U,
/*   LINFLEXD_CLK clock         */ 0U,
/*   LIN0_CLK clock             */ 0U,
#if defined(CLOCK_IP_HAS_LIN1_CLK)
/*   LIN1_CLK clock             */ 0U,
#endif
/*   SYS_M7_0_CLK clock         */ 0U,
#if defined(CLOCK_IP_HAS_SYS_M7_1_CLK)
/*   SYS_M7_1_CLK clock         */ 0U,
#endif
/*   SYS_HSE_SYS_CLK clock      */ 0U,
#if defined(CLOCK_IP_HAS_MIPICSI2_0_CLK)
/*   MIPICSI2_0_CLK clock       */ 0U,
#endif
#if defined(CLOCK_IP_HAS_MIPICSI2_1_CLK)
/*   MIPICSI2_1_CLK clock       */ 0U,
#endif
/*   MSCM_CLK clock             */ 0U,
/*   NOC_TRACE_CLK clock        */ 0U,
/*   OCOTP_CLK clock            */ 0U,
/*   PIT0_CLK clock             */ 0U,
/*   PIT2_CLK clock             */ 0U,
/*   QSPI_2X_CLK clock          */ 0U,
/*   QSPI_1X_CLK clock          */ 0U,
/*   QSPI0_CLK clock            */ 0U,
/*   SAR_ADC_CLK clock          */ 0U,
/*   SEMA42_1_CLK clock         */ 0U,
/*   SEMA42_CLK clock           */ 0U,
/*   SIUL2_CLK clock            */ 0U,
/*   SPI_CLK clock              */ 0U,
/*   SPI0_CLK clock             */ 0U,
/*   SPI1_CLK clock             */ 0U,
#if defined(CLOCK_IP_HAS_SPI2_CLK)
/*   SPI2_CLK clock             */ 0U,
#endif
#if defined(CLOCK_IP_HAS_SPI3_CLK)
/*   SPI3_CLK clock             */ 0U,
#endif
#if defined(CLOCK_IP_HAS_SPT_CLK)
/*   SPT_CLK clock              */ 0U,
#endif
/*   SRAM_CLK clock             */ 0U,
/*   STCU_CLK clock             */ 0U,
/*   STM0_CLK clock             */ 0U,
/*   STM1_CLK clock             */ 0U,
/*   STM2_CLK clock             */ 0U,
/*   SWT0_CLK clock             */ 0U,
#if defined(CLOCK_IP_HAS_SWT1_CLK)
/*   SWT1_CLK clock             */ 0U,
#endif
#if defined(CLOCK_IP_HAS_SWT2_CLK)
/*   SWT2_CLK clock             */ 0U,
#endif
#if defined(CLOCK_IP_HAS_SWT3_CLK)
/*   SWT3_CLK clock             */ 0U,
#endif
/*   TMU_CLK clock              */ 0U,
/*   TCLK_CLK clock             */ 0U,
#if defined(CLOCK_IP_HAS_WKPU_CLK)
/*   WKPU_CLK clock             */ 0U,
#endif
/*   XRDC0_CLK clock            */ 0U,
/*   XRDC1_CLK clock            */ 0U,
};


/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_8

#include "Mcu_MemMap.h"


/* Clock start constant section data */
#define MCU_START_SEC_CONST_16

#include "Mcu_MemMap.h"

/*!
 * @brief Converts a clock name to a selector entry hardware value
 */
const uint16 Clock_Ip_au16SelectorEntryHardwareValue[CLOCK_IP_PRODUCERS_NO] = {
    0U,                                       /*!< CLOCK_IS_OFF                            */
    0U,                                       /*!< FIRC_CLK                                */
    2U,                                       /*!< FXOSC_CLK                               */
#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
    0U,                                       /*!< AURORAPLL_CLK                           */
#endif
    0U,                                       /*!< COREPLL_CLK                             */
    0U,                                       /*!< PERIPHPLL_CLK                           */
    4U,                                       /*!< COREPLL_PHI0_CLK                        */
    5U,                                       /*!< COREPLL_PHI1_CLK                        */
    6U,                                       /*!< COREPLL_PHI2_CLK                        */
    7U,                                       /*!< COREPLL_PHI3_CLK                        */
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
    8U,                                       /*!< COREPLL_PHI4_CLK                        */
#endif
    9U,                                       /*!< COREPLL_PHI5_CLK                        */
    10U,                                      /*!< COREPLL_PHI6_CLK                        */
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
    11U,                                      /*!< COREPLL_PHI7_CLK                        */
#endif
    12U,                                      /*!< COREPLL_PHI8_CLK                        */
    13U,                                      /*!< COREPLL_PHI9_CLK                        */
    18U,                                      /*!< PERIPHPLL_PHI0_CLK                      */
    19U,                                      /*!< PERIPHPLL_PHI1_CLK                      */
    20U,                                      /*!< PERIPHPLL_PHI2_CLK                      */
    21U,                                      /*!< PERIPHPLL_PHI3_CLK                      */
    22U,                                      /*!< PERIPHPLL_PHI4_CLK                      */
    23U,                                      /*!< PERIPHPLL_PHI5_CLK                      */
    24U,                                      /*!< PERIPHPLL_PHI6_CLK                      */
    25U,                                      /*!< PERIPHPLL_PHI7_CLK                      */
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
    15U,                                      /*!< PERIPHPLL_PHI8_CLK                      */
#endif
    16U,                                      /*!< PERIPHPLL_PHI9_CLK                      */
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
    26U,                                      /*!< PERIPHPLL_DFS1_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
    27U,                                      /*!< PERIPHPLL_DFS2_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
    50U,                                      /*!< AURORAPLL_PHI0_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
    50U,                                      /*!< AURORAPLL_PHI1_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI2_CLK)
    0U,                                       /*!< AURORAPLL_PHI2_CLK                      */
#endif
    34U,                                      /*!< FTM_0_EXT_REF_CLK                       */
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
    39U,                                      /*!< GMAC_0_EXT_REF_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
    38U,                                      /*!< GMAC_0_EXT_RX_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
    37U,                                      /*!< GMAC_0_EXT_TX_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
    44U,                                      /*!< GMAC_0_EXT_TS_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
    61U,                                      /*!< GMAC_0_SGMII_REF_CLK                    */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
    60U,                                      /*!< GMAC_0_SGMII_RX_CLK                     */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
    59U,                                      /*!< GMAC_0_SGMII_TX_CLK                     */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
    58U,                                      /*!< GMAC_1_EXT_REF_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
    57U,                                      /*!< GMAC_1_EXT_RX_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
    56U,                                      /*!< GMAC_1_EXT_TX_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
    55U,                                      /*!< GMAC_1_EXT_TS_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
    0U,                                       /*!< FIRC_MUXED_CLK                          */
#endif
#if defined(CLOCK_IP_HAS_LVDS_CLK)
    0U,                                       /*!< LVDS_CLK                                */
#endif
#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
    0U,                                       /*!< RFE_PLL_CLK                             */
#endif
    0U,                                       /*!< SYS_CLK                                 */
    0U,                                       /*!< SYS_DIV2_CLK                            */
    0U,                                       /*!< SYS_DIV4_CLK                            */
    0U,                                       /*!< SYS_DIV8_CLK                            */
    0U,                                       /*!< RT_DAPB_CLK                             */
#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
    0U,                                       /*!< A53_CORE_CLK                            */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV2_CLK)
    0U,                                       /*!< A53_CORE_DIV2_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
    0U,                                       /*!< A53_CORE_DIV4_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV10_CLK)
    0U,                                       /*!< A53_CORE_DIV10_CLK                      */
#endif
    0U,                                       /*!< ACCEL_CLK                               */
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
    0U,                                       /*!< ACCEL_DIV3_CLK                          */
#endif
#if defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
    0U,                                       /*!< ACCEL_DIV4_CLK                          */
#endif
    0U,                                       /*!< ACCEL_XBAR_CLK                          */
    0U,                                       /*!< ACCEL_XBAR_DIV2_CLK                     */
    0U,                                       /*!< ACCEL_XBAR_DIV4_CLK                     */
    0U,                                       /*!< ACCEL_XBAR_DIV8_CLK                     */
    0U,                                       /*!< AP_DAPB_CLK                             */
#if defined(CLOCK_IP_HAS_GMAC0_REF_CLK)
    0U,                                       /*!< GMAC0_REF_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
    45U,                                      /*!< GMAC0_REF_DIV_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
    0U,                                       /*!< GMAC1_REF_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
    54U,                                      /*!< GMAC1_REF_DIV_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
    0U,                                       /*!< GMAC1_INT_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
    0U,                                       /*!< AURORA_TRACE_TEST_CLK                   */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_DIFF_CLK)
    0U,                                       /*!< AURORAPLL_DIFF_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
    53U,                                      /*!< GMAC_1_INT_REF_CLK                      */
#endif
};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_16

#include "Mcu_MemMap.h"


/* Clock start constant section data */
#define MCU_START_SEC_CONST_32

#include "Mcu_MemMap.h"

#if (defined(CLOCK_IP_DEV_ERROR_DETECT))
#if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
/* Clock name types */
const uint32 Clock_Ip_au8ClockNameTypes[CLOCK_IP_NAMES_NO] =
{
/*   CLOCK_IS_OFF clock         */ 0U,                                                                                                                                                                                                                                                                                       /*   CLOCK_IS_OFF               */
/*   FIRC_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   FIRC_CLK clock             */
/*   FXOSC_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   FXOSC_CLK clock            */
#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
/*   AURORAPLL_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   AURORAPLL_CLK clock        */
#endif
/*   COREPLL_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_CLK clock          */
/*   PERIPHPLL_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_CLK clock        */
/*   COREPLL_PHI0 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI0 clock         */
/*   COREPLL_PHI1 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI1 clock         */
/*   COREPLL_PHI2 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI2 clock         */
/*   COREPLL_PHI3 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI3 clock         */
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
/*   COREPLL_PHI4 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI4 clock         */
#endif
/*   COREPLL_PHI5 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI5 clock         */
/*   COREPLL_PHI6 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI6 clock         */
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
/*   COREPLL_PHI7 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI7 clock         */
#endif
/*   COREPLL_PHI8 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI8 clock         */
/*   COREPLL_PHI9 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   COREPLL_PHI9 clock         */
/*   PERIPHPLL_PHI0 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI0 clock       */
/*   PERIPHPLL_PHI1 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI1 clock       */
/*   PERIPHPLL_PHI2 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI2 clock       */
/*   PERIPHPLL_PHI3 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI3 clock       */
/*   PERIPHPLL_PHI4 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI4 clock       */
/*   PERIPHPLL_PHI5 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI5 clock       */
/*   PERIPHPLL_PHI6 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI6 clock       */
/*   PERIPHPLL_PHI7 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI7 clock       */
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
/*   PERIPHPLL_PHI8 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI8 clock       */
#endif
/*   PERIPHPLL_PHI9 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_PHI9 clock       */
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
/*   AURORAPLL_PHI0 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   AURORAPLL_PHI0 clock       */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
/*   AURORAPLL_PHI1 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   AURORAPLL_PHI1 clock       */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI2_CLK)
/*   AURORAPLL_PHI2 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   AURORAPLL_PHI2 clock       */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
/*   PERIPHPLL_DFS1 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_DFS1 clock       */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
/*   PERIPHPLL_DFS2 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PERIPHPLL_DFS2 clock       */
#endif
/*   ftm_0_ext_ref clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ftm_0_ext_ref clock        */
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
/*   gmac_0_ext_ref clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_0_ext_ref clock       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
/*   gmac_0_ext_rx clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_0_ext_rx clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
/*   gmac_0_ext_tx clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_0_ext_tx clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
/*   gmac_0_ext_ts clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_0_ext_ts clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
/*   gmac_0_sgmii_ref clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_0_sgmii_ref clock     */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
/*   gmac_0_sgmii_rx clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_0_sgmii_rx clock      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
/*   gmac_0_sgmii_tx clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_0_sgmii_tx clock      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
/*   gmac_1_ext_ref clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_1_ext_ref clock       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
/*   gmac_1_ext_rx clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_1_ext_rx clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
/*   gmac_1_ext_tx clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_1_ext_tx clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
/*   gmac_1_ext_ts clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   gmac_1_ext_ts clock        */
#endif
#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
/*   firc_muxed_clk clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   firc_muxed_clk clock       */
#endif
#if defined(CLOCK_IP_HAS_LVDS_CLK)
/*   lvds clock                 */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   lvds clock                 */
#endif
#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
/*   rfe_pll_clk clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   rfe_pll_clk clock          */
#endif
/*   SYS_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SYS_CLK clock              */
/*   SYS_DIV2_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SYS_DIV2_CLK clock         */
/*   SYS_DIV4_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SYS_DIV4_CLK clock         */
/*   SYS_DIV8_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SYS_DIV8_CLK clock         */
/*   RT_DAPB_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   RT_DAPB_CLK clock          */
#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
/*   A53_CORE_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   A53_CORE_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV2_CLK)
/*   A53_CORE_DIV2_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   A53_CORE_DIV2_CLK clock    */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
/*   A53_CORE_DIV4_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   A53_CORE_DIV4_CLK clock    */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV10_CLK)
/*   A53_CORE_DIV10_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   A53_CORE_DIV10_CLK clock   */
#endif
/*   ACCEL_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ACCEL_CLK clock            */
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
/*   ACCEL_DIV3_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ACCEL_DIV3_CLK clock       */
#endif
#if defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
/*   ACCEL_DIV4_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ACCEL_DIV4_CLK clock       */
#endif
/*   ACCEL_XBAR_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ACCEL_XBAR_CLK clock       */
/*   ACCEL_XBAR_DIV2_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ACCEL_XBAR_DIV2_CLK clock  */
/*   ACCEL_XBAR_DIV4_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ACCEL_XBAR_DIV4_CLK clock  */
/*   ACCEL_XBAR_DIV8_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ACCEL_XBAR_DIV8_CLK clock  */
/*   AP_DAPB_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   AP_DAPB_CLK clock          */
#if defined(CLOCK_IP_HAS_GMAC0_REF_CLK)
/*   GMAC0_REF_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC0_REF_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
/*   GMAC0_REF_DIV_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC0_REF_DIV_CLK clock    */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
/*   GMAC1_REF_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC1_REF_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
/*   GMAC1_REF_DIV_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC1_REF_DIV_CLK clock    */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
/*   GMAC1_INT_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC1_INT_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
/*   AURORA_TRACE_TEST_CLK clock*/ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   AURORA_TRACE_TEST_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_DIFF_CLK)
/*   AURORAPLL_DIFF_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   AURORAPLL_DIFF_CLK clock   */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
/*   GMAC_1_INT_REF_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC_1_INT_REF_CLK clock        */
#endif
/*   THE_LAST_PRODUCER_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   THE_LAST_PRODUCER_CLK      */
/*   BBE32EP_DSP_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   BBE32EP_DSP_CLK clock      */
/*   CAN_CHI_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CAN_CHI_CLK clock          */
/*   CAN_TS_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CAN_TS_CLK clock           */
/*   CAN_PE_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CAN_PE_CLK clock           */
/*   CAN0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CAN0_CLK clock             */
/*   CAN1_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CAN1_CLK clock             */
/*   CLKOUT0_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CLKOUT0_CLK clock          */
/*   CLKOUT1_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CLKOUT1_CLK clock          */
#if defined(CLOCK_IP_HAS_CORE_A53_CLUSTER_0_CLK)
/*   CORE_A53_CLUSTER_0_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CORE_A53_CLUSTER_0_CLK     */
#endif
#if defined(CLOCK_IP_HAS_CORE_A53_CLUSTER_1_CLK)
/*   CORE_A53_CLUSTER_1_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CORE_A53_CLUSTER_1_CLK     */
#endif
/*   CRC_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CRC_CLK clock              */
#if defined(CLOCK_IP_HAS_CSI_CLK)
/*   CSI_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CSI_CLK clock              */
#endif
#if defined(CLOCK_IP_HAS_CSI_CFG_CLK)
/*   CSI_CFG_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CSI_CFG_CLK clock          */
#endif
#if defined(CLOCK_IP_HAS_CTE_CLK)
/*   CTE_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CTE_CLK clock              */
#endif
#if defined(CLOCK_IP_HAS_CSI_IPS_CLK)
/*   CSI_IPS_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CSI_IPS_CLK clock          */
#endif
#if defined(CLOCK_IP_HAS_CSI_TXCLK_CLK)
/*   CSI_TXCLK_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CSI_TXCLK_CLK clock        */
#endif
/*   MC_CLK clock               */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   MC_CLK clock               */
/*   CTU_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CTU_CLK clock              */
/*   CTU_IPS_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   CTU_IPS_CLK clock          */
/*   DAPB_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   DAPB_CLK clock             */
/*   DMA_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   DMA_CLK clock              */
/*   DMA_CRC_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   DMA_CRC_CLK clock          */
/*   DMA_TCD_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   DMA_TCD_CLK clock          */
/*   DMAMUX0_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   DMAMUX0_CLK clock          */
/*   DMAMUX1_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   DMAMUX1_CLK clock          */
/*   DSPI_SCK_TST_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   DSPI_SCK_TST_CLK clock     */
/*   EIM_AP1_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   EIM_AP1_CLK clock          */
/*   EIM_CM70_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   EIM_CM70_CLK clock         */
#if defined(CLOCK_IP_HAS_EIM_CM71_CLK)
/*   EIM_CM71_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   EIM_CM71_CLK clock         */
#endif
/*   EIM_DSP_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   EIM_DSP_CLK clock          */
/*   EIM_RT0_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   EIM_RT0_CLK clock          */
/*   EIM_RT2_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   EIM_RT2_CLK clock          */
/*   ERM_AP1_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ERM_AP1_CLK clock          */
/*   ERM_RT0_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ERM_RT0_CLK clock          */
/*   ERM_RT1_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ERM_RT1_CLK clock          */
/*   ERM_RT2_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   ERM_RT2_CLK clock          */
/*   FCCU_IPS_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   FCCU_IPS_CLK clock         */
/*   FTM0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   FTM0_CLK clock             */
/*   FTM0_EXT_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   FTM0_EXT_CLK clock         */
/*   GMAC0_RX_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC0_RX_CLK clock         */
/*   GMAC0_TS_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC0_TS_CLK clock         */
/*   GMAC0_TX_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC0_TX_CLK clock         */
#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK)
/*   GMAC1_RX_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC1_RX_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK)
/*   GMAC1_TS_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC1_TS_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK)
/*   GMAC1_TX_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   GMAC1_TX_CLK clock         */
#endif
/*   IIC0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   IIC0_CLK clock             */
/*   IIC1_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   IIC1_CLK clock             */
/*   LBIST_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LBIST_CLK clock            */
/*   LBIST0_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LBIST0_CLK clock           */
/*   LBIST1_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LBIST1_CLK clock           */
/*   LBIST2_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LBIST2_CLK clock           */
/*   LBIST3_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LBIST3_CLK clock           */
/*   LBIST4_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LBIST4_CLK clock           */
/*   LBIST5_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LBIST5_CLK clock           */
/*   LBIST6_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LBIST6_CLK clock           */
/*   LBIST7_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LBIST7_CLK clock           */
/*   LIN_BAUD_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LIN_BAUD_CLK clock         */
/*   LINFLEXD_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LINFLEXD_CLK clock         */
/*   LIN0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LIN0_CLK clock             */
#if defined(CLOCK_IP_HAS_LIN1_CLK)
/*   LIN1_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   LIN1_CLK clock             */
#endif
/*   SYS_M7_0_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SYS_M7_0_CLK clock         */
#if defined(CLOCK_IP_HAS_SYS_M7_1_CLK)
/*   SYS_M7_1_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SYS_M7_1_CLK clock         */
#endif
/*   SYS_HSE_SYS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SYS_HSE_SYS_CLK clock      */
#if defined(CLOCK_IP_HAS_MIPICSI2_0_CLK)
/*   MIPICSI2_0_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   MIPICSI2_0_CLK clock       */
#endif
#if defined(CLOCK_IP_HAS_MIPICSI2_1_CLK)
/*   MIPICSI2_1_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   MIPICSI2_1_CLK clock       */
#endif
/*   MSCM_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   MSCM_CLK clock             */
/*   NOC_TRACE_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   NOC_TRACE_CLK clock        */
/*   OCOTP_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   OCOTP_CLK clock            */
/*   PIT0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PIT0_CLK clock             */
/*   PIT2_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   PIT2_CLK clock             */
/*   QSPI_2X_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   QSPI_2X_CLK clock          */
/*   QSPI_1X_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   QSPI_1X_CLK clock          */
/*   QSPI0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   QSPI0_CLK clock            */
/*   SAR_ADC_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SAR_ADC_CLK clock          */
/*   SEMA42_1_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SEMA42_1_CLK clock         */
/*   SEMA42_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SEMA42_CLK clock           */
/*   SIUL2_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SIUL2_CLK clock            */
/*   SPI_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SPI_CLK clock              */
/*   SPI0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SPI0_CLK clock             */
/*   SPI1_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SPI1_CLK clock             */
#if defined(CLOCK_IP_HAS_SPI2_CLK)
/*   SPI2_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SPI2_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_SPI3_CLK)
/*   SPI3_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SPI3_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_SPT_CLK)
/*   SPT_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SPT_CLK clock              */
#endif
/*   SRAM_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SRAM_CLK clock             */
/*   STCU_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   STCU_CLK clock             */
/*   STM0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   STM0_CLK clock             */
/*   STM1_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   STM1_CLK clock             */
/*   STM2_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   STM2_CLK clock             */
/*   SWT0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SWT0_CLK clock             */
#if defined(CLOCK_IP_HAS_SWT1_CLK)
/*   SWT1_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SWT1_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_SWT2_CLK)
/*   SWT2_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SWT2_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_SWT3_CLK)
/*   SWT3_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   SWT3_CLK clock             */
#endif
/*   TMU_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   TMU_CLK clock              */
/*   TCLK_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   TCLK_CLK clock             */
#if defined(CLOCK_IP_HAS_WKPU_CLK)
/*   WKPU_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   WKPU_CLK clock             */
#endif
/*   XRDC0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   XRDC0_CLK clock            */
/*   XRDC1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   XRDC1_CLK clock            */
};
#endif
#endif /* CLOCK_IP_DEV_ERROR_DETECT */

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"


/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

Clock_Ip_CgmMuxType* const Clock_Ip_apxCgm[CLOCK_IP_MC_CGM_INSTANCES_COUNT][CLOCK_IP_MC_CGM_MUXS_COUNT] =
{
    /* CGM_0 */
    {
     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_0->MUX_0_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_0->MUX_1_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_0->MUX_2_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_0->MUX_3_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_0->MUX_4_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_0->MUX_5_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_0->MUX_6_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_0->MUX_7_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_0->MUX_8_CSC) ),
    },

    /* CGM_1 */
    {
     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_1->MUX_0_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_1->MUX_1_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_1->MUX_2_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_1->MUX_3_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_1->MUX_4_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_1->MUX_5_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_1->MUX_6_CSC) ),

     NULL_PTR,

     NULL_PTR,
    },

    /* CGM_2 */
    {
     NULL_PTR,
#ifdef IP_MC_CGM_2
     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_2->MUX_1_CSC) ),
#else
     NULL_PTR,
#endif

#ifdef IP_MC_CGM_2
     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_2->MUX_2_CSC) ),
#else
     NULL_PTR,
#endif

#ifdef IP_MC_CGM_2
     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_2->MUX_3_CSC) ),
#else
     NULL_PTR,
#endif

#ifdef IP_MC_CGM_2
     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_2->MUX_4_CSC) ),
#else
     NULL_PTR,
#endif

     NULL_PTR,

     NULL_PTR,

     NULL_PTR,

     NULL_PTR,
    },

    /* CGM_3 */
    {
     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_3->MUX_0_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_3->MUX_1_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_3->MUX_2_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_3->MUX_3_CSC) ),

     (Clock_Ip_CgmMuxType*)( &(IP_MC_CGM_3->MUX_4_CSC) ),

     NULL_PTR,

     NULL_PTR,

     NULL_PTR,

     NULL_PTR,
    },
};


volatile Clock_Ip_CgmPcfsType* const Clock_Ip_apxCgmPcfs[CLOCK_IP_MC_CGM_INSTANCES_COUNT] =
{
    NULL_PTR,(volatile Clock_Ip_CgmPcfsType*)(&IP_MC_CGM_1->PCFS_SDUR),NULL_PTR,NULL_PTR
};


Clock_Ip_ExtOSCType* const Clock_Ip_apxXosc[CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE] =
{
    (Clock_Ip_ExtOSCType*)IP_FXOSC,
};

#ifdef IP_PERIPH_DFS
DFS_Type* const Clock_Ip_apxDfs[CLOCK_IP_DFS_INSTANCES_ARRAY_SIZE] = {IP_PERIPH_DFS};
#endif

Clock_Ip_PllType const Clock_Ip_apxPll[CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE] = {
    {
        (PLLDIG_Type*)IP_CORE_PLL,
        CLOCK_IP_COREPLL_DIVIDER_COUNT,
    },
    {
        (PLLDIG_Type*)IP_PERIPH_PLL,
        CLOCK_IP_PERIPHPLL_DIVIDER_COUNT,
    }
};

Clock_Ip_ClockMonitorType* const Clock_Ip_apxCmu[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE] =
{
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_0,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_1,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_3,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_5,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_6,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_7,
#ifdef IP_CMU_FC_8
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_8,
#else
     NULL_PTR,
#endif
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_10,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_11,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_12,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_13,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_14,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_15,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_16,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_17,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_21,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_22,
#ifdef IP_CMU_FC_23
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_23,
#else
     NULL_PTR,
#endif
#ifdef IP_CMU_FC_24
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_24,
#else
     NULL_PTR,
#endif
#ifdef IP_CMU_FC_25
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_25,
#else
     NULL_PTR,
#endif
#ifdef IP_CMU_FC_26
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_26,
#else
     NULL_PTR,
#endif
#ifdef IP_CMU_FC_27
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_27,
#else
     NULL_PTR,
#endif
#ifdef IP_CMU_FC_28
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_28,
#else
     NULL_PTR,
#endif
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_29,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_30,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_31,
};

Clock_Ip_NameType const Clock_Ip_aeCmuNames[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE] =
{
    FXOSC_CLK,
    FIRC_CLK,
    FTM0_EXT_CLK,
    STCU_CLK,
    SYS_M7_0_CLK,
    SYS_DIV8_CLK,
#if defined(CLOCK_IP_HAS_SYS_M7_1_CLK)
    SYS_M7_1_CLK,
#else
    RESERVED_CLK,
#endif
    MC_CLK,
    CLKOUT0_CLK,
    FCCU_IPS_CLK,
    CAN_PE_CLK,
    GMAC0_TX_CLK,
    GMAC0_TS_CLK,
    LINFLEXD_CLK,
    QSPI_1X_CLK,
    GMAC0_RX_CLK,
    SPI_CLK,
#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK)
    GMAC1_TX_CLK,
#else
    RESERVED_CLK,
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK)
    GMAC1_TS_CLK,
#else
    RESERVED_CLK,
#endif
#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK)
    GMAC1_RX_CLK,
#else
    RESERVED_CLK,
#endif
#if defined(CLOCK_IP_HAS_CTE_CLK)
    CTE_CLK,
#else
    RESERVED_CLK,
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
    A53_CORE_CLK,
#else
    RESERVED_CLK,
#endif
#if defined(CLOCK_IP_HAS_CSI_CFG_CLK)
    CSI_CFG_CLK,
#else
    RESERVED_CLK,
#endif
    ACCEL_XBAR_DIV4_CLK,
    ACCEL_XBAR_DIV8_CLK,
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
    ACCEL_DIV3_CLK,
#elif defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
    ACCEL_DIV4_CLK,
#endif
};

Clock_Ip_CmuInfoType const Clock_Ip_axCmuInfo[CLOCK_IP_CMU_INFO_SIZE] =  {

/* CLOCK_IP_CMU_FC_0_INSTANCE */
{
    FXOSC_CLK,                                       /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_0,         /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_1_INSTANCE */
{
    FIRC_CLK,                                        /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_1,         /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_3_INSTANCE */
{
    FTM0_EXT_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_3,         /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_5_INSTANCE */
{
    STCU_CLK,                                        /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_5,         /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_6_INSTANCE */
{
    SYS_M7_0_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_6,         /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_7_INSTANCE */
{
    SYS_DIV8_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_7,         /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_8_INSTANCE */
#if defined(CLOCK_IP_HAS_SYS_M7_1_CLK) && defined(IP_CMU_FC_8)
{
    SYS_M7_1_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_8,         /* Cmu instance */
},
#else
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
#endif
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_10_INSTANCE */
{
    MC_CLK,                                          /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_10,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_11_INSTANCE */
{
    CLKOUT0_CLK,                                     /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_11,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_12_INSTANCE */
{
    FCCU_IPS_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_12,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_13_INSTANCE */
{
    CAN_PE_CLK,                                      /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_13,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_14_INSTANCE */
{
    GMAC0_TX_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_14,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_15_INSTANCE */
{
    GMAC0_TS_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_15,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_16_INSTANCE */
{
    LINFLEXD_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_16,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_17_INSTANCE */
{
    QSPI_1X_CLK,                                     /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_17,        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_21_INSTANCE */
{
    GMAC0_RX_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_21,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_22_INSTANCE */
{
    SPI_CLK,                                         /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_22,        /* Cmu instance */
},
#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK) && defined(IP_CMU_FC_23)
/* CLOCK_IP_CMU_FC_23_INSTANCE */
{
    GMAC1_TX_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_23,        /* Cmu instance */
},
#else
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK) && defined(IP_CMU_FC_24)
/* CLOCK_IP_CMU_FC_24_INSTANCE */
{
    GMAC1_TS_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_24,        /* Cmu instance */
},
#else
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
#endif
#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK) && defined(IP_CMU_FC_25)
/* CLOCK_IP_CMU_FC_25_INSTANCE */
{
    GMAC1_RX_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_25,        /* Cmu instance */
},
#else
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
#endif
#if defined(IP_CMU_FC_26)
/* CLOCK_IP_CMU_FC_26_INSTANCE */
{
    CTE_CLK,                                         /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_26,        /* Cmu instance */
},
#else
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
#endif
#if defined(IP_CMU_FC_27)
/* CLOCK_IP_CMU_FC_27_INSTANCE */
{
    A53_CORE_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_27,        /* Cmu instance */
},
#else
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
#endif
#if defined(CLOCK_IP_HAS_CSI_CFG_CLK) && defined(IP_CMU_FC_28)
/* CLOCK_IP_CMU_FC_28_INSTANCE */
{
    CSI_CFG_CLK,                                     /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_28,        /* Cmu instance */
},
#else
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
#endif
/* CLOCK_IP_CMU_FC_29_INSTANCE */
{
    ACCEL_XBAR_DIV4_CLK,                             /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_29,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_30_INSTANCE */
{
    ACCEL_XBAR_DIV8_CLK,                             /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_30,        /* Cmu instance */
},
/* CLOCK_IP_CMU_FC_31_INSTANCE */
{
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
    ACCEL_DIV3_CLK,                                  /* Name of the clock that supports cmu (clock monitor) */
#elif defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
    ACCEL_DIV4_CLK,                                  /* Name of the clock that supports cmu (clock monitor) */
#endif
    FXOSC_CLK,                                       /* Name of the reference clock */
    SYS_DIV8_CLK,                                    /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_31,        /* Cmu instance */
},
};

volatile Clock_Ip_McmePartitionSetType* const Clock_Ip_apxMcMeSetPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT] =
{
     (volatile Clock_Ip_McmePartitionSetType*)(PRTN0_COFB0_CLKEN_ADDRESS),

     (volatile Clock_Ip_McmePartitionSetType*)( ((volatile uint8*)&(IP_MC_ME->PRTN1_COFB0_CLKEN)) ),
};

volatile const Clock_Ip_McmePartitionGetType* const Clock_Ip_apxMcMeGetPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT] =
{
     (volatile const Clock_Ip_McmePartitionGetType*)(PRTN0_COFB0_STAT_ADDRESS),

     (volatile const Clock_Ip_McmePartitionGetType*)( ((volatile const uint8*)&(IP_MC_ME->PRTN1_COFB0_STAT)) ),
};

volatile Clock_Ip_McmePartitionTriggerType* const Clock_Ip_apxMcMeTriggerPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT] =
{
     (volatile Clock_Ip_McmePartitionTriggerType*)( ((volatile uint8*)&(IP_MC_ME->PRTN0_PCONF)) ),

     (volatile Clock_Ip_McmePartitionTriggerType*)( ((volatile uint8*)&(IP_MC_ME->PRTN1_PCONF)) ),
};

const Clock_Ip_ClockNameSourceType Clock_Ip_aeSourceTypeClockName[CLOCK_IP_PRODUCERS_NO] = {
    UKNOWN_TYPE,                               /*!< CLOCK_IS_OFF                            */
    IRCOSC_TYPE,                               /*!< FIRC_CLK                                */
    XOSC_TYPE,                                 /*!< FXOSC_CLK                               */
#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
    PLL_TYPE,                                  /*!< AURORAPLL_CLK                           */
#endif
    PLL_TYPE,                                  /*!< COREPLL_CLK                             */
    PLL_TYPE,                                  /*!< PERIPHPLL_CLK                           */
    PLL_TYPE,                                  /*!< COREPLL_PHI0_CLK                        */
    PLL_TYPE,                                  /*!< COREPLL_PHI1_CLK                        */
    PLL_TYPE,                                  /*!< COREPLL_PHI2_CLK                        */
    PLL_TYPE,                                  /*!< COREPLL_PHI3_CLK                        */
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
    PLL_TYPE,                                  /*!< COREPLL_PHI4_CLK                        */
#endif
    PLL_TYPE,                                  /*!< COREPLL_PHI5_CLK                        */
    PLL_TYPE,                                  /*!< COREPLL_PHI6_CLK                        */
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
    PLL_TYPE,                                  /*!< COREPLL_PHI7_CLK                        */
#endif
    PLL_TYPE,                                  /*!< COREPLL_PHI8_CLK                        */
    PLL_TYPE,                                  /*!< COREPLL_PHI9_CLK                        */
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI0_CLK                      */
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI1_CLK                      */
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI2_CLK                      */
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI3_CLK                      */
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI4_CLK                      */
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI5_CLK                      */
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI6_CLK                      */
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI7_CLK                      */
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI8_CLK                      */
#endif
    PLL_TYPE,                                  /*!< PERIPHPLL_PHI9_CLK                      */
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
    PLL_TYPE,                                  /*!< AURORAPLL_PHI0_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
    PLL_TYPE,                                  /*!< AURORAPLL_PHI1_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI2_CLK)
    PLL_TYPE,                                  /*!< AURORAPLL_PHI2_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
    PLL_TYPE,                                  /*!< PERIPHPLL_DFS1_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
    PLL_TYPE,                                  /*!< PERIPHPLL_DFS2_CLK                      */
#endif
    EXT_CLK_TYPE,                              /*!< FTM_0_EXT_REF_CLK                       */
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_0_EXT_REF_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_0_EXT_RX_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_0_EXT_TX_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_0_EXT_TS_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_0_SGMII_REF_CLK                    */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_0_SGMII_RX_CLK                     */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_0_SGMII_TX_CLK                     */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_1_EXT_REF_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_1_EXT_RX_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_1_EXT_TX_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
    EXT_CLK_TYPE,                              /*!< GMAC_1_EXT_TS_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
    EXT_CLK_TYPE,                              /*!< FIRC_MUXED_CLK                          */
#endif
#if defined(CLOCK_IP_HAS_LVDS_CLK)
    EXT_CLK_TYPE,                              /*!< LVDS_CLK                                */
#endif
#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
    EXT_CLK_TYPE,                              /*!< RFE_PLL_CLK                             */
#endif
    UKNOWN_TYPE,                               /*!< SYS_CLK                                 */
    UKNOWN_TYPE,                               /*!< SYS_DIV2_CLK                            */
    UKNOWN_TYPE,                               /*!< SYS_DIV4_CLK                            */
    UKNOWN_TYPE,                               /*!< SYS_DIV8_CLK                            */
    UKNOWN_TYPE,                               /*!< RT_DAPB_CLK                             */
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
    UKNOWN_TYPE,                               /*!< A53_CORE_CLK                            */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
    UKNOWN_TYPE,                               /*!< A53_CORE_DIV2_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
    UKNOWN_TYPE,                               /*!< A53_CORE_DIV4_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV10_CLK)
    UKNOWN_TYPE,                               /*!< A53_CORE_DIV10_CLK                      */
#endif
    UKNOWN_TYPE,                               /*!< ACCEL_CLK                               */
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
    UKNOWN_TYPE,                               /*!< ACCEL_DIV3_CLK                          */
#endif
#if defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
    UKNOWN_TYPE,                               /*!< ACCEL_DIV4_CLK                          */
#endif
    UKNOWN_TYPE,                               /*!< ACCEL_XBAR_CLK                          */
    UKNOWN_TYPE,                               /*!< ACCEL_XBAR_DIV2_CLK                     */
    UKNOWN_TYPE,                               /*!< ACCEL_XBAR_DIV4_CLK                     */
    UKNOWN_TYPE,                               /*!< ACCEL_XBAR_DIV8_CLK                     */
    UKNOWN_TYPE,                               /*!< AP_DAPB_CLK                             */
#if defined(CLOCK_IP_HAS_GMAC0_REF_CLK)
    UKNOWN_TYPE,                               /*!< GMAC0_REF_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
    UKNOWN_TYPE,                               /*!< GMAC0_REF_DIV_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
    UKNOWN_TYPE,                               /*!< GMAC1_REF_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
    UKNOWN_TYPE,                               /*!< GMAC1_REF_DIV_CLK                       */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
    UKNOWN_TYPE,                               /*!< GMAC1_INT_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
    UKNOWN_TYPE,                               /*!< AURORA_TRACE_TEST_CLK                   */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_DIFF_CLK)
    UKNOWN_TYPE,                               /*!< AURORAPLL_DIFF_CLK                      */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
    UKNOWN_TYPE,                               /*!< GMAC_1_INT_REF_CLK                      */
#endif
};

const Clock_Ip_NameType Clock_Ip_aeHwPllName[CLOCK_IP_HARDWARE_PLL_ARRAY_SIZE] =
{
#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
    AURORAPLL_CLK,                  /* AURORAPLL_CLK Clock */
#endif
    COREPLL_CLK,                    /* COREPLL_CLK Clock */
    PERIPHPLL_CLK,                  /* PERIPHPLL_CLK Clock */
};

const Clock_Ip_NameType Clock_Ip_aeHwDfsName[CLOCK_IP_HARDWARE_DFS_ARRAY_SIZE] =
{
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
    PERIPHPLL_DFS1_CLK,            /* PERIPHPLL_DFS1_CLK Clock */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
    PERIPHPLL_DFS2_CLK,            /* PERIPHPLL_DFS2_CLK Clock */
#endif
#if !defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK) && !defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
    RESERVED_CLK,              /* RESERVED_CLK Clock */
#endif
};



const Clock_Ip_ClockExtensionType Clock_Ip_axFeatureExtensions[CLOCK_IP_EXTENSIONS_SIZE] = {
    /* Partition value index           Selector value index               Request value shift                Request value mask  */
    {MC_CGM_0_MUX_0_CSC_SELCTL_MASK,   MC_CGM_0_MUX_0_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_SYS_EXTENSION */
#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
    {MC_CGM_MUX_0_CSC_SELCTL_MASK,     MC_CGM_MUX_0_CSC_SELCTL_SHIFT,     0U,                                0U},                               /* CLOCK_IP_A53_CORE_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
    {MC_CGM_MUX_1_CSC_SELCTL_MASK,     MC_CGM_MUX_1_CSC_SELCTL_SHIFT,     MC_CGM_MUX_1_DC_0_DIV_MASK,        MC_CGM_MUX_1_DC_0_DIV_SHIFT},      /* CLOCK_IP_ACCEL_EXTENSION */
    {MC_CGM_MUX_2_CSC_SELCTL_MASK,     MC_CGM_MUX_2_CSC_SELCTL_SHIFT,     0U,                                0U},                               /* CLOCK_IP_ACCEL_XBAR_EXTENSION */
#if defined(CLOCK_IP_HAS_GMAC0_REF_CLK)
    {MC_CGM_MUX_3_CSC_SELCTL_MASK,     MC_CGM_MUX_3_CSC_SELCTL_SHIFT,     0U,                                0U},                               /* CLOCK_IP_GMAC0_REF_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
    {MC_CGM_MUX_3_CSC_SELCTL_MASK,     MC_CGM_MUX_3_CSC_SELCTL_SHIFT,     MC_CGM_MUX_3_DC_0_DIV_MASK,        MC_CGM_MUX_3_DC_0_DIV_SHIFT},      /* CLOCK_IP_GMAC0_REF_DIV_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
    {MC_CGM_2_MUX_3_CSC_SELCTL_MASK,   MC_CGM_2_MUX_3_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_GMAC1_REF_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
    {MC_CGM_2_MUX_3_CSC_SELCTL_MASK,   MC_CGM_2_MUX_3_CSC_SELCTL_SHIFT,   MC_CGM_2_MUX_3_DC_0_DIV_MASK,      MC_CGM_2_MUX_3_DC_0_DIV_SHIFT},    /* CLOCK_IP_GMAC1_REF_DIV_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
    {MC_CGM_0_MUX_6_CSC_SELCTL_MASK,   MC_CGM_0_MUX_6_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_GMAC1_INT_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
    {MC_CGM_0_MUX_6_CSC_SELCTL_MASK,   MC_CGM_0_MUX_6_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_AURORA_TRACE_TEST_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
    {MC_CGM_0_MUX_7_CSC_SELCTL_MASK,   MC_CGM_0_MUX_7_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_CAN_PE_EXTENSION */
    {MC_CGM_0_MUX_1_CSC_SELCTL_MASK,   MC_CGM_0_MUX_1_CSC_SELCTL_SHIFT,   MC_CGM_0_MUX_1_DC_0_DIV_MASK,      MC_CGM_0_MUX_1_DC_0_DIV_SHIFT},    /* CLOCK_IP_CLKOUT0_EXTENSION */
    {MC_CGM_0_MUX_2_CSC_SELCTL_MASK,   MC_CGM_0_MUX_2_CSC_SELCTL_SHIFT,   MC_CGM_0_MUX_2_DC_0_DIV_MASK,      MC_CGM_0_MUX_2_DC_0_DIV_SHIFT},    /* CLOCK_IP_CLKOUT1_EXTENSION */
#if defined(CLOCK_IP_HAS_CSI_CLK)
    {MC_CGM_MUX_4_CSC_SELCTL_MASK,     MC_CGM_MUX_4_CSC_SELCTL_SHIFT,     0U,                                0U},                               /* CLOCK_IP_CSI_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
#if defined(CLOCK_IP_HAS_CSI_CFG_CLK)
    {MC_CGM_MUX_4_CSC_SELCTL_MASK,     MC_CGM_MUX_4_CSC_SELCTL_SHIFT,     MC_CGM_MUX_4_DC_0_DIV_MASK,        MC_CGM_MUX_4_DC_0_DIV_SHIFT},      /* CLOCK_IP_CSI_CFG_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
    {MC_CGM_MUX_3_CSC_SELCTL_MASK,     MC_CGM_MUX_3_CSC_SELCTL_SHIFT,     0U,                                0U},                               /* CLOCK_IP_CTE_EXTENSION */
#if defined(CLOCK_IP_HAS_CSI_TXCLK_CLK)
    {MC_CGM_MUX_4_CSC_SELCTL_MASK,     MC_CGM_MUX_4_CSC_SELCTL_SHIFT,     MC_CGM_MUX_4_DC_1_DIV_MASK,        MC_CGM_MUX_4_DC_1_DIV_SHIFT},      /* CLOCK_IP_CSI_TXCLK_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
    {MC_CGM_0_MUX_3_CSC_SELCTL_MASK,   MC_CGM_0_MUX_3_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_MC_EXTENSION */
    {MC_CGM_MUX_0_CSC_SELCTL_MASK,     MC_CGM_MUX_0_CSC_SELCTL_SHIFT,     MC_CGM_MUX_0_DC_0_DIV_MASK,        MC_CGM_MUX_0_DC_0_DIV_SHIFT},      /* CLOCK_IP_FTM0_EXT_EXTENSION */
    {MC_CGM_MUX_4_CSC_SELCTL_MASK,     MC_CGM_MUX_4_CSC_SELCTL_SHIFT,     0U,                                0U},                               /* CLOCK_IP_GMAC0_RX_EXTENSION */
    {MC_CGM_MUX_1_CSC_SELCTL_MASK,     MC_CGM_MUX_1_CSC_SELCTL_SHIFT,     MC_CGM_MUX_1_DC_0_DIV_MASK,        MC_CGM_MUX_1_DC_0_DIV_SHIFT},      /* CLOCK_IP_GMAC0_TS_EXTENSION */
    {MC_CGM_0_MUX_2_CSC_SELCTL_MASK,   MC_CGM_0_MUX_2_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_GMAC0_TX_EXTENSION */
#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK)
    {MC_CGM_2_MUX_4_CSC_SELCTL_MASK,   MC_CGM_2_MUX_4_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_GMAC1_RX_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK)
    {MC_CGM_MUX_1_CSC_SELCTL_MASK,     MC_CGM_MUX_1_CSC_SELCTL_SHIFT,     MC_CGM_MUX_1_DC_0_DIV_MASK,        MC_CGM_MUX_1_DC_0_DIV_SHIFT},      /* CLOCK_IP_GMAC1_TS_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK)
    {MC_CGM_2_MUX_2_CSC_SELCTL_MASK,   MC_CGM_2_MUX_2_CSC_SELCTL_SHIFT,   MC_CGM_2_MUX_2_DC_0_DIV_MASK,      MC_CGM_2_MUX_2_DC_0_DIV_SHIFT},    /* CLOCK_IP_GMAC1_TX_EXTENSION */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
    {MC_CGM_MUX_6_CSC_SELCTL_MASK,     MC_CGM_MUX_6_CSC_SELCTL_SHIFT,     MC_CGM_MUX_6_DC_0_DIV_MASK,        MC_CGM_MUX_6_DC_0_DIV_SHIFT},      /* CLOCK_IP_LBIST_EXTENSION */
    {MC_CGM_0_MUX_8_CSC_SELCTL_MASK,   MC_CGM_0_MUX_8_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_LIN_BAUD_EXTENSION */
    {MC_CGM_MUX_5_CSC_SELCTL_MASK,     MC_CGM_MUX_5_CSC_SELCTL_SHIFT,     0U,                                0U},                               /* CLOCK_IP_NOC_TRACE_EXTENSION */
    {MC_CGM_0_MUX_5_CSC_SELCTL_MASK,   MC_CGM_0_MUX_5_CSC_SELCTL_SHIFT,   MC_CGM_0_MUX_5_DC_0_DIV_MASK,      MC_CGM_0_MUX_5_DC_0_DIV_SHIFT},    /* CLOCK_IP_QSPI_2X_EXTENSION */
    {MC_CGM_0_MUX_4_CSC_SELCTL_MASK,   MC_CGM_0_MUX_4_CSC_SELCTL_SHIFT,   0U,                                0U},                               /* CLOCK_IP_SPI_EXTENSION */
    {MC_CGM_0_MUX_6_CSC_SELCTL_MASK,   MC_CGM_0_MUX_6_CSC_SELCTL_SHIFT,   MC_CGM_0_MUX_6_DC_0_DIV_MASK,      MC_CGM_0_MUX_6_DC_0_DIV_SHIFT},    /* CLOCK_IP_CAN_TS_EXTENSION */
    {MC_CGM_0_MUX_6_CSC_SELCTL_MASK,   MC_CGM_0_MUX_6_CSC_SELCTL_SHIFT,   MC_CGM_0_MUX_6_DC_1_DIV_MASK,      MC_CGM_0_MUX_6_DC_1_DIV_SHIFT},    /* CLOCK_IP_CAN_CHI_EXTENSION */
    {MC_CGM_0_MUX_6_CSC_SELCTL_MASK,   MC_CGM_0_MUX_6_CSC_SELCTL_SHIFT,   MC_CGM_0_MUX_6_DC_2_DIV_MASK,      MC_CGM_0_MUX_6_DC_2_DIV_SHIFT},    /* CLOCK_IP_TCLK_EXTENSION */
    {MC_CGM_0_MUX_6_CSC_SELCTL_MASK,   MC_CGM_0_MUX_6_CSC_SELCTL_SHIFT,   MC_CGM_0_MUX_6_DC_3_DIV_MASK,      MC_CGM_0_MUX_6_DC_3_DIV_SHIFT},    /* CLOCK_IP_DSPI_SCK_TST_EXTENSION */
    {MC_CGM_0_MUX_6_CSC_SELCTL_MASK,   MC_CGM_0_MUX_6_CSC_SELCTL_SHIFT,   MC_CGM_0_MUX_6_DC_4_DIV_MASK,      MC_CGM_0_MUX_6_DC_4_DIV_SHIFT},    /* CLOCK_IP_STCU_EXTENSION */
};


Clock_Ip_GateInfoType const Clock_Ip_axGateInfo[CLOCK_IP_GATE_INFO_SIZE] =  {
    /* Partition value index                   Collection value index             Request value shift                  Request value mask  */
    {CLOCK_IP_PARTITION_1_INDEX,               CLOCK_IP_COLLECTION_0_INDEX,       MC_ME_PRTN1_COFB0_CLKEN_REQ0_SHIFT,  MC_ME_PRTN1_COFB0_CLKEN_REQ0_MASK},     /*   BBE32EP_DSP_CLK clock */
#if defined(CLOCK_IP_HAS_SPT_CLK)
    {CLOCK_IP_PARTITION_1_INDEX,               CLOCK_IP_COLLECTION_0_INDEX,       MC_ME_PRTN1_COFB0_CLKEN_REQ1_SHIFT,  MC_ME_PRTN1_COFB0_CLKEN_REQ1_MASK},     /*   SPT_CLK clock */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
#if defined(CLOCK_IP_HAS_MIPICSI2_0_CLK) || defined(CLOCK_IP_HAS_MIPICSI2_1_CLK)
    {CLOCK_IP_PARTITION_1_INDEX,               CLOCK_IP_COLLECTION_0_INDEX,       MC_ME_PRTN1_COFB0_CLKEN_REQ2_SHIFT,  MC_ME_PRTN1_COFB0_CLKEN_REQ2_MASK},     /*   MIPICSI2_X_CLK clock */
#else
    {0U,                               0U,                                0U,                                0U},
#endif
};

#ifdef IP_ATP
Clock_Ip_ATPType* const Clock_Ip_apxAurora = (Clock_Ip_ATPType*)IP_ATP;
#endif
#ifdef IP_ATP_PLL
Clock_Ip_ATPType* const Clock_Ip_apxAurora = (Clock_Ip_ATPType*)IP_ATP_PLL;
#endif



/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

