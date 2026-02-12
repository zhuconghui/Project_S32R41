/**************************************************************************************************
 * 
 * NXP Confidential Proprietary
 *
 * Copyright 2021 NXP 
 * All Rights Reserved
 *
 *****************************************************************************
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

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/

#include <stdio.h>
#include "rsdk_osenv.h"
#include "rsdk_S32R41.h"
#ifdef ARMCM7_SP
#include "interrupts_cm7.h"
#else
#include "interrupts.h"
#endif
#include "platform_setup_basic.h"
#include "partition_control.h"
#include "rsdk_glue_timer_api.h"
#include "rsdk_glue_gpio_api.h"
#include "s32r41_cgm_sel_src.h"
#include "xrdc.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
 ==================================================================================================*/
#define PLLO_DIV_OFFSET             16  // Position of DIV field in PLL Output Divider registers
#define DVPORT_MFI_OFFSET           8

/* SIUL2 MSCR and IMCR helper macros */
#define B_OBE     (1 << 21)
#define B_IBE     (1 << 19)
#define B_SRE(x)  ((x & 7) << 14)
#define B_SSS(x)  (x & 7)
#define B_IMCR(x) (x - 512) // I/O mux sheet gives IMCR index offset by 512
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL FUNCTIONS
 ==================================================================================================*/

static void cgm_init()
{
    /*-------------------------------------------------------------------------------------------------
     * Realtime Domain
     *-----------------------------------------------------------------------------------------------*/

    /*-----------------------------------------------
     * MC_CGM_0
     *---------------------------------------------*/

	/* MC_CGM_0 MUX_0
	 * SYS_CLK = PERIPH_PLL_PHI0_CLK = 400 MHz
	 * RT_DAPB_CLK = PERIPH_PLL_PHI0_CLK / 8 = 400 MHz / 8 = 50 MHz */

    while(MC_CGM_0.MUX_0_CSS.B.SWIP != 0x0);                            // Check no switch in progress
    MC_CGM_0.MUX_0_CSC.B.SELCTL = PERIPH_PLL_PHI0_CLK_ID;               // Set the mux selector index
    MC_CGM_0.MUX_0_CSC.B.CLK_SW = 1;									// Trigger the clock switch
    while(MC_CGM_0.MUX_0_CSC.B.CLK_SW != 0);                            // Wait for switch to complete
    while(MC_CGM_0.MUX_0_CSS.B.SWIP != 0x0);
    while(MC_CGM_0.MUX_0_CSS.B.SWTRG != 0x1); 							// Check requested switch was successful
    while(MC_CGM_0.MUX_0_CSS.B.SELSTAT != PERIPH_PLL_PHI0_CLK_ID);      // Verify the selected clock

    /* MC_CGM_0 MUX_1
     * CLKOUT0 */

    MC_CGM_0.MUX_1_CSC.B.CG = 1;                                        // Gate the clock
    while(MC_CGM_0.MUX_1_CSS.B.CS != 0);                                // Check clock status
    MC_CGM_0.MUX_1_CSC.B.SELCTL = FXOSC_CLK_ID;                         // Set the mux selector index
    //MC_CGM_0.MUX_1_CSC.B.SELCTL = CORE_PLL_PHI5_CLK_ID;
    //MC_CGM_0.MUX_1_CSC.B.SELCTL = PERIPH_PLL_PHI6_CLK_ID;
    //MC_CGM_0.MUX_1_CSC.B.SELCTL = PERIPH_DFS2_CLK_ID;
    MC_CGM_0.MUX_1_CSC.B.FCG = 0;                                       // Clear force clock gate
    MC_CGM_0.MUX_1_CSC.B.CG = 0;                                        // Clear clock gate
    while(MC_CGM_0.MUX_1_CSS.B.CS != 1)                                 // Check the clock status
    while(MC_CGM_0.MUX_1_CSS.B.SELSTAT != FXOSC_CLK_ID);                // Verify the selected clock
    //while(MC_CGM_0.MUX_1_CSS.B.SELSTAT != CORE_PLL_PHI5_CLK_ID);
    //while(MC_CGM_0.MUX_1_CSS.B.SELSTAT != PERIPH_PLL_PHI6_CLK_ID);
    //while(MC_CGM_0.MUX_1_CSS.B.SELSTAT != PERIPH_DFS2_CLK_ID);

    /* MC_CGM_0 MUX_2
     * CLKOUT1 */

    MC_CGM_0.MUX_1_CSC.B.CG = 1;                                        // Gate the clock
    while(MC_CGM_0.MUX_1_CSS.B.CS != 0);                                // Check clock status
    MC_CGM_0.MUX_2_CSC.B.SELCTL = FXOSC_CLK_ID;                         // Set the mux selector index
    //MC_CGM_0.MUX_2_CSC.B.SELCTL = CORE_PLL_PHI5_CLK_ID;
    //MC_CGM_0.MUX_2_CSC.B.SELCTL = PERIPH_PLL_PHI6_CLK_ID;
    //MC_CGM_0.MUX_2_CSC.B.SELCTL = PERIPH_DFS2_CLK_ID;
    MC_CGM_0.MUX_1_CSC.B.FCG = 0;                                       // Clear force clock gate
    MC_CGM_0.MUX_1_CSC.B.CG = 0;                                        // Clear clock gate
    while(MC_CGM_0.MUX_1_CSS.B.CS != 1)                                 // Check the clock status
    while(MC_CGM_0.MUX_2_CSS.B.SELSTAT != FXOSC_CLK_ID);                // Verify the selected clock
    //while(MC_CGM_0.MUX_2_CSS.B.SELSTAT != CORE_PLL_PHI5_CLK_ID);
    //while(MC_CGM_0.MUX_2_CSS.B.SELSTAT != PERIPH_PLL_PHI6_CLK_ID);
    //while(MC_CGM_0.MUX_2_CSS.B.SELSTAT != PERIPH_DFS2_CLK_ID);

    /* MC_CGM_0 MUX_3
     * MC_CLK = PERIPH_PLL_PHI1_CLK = 80 MHz */

    while(MC_CGM_0.MUX_3_CSS.B.SWIP != 0x0);                            // Check no switch in progress
    MC_CGM_0.MUX_3_CSC.B.SELCTL = PERIPH_PLL_PHI1_CLK_ID;               // Set the mux selector index
    MC_CGM_0.MUX_3_CSC.B.CLK_SW = 1;                                    // Trigger the clock switch
    while(MC_CGM_0.MUX_3_CSC.B.CLK_SW != 0);                            // Wait for switch to complete
    while(MC_CGM_0.MUX_3_CSS.B.SWIP != 0x0);
    while(MC_CGM_0.MUX_3_CSS.B.SWTRG != 0x1);                           // Check switch was successful
    while(MC_CGM_0.MUX_3_CSS.B.SELSTAT != PERIPH_PLL_PHI1_CLK_ID);      // Verify the selected clock

	/* MC_CGM_0 MUX_4
	 * SPI_CLK = PERIPH_PLL_PHI7_CLK = 100 MHz */

    while(MC_CGM_0.MUX_4_CSS.B.SWIP != 0x0);                            // Check no switch in progress
    MC_CGM_0.MUX_4_CSC.B.SELCTL = PERIPH_PLL_PHI7_CLK_ID;               // Set the mux selector index
    MC_CGM_0.MUX_4_CSC.B.CLK_SW = 1;									// Trigger the clock switch
    while(MC_CGM_0.MUX_4_CSC.B.CLK_SW != 0);                            // Wait for switch to complete
    while(MC_CGM_0.MUX_4_CSS.B.SWIP != 0x0);
    while(MC_CGM_0.MUX_4_CSS.B.SWTRG != 0x1); 							// Check switch was successful
    while(MC_CGM_0.MUX_4_CSS.B.SELSTAT != PERIPH_PLL_PHI7_CLK_ID);      // Verify the selected clock

    /* MC_CGM_0 MUX_5
     * QSPI_2X_CLK = PERIPH_DFS1_CLK / 3 = 800 MHz / 3 = 266.6 MHz
     * QSPI_1X_CLK = QSPI_2X_CLK / 2 = 133.3 MHz*/

    MC_CGM_0.MUX_5_DC_0.B.DE = 0;										// Disable Divider
    while (MC_CGM_0.MUX_5_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    while(MC_CGM_0.MUX_5_CSS.B.SWIP != 0x0);                            // Check no switch in progress
    MC_CGM_0.MUX_5_CSC.B.SELCTL = PERIPH_DFS1_CLK_ID;                   // Set the mux selector index
    MC_CGM_0.MUX_5_DC_0.B.DIV = 2;									    // Set Divider to 2+1, output = PERIPH_DFS1_CLK / 3
    MC_CGM_0.MUX_5_CSC.B.CLK_SW = 1;									// Trigger the clock switch
    while(MC_CGM_0.MUX_5_CSC.B.CLK_SW != 0);                            // Wait for switch to complete
    while(MC_CGM_0.MUX_5_CSS.B.SWIP != 0x0);
    while(MC_CGM_0.MUX_5_CSS.B.SWTRG != 0x1); 							// Check switch was successful
    while(MC_CGM_0.MUX_5_CSS.B.SELSTAT != PERIPH_DFS1_CLK_ID);          // Verify selected clock
    MC_CGM_0.MUX_5_DC_0.B.DE = 1;										// Enable Divider
    while (MC_CGM_0.MUX_5_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    /* MC_CGM_0 MUX_6
     * GMAC_1_INT_REF_CLK = PERIPH_PLL_PHI5_CLK / 10 = 500 MHz / 10 = 50 MHz
     * CAN_TS_CLK = PERIPH_PLL_PHI5_CLK / 2 = 500 MHz / 2 = 250 MHz
     * CAN_CHI_CLK = PERIPH_PLL_PHI5_CLK / 4 = 500 MHz / 4 = 125 MHz
     * FCCU_IPS_CLK = PERIPH_PLL_PHI5_CLK / 4 = 500 MHz / 4 = 125 MHz
     * CTU_IPS_CLK = PERIPH_PLL_PHI5_CLK / 4 = 500 MHz / 4 = 125 MHz
     * TMU_CLK = PERIPH_PLL_PHI5_CLK / 4 = 500 MHz / 4 = 125 MHz
     * STCU_CLK = PERIPH_PLL_PHI5_CLK / 10 = 500 MHz / 10 = 50 MHz
     * DAPB_CLK  = PERIPH_PLL_PHI5_CLK / 10 = 500 MHz / 10 = 50 MHz*/

    /* DIV 0
     * CAN_TS_CLK */
    MC_CGM_0.MUX_6_DC_0.B.DE = 0;										// Disable Divider
    while (MC_CGM_0.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    MC_CGM_0.MUX_6_DC_0.B.DIV = 1;  //  500/2 = 250 MHz
    while (MC_CGM_0.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    /* DIV 1
     * CAN_CHI_CLK, FCCU_IPS_CLK, CTU_IPS_CLK, TMU_CLK */
    MC_CGM_0.MUX_6_DC_1.B.DE = 0;										// Disable Divider
    while (MC_CGM_0.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    MC_CGM_0.MUX_6_DC_1.B.DIV = 3;  // 500/4 = 125 MHz
    while (MC_CGM_0.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    /* DIV 4
     * STCU_CLK, DAPB_CLK*/
    MC_CGM_0.MUX_6_DC_4.B.DE = 0;										// Disable Divider
    while (MC_CGM_0.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    MC_CGM_0.MUX_6_DC_4.B.DIV = 9;  // 500/10 = 50 MHz,
    while (MC_CGM_0.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    while(MC_CGM_0.MUX_6_CSS.B.SWIP != 0x0);                            // Check no switch in progress
    MC_CGM_0.MUX_6_CSC.B.SELCTL = PERIPH_PLL_PHI5_CLK_ID;               // Set mux selector index
    MC_CGM_0.MUX_6_CSC.B.CLK_SW = 1;									// Trigger the clock switch
    while(MC_CGM_0.MUX_6_CSC.B.CLK_SW != 0);                            // Wait for switch to complete
    while(MC_CGM_0.MUX_6_CSS.B.SWIP != 0x0);
    while(MC_CGM_0.MUX_6_CSS.B.SWTRG != 0x1); 							// Check switch was successful
    while(MC_CGM_0.MUX_6_CSS.B.SELSTAT != PERIPH_PLL_PHI5_CLK_ID);      // Verify the selected clock

    MC_CGM_0.MUX_6_DC_0.B.DE = 1;										// Enable Divider 0
    while (MC_CGM_0.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    MC_CGM_0.MUX_6_DC_1.B.DE = 1;										// Enable Divider 1
    while (MC_CGM_0.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    MC_CGM_0.MUX_6_DC_4.B.DE = 1;										// Enable Divider 4
    while (MC_CGM_0.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    /* MC_CGM_0 MUX_7
     * CAN_PE_CLK = PERIPH_PLL_PHI2_CLK = 80 MHz */

    while(MC_CGM_0.MUX_7_CSS.B.SWIP != 0x0);                            // Check no switch in progress
    MC_CGM_0.MUX_7_CSC.B.SELCTL = PERIPH_PLL_PHI2_CLK_ID;               // Set mux selector index
    MC_CGM_0.MUX_7_CSC.B.CLK_SW = 1;									// Trigger the clock switch
    while(MC_CGM_0.MUX_7_CSC.B.CLK_SW != 0);                            // Wait for switch to complete
    while(MC_CGM_0.MUX_8_CSS.B.SWIP != 0x0);
    while(MC_CGM_0.MUX_7_CSS.B.SWTRG != 0x1); 							// Check switch was successful
    while(MC_CGM_0.MUX_7_CSS.B.SELSTAT != PERIPH_PLL_PHI2_CLK_ID);      // Verify the selected clock

    /* MC_CGM_0 MUX_8
     * LIN_BAUD_CLK = PERIPH_PLL_PHI3_CLK = 100 MHz
     * LINFLEXD_CLK = PERIPH_PLL_PHI3_CLK / 2 = 100 MHz / 2 = 50 MHz */

    while(MC_CGM_0.MUX_8_CSS.B.SWIP != 0x0);
    MC_CGM_0.MUX_8_CSC.B.SELCTL = PERIPH_PLL_PHI3_CLK_ID;
    MC_CGM_0.MUX_8_CSC.B.CLK_SW = 1;									// Trigger the clock switch
    while(MC_CGM_0.MUX_8_CSC.B.CLK_SW != 0);
    while(MC_CGM_0.MUX_8_CSS.B.SWIP != 0x0);
    while(MC_CGM_0.MUX_8_CSS.B.SWTRG != 0x1); 							// Check switch was successful
    while(MC_CGM_0.MUX_8_CSS.B.SELSTAT != PERIPH_PLL_PHI3_CLK_ID);

    /*-----------------------------------------------
     * MC_CGM_3
     *---------------------------------------------*/

    /* MC_CGM_3 MUX_0
     * FTM0_EXT_CLK = PERIPH_PLL_PHI1_CLK / 1 = 80 MHz / 1 = 80 MHz */

    MC_CGM_3.MUX_0_DC_0.B.DE = 0;										// Disable Divider
    while (MC_CGM_3.MUX_0_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    MC_CGM_3.MUX_0_DC_0.B.DIV = 0;										// Set Divider to 1
    while (MC_CGM_3.MUX_0_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    while(MC_CGM_3.MUX_0_CSS.B.SWIP != 0x0);
    MC_CGM_3.MUX_0_CSC.B.SELCTL = PERIPH_PLL_PHI1_CLK_ID;
    MC_CGM_3.MUX_0_CSC.B.CLK_SW = 1;									// Trigger the clock switch
    while(MC_CGM_3.MUX_0_CSC.B.CLK_SW != 0);
    while(MC_CGM_3.MUX_0_CSS.B.SWIP != 0x0);
    while(MC_CGM_3.MUX_0_CSS.B.SWTRG != 0x1); 							// Check switch was successful
    while(MC_CGM_3.MUX_0_CSS.B.SELSTAT != PERIPH_PLL_PHI1_CLK_ID);

    MC_CGM_3.MUX_0_DC_0.B.DE = 1;										// Enable Divider
    while (MC_CGM_3.MUX_0_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    /* MC_CGM_3 MUX_1
     * GMAC_0_TS_CLK = PERIPH_PLL_PHI4_CLK / 1 = 200 MHz / 1 = 200 MHz*/

    MC_CGM_3.MUX_1_DC_0.B.DE = 0;										// Disable Divider
    while (MC_CGM_3.MUX_1_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    MC_CGM_3.MUX_1_DC_0.B.DIV = 0;                                      // Set divider to 1
    while (MC_CGM_3.MUX_1_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    while(MC_CGM_3.MUX_1_CSS.B.SWIP != 0x0);
    MC_CGM_3.MUX_1_CSC.B.SELCTL = PERIPH_PLL_PHI4_CLK_ID;
    MC_CGM_3.MUX_1_CSC.B.CLK_SW = 1;									// Trigger the clock switch
    while(MC_CGM_3.MUX_1_CSC.B.CLK_SW != 0);
    while(MC_CGM_3.MUX_1_CSS.B.SWIP != 0x0);
    while(MC_CGM_3.MUX_1_CSS.B.SWTRG != 0x1); 							// Check switch was successful
    while(MC_CGM_3.MUX_1_CSS.B.SELSTAT != PERIPH_PLL_PHI4_CLK_ID);

    MC_CGM_3.MUX_1_DC_0.B.DE = 1;										// Enable Divider
    while (MC_CGM_3.MUX_1_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    /*-------------------------------------------------------------------------------------------------
     * Application Domain
     *-----------------------------------------------------------------------------------------------*/

    /*-----------------------------------------------
     * MC_CGM_1
     *---------------------------------------------*/

    /* MC_CGM_1 MUX_0
     * CORE_CLK = CORE_PLL_PHI0_CLK = 800 MHz */

    while(MC_CGM_1.MUX_0_CSS.B.SWIP != 0x0);
    MC_CGM_1.MUX_0_CSC.B.SELCTL = CORE_PLL_PHI0_CLK_ID;
    MC_CGM_1.MUX_0_CSC.B.CLK_SW = 1;									// Trigger the clock switch and wait until complete
    while(MC_CGM_1.MUX_0_CSC.B.CLK_SW != 0);
    while(MC_CGM_1.MUX_0_CSS.B.SWIP != 0x0);
    while(MC_CGM_1.MUX_0_CSS.B.SWTRG != 0x1); 							// Check switch was successful and verify the selected clock
    while(MC_CGM_1.MUX_0_CSS.B.SELSTAT != CORE_PLL_PHI0_CLK_ID);

    /* MC_CGM_1 MUX_1
     * ACCEL_CLK = CORE_PLL_PHI1_CLK = 600 MHz */

    while(MC_CGM_1.MUX_1_CSS.B.SWIP != 0x0);
    MC_CGM_1.MUX_1_CSC.B.SELCTL = CORE_PLL_PHI1_CLK_ID;
    MC_CGM_1.MUX_1_CSC.B.CLK_SW = 1;									// Trigger the clock switch and wait until complete
    while(MC_CGM_1.MUX_1_CSC.B.CLK_SW != 0);
    while(MC_CGM_1.MUX_1_CSS.B.SWIP != 0x0);
    while(MC_CGM_1.MUX_1_CSS.B.SWTRG != 0x1); 							// Check switch was successful and verify the selected clock
    while(MC_CGM_1.MUX_1_CSS.B.SELSTAT != CORE_PLL_PHI1_CLK_ID);

    /* MC_CGM_1 MUX_2
     * ACCEL_XBAR_CLK = CORE_PLL_PHI2_CLK = 400 MHz */

    while(MC_CGM_1.MUX_2_CSS.B.SWIP != 0x0);
    MC_CGM_1.MUX_2_CSC.B.SELCTL = CORE_PLL_PHI2_CLK_ID;
    MC_CGM_1.MUX_2_CSC.B.CLK_SW = 1;									// Trigger the clock switch and wait until complete
    while(MC_CGM_1.MUX_2_CSC.B.CLK_SW != 0);
    while(MC_CGM_1.MUX_2_CSS.B.SWIP != 0x0);
    while(MC_CGM_1.MUX_2_CSS.B.SWTRG != 0x1); 							// Check switch was successful and verify the selected clock
    while(MC_CGM_1.MUX_2_CSS.B.SELSTAT != CORE_PLL_PHI2_CLK_ID);

    /* MC_CGM_1 MUX_3
     * CTE_CLK = CORE_PLL_PHI3_CLK = 80 MHz
     * CSI_IPS_CLK = CORE_PLL_PHI3_CLK = 80 MHz */

    while(MC_CGM_1.MUX_3_CSS.B.SWIP != 0x0);
    MC_CGM_1.MUX_3_CSC.B.SELCTL = CORE_PLL_PHI3_CLK_ID;
    MC_CGM_1.MUX_3_CSC.B.CLK_SW = 1;									// Trigger the clock switch and wait until complete
    while(MC_CGM_1.MUX_3_CSC.B.CLK_SW != 0);
    while(MC_CGM_1.MUX_3_CSS.B.SWIP != 0x0);
    while(MC_CGM_1.MUX_3_CSS.B.SWTRG != 0x1); 							// Check switch was successful and verify the selected clock
    while(MC_CGM_1.MUX_3_CSS.B.SELSTAT != CORE_PLL_PHI3_CLK_ID);

    /* MC_CGM_1 MUX_4
     * CSI_CFG_CLK = CORE_PLL_PHI4_CLK / 2 = 40 Mhz / 2 = 20 MHz
     * CSI_TXCLK_ESC = CORE_PLL_PHI4_CLK / 2 = 40 Mhz / 2 = 20 MHz */

    MC_CGM_1.MUX_4_DC_0.B.DE = 0;                                       // Disable divider
    while (MC_CGM_1.MUX_4_DIV_UPD_STAT.B.DIV_STAT);                     // Wait for divider update to complete
    MC_CGM_1.MUX_4_DC_0.B.DIV = 1;                                      // Set Divider to 2
    while (MC_CGM_1.MUX_4_DIV_UPD_STAT.B.DIV_STAT);                     // Wait for divider update to complete

    while(MC_CGM_1.MUX_4_CSS.B.SWIP != 0x0);
    MC_CGM_1.MUX_4_CSC.B.SELCTL = CORE_PLL_PHI4_CLK_ID;
    MC_CGM_1.MUX_4_CSC.B.CLK_SW = 1;									// Trigger the clock switch and wait until complete
    while(MC_CGM_1.MUX_4_CSC.B.CLK_SW != 0);
    while(MC_CGM_1.MUX_4_CSS.B.SWIP != 0x0);
    while(MC_CGM_1.MUX_4_CSS.B.SWTRG != 0x1); 							// Check switch was successful and verify the selected clock
    while(MC_CGM_1.MUX_4_CSS.B.SELSTAT != CORE_PLL_PHI4_CLK_ID);

    MC_CGM_1.MUX_4_DC_0.B.DE = 1;                                       // Enable divider
    while (MC_CGM_1.MUX_4_DIV_UPD_STAT.B.DIV_STAT);                     // Wait for divider update to complete

    /* MC_CGM_1 MUX_5
     * NOC_TRACE_CLK = CORE_PLL_PHI8_CLK = 800 MHz */

    while(MC_CGM_1.MUX_5_CSS.B.SWIP != 0x0);
    MC_CGM_1.MUX_5_CSC.B.SELCTL = CORE_PLL_PHI8_CLK_ID;
    MC_CGM_1.MUX_5_CSC.B.CLK_SW = 1;                                    // Trigger the clock switch and wait until complete
    while(MC_CGM_1.MUX_5_CSC.B.CLK_SW != 0);
    while(MC_CGM_1.MUX_5_CSS.B.SWIP != 0x0);
    while(MC_CGM_1.MUX_5_CSS.B.SWTRG != 0x1);                           // Check switch was successful and verify the selected clock
    while(MC_CGM_1.MUX_5_CSS.B.SELSTAT != CORE_PLL_PHI8_CLK_ID);

    /* MC_CGM_1 MUX_6
     * LBIST_CLK[7:0] =  CORE_PLL_PHI9_CLK / 8 = 400 MHz / 8 = 50 MHz */

    MC_CGM_1.MUX_6_DC_0.B.DE = 0;										// Disable Divider
    while (MC_CGM_1.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    MC_CGM_1.MUX_6_DC_0.B.DIV = 7;										// Set Divider to 8
    while (MC_CGM_1.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    while(MC_CGM_1.MUX_6_CSS.B.SWIP != 0x0);
    MC_CGM_1.MUX_6_CSC.B.SELCTL = CORE_PLL_PHI9_CLK_ID;
    MC_CGM_1.MUX_6_CSC.B.CLK_SW = 1;									// Trigger the clock switch and wait until complete
    while(MC_CGM_1.MUX_6_CSC.B.CLK_SW != 0);
    while(MC_CGM_1.MUX_6_CSS.B.SWIP != 0x0);
    while(MC_CGM_1.MUX_6_CSS.B.SWTRG != 0x1); 							// Check switch was successful and verify the selected clock
    while(MC_CGM_1.MUX_6_CSS.B.SELSTAT != CORE_PLL_PHI9_CLK_ID);

    MC_CGM_1.MUX_6_DC_0.B.DE = 1;										// Enable Divider
    while (MC_CGM_1.MUX_6_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    /*-----------------------------------------------
     * MC_CGM_2
     *---------------------------------------------*/

    /* MC_CGM_2 MUX_1
     * GMAC_1_TS_CLK = PERIPH_PLL_PHI4_CLK / 1 = 200 MHz / 1 = 200 MHz */

    MC_CGM_2.MUX_1_DC_0.B.DE = 0;										// Disable Divider
    while (MC_CGM_2.MUX_1_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete
    MC_CGM_2.MUX_1_DC_0.B.DIV = 0;										// Set Divider to 1
    while (MC_CGM_2.MUX_1_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

    while(MC_CGM_2.MUX_1_CSS.B.SWIP != 0x0);
    MC_CGM_2.MUX_1_CSC.B.SELCTL = PERIPH_PLL_PHI4_CLK_ID;
    MC_CGM_2.MUX_1_CSC.B.CLK_SW = 1;									// Trigger the clock switch and wait until complete
    while(MC_CGM_2.MUX_1_CSC.B.CLK_SW != 0);
    while(MC_CGM_2.MUX_1_CSS.B.SWIP != 0x0);
    while(MC_CGM_2.MUX_1_CSS.B.SWTRG != 0x1); 							// Check switch was successful and verify the selected clock
    while(MC_CGM_2.MUX_1_CSS.B.SELSTAT != PERIPH_PLL_PHI4_CLK_ID);

    MC_CGM_2.MUX_1_DC_0.B.DE = 1;										// Enable Divider
    while (MC_CGM_2.MUX_1_DIV_UPD_STAT.B.DIV_STAT);						// Wait for divider update to complete

}

static void dfs_periph_init()
{
    /* Fout = Fin / (2 x (DVPORT[MFI] + DVPORT[MFN]/36)
     * Fin = PERIPH_PLL_VCO_CLK = 2000 MHz */

    /* Disable all ports */
    PERIPH_DFS.PORTRESET.R = 0x3;
    /* Check PORTSR is 0 */
    while(PERIPH_DFS.PORTSR.R != 0x00000000);
    /* Disable DFS */
    PERIPH_DFS.CTL.R |= 0x00000002;
    /* Clear any residual sticky flag before configuring */
    PERIPH_DFS.PORTLOLSR.R = 0x3;

    /* PERIPH_DFS1_CLK ->  CGM_0.MUX_5 -> QSPI_CLK
     * MFI set to 1
     * MFN set to 9 (9/36 = 0.25)
     * Hence Fin is divided by 2 x 1.25 = 2.5
     * 2000 / 2 * (1 + 8 / 36) = 800 MHz */
    PERIPH_DFS.DVPORT[0].R = (1 << DVPORT_MFI_OFFSET) | 9;
    /* PERIPH_DFS3_CLK -> CGM_1.MUX_5 -> NOC_TRACE_CLK
     * MFI set to 1
     * MFN set to 9 (9/36 = 0.25)
     * Hence Fin is divided by 2 x 1.25 = 2.5
     * 2000 / 2 * (1 + 9 / 36) = 800 MHz */
    PERIPH_DFS.DVPORT[1].R = (1 << DVPORT_MFI_OFFSET) | 9;

    /* Enable DFS */
    PERIPH_DFS.CTL.R = 0;
    /* Enable all ports */
    PERIPH_DFS.PORTRESET.R = 0x0;
    /* Wait til all configured ports are locked */
    while(PERIPH_DFS.PORTSR.R != 0x00000003);
}

static void pll_core()
{
    uint8_t i;

    /* f(pll_vco) = (f(pll_ref)/PLLDV[RDIV]) * ((PLLDV[MFI]) + (PLLFD[MFN])/18432)
     * PLL_VCO = 2.4 GHz (R41)
     * f(pll_ref) = 40 (40 MHz)
     * PLLDV[RDIV] = 1
     * PLLDV[MFI] = 60 (R41)
     */

    /* 1. Confirm that PLLODIV_n[DE] is 0 for all dividers. */
    for (i = 0; i < 10; i++)
    {
        CORE_PLL.PLLODIV[i].B.DE = 0;
    }

    /* 2. Confirm that PLLCR[PLLPD] is 1. */
    CORE_PLL.PLLCR.R = 0x80000000;

    /* 3. Program PLLCLKMUX to select appropriate PLL reference clock.
     * Select FXOSC (40MHz) as the reference (PLLCLKMUX = 1) */
    CORE_PLL.PLLCLKMUX.R = 0x00000001;

    /* 4. Program the following as needed: PLLDV, PLLFD, PLLFM to the desired value. */
    /* PLLDV[RDIV] = 0 (divide by 1), [MFI] = 60. Results in f(pll_vco) = 2.4 GHz */
    CORE_PLL.PLLDV.B.MFI = 60;
    /* PLLFM and PLLFD left at reset because SSCG and fractional divide not used */

    /* 5. Program field PLLODIV_n[DIV] to the desired value. */
    /* PLL PHI 0 CLK - CGM_1.MUX_0 -> CORE_CLK (A53_CORE_CLK)
     * Divider = 2+1, freq = 2400/3 = 800 MHz */
    CORE_PLL.PLLODIV[0].R = 2 << PLLO_DIV_OFFSET;
    /* PLL PHI 1 CLK - CGM_1.MUX_1 -> ACCEL_CLK
     * Divider = 3+1, freq = 2400/4 = 600 MHz */
    CORE_PLL.PLLODIV[1].R = 3 << PLLO_DIV_OFFSET;
    /* PLL PHI 2 CLK - CGM_1.MUX_2 -> ACCEL__XBAR_CL
     * Divider = 5+1, freq = 2400/6 = 400 MHz */
    CORE_PLL.PLLODIV[2].R = 5 << PLLO_DIV_OFFSET;
    /* PLL PHI 3 CLK - CGM_1.MUX_3 -> CTE_CLK, CSI_IPS_CLK
     * Divider = 29+1, freq = 2400/30 = 80 MHz */
    CORE_PLL.PLLODIV[3].R = 29 << PLLO_DIV_OFFSET;
    /* PLL PHI 4 CLK - CGM_1.MUX_4 -> CSI_TXCLK_ESC/CSI_CFG_CLK
     * Divider = 59+1, freq = 2400/60 = 40 MHz */
    CORE_PLL.PLLODIV[4].R = 59 << PLLO_DIV_OFFSET;
    /* PLL PHI 5 CLK - CGM_0.MUX_1 -> CLKOUT0, CGM_0.MUX_2 -> CLKOUT1
     * Divider = 11+1, freq = 2400/12 = 200 MHz */
    CORE_PLL.PLLODIV[5].R = 11 << PLLO_DIV_OFFSET;
    /* PLL PHI 6 CLK - CGM_0.MUX_0 -> SYS_CLK
     * Divider = 5+1, freq = 2400/6 = 400 MHz */
    CORE_PLL.PLLODIV[6].R = 5 << PLLO_DIV_OFFSET;
    /* PLL PHI 7 CLK - NC
     *  */
    //CORE_PLL.PLLODIV[7].R = 0 << PLLO_DIV_OFFSET;
    /* PLL PHI 8 CLK - CGM_1.MUX_5 -> NOC_TRACE_CLK
     * Divider = 2+1, freq = 2400/3 = 800 MHz */
    CORE_PLL.PLLODIV[8].R = 2 << PLLO_DIV_OFFSET;
    /* PLL PHI 9 CLK - CGM_1.MUX_6 -> LBIST_CLK[7:0]
     *  Divider = 47+1, freq = 2400/48 = 50 MHz */
    CORE_PLL.PLLODIV[9].R = 47 << PLLO_DIV_OFFSET;

    /* 6. Wait for the PLL reference clock to be stable
     * FXOSC already stabilized in fxosc_init() */

    /* 7. Write PLLCR[PLLPD] = 0 */
    CORE_PLL.PLLCR.R = 0x0;

    /* 8. Wait for field PLLSR[LOCK] = 1. */
    while(!CORE_PLL.PLLSR.B.LOCK);

    /* 9. Write PLLODIV[DE] = 1 */
    for (i = 0; i < 10; i++)
    {
        if (i == 7)
            continue;
        CORE_PLL.PLLODIV[i].B.DE = 1;
    }
}

static void pll_peripheral(void)
{
    uint8_t i;

	/* f(pll_vco) = (f(pll_ref)/PLLDV[RDIV]) * ((PLLDV[MFI]) + (PLLFD[MFN])/18432)
	* f(pll_ref) = 40 (40 MHz)
	* PLL_VCO = 2000 MHz
	*/

    /* 1. Confirm that PLLODIV_n[DE] is 0 for all dividers. */
    for (i = 0; i < 10; i++)
    {
        PERIPH_PLL.PLLODIV[i].B.DE = 0;
    }

	/* 2. Confirm that PLLCR[PLLPD] is 1. */
	PERIPH_PLL.PLLCR.R = 0x80000000;

	/* 3. Program PLLCLKMUX to select appropriate PLL reference clock.
	 * Select FXOSC (40 MHz) as the reference (PLLCLKMUX = 1) */
	PERIPH_PLL.PLLCLKMUX.R = 0x00000001;

	/* 4. Program the following as needed: PLLDV, PLLFD, PLLFM to the desired value. */
	/* PLLDV[RDIV] = 0 (divide by 1), [MFI] = 50. Results in f(pll_vco) = 2 GHz */
	PERIPH_PLL.PLLDV.B.MFI = 50;
	/* PLLFM and PLLFD left at reset because SSCG and fractional divide not used */

	/* 5. Program field PLLODIV_n[DIV] to the desired value. */
    /* PLL PHI 0 CLK - CGM_0.MUX_0 -> SYS_CLOCK
     *  Divider = 4+1, freq = 2000/5 = 400 MHz */
    PERIPH_PLL.PLLODIV[0].R = 4 << PLLO_DIV_OFFSET;
    /* PLL PHI 1 CLK - CGM_0.MUX_3 -> MC_CLK
     *  Divider = 24+1, freq = 2000/25 = 80 MHz */
    PERIPH_PLL.PLLODIV[1].R = 24 << PLLO_DIV_OFFSET;
    /* PLL PHI 2 CLK - CGM_0.MUX_7 -> CAN_PE CLK
     * Divider = 24+1, freq = 2000/25 = 80 MHz */
    PERIPH_PLL.PLLODIV[2].R = 24 << PLLO_DIV_OFFSET;
    /* PLL PHI 3 CLK - CGM_0.MUX_8 -> LIN_BAUD CLK, LINFLEXD_CLK(LIN_BAUD_CLK/2)
    Divider = 19+1, Freq = 2000/20 = 100 MHz */
    PERIPH_PLL.PLLODIV[3].R = 19 << PLLO_DIV_OFFSET;
    /* PLL PHI 4 CLK - CGM_3.MUX_1 -> GMAC_0_TS_CLK
     * Divider = 9+1, freq = 2000/10 = 200 MHz*/
    PERIPH_PLL.PLLODIV[4].R = 9 << PLLO_DIV_OFFSET;
    /* PLL PHI 5 CLK - CGM_0.MUX_6 -> GMAC_0_TX_CLK, CAN_TS, CAN_CHI, FCCU_IPS_CLK, STCU_CLK, DAPB_CLK, CTU_IPS_CLK, TMU_CLK
     * Divider = 3+1, freq = 2000/4 = 500 MHz */
    PERIPH_PLL.PLLODIV[5].R = 3 << PLLO_DIV_OFFSET;
    /* PLL PHI 6 CLK - CGM_3_MUX_3 -> GMAC_0_REF_CLK, GMAC_0_REF_DIV_CLK
     * Divider = 39+1, freq = 2000/40 = 50 MHz */
    PERIPH_PLL.PLLODIV[6].R = 39 << PLLO_DIV_OFFSET;  // /40 = 50 MHz
    //PERIPH_PLL.PLLODIV[6].R = 19 << PLLO_DIV_OFFSET;    // /20 = 100 MHz
    /* PLL PHI 7 CLK - CGM_0.MUX_4 -> SPI_CLK
     * Divider = 19+1, freq = 2000/20 = 100 MHz */
    PERIPH_PLL.PLLODIV[7].R = 19 << PLLO_DIV_OFFSET;    // /20 = 100 MHz
    //PERIPH_PLL.PLLODIV[7].R = 39 << PLLO_DIV_OFFSET; // /40 = 50 MHz
    /* PLL PHI 8 CLK - ?
     * Divider = 4+1, freq = 2000/5 = 400 MHz */
    PERIPH_PLL.PLLODIV[8].R = 4 << PLLO_DIV_OFFSET;
    /* PLL PHI 9 CLK - CGM_0.MUX_5 -> QSPI_CLK
     * Divider = 6+1, freq = 2000/7 = 286 MHz */
    PERIPH_PLL.PLLODIV[9].R = 6 << PLLO_DIV_OFFSET;

	/* 6. Wait for the PLL reference clock to be stable
	 * FXOSC already stabilized in fxosc_init() */

	/* 7. Write PLLCR[PLLPD] = 0 */
	PERIPH_PLL.PLLCR.R = 0x00000000;

	/* 8. Wait for field PLLSR[LOCK] = 1. */
	while(!PERIPH_PLL.PLLSR.B.LOCK);

	/* 9. Write PLLODIV_n[DE] = 1.*/
    for (i = 0; i < 10; i++)
    {
        PERIPH_PLL.PLLODIV[i].B.DE = 1;
    }
}

static void fxosc_init()
{
	/* Osc not bypassed, comparator enabled, osc on.
	   OCV = 78 (1ms wait time at 40 MHz), GM_SEL = 0xF (1.0x) */
    FXOSC.CTRL.B.OSC_BYP = 0;
    FXOSC.CTRL.B.COMP_EN = 1;
    FXOSC.CTRL.B.GM_SEL = 0xF; // 0b1111 = 1.0x
    FXOSC.CTRL.B.EOCV = 78;
    FXOSC.CTRL.B.OSCON = 1;

	/* Wait condition to check crystal oscillator is on and providing a stable clock*/
	while (FXOSC.STAT.R != 0x80000000);

	return;
}

static void init_clocks(void)
{
    /* Turn on FXOSC */
    fxosc_init();

    /* Set-up PLLS */
    pll_peripheral();
    pll_core();

    /* Set-up DFS */
    dfs_periph_init();

    /* Configure CGM selectors and dividers */
    cgm_init();
}


#ifdef CONFIG_PINS
static void siul2_dspi(void)
{
	//only SPI1 and 2 are needed, to connect with the RFE

    /* DSPI_1_SCK: PC_11 */
	SIUL2_0.MSCR[43].R = (B_OBE | B_SRE(7) | B_SSS(1)); // B_SSS = 001, B_IBE = 0, B_OBE = 1
	/* DSPI_1_SOUT: PC_12 */
	SIUL2_0.MSCR[44].R = (B_OBE | B_SRE(7) | B_SSS(1)); // B_SSS = 001, B_IBE = 0, B_OBE = 1
	/* DSPI_1_SIN: PC_13 */
	SIUL2_0.MSCR[45].R = B_IBE; // B_SSS = 001, B_SRE = 100, B_IBE = 1, B_OBE = 1
	SIUL2_0.IMCR[B_IMCR(541)].R = 1; // B_SSS = 001
	/* DSPI_1_PCS0: PC_14 */
	SIUL2_0.MSCR[46].R = (B_OBE | B_SRE(7) | B_SSS(1)); // B_SSS = 001, B_IBE = 0, B_OBE = 1

	/* DSPI_2_SCK: PD_00 */
	SIUL2_0.MSCR[48].R = (B_OBE | B_SSS(2)); // B_SSS = 010, B_IBE = 0, B_OBE = 1
	/* DSPI_2_SOUT: PD_01 */
	SIUL2_0.MSCR[49].R = (B_OBE | B_SRE(7) | B_SSS(2)); // B_SSS = 010, B_IBE = 0, B_OBE = 1
	/* DSPI_2_SIN: PD_02 */
	SIUL2_0.MSCR[50].R = B_IBE; // B_IBE = 1
	SIUL2_0.IMCR[B_IMCR(544)].R = 1; // B_SSS = 001
	/* DSPI_2_PCS0: PD_03 */
	SIUL2_0.MSCR[51].R = (B_OBE | B_SSS(2)); // B_SSS = 010, B_IBE = 0, B_OBE = 1
}

static void siul_lin_0()
{
    /* LIN_0_TX: PD_10 */
    SIUL2_0.MSCR[58].R = (B_OBE | B_SRE(4) | B_SSS(1)); // SSS = 001, SRE = 100, IBE = 0, OBE = 1

    /* LIN_0_RX: PD_11 */
    SIUL2_0.MSCR[59].R = B_IBE; // IBE = 1
    SIUL2_0.IMCR[B_IMCR(608)].R = 2; // SSS = 2
}

static void siul2_setup(void)
{
    siul_lin_0();
#ifdef RFE_ENABLE
    siul2_dspi();
    RsdkGlueGPIOInit();
#endif
}
#endif

//STM0 and STM1 are clocked by SYS_CLK/2 = 200 MHz
//STM_2 is clocked by ACCEL_XBAR_CLK/4 = 100 MHz
#define STM_CLOCK_MHZ 200u

// Must be used after platform setup, as it assumes XBAR_DIV3_CLK clock of value STM_CLOCK_MHZ
// return 0 for success
// see also RsdkDelayMs(), RsdkDelayUs() and RsdkTimeOutArmUs()
uint32_t RsdkSTMInit(void)
{
    // set  TEN=1 (enable) and CPS=0 (clock divider=1) to enable STM_0
    STM_0.CR.R = 0x1;

    // zero STM0 count (note: STM_0 increments with time)
    STM_0.CNT.R = 0;

    return 0;
}

/*-------------------------------------------------------------------------------------------------*/

// Core will busy wait delayUs microseconds
// return 0 for success
// see notes on RsdkDelayMs() and RsdkSTMInit()
uint32_t RsdkDelayUs(uint32_t us)
{
    uint32_t currTimeStamp;
    uint32_t res = GLUE_TIMER_SUCCESS;

    if (STM_0.CR.B.TEN != 0x1)  //has timer been started previously
    {
        res = GLUE_TIMER_ERR_NOT_INIT;
    }

    if (us >= (UINT32_MAX / STM_CLOCK_MHZ)) /*so that multiplication below still fits uint32_t*/
    {
        res = GLUE_TIMER_ERR_DELAY;
    }

    // The a53 at 1GHz has problems with using the STM for delays of 1us
    if (us == 1)
    {
        us = 2;
    }

    if (res == GLUE_TIMER_SUCCESS)
    {

#ifdef ARMCM7_SP
    	__disable_irq();
#else
        interruptsDisable();
#endif

        currTimeStamp = STM_0.CNT.R;
        STM_0.CHANNEL[0].CMP.R = currTimeStamp + (us * STM_CLOCK_MHZ); /*uint wraps around over UINT32_MAX*/
        STM_0.CHANNEL[0].CCR.B.CEN = 1;                                /*enable channel*/

#ifdef ARMCM7_SP
        __enable_irq();
#else
        interruptsEnable();
#endif

        while (STM_0.CHANNEL[0].CIR.B.CIF == 0)
        {
        }

        STM_0.CHANNEL[0].CIR.B.CIF = 1; /*clear interrupt*/
        STM_0.CHANNEL[0].CCR.B.CEN = 0; /*disable channel*/
    }

    return res;
}

/*-------------------------------------------------------------------------------------------------*/

// Core will busy wait delayMs miliseconds
// return 0 for success
// Attn: this function distructively uses of STM counter of current core.
//       Must be used after platform setup and after calling RsdkSTMInit()
uint32_t RsdkDelayMs(uint32_t ms)
{
    if (ms >= (UINT32_MAX / 1000u)) /*so that param for RsdkDelayUs() below still fits uint32_t*/
    {
        return GLUE_TIMER_ERR_DELAY;
    }
    else
    {
        return RsdkDelayUs(ms * 1000);
    }
}

/*-------------------------------------------------------------------------------------------------*/

//in useconds, mind it wraps around (have no fear, uint32_t wraps around, too)
//assumes ref clock value in STM_CLOCK_MHZ
//NB: invoke RsdkSTMInit() before this
uint32_t RsdkTimerGetValue(void)
{
    return (STM_0.CNT.R / STM_CLOCK_MHZ);
}

/*-------------------------------------------------------------------------------------------------*/

//channel must be a positive value (max 4 for STM)
//returns 0 for success
//NB: invoke RsdkSTMInit() before this
uint32_t RsdkTimeOutArmUs(uint32_t us, uint32_t channel)
{
    uint32_t currTimeStamp;
    uint32_t res = GLUE_TIMER_SUCCESS;

    if (STM_0.CR.B.TEN != 0x1)  //has timer been started previously
    {
        res = GLUE_TIMER_ERR_NOT_INIT;
    }

    if (res == GLUE_TIMER_SUCCESS)
    {
        if ((channel < 1u) || (channel > 4u))
        {
            res = GLUE_TIMER_ERR_CHANNEL;
        }
    }

    if (us >= (UINT32_MAX / STM_CLOCK_MHZ)) /*so that multiplication below still fits uint32_t*/
    {
        res = GLUE_TIMER_ERR_DELAY;
    }

    if (res == GLUE_TIMER_SUCCESS)
    {
#ifdef ARMCM7_SP
    	__disable_irq();
#else
        interruptsDisable();
#endif
        currTimeStamp = STM_0.CNT.R;
        /*have no fear, uint wraps around over UINT32_MAX*/
        STM_0.CHANNEL[channel].CMP.R = currTimeStamp + (us * STM_CLOCK_MHZ);
        STM_0.CHANNEL[channel].CCR.B.CEN = 1; /*enable channel*/
#ifdef ARMCM7_SP
        __enable_irq();
#else
        interruptsEnable();
#endif
    }

    return res;
}

/*-------------------------------------------------------------------------------------------------*/

//channel must be a positive value
//NB: arm the timer with RsdkTimeOutArmUs() on the same channel
//returns 0 for success
uint32_t RsdkTimeOutDisarm(uint32_t channel)
{
    uint32_t res = GLUE_TIMER_SUCCESS;

    if (STM_0.CR.B.TEN != 0x1)  //has timer been started previously
    {
        res = GLUE_TIMER_ERR_NOT_INIT;
    }

    if (res == GLUE_TIMER_SUCCESS)
    {
        if ((channel < 1u) || (channel > 4u))
        {
            res = GLUE_TIMER_ERR_CHANNEL;
        }
    }

    if (res == GLUE_TIMER_SUCCESS)
    {
        STM_0.CHANNEL[channel].CCR.B.CEN = 0; /*disable channel*/
    }

    return res;
}

/*-------------------------------------------------------------------------------------------------*/

//returns 255 if timer has expired, 0 if still ticking and a positive value in case of error
//NB: arm the timer with RsdkTimeOutArmUs() on the same channel
uint32_t RsdkTimeOutHasExpired(uint32_t channel)
{
    uint32_t expired = GLUE_TIMER_SUCCESS;

    if (STM_0.CR.B.TEN != 0x1)  //has timer been started previously
    {
        expired = GLUE_TIMER_ERR_NOT_INIT;
    }

    if (expired == GLUE_TIMER_SUCCESS)
    {
        if ((channel < 1u) || (channel > 4u))
        {
            expired = GLUE_TIMER_ERR_CHANNEL;
        }
    }

    if (expired == GLUE_TIMER_SUCCESS)
    {
        expired = (STM_0.CHANNEL[channel].CIR.B.CIF != 0) ? GLUE_TIMER_EXPIRED : GLUE_TIMER_SUCCESS;
    }

    if (expired == GLUE_TIMER_EXPIRED)
    {
        STM_0.CHANNEL[channel].CIR.B.CIF = 1; /*clear interrupt*/
    }

    return expired;
}

/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/


// Platform setup wrapper
appStatus_t RsdkPlatformSetup(platformType_t platformType)
{
    appStatus_t status = APP_STATUS_SUCCESS;

    switch (platformType)
    {
        case PLAT_TYPE_S32R41_EVB:

#ifdef ARMCM7_SP
        	interrupts_cm7_enable();
#else
            interrupts_init();
#endif
            (void)init_clocks();

            xrdc_ConfigureEnable();

            /* Enable partition 1 (A53, SPT, BBE32).
             * Release the global reset that governs reset for entire partition */
            status = platform_partition_enable(1, MC_RGM_PERIPH_RST_CA53_GLOBAL);
            /* Enable clock to functional blocks */
            status = platform_block_enable(1, (MC_ME_PRTN1_COFB0_SPT | MC_ME_PRTN1_COFB0_BBE32 | MC_ME_PRTN1_COFB_MIPICSI2));

#ifdef CONFIG_PINS
            //configure the GPIO pins
            siul2_setup();
#endif
            RsdkSTMInit();

        	break;
        default:
            status = APP_STATUS_ERROR;  // incorrect platformType specified
            break;
    }

    return status;
}


#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
