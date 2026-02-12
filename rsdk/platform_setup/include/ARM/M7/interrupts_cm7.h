/*
 * Copyright 2019-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

/**************************************************************************************************
 @file		interrupts_cm7.h
 @author	NXP

 @brief		Interrupt vector table and NVIC helper functions
**************************************************************************************************/

#ifndef INTERRUPTS_CM7_H_
#define INTERRUPTS_CM7_H_

/**************************************************************************************************
 Includes
**************************************************************************************************/
#include "ARMCM7_SP.h"  // CMSIS Cortex-M7 Core Peripheral Access Layer Header File

#if defined(RSDK_AUTOSAR)
#include "Std_Types.h"
#else
#include "typedefs.h"
#endif

#if !defined(SAF85XX)
//#include "interrupts_cm7_irq_num.h"
#include "rsdk_glue_irq_register_api.h"
#endif

#include "rsdk_status.h"

/**************************************************************************************************
 Constants and Macros
**************************************************************************************************/
#define CM7_NUM_EXCEPTIONS 16									// Core exception handlers
#define CM7_NUM_IRQS 	   240									// Interrupt requests
#define CM7_NUM_VECTORS    CM7_NUM_EXCEPTIONS + CM7_NUM_IRQS	// Total entries in vector table

#define RSDK_MAX_EXT_IRQ_NUM (CM7_NUM_IRQS)  // The maximum IRQ number assigned for SoC (JTAGM)
/**************************************************************************************************
 User-defined Types
**************************************************************************************************/
/* Exception / Interrupt Handler Function Prototype */
typedef void( *pFunc )( void );

#if defined(SAF85XX)
/** @brief Core number identifiers.
*
*/
typedef enum
{
    RSDK_CURRENT_CORE = -1, /**< current processing core */
    RSDK_CORE_0 = 0,        /**< main core (Z4 for S32R274, A53 #0 in cluster 0 for S32R45)*/
    RSDK_CORE_1,
    RSDK_CORE_2,
#if defined(S32R45)
    RSDK_CORE_3,
#endif
    RSDK_MAX_COREID
} rsdkCoreId_t;
#endif

/**************************************************************************************************
 Global Function Prototypes
**************************************************************************************************/
rsdkStatus_t interrupts_cm7_enable(void);

rsdkStatus_t interrupts_cm7_enable_irq(IRQn_Type irq_num, uint8_t priority);

rsdkStatus_t interrupts_cm7_disable_irq(IRQn_Type irq_num);

rsdkStatus_t interrupts_cm7_register_isr(IRQn_Type irq_num, pFunc isr);

rsdkStatus_t interrupts_cm7_install(IRQn_Type irq_num, uint8_t priority, pFunc isr, rsdkCoreId_t execCoreId);

void __attribute__ ((interrupt ("SVC"))) dummy_isr(void);

#endif /* INTERRUPTS_CM7_H_ */
