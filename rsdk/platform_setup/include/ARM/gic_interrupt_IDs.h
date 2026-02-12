/*
 * Copyright 2020-2021 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef GIC_INTERRUPT_IDS_H_
#define GIC_INTERRUPT_IDS_H_

typedef enum
{


















































































































































































































































































    INT_SGI_0 = 0,
    INT_SGI_1 = 1,
    INT_SGI_2 = 2,
    INT_SGI_3 = 3,
    INT_SGI_4 = 4,
    INT_SGI_5 = 5,
    INT_SGI_6 = 6,
    INT_SGI_7 = 7,
    INT_SGI_8 = 8,
    INT_SGI_9 = 9,
    INT_SGI_10 = 10,
    INT_SGI_11 = 11,
    INT_SGI_12 = 12,
    INT_SGI_13 = 13,
    INT_SGI_14 = 14,
    INT_SGI_15 = 15,
    /* reserved             = 16, */
    /* reserved             = 17, */
    /* reserved             = 18, */
    /* reserved             = 19, */
    /* reserved             = 20, */
    /* reserved             = 21, */
    INT_PPI_CC_RX_TX        = 22,
    INT_PPI_PMU             = 23,
    INT_PPI_CTI             = 24,
    INT_PPI_VMI             = 25,
    INT_PPI_HYP_TIMER       = 26,
    INT_PPI_VTIMER          = 27,
    INT_PPI_EL2_VTIMER      = 28,
    INT_PPI_STIMER          = 29,
    INT_PPI_NSTIMER         = 30,
    /* reserved             = 31, */
    /* reserved             = 32, */
    INT_CPU_TO_CPU_INT_0    = 33,
    INT_CPU_TO_CPU_INT_1    = 34,
    INT_CPU_TO_CPU_INT_2    = 35,
    INT_CPU_TO_CPU_INT_3    = 36,
    /* reserved             = 37, */
    /* reserved             = 38, */
    /* reserved             = 39, */
    INT_DMA_0_CH_0_15       = 40,
    INT_DMA_0_CH_16_31      = 41,
    INT_DMA_0_ERR           = 42,
    /* reserved             = 43, */
    /* reserved             = 44, */
    /* reserved             = 45, */
    INT_SWT_0               = 46,
    INT_SWT_1               = 47,
    INT_SWT_2               = 48,
    /* reserved             = 49, */
    /* reserved             = 50, */
    /* reserved             = 51, */
    /* reserved             = 52, */
    /* reserved             = 53, */
    /* reserved             = 54, */
    /* reserved             = 55, */
    INT_STM_0               = 56,
    INT_STM_1               = 57,
    INT_STM_2               = 58,
    /* reserved             = 59, */
    /* reserved             = 60, */
    /* reserved             = 61, */
    /* reserved             = 62, */
    /* reserved             = 63, */
    INT_QSPI_0              = 64,
    INT_QSPI_FLASH_A_ERR    = 65,
    /* reserved             = 66, */
    INT_STCU_BIST           = 67,
    /* reserved             = 68, */
    INT_FLEXCAN_0_BUS_OFF   = 69,
    INT_FLEXCAN_0_ERR       = 70,
    INT_FLEXCAN_0_MBIL_7_0  = 71,
    INT_FLEXCAN_0_MBIL_95_8 = 72,
    INT_FLEXCAN_1_BUS_OFF   = 73,
    INT_FLEXCAN_1_ERR       = 74,
    INT_FLEXCAN_1_MBIL_7_0  = 75,
    INT_FLEXCAN_1_MBIL_95_8 = 76,
    /* reserved             = 77, */
    /* reserved             = 78, */
    /* reserved             = 79, */
    /* reserved             = 80, */
    /* reserved             = 81, */
    /* reserved             = 82, */
    /* reserved             = 83, */
    /* reserved             = 84, */
    INT_PIT_0               = 85,
    INT_CMU_1               = 86,
    INT_FTM_0               = 87,
    INT_CMU_12              = 88,
    INT_GMAC_0_ERROR        = 89,
    INT_GMAC_0_CH0_TX       = 90,
    INT_GMAC_0_CH0_RX       = 91,
    INT_GMAC_0_CH1_TX       = 92,
    INT_GMAC_0_CH1_RX       = 93,
    /* reserved             = 94, */
    /* reserved             = 95, */
    /* reserved             = 96, */
    /* reserved             = 97, */
    /* reserved             = 98, */
    /* reserved             = 99, */
    /* reserved             = 100, */
    /* reserved             = 101, */
    INT_ADC_0               = 102,
    /* reserved             = 103, */
    /* reserved             = 104, */
    /* reserved             = 105, */
    /* reserved             = 106, */
    /* reserved             = 107, */
    /* reserved             = 108, */
    /* reserved             = 109, */
    /* reserved             = 110, */
    /* reserved             = 111, */
    /* reserved             = 112, */
    /* reserved             = 113, */
    INT_LINFLEXD_0          = 114,
    /* reserved             = 115, */
    /* reserved             = 116, */
    INT_SPI_0               = 117,
    INT_SPI_1               = 118,
    INT_SPI_2               = 119,
    INT_SPI_3               = 120,
    /* reserved             = 121, */
    /* reserved             = 122, */
    /* reserved             = 123, */
    INT_I2C_0               = 124,
    INT_I2C_1               = 125,
    /* reserved             = 126, */
    /* reserved             = 127, */
    /* reserved             = 128, */
    /* reserved             = 129, */
    INT_MC_RGM              = 130,
    /* reserved             = 131, */
    INT_FCCU_ALARM          = 132,
    INT_FCCU_TO             = 133,
    /* reserved             = 134, */
    INT_HSE_TX_MU0          = 135,
    INT_HSE_RX_MU0          = 136,
    INT_HSE_GPIRQ_MU0       = 137,
    INT_HSE_TX_MU1          = 138,
    INT_HSE_RX_MU1          = 139,
    INT_HSE_GPIRQ_MU1       = 140,
    INT_HSE_TD              = 141,
    /* reserved             = 142, */
    /* reserved             = 143, */
    /* reserved             = 144, */
    /* reserved             = 145, */
    /* reserved             = 146, */
    /* reserved             = 147, */
    /* reserved             = 148, */
    INT_CTU_FIFO_0_4        = 149,
    INT_CTU_TRIG            = 150,
    INT_CTU_ERR             = 151,
    INT_TMU_ALARM           = 152,
    INT_TMU_CRIT            = 153,
    /* reserved             = 154, */
    /* reserved             = 155, */
    /* reserved             = 156, */
    /* reserved             = 157, */
    /* reserved             = 158, */
    /* reserved             = 159, */
    /* reserved             = 160, */
    /* reserved             = 161, */
    /* reserved             = 162, */
    /* reserved             = 163, */
    /* reserved             = 164, */
    /* reserved             = 165, */
    /* reserved             = 166, */
    /* reserved             = 167, */
    /* reserved             = 168, */
    /* reserved             = 169, */
    /* reserved             = 170, */
    /* reserved             = 171, */
    /* reserved             = 172, */
    /* reserved             = 173, */
    /* reserved             = 174, */
    /* reserved             = 175, */
    /* reserved             = 176, */
    /* reserved             = 177, */
    /* reserved             = 178, */
    /* reserved             = 179, */
    /* reserved             = 180, */
    /* reserved             = 181, */
    /* reserved             = 182, */
    INT_CA53_L2_RAM_ECC     = 183,
    INT_CA53_AXI_ERR        = 184,
    /* reserved             = 185, */
    /* reserved             = 186, */
    INT_JDC                 = 187,
    /* reserved             = 188, */
    /* reserved             = 189, */
    /* reserved             = 190, */
    /* reserved             = 191, */
    /* reserved             = 192, */
    /* reserved             = 193, */
    /* reserved             = 194, */
    /* reserved             = 195, */
    /* reserved             = 196, */
    /* reserved             = 197, */
    /* reserved             = 198, */
    /* reserved             = 199, */
    /* reserved             = 200, */
    /* reserved             = 201, */
    /* reserved             = 202, */
    /* reserved             = 203, */
    INT_MIPI_0_RX_PATH       = 204,
    INT_MIPI_0_PNP_ERR       = 205,
    INT_MIPI_0_PATH_ERR      = 206,
    /* reserved             = 207, */
    /* reserved             = 208, */
    /* reserved             = 209, */
    INT_MIPI_1_RX_PATH       = 210,
    INT_MIPI_1_PNP_ERR       = 211,
    INT_MIPI_1_PATH_ERR      = 212,
    /* reserved             = 213, */
    /* reserved             = 214, */
    /* reserved             = 215, */
    /* reserved             = 216, */
    INT_SPT_DSP_ARITH_EXC   = 217,
    INT_SWT_3               = 218,
    INT_CTE_RADAR_EVT       = 219,
    INT_SPT_DSP_ERR         = 220,
    INT_SPT_EVENT           = 221,
    INT_SPT_ECS             = 222,
    INT_SPT_DMA_COMP        = 223,
    INT_PIT_2               = 224,
    /* reserved             = 225, */
    /* reserved             = 226, */
    /* reserved             = 227, */
    /* reserved             = 228, */
    /* reserved             = 229, */
    /* reserved             = 230, */
    /* reserved             = 231, */
    /* reserved             = 232, */
    /* reserved             = 233, */
    /* reserved             = 234, */
    /* reserved             = 235, */
    /* reserved             = 236, */
    /* reserved             = 237, */
    /* reserved             = 238, */
    /* reserved             = 239, */
    /* reserved             = 240, */
    /* reserved             = 241, */
    /* reserved             = 242, */
    /* reserved             = 243, */
    /* reserved             = 244, */
    /* reserved             = 245, */
    /* reserved             = 246, */
    /* reserved             = 247, */
    /* reserved             = 248, */
    /* reserved             = 249, */
    /* reserved             = 250, */
    /* reserved             = 251, */
    INT_GMAC_1_ERROR         = 252,
    INT_GMAC_1_CH0_TX        = 253,
    INT_GMAC_1_CH0_RX        = 254,
    INT_GMAC_1_CH1_TX        = 255,
    INT_GMAC_1_CH1_RX        = 256,
    /* reserved             = 257, */
    /* reserved             = 258, */
    /* reserved             = 259, */
    /* reserved             = 260, */
    /* reserved             = 261, */
    /* reserved             = 262, */
    /* reserved             = 263, */
    /* reserved             = 264, */
    /* reserved             = 265, */
    /* reserved             = 266, */
    /* reserved             = 267, */
    /* reserved             = 268, */
    INT_SIUL2_0_EIRQ        = 269,
    /* reserved             = 270, */
    /* reserved             = 271, */

} gic_int_id_t;

#endif /* INTERRUPTS_GIC_INTERRUPT_IDS_H_ */
