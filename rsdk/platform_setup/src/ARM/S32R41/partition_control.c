/**************************************************************************************************
 *
 * Copyright 2021 NXP
 *
 **************************************************************************************************
 *
 * NXP Confidential Proprietary. This software is owned or controlled by NXP and may only be used
 * strictly in accordance with the applicable terms. By expressly accepting such terms or by
 * downloading, installing, activating and/or otherwise using the software, you are agreeing that
 * you have read, and that you agree to comply with and are bound by, such license terms.
 * If you do not agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
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
 @file    	partition_control.c
 @author  	NXP

 @brief     Functions for enabling software reset-able partitions and starting A53 cores.
**************************************************************************************************/
/**************************************************************************************************
 Includes
**************************************************************************************************/
#include "rsdk_S32R41.h"
#include "partition_control.h"

/**************************************************************************************************
 Constants and Macros
**************************************************************************************************/
/* Timeout value for simple loop counters */
#define TIMEOUT_COUNT (100000U)

/**************************************************************************************************
 Global Variables
**************************************************************************************************/

/**************************************************************************************************
 External Objects
**************************************************************************************************/

/**************************************************************************************************
 Local Function Prototypes
**************************************************************************************************/

/**************************************************************************************************
 Global Functions
**************************************************************************************************/
/** -----------------------------------------------------------------------------------------------
 @brief      Implements the software reset partition turn-on flow.
 @param[in]  uint8_t partition_num - Partition to enable
 @param[in]  uint32_t periph_rst_mask - Bitmask for the specific core/periph reset to be released.
 @return     Status indicator
-------------------------------------------------------------------------------------------------*/
#define TIMEOUT_CHECK(timeout) if (timeout == 0) {return APP_STATUS_TIMEOUT;} else {timeout = TIMEOUT_COUNT;}

appStatus_t platform_partition_enable(uint8_t partition_num, uint32_t reset_mask)
{
    uint32_t timeout = TIMEOUT_COUNT;

    switch(partition_num)
    {

    /* CM7_0, CM7_1 (CM7_Cluster_0_RST, CM7_Cluster_1_RST)  */
    case 0:
        /* Check if partition clock is already enabled */
        if((MC_ME.PRTN0_STAT.R & MC_ME_PRTN_STAT_PCS_MASK) == 0)
        {
            /* Enable the partition clock */
            MC_ME.PRTN0_PCONF.R = MC_ME.PRTN0_PCONF.R | MC_ME_PRTN_PCONF_PCE_MASK;          // Set PCE to enable partition clock
            MC_ME.PRTN0_PUPD.R = MC_ME.PRTN0_PUPD.R | MC_ME_PRTN_PCONF_PCE_MASK;            // Trigger the process of clock enable

            /* Write the key and then inverted key to perform the mode transition */
            MC_ME.CTL_KEY.R = 0x00005AF0;
            MC_ME.CTL_KEY.R = 0x0000A50F;
            while(((MC_ME.PRTN0_STAT.R & MC_ME_PRTN_STAT_PCS_MASK) == 0) && (timeout > 0)) timeout--;   // Poll for partition clock status to set
            TIMEOUT_CHECK(timeout)
        }

        /* Release partition constituent reset via RGM_PRST0_0 */
        MC_RGM.PRST0_0.R = MC_RGM.PRST0_0.R & (~reset_mask);  // Clear reset control

        /* Disable the partition output isolation (output safe stating) - not necessary on partition 0 */
        //MC_ME.PRTN0_PCONF.R = MC_ME.PRTN0_PCONF.R & ~MC_ME_PRTN_PCONF_OSSE_MASK;            // Clear OSSE  to disable output safe stating
        //MC_ME.PRTN0_PUPD.R = MC_ME.PRTN0_PUPD.R | MC_ME_PRTN_PCONF_OSSE_MASK;               // Trigger the process

        /* Write the key and then inverted key to perform the mode transition */
        MC_ME.CTL_KEY.R = 0x00005AF0;
        MC_ME.CTL_KEY.R = 0x0000A50F;

        /* Wait until specific core out of reset */
        while(((MC_RGM.PSTAT0_0.R & reset_mask) != 0) && (timeout > 0)) timeout--;
        TIMEOUT_CHECK(timeout)

        /* Wait for output safe stating status to clear - not necessary on partition 0*/
        //while((MC_ME.PRTN0_STAT.R != (MC_ME.PRTN0_STAT.R & ~MC_ME_PRTN_STAT_OSSS_MASK)) && (timeout > 0)) timeout--;
        //TIMEOUT_CHECK(timeout)

        break;

    /* CA53 (A53_Cluster_RST) */
    case 1:
        /* Enable the partition clock */
        MC_ME.PRTN1_PCONF.R = MC_ME.PRTN1_PCONF.R | MC_ME_PRTN_PCONF_PCE_MASK;          // Set PCE to enable partition clock
        MC_ME.PRTN1_PUPD.R = MC_ME.PRTN1_PUPD.R | MC_ME_PRTN_PCONF_PCE_MASK;            // Trigger the process of clock enable

        /* Write the key and then inverted key to perform the mode transition */
        MC_ME.CTL_KEY.R = 0x00005AF0;
        MC_ME.CTL_KEY.R = 0x0000A50F;
        while(((MC_ME.PRTN1_STAT.R & MC_ME_PRTN_STAT_PCS_MASK) == 0) && (timeout > 0)) timeout--;   // Poll for partition clock status to set
        TIMEOUT_CHECK(timeout)

        /* Enable the NoC interface */
        RDC.RD1_CTRL_REG.R = RDC.RD1_CTRL_REG.R | RDC_RD_CTRL_UNLOCK;                   // Unlock the control register
        RDC.RD1_CTRL_REG.R = RDC.RD1_CTRL_REG.R & (~RDC_RD_XBAR_INTERFACE_DISABLE); // Enable the interconnect interface
        while(((RDC.RD1_STAT_REG.R & RDC_RD_XBAR_INTERFACE_DISABLE_STAT) != 0) && (timeout > 0)) timeout--; // Poll for interface to become enabled
        TIMEOUT_CHECK(timeout)

        /* Release the partition reset */

        /* Release specific core reset via RGM_PRST1_0 */
        MC_RGM.PRST1_0.R = MC_RGM.PRST1_0.R & (~reset_mask);  // Clear reset control

        /* Disable the partition output isolation (output safe stating) */
        MC_ME.PRTN1_PCONF.R = MC_ME.PRTN1_PCONF.R & ~MC_ME_PRTN_PCONF_OSSE_MASK;            // Clear OSSE  to disable output safe stating
        MC_ME.PRTN1_PUPD.R = MC_ME.PRTN1_PUPD.R | MC_ME_PRTN_PCONF_OSSE_MASK;               // Trigger the process

        /* Write the key and then inverted key to perform the mode transition */
        MC_ME.CTL_KEY.R = 0x00005AF0;
        MC_ME.CTL_KEY.R = 0x0000A50F;

        /* Wait until partition and specific core out of reset */
        while(((MC_RGM.PSTAT1_0.R & reset_mask) != 0) && (timeout > 0)) timeout--;
        TIMEOUT_CHECK(timeout)

        /* Wait for output safe stating status to clear */
        while((MC_ME.PRTN1_STAT.R != (MC_ME.PRTN1_STAT.R & ~MC_ME_PRTN_STAT_OSSS_MASK)) && (timeout > 0)) timeout--;
        TIMEOUT_CHECK(timeout)

        break;
    }

    return APP_STATUS_SUCCESS;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Enable the clocks to functional blocks (IPs) within a software reset-able partition
 @param[in]  uint8_t partition_num - partition to enable
 @param[in]  uint32_t mask_COFB - bitmask for the functional blocks to enable the clocks for
 @return     Status indicator
-------------------------------------------------------------------------------------------------*/
appStatus_t platform_block_enable(uint8_t partition_num, uint32_t mask_COFB)
{
    uint32_t timeout = TIMEOUT_COUNT;

    switch(partition_num)
    {
    case 0:
        /* No IP blocks present in partition 0 */

        break;

    case 1:
        /* Enable the clocks to the functional blocks inside partition */

        MC_ME.PRTN1_COFB0_CLKEN.R |= mask_COFB;         // Set the clock enable control for the block in partition
        MC_ME.PRTN1_PUPD.R = MC_ME.PRTN1_PUPD.R | MC_ME_PRTN_PCONF_PCE_MASK;    // Trigger the prcoess of clock enable

        /* Write the key and then inverted key to perform the mode transition */

        MC_ME.CTL_KEY.R = 0x00005AF0;
        MC_ME.CTL_KEY.R = 0x0000A50F;
        while((MC_ME.PRTN1_COFB0_STAT.R != (MC_ME.PRTN1_COFB0_STAT.R | mask_COFB)) && (timeout > 0)) timeout--; // Wait until the clock is running for specified IP blocks
        TIMEOUT_CHECK(timeout)

        break;

    default:
        break;

    }

    return APP_STATUS_SUCCESS;
}
