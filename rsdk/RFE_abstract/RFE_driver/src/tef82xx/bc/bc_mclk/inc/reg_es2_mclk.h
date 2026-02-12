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
* @reg_es2_mclk.h
*/
#ifndef REG_ES2_MCLK_H
#define REG_ES2_MCLK_H
#include <stdint.h>
/**
* R2M0C_IREF_LDO_CONTROL_U16
* RegisterName: MOD0C_IREF_LDO_CONTROL
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x00000D0F
*/
#define R2M0C_IREF_LDO_CONTROL_U16 (uint16_t)0x0000
/**
* R2M0C_XO_PLL_LDO_CONTROL_U16
* RegisterName: MOD0C_XO_PLL_LDO_CONTROL
* AccessMode: RW
* AddressRange: 0x0004 - 0x0008
* ResetValue: 0x0F0F0F0F
*/
#define R2M0C_XO_PLL_LDO_CONTROL_U16 (uint16_t)0x0004
/**
* R2M0C_MC_LDO_CONTROL_U16
* RegisterName: MOD0C_MC_LDO_CONTROL
* AccessMode: RW
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x0000000F
*/
#define R2M0C_MC_LDO_CONTROL_U16 (uint16_t)0x0008
/**
* R2M0C_TRIM_SETTINGS_U16
* RegisterName: MOD0C_TRIM_SETTINGS
* AccessMode: RW
* AddressRange: 0x000C - 0x0010
* ResetValue: 0x00001010
*/
#define R2M0C_TRIM_SETTINGS_U16 (uint16_t)0x000C
/**
* R2M0C_XO_PLL_MC_LDO_ENABLE_U16
* RegisterName: MOD0C_XO_PLL_MC_LDO_ENABLE
* AccessMode: RW
* AddressRange: 0x0010 - 0x0014
* ResetValue: 0x00001111
*/
#define R2M0C_XO_PLL_MC_LDO_ENABLE_U16 (uint16_t)0x0010
/**
* R2M0C_IBIAS_CONTROL_U16
* RegisterName: MOD0C_IBIAS_CONTROL
* AccessMode: RW
* AddressRange: 0x0020 - 0x0024
* ResetValue: 0x11186444
*/
#define R2M0C_IBIAS_CONTROL_U16 (uint16_t)0x0020
/**
* R2M0C_PFD_CONTROL_U16
* RegisterName: MOD0C_PFD_CONTROL
* AccessMode: RW
* AddressRange: 0x0024 - 0x0028
* ResetValue: 0x00000000
*/
#define R2M0C_PFD_CONTROL_U16 (uint16_t)0x0024
/**
* R2M0C_CP_CONTROL_U16
* RegisterName: MOD0C_CP_CONTROL
* AccessMode: RW
* AddressRange: 0x0028 - 0x002C
* ResetValue: 0x000001FF
*/
#define R2M0C_CP_CONTROL_U16 (uint16_t)0x0028
/**
* R2M0C_CLOCK_DELAY_SKEW_CONTROL_U16
* RegisterName: MOD0C_CLOCK_DELAY_SKEW_CONTROL
* AccessMode: RW
* AddressRange: 0x002C - 0x0030
* ResetValue: 0x00000000
*/
#define R2M0C_CLOCK_DELAY_SKEW_CONTROL_U16 (uint16_t)0x002C
/**
* R2M0C_LOOP_FILTER_CONTROL_U16
* RegisterName: MOD0C_LOOP_FILTER_CONTROL
* AccessMode: RW
* AddressRange: 0x0030 - 0x0034
* ResetValue: 0x00000021
*/
#define R2M0C_LOOP_FILTER_CONTROL_U16 (uint16_t)0x0030
/**
* R2M0C_LOCK_CONTROL_U16
* RegisterName: MOD0C_LOCK_CONTROL
* AccessMode: RW
* AddressRange: 0x0034 - 0x0038
* ResetValue: 0x000001C4
*/
#define R2M0C_LOCK_CONTROL_U16 (uint16_t)0x0034
/**
* R2M0C_XO_BUFFER_CONTROL_U16
* RegisterName: MOD0C_XO_BUFFER_CONTROL
* AccessMode: RW
* AddressRange: 0x0040 - 0x0044
* ResetValue: 0x00000000
*/
#define R2M0C_XO_BUFFER_CONTROL_U16 (uint16_t)0x0040
/**
* R2M0C_CLOCK_BUFFER_CONTROL_U16
* RegisterName: MOD0C_CLOCK_BUFFER_CONTROL
* AccessMode: RW
* AddressRange: 0x0060 - 0x0064
* ResetValue: 0x00000000
*/
#define R2M0C_CLOCK_BUFFER_CONTROL_U16 (uint16_t)0x0060
/**
* R2M0C_CLOCK_GATE_CONTROL_U16
* RegisterName: MOD0C_CLOCK_GATE_CONTROL
* AccessMode: RW
* AddressRange: 0x0064 - 0x0068
* ResetValue: 0x00000000
*/
#define R2M0C_CLOCK_GATE_CONTROL_U16 (uint16_t)0x0064
/**
* R2M0C_CLKSEL_U16
* RegisterName: MOD0C_CLKSEL
* AccessMode: RW
* AddressRange: 0x0074 - 0x0078
* ResetValue: 0x00000010
*/
#define R2M0C_CLKSEL_U16 (uint16_t)0x0074
/**
* R2M0C_CALIBRATION_AFC_CONTROL5_U16
* RegisterName: MOD0C_CALIBRATION_AFC_CONTROL5
* AccessMode: RW
* AddressRange: 0x00B0 - 0x00B4
* ResetValue: 0x00000010
*/
#define R2M0C_CALIBRATION_AFC_CONTROL5_U16 (uint16_t)0x00B0
/**
* R2M0C_CLK_DET_EN_CONFIG_U16
* RegisterName: MOD0C_CLK_DET_EN_CONFIG
* AccessMode: RW
* AddressRange: 0x00C0 - 0x00C4
* ResetValue: 0x00000000
*/
#define R2M0C_CLK_DET_EN_CONFIG_U16 (uint16_t)0x00C0
/**
* R2M0C_MSPC_CONTROL1_U16
* RegisterName: MOD0C_MSPC_CONTROL1
* AccessMode: RW
* AddressRange: 0x0110 - 0x0114
* ResetValue: 0x00000003
*/
#define R2M0C_MSPC_CONTROL1_U16 (uint16_t)0x0110
/**
* R2M0C_MSPC_CONTROL2_U16
* RegisterName: MOD0C_MSPC_CONTROL2
* AccessMode: RW
* AddressRange: 0x0114 - 0x0118
* ResetValue: 0x00000034
*/
#define R2M0C_MSPC_CONTROL2_U16 (uint16_t)0x0114
/**
* R2M0C_MSPC_CONTROL3_U16
* RegisterName: MOD0C_MSPC_CONTROL3
* AccessMode: RW
* AddressRange: 0x0118 - 0x011C
* ResetValue: 0x00000000
*/
#define R2M0C_MSPC_CONTROL3_U16 (uint16_t)0x0118
/**
* R2M0C_MSPC_TRIM_SETTINGS_U16
* RegisterName: MOD0C_MSPC_TRIM_SETTINGS
* AccessMode: RW
* AddressRange: 0x011C - 0x0120
* ResetValue: 0x00000007
*/
#define R2M0C_MSPC_TRIM_SETTINGS_U16 (uint16_t)0x011C
/**
* R2M0C_VCO_CONTROL_U16
* RegisterName: MOD0C_VCO_CONTROL
* AccessMode: RW
* AddressRange: 0x0120 - 0x0124
* ResetValue: 0x00000001
*/
#define R2M0C_VCO_CONTROL_U16 (uint16_t)0x0120
/**
* R2M0C_START_CALIBRATION_U16
* RegisterName: MOD0C_START_CALIBRATION
* AccessMode: W
* AddressRange: 0x0124 - 0x0128
* ResetValue: 0x00000000
*/
#define R2M0C_START_CALIBRATION_U16 (uint16_t)0x0124
/**
* R2M0C_RESET_CALIBRATION_U16
* RegisterName: MOD0C_RESET_CALIBRATION
* AccessMode: RW
* AddressRange: 0x0128 - 0x012C
* ResetValue: 0x00000000
*/
#define R2M0C_RESET_CALIBRATION_U16 (uint16_t)0x0128
/**
* R2M0C_SNS_CONTROL_U16
* RegisterName: MOD0C_SNS_CONTROL
* AccessMode: RW
* AddressRange: 0x0130 - 0x0134
* ResetValue: 0x00000000
*/
#define R2M0C_SNS_CONTROL_U16 (uint16_t)0x0130
/**
* R2M0C_CALIBRATION_STATUS1_U16
* RegisterName: MOD0C_CALIBRATION_STATUS1
* AccessMode: R
* AddressRange: 0x0140 - 0x0144
* ResetValue: 0x3E110100
*/
#define R2M0C_CALIBRATION_STATUS1_U16 (uint16_t)0x0140
/**
* R2M0C_CALIBRATION_STATUS2_U16
* RegisterName: MOD0C_CALIBRATION_STATUS2
* AccessMode: R
* AddressRange: 0x0144 - 0x0148
* ResetValue: 0x000000FF
*/
#define R2M0C_CALIBRATION_STATUS2_U16 (uint16_t)0x0144
/**
* R2M0C_CALIBRATION_STATUS3_U16
* RegisterName: MOD0C_CALIBRATION_STATUS3
* AccessMode: R
* AddressRange: 0x0148 - 0x014C
* ResetValue: 0x00001000
*/
#define R2M0C_CALIBRATION_STATUS3_U16 (uint16_t)0x0148
/**
* R2M0C_XO_STATUS_U16
* RegisterName: MOD0C_XO_STATUS
* AccessMode: R
* AddressRange: 0x0150 - 0x0154
* ResetValue: 0x00000000
*/
#define R2M0C_XO_STATUS_U16 (uint16_t)0x0150
/**
* R2M0C_MSPC_CALIB_CHECK_STATUS_U16
* RegisterName: MOD0C_MSPC_CALIB_CHECK_STATUS
* AccessMode: R
* AddressRange: 0x0160 - 0x0164
* ResetValue: 0x00000000
*/
#define R2M0C_MSPC_CALIB_CHECK_STATUS_U16 (uint16_t)0x0160
/**
* R2M0C_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD0C_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0304 - 0x0308
* ResetValue: 0x00000000
*/
#define R2M0C_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0304
/**
* R2M0C_CRC_ERROR_STATUS1_U16
* RegisterName: MOD0C_CRC_ERROR_STATUS1
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M0C_CRC_ERROR_STATUS1_U16 (uint16_t)0x0F40
/**
* R2M0C_CRC_ERROR_STATUS2_U16
* RegisterName: MOD0C_CRC_ERROR_STATUS2
* AccessMode: R
* AddressRange: 0x0F44 - 0x0F48
* ResetValue: 0x00000000
*/
#define R2M0C_CRC_ERROR_STATUS2_U16 (uint16_t)0x0F44
/**
* R2M0C_CRC_ERROR_STATUS3_U16
* RegisterName: MOD0C_CRC_ERROR_STATUS3
* AccessMode: R
* AddressRange: 0x0F48 - 0x0F4C
* ResetValue: 0x00000000
*/
#define R2M0C_CRC_ERROR_STATUS3_U16 (uint16_t)0x0F48
/**
* R2M0C_MODULE_ID_U16
* RegisterName: MOD0C_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x000C4001
*/
#define R2M0C_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M0C_IrefLdoControlBits_t
* RegisterName: IREF_LDO_CONTROL
* Bias control settings
* 
* Address: 0x000
* ResetValue: 0x00000D0F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: xo_ldo_iref
	* Description: internal ldo reference current selection inputs(1.8v)
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t XoLdoIref : 5;        /*## attribute XoLdoIref */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: sel_iref_bias
	* Description: PLL4G8 internal current source trim value
	* Read/Write: RW
	* Bits: [12:8]
	* ResetValue: 0b01101
	* Source: OTP
	* FuSa: No
	*/
	uint32_t SelIrefBias : 5;        /*## attribute SelIrefBias */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 19;        /*## attribute Reserved1 */
}R2M0C_IrefLdoControlBits_t;
/**
* R2M0C_XoPllLdoControlBits_t
* RegisterName: XO_PLL_LDO_CONTROL
* Ldo control settings for the PLL.
* All LDO's to eb enabed for the PLL to work.
* 
* Address: 0x004
* ResetValue: 0x0F0F0F0F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vout_ldo1
	* Description: set output voltage of PLL4G8 LDO1. Value comes from OTP
	* 
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t VoutLdo1 : 5;        /*## attribute VoutLdo1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: vout_ldo2
	* Description: set output voltage of PLL4G8 LDO2. Value comes from OTP
	* 
	* Read/Write: RW
	* Bits: [12:8]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t VoutLdo2 : 5;        /*## attribute VoutLdo2 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: vout_ldo3
	* Description: set output voltage of PLL4G8 LDO3. Value comes from OTP
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [20:16]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t VoutLdo3 : 5;        /*## attribute VoutLdo3 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: xo_ldo_vout
	* Description: Set output voltage of XO LDO. Value comes from OTP
	* .
	* Read/Write: RW
	* Bits: [28:24]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t XoLdoVout : 5;        /*## attribute XoLdoVout */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
}R2M0C_XoPllLdoControlBits_t;
/**
* R2M0C_McLdoControlBits_t
* RegisterName: MC_LDO_CONTROL
* Master clock local Ldo control settings
* Address: 0x008
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ldo_sel_vout
	* Description: Set output voltage of Master clock LDO. Value comes from OTP
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVout : 5;        /*## attribute LdoSelVout */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
}R2M0C_McLdoControlBits_t;
/**
* R2M0C_TrimSettingsBits_t
* RegisterName: TRIM_SETTINGS
* PLL4G8 trim values
* 
* Address: 0x00C
* ResetValue: 0x00001010
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vco_rset
	* Description: vco current control resistor value (internally this delayed by pon_counter cycles)
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t VcoRset : 5;        /*## attribute VcoRset */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: lpf_r2
	* Description: LPF set R2 value
	* Read/Write: RW
	* Bits: [12:8]
	* ResetValue: 0b10000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LpfR2 : 5;        /*## attribute LpfR2 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 19;        /*## attribute Reserved1 */
}R2M0C_TrimSettingsBits_t;
/**
* R2M0C_XoPllMcLdoEnableBits_t
* RegisterName: XO_PLL_MC_LDO_ENABLE
* Ldo control settings for the PLL.
* All LDO's to be enabed for the PLL to work.
* 
* Address: 0x010
* ResetValue: 0x00001111
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mc_ldo_en
	* Description: Master clock LDO enable (buffers, XO functional safety)
	* 1: Enable LDO
	* 0: Disable LDO
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t McLdoEn : 1;        /*## attribute McLdoEn */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_ena_ldo1
	* Description: enable PLL4G8 LDO1 (Divider)
	* 1: Enable LDO1
	* 0: Disable LDO1
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllEnaLdo1 : 1;        /*## attribute PllEnaLdo1 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: pll_ena_ldo2
	* Description: enable PLL4G8 LDO2 (Charge pump, PFD, Low-pass filterm PLL glue logic)
	* 1: Enable LDO2
	* 0: Disable LDO2
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllEnaLdo2 : 1;        /*## attribute PllEnaLdo2 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: pll_ena_ldo3
	* Description: enable PLL4G8 LDO3 (VCO, peak detector for calibration, first stage divider, 2G4 I/O)
	* 1: Enable LDO3
	* 0: Disable LDO3
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllEnaLdo3 : 1;        /*## attribute PllEnaLdo3 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M0C_XoPllMcLdoEnableBits_t;
/**
* R2M0C_IbiasControlBits_t
* RegisterName: IBIAS_CONTROL
* PLL4G8 bias control
* 
* Address: 0x020
* ResetValue: 0x11186444
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vcom_2g4_predriv
	* Description: PLL4G8 common mode voltage 2.4GHz pre driver trim value
	* 
	* 
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b100
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcom2G4Predriv : 3;        /*## attribute CtlVcom2G4Predriv */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_2g4_predriv_200u
	* Description: PLL4G8 ibias 2.4GHz pre driver trim value
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b100
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbias2G4Predriv200U : 3;        /*## attribute CtlIbias2G4Predriv200U */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_ibias_2g4buf_350u
	* Description: PLL4G8 ibias 2.4GHz output buffer trim value
	* Read/Write: RW
	* Bits: [10:8]
	* ResetValue: 0b100
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbias2G4Buf350U : 3;        /*## attribute CtlIbias2G4Buf350U */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_bias_opamp_100u
	* Description: PLL4G8 ibias opamp (inside charge pump) trim value
	* Read/Write: RW
	* Bits: [14:12]
	* ResetValue: 0b110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBiasOpamp100U : 3;        /*## attribute CtlBiasOpamp100U */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_bias_cp_100u
	* Description: PLL4G8 ibias charge pump trim value
	* Read/Write: RW
	* Bits: [20:16]
	* ResetValue: 0b11000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBiasCp100U : 5;        /*## attribute CtlBiasCp100U */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: sel_globalref
	* Description: 
	* Selects the reference current source of the bias currents used in the PLL4G8 (100uA).
	* 0: selects the reference current source in the PLL4G8  
	* 1: selects the reference current source in the Global Bias 
	* 
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t SelGlobalref : 1;        /*## attribute SelGlobalref */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: en_iref_bias
	* Description: PLL4G8 internal current source enable
	* 1: Enable
	* 0: Disable
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnIrefBias : 1;        /*## attribute EnIrefBias */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
}R2M0C_IbiasControlBits_t;
/**
* R2M0C_PfdControlBits_t
* RegisterName: PFD_CONTROL
* Phase Frequency Detector control settings for 4.8GHz PLL
* .
* Address: 0x024
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pfd_force_down
	* Description: force pfd down
	* 1: Decrease current
	* 0: no effect
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PfdForceDown : 1;        /*## attribute PfdForceDown */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: pfd_force_up
	* Description: force pfd up
	* 1: Increase current
	* 0: no effect
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PfdForceUp : 1;        /*## attribute PfdForceUp */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: pfd_del
	* Description: pfd reset delay control
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PfdDel : 2;        /*## attribute PfdDel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: pfd_rst
	* Description: overrule reset pfd
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PfdRst : 1;        /*## attribute PfdRst */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M0C_PfdControlBits_t;
/**
* R2M0C_CpControlBits_t
* RegisterName: CP_CONTROL
* Charge pump control settings
* .
* Address: 0x028
* ResetValue: 0x000001FF
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: cp_slice_ena
	* Description: set charge pump current per slice
	* Each bit controls one slice
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b11111111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CpSliceEna : 8;        /*## attribute CpSliceEna */
	/**
	* BitsName: cp_ena
	* Description: enable charge pump
	* 1: Enable
	* 0: Disable
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CpEna : 1;        /*## attribute CpEna */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
}R2M0C_CpControlBits_t;
/**
* R2M0C_ClockDelaySkewControlBits_t
* RegisterName: CLOCK_DELAY_SKEW_CONTROL
* In applications where two  ICs have to work together, the phases of the 600MHz
* clocks in both ICs have to be aligned within a tight tolerance. In this case one of the ICs
* works as leader, the other one as follower. Only the leader will use the xtal oscillator, while
* the follower receives its 40MHz reference clock from the leader.
* Obviously the follower reference clock will always be delayed by a few nanoseconds with
* respect to the leader reference clock. To compensate for this delay, the PLL has two
* provisions: ADC reference clock re-clocking and fine pitch output clock skew
* 
* 
* ADC reference clock re-clocking
* 
* PLL reference clock delay between leader and follower IC can be more
* than one period of the 600MHz clock. Obviously we cannot advance the 600MHz clock for
* more than a single period w.r.t. the 40MHz input clock. However the
* 40MHz clock that goes to the ADC can be manipulated, as a reference for the sampling time point. By shifting
* this ADC reference clock over a number of periods of the 600MHz clock, it is possible to
* compensate for any amount of delay (as long as it is less than the 40MHz clock period).
* 
* Fine pitch output clock skew :
* 
* The PLL feedback divide chain implements two cascaded dividers; a divide-by-8 and a
* divide-by-15 circuit. The output signal of this divide-by-8 circuit is 600MHz.
* This divider is synchronized to a second divide-by-8 circuit, which delivers the 600MHz
* output clock, for clocking the the Chip ADC. However the exact phase relation between
* these two divide-by-8 circuits is made adjustable. The 600MHz output of the first divider
* can be delayed from 0 to15/16.T600M, in steps of 1/16.T600M (approx. 104ps nom.).
* Since the first divide-by-8 is part of the feedback divider chain, the phase relation between
* its 600MHz output clock and the 40MHz feedback clock is automatically fixed; their rising
* edges will always coincide. When, as described, the 600MHz clock in the feedback path is
* delayed for a part of its period, the 600MHz output clock for the ADC becomes advanced
* with respect to the 40MHz input clock of the PLL
* Address: 0x02C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: output_clk_skew
	* Description: fine pitch 600MHz output clock skew 0 to -15/16.T
	* 
	* 
	* In the manual mode, the value written into this field will be driven towards the pll and the same can be read back. 
	* 
	* Incase of autonomous mode mspc calibration, the written value is ignored but the read value after the calibration reflects the calibration converged value
	* 
	* The fine adjustment is interms of 104 ps
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t OutputClkSkew : 4;        /*## attribute OutputClkSkew */
	/**
	* BitsName: set_delay_clk40
	* Description: Select reference clock delay factor N
	* Delay = N. (1/600MHz). N=1 to 5
	* 
	* In the manual mode, the value written into this field will be driven towards the pll and the same can be read back. 
	* 
	* Incase of autonomous mode mspc calibration, the written value is ignored but the read value after the calibration reflects the calibration converged value
	* 
	* The delay is adjusted interms of 1.6 ns
	* 
	* 
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t SetDelayClk40 : 4;        /*## attribute SetDelayClk40 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
}R2M0C_ClockDelaySkewControlBits_t;
/**
* R2M0C_LoopFilterControlBits_t
* RegisterName: LOOP_FILTER_CONTROL
* PLL4G8 loop-filter control settings
* Address: 0x030
* ResetValue: 0x00000021
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: lpf_c1
	* Description: LPF set C1 value
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0001
	* Source: Application
	* FuSa: No
	*/
	uint32_t LpfC1 : 4;        /*## attribute LpfC1 */
	/**
	* BitsName: lpf_c2
	* Description: LPF set C2 value
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0010
	* Source: Application
	* FuSa: No
	*/
	uint32_t LpfC2 : 4;        /*## attribute LpfC2 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
}R2M0C_LoopFilterControlBits_t;
/**
* R2M0C_LockControlBits_t
* RegisterName: LOCK_CONTROL
* PLL un Lock detector control settings. This is a functional safety control register
* Address: 0x034
* ResetValue: 0x000001C4
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: lock_det_mode_ctrl
	* Description: lock detector mode control (7:6=anl, 4:0=dig)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b11000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LockDetModeCtrl : 8;        /*## attribute LockDetModeCtrl */
	/**
	* BitsName: lock_det_enable
	* Description: lock detector enable
	* 1: Enable
	* 0: Disable
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LockDetEnable : 1;        /*## attribute LockDetEnable */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
	/**
	* BitsName: lock_det_force_rst
	* Description: lock detector force reset condition
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LockDetForceRst : 1;        /*## attribute LockDetForceRst */
}R2M0C_LockControlBits_t;
/**
* R2M0C_XoBufferControlBits_t
* RegisterName: XO_BUFFER_CONTROL
* Xtal oscillator buffer control register
* Address: 0x040
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: xo_clkin_pd
	* Description: clock input (to control the clk_in ball) buffer power down signal
	* 
	* 1: Powerdown enabled
	* 0 : No powerdown
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoClkinPd : 1;        /*## attribute XoClkinPd */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: xo_clkoutp_pd
	* Description: clock output P (also called xo_clkout_0_pd to control the clk_out_0 ball) buffer power down signal
	* 
	* 1: Powerdown enabled
	* 0 : No powerdown
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoClkoutpPd : 1;        /*## attribute XoClkoutpPd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: xo_clkoutn_pd
	* Description: clock output N (also called xo_clkout_180_pd to control the clk_out_180 ball) buffer power down signal
	* 
	* 1: Powerdown enabled
	* 0 : No powerdown
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoClkoutnPd : 1;        /*## attribute XoClkoutnPd */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: xo_clkoutdrvlvl_red
	* Description: reduces drive level of XO output buffers
	* 
	* 1: Drive level reduced
	* 0 : Normal drive level
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoClkoutdrvlvlRed : 1;        /*## attribute XoClkoutdrvlvlRed */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M0C_XoBufferControlBits_t;
/**
* R2M0C_ClockBufferControlBits_t
* RegisterName: CLOCK_BUFFER_CONTROL
* Clock output buffer control
* Address: 0x060
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: en_clk_chirp_480
	* Description: Enable 480MHz chirp clock buffer 
	* 0 = disable 
	* 1 = enable
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkChirp480 : 1;        /*## attribute EnClkChirp480 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: en_clk_ser_480_600
	* Description: Enable 480_600MHz SER clock buffer 
	* 0 = disable 
	* 1 = enable
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkSer480600 : 1;        /*## attribute EnClkSer480600 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: en_clk_adc_1200
	* Description: Enable 1200MHz ADC clock buffer 
	* 0 = disable 
	* 1 = enable
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkAdc1200 : 1;        /*## attribute EnClkAdc1200 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: en_clk_ssbmod_600
	* Description: Enable 600MHz SSBmod clock buffer 0 = disable
	* 1 = enable
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkSsbmod600 : 1;        /*## attribute EnClkSsbmod600 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: en_clk_adc_40
	* Description: Enable 40MHz ADC clock buffer
	* 0 = disable
	* 1 = enable
	* 
	* 
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkAdc40 : 1;        /*## attribute EnClkAdc40 */
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
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 1;        /*## attribute Reserved7 */
	/**
	* BitsName: Reserved_8 
	* Description: not used 
	*/
	uint32_t Reserved8 : 7;        /*## attribute Reserved8 */
}R2M0C_ClockBufferControlBits_t;
/**
* R2M0C_ClockGateControlBits_t
* RegisterName: CLOCK_GATE_CONTROL
* Clock gate control
* Address: 0x064
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: clkgate_chirp_480
	* Description: Enable clockgate for 480MHz chirp clock buffer 
	*  0 = disable power save and  enable clock propagation  
	*  1 = enable power save and disable clock propagation
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkgateChirp480 : 1;        /*## attribute ClkgateChirp480 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: clkgate_ser_480_600
	* Description: Enable clockgate for 480_600MHz SER clock buffer 
	*  0 = disable power save and  enable clock propagation  
	*  1 = enable power save and disable clock propagation
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkgateSer480600 : 1;        /*## attribute ClkgateSer480600 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: clkgate_adc_1200
	* Description: Enable clockgate for 1200MHz ADC clock buffer 
	*  0 = disable power save and  enable clock propagation  
	*  1 = enable power save and disable clock propagation
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkgateAdc1200 : 1;        /*## attribute ClkgateAdc1200 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: clkgate_ssbmod_600
	* Description: Enable clockgate for 600MHz SSBmod clock buffer 
	*  0 = disable power save and  enable clock propagation  
	*  1 = enable power save and disable clock propagation
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkgateSsbmod600 : 1;        /*## attribute ClkgateSsbmod600 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M0C_ClockGateControlBits_t;
/**
* R2M0C_ClkselBits_t
* RegisterName: CLKSEL
* CC and ADC synchronization clock control
* Address: 0x074
* ResetValue: 0x00000010
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: clksel_cc_40_calclk
	* Description: 0: XO clock for CC (use only during startup) 
	* 1: calibrated clock for CC (use after starting 4.8GHz PLL)
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkselCc40Calclk : 1;        /*## attribute ClkselCc40Calclk */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: clksel_adc_40_negedge
	* Description: select negedge of 1200MHz clock for ADC
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkselAdc40Negedge : 1;        /*## attribute ClkselAdc40Negedge */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M0C_ClkselBits_t;
/**
* R2M0C_CalibrationAfcControl5Bits_t
* RegisterName: CALIBRATION_AFC_CONTROL5
* Automatic frequency calibration settings5
* 
* Address: 0x0B0
* ResetValue: 0x00000010
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: afc_manual
	* Description: frequency control loop manual mode
	* 1: Manual mode Enabled
	* 0: Disabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcManual : 1;        /*## attribute AfcManual */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_use_recal_settings
	* Description: Use recalibration settings
	* 
	* 1: Recalibration settings applied
	* 0: Recalibration settings not applied
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllUseRecalSettings : 1;        /*## attribute PllUseRecalSettings */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M0C_CalibrationAfcControl5Bits_t;
/**
* R2M0C_ClkDetEnConfigBits_t
* RegisterName: CLK_DET_EN_CONFIG
* Clk (XO CLK, CLKIN, PLLCLK) detector configuration (which detector to be enabled/disabled) and XO clock enable to enable the clean clock towards Chirp and Serializer frequency counter
* 
* Address: 0x0C0
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: clk_det_mode
	* Description: Clock Detector Mode Settings is about applying the masks to the clock detector in the different modes : {pllclk_mask, clkin_mask, xoclk_mask}
	* 000: Startup mode    ({pllclk_mask, clkin_mask, xoclk_mask}=3'b100)
	* 001: Standalone mode ({pllclk_mask, clkin_mask, xoclk_mask}=3'b010)
	* 010: Leader mode ({pllclk_mask, clkin_mask, xoclk_mask}=3'b000)
	* 011: Follower mode   ({pllclk_mask, clkin_mask, xoclk_mask}=3'b001)
	* >=100: Direct mask value defined in the field clk_det_mode_debug
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkDetMode : 3;        /*## attribute ClkDetMode */
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
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
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
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: always_enable_chirp_ser_xo_clk
	* Description: Always enable the xo clock towards chirp, serializer freq counter
	* 
	* 1: Always enable xo clock
	* 0: enable xo clock based on the chirp and serializer enable signals
	* 
	* Note: If set 0, the mask bits in this register still can be configured to disable the xo clock
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AlwaysEnableChirpSerXoClk : 1;        /*## attribute AlwaysEnableChirpSerXoClk */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 15;        /*## attribute Reserved7 */
}R2M0C_ClkDetEnConfigBits_t;
/**
* R2M0C_MspcControl1Bits_t
* RegisterName: MSPC_CONTROL1
* MSPC Control settings
* Address: 0x110
* ResetValue: 0x00000003
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mspc_clkmux_ctrl
	* Description: DFT: selects reference clock from clk_in or divided PLL clock for both inputs
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b11
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcClkmuxCtrl : 2;        /*## attribute MspcClkmuxCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: mspc_pfd_1v1_ena
	* Description: enables 1v1 related blocks in PFD
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPfd1V1Ena : 1;        /*## attribute MspcPfd1V1Ena */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mspc_pfd_1v8_ena
	* Description: enables 1v8 related blocks in PFD
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPfd1V8Ena : 1;        /*## attribute MspcPfd1V8Ena */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
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
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: mspc_pfd_clkin_early_invert
	* Description: Invert the clkin_early generated from analog PFD (Phase Frequency Detector)
	* 
	* 0: No inversion on the clkin_early from analog PFD
	* 1: Invert clkin_early from analog PFD
	* Note: In general, this bit needs to be set 1'b1 when mspc_clkmux_ctrl = 2'b00
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPfdClkinEarlyInvert : 1;        /*## attribute MspcPfdClkinEarlyInvert */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 11;        /*## attribute Reserved7 */
}R2M0C_MspcControl1Bits_t;
/**
* R2M0C_MspcControl2Bits_t
* RegisterName: MSPC_CONTROL2
* MSPC Control settings
* Address: 0x114
* ResetValue: 0x00000034
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mspc_pll_skew_wait_time
	* Description: The wait time to be applied after the pll skew is programmed
	* 
	* 3'b000 : 2.5 us
	* 3'b001 : 5 us
	* 3'b010 : 10 us
	* 3'b011 : 20 us
	* 3'b100 : 40 us
	* 3'b101 : 80 us
	* 3'b110 : 160 us
	* 3'b111 : 320 us
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPllSkewWaitTime : 3;        /*## attribute MspcPllSkewWaitTime */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: mspc_measure_wait_time
	* Description: The wait time for the mspc measurement
	* 
	* 3'b000 : 1 us
	* 3'b001 : 2 us
	* 3'b010 : 4 us
	* 3'b011 : 8 us
	* 3'b100 : 16 us
	* 3'b101 : 32 us
	* 3'b110 : 64 us
	* 3'b111 : 128 us
	* 
	* 
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcMeasureWaitTime : 3;        /*## attribute MspcMeasureWaitTime */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: mspc_set_delay_wait_time
	* Description: The wait time to be applied after the set_delay is programmed
	* 
	* 2'b00 : 4 * 25 ns
	* 2'b01 : 8 * 25 ns
	* 2'b10 : 16 * 25 ns
	* 2'b11 : 32 * 25 ns
	* 
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcSetDelayWaitTime : 2;        /*## attribute MspcSetDelayWaitTime */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 22;        /*## attribute Reserved2 */
}R2M0C_MspcControl2Bits_t;
/**
* R2M0C_MspcControl3Bits_t
* RegisterName: MSPC_CONTROL3
* MSPC Control settings
* Address: 0x118
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mspc_pfd_start_meas
	* Description: starts measurement of phase calibration
	* 
	* 
	* 1'b0 : No operation
	* 1'b1 : MSPC start is triggered
	* 
	* Note: As the same bit is used for Auto and Manual mode calibration trigger, 0 to 1 on this bit is detected as start calibration. This bit and mspc_calibration_check bit in the same register should not be set at the same time. If both set 1, no operation will be performed 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPfdStartMeas : 1;        /*## attribute MspcPfdStartMeas */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
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
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: mspc_calib_mode
	* Description: MSPC calibration mode
	* 
	* 1'b0 : HW (Autonomous) based MSPC calibration
	* 1'b1 : SW based MSPC calibration
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcCalibMode : 1;        /*## attribute MspcCalibMode */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: mspc_calib_check
	* Description: Control to activate Calibration check, This control should not to be used directly. Instead software API to be used for calibration check
	* 
	* 1'b0 : No operation
	* 1'b1 : MSPC check is triggered
	* 
	* Note1: As the same bit is used for Auto and Manual mode calibration trigger, 0 to 1 on this bit is detected as start calibration check. This bit and mspc_pfd_start_meas bit in the same register should not be set at the same time. If both set 1, no operation will be performed
	* Note2: In general, calib_check to be triggered atleast once the first mspc calibration done
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcCalibCheck : 1;        /*## attribute MspcCalibCheck */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: mspc_calib_check_correction_enable
	* Description: Control to enable the new settings after calib check, This control should not to be used directly. Instead software API to be used for correction
	* 
	* 1'b0 : Old pll set_delay and skew are maintained after the mspc_calib_check completion
	* 1'b1 : New pll set_delay and skew are applied after the mspc_calib_check completion if the difference (in skew, set_delay) is found
	* 
	* 
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcCalibCheckCorrectionEnable : 1;        /*## attribute MspcCalibCheckCorrectionEnable */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 11;        /*## attribute Reserved7 */
}R2M0C_MspcControl3Bits_t;
/**
* R2M0C_MspcTrimSettingsBits_t
* RegisterName: MSPC_TRIM_SETTINGS
* MSPC Trim settings
* Address: 0x11C
* ResetValue: 0x00000007
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mspc_trim_ctrl
	* Description: trim charge pump currents in PFD
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b00111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t MspcTrimCtrl : 5;        /*## attribute MspcTrimCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
}R2M0C_MspcTrimSettingsBits_t;
/**
* R2M0C_VcoControlBits_t
* RegisterName: VCO_CONTROL
* VCO control settings
* 
* Address: 0x120
* ResetValue: 0x00000001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vco_en
	* Description: enable vco (internally this delayed by pon_counter cycles)
	* 1: Enabled
	* 0: Disabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoEn : 1;        /*## attribute VcoEn */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M0C_VcoControlBits_t;
/**
* R2M0C_StartCalibrationBits_t
* RegisterName: START_CALIBRATION
* PLL4G8 calibration trigger
* Address: 0x124
* ResetValue: 0x00000000
* Read/Write: W
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: start_calibration_ctrl
	* Description: Trigger the PLL4G8 calibration
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t StartCalibrationCtrl : 1;        /*## attribute StartCalibrationCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M0C_StartCalibrationBits_t;
/**
* R2M0C_ResetCalibrationBits_t
* RegisterName: RESET_CALIBRATION
* Calibration control at reset
* Address: 0x128
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: rst_an
	* Description: When the reset is released, the system will automatically perform a calibration of the 4.8GHz PLL
	* 0: Apply reset
	* 1: Normal operation
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RstAn : 1;        /*## attribute RstAn */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M0C_ResetCalibrationBits_t;
/**
* R2M0C_SnsControlBits_t
* RegisterName: SNS_CONTROL
* supply monitor (SM) control bits
* Address: 0x130
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: sns_low_pd
	* Description: This bit drives the input port Power down bit of supply monitor(SM). 
	* 1 : will disable  Supply monitor (SM)
	* 0: Normal operation
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SnsLowPd : 1;        /*## attribute SnsLowPd */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M0C_SnsControlBits_t;
/**
* R2M0C_CalibrationStatus1Bits_t
* RegisterName: CALIBRATION_STATUS1
* Calibration status1
* Address: 0x140
* ResetValue: 0x3E110100
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 4;        /*## attribute Reserved0 */
	/**
	* BitsName: vco_freq_recalib
	* Description: tuning voltage recalibration comparator output
	* 1: Freq recalibration required
	* 0: Freq recalibration not required
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoFreqRecalib : 1;        /*## attribute VcoFreqRecalib */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_level_recalib
	* Description: vco level recalibration comparator output
	* 1: Level recalibration required
	* 0: Level recalibration not required
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoLevelRecalib : 1;        /*## attribute VcoLevelRecalib */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 7;        /*## attribute Reserved2 */
	/**
	* BitsName: vco_level_comp
	* Description: vco amplitude comparator output
	* 
	* Read/Write: R
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoLevelComp : 1;        /*## attribute VcoLevelComp */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: vtune_override_out
	* Description: VCO tuning voltage override by calibration controller
	* 1: Override
	* 0: No override
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VtuneOverrideOut : 1;        /*## attribute VtuneOverrideOut */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: aac_ictrl_mon
	* Description: vco current control monitor. Updated the reset value based on the wreal model
	* Read/Write: R
	* Bits: [29:24]
	* ResetValue: 0b111110
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIctrlMon : 6;        /*## attribute AacIctrlMon */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: pll_bias_filter_override_mon
	* Description: pll bias filter override monitor
	* Read/Write: R
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllBiasFilterOverrideMon : 1;        /*## attribute PllBiasFilterOverrideMon */
}R2M0C_CalibrationStatus1Bits_t;
/**
* R2M0C_CalibrationStatus2Bits_t
* RegisterName: CALIBRATION_STATUS2
* Calibration status2
* Address: 0x144
* ResetValue: 0x000000FF
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: afc_fsel_out
	* Description: vco coarse frequency tuning
	* Read/Write: R
	* Bits: [7:0]
	* ResetValue: 0b11111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselOut : 8;        /*## attribute AfcFselOut */
	/**
	* BitsName: afc_m
	* Description: frequency loop actual Mvalue
	* Read/Write: R
	* Bits: [20:8]
	* ResetValue: 0b0000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcM : 13;        /*## attribute AfcM */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_dbg_cal_state
	* Description: Calibration state for debug
	* 
	* Read/Write: R
	* Bits: [31:28]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDbgCalState : 4;        /*## attribute PllDbgCalState */
}R2M0C_CalibrationStatus2Bits_t;
/**
* R2M0C_CalibrationStatus3Bits_t
* RegisterName: CALIBRATION_STATUS3
* Calibration status3 
* This is same bits as calibration_status1 and calibration_status2 but kept in single register here to make it easier for software to get the content in single read and also keeping those bits status1& status2 for backward compatibility
* Address: 0x148
* ResetValue: 0x00001000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_calibration_active
	* Description: Calibration active status
	* 1: Calibration active
	* 0: Calibration not active
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllCalibrationActive : 1;        /*## attribute PllCalibrationActive */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lock_error
	* Description: lock error. This bit has to be checked after pll_calibration_active is deasserted
	* 1: lock error
	* 0: no error
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLockError : 1;        /*## attribute PllLockError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_level_error
	* Description: vco level detect output (before func safety latch)
	* 1: VCO level error
	* 0: No VCO level error
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoLevelError : 1;        /*## attribute VcoLevelError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: vco_recalibrate
	* Description: vco recalibration indicator flag
	* 1: Recalibration required
	* 0: Recalibration not required
	* Read/Write: R
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoRecalibrate : 1;        /*## attribute VcoRecalibrate */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M0C_CalibrationStatus3Bits_t;
/**
* R2M0C_XoStatusBits_t
* RegisterName: XO_STATUS
* Lock status bits
* Address: 0x150
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: xo_det_xoclk
	* Description: Indicates that crystal clock is detected
	* 1: Detected
	* 0: Not Detected
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoDetXoclk : 1;        /*## attribute XoDetXoclk */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: xo_det_clkin
	* Description: indicates that follower clock at clk_in is detected
	* 1: Detected
	* 0: Not Detected
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoDetClkin : 1;        /*## attribute XoDetClkin */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: xo_det_pllclk
	* Description: indicates that follower clock at output of XO to pll is detected
	* 1: Detected
	* 0: Not Detected
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoDetPllclk : 1;        /*## attribute XoDetPllclk */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 23;        /*## attribute Reserved2 */
}R2M0C_XoStatusBits_t;
/**
* R2M0C_MspcCalibCheckStatusBits_t
* RegisterName: MSPC_CALIB_CHECK_STATUS
* This register indicates mspc calibration status
* Address: 0x160
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mspc_calib_state_debug
	* Description: Indicates the calibration state for debug
	* 
	* Read/Write: R
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcCalibStateDebug : 4;        /*## attribute MspcCalibStateDebug */
	/**
	* BitsName: mspc_calib_check_state_debug
	* Description: Indicates the calibration check state for debug
	* Read/Write: R
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcCalibCheckStateDebug : 4;        /*## attribute MspcCalibCheckStateDebug */
	/**
	* BitsName: mspc_calib_busy
	* Description: Indicates the busy status of mspc calibration 
	* 1: calibration is active
	* 0: calibration  is inactive
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcCalibBusy : 1;        /*## attribute MspcCalibBusy */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: mspc_calib_check_busy
	* Description: Indicates the busy status of calib check 
	* 1: calibration check is active
	* 0: calibration check is inactive
	* Read/Write: R
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcCalibCheckBusy : 1;        /*## attribute MspcCalibCheckBusy */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mspc_pfd_clkin_early
	* Description: Indicates clk_in status compared to pll reference clock
	* 1: Clk_in is early compared to pll 40MHz feedback reference clock
	* 0: Clk_in is not early compared to pll 40MHz feedback reference clock
	* Read/Write: R
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcPfdClkinEarly : 1;        /*## attribute MspcPfdClkinEarly */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mspc_error
	* Description: MSPC calibration status
	* 
	* 0: no error
	* 1: phase calibration error is set
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcError : 1;        /*## attribute MspcError */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 11;        /*## attribute Reserved3 */
}R2M0C_MspcCalibCheckStatusBits_t;
/**
* R2M0C_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This register is kept for validation and not to be used in the functional context
* Address: 0x304
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_supply_low_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyLowResetError : 1;        /*## attribute MaskSupplyLowResetError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_xo_det_xoclk_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskXoDetXoclkResetError : 1;        /*## attribute MaskXoDetXoclkResetError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mask_pll_lock_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskPllLockResetError : 1;        /*## attribute MaskPllLockResetError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_pll_level_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskPllLevelResetError : 1;        /*## attribute MaskPllLevelResetError */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mask_pll_vco_recalibrate_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskPllVcoRecalibrateResetError : 1;        /*## attribute MaskPllVcoRecalibrateResetError */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskRegCrcResetError : 1;        /*## attribute MaskRegCrcResetError */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: mask_mspc_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskMspcResetError : 1;        /*## attribute MaskMspcResetError */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: mask_xo_det_clkin_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskXoDetClkinResetError : 1;        /*## attribute MaskXoDetClkinResetError */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 2;        /*## attribute Reserved7 */
	/**
	* BitsName: mask_xo_det_pllclk_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskXoDetPllclkResetError : 1;        /*## attribute MaskXoDetPllclkResetError */
}R2M0C_MaskCcResetErrorBits_t;
/**
* R2M0C_CrcErrorStatus1Bits_t
* RegisterName: CRC_ERROR_STATUS1
* Status of the CRC for each register
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
}R2M0C_CrcErrorStatus1Bits_t;
/**
* R2M0C_CrcErrorStatus2Bits_t
* RegisterName: CRC_ERROR_STATUS2
* Status of the CRC for each register
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
}R2M0C_CrcErrorStatus2Bits_t;
/**
* R2M0C_CrcErrorStatus3Bits_t
* RegisterName: CRC_ERROR_STATUS3
* Status of the CRC for each register
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
	* Note: The status corresponds to last 2 registers listed i.e registers 65(msb) down to 64(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 32;        /*## attribute CrcErrorStatusReg3 */
}R2M0C_CrcErrorStatus3Bits_t;
/**
* R2M0C_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x000C4001
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
	* ResetValue: 0b0100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRevision : 4;        /*## attribute MajorRevision */
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000001100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M0C_ModuleIdBits_t;

 #else
/**
* R2M0C_IrefLdoControlBits_t
* RegisterName: IREF_LDO_CONTROL
* Bias control settings
* 
* Address: 0x000
* ResetValue: 0x00000D0F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: sel_iref_bias
	* Description: PLL4G8 internal current source trim value
	* Read/Write: RW
	* Bits: [12:8]
	* ResetValue: 0b01101
	* Source: OTP
	* FuSa: No
	*/
	uint32_t SelIrefBias : 5;        /*## attribute SelIrefBias */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: xo_ldo_iref
	* Description: internal ldo reference current selection inputs(1.8v)
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t XoLdoIref : 5;        /*## attribute XoLdoIref */
}R2M0C_IrefLdoControlBits_t;
/**
* R2M0C_XoPllLdoControlBits_t
* RegisterName: XO_PLL_LDO_CONTROL
* Ldo control settings for the PLL.
* All LDO's to eb enabed for the PLL to work.
* 
* Address: 0x004
* ResetValue: 0x0F0F0F0F
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
	* BitsName: xo_ldo_vout
	* Description: Set output voltage of XO LDO. Value comes from OTP
	* .
	* Read/Write: RW
	* Bits: [28:24]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t XoLdoVout : 5;        /*## attribute XoLdoVout */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: vout_ldo3
	* Description: set output voltage of PLL4G8 LDO3. Value comes from OTP
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [20:16]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t VoutLdo3 : 5;        /*## attribute VoutLdo3 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: vout_ldo2
	* Description: set output voltage of PLL4G8 LDO2. Value comes from OTP
	* 
	* Read/Write: RW
	* Bits: [12:8]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t VoutLdo2 : 5;        /*## attribute VoutLdo2 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: vout_ldo1
	* Description: set output voltage of PLL4G8 LDO1. Value comes from OTP
	* 
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t VoutLdo1 : 5;        /*## attribute VoutLdo1 */
}R2M0C_XoPllLdoControlBits_t;
/**
* R2M0C_McLdoControlBits_t
* RegisterName: MC_LDO_CONTROL
* Master clock local Ldo control settings
* Address: 0x008
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: ldo_sel_vout
	* Description: Set output voltage of Master clock LDO. Value comes from OTP
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVout : 5;        /*## attribute LdoSelVout */
}R2M0C_McLdoControlBits_t;
/**
* R2M0C_TrimSettingsBits_t
* RegisterName: TRIM_SETTINGS
* PLL4G8 trim values
* 
* Address: 0x00C
* ResetValue: 0x00001010
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: lpf_r2
	* Description: LPF set R2 value
	* Read/Write: RW
	* Bits: [12:8]
	* ResetValue: 0b10000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LpfR2 : 5;        /*## attribute LpfR2 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_rset
	* Description: vco current control resistor value (internally this delayed by pon_counter cycles)
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t VcoRset : 5;        /*## attribute VcoRset */
}R2M0C_TrimSettingsBits_t;
/**
* R2M0C_XoPllMcLdoEnableBits_t
* RegisterName: XO_PLL_MC_LDO_ENABLE
* Ldo control settings for the PLL.
* All LDO's to be enabed for the PLL to work.
* 
* Address: 0x010
* ResetValue: 0x00001111
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_ena_ldo3
	* Description: enable PLL4G8 LDO3 (VCO, peak detector for calibration, first stage divider, 2G4 I/O)
	* 1: Enable LDO3
	* 0: Disable LDO3
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllEnaLdo3 : 1;        /*## attribute PllEnaLdo3 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: pll_ena_ldo2
	* Description: enable PLL4G8 LDO2 (Charge pump, PFD, Low-pass filterm PLL glue logic)
	* 1: Enable LDO2
	* 0: Disable LDO2
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllEnaLdo2 : 1;        /*## attribute PllEnaLdo2 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: pll_ena_ldo1
	* Description: enable PLL4G8 LDO1 (Divider)
	* 1: Enable LDO1
	* 0: Disable LDO1
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllEnaLdo1 : 1;        /*## attribute PllEnaLdo1 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mc_ldo_en
	* Description: Master clock LDO enable (buffers, XO functional safety)
	* 1: Enable LDO
	* 0: Disable LDO
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t McLdoEn : 1;        /*## attribute McLdoEn */
}R2M0C_XoPllMcLdoEnableBits_t;
/**
* R2M0C_IbiasControlBits_t
* RegisterName: IBIAS_CONTROL
* PLL4G8 bias control
* 
* Address: 0x020
* ResetValue: 0x11186444
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
	* BitsName: en_iref_bias
	* Description: PLL4G8 internal current source enable
	* 1: Enable
	* 0: Disable
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnIrefBias : 1;        /*## attribute EnIrefBias */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: sel_globalref
	* Description: 
	* Selects the reference current source of the bias currents used in the PLL4G8 (100uA).
	* 0: selects the reference current source in the PLL4G8  
	* 1: selects the reference current source in the Global Bias 
	* 
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t SelGlobalref : 1;        /*## attribute SelGlobalref */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_bias_cp_100u
	* Description: PLL4G8 ibias charge pump trim value
	* Read/Write: RW
	* Bits: [20:16]
	* ResetValue: 0b11000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBiasCp100U : 5;        /*## attribute CtlBiasCp100U */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_bias_opamp_100u
	* Description: PLL4G8 ibias opamp (inside charge pump) trim value
	* Read/Write: RW
	* Bits: [14:12]
	* ResetValue: 0b110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBiasOpamp100U : 3;        /*## attribute CtlBiasOpamp100U */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: ctl_ibias_2g4buf_350u
	* Description: PLL4G8 ibias 2.4GHz output buffer trim value
	* Read/Write: RW
	* Bits: [10:8]
	* ResetValue: 0b100
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbias2G4Buf350U : 3;        /*## attribute CtlIbias2G4Buf350U */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: ctl_ibias_2g4_predriv_200u
	* Description: PLL4G8 ibias 2.4GHz pre driver trim value
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b100
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbias2G4Predriv200U : 3;        /*## attribute CtlIbias2G4Predriv200U */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 1;        /*## attribute Reserved6 */
	/**
	* BitsName: ctl_vcom_2g4_predriv
	* Description: PLL4G8 common mode voltage 2.4GHz pre driver trim value
	* 
	* 
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b100
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcom2G4Predriv : 3;        /*## attribute CtlVcom2G4Predriv */
}R2M0C_IbiasControlBits_t;
/**
* R2M0C_PfdControlBits_t
* RegisterName: PFD_CONTROL
* Phase Frequency Detector control settings for 4.8GHz PLL
* .
* Address: 0x024
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: pfd_rst
	* Description: overrule reset pfd
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PfdRst : 1;        /*## attribute PfdRst */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: pfd_del
	* Description: pfd reset delay control
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PfdDel : 2;        /*## attribute PfdDel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: pfd_force_up
	* Description: force pfd up
	* 1: Increase current
	* 0: no effect
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PfdForceUp : 1;        /*## attribute PfdForceUp */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: pfd_force_down
	* Description: force pfd down
	* 1: Decrease current
	* 0: no effect
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PfdForceDown : 1;        /*## attribute PfdForceDown */
}R2M0C_PfdControlBits_t;
/**
* R2M0C_CpControlBits_t
* RegisterName: CP_CONTROL
* Charge pump control settings
* .
* Address: 0x028
* ResetValue: 0x000001FF
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: cp_ena
	* Description: enable charge pump
	* 1: Enable
	* 0: Disable
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CpEna : 1;        /*## attribute CpEna */
	/**
	* BitsName: cp_slice_ena
	* Description: set charge pump current per slice
	* Each bit controls one slice
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b11111111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CpSliceEna : 8;        /*## attribute CpSliceEna */
}R2M0C_CpControlBits_t;
/**
* R2M0C_ClockDelaySkewControlBits_t
* RegisterName: CLOCK_DELAY_SKEW_CONTROL
* In applications where two  ICs have to work together, the phases of the 600MHz
* clocks in both ICs have to be aligned within a tight tolerance. In this case one of the ICs
* works as leader, the other one as follower. Only the leader will use the xtal oscillator, while
* the follower receives its 40MHz reference clock from the leader.
* Obviously the follower reference clock will always be delayed by a few nanoseconds with
* respect to the leader reference clock. To compensate for this delay, the PLL has two
* provisions: ADC reference clock re-clocking and fine pitch output clock skew
* 
* 
* ADC reference clock re-clocking
* 
* PLL reference clock delay between leader and follower IC can be more
* than one period of the 600MHz clock. Obviously we cannot advance the 600MHz clock for
* more than a single period w.r.t. the 40MHz input clock. However the
* 40MHz clock that goes to the ADC can be manipulated, as a reference for the sampling time point. By shifting
* this ADC reference clock over a number of periods of the 600MHz clock, it is possible to
* compensate for any amount of delay (as long as it is less than the 40MHz clock period).
* 
* Fine pitch output clock skew :
* 
* The PLL feedback divide chain implements two cascaded dividers; a divide-by-8 and a
* divide-by-15 circuit. The output signal of this divide-by-8 circuit is 600MHz.
* This divider is synchronized to a second divide-by-8 circuit, which delivers the 600MHz
* output clock, for clocking the the Chip ADC. However the exact phase relation between
* these two divide-by-8 circuits is made adjustable. The 600MHz output of the first divider
* can be delayed from 0 to15/16.T600M, in steps of 1/16.T600M (approx. 104ps nom.).
* Since the first divide-by-8 is part of the feedback divider chain, the phase relation between
* its 600MHz output clock and the 40MHz feedback clock is automatically fixed; their rising
* edges will always coincide. When, as described, the 600MHz clock in the feedback path is
* delayed for a part of its period, the 600MHz output clock for the ADC becomes advanced
* with respect to the 40MHz input clock of the PLL
* Address: 0x02C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
	/**
	* BitsName: set_delay_clk40
	* Description: Select reference clock delay factor N
	* Delay = N. (1/600MHz). N=1 to 5
	* 
	* In the manual mode, the value written into this field will be driven towards the pll and the same can be read back. 
	* 
	* Incase of autonomous mode mspc calibration, the written value is ignored but the read value after the calibration reflects the calibration converged value
	* 
	* The delay is adjusted interms of 1.6 ns
	* 
	* 
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t SetDelayClk40 : 4;        /*## attribute SetDelayClk40 */
	/**
	* BitsName: output_clk_skew
	* Description: fine pitch 600MHz output clock skew 0 to -15/16.T
	* 
	* 
	* In the manual mode, the value written into this field will be driven towards the pll and the same can be read back. 
	* 
	* Incase of autonomous mode mspc calibration, the written value is ignored but the read value after the calibration reflects the calibration converged value
	* 
	* The fine adjustment is interms of 104 ps
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t OutputClkSkew : 4;        /*## attribute OutputClkSkew */
}R2M0C_ClockDelaySkewControlBits_t;
/**
* R2M0C_LoopFilterControlBits_t
* RegisterName: LOOP_FILTER_CONTROL
* PLL4G8 loop-filter control settings
* Address: 0x030
* ResetValue: 0x00000021
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
	/**
	* BitsName: lpf_c2
	* Description: LPF set C2 value
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0010
	* Source: Application
	* FuSa: No
	*/
	uint32_t LpfC2 : 4;        /*## attribute LpfC2 */
	/**
	* BitsName: lpf_c1
	* Description: LPF set C1 value
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0001
	* Source: Application
	* FuSa: No
	*/
	uint32_t LpfC1 : 4;        /*## attribute LpfC1 */
}R2M0C_LoopFilterControlBits_t;
/**
* R2M0C_LockControlBits_t
* RegisterName: LOCK_CONTROL
* PLL un Lock detector control settings. This is a functional safety control register
* Address: 0x034
* ResetValue: 0x000001C4
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: lock_det_force_rst
	* Description: lock detector force reset condition
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LockDetForceRst : 1;        /*## attribute LockDetForceRst */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
	/**
	* BitsName: lock_det_enable
	* Description: lock detector enable
	* 1: Enable
	* 0: Disable
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LockDetEnable : 1;        /*## attribute LockDetEnable */
	/**
	* BitsName: lock_det_mode_ctrl
	* Description: lock detector mode control (7:6=anl, 4:0=dig)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b11000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LockDetModeCtrl : 8;        /*## attribute LockDetModeCtrl */
}R2M0C_LockControlBits_t;
/**
* R2M0C_XoBufferControlBits_t
* RegisterName: XO_BUFFER_CONTROL
* Xtal oscillator buffer control register
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
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: xo_clkoutdrvlvl_red
	* Description: reduces drive level of XO output buffers
	* 
	* 1: Drive level reduced
	* 0 : Normal drive level
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoClkoutdrvlvlRed : 1;        /*## attribute XoClkoutdrvlvlRed */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: xo_clkoutn_pd
	* Description: clock output N (also called xo_clkout_180_pd to control the clk_out_180 ball) buffer power down signal
	* 
	* 1: Powerdown enabled
	* 0 : No powerdown
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoClkoutnPd : 1;        /*## attribute XoClkoutnPd */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: xo_clkoutp_pd
	* Description: clock output P (also called xo_clkout_0_pd to control the clk_out_0 ball) buffer power down signal
	* 
	* 1: Powerdown enabled
	* 0 : No powerdown
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoClkoutpPd : 1;        /*## attribute XoClkoutpPd */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: xo_clkin_pd
	* Description: clock input (to control the clk_in ball) buffer power down signal
	* 
	* 1: Powerdown enabled
	* 0 : No powerdown
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoClkinPd : 1;        /*## attribute XoClkinPd */
}R2M0C_XoBufferControlBits_t;
/**
* R2M0C_ClockBufferControlBits_t
* RegisterName: CLOCK_BUFFER_CONTROL
* Clock output buffer control
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
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
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
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: en_clk_adc_40
	* Description: Enable 40MHz ADC clock buffer
	* 0 = disable
	* 1 = enable
	* 
	* 
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkAdc40 : 1;        /*## attribute EnClkAdc40 */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: en_clk_ssbmod_600
	* Description: Enable 600MHz SSBmod clock buffer 0 = disable
	* 1 = enable
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkSsbmod600 : 1;        /*## attribute EnClkSsbmod600 */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: en_clk_adc_1200
	* Description: Enable 1200MHz ADC clock buffer 
	* 0 = disable 
	* 1 = enable
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkAdc1200 : 1;        /*## attribute EnClkAdc1200 */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 3;        /*## attribute Reserved7 */
	/**
	* BitsName: en_clk_ser_480_600
	* Description: Enable 480_600MHz SER clock buffer 
	* 0 = disable 
	* 1 = enable
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkSer480600 : 1;        /*## attribute EnClkSer480600 */
	/**
	* BitsName: Reserved_8 
	* Description: not used 
	*/
	uint32_t Reserved8 : 3;        /*## attribute Reserved8 */
	/**
	* BitsName: en_clk_chirp_480
	* Description: Enable 480MHz chirp clock buffer 
	* 0 = disable 
	* 1 = enable
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnClkChirp480 : 1;        /*## attribute EnClkChirp480 */
}R2M0C_ClockBufferControlBits_t;
/**
* R2M0C_ClockGateControlBits_t
* RegisterName: CLOCK_GATE_CONTROL
* Clock gate control
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
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: clkgate_ssbmod_600
	* Description: Enable clockgate for 600MHz SSBmod clock buffer 
	*  0 = disable power save and  enable clock propagation  
	*  1 = enable power save and disable clock propagation
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkgateSsbmod600 : 1;        /*## attribute ClkgateSsbmod600 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: clkgate_adc_1200
	* Description: Enable clockgate for 1200MHz ADC clock buffer 
	*  0 = disable power save and  enable clock propagation  
	*  1 = enable power save and disable clock propagation
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkgateAdc1200 : 1;        /*## attribute ClkgateAdc1200 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: clkgate_ser_480_600
	* Description: Enable clockgate for 480_600MHz SER clock buffer 
	*  0 = disable power save and  enable clock propagation  
	*  1 = enable power save and disable clock propagation
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkgateSer480600 : 1;        /*## attribute ClkgateSer480600 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: clkgate_chirp_480
	* Description: Enable clockgate for 480MHz chirp clock buffer 
	*  0 = disable power save and  enable clock propagation  
	*  1 = enable power save and disable clock propagation
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkgateChirp480 : 1;        /*## attribute ClkgateChirp480 */
}R2M0C_ClockGateControlBits_t;
/**
* R2M0C_ClkselBits_t
* RegisterName: CLKSEL
* CC and ADC synchronization clock control
* Address: 0x074
* ResetValue: 0x00000010
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: clksel_adc_40_negedge
	* Description: select negedge of 1200MHz clock for ADC
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkselAdc40Negedge : 1;        /*## attribute ClkselAdc40Negedge */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: clksel_cc_40_calclk
	* Description: 0: XO clock for CC (use only during startup) 
	* 1: calibrated clock for CC (use after starting 4.8GHz PLL)
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkselCc40Calclk : 1;        /*## attribute ClkselCc40Calclk */
}R2M0C_ClkselBits_t;
/**
* R2M0C_CalibrationAfcControl5Bits_t
* RegisterName: CALIBRATION_AFC_CONTROL5
* Automatic frequency calibration settings5
* 
* Address: 0x0B0
* ResetValue: 0x00000010
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_use_recal_settings
	* Description: Use recalibration settings
	* 
	* 1: Recalibration settings applied
	* 0: Recalibration settings not applied
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllUseRecalSettings : 1;        /*## attribute PllUseRecalSettings */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: afc_manual
	* Description: frequency control loop manual mode
	* 1: Manual mode Enabled
	* 0: Disabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcManual : 1;        /*## attribute AfcManual */
}R2M0C_CalibrationAfcControl5Bits_t;
/**
* R2M0C_ClkDetEnConfigBits_t
* RegisterName: CLK_DET_EN_CONFIG
* Clk (XO CLK, CLKIN, PLLCLK) detector configuration (which detector to be enabled/disabled) and XO clock enable to enable the clean clock towards Chirp and Serializer frequency counter
* 
* Address: 0x0C0
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
	* BitsName: always_enable_chirp_ser_xo_clk
	* Description: Always enable the xo clock towards chirp, serializer freq counter
	* 
	* 1: Always enable xo clock
	* 0: enable xo clock based on the chirp and serializer enable signals
	* 
	* Note: If set 0, the mask bits in this register still can be configured to disable the xo clock
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AlwaysEnableChirpSerXoClk : 1;        /*## attribute AlwaysEnableChirpSerXoClk */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
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
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 1;        /*## attribute Reserved7 */
	/**
	* BitsName: clk_det_mode
	* Description: Clock Detector Mode Settings is about applying the masks to the clock detector in the different modes : {pllclk_mask, clkin_mask, xoclk_mask}
	* 000: Startup mode    ({pllclk_mask, clkin_mask, xoclk_mask}=3'b100)
	* 001: Standalone mode ({pllclk_mask, clkin_mask, xoclk_mask}=3'b010)
	* 010: Leader mode ({pllclk_mask, clkin_mask, xoclk_mask}=3'b000)
	* 011: Follower mode   ({pllclk_mask, clkin_mask, xoclk_mask}=3'b001)
	* >=100: Direct mask value defined in the field clk_det_mode_debug
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t ClkDetMode : 3;        /*## attribute ClkDetMode */
}R2M0C_ClkDetEnConfigBits_t;
/**
* R2M0C_MspcControl1Bits_t
* RegisterName: MSPC_CONTROL1
* MSPC Control settings
* Address: 0x110
* ResetValue: 0x00000003
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
	* BitsName: mspc_pfd_clkin_early_invert
	* Description: Invert the clkin_early generated from analog PFD (Phase Frequency Detector)
	* 
	* 0: No inversion on the clkin_early from analog PFD
	* 1: Invert clkin_early from analog PFD
	* Note: In general, this bit needs to be set 1'b1 when mspc_clkmux_ctrl = 2'b00
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPfdClkinEarlyInvert : 1;        /*## attribute MspcPfdClkinEarlyInvert */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
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
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: mspc_pfd_1v8_ena
	* Description: enables 1v8 related blocks in PFD
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPfd1V8Ena : 1;        /*## attribute MspcPfd1V8Ena */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: mspc_pfd_1v1_ena
	* Description: enables 1v1 related blocks in PFD
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPfd1V1Ena : 1;        /*## attribute MspcPfd1V1Ena */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 2;        /*## attribute Reserved7 */
	/**
	* BitsName: mspc_clkmux_ctrl
	* Description: DFT: selects reference clock from clk_in or divided PLL clock for both inputs
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b11
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcClkmuxCtrl : 2;        /*## attribute MspcClkmuxCtrl */
}R2M0C_MspcControl1Bits_t;
/**
* R2M0C_MspcControl2Bits_t
* RegisterName: MSPC_CONTROL2
* MSPC Control settings
* Address: 0x114
* ResetValue: 0x00000034
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
	* BitsName: mspc_set_delay_wait_time
	* Description: The wait time to be applied after the set_delay is programmed
	* 
	* 2'b00 : 4 * 25 ns
	* 2'b01 : 8 * 25 ns
	* 2'b10 : 16 * 25 ns
	* 2'b11 : 32 * 25 ns
	* 
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcSetDelayWaitTime : 2;        /*## attribute MspcSetDelayWaitTime */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: mspc_measure_wait_time
	* Description: The wait time for the mspc measurement
	* 
	* 3'b000 : 1 us
	* 3'b001 : 2 us
	* 3'b010 : 4 us
	* 3'b011 : 8 us
	* 3'b100 : 16 us
	* 3'b101 : 32 us
	* 3'b110 : 64 us
	* 3'b111 : 128 us
	* 
	* 
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcMeasureWaitTime : 3;        /*## attribute MspcMeasureWaitTime */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: mspc_pll_skew_wait_time
	* Description: The wait time to be applied after the pll skew is programmed
	* 
	* 3'b000 : 2.5 us
	* 3'b001 : 5 us
	* 3'b010 : 10 us
	* 3'b011 : 20 us
	* 3'b100 : 40 us
	* 3'b101 : 80 us
	* 3'b110 : 160 us
	* 3'b111 : 320 us
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPllSkewWaitTime : 3;        /*## attribute MspcPllSkewWaitTime */
}R2M0C_MspcControl2Bits_t;
/**
* R2M0C_MspcControl3Bits_t
* RegisterName: MSPC_CONTROL3
* MSPC Control settings
* Address: 0x118
* ResetValue: 0x00000000
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
	* BitsName: mspc_calib_check_correction_enable
	* Description: Control to enable the new settings after calib check, This control should not to be used directly. Instead software API to be used for correction
	* 
	* 1'b0 : Old pll set_delay and skew are maintained after the mspc_calib_check completion
	* 1'b1 : New pll set_delay and skew are applied after the mspc_calib_check completion if the difference (in skew, set_delay) is found
	* 
	* 
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcCalibCheckCorrectionEnable : 1;        /*## attribute MspcCalibCheckCorrectionEnable */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mspc_calib_check
	* Description: Control to activate Calibration check, This control should not to be used directly. Instead software API to be used for calibration check
	* 
	* 1'b0 : No operation
	* 1'b1 : MSPC check is triggered
	* 
	* Note1: As the same bit is used for Auto and Manual mode calibration trigger, 0 to 1 on this bit is detected as start calibration check. This bit and mspc_pfd_start_meas bit in the same register should not be set at the same time. If both set 1, no operation will be performed
	* Note2: In general, calib_check to be triggered atleast once the first mspc calibration done
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcCalibCheck : 1;        /*## attribute MspcCalibCheck */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mspc_calib_mode
	* Description: MSPC calibration mode
	* 
	* 1'b0 : HW (Autonomous) based MSPC calibration
	* 1'b1 : SW based MSPC calibration
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcCalibMode : 1;        /*## attribute MspcCalibMode */
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
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 1;        /*## attribute Reserved6 */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 3;        /*## attribute Reserved7 */
	/**
	* BitsName: mspc_pfd_start_meas
	* Description: starts measurement of phase calibration
	* 
	* 
	* 1'b0 : No operation
	* 1'b1 : MSPC start is triggered
	* 
	* Note: As the same bit is used for Auto and Manual mode calibration trigger, 0 to 1 on this bit is detected as start calibration. This bit and mspc_calibration_check bit in the same register should not be set at the same time. If both set 1, no operation will be performed 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MspcPfdStartMeas : 1;        /*## attribute MspcPfdStartMeas */
}R2M0C_MspcControl3Bits_t;
/**
* R2M0C_MspcTrimSettingsBits_t
* RegisterName: MSPC_TRIM_SETTINGS
* MSPC Trim settings
* Address: 0x11C
* ResetValue: 0x00000007
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: mspc_trim_ctrl
	* Description: trim charge pump currents in PFD
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b00111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t MspcTrimCtrl : 5;        /*## attribute MspcTrimCtrl */
}R2M0C_MspcTrimSettingsBits_t;
/**
* R2M0C_VcoControlBits_t
* RegisterName: VCO_CONTROL
* VCO control settings
* 
* Address: 0x120
* ResetValue: 0x00000001
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
	* BitsName: vco_en
	* Description: enable vco (internally this delayed by pon_counter cycles)
	* 1: Enabled
	* 0: Disabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoEn : 1;        /*## attribute VcoEn */
}R2M0C_VcoControlBits_t;
/**
* R2M0C_StartCalibrationBits_t
* RegisterName: START_CALIBRATION
* PLL4G8 calibration trigger
* Address: 0x124
* ResetValue: 0x00000000
* Read/Write: W
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: start_calibration_ctrl
	* Description: Trigger the PLL4G8 calibration
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t StartCalibrationCtrl : 1;        /*## attribute StartCalibrationCtrl */
}R2M0C_StartCalibrationBits_t;
/**
* R2M0C_ResetCalibrationBits_t
* RegisterName: RESET_CALIBRATION
* Calibration control at reset
* Address: 0x128
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: rst_an
	* Description: When the reset is released, the system will automatically perform a calibration of the 4.8GHz PLL
	* 0: Apply reset
	* 1: Normal operation
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RstAn : 1;        /*## attribute RstAn */
}R2M0C_ResetCalibrationBits_t;
/**
* R2M0C_SnsControlBits_t
* RegisterName: SNS_CONTROL
* supply monitor (SM) control bits
* Address: 0x130
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_low_pd
	* Description: This bit drives the input port Power down bit of supply monitor(SM). 
	* 1 : will disable  Supply monitor (SM)
	* 0: Normal operation
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SnsLowPd : 1;        /*## attribute SnsLowPd */
}R2M0C_SnsControlBits_t;
/**
* R2M0C_CalibrationStatus1Bits_t
* RegisterName: CALIBRATION_STATUS1
* Calibration status1
* Address: 0x140
* ResetValue: 0x3E110100
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_bias_filter_override_mon
	* Description: pll bias filter override monitor
	* Read/Write: R
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllBiasFilterOverrideMon : 1;        /*## attribute PllBiasFilterOverrideMon */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: aac_ictrl_mon
	* Description: vco current control monitor. Updated the reset value based on the wreal model
	* Read/Write: R
	* Bits: [29:24]
	* ResetValue: 0b111110
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIctrlMon : 6;        /*## attribute AacIctrlMon */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: vtune_override_out
	* Description: VCO tuning voltage override by calibration controller
	* 1: Override
	* 0: No override
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VtuneOverrideOut : 1;        /*## attribute VtuneOverrideOut */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: vco_level_comp
	* Description: vco amplitude comparator output
	* 
	* Read/Write: R
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoLevelComp : 1;        /*## attribute VcoLevelComp */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 7;        /*## attribute Reserved3 */
	/**
	* BitsName: vco_level_recalib
	* Description: vco level recalibration comparator output
	* 1: Level recalibration required
	* 0: Level recalibration not required
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoLevelRecalib : 1;        /*## attribute VcoLevelRecalib */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: vco_freq_recalib
	* Description: tuning voltage recalibration comparator output
	* 1: Freq recalibration required
	* 0: Freq recalibration not required
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoFreqRecalib : 1;        /*## attribute VcoFreqRecalib */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 4;        /*## attribute Reserved5 */
}R2M0C_CalibrationStatus1Bits_t;
/**
* R2M0C_CalibrationStatus2Bits_t
* RegisterName: CALIBRATION_STATUS2
* Calibration status2
* Address: 0x144
* ResetValue: 0x000000FF
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_dbg_cal_state
	* Description: Calibration state for debug
	* 
	* Read/Write: R
	* Bits: [31:28]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDbgCalState : 4;        /*## attribute PllDbgCalState */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: afc_m
	* Description: frequency loop actual Mvalue
	* Read/Write: R
	* Bits: [20:8]
	* ResetValue: 0b0000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcM : 13;        /*## attribute AfcM */
	/**
	* BitsName: afc_fsel_out
	* Description: vco coarse frequency tuning
	* Read/Write: R
	* Bits: [7:0]
	* ResetValue: 0b11111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselOut : 8;        /*## attribute AfcFselOut */
}R2M0C_CalibrationStatus2Bits_t;
/**
* R2M0C_CalibrationStatus3Bits_t
* RegisterName: CALIBRATION_STATUS3
* Calibration status3 
* This is same bits as calibration_status1 and calibration_status2 but kept in single register here to make it easier for software to get the content in single read and also keeping those bits status1& status2 for backward compatibility
* Address: 0x148
* ResetValue: 0x00001000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: vco_recalibrate
	* Description: vco recalibration indicator flag
	* 1: Recalibration required
	* 0: Recalibration not required
	* Read/Write: R
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoRecalibrate : 1;        /*## attribute VcoRecalibrate */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_level_error
	* Description: vco level detect output (before func safety latch)
	* 1: VCO level error
	* 0: No VCO level error
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t VcoLevelError : 1;        /*## attribute VcoLevelError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: pll_lock_error
	* Description: lock error. This bit has to be checked after pll_calibration_active is deasserted
	* 1: lock error
	* 0: no error
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLockError : 1;        /*## attribute PllLockError */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: pll_calibration_active
	* Description: Calibration active status
	* 1: Calibration active
	* 0: Calibration not active
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllCalibrationActive : 1;        /*## attribute PllCalibrationActive */
}R2M0C_CalibrationStatus3Bits_t;
/**
* R2M0C_XoStatusBits_t
* RegisterName: XO_STATUS
* Lock status bits
* Address: 0x150
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: xo_det_pllclk
	* Description: indicates that follower clock at output of XO to pll is detected
	* 1: Detected
	* 0: Not Detected
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoDetPllclk : 1;        /*## attribute XoDetPllclk */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: xo_det_clkin
	* Description: indicates that follower clock at clk_in is detected
	* 1: Detected
	* 0: Not Detected
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoDetClkin : 1;        /*## attribute XoDetClkin */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: xo_det_xoclk
	* Description: Indicates that crystal clock is detected
	* 1: Detected
	* 0: Not Detected
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t XoDetXoclk : 1;        /*## attribute XoDetXoclk */
}R2M0C_XoStatusBits_t;
/**
* R2M0C_MspcCalibCheckStatusBits_t
* RegisterName: MSPC_CALIB_CHECK_STATUS
* This register indicates mspc calibration status
* Address: 0x160
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 11;        /*## attribute Reserved0 */
	/**
	* BitsName: mspc_error
	* Description: MSPC calibration status
	* 
	* 0: no error
	* 1: phase calibration error is set
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcError : 1;        /*## attribute MspcError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mspc_pfd_clkin_early
	* Description: Indicates clk_in status compared to pll reference clock
	* 1: Clk_in is early compared to pll 40MHz feedback reference clock
	* 0: Clk_in is not early compared to pll 40MHz feedback reference clock
	* Read/Write: R
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcPfdClkinEarly : 1;        /*## attribute MspcPfdClkinEarly */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mspc_calib_check_busy
	* Description: Indicates the busy status of calib check 
	* 1: calibration check is active
	* 0: calibration check is inactive
	* Read/Write: R
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcCalibCheckBusy : 1;        /*## attribute MspcCalibCheckBusy */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mspc_calib_busy
	* Description: Indicates the busy status of mspc calibration 
	* 1: calibration is active
	* 0: calibration  is inactive
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcCalibBusy : 1;        /*## attribute MspcCalibBusy */
	/**
	* BitsName: mspc_calib_check_state_debug
	* Description: Indicates the calibration check state for debug
	* Read/Write: R
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcCalibCheckStateDebug : 4;        /*## attribute MspcCalibCheckStateDebug */
	/**
	* BitsName: mspc_calib_state_debug
	* Description: Indicates the calibration state for debug
	* 
	* Read/Write: R
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t MspcCalibStateDebug : 4;        /*## attribute MspcCalibStateDebug */
}R2M0C_MspcCalibCheckStatusBits_t;
/**
* R2M0C_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This register is kept for validation and not to be used in the functional context
* Address: 0x304
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_xo_det_pllclk_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskXoDetPllclkResetError : 1;        /*## attribute MaskXoDetPllclkResetError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_xo_det_clkin_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskXoDetClkinResetError : 1;        /*## attribute MaskXoDetClkinResetError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mask_mspc_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskMspcResetError : 1;        /*## attribute MaskMspcResetError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskRegCrcResetError : 1;        /*## attribute MaskRegCrcResetError */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mask_pll_vco_recalibrate_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskPllVcoRecalibrateResetError : 1;        /*## attribute MaskPllVcoRecalibrateResetError */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: mask_pll_level_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskPllLevelResetError : 1;        /*## attribute MaskPllLevelResetError */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: mask_pll_lock_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskPllLockResetError : 1;        /*## attribute MaskPllLockResetError */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: mask_xo_det_xoclk_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskXoDetXoclkResetError : 1;        /*## attribute MaskXoDetXoclkResetError */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 3;        /*## attribute Reserved7 */
	/**
	* BitsName: mask_supply_low_reset_error
	* Description: If set to 1, masks the reset_error generated by the central control towards the sensor
	* 1: mask the error getting forced
	* 0: unmask the error getting forced
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyLowResetError : 1;        /*## attribute MaskSupplyLowResetError */
}R2M0C_MaskCcResetErrorBits_t;
/**
* R2M0C_CrcErrorStatus1Bits_t
* RegisterName: CRC_ERROR_STATUS1
* Status of the CRC for each register
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
}R2M0C_CrcErrorStatus1Bits_t;
/**
* R2M0C_CrcErrorStatus2Bits_t
* RegisterName: CRC_ERROR_STATUS2
* Status of the CRC for each register
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
}R2M0C_CrcErrorStatus2Bits_t;
/**
* R2M0C_CrcErrorStatus3Bits_t
* RegisterName: CRC_ERROR_STATUS3
* Status of the CRC for each register
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
	* Note: The status corresponds to last 2 registers listed i.e registers 65(msb) down to 64(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 32;        /*## attribute CrcErrorStatusReg3 */
}R2M0C_CrcErrorStatus3Bits_t;
/**
* R2M0C_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x000C4001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000001100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
	/**
	* BitsName: major_revision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0100
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
}R2M0C_ModuleIdBits_t;
#endif
/**
* R2M0C_IrefLdoControlUnion_t
* R2M0C_IrefLdoControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_IrefLdoControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_IrefLdoControlUnion_t;

/**
* R2M0C_XoPllLdoControlUnion_t
* R2M0C_XoPllLdoControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_XoPllLdoControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_XoPllLdoControlUnion_t;

/**
* R2M0C_McLdoControlUnion_t
* R2M0C_McLdoControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_McLdoControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_McLdoControlUnion_t;

/**
* R2M0C_TrimSettingsUnion_t
* R2M0C_TrimSettingsUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_TrimSettingsBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_TrimSettingsUnion_t;

/**
* R2M0C_XoPllMcLdoEnableUnion_t
* R2M0C_XoPllMcLdoEnableUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_XoPllMcLdoEnableBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_XoPllMcLdoEnableUnion_t;

/**
* R2M0C_IbiasControlUnion_t
* R2M0C_IbiasControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_IbiasControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_IbiasControlUnion_t;

/**
* R2M0C_PfdControlUnion_t
* R2M0C_PfdControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_PfdControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_PfdControlUnion_t;

/**
* R2M0C_CpControlUnion_t
* R2M0C_CpControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_CpControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_CpControlUnion_t;

/**
* R2M0C_ClockDelaySkewControlUnion_t
* R2M0C_ClockDelaySkewControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_ClockDelaySkewControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_ClockDelaySkewControlUnion_t;

/**
* R2M0C_LoopFilterControlUnion_t
* R2M0C_LoopFilterControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_LoopFilterControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_LoopFilterControlUnion_t;

/**
* R2M0C_LockControlUnion_t
* R2M0C_LockControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_LockControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_LockControlUnion_t;

/**
* R2M0C_XoBufferControlUnion_t
* R2M0C_XoBufferControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_XoBufferControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_XoBufferControlUnion_t;

/**
* R2M0C_ClockBufferControlUnion_t
* R2M0C_ClockBufferControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_ClockBufferControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_ClockBufferControlUnion_t;

/**
* R2M0C_ClockGateControlUnion_t
* R2M0C_ClockGateControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_ClockGateControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_ClockGateControlUnion_t;

/**
* R2M0C_ClkselUnion_t
* R2M0C_ClkselUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_ClkselBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_ClkselUnion_t;

/**
* R2M0C_CalibrationAfcControl5Union_t
* R2M0C_CalibrationAfcControl5Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_CalibrationAfcControl5Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_CalibrationAfcControl5Union_t;

/**
* R2M0C_ClkDetEnConfigUnion_t
* R2M0C_ClkDetEnConfigUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_ClkDetEnConfigBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_ClkDetEnConfigUnion_t;

/**
* R2M0C_MspcControl1Union_t
* R2M0C_MspcControl1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_MspcControl1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_MspcControl1Union_t;

/**
* R2M0C_MspcControl2Union_t
* R2M0C_MspcControl2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_MspcControl2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_MspcControl2Union_t;

/**
* R2M0C_MspcControl3Union_t
* R2M0C_MspcControl3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_MspcControl3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_MspcControl3Union_t;

/**
* R2M0C_MspcTrimSettingsUnion_t
* R2M0C_MspcTrimSettingsUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_MspcTrimSettingsBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_MspcTrimSettingsUnion_t;

/**
* R2M0C_VcoControlUnion_t
* R2M0C_VcoControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_VcoControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_VcoControlUnion_t;

/**
* R2M0C_StartCalibrationUnion_t
* R2M0C_StartCalibrationUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_StartCalibrationBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_StartCalibrationUnion_t;

/**
* R2M0C_ResetCalibrationUnion_t
* R2M0C_ResetCalibrationUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_ResetCalibrationBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_ResetCalibrationUnion_t;

/**
* R2M0C_SnsControlUnion_t
* R2M0C_SnsControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_SnsControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_SnsControlUnion_t;

/**
* R2M0C_CalibrationStatus1Union_t
* R2M0C_CalibrationStatus1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_CalibrationStatus1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_CalibrationStatus1Union_t;

/**
* R2M0C_CalibrationStatus2Union_t
* R2M0C_CalibrationStatus2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_CalibrationStatus2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_CalibrationStatus2Union_t;

/**
* R2M0C_CalibrationStatus3Union_t
* R2M0C_CalibrationStatus3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_CalibrationStatus3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_CalibrationStatus3Union_t;

/**
* R2M0C_XoStatusUnion_t
* R2M0C_XoStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_XoStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_XoStatusUnion_t;

/**
* R2M0C_MspcCalibCheckStatusUnion_t
* R2M0C_MspcCalibCheckStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_MspcCalibCheckStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_MspcCalibCheckStatusUnion_t;

/**
* R2M0C_MaskCcResetErrorUnion_t
* R2M0C_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_MaskCcResetErrorUnion_t;

/**
* R2M0C_CrcErrorStatus1Union_t
* R2M0C_CrcErrorStatus1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_CrcErrorStatus1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_CrcErrorStatus1Union_t;

/**
* R2M0C_CrcErrorStatus2Union_t
* R2M0C_CrcErrorStatus2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_CrcErrorStatus2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_CrcErrorStatus2Union_t;

/**
* R2M0C_CrcErrorStatus3Union_t
* R2M0C_CrcErrorStatus3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_CrcErrorStatus3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_CrcErrorStatus3Union_t;

/**
* R2M0C_ModuleIdUnion_t
* R2M0C_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0C_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0C_ModuleIdUnion_t;


#endif
