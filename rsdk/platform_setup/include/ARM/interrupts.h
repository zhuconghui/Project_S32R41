/*
 * Copyright 2017-2021 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/**************************************************************************************************
 Includes
**************************************************************************************************/
#include "typedefs.h"
#include "gic_interrupt_IDs.h"
#include "rsdk_glue_irq_register_api.h"

/**************************************************************************************************
 Constants and Macros
**************************************************************************************************/





#define S32_GIC_DIST_BASE       0x50800000
#define S32_GIC_REDIST_BASE     0x50840000
#define S32_GIC_SGIIST_BASE     0x50848000


#define A53_NUM_OF_VECTORS 287       // Total number of vectors
#define A53_NUM_OF_START_VECTORS 16  // Core internal exception vectors
#define A53_NUM_OF_INTERNAL_INTERRUPTS \
    32  // Software Generated Interrupts (SGI) and Private Peripheral Interrupts (PPI)
#define A53_NUM_OF_INTERRUPTS (A53_NUM_OF_VECTORS - A53_NUM_OF_START_VECTORS)

#define GIC_SGI_BEGIN 0
#define GIC_SGI_END 15
#define GIC_SGI_NUM (GIC_SGI_END - GIC_SGI_BEGIN + 1)  // 16

#define GIC_PPI_BEGIN 16
#define GIC_PPI_END 31
#define GIC_PPI_NUM (GIC_PPI_END - GIC_PPI_BEGIN + 1)  // 16

#define GIC_SPI_BEGIN 32
#define GIC_SPI_END 271
#define GIC_SPI_NUM (GIC_SPI_END - GIC_SPI_BEGIN + 1)  // 176

#define RSDK_MAX_EXT_IRQ_NUM (480)  // The maximum IRQ number assigned for SoC (JTAGM)

/**************************************************************************************************
 User-defined Types
**************************************************************************************************/
typedef void (*isr_t)(void);

typedef enum
{
    PRIORITY_0,
    PRIORITY_1,
    PRIORITY_2,
    PRIORITY_3,
    PRIORITY_4,
    PRIORITY_5,
    PRIORITY_6,
    PRIORITY_7,
    PRIORITY_8,
    PRIORITY_9,
    PRIORITY_10,
    PRIORITY_11,
    PRIORITY_12,
    PRIORITY_13,
    PRIORITY_14,
    PRIORITY_15,
    PRIORITY_16,
    PRIORITY_17,
    PRIORITY_18,
    PRIORITY_19,
    PRIORITY_20,
    PRIORITY_21,
    PRIORITY_22,
    PRIORITY_23,
    PRIORITY_24,
    PRIORITY_25,
    PRIORITY_26,
    PRIORITY_27,
    PRIORITY_28,
    PRIORITY_29,
    PRIORITY_30,
    PRIORITY_31,
} gic_priority_t;

typedef enum
{
    GIC_LEVEL,
    GIC_EDGE
} gic_type_t;

typedef enum
{
    GROUP0,
    GROUP1
} gic_group_t;

/**************************************************************************************************
 Global Function Prototypes
**************************************************************************************************/
void    interrupts_init(void);
void    interrupts_enable_all(void);
void    gic_set_target(uint32_t id, uint32_t target);
uint8_t interrupts_register_ISR_enable(gic_int_id_t int_id, isr_t isr, gic_priority_t priority, gic_group_t group,
                                       gic_type_t type);
void    Current_EL3_SPx_Sync(void);
void    interruptsEnable(void);
void    interruptsDisable(void);

#endif /* INTERRUPTS_H_ */
