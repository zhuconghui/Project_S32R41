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

#ifndef INTCTRL_IP_CFG_DEFINES_H_
#define INTCTRL_IP_CFG_DEFINES_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_VENDOR_ID                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_MAJOR_VERSION                   2
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_PATCH_VERSION                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/* CPU to CPU interrupt (MSI) routing through MSCM */
#define INT_CTRL_IP_MSI_AVAILABLE                 (STD_ON)
    #include "S32R41.h"
    #include "S32R41_NVIC.h"
    #include "S32R41_MSCM.h"
    #include "S32R41_SCB.h"
    #define INT_CTRL_CORE_SPECIFIC_VTABLE (STD_OFF)
    #if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
    typedef struct {
        __IO uint32_t IntStatusR;  /**< Interrupt Router CPn Interruptx Status Register; array offset: 0x200; index*0x20; index2*0x8 */
        __O  uint32_t IGR;  /**< Interrupt Router CPn Interruptx Generation Register; array offset: 0x204; index*0x20; index2*0x8 */
    } MSCM_IRCP_IR_Type;

    typedef struct {
        MSCM_IRCP_IR_Type IRCPnIRx[4][4];
    } MSCM_IRCPnIRx_Type;

    #define MSCM_IRCPnIRx ((volatile MSCM_IRCPnIRx_Type*)&IP_MSCM->IRCP0ISR0)
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Development error detection */
#define INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER  (STD_OFF)
#define INT_CTRL_IP_DEV_ERROR_DETECT              (STD_ON)
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)

/* MSI target core count */
#define INT_CTRL_IP_MSI_CORE_CNT                   (3U)

/* MSI vector min */
#define INT_CTRL_IP_DIRECTED_CPU_INT_MIN           (MSCM_INT0_IRQn)

/* MSI vector max */
#define INT_CTRL_IP_DIRECTED_CPU_INT_MAX           (MSCM_Pcie_0_MSI_IRQn)
#endif
/* IP standalone APIs  */
#define INT_CTRL_IP_STANDALONE_APIS               (STD_ON)


/* VTOR address configuration enable */
#define INT_CTRL_IP_ENABLE_VTOR_CONFIG             (STD_OFF)

/* Number of nvic priority bits implemented */
#define INT_CTRL_IP_NVIC_PRIO_BITS                (4U)
/* Number of gic priority bits implemented */
#define INT_CTRL_IP_GIC_PRIO_BITS                (5U)
/* User mode support */
#define INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT (STD_OFF)

/*Interrupt Router Shared Peripheral Routing Control Register*/
#define INT_CTRL_IP_ROUTING_CONTROL_REGISTER      (STD_ON)
/* This instruction invalidates the entire instruction cache or caches */
#define INT_CTRL_IP_INVALIDATE_CACHE              (STD_OFF)

/* First implemented interrupt vector */
#define INT_CTRL_IP_IRQ_MIN                       (MSCM_INT0_IRQn)
/* Last implemented interrupt vector */
#define INT_CTRL_IP_IRQ_MAX                       (SIUL2_INT_IRQn)
/* The interrupt counter value*/
#define INT_CTRL_IP_IRQ_COUNT                     (84)
/* Arm Cortex R */
#define INT_CTRL_IP_CORTEXR                       (STD_OFF)
/* Arm Cortex M */
#define INT_CTRL_IP_CORTEXM                       (STD_ON)
#define INT_CTRL_IP_CORTEXM0PLUS                  (STD_OFF)
/* Arm Cortex A */
#define INT_CTRL_IP_CORTEXA                       (STD_OFF)

#endif /* INTCTRL_IP_CFG_DEFINES_H_ */

