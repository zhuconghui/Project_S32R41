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
* @reg_es2_gldo.h
*/
#ifndef REG_ES2_GLDO_H
#define REG_ES2_GLDO_H
#include <stdint.h>
/**
* R2M15_GLDO1V1_SNS_LOW_TOP_CONTROL_U16
* RegisterName: MOD15_GLDO1V1_SNS_LOW_TOP_CONTROL
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x00000000
*/
#define R2M15_GLDO1V1_SNS_LOW_TOP_CONTROL_U16 (uint16_t)0x0000
/**
* R2M15_GLDO1V1_SNS_HIGH_TOP_CONTROL_U16
* RegisterName: MOD15_GLDO1V1_SNS_HIGH_TOP_CONTROL
* AccessMode: RW
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x00000000
*/
#define R2M15_GLDO1V1_SNS_HIGH_TOP_CONTROL_U16 (uint16_t)0x0008
/**
* R2M15_GLDO1V8_SNS_LOW_TOP_CONTROL_U16
* RegisterName: MOD15_GLDO1V8_SNS_LOW_TOP_CONTROL
* AccessMode: RW
* AddressRange: 0x0010 - 0x0014
* ResetValue: 0x00000000
*/
#define R2M15_GLDO1V8_SNS_LOW_TOP_CONTROL_U16 (uint16_t)0x0010
/**
* R2M15_GLDO1V8_SNS_HIGH_TOP_CONTROL_U16
* RegisterName: MOD15_GLDO1V8_SNS_HIGH_TOP_CONTROL
* AccessMode: RW
* AddressRange: 0x0018 - 0x001C
* ResetValue: 0x00000000
*/
#define R2M15_GLDO1V8_SNS_HIGH_TOP_CONTROL_U16 (uint16_t)0x0018
/**
* R2M15_GLDO_BG_REF_CONFIG_U16
* RegisterName: MOD15_GLDO_BG_REF_CONFIG
* AccessMode: RW
* AddressRange: 0x0020 - 0x0024
* ResetValue: 0x00000000
*/
#define R2M15_GLDO_BG_REF_CONFIG_U16 (uint16_t)0x0020
/**
* R2M15_GLDO_BG_REF_CONFIG1_EXT_U16
* RegisterName: MOD15_GLDO_BG_REF_CONFIG1_EXT
* AccessMode: RW
* AddressRange: 0x0024 - 0x0028
* ResetValue: 0x00000044
*/
#define R2M15_GLDO_BG_REF_CONFIG1_EXT_U16 (uint16_t)0x0024
/**
* R2M15_GLDO_BG_REF_CONFIG2_EXT_U16
* RegisterName: MOD15_GLDO_BG_REF_CONFIG2_EXT
* AccessMode: RW
* AddressRange: 0x0028 - 0x002C
* ResetValue: 0x00003F3F
*/
#define R2M15_GLDO_BG_REF_CONFIG2_EXT_U16 (uint16_t)0x0028
/**
* R2M15_GLDO1V1_1V8_SNS_LOW_HIGH_THRESHOLD_CONFIG_U16
* RegisterName: MOD15_GLDO1V1_1V8_SNS_LOW_HIGH_THRESHOLD_CONFIG
* AccessMode: RW
* AddressRange: 0x002C - 0x0030
* ResetValue: 0x00000000
*/
#define R2M15_GLDO1V1_1V8_SNS_LOW_HIGH_THRESHOLD_CONFIG_U16 (uint16_t)0x002C
/**
* R2M15_GLDO1V8_SNS_LOW_CAL_REG_U16
* RegisterName: MOD15_GLDO1V8_SNS_LOW_CAL_REG
* AccessMode: RW
* AddressRange: 0x0030 - 0x0034
* ResetValue: 0x0000003F
*/
#define R2M15_GLDO1V8_SNS_LOW_CAL_REG_U16 (uint16_t)0x0030
/**
* R2M15_GLDO1V8_SNS_HIGH_CAL_REG_U16
* RegisterName: MOD15_GLDO1V8_SNS_HIGH_CAL_REG
* AccessMode: RW
* AddressRange: 0x0034 - 0x0038
* ResetValue: 0x0000003F
*/
#define R2M15_GLDO1V8_SNS_HIGH_CAL_REG_U16 (uint16_t)0x0034
/**
* R2M15_GLDO1V1_SNS_LOW_CAL_REG_U16
* RegisterName: MOD15_GLDO1V1_SNS_LOW_CAL_REG
* AccessMode: RW
* AddressRange: 0x0038 - 0x003C
* ResetValue: 0x0000003F
*/
#define R2M15_GLDO1V1_SNS_LOW_CAL_REG_U16 (uint16_t)0x0038
/**
* R2M15_GLDO1V1_SNS_HIGH_CAL_REG_U16
* RegisterName: MOD15_GLDO1V1_SNS_HIGH_CAL_REG
* AccessMode: RW
* AddressRange: 0x003C - 0x0040
* ResetValue: 0x0000003F
*/
#define R2M15_GLDO1V1_SNS_HIGH_CAL_REG_U16 (uint16_t)0x003C
/**
* R2M15_GLDO_OVUV_DEGLITCH_CONTROL_U16
* RegisterName: MOD15_GLDO_OVUV_DEGLITCH_CONTROL
* AccessMode: RW
* AddressRange: 0x0044 - 0x0048
* ResetValue: 0x04040404
*/
#define R2M15_GLDO_OVUV_DEGLITCH_CONTROL_U16 (uint16_t)0x0044
/**
* R2M15_GLDO_BG_REF_STATUS_U16
* RegisterName: MOD15_GLDO_BG_REF_STATUS
* AccessMode: R
* AddressRange: 0x0094 - 0x0098
* ResetValue: 0x00000111
*/
#define R2M15_GLDO_BG_REF_STATUS_U16 (uint16_t)0x0094
/**
* R2M15_TEST_ERROR_FLAG_STATUS_U16
* RegisterName: MOD15_TEST_ERROR_FLAG_STATUS
* AccessMode: RW
* AddressRange: 0x0108 - 0x010C
* ResetValue: 0x00000000
*/
#define R2M15_TEST_ERROR_FLAG_STATUS_U16 (uint16_t)0x0108
/**
* R2M15_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD15_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0204 - 0x0208
* ResetValue: 0x00000000
*/
#define R2M15_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0204
/**
* R2M15_SNS_INTEGRITY_TEST_REG_U16
* RegisterName: MOD15_SNS_INTEGRITY_TEST_REG
* AccessMode: RW
* AddressRange: 0x020C - 0x0210
* ResetValue: 0x00000000
*/
#define R2M15_SNS_INTEGRITY_TEST_REG_U16 (uint16_t)0x020C
/**
* R2M15_CRC_ERROR_STATUS1_U16
* RegisterName: MOD15_CRC_ERROR_STATUS1
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M15_CRC_ERROR_STATUS1_U16 (uint16_t)0x0F40
/**
* R2M15_CRC_ERROR_STATUS2_U16
* RegisterName: MOD15_CRC_ERROR_STATUS2
* AccessMode: R
* AddressRange: 0x0F44 - 0x0F48
* ResetValue: 0x00000000
*/
#define R2M15_CRC_ERROR_STATUS2_U16 (uint16_t)0x0F44
/**
* R2M15_MODULE_ID_U16
* RegisterName: MOD15_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x00154001
*/
#define R2M15_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M15_Gldo1V1SnsLowTopControlBits_t
* RegisterName: GLDO1V1_SNS_LOW_TOP_CONTROL
* 1V1 supply low monitor (SM) control
* Address: 0x000
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: sns_1v1_low_reset
	* Description: Reset (high) signal of LDO SM
	* 0: No action
	* 1: Reset is applied 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V1LowReset : 1;        /*## attribute Sns1V1LowReset */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v1_low_pd
	* Description: Power down supply low monitor (SM)
	* 0: Normal operation
	* 1: Supply monitor (SM) powered down
	* note: SNS_LOW and SNS_HIGH both should be in the same state
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V1LowPd : 1;        /*## attribute Sns1V1LowPd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M15_Gldo1V1SnsLowTopControlBits_t;
/**
* R2M15_Gldo1V1SnsHighTopControlBits_t
* RegisterName: GLDO1V1_SNS_HIGH_TOP_CONTROL
* 1V1 supply high  sensor control
* Address: 0x008
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: sns_1v1_high_reset
	* Description: Reset (high) signal of LDO SM
	* 0: No action
	* 1: Reset is applied 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V1HighReset : 1;        /*## attribute Sns1V1HighReset */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v1_high_pd
	* Description: Power down supply low monitor (SM)
	* 0: Normal operation
	* 1: Supply monitor powered down
	* note: SNS_LOW and SNS_HIGH both should be in the same state
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V1HighPd : 1;        /*## attribute Sns1V1HighPd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M15_Gldo1V1SnsHighTopControlBits_t;
/**
* R2M15_Gldo1V8SnsLowTopControlBits_t
* RegisterName: GLDO1V8_SNS_LOW_TOP_CONTROL
* 1V8 supply low  sensor control
* Address: 0x010
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: sns_1v8_low_reset
	* Description: Reset (high) signal of LDO SM
	* 0: No action
	* 1: Reset is applied 
	* 
	* Set this bit to '0' for this insatance.. Other values are not permited
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V8LowReset : 1;        /*## attribute Sns1V8LowReset */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v8_low_pd
	* Description: Power down supply low monitor (SM)
	* 0: Normal operation
	* 1: Supply monitor powered down
	* 
	* Set this bit to '0' for this insatance.. Other values are not permited
	* note: SNS_LOW can only work when SNS_HIGH is in normal operation
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V8LowPd : 1;        /*## attribute Sns1V8LowPd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M15_Gldo1V8SnsLowTopControlBits_t;
/**
* R2M15_Gldo1V8SnsHighTopControlBits_t
* RegisterName: GLDO1V8_SNS_HIGH_TOP_CONTROL
* 1V8 supply high  sensor control
* Address: 0x018
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: sns_1v8_high_reset
	* Description: Reset (high) signal of LDO SM
	* 0: No action
	* 1: Reset is applied 
	* 
	* Set this bit to '0' for this insatance.. Other values are not permited
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V8HighReset : 1;        /*## attribute Sns1V8HighReset */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v8_high_pd
	* Description: Power down supply low monitor (SM)
	* 0: Normal operation
	* 1: Supply monitor powered down
	* 
	* Set this bit to '0' for this insatance.. Other values are not permited
	* note: SNS_LOW can only work when SNS_HIGH is in normal operation
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V8HighPd : 1;        /*## attribute Sns1V8HighPd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M15_Gldo1V8SnsHighTopControlBits_t;
/**
* R2M15_GldoBgRefConfigBits_t
* RegisterName: GLDO_BG_REF_CONFIG
* Global LDO reference settings. sel_vref should be '1' to get the calibrated supply voltages
* Address: 0x020
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: sel_vref
	* Description: Reset value set to 0 to select noisy bangap voltage reference for safe start-up.
	* 0:  internal BG is used ( may be more noisy)
	* 1: Calibarated low-noise refernce is used
	* 
	* As part of start up procedure this bit is set to '1'to ensure low noise performance of the supply
	* 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t SelVref : 1;        /*## attribute SelVref */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M15_GldoBgRefConfigBits_t;
/**
* R2M15_GldoBgRefConfig1ExtBits_t
* RegisterName: GLDO_BG_REF_CONFIG1_EXT
* External Low Noise reference settings to compensate for temp coefficient. Temperature curvature correction value for LDO. Setting from OTP.
* Address: 0x024
* ResetValue: 0x00000044
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ref_ldo1v1_set_curve
	* Description: 
	* 
	* Reset value is set to the middle of the control range for low-noise reference to start with zero Temperature Coefficient in silicon.
	* Set this to value  always to "100" in an application context
	* 
	* 
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b100
	* Source: OTP
	* FuSa: No
	*/
	uint32_t RefLdo1V1SetCurve : 3;        /*## attribute RefLdo1V1SetCurve */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ref_ldo1v8_set_curve
	* Description: 
	* 
	* Reset value is set to the middle of the control range for low-noise reference to start with zero Temperature Coefficient in silicon.
	* Set this to value  always to "100" in an application context
	* 
	* 
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b100
	* Source: OTP
	* FuSa: No
	*/
	uint32_t RefLdo1V8SetCurve : 3;        /*## attribute RefLdo1V8SetCurve */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 25;        /*## attribute Reserved1 */
}R2M15_GldoBgRefConfig1ExtBits_t;
/**
* R2M15_GldoBgRefConfig2ExtBits_t
* RegisterName: GLDO_BG_REF_CONFIG2_EXT
* External Low Noise reference settings. The calibrated values from OTP to be copied to this register
* Address: 0x028
* ResetValue: 0x00003F3F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ref_ldo1v1_set_dc
	* Description: Reset value is set to the middle of the control range for low-noise reference to start nominally at 900mV in case of sel_vref  toggles by accident before calibrating ref_set_dc.
	* 
	* Trim code 7b0000000 leads to maximum value and 7b1111111 to minimum value of ref0v9 output voltage. Trimming step size depends on set_curve[2:0] and varies from 5mV (set_curve=7) to 7.8mV (set_curve=0) at nominal corner. The default dc trim step size at set_curve=4 is 6mV at nominal corner.
	* 
	* As part of calibration this value is replaced with a calibrated value from OTP (ref_set_dc is form OTP ( 0x3C bits 31..25))
	* 
	* Note1: . A 6mV step with the ref_set_dc (*) leads to 7.33mV step in 1v1.
	* Note that higher code leads to lower output voltage.
	* 
	* 
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t RefLdo1V1SetDc : 7;        /*## attribute RefLdo1V1SetDc */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ref_ldo1v8_set_dc
	* Description: Reset value is set to the middle of the control range for low-noise reference to start nominally at 900mV in case of sel_vref  toggles by accident before calibrating ref_set_dc.
	* 
	* Trim code 7b0000000 leads to maximum value and 7b1111111 to minimum value of ref0v9 output voltage. Trimming step size depends on set_curve[2:0] and varies from 5mV (set_curve=7) to 7.8mV (set_curve=0) at nominal corner. The default dc trim step size at set_curve=4 is 6mV at nominal corner.
	* 
	* As part of calibration this value is replaced with a calibrated value from OTP (ref_set_dc is form OTP ( 0x3C bits 31..25))
	* 
	* Note1: . A 6mV step with the ref_set_dc (*) leads to 12mV step in the 1v8 
	* Note that higher code leads to lower output voltage.
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [14:8]
	* ResetValue: 0b0111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t RefLdo1V8SetDc : 7;        /*## attribute RefLdo1V8SetDc */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 17;        /*## attribute Reserved1 */
}R2M15_GldoBgRefConfig2ExtBits_t;
/**
* R2M15_Gldo1V11V8SnsLowHighThresholdConfigBits_t
* RegisterName: GLDO1V1_1V8_SNS_LOW_HIGH_THRESHOLD_CONFIG
* 1V1 and 1V8 supply Low/High Threshold sensor configuration. The values to be copied from OTP
* selects supply high/low threshold (coarse setting):
* thresh_sel<1:0> = 00 => minimum change required to trigger detect signal
* thresh_sel<1:0> = 11 => maximum change required to trigger detect signal
* Value to be trimmed during testing and read from OTP before operation.
* Address: 0x02C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: sns_1v1_low_thresh_sel
	* Description: selects supply low threshold (coarse setting):
	* thresh_sel<1:0> = 00 => +10% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 01 => +5% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 10 => +0% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 11 => -5% of Vmon will trigger dip detect signal
	* 
	* Value to be trimmed during testing.
	* 
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Sns1V1LowThreshSel : 2;        /*## attribute Sns1V1LowThreshSel */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v1_high_thresh_sel
	* Description: selects supply high threshold (coarse setting):
	* thresh_sel<1:0> = 00 => +5% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 01 => +10% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 10 => +15% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 11 => +20% of Vmon will trigger peak detect signal
	* 
	* Value to be trimmed during testing.
	* 
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Sns1V1HighThreshSel : 2;        /*## attribute Sns1V1HighThreshSel */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: sns_1v8_low_thresh_sel
	* Description: selects supply low  threshold (coarse setting):
	* thresh_sel<1:0> = 00 => +10% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 01 => +5% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 10 => +0% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 11 => -5% of Vmon will trigger dip detect signal
	* 
	* Value to be trimmed during testing.
	* 
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Sns1V8LowThreshSel : 2;        /*## attribute Sns1V8LowThreshSel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: sns_1v8_high_thresh_sel
	* Description: selects supply high threshold (coarse setting):
	* thresh_sel<1:0> = 00 => +5% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 01 => +10% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 10 => +15% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 11 => +20% of Vmon will trigger peak detect signal
	* 
	* Value to be trimmed during testing.
	* 
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Sns1V8HighThreshSel : 2;        /*## attribute Sns1V8HighThreshSel */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 18;        /*## attribute Reserved3 */
}R2M15_Gldo1V11V8SnsLowHighThresholdConfigBits_t;
/**
* R2M15_Gldo1V8SnsLowCalRegBits_t
* RegisterName: GLDO1V8_SNS_LOW_CAL_REG
* This register is used to tune the threshold voltage. Value to be used comes from OTP
* Address: 0x030
* ResetValue: 0x0000003F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: gldo1v8_sns_low_cal
	* Description: Select 1.8V low supply monitor (SM) threshold (fine setting)
	* Value to be trimmed during testing and read from OTP before operation, sets dip supply threshold to -3%
	* The register value is converted into corresponding one hot encoded value.
	* Trim code 6b000000 leads to maximum value and 6b111111 to minimum value
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Gldo1V8SnsLowCal : 6;        /*## attribute Gldo1V8SnsLowCal */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M15_Gldo1V8SnsLowCalRegBits_t;
/**
* R2M15_Gldo1V8SnsHighCalRegBits_t
* RegisterName: GLDO1V8_SNS_HIGH_CAL_REG
* This register is used to tune the threshold voltage. Value to be used comes from OTP
* Address: 0x034
* ResetValue: 0x0000003F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: gldo1v8_sns_high_cal
	* Description: Select 1.8V high supply monitor (SM) threshold (fine setting)
	* Value to be trimmed during testing and read from OTP before operation, sets dip supply threshold to -3%
	* The register value is converted into corresponding one hot encoded value.
	* Trim code 6b000000 leads to maximum value and 6b111111 to minimum value
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Gldo1V8SnsHighCal : 6;        /*## attribute Gldo1V8SnsHighCal */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M15_Gldo1V8SnsHighCalRegBits_t;
/**
* R2M15_Gldo1V1SnsLowCalRegBits_t
* RegisterName: GLDO1V1_SNS_LOW_CAL_REG
* This register is used to tune the threshold voltage. Value to be used comes from OTP
* Address: 0x038
* ResetValue: 0x0000003F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: gldo1v1_sns_low_cal
	* Description: Select 1.1V low supply monitor (SM) threshold (fine setting)
	* Value to be trimmed during testing and read from OTP before operation, sets dip supply threshold to -3%
	* The register value is converted into corresponding one hot encoded value.
	* Trim code 6b000000 leads to maximum value and 6b111111 to minimum value
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Gldo1V1SnsLowCal : 6;        /*## attribute Gldo1V1SnsLowCal */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M15_Gldo1V1SnsLowCalRegBits_t;
/**
* R2M15_Gldo1V1SnsHighCalRegBits_t
* RegisterName: GLDO1V1_SNS_HIGH_CAL_REG
* This register is used to tune the threshold voltage. Value to be used comes from OTP
* Address: 0x03C
* ResetValue: 0x0000003F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: gldo1v1_sns_high_cal
	* Description: Select 1.1V high supply monitor (SM) threshold (fine setting)
	* Value to be trimmed during testing and read from OTP before operation, sets dip supply threshold to -3%
	* The register value is converted into corresponding one hot encoded value.
	* Trim code 6b000000 leads to maximum value and 6b111111 to minimum value
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Gldo1V1SnsHighCal : 6;        /*## attribute Gldo1V1SnsHighCal */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M15_Gldo1V1SnsHighCalRegBits_t;
/**
* R2M15_GldoOvuvDeglitchControlBits_t
* RegisterName: GLDO_OVUV_DEGLITCH_CONTROL
* Deglitch control to eliminate spurious Over Voltage and Under Voltage conditions for 1V1 and 1V8 supply
* Address: 0x044
* ResetValue: 0x04040404
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: supply_1v1_low_deglitch_threshold
	* Description: 
	* 
	* Selects the pulse width (counted with 25 ns/40Mhz clock), for the 1v1 supply low condition. The supply staying high equal to or greater than this pulse width, triggers the 1V1 low error. Value 1 corresponds to 25 ns pulse width
	* 
	* 'd1 : 1 * 25 ns 
	* 'd2 : 2 * 25 ns
	* ...............
	* 'd255: 255 * 25 ns
	* 
	* 
	* 
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Supply1V1LowDeglitchThreshold : 8;        /*## attribute Supply1V1LowDeglitchThreshold */
	/**
	* BitsName: supply_1v1_high_deglitch_threshold
	* Description: 
	* 
	* Selects the pulse width (counted with 25 ns/40Mhz clock), for the 1v1 supply high condition. The supply staying high equal to or greater than this pulse width, triggers the 1V1 high error. Value 1 corresponds to 25 ns pulse width
	* 
	* 'd1 : 1 * 25 ns 
	* 'd2 : 2 * 25 ns
	* ...............
	* 'd255: 255 * 25 ns
	* 
	* 
	* 
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Supply1V1HighDeglitchThreshold : 8;        /*## attribute Supply1V1HighDeglitchThreshold */
	/**
	* BitsName: supply_1v8_low_deglitch_threshold
	* Description: 
	* 
	* Selects the pulse width (counted with 25 ns/40Mhz clock), for the 1v8 supply low condition. The supply staying low equal to or greater than this pulse width, triggers the 1V8 low error. Value 1 corresponds to 25 ns pulse width
	* 
	* 'd1 : 1 * 25 ns 
	* 'd2 : 2 * 25 ns
	* ...............
	* 'd255: 255 * 25 ns
	* 
	* 
	* 
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Supply1V8LowDeglitchThreshold : 8;        /*## attribute Supply1V8LowDeglitchThreshold */
	/**
	* BitsName: supply_1v8_high_deglitch_threshold
	* Description: 
	* 
	* Selects the pulse width (counted with 25 ns/40Mhz clock), for the 1v8 supply high condition. The supply staying low equal to or greater than this pulse width, triggers the 1V8 high error. Value 1 corresponds to 25 ns pulse width
	* 
	* 'd1 : 1 * 25 ns 
	* 'd2 : 2 * 25 ns
	* ...............
	* 'd255: 255 * 25 ns
	* 
	* 
	* 
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [31:24]
	* ResetValue: 0b00000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Supply1V8HighDeglitchThreshold : 8;        /*## attribute Supply1V8HighDeglitchThreshold */
}R2M15_GldoOvuvDeglitchControlBits_t;
/**
* R2M15_GldoBgRefStatusBits_t
* RegisterName: GLDO_BG_REF_STATUS
* Global LDO reference status checK
* Address: 0x094
* ResetValue: 0x00000111
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: bg_ok
	* Description: Band gap  setting OK
	* 0: Nok OK
	* 1: OK
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BgOk : 1;        /*## attribute BgOk */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: ref_ldo1v1_ok
	* Description: Reference 1V1 OK
	* 0: Nok OK
	* 1: OK
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RefLdo1V1Ok : 1;        /*## attribute RefLdo1V1Ok */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ref_ldo1v8_ok
	* Description: Reference 1V8 OK
	* 0: Nok OK
	* 1: OK
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RefLdo1V8Ok : 1;        /*## attribute RefLdo1V8Ok */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 23;        /*## attribute Reserved2 */
}R2M15_GldoBgRefStatusBits_t;
/**
* R2M15_TestErrorFlagStatusBits_t
* RegisterName: TEST_ERROR_FLAG_STATUS
* Registers for validation purposes. 
* Address: 0x108
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: supply_1v1_low_error_flag
	* Description: 1V1 LOW supply monitor (SM) error flag.
	* 
	* When Read
	* 0 = No error from Analogue Module
	* 1 = Error set from Analogue Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Supply1V1LowErrorFlag : 1;        /*## attribute Supply1V1LowErrorFlag */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: supply_1v1_high_error_flag
	* Description: 1V1 high supply monitor (SM) error flag.
	* 
	* When Read
	* 0 = No error from Analogue Module
	* 1 = Error set from Analogue Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Supply1V1HighErrorFlag : 1;        /*## attribute Supply1V1HighErrorFlag */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: supply_1v8_low_error_flag
	* Description: 1V8 LOW supply monitor (SM) error flag.
	* 
	* When Read
	* 0 = No error from Analogue Module
	* 1 = Error set from Analogue Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Supply1V8LowErrorFlag : 1;        /*## attribute Supply1V8LowErrorFlag */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: supply_1v8_high_error_flag
	* Description: 1V8 high supply monitor (SM) error flag.
	* 
	* When Read
	* 0 = No error from Analogue Module
	* 1 = Error set from Analogue Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Supply1V8HighErrorFlag : 1;        /*## attribute Supply1V8HighErrorFlag */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: reg_crc_error_flag
	* Description: reg crc error flag.
	* 
	* When Read
	* 0 = No error from crc Module
	* 1 = Error set from crc Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t RegCrcErrorFlag : 1;        /*## attribute RegCrcErrorFlag */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 15;        /*## attribute Reserved4 */
}R2M15_TestErrorFlagStatusBits_t;
/**
* R2M15_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* nan
* Address: 0x204
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_supply_1v1_low_reset_error
	* Description: Mask for 1V1 LOW reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V1LowResetError : 1;        /*## attribute MaskSupply1V1LowResetError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_supply_1v1_high_reset_error
	* Description: Mask for 1V1 high reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V1HighResetError : 1;        /*## attribute MaskSupply1V1HighResetError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mask_supply_1v8_low_reset_error
	* Description: Mask for 1V8 LOW reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V8LowResetError : 1;        /*## attribute MaskSupply1V8LowResetError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_supply_1v8_high_reset_error
	* Description: Mask for 1V8 high reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V8HighResetError : 1;        /*## attribute MaskSupply1V8HighResetError */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: Reg crc reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskRegCrcResetError : 1;        /*## attribute MaskRegCrcResetError */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 15;        /*## attribute Reserved4 */
}R2M15_MaskCcResetErrorBits_t;
/**
* R2M15_SnsIntegrityTestRegBits_t
* RegisterName: SNS_INTEGRITY_TEST_REG
* This register is used to inject fault in the Analog sensor
* Address: 0x20C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: sns_integrity_supply_1vX_reset_error
	* Description: Reset error to all 4 supply monitors: 1v8_high, 1v8_low, 1v1_high and 1v1_low
	* Note: Reset error from ISM is required to clear the flag; the local reset error is ONLY for removing the Analog fault; ISM reset_error is required from ISM since the latch is part of the digital logic
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t SnsIntegritySupply1VxResetError : 1;        /*## attribute SnsIntegritySupply1VxResetError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_integrity_supply_1vX_force_error
	* Description: Force error to all 4 supply monitors: 1v8_high, 1v8_low, 1v1_high, 1v1_low
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t SnsIntegritySupply1VxForceError : 1;        /*## attribute SnsIntegritySupply1VxForceError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M15_SnsIntegrityTestRegBits_t;
/**
* R2M15_CrcErrorStatus1Bits_t
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
}R2M15_CrcErrorStatus1Bits_t;
/**
* R2M15_CrcErrorStatus2Bits_t
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
	* Note: The status corresponds to last 4 registers listed i.e registers 35(msb) down to 32(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 32;        /*## attribute CrcErrorStatusReg2 */
}R2M15_CrcErrorStatus2Bits_t;
/**
* R2M15_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00154001
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
	* BitsName: minor_rivision
	* Description: Minor revision number i.e. with no software consequences
	* Read/Write: R
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MinorRivision : 4;        /*## attribute MinorRivision */
	/**
	* BitsName: major_rivision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRivision : 4;        /*## attribute MajorRivision */
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000010101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M15_ModuleIdBits_t;

 #else
/**
* R2M15_Gldo1V1SnsLowTopControlBits_t
* RegisterName: GLDO1V1_SNS_LOW_TOP_CONTROL
* 1V1 supply low monitor (SM) control
* Address: 0x000
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v1_low_pd
	* Description: Power down supply low monitor (SM)
	* 0: Normal operation
	* 1: Supply monitor (SM) powered down
	* note: SNS_LOW and SNS_HIGH both should be in the same state
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V1LowPd : 1;        /*## attribute Sns1V1LowPd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: sns_1v1_low_reset
	* Description: Reset (high) signal of LDO SM
	* 0: No action
	* 1: Reset is applied 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V1LowReset : 1;        /*## attribute Sns1V1LowReset */
}R2M15_Gldo1V1SnsLowTopControlBits_t;
/**
* R2M15_Gldo1V1SnsHighTopControlBits_t
* RegisterName: GLDO1V1_SNS_HIGH_TOP_CONTROL
* 1V1 supply high  sensor control
* Address: 0x008
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v1_high_pd
	* Description: Power down supply low monitor (SM)
	* 0: Normal operation
	* 1: Supply monitor powered down
	* note: SNS_LOW and SNS_HIGH both should be in the same state
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V1HighPd : 1;        /*## attribute Sns1V1HighPd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: sns_1v1_high_reset
	* Description: Reset (high) signal of LDO SM
	* 0: No action
	* 1: Reset is applied 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V1HighReset : 1;        /*## attribute Sns1V1HighReset */
}R2M15_Gldo1V1SnsHighTopControlBits_t;
/**
* R2M15_Gldo1V8SnsLowTopControlBits_t
* RegisterName: GLDO1V8_SNS_LOW_TOP_CONTROL
* 1V8 supply low  sensor control
* Address: 0x010
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v8_low_pd
	* Description: Power down supply low monitor (SM)
	* 0: Normal operation
	* 1: Supply monitor powered down
	* 
	* Set this bit to '0' for this insatance.. Other values are not permited
	* note: SNS_LOW can only work when SNS_HIGH is in normal operation
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V8LowPd : 1;        /*## attribute Sns1V8LowPd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: sns_1v8_low_reset
	* Description: Reset (high) signal of LDO SM
	* 0: No action
	* 1: Reset is applied 
	* 
	* Set this bit to '0' for this insatance.. Other values are not permited
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V8LowReset : 1;        /*## attribute Sns1V8LowReset */
}R2M15_Gldo1V8SnsLowTopControlBits_t;
/**
* R2M15_Gldo1V8SnsHighTopControlBits_t
* RegisterName: GLDO1V8_SNS_HIGH_TOP_CONTROL
* 1V8 supply high  sensor control
* Address: 0x018
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v8_high_pd
	* Description: Power down supply low monitor (SM)
	* 0: Normal operation
	* 1: Supply monitor powered down
	* 
	* Set this bit to '0' for this insatance.. Other values are not permited
	* note: SNS_LOW can only work when SNS_HIGH is in normal operation
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V8HighPd : 1;        /*## attribute Sns1V8HighPd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: sns_1v8_high_reset
	* Description: Reset (high) signal of LDO SM
	* 0: No action
	* 1: Reset is applied 
	* 
	* Set this bit to '0' for this insatance.. Other values are not permited
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Sns1V8HighReset : 1;        /*## attribute Sns1V8HighReset */
}R2M15_Gldo1V8SnsHighTopControlBits_t;
/**
* R2M15_GldoBgRefConfigBits_t
* RegisterName: GLDO_BG_REF_CONFIG
* Global LDO reference settings. sel_vref should be '1' to get the calibrated supply voltages
* Address: 0x020
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
	* BitsName: sel_vref
	* Description: Reset value set to 0 to select noisy bangap voltage reference for safe start-up.
	* 0:  internal BG is used ( may be more noisy)
	* 1: Calibarated low-noise refernce is used
	* 
	* As part of start up procedure this bit is set to '1'to ensure low noise performance of the supply
	* 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t SelVref : 1;        /*## attribute SelVref */
}R2M15_GldoBgRefConfigBits_t;
/**
* R2M15_GldoBgRefConfig1ExtBits_t
* RegisterName: GLDO_BG_REF_CONFIG1_EXT
* External Low Noise reference settings to compensate for temp coefficient. Temperature curvature correction value for LDO. Setting from OTP.
* Address: 0x024
* ResetValue: 0x00000044
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 25;        /*## attribute Reserved0 */
	/**
	* BitsName: ref_ldo1v8_set_curve
	* Description: 
	* 
	* Reset value is set to the middle of the control range for low-noise reference to start with zero Temperature Coefficient in silicon.
	* Set this to value  always to "100" in an application context
	* 
	* 
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b100
	* Source: OTP
	* FuSa: No
	*/
	uint32_t RefLdo1V8SetCurve : 3;        /*## attribute RefLdo1V8SetCurve */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: ref_ldo1v1_set_curve
	* Description: 
	* 
	* Reset value is set to the middle of the control range for low-noise reference to start with zero Temperature Coefficient in silicon.
	* Set this to value  always to "100" in an application context
	* 
	* 
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b100
	* Source: OTP
	* FuSa: No
	*/
	uint32_t RefLdo1V1SetCurve : 3;        /*## attribute RefLdo1V1SetCurve */
}R2M15_GldoBgRefConfig1ExtBits_t;
/**
* R2M15_GldoBgRefConfig2ExtBits_t
* RegisterName: GLDO_BG_REF_CONFIG2_EXT
* External Low Noise reference settings. The calibrated values from OTP to be copied to this register
* Address: 0x028
* ResetValue: 0x00003F3F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 17;        /*## attribute Reserved0 */
	/**
	* BitsName: ref_ldo1v8_set_dc
	* Description: Reset value is set to the middle of the control range for low-noise reference to start nominally at 900mV in case of sel_vref  toggles by accident before calibrating ref_set_dc.
	* 
	* Trim code 7b0000000 leads to maximum value and 7b1111111 to minimum value of ref0v9 output voltage. Trimming step size depends on set_curve[2:0] and varies from 5mV (set_curve=7) to 7.8mV (set_curve=0) at nominal corner. The default dc trim step size at set_curve=4 is 6mV at nominal corner.
	* 
	* As part of calibration this value is replaced with a calibrated value from OTP (ref_set_dc is form OTP ( 0x3C bits 31..25))
	* 
	* Note1: . A 6mV step with the ref_set_dc (*) leads to 12mV step in the 1v8 
	* Note that higher code leads to lower output voltage.
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [14:8]
	* ResetValue: 0b0111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t RefLdo1V8SetDc : 7;        /*## attribute RefLdo1V8SetDc */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: ref_ldo1v1_set_dc
	* Description: Reset value is set to the middle of the control range for low-noise reference to start nominally at 900mV in case of sel_vref  toggles by accident before calibrating ref_set_dc.
	* 
	* Trim code 7b0000000 leads to maximum value and 7b1111111 to minimum value of ref0v9 output voltage. Trimming step size depends on set_curve[2:0] and varies from 5mV (set_curve=7) to 7.8mV (set_curve=0) at nominal corner. The default dc trim step size at set_curve=4 is 6mV at nominal corner.
	* 
	* As part of calibration this value is replaced with a calibrated value from OTP (ref_set_dc is form OTP ( 0x3C bits 31..25))
	* 
	* Note1: . A 6mV step with the ref_set_dc (*) leads to 7.33mV step in 1v1.
	* Note that higher code leads to lower output voltage.
	* 
	* 
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t RefLdo1V1SetDc : 7;        /*## attribute RefLdo1V1SetDc */
}R2M15_GldoBgRefConfig2ExtBits_t;
/**
* R2M15_Gldo1V11V8SnsLowHighThresholdConfigBits_t
* RegisterName: GLDO1V1_1V8_SNS_LOW_HIGH_THRESHOLD_CONFIG
* 1V1 and 1V8 supply Low/High Threshold sensor configuration. The values to be copied from OTP
* selects supply high/low threshold (coarse setting):
* thresh_sel<1:0> = 00 => minimum change required to trigger detect signal
* thresh_sel<1:0> = 11 => maximum change required to trigger detect signal
* Value to be trimmed during testing and read from OTP before operation.
* Address: 0x02C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 18;        /*## attribute Reserved0 */
	/**
	* BitsName: sns_1v8_high_thresh_sel
	* Description: selects supply high threshold (coarse setting):
	* thresh_sel<1:0> = 00 => +5% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 01 => +10% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 10 => +15% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 11 => +20% of Vmon will trigger peak detect signal
	* 
	* Value to be trimmed during testing.
	* 
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Sns1V8HighThreshSel : 2;        /*## attribute Sns1V8HighThreshSel */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: sns_1v8_low_thresh_sel
	* Description: selects supply low  threshold (coarse setting):
	* thresh_sel<1:0> = 00 => +10% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 01 => +5% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 10 => +0% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 11 => -5% of Vmon will trigger dip detect signal
	* 
	* Value to be trimmed during testing.
	* 
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Sns1V8LowThreshSel : 2;        /*## attribute Sns1V8LowThreshSel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: sns_1v1_high_thresh_sel
	* Description: selects supply high threshold (coarse setting):
	* thresh_sel<1:0> = 00 => +5% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 01 => +10% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 10 => +15% of Vmon will trigger peak detect signal
	* thresh_sel<1:0> = 11 => +20% of Vmon will trigger peak detect signal
	* 
	* Value to be trimmed during testing.
	* 
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Sns1V1HighThreshSel : 2;        /*## attribute Sns1V1HighThreshSel */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: sns_1v1_low_thresh_sel
	* Description: selects supply low threshold (coarse setting):
	* thresh_sel<1:0> = 00 => +10% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 01 => +5% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 10 => +0% of Vmon will trigger dip detect signal
	* thresh_sel<1:0> = 11 => -5% of Vmon will trigger dip detect signal
	* 
	* Value to be trimmed during testing.
	* 
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Sns1V1LowThreshSel : 2;        /*## attribute Sns1V1LowThreshSel */
}R2M15_Gldo1V11V8SnsLowHighThresholdConfigBits_t;
/**
* R2M15_Gldo1V8SnsLowCalRegBits_t
* RegisterName: GLDO1V8_SNS_LOW_CAL_REG
* This register is used to tune the threshold voltage. Value to be used comes from OTP
* Address: 0x030
* ResetValue: 0x0000003F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
	/**
	* BitsName: gldo1v8_sns_low_cal
	* Description: Select 1.8V low supply monitor (SM) threshold (fine setting)
	* Value to be trimmed during testing and read from OTP before operation, sets dip supply threshold to -3%
	* The register value is converted into corresponding one hot encoded value.
	* Trim code 6b000000 leads to maximum value and 6b111111 to minimum value
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Gldo1V8SnsLowCal : 6;        /*## attribute Gldo1V8SnsLowCal */
}R2M15_Gldo1V8SnsLowCalRegBits_t;
/**
* R2M15_Gldo1V8SnsHighCalRegBits_t
* RegisterName: GLDO1V8_SNS_HIGH_CAL_REG
* This register is used to tune the threshold voltage. Value to be used comes from OTP
* Address: 0x034
* ResetValue: 0x0000003F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
	/**
	* BitsName: gldo1v8_sns_high_cal
	* Description: Select 1.8V high supply monitor (SM) threshold (fine setting)
	* Value to be trimmed during testing and read from OTP before operation, sets dip supply threshold to -3%
	* The register value is converted into corresponding one hot encoded value.
	* Trim code 6b000000 leads to maximum value and 6b111111 to minimum value
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Gldo1V8SnsHighCal : 6;        /*## attribute Gldo1V8SnsHighCal */
}R2M15_Gldo1V8SnsHighCalRegBits_t;
/**
* R2M15_Gldo1V1SnsLowCalRegBits_t
* RegisterName: GLDO1V1_SNS_LOW_CAL_REG
* This register is used to tune the threshold voltage. Value to be used comes from OTP
* Address: 0x038
* ResetValue: 0x0000003F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
	/**
	* BitsName: gldo1v1_sns_low_cal
	* Description: Select 1.1V low supply monitor (SM) threshold (fine setting)
	* Value to be trimmed during testing and read from OTP before operation, sets dip supply threshold to -3%
	* The register value is converted into corresponding one hot encoded value.
	* Trim code 6b000000 leads to maximum value and 6b111111 to minimum value
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Gldo1V1SnsLowCal : 6;        /*## attribute Gldo1V1SnsLowCal */
}R2M15_Gldo1V1SnsLowCalRegBits_t;
/**
* R2M15_Gldo1V1SnsHighCalRegBits_t
* RegisterName: GLDO1V1_SNS_HIGH_CAL_REG
* This register is used to tune the threshold voltage. Value to be used comes from OTP
* Address: 0x03C
* ResetValue: 0x0000003F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
	/**
	* BitsName: gldo1v1_sns_high_cal
	* Description: Select 1.1V high supply monitor (SM) threshold (fine setting)
	* Value to be trimmed during testing and read from OTP before operation, sets dip supply threshold to -3%
	* The register value is converted into corresponding one hot encoded value.
	* Trim code 6b000000 leads to maximum value and 6b111111 to minimum value
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b111111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Gldo1V1SnsHighCal : 6;        /*## attribute Gldo1V1SnsHighCal */
}R2M15_Gldo1V1SnsHighCalRegBits_t;
/**
* R2M15_GldoOvuvDeglitchControlBits_t
* RegisterName: GLDO_OVUV_DEGLITCH_CONTROL
* Deglitch control to eliminate spurious Over Voltage and Under Voltage conditions for 1V1 and 1V8 supply
* Address: 0x044
* ResetValue: 0x04040404
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: supply_1v8_high_deglitch_threshold
	* Description: 
	* 
	* Selects the pulse width (counted with 25 ns/40Mhz clock), for the 1v8 supply high condition. The supply staying low equal to or greater than this pulse width, triggers the 1V8 high error. Value 1 corresponds to 25 ns pulse width
	* 
	* 'd1 : 1 * 25 ns 
	* 'd2 : 2 * 25 ns
	* ...............
	* 'd255: 255 * 25 ns
	* 
	* 
	* 
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [31:24]
	* ResetValue: 0b00000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Supply1V8HighDeglitchThreshold : 8;        /*## attribute Supply1V8HighDeglitchThreshold */
	/**
	* BitsName: supply_1v8_low_deglitch_threshold
	* Description: 
	* 
	* Selects the pulse width (counted with 25 ns/40Mhz clock), for the 1v8 supply low condition. The supply staying low equal to or greater than this pulse width, triggers the 1V8 low error. Value 1 corresponds to 25 ns pulse width
	* 
	* 'd1 : 1 * 25 ns 
	* 'd2 : 2 * 25 ns
	* ...............
	* 'd255: 255 * 25 ns
	* 
	* 
	* 
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Supply1V8LowDeglitchThreshold : 8;        /*## attribute Supply1V8LowDeglitchThreshold */
	/**
	* BitsName: supply_1v1_high_deglitch_threshold
	* Description: 
	* 
	* Selects the pulse width (counted with 25 ns/40Mhz clock), for the 1v1 supply high condition. The supply staying high equal to or greater than this pulse width, triggers the 1V1 high error. Value 1 corresponds to 25 ns pulse width
	* 
	* 'd1 : 1 * 25 ns 
	* 'd2 : 2 * 25 ns
	* ...............
	* 'd255: 255 * 25 ns
	* 
	* 
	* 
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Supply1V1HighDeglitchThreshold : 8;        /*## attribute Supply1V1HighDeglitchThreshold */
	/**
	* BitsName: supply_1v1_low_deglitch_threshold
	* Description: 
	* 
	* Selects the pulse width (counted with 25 ns/40Mhz clock), for the 1v1 supply low condition. The supply staying high equal to or greater than this pulse width, triggers the 1V1 low error. Value 1 corresponds to 25 ns pulse width
	* 
	* 'd1 : 1 * 25 ns 
	* 'd2 : 2 * 25 ns
	* ...............
	* 'd255: 255 * 25 ns
	* 
	* 
	* 
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Supply1V1LowDeglitchThreshold : 8;        /*## attribute Supply1V1LowDeglitchThreshold */
}R2M15_GldoOvuvDeglitchControlBits_t;
/**
* R2M15_GldoBgRefStatusBits_t
* RegisterName: GLDO_BG_REF_STATUS
* Global LDO reference status checK
* Address: 0x094
* ResetValue: 0x00000111
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
	* BitsName: ref_ldo1v8_ok
	* Description: Reference 1V8 OK
	* 0: Nok OK
	* 1: OK
	* Read/Write: R
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RefLdo1V8Ok : 1;        /*## attribute RefLdo1V8Ok */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ref_ldo1v1_ok
	* Description: Reference 1V1 OK
	* 0: Nok OK
	* 1: OK
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RefLdo1V1Ok : 1;        /*## attribute RefLdo1V1Ok */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: bg_ok
	* Description: Band gap  setting OK
	* 0: Nok OK
	* 1: OK
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BgOk : 1;        /*## attribute BgOk */
}R2M15_GldoBgRefStatusBits_t;
/**
* R2M15_TestErrorFlagStatusBits_t
* RegisterName: TEST_ERROR_FLAG_STATUS
* Registers for validation purposes. 
* Address: 0x108
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 15;        /*## attribute Reserved0 */
	/**
	* BitsName: reg_crc_error_flag
	* Description: reg crc error flag.
	* 
	* When Read
	* 0 = No error from crc Module
	* 1 = Error set from crc Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t RegCrcErrorFlag : 1;        /*## attribute RegCrcErrorFlag */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: supply_1v8_high_error_flag
	* Description: 1V8 high supply monitor (SM) error flag.
	* 
	* When Read
	* 0 = No error from Analogue Module
	* 1 = Error set from Analogue Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Supply1V8HighErrorFlag : 1;        /*## attribute Supply1V8HighErrorFlag */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: supply_1v8_low_error_flag
	* Description: 1V8 LOW supply monitor (SM) error flag.
	* 
	* When Read
	* 0 = No error from Analogue Module
	* 1 = Error set from Analogue Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Supply1V8LowErrorFlag : 1;        /*## attribute Supply1V8LowErrorFlag */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: supply_1v1_high_error_flag
	* Description: 1V1 high supply monitor (SM) error flag.
	* 
	* When Read
	* 0 = No error from Analogue Module
	* 1 = Error set from Analogue Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Supply1V1HighErrorFlag : 1;        /*## attribute Supply1V1HighErrorFlag */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: supply_1v1_low_error_flag
	* Description: 1V1 LOW supply monitor (SM) error flag.
	* 
	* When Read
	* 0 = No error from Analogue Module
	* 1 = Error set from Analogue Module
	* 
	* Write
	* 0 = No error set to Inner Safety Monitor
	* 1 = Error set to Inner Safety Monitor
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Supply1V1LowErrorFlag : 1;        /*## attribute Supply1V1LowErrorFlag */
}R2M15_TestErrorFlagStatusBits_t;
/**
* R2M15_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* nan
* Address: 0x204
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
	* BitsName: mask_reg_crc_reset_error
	* Description: Reg crc reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [16]
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
	* BitsName: mask_supply_1v8_high_reset_error
	* Description: Mask for 1V8 high reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V8HighResetError : 1;        /*## attribute MaskSupply1V8HighResetError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_supply_1v8_low_reset_error
	* Description: Mask for 1V8 LOW reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V8LowResetError : 1;        /*## attribute MaskSupply1V8LowResetError */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mask_supply_1v1_high_reset_error
	* Description: Mask for 1V1 high reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V1HighResetError : 1;        /*## attribute MaskSupply1V1HighResetError */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: mask_supply_1v1_low_reset_error
	* Description: Mask for 1V1 LOW reset error 1-> Masked 0-> Not Masked
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupply1V1LowResetError : 1;        /*## attribute MaskSupply1V1LowResetError */
}R2M15_MaskCcResetErrorBits_t;
/**
* R2M15_SnsIntegrityTestRegBits_t
* RegisterName: SNS_INTEGRITY_TEST_REG
* This register is used to inject fault in the Analog sensor
* Address: 0x20C
* ResetValue: 0x00000000
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
	* BitsName: sns_integrity_supply_1vX_force_error
	* Description: Force error to all 4 supply monitors: 1v8_high, 1v8_low, 1v1_high, 1v1_low
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t SnsIntegritySupply1VxForceError : 1;        /*## attribute SnsIntegritySupply1VxForceError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: sns_integrity_supply_1vX_reset_error
	* Description: Reset error to all 4 supply monitors: 1v8_high, 1v8_low, 1v1_high and 1v1_low
	* Note: Reset error from ISM is required to clear the flag; the local reset error is ONLY for removing the Analog fault; ISM reset_error is required from ISM since the latch is part of the digital logic
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t SnsIntegritySupply1VxResetError : 1;        /*## attribute SnsIntegritySupply1VxResetError */
}R2M15_SnsIntegrityTestRegBits_t;
/**
* R2M15_CrcErrorStatus1Bits_t
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
}R2M15_CrcErrorStatus1Bits_t;
/**
* R2M15_CrcErrorStatus2Bits_t
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
	* Note: The status corresponds to last 4 registers listed i.e registers 35(msb) down to 32(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 32;        /*## attribute CrcErrorStatusReg2 */
}R2M15_CrcErrorStatus2Bits_t;
/**
* R2M15_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00154001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000010101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
	/**
	* BitsName: major_rivision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRivision : 4;        /*## attribute MajorRivision */
	/**
	* BitsName: minor_rivision
	* Description: Minor revision number i.e. with no software consequences
	* Read/Write: R
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MinorRivision : 4;        /*## attribute MinorRivision */
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
}R2M15_ModuleIdBits_t;
#endif
/**
* R2M15_Gldo1V1SnsLowTopControlUnion_t
* R2M15_Gldo1V1SnsLowTopControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_Gldo1V1SnsLowTopControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_Gldo1V1SnsLowTopControlUnion_t;

/**
* R2M15_Gldo1V1SnsHighTopControlUnion_t
* R2M15_Gldo1V1SnsHighTopControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_Gldo1V1SnsHighTopControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_Gldo1V1SnsHighTopControlUnion_t;

/**
* R2M15_Gldo1V8SnsLowTopControlUnion_t
* R2M15_Gldo1V8SnsLowTopControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_Gldo1V8SnsLowTopControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_Gldo1V8SnsLowTopControlUnion_t;

/**
* R2M15_Gldo1V8SnsHighTopControlUnion_t
* R2M15_Gldo1V8SnsHighTopControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_Gldo1V8SnsHighTopControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_Gldo1V8SnsHighTopControlUnion_t;

/**
* R2M15_GldoBgRefConfigUnion_t
* R2M15_GldoBgRefConfigUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_GldoBgRefConfigBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_GldoBgRefConfigUnion_t;

/**
* R2M15_GldoBgRefConfig1ExtUnion_t
* R2M15_GldoBgRefConfig1ExtUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_GldoBgRefConfig1ExtBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_GldoBgRefConfig1ExtUnion_t;

/**
* R2M15_GldoBgRefConfig2ExtUnion_t
* R2M15_GldoBgRefConfig2ExtUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_GldoBgRefConfig2ExtBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_GldoBgRefConfig2ExtUnion_t;

/**
* R2M15_Gldo1V11V8SnsLowHighThresholdConfigUnion_t
* R2M15_Gldo1V11V8SnsLowHighThresholdConfigUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_Gldo1V11V8SnsLowHighThresholdConfigBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_Gldo1V11V8SnsLowHighThresholdConfigUnion_t;

/**
* R2M15_Gldo1V8SnsLowCalRegUnion_t
* R2M15_Gldo1V8SnsLowCalRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_Gldo1V8SnsLowCalRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_Gldo1V8SnsLowCalRegUnion_t;

/**
* R2M15_Gldo1V8SnsHighCalRegUnion_t
* R2M15_Gldo1V8SnsHighCalRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_Gldo1V8SnsHighCalRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_Gldo1V8SnsHighCalRegUnion_t;

/**
* R2M15_Gldo1V1SnsLowCalRegUnion_t
* R2M15_Gldo1V1SnsLowCalRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_Gldo1V1SnsLowCalRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_Gldo1V1SnsLowCalRegUnion_t;

/**
* R2M15_Gldo1V1SnsHighCalRegUnion_t
* R2M15_Gldo1V1SnsHighCalRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_Gldo1V1SnsHighCalRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_Gldo1V1SnsHighCalRegUnion_t;

/**
* R2M15_GldoOvuvDeglitchControlUnion_t
* R2M15_GldoOvuvDeglitchControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_GldoOvuvDeglitchControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_GldoOvuvDeglitchControlUnion_t;

/**
* R2M15_GldoBgRefStatusUnion_t
* R2M15_GldoBgRefStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_GldoBgRefStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_GldoBgRefStatusUnion_t;

/**
* R2M15_TestErrorFlagStatusUnion_t
* R2M15_TestErrorFlagStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_TestErrorFlagStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_TestErrorFlagStatusUnion_t;

/**
* R2M15_MaskCcResetErrorUnion_t
* R2M15_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_MaskCcResetErrorUnion_t;

/**
* R2M15_SnsIntegrityTestRegUnion_t
* R2M15_SnsIntegrityTestRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_SnsIntegrityTestRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_SnsIntegrityTestRegUnion_t;

/**
* R2M15_CrcErrorStatus1Union_t
* R2M15_CrcErrorStatus1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_CrcErrorStatus1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_CrcErrorStatus1Union_t;

/**
* R2M15_CrcErrorStatus2Union_t
* R2M15_CrcErrorStatus2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_CrcErrorStatus2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_CrcErrorStatus2Union_t;

/**
* R2M15_ModuleIdUnion_t
* R2M15_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M15_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M15_ModuleIdUnion_t;


#endif
