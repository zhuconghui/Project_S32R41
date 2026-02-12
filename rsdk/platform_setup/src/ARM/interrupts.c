/**************************************************************************************************
*
* Copyright 2019-2021 NXP
* All Rights Reserved
*
**************************************************************************************************
*
* NXP Confidential Proprietary. This software is owned or controlled by NXP and may only be used
* strictly in accordance with the applicable license terms. By expressly accepting
* such terms or by downloading, installing, activating and/or otherwise using the software, you
* are agreeing that you have read, and that you agree to comply with and are bound by, such
* license terms. If you do not agree to be bound by the applicable license terms, then you
* may not retain, install, activate or otherwise use the software.
*
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
*
**************************************************************************************************/
/**************************************************************************************************
@file       interrupts.c
@author     G.Kerr
@date       28 Nov 2019

===================================================================================================
REVISION HISTORY
===================================================================================================
REV    AUTHOR      DATE          COMMENT
0.1    G.Kerr      28 Nov 2019   Initial version
0.2    G.Kerr      19 Dec 2019	 Made the special register access safe. Added usability features.
1.0	   G.Kerr	   20 Dec 2019	 Added helper functions for configuring interrupts at GICD.
**************************************************************************************************/
/**************************************************************************************************
 Includes
**************************************************************************************************/
#include "interrupts.h"




#include "rsdk_S32R41.h"




#include "GICv3.h"
#include "gic_cpu_gcc.h"

/**************************************************************************************************
 Constants and Macros
**************************************************************************************************/
#define GICD (*(volatile struct GICv3_dist_if *)S32_GIC_DIST_BASE)

#define GICR (*(volatile struct GICR_tag *)S32_GIC_REDIST_BASE)
#define GICR_0 (GICR.REDIST[0])
#define GICR_1 (GICR.REDIST[1])
#define GICR_2 (GICR.REDIST[2])
#define GICR_3 (GICR.REDIST[3])

#define GICR_0_SGI (*(volatile struct GICv3_sgiist_if *)S32_GIC_SGIIST_BASE)

/**************************************************************************************************
 Global Variables
**************************************************************************************************/
isr_t isr_table[A53_NUM_OF_INTERRUPTS];  // The ISR vector table

/**************************************************************************************************
 Local Function Prototypes
**************************************************************************************************/
void        gic_interrupt_handler(void);
static void dummy_ISR(void);

void    gic_enable_ID(uint32_t id, uint8_t enable);
void    gic_set_priority(uint32_t id, uint32_t priority);
void    gic_set_group(uint32_t id, uint8_t group);
void    gic_set_detection(uint32_t id, uint8_t type);
uint8_t gic_int_pending(uint32_t id, uint8_t set_clear);

/**************************************************************************************************
 Global Variables
**************************************************************************************************/
uint32_t gic_itln;

/**************************************************************************************************
 Global Functions
**************************************************************************************************/
/** -----------------------------------------------------------------------------------------------
 @brief      Example A53 interrupt configuration for single core handling at EL3.
 @return     None
-------------------------------------------------------------------------------------------------*/
void interrupts_init(void)
{
    uint32_t i;
    uint64_t reg;

    /*
	 * Initialise GIC Distributor and Re-Distributor
	 */

    GICD.CTLR |= (1 << 0);  // Enable GICD group 0 interrupt
    GICD.CTLR |= (1 << 1);  // Enable GICD group 1NS interrupt
    GICD.CTLR |= (1 << 2);  // Enable GICD group 1S interrupt
    while ((GICD.CTLR & 0x80000000) != 0x0)
        ;  // Wait until RWP is cleared

    GICR_0.WAKER &= ~0x2;  // Clear GICR_WAKER.ProcessorAsleep
    while ((GICR_0.WAKER & 0x00000004) != 0x0)
        ;  // Wait until GICR_WAKER.ChildrenAsleep is cleared

    /*
	 * Initialize GIC CPU Interface
	 * System register access is the only method supported
	 */

    /* Interrupt Controller System Register Enable register EL3 (ICC_SRE_EL3) */
    __set_ICC_SRE_EL3(
        0xF);  // SRE = 1, disable IRQ/FIQ bypass, allow EL2 access to ICC_SRE_EL2/EL1, allow EL1 access to ICC_SRE_EL1
    __ISB();

    /* Interrupt Controller System Register Enable register EL1 (ICC_SRE_EL1) */
    __set_ICC_SRE_EL1(0x7);  // SRE = 1, disable IRQ/FIQ bypass
    __ISB();

    /*
	 * Configure interrupts at GIC CPU Interface level
	 */

    /* Enable group1S and group1NS interrupts at EL3 */
    __set_ICC_IGRPEN1_EL3(0x3);  // EnableGrp1NS = 1, EnableGrp1S = 1
    __ISB();

    /* Enable CPU group 0 interrupt at EL1 */
    __set_ICC_IGRPEN0_EL1(0x1);
    __ISB();

    /* Set CPU interrupt priority mask to min (accept anything) */
    __set_ICC_PMR_EL1(0xFF);

    /* Set priority field binary point to 7 (Disable preemption)  */
    __set_ICC_BPR0_EL1(0x7);
    __set_ICC_BPR1_EL1(0x7);

    /* Configure CPU interrupt handling mode, EOImode = 0 */
    __set_ICC_CTLR_EL3(0x0);
    __ISB();

    /*
	 * Configure CPU to accept interrupt requests
	 */

    /* Set SError, IRQ and FIQ to be handled in EL3 so we don't need to change to EL1
	 * Secure Configuration Register EL3 (SCR_EL3_ */
    reg = __get_SCR_EL3();
    reg |= 0xE;
    __set_SCR_EL3(reg);

    /* Unmask core global interrupt inputs (enable FIQ and IRQ) */
    __asm volatile("msr DAIFClr, #0x1");
    __asm volatile("msr DAIFClr, #0x2");

    /*
	 * Configure interrupts at GIC Distrubutor
	 */

    /* Get max number of SPIs that the GIC supports
	 * Number of ISENABLER/IGROUPR instances = GICD_TYPRE[ITLN]+1
	 * Total IRQs = 32 * (GICD_TYPRE[ITLN] + 1) - 1 */
    gic_itln = (GICD.TYPRE & 0x0000001F);  //

    /*  GICD_IGROUPRnb (Interrupt Group Registers at offset 0x0084 - 0x00F8) */
    for (i = 1; i <= gic_itln; i++)
    {
        GICD.IGROUPR[i] = 0xFFFFFFFF;  // Route all SPI (peripheral IRQs) to Group1 which is handled in EL3
        //GICD.IGROUPR[i] = 0x0;	// Route all SPI (peripheral IRQs) to Group0 which is handled in EL1
    }

    /*  GICD_ICFGR (Interrupt Configuration Registers at offset 0x0C00 - 0x0D00 */
    for (i = 0; i < ((gic_itln + 1) * 2); i++)
    {
        GICD.ICFGR[i] = 0;  // All interrupts level-sensitive
    }

    GICR_0_SGI.ICFGR[1] = 0x00000000;  // All PPI interrupts made level sensitive

    /*
	 * Init the ISR vector table
	 */

    /* Set default interrupt handler function */
    for (i = 0; i < A53_NUM_OF_INTERRUPTS; i++)
    {
        isr_table[i] = dummy_ISR;
    }

    return;
}

//// Configures the specified ID as being level or edge triggered
//void interrupts_configureSPI(unsigned int ID, unsigned int conf)
//{
//    unsigned int bank, tmp;
//
//    conf = conf & 0x3;  // Mask out unused bits
//
//    bank = ID / 16;  // There are 16 IDs per register, need to work out which
//                     // register to access
//    ID = ID & 0xF;   // ... and which field within the register
//    ID = ID * 2;     // Convert from which field to a bit offset (2-bits per field)
//
//    conf = conf << ID;  // Move configuration value into correct bit position
//
//    tmp = GICD.ICFGR[bank];  // Read current vlase
//    tmp = tmp & ~(0x3 << ID);          // Clear the bits for the specified field
//    tmp = tmp | conf;                  // OR in new configuration
//    GICD.ICFGR[bank] = tmp;  // Write updated value back
//
//    return;
//}

/** -----------------------------------------------------------------------------------------------
 @brief      Example function which enables ALL interrupts and routes them to CA53_0_0
 @return     None
-------------------------------------------------------------------------------------------------*/
void interrupts_enable_all(void)
{
    uint32_t i;

    /* Set highest priority on all interrupts
	 * Number of IPRIORITY instances = (GICD_TYPRE[ITLN]+1) * 8 */
    for (i = 8; i < ((gic_itln + 1) * 8); i++)
    {
        GICD.IPRIORITYR[i] = 0;  // Set priority on all global interrupts.
    }

    /*  GICD_ISENABLERn (Interrupt Set-Enable registers at offset 0x104 - 0x178) */
    for (i = 1; i <= gic_itln; i++)
    {
        GICD.ISENABLER[i] = 0xFFFFFFFF;  // Enable all SPI (peripheral IRQs)
    }

    GICR_0_SGI.ISENABLER0 = 0xFFFFFFFF;  // Enabling all PPIs & SGIs

    /* Enable MSCM peripheral IRQ routing to all cores */
    for (i = 0; i < 240; i += 1)
    {
        MSCM.IRSPRC[i].R = 0xF;
    }

    return;
}

/** -----------------------------------------------------------------------------------------------
 @brief		 Add user ISR function to the table and enable the interrupt with specified settings.
 @param[in] int_id - the interrupt ID (IRQ number)
 @param[in] isr - the interrupt service routine function
 @param[in] priority - specify the desired interrupt priority
 @param[in] group - the group in which to set the interrupt (group0 or group1)
 @param[in] type - whether the interrupt is level-sensitive (0) or edge detected (1)
 @return     status indicator
-------------------------------------------------------------------------------------------------*/
uint8_t interrupts_register_ISR_enable(gic_int_id_t int_id, isr_t isr, gic_priority_t priority, gic_group_t group,
                                       gic_type_t type)
{
    uint32_t id = (uint32_t)int_id;

    if (id >= A53_NUM_OF_INTERRUPTS)
        return 1;  // Invalid IRQ number provided

    /* Enable the interrupt, set priority, set group */
    gic_enable_ID(id, 1);
    gic_set_priority(id, (uint32_t)priority);
    gic_set_group(id, (uint8_t)group);

    /* Set the type (level or edge) */
    //setIntTarget(id, targetCore);
    gic_set_detection(id, (uint8_t)type);

    /* Add the ISR address to the table */
    isr_table[id] = isr;

    /* Enable MSCM corresponding peripheral IRQ routing to GIC */
    MSCM.IRSPRC[id].R = 0x1;

    return 0;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Example handler called by core exception handler. Gets the interrupt ID and calls the
 	 	 	 associated ISR. Once complete, deactivates the interrupt request.
 @return     None
-------------------------------------------------------------------------------------------------*/
void gic_interrupt_handler(void)
{
    unsigned int id;

    /* Read the interrupt ID from the acknowledge register
     * There are two ack regs, one for each group. We are handling group1 interrupts so read ICC_IAR1_EL1
     * This is valid since we have configured to handle group1 at EL3.
     */
    id = __get_ICC_IAR1_EL1();

    if (id >= A53_NUM_OF_INTERRUPTS)
    {
        /* Illegal interrupt source */
        return;
    }

    /* Run specific interrupt service routine */
    isr_table[id]();

    /* Write the ID to group1 end of interrupt register to deactivate the request */
    __set_ICC_EOIR1_EL1(id);

    return;
}

/**************************************************************************************************
 Local Functions
**************************************************************************************************/
/** -----------------------------------------------------------------------------------------------
 @brief      Enable/disable the interrupt source given by the ID
 @param[in]  id - GIC interrupt ID
 @param[in]	 enable - provide 1 to enable the interrupt, 0 to disable.
 @return     None
-------------------------------------------------------------------------------------------------*/
void gic_enable_ID(uint32_t id, uint8_t enable)
{
    uint32_t reg_val, bank;

    bank = id / 32;  // Each reg contains bit for 32 interrupt IDs
    id &= 0x1f;      // Mask off unused bits

    // Set only the bit corresponding to the ID
    //NOTE: according to ARM GIC Arch Spec, setting bits to 0 in ISENABLER and ICENABLER has no effect.
    reg_val = (1 << id);

    if (enable)
        GICD.ISENABLER[bank] = reg_val;  // Write bit in the 'set enable' register
    else
        GICD.ICENABLER[bank] = reg_val;  // Write bit in the 'clear enable' register

    return;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Set priority value for the given ID
 @param[in]  id - GIC interrupt ID
 @param[in]	 priority - the priority value to set
 @return     None
-------------------------------------------------------------------------------------------------*/
void gic_set_priority(uint32_t id, uint32_t priority)
{
    /* The priority registers are an array of bytes, each one corresponds to an ID */
    GICD.IPRIORITYR[id] = priority;

    return;
}

/** -----------------------------------------------------------------------------------------------
 @brief		Set group0 (secure) or group1 (non-secure) for given ID
 @param[in] id - GIC interrupt ID
 @param[in] group - Provide 0 for group0, 1 for group1
 @return	None
-------------------------------------------------------------------------------------------------*/
void gic_set_group(uint32_t id, uint8_t group)
{
    uint32_t reg_val, bank;

    bank = id / 32;  // Each reg contains bit for 32 interrupt IDs
    id &= 0x1f;      // Mask off unused bits

    reg_val = GICD.IGROUPR[bank];

    if (group == 0)
        reg_val |= ~(1 << id);  // Bit is cleared for group0
    else
        reg_val |= (1 << id);  // Bit is set for group1

    GICD.IGROUPR[bank] = reg_val;

    return;
}
/** -----------------------------------------------------------------------------------------------
 @brief		Configure as level or edge triggered interrupt
 @param[in] id - GIC interrupt ID
 @param[in] type - provide 0 for level-sensitive, 1 for edge-triggered
 @return	None
-------------------------------------------------------------------------------------------------*/
void gic_set_detection(uint32_t id, uint8_t type)
{
    uint32_t reg_val, bank;

    bank = id / 16;       // Each reg contains bit for 16 interrupt IDs (2 bits each)
    id = (id & 0xF) * 2;  // Mask off unused bits and calculate bit position
    type &= 0x3;          // Mask off unused bits

    reg_val = GICD.ICFGR[bank];
    reg_val &= ~(0x3 << id);                    // Clear the corresponding bits
    GICD.ICFGR[bank] = reg_val | (type << id);  // Set new value

    return;
}

/** -----------------------------------------------------------------------------------------------
 @brief		Sets the target CPUs for requests from given ID
 @param[in] id - GIC interrupt ID
 @param[in] target - The target CPU value to set
 @return	None
-------------------------------------------------------------------------------------------------*/
void gic_set_target(uint32_t id, uint32_t target)
{
    uint32_t reg_val, bank;

    bank = id / 4;        // Each reg contains 8-bits per ID
    target &= 0xFF;       // Mask off unused bits
    id = (id & 0x3) * 8;  // Mask off unused bits and calculate bit position

    reg_val = GICD.ITARGETSR[bank];
    reg_val &= ~(0xFF << id);  // Clear corresponding bits
    GICD.ITARGETSR[bank] = reg_val | (target << id);

    return;
}

/** -----------------------------------------------------------------------------------------------
 @brief		Returns value of interrupt pending bit for the given ID.
 	 	 	Also allows pending bit to be set, cleared or left as is.
 @param[in] id - GIC interrupt ID
 @param[in] set_clear - Provide 1 to set pending bit, 0 to clear, anything else to leave as is.
 @return	Interrupt pending bit value before call.
-------------------------------------------------------------------------------------------------*/
uint8_t gic_int_pending(uint32_t id, uint8_t set_clear)
{
    uint32_t reg_val, bank, ret;

    bank = id / 32;  // Each reg contains bit for 32 interrupt IDs
    id &= 0x1F;      // Mask off unused bits

    reg_val = GICD.ICPENDR[bank];
    ret = (reg_val >> id) & 0x1;  // Select the desired pending bit and mask off unused bits

    if (set_clear == 0)
        GICD.ICPENDR[bank] = (1 << id);  // Write the 'clear pending' register
    else if (set_clear == 1)
        GICD.ISPENDR[bank] = (1 << id);  // Write the 'set pending' register

    return ret;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Default interrupt service routine. Does nothing.
 @return     None
-------------------------------------------------------------------------------------------------*/
static void dummy_ISR(void)
{
    return;
}

void interruptsEnable(void)
{
    // DAIF is a special purpose register that holds the D, A, I, F flags from PSTATE
    // Using the special form of the instruction to clear the I, F bits
    __asm("msr DAIFclr, #0x3");
}

void interruptsDisable(void)
{
    // Using the special form of the instruction to set the I, F bits
    __asm("msr DAIFset, #0x3");
}

//legacy function inherited from DS New Project template. TODO: remove if not needed.
void Current_EL3_SPx_Sync()
{
    while (1)
        ;
}
