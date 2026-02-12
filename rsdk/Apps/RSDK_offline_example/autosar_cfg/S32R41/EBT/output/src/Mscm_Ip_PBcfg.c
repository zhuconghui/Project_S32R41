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
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_D2402_ASR_REL_4_7_REV_0000_20240221
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
*   @file Mscm_Ip_PBcfg.c
*
*   @addtogroup MSCM_IP MSCM IPV Driver
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
#include "Mscm_Ip_Types.h"
#include "Mscm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_PBCFG_VENDOR_ID_C                     43
#define RM_MSCM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_MSCM_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define RM_MSCM_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_MSCM_IP_PBCFG_SW_MAJOR_VERSION_C              2
#define RM_MSCM_IP_PBCFG_SW_MINOR_VERSION_C              0
#define RM_MSCM_IP_PBCFG_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mscm_Ip_Types.h */
#if (RM_MSCM_IP_PBCFG_VENDOR_ID_C != RM_MSCM_IP_TYPES_VENDOR_ID)
    #error "Mscm_Ip_PBcfg.c and Mscm_Ip_Types.h have different vendor ids"
#endif
#if ((RM_MSCM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_MSCM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MSCM_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_MSCM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_MSCM_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_MSCM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mscm_Ip_PBcfg.c and Mscm_Ip_Types.h are different"
#endif
#if ((RM_MSCM_IP_PBCFG_SW_MAJOR_VERSION_C != RM_MSCM_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_PBCFG_SW_MINOR_VERSION_C != RM_MSCM_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_PBCFG_SW_PATCH_VERSION_C != RM_MSCM_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mscm_Ip_PBcfg.c and Mscm_Ip_Types.h are different"
#endif

/* Checks against Mscm_Ip_Cfg.h */
#if (RM_MSCM_IP_PBCFG_VENDOR_ID_C != RM_MSCM_IP_CFG_VENDOR_ID)
    #error "Mscm_Ip_PBcfg.c and Mscm_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_MSCM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_MSCM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MSCM_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_MSCM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_MSCM_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_MSCM_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mscm_Ip_PBcfg.c and Mscm_Ip_Cfg.h are different"
#endif
#if ((RM_MSCM_IP_PBCFG_SW_MAJOR_VERSION_C != RM_MSCM_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_PBCFG_SW_MINOR_VERSION_C != RM_MSCM_IP_CFG_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_PBCFG_SW_PATCH_VERSION_C != RM_MSCM_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mscm_Ip_PBcfg.c and Mscm_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"




static const Mscm_Ip_IrqRouteConfigType IrqRouteConfig[79] =
{
    {MSCM_MSCM_Pcie_1_MSI_IRQn, 15U},
    {MSCM_MSCM_INT0_IRQn, 15U},
    {MSCM_MSCM_INT1_IRQn, 15U},
    {MSCM_MSCM_INT2_IRQn, 15U},
    {MSCM_MSCM_INT3_IRQn, 15U},
    {MSCM_MSCM_CTI_0_IRQn, 15U},
    {MSCM_MSCM_CTI_1_IRQn, 15U},
    {MSCM_MCM_IRQn, 15U},
    {MSCM_DMA0_0_15_IRQn, 15U},
    {MSCM_DMA0_16_31_IRQn, 15U},
    {MSCM_DMA0_ERR0_IRQn, 15U},
    {MSCM_SWT0_IRQn, 15U},
    {MSCM_SWT1_IRQn, 15U},
    {MSCM_SWT2_IRQn, 15U},
    {MSCM_XRDC0_ERR0_IRQn, 15U},
    {MSCM_XRDC1_ERR1_IRQn, 15U},
    {MSCM_STM0_IRQn, 15U},
    {MSCM_STM1_IRQn, 15U},
    {MSCM_STM2_IRQn, 15U},
    {MSCM_QSPI0_IRQn, 15U},
    {MSCM_QSPI1_IRQn, 15U},
    {MSCM_STCU2_LBIST_MBIST_IRQn, 15U},
    {MSCM_CAN0_ORED_0_7_MB_IRQn, 15U},
    {MSCM_CAN0_ORED_8_95_MB_IRQn, 15U},
    {MSCM_CAN1_ERR_IRQn, 15U},
    {MSCM_CAN1_ORED_0_7_MB_IRQn, 15U},
    {MSCM_CAN1_ORED_8_95_MB_IRQn, 15U},
    {MSCM_PIT0_IRQn, 15U},
    {MSCM_CMU1_IRQn, 15U},
    {MSCM_FTM0_IRQn, 15U},
    {MSCM_GMAC0_Common_IRQn, 15U},
    {MSCM_GMAC0_CH0_TX_IRQn, 15U},
    {MSCM_GMAC0_CH0_RX_IRQn, 15U},
    {MSCM_GMAC0_CH1_TX_IRQn, 15U},
    {MSCM_GMAC0_CH1_RX_IRQn, 15U},
    {MSCM_SAR_ADC0_INT_IRQn, 15U},
    {MSCM_LINFLEXD0_IRQn, 15U},
    {MSCM_SPI0_IRQn, 15U},
    {MSCM_SPI1_IRQn, 15U},
    {MSCM_SPI2_IRQn, 15U},
    {MSCM_SPI3_IRQn, 15U},
    {MSCM_I2C0_IRQn, 15U},
    {MSCM_I2C1_IRQn, 15U},
    {MSCM_MC_RGM_IRQn, 15U},
    {MSCM_FCCU_ALARM_IRQn, 15U},
    {MSCM_FCCU_MISC_IRQn, 15U},
    {MSCM_HSE_MU0_TX_IRQn, 15U},
    {MSCM_HSE_MU0_RX_IRQn, 15U},
    {MSCM_HSE_MU0_ORED_IRQn, 15U},
    {MSCM_HSE_MU1_TX_IRQn, 15U},
    {MSCM_HSE_MU1_RX_IRQn, 15U},
    {MSCM_HSE_MU1_ORED_IRQn, 15U},
    {MSCM_CTU_FIFO_FULL_EMPTY_IRQn, 15U},
    {MSCM_CTU_M_RELOAD_IRQn, 15U},
    {MSCM_CTU_ERR_IRQn, 15U},
    {MSCM_TMU_ALARM_IRQn, 15U},
    {MSCM_TMU_CRIT_ALARM_IRQn, 15U},
    {MSCM_CORTEX_A53_ERR_L2RAM_CLUSTER0_IRQn, 15U},
    {MSCM_CORTEX_A53_ERR_AXI_CLUSTER0_IRQn, 15U},
    {MSCM_JDC_IRQn, 15U},
    {MSCM_MIPICSI2_0_INT0_IRQn, 15U},
    {MSCM_MIPICSI2_0_INT1_IRQn, 15U},
    {MSCM_MIPICSI2_0_INT2_IRQn, 15U},
    {MSCM_MIPICSI2_1_INT0_IRQn, 15U},
    {MSCM_MIPICSI2_1_INT1_IRQn, 15U},
    {MSCM_MIPICSI2_1_INT2_IRQn, 15U},
    {MSCM_SWT3_IRQn, 15U},
    {MSCM_CTE_IRQn, 15U},
    {MSCM_SPT_DSP_ERR_IRQn, 15U},
    {MSCM_SPT_EVENT_IRQn, 15U},
    {MSCM_SPT_ECS_IRQn, 15U},
    {MSCM_SPT_DMA_COMPL_IRQn, 15U},
    {MSCM_PIT2_IRQn, 15U},
    {MSCM_GMAC1_Common_IRQn, 15U},
    {MSCM_GMAC1_CH0_TX_IRQn, 15U},
    {MSCM_GMAC1_CH0_RX_IRQn, 15U},
    {MSCM_GMAC1_CH1_TX_IRQn, 15U},
    {MSCM_GMAC1_CH1_RX_IRQn, 15U},
    {MSCM_SIUL2_INT_IRQn, 15U}

};
const Mscm_Ip_ConfigType Mscm_Config =
{
    (uint32)79U,
    IrqRouteConfig
};


#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

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

