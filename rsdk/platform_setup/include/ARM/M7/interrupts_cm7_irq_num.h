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
 @file       interrupts_IDs_CM7.h
 @author     NXP

 @brief      This file contains interrupt identifiers/numbers
**************************************************************************************************/
#ifndef INTERRUPT_IDS_H_
#define INTERRUPT_IDS_H_

#define NUMBER_OF_INT_VECTORS 256                /**< Number of interrupts in the Vector table */

/*-----------------------------------------------
 * SAF86XX
 *---------------------------------------------*/





































































































































































































































































typedef enum {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M7 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M7 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M7 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M7 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M7 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M7 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M7 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M7 System Tick Interrupt */

  /* Device specific interrupts */
  /* reserved                  = 0, */
  INT0_IRQn                    = 1,                /**< Software generated CPU interrupt to M7/A53/BBE32 core - interrupt#0 */
  INT1_IRQn                    = 2,                /**< Software generated CPU interrupt to M7/A53/BBE32 core - interrupt#1 */
  INT2_IRQn                    = 3,                /**< Software generated CPU interrupt to M7/A53/BBE32 core - interrupt#2 */
  INT3_IRQn                    = 4,               /**< Software generated CPU interrupt to M7/A53/BBE32 core - interrupt#3 */
  CTI_0_IRQn                   = 5,                /**< CTI interrupt[0] */
  CTI_1_IRQn                   = 6,                /**< CTI interrupt[1] */
  MCM_IRQn                     = 7,                /**< Cortex M7 interrupt for FPU events and TCM errors */
  DMA0_0_15_IRQn               = 8,                /**< eDMA0 - DMA interrupt CH0-15 */
  DMA0_16_31_IRQn              = 9,                /**< eDMA0 - DMA interrupt CH16-31 */
  DMA0_ERR0_31_IRQn            = 10,               /**< eDMA0 - DMA error interrupt */
  /* reserved                  = 11, */
  /* reserved                  = 12, */
  /* reserved                  = 13, */
  SWT0_IRQn                    = 14,               /**< Watchdog timer interrupt */
  SWT1_IRQn                    = 15,               /**< Watchdog timer interrupt */
  SWT2_IRQn                    = 16,               /**< Watchdog timer interrupt */
  /* reserved                  = 17, */
  /* reserved                  = 18, */
  /* reserved                  = 19, */
  /* reserved                  = 20, */
  /* reserved                  = 21, */
  /* reserved                  = 22, */
  /* reserved                  = 23, */
  STM0_IRQn                    = 24,               /**< STM0 interrupt channel request 0, 1, 2, 3 */
  STM1_IRQn                    = 25,               /**< STM1 interrupt channel request 0, 1, 2, 3 */
  STM2_IRQn                    = 26,               /**< STM2 interrupt channel request 0, 1, 2, 3 */
  /* reserved                  = 27, */
  /* reserved                  = 28, */
  /* reserved                  = 29, */
  /* reserved                  = 30, */
  QUADSPI_ORED_IRQ             = 32,               /**< QSPI Ored interrupt via OTC */
  QUADSPI_FLASHA_IRQ           = 33,               /**< Flash A Error interrupt via OTC */
  /* reserved                  = 34, */
  STCU2_LBIST_IRQn             = 35,               /**< LBIST */
  /* reserved                  = 36, */
  CAN0_ORED_IRQn               = 37,               /**< CAN0 OR'ed Bus in Off State. */
  CAN0_ERR_IRQn                = 38,               /**< CAN0 Interrupt indicating that errors were detected on the CAN bus */
  CAN0_ORED_0_7_MB_IRQn        = 39,               /**< CAN0 OR'ed Message buffer (0-7),Rx FIFO Watermark, Rx FIFO Data Available, Rx FIFO Underflow, Rx FIFO Overflow */
  CAN0_ORED_8_95_MB_IRQn       = 40,               /**< CAN0 OR'ed Message buffer (8-95) */
  CAN1_ORED_IRQn               = 41,               /**< CAN1 OR'ed Bus in Off State */
  CAN1_ERR_IRQn                = 42,               /**< CAN1 Interrupt indicating that errors were detected on the CAN bus */
  CAN1_ORED_0_7_MB_IRQn        = 43,               /**< CAN1 OR'ed Message buffer (0-7),Rx FIFO Watermark, Rx FIFO Data Available, Rx FIFO Underflow, Rx FIFO Overflow */
  CAN1_ORED_8_95_MB_IRQn       = 44,               /**< CAN1 OR'ed Message buffer (8-95) */
  /* reserved                  = 45, */
  /* reserved                  = 46, */
  /* reserved                  = 47, */
  /* reserved                  = 48, */
  /* reserved                  = 49, */
  /* reserved                  = 50, */
  /* reserved                  = 51, */
  /* reserved                  = 52, */
  PIT0_IRQn                    = 53,               /**< OR'ed Interrupt for Channel 0, 1, 2, 3, 4, 5, 6 */
  CMU1_IRQn                    = 54,               /**< Frequency Higher or Lower than range >**/
  FTM0_IRQn                    = 55,               /**< OR'ed Interrupt for Channel 0, 1, 2, 3, 4, 5, Overflow, Reload */
  CMU12_IRQn                   = 56,               /**< Frequency Higher or Lower than range >**/
  GMAC0_Common_IRQn            = 57,               /**< Common Interrupt */
  GMAC0_CH0_TX_IRQn            = 58,               /**< Channel0 TX Interrupt */
  GMAC0_CH0_RX_IRQn            = 59,               /**< Channel0 RX Interrupt */
  GMAC0_CH1_TX_IRQn            = 60,               /**< Channel1 TX Interrupt */
  GMAC0_CH1_RX_IRQn            = 61,               /**< Channel1 RX Interrupt */
  /* reserved                  = 62, */
  /* reserved                  = 63, */
  /* reserved                  = 64, */
  /* reserved                  = 65, */
  /* reserved                  = 66, */
  /* reserved                  = 67, */
  /* reserved                  = 68, */
  /* reserved                  = 69, */
  SAR_ADC0_INT_IRQn            = 70,               /**< End of conv., ERROR and Analog Watchdog Interrupt */
  /* reserved                  = 71, */
  /* reserved                  = 72, */
  /* reserved                  = 73, */
  /* reserved                  = 74, */
  /* reserved                  = 75, */
  /* reserved                  = 76, */
  /* reserved                  = 77, */
  /* reserved                  = 78, */
  /* reserved                  = 79, */
  /* reserved                  = 80, */
  /* reserved                  = 81, */
  LINFLEXD0_IRQn               = 82,               /**< Internal all interrupt request */
  /* reserved                  = 83, */
  /* reserved                  = 84, */
  SPI0_IRQn                    = 85,               /**< OR'ed DSPI Global Interrupt */
  SPI1_IRQn                    = 86,               /**< OR'ed DSPI Global Interrupt */
  SPI2_IRQn                    = 87,               /**< OR'ed DSPI Global Interrupt */
  SPI3_IRQn                    = 88,               /**< OR'ed DSPI Global Interrupt */
  /* reserved                  = 89, */
  /* reserved                  = 90, */
  /* reserved                  = 91, */
  I2C0_IRQn                    = 92,               /**< Interrupt Request */
  I2C1_IRQn                    = 93,               /**< Interrupt Request */
  /* reserved                  = 94, */
  /* reserved                  = 95, */
  /* reserved                  = 96, */
  /* reserved                  = 97, */
  MC_RGM_IRQn                  = 98,               /**< Interrupt Request to System */
  /* reserved                  = 99, */
  FCCU_ALARM_IRQn              = 100,              /**< Interrupt request (ALARM state) */
  FCCU_MISC_IRQn               = 101,              /**< Interrupt request (miscellaneous conditions) */
  /* reserved                  = 102, */
  HSE_MU0_TX_IRQn              = 103,              /**< Ored tx interrupt to MU-0 */
  HSE_MU0_RX_IRQn              = 104,              /**< Ored rx interrupt to MU-0 */
  HSE_MU0_ORED_IRQn            = 105,              /**< ORed general purpose interrupt request to MU-0 */
  HSE_MU1_TX_IRQn              = 106,              /**< Ored tx interrupt to MU-1 */
  HSE_MU1_RX_IRQn              = 107,              /**< Ored rx interrupt to MU-1 */
  HSE_MU1_ORED_IRQn            = 108,              /**< ORed general purpose interrupt request to MU-1 */
  HSE_TD                       = 109,              /**< HSE tamper detect */
  /* reserved                  = 110, */
  /* reserved                  = 111, */
  /* reserved                  = 112, */
  /* reserved                  = 113, */
  /* reserved                  = 114, */
  /* reserved                  = 115, */
  CTU_FIFO_FULL_EMPTY_IRQn     = 117,              /**< FIFO 0,1,2,3 full  or empty or overflow or overrun interrupt */
  CTU_M_RELOAD_IRQn            = 118,              /**< Master reload interrupt,Trigger0 interrupt,Trigger1 interrupt,Trigger2 interrupt,Trigger3 interrupt,Trigger4 interrupt,Trigger5 interrupt,Trigger6 interrupt,Trigger7 interrupt,ADC command interrupt */
  CTU_ERR_IRQn                 = 119,              /**< Error interrupt */
  TMU_ALARM_IRQn               = 120,              /**< Level sensitive temperature alarm interrupt */
  TMU_CRIT_IRQn                = 121,              /**< Level sensitive citical temperature alarm interrupt */
  /* reserved                  = 122, */
  /* reserved                  = 123, */
  /* reserved                  = 124, */
  /* reserved                  = 125, */
  /* reserved                  = 126, */
  /* reserved                  = 127, */
  /* reserved                  = 128, */
  /* reserved                  = 129, */
  /* reserved                  = 130, */
  /* reserved                  = 131, */
  /* reserved                  = 132, */
  /* reserved                  = 133, */
  /* reserved                  = 134, */
  /* reserved                  = 135, */
  /* reserved                  = 136, */
  /* reserved                  = 137, */
  /* reserved                  = 138, */
  /* reserved                  = 139, */
  /* reserved                  = 140, */
  /* reserved                  = 141, */
  /* reserved                  = 142, */
  /* reserved                  = 143, */
  /* reserved                  = 144, */
  /* reserved                  = 145, */
  /* reserved                  = 146, */
  /* reserved                  = 147, */
  /* reserved                  = 148, */
  /* reserved                  = 149, */
  /* reserved                  = 150, */
  CORTEX_A53_ERR_L2RAM_IRQn    = 151,              /**< A53: Error indicator for L2 RAM double-bit ECC error */
  CORTEX_A53_ERR_AXI_IRQn      = 152,              /**< A53: Error indicator for AXI or CH bus error */
  /* reserved                  = 153, */
  /* reserved                  = 154, */
  JDC_IRQn                     = 155,              /**< Indicates data ready to be read from JIN_IPS register or new data can be written to JOUT_IPS register when asserted */
  /* reserved                  = 156, */
  /* reserved                  = 157, */
  /* reserved                  = 158, */
  /* reserved                  = 159, */
  /* reserved                  = 160, */
  /* reserved                  = 161, */
  /* reserved                  = 162, */
  /* reserved                  = 163, */
  /* reserved                  = 164, */
  /* reserved                  = 165, */
  /* reserved                  = 166, */
  /* reserved                  = 167, */
  /* reserved                  = 168, */
  /* reserved                  = 169, */
  /* reserved                  = 170, */
  /* reserved                  = 171, */
  MIPICSI2_0_INT0_IRQn         = 172,              /**< MIPI-CSI2_0 - Reports errors in the receive path */
  MIPICSI2_0_INT1_IRQn         = 173,              /**< MIPI-CSI2_0 - Protocol and Packet Level Error Reporting */
  MIPICSI2_0_INT2_IRQn         = 174,              /**< MIPI-CSI2_0 - Receive path errors like line length error/ line count error */
  /* reserved                  = 175, */
  /* reserved                  = 176, */
  /* reserved                  = 177, */
  MIPICSI2_1_INT0_IRQn         = 178,              /**< MIPI-CSI2_1 - Reports errors in the receive path */
  MIPICSI2_1_INT1_IRQn         = 179,              /**< MIPI-CSI2_1 - Protocol and Packet Level Error Reporting */
  MIPICSI2_1_INT2_IRQn         = 180,              /**< MIPI-CSI2_1 - Receive path errors like line length error/ line count error */
  /* reserved                  = 181, */
  /* reserved                  = 182, */
  /* reserved                  = 183, */
  /* reserved                  = 184, */
  SPT_DSP_ARITH_EXC_IRQn       = 185,              /**< SPT DSP arithmetic exception */
  SWT3_IRQn                    = 186,              /**< Watchdog timer interrupt */
  CTE_INT_IRQn                 = 187,              /**< Interrupt signal becomes high on the rising edge of the event defined in the interrupt status register at 0x0224 */
  SPT_DSP_ERR_IRQn             = 188,              /**< DSP error interrupt */
  SPT_EVENT_IRQn               = 189,              /**< SPT Event IRQ */
  SPT_ECS_IRQn                 = 190,              /**< ECS IRQ */
  SPT_DMA_COMPL_IRQn           = 191,              /**< Interrupt on DMA completion */
  PIT2_IRQn                    = 192,              /**< OR'ed Interrupt */
  /* reserved                  = 193, */
  /* reserved                  = 194, */
  /* reserved                  = 195, */
  /* reserved                  = 196, */
  /* reserved                  = 197, */
  /* reserved                  = 198, */
  /* reserved                  = 199, */
  /* reserved                  = 200, */
  /* reserved                  = 201, */
  /* reserved                  = 202, */
  /* reserved                  = 203, */
  /* reserved                  = 204, */
  /* reserved                  = 205, */
  /* reserved                  = 206, */
  /* reserved                  = 207, */
  /* reserved                  = 208, */
  /* reserved                  = 209, */
  /* reserved                  = 210, */
  /* reserved                  = 211, */
  /* reserved                  = 212, */
  /* reserved                  = 213, */
  /* reserved                  = 214, */
  /* reserved                  = 215, */
  /* reserved                  = 216, */
  /* reserved                  = 217, */
  /* reserved                  = 218, */
  /* reserved                  = 219, */
  GMAC1_Common_IRQn            = 220,              /**< Common Interrupt */
  GMAC1_CH0_TX_IRQn            = 221,              /**< Channel0 TX Interrupt */
  GMAC1_CH0_RX_IRQn            = 222,              /**< Channel0 RX Interrupt */
  GMAC1_CH1_TX_IRQn            = 223,              /**< Channel1 TX Interrupt */
  GMAC1_CH1_RX_IRQn            = 224,              /**< Channel1 RX Interrupt */
  /* reserved                  = 225, */
  /* reserved                  = 226, */
  /* reserved                  = 227, */
  /* reserved                  = 228, */
  /* reserved                  = 229, */
  /* reserved                  = 230, */
  /* reserved                  = 231, */
  /* reserved                  = 232, */
  /* reserved                  = 233, */
  /* reserved                  = 234, */
  /* reserved                  = 235, */
  /* reserved                  = 236, */
  SIUL2_0_INT_IRQn             = 237,              /**< External Interrupt Vector 0, External Interrupt Vector 1, External Interrupt Vector 2, External Interrupt Vector 3 */
  /* reserved                  = 238, */
  /* reserved                  = 239, */
} IRQn_Type;

#endif /* INTERRUPT_IDS_H_ */
