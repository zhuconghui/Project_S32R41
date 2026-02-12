/*
 * Copyright 2020-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
* @reg_es2_mipi.h
*/
#ifndef REG_ES2_MIPI_H
#define REG_ES2_MIPI_H
#include <stdint.h>
/**
* R2M02_TRIM_REG0_U16
* RegisterName: MOD02_TRIM_REG0
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x0A040018
*/
#define R2M02_TRIM_REG0_U16 (uint16_t)0x0000
/**
* R2M02_TRIM_REG1_U16
* RegisterName: MOD02_TRIM_REG1
* AccessMode: RW
* AddressRange: 0x0004 - 0x0008
* ResetValue: 0x4DB1100F
*/
#define R2M02_TRIM_REG1_U16 (uint16_t)0x0004
/**
* R2M02_TRIM_REG2_U16
* RegisterName: MOD02_TRIM_REG2
* AccessMode: RW
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x10000000
*/
#define R2M02_TRIM_REG2_U16 (uint16_t)0x0008
/**
* R2M02_TRIM_REG3_U16
* RegisterName: MOD02_TRIM_REG3
* AccessMode: RW
* AddressRange: 0x000C - 0x0010
* ResetValue: 0x0020C1FC
*/
#define R2M02_TRIM_REG3_U16 (uint16_t)0x000C
/**
* R2M02_DPHY_DFE_DLN_REGISTER_0_U16
* RegisterName: MOD02_DPHY_DFE_DLN_REGISTER_0
* AccessMode: RW
* AddressRange: 0x0020 - 0x0024
* ResetValue: 0x0A0D0716
*/
#define R2M02_DPHY_DFE_DLN_REGISTER_0_U16 (uint16_t)0x0020
/**
* R2M02_DPHY_DFE_DLN_REGISTER_1_U16
* RegisterName: MOD02_DPHY_DFE_DLN_REGISTER_1
* AccessMode: RW
* AddressRange: 0x0024 - 0x0028
* ResetValue: 0x00061E07
*/
#define R2M02_DPHY_DFE_DLN_REGISTER_1_U16 (uint16_t)0x0024
/**
* R2M02_DPHY_DFE_CLN_REGISTER_0_U16
* RegisterName: MOD02_DPHY_DFE_CLN_REGISTER_0
* AccessMode: RW
* AddressRange: 0x0028 - 0x002C
* ResetValue: 0x080D0521
*/
#define R2M02_DPHY_DFE_CLN_REGISTER_0_U16 (uint16_t)0x0028
/**
* R2M02_DPHY_DFE_CLN_REGISTER_1_U16
* RegisterName: MOD02_DPHY_DFE_CLN_REGISTER_1
* AccessMode: RW
* AddressRange: 0x002C - 0x0030
* ResetValue: 0x00000006
*/
#define R2M02_DPHY_DFE_CLN_REGISTER_1_U16 (uint16_t)0x002C
/**
* R2M02_PPI_DATA_LANE_SWAP_REGISTER_U16
* RegisterName: MOD02_PPI_DATA_LANE_SWAP_REGISTER
* AccessMode: RW
* AddressRange: 0x0034 - 0x0038
* ResetValue: 0x00000300
*/
#define R2M02_PPI_DATA_LANE_SWAP_REGISTER_U16 (uint16_t)0x0034
/**
* R2M02_FIFO_STATUS_REGISTER_U16
* RegisterName: MOD02_FIFO_STATUS_REGISTER
* AccessMode: R
* AddressRange: 0x0038 - 0x003C
* ResetValue: 0x00000000
*/
#define R2M02_FIFO_STATUS_REGISTER_U16 (uint16_t)0x0038
/**
* R2M02_USD_PIXEL_MODE_CONTROL_REGISTER_U16
* RegisterName: MOD02_USD_PIXEL_MODE_CONTROL_REGISTER
* AccessMode: RW
* AddressRange: 0x003C - 0x0040
* ResetValue: 0x00000000
*/
#define R2M02_USD_PIXEL_MODE_CONTROL_REGISTER_U16 (uint16_t)0x003C
/**
* R2M02_YUV_PIXEL_MODE_CONTROL_REGISTER_U16
* RegisterName: MOD02_YUV_PIXEL_MODE_CONTROL_REGISTER
* AccessMode: RW
* AddressRange: 0x0040 - 0x0044
* ResetValue: 0x00000000
*/
#define R2M02_YUV_PIXEL_MODE_CONTROL_REGISTER_U16 (uint16_t)0x0040
/**
* R2M02_RAW_PIXEL_MODE_CONTROL_REGISTER_U16
* RegisterName: MOD02_RAW_PIXEL_MODE_CONTROL_REGISTER
* AccessMode: RW
* AddressRange: 0x0044 - 0x0048
* ResetValue: 0x00000000
*/
#define R2M02_RAW_PIXEL_MODE_CONTROL_REGISTER_U16 (uint16_t)0x0044
/**
* R2M02_PHY_TINIT_COUNT_REGISTER_U16
* RegisterName: MOD02_PHY_TINIT_COUNT_REGISTER
* AccessMode: RW
* AddressRange: 0x0048 - 0x004C
* ResetValue: 0x0000FFFF
*/
#define R2M02_PHY_TINIT_COUNT_REGISTER_U16 (uint16_t)0x0048
/**
* R2M02_VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_1_U16
* RegisterName: MOD02_VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* AccessMode: RW
* AddressRange: 0x004C - 0x0050
* ResetValue: 0x00000000
*/
#define R2M02_VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_1_U16 (uint16_t)0x004C
/**
* R2M02_VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_2_U16
* RegisterName: MOD02_VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* AccessMode: RW
* AddressRange: 0x0050 - 0x0054
* ResetValue: 0x00000000
*/
#define R2M02_VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_2_U16 (uint16_t)0x0050
/**
* R2M02_VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_1_U16
* RegisterName: MOD02_VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* AccessMode: RW
* AddressRange: 0x0054 - 0x0058
* ResetValue: 0x00000000
*/
#define R2M02_VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_1_U16 (uint16_t)0x0054
/**
* R2M02_VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_2_U16
* RegisterName: MOD02_VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* AccessMode: RW
* AddressRange: 0x0058 - 0x005C
* ResetValue: 0x00000000
*/
#define R2M02_VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_2_U16 (uint16_t)0x0058
/**
* R2M02_VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_1_U16
* RegisterName: MOD02_VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* AccessMode: RW
* AddressRange: 0x005C - 0x0060
* ResetValue: 0x00000000
*/
#define R2M02_VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_1_U16 (uint16_t)0x005C
/**
* R2M02_VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_2_U16
* RegisterName: MOD02_VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* AccessMode: RW
* AddressRange: 0x0060 - 0x0064
* ResetValue: 0x00000000
*/
#define R2M02_VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_2_U16 (uint16_t)0x0060
/**
* R2M02_VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_1_U16
* RegisterName: MOD02_VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* AccessMode: RW
* AddressRange: 0x0064 - 0x0068
* ResetValue: 0x00000000
*/
#define R2M02_VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_1_U16 (uint16_t)0x0064
/**
* R2M02_VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_2_U16
* RegisterName: MOD02_VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* AccessMode: RW
* AddressRange: 0x0068 - 0x006C
* ResetValue: 0x00000000
*/
#define R2M02_VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_2_U16 (uint16_t)0x0068
/**
* R2M02_PLL_COUNT_REGISTER_U16
* RegisterName: MOD02_PLL_COUNT_REGISTER
* AccessMode: RW
* AddressRange: 0x006C - 0x0070
* ResetValue: 0x00004E20
*/
#define R2M02_PLL_COUNT_REGISTER_U16 (uint16_t)0x006C
/**
* R2M02_DEVICE_READY_INDICATION_REGISTER_U16
* RegisterName: MOD02_DEVICE_READY_INDICATION_REGISTER
* AccessMode: R
* AddressRange: 0x0070 - 0x0074
* ResetValue: 0x00000000
*/
#define R2M02_DEVICE_READY_INDICATION_REGISTER_U16 (uint16_t)0x0070
/**
* R2M02_CSI2_ADAPT_CONFIG_REG1_U16
* RegisterName: MOD02_CSI2_ADAPT_CONFIG_REG1
* AccessMode: RW
* AddressRange: 0x0080 - 0x0084
* ResetValue: 0x0000002C
*/
#define R2M02_CSI2_ADAPT_CONFIG_REG1_U16 (uint16_t)0x0080
/**
* R2M02_CSI2_ADAPT_CONFIG_REG2_U16
* RegisterName: MOD02_CSI2_ADAPT_CONFIG_REG2
* AccessMode: RW
* AddressRange: 0x0084 - 0x0088
* ResetValue: 0x0C810000
*/
#define R2M02_CSI2_ADAPT_CONFIG_REG2_U16 (uint16_t)0x0084
/**
* R2M02_CSI2_ADAPT_CONFIG_REG3_U16
* RegisterName: MOD02_CSI2_ADAPT_CONFIG_REG3
* AccessMode: RW
* AddressRange: 0x0088 - 0x008C
* ResetValue: 0x0000002B
*/
#define R2M02_CSI2_ADAPT_CONFIG_REG3_U16 (uint16_t)0x0088
/**
* R2M02_CSI2_CRC_CTRL1_U16
* RegisterName: MOD02_CSI2_CRC_CTRL1
* AccessMode: RW
* AddressRange: 0x008C - 0x0090
* ResetValue: 0xFFFFFFFF
*/
#define R2M02_CSI2_CRC_CTRL1_U16 (uint16_t)0x008C
/**
* R2M02_CSI2_CRC_CTRL2_U16
* RegisterName: MOD02_CSI2_CRC_CTRL2
* AccessMode: RW
* AddressRange: 0x0090 - 0x0094
* ResetValue: 0xFFFFFFFF
*/
#define R2M02_CSI2_CRC_CTRL2_U16 (uint16_t)0x0090
/**
* R2M02_CSI2_CRC_CTRL3_U16
* RegisterName: MOD02_CSI2_CRC_CTRL3
* AccessMode: RW
* AddressRange: 0x0094 - 0x0098
* ResetValue: 0x00000110
*/
#define R2M02_CSI2_CRC_CTRL3_U16 (uint16_t)0x0094
/**
* R2M02_PDC_CONFIG_REG_U16
* RegisterName: MOD02_PDC_CONFIG_REG
* AccessMode: RW
* AddressRange: 0x0098 - 0x009C
* ResetValue: 0x01A9A700
*/
#define R2M02_PDC_CONFIG_REG_U16 (uint16_t)0x0098
/**
* R2M02_DATA_VALID_PAD_CTRL_U16
* RegisterName: MOD02_DATA_VALID_PAD_CTRL
* AccessMode: RW
* AddressRange: 0x009C - 0x00A0
* ResetValue: 0x00010111
*/
#define R2M02_DATA_VALID_PAD_CTRL_U16 (uint16_t)0x009C
/**
* R2M02_LP_METADATA_CONFIG1_U16
* RegisterName: MOD02_LP_METADATA_CONFIG1
* AccessMode: RW
* AddressRange: 0x00A0 - 0x00A4
* ResetValue: 0x00003000
*/
#define R2M02_LP_METADATA_CONFIG1_U16 (uint16_t)0x00A0
/**
* R2M02_LP_METADATA_CONFIG2_U16
* RegisterName: MOD02_LP_METADATA_CONFIG2
* AccessMode: RW
* AddressRange: 0x00A4 - 0x00A8
* ResetValue: 0x00500050
*/
#define R2M02_LP_METADATA_CONFIG2_U16 (uint16_t)0x00A4
/**
* R2M02_LP_METADATA_USERINFO_U16
* RegisterName: MOD02_LP_METADATA_USERINFO
* AccessMode: RW
* AddressRange: 0x00A8 - 0x00AC
* ResetValue: 0x00000000
*/
#define R2M02_LP_METADATA_USERINFO_U16 (uint16_t)0x00A8
/**
* R2M02_VIRTUAL_CHANNEL_CONTROL_U16
* RegisterName: MOD02_VIRTUAL_CHANNEL_CONTROL
* AccessMode: RW
* AddressRange: 0x0100 - 0x0104
* ResetValue: 0x00000001
*/
#define R2M02_VIRTUAL_CHANNEL_CONTROL_U16 (uint16_t)0x0100
/**
* R2M02_SPARE_REG1_U16
* RegisterName: MOD02_SPARE_REG1
* AccessMode: RW
* AddressRange: 0x0104 - 0x0108
* ResetValue: 0x00000000
*/
#define R2M02_SPARE_REG1_U16 (uint16_t)0x0104
/**
* R2M02_CSI2_TXN_CTRL_U16
* RegisterName: MOD02_CSI2_TXN_CTRL
* AccessMode: RW
* AddressRange: 0x0200 - 0x0204
* ResetValue: 0x00000000
*/
#define R2M02_CSI2_TXN_CTRL_U16 (uint16_t)0x0200
/**
* R2M02_CSI2_TEST_MODE_CONTROL_REG_U16
* RegisterName: MOD02_CSI2_TEST_MODE_CONTROL_REG
* AccessMode: RW
* AddressRange: 0x0300 - 0x0304
* ResetValue: 0x00000FFF
*/
#define R2M02_CSI2_TEST_MODE_CONTROL_REG_U16 (uint16_t)0x0300
/**
* R2M02_PRBS_CONTROL_U16
* RegisterName: MOD02_PRBS_CONTROL
* AccessMode: RW
* AddressRange: 0x0304 - 0x0308
* ResetValue: 0x00000FFF
*/
#define R2M02_PRBS_CONTROL_U16 (uint16_t)0x0304
/**
* R2M02_PDC_SHIFT_REG_IDIV_CTRL_U16
* RegisterName: MOD02_PDC_SHIFT_REG_IDIV_CTRL
* AccessMode: RW
* AddressRange: 0x0310 - 0x0314
* ResetValue: 0x00010001
*/
#define R2M02_PDC_SHIFT_REG_IDIV_CTRL_U16 (uint16_t)0x0310
/**
* R2M02_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD02_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0704 - 0x0708
* ResetValue: 0x00000000
*/
#define R2M02_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0704
/**
* R2M02_REF_CNTR_INIT_U16
* RegisterName: MOD02_REF_CNTR_INIT
* AccessMode: RW
* AddressRange: 0x0800 - 0x0804
* ResetValue: 0x01E00028
*/
#define R2M02_REF_CNTR_INIT_U16 (uint16_t)0x0800
/**
* R2M02_FREQ_COUNTER_START_U16
* RegisterName: MOD02_FREQ_COUNTER_START
* AccessMode: RW
* AddressRange: 0x0804 - 0x0808
* ResetValue: 0x00000100
*/
#define R2M02_FREQ_COUNTER_START_U16 (uint16_t)0x0804
/**
* R2M02_FREQ_COUNTER_READ_VALUE_U16
* RegisterName: MOD02_FREQ_COUNTER_READ_VALUE
* AccessMode: R
* AddressRange: 0x0808 - 0x080C
* ResetValue: 0x00000000
*/
#define R2M02_FREQ_COUNTER_READ_VALUE_U16 (uint16_t)0x0808
/**
* R2M02_REF_COUNTER_READ_VALUE_U16
* RegisterName: MOD02_REF_COUNTER_READ_VALUE
* AccessMode: R
* AddressRange: 0x080C - 0x0810
* ResetValue: 0x00000000
*/
#define R2M02_REF_COUNTER_READ_VALUE_U16 (uint16_t)0x080C
/**
* R2M02_CRC_ERROR_STATUS1_U16
* RegisterName: MOD02_CRC_ERROR_STATUS1
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M02_CRC_ERROR_STATUS1_U16 (uint16_t)0x0F40
/**
* R2M02_CRC_ERROR_STATUS2_U16
* RegisterName: MOD02_CRC_ERROR_STATUS2
* AccessMode: R
* AddressRange: 0x0F44 - 0x0F48
* ResetValue: 0x00000000
*/
#define R2M02_CRC_ERROR_STATUS2_U16 (uint16_t)0x0F44
/**
* R2M02_CRC_ERROR_STATUS3_U16
* RegisterName: MOD02_CRC_ERROR_STATUS3
* AccessMode: R
* AddressRange: 0x0F48 - 0x0F4C
* ResetValue: 0x00000000
*/
#define R2M02_CRC_ERROR_STATUS3_U16 (uint16_t)0x0F48
/**
* R2M02_MODULE_ID_U16
* RegisterName: MOD02_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x00025001
*/
#define R2M02_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M02_TrimReg0Bits_t
* RegisterName: TRIM_REG0
* Dphy Trim Register0. 
* Keep the default value = 0x0A040018 for normal modes of operation.
* Address: 0x000
* ResetValue: 0x0A040018
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: lptx_trim_slew
	* Description: trim control for lp slew rate
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LptxTrimSlew : 2;        /*## attribute LptxTrimSlew */
	/**
	* BitsName: tr_sel
	* Description: Rise time and fall time trimming
	* for predriver
	* Read/Write: RW
	* Bits: [3:2]
	* ResetValue: 0b10
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrSel : 2;        /*## attribute TrSel */
	/**
	* BitsName: gdefault
	* Description: trim gain for front-end amplifier
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Gdefault : 1;        /*## attribute Gdefault */
	/**
	* BitsName: gnctrl
	* Description: trim gain for front-end amplifier
	* Read/Write: RW
	* Bits: [6:5]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Gnctrl : 2;        /*## attribute Gnctrl */
	/**
	* BitsName: rxcksel
	* Description: trim delay control for receiver
	* data lane 0
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Rxcksel : 1;        /*## attribute Rxcksel */
	/**
	* BitsName: rxhsdpol
	* Description: Change polarity of high speed
	* receive data
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Rxhsdpol : 1;        /*## attribute Rxhsdpol */
	/**
	* BitsName: trim_polarity_swap_ln0
	* Description: 0 - No polarity swap for lane 0
	* 1- Polarity swap for lane 0
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapLn0 : 1;        /*## attribute TrimPolaritySwapLn0 */
	/**
	* BitsName: trim_polarity_swap_ln1
	* Description: 0 - No polarity swap for lane 1
	* 1- Polarity swap for lane 1
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapLn1 : 1;        /*## attribute TrimPolaritySwapLn1 */
	/**
	* BitsName: cdpd
	* Description: Contention detection power
	* down
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Cdpd : 1;        /*## attribute Cdpd */
	/**
	* BitsName: hs_dc_test_en
	* Description: HS enable trim for testing DC
	* characteristics of the HS driver
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t HsDcTestEn : 1;        /*## attribute HsDcTestEn */
	/**
	* BitsName: lp_dc_test_en
	* Description: LP enable trim for testing DC
	* characteristics of the LP driver
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LpDcTestEn : 1;        /*## attribute LpDcTestEn */
	/**
	* BitsName: dc_test_data
	* Description: Test data for DC in LP and Hsmode
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DcTestData : 1;        /*## attribute DcTestData */
	/**
	* BitsName: trim_bit_glitch
	* Description: input selection trimbit(Comp_out
	* or vdd)
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimBitGlitch : 1;        /*## attribute TrimBitGlitch */
	/**
	* BitsName: iref_20u_cp_trim
	* Description: glitch removal ckt current trim
	* Read/Write: RW
	* Bits: [17:16]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Iref20UCpTrim : 2;        /*## attribute Iref20UCpTrim */
	/**
	* BitsName: pulser_bypass
	* Description: trim control for pulse rejection
	* bypass
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PulserBypass : 1;        /*## attribute PulserBypass */
	/**
	* BitsName: vco_selection
	* Description: Vco selection control
	* Read/Write: RW
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t VcoSelection : 1;        /*## attribute VcoSelection */
	/**
	* BitsName: trim_polarity_swap_ln2
	* Description: 0 - No polarity swap for lane 2
	* 1- Polarity swap for lane 2
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapLn2 : 1;        /*## attribute TrimPolaritySwapLn2 */
	/**
	* BitsName: trim_polarity_swap_ln3
	* Description: 0 - No polarity swap for lane 3
	* 1- Polarity swap for lane 3
	* Read/Write: RW
	* Bits: [21]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapLn3 : 1;        /*## attribute TrimPolaritySwapLn3 */
	/**
	* BitsName: trim_polarity_swap_clk
	* Description: 0 - No polarity swap for clk lane
	* 1- Polarity swap for clk lane
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapClk : 1;        /*## attribute TrimPolaritySwapClk */
	/**
	* BitsName: ddr_delay_sel
	* Description: DDR delay trim control
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [24:23]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DdrDelaySel : 2;        /*## attribute DdrDelaySel */
	/**
	* BitsName: trim_imp
	* Description: Tx Impedance Control
	* Read/Write: RW
	* Bits: [26:25]
	* ResetValue: 0b01
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimImp : 2;        /*## attribute TrimImp */
	/**
	* BitsName: trim_ff_bypass_reg0
	* Description: trim to bypass flip-flop for LPTX
	* in clock lane and data lanes 1,2
	* and 3
	* Read/Write: RW
	* Bits: [27]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimFfBypassReg0 : 1;        /*## attribute TrimFfBypassReg0 */
	/**
	* BitsName: ext_high_vco_en
	* Description: External trim bit control to enable
	* the high vco
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ExtHighVcoEn : 1;        /*## attribute ExtHighVcoEn */
	/**
	* BitsName: ext_low_vco_en
	* Description: External trim bit control to enable
	* the low vco
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ExtLowVcoEn : 1;        /*## attribute ExtLowVcoEn */
	/**
	* BitsName: hs_rx_fixed_delay_enable
	* Description: Fix delay enable control for Rx
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t HsRxFixedDelayEnable : 1;        /*## attribute HsRxFixedDelayEnable */
	/**
	* BitsName: hs_tx_fixed_delay_enable
	* Description: Fix delay enable control for Tx.
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t HsTxFixedDelayEnable : 1;        /*## attribute HsTxFixedDelayEnable */
}R2M02_TrimReg0Bits_t;
/**
* R2M02_TrimReg1Bits_t
* RegisterName: TRIM_REG1
* Dphy Trim Register1. 
* Should be programmed to  
* 
* = 0x4DB11041  ->  120 Mbps Per Lane Mode.
* = 0x4DB11003   -> 240 Mbps Per Lane Mode.
* = 0x4DB11006   -> 480 Mbps Per Lane Mode.
* 
* Address: 0x004
* ResetValue: 0x4DB1100F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: cnta
	* Description: Divider ratio Counter A
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b001111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Cnta : 6;        /*## attribute Cnta */
	/**
	* BitsName: cntb
	* Description: Dphy PLL divider value.Combination of cnta and cntb determines the PLL o/p frequency.
	* Need to be changed for different decimation factors and different no of lanes .Divider ratio Counter B
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Cntb : 1;        /*## attribute Cntb */
	/**
	* BitsName: dlpf
	* Description: Discharge lpf capacitor to zero
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Dlpf : 1;        /*## attribute Dlpf */
	/**
	* BitsName: dlpf_reg_sel
	* Description: Discharge lpf register bit select
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DlpfRegSel : 1;        /*## attribute DlpfRegSel */
	/**
	* BitsName: refin_sel
	* Description: Reference clock signal control
	* Read/Write: RW
	* Bits: [11:9]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RefinSel : 3;        /*## attribute RefinSel */
	/**
	* BitsName: lp_enable_selection
	* Description: External lp enable selection trim bit
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LpEnableSelection : 1;        /*## attribute LpEnableSelection */
	/**
	* BitsName: pll_lock_trim
	* Description: External trim bit control to enable
	* pll lock
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllLockTrim : 1;        /*## attribute PllLockTrim */
	/**
	* BitsName: bwb
	* Description: Chargepump current tunability
	* Read/Write: RW
	* Bits: [16:14]
	* ResetValue: 0b100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Bwb : 3;        /*## attribute Bwb */
	/**
	* BitsName: res
	* Description: LPF Resistor tunability
	* Read/Write: RW
	* Bits: [19:17]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Res : 3;        /*## attribute Res */
	/**
	* BitsName: plltstcksel
	* Description: PLL Test clock selection control
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b11
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Plltstcksel : 2;        /*## attribute Plltstcksel */
	/**
	* BitsName: tstodby4
	* Description: PLL Test output selection (div4/
	* div8)
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tstodby4 : 1;        /*## attribute Tstodby4 */
	/**
	* BitsName: cdhigh_trim
	* Description: trim control for CD high resistor
	* control
	* Read/Write: RW
	* Bits: [25:23]
	* ResetValue: 0b011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CdhighTrim : 3;        /*## attribute CdhighTrim */
	/**
	* BitsName: cdlow_trim
	* Description: trim control for CD low resistor
	* control
	* Read/Write: RW
	* Bits: [28:26]
	* ResetValue: 0b011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CdlowTrim : 3;        /*## attribute CdlowTrim */
	/**
	* BitsName: trim_hstx_ldo_pd
	* Description: power down register to control
	* the hstx ldo
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimHstxLdoPd : 1;        /*## attribute TrimHstxLdoPd */
	/**
	* BitsName: rtermctrl
	* Description: termination resistance control
	* Read/Write: RW
	* Bits: [31:30]
	* ResetValue: 0b01
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Rtermctrl : 2;        /*## attribute Rtermctrl */
}R2M02_TrimReg1Bits_t;
/**
* R2M02_TrimReg2Bits_t
* RegisterName: TRIM_REG2
* Dphy Trim Register2. 
* Keep the default value = 0x10000000 for normal modes of operation.
* Address: 0x008
* ResetValue: 0x10000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: rstn_reg_en
	* Description: Enable Reset input through register
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RstnRegEn : 1;        /*## attribute RstnRegEn */
	/**
	* BitsName: rstn_reg
	* Description: Reset input through register
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RstnReg : 1;        /*## attribute RstnReg */
	/**
	* BitsName: pllpd_reg
	* Description: Power down for pll
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllpdReg : 1;        /*## attribute PllpdReg */
	/**
	* BitsName: pllpden
	* Description: Register control enable for pll
	* power down
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Pllpden : 1;        /*## attribute Pllpden */
	/**
	* BitsName: pllrst_reg
	* Description: Pll reset
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllrstReg : 1;        /*## attribute PllrstReg */
	/**
	* BitsName: txhsen_reg_ck
	* Description: Enable register control for HSTX clk
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxhsenRegCk : 1;        /*## attribute TxhsenRegCk */
	/**
	* BitsName: txhsen_reg_d3_d0
	* Description: Enable register control for HSTX data line 
	* Read/Write: RW
	* Bits: [9:6]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxhsenRegD3D0 : 4;        /*## attribute TxhsenRegD3D0 */
	/**
	* BitsName: reg_ctrl_hstx_en
	* Description: Register control enable for lane
	* HSTX enables
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlHstxEn : 1;        /*## attribute RegCtrlHstxEn */
	/**
	* BitsName: txlpen_reg_ck
	* Description: 1 in lp mode and 0 in hs  clock lane
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxlpenRegCk : 1;        /*## attribute TxlpenRegCk */
	/**
	* BitsName: txlpen_reg_d3_d0
	* Description: 1 in lp mode and 0 in hs mode data lane
	* Read/Write: RW
	* Bits: [15:12]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxlpenRegD3D0 : 4;        /*## attribute TxlpenRegD3D0 */
	/**
	* BitsName: reg_ctrl_lptx_en
	* Description: Register control enable for lane
	* lptx enables
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlLptxEn : 1;        /*## attribute RegCtrlLptxEn */
	/**
	* BitsName: txpd_reg_ck
	* Description: Power down bit for Txlane of Clk Lane
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxpdRegCk : 1;        /*## attribute TxpdRegCk */
	/**
	* BitsName: txpd_reg_d3_d0
	* Description: Power down bit for Txlane
	* Read/Write: RW
	* Bits: [21:18]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxpdRegD3D0 : 4;        /*## attribute TxpdRegD3D0 */
	/**
	* BitsName: reg_ctrl_tx_pd
	* Description: Register control enable for tx
	* lane power down
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlTxPd : 1;        /*## attribute RegCtrlTxPd */
	/**
	* BitsName: rxhsen_reg_ck
	* Description: Enable register control for HSRX
	* clk
	* Read/Write: RW
	* Bits: [23]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxhsenRegCk : 1;        /*## attribute RxhsenRegCk */
	/**
	* BitsName: rxhsen_reg_d3_d0
	* Description: Enable register control for HSRX
	* Read/Write: RW
	* Bits: [27:24]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxhsenRegD3D0 : 4;        /*## attribute RxhsenRegD3D0 */
	/**
	* BitsName: reg_ctrl_hsrx_en
	* Description: Register control enable for lane
	* HSRX enables
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlHsrxEn : 1;        /*## attribute RegCtrlHsrxEn */
	/**
	* BitsName: rxlpen_reg_ck
	* Description: 1 in lp mode and 0 in hs mode
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxlpenRegCk : 1;        /*## attribute RxlpenRegCk */
	/**
	* BitsName: rxlpen_reg_d0
	* Description: 1 in lp mode and 0 in hs mode
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxlpenRegD0 : 1;        /*## attribute RxlpenRegD0 */
	/**
	* BitsName: rxlpen_reg_d1
	* Description: 1 in lp mode and 0 in hs mode
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxlpenRegD1 : 1;        /*## attribute RxlpenRegD1 */
}R2M02_TrimReg2Bits_t;
/**
* R2M02_TrimReg3Bits_t
* RegisterName: TRIM_REG3
* Dphy Trim Register3. 
* Always keep the default value of 0x0020C1FC for all modes of operation. The bits 30..26 are used for internal to the AFE and not related to polarity swap and hence should not be changed.
* TRIM_REG0(bits 9,10,20,21,22) is used for polarity swap
* Address: 0x00C
* ResetValue: 0x0020C1FC
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: rxlpen_reg_d3_d2
	* Description: 1 in lp mode and 0 in hs mode
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxlpenRegD3D2 : 2;        /*## attribute RxlpenRegD3D2 */
	/**
	* BitsName: reg_ctrl_lprx_en
	* Description: Register control enable for lane
	* lprx enables
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlLprxEn : 1;        /*## attribute RegCtrlLprxEn */
	/**
	* BitsName: rxpd_reg_ck
	* Description: Power down bit for Rxlane of Clk Lane
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxpdRegCk : 1;        /*## attribute RxpdRegCk */
	/**
	* BitsName: rxpd_reg_d3_d0
	* Description: Power down bit for data Rxlane 
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b1111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxpdRegD3D0 : 4;        /*## attribute RxpdRegD3D0 */
	/**
	* BitsName: reg_ctrl_rx_pd
	* Description: Register control enable for rx
	* lane power down
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlRxPd : 1;        /*## attribute RegCtrlRxPd */
	/**
	* BitsName: rtermen_reg_ck
	* Description: Register control for termination
	* enable clk
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RtermenRegCk : 1;        /*## attribute RtermenRegCk */
	/**
	* BitsName: rtermen_reg_d3_d0
	* Description: Register control for termination
	* enable data 
	* Read/Write: RW
	* Bits: [13:10]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RtermenRegD3D0 : 4;        /*## attribute RtermenRegD3D0 */
	/**
	* BitsName: rterm_reg_en
	* Description: Register control enable for termination
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RtermRegEn : 1;        /*## attribute RtermRegEn */
	/**
	* BitsName: trim_ff_bypass_reg3
	* Description: trim to bypass flip-flop for LPTX
	* in data lanes 0
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimFfBypassReg3 : 1;        /*## attribute TrimFfBypassReg3 */
	/**
	* BitsName: v2ipd_bgpd
	* Description: Power down selection for BG,
	* bias(v2i)
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t V2IpdBgpd : 1;        /*## attribute V2IpdBgpd */
	/**
	* BitsName: bw_res_sel
	* Description: PLL BW resistor selection control
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BwResSel : 1;        /*## attribute BwResSel */
	/**
	* BitsName: trim_s3_s0
	* Description: Common mode voltage control
	* for TX
	* Read/Write: RW
	* Bits: [21:18]
	* ResetValue: 0b1000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimS3S0 : 4;        /*## attribute TrimS3S0 */
	/**
	* BitsName: bist_lane_trim_3_0
	* Description: Enable Bandgap offset cancellation
	* circuit
	* Read/Write: RW
	* Bits: [25:22]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BistLaneTrim30 : 4;        /*## attribute BistLaneTrim30 */
	/**
	* BitsName: clk_pol_sel_ck
	* Description: trim control for clock polarity
	* selection of clk
	* Read/Write: RW
	* Bits: [26]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ClkPolSelCk : 1;        /*## attribute ClkPolSelCk */
	/**
	* BitsName: clk_pol_sel_d3_d0
	* Description: trim control for clock polarity
	* selection of data lane
	* Read/Write: RW
	* Bits: [30:27]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ClkPolSelD3D0 : 4;        /*## attribute ClkPolSelD3D0 */
	/**
	* BitsName: vbg_sel
	* Description: Bandgap selection control
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t VbgSel : 1;        /*## attribute VbgSel */
}R2M02_TrimReg3Bits_t;
/**
* R2M02_DphyDfeDlnRegister0Bits_t
* RegisterName: DPHY_DFE_DLN_REGISTER_0
* DLN_REG0 
* Should be programmed to  
* 0x03068309 -> 480 Mbps per Lane
* 0x01038106 -> 240 Mbps per Lane
* 0x01028004 -> 120 Mbps per Lane
* Address: 0x020
* ResetValue: 0x0A0D0716
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: dfe_dln_hs_zero_cnt
	* Description: This parameter specifies the number of byte clocks cycles the data lane shall wait to complete the HS-ZERO time
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00010110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnHsZeroCnt : 8;        /*## attribute DfeDlnHsZeroCnt */
	/**
	* BitsName: dfe_dln_hs_prepare
	* Description: This parameter specifies the number of clock cycles the data lane shall wait to complete the HS PREPARE time
	* [13:8]   -> In Byte Clock Cycles 
	* [15:14] -> In DDR Clock Cyles s
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnHsPrepare : 8;        /*## attribute DfeDlnHsPrepare */
	/**
	* BitsName: dfe_dln_hs_exit
	* Description: This parameter specifies the number of byte clock cycles the data lane shall wait to complete the HS-EXIT time
	* 
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00001101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnHsExit : 8;        /*## attribute DfeDlnHsExit */
	/**
	* BitsName: dfe_dln_hs_trial
	* Description: This parameter specifies the number of byte clock cycles the data lane shall wait to complete the HS TRIAL time
	* Read/Write: RW
	* Bits: [31:24]
	* ResetValue: 0b00001010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnHsTrial : 8;        /*## attribute DfeDlnHsTrial */
}R2M02_DphyDfeDlnRegister0Bits_t;
/**
* R2M02_DphyDfeDlnRegister1Bits_t
* RegisterName: DPHY_DFE_DLN_REGISTER_1
* DLN_REG1 
* Should be programmed to  
* 0x00030E04 -> 480 Mbps per Lane mode
* 0x00010A03 -> 240 Mbps per Lane mode
* 0x00000803 -> 120 Mbps per Lane mode
* Address: 0x024
* ResetValue: 0x00061E07
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: dfe_dln_rx_cnt
	* Description: This parameter specifies the number of byte clocks cycles the data lane shall wait before enabling the HS receiver
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnRxCnt : 8;        /*## attribute DfeDlnRxCnt */
	/**
	* BitsName: dfe_dln_sync_cnt
	* Description: This parameter specifies the number of byte clock cycles the
	* data lane shall wait before announcing an error on the
	* timeout of the SYNC pattern
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00011110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnSyncCnt : 8;        /*## attribute DfeDlnSyncCnt */
	/**
	* BitsName: dfe_dln_lpx_hs_cnt
	* Description: This parameter specifies the number of byte clock cycles required to accommodate an LP- xx state on the data lane
	* 
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00000110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnLpxHsCnt : 8;        /*## attribute DfeDlnLpxHsCnt */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
}R2M02_DphyDfeDlnRegister1Bits_t;
/**
* R2M02_DphyDfeClnRegister0Bits_t
* RegisterName: DPHY_DFE_CLN_REGISTER_0
* CLN_REG0
* Should be programmed to  
* 0x0406030E -> 480 Mbps per Lane mode
* 0x03030106 -> 240 Mbps per Lane mode
* 0x02024003 -> 120 Mbps per Lane mode
* Address: 0x028
* ResetValue: 0x080D0521
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: dfe_cln_zero
	* Description: This parameter specifies the number of byte clocks cycles the clock lane transmitter module shall wait during the HS-ZERO sequence of the high speed clock transmission
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00100001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnZero : 8;        /*## attribute DfeClnZero */
	/**
	* BitsName: dfe_cln_prepare
	* Description: This parameter specifies the number of  clock cycles the clock lane transmitter module shall wait during the prepare sequence of the high speed clock transmission
	* [13:8]   -> In Byte Clock Cycles 
	* [15:14] -> In DDR Clock Cyles s
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnPrepare : 8;        /*## attribute DfeClnPrepare */
	/**
	* BitsName: dfe_cln_hs_exit
	* Description: This parameter specifies the number of byte clock cycles the clock lane transmitter module shall wait during the exit sequence of the high speed clock transmission
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00001101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnHsExit : 8;        /*## attribute DfeClnHsExit */
	/**
	* BitsName: dfe_cln_hs_trial
	* Description: This parameter specifies the number of byte clock cycles the clock lane transmitter module shall wait during the TRIAL sequence of the high speed clock transmission
	* Read/Write: RW
	* Bits: [31:24]
	* ResetValue: 0b00001000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnHsTrial : 8;        /*## attribute DfeClnHsTrial */
}R2M02_DphyDfeClnRegister0Bits_t;
/**
* R2M02_DphyDfeClnRegister1Bits_t
* RegisterName: DPHY_DFE_CLN_REGISTER_1
* CLN_REG1
* Should be programmed to  
* 0x000A0102 -> 480 Mbps per Lane mode
* 0x00080101 -> 240 Mbps per Lane mode
* 0x00070100 -> 120 Mbps per Lane mode
* 
* Note: Ideal values for continous clock mode are specified above, For non-continuous clock mode, the same settings should work. Incase of failure, the lsb to be adjusted by +1 from the current settings for this field
* Address: 0x02C
* ResetValue: 0x00000006
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: dfe_cln_lpx_hs_cnt
	* Description: This parameter specifies the number of byte clocks required to accommodate an LP-xx stat on the clock lane
	* 
	* Note: Ideal values for continous clock mode are specified above, For non-continuous clock mode, the same settings should work. Incase of failure, the lsb to be adjusted by +1 from the current settings for this field
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnLpxHsCnt : 8;        /*## attribute DfeClnLpxHsCnt */
	/**
	* BitsName: tclk_pre
	* Description: This parameter specifies that the HS clock shall be driven by the transmitter prior to any associated data lane beginning the transition from LP to HS mode. The parameter is in terms of number of TxByteClkHS
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TclkPre : 8;        /*## attribute TclkPre */
	/**
	* BitsName: tclk_post
	* Description: This parameter specifies the number of byte clock cycles the clock lane transmitter module shall wait before removing the clock lane request after the last associated data lane has transitioned to LP mode
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TclkPost : 8;        /*## attribute TclkPost */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
}R2M02_DphyDfeClnRegister1Bits_t;
/**
* R2M02_PpiDataLaneSwapRegisterBits_t
* RegisterName: PPI_DATA_LANE_SWAP_REGISTER
* Set Number of DPHY Lanes
* Address: 0x034
* ResetValue: 0x00000300
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: swap_lane0
	* Description: Set by the processor to enable the Lane-0 swapping. When enable the LANE0 PPI interface signal of Controller is driven on to respective Lane on the DPHY 
	* When 00 : No Swap : Lane0 : Lane0
	*  When 01 : Swap : Lane0 : Lane1
	*  When 10 : Swap : Lane0 : Lane2 
	* When 11 : Swap : Lane0 : Lane3
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwapLane0 : 2;        /*## attribute SwapLane0 */
	/**
	* BitsName: swap_lane1
	* Description: Set by the processor to enable the Lane-1 swapping. When enable the LANE1 PPI interface signal of Controller is driven on to respective Lane on the DPHY
	*  When 00 : No Swap : Lane1 : Lane1 
	* When 01 : Swap : Lane1 : Lane0 
	* When 10 : Swap : Lane1 : Lane2 
	* When 11 : Swap : Lane1 : Lane3
	* Read/Write: RW
	* Bits: [3:2]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwapLane1 : 2;        /*## attribute SwapLane1 */
	/**
	* BitsName: swap_lane2
	* Description: Set by the processor to enable the Lane-2 swapping. When enable the LANE2 PPI interface signal of Controller is driven on to respective Lane on the DPHY 
	* When 00 : No Swap : Lane2 : Lane2
	*  When 01 : Swap : Lane2 : Lane0 
	* When 10 : Swap : Lane2 : Lane1 
	* When 11 : Swap : Lane2 : Lane3
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwapLane2 : 2;        /*## attribute SwapLane2 */
	/**
	* BitsName: swap_lane3
	* Description: Set by the processor to enable the Lane-3 swapping. When enable the LANE3 PPI interface signal of Controller is driven on to respective Lane on the DPHY 
	* When 00 : No Swap : Lane3 : Lane3 
	* When 01 : Swap : Lane3 : Lane0 
	* When 10 : Swap : Lane3 : Lane1
	*  When 11 : Swap : Lane3 : Lane2
	* Read/Write: RW
	* Bits: [7:6]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwapLane3 : 2;        /*## attribute SwapLane3 */
	/**
	* BitsName: number_of_lanes
	* Description: Default: - 4-Lanes. Set by the processor to configure the number of PPI lanes 
	* When 00 : One Lane Enabled (Lane-0) 
	* When 01 : Two Lane Enabled (Lane-0,1) 
	* When 10 : Three Lane Enabled( Lane-0,1,2) 
	* When 11 : Four Lane Enabled( Lane-0,1,2,3)
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b11
	* Source: Application
	* FuSa: No
	*/
	uint32_t NumberOfLanes : 2;        /*## attribute NumberOfLanes */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
}R2M02_PpiDataLaneSwapRegisterBits_t;
/**
* R2M02_FifoStatusRegisterBits_t
* RegisterName: FIFO_STATUS_REGISTER
* Sensor FIFO Status register
* Address: 0x038
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: sensor_fifo_empty
	* Description: Indicates the SENSOR FIFO empty status
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SensorFifoEmpty : 1;        /*## attribute SensorFifoEmpty */
	/**
	* BitsName: sensor_fifo_almost_full
	* Description: Indicates the SENSOR FIFO threshold full status
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SensorFifoAlmostFull : 1;        /*## attribute SensorFifoAlmostFull */
	/**
	* BitsName: sensor_fifo_full
	* Description: Indicates the SENSOR FIFO full status
	* Read/Write: R
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SensorFifoFull : 1;        /*## attribute SensorFifoFull */
	/**
	* BitsName: csi_fifo_empty
	* Description: Indicates the CSI FIFO empty status
	* Read/Write: R
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CsiFifoEmpty : 1;        /*## attribute CsiFifoEmpty */
	/**
	* BitsName: csi_fifo_full
	* Description: Indicates the CSI FIFO threshold full status
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CsiFifoFull : 1;        /*## attribute CsiFifoFull */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
}R2M02_FifoStatusRegisterBits_t;
/**
* R2M02_UsdPixelModeControlRegisterBits_t
* RegisterName: USD_PIXEL_MODE_CONTROL_REGISTER
* Keep reset value
* Address: 0x03C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: usd_data_type1_en
	* Description: Set by the processor to configure the USD data_type1 one/two/three/four pixel mode
	*  00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : Three pixel mode configured 
	* 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType1En : 2;        /*## attribute UsdDataType1En */
	/**
	* BitsName: usd_data_type2_en
	* Description: Set by the processor to configure the USD data_type2 one/two/three/four pixel mode 00 : One pixel mode configured 01 : Two pixel mode configured 10 : Three pixel mode configured 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [3:2]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType2En : 2;        /*## attribute UsdDataType2En */
	/**
	* BitsName: usd_data_type3_en
	* Description: Set by the processor to configure the USD data_type3 one/two/three/four pixel mode 
	* 00 :One pixel mode configured 
	* 01 :Two pixel mode configured
	*  10 : Three pixel mode configured
	*  11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType3En : 2;        /*## attribute UsdDataType3En */
	/**
	* BitsName: usd_data_type4_en
	* Description: Set by the processor to configure the USD data_type4 one/two/three/four pixel mode 
	* 00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : Three pixel mode configured 
	* 11: Four pixel mode configured
	* Read/Write: RW
	* Bits: [7:6]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType4En : 2;        /*## attribute UsdDataType4En */
	/**
	* BitsName: usd_data_type5_en
	* Description: Set by the processor to configure the USD data_type5 one/two/three/four pixel mode 
	* 00 : One pixel mode configured
	*  01 : Two pixel mode configured
	*  10 : Three pixel mode configured 
	* 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType5En : 2;        /*## attribute UsdDataType5En */
	/**
	* BitsName: usd_data_type6_en
	* Description: Set by the processor to configure the USD data_type6 one/two/three/four pixel mode
	*  00 : One pixel mode configured
	*  01 : Two pixel mode configured 
	* 10 : Three pixel mode configured 
	* 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [11:10]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType6En : 2;        /*## attribute UsdDataType6En */
	/**
	* BitsName: usd_data_type7_en
	* Description: Set by the processor to configure the USD data_type7 one/two/three/four pixel mode 
	* 00 : One pixel mode configured 
	* 01 : Two pixel mode configured
	* 10 : Three pixel mode configured 
	* 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType7En : 2;        /*## attribute UsdDataType7En */
	/**
	* BitsName: usd_data_type8_en
	* Description: Set by the processor to configure the USD data_type8 one/two/three/four pixel mode 
	* 00 : One pixel mode configured
	*  01 : Two pixel mode configured 
	* 10 : Three pixel mode configured
	*  11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [15:14]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType8En : 2;        /*## attribute UsdDataType8En */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M02_UsdPixelModeControlRegisterBits_t;
/**
* R2M02_YuvPixelModeControlRegisterBits_t
* RegisterName: YUV_PIXEL_MODE_CONTROL_REGISTER
* Keep reset value
* Address: 0x040
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 20;        /*## attribute Reserved0 */
	/**
	* BitsName: yuv422_8bit_en
	* Description: Set by the processor to configure the YUV422 8-bit one/two pixel mode 00 : One pixel mode configured 01 : Two pixel mode configured 10 : NA 11 : NA
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Yuv4228BitEn : 2;        /*## attribute Yuv4228BitEn */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 10;        /*## attribute Reserved1 */
}R2M02_YuvPixelModeControlRegisterBits_t;
/**
* R2M02_RawPixelModeControlRegisterBits_t
* RegisterName: RAW_PIXEL_MODE_CONTROL_REGISTER
* Keep reset value
* Address: 0x044
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 4;        /*## attribute Reserved0 */
	/**
	* BitsName: raw8_en
	* Description: Set by the processor to configure RAW8 one/two/three/four pixel mode 00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : Three pixel mode configured
	*  11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Raw8En : 2;        /*## attribute Raw8En */
	/**
	* BitsName: raw10_en
	* Description: Set by the processor to configure RAW10 one/two/three pixel mode 00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : Three pixel mode configured 
	* 11 : NA
	* Read/Write: RW
	* Bits: [7:6]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Raw10En : 2;        /*## attribute Raw10En */
	/**
	* BitsName: raw12_en
	* Description: Set by the processor to configure RAW12 one/two pixel mode 00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : NA 
	* 11 : NA
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Raw12En : 2;        /*## attribute Raw12En */
	/**
	* BitsName: raw14_en
	* Description: Set by the processor to configure RAW14 one/two pixel mode 00 : One pixel mode configured
	*  01 : Two pixel mode configured 
	* 10 : NA
	*  11 : NA
	* Read/Write: RW
	* Bits: [11:10]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Raw14En : 2;        /*## attribute Raw14En */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 20;        /*## attribute Reserved1 */
}R2M02_RawPixelModeControlRegisterBits_t;
/**
* R2M02_PhyTinitCountRegisterBits_t
* RegisterName: PHY_TINIT_COUNT_REGISTER
* PHY Init Time control. (After the PLL Lock , the Clock Lane remains in the LP state till this counter is expired).Program a value of 0x00002000 (recommended ) for fast lock after reset release .
* Address: 0x048
* ResetValue: 0x0000FFFF
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: tinit_timer
	* Description: This parameter specifies the number of txbyte clocks cycles the CSI-2 controller should wait to start accepting the data from the sensor interface.
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000001111111111111111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TinitTimer : 32;        /*## attribute TinitTimer */
}R2M02_PhyTinitCountRegisterBits_t;
/**
* R2M02_Vc0CompressionPredictionSchemeRegister1Bits_t
* RegisterName: VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* Keep reset value
* Address: 0x04C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vc0_compression_prediction1
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [29:0]
	* ResetValue: 0b000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc0CompressionPrediction1 : 30;        /*## attribute Vc0CompressionPrediction1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
}R2M02_Vc0CompressionPredictionSchemeRegister1Bits_t;
/**
* R2M02_Vc0CompressionPredictionSchemeRegister2Bits_t
* RegisterName: VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* Keep reset value
* Address: 0x050
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vc0_compression_prediction2
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc0CompressionPrediction2 : 10;        /*## attribute Vc0CompressionPrediction2 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
}R2M02_Vc0CompressionPredictionSchemeRegister2Bits_t;
/**
* R2M02_Vc1CompressionPredictionSchemeRegister1Bits_t
* RegisterName: VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* Keep reset value
* Address: 0x054
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vc1_compression_prediction1
	* Description: Since the Chip does not support any Prediction or Compression write ZERO
	* Read/Write: RW
	* Bits: [29:0]
	* ResetValue: 0b000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc1CompressionPrediction1 : 30;        /*## attribute Vc1CompressionPrediction1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
}R2M02_Vc1CompressionPredictionSchemeRegister1Bits_t;
/**
* R2M02_Vc1CompressionPredictionSchemeRegister2Bits_t
* RegisterName: VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* Keep reset value
* Address: 0x058
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vc1_compression_prediction2
	* Description: Since the Chip does not support any Prediction or Compression write ZERO
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc1CompressionPrediction2 : 10;        /*## attribute Vc1CompressionPrediction2 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
}R2M02_Vc1CompressionPredictionSchemeRegister2Bits_t;
/**
* R2M02_Vc2CompressionPredictionSchemeRegister1Bits_t
* RegisterName: VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* Keep reset value
* Address: 0x05C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vc2_compression_prediction1
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [29:0]
	* ResetValue: 0b000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc2CompressionPrediction1 : 30;        /*## attribute Vc2CompressionPrediction1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
}R2M02_Vc2CompressionPredictionSchemeRegister1Bits_t;
/**
* R2M02_Vc2CompressionPredictionSchemeRegister2Bits_t
* RegisterName: VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* Keep reset value
* Address: 0x060
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vc2_compression_prediction2
	* Description: Since the Chip does not support any Prediction or Compression write ZERO
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc2CompressionPrediction2 : 10;        /*## attribute Vc2CompressionPrediction2 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
}R2M02_Vc2CompressionPredictionSchemeRegister2Bits_t;
/**
* R2M02_Vc3CompressionPredictionSchemeRegister1Bits_t
* RegisterName: VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* Keep reset value
* Address: 0x064
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vc3_compression_prediction1
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [29:0]
	* ResetValue: 0b000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc3CompressionPrediction1 : 30;        /*## attribute Vc3CompressionPrediction1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
}R2M02_Vc3CompressionPredictionSchemeRegister1Bits_t;
/**
* R2M02_Vc3CompressionPredictionSchemeRegister2Bits_t
* RegisterName: VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* Keep reset value
* Address: 0x068
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vc3_compression_prediction2
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc3CompressionPrediction2 : 10;        /*## attribute Vc3CompressionPrediction2 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
}R2M02_Vc3CompressionPredictionSchemeRegister2Bits_t;
/**
* R2M02_PllCountRegisterBits_t
* RegisterName: PLL_COUNT_REGISTER
* Program a value of 0x00000000 (recommended ) for fast lock after reset release .
* Address: 0x06C
* ResetValue: 0x00004E20
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_cnt
	* Description: Programmed by the processor. Default time period is set for 1ms. This is set in terms of txbyteclkhs
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0100111000100000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllCnt : 16;        /*## attribute PllCnt */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M02_PllCountRegisterBits_t;
/**
* R2M02_DeviceReadyIndicationRegisterBits_t
* RegisterName: DEVICE_READY_INDICATION_REGISTER
* Device ready Indication register 
* Address: 0x070
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: device_ready
	* Description: When 0 : Indicates that CSI-2 controller is not ready to accept packet information from external sensor When 1: Indicates that CSI-2 controller is ready to accept packet information from external sensor.Chrp should be enabled only after this bit goes high.
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t DeviceReady : 1;        /*## attribute DeviceReady */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M02_DeviceReadyIndicationRegisterBits_t;
/**
* R2M02_Csi2AdaptConfigReg1Bits_t
* RegisterName: CSI2_ADAPT_CONFIG_REG1
* CSI2 Adapter configuration register.
* Address: 0x080
* ResetValue: 0x0000002C
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: csi2packettype
	* Description: the Chip supports only RAW12 (RAW12 -> 0x2C. So use 0x2C as default value)
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Packettype : 6;        /*## attribute Csi2Packettype */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: csi2dphyclkmode
	* Description: When 0 : Continuous Clock Mode When 1 : Non Continuous Clock Mode This is configured by the application based on the mode in which MIPI PHY clock lane need to operate
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Dphyclkmode : 1;        /*## attribute Csi2Dphyclkmode */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 7;        /*## attribute Reserved3 */
	/**
	* BitsName: csi2txulpsesc
	* Description: This signal indicates if the DPHY has to initiates the ULPS sequence. If this is asserted high the CSI-2 Tx will drive ULPS entry enable for D-PHY(Clock and Data Lanes) This is configured by application for driving the D-PHY to ULPS mode
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Txulpsesc : 1;        /*## attribute Csi2Txulpsesc */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: csi2txulpsexit
	* Description: This signal indicates if the DPHY has to exit out of a ULPS state. If this is asserted high the CSI-2 Tx will drive ULPS exit enable for D-PHY(Clock and Data lanes) This is configured by the application to exit the DPHY from ULPS mode
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Txulpsexit : 1;        /*## attribute Csi2Txulpsexit */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 7;        /*## attribute Reserved5 */
}R2M02_Csi2AdaptConfigReg1Bits_t;
/**
* R2M02_Csi2AdaptConfigReg2Bits_t
* RegisterName: CSI2_ADAPT_CONFIG_REG2
* CSI2 Adapter configuration register.
* Address: 0x084
* ResetValue: 0x0C810000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: csi2packetenable
	* Description: Packet Header Enable :
	* 0: no Packet Header on transmitted data Packet.
	* 1: Packet Header is appended to the  Data Packet.
	* Note:Packet header contains Chirp No and Word Count(no of ADC samples sent over the CSI2 interface)
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Packetenable : 1;        /*## attribute Csi2Packetenable */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: csi2datagrpmodeselect
	* Description: 1= 4 data chunk mode(4 consecutive samples of ADC1,4 consecutive samples of ADC2,4 consecutive samples of ADC3, 4 consecutive samples of ADC4,4 consecutive samples of ADC1 so on)
	* 0= 1 data  mode (1 sample of ADC1,1 sample of ADC2,1 sample of ADC3,1 sample of ADC4,1 sample of ADC1 so on)  
	* 
	* 
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Datagrpmodeselect : 1;        /*## attribute Csi2Datagrpmodeselect */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: csi2crccontrol
	* Description: Packet footer :This bit enables the 32-bit CRC engine and append the CRC output in the packet footer.32 -bit CRC is send as three seperated 12 bit in the packet.  
	* 1= enable CRC
	* 0= disable CRC 
	* 
	* 
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Crccontrol : 1;        /*## attribute Csi2Crccontrol */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: csi2dphyclkdiv
	* Description: Refrece clock generationor the PLL inside DPHY.Default = 20MHz.Input to the clock divider is 40MHz XTAL clock
	* 
	* 01 - Divide by 2  (40/2 = 20 MHz)
	* 10 - Divide by 3 (40/3 = 13.33 MHz)
	* 11 - Divide by 4 (40/4 = 10 MHz)
	* 
	* Read/Write: RW
	* Bits: [17:16]
	* ResetValue: 0b01
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Dphyclkdiv : 2;        /*## attribute Csi2Dphyclkdiv */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 2;        /*## attribute Reserved5 */
	/**
	* BitsName: csi2delaycnt
	* Description: An internal delay generator which delays the incoming frame_active negedge signals from chirp so that the delay requirement b/w sensor signal FE and end of CSI2 transmission is met.Counter running at 40 MHz.The delay value varies with the decimation and no of DPHY lanes enabled (csi_clk). Need feedback from validation to fix the delay for various decimations
	* Read/Write: RW
	* Bits: [31:20]
	* ResetValue: 0b000011001000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Delaycnt : 12;        /*## attribute Csi2Delaycnt */
}R2M02_Csi2AdaptConfigReg2Bits_t;
/**
* R2M02_Csi2AdaptConfigReg3Bits_t
* RegisterName: CSI2_ADAPT_CONFIG_REG3
* CSI2 Adapter configuration register.
* Address: 0x088
* ResetValue: 0x0000002B
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: frame_active_delay
	* Description: Frame active rising edge triggeres the FS short packet.Profile load occurs every Frame active rise edge which switches the internal clock divider based on the new decimation value.  
	* Frame active is internally delayed to accomodate the Switching time of the Clock divider. Delay counter is running at 40 MHz clock in all modes.
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FrameActiveDelay : 6;        /*## attribute FrameActiveDelay */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: chirp_number_clr
	* Description: Chirp number clear bit from SPI
	* 1:  Clear the internal Chirp number counter
	* 0:  No clear
	* Note: autoclear register
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpNumberClr : 1;        /*## attribute ChirpNumberClr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: chirp_number_clr_sel
	* Description: Chirp Number clear selection:
	* 0: Chirp Number is cleared automatically  for every sequen/frame active
	* 1: Chirp number is cleared by writing to the register bit chirp_number_clr
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpNumberClrSel : 1;        /*## attribute ChirpNumberClrSel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: adcchanneldisable
	* Description: Only for internal validation and debug purpose.Individual ADC channel can be disabled.So in this case instead of scaling down the clock,the Chip send a known data in this disabled ADC slot.
	* 
	* [0] ->  1 :  disable  adc channel 1 & 0 : enable adc channel 1
	* [1] ->  1 :  disable  adc channel 2 & 0 : enable adc channel 2
	* [2] ->  1 :  disable  adc channel 3 & 0 : enable adc channel 3
	* [3] ->  1 :  disable  adc channel 4 & 0 : enable adc channel 4
	* Read/Write: RW
	* Bits: [19:16]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Adcchanneldisable : 4;        /*## attribute Adcchanneldisable */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 4;        /*## attribute Reserved3 */
	/**
	* BitsName: channeldisabledatasel
	* Description: Individual ADC channel can de disabled or enabled.
	* 0 : when adc channel is disabled send zero data 
	* 1: when adc channel is disabled send Test data programmed in Csi2TestModeControlReg
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Channeldisabledatasel : 1;        /*## attribute Channeldisabledatasel */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: packet_endianness
	* Description: 0: Sends MS first in Packet Header and Packet Footer(crc)
	* 1: Send LS first in Packet Header and Packet Footer(crc)
	* Note: This is only applicable to Packet Header and Packet Footer not for Data
	* 
	* Note: CRC is 32 bit and WordCunt is 14 bit so this needs to be splitted into MS and LS formats.
	* 
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PacketEndianness : 1;        /*## attribute PacketEndianness */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
}R2M02_Csi2AdaptConfigReg3Bits_t;
/**
* R2M02_Csi2CrcCtrl1Bits_t
* RegisterName: CSI2_CRC_CTRL1
* CRC 32- control
* Address: 0x08C
* ResetValue: 0xFFFFFFFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: crc_init_value
	* Description: Initial value of the CRC polynomial register register..It is a CRC Engine configuration parameter 
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b11111111111111111111111111111111
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CrcInitValue : 32;        /*## attribute CrcInitValue */
}R2M02_Csi2CrcCtrl1Bits_t;
/**
* R2M02_Csi2CrcCtrl2Bits_t
* RegisterName: CSI2_CRC_CTRL2
* CRC 32- control
* Address: 0x090
* ResetValue: 0xFFFFFFFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: crc_xor_out_value
	* Description: Final CRC output is XOR ed with this value.It is a CRC Engine configuration parameter 
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b11111111111111111111111111111111
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CrcXorOutValue : 32;        /*## attribute CrcXorOutValue */
}R2M02_Csi2CrcCtrl2Bits_t;
/**
* R2M02_Csi2CrcCtrl3Bits_t
* RegisterName: CSI2_CRC_CTRL3
* CRC 32- control.CRC is calculated using a 32-bit input CRC engine.Two consecutive adc samples con-catinated [data1,4'b0000 : data0,4'b0000] and given to the engine.
* Address: 0x094
* ResetValue: 0x00000110
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: crc_endianness
	* Description: Enable/Disable CRC data Swapping :
	* The Chip uses 32-bit CRC engine. So input data to be con-catinated.  After con-catination 32 bit data is swapped before inputting the date to the CRC engine
	* 0 : Swapping enable 
	* 1 : Swapping disable
	* 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CrcEndianness : 1;        /*## attribute CrcEndianness */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: reflect_input
	* Description: Reflecting the bits of the input 32-bit data around the middle. 
	* 0: No swapping
	* 1: Bit order is swapped around the middle of the input 32 bit data(default)It is a CRC Engine configuration parameter
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ReflectInput : 1;        /*## attribute ReflectInput */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: reflect_output
	* Description: For reflecting the final CRC ouput bits before final XOR .
	* 0 : No swapping 
	* 1 : Bit order is swapped around the middle of the CRC result.(default)
	* It is a CRC Engine configuration parameter
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ReflectOutput : 1;        /*## attribute ReflectOutput */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: dummy_zero_position
	* Description: CRC is calculated using a 32-bit input CRC engine.Two consecutive adc samples con-catinated [data1,4'b0000 : data0,4'b0000] and given to the engine.Zero padding can be done at LSB side or MSB side.
	* 
	* 0: Zero padding at LSB position (default)
	* 1: Zero padding at MSB position
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t DummyZeroPosition : 1;        /*## attribute DummyZeroPosition */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M02_Csi2CrcCtrl3Bits_t;
/**
* R2M02_PdcConfigRegBits_t
* RegisterName: PDC_CONFIG_REG
* PDC Configuration controls
* Address: 0x098
* ResetValue: 0x01A9A700
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: make_output_unsigned
	* Description: Signed or Unsigned 12 bits.
	* 0: PDC output is Signed 12 bit
	* 1: PDC output is UnSigned 12 bit
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MakeOutputUnsigned : 1;        /*## attribute MakeOutputUnsigned */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_input_w_wa
	* Description: 
	* 0: always process input data.PDC will process all the input samples irrespective of the window active from timing engine
	* 1: PDC will only process ADC samples only during the window active
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskInputWWa : 1;        /*## attribute MaskInputWWa */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: wa_delay_decimation_mode1
	* Description: window active delay value for decimation mode 1(by 2  decimation factor).The delay b/w the input and output window active of PDC.The output data_valid will also be delayed by the same factor.Since PDC is running at 80 MHz,Delay measured in clocks of 80 MHz.
	* Delay= register value x 2 clocks
	* default  value of Delay = 7x2 = 14 clocks of 80MHz.
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WaDelayDecimationMode1 : 4;        /*## attribute WaDelayDecimationMode1 */
	/**
	* BitsName: wa_delay_decimation_mode2
	* Description: window active delay value for decimation mode 2(by 4  decimation factor).The delay b/w the input and output window active of PDC.The output data_valid will also be delayed by the same factor.Since PDC is running at 80 MHz,Delay measured in clocks of 80 MHz.
	* Delay= register value x 4 clocks
	* default  value of Delay = 10x4 = 40 clocks of 80MHz.
	* Read/Write: RW
	* Bits: [15:12]
	* ResetValue: 0b1010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WaDelayDecimationMode2 : 4;        /*## attribute WaDelayDecimationMode2 */
	/**
	* BitsName: wa_delay_decimation_mode3
	* Description: window active delay value for decimation mode 3(by 8  decimation factor).The delay b/w the input and output window active of PDC.The output data_valid will also be delayed by the same factor.Since PDC is running at 80 MHz,Delay measured in clocks of 80 MHz.
	* Delay= register value x 8 clocks
	* default  value of Delay = 9x8 = 72 clocks of 80MHz.
	* Read/Write: RW
	* Bits: [19:16]
	* ResetValue: 0b1001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WaDelayDecimationMode3 : 4;        /*## attribute WaDelayDecimationMode3 */
	/**
	* BitsName: wa_delay_decimation_mode4
	* Description: window active delay value for decimation mode 4(by 16  decimation factor).The delay b/w the input and output window active of PDC.The output data_valid will also be delayed by the same factor.Since PDC is running at 80 MHz,Delay measured in clocks of 80 MHz.
	* Delay= register value x 16 clocks
	* default  value of Delay = 10x16 = 160 clocks of 80MHz.
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [23:20]
	* ResetValue: 0b1010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WaDelayDecimationMode4 : 4;        /*## attribute WaDelayDecimationMode4 */
	/**
	* BitsName: enable_pdc_reset
	* Description: Enable PDC Sync
	* 1: PDC will get reset for every rise edge of pdc_reset signal from Chirp
	* 0: No Reset
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnablePdcReset : 1;        /*## attribute EnablePdcReset */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: disable_pdc_filter
	* Description: Debug:
	* 1 : Filter inside PDC is disabled (Only down sampling)
	* 0:  Filter Enabled
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DisablePdcFilter : 1;        /*## attribute DisablePdcFilter */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
}R2M02_PdcConfigRegBits_t;
/**
* R2M02_DataValidPadCtrlBits_t
* RegisterName: DATA_VALID_PAD_CTRL
* nan
* Address: 0x09C
* ResetValue: 0x00010111
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: lvds_csi2_datavalid_mfio_en
	* Description: Data valid(mfio) pad enable/disable:
	* Disable Output Driver(Active High)
	* 0: Pad enabled
	* 1: Pad disabled.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEn : 1;        /*## attribute LvdsCsi2DatavalidMfioEn */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_enzi
	* Description: Receiver Enable (Active Low)
	* 1: Receiver Disabled
	* 0: Receiver Enabled
	* 
	* ENZI    EPUN  EPD    Mode
	* 
	* 0          0           0       Plain input with weak pull-up 
	* 0          0           1       Plain input with repeater (bus keeper)
	* 0          1           0       Plain input
	* 0          1           1       
	* 
	* 1          0           0       Weak pull-up
	* 1          0           1       Weak pull-down
	* 1          1           0       High impedance (Analog I/O)
	* 1          1           1       Weak pull-down
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEnzi : 1;        /*## attribute LvdsCsi2DatavalidMfioEnzi */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_epun
	* Description: Enable weak pull-up (Active Low)
	* 1: weak pull-up Disabled
	* 0: weak pull-up Enabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEpun : 1;        /*## attribute LvdsCsi2DatavalidMfioEpun */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_epd
	* Description: Enable weak pull-down(active high)
	* 1: weak pull-down Enabled
	* 0: weak pull-down Disabled
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEpd : 1;        /*## attribute LvdsCsi2DatavalidMfioEpd */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_ehs0
	* Description: MFIO Speed Selection 
	* [ehs1 ehs0] :
	* [0               0] : 20 MHz
	* [0               1] : 40 MHz
	* [1               0] : 85 MHz
	* [1               1] : 125 MHz"
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEhs0 : 1;        /*## attribute LvdsCsi2DatavalidMfioEhs0 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_ehs1
	* Description: speed selection bit 1
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEhs1 : 1;        /*## attribute LvdsCsi2DatavalidMfioEhs1 */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 14;        /*## attribute Reserved4 */
}R2M02_DataValidPadCtrlBits_t;
/**
* R2M02_LpMetadataConfig1Bits_t
* RegisterName: LP_METADATA_CONFIG1
* nan
* Address: 0x0A0
* ResetValue: 0x00003000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: metadata_lp_en
	* Description: Enable of complete Long Packet Meta Data
	* 1: Enabled. Metadata Long Packet shall be transmistted after last chirp in each frame.
	* 0: Long Packet metadata transmission disabled.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpEn : 1;        /*## attribute MetadataLpEn */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: metadata_lp_userfield_en
	* Description: Long Packet Metadata User field Enable
	* 1: User field is enabled. 72 byte long User data will be transmitted as part of Long Packet Metadata. Those bytes contain 18x32b registers from ISM
	* 0: User field is disabled & not transmitted.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpUserfieldEn : 1;        /*## attribute MetadataLpUserfieldEn */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: metadata_lp_datatype
	* Description: User defined data type used for long packet metadata  transmission
	* Valid values (As per CSI2 specification): 0x30 - 0x37
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b110000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpDatatype : 6;        /*## attribute MetadataLpDatatype */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: metadata_lp_vc
	* Description: Virtual Channel used for long packet metadata transmission
	* Valid values :
	* 2'b00, 2'b01, 2'b10, 2'b11
	* Read/Write: RW
	* Bits: [17:16]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpVc : 2;        /*## attribute MetadataLpVc */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 14;        /*## attribute Reserved3 */
}R2M02_LpMetadataConfig1Bits_t;
/**
* R2M02_LpMetadataConfig2Bits_t
* RegisterName: LP_METADATA_CONFIG2
* nan
* Address: 0x0A4
* ResetValue: 0x00500050
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: metadata_lp_length
	* Description: Long Packet metadata length in bytes.
	* Minimum packet length shall be 8 bytes when metadata_lp_userfield_en is disabled, containing User Info
	* Minimum packet length shall be 80 bytes when metadata_lp_userfield_en is enabled (8 bytes for User Info + 18x4=72 bytes for ISM data named "Userfield")
	* When packet length configured is more than minimum required length, dummy byte '8'h33' will be transmitted to meet the packet length.
	* Even if Packet length configured is less than minimum required length, Metadata packet will be transmitted with minimum required length for selected configuration.
	* Note: Following registers from ISM are packed as part of the user field
	* csi2_adc12_clipping_events_threshold_counter
	* csi2_adc34_clipping_events_threshold_counter
	* csi2_master_error_flag_to_mcu
	* csi2_ism_error_status
	* csi2_tx_masked_error_status_reg
	* csi2_rx_masked_error_status_reg
	* csi2_chirp_masked_error_status_reg
	* csi2_mc_lo_cc_ism_otp_masked_error_status_reg
	* csi2_ssb_gb_ser_gldo_atb_masked_error_status_reg
	* csi2_adc_masked_error_status_reg_to_mcu
	* csi2_supply_masked_error_status_reg
	* csi2_register_crc_error_flag_masked_status
	* csi2_rf_power_down_masked_flag
	* csi2_status_monitoring_flag_reg_to_mcu
	* csi2_first_masked_error_info_reg
	* csi2_first_masked_error_status
	* csi2_first_masked_warning_info_reg
	* csi2_first_masked_warning_status
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000001010000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpLength : 16;        /*## attribute MetadataLpLength */
	/**
	* BitsName: metadata_lp_start_dly
	* Description: This delay value field configures the delay between end of final chirp & start of metadata Long packet.
	* Delay counter always counts on 40MHz clock cycles. Default value(8'd80) is configured for 2us delay.
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b01010000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpStartDly : 8;        /*## attribute MetadataLpStartDly */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
}R2M02_LpMetadataConfig2Bits_t;
/**
* R2M02_LpMetadataUserinfoBits_t
* RegisterName: LP_METADATA_USERINFO
* nan
* Address: 0x0A8
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: metadata_lp_userinfo
	* Description: Metadata User info
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpUserinfo : 32;        /*## attribute MetadataLpUserinfo */
}R2M02_LpMetadataUserinfoBits_t;
/**
* R2M02_VirtualChannelControlBits_t
* RegisterName: VIRTUAL_CHANNEL_CONTROL
* nan
* Address: 0x100
* ResetValue: 0x00000001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vc0_en
	* Description: enable for Virtual channel 0 ; 
	* 0 = disable, 1 = enable
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc0En : 1;        /*## attribute Vc0En */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: vc1_en
	* Description: enable for Virtual channel 1 ; 
	* 0 = disable, 1 = enable
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc1En : 1;        /*## attribute Vc1En */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: vc2_en
	* Description: enable for Virtual channel 2 ; 
	* 0 = disable, 1 = enable
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc2En : 1;        /*## attribute Vc2En */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: vc3_en
	* Description: enable for Virtual channel 3 ; 
	* 0 = disable, 1 = enable
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc3En : 1;        /*## attribute Vc3En */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: vc0_frame_num_clr
	* Description: Write '1' to this register to clear the frame counter for VC=0. Counter is cleared at the end of frame
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc0FrameNumClr : 1;        /*## attribute Vc0FrameNumClr */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: vc1_frame_num_clr
	* Description: Write '1' to this register to clear the frame counter for VC=1. Counter is cleared at the end of frame
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc1FrameNumClr : 1;        /*## attribute Vc1FrameNumClr */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: vc2_frame_num_clr
	* Description: Write '1' to this register to clear the frame counter for VC=2. Counter is cleared at the end of frame
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc2FrameNumClr : 1;        /*## attribute Vc2FrameNumClr */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: vc3_frame_num_clr
	* Description: Write '1' to this register to clear the frame counter for VC=3. Counter is cleared at the end of frame
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc3FrameNumClr : 1;        /*## attribute Vc3FrameNumClr */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 3;        /*## attribute Reserved7 */
}R2M02_VirtualChannelControlBits_t;
/**
* R2M02_SpareReg1Bits_t
* RegisterName: SPARE_REG1
* nan
* Address: 0x104
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 6;        /*## attribute Reserved0 */
	/**
	* BitsName: spare_bits_1
	* Description: Spare bits
	* 
	* Read/Write: RW
	* Bits: [31:6]
	* ResetValue: 0b00000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SpareBits1 : 26;        /*## attribute SpareBits1 */
}R2M02_SpareReg1Bits_t;
/**
* R2M02_Csi2TxnCtrlBits_t
* RegisterName: CSI2_TXN_CTRL
* CSI2 Transmission Enable register
* Address: 0x200
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: csi2_txn_en
	* Description: Transmision enable for Csi2.This should be the last register to be programmed(enabled) during configuration.
	* 0: Transmission is disabled
	* 1: Transmission is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Csi2TxnEn : 1;        /*## attribute Csi2TxnEn */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M02_Csi2TxnCtrlBits_t;
/**
* R2M02_Csi2TestModeControlRegBits_t
* RegisterName: CSI2_TEST_MODE_CONTROL_REG
* only for internal validation and debug purpose.Keep default value for functional use case
* Address: 0x300
* ResetValue: 0x00000FFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: csi2_testmode_test_data
	* Description: Fixed Test Data to be send inTest Mode
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b111111111111
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Csi2TestmodeTestData : 12;        /*## attribute Csi2TestmodeTestData */
	/**
	* BitsName: delayed_test_pattern
	* Description: 1 : Delayed Pattern Across Channels: Channel 4 is getting
	*      the data delayed by 3 cycles, channel 3 is getting the
	*      data delayed by 2 cycles, channel 2 is getting the data 
	*      delayed by 1 cycle, and channel 1 is getting the data
	*       from the pattern generator without delay.
	* 0 : No delay across channels.
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t DelayedTestPattern : 1;        /*## attribute DelayedTestPattern */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: csi2_testmode_en
	* Description: 0: PDC functional data as input to csi2
	* 1: Test data is input to csi2 
	* 
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Csi2TestmodeEn : 1;        /*## attribute Csi2TestmodeEn */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: csi2_testmode_data_sel
	* Description:  
	* 00 : csi2_testmode_test_data regiser field value as test data   
	* 01: Sinewave as test data (78.125 KHz)   
	* 10: Incremental Pattern as test data  ( 0x001 ->FFF)  
	* 11: PRBS7 (  X ^ 7 + X ^6 + 1)
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Csi2TestmodeDataSel : 2;        /*## attribute Csi2TestmodeDataSel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: csi2_testmode_skip_pdc
	* Description: 0: test data inserted at the input side of PDC
	* 1: test data inserted at the o/p side of PDC
	* Note: During the test mode csi2_testmode_skip_pdc should be "1" to test the SER link
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Csi2TestmodeSkipPdc : 1;        /*## attribute Csi2TestmodeSkipPdc */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 7;        /*## attribute Reserved3 */
}R2M02_Csi2TestModeControlRegBits_t;
/**
* R2M02_PrbsControlBits_t
* RegisterName: PRBS_CONTROL
* PRBS test generator controls
* Address: 0x304
* ResetValue: 0x00000FFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: prbs_initial_value
	* Description: Initial value for the PRBS Test pattern Generator
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b111111111111
	* Source: Application
	* FuSa: Y
	*/
	uint32_t PrbsInitialValue : 12;        /*## attribute PrbsInitialValue */
	/**
	* BitsName: invert_prbs_pattern
	* Description: 1  :  Invert the PRBS Test Pattern
	* 0  :  No Invert
	* 
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t InvertPrbsPattern : 1;        /*## attribute InvertPrbsPattern */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
}R2M02_PrbsControlBits_t;
/**
* R2M02_PdcShiftRegIdivCtrlBits_t
* RegisterName: PDC_SHIFT_REG_IDIV_CTRL
* ADC data Sampling control register
* Address: 0x310
* ResetValue: 0x00010001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: adc_data_sampling_point
	* Description: ADC Data Capturing :After the sampling pulse generation ,the idea is to position the sampling pulse in the middle of the ADC data window.The pulse can be moved to the right in steps of 480 MHz clock using this register field.
	* 000: sampling pulse is right shifted by two 480/600 clks (double-sync) from the selected adc_clk edge 
	* 001:sampling pulse is right shifted by three 480/600 clks
	* 010:sampling pulse is right shifted by four 480/600 clks
	* .
	* .
	* 111: sampling pulse is right shifted by nine 480/600 clks
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcDataSamplingPoint : 3;        /*## attribute AdcDataSamplingPoint */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: adc_clk_edge_sel
	* Description: ADC data is sampled on serialiser 480MHz clock using a clock aligner logic.Sampling pulse  is generated with an edge detector in  adc_strobe path.
	* 00: Detect  both edges 
	* 01: Detect pos edge
	* 10: Detect neg edge
	* 11: Detect  both edges of adc_strobe signal
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcClkEdgeSel : 2;        /*## attribute AdcClkEdgeSel */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: adc_clock_select
	* Description: ADC clock selection logic. The selected ADC clock is used as adc_strobe to sample the ADC data.
	* 000 : All the ADC clocks are OR ed together (default )
	* 001 : Select adc1 clock
	* 010 : Select adc2 clock
	* 011 : Select adc3 clock
	* 100 : Select adc4 clock
	* 101 : OR adc1 & adc3 clock
	* 110 : OR adc2 & adc4 clock
	* 111 : OR adc1 & adc4 clock.
	* Read/Write: RW
	* Bits: [10:8]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcClockSelect : 3;        /*## attribute AdcClockSelect */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: window_active_sampling_edge_sel
	* Description: Window Active is sampled on serialiser 480MHz clock using a clock aligner logic.Sampling pulse  is generated with an edge detector in adc_strobe signal 
	* 00: adc_valid_both_edge_pulse 
	* 01:adc_valid_posedge_pulse   
	* 10:adc_valid_negedge_pulse   
	* 11:adc_valid_both_edge_pulse 
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WindowActiveSamplingEdgeSel : 2;        /*## attribute WindowActiveSamplingEdgeSel */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: window_active_sampling_point
	* Description: WA Capturing :The pulse can be moved to the right in steps of 480 MHz clock using this register field.
	* 000: sampling pulse is right shifted by two 480/600 clks (double-sync) from the selected adc_strobe signal
	* 001:sampling pulse is right shifted by three 480/600 clks
	* 010:sampling pulse is right shifted by four 480/600 clks
	* .
	* .
	* 111: sampling pulse is right shifted by nine 480/600 clks
	* 
	* Use model:  The value to be used has to come form Validation . The end user can use  the proposed value from validation
	* Read/Write: RW
	* Bits: [18:16]
	* ResetValue: 0b001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WindowActiveSamplingPoint : 3;        /*## attribute WindowActiveSamplingPoint */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: window_active_sampling_mode
	* Description: 0: WA is directly captured withj the adc data sampling pulse.(ADC clocks and WA are aligned)
	* 1:WA is double synchronized and captured with the adc data sampling pulse
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WindowActiveSamplingMode : 1;        /*## attribute WindowActiveSamplingMode */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 11;        /*## attribute Reserved5 */
}R2M02_PdcShiftRegIdivCtrlBits_t;
/**
* R2M02_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This functional safety register is only used for internal validation and debug purpose.Not to be changed in normal functioning  mode
* Address: 0x704
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_supply_1v1_csi2_low_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 0: no mask
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V1Csi2LowResetError : 1;        /*## attribute MaskSupply1V1Csi2LowResetError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the design
	* 0: no mask
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskRegCrcResetError : 1;        /*## attribute MaskRegCrcResetError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mask_freq_count_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the design
	* 0: no mask
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskFreqCountResetError : 1;        /*## attribute MaskFreqCountResetError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_supply_1v1_ser_low_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 0: no mask
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V1SerLowResetError : 1;        /*## attribute MaskSupply1V1SerLowResetError */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mask_supply_1v8_low_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 0: no mask
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V8LowResetError : 1;        /*## attribute MaskSupply1V8LowResetError */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 15;        /*## attribute Reserved4 */
}R2M02_MaskCcResetErrorBits_t;
/**
* R2M02_RefCntrInitBits_t
* RegisterName: REF_CNTR_INIT
* Frequency counter used for counting 480/600 MHz clock
* Address: 0x800
* ResetValue: 0x01E00028
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ref_count_value
	* Description: value for the reference count time (40 MHz= 25 ns base time) default is d'40. This is used as reference count in both spi triggered mode and window_active triggered mode
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000000101000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RefCountValue : 16;        /*## attribute RefCountValue */
	/**
	* BitsName: ideal_480_count_value
	* Description: This is applicable when the freq counter trigger is based on  window_active (for func safety). The correct value to be programmed which is compared against the freq counter read value in the hardware. The value is restricted to 16 bits (as against 18 bit in the freq read counter value) as this triggered one time during active period of the window active and the bit width is sufficient to cover the frequency counting considering the variation of the chirp period
	* Read/Write: RW
	* Bits: [31:16]
	* ResetValue: 0b0000000111100000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Ideal480CountValue : 16;        /*## attribute Ideal480CountValue */
}R2M02_RefCntrInitBits_t;
/**
* R2M02_FreqCounterStartBits_t
* RegisterName: FREQ_COUNTER_START
* Frequency Counter : Used for measuring Serialiser Clock 480/600 frequency.
* Address: 0x804
* ResetValue: 0x00000100
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: freq_start
	* Description: Start the freq. count
	* 0 = idle, 1 = start
	* 
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t FreqStart : 1;        /*## attribute FreqStart */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: freq_counter_deviation
	* Description: Number of lsb bits to be ignored while comparing the final freq counter read value. This is required incase of frequency counter trigger is based on window_active  for functional safety. The hardware then compares the value measured by frequency counter against ideal_480_count_value ignoring the lsb bits. 
	* 0001: Zeroth bit is ignored from comparison
	* 0011: Zeroth & first bits are ignored from comparison
	* 0111: Zeroth & first & second bits are ignored from comparison
	* 1111: Zeroth & first & second & third bits are ignored from comparison
	* 
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t FreqCounterDeviation : 4;        /*## attribute FreqCounterDeviation */
	/**
	* BitsName: freq_counter_trigger_sel
	* Description: 1: the frequency counter is triggered based on window_active posedge to measure the frequency deviation if any and to report to the ISM for every chirp.
	* 0: freq_start register field is required to be written to trigger the frequency counter
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t FreqCounterTriggerSel : 1;        /*## attribute FreqCounterTriggerSel */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 23;        /*## attribute Reserved1 */
}R2M02_FreqCounterStartBits_t;
/**
* R2M02_FreqCounterReadValueBits_t
* RegisterName: FREQ_COUNTER_READ_VALUE
* Frequency Counter : Used for measuring Serialiser Clock 480/600 frequency
* Address: 0x808
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: freq_count_value
	* Description: Freq value computed. Actual value need to be assessed based on  the ref_cntr_init value
	* e.g ref_cntr_int = d'40 then freq count value = reported value in MHz
	* e.g ref_cntr_int = d'400 (40*10) then freq count value = (reported value/10 ) in MHz
	* 
	* 
	* Read/Write: R
	* Bits: [17:0]
	* ResetValue: 0b000000000000000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t FreqCountValue : 18;        /*## attribute FreqCountValue */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: done_flag
	* Description: Indicates that a freq count value is valid. Write to freq counter start reg will clear this bit
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t DoneFlag : 1;        /*## attribute DoneFlag */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 11;        /*## attribute Reserved1 */
}R2M02_FreqCounterReadValueBits_t;
/**
* R2M02_RefCounterReadValueBits_t
* RegisterName: REF_COUNTER_READ_VALUE
* Frequency counter used for counting 480/600 MHz clock
* Address: 0x80C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: counter_read_value
	* Description: Reference count value
	* Read/Write: R
	* Bits: [15:0]
	* ResetValue: 0b0000000000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CounterReadValue : 16;        /*## attribute CounterReadValue */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M02_RefCounterReadValueBits_t;
/**
* R2M02_CrcErrorStatus1Bits_t
* RegisterName: CRC_ERROR_STATUS1
* Status of the CRC for each register.   Total 71 CRC registers for CSI2.
* Address: 0xF40
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg1
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to first 32 registers listed i.e registers 31(msb) down to 0(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg1 : 32;        /*## attribute CrcErrorStatusReg1 */
}R2M02_CrcErrorStatus1Bits_t;
/**
* R2M02_CrcErrorStatus2Bits_t
* RegisterName: CRC_ERROR_STATUS2
* Status of the CRC for each register.   Total 71 CRC registers for CSI2.
* Address: 0xF44
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg2
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to next 32 registers listed i.e registers 63(msb) down to 32(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 32;        /*## attribute CrcErrorStatusReg2 */
}R2M02_CrcErrorStatus2Bits_t;
/**
* R2M02_CrcErrorStatus3Bits_t
* RegisterName: CRC_ERROR_STATUS3
* Status of the CRC for each register.   Total 71 CRC registers for CSI2.
* Address: 0xF48
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg3
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to last 7 registers listed i.e registers 71(msb) down to 64(lsb) and rest of the bits are not valid
	* Read/Write: R
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 7;        /*## attribute CrcErrorStatusReg3 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 25;        /*## attribute Reserved0 */
}R2M02_CrcErrorStatus3Bits_t;
/**
* R2M02_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00025001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: aperture
	* Description: Aperture. Fixed value of 'h01 
	* Read/Write: R
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Aperture : 8;        /*## attribute Aperture */
	/**
	* BitsName: minor_revision
	* Description: Minor revision number i.e. with no software consequences
	* Read/Write: R
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MinorRevision : 4;        /*## attribute MinorRevision */
	/**
	* BitsName: major_revision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRevision : 4;        /*## attribute MajorRevision */
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000000010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M02_ModuleIdBits_t;

 #else
/**
* R2M02_TrimReg0Bits_t
* RegisterName: TRIM_REG0
* Dphy Trim Register0. 
* Keep the default value = 0x0A040018 for normal modes of operation.
* Address: 0x000
* ResetValue: 0x0A040018
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: hs_tx_fixed_delay_enable
	* Description: Fix delay enable control for Tx.
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t HsTxFixedDelayEnable : 1;        /*## attribute HsTxFixedDelayEnable */
	/**
	* BitsName: hs_rx_fixed_delay_enable
	* Description: Fix delay enable control for Rx
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t HsRxFixedDelayEnable : 1;        /*## attribute HsRxFixedDelayEnable */
	/**
	* BitsName: ext_low_vco_en
	* Description: External trim bit control to enable
	* the low vco
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ExtLowVcoEn : 1;        /*## attribute ExtLowVcoEn */
	/**
	* BitsName: ext_high_vco_en
	* Description: External trim bit control to enable
	* the high vco
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ExtHighVcoEn : 1;        /*## attribute ExtHighVcoEn */
	/**
	* BitsName: trim_ff_bypass_reg0
	* Description: trim to bypass flip-flop for LPTX
	* in clock lane and data lanes 1,2
	* and 3
	* Read/Write: RW
	* Bits: [27]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimFfBypassReg0 : 1;        /*## attribute TrimFfBypassReg0 */
	/**
	* BitsName: trim_imp
	* Description: Tx Impedance Control
	* Read/Write: RW
	* Bits: [26:25]
	* ResetValue: 0b01
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimImp : 2;        /*## attribute TrimImp */
	/**
	* BitsName: ddr_delay_sel
	* Description: DDR delay trim control
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [24:23]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DdrDelaySel : 2;        /*## attribute DdrDelaySel */
	/**
	* BitsName: trim_polarity_swap_clk
	* Description: 0 - No polarity swap for clk lane
	* 1- Polarity swap for clk lane
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapClk : 1;        /*## attribute TrimPolaritySwapClk */
	/**
	* BitsName: trim_polarity_swap_ln3
	* Description: 0 - No polarity swap for lane 3
	* 1- Polarity swap for lane 3
	* Read/Write: RW
	* Bits: [21]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapLn3 : 1;        /*## attribute TrimPolaritySwapLn3 */
	/**
	* BitsName: trim_polarity_swap_ln2
	* Description: 0 - No polarity swap for lane 2
	* 1- Polarity swap for lane 2
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapLn2 : 1;        /*## attribute TrimPolaritySwapLn2 */
	/**
	* BitsName: vco_selection
	* Description: Vco selection control
	* Read/Write: RW
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t VcoSelection : 1;        /*## attribute VcoSelection */
	/**
	* BitsName: pulser_bypass
	* Description: trim control for pulse rejection
	* bypass
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PulserBypass : 1;        /*## attribute PulserBypass */
	/**
	* BitsName: iref_20u_cp_trim
	* Description: glitch removal ckt current trim
	* Read/Write: RW
	* Bits: [17:16]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Iref20UCpTrim : 2;        /*## attribute Iref20UCpTrim */
	/**
	* BitsName: trim_bit_glitch
	* Description: input selection trimbit(Comp_out
	* or vdd)
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimBitGlitch : 1;        /*## attribute TrimBitGlitch */
	/**
	* BitsName: dc_test_data
	* Description: Test data for DC in LP and Hsmode
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DcTestData : 1;        /*## attribute DcTestData */
	/**
	* BitsName: lp_dc_test_en
	* Description: LP enable trim for testing DC
	* characteristics of the LP driver
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LpDcTestEn : 1;        /*## attribute LpDcTestEn */
	/**
	* BitsName: hs_dc_test_en
	* Description: HS enable trim for testing DC
	* characteristics of the HS driver
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t HsDcTestEn : 1;        /*## attribute HsDcTestEn */
	/**
	* BitsName: cdpd
	* Description: Contention detection power
	* down
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Cdpd : 1;        /*## attribute Cdpd */
	/**
	* BitsName: trim_polarity_swap_ln1
	* Description: 0 - No polarity swap for lane 1
	* 1- Polarity swap for lane 1
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapLn1 : 1;        /*## attribute TrimPolaritySwapLn1 */
	/**
	* BitsName: trim_polarity_swap_ln0
	* Description: 0 - No polarity swap for lane 0
	* 1- Polarity swap for lane 0
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimPolaritySwapLn0 : 1;        /*## attribute TrimPolaritySwapLn0 */
	/**
	* BitsName: rxhsdpol
	* Description: Change polarity of high speed
	* receive data
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Rxhsdpol : 1;        /*## attribute Rxhsdpol */
	/**
	* BitsName: rxcksel
	* Description: trim delay control for receiver
	* data lane 0
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Rxcksel : 1;        /*## attribute Rxcksel */
	/**
	* BitsName: gnctrl
	* Description: trim gain for front-end amplifier
	* Read/Write: RW
	* Bits: [6:5]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Gnctrl : 2;        /*## attribute Gnctrl */
	/**
	* BitsName: gdefault
	* Description: trim gain for front-end amplifier
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Gdefault : 1;        /*## attribute Gdefault */
	/**
	* BitsName: tr_sel
	* Description: Rise time and fall time trimming
	* for predriver
	* Read/Write: RW
	* Bits: [3:2]
	* ResetValue: 0b10
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrSel : 2;        /*## attribute TrSel */
	/**
	* BitsName: lptx_trim_slew
	* Description: trim control for lp slew rate
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LptxTrimSlew : 2;        /*## attribute LptxTrimSlew */
}R2M02_TrimReg0Bits_t;
/**
* R2M02_TrimReg1Bits_t
* RegisterName: TRIM_REG1
* Dphy Trim Register1. 
* Should be programmed to  
* 
* = 0x4DB11041  ->  120 Mbps Per Lane Mode.
* = 0x4DB11003   -> 240 Mbps Per Lane Mode.
* = 0x4DB11006   -> 480 Mbps Per Lane Mode.
* 
* Address: 0x004
* ResetValue: 0x4DB1100F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: rtermctrl
	* Description: termination resistance control
	* Read/Write: RW
	* Bits: [31:30]
	* ResetValue: 0b01
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Rtermctrl : 2;        /*## attribute Rtermctrl */
	/**
	* BitsName: trim_hstx_ldo_pd
	* Description: power down register to control
	* the hstx ldo
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimHstxLdoPd : 1;        /*## attribute TrimHstxLdoPd */
	/**
	* BitsName: cdlow_trim
	* Description: trim control for CD low resistor
	* control
	* Read/Write: RW
	* Bits: [28:26]
	* ResetValue: 0b011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CdlowTrim : 3;        /*## attribute CdlowTrim */
	/**
	* BitsName: cdhigh_trim
	* Description: trim control for CD high resistor
	* control
	* Read/Write: RW
	* Bits: [25:23]
	* ResetValue: 0b011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CdhighTrim : 3;        /*## attribute CdhighTrim */
	/**
	* BitsName: tstodby4
	* Description: PLL Test output selection (div4/
	* div8)
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tstodby4 : 1;        /*## attribute Tstodby4 */
	/**
	* BitsName: plltstcksel
	* Description: PLL Test clock selection control
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b11
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Plltstcksel : 2;        /*## attribute Plltstcksel */
	/**
	* BitsName: res
	* Description: LPF Resistor tunability
	* Read/Write: RW
	* Bits: [19:17]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Res : 3;        /*## attribute Res */
	/**
	* BitsName: bwb
	* Description: Chargepump current tunability
	* Read/Write: RW
	* Bits: [16:14]
	* ResetValue: 0b100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Bwb : 3;        /*## attribute Bwb */
	/**
	* BitsName: pll_lock_trim
	* Description: External trim bit control to enable
	* pll lock
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllLockTrim : 1;        /*## attribute PllLockTrim */
	/**
	* BitsName: lp_enable_selection
	* Description: External lp enable selection trim bit
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LpEnableSelection : 1;        /*## attribute LpEnableSelection */
	/**
	* BitsName: refin_sel
	* Description: Reference clock signal control
	* Read/Write: RW
	* Bits: [11:9]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RefinSel : 3;        /*## attribute RefinSel */
	/**
	* BitsName: dlpf_reg_sel
	* Description: Discharge lpf register bit select
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DlpfRegSel : 1;        /*## attribute DlpfRegSel */
	/**
	* BitsName: dlpf
	* Description: Discharge lpf capacitor to zero
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Dlpf : 1;        /*## attribute Dlpf */
	/**
	* BitsName: cntb
	* Description: Dphy PLL divider value.Combination of cnta and cntb determines the PLL o/p frequency.
	* Need to be changed for different decimation factors and different no of lanes .Divider ratio Counter B
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Cntb : 1;        /*## attribute Cntb */
	/**
	* BitsName: cnta
	* Description: Divider ratio Counter A
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b001111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Cnta : 6;        /*## attribute Cnta */
}R2M02_TrimReg1Bits_t;
/**
* R2M02_TrimReg2Bits_t
* RegisterName: TRIM_REG2
* Dphy Trim Register2. 
* Keep the default value = 0x10000000 for normal modes of operation.
* Address: 0x008
* ResetValue: 0x10000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: rxlpen_reg_d1
	* Description: 1 in lp mode and 0 in hs mode
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxlpenRegD1 : 1;        /*## attribute RxlpenRegD1 */
	/**
	* BitsName: rxlpen_reg_d0
	* Description: 1 in lp mode and 0 in hs mode
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxlpenRegD0 : 1;        /*## attribute RxlpenRegD0 */
	/**
	* BitsName: rxlpen_reg_ck
	* Description: 1 in lp mode and 0 in hs mode
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxlpenRegCk : 1;        /*## attribute RxlpenRegCk */
	/**
	* BitsName: reg_ctrl_hsrx_en
	* Description: Register control enable for lane
	* HSRX enables
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlHsrxEn : 1;        /*## attribute RegCtrlHsrxEn */
	/**
	* BitsName: rxhsen_reg_d3_d0
	* Description: Enable register control for HSRX
	* Read/Write: RW
	* Bits: [27:24]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxhsenRegD3D0 : 4;        /*## attribute RxhsenRegD3D0 */
	/**
	* BitsName: rxhsen_reg_ck
	* Description: Enable register control for HSRX
	* clk
	* Read/Write: RW
	* Bits: [23]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxhsenRegCk : 1;        /*## attribute RxhsenRegCk */
	/**
	* BitsName: reg_ctrl_tx_pd
	* Description: Register control enable for tx
	* lane power down
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlTxPd : 1;        /*## attribute RegCtrlTxPd */
	/**
	* BitsName: txpd_reg_d3_d0
	* Description: Power down bit for Txlane
	* Read/Write: RW
	* Bits: [21:18]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxpdRegD3D0 : 4;        /*## attribute TxpdRegD3D0 */
	/**
	* BitsName: txpd_reg_ck
	* Description: Power down bit for Txlane of Clk Lane
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxpdRegCk : 1;        /*## attribute TxpdRegCk */
	/**
	* BitsName: reg_ctrl_lptx_en
	* Description: Register control enable for lane
	* lptx enables
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlLptxEn : 1;        /*## attribute RegCtrlLptxEn */
	/**
	* BitsName: txlpen_reg_d3_d0
	* Description: 1 in lp mode and 0 in hs mode data lane
	* Read/Write: RW
	* Bits: [15:12]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxlpenRegD3D0 : 4;        /*## attribute TxlpenRegD3D0 */
	/**
	* BitsName: txlpen_reg_ck
	* Description: 1 in lp mode and 0 in hs  clock lane
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxlpenRegCk : 1;        /*## attribute TxlpenRegCk */
	/**
	* BitsName: reg_ctrl_hstx_en
	* Description: Register control enable for lane
	* HSTX enables
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlHstxEn : 1;        /*## attribute RegCtrlHstxEn */
	/**
	* BitsName: txhsen_reg_d3_d0
	* Description: Enable register control for HSTX data line 
	* Read/Write: RW
	* Bits: [9:6]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxhsenRegD3D0 : 4;        /*## attribute TxhsenRegD3D0 */
	/**
	* BitsName: txhsen_reg_ck
	* Description: Enable register control for HSTX clk
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxhsenRegCk : 1;        /*## attribute TxhsenRegCk */
	/**
	* BitsName: pllrst_reg
	* Description: Pll reset
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllrstReg : 1;        /*## attribute PllrstReg */
	/**
	* BitsName: pllpden
	* Description: Register control enable for pll
	* power down
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Pllpden : 1;        /*## attribute Pllpden */
	/**
	* BitsName: pllpd_reg
	* Description: Power down for pll
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllpdReg : 1;        /*## attribute PllpdReg */
	/**
	* BitsName: rstn_reg
	* Description: Reset input through register
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RstnReg : 1;        /*## attribute RstnReg */
	/**
	* BitsName: rstn_reg_en
	* Description: Enable Reset input through register
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RstnRegEn : 1;        /*## attribute RstnRegEn */
}R2M02_TrimReg2Bits_t;
/**
* R2M02_TrimReg3Bits_t
* RegisterName: TRIM_REG3
* Dphy Trim Register3. 
* Always keep the default value of 0x0020C1FC for all modes of operation. The bits 30..26 are used for internal to the AFE and not related to polarity swap and hence should not be changed.
* TRIM_REG0(bits 9,10,20,21,22) is used for polarity swap
* Address: 0x00C
* ResetValue: 0x0020C1FC
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vbg_sel
	* Description: Bandgap selection control
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t VbgSel : 1;        /*## attribute VbgSel */
	/**
	* BitsName: clk_pol_sel_d3_d0
	* Description: trim control for clock polarity
	* selection of data lane
	* Read/Write: RW
	* Bits: [30:27]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ClkPolSelD3D0 : 4;        /*## attribute ClkPolSelD3D0 */
	/**
	* BitsName: clk_pol_sel_ck
	* Description: trim control for clock polarity
	* selection of clk
	* Read/Write: RW
	* Bits: [26]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ClkPolSelCk : 1;        /*## attribute ClkPolSelCk */
	/**
	* BitsName: bist_lane_trim_3_0
	* Description: Enable Bandgap offset cancellation
	* circuit
	* Read/Write: RW
	* Bits: [25:22]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BistLaneTrim30 : 4;        /*## attribute BistLaneTrim30 */
	/**
	* BitsName: trim_s3_s0
	* Description: Common mode voltage control
	* for TX
	* Read/Write: RW
	* Bits: [21:18]
	* ResetValue: 0b1000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimS3S0 : 4;        /*## attribute TrimS3S0 */
	/**
	* BitsName: bw_res_sel
	* Description: PLL BW resistor selection control
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BwResSel : 1;        /*## attribute BwResSel */
	/**
	* BitsName: v2ipd_bgpd
	* Description: Power down selection for BG,
	* bias(v2i)
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t V2IpdBgpd : 1;        /*## attribute V2IpdBgpd */
	/**
	* BitsName: trim_ff_bypass_reg3
	* Description: trim to bypass flip-flop for LPTX
	* in data lanes 0
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TrimFfBypassReg3 : 1;        /*## attribute TrimFfBypassReg3 */
	/**
	* BitsName: rterm_reg_en
	* Description: Register control enable for termination
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RtermRegEn : 1;        /*## attribute RtermRegEn */
	/**
	* BitsName: rtermen_reg_d3_d0
	* Description: Register control for termination
	* enable data 
	* Read/Write: RW
	* Bits: [13:10]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RtermenRegD3D0 : 4;        /*## attribute RtermenRegD3D0 */
	/**
	* BitsName: rtermen_reg_ck
	* Description: Register control for termination
	* enable clk
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RtermenRegCk : 1;        /*## attribute RtermenRegCk */
	/**
	* BitsName: reg_ctrl_rx_pd
	* Description: Register control enable for rx
	* lane power down
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlRxPd : 1;        /*## attribute RegCtrlRxPd */
	/**
	* BitsName: rxpd_reg_d3_d0
	* Description: Power down bit for data Rxlane 
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b1111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxpdRegD3D0 : 4;        /*## attribute RxpdRegD3D0 */
	/**
	* BitsName: rxpd_reg_ck
	* Description: Power down bit for Rxlane of Clk Lane
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxpdRegCk : 1;        /*## attribute RxpdRegCk */
	/**
	* BitsName: reg_ctrl_lprx_en
	* Description: Register control enable for lane
	* lprx enables
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RegCtrlLprxEn : 1;        /*## attribute RegCtrlLprxEn */
	/**
	* BitsName: rxlpen_reg_d3_d2
	* Description: 1 in lp mode and 0 in hs mode
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxlpenRegD3D2 : 2;        /*## attribute RxlpenRegD3D2 */
}R2M02_TrimReg3Bits_t;
/**
* R2M02_DphyDfeDlnRegister0Bits_t
* RegisterName: DPHY_DFE_DLN_REGISTER_0
* DLN_REG0 
* Should be programmed to  
* 0x03068309 -> 480 Mbps per Lane
* 0x01038106 -> 240 Mbps per Lane
* 0x01028004 -> 120 Mbps per Lane
* Address: 0x020
* ResetValue: 0x0A0D0716
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: dfe_dln_hs_trial
	* Description: This parameter specifies the number of byte clock cycles the data lane shall wait to complete the HS TRIAL time
	* Read/Write: RW
	* Bits: [31:24]
	* ResetValue: 0b00001010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnHsTrial : 8;        /*## attribute DfeDlnHsTrial */
	/**
	* BitsName: dfe_dln_hs_exit
	* Description: This parameter specifies the number of byte clock cycles the data lane shall wait to complete the HS-EXIT time
	* 
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00001101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnHsExit : 8;        /*## attribute DfeDlnHsExit */
	/**
	* BitsName: dfe_dln_hs_prepare
	* Description: This parameter specifies the number of clock cycles the data lane shall wait to complete the HS PREPARE time
	* [13:8]   -> In Byte Clock Cycles 
	* [15:14] -> In DDR Clock Cyles s
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnHsPrepare : 8;        /*## attribute DfeDlnHsPrepare */
	/**
	* BitsName: dfe_dln_hs_zero_cnt
	* Description: This parameter specifies the number of byte clocks cycles the data lane shall wait to complete the HS-ZERO time
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00010110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnHsZeroCnt : 8;        /*## attribute DfeDlnHsZeroCnt */
}R2M02_DphyDfeDlnRegister0Bits_t;
/**
* R2M02_DphyDfeDlnRegister1Bits_t
* RegisterName: DPHY_DFE_DLN_REGISTER_1
* DLN_REG1 
* Should be programmed to  
* 0x00030E04 -> 480 Mbps per Lane mode
* 0x00010A03 -> 240 Mbps per Lane mode
* 0x00000803 -> 120 Mbps per Lane mode
* Address: 0x024
* ResetValue: 0x00061E07
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: dfe_dln_lpx_hs_cnt
	* Description: This parameter specifies the number of byte clock cycles required to accommodate an LP- xx state on the data lane
	* 
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00000110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnLpxHsCnt : 8;        /*## attribute DfeDlnLpxHsCnt */
	/**
	* BitsName: dfe_dln_sync_cnt
	* Description: This parameter specifies the number of byte clock cycles the
	* data lane shall wait before announcing an error on the
	* timeout of the SYNC pattern
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00011110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnSyncCnt : 8;        /*## attribute DfeDlnSyncCnt */
	/**
	* BitsName: dfe_dln_rx_cnt
	* Description: This parameter specifies the number of byte clocks cycles the data lane shall wait before enabling the HS receiver
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeDlnRxCnt : 8;        /*## attribute DfeDlnRxCnt */
}R2M02_DphyDfeDlnRegister1Bits_t;
/**
* R2M02_DphyDfeClnRegister0Bits_t
* RegisterName: DPHY_DFE_CLN_REGISTER_0
* CLN_REG0
* Should be programmed to  
* 0x0406030E -> 480 Mbps per Lane mode
* 0x03030106 -> 240 Mbps per Lane mode
* 0x02024003 -> 120 Mbps per Lane mode
* Address: 0x028
* ResetValue: 0x080D0521
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: dfe_cln_hs_trial
	* Description: This parameter specifies the number of byte clock cycles the clock lane transmitter module shall wait during the TRIAL sequence of the high speed clock transmission
	* Read/Write: RW
	* Bits: [31:24]
	* ResetValue: 0b00001000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnHsTrial : 8;        /*## attribute DfeClnHsTrial */
	/**
	* BitsName: dfe_cln_hs_exit
	* Description: This parameter specifies the number of byte clock cycles the clock lane transmitter module shall wait during the exit sequence of the high speed clock transmission
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00001101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnHsExit : 8;        /*## attribute DfeClnHsExit */
	/**
	* BitsName: dfe_cln_prepare
	* Description: This parameter specifies the number of  clock cycles the clock lane transmitter module shall wait during the prepare sequence of the high speed clock transmission
	* [13:8]   -> In Byte Clock Cycles 
	* [15:14] -> In DDR Clock Cyles s
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnPrepare : 8;        /*## attribute DfeClnPrepare */
	/**
	* BitsName: dfe_cln_zero
	* Description: This parameter specifies the number of byte clocks cycles the clock lane transmitter module shall wait during the HS-ZERO sequence of the high speed clock transmission
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00100001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnZero : 8;        /*## attribute DfeClnZero */
}R2M02_DphyDfeClnRegister0Bits_t;
/**
* R2M02_DphyDfeClnRegister1Bits_t
* RegisterName: DPHY_DFE_CLN_REGISTER_1
* CLN_REG1
* Should be programmed to  
* 0x000A0102 -> 480 Mbps per Lane mode
* 0x00080101 -> 240 Mbps per Lane mode
* 0x00070100 -> 120 Mbps per Lane mode
* 
* Note: Ideal values for continous clock mode are specified above, For non-continuous clock mode, the same settings should work. Incase of failure, the lsb to be adjusted by +1 from the current settings for this field
* Address: 0x02C
* ResetValue: 0x00000006
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: tclk_post
	* Description: This parameter specifies the number of byte clock cycles the clock lane transmitter module shall wait before removing the clock lane request after the last associated data lane has transitioned to LP mode
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TclkPost : 8;        /*## attribute TclkPost */
	/**
	* BitsName: tclk_pre
	* Description: This parameter specifies that the HS clock shall be driven by the transmitter prior to any associated data lane beginning the transition from LP to HS mode. The parameter is in terms of number of TxByteClkHS
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TclkPre : 8;        /*## attribute TclkPre */
	/**
	* BitsName: dfe_cln_lpx_hs_cnt
	* Description: This parameter specifies the number of byte clocks required to accommodate an LP-xx stat on the clock lane
	* 
	* Note: Ideal values for continous clock mode are specified above, For non-continuous clock mode, the same settings should work. Incase of failure, the lsb to be adjusted by +1 from the current settings for this field
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DfeClnLpxHsCnt : 8;        /*## attribute DfeClnLpxHsCnt */
}R2M02_DphyDfeClnRegister1Bits_t;
/**
* R2M02_PpiDataLaneSwapRegisterBits_t
* RegisterName: PPI_DATA_LANE_SWAP_REGISTER
* Set Number of DPHY Lanes
* Address: 0x034
* ResetValue: 0x00000300
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
	/**
	* BitsName: number_of_lanes
	* Description: Default: - 4-Lanes. Set by the processor to configure the number of PPI lanes 
	* When 00 : One Lane Enabled (Lane-0) 
	* When 01 : Two Lane Enabled (Lane-0,1) 
	* When 10 : Three Lane Enabled( Lane-0,1,2) 
	* When 11 : Four Lane Enabled( Lane-0,1,2,3)
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b11
	* Source: Application
	* FuSa: No
	*/
	uint32_t NumberOfLanes : 2;        /*## attribute NumberOfLanes */
	/**
	* BitsName: swap_lane3
	* Description: Set by the processor to enable the Lane-3 swapping. When enable the LANE3 PPI interface signal of Controller is driven on to respective Lane on the DPHY 
	* When 00 : No Swap : Lane3 : Lane3 
	* When 01 : Swap : Lane3 : Lane0 
	* When 10 : Swap : Lane3 : Lane1
	*  When 11 : Swap : Lane3 : Lane2
	* Read/Write: RW
	* Bits: [7:6]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwapLane3 : 2;        /*## attribute SwapLane3 */
	/**
	* BitsName: swap_lane2
	* Description: Set by the processor to enable the Lane-2 swapping. When enable the LANE2 PPI interface signal of Controller is driven on to respective Lane on the DPHY 
	* When 00 : No Swap : Lane2 : Lane2
	*  When 01 : Swap : Lane2 : Lane0 
	* When 10 : Swap : Lane2 : Lane1 
	* When 11 : Swap : Lane2 : Lane3
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwapLane2 : 2;        /*## attribute SwapLane2 */
	/**
	* BitsName: swap_lane1
	* Description: Set by the processor to enable the Lane-1 swapping. When enable the LANE1 PPI interface signal of Controller is driven on to respective Lane on the DPHY
	*  When 00 : No Swap : Lane1 : Lane1 
	* When 01 : Swap : Lane1 : Lane0 
	* When 10 : Swap : Lane1 : Lane2 
	* When 11 : Swap : Lane1 : Lane3
	* Read/Write: RW
	* Bits: [3:2]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwapLane1 : 2;        /*## attribute SwapLane1 */
	/**
	* BitsName: swap_lane0
	* Description: Set by the processor to enable the Lane-0 swapping. When enable the LANE0 PPI interface signal of Controller is driven on to respective Lane on the DPHY 
	* When 00 : No Swap : Lane0 : Lane0
	*  When 01 : Swap : Lane0 : Lane1
	*  When 10 : Swap : Lane0 : Lane2 
	* When 11 : Swap : Lane0 : Lane3
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwapLane0 : 2;        /*## attribute SwapLane0 */
}R2M02_PpiDataLaneSwapRegisterBits_t;
/**
* R2M02_FifoStatusRegisterBits_t
* RegisterName: FIFO_STATUS_REGISTER
* Sensor FIFO Status register
* Address: 0x038
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: csi_fifo_full
	* Description: Indicates the CSI FIFO threshold full status
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CsiFifoFull : 1;        /*## attribute CsiFifoFull */
	/**
	* BitsName: csi_fifo_empty
	* Description: Indicates the CSI FIFO empty status
	* Read/Write: R
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CsiFifoEmpty : 1;        /*## attribute CsiFifoEmpty */
	/**
	* BitsName: sensor_fifo_full
	* Description: Indicates the SENSOR FIFO full status
	* Read/Write: R
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SensorFifoFull : 1;        /*## attribute SensorFifoFull */
	/**
	* BitsName: sensor_fifo_almost_full
	* Description: Indicates the SENSOR FIFO threshold full status
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SensorFifoAlmostFull : 1;        /*## attribute SensorFifoAlmostFull */
	/**
	* BitsName: sensor_fifo_empty
	* Description: Indicates the SENSOR FIFO empty status
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SensorFifoEmpty : 1;        /*## attribute SensorFifoEmpty */
}R2M02_FifoStatusRegisterBits_t;
/**
* R2M02_UsdPixelModeControlRegisterBits_t
* RegisterName: USD_PIXEL_MODE_CONTROL_REGISTER
* Keep reset value
* Address: 0x03C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: usd_data_type8_en
	* Description: Set by the processor to configure the USD data_type8 one/two/three/four pixel mode 
	* 00 : One pixel mode configured
	*  01 : Two pixel mode configured 
	* 10 : Three pixel mode configured
	*  11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [15:14]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType8En : 2;        /*## attribute UsdDataType8En */
	/**
	* BitsName: usd_data_type7_en
	* Description: Set by the processor to configure the USD data_type7 one/two/three/four pixel mode 
	* 00 : One pixel mode configured 
	* 01 : Two pixel mode configured
	* 10 : Three pixel mode configured 
	* 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType7En : 2;        /*## attribute UsdDataType7En */
	/**
	* BitsName: usd_data_type6_en
	* Description: Set by the processor to configure the USD data_type6 one/two/three/four pixel mode
	*  00 : One pixel mode configured
	*  01 : Two pixel mode configured 
	* 10 : Three pixel mode configured 
	* 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [11:10]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType6En : 2;        /*## attribute UsdDataType6En */
	/**
	* BitsName: usd_data_type5_en
	* Description: Set by the processor to configure the USD data_type5 one/two/three/four pixel mode 
	* 00 : One pixel mode configured
	*  01 : Two pixel mode configured
	*  10 : Three pixel mode configured 
	* 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType5En : 2;        /*## attribute UsdDataType5En */
	/**
	* BitsName: usd_data_type4_en
	* Description: Set by the processor to configure the USD data_type4 one/two/three/four pixel mode 
	* 00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : Three pixel mode configured 
	* 11: Four pixel mode configured
	* Read/Write: RW
	* Bits: [7:6]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType4En : 2;        /*## attribute UsdDataType4En */
	/**
	* BitsName: usd_data_type3_en
	* Description: Set by the processor to configure the USD data_type3 one/two/three/four pixel mode 
	* 00 :One pixel mode configured 
	* 01 :Two pixel mode configured
	*  10 : Three pixel mode configured
	*  11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType3En : 2;        /*## attribute UsdDataType3En */
	/**
	* BitsName: usd_data_type2_en
	* Description: Set by the processor to configure the USD data_type2 one/two/three/four pixel mode 00 : One pixel mode configured 01 : Two pixel mode configured 10 : Three pixel mode configured 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [3:2]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType2En : 2;        /*## attribute UsdDataType2En */
	/**
	* BitsName: usd_data_type1_en
	* Description: Set by the processor to configure the USD data_type1 one/two/three/four pixel mode
	*  00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : Three pixel mode configured 
	* 11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UsdDataType1En : 2;        /*## attribute UsdDataType1En */
}R2M02_UsdPixelModeControlRegisterBits_t;
/**
* R2M02_YuvPixelModeControlRegisterBits_t
* RegisterName: YUV_PIXEL_MODE_CONTROL_REGISTER
* Keep reset value
* Address: 0x040
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 10;        /*## attribute Reserved0 */
	/**
	* BitsName: yuv422_8bit_en
	* Description: Set by the processor to configure the YUV422 8-bit one/two pixel mode 00 : One pixel mode configured 01 : Two pixel mode configured 10 : NA 11 : NA
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Yuv4228BitEn : 2;        /*## attribute Yuv4228BitEn */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 20;        /*## attribute Reserved1 */
}R2M02_YuvPixelModeControlRegisterBits_t;
/**
* R2M02_RawPixelModeControlRegisterBits_t
* RegisterName: RAW_PIXEL_MODE_CONTROL_REGISTER
* Keep reset value
* Address: 0x044
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 20;        /*## attribute Reserved0 */
	/**
	* BitsName: raw14_en
	* Description: Set by the processor to configure RAW14 one/two pixel mode 00 : One pixel mode configured
	*  01 : Two pixel mode configured 
	* 10 : NA
	*  11 : NA
	* Read/Write: RW
	* Bits: [11:10]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Raw14En : 2;        /*## attribute Raw14En */
	/**
	* BitsName: raw12_en
	* Description: Set by the processor to configure RAW12 one/two pixel mode 00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : NA 
	* 11 : NA
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Raw12En : 2;        /*## attribute Raw12En */
	/**
	* BitsName: raw10_en
	* Description: Set by the processor to configure RAW10 one/two/three pixel mode 00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : Three pixel mode configured 
	* 11 : NA
	* Read/Write: RW
	* Bits: [7:6]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Raw10En : 2;        /*## attribute Raw10En */
	/**
	* BitsName: raw8_en
	* Description: Set by the processor to configure RAW8 one/two/three/four pixel mode 00 : One pixel mode configured 
	* 01 : Two pixel mode configured 
	* 10 : Three pixel mode configured
	*  11 : Four pixel mode configured
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Raw8En : 2;        /*## attribute Raw8En */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
}R2M02_RawPixelModeControlRegisterBits_t;
/**
* R2M02_PhyTinitCountRegisterBits_t
* RegisterName: PHY_TINIT_COUNT_REGISTER
* PHY Init Time control. (After the PLL Lock , the Clock Lane remains in the LP state till this counter is expired).Program a value of 0x00002000 (recommended ) for fast lock after reset release .
* Address: 0x048
* ResetValue: 0x0000FFFF
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: tinit_timer
	* Description: This parameter specifies the number of txbyte clocks cycles the CSI-2 controller should wait to start accepting the data from the sensor interface.
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000001111111111111111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TinitTimer : 32;        /*## attribute TinitTimer */
}R2M02_PhyTinitCountRegisterBits_t;
/**
* R2M02_Vc0CompressionPredictionSchemeRegister1Bits_t
* RegisterName: VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* Keep reset value
* Address: 0x04C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: vc0_compression_prediction1
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [29:0]
	* ResetValue: 0b000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc0CompressionPrediction1 : 30;        /*## attribute Vc0CompressionPrediction1 */
}R2M02_Vc0CompressionPredictionSchemeRegister1Bits_t;
/**
* R2M02_Vc0CompressionPredictionSchemeRegister2Bits_t
* RegisterName: VC0_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* Keep reset value
* Address: 0x050
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
	/**
	* BitsName: vc0_compression_prediction2
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc0CompressionPrediction2 : 10;        /*## attribute Vc0CompressionPrediction2 */
}R2M02_Vc0CompressionPredictionSchemeRegister2Bits_t;
/**
* R2M02_Vc1CompressionPredictionSchemeRegister1Bits_t
* RegisterName: VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* Keep reset value
* Address: 0x054
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: vc1_compression_prediction1
	* Description: Since the Chip does not support any Prediction or Compression write ZERO
	* Read/Write: RW
	* Bits: [29:0]
	* ResetValue: 0b000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc1CompressionPrediction1 : 30;        /*## attribute Vc1CompressionPrediction1 */
}R2M02_Vc1CompressionPredictionSchemeRegister1Bits_t;
/**
* R2M02_Vc1CompressionPredictionSchemeRegister2Bits_t
* RegisterName: VC1_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* Keep reset value
* Address: 0x058
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
	/**
	* BitsName: vc1_compression_prediction2
	* Description: Since the Chip does not support any Prediction or Compression write ZERO
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc1CompressionPrediction2 : 10;        /*## attribute Vc1CompressionPrediction2 */
}R2M02_Vc1CompressionPredictionSchemeRegister2Bits_t;
/**
* R2M02_Vc2CompressionPredictionSchemeRegister1Bits_t
* RegisterName: VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* Keep reset value
* Address: 0x05C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: vc2_compression_prediction1
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [29:0]
	* ResetValue: 0b000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc2CompressionPrediction1 : 30;        /*## attribute Vc2CompressionPrediction1 */
}R2M02_Vc2CompressionPredictionSchemeRegister1Bits_t;
/**
* R2M02_Vc2CompressionPredictionSchemeRegister2Bits_t
* RegisterName: VC2_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* Keep reset value
* Address: 0x060
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
	/**
	* BitsName: vc2_compression_prediction2
	* Description: Since the Chip does not support any Prediction or Compression write ZERO
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc2CompressionPrediction2 : 10;        /*## attribute Vc2CompressionPrediction2 */
}R2M02_Vc2CompressionPredictionSchemeRegister2Bits_t;
/**
* R2M02_Vc3CompressionPredictionSchemeRegister1Bits_t
* RegisterName: VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_1
* Keep reset value
* Address: 0x064
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: vc3_compression_prediction1
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [29:0]
	* ResetValue: 0b000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc3CompressionPrediction1 : 30;        /*## attribute Vc3CompressionPrediction1 */
}R2M02_Vc3CompressionPredictionSchemeRegister1Bits_t;
/**
* R2M02_Vc3CompressionPredictionSchemeRegister2Bits_t
* RegisterName: VC3_COMPRESSION_PREDICTION_SCHEME_REGISTER_2
* Keep reset value
* Address: 0x068
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
	/**
	* BitsName: vc3_compression_prediction2
	* Description: Since the Chip does not support any Prediction or Compression keep defualt value
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Vc3CompressionPrediction2 : 10;        /*## attribute Vc3CompressionPrediction2 */
}R2M02_Vc3CompressionPredictionSchemeRegister2Bits_t;
/**
* R2M02_PllCountRegisterBits_t
* RegisterName: PLL_COUNT_REGISTER
* Program a value of 0x00000000 (recommended ) for fast lock after reset release .
* Address: 0x06C
* ResetValue: 0x00004E20
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_cnt
	* Description: Programmed by the processor. Default time period is set for 1ms. This is set in terms of txbyteclkhs
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0100111000100000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllCnt : 16;        /*## attribute PllCnt */
}R2M02_PllCountRegisterBits_t;
/**
* R2M02_DeviceReadyIndicationRegisterBits_t
* RegisterName: DEVICE_READY_INDICATION_REGISTER
* Device ready Indication register 
* Address: 0x070
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: device_ready
	* Description: When 0 : Indicates that CSI-2 controller is not ready to accept packet information from external sensor When 1: Indicates that CSI-2 controller is ready to accept packet information from external sensor.Chrp should be enabled only after this bit goes high.
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t DeviceReady : 1;        /*## attribute DeviceReady */
}R2M02_DeviceReadyIndicationRegisterBits_t;
/**
* R2M02_Csi2AdaptConfigReg1Bits_t
* RegisterName: CSI2_ADAPT_CONFIG_REG1
* CSI2 Adapter configuration register.
* Address: 0x080
* ResetValue: 0x0000002C
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: csi2txulpsexit
	* Description: This signal indicates if the DPHY has to exit out of a ULPS state. If this is asserted high the CSI-2 Tx will drive ULPS exit enable for D-PHY(Clock and Data lanes) This is configured by the application to exit the DPHY from ULPS mode
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Txulpsexit : 1;        /*## attribute Csi2Txulpsexit */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: csi2txulpsesc
	* Description: This signal indicates if the DPHY has to initiates the ULPS sequence. If this is asserted high the CSI-2 Tx will drive ULPS entry enable for D-PHY(Clock and Data Lanes) This is configured by application for driving the D-PHY to ULPS mode
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Txulpsesc : 1;        /*## attribute Csi2Txulpsesc */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 7;        /*## attribute Reserved2 */
	/**
	* BitsName: csi2dphyclkmode
	* Description: When 0 : Continuous Clock Mode When 1 : Non Continuous Clock Mode This is configured by the application based on the mode in which MIPI PHY clock lane need to operate
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Dphyclkmode : 1;        /*## attribute Csi2Dphyclkmode */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 2;        /*## attribute Reserved5 */
	/**
	* BitsName: csi2packettype
	* Description: the Chip supports only RAW12 (RAW12 -> 0x2C. So use 0x2C as default value)
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Packettype : 6;        /*## attribute Csi2Packettype */
}R2M02_Csi2AdaptConfigReg1Bits_t;
/**
* R2M02_Csi2AdaptConfigReg2Bits_t
* RegisterName: CSI2_ADAPT_CONFIG_REG2
* CSI2 Adapter configuration register.
* Address: 0x084
* ResetValue: 0x0C810000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: csi2delaycnt
	* Description: An internal delay generator which delays the incoming frame_active negedge signals from chirp so that the delay requirement b/w sensor signal FE and end of CSI2 transmission is met.Counter running at 40 MHz.The delay value varies with the decimation and no of DPHY lanes enabled (csi_clk). Need feedback from validation to fix the delay for various decimations
	* Read/Write: RW
	* Bits: [31:20]
	* ResetValue: 0b000011001000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Delaycnt : 12;        /*## attribute Csi2Delaycnt */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: csi2dphyclkdiv
	* Description: Refrece clock generationor the PLL inside DPHY.Default = 20MHz.Input to the clock divider is 40MHz XTAL clock
	* 
	* 01 - Divide by 2  (40/2 = 20 MHz)
	* 10 - Divide by 3 (40/3 = 13.33 MHz)
	* 11 - Divide by 4 (40/4 = 10 MHz)
	* 
	* Read/Write: RW
	* Bits: [17:16]
	* ResetValue: 0b01
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Dphyclkdiv : 2;        /*## attribute Csi2Dphyclkdiv */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: csi2crccontrol
	* Description: Packet footer :This bit enables the 32-bit CRC engine and append the CRC output in the packet footer.32 -bit CRC is send as three seperated 12 bit in the packet.  
	* 1= enable CRC
	* 0= disable CRC 
	* 
	* 
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Crccontrol : 1;        /*## attribute Csi2Crccontrol */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: csi2datagrpmodeselect
	* Description: 1= 4 data chunk mode(4 consecutive samples of ADC1,4 consecutive samples of ADC2,4 consecutive samples of ADC3, 4 consecutive samples of ADC4,4 consecutive samples of ADC1 so on)
	* 0= 1 data  mode (1 sample of ADC1,1 sample of ADC2,1 sample of ADC3,1 sample of ADC4,1 sample of ADC1 so on)  
	* 
	* 
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Datagrpmodeselect : 1;        /*## attribute Csi2Datagrpmodeselect */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: csi2packetenable
	* Description: Packet Header Enable :
	* 0: no Packet Header on transmitted data Packet.
	* 1: Packet Header is appended to the  Data Packet.
	* Note:Packet header contains Chirp No and Word Count(no of ADC samples sent over the CSI2 interface)
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Csi2Packetenable : 1;        /*## attribute Csi2Packetenable */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
}R2M02_Csi2AdaptConfigReg2Bits_t;
/**
* R2M02_Csi2AdaptConfigReg3Bits_t
* RegisterName: CSI2_ADAPT_CONFIG_REG3
* CSI2 Adapter configuration register.
* Address: 0x088
* ResetValue: 0x0000002B
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: packet_endianness
	* Description: 0: Sends MS first in Packet Header and Packet Footer(crc)
	* 1: Send LS first in Packet Header and Packet Footer(crc)
	* Note: This is only applicable to Packet Header and Packet Footer not for Data
	* 
	* Note: CRC is 32 bit and WordCunt is 14 bit so this needs to be splitted into MS and LS formats.
	* 
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PacketEndianness : 1;        /*## attribute PacketEndianness */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: channeldisabledatasel
	* Description: Individual ADC channel can de disabled or enabled.
	* 0 : when adc channel is disabled send zero data 
	* 1: when adc channel is disabled send Test data programmed in Csi2TestModeControlReg
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Channeldisabledatasel : 1;        /*## attribute Channeldisabledatasel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 4;        /*## attribute Reserved2 */
	/**
	* BitsName: adcchanneldisable
	* Description: Only for internal validation and debug purpose.Individual ADC channel can be disabled.So in this case instead of scaling down the clock,the Chip send a known data in this disabled ADC slot.
	* 
	* [0] ->  1 :  disable  adc channel 1 & 0 : enable adc channel 1
	* [1] ->  1 :  disable  adc channel 2 & 0 : enable adc channel 2
	* [2] ->  1 :  disable  adc channel 3 & 0 : enable adc channel 3
	* [3] ->  1 :  disable  adc channel 4 & 0 : enable adc channel 4
	* Read/Write: RW
	* Bits: [19:16]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Adcchanneldisable : 4;        /*## attribute Adcchanneldisable */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: chirp_number_clr_sel
	* Description: Chirp Number clear selection:
	* 0: Chirp Number is cleared automatically  for every sequen/frame active
	* 1: Chirp number is cleared by writing to the register bit chirp_number_clr
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpNumberClrSel : 1;        /*## attribute ChirpNumberClrSel */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: chirp_number_clr
	* Description: Chirp number clear bit from SPI
	* 1:  Clear the internal Chirp number counter
	* 0:  No clear
	* Note: autoclear register
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpNumberClr : 1;        /*## attribute ChirpNumberClr */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 2;        /*## attribute Reserved5 */
	/**
	* BitsName: frame_active_delay
	* Description: Frame active rising edge triggeres the FS short packet.Profile load occurs every Frame active rise edge which switches the internal clock divider based on the new decimation value.  
	* Frame active is internally delayed to accomodate the Switching time of the Clock divider. Delay counter is running at 40 MHz clock in all modes.
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FrameActiveDelay : 6;        /*## attribute FrameActiveDelay */
}R2M02_Csi2AdaptConfigReg3Bits_t;
/**
* R2M02_Csi2CrcCtrl1Bits_t
* RegisterName: CSI2_CRC_CTRL1
* CRC 32- control
* Address: 0x08C
* ResetValue: 0xFFFFFFFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: crc_init_value
	* Description: Initial value of the CRC polynomial register register..It is a CRC Engine configuration parameter 
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b11111111111111111111111111111111
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CrcInitValue : 32;        /*## attribute CrcInitValue */
}R2M02_Csi2CrcCtrl1Bits_t;
/**
* R2M02_Csi2CrcCtrl2Bits_t
* RegisterName: CSI2_CRC_CTRL2
* CRC 32- control
* Address: 0x090
* ResetValue: 0xFFFFFFFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: crc_xor_out_value
	* Description: Final CRC output is XOR ed with this value.It is a CRC Engine configuration parameter 
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b11111111111111111111111111111111
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CrcXorOutValue : 32;        /*## attribute CrcXorOutValue */
}R2M02_Csi2CrcCtrl2Bits_t;
/**
* R2M02_Csi2CrcCtrl3Bits_t
* RegisterName: CSI2_CRC_CTRL3
* CRC 32- control.CRC is calculated using a 32-bit input CRC engine.Two consecutive adc samples con-catinated [data1,4'b0000 : data0,4'b0000] and given to the engine.
* Address: 0x094
* ResetValue: 0x00000110
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: dummy_zero_position
	* Description: CRC is calculated using a 32-bit input CRC engine.Two consecutive adc samples con-catinated [data1,4'b0000 : data0,4'b0000] and given to the engine.Zero padding can be done at LSB side or MSB side.
	* 
	* 0: Zero padding at LSB position (default)
	* 1: Zero padding at MSB position
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t DummyZeroPosition : 1;        /*## attribute DummyZeroPosition */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: reflect_output
	* Description: For reflecting the final CRC ouput bits before final XOR .
	* 0 : No swapping 
	* 1 : Bit order is swapped around the middle of the CRC result.(default)
	* It is a CRC Engine configuration parameter
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ReflectOutput : 1;        /*## attribute ReflectOutput */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: reflect_input
	* Description: Reflecting the bits of the input 32-bit data around the middle. 
	* 0: No swapping
	* 1: Bit order is swapped around the middle of the input 32 bit data(default)It is a CRC Engine configuration parameter
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ReflectInput : 1;        /*## attribute ReflectInput */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: crc_endianness
	* Description: Enable/Disable CRC data Swapping :
	* The Chip uses 32-bit CRC engine. So input data to be con-catinated.  After con-catination 32 bit data is swapped before inputting the date to the CRC engine
	* 0 : Swapping enable 
	* 1 : Swapping disable
	* 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CrcEndianness : 1;        /*## attribute CrcEndianness */
}R2M02_Csi2CrcCtrl3Bits_t;
/**
* R2M02_PdcConfigRegBits_t
* RegisterName: PDC_CONFIG_REG
* PDC Configuration controls
* Address: 0x098
* ResetValue: 0x01A9A700
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: disable_pdc_filter
	* Description: Debug:
	* 1 : Filter inside PDC is disabled (Only down sampling)
	* 0:  Filter Enabled
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DisablePdcFilter : 1;        /*## attribute DisablePdcFilter */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: enable_pdc_reset
	* Description: Enable PDC Sync
	* 1: PDC will get reset for every rise edge of pdc_reset signal from Chirp
	* 0: No Reset
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnablePdcReset : 1;        /*## attribute EnablePdcReset */
	/**
	* BitsName: wa_delay_decimation_mode4
	* Description: window active delay value for decimation mode 4(by 16  decimation factor).The delay b/w the input and output window active of PDC.The output data_valid will also be delayed by the same factor.Since PDC is running at 80 MHz,Delay measured in clocks of 80 MHz.
	* Delay= register value x 16 clocks
	* default  value of Delay = 10x16 = 160 clocks of 80MHz.
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [23:20]
	* ResetValue: 0b1010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WaDelayDecimationMode4 : 4;        /*## attribute WaDelayDecimationMode4 */
	/**
	* BitsName: wa_delay_decimation_mode3
	* Description: window active delay value for decimation mode 3(by 8  decimation factor).The delay b/w the input and output window active of PDC.The output data_valid will also be delayed by the same factor.Since PDC is running at 80 MHz,Delay measured in clocks of 80 MHz.
	* Delay= register value x 8 clocks
	* default  value of Delay = 9x8 = 72 clocks of 80MHz.
	* Read/Write: RW
	* Bits: [19:16]
	* ResetValue: 0b1001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WaDelayDecimationMode3 : 4;        /*## attribute WaDelayDecimationMode3 */
	/**
	* BitsName: wa_delay_decimation_mode2
	* Description: window active delay value for decimation mode 2(by 4  decimation factor).The delay b/w the input and output window active of PDC.The output data_valid will also be delayed by the same factor.Since PDC is running at 80 MHz,Delay measured in clocks of 80 MHz.
	* Delay= register value x 4 clocks
	* default  value of Delay = 10x4 = 40 clocks of 80MHz.
	* Read/Write: RW
	* Bits: [15:12]
	* ResetValue: 0b1010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WaDelayDecimationMode2 : 4;        /*## attribute WaDelayDecimationMode2 */
	/**
	* BitsName: wa_delay_decimation_mode1
	* Description: window active delay value for decimation mode 1(by 2  decimation factor).The delay b/w the input and output window active of PDC.The output data_valid will also be delayed by the same factor.Since PDC is running at 80 MHz,Delay measured in clocks of 80 MHz.
	* Delay= register value x 2 clocks
	* default  value of Delay = 7x2 = 14 clocks of 80MHz.
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WaDelayDecimationMode1 : 4;        /*## attribute WaDelayDecimationMode1 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_input_w_wa
	* Description: 
	* 0: always process input data.PDC will process all the input samples irrespective of the window active from timing engine
	* 1: PDC will only process ADC samples only during the window active
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskInputWWa : 1;        /*## attribute MaskInputWWa */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: make_output_unsigned
	* Description: Signed or Unsigned 12 bits.
	* 0: PDC output is Signed 12 bit
	* 1: PDC output is UnSigned 12 bit
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MakeOutputUnsigned : 1;        /*## attribute MakeOutputUnsigned */
}R2M02_PdcConfigRegBits_t;
/**
* R2M02_DataValidPadCtrlBits_t
* RegisterName: DATA_VALID_PAD_CTRL
* nan
* Address: 0x09C
* ResetValue: 0x00010111
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 14;        /*## attribute Reserved0 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_ehs1
	* Description: speed selection bit 1
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEhs1 : 1;        /*## attribute LvdsCsi2DatavalidMfioEhs1 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_ehs0
	* Description: MFIO Speed Selection 
	* [ehs1 ehs0] :
	* [0               0] : 20 MHz
	* [0               1] : 40 MHz
	* [1               0] : 85 MHz
	* [1               1] : 125 MHz"
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEhs0 : 1;        /*## attribute LvdsCsi2DatavalidMfioEhs0 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_epd
	* Description: Enable weak pull-down(active high)
	* 1: weak pull-down Enabled
	* 0: weak pull-down Disabled
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEpd : 1;        /*## attribute LvdsCsi2DatavalidMfioEpd */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_epun
	* Description: Enable weak pull-up (Active Low)
	* 1: weak pull-up Disabled
	* 0: weak pull-up Enabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEpun : 1;        /*## attribute LvdsCsi2DatavalidMfioEpun */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_enzi
	* Description: Receiver Enable (Active Low)
	* 1: Receiver Disabled
	* 0: Receiver Enabled
	* 
	* ENZI    EPUN  EPD    Mode
	* 
	* 0          0           0       Plain input with weak pull-up 
	* 0          0           1       Plain input with repeater (bus keeper)
	* 0          1           0       Plain input
	* 0          1           1       
	* 
	* 1          0           0       Weak pull-up
	* 1          0           1       Weak pull-down
	* 1          1           0       High impedance (Analog I/O)
	* 1          1           1       Weak pull-down
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEnzi : 1;        /*## attribute LvdsCsi2DatavalidMfioEnzi */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_en
	* Description: Data valid(mfio) pad enable/disable:
	* Disable Output Driver(Active High)
	* 0: Pad enabled
	* 1: Pad disabled.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEn : 1;        /*## attribute LvdsCsi2DatavalidMfioEn */
}R2M02_DataValidPadCtrlBits_t;
/**
* R2M02_LpMetadataConfig1Bits_t
* RegisterName: LP_METADATA_CONFIG1
* nan
* Address: 0x0A0
* ResetValue: 0x00003000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 14;        /*## attribute Reserved0 */
	/**
	* BitsName: metadata_lp_vc
	* Description: Virtual Channel used for long packet metadata transmission
	* Valid values :
	* 2'b00, 2'b01, 2'b10, 2'b11
	* Read/Write: RW
	* Bits: [17:16]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpVc : 2;        /*## attribute MetadataLpVc */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: metadata_lp_datatype
	* Description: User defined data type used for long packet metadata  transmission
	* Valid values (As per CSI2 specification): 0x30 - 0x37
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b110000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpDatatype : 6;        /*## attribute MetadataLpDatatype */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: metadata_lp_userfield_en
	* Description: Long Packet Metadata User field Enable
	* 1: User field is enabled. 72 byte long User data will be transmitted as part of Long Packet Metadata. Those bytes contain 18x32b registers from ISM
	* 0: User field is disabled & not transmitted.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpUserfieldEn : 1;        /*## attribute MetadataLpUserfieldEn */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: metadata_lp_en
	* Description: Enable of complete Long Packet Meta Data
	* 1: Enabled. Metadata Long Packet shall be transmistted after last chirp in each frame.
	* 0: Long Packet metadata transmission disabled.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpEn : 1;        /*## attribute MetadataLpEn */
}R2M02_LpMetadataConfig1Bits_t;
/**
* R2M02_LpMetadataConfig2Bits_t
* RegisterName: LP_METADATA_CONFIG2
* nan
* Address: 0x0A4
* ResetValue: 0x00500050
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: metadata_lp_start_dly
	* Description: This delay value field configures the delay between end of final chirp & start of metadata Long packet.
	* Delay counter always counts on 40MHz clock cycles. Default value(8'd80) is configured for 2us delay.
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b01010000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpStartDly : 8;        /*## attribute MetadataLpStartDly */
	/**
	* BitsName: metadata_lp_length
	* Description: Long Packet metadata length in bytes.
	* Minimum packet length shall be 8 bytes when metadata_lp_userfield_en is disabled, containing User Info
	* Minimum packet length shall be 80 bytes when metadata_lp_userfield_en is enabled (8 bytes for User Info + 18x4=72 bytes for ISM data named "Userfield")
	* When packet length configured is more than minimum required length, dummy byte '8'h33' will be transmitted to meet the packet length.
	* Even if Packet length configured is less than minimum required length, Metadata packet will be transmitted with minimum required length for selected configuration.
	* Note: Following registers from ISM are packed as part of the user field
	* csi2_adc12_clipping_events_threshold_counter
	* csi2_adc34_clipping_events_threshold_counter
	* csi2_master_error_flag_to_mcu
	* csi2_ism_error_status
	* csi2_tx_masked_error_status_reg
	* csi2_rx_masked_error_status_reg
	* csi2_chirp_masked_error_status_reg
	* csi2_mc_lo_cc_ism_otp_masked_error_status_reg
	* csi2_ssb_gb_ser_gldo_atb_masked_error_status_reg
	* csi2_adc_masked_error_status_reg_to_mcu
	* csi2_supply_masked_error_status_reg
	* csi2_register_crc_error_flag_masked_status
	* csi2_rf_power_down_masked_flag
	* csi2_status_monitoring_flag_reg_to_mcu
	* csi2_first_masked_error_info_reg
	* csi2_first_masked_error_status
	* csi2_first_masked_warning_info_reg
	* csi2_first_masked_warning_status
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000001010000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpLength : 16;        /*## attribute MetadataLpLength */
}R2M02_LpMetadataConfig2Bits_t;
/**
* R2M02_LpMetadataUserinfoBits_t
* RegisterName: LP_METADATA_USERINFO
* nan
* Address: 0x0A8
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: metadata_lp_userinfo
	* Description: Metadata User info
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MetadataLpUserinfo : 32;        /*## attribute MetadataLpUserinfo */
}R2M02_LpMetadataUserinfoBits_t;
/**
* R2M02_VirtualChannelControlBits_t
* RegisterName: VIRTUAL_CHANNEL_CONTROL
* nan
* Address: 0x100
* ResetValue: 0x00000001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: vc3_frame_num_clr
	* Description: Write '1' to this register to clear the frame counter for VC=3. Counter is cleared at the end of frame
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc3FrameNumClr : 1;        /*## attribute Vc3FrameNumClr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: vc2_frame_num_clr
	* Description: Write '1' to this register to clear the frame counter for VC=2. Counter is cleared at the end of frame
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc2FrameNumClr : 1;        /*## attribute Vc2FrameNumClr */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: vc1_frame_num_clr
	* Description: Write '1' to this register to clear the frame counter for VC=1. Counter is cleared at the end of frame
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc1FrameNumClr : 1;        /*## attribute Vc1FrameNumClr */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: vc0_frame_num_clr
	* Description: Write '1' to this register to clear the frame counter for VC=0. Counter is cleared at the end of frame
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc0FrameNumClr : 1;        /*## attribute Vc0FrameNumClr */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: vc3_en
	* Description: enable for Virtual channel 3 ; 
	* 0 = disable, 1 = enable
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc3En : 1;        /*## attribute Vc3En */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: vc2_en
	* Description: enable for Virtual channel 2 ; 
	* 0 = disable, 1 = enable
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc2En : 1;        /*## attribute Vc2En */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: vc1_en
	* Description: enable for Virtual channel 1 ; 
	* 0 = disable, 1 = enable
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc1En : 1;        /*## attribute Vc1En */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 3;        /*## attribute Reserved7 */
	/**
	* BitsName: vc0_en
	* Description: enable for Virtual channel 0 ; 
	* 0 = disable, 1 = enable
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t Vc0En : 1;        /*## attribute Vc0En */
}R2M02_VirtualChannelControlBits_t;
/**
* R2M02_SpareReg1Bits_t
* RegisterName: SPARE_REG1
* nan
* Address: 0x104
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: spare_bits_1
	* Description: Spare bits
	* 
	* Read/Write: RW
	* Bits: [31:6]
	* ResetValue: 0b00000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SpareBits1 : 26;        /*## attribute SpareBits1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 6;        /*## attribute Reserved0 */
}R2M02_SpareReg1Bits_t;
/**
* R2M02_Csi2TxnCtrlBits_t
* RegisterName: CSI2_TXN_CTRL
* CSI2 Transmission Enable register
* Address: 0x200
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: csi2_txn_en
	* Description: Transmision enable for Csi2.This should be the last register to be programmed(enabled) during configuration.
	* 0: Transmission is disabled
	* 1: Transmission is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Csi2TxnEn : 1;        /*## attribute Csi2TxnEn */
}R2M02_Csi2TxnCtrlBits_t;
/**
* R2M02_Csi2TestModeControlRegBits_t
* RegisterName: CSI2_TEST_MODE_CONTROL_REG
* only for internal validation and debug purpose.Keep default value for functional use case
* Address: 0x300
* ResetValue: 0x00000FFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: csi2_testmode_skip_pdc
	* Description: 0: test data inserted at the input side of PDC
	* 1: test data inserted at the o/p side of PDC
	* Note: During the test mode csi2_testmode_skip_pdc should be "1" to test the SER link
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Csi2TestmodeSkipPdc : 1;        /*## attribute Csi2TestmodeSkipPdc */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: csi2_testmode_data_sel
	* Description:  
	* 00 : csi2_testmode_test_data regiser field value as test data   
	* 01: Sinewave as test data (78.125 KHz)   
	* 10: Incremental Pattern as test data  ( 0x001 ->FFF)  
	* 11: PRBS7 (  X ^ 7 + X ^6 + 1)
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Csi2TestmodeDataSel : 2;        /*## attribute Csi2TestmodeDataSel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: csi2_testmode_en
	* Description: 0: PDC functional data as input to csi2
	* 1: Test data is input to csi2 
	* 
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Csi2TestmodeEn : 1;        /*## attribute Csi2TestmodeEn */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: delayed_test_pattern
	* Description: 1 : Delayed Pattern Across Channels: Channel 4 is getting
	*      the data delayed by 3 cycles, channel 3 is getting the
	*      data delayed by 2 cycles, channel 2 is getting the data 
	*      delayed by 1 cycle, and channel 1 is getting the data
	*       from the pattern generator without delay.
	* 0 : No delay across channels.
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t DelayedTestPattern : 1;        /*## attribute DelayedTestPattern */
	/**
	* BitsName: csi2_testmode_test_data
	* Description: Fixed Test Data to be send inTest Mode
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b111111111111
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Csi2TestmodeTestData : 12;        /*## attribute Csi2TestmodeTestData */
}R2M02_Csi2TestModeControlRegBits_t;
/**
* R2M02_PrbsControlBits_t
* RegisterName: PRBS_CONTROL
* PRBS test generator controls
* Address: 0x304
* ResetValue: 0x00000FFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: invert_prbs_pattern
	* Description: 1  :  Invert the PRBS Test Pattern
	* 0  :  No Invert
	* 
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t InvertPrbsPattern : 1;        /*## attribute InvertPrbsPattern */
	/**
	* BitsName: prbs_initial_value
	* Description: Initial value for the PRBS Test pattern Generator
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b111111111111
	* Source: Application
	* FuSa: Y
	*/
	uint32_t PrbsInitialValue : 12;        /*## attribute PrbsInitialValue */
}R2M02_PrbsControlBits_t;
/**
* R2M02_PdcShiftRegIdivCtrlBits_t
* RegisterName: PDC_SHIFT_REG_IDIV_CTRL
* ADC data Sampling control register
* Address: 0x310
* ResetValue: 0x00010001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 11;        /*## attribute Reserved0 */
	/**
	* BitsName: window_active_sampling_mode
	* Description: 0: WA is directly captured withj the adc data sampling pulse.(ADC clocks and WA are aligned)
	* 1:WA is double synchronized and captured with the adc data sampling pulse
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WindowActiveSamplingMode : 1;        /*## attribute WindowActiveSamplingMode */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: window_active_sampling_point
	* Description: WA Capturing :The pulse can be moved to the right in steps of 480 MHz clock using this register field.
	* 000: sampling pulse is right shifted by two 480/600 clks (double-sync) from the selected adc_strobe signal
	* 001:sampling pulse is right shifted by three 480/600 clks
	* 010:sampling pulse is right shifted by four 480/600 clks
	* .
	* .
	* 111: sampling pulse is right shifted by nine 480/600 clks
	* 
	* Use model:  The value to be used has to come form Validation . The end user can use  the proposed value from validation
	* Read/Write: RW
	* Bits: [18:16]
	* ResetValue: 0b001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WindowActiveSamplingPoint : 3;        /*## attribute WindowActiveSamplingPoint */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: window_active_sampling_edge_sel
	* Description: Window Active is sampled on serialiser 480MHz clock using a clock aligner logic.Sampling pulse  is generated with an edge detector in adc_strobe signal 
	* 00: adc_valid_both_edge_pulse 
	* 01:adc_valid_posedge_pulse   
	* 10:adc_valid_negedge_pulse   
	* 11:adc_valid_both_edge_pulse 
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t WindowActiveSamplingEdgeSel : 2;        /*## attribute WindowActiveSamplingEdgeSel */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: adc_clock_select
	* Description: ADC clock selection logic. The selected ADC clock is used as adc_strobe to sample the ADC data.
	* 000 : All the ADC clocks are OR ed together (default )
	* 001 : Select adc1 clock
	* 010 : Select adc2 clock
	* 011 : Select adc3 clock
	* 100 : Select adc4 clock
	* 101 : OR adc1 & adc3 clock
	* 110 : OR adc2 & adc4 clock
	* 111 : OR adc1 & adc4 clock.
	* Read/Write: RW
	* Bits: [10:8]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcClockSelect : 3;        /*## attribute AdcClockSelect */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 2;        /*## attribute Reserved4 */
	/**
	* BitsName: adc_clk_edge_sel
	* Description: ADC data is sampled on serialiser 480MHz clock using a clock aligner logic.Sampling pulse  is generated with an edge detector in  adc_strobe path.
	* 00: Detect  both edges 
	* 01: Detect pos edge
	* 10: Detect neg edge
	* 11: Detect  both edges of adc_strobe signal
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcClkEdgeSel : 2;        /*## attribute AdcClkEdgeSel */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: adc_data_sampling_point
	* Description: ADC Data Capturing :After the sampling pulse generation ,the idea is to position the sampling pulse in the middle of the ADC data window.The pulse can be moved to the right in steps of 480 MHz clock using this register field.
	* 000: sampling pulse is right shifted by two 480/600 clks (double-sync) from the selected adc_clk edge 
	* 001:sampling pulse is right shifted by three 480/600 clks
	* 010:sampling pulse is right shifted by four 480/600 clks
	* .
	* .
	* 111: sampling pulse is right shifted by nine 480/600 clks
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcDataSamplingPoint : 3;        /*## attribute AdcDataSamplingPoint */
}R2M02_PdcShiftRegIdivCtrlBits_t;
/**
* R2M02_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This functional safety register is only used for internal validation and debug purpose.Not to be changed in normal functioning  mode
* Address: 0x704
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 15;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_supply_1v8_low_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 0: no mask
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V8LowResetError : 1;        /*## attribute MaskSupply1V8LowResetError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mask_supply_1v1_ser_low_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 0: no mask
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V1SerLowResetError : 1;        /*## attribute MaskSupply1V1SerLowResetError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_freq_count_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the design
	* 0: no mask
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskFreqCountResetError : 1;        /*## attribute MaskFreqCountResetError */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the design
	* 0: no mask
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskRegCrcResetError : 1;        /*## attribute MaskRegCrcResetError */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: mask_supply_1v1_csi2_low_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 0: no mask
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V1Csi2LowResetError : 1;        /*## attribute MaskSupply1V1Csi2LowResetError */
}R2M02_MaskCcResetErrorBits_t;
/**
* R2M02_RefCntrInitBits_t
* RegisterName: REF_CNTR_INIT
* Frequency counter used for counting 480/600 MHz clock
* Address: 0x800
* ResetValue: 0x01E00028
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ideal_480_count_value
	* Description: This is applicable when the freq counter trigger is based on  window_active (for func safety). The correct value to be programmed which is compared against the freq counter read value in the hardware. The value is restricted to 16 bits (as against 18 bit in the freq read counter value) as this triggered one time during active period of the window active and the bit width is sufficient to cover the frequency counting considering the variation of the chirp period
	* Read/Write: RW
	* Bits: [31:16]
	* ResetValue: 0b0000000111100000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Ideal480CountValue : 16;        /*## attribute Ideal480CountValue */
	/**
	* BitsName: ref_count_value
	* Description: value for the reference count time (40 MHz= 25 ns base time) default is d'40. This is used as reference count in both spi triggered mode and window_active triggered mode
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000000101000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RefCountValue : 16;        /*## attribute RefCountValue */
}R2M02_RefCntrInitBits_t;
/**
* R2M02_FreqCounterStartBits_t
* RegisterName: FREQ_COUNTER_START
* Frequency Counter : Used for measuring Serialiser Clock 480/600 frequency.
* Address: 0x804
* ResetValue: 0x00000100
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: freq_counter_trigger_sel
	* Description: 1: the frequency counter is triggered based on window_active posedge to measure the frequency deviation if any and to report to the ISM for every chirp.
	* 0: freq_start register field is required to be written to trigger the frequency counter
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t FreqCounterTriggerSel : 1;        /*## attribute FreqCounterTriggerSel */
	/**
	* BitsName: freq_counter_deviation
	* Description: Number of lsb bits to be ignored while comparing the final freq counter read value. This is required incase of frequency counter trigger is based on window_active  for functional safety. The hardware then compares the value measured by frequency counter against ideal_480_count_value ignoring the lsb bits. 
	* 0001: Zeroth bit is ignored from comparison
	* 0011: Zeroth & first bits are ignored from comparison
	* 0111: Zeroth & first & second bits are ignored from comparison
	* 1111: Zeroth & first & second & third bits are ignored from comparison
	* 
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t FreqCounterDeviation : 4;        /*## attribute FreqCounterDeviation */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: freq_start
	* Description: Start the freq. count
	* 0 = idle, 1 = start
	* 
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t FreqStart : 1;        /*## attribute FreqStart */
}R2M02_FreqCounterStartBits_t;
/**
* R2M02_FreqCounterReadValueBits_t
* RegisterName: FREQ_COUNTER_READ_VALUE
* Frequency Counter : Used for measuring Serialiser Clock 480/600 frequency
* Address: 0x808
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 11;        /*## attribute Reserved0 */
	/**
	* BitsName: done_flag
	* Description: Indicates that a freq count value is valid. Write to freq counter start reg will clear this bit
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t DoneFlag : 1;        /*## attribute DoneFlag */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: freq_count_value
	* Description: Freq value computed. Actual value need to be assessed based on  the ref_cntr_init value
	* e.g ref_cntr_int = d'40 then freq count value = reported value in MHz
	* e.g ref_cntr_int = d'400 (40*10) then freq count value = (reported value/10 ) in MHz
	* 
	* 
	* Read/Write: R
	* Bits: [17:0]
	* ResetValue: 0b000000000000000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t FreqCountValue : 18;        /*## attribute FreqCountValue */
}R2M02_FreqCounterReadValueBits_t;
/**
* R2M02_RefCounterReadValueBits_t
* RegisterName: REF_COUNTER_READ_VALUE
* Frequency counter used for counting 480/600 MHz clock
* Address: 0x80C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: counter_read_value
	* Description: Reference count value
	* Read/Write: R
	* Bits: [15:0]
	* ResetValue: 0b0000000000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CounterReadValue : 16;        /*## attribute CounterReadValue */
}R2M02_RefCounterReadValueBits_t;
/**
* R2M02_CrcErrorStatus1Bits_t
* RegisterName: CRC_ERROR_STATUS1
* Status of the CRC for each register.   Total 71 CRC registers for CSI2.
* Address: 0xF40
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg1
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to first 32 registers listed i.e registers 31(msb) down to 0(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg1 : 32;        /*## attribute CrcErrorStatusReg1 */
}R2M02_CrcErrorStatus1Bits_t;
/**
* R2M02_CrcErrorStatus2Bits_t
* RegisterName: CRC_ERROR_STATUS2
* Status of the CRC for each register.   Total 71 CRC registers for CSI2.
* Address: 0xF44
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg2
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to next 32 registers listed i.e registers 63(msb) down to 32(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 32;        /*## attribute CrcErrorStatusReg2 */
}R2M02_CrcErrorStatus2Bits_t;
/**
* R2M02_CrcErrorStatus3Bits_t
* RegisterName: CRC_ERROR_STATUS3
* Status of the CRC for each register.   Total 71 CRC registers for CSI2.
* Address: 0xF48
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 25;        /*## attribute Reserved0 */
	/**
	* BitsName: crc_error_status_reg3
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to last 7 registers listed i.e registers 71(msb) down to 64(lsb) and rest of the bits are not valid
	* Read/Write: R
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 7;        /*## attribute CrcErrorStatusReg3 */
}R2M02_CrcErrorStatus3Bits_t;
/**
* R2M02_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00025001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000000010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
	/**
	* BitsName: major_revision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRevision : 4;        /*## attribute MajorRevision */
	/**
	* BitsName: minor_revision
	* Description: Minor revision number i.e. with no software consequences
	* Read/Write: R
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MinorRevision : 4;        /*## attribute MinorRevision */
	/**
	* BitsName: aperture
	* Description: Aperture. Fixed value of 'h01 
	* Read/Write: R
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Aperture : 8;        /*## attribute Aperture */
}R2M02_ModuleIdBits_t;
#endif
/**
* R2M02_TrimReg0Union_t
* R2M02_TrimReg0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_TrimReg0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_TrimReg0Union_t;

/**
* R2M02_TrimReg1Union_t
* R2M02_TrimReg1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_TrimReg1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_TrimReg1Union_t;

/**
* R2M02_TrimReg2Union_t
* R2M02_TrimReg2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_TrimReg2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_TrimReg2Union_t;

/**
* R2M02_TrimReg3Union_t
* R2M02_TrimReg3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_TrimReg3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_TrimReg3Union_t;

/**
* R2M02_DphyDfeDlnRegister0Union_t
* R2M02_DphyDfeDlnRegister0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_DphyDfeDlnRegister0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_DphyDfeDlnRegister0Union_t;

/**
* R2M02_DphyDfeDlnRegister1Union_t
* R2M02_DphyDfeDlnRegister1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_DphyDfeDlnRegister1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_DphyDfeDlnRegister1Union_t;

/**
* R2M02_DphyDfeClnRegister0Union_t
* R2M02_DphyDfeClnRegister0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_DphyDfeClnRegister0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_DphyDfeClnRegister0Union_t;

/**
* R2M02_DphyDfeClnRegister1Union_t
* R2M02_DphyDfeClnRegister1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_DphyDfeClnRegister1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_DphyDfeClnRegister1Union_t;

/**
* R2M02_PpiDataLaneSwapRegisterUnion_t
* R2M02_PpiDataLaneSwapRegisterUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_PpiDataLaneSwapRegisterBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_PpiDataLaneSwapRegisterUnion_t;

/**
* R2M02_FifoStatusRegisterUnion_t
* R2M02_FifoStatusRegisterUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_FifoStatusRegisterBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_FifoStatusRegisterUnion_t;

/**
* R2M02_UsdPixelModeControlRegisterUnion_t
* R2M02_UsdPixelModeControlRegisterUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_UsdPixelModeControlRegisterBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_UsdPixelModeControlRegisterUnion_t;

/**
* R2M02_YuvPixelModeControlRegisterUnion_t
* R2M02_YuvPixelModeControlRegisterUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_YuvPixelModeControlRegisterBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_YuvPixelModeControlRegisterUnion_t;

/**
* R2M02_RawPixelModeControlRegisterUnion_t
* R2M02_RawPixelModeControlRegisterUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_RawPixelModeControlRegisterBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_RawPixelModeControlRegisterUnion_t;

/**
* R2M02_PhyTinitCountRegisterUnion_t
* R2M02_PhyTinitCountRegisterUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_PhyTinitCountRegisterBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_PhyTinitCountRegisterUnion_t;

/**
* R2M02_Vc0CompressionPredictionSchemeRegister1Union_t
* R2M02_Vc0CompressionPredictionSchemeRegister1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Vc0CompressionPredictionSchemeRegister1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Vc0CompressionPredictionSchemeRegister1Union_t;

/**
* R2M02_Vc0CompressionPredictionSchemeRegister2Union_t
* R2M02_Vc0CompressionPredictionSchemeRegister2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Vc0CompressionPredictionSchemeRegister2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Vc0CompressionPredictionSchemeRegister2Union_t;

/**
* R2M02_Vc1CompressionPredictionSchemeRegister1Union_t
* R2M02_Vc1CompressionPredictionSchemeRegister1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Vc1CompressionPredictionSchemeRegister1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Vc1CompressionPredictionSchemeRegister1Union_t;

/**
* R2M02_Vc1CompressionPredictionSchemeRegister2Union_t
* R2M02_Vc1CompressionPredictionSchemeRegister2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Vc1CompressionPredictionSchemeRegister2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Vc1CompressionPredictionSchemeRegister2Union_t;

/**
* R2M02_Vc2CompressionPredictionSchemeRegister1Union_t
* R2M02_Vc2CompressionPredictionSchemeRegister1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Vc2CompressionPredictionSchemeRegister1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Vc2CompressionPredictionSchemeRegister1Union_t;

/**
* R2M02_Vc2CompressionPredictionSchemeRegister2Union_t
* R2M02_Vc2CompressionPredictionSchemeRegister2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Vc2CompressionPredictionSchemeRegister2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Vc2CompressionPredictionSchemeRegister2Union_t;

/**
* R2M02_Vc3CompressionPredictionSchemeRegister1Union_t
* R2M02_Vc3CompressionPredictionSchemeRegister1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Vc3CompressionPredictionSchemeRegister1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Vc3CompressionPredictionSchemeRegister1Union_t;

/**
* R2M02_Vc3CompressionPredictionSchemeRegister2Union_t
* R2M02_Vc3CompressionPredictionSchemeRegister2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Vc3CompressionPredictionSchemeRegister2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Vc3CompressionPredictionSchemeRegister2Union_t;

/**
* R2M02_PllCountRegisterUnion_t
* R2M02_PllCountRegisterUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_PllCountRegisterBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_PllCountRegisterUnion_t;

/**
* R2M02_DeviceReadyIndicationRegisterUnion_t
* R2M02_DeviceReadyIndicationRegisterUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_DeviceReadyIndicationRegisterBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_DeviceReadyIndicationRegisterUnion_t;

/**
* R2M02_Csi2AdaptConfigReg1Union_t
* R2M02_Csi2AdaptConfigReg1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Csi2AdaptConfigReg1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Csi2AdaptConfigReg1Union_t;

/**
* R2M02_Csi2AdaptConfigReg2Union_t
* R2M02_Csi2AdaptConfigReg2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Csi2AdaptConfigReg2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Csi2AdaptConfigReg2Union_t;

/**
* R2M02_Csi2AdaptConfigReg3Union_t
* R2M02_Csi2AdaptConfigReg3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Csi2AdaptConfigReg3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Csi2AdaptConfigReg3Union_t;

/**
* R2M02_Csi2CrcCtrl1Union_t
* R2M02_Csi2CrcCtrl1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Csi2CrcCtrl1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Csi2CrcCtrl1Union_t;

/**
* R2M02_Csi2CrcCtrl2Union_t
* R2M02_Csi2CrcCtrl2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Csi2CrcCtrl2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Csi2CrcCtrl2Union_t;

/**
* R2M02_Csi2CrcCtrl3Union_t
* R2M02_Csi2CrcCtrl3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Csi2CrcCtrl3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Csi2CrcCtrl3Union_t;

/**
* R2M02_PdcConfigRegUnion_t
* R2M02_PdcConfigRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_PdcConfigRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_PdcConfigRegUnion_t;

/**
* R2M02_DataValidPadCtrlUnion_t
* R2M02_DataValidPadCtrlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_DataValidPadCtrlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_DataValidPadCtrlUnion_t;

/**
* R2M02_LpMetadataConfig1Union_t
* R2M02_LpMetadataConfig1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_LpMetadataConfig1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_LpMetadataConfig1Union_t;

/**
* R2M02_LpMetadataConfig2Union_t
* R2M02_LpMetadataConfig2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_LpMetadataConfig2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_LpMetadataConfig2Union_t;

/**
* R2M02_LpMetadataUserinfoUnion_t
* R2M02_LpMetadataUserinfoUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_LpMetadataUserinfoBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_LpMetadataUserinfoUnion_t;

/**
* R2M02_VirtualChannelControlUnion_t
* R2M02_VirtualChannelControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_VirtualChannelControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_VirtualChannelControlUnion_t;

/**
* R2M02_SpareReg1Union_t
* R2M02_SpareReg1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_SpareReg1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_SpareReg1Union_t;

/**
* R2M02_Csi2TxnCtrlUnion_t
* R2M02_Csi2TxnCtrlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Csi2TxnCtrlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Csi2TxnCtrlUnion_t;

/**
* R2M02_Csi2TestModeControlRegUnion_t
* R2M02_Csi2TestModeControlRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_Csi2TestModeControlRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_Csi2TestModeControlRegUnion_t;

/**
* R2M02_PrbsControlUnion_t
* R2M02_PrbsControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_PrbsControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_PrbsControlUnion_t;

/**
* R2M02_PdcShiftRegIdivCtrlUnion_t
* R2M02_PdcShiftRegIdivCtrlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_PdcShiftRegIdivCtrlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_PdcShiftRegIdivCtrlUnion_t;

/**
* R2M02_MaskCcResetErrorUnion_t
* R2M02_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_MaskCcResetErrorUnion_t;

/**
* R2M02_RefCntrInitUnion_t
* R2M02_RefCntrInitUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_RefCntrInitBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_RefCntrInitUnion_t;

/**
* R2M02_FreqCounterStartUnion_t
* R2M02_FreqCounterStartUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_FreqCounterStartBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_FreqCounterStartUnion_t;

/**
* R2M02_FreqCounterReadValueUnion_t
* R2M02_FreqCounterReadValueUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_FreqCounterReadValueBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_FreqCounterReadValueUnion_t;

/**
* R2M02_RefCounterReadValueUnion_t
* R2M02_RefCounterReadValueUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_RefCounterReadValueBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_RefCounterReadValueUnion_t;

/**
* R2M02_CrcErrorStatus1Union_t
* R2M02_CrcErrorStatus1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_CrcErrorStatus1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_CrcErrorStatus1Union_t;

/**
* R2M02_CrcErrorStatus2Union_t
* R2M02_CrcErrorStatus2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_CrcErrorStatus2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_CrcErrorStatus2Union_t;

/**
* R2M02_CrcErrorStatus3Union_t
* R2M02_CrcErrorStatus3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_CrcErrorStatus3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_CrcErrorStatus3Union_t;

/**
* R2M02_ModuleIdUnion_t
* R2M02_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M02_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M02_ModuleIdUnion_t;


#endif
