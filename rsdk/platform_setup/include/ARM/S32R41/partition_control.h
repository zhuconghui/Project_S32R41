/**************************************************************************************************
 *
 * Copyright 2019-2021 NXP
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
 @file		partition_control.h
 @author	NXP
**************************************************************************************************/
#ifndef PARTITION_CONTROL_H_
#define PARTITION_CONTROL_H_

/**************************************************************************************************
 Includes
**************************************************************************************************/
#include "platform_setup_basic.h"

/**************************************************************************************************
 Constants and Macros
**************************************************************************************************/

/* MC_RGM */

/* Partition 0 reset controls (MC_RGM_PRST0_0) */

#define MC_RGM_PERIPH_RST_CM7_0		0x00000001	// RGM_PRST0 PERIPH_0_RST/CM7_Cluster_0_RST
#define MC_RGM_PERIPH_RST_CM7_1		0x00000002	// RGM_PRST0 PERIPH_1_RST/CM7_Cluster_1_RST

/* Partition 1 reset controls (MC_RGM_PRST1_0)
 * Contains global partition reset and individual CA53 core reset controls */

#define MC_RGM_PERIPH_RST_CA53_GLOBAL	0x00000001	// RGM_PRST0 PERIPH_64_RST/A53_Cluster_RST
#define MC_RGM_PERIPH_RST_CA53          0x00000002

/* MC_ME */

#define MC_ME_PRTN_PCONF_PCE_MASK 		0x00000001
#define MC_ME_PRTN_STAT_PCS_MASK 		0x00000001

#define MC_ME_PRTN_PCONF_OSSE_MASK 		0x00000004
#define MC_ME_PRTN_STAT_OSSS_MASK		0x00000004

#define MC_ME_CORE_PCONF_CCE_MASK		0x00000001
#define MC_ME_CORE_PCONF_CCS_MASK		0x00000001

/* Partition 0 */

#define MC_ME_PRTN0_CM7_0	            0
#define MC_ME_PRTN0_CM7_1	            1

/* Partition 1 */

#define MC_ME_PRTN1_CA53_0_0	        0
#define MC_ME_PRTN1_CA53                0

#define MC_ME_PRTN1_COFB0_BBE32         0x00000001
#define MC_ME_PRTN1_COFB0_SPT           0x00000002
#define MC_ME_PRTN1_COFB_MIPICSI2       0x00000004

/* RDC */

#define RDC_RD_CTRL_UNLOCK_BIT					(31)
#define RDC_RD_CTRL_UNLOCK						((1) << (RDC_RD_CTRL_UNLOCK_BIT))

#define RDC_RD_XBAR_INTERFACE_DISABLE_BIT		(3)
#define RDC_RD_XBAR_INTERFACE_DISABLE			((1) << (RDC_RD_XBAR_INTERFACE_DISABLE_BIT))

#define RDC_RD_XBAR_INTERFACE_DISABLE_STAT_BIT 	(4)
#define RDC_RD_XBAR_INTERFACE_DISABLE_STAT 		((1) << (RDC_RD_XBAR_INTERFACE_DISABLE_STAT_BIT))

/**************************************************************************************************
 Functions
**************************************************************************************************/
appStatus_t platform_partition_enable(uint8_t partition_num, uint32_t reset_mask);
appStatus_t platform_block_enable(uint8_t partition_num, uint32_t mask_COFB);

#endif /* PARTITION_CONTROL_H_ */
