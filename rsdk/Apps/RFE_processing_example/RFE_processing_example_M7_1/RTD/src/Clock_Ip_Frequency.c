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
*   @file       Clock_Ip_Frequency.c
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

#if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON))


/*==================================================================================================
*                                     SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_FREQUENCY_VENDOR_ID_C                      43
#define CLOCK_IP_FREQUENCY_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_FREQUENCY_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_FREQUENCY_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_FREQUENCY_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_FREQUENCY_SW_MINOR_VERSION_C               0
#define CLOCK_IP_FREQUENCY_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Frequency.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_FREQUENCY_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Frequency.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Frequency.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_FREQUENCY_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Frequency.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Frequency.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_FREQUENCY_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Frequency.c and Clock_Ip_Private.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef struct{

    Clock_Ip_NameType Name;
    uint32 Frequency;

}extSignalFreq;

typedef uint32 (*getFreqType)(void);

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define CLOCK_IP_SELECTOR_SOURCE_NO  64U
#define CLOCK_IP_EXT_SIGNALS_NO      15U
#define CLOCK_IP_DFS_MASK_0_CHANNEL  1U
#define CLOCK_IP_DFS_MASK_1_CHANNEL  2U
#define CLOCK_IP_DFS_MASK_2_CHANNEL  4U
#define CLOCK_IP_DFS_MASK_3_CHANNEL  8U
#define CLOCK_IP_DFS_MASK_4_CHANNEL  16U
#define CLOCK_IP_DFS_MASK_5_CHANNEL  32U

#define CLOCK_IP_MUL_BY_16384        14U
#define CLOCK_IP_MUL_BY_2048         11U
#define CLOCK_IP_MUL_BY_32           5U
#define CLOCK_IP_MUL_BY_16           4U
#define CLOCK_IP_MUL_BY_4            2U
#define CLOCK_IP_MUL_BY_2            1U
#define CLOCK_IP_DISABLED            0U
#define CLOCK_IP_ENABLED             0xFFFFFFFFU

#define CLOCK_IP_FTM_0_EXT_REF_CLK_INDEX_ENTRY          0U
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
#define CLOCK_IP_GMAC_0_EXT_REF_CLK_INDEX_ENTRY         1U
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
#define CLOCK_IP_GMAC_0_EXT_RX_CLK_INDEX_ENTRY          2U
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
#define CLOCK_IP_GMAC_0_EXT_TX_CLK_INDEX_ENTRY          3U
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
#define CLOCK_IP_GMAC_0_EXT_TS_CLK_INDEX_ENTRY          4U
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
#define CLOCK_IP_GMAC_1_EXT_REF_CLK_INDEX_ENTRY         5U
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
#define CLOCK_IP_GMAC_1_EXT_RX_CLK_INDEX_ENTRY          6U
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
#define CLOCK_IP_GMAC_1_EXT_TX_CLK_INDEX_ENTRY          7U
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
#define CLOCK_IP_GMAC_1_EXT_TS_CLK_INDEX_ENTRY          8U
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
#define CLOCK_IP_GMAC_0_SGMII_REF_CLK_INDEX_ENTRY       9U
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
#define CLOCK_IP_GMAC_0_SGMII_RX_CLK_INDEX_ENTRY        10U
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
#define CLOCK_IP_GMAC_0_SGMII_TX_CLK_INDEX_ENTRY        11U
#endif
#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
#define CLOCK_IP_FIRC_MUXED_CLK_INDEX_ENTRY             12U
#endif
#if defined(CLOCK_IP_HAS_LVDS_CLK)
#define CLOCK_IP_LVDS_CLK_INDEX_ENTRY                   13U
#endif
#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
#define CLOCK_IP_RFE_PLL_CLK_INDEX_ENTRY                14U
#endif

#define CLOCK_IP_COREPLL_FREQ                        2000000000U
#define CLOCK_IP_COREPLL_CHECKSUM                    4147U
#define CLOCK_IP_PERIPHPLL_FREQ                      2000000000U
#define CLOCK_IP_PERIPHPLL_CHECKSUM                  4147U
#define CLOCK_IP_COREPLL_PHI0_FREQ                   800000000U
#define CLOCK_IP_COREPLL_PHI0_CHECKSUM               5694U
#define CLOCK_IP_COREPLL_PHI1_FREQ                   800000000U
#define CLOCK_IP_COREPLL_PHI1_CHECKSUM               5694U
#define CLOCK_IP_COREPLL_PHI2_FREQ                   800000000U
#define CLOCK_IP_COREPLL_PHI2_CHECKSUM               5694U
#define CLOCK_IP_COREPLL_PHI3_FREQ                   0U
#define CLOCK_IP_COREPLL_PHI3_CHECKSUM               5943U
#define CLOCK_IP_COREPLL_PHI4_FREQ                   0U
#define CLOCK_IP_COREPLL_PHI4_CHECKSUM               5943U
#define CLOCK_IP_COREPLL_PHI5_FREQ                   0U
#define CLOCK_IP_COREPLL_PHI5_CHECKSUM               5943U
#define CLOCK_IP_COREPLL_PHI6_FREQ                   0U
#define CLOCK_IP_COREPLL_PHI6_CHECKSUM               5943U
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
#define CLOCK_IP_COREPLL_PHI7_FREQ                   0U
#define CLOCK_IP_COREPLL_PHI7_CHECKSUM               5943U
#endif
#define CLOCK_IP_COREPLL_PHI8_FREQ                   0U
#define CLOCK_IP_COREPLL_PHI8_CHECKSUM               5943U
#define CLOCK_IP_COREPLL_PHI9_FREQ                   0U
#define CLOCK_IP_COREPLL_PHI9_CHECKSUM               5943U
#define CLOCK_IP_PERIPHPLL_PHI0_FREQ                 800000000U
#define CLOCK_IP_PERIPHPLL_PHI0_CHECKSUM             5694U
#define CLOCK_IP_PERIPHPLL_PHI1_FREQ                 800000000U
#define CLOCK_IP_PERIPHPLL_PHI1_CHECKSUM             5694U
#define CLOCK_IP_PERIPHPLL_PHI2_FREQ                 800000000U
#define CLOCK_IP_PERIPHPLL_PHI2_CHECKSUM             5694U
#define CLOCK_IP_PERIPHPLL_PHI3_FREQ                 0U
#define CLOCK_IP_PERIPHPLL_PHI3_CHECKSUM             5943U
#define CLOCK_IP_PERIPHPLL_PHI4_FREQ                 0U
#define CLOCK_IP_PERIPHPLL_PHI4_CHECKSUM             5943U
#define CLOCK_IP_PERIPHPLL_PHI5_FREQ                 0U
#define CLOCK_IP_PERIPHPLL_PHI5_CHECKSUM             5943U
#define CLOCK_IP_PERIPHPLL_PHI6_FREQ                 0U
#define CLOCK_IP_PERIPHPLL_PHI6_CHECKSUM             5943U
#define CLOCK_IP_PERIPHPLL_PHI7_FREQ                 0U
#define CLOCK_IP_PERIPHPLL_PHI7_CHECKSUM             5943U
#define CLOCK_IP_PERIPHPLL_PHI8_FREQ                 0U
#define CLOCK_IP_PERIPHPLL_PHI8_CHECKSUM             5943U
#define CLOCK_IP_PERIPHPLL_PHI9_FREQ                 0U
#define CLOCK_IP_PERIPHPLL_PHI9_CHECKSUM             5943U
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
#define CLOCK_IP_PERIPHDFS1_FREQ                     800000000U
#define CLOCK_IP_PERIPHDFS1_CHECKSUM                 5694U
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
#define CLOCK_IP_PERIPHDFS2_FREQ                     631578947U
#define CLOCK_IP_PERIPHDFS2_CHECKSUM                 5666U
#endif

#ifdef PLLDIG_PLLCLKMUX_REFCLKSEL_MASK
#define CORE_PLL_CHECKSUM() (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD)
#define PERIPH_PLL_CHECKSUM() (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV)
#else
#define CORE_PLL_CHECKSUM() (IP_CORE_PLL->CLKMUX)
#define PERIPH_PLL_CHECKSUM() (IP_PERIPH_PLL->CLKMUX)
#endif

#if defined(IP_ATP_PLL)
#define ATP_PLLSR_LOCK_MASK                          ATP_PLL_PLLSR_LOCK_MASK
#define ATP_PLLSR_LOCK_SHIFT                         ATP_PLL_PLLSR_LOCK_SHIFT
#define ATP_PLLCR_PLLPD_MASK                         ATP_PLL_PLLCR_PLLPD_MASK
#define ATP_PLLCR_PLLPD_SHIFT                        ATP_PLL_PLLCR_PLLPD_SHIFT
#define ATP_PLLODIV_0_DE_MASK                        ATP_PLL_PLLODIV_0_DE_MASK
#define ATP_PLLODIV_0_DE_SHIFT                       ATP_PLL_PLLODIV_0_DE_SHIFT
#define ATP_FCW_NDIV_PDIV_CONFIG_PDIV_MASK           ATP_PLL_FCW_NDIV_PDIV_CONFIG_PDIV_MASK
#define ATP_FCW_NDIV_PDIV_CONFIG_PDIV_SHIFT          ATP_PLL_FCW_NDIV_PDIV_CONFIG_PDIV_SHIFT
#define ATP_PLLODIV_0_DIV_MASK                       ATP_PLL_PLLODIV_0_DIV_MASK
#define ATP_PLLODIV_0_DIV_SHIFT                      ATP_PLL_PLLODIV_0_DIV_SHIFT
#define ATP_PLLODIV_2_DE_MASK                        ATP_PLL_PLLODIV_2_DE_MASK
#define ATP_PLLODIV_2_DE_SHIFT                       ATP_PLL_PLLODIV_2_DE_SHIFT
#define ATP_PLLODIV_2_DIV_MASK                       ATP_PLL_PLLODIV_2_DIV_MASK
#define ATP_PLLODIV_2_DIV_SHIFT                      ATP_PLL_PLLODIV_2_DIV_SHIFT
#define ATP_FCW_NDIV_PDIV_CONFIG_NDIV_MASK           ATP_PLL_FCW_NDIV_PDIV_CONFIG_NDIV_MASK
#define ATP_FCW_NDIV_PDIV_CONFIG_NDIV_SHIFT          ATP_PLL_FCW_NDIV_PDIV_CONFIG_NDIV_SHIFT
#define ATP_FCW_NDIV_PDIV_CONFIG_FCW_MASK            ATP_PLL_FCW_NDIV_PDIV_CONFIG_FCW_MASK
#define ATP_FCW_NDIV_PDIV_CONFIG_FCW_SHIFT           ATP_PLL_FCW_NDIV_PDIV_CONFIG_FCW_SHIFT
#define ATP_CLKMUX_RCLKSEL_MASK                      ATP_PLL_CLKMUX_RCLKSEL_MASK
#define ATP_CLKMUX_RCLKSEL_SHIFT                     ATP_PLL_CLKMUX_RCLKSEL_SHIFT
#define ATP_ENABLE_CLOCKS_DIRECTO_MASK               ATP_PLL_ENABLE_CLOCKS_DIRECTO_MASK
#endif

/*==================================================================================================
*                                    GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static uint32 Clock_Ip_Get_Zero_Frequency(void);
static uint32 Clock_Ip_Get_FIRC_CLK_Frequency(void);
static uint32 Clock_Ip_Get_FXOSC_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
static uint32 Clock_Ip_Get_AURORAPLL_CLK_Frequency(void);
#endif
static uint32 Clock_Ip_Get_COREPLL_CLK_Frequency(void);
static uint32 Clock_Ip_Get_PERIPHPLL_CLK_Frequency(void);
static uint32 Clock_Ip_Get_COREPLL_PHI0_Frequency(void);
static uint32 Clock_Ip_Get_COREPLL_PHI1_Frequency(void);
static uint32 Clock_Ip_Get_COREPLL_PHI2_Frequency(void);
static uint32 Clock_Ip_Get_COREPLL_PHI3_Frequency(void);
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
static uint32 Clock_Ip_Get_COREPLL_PHI4_Frequency(void);
#endif
static uint32 Clock_Ip_Get_COREPLL_PHI5_Frequency(void);
static uint32 Clock_Ip_Get_COREPLL_PHI6_Frequency(void);
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
static uint32 Clock_Ip_Get_COREPLL_PHI7_Frequency(void);
#endif
static uint32 Clock_Ip_Get_COREPLL_PHI8_Frequency(void);
static uint32 Clock_Ip_Get_COREPLL_PHI9_Frequency(void);
static uint32 Clock_Ip_Get_PERIPHPLL_PHI0_Frequency(void);
static uint32 Clock_Ip_Get_PERIPHPLL_PHI1_Frequency(void);
static uint32 Clock_Ip_Get_PERIPHPLL_PHI2_Frequency(void);
static uint32 Clock_Ip_Get_PERIPHPLL_PHI3_Frequency(void);
static uint32 Clock_Ip_Get_PERIPHPLL_PHI4_Frequency(void);
static uint32 Clock_Ip_Get_PERIPHPLL_PHI5_Frequency(void);
static uint32 Clock_Ip_Get_PERIPHPLL_PHI6_Frequency(void);
static uint32 Clock_Ip_Get_PERIPHPLL_PHI7_Frequency(void);
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
static uint32 Clock_Ip_Get_PERIPHPLL_PHI8_Frequency(void);
#endif
static uint32 Clock_Ip_Get_PERIPHPLL_PHI9_Frequency(void);
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
static uint32 Clock_Ip_Get_AURORAPLL_PHI0_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
static uint32 Clock_Ip_Get_AURORAPLL_PHI1_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI2_CLK)
static uint32 Clock_Ip_Get_AURORAPLL_PHI2_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
static uint32 Clock_Ip_Get_PERIPHPLL_DFS1_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
static uint32 Clock_Ip_Get_PERIPHPLL_DFS2_Frequency(void);
#endif
static uint32 Clock_Ip_Get_ftm_0_ext_ref_Frequency(void);
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
static uint32 Clock_Ip_Get_gmac_0_ext_ref_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
static uint32 Clock_Ip_Get_gmac_0_ext_rx_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
static uint32 Clock_Ip_Get_gmac_0_ext_tx_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
static uint32 Clock_Ip_Get_gmac_0_ext_ts_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
static uint32 Clock_Ip_Get_gmac_0_sgmii_ref_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
static uint32 Clock_Ip_Get_gmac_0_sgmii_rx_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
static uint32 Clock_Ip_Get_gmac_0_sgmii_tx_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
static uint32 Clock_Ip_Get_gmac_1_ext_ref_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
static uint32 Clock_Ip_Get_gmac_1_ext_rx_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
static uint32 Clock_Ip_Get_gmac_1_ext_tx_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
static uint32 Clock_Ip_Get_gmac_1_ext_ts_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
static uint32 Clock_Ip_Get_firc_muxed_clk_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_LVDS_CLK)
static uint32 Clock_Ip_Get_lvds_clk_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
static uint32 Clock_Ip_Get_rfe_pll_clk_Frequency(void);
#endif
static uint32 Clock_Ip_Get_SYS_CLK_Frequency(void);
static uint32 Clock_Ip_Get_SYS_DIV2_CLK_Frequency(void);
static uint32 Clock_Ip_Get_SYS_DIV4_CLK_Frequency(void);
static uint32 Clock_Ip_Get_SYS_DIV8_CLK_Frequency(void);
static uint32 Clock_Ip_Get_SYS_DIV8_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
static uint32 Clock_Ip_Get_A53_CORE_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV2_CLK)
static uint32 Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
static uint32 Clock_Ip_Get_A53_CORE_DIV4_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV10_CLK)
static uint32 Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency(void);
#endif
static uint32 Clock_Ip_Get_ACCEL_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
static uint32 Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
static uint32 Clock_Ip_Get_ACCEL_DIV4_CLK_Frequency(void);
#endif
static uint32 Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency(void);
static uint32 Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency(void);
static uint32 Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency(void);
static uint32 Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency(void);
static uint32 Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_GMAC0_REF_CLK)
static uint32 Clock_Ip_Get_GMAC0_REF_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
static uint32 Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
static uint32 Clock_Ip_Get_GMAC1_REF_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
static uint32 Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
static uint32 Clock_Ip_Get_AURORA_TRACE_TEST_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_DIFF_CLK)
static uint32 Clock_Ip_Get_AURORAPLL_DIFF_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
static uint32 Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
static uint32 Clock_Ip_Get_GMAC1_INT_CLK_Frequency(void);
#endif
static uint32 Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency(void);
static uint32 Clock_Ip_Get_CAN_CHI_CLK_Frequency(void);
static uint32 Clock_Ip_Get_CAN_PE_CLK_Frequency(void);
static uint32 Clock_Ip_Get_CAN_TS_CLK_Frequency(void);
static uint32 Clock_Ip_Get_CLKOUT0_CLK_Frequency(void);
static uint32 Clock_Ip_Get_CLKOUT1_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_CSI_CLK)
static uint32 Clock_Ip_Get_CSI_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_CSI_CFG_CLK)
static uint32 Clock_Ip_Get_CSI_CFG_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_CSI_TXCLK_CLK)
static uint32 Clock_Ip_Get_CSI_TXCLK_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_CTE_CLK)
static uint32 Clock_Ip_Get_CTE_CLK_Frequency(void);
#endif
static uint32 Clock_Ip_Get_CTU_IPS_CLK_Frequency(void);
static uint32 Clock_Ip_Get_DAPB_CLK_Frequency(void);
static uint32 Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency(void);
static uint32 Clock_Ip_Get_FCCU_IPS_CLK_Frequency(void);
static uint32 Clock_Ip_Get_FTM0_EXT_CLK_Frequency(void);
static uint32 Clock_Ip_Get_GMAC0_RX_CLK_Frequency(void);
static uint32 Clock_Ip_Get_GMAC0_TS_CLK_Frequency(void);
static uint32 Clock_Ip_Get_GMAC0_TX_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK)
static uint32 Clock_Ip_Get_GMAC1_RX_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK)
static uint32 Clock_Ip_Get_GMAC1_TS_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK)
static uint32 Clock_Ip_Get_GMAC1_TX_CLK_Frequency(void);
#endif
static uint32 Clock_Ip_Get_LBIST_CLK_Frequency(void);
static uint32 Clock_Ip_Get_LIN_BAUD_CLK_Frequency(void);
static uint32 Clock_Ip_Get_LINFLEXD_CLK_Frequency(void);
static uint32 Clock_Ip_Get_MC_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_MIPICSI2_0_CLK)
static uint32 Clock_Ip_Get_MIPICSI2_0_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_MIPICSI2_1_CLK)
static uint32 Clock_Ip_Get_MIPICSI2_1_CLK_Frequency(void);
#endif
static uint32 Clock_Ip_Get_NOC_TRACE_CLK_Frequency(void);
static uint32 Clock_Ip_Get_QSPI_2X_CLK_Frequency(void);
static uint32 Clock_Ip_Get_QSPI_1X_CLK_Frequency(void);
static uint32 Clock_Ip_Get_QSPI0_CLK_Frequency(void);
static uint32 Clock_Ip_Get_SPI_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_SPT_CLK)
static uint32 Clock_Ip_Get_SPT_CLK_Frequency(void);
#endif
static uint32 Clock_Ip_Get_STCU_CLK_Frequency(void);
static uint32 Clock_Ip_Get_SYS_CLK_Frequency(void);
static uint32 Clock_Ip_Get_TMU_CLK_Frequency(void);
static uint32 Clock_Ip_Get_TCLK_CLK_Frequency(void);

static uint32 Clock_Ip_PLL_VCO(const PLLDIG_Type *Base);
#if (defined(IP_ATP) || defined(IP_ATP_PLL))
static uint32 Clock_Ip_PLL_DCO(void);
#endif
#ifdef IP_PERIPH_DFS
static uint32 Clock_Ip_DFS_OUTPUT(const DFS_Type *Base, uint32 Channel, uint32 Fin);
#endif


/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

static const uint32 Clock_Ip_u32EnableDivider[2U] = {CLOCK_IP_DISABLED,CLOCK_IP_ENABLED};
static const uint32 Clock_Ip_u32EnableGate[2U] = {CLOCK_IP_DISABLED,CLOCK_IP_ENABLED};

#if (defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK) || defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK) || defined(CLOCK_IP_HAS_GMAC1_INT_CLK))
static const getFreqType Clock_Ip_apfTableClockGeneration[CLOCK_IP_SELECTOR_SOURCE_NO] =
{
    &Clock_Ip_Get_FIRC_CLK_Frequency,              /* clock name for 0  hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 1  hardware value */
    &Clock_Ip_Get_FXOSC_CLK_Frequency,             /* clock name for 2  hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 3  hardware value */
    &Clock_Ip_Get_COREPLL_PHI0_Frequency,          /* clock name for 4  hardware value */
    &Clock_Ip_Get_COREPLL_PHI1_Frequency,          /* clock name for 5  hardware value */
    &Clock_Ip_Get_COREPLL_PHI2_Frequency,          /* clock name for 6  hardware value */
    &Clock_Ip_Get_COREPLL_PHI3_Frequency,          /* clock name for 7  hardware value */
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
    &Clock_Ip_Get_COREPLL_PHI4_Frequency,          /* clock name for 8  hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 8  hardware value */
#endif
    &Clock_Ip_Get_COREPLL_PHI5_Frequency,          /* clock name for 9  hardware value */
    &Clock_Ip_Get_COREPLL_PHI6_Frequency,          /* clock name for 10 hardware value */
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
    &Clock_Ip_Get_COREPLL_PHI7_Frequency,          /* clock name for 11 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 11 hardware value */
#endif
    &Clock_Ip_Get_COREPLL_PHI8_Frequency,          /* clock name for 12 hardware value */
    &Clock_Ip_Get_COREPLL_PHI9_Frequency,          /* clock name for 13 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 14 hardware value */
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
    &Clock_Ip_Get_PERIPHPLL_PHI8_Frequency,        /* clock name for 15 hardware value */
#endif
    &Clock_Ip_Get_PERIPHPLL_PHI9_Frequency,        /* clock name for 16 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 17 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI0_Frequency,        /* clock name for 18 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI1_Frequency,        /* clock name for 19 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI2_Frequency,        /* clock name for 20 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI3_Frequency,        /* clock name for 21 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI4_Frequency,        /* clock name for 22 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI5_Frequency,        /* clock name for 23 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI6_Frequency,        /* clock name for 24 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI7_Frequency,        /* clock name for 25 hardware value */
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
    &Clock_Ip_Get_PERIPHPLL_DFS1_Frequency,        /* clock name for 26 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 26 hardware value */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
    &Clock_Ip_Get_PERIPHPLL_DFS2_Frequency,        /* clock name for 27 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 27 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 28 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 29 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 30 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 31 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 32 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 33 hardware value */
    &Clock_Ip_Get_ftm_0_ext_ref_Frequency,         /* clock name for 34 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 35 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 36 hardware value */
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
    &Clock_Ip_Get_gmac_0_ext_tx_Frequency,         /* clock name for 37 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 37 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
    &Clock_Ip_Get_gmac_0_ext_rx_Frequency,         /* clock name for 38 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 38 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
    &Clock_Ip_Get_gmac_0_ext_ref_Frequency,        /* clock name for 39 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 39 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 40 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 41 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 42 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 43 hardware value */
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
    &Clock_Ip_Get_gmac_0_ext_ts_Frequency,         /* clock name for 44 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 44 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 45 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 46 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 47 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 48 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 49 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 50 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 51 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 52 hardware value */
#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
    &Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency,    /* clock name for 53 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 53 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 54 hardware value */
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
    &Clock_Ip_Get_gmac_1_ext_ts_Frequency,         /* clock name for 55 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 55 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
    &Clock_Ip_Get_gmac_1_ext_tx_Frequency,         /* clock name for 56 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 56 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
    &Clock_Ip_Get_gmac_1_ext_rx_Frequency,         /* clock name for 57 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 57 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
    &Clock_Ip_Get_gmac_1_ext_ref_Frequency,        /* clock name for 58 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 58 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
    &Clock_Ip_Get_gmac_0_sgmii_tx_Frequency,       /* clock name for 59 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 58 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
    &Clock_Ip_Get_gmac_0_sgmii_rx_Frequency,       /* clock name for 60 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 58 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
    &Clock_Ip_Get_gmac_0_sgmii_ref_Frequency,      /* clock name for 61 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 61 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 62 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 63 hardware value */
};
#endif

static const getFreqType Clock_Ip_apfFreqTableClkSrc[CLOCK_IP_SELECTOR_SOURCE_NO] =
{
    &Clock_Ip_Get_FIRC_CLK_Frequency,              /* clock name for 0  hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 1  hardware value */
    &Clock_Ip_Get_FXOSC_CLK_Frequency,             /* clock name for 2  hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 3  hardware value */
    &Clock_Ip_Get_COREPLL_PHI0_Frequency,          /* clock name for 4  hardware value */
    &Clock_Ip_Get_COREPLL_PHI1_Frequency,          /* clock name for 5  hardware value */
    &Clock_Ip_Get_COREPLL_PHI2_Frequency,          /* clock name for 6  hardware value */
    &Clock_Ip_Get_COREPLL_PHI3_Frequency,          /* clock name for 7  hardware value */
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
    &Clock_Ip_Get_COREPLL_PHI4_Frequency,          /* clock name for 8  hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 8  hardware value */
#endif
    &Clock_Ip_Get_COREPLL_PHI5_Frequency,          /* clock name for 9  hardware value */
    &Clock_Ip_Get_COREPLL_PHI6_Frequency,          /* clock name for 10 hardware value */
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
    &Clock_Ip_Get_COREPLL_PHI7_Frequency,          /* clock name for 11 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 11 hardware value */
#endif
    &Clock_Ip_Get_COREPLL_PHI8_Frequency,          /* clock name for 12 hardware value */
    &Clock_Ip_Get_COREPLL_PHI9_Frequency,          /* clock name for 13 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 14 hardware value */
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
    &Clock_Ip_Get_PERIPHPLL_PHI8_Frequency,        /* clock name for 15 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 15 hardware value */
#endif
    &Clock_Ip_Get_PERIPHPLL_PHI9_Frequency,        /* clock name for 16 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 17 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI0_Frequency,        /* clock name for 18 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI1_Frequency,        /* clock name for 19 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI2_Frequency,        /* clock name for 20 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI3_Frequency,        /* clock name for 21 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI4_Frequency,        /* clock name for 22 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI5_Frequency,        /* clock name for 23 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI6_Frequency,        /* clock name for 24 hardware value */
    &Clock_Ip_Get_PERIPHPLL_PHI7_Frequency,        /* clock name for 25 hardware value */
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
    &Clock_Ip_Get_PERIPHPLL_DFS1_Frequency,        /* clock name for 26 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 26 hardware value */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
    &Clock_Ip_Get_PERIPHPLL_DFS2_Frequency,        /* clock name for 27 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 27 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 28 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 29 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 30 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 31 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 32 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 33 hardware value */
    &Clock_Ip_Get_ftm_0_ext_ref_Frequency,         /* clock name for 34 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 35 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 36 hardware value */
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
    &Clock_Ip_Get_gmac_0_ext_tx_Frequency,         /* clock name for 37 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 37 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
    &Clock_Ip_Get_gmac_0_ext_rx_Frequency,         /* clock name for 38 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 38 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
    &Clock_Ip_Get_gmac_0_ext_ref_Frequency,        /* clock name for 39 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 39 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 40 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 41 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 42 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 43 hardware value */
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
    &Clock_Ip_Get_gmac_0_ext_ts_Frequency,         /* clock name for 44 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 44 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
    &Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency,    /* clock name for 45 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 45 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 46 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 47 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 48 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 49 hardware value */
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
    &Clock_Ip_Get_AURORAPLL_PHI1_Frequency,        /* clock name for 50 hardware value */
#elif defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
    &Clock_Ip_Get_AURORAPLL_PHI0_Frequency,        /* clock name for 50 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 50 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 51 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 52 hardware value */
#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
    &Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency,    /* clock name for 53 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 53 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
    &Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency,     /* clock name for 54 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 54 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
    &Clock_Ip_Get_gmac_1_ext_ts_Frequency,         /* clock name for 55 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 55 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
    &Clock_Ip_Get_gmac_1_ext_tx_Frequency,         /* clock name for 56 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 56 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
    &Clock_Ip_Get_gmac_1_ext_rx_Frequency,         /* clock name for 57 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 57 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
    &Clock_Ip_Get_gmac_1_ext_ref_Frequency,        /* clock name for 58 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 58 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
    &Clock_Ip_Get_gmac_0_sgmii_tx_Frequency,       /* clock name for 59 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 58 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
    &Clock_Ip_Get_gmac_0_sgmii_rx_Frequency,       /* clock name for 60 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 58 hardware value */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
    &Clock_Ip_Get_gmac_0_sgmii_ref_Frequency,      /* clock name for 61 hardware value */
#else
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 61 hardware value */
#endif
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 62 hardware value */
    &Clock_Ip_Get_Zero_Frequency,                  /* clock name for 63 hardware value */
};

static const getFreqType Clock_Ip_apfFreqTable[CLOCK_IP_NAMES_NO] =
{
    &Clock_Ip_Get_Zero_Frequency,                                    /* CLOCK_IS_OFF                        */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                /* FIRC_CLK clock                      */
    &Clock_Ip_Get_FXOSC_CLK_Frequency,                               /* FXOSC_CLK clock                     */
#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
    &Clock_Ip_Get_AURORAPLL_CLK_Frequency,                           /* AURORAPLL_CLK clock                 */
#endif
    &Clock_Ip_Get_COREPLL_CLK_Frequency,                             /* COREPLL_CLK clock                   */
    &Clock_Ip_Get_PERIPHPLL_CLK_Frequency,                           /* PERIPHPLL_CLK clock                 */
    &Clock_Ip_Get_COREPLL_PHI0_Frequency,                            /* COREPLL_PHI0 clock                  */
    &Clock_Ip_Get_COREPLL_PHI1_Frequency,                            /* COREPLL_PHI1 clock                  */
    &Clock_Ip_Get_COREPLL_PHI2_Frequency,                            /* COREPLL_PHI2 clock                  */
    &Clock_Ip_Get_COREPLL_PHI3_Frequency,                            /* COREPLL_PHI3 clock                  */
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
    &Clock_Ip_Get_COREPLL_PHI4_Frequency,                            /* COREPLL_PHI4 clock                  */
#endif
    &Clock_Ip_Get_COREPLL_PHI5_Frequency,                            /* COREPLL_PHI5 clock                  */
    &Clock_Ip_Get_COREPLL_PHI6_Frequency,                            /* COREPLL_PHI6 clock                  */
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
    &Clock_Ip_Get_COREPLL_PHI7_Frequency,                            /* COREPLL_PHI7 clock                  */
#endif
    &Clock_Ip_Get_COREPLL_PHI8_Frequency,                            /* COREPLL_PHI8 clock                  */
    &Clock_Ip_Get_COREPLL_PHI9_Frequency,                            /* COREPLL_PHI9 clock                  */
    &Clock_Ip_Get_PERIPHPLL_PHI0_Frequency,                          /* PERIPHPLL_PHI0 clock                */
    &Clock_Ip_Get_PERIPHPLL_PHI1_Frequency,                          /* PERIPHPLL_PHI1 clock                */
    &Clock_Ip_Get_PERIPHPLL_PHI2_Frequency,                          /* PERIPHPLL_PHI2 clock                */
    &Clock_Ip_Get_PERIPHPLL_PHI3_Frequency,                          /* PERIPHPLL_PHI3 clock                */
    &Clock_Ip_Get_PERIPHPLL_PHI4_Frequency,                          /* PERIPHPLL_PHI4 clock                */
    &Clock_Ip_Get_PERIPHPLL_PHI5_Frequency,                          /* PERIPHPLL_PHI5 clock                */
    &Clock_Ip_Get_PERIPHPLL_PHI6_Frequency,                          /* PERIPHPLL_PHI6 clock                */
    &Clock_Ip_Get_PERIPHPLL_PHI7_Frequency,                          /* PERIPHPLL_PHI7 clock                */
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
    &Clock_Ip_Get_PERIPHPLL_PHI8_Frequency,                          /* PERIPHPLL_PHI8 clock                */
#endif
    &Clock_Ip_Get_PERIPHPLL_PHI9_Frequency,                          /* PERIPHPLL_PHI9 clock                */
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
    &Clock_Ip_Get_PERIPHPLL_DFS1_Frequency,                          /* PERIPHPLL_DFS1 clock                */
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
    &Clock_Ip_Get_PERIPHPLL_DFS2_Frequency,                          /* PERIPHPLL_DFS2 clock                */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
    &Clock_Ip_Get_AURORAPLL_PHI0_Frequency,                          /* AURORAPLL_PHI0 clock                */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
    &Clock_Ip_Get_AURORAPLL_PHI1_Frequency,                          /* AURORAPLL_PHI1 clock                */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI2_CLK)
    &Clock_Ip_Get_AURORAPLL_PHI2_Frequency,                          /* AURORAPLL_PHI2 clock                */
#endif
    &Clock_Ip_Get_ftm_0_ext_ref_Frequency,                           /* ftm_0_ext_ref clock                 */
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
    &Clock_Ip_Get_gmac_0_ext_ref_Frequency,                          /* gmac_0_ext_ref clock                */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
    &Clock_Ip_Get_gmac_0_ext_rx_Frequency,                           /* gmac_0_ext_rx clock                 */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
    &Clock_Ip_Get_gmac_0_ext_tx_Frequency,                           /* gmac_0_ext_tx clock                 */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
    &Clock_Ip_Get_gmac_0_ext_ts_Frequency,                           /* gmac_0_ext_ts clock                 */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
    &Clock_Ip_Get_gmac_0_sgmii_ref_Frequency,                        /* gmac_0_sgmii_ref clock              */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
    &Clock_Ip_Get_gmac_0_sgmii_rx_Frequency,                         /* gmac_0_sgmii_rx clock               */
#endif
#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
    &Clock_Ip_Get_gmac_0_sgmii_tx_Frequency,                         /* gmac_0_sgmii_tx clock               */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
    &Clock_Ip_Get_gmac_1_ext_ref_Frequency,                          /* gmac_1_ext_ref clock                */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
    &Clock_Ip_Get_gmac_1_ext_rx_Frequency,                           /* gmac_1_ext_rx clock                 */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
    &Clock_Ip_Get_gmac_1_ext_tx_Frequency,                           /* gmac_1_ext_tx clock                 */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
    &Clock_Ip_Get_gmac_1_ext_ts_Frequency,                           /* gmac_1_ext_ts clock                 */
#endif
#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
    &Clock_Ip_Get_firc_muxed_clk_Frequency,                          /* firc_muxed_clk clock                */
#endif
#if defined(CLOCK_IP_HAS_LVDS_CLK)
    &Clock_Ip_Get_lvds_clk_Frequency,                                /* lvds_clk clock                      */
#endif
#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
    &Clock_Ip_Get_rfe_pll_clk_Frequency,                             /* rfe_pll_clk clock                   */
#endif
    &Clock_Ip_Get_SYS_CLK_Frequency,                                 /* SYS_CLK clock                       */
    &Clock_Ip_Get_SYS_DIV2_CLK_Frequency,                            /* SYS_DIV2_CLK clock                  */
    &Clock_Ip_Get_SYS_DIV4_CLK_Frequency,                            /* SYS_DIV4_CLK clock                  */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* SYS_DIV8_CLK clock                  */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* RT_DAPB_CLK clock                   */
#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
    &Clock_Ip_Get_A53_CORE_CLK_Frequency,                            /* A53_CORE_CLK clock                  */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV2_CLK)
    &Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency,                       /* A53_CORE_DIV2_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV3_CLK)
    &Clock_Ip_Get_A53_CORE_DIV3_CLK_Frequency,                       /* A53_CORE_DIV3_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
    &Clock_Ip_Get_A53_CORE_DIV4_CLK_Frequency,                       /* A53_CORE_DIV4_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_A53_CORE_DIV10_CLK)
    &Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency,                      /* A53_CORE_DIV10_CLK clock            */
#endif
    &Clock_Ip_Get_ACCEL_CLK_Frequency,                               /* ACCEL_CLK clock                     */
#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
    &Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency,                          /* ACCEL_DIV3_CLK clock                */
#endif
#if defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
    &Clock_Ip_Get_ACCEL_DIV4_CLK_Frequency,                          /* ACCEL_DIV4_CLK clock                */
#endif
    &Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency,                          /* ACCEL_XBAR_CLK clock                */
    &Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency,                     /* ACCEL_XBAR_DIV2_CLK clock           */
    &Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency,                     /* ACCEL_XBAR_DIV4_CLK clock           */
    &Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency,                     /* ACCEL_XBAR_DIV8_CLK clock           */
    &Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency,                     /* AP_DAPB_CLK clock                   */
#if defined(CLOCK_IP_HAS_GMAC0_REF_CLK)
    &Clock_Ip_Get_GMAC0_REF_CLK_Frequency,                           /* GMAC0_REF_CLK clock                 */
#endif
#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
    &Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency,                       /* GMAC0_REF_DIV_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
    &Clock_Ip_Get_GMAC1_REF_CLK_Frequency,                           /* GMAC1_REF_CLK clock                 */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
    &Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency,                       /* GMAC1_REF_DIV_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
    &Clock_Ip_Get_GMAC1_INT_CLK_Frequency,                           /* GMAC1_INT_CLK clock            */
#endif
#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
    &Clock_Ip_Get_AURORA_TRACE_TEST_CLK_Frequency,                   /* AURORA_TRACE_TEST_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_AURORAPLL_DIFF_CLK)
    &Clock_Ip_Get_AURORAPLL_DIFF_CLK_Frequency,                      /* AURORAPLL_DIFF_CLK clock            */
#endif
#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
    &Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency,                      /* GMAC_1_INT_REF_CLK clock            */
#endif
    NULL_PTR,                                                       /* THE_LAST_PRODUCER_CLK */
    &Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency,                         /* BBE32EP_DSP_CLK clock               */
    &Clock_Ip_Get_CAN_CHI_CLK_Frequency,                             /* CAN_CHI_CLK clock                   */
    &Clock_Ip_Get_CAN_TS_CLK_Frequency,                              /* CAN_TS_CLK clock                    */
    &Clock_Ip_Get_CAN_PE_CLK_Frequency,                              /* CAN_PE_CLK clock                    */
    &Clock_Ip_Get_CAN_PE_CLK_Frequency,                              /* CAN0_CLK clock                      */
    &Clock_Ip_Get_CAN_PE_CLK_Frequency,                              /* CAN1_CLK clock                      */
    &Clock_Ip_Get_CLKOUT0_CLK_Frequency,                             /* CLKOUT0_CLK clock                   */
    &Clock_Ip_Get_CLKOUT1_CLK_Frequency,                             /* CLKOUT1_CLK clock                   */
#if defined(CLOCK_IP_HAS_CORE_A53_CLUSTER_0_CLK)
    &Clock_Ip_Get_A53_CORE_CLK_Frequency,                            /* CORE_A53_CLUSTER_0_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_CORE_A53_CLUSTER_1_CLK)
    &Clock_Ip_Get_A53_CORE_CLK_Frequency,                            /* CORE_A53_CLUSTER_1_CLK clock        */
#endif
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* CRC_CLK clock                       */
#if defined(CLOCK_IP_HAS_CSI_CLK)
    &Clock_Ip_Get_CSI_CLK_Frequency,                                 /* CSI_CLK clock                       */
#endif
#if defined(CLOCK_IP_HAS_CSI_CFG_CLK)
    &Clock_Ip_Get_CSI_CFG_CLK_Frequency,                             /* CSI_CFG_CLK clock                   */
#endif
#if defined(CLOCK_IP_HAS_CTE_CLK)
    &Clock_Ip_Get_CTE_CLK_Frequency,                                 /* CTE_CLK clock                       */
#endif
#if defined(CLOCK_IP_HAS_CSI_IPS_CLK)
    &Clock_Ip_Get_CTE_CLK_Frequency,                                 /* CSI_IPS_CLK clock                   */
#endif
#if defined(CLOCK_IP_HAS_CSI_TXCLK_CLK)
    &Clock_Ip_Get_CSI_TXCLK_CLK_Frequency,                           /* CSI_TXCLK_CLK clock                 */
#endif
    &Clock_Ip_Get_MC_CLK_Frequency,                                  /* MC_CLK clock                        */
    &Clock_Ip_Get_MC_CLK_Frequency,                                  /* CTU_CLK clock                       */
    &Clock_Ip_Get_CTU_IPS_CLK_Frequency,                             /* CTU_IPS_CLK clock                   */
    &Clock_Ip_Get_DAPB_CLK_Frequency,                                /* DAPB_CLK clock                      */
    &Clock_Ip_Get_SYS_CLK_Frequency,                                 /* DMA_CLK clock                       */
    &Clock_Ip_Get_SYS_DIV2_CLK_Frequency,                            /* DMA_CRC_CLK clock                   */
    &Clock_Ip_Get_SYS_CLK_Frequency,                                 /* DMA_TCD_CLK clock                   */
    &Clock_Ip_Get_SYS_CLK_Frequency,                                 /* DMAMUX0_CLK clock                   */
    &Clock_Ip_Get_SYS_CLK_Frequency,                                 /* DMAMUX1_CLK clock                   */
    &Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency,                        /* DSPI_SCK_TST_CLK clock              */
    &Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency,                     /* EIM_AP1_CLK clock                   */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* EIM_CM70_CLK clock                  */
#if defined(CLOCK_IP_HAS_EIM_CM71_CLK)
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* EIM_CM71_CLK clock                  */
#endif
    &Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency,                     /* EIM_DSP_CLK clock                   */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* EIM_RT0_CLK clock                   */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* EIM_RT2_CLK clock                   */
    &Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency,                     /* ERM_AP1_CLK clock                   */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* ERM_RT0_CLK clock                   */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* ERM_RT1_CLK clock                   */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* ERM_RT2_CLK clock                   */
    &Clock_Ip_Get_FCCU_IPS_CLK_Frequency,                            /* FCCU_IPS_CLK clock                  */
    &Clock_Ip_Get_MC_CLK_Frequency,                                  /* FTM0_CLK clock                      */
    &Clock_Ip_Get_FTM0_EXT_CLK_Frequency,                            /* FTM0_EXT_CLK clock                  */
    &Clock_Ip_Get_GMAC0_RX_CLK_Frequency,                            /* GMAC0_RX_CLK clock                  */
    &Clock_Ip_Get_GMAC0_TS_CLK_Frequency,                            /* GMAC0_TS_CLK clock                  */
    &Clock_Ip_Get_GMAC0_TX_CLK_Frequency,                            /* GMAC0_TX_CLK clock                  */
#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK)
    &Clock_Ip_Get_GMAC1_RX_CLK_Frequency,                            /* GMAC1_RX_CLK clock                  */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK)
    &Clock_Ip_Get_GMAC1_TS_CLK_Frequency,                            /* GMAC1_TS_CLK clock                  */
#endif
#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK)
    &Clock_Ip_Get_GMAC1_TX_CLK_Frequency,                            /* GMAC1_TX_CLK clock                  */
#endif
    &Clock_Ip_Get_SYS_DIV4_CLK_Frequency,                            /* IIC0_CLK clock                      */
    &Clock_Ip_Get_SYS_DIV4_CLK_Frequency,                            /* IIC1_CLK clock                      */
    &Clock_Ip_Get_LBIST_CLK_Frequency,                               /* LBIST_CLK clock                     */
    &Clock_Ip_Get_LBIST_CLK_Frequency,                               /* LBIST0_CLK clock                    */
    &Clock_Ip_Get_LBIST_CLK_Frequency,                               /* LBIST1_CLK clock                    */
    &Clock_Ip_Get_LBIST_CLK_Frequency,                               /* LBIST2_CLK clock                    */
    &Clock_Ip_Get_LBIST_CLK_Frequency,                               /* LBIST3_CLK clock                    */
    &Clock_Ip_Get_LBIST_CLK_Frequency,                               /* LBIST4_CLK clock                    */
    &Clock_Ip_Get_LBIST_CLK_Frequency,                               /* LBIST5_CLK clock                    */
    &Clock_Ip_Get_LBIST_CLK_Frequency,                               /* LBIST6_CLK clock                    */
    &Clock_Ip_Get_LBIST_CLK_Frequency,                               /* LBIST7_CLK clock                    */
    &Clock_Ip_Get_LIN_BAUD_CLK_Frequency,                            /* LIN_BAUD_CLK clock                  */
    &Clock_Ip_Get_LINFLEXD_CLK_Frequency,                             /* LINFLEXD_CLK                         */
    &Clock_Ip_Get_LIN_BAUD_CLK_Frequency,                            /* LIN0_CLK clock                      */
#if defined(CLOCK_IP_HAS_LIN1_CLK)
    &Clock_Ip_Get_LIN_BAUD_CLK_Frequency,                            /* LIN1_CLK clock                      */
#endif
    &Clock_Ip_Get_SYS_CLK_Frequency,                                 /* SYS_M7_0_CLK clock                  */
#if defined(CLOCK_IP_HAS_SYS_M7_1_CLK)
    &Clock_Ip_Get_SYS_CLK_Frequency,                                 /* SYS_M7_1_CLK clock                  */
#endif
    &Clock_Ip_Get_SYS_CLK_Frequency,                                 /* SYS_HSE_SYS_CLK clock               */
#if defined(CLOCK_IP_HAS_MIPICSI2_0_CLK)
    &Clock_Ip_Get_MIPICSI2_0_CLK_Frequency,                          /* MIPICSI2_0_CLK clock                */
#endif
#if defined(CLOCK_IP_HAS_MIPICSI2_1_CLK)
    &Clock_Ip_Get_MIPICSI2_1_CLK_Frequency,                          /* MIPICSI2_1_CLK clock                */
#endif
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* MSCM_CLK clock                      */
    &Clock_Ip_Get_NOC_TRACE_CLK_Frequency,                           /* NOC_TRACE_CLK clock                 */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                /* OCOTP_CLK clock                     */
    &Clock_Ip_Get_SYS_DIV4_CLK_Frequency,                            /* PIT0_CLK clock                      */
    &Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency,                     /* PIT2_CLK clock                      */
    &Clock_Ip_Get_QSPI_2X_CLK_Frequency,                             /* QSPI_2X_CLK clock                   */
    &Clock_Ip_Get_QSPI_1X_CLK_Frequency,                             /* QSPI_1X_CLK                         */
    &Clock_Ip_Get_QSPI0_CLK_Frequency,                               /* QSPI0_CLK clock                     */
    &Clock_Ip_Get_MC_CLK_Frequency,                                  /* SAR_ADC_CLK clock                   */
    &Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency,                     /* SEMA42_1_CLK clock                  */
    &Clock_Ip_Get_SYS_DIV2_CLK_Frequency,                            /* SEMA42_CLK clock                    */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* SIUL2_CLK clock                     */
    &Clock_Ip_Get_SPI_CLK_Frequency,                                 /* SPI_CLK clock                       */
    &Clock_Ip_Get_SPI_CLK_Frequency,                                 /* SPI0_CLK clock                      */
    &Clock_Ip_Get_SPI_CLK_Frequency,                                 /* SPI1_CLK clock                      */
#if defined(CLOCK_IP_HAS_SPI2_CLK)
    &Clock_Ip_Get_SPI_CLK_Frequency,                                 /* SPI2_CLK clock                      */
#endif
#if defined(CLOCK_IP_HAS_SPI3_CLK)
    &Clock_Ip_Get_SPI_CLK_Frequency,                                 /* SPI3_CLK clock                      */
#endif
#if defined(CLOCK_IP_HAS_SPT_CLK)
    &Clock_Ip_Get_SPT_CLK_Frequency,                                 /* SPT_CLK clock                       */
#endif
    &Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency,                          /* SRAM_CLK clock                      */
    &Clock_Ip_Get_STCU_CLK_Frequency,                                /* STCU_CLK clock                      */
    &Clock_Ip_Get_SYS_DIV2_CLK_Frequency,                            /* STM0_CLK clock                      */
    &Clock_Ip_Get_SYS_DIV2_CLK_Frequency,                            /* STM1_CLK clock                      */
    &Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency,                     /* STM2_CLK clock                      */
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* SWT0_CLK clock                      */
#if defined(CLOCK_IP_HAS_SWT1_CLK)
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* SWT1_CLK clock                      */
#endif
#if defined(CLOCK_IP_HAS_SWT2_CLK)
    &Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency,                     /* SWT2_CLK clock                      */
#endif
#if defined(CLOCK_IP_HAS_SWT3_CLK)
    &Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency,                     /* SWT3_CLK clock                      */
#endif
    &Clock_Ip_Get_TMU_CLK_Frequency,                                 /* TMU_CLK clock                       */
    &Clock_Ip_Get_TCLK_CLK_Frequency,                                /* TCLK_CLK clock                      */
#if defined(CLOCK_IP_HAS_WKPU_CLK)
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* WKPU_CLK clock                      */
#endif
    &Clock_Ip_Get_SYS_DIV8_CLK_Frequency,                            /* XRDC0_CLK clock                     */
    &Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency,                     /* XRDC1_CLK clock                     */
};
/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static extSignalFreq Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_EXT_SIGNALS_NO] =  {
{FTM_0_EXT_REF_CLK,0U},
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
{GMAC_0_EXT_REF_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
{GMAC_0_EXT_RX_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
{GMAC_0_EXT_TX_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
{GMAC_0_EXT_TS_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
{GMAC_1_EXT_REF_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
{GMAC_1_EXT_RX_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
{GMAC_1_EXT_TX_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
{GMAC_1_EXT_TS_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif


#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)
{GMAC_0_SGMII_REF_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
{GMAC_0_SGMII_RX_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
{GMAC_0_SGMII_TX_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
{FIRC_MUXED_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_LVDS_CLK)
{LVDS_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif

#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
{RFE_PLL_CLK,0U},
#else
{RESERVED_CLK,CLOCK_IP_EXT_SIGNALS_NO},
#endif
};




/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"


#define MCU_START_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

/* External oscillators */
static uint32 Clock_Ip_u32Fxosc = CLOCK_IP_DEFAULT_FXOSC_FREQUENCY;
static uint32 Clock_Ip_u32CorePllFreq        = CLOCK_IP_COREPLL_FREQ;
static uint32 Clock_Ip_u32CorePllChecksum    = CLOCK_IP_COREPLL_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPllFreq      = CLOCK_IP_PERIPHPLL_FREQ;
static uint32 Clock_Ip_u32PeriphPllChecksum  = CLOCK_IP_PERIPHPLL_CHECKSUM;
static uint32 Clock_Ip_u32CorePhi0Freq       = CLOCK_IP_COREPLL_PHI0_FREQ;
static uint32 Clock_Ip_u32CorePhi0Checksum   = CLOCK_IP_COREPLL_PHI0_CHECKSUM;
static uint32 Clock_Ip_u32CorePhi1Freq       = CLOCK_IP_COREPLL_PHI1_FREQ;
static uint32 Clock_Ip_u32CorePhi1Checksum   = CLOCK_IP_COREPLL_PHI1_CHECKSUM;
static uint32 Clock_Ip_u32CorePhi2Freq       = CLOCK_IP_COREPLL_PHI2_FREQ;
static uint32 Clock_Ip_u32CorePhi2Checksum   = CLOCK_IP_COREPLL_PHI2_CHECKSUM;
static uint32 Clock_Ip_u32CorePhi3Freq       = CLOCK_IP_COREPLL_PHI3_FREQ;
static uint32 Clock_Ip_u32CorePhi3Checksum   = CLOCK_IP_COREPLL_PHI3_CHECKSUM;
#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
static uint32 Clock_Ip_u32CorePhi4Freq       = CLOCK_IP_COREPLL_PHI4_FREQ;
static uint32 Clock_Ip_u32CorePhi4Checksum   = CLOCK_IP_COREPLL_PHI4_CHECKSUM;
#endif
static uint32 Clock_Ip_u32CorePhi5Freq       = CLOCK_IP_COREPLL_PHI5_FREQ;
static uint32 Clock_Ip_u32CorePhi5Checksum   = CLOCK_IP_COREPLL_PHI5_CHECKSUM;
static uint32 Clock_Ip_u32CorePhi6Freq       = CLOCK_IP_COREPLL_PHI6_FREQ;
static uint32 Clock_Ip_u32CorePhi6Checksum   = CLOCK_IP_COREPLL_PHI6_CHECKSUM;
#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
static uint32 Clock_Ip_u32CorePhi7Freq       = CLOCK_IP_COREPLL_PHI7_FREQ;
static uint32 Clock_Ip_u32CorePhi7Checksum   = CLOCK_IP_COREPLL_PHI7_CHECKSUM;
#endif
static uint32 Clock_Ip_u32CorePhi8Freq       = CLOCK_IP_COREPLL_PHI8_FREQ;
static uint32 Clock_Ip_u32CorePhi8Checksum   = CLOCK_IP_COREPLL_PHI8_CHECKSUM;
static uint32 Clock_Ip_u32CorePhi9Freq       = CLOCK_IP_COREPLL_PHI9_FREQ;
static uint32 Clock_Ip_u32CorePhi9Checksum   = CLOCK_IP_COREPLL_PHI9_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPhi0Freq     = CLOCK_IP_PERIPHPLL_PHI0_FREQ;
static uint32 Clock_Ip_u32PeriphPhi0Checksum = CLOCK_IP_PERIPHPLL_PHI0_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPhi1Freq     = CLOCK_IP_PERIPHPLL_PHI1_FREQ;
static uint32 Clock_Ip_u32PeriphPhi1Checksum = CLOCK_IP_PERIPHPLL_PHI1_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPhi2Freq     = CLOCK_IP_PERIPHPLL_PHI2_FREQ;
static uint32 Clock_Ip_u32PeriphPhi2Checksum = CLOCK_IP_PERIPHPLL_PHI2_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPhi3Freq     = CLOCK_IP_PERIPHPLL_PHI3_FREQ;
static uint32 Clock_Ip_u32PeriphPhi3Checksum = CLOCK_IP_PERIPHPLL_PHI3_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPhi4Freq     = CLOCK_IP_PERIPHPLL_PHI4_FREQ;
static uint32 Clock_Ip_u32PeriphPhi4Checksum = CLOCK_IP_PERIPHPLL_PHI4_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPhi5Freq     = CLOCK_IP_PERIPHPLL_PHI5_FREQ;
static uint32 Clock_Ip_u32PeriphPhi5Checksum = CLOCK_IP_PERIPHPLL_PHI5_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPhi6Freq     = CLOCK_IP_PERIPHPLL_PHI6_FREQ;
static uint32 Clock_Ip_u32PeriphPhi6Checksum = CLOCK_IP_PERIPHPLL_PHI6_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPhi7Freq     = CLOCK_IP_PERIPHPLL_PHI7_FREQ;
static uint32 Clock_Ip_u32PeriphPhi7Checksum = CLOCK_IP_PERIPHPLL_PHI7_CHECKSUM;
#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
static uint32 Clock_Ip_u32PeriphPhi8Freq     = CLOCK_IP_PERIPHPLL_PHI8_FREQ;
static uint32 Clock_Ip_u32PeriphPhi8Checksum = CLOCK_IP_PERIPHPLL_PHI8_CHECKSUM;
#endif
static uint32 Clock_Ip_u32PeriphPhi9Freq     = CLOCK_IP_PERIPHPLL_PHI9_FREQ;
static uint32 Clock_Ip_u32PeriphPhi9Checksum = CLOCK_IP_PERIPHPLL_PHI9_CHECKSUM;
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
static uint32 Clock_Ip_u32PeriphDfs1Freq     = CLOCK_IP_PERIPHDFS1_FREQ;
static uint32 Clock_Ip_u32PeriphDfs1Checksum = CLOCK_IP_PERIPHDFS1_CHECKSUM;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
static uint32 Clock_Ip_u32PeriphDfs2Freq     = CLOCK_IP_PERIPHDFS2_FREQ;
static uint32 Clock_Ip_u32PeriphDfs2Checksum = CLOCK_IP_PERIPHDFS2_CHECKSUM;
#endif

#define MCU_STOP_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/* Return zero frequency */
static uint32 Clock_Ip_Get_Zero_Frequency(void)
{

    return 0U;
}

/* Return FIRC_CLK frequency */
static uint32 Clock_Ip_Get_FIRC_CLK_Frequency(void) {

    return CLOCK_IP_FIRC_FREQUENCY;
}

/* Return FXOSC_CLK frequency */
static uint32 Clock_Ip_Get_FXOSC_CLK_Frequency(void) {
    uint32 Frequency;

#ifdef CLOCK_IP_DERIVATIVE_001
    Frequency = (((IP_FXOSC->STAT & FXOSC_STAT_OSC_STAT_MASK) >> FXOSC_STAT_OSC_STAT_SHIFT) != 0U) ? Clock_Ip_u32Fxosc : 0U;
#else
    Frequency = (((IP_FXOSC->STATUS & FXOSC_STATUS_OSC_STAT_MASK) >> FXOSC_STATUS_OSC_STAT_SHIFT) != 0U) ? Clock_Ip_u32Fxosc : 0U;
#endif
    return Frequency;
}

/* Return COREPLL_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_CLK_Frequency(void) {

    if (Clock_Ip_u32CorePllChecksum != (CORE_PLL_CHECKSUM()))
    {
        Clock_Ip_u32CorePllChecksum = (CORE_PLL_CHECKSUM());
        Clock_Ip_u32CorePllFreq = Clock_Ip_PLL_VCO(IP_CORE_PLL);
    }
    return (((IP_CORE_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT) != 0U) ? Clock_Ip_u32CorePllFreq : 0U;
}

/* Return PERIPHPLL_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_CLK_Frequency(void) {

    if (Clock_Ip_u32PeriphPllChecksum != (PERIPH_PLL_CHECKSUM()))
    {
        Clock_Ip_u32PeriphPllChecksum = (PERIPH_PLL_CHECKSUM());
        Clock_Ip_u32PeriphPllFreq = Clock_Ip_PLL_VCO(IP_PERIPH_PLL);
    }
    return (((IP_PERIPH_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT) != 0U) ? Clock_Ip_u32PeriphPllFreq : 0U;
}

#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
/* Return AURORAPLL_CLK frequency */
static uint32 Clock_Ip_Get_AURORAPLL_CLK_Frequency(void) {
#ifdef IP_ATP_PLL
    const ATP_PLL_Type *Base = IP_ATP_PLL;
#else
    const ATP_Type *Base = IP_ATP;
#endif
    uint32 Frequency;

    Frequency = Clock_Ip_PLL_DCO();

    if ( (((Base->PLLSR & ATP_PLLSR_LOCK_MASK) >> ATP_PLLSR_LOCK_SHIFT) != 1U) || \
         (((Base->PLLSR & ATP_PLLCR_PLLPD_MASK) >> ATP_PLLCR_PLLPD_SHIFT) != 0U) )
    {
        Frequency = 0U;
    }

    return Frequency;
}
#endif

/* Return COREPLL_PHI0_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI0_Frequency(void) {

    if (Clock_Ip_u32CorePhi0Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[0U]))
    {
        Clock_Ip_u32CorePhi0Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[0U]);

        Clock_Ip_u32CorePhi0Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi0Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi0Freq /= (((IP_CORE_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi0Freq;
}

/* Return COREPLL_PHI1_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI1_Frequency(void) {

    if (Clock_Ip_u32CorePhi1Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[1U]))
    {
        Clock_Ip_u32CorePhi1Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[1U]);

        Clock_Ip_u32CorePhi1Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi1Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi1Freq /= (((IP_CORE_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi1Freq;
}

/* Return COREPLL_PHI2_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI2_Frequency(void) {

    if (Clock_Ip_u32CorePhi2Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[2U]))
    {
        Clock_Ip_u32CorePhi2Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[2U]);

        Clock_Ip_u32CorePhi2Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi2Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[2U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi2Freq /= (((IP_CORE_PLL->PLLODIV[2U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi2Freq;
}

/* Return COREPLL_PHI3_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI3_Frequency(void) {

    if (Clock_Ip_u32CorePhi3Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[3U]))
    {
        Clock_Ip_u32CorePhi3Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[3U]);

        Clock_Ip_u32CorePhi3Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi3Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[3U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi3Freq /= (((IP_CORE_PLL->PLLODIV[3U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi3Freq;
}

#if defined(CLOCK_IP_HAS_COREPLL_PHI4_CLK)
/* Return COREPLL_PHI4_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI4_Frequency(void) {

    if (Clock_Ip_u32CorePhi4Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[4U]))
    {
        Clock_Ip_u32CorePhi4Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[4U]);

        Clock_Ip_u32CorePhi4Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi4Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[4U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi4Freq /= (((IP_CORE_PLL->PLLODIV[4U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi4Freq;
}
#endif

/* Return COREPLL_PHI5_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI5_Frequency(void) {

    if (Clock_Ip_u32CorePhi5Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[5U]))
    {
        Clock_Ip_u32CorePhi5Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[5U]);

        Clock_Ip_u32CorePhi5Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi5Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[5U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi5Freq /= (((IP_CORE_PLL->PLLODIV[5U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi5Freq;
}

/* Return COREPLL_PHI6_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI6_Frequency(void) {

    if (Clock_Ip_u32CorePhi6Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[6U]))
    {
        Clock_Ip_u32CorePhi6Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[6U]);

        Clock_Ip_u32CorePhi6Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi6Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[6U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi6Freq /= (((IP_CORE_PLL->PLLODIV[6U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi6Freq;
}

#if defined(CLOCK_IP_HAS_COREPLL_PHI7_CLK)
/* Return COREPLL_PHI7_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI7_Frequency(void) {

    if (Clock_Ip_u32CorePhi7Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[7U]))
    {
        Clock_Ip_u32CorePhi7Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[7U]);

        Clock_Ip_u32CorePhi7Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi7Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[7U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi7Freq /= (((IP_CORE_PLL->PLLODIV[7U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi7Freq;
}
#endif

/* Return COREPLL_PHI8_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI8_Frequency(void) {

    if (Clock_Ip_u32CorePhi8Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[8U]))
    {
        Clock_Ip_u32CorePhi8Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[8U]);

        Clock_Ip_u32CorePhi8Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi8Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[8U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi8Freq /= (((IP_CORE_PLL->PLLODIV[8U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi8Freq;
}

/* Return COREPLL_PHI9_CLK frequency */
static uint32 Clock_Ip_Get_COREPLL_PHI9_Frequency(void) {

    if (Clock_Ip_u32CorePhi9Checksum != (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[9U]))
    {
        Clock_Ip_u32CorePhi9Checksum = (CORE_PLL_CHECKSUM() ^ IP_CORE_PLL->PLLSR ^ IP_CORE_PLL->PLLODIV[9U]);

        Clock_Ip_u32CorePhi9Freq = Clock_Ip_Get_COREPLL_CLK_Frequency();
        Clock_Ip_u32CorePhi9Freq &= Clock_Ip_u32EnableDivider[((IP_CORE_PLL->PLLODIV[9U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32CorePhi9Freq /= (((IP_CORE_PLL->PLLODIV[9U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32CorePhi9Freq;
}

/* Return PERIPHPLL_PHI0_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI0_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi0Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[0U]))
    {
        Clock_Ip_u32PeriphPhi0Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[0U]);

        Clock_Ip_u32PeriphPhi0Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi0Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi0Freq /= (((IP_PERIPH_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi0Freq;
}

/* Return PERIPHPLL_PHI1_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI1_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi1Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[1U]))
    {
        Clock_Ip_u32PeriphPhi1Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[1U]);

        Clock_Ip_u32PeriphPhi1Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi1Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi1Freq /= (((IP_PERIPH_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi1Freq;
}

/* Return PERIPHPLL_PHI2_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI2_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi2Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[2U]))
    {
        Clock_Ip_u32PeriphPhi2Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[2U]);

        Clock_Ip_u32PeriphPhi2Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi2Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[2U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi2Freq /= (((IP_PERIPH_PLL->PLLODIV[2U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi2Freq;
}

/* Return PERIPHPLL_PHI3_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI3_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi3Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[3U]))
    {
        Clock_Ip_u32PeriphPhi3Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[3U]);

        Clock_Ip_u32PeriphPhi3Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi3Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[3U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi3Freq /= (((IP_PERIPH_PLL->PLLODIV[3U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi3Freq;
}

/* Return PERIPHPLL_PHI4_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI4_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi4Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[4U]))
    {
        Clock_Ip_u32PeriphPhi4Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[4U]);

        Clock_Ip_u32PeriphPhi4Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi4Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[4U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi4Freq /= (((IP_PERIPH_PLL->PLLODIV[4U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi4Freq;
}

/* Return PERIPHPLL_PHI5_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI5_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi5Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[5U]))
    {
        Clock_Ip_u32PeriphPhi5Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[5U]);

        Clock_Ip_u32PeriphPhi5Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi5Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[5U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi5Freq /= (((IP_PERIPH_PLL->PLLODIV[5U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi5Freq;
}

/* Return PERIPHPLL_PHI6_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI6_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi6Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[6U]))
    {
        Clock_Ip_u32PeriphPhi6Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[6U]);

        Clock_Ip_u32PeriphPhi6Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi6Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[6U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi6Freq /= (((IP_PERIPH_PLL->PLLODIV[6U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi6Freq;
}

/* Return PERIPHPLL_PHI7_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI7_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi7Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[7U]))
    {
        Clock_Ip_u32PeriphPhi7Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[7U]);

        Clock_Ip_u32PeriphPhi7Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi7Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[7U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi7Freq /= (((IP_PERIPH_PLL->PLLODIV[7U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi7Freq;
}

#if defined(CLOCK_IP_HAS_PERIPHPLL_PHI8_CLK)
/* Return PERIPHPLL_PHI8_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI8_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi8Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[8U]))
    {
        Clock_Ip_u32PeriphPhi8Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[8U]);

        Clock_Ip_u32PeriphPhi8Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi8Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[8U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi8Freq /= (((IP_PERIPH_PLL->PLLODIV[8U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi8Freq;
}
#endif

/* Return PERIPHPLL_PHI9_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_PHI9_Frequency(void) {

    if (Clock_Ip_u32PeriphPhi9Checksum != (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[9U]))
    {
        Clock_Ip_u32PeriphPhi9Checksum = (PERIPH_PLL_CHECKSUM() ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_PLL->PLLODIV[9U]);

        Clock_Ip_u32PeriphPhi9Freq = Clock_Ip_Get_PERIPHPLL_CLK_Frequency();
        Clock_Ip_u32PeriphPhi9Freq &= Clock_Ip_u32EnableDivider[((IP_PERIPH_PLL->PLLODIV[9U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
        Clock_Ip_u32PeriphPhi9Freq /= (((IP_PERIPH_PLL->PLLODIV[9U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    }
    return Clock_Ip_u32PeriphPhi9Freq;
}

#if defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
/* Return AURORAPLL_PHI0_CLK frequency */
static uint32 Clock_Ip_Get_AURORAPLL_PHI0_Frequency(void) {
#ifdef IP_ATP_PLL
    const ATP_PLL_Type *Base = IP_ATP_PLL;
#else
    const ATP_Type *Base = IP_ATP;
#endif
    uint32 Frequency;

    Frequency = Clock_Ip_Get_AURORAPLL_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableDivider[((Base->PLLODIV_0 & ATP_PLLODIV_0_DE_MASK) >> ATP_PLLODIV_0_DE_SHIFT)];                                    /*  Divider enable/disable */

    if (0U == (Base->ENABLE_CLOCKS & ATP_ENABLE_CLOCKS_DIRECTO_MASK))
    {
        Frequency /= ((Base->FCW_NDIV_PDIV_CONFIG & ATP_FCW_NDIV_PDIV_CONFIG_PDIV_MASK) >> ATP_FCW_NDIV_PDIV_CONFIG_PDIV_SHIFT);                                    /*  Divider Pdiv */
    }

    Frequency /= ((((Base->PLLODIV_0 & ATP_PLLODIV_0_DIV_MASK) >> ATP_PLLODIV_0_DIV_SHIFT) > 1U) ? (4U) : (((Base->PLLODIV_0 & ATP_PLLODIV_0_DIV_MASK) >> ATP_PLLODIV_0_DIV_SHIFT) + 1U));                                          /*  Apply divider value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
/* Return AURORAPLL_PHI1_CLK frequency */
static uint32 Clock_Ip_Get_AURORAPLL_PHI1_Frequency(void) {

    const ATP_Type *Base = IP_ATP;
    uint32 Frequency;

    Frequency = Clock_Ip_Get_AURORAPLL_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableDivider[((Base->PLLODIV_1 & ATP_PLLODIV_1_DE_MASK) >> ATP_PLLODIV_1_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= ((Base->FCW_NDIV_PDIV_CONFIG & ATP_FCW_NDIV_PDIV_CONFIG_PDIV_MASK) >> ATP_FCW_NDIV_PDIV_CONFIG_PDIV_SHIFT);                                    /*  Divider Pdiv */
    Frequency /= (((Base->PLLODIV_1 & ATP_PLLODIV_1_DIV_MASK) >> ATP_PLLODIV_1_DIV_SHIFT) + 1U);                                          /*  Apply divider value */

    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_AURORAPLL_PHI2_CLK)
/* Return AURORAPLL_PHI2_CLK frequency */
static uint32 Clock_Ip_Get_AURORAPLL_PHI2_Frequency(void) {
#ifdef IP_ATP_PLL
    const ATP_PLL_Type *Base = IP_ATP_PLL;
#else
    const ATP_Type *Base = IP_ATP;
#endif
    uint32 Frequency;

    Frequency = Clock_Ip_Get_AURORAPLL_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableDivider[((Base->PLLODIV_2 & ATP_PLLODIV_2_DE_MASK) >> ATP_PLLODIV_2_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= ((Base->FCW_NDIV_PDIV_CONFIG & ATP_FCW_NDIV_PDIV_CONFIG_PDIV_MASK) >> ATP_FCW_NDIV_PDIV_CONFIG_PDIV_SHIFT);                                    /*  Divider Pdiv */
    Frequency /= (((Base->PLLODIV_2 & ATP_PLLODIV_2_DIV_MASK) >> ATP_PLLODIV_2_DIV_SHIFT) + 1U);                                          /*  Apply divider value */

    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
/* Return PERIPHPLL_DFS1_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_DFS1_Frequency(void) {

    if (Clock_Ip_u32PeriphDfs1Checksum != (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[0U]))
    {
        Clock_Ip_u32PeriphDfs1Checksum = (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[0U]);
        Clock_Ip_u32PeriphDfs1Freq = Clock_Ip_DFS_OUTPUT(IP_PERIPH_DFS,0U,Clock_Ip_Get_PERIPHPLL_CLK_Frequency());
    }
    return ((((IP_PERIPH_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_0_CHANNEL) != 0U) ? Clock_Ip_u32PeriphDfs1Freq : 0U;
}
#endif

#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
/* Return PERIPHPLL_DFS2_CLK frequency */
static uint32 Clock_Ip_Get_PERIPHPLL_DFS2_Frequency(void) {

    if (Clock_Ip_u32PeriphDfs2Checksum != (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[1U]))
    {
        Clock_Ip_u32PeriphDfs2Checksum = (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[1U]);
        Clock_Ip_u32PeriphDfs2Freq = Clock_Ip_DFS_OUTPUT(IP_PERIPH_DFS,1U,Clock_Ip_Get_PERIPHPLL_CLK_Frequency());
    }
    return ((((IP_PERIPH_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_1_CHANNEL) != 0U) ? Clock_Ip_u32PeriphDfs2Freq : 0U;
}
#endif

/* Return ftm_0_ext_ref frequency */
static uint32 Clock_Ip_Get_ftm_0_ext_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_FTM_0_EXT_REF_CLK_INDEX_ENTRY].Frequency;
}
#if defined(CLOCK_IP_HAS_GMAC_0_EXT_REF_CLK)
/* Return gmac_0_ext_ref frequency */
static uint32 Clock_Ip_Get_gmac_0_ext_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_EXT_REF_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_EXT_RX_CLK)
/* Return gmac_0_ext_rx frequency */
static uint32 Clock_Ip_Get_gmac_0_ext_rx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_EXT_RX_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TX_CLK)
/* Return gmac_0_ext_tx frequency */
static uint32 Clock_Ip_Get_gmac_0_ext_tx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_EXT_TX_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_EXT_TS_CLK)
/* Return gmac_0_ext_ts frequency */
static uint32 Clock_Ip_Get_gmac_0_ext_ts_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_EXT_TS_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_1_EXT_REF_CLK)
/* Return gmac_1_ext_ref frequency */
static uint32 Clock_Ip_Get_gmac_1_ext_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_1_EXT_REF_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_1_EXT_RX_CLK)
/* Return gmac_1_ext_rx frequency */
static uint32 Clock_Ip_Get_gmac_1_ext_rx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_1_EXT_RX_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TX_CLK)
/* Return gmac_1_ext_tx frequency */
static uint32 Clock_Ip_Get_gmac_1_ext_tx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_1_EXT_TX_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_1_EXT_TS_CLK)
/* Return gmac_1_ext_ts frequency */
static uint32 Clock_Ip_Get_gmac_1_ext_ts_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_1_EXT_TS_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_REF_CLK)

/* Return gmac_0_sgmii_ref frequency */
static uint32 Clock_Ip_Get_gmac_0_sgmii_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_SGMII_REF_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_RX_CLK)
/* Return gmac_0_sgmii_rx frequency */
static uint32 Clock_Ip_Get_gmac_0_sgmii_rx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_SGMII_RX_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_0_SGMII_TX_CLK)
/* Return gmac_0_sgmii_tx frequency */
static uint32 Clock_Ip_Get_gmac_0_sgmii_tx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_SGMII_TX_CLK_INDEX_ENTRY].Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_FIRC_MUXED_CLK)
/* Return firc_muxed_clk frequency */
static uint32 Clock_Ip_Get_firc_muxed_clk_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_FIRC_MUXED_CLK_INDEX_ENTRY].Frequency;
}
#endif
#if defined(CLOCK_IP_HAS_LVDS_CLK)
/* Return lvds_clk frequency */
static uint32 Clock_Ip_Get_lvds_clk_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_LVDS_CLK_INDEX_ENTRY].Frequency;
}
#endif
#if defined(CLOCK_IP_HAS_RFE_PLL_CLK)
/* Return rfe_pll_clk frequency */
static uint32 Clock_Ip_Get_rfe_pll_clk_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_RFE_PLL_CLK_INDEX_ENTRY].Frequency;
}
#endif
/* Return SYS_CLK frequency */
static uint32 Clock_Ip_Get_SYS_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_0_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

/* Return SYS_DIV2_CLK frequency */
static uint32 Clock_Ip_Get_SYS_DIV2_CLK_Frequency(void) {

    return Clock_Ip_Get_SYS_CLK_Frequency() >> 1U;
}

/* Return SYS_DIV4_CLK frequency */
static uint32 Clock_Ip_Get_SYS_DIV4_CLK_Frequency(void) {

    return Clock_Ip_Get_SYS_CLK_Frequency() >> 2U;
}

/* Return SYS_DIV8_CLK frequency */
static uint32 Clock_Ip_Get_SYS_DIV8_CLK_Frequency(void) {

    return Clock_Ip_Get_SYS_CLK_Frequency() >> 3U;
}

#if defined(CLOCK_IP_HAS_A53_CORE_CLK)
/* Return A53_CORE_CLK frequency */
static uint32 Clock_Ip_Get_A53_CORE_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSS_SELSTAT_MASK) >> MC_CGM_MUX_0_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_A53_CORE_DIV2_CLK)
/* Return A53_CORE_DIV2_CLK frequency */
static uint32 Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency(void) {

    return Clock_Ip_Get_A53_CORE_CLK_Frequency() >> 1U;
}
#endif

#if defined(CLOCK_IP_HAS_A53_CORE_DIV3_CLK)
/* Return A53_CORE_DIV3_CLK frequency */
static uint32 Clock_Ip_Get_A53_CORE_DIV3_CLK_Frequency(void) {

    return Clock_Ip_Get_A53_CORE_CLK_Frequency() / 3U;
}
#endif

#if defined(CLOCK_IP_HAS_A53_CORE_DIV4_CLK)
/* Return A53_CORE_DIV4_CLK frequency */
static uint32 Clock_Ip_Get_A53_CORE_DIV4_CLK_Frequency(void) {

    return Clock_Ip_Get_A53_CORE_CLK_Frequency() / 4U;
}
#endif

#if defined(CLOCK_IP_HAS_A53_CORE_DIV10_CLK)
/* Return A53_CORE_DIV10_CLK frequency */
static uint32 Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency(void) {

    return Clock_Ip_Get_A53_CORE_CLK_Frequency() / 10U;
}
#endif

/* Return ACCEL_CLK frequency */
static uint32 Clock_Ip_Get_ACCEL_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_1_CSS & MC_CGM_MUX_1_CSS_SELSTAT_MASK) >> MC_CGM_MUX_1_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

#if defined(CLOCK_IP_HAS_ACCEL_DIV3_CLK)
/* Return ACCEL_DIV3_CLK frequency */
static uint32 Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency(void) {

    return Clock_Ip_Get_ACCEL_CLK_Frequency() / 3U;
}
#endif

#if defined(CLOCK_IP_HAS_ACCEL_DIV4_CLK)
/* Return A53_CORE_DIV4_CLK frequency */
static uint32 Clock_Ip_Get_ACCEL_DIV4_CLK_Frequency(void) {

    return Clock_Ip_Get_ACCEL_CLK_Frequency() / 4U;
}
#endif

/* Return _ACCEL_XBAR_CLK frequency */
static uint32 Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_2_CSS & MC_CGM_MUX_2_CSS_SELSTAT_MASK) >> MC_CGM_MUX_2_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

/* Return ACCEL_XBAR_DIV2_CLK frequency */
static uint32 Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency(void) {

    return Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency() >> 1U;
}

/* Return ACCEL_XBAR_DIV4_CLK frequency */
static uint32 Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency(void) {

    return Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency() >> 2U;
}

/* Return ACCEL_XBAR_DIV8_CLK frequency */
static uint32 Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency(void) {

    return Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency() >> 3U;
}

#if defined(CLOCK_IP_HAS_GMAC0_REF_CLK)
/* Return GMAC0_REF_CLK frequency */
static uint32 Clock_Ip_Get_GMAC0_REF_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_3->MUX_3_CSS & MC_CGM_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_MUX_3_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC0_REF_DIV_CLK)
/* Return GMAC0_REF_DIV_CLK frequency */
static uint32 Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfTableClockGeneration[((IP_MC_CGM_3->MUX_3_CSS & MC_CGM_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_MUX_3_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_3->MUX_3_DC_0 & MC_CGM_MUX_3_DC_0_DE_MASK) >> MC_CGM_MUX_3_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->MUX_3_DC_0 & MC_CGM_MUX_3_DC_0_DIV_MASK) >> MC_CGM_MUX_3_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC1_REF_CLK)
/* Return GMAC1_REF_CLK frequency */
static uint32 Clock_Ip_Get_GMAC1_REF_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_2->MUX_3_CSS & MC_CGM_2_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_2_MUX_3_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC1_REF_DIV_CLK)
/* Return GMAC1_REF_DIV_CLK frequency */
static uint32 Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfTableClockGeneration[((IP_MC_CGM_2->MUX_3_CSS & MC_CGM_2_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_2_MUX_3_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_2->MUX_3_DC_0 & MC_CGM_2_MUX_3_DC_0_DE_MASK) >> MC_CGM_2_MUX_3_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_2->MUX_3_DC_0 & MC_CGM_2_MUX_3_DC_0_DIV_MASK) >> MC_CGM_2_MUX_3_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_AURORA_TRACE_TEST_CLK)
/* Return AURORA_TRACE_TEST_CLK frequency */
static uint32 Clock_Ip_Get_AURORA_TRACE_TEST_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_AURORAPLL_DIFF_CLK)
/* Return AURORAPLL_DIFF_CLK frequency */
static uint32 Clock_Ip_Get_AURORAPLL_DIFF_CLK_Frequency(void) {
#ifdef IP_ATP_PLL
    const ATP_PLL_Type *Base = IP_ATP_PLL;
#else
    const ATP_Type *Base = IP_ATP;
#endif
    uint32 Frequency;

    Frequency = Clock_Ip_Get_AURORAPLL_CLK_Frequency();
    Frequency /= ((Base->FCW_NDIV_PDIV_CONFIG & ATP_FCW_NDIV_PDIV_CONFIG_PDIV_MASK) >> ATP_FCW_NDIV_PDIV_CONFIG_PDIV_SHIFT);                                    /*  Divider Pdiv */

    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC_1_INT_REF_CLK)
/* Return GMAC_1_INT_REF_CLK frequency */
static uint32 Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency(void) {

    uint32 Frequency;

    if (((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT) != (uint32)23U)
    {
        Frequency = Clock_Ip_Get_FIRC_CLK_Frequency();
    }
    else
    {
        Frequency = Clock_Ip_Get_PERIPHPLL_PHI5_Frequency();
    }
    Frequency  = Frequency /10U;
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC1_INT_CLK)
/* Return GMAC1_INT_CLK frequency */
static uint32 Clock_Ip_Get_GMAC1_INT_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfTableClockGeneration[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}
#endif

/* Return BBE32EP_DSP_CLK frequency */
static uint32 Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_1_CSS & MC_CGM_MUX_1_CSS_SELSTAT_MASK) >> MC_CGM_MUX_1_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[(IP_MC_ME->PRTN1_COFB0_STAT & MC_ME_PRTN1_COFB0_STAT_BLOCK0_MASK) >> MC_ME_PRTN1_COFB0_STAT_BLOCK0_SHIFT];
    return Frequency;
}

/* Return CAN_CHI_CLK frequency */
static uint32 Clock_Ip_Get_CAN_CHI_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_1 & MC_CGM_0_MUX_6_DC_1_DE_MASK) >> MC_CGM_0_MUX_6_DC_1_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_1 & MC_CGM_0_MUX_6_DC_1_DIV_MASK) >> MC_CGM_0_MUX_6_DC_1_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return CAN_TS_CLK frequency */
static uint32 Clock_Ip_Get_CAN_TS_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_0 & MC_CGM_0_MUX_6_DC_0_DE_MASK) >> MC_CGM_0_MUX_6_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_0 & MC_CGM_0_MUX_6_DC_0_DIV_MASK) >> MC_CGM_0_MUX_6_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return CAN_PE_CLK frequency */
static uint32 Clock_Ip_Get_CAN_PE_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_0_MUX_7_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_7_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

/* Return CLKOUT0_CLK frequency */
static uint32 Clock_Ip_Get_CLKOUT0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_1_CSS & MC_CGM_0_MUX_1_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_1_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_1_DC_0 & MC_CGM_0_MUX_1_DC_0_DE_MASK) >> MC_CGM_0_MUX_1_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_1_DC_0 & MC_CGM_0_MUX_1_DC_0_DIV_MASK) >> MC_CGM_0_MUX_1_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return CLKOUT1_CLK frequency */
static uint32 Clock_Ip_Get_CLKOUT1_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_2_CSS & MC_CGM_0_MUX_2_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_2_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_2_DC_0 & MC_CGM_0_MUX_2_DC_0_DE_MASK) >> MC_CGM_0_MUX_2_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_2_DC_0 & MC_CGM_0_MUX_2_DC_0_DIV_MASK) >> MC_CGM_0_MUX_2_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

#if defined(CLOCK_IP_HAS_CSI_CLK)
/* Return CSI_CLK frequency */
static uint32 Clock_Ip_Get_CSI_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_4_CSS & MC_CGM_MUX_4_CSS_SELSTAT_MASK) >> MC_CGM_MUX_4_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_CSI_CFG_CLK)
/* Return CSI_CFG_CLK frequency */
static uint32 Clock_Ip_Get_CSI_CFG_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_4_CSS & MC_CGM_MUX_4_CSS_SELSTAT_MASK) >> MC_CGM_MUX_4_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_1->MUX_4_DC_0 & MC_CGM_MUX_4_DC_0_DE_MASK) >> MC_CGM_MUX_4_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_1->MUX_4_DC_0 & MC_CGM_MUX_4_DC_0_DIV_MASK) >> MC_CGM_MUX_4_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_CTE_CLK)
/* Return CTE_CLK frequency */
static uint32 Clock_Ip_Get_CTE_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_3_CSS & MC_CGM_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_MUX_3_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_CSI_TXCLK_CLK)
/* Return CSI_TXCLK_CLK frequency */
static uint32 Clock_Ip_Get_CSI_TXCLK_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_4_CSS & MC_CGM_MUX_4_CSS_SELSTAT_MASK) >> MC_CGM_MUX_4_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_1->MUX_4_DC_1 & MC_CGM_MUX_4_DC_1_DE_MASK) >> MC_CGM_MUX_4_DC_1_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_1->MUX_4_DC_1 & MC_CGM_MUX_4_DC_1_DIV_MASK) >> MC_CGM_MUX_4_DC_1_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}
#endif

/* Return MC_CLK frequency */
static uint32 Clock_Ip_Get_MC_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_0_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_3_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

/* Return CTU_IPS_CLK frequency */
static uint32 Clock_Ip_Get_CTU_IPS_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_1 & MC_CGM_0_MUX_6_DC_1_DE_MASK) >> MC_CGM_0_MUX_6_DC_1_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_1 & MC_CGM_0_MUX_6_DC_1_DIV_MASK) >> MC_CGM_0_MUX_6_DC_1_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return DAPB_CLK frequency */
static uint32 Clock_Ip_Get_DAPB_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_4 & MC_CGM_0_MUX_6_DC_4_DE_MASK) >> MC_CGM_0_MUX_6_DC_4_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_4 & MC_CGM_0_MUX_6_DC_4_DIV_MASK) >> MC_CGM_0_MUX_6_DC_4_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return DSPI_SCK_TST_CLK frequency */
static uint32 Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_3 & MC_CGM_0_MUX_6_DC_3_DE_MASK) >> MC_CGM_0_MUX_6_DC_3_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_3 & MC_CGM_0_MUX_6_DC_3_DIV_MASK) >> MC_CGM_0_MUX_6_DC_3_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return FCCU_IPS_CLK frequency */
static uint32 Clock_Ip_Get_FCCU_IPS_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_1 & MC_CGM_0_MUX_6_DC_1_DE_MASK) >> MC_CGM_0_MUX_6_DC_1_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_1 & MC_CGM_0_MUX_6_DC_1_DIV_MASK) >> MC_CGM_0_MUX_6_DC_1_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return FTM0_EXT_CLK frequency */
static uint32 Clock_Ip_Get_FTM0_EXT_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_3->MUX_0_CSS & MC_CGM_MUX_0_CSS_SELSTAT_MASK) >> MC_CGM_MUX_0_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_3->MUX_0_DC_0 & MC_CGM_MUX_0_DC_0_DE_MASK) >> MC_CGM_MUX_0_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->MUX_0_DC_0 & MC_CGM_MUX_0_DC_0_DIV_MASK) >> MC_CGM_MUX_0_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return GMAC0_RX_CLK frequency */
static uint32 Clock_Ip_Get_GMAC0_RX_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_3->MUX_4_CSS & MC_CGM_MUX_4_CSS_SELSTAT_MASK) >> MC_CGM_MUX_4_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

/* Return GMAC0_TS_CLK frequency */
static uint32 Clock_Ip_Get_GMAC0_TS_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_3->MUX_1_CSS & MC_CGM_MUX_1_CSS_SELSTAT_MASK) >> MC_CGM_MUX_1_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_3->MUX_1_DC_0 & MC_CGM_MUX_1_DC_0_DE_MASK) >> MC_CGM_MUX_1_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->MUX_1_DC_0 & MC_CGM_MUX_1_DC_0_DIV_MASK) >> MC_CGM_MUX_1_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return GMAC0_TX_CLK frequency */
static uint32 Clock_Ip_Get_GMAC0_TX_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_3->MUX_2_CSS & MC_CGM_MUX_2_CSS_SELSTAT_MASK) >> MC_CGM_MUX_2_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

#if defined(CLOCK_IP_HAS_GMAC1_RX_CLK)
/* Return GMAC1_RX_CLK frequency */
static uint32 Clock_Ip_Get_GMAC1_RX_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_2->MUX_4_CSS & MC_CGM_2_MUX_4_CSS_SELSTAT_MASK) >> MC_CGM_2_MUX_4_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC1_TS_CLK)
/* Return GMAC1_TS_CLK frequency */
static uint32 Clock_Ip_Get_GMAC1_TS_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_2->MUX_1_CSS & MC_CGM_MUX_1_CSS_SELSTAT_MASK) >> MC_CGM_MUX_1_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_2->MUX_1_DC_0 & MC_CGM_MUX_1_DC_0_DE_MASK) >> MC_CGM_MUX_1_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_2->MUX_1_DC_0 & MC_CGM_MUX_1_DC_0_DIV_MASK) >> MC_CGM_MUX_1_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GMAC1_TX_CLK)
/* Return GMAC1_TX_CLK frequency */
static uint32 Clock_Ip_Get_GMAC1_TX_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_2->MUX_2_CSS & MC_CGM_2_MUX_2_CSS_SELSTAT_MASK) >> MC_CGM_2_MUX_2_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_2->MUX_2_DC_0 & MC_CGM_2_MUX_2_DC_0_DE_MASK) >> MC_CGM_2_MUX_2_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_2->MUX_2_DC_0 & MC_CGM_2_MUX_2_DC_0_DIV_MASK) >> MC_CGM_2_MUX_2_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}
#endif

/* Return LBIST_CLK frequency */
static uint32 Clock_Ip_Get_LBIST_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_6_CSS & MC_CGM_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_1->MUX_6_DC_0 & MC_CGM_MUX_6_DC_0_DE_MASK) >> MC_CGM_MUX_6_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_1->MUX_6_DC_0 & MC_CGM_MUX_6_DC_0_DIV_MASK) >> MC_CGM_MUX_6_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return LIN_BAUD_CLK frequency */
static uint32 Clock_Ip_Get_LIN_BAUD_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_0_MUX_8_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_8_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

/* Return LINFLEXD_CLK frequency */
static uint32 Clock_Ip_Get_LINFLEXD_CLK_Frequency(void) {

    return Clock_Ip_Get_LIN_BAUD_CLK_Frequency() >> 1U;
}

#if defined(CLOCK_IP_HAS_MIPICSI2_0_CLK)
/* Return MIPICSI2_0_CLK frequency */
static uint32 Clock_Ip_Get_MIPICSI2_0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_3_CSS & MC_CGM_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_MUX_3_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[(IP_MC_ME->PRTN1_COFB0_STAT & MC_ME_PRTN1_COFB0_STAT_BLOCK2_MASK) >> MC_ME_PRTN1_COFB0_STAT_BLOCK2_SHIFT];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_MIPICSI2_1_CLK)
/* Return MIPICSI2_1_CLK frequency */
static uint32 Clock_Ip_Get_MIPICSI2_1_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_3_CSS & MC_CGM_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_MUX_3_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[(IP_MC_ME->PRTN1_COFB0_STAT & MC_ME_PRTN1_COFB0_STAT_BLOCK2_MASK) >> MC_ME_PRTN1_COFB0_STAT_BLOCK2_SHIFT];

    return Frequency;
}
#endif

/* Return NOC_TRACE_CLK frequency */
static uint32 Clock_Ip_Get_NOC_TRACE_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_5_CSS & MC_CGM_MUX_5_CSS_SELSTAT_MASK) >> MC_CGM_MUX_5_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

/* Return QSPI_2X_CLK frequency */
static uint32 Clock_Ip_Get_QSPI_2X_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_0_MUX_5_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_5_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_5_DC_0 & MC_CGM_0_MUX_5_DC_0_DE_MASK) >> MC_CGM_0_MUX_5_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_5_DC_0 & MC_CGM_0_MUX_5_DC_0_DIV_MASK) >> MC_CGM_0_MUX_5_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return Clock_Ip_Get_QSPI_1X_CLK frequency */
static uint32 Clock_Ip_Get_QSPI_1X_CLK_Frequency(void) {

    return Clock_Ip_Get_QSPI_2X_CLK_Frequency() >> 1U;
}

/* Return QSPI0_CLK frequency */
static uint32 Clock_Ip_Get_QSPI0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_0_MUX_5_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_5_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_5_DC_0 & MC_CGM_0_MUX_5_DC_0_DE_MASK) >> MC_CGM_0_MUX_5_DC_0_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_5_DC_0 & MC_CGM_0_MUX_5_DC_0_DIV_MASK) >> MC_CGM_0_MUX_5_DC_0_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return SPI_CLK frequency */
static uint32 Clock_Ip_Get_SPI_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_0_MUX_4_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_4_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    return Frequency;
}

#if defined(CLOCK_IP_HAS_SPT_CLK)
/* Return SPT_CLK frequency */
static uint32 Clock_Ip_Get_SPT_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_1_CSS & MC_CGM_MUX_1_CSS_SELSTAT_MASK) >> MC_CGM_MUX_1_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[(IP_MC_ME->PRTN1_COFB0_STAT & MC_ME_PRTN1_COFB0_STAT_BLOCK1_MASK) >> MC_ME_PRTN1_COFB0_STAT_BLOCK1_SHIFT];
    return Frequency;
}
#endif

/* Return STCU_CLK frequency */
static uint32 Clock_Ip_Get_STCU_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_4 & MC_CGM_0_MUX_6_DC_4_DE_MASK) >> MC_CGM_0_MUX_6_DC_4_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_4 & MC_CGM_0_MUX_6_DC_4_DIV_MASK) >> MC_CGM_0_MUX_6_DC_4_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return TMU_CLK frequency */
static uint32 Clock_Ip_Get_TMU_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_1 & MC_CGM_0_MUX_6_DC_1_DE_MASK) >> MC_CGM_0_MUX_6_DC_1_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_1 & MC_CGM_0_MUX_6_DC_1_DIV_MASK) >> MC_CGM_0_MUX_6_DC_1_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return TCLK_CLK frequency */
static uint32 Clock_Ip_Get_TCLK_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_0_MUX_6_CSS_SELSTAT_SHIFT)]();/*  Selector value */
    Frequency &= Clock_Ip_u32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_2 & MC_CGM_0_MUX_6_DC_2_DE_MASK) >> MC_CGM_0_MUX_6_DC_2_DE_SHIFT)];                    /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_2 & MC_CGM_0_MUX_6_DC_2_DIV_MASK) >> MC_CGM_0_MUX_6_DC_2_DIV_SHIFT) + 1U);                          /*  Apply divider value */
    return Frequency;
}

/* Return PLL_VCO_CLK frequency */
static uint32 Clock_Ip_PLL_VCO(const PLLDIG_Type *Base)
{
    uint32 Fin = 0;
    uint32 Fout;
#ifdef PLLDIG_PLLCLKMUX_REFCLKSEL_MASK
    uint32 Rdiv;
    uint32 Mfi;
    uint32 Mfn;
    uint32 Var1;
    uint32 Var2;
    uint32 Var3;
    uint32 Var4;
    uint32 Var5;
#endif

    if ((Base->PLLCR & PLLDIG_PLLCR_PLLPD_MASK) == 0U)   /* if PLL is enabled */
    {
#ifdef PLLDIG_PLLCLKMUX_REFCLKSEL_MASK
        Fin  = (((Base->PLLCLKMUX & PLLDIG_PLLCLKMUX_REFCLKSEL_MASK) >> PLLDIG_PLLCLKMUX_REFCLKSEL_SHIFT) == 0U) ? Clock_Ip_Get_FIRC_CLK_Frequency() : Clock_Ip_Get_FXOSC_CLK_Frequency();   /* input freq */
        Rdiv = ((Base->PLLDV & PLLDIG_PLLDV_RDIV_MASK) >> PLLDIG_PLLDV_RDIV_SHIFT);              /* Rdiv */
        Mfi  = ((Base->PLLDV & PLLDIG_PLLDV_MFI_MASK) >> PLLDIG_PLLDV_MFI_SHIFT);                /* Mfi */
        if(IP_PERIPH_PLL == Base)
        {
            Mfn  = 0U;                                                                               /* Mfn */
        }
        else
        {
            Mfn  = ((Base->PLLFD & PLLDIG_PLLFD_MFN_MASK) >> PLLDIG_PLLFD_MFN_SHIFT);                /* Mfn */
        }


        Var1 = Mfi / Rdiv;                                      /* Mfi divided by Rdiv */
        Var2 = Mfi - (Var1 * Rdiv);                             /* Mfi minus Var1 multiplied by Rdiv */
        Var3 = (Rdiv << CLOCK_IP_MUL_BY_16384) + (Rdiv << CLOCK_IP_MUL_BY_2048);  /* Rdiv multiplied by 18432 */
        Var4 = Fin / Var3;                                      /* Fin divide by (Rdiv multiplied by 18432) */
        Var5 = Fin - (Var4 * Var3);                               /* Fin minus Var4 multiplied by (Rdiv mul 18432) */

        Fout = Var1 * Fin;                                      /* Var1 multipied by Fin */
        Fout += Fin / Rdiv * Var2;                                /* Fin divided by Rdiv and multiplied by Var2 */
        Fout += Var4 * Mfn;                                     /* Mfn multiplied by Var4 */
        Fout += Var5 * Mfn / Var3;                              /* Var5 multiplied by Mfn and divide by (Rdiv mul 18432) */
#else
        switch((Base->CLKMUX & PLLDIG_CLKMUX_RCLKSEL_MASK) >> PLLDIG_CLKMUX_RCLKSEL_SHIFT)
        {
            case 1U:
                /* Select input reference. */
                Fin  = Clock_Ip_Get_FXOSC_CLK_Frequency();
                break;
            case 2U:
                /* Select input reference. */
                Fin  = Clock_Ip_Get_rfe_pll_clk_Frequency();
                break;
            case 3U:
                /* Select input reference. */
#if defined(CLOCK_IP_HAS_AURORAPLL_PHI1_CLK)
                Fin  = Clock_Ip_Get_AURORAPLL_PHI1_Frequency();
#elif defined(CLOCK_IP_HAS_AURORAPLL_PHI0_CLK)
                Fin  = Clock_Ip_Get_AURORAPLL_PHI0_Frequency();
#endif
                break;
            default:
                /* Select input reference. */
                Fin  = Clock_Ip_Get_firc_muxed_clk_Frequency();
                break;
        }
        Fout = Fin;
#endif
    }
    else
    {
        Fout = 0U;
    }

    return Fout;
}



#if (defined(IP_ATP) || defined(IP_ATP_PLL))
/* Return PLL_DCO_CLK frequency */
static uint32 Clock_Ip_PLL_DCO(void)
{
#ifdef IP_ATP_PLL
    const ATP_PLL_Type *Base = IP_ATP_PLL;
#else
    const ATP_Type *Base = IP_ATP;
#endif
    uint32 Fin = 0;
    uint32 Ndiv;
    uint32 Fcw;
    uint32 Fout;

    Ndiv = ((Base->FCW_NDIV_PDIV_CONFIG & ATP_FCW_NDIV_PDIV_CONFIG_NDIV_MASK) >> ATP_FCW_NDIV_PDIV_CONFIG_NDIV_SHIFT) + 1U;      /* Ndiv */
    Fcw = ((Base->FCW_NDIV_PDIV_CONFIG & ATP_FCW_NDIV_PDIV_CONFIG_FCW_MASK) >> ATP_FCW_NDIV_PDIV_CONFIG_FCW_SHIFT);              /* Fcw */

    switch((Base->CLKMUX & ATP_CLKMUX_RCLKSEL_MASK) >> ATP_CLKMUX_RCLKSEL_SHIFT)
    {
        case 0U:
            /* Select input reference. */
            Fin  = Clock_Ip_Get_lvds_clk_Frequency();
            break;
        case 1U:
            /* Select input reference. */
            Fin  = Clock_Ip_Get_FXOSC_CLK_Frequency();
            break;
        case 2U:
            /* Select input reference. */
            Fin  = Clock_Ip_Get_FIRC_CLK_Frequency();
            break;
        default:
            /* Command is not implemented on this platform */
            break;
    }

    /* Div by 1000 to avoid overflow when Fin is 40Mhz and Fcw is 125 */
    Fin = Fin / 1000U;

    if (0U != Fin)
    {
        if ( Fcw == ((uint32)(Fcw * Fin) / Fin) )           /* Checking overflow */
        {
            Fout = (Fcw * Fin) / Ndiv;                              /* Fin divided by Ndiv and multiplied by Fcw */
        }
        else
        {
            Fout = 0U;
        }
    }
    else
    {
        Fout = 0U;
    }

    if (Fout == ((uint32)(Fout * 1000U) / 1000U))
    {
        Fout = Fout * 1000U;
    }
    else
    {
        Fout = 0U;
    }

    return Fout;
}
#endif

#ifdef IP_PERIPH_DFS
static uint32 Clock_Ip_DFS_OUTPUT(const DFS_Type *Base, uint32 Channel, uint32 Fin)
{
    uint32 Mfi;
    uint32 Mfn;
    uint32 Divider;
    uint32 DividerResult;
    uint32 DividerModulo;

    Mfi = ((Base->DVPORT[Channel] & DFS_DVPORT_MFI_MASK) >> DFS_DVPORT_MFI_SHIFT);              /* Mfi */
    Mfn = ((Base->DVPORT[Channel] & DFS_DVPORT_MFN_MASK) >> DFS_DVPORT_MFN_SHIFT);              /* Mfn */

    Divider = ((Mfi << CLOCK_IP_MUL_BY_32) + (Mfi << CLOCK_IP_MUL_BY_4) + Mfn);               /* Mfi multiplied by 36 add Mfn */
    DividerResult = (Divider != 0U) ? (Fin / Divider) : 0U;                 /* Fin divide by Divider */
    DividerModulo = Fin - (Divider * DividerResult);                        /* Fin minus DividerResult multiplied by Divider */

    /* DividerResult multiplied by 18 added DividerModulo multiplied by 18 divide by Divider */
    return (Divider != 0U) ? ((DividerResult << CLOCK_IP_MUL_BY_16) + (DividerResult << CLOCK_IP_MUL_BY_2) +
                                        (((DividerModulo << CLOCK_IP_MUL_BY_16) + (DividerModulo << CLOCK_IP_MUL_BY_2)) / Divider)) : 0U;
}
#endif

/* Get external frequency */
void Clock_Ip_SetExternalOscillatorFrequency(Clock_Ip_NameType ExtOscName, uint32 Frequency)
{
    (void)ExtOscName;
    Clock_Ip_u32Fxosc = Frequency;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/* Return frequency value */
uint32 Clock_Ip_GetFreq(Clock_Ip_NameType ClockName)
{
    return Clock_Ip_apfFreqTable[ClockName]();
}

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#endif  /* #if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON)) */

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/* Set external frequency */
void Clock_Ip_SetExternalSignalFrequency(Clock_Ip_NameType SignalName, uint32 Frequency)
{
#if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON))
    uint32 Index;
    for (Index = 0U; Index < CLOCK_IP_EXT_SIGNALS_NO; Index++)
    {
        if (SignalName == Clock_Ip_axExtSignalFreqEntries[Index].Name)
        {
            Clock_Ip_axExtSignalFreqEntries[Index].Frequency = Frequency;
            break;
        }
    }
#else
    (void)SignalName;
    (void)Frequency;
#endif
}

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
