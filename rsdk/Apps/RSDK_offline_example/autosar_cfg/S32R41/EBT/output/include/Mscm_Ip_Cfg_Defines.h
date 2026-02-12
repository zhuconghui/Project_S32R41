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

#ifndef MSCM_IP_CFG_DEFINES_H
#define MSCM_IP_CFG_DEFINES_H

/**
*   @file Mscm_Ip_Cfg_Defines.h
*
*   @addtogroup MSCM_IP MSCM IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
/**
 * Include specific header file
 */
#include "StandardTypes.h"
#include "S32R41_MSCM.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_CFG_DEFINES_VENDOR_ID                          43
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0
#define RM_MSCM_IP_CFG_DEFINES_SW_MAJOR_VERSION                   2
#define RM_MSCM_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define RM_MSCM_IP_CFG_DEFINES_SW_PATCH_VERSION                   0

/*==================================================================================================
*                                   FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against StandardTypes.h */
#if ((RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mscm_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief    Core Mask to write MSCM Register */
#define MSCM_IP_CORE_MASK                           (15U)
/** @brief    Development error checking */
#define MSCM_IP_DEV_ERROR_DETECT                    (STD_ON)



/** @brief        Last implemented interrupt routing */
#define MSCM_IP_SPI_MAX                             (237U)
/** @brief        Number of SPI Routing Support */
#define MSCM_IP_SPI_COUNT                           (85U)

/** @brief        SPI Number Configuration */
#define MSCM_MSCM_Pcie_1_MSI_IRQn                                    (0U)
#define MSCM_MSCM_INT0_IRQn                                          (1U)
#define MSCM_MSCM_INT1_IRQn                                          (2U)
#define MSCM_MSCM_INT2_IRQn                                          (3U)
#define MSCM_MSCM_INT3_IRQn                                          (4U)
#define MSCM_MSCM_CTI_0_IRQn                                         (5U)
#define MSCM_MSCM_CTI_1_IRQn                                         (6U)
#define MSCM_MCM_IRQn                                                (7U)
#define MSCM_DMA0_0_15_IRQn                                          (8U)
#define MSCM_DMA0_16_31_IRQn                                         (9U)
#define MSCM_DMA0_ERR0_IRQn                                          (10U)
#define MSCM_SWT0_IRQn                                               (14U)
#define MSCM_SWT1_IRQn                                               (15U)
#define MSCM_SWT2_IRQn                                               (16U)
#define MSCM_XRDC0_ERR0_IRQn                                         (20U)
#define MSCM_XRDC1_ERR1_IRQn                                         (21U)
#define MSCM_STM0_IRQn                                               (24U)
#define MSCM_STM1_IRQn                                               (25U)
#define MSCM_STM2_IRQn                                               (26U)
#define MSCM_QSPI0_IRQn                                              (32U)
#define MSCM_QSPI1_IRQn                                              (33U)
#define MSCM_STCU2_LBIST_MBIST_IRQn                                  (35U)
#define MSCM_CAN0_OFF_IRQn                                           (37U)
#define MSCM_CAN0_ERR_IRQn                                           (38U)
#define MSCM_CAN0_ORED_0_7_MB_IRQn                                   (39U)
#define MSCM_CAN0_ORED_8_95_MB_IRQn                                  (40U)
#define MSCM_CAN1_OFF_IRQn                                           (41U)
#define MSCM_CAN1_ERR_IRQn                                           (42U)
#define MSCM_CAN1_ORED_0_7_MB_IRQn                                   (43U)
#define MSCM_CAN1_ORED_8_95_MB_IRQn                                  (44U)
#define MSCM_PIT0_IRQn                                               (53U)
#define MSCM_CMU1_IRQn                                               (54U)
#define MSCM_FTM0_IRQn                                               (55U)
#define MSCM_CMU12_IRQn                                              (56U)
#define MSCM_GMAC0_Common_IRQn                                       (57U)
#define MSCM_GMAC0_CH0_TX_IRQn                                       (58U)
#define MSCM_GMAC0_CH0_RX_IRQn                                       (59U)
#define MSCM_GMAC0_CH1_TX_IRQn                                       (60U)
#define MSCM_GMAC0_CH1_RX_IRQn                                       (61U)
#define MSCM_SAR_ADC0_INT_IRQn                                       (70U)
#define MSCM_LINFLEXD0_IRQn                                          (82U)
#define MSCM_SPI0_IRQn                                               (85U)
#define MSCM_SPI1_IRQn                                               (86U)
#define MSCM_SPI2_IRQn                                               (87U)
#define MSCM_SPI3_IRQn                                               (88U)
#define MSCM_I2C0_IRQn                                               (92U)
#define MSCM_I2C1_IRQn                                               (93U)
#define MSCM_MC_RGM_IRQn                                             (98U)
#define MSCM_FCCU_ALARM_IRQn                                         (100U)
#define MSCM_FCCU_MISC_IRQn                                          (101U)
#define MSCM_HSE_MU0_TX_IRQn                                         (103U)
#define MSCM_HSE_MU0_RX_IRQn                                         (104U)
#define MSCM_HSE_MU0_ORED_IRQn                                       (105U)
#define MSCM_HSE_MU1_TX_IRQn                                         (106U)
#define MSCM_HSE_MU1_RX_IRQn                                         (107U)
#define MSCM_HSE_MU1_ORED_IRQn                                       (108U)
#define MSCM_HSE_TAMP_IRQn                                           (109U)
#define MSCM_CTU_FIFO_FULL_EMPTY_IRQn                                (117U)
#define MSCM_CTU_M_RELOAD_IRQn                                       (118U)
#define MSCM_CTU_ERR_IRQn                                            (119U)
#define MSCM_TMU_ALARM_IRQn                                          (120U)
#define MSCM_TMU_CRIT_ALARM_IRQn                                     (121U)
#define MSCM_CORTEX_A53_ERR_L2RAM_CLUSTER0_IRQn                      (151U)
#define MSCM_CORTEX_A53_ERR_AXI_CLUSTER0_IRQn                        (152U)
#define MSCM_JDC_IRQn                                                (155U)
#define MSCM_MIPICSI2_1_INT0_IRQn                                    (172U)
#define MSCM_MIPICSI2_1_INT1_IRQn                                    (173U)
#define MSCM_MIPICSI2_1_INT2_IRQn                                    (174U)
#define MSCM_MIPICSI2_0_INT0_IRQn                                    (178U)
#define MSCM_MIPICSI2_0_INT1_IRQn                                    (179U)
#define MSCM_MIPICSI2_0_INT2_IRQn                                    (180U)
#define MSCM_SPT_DSP_ARTH_IRQn                                       (185U)
#define MSCM_SWT3_IRQn                                               (186U)
#define MSCM_CTE_IRQn                                                (187U)
#define MSCM_SPT_DSP_ERR_IRQn                                        (188U)
#define MSCM_SPT_EVENT_IRQn                                          (189U)
#define MSCM_SPT_ECS_IRQn                                            (190U)
#define MSCM_SPT_DMA_COMPL_IRQn                                      (191U)
#define MSCM_PIT2_IRQn                                               (192U)
#define MSCM_GMAC1_Common_IRQn                                       (220U)
#define MSCM_GMAC1_CH0_TX_IRQn                                       (221U)
#define MSCM_GMAC1_CH0_RX_IRQn                                       (222U)
#define MSCM_GMAC1_CH1_TX_IRQn                                       (223U)
#define MSCM_GMAC1_CH1_RX_IRQn                                       (224U)
#define MSCM_SIUL2_INT_IRQn                                          (237U)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MSCM_IP_CFG_DEFINES_H */

