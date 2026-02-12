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
@file       interrupts_cm7.c
@author     NXP

@brief 		Interrupt vector table and NVIC helper functions
**************************************************************************************************/
/**************************************************************************************************
 Includes
**************************************************************************************************/
#include "interrupts_cm7.h"



#include "S32R41_MSCM.h"






#include <stdint.h>

/**************************************************************************************************
 External Objects
**************************************************************************************************/
extern const pFunc __VECTOR_TABLE[240];

/**************************************************************************************************
 Local Function Prototypes
**************************************************************************************************/

/**************************************************************************************************
 Global Functions
**************************************************************************************************/
/** -----------------------------------------------------------------------------------------------
 @brief      Enable the interrupts on the executing core (CM7 NVIC)
 @return     Status indicator
-------------------------------------------------------------------------------------------------*/
rsdkStatus_t interrupts_cm7_enable(void)
{
	uint32_t i;

	/* CM7 uses 3 bits for priority levels, giving 8 possible levels
	 * The group/pre-emption priority and sub-priority split is set using below function. */
    NVIC_SetPriorityGrouping(4); 	// 4 means 3 bits for pre-emption priority, 0 for sub-priority

    /* Set the default handler address as the ISR for each IRQ. The address is overwritten by the real ISR address when an interrupt is installed. */
    for(i=0; i<CM7_NUM_IRQS-CM7_NUM_EXCEPTIONS; i++)
    {
    	NVIC_SetVector((IRQn_Type) i, (uint32_t) dummy_isr);
    }

    /* Enable interrupts to the core */

    __enable_irq();
	return RSDK_SUCCESS;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Enable the interrupt request for specifed IRQ number and set priority
 @param[in]  irq_num - Peripheral interrupt ID (see interrupt_IDs header file).
 @param[in]  priority - priority ranging 0-15
 @return     Status indicator
-------------------------------------------------------------------------------------------------*/
rsdkStatus_t interrupts_cm7_enable_irq(IRQn_Type irq_num, uint8_t priority)
{
    NVIC_SetPriority(irq_num, priority);
	NVIC_EnableIRQ(irq_num);

	return RSDK_SUCCESS;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Disable the interrupt request for specifed IRQ number
 @param[in]  irq_num - Peripheral interrupt ID (see interrupt_IDs header file).
 @return     Status indicator
-------------------------------------------------------------------------------------------------*/
rsdkStatus_t interrupts_cm7_disable_irq(IRQn_Type irq_num)
{
	NVIC_DisableIRQ(irq_num);

	return RSDK_SUCCESS;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Use vector table to register interrupt service routine function (handler) with an IRQ
 @param[in]  irq_num - Peripheral interrupt ID (see interrupt_IDs header file).
 @param[in]  isr - Address of interrupt service routine.
 @return     Status indicator
-------------------------------------------------------------------------------------------------*/
rsdkStatus_t interrupts_cm7_register_isr(IRQn_Type irq_num, pFunc isr)
{
	NVIC_SetVector(irq_num, (uint32_t) isr);

	return RSDK_SUCCESS;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Full setup of specified interrupt. Chains the register_ISR and enable_IRQ functions.
 @param[in]  irq_num - Peripheral interrupt ID (see interrupt_IDs header file).
 @param[in]  priority - priority ranging 0-15.
 @param[in]  isr - Address of interrupt service routine.
 @return     Status indicator
-------------------------------------------------------------------------------------------------*/
rsdkStatus_t interrupts_cm7_install(IRQn_Type irq_num, uint8_t priority, pFunc isr, rsdkCoreId_t execCoreId)
{
	volatile MSCM_Type*const pMscmRegs = (volatile MSCM_Type *)IP_MSCM_BASE;

	// for R41 Cortex M7, core must be clear specify, no mechanism to get core id
	if (execCoreId != RSDK_CORE_0 && execCoreId != RSDK_CORE_1)
	{
		return RSDK_INVALID_PARAMETER;
	}
	interrupts_cm7_register_isr(irq_num, isr);
	interrupts_cm7_enable_irq(irq_num, priority);

	if(irq_num >= 0)
	{
		// Route the external peripheral interrupt to executing core
		pMscmRegs->IRSPRC[irq_num] = (1 << (execCoreId));
	}

	// Data and instruction barrier to ensure ISR registered before returning
    __DSB();
    __ISB();

	return RSDK_SUCCESS;
}

/** -----------------------------------------------------------------------------------------------
 @brief    Dummy ISR used as placeholder in vector table
-------------------------------------------------------------------------------------------------*/
void __attribute__ ((interrupt ("IRQ"))) dummy_isr(void)
{
	while(1);
    return;
}

/**************************************************************************************************
 Local Functions
**************************************************************************************************/
