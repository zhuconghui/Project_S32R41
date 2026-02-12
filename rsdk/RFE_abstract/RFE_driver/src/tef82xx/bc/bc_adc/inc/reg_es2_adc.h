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
* @reg_es2_adc.h
*/
#ifndef REG_ES2_ADC_H
#define REG_ES2_ADC_H
#include <stdint.h>
/**
* R2M07_PON_U16
* RegisterName: MOD07_PON
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x00000000
*/
#define R2M07_PON_U16 (uint16_t)0x0000
/**
* R2M07_CALIBRATION_STATUS_U16
* RegisterName: MOD07_CALIBRATION_STATUS
* AccessMode: R
* AddressRange: 0x0004 - 0x0008
* ResetValue: 0x00000000
*/
#define R2M07_CALIBRATION_STATUS_U16 (uint16_t)0x0004
/**
* R2M07_CALIBRATION_START_U16
* RegisterName: MOD07_CALIBRATION_START
* AccessMode: W
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x00000000
*/
#define R2M07_CALIBRATION_START_U16 (uint16_t)0x0008
/**
* R2M07_OUTPUT_POLARITY_CONTROL_U16
* RegisterName: MOD07_OUTPUT_POLARITY_CONTROL
* AccessMode: RW
* AddressRange: 0x0010 - 0x0014
* ResetValue: 0x00000000
*/
#define R2M07_OUTPUT_POLARITY_CONTROL_U16 (uint16_t)0x0010
/**
* R2M07_CLIPLEVEL_CONTROL_U16
* RegisterName: MOD07_CLIPLEVEL_CONTROL
* AccessMode: RW
* AddressRange: 0x0014 - 0x0018
* ResetValue: 0x00600600
*/
#define R2M07_CLIPLEVEL_CONTROL_U16 (uint16_t)0x0014
/**
* R2M07_ERRORCOUNT_THRESHOLD_U16
* RegisterName: MOD07_ERRORCOUNT_THRESHOLD
* AccessMode: RW
* AddressRange: 0x0018 - 0x001C
* ResetValue: 0x0000300C
*/
#define R2M07_ERRORCOUNT_THRESHOLD_U16 (uint16_t)0x0018
/**
* R2M07_CLIPPING_COUNTER_OVERVIEW_U16
* RegisterName: MOD07_CLIPPING_COUNTER_OVERVIEW
* AccessMode: R
* AddressRange: 0x001C - 0x0020
* ResetValue: 0x00000000
*/
#define R2M07_CLIPPING_COUNTER_OVERVIEW_U16 (uint16_t)0x001C
/**
* R2M07_ERROR_EVENT_OVERVIEW_U16
* RegisterName: MOD07_ERROR_EVENT_OVERVIEW
* AccessMode: R
* AddressRange: 0x0020 - 0x0024
* ResetValue: 0x00000000
*/
#define R2M07_ERROR_EVENT_OVERVIEW_U16 (uint16_t)0x0020
/**
* R2M07_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD07_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0028 - 0x002C
* ResetValue: 0x00000000
*/
#define R2M07_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0028
/**
* R2M07_POWERSAVE_CONTROL_U16
* RegisterName: MOD07_POWERSAVE_CONTROL
* AccessMode: RW
* AddressRange: 0x003C - 0x0040
* ResetValue: 0x00000001
*/
#define R2M07_POWERSAVE_CONTROL_U16 (uint16_t)0x003C
/**
* R2M07_CALIBRATION_CONTROL_U16
* RegisterName: MOD07_CALIBRATION_CONTROL
* AccessMode: RW
* AddressRange: 0x0040 - 0x0044
* ResetValue: 0x0000017F
*/
#define R2M07_CALIBRATION_CONTROL_U16 (uint16_t)0x0040
/**
* R2M07_OUTPUTMUX_SETTING_U16
* RegisterName: MOD07_OUTPUTMUX_SETTING
* AccessMode: RW
* AddressRange: 0x0094 - 0x0098
* ResetValue: 0x00000030
*/
#define R2M07_OUTPUTMUX_SETTING_U16 (uint16_t)0x0094
/**
* R2M07_OUTPUTMUX_CONSTANT_U16
* RegisterName: MOD07_OUTPUTMUX_CONSTANT
* AccessMode: RW
* AddressRange: 0x0098 - 0x009C
* ResetValue: 0xCE209B50
*/
#define R2M07_OUTPUTMUX_CONSTANT_U16 (uint16_t)0x0098
/**
* R2M07_CAL_MONITOR_MAX_ERROR_U16
* RegisterName: MOD07_CAL_MONITOR_MAX_ERROR
* AccessMode: RW
* AddressRange: 0x00A0 - 0x00A4
* ResetValue: 0x01000080
*/
#define R2M07_CAL_MONITOR_MAX_ERROR_U16 (uint16_t)0x00A0
/**
* R2M07_CAL_MONITOR_STATUS_U16
* RegisterName: MOD07_CAL_MONITOR_STATUS
* AccessMode: R
* AddressRange: 0x00A4 - 0x00A8
* ResetValue: 0x00000000
*/
#define R2M07_CAL_MONITOR_STATUS_U16 (uint16_t)0x00A4
/**
* R2M07_ADC_CLOCK_CONTROL_U16
* RegisterName: MOD07_ADC_CLOCK_CONTROL
* AccessMode: RW
* AddressRange: 0x0300 - 0x0304
* ResetValue: 0x0000001F
*/
#define R2M07_ADC_CLOCK_CONTROL_U16 (uint16_t)0x0300
/**
* R2M07_CRC_ERROR_STATUS1_U16
* RegisterName: MOD07_CRC_ERROR_STATUS1
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M07_CRC_ERROR_STATUS1_U16 (uint16_t)0x0F40
/**
* R2M07_CRC_ERROR_STATUS2_U16
* RegisterName: MOD07_CRC_ERROR_STATUS2
* AccessMode: R
* AddressRange: 0x0F44 - 0x0F48
* ResetValue: 0x00000000
*/
#define R2M07_CRC_ERROR_STATUS2_U16 (uint16_t)0x0F44
/**
* R2M07_CRC_ERROR_STATUS3_U16
* RegisterName: MOD07_CRC_ERROR_STATUS3
* AccessMode: R
* AddressRange: 0x0F48 - 0x0F4C
* ResetValue: 0x00000000
*/
#define R2M07_CRC_ERROR_STATUS3_U16 (uint16_t)0x0F48
/**
* R2M07_CRC_ERROR_STATUS4_U16
* RegisterName: MOD07_CRC_ERROR_STATUS4
* AccessMode: R
* AddressRange: 0x0F4C - 0x0F50
* ResetValue: 0x00000000
*/
#define R2M07_CRC_ERROR_STATUS4_U16 (uint16_t)0x0F4C
/**
* R2M07_MODULE_ID_U16
* RegisterName: MOD07_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x00075001
*/
#define R2M07_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M07_PonBits_t
* RegisterName: PON
* ADC pon control
* Address: 0x000
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pon_launch
	* Description: Master PO
	* 0: Module is powered down
	* 1: Module is powered on
	* 
	* Use model : this bit must be set high in a functional use case. 
	* Before setting this bit high, the PON from CC shall be set to high and the functional reset from CC shall be released.  
	* Under the above condition, a rising edge of this bit triggers a start up calibration of the module.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonLaunch : 1;        /*## attribute PonLaunch */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M07_PonBits_t;
/**
* R2M07_CalibrationStatusBits_t
* RegisterName: CALIBRATION_STATUS
* ADC calibration status
* Address: 0x004
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: calibration_busy
	* Description: 0: Calibration not active
	* 1: Calibration is active
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CalibrationBusy : 1;        /*## attribute CalibrationBusy */
	/**
	* BitsName: calibration_launched_okay
	* Description: 0: Calibration start could not be performed
	* 1: The calibration was started
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CalibrationLaunchedOkay : 1;        /*## attribute CalibrationLaunchedOkay */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
}R2M07_CalibrationStatusBits_t;
/**
* R2M07_CalibrationStartBits_t
* RegisterName: CALIBRATION_START
* Manual calibration start control
* Address: 0x008
* ResetValue: 0x00000000
* Read/Write: W
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: start_calibration
	* Description: 0: No action
	* 1: Starts a calibration
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t StartCalibration : 1;        /*## attribute StartCalibration */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M07_CalibrationStartBits_t;
/**
* R2M07_OutputPolarityControlBits_t
* RegisterName: OUTPUT_POLARITY_CONTROL
* Output polarity control
* Address: 0x010
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: invert_output_polarity
	* Description: 0: No action
	* 1: Invert the polarity of the ADC outputs
	* 
	* Note:
	* - b[0] controls the polarity of ADC_00
	* - b[1] controls the polarity of ADC_01
	* - b[2] controls the polarity of ADC_10
	* - b[3] controls the polarity of ADC_11
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t InvertOutputPolarity : 4;        /*## attribute InvertOutputPolarity */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 28;        /*## attribute Reserved0 */
}R2M07_OutputPolarityControlBits_t;
/**
* R2M07_CliplevelControlBits_t
* RegisterName: CLIPLEVEL_CONTROL
* Clipping level settings
* Address: 0x014
* ResetValue: 0x00600600
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: cliplevel_adc_0
	* Description: ADC 0 output level (code) that triggers the adjustable clipping detector
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b011000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CliplevelAdc0 : 12;        /*## attribute CliplevelAdc0 */
	/**
	* BitsName: cliplevel_adc_1
	* Description: ADC 1 output level (code) that triggers the adjustable clipping detector
	* Read/Write: RW
	* Bits: [23:12]
	* ResetValue: 0b011000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CliplevelAdc1 : 12;        /*## attribute CliplevelAdc1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
}R2M07_CliplevelControlBits_t;
/**
* R2M07_ErrorcountThresholdBits_t
* RegisterName: ERRORCOUNT_THRESHOLD
* Errorcount threshold settings
* Address: 0x018
* ResetValue: 0x0000300C
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: errorcount_threshold_adc_0
	* Description: Errorcount threshold for the ADC 0 Safety Controller
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000001100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t ErrorcountThresholdAdc0 : 10;        /*## attribute ErrorcountThresholdAdc0 */
	/**
	* BitsName: errorcount_threshold_adc_1
	* Description: Errorcount threshold for the ADC 1 Safety Controller
	* Read/Write: RW
	* Bits: [19:10]
	* ResetValue: 0b0000001100
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorcountThresholdAdc1 : 10;        /*## attribute ErrorcountThresholdAdc1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 12;        /*## attribute Reserved0 */
}R2M07_ErrorcountThresholdBits_t;
/**
* R2M07_ClippingCounterOverviewBits_t
* RegisterName: CLIPPING_COUNTER_OVERVIEW
* Running value of the clipping counter. 
* Clipping counter gets cleared every chirp reset period by the signal reset_error generated from CC. 
* To read the clipping counter in between the chirps, the reset_error from the CC to be masked using the register by setting the following bits to 1'b1 MASK_CC_RESET_ERROR.mask_adc_reset_error[0] & MASK_CC_RESET_ERROR.mask_adc_reset_error[1] . In this case, the counter runs across the chirps counting the clipping errors.
* Address: 0x01C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: clipping_counter_adc_0
	* Description: Clipping counter value for ADC 0 
	* Read/Write: R
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ClippingCounterAdc0 : 10;        /*## attribute ClippingCounterAdc0 */
	/**
	* BitsName: clipping_counter_adc_1
	* Description: Clipping counter value for ADC 1 
	* Read/Write: R
	* Bits: [19:10]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ClippingCounterAdc1 : 10;        /*## attribute ClippingCounterAdc1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 12;        /*## attribute Reserved0 */
}R2M07_ClippingCounterOverviewBits_t;
/**
* R2M07_ErrorEventOverviewBits_t
* RegisterName: ERROR_EVENT_OVERVIEW
* Error event overview
* Address: 0x020
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: error_events
	* Description: error_events[0] = 0 => ADC 0 not exceeding the clipping threshold, as set by cliplevel_adc_0
	* error_events[0] = 1 => ADC 0 exceeding the clipping threshold, as set by cliplevel_adc_0
	* error_events[1] = 0 => ADC 1 not exceeding the clipping threshold, as set by cliplevel_adc_1
	* error_events[1] = 1 => ADC 1 exceeding the clipping threshold, as set by cliplevel_adc_1
	* error_events[2] = 0 => ADC 0 not hard clipping
	* error_events[2] = 1 => ADC 0 hard clipping
	* error_events[3] = 0 => ADC 1 not hard clipping
	* error_events[3] = 1 => ADC 1 hard clipping
	* error_events[4] = 0 => ADC 0 no calibration error
	* error_events[4] = 1 => ADC 0 calibartion error
	* error_events[5] = 0 => ADC 1 no calibration error
	* error_events[5] = 1 => ADC 1 calibartion error
	* error_events[6] = 0 => no analog supply error
	* error_events[6] = 1 => analog_supply_error
	* error_events[7] = 0 => ADC 0 clipping counter not exceeding the counter threshold, as set by errorcount_threshold_adc_0
	* error_events[7] = 1 => ADC 0 clipping counter exceeding the counter threshold, as set by errorcount_threshold_adc_0
	* error_events[8] = 0 => ADC 1 clipping counter not exceeding the counter threshold, as set by errorcount_threshold_adc_1
	* error_events[8] = 1 => ADC 1 clipping counter exceeding the counter threshold, as set by errorcount_threshold_adc_1
	* Read/Write: R
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t ErrorEvents : 9;        /*## attribute ErrorEvents */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
}R2M07_ErrorEventOverviewBits_t;
/**
* R2M07_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* Block the Safety Controller error flag reseta and the clipping counter reset, as provided by the adc_reset_error pin
* Address: 0x028
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_adc_reset_error
	* Description: mask_adc_reset_error[0] = 0 => reset of the ADC_0 clipping threshold flag and the ADC 0 clipping counter not blocked
	* mask_adc_reset_error[0] = 1 => reset of the ADC_0 clipping threshold flag and the ADC 0 clipping counter blocked
	* mask_adc_reset_error[1] = 0 => reset of the ADC_1 clipping threshold flag and the ADC 1 clipping counter not blocked
	* mask_adc_reset_error[1] = 1 => reset of the ADC_1 clipping threshold flag and the ADC 1 clipping counter blocked
	* mask_adc_reset_error[2] = 0 => reset of the ADC_0 hard clipping flag not blocked
	* mask_adc_reset_error[2] = 1 => reset of the ADC_0 hard clipping flag blocked
	* mask_adc_reset_error[3] = 0 => reset of the ADC_1 hard clipping flag not blocked
	* mask_adc_reset_error[3] = 1 => reset of the ADC_1 hard clipping flag blocked
	* mask_adc_reset_error[4] = 0 => reset of the ADC_0 calibration error flag not blocked
	* mask_adc_reset_error[4] = 1 => reset of the ADC_0 calibration error flag blocked
	* mask_adc_reset_error[5] = 0 => reset of the ADC_1 calibration error flag not blocked
	* mask_adc_reset_error[5] = 1 => reset of the ADC_1 calibration error flag blocked
	* mask_adc_reset_error[6] = 0 => reset of the ADC_1 calibration bg abort flag not blocked
	* mask_adc_reset_error[6] = 1 => reset of the ADC_1 calibration bg abort flag blocked
	* mask_adc_reset_error[7] = 0 => reset of the analog supply monitor not blocked
	* mask_adc_reset_error[7] = 1 => reset of the analog supply monitor blocked
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAdcResetError : 8;        /*## attribute MaskAdcResetError */
	/**
	* BitsName: mask_adc_reg_crc_reset_error
	* Description: mask_adc_reg_crc_reset_error = 0 => reset of the ADC_0 reg crc error flag not blocked
	* mask_adc_reg_crc_reset_error = 1 => reset of the ADC_0 reg crc error flag blocked
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAdcRegCrcResetError : 1;        /*## attribute MaskAdcRegCrcResetError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
}R2M07_MaskCcResetErrorBits_t;
/**
* R2M07_PowersaveControlBits_t
* RegisterName: POWERSAVE_CONTROL
* Power save (startup calibration) control
* Address: 0x03C
* ResetValue: 0x00000001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pon_powersave_enable
	* Description: pon_powersave_enable = 0 => PON always triggers calibration
	* pon_powersave_enable = 1 => PON only triggers calibation once
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonPowersaveEnable : 1;        /*## attribute PonPowersaveEnable */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M07_PowersaveControlBits_t;
/**
* R2M07_CalibrationControlBits_t
* RegisterName: CALIBRATION_CONTROL
* Calibration settings
* Address: 0x040
* ResetValue: 0x0000017F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: auto_calibrate_at_pon
	* Description: auto_calibrate_at_pon = 0 => no action
	* auto_calibrate_at_pon = 1 => automatically calibrate the ADC after power-on
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AutoCalibrateAtPon : 1;        /*## attribute AutoCalibrateAtPon */
	/**
	* BitsName: auto_sync_sequencer_after_calibration
	* Description: auto_sync_sequencer_after_calibration = 0 => no action
	* auto_sync_sequencer_after_calibration = 1 => automatically synchronize sequencer with other dual ADC after calibration
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AutoSyncSequencerAfterCalibration : 1;        /*## attribute AutoSyncSequencerAfterCalibration */
	/**
	* BitsName: calibrate_lsb_weights
	* Description: calibrate_lsb_weights = 0 => disable calibration of LSBs that are not part of the DEM array
	* calibrate_lsb_weights = 1 => enable calibration of LSBs that are not part of the DEM array
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CalibrateLsbWeights : 1;        /*## attribute CalibrateLsbWeights */
	/**
	* BitsName: enable_interleaved_calibration
	* Description: enable_interleaved_calibration = 0 => simultaneous calibration (Dolphin compatible mode)
	* enable_interleaved_calibration = 1 => interleaved operation during calibration
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnableInterleavedCalibration : 1;        /*## attribute EnableInterleavedCalibration */
	/**
	* BitsName: enable_continuous_bg_calibration
	* Description: enable_continuous_bg_calibration = 0 => no continuation of weight calibration after BG abort (Dolphin compatible mode)
	* enable_continuous_bg_calibration = 1 => continuation of weight calibration after BG abort enabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnableContinuousBgCalibration : 1;        /*## attribute EnableContinuousBgCalibration */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: enable_powersave_bg_calibration
	* Description: enable_powersave_bg_calibration = 0 => power-save background calibration disabled
	* enable_powersave_bg_calibration = 1 => power-save background calibration enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnablePowersaveBgCalibration : 1;        /*## attribute EnablePowersaveBgCalibration */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: powersave_bg_calibration_nweights
	* Description: Number of weights to calibrate per power-save background calibration cycle
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PowersaveBgCalibrationNweights : 4;        /*## attribute PowersaveBgCalibrationNweights */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 20;        /*## attribute Reserved2 */
}R2M07_CalibrationControlBits_t;
/**
* R2M07_OutputmuxSettingBits_t
* RegisterName: OUTPUTMUX_SETTING
* Output mux control
* Address: 0x094
* ResetValue: 0x00000030
* Read/Write: RW
* FuSa: ?
*/
typedef struct  {
	/**
	* BitsName: outputmux_mode_adc_0
	* Description: Operation mode for the ADC_0 output mux
	* outputmux_mode_adc_0 = 00 => normal operation
	* outputmux_mode_adc_0 = 01 => ADC_0 constant value as set by the value of the outputmux_debug_constant_data field                                                            
	* outputmux_mode_adc_0 = 10 => counter value                                                          
	* outputmux_mode_adc_0 = 11 => counter value + 4-bit ADC_0 offset value (LSB-aligned)
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxModeAdc0 : 2;        /*## attribute OutputmuxModeAdc0 */
	/**
	* BitsName: outputmux_mode_adc_1
	* Description: Operation mode for the ADC_1 output mux
	* outputmux_mode_adc_1 = 00 => normal operation
	* outputmux_mode_adc_1 = 01 => ADC_1 constant value as set by the value of the outputmux_debug_constant_data field                                                            
	* outputmux_mode_adc_1 = 10 => counter value                                                          
	* outputmux_mode_adc_1 = 11 => counter value + 4-bit ADC_1 offset value (LSB-aligned)
	* Read/Write: RW
	* Bits: [3:2]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxModeAdc1 : 2;        /*## attribute OutputmuxModeAdc1 */
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
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 22;        /*## attribute Reserved3 */
}R2M07_OutputmuxSettingBits_t;
/**
* R2M07_OutputmuxConstantBits_t
* RegisterName: OUTPUTMUX_CONSTANT
* Output mux control
* Address: 0x098
* ResetValue: 0xCE209B50
* Read/Write: RW
* FuSa: ?
*/
typedef struct  {
	/**
	* BitsName: outputmux_counter_offset_adc_0
	* Description: 4-bit offset value for the debug counter for the ADC_0 output mux
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxCounterOffsetAdc0 : 4;        /*## attribute OutputmuxCounterOffsetAdc0 */
	/**
	* BitsName: outputmux_debug_constant_data_adc_0
	* Description: Constant debug value for the ADC_0 output mux
	* Read/Write: RW
	* Bits: [15:4]
	* ResetValue: 0b100110110101
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxDebugConstantDataAdc0 : 12;        /*## attribute OutputmuxDebugConstantDataAdc0 */
	/**
	* BitsName: outputmux_counter_offset_adc_1
	* Description: 4-bit offset value for the debug counter for the ADC_1 output mux
	* Read/Write: RW
	* Bits: [19:16]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t OutputmuxCounterOffsetAdc1 : 4;        /*## attribute OutputmuxCounterOffsetAdc1 */
	/**
	* BitsName: outputmux_debug_constant_data_adc_1
	* Description: Constant debug value for the ADC_1 output mux
	* Read/Write: RW
	* Bits: [31:20]
	* ResetValue: 0b110011100010
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxDebugConstantDataAdc1 : 12;        /*## attribute OutputmuxDebugConstantDataAdc1 */
}R2M07_OutputmuxConstantBits_t;
/**
* R2M07_CalMonitorMaxErrorBits_t
* RegisterName: CAL_MONITOR_MAX_ERROR
* Calibration monitor maximum allowed error control
* Address: 0x0A0
* ResetValue: 0x01000080
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: cal_monitor_max_offset_error
	* Description: Maximum allowed offset calibration error
	* Specificed in 4.6 unsigned format (64=1 lsb)
	* Note: Default value to be used instead of Reset value
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0010000000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CalMonitorMaxOffsetError : 10;        /*## attribute CalMonitorMaxOffsetError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 6;        /*## attribute Reserved0 */
	/**
	* BitsName: cal_monitor_max_gain_error
	* Description: Maximum allowed gain calibration error
	* Specified in 4.6 unsigned format (64=1 lsb)
	* Read/Write: RW
	* Bits: [25:16]
	* ResetValue: 0b0100000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CalMonitorMaxGainError : 10;        /*## attribute CalMonitorMaxGainError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 6;        /*## attribute Reserved1 */
}R2M07_CalMonitorMaxErrorBits_t;
/**
* R2M07_CalMonitorStatusBits_t
* RegisterName: CAL_MONITOR_STATUS
* Calibration monitor status
* Address: 0x0A4
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: cal_monitor_calibration_check_done
	* Description: cal_monitor_calibration_check_done = 0 => calibration monitor is running
	* cal_monitor_calibration_check_done = 1 => calibration monitor check is done
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CalMonitorCalibrationCheckDone : 1;        /*## attribute CalMonitorCalibrationCheckDone */
	/**
	* BitsName: cal_monitor_calibration_okay
	* Description: cal_monitor_calibration_okay[0] = 0 => calibration of ADC_00 failed
	* cal_monitor_calibration_okay[0] = 1 => calibration of ADC_00 succesful
	* cal_monitor_calibration_okay[1] = 0 => calibration of ADC_01 failed
	* cal_monitor_calibration_okay[1] = 1 => calibration of ADC_01 succesful
	* cal_monitor_calibration_okay[2] = 0 => calibration of ADC_10 failed
	* cal_monitor_calibration_okay[2] = 1 => calibration of ADC_10 succesful
	* cal_monitor_calibration_okay[3] = 0 => calibration of ADC_11 failed
	* cal_monitor_calibration_okay[3] = 1 => calibration of ADC_11 succesful
	* Read/Write: R
	* Bits: [4:1]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CalMonitorCalibrationOkay : 4;        /*## attribute CalMonitorCalibrationOkay */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
}R2M07_CalMonitorStatusBits_t;
/**
* R2M07_AdcClockControlBits_t
* RegisterName: ADC_CLOCK_CONTROL
* ADC clock control
* Address: 0x300
* ResetValue: 0x0000001F
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
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: adcsync_skew_ctrl
	* Description: adcsync_skew_ctrl = 00 => delay set to 0 ps
	* adcsync_skew_ctrl = 01 => delay set to 100 ps
	* adcsync_skew_ctrl = 10 => delay set to 200 ps
	* adcsync_skew_ctrl = 11 => delay set to 300 ps
	* Read/Write: RW
	* Bits: [6:5]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcsyncSkewCtrl : 2;        /*## attribute AdcsyncSkewCtrl */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 25;        /*## attribute Reserved3 */
}R2M07_AdcClockControlBits_t;
/**
* R2M07_CrcErrorStatus1Bits_t
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
}R2M07_CrcErrorStatus1Bits_t;
/**
* R2M07_CrcErrorStatus2Bits_t
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
}R2M07_CrcErrorStatus2Bits_t;
/**
* R2M07_CrcErrorStatus3Bits_t
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
	* Note: The status corresponds to next 32 registers listed i.e registers 95(msb) down to 64(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 32;        /*## attribute CrcErrorStatusReg3 */
}R2M07_CrcErrorStatus3Bits_t;
/**
* R2M07_CrcErrorStatus4Bits_t
* RegisterName: CRC_ERROR_STATUS4
* Status of the CRC for each register
* Address: 0xF4C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg4
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to last 22 registers listed i.e registers 117(msb) down to 96(lsb) and other bits are not valid 
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg4 : 32;        /*## attribute CrcErrorStatusReg4 */
}R2M07_CrcErrorStatus4Bits_t;
/**
* R2M07_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00075001
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
	* Description: Minor revision numer i.e. with no software consequences
	* Derived from the 8 bit RTL parameter
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
	* Derived from the 8 bit RTL parameter
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRevision : 4;        /*## attribute MajorRevision */
	/**
	* BitsName: mod_id
	* Description: Module identifier. The 8 lsb's are determined by hardware ties at ADC Digital Core level
	* Read/Write: R
	* Bits: [23:16]
	* ResetValue: 0b00000111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ModId : 8;        /*## attribute ModId */
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* The 8 msb's are derived from the 8 msb's of a 16 bit RTL parameter
	* Read/Write: R
	* Bits: [31:24]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 8;        /*## attribute Identifier */
}R2M07_ModuleIdBits_t;

 #else
/**
* R2M07_PonBits_t
* RegisterName: PON
* ADC pon control
* Address: 0x000
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
	* BitsName: pon_launch
	* Description: Master PO
	* 0: Module is powered down
	* 1: Module is powered on
	* 
	* Use model : this bit must be set high in a functional use case. 
	* Before setting this bit high, the PON from CC shall be set to high and the functional reset from CC shall be released.  
	* Under the above condition, a rising edge of this bit triggers a start up calibration of the module.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonLaunch : 1;        /*## attribute PonLaunch */
}R2M07_PonBits_t;
/**
* R2M07_CalibrationStatusBits_t
* RegisterName: CALIBRATION_STATUS
* ADC calibration status
* Address: 0x004
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
	/**
	* BitsName: calibration_launched_okay
	* Description: 0: Calibration start could not be performed
	* 1: The calibration was started
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CalibrationLaunchedOkay : 1;        /*## attribute CalibrationLaunchedOkay */
	/**
	* BitsName: calibration_busy
	* Description: 0: Calibration not active
	* 1: Calibration is active
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CalibrationBusy : 1;        /*## attribute CalibrationBusy */
}R2M07_CalibrationStatusBits_t;
/**
* R2M07_CalibrationStartBits_t
* RegisterName: CALIBRATION_START
* Manual calibration start control
* Address: 0x008
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
	* BitsName: start_calibration
	* Description: 0: No action
	* 1: Starts a calibration
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t StartCalibration : 1;        /*## attribute StartCalibration */
}R2M07_CalibrationStartBits_t;
/**
* R2M07_OutputPolarityControlBits_t
* RegisterName: OUTPUT_POLARITY_CONTROL
* Output polarity control
* Address: 0x010
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 28;        /*## attribute Reserved0 */
	/**
	* BitsName: invert_output_polarity
	* Description: 0: No action
	* 1: Invert the polarity of the ADC outputs
	* 
	* Note:
	* - b[0] controls the polarity of ADC_00
	* - b[1] controls the polarity of ADC_01
	* - b[2] controls the polarity of ADC_10
	* - b[3] controls the polarity of ADC_11
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t InvertOutputPolarity : 4;        /*## attribute InvertOutputPolarity */
}R2M07_OutputPolarityControlBits_t;
/**
* R2M07_CliplevelControlBits_t
* RegisterName: CLIPLEVEL_CONTROL
* Clipping level settings
* Address: 0x014
* ResetValue: 0x00600600
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: cliplevel_adc_1
	* Description: ADC 1 output level (code) that triggers the adjustable clipping detector
	* Read/Write: RW
	* Bits: [23:12]
	* ResetValue: 0b011000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CliplevelAdc1 : 12;        /*## attribute CliplevelAdc1 */
	/**
	* BitsName: cliplevel_adc_0
	* Description: ADC 0 output level (code) that triggers the adjustable clipping detector
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b011000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CliplevelAdc0 : 12;        /*## attribute CliplevelAdc0 */
}R2M07_CliplevelControlBits_t;
/**
* R2M07_ErrorcountThresholdBits_t
* RegisterName: ERRORCOUNT_THRESHOLD
* Errorcount threshold settings
* Address: 0x018
* ResetValue: 0x0000300C
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 12;        /*## attribute Reserved0 */
	/**
	* BitsName: errorcount_threshold_adc_1
	* Description: Errorcount threshold for the ADC 1 Safety Controller
	* Read/Write: RW
	* Bits: [19:10]
	* ResetValue: 0b0000001100
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorcountThresholdAdc1 : 10;        /*## attribute ErrorcountThresholdAdc1 */
	/**
	* BitsName: errorcount_threshold_adc_0
	* Description: Errorcount threshold for the ADC 0 Safety Controller
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0000001100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t ErrorcountThresholdAdc0 : 10;        /*## attribute ErrorcountThresholdAdc0 */
}R2M07_ErrorcountThresholdBits_t;
/**
* R2M07_ClippingCounterOverviewBits_t
* RegisterName: CLIPPING_COUNTER_OVERVIEW
* Running value of the clipping counter. 
* Clipping counter gets cleared every chirp reset period by the signal reset_error generated from CC. 
* To read the clipping counter in between the chirps, the reset_error from the CC to be masked using the register by setting the following bits to 1'b1 MASK_CC_RESET_ERROR.mask_adc_reset_error[0] & MASK_CC_RESET_ERROR.mask_adc_reset_error[1] . In this case, the counter runs across the chirps counting the clipping errors.
* Address: 0x01C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 12;        /*## attribute Reserved0 */
	/**
	* BitsName: clipping_counter_adc_1
	* Description: Clipping counter value for ADC 1 
	* Read/Write: R
	* Bits: [19:10]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ClippingCounterAdc1 : 10;        /*## attribute ClippingCounterAdc1 */
	/**
	* BitsName: clipping_counter_adc_0
	* Description: Clipping counter value for ADC 0 
	* Read/Write: R
	* Bits: [9:0]
	* ResetValue: 0b0000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ClippingCounterAdc0 : 10;        /*## attribute ClippingCounterAdc0 */
}R2M07_ClippingCounterOverviewBits_t;
/**
* R2M07_ErrorEventOverviewBits_t
* RegisterName: ERROR_EVENT_OVERVIEW
* Error event overview
* Address: 0x020
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: error_events
	* Description: error_events[0] = 0 => ADC 0 not exceeding the clipping threshold, as set by cliplevel_adc_0
	* error_events[0] = 1 => ADC 0 exceeding the clipping threshold, as set by cliplevel_adc_0
	* error_events[1] = 0 => ADC 1 not exceeding the clipping threshold, as set by cliplevel_adc_1
	* error_events[1] = 1 => ADC 1 exceeding the clipping threshold, as set by cliplevel_adc_1
	* error_events[2] = 0 => ADC 0 not hard clipping
	* error_events[2] = 1 => ADC 0 hard clipping
	* error_events[3] = 0 => ADC 1 not hard clipping
	* error_events[3] = 1 => ADC 1 hard clipping
	* error_events[4] = 0 => ADC 0 no calibration error
	* error_events[4] = 1 => ADC 0 calibartion error
	* error_events[5] = 0 => ADC 1 no calibration error
	* error_events[5] = 1 => ADC 1 calibartion error
	* error_events[6] = 0 => no analog supply error
	* error_events[6] = 1 => analog_supply_error
	* error_events[7] = 0 => ADC 0 clipping counter not exceeding the counter threshold, as set by errorcount_threshold_adc_0
	* error_events[7] = 1 => ADC 0 clipping counter exceeding the counter threshold, as set by errorcount_threshold_adc_0
	* error_events[8] = 0 => ADC 1 clipping counter not exceeding the counter threshold, as set by errorcount_threshold_adc_1
	* error_events[8] = 1 => ADC 1 clipping counter exceeding the counter threshold, as set by errorcount_threshold_adc_1
	* Read/Write: R
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t ErrorEvents : 9;        /*## attribute ErrorEvents */
}R2M07_ErrorEventOverviewBits_t;
/**
* R2M07_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* Block the Safety Controller error flag reseta and the clipping counter reset, as provided by the adc_reset_error pin
* Address: 0x028
* ResetValue: 0x00000000
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
	* BitsName: mask_adc_reg_crc_reset_error
	* Description: mask_adc_reg_crc_reset_error = 0 => reset of the ADC_0 reg crc error flag not blocked
	* mask_adc_reg_crc_reset_error = 1 => reset of the ADC_0 reg crc error flag blocked
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAdcRegCrcResetError : 1;        /*## attribute MaskAdcRegCrcResetError */
	/**
	* BitsName: mask_adc_reset_error
	* Description: mask_adc_reset_error[0] = 0 => reset of the ADC_0 clipping threshold flag and the ADC 0 clipping counter not blocked
	* mask_adc_reset_error[0] = 1 => reset of the ADC_0 clipping threshold flag and the ADC 0 clipping counter blocked
	* mask_adc_reset_error[1] = 0 => reset of the ADC_1 clipping threshold flag and the ADC 1 clipping counter not blocked
	* mask_adc_reset_error[1] = 1 => reset of the ADC_1 clipping threshold flag and the ADC 1 clipping counter blocked
	* mask_adc_reset_error[2] = 0 => reset of the ADC_0 hard clipping flag not blocked
	* mask_adc_reset_error[2] = 1 => reset of the ADC_0 hard clipping flag blocked
	* mask_adc_reset_error[3] = 0 => reset of the ADC_1 hard clipping flag not blocked
	* mask_adc_reset_error[3] = 1 => reset of the ADC_1 hard clipping flag blocked
	* mask_adc_reset_error[4] = 0 => reset of the ADC_0 calibration error flag not blocked
	* mask_adc_reset_error[4] = 1 => reset of the ADC_0 calibration error flag blocked
	* mask_adc_reset_error[5] = 0 => reset of the ADC_1 calibration error flag not blocked
	* mask_adc_reset_error[5] = 1 => reset of the ADC_1 calibration error flag blocked
	* mask_adc_reset_error[6] = 0 => reset of the ADC_1 calibration bg abort flag not blocked
	* mask_adc_reset_error[6] = 1 => reset of the ADC_1 calibration bg abort flag blocked
	* mask_adc_reset_error[7] = 0 => reset of the analog supply monitor not blocked
	* mask_adc_reset_error[7] = 1 => reset of the analog supply monitor blocked
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAdcResetError : 8;        /*## attribute MaskAdcResetError */
}R2M07_MaskCcResetErrorBits_t;
/**
* R2M07_PowersaveControlBits_t
* RegisterName: POWERSAVE_CONTROL
* Power save (startup calibration) control
* Address: 0x03C
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
	* BitsName: pon_powersave_enable
	* Description: pon_powersave_enable = 0 => PON always triggers calibration
	* pon_powersave_enable = 1 => PON only triggers calibation once
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonPowersaveEnable : 1;        /*## attribute PonPowersaveEnable */
}R2M07_PowersaveControlBits_t;
/**
* R2M07_CalibrationControlBits_t
* RegisterName: CALIBRATION_CONTROL
* Calibration settings
* Address: 0x040
* ResetValue: 0x0000017F
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
	* BitsName: powersave_bg_calibration_nweights
	* Description: Number of weights to calibrate per power-save background calibration cycle
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PowersaveBgCalibrationNweights : 4;        /*## attribute PowersaveBgCalibrationNweights */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: enable_powersave_bg_calibration
	* Description: enable_powersave_bg_calibration = 0 => power-save background calibration disabled
	* enable_powersave_bg_calibration = 1 => power-save background calibration enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnablePowersaveBgCalibration : 1;        /*## attribute EnablePowersaveBgCalibration */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: enable_continuous_bg_calibration
	* Description: enable_continuous_bg_calibration = 0 => no continuation of weight calibration after BG abort (Dolphin compatible mode)
	* enable_continuous_bg_calibration = 1 => continuation of weight calibration after BG abort enabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnableContinuousBgCalibration : 1;        /*## attribute EnableContinuousBgCalibration */
	/**
	* BitsName: enable_interleaved_calibration
	* Description: enable_interleaved_calibration = 0 => simultaneous calibration (Dolphin compatible mode)
	* enable_interleaved_calibration = 1 => interleaved operation during calibration
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnableInterleavedCalibration : 1;        /*## attribute EnableInterleavedCalibration */
	/**
	* BitsName: calibrate_lsb_weights
	* Description: calibrate_lsb_weights = 0 => disable calibration of LSBs that are not part of the DEM array
	* calibrate_lsb_weights = 1 => enable calibration of LSBs that are not part of the DEM array
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CalibrateLsbWeights : 1;        /*## attribute CalibrateLsbWeights */
	/**
	* BitsName: auto_sync_sequencer_after_calibration
	* Description: auto_sync_sequencer_after_calibration = 0 => no action
	* auto_sync_sequencer_after_calibration = 1 => automatically synchronize sequencer with other dual ADC after calibration
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AutoSyncSequencerAfterCalibration : 1;        /*## attribute AutoSyncSequencerAfterCalibration */
	/**
	* BitsName: auto_calibrate_at_pon
	* Description: auto_calibrate_at_pon = 0 => no action
	* auto_calibrate_at_pon = 1 => automatically calibrate the ADC after power-on
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AutoCalibrateAtPon : 1;        /*## attribute AutoCalibrateAtPon */
}R2M07_CalibrationControlBits_t;
/**
* R2M07_OutputmuxSettingBits_t
* RegisterName: OUTPUTMUX_SETTING
* Output mux control
* Address: 0x094
* ResetValue: 0x00000030
* Read/Write: RW
* FuSa: ?
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
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
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: outputmux_mode_adc_1
	* Description: Operation mode for the ADC_1 output mux
	* outputmux_mode_adc_1 = 00 => normal operation
	* outputmux_mode_adc_1 = 01 => ADC_1 constant value as set by the value of the outputmux_debug_constant_data field                                                            
	* outputmux_mode_adc_1 = 10 => counter value                                                          
	* outputmux_mode_adc_1 = 11 => counter value + 4-bit ADC_1 offset value (LSB-aligned)
	* Read/Write: RW
	* Bits: [3:2]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxModeAdc1 : 2;        /*## attribute OutputmuxModeAdc1 */
	/**
	* BitsName: outputmux_mode_adc_0
	* Description: Operation mode for the ADC_0 output mux
	* outputmux_mode_adc_0 = 00 => normal operation
	* outputmux_mode_adc_0 = 01 => ADC_0 constant value as set by the value of the outputmux_debug_constant_data field                                                            
	* outputmux_mode_adc_0 = 10 => counter value                                                          
	* outputmux_mode_adc_0 = 11 => counter value + 4-bit ADC_0 offset value (LSB-aligned)
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxModeAdc0 : 2;        /*## attribute OutputmuxModeAdc0 */
}R2M07_OutputmuxSettingBits_t;
/**
* R2M07_OutputmuxConstantBits_t
* RegisterName: OUTPUTMUX_CONSTANT
* Output mux control
* Address: 0x098
* ResetValue: 0xCE209B50
* Read/Write: RW
* FuSa: ?
*/
typedef struct  {
	/**
	* BitsName: outputmux_debug_constant_data_adc_1
	* Description: Constant debug value for the ADC_1 output mux
	* Read/Write: RW
	* Bits: [31:20]
	* ResetValue: 0b110011100010
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxDebugConstantDataAdc1 : 12;        /*## attribute OutputmuxDebugConstantDataAdc1 */
	/**
	* BitsName: outputmux_counter_offset_adc_1
	* Description: 4-bit offset value for the debug counter for the ADC_1 output mux
	* Read/Write: RW
	* Bits: [19:16]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t OutputmuxCounterOffsetAdc1 : 4;        /*## attribute OutputmuxCounterOffsetAdc1 */
	/**
	* BitsName: outputmux_debug_constant_data_adc_0
	* Description: Constant debug value for the ADC_0 output mux
	* Read/Write: RW
	* Bits: [15:4]
	* ResetValue: 0b100110110101
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxDebugConstantDataAdc0 : 12;        /*## attribute OutputmuxDebugConstantDataAdc0 */
	/**
	* BitsName: outputmux_counter_offset_adc_0
	* Description: 4-bit offset value for the debug counter for the ADC_0 output mux
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: ?
	*/
	uint32_t OutputmuxCounterOffsetAdc0 : 4;        /*## attribute OutputmuxCounterOffsetAdc0 */
}R2M07_OutputmuxConstantBits_t;
/**
* R2M07_CalMonitorMaxErrorBits_t
* RegisterName: CAL_MONITOR_MAX_ERROR
* Calibration monitor maximum allowed error control
* Address: 0x0A0
* ResetValue: 0x01000080
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
	* BitsName: cal_monitor_max_gain_error
	* Description: Maximum allowed gain calibration error
	* Specified in 4.6 unsigned format (64=1 lsb)
	* Read/Write: RW
	* Bits: [25:16]
	* ResetValue: 0b0100000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CalMonitorMaxGainError : 10;        /*## attribute CalMonitorMaxGainError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 6;        /*## attribute Reserved1 */
	/**
	* BitsName: cal_monitor_max_offset_error
	* Description: Maximum allowed offset calibration error
	* Specificed in 4.6 unsigned format (64=1 lsb)
	* Note: Default value to be used instead of Reset value
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b0010000000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CalMonitorMaxOffsetError : 10;        /*## attribute CalMonitorMaxOffsetError */
}R2M07_CalMonitorMaxErrorBits_t;
/**
* R2M07_CalMonitorStatusBits_t
* RegisterName: CAL_MONITOR_STATUS
* Calibration monitor status
* Address: 0x0A4
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
	* BitsName: cal_monitor_calibration_okay
	* Description: cal_monitor_calibration_okay[0] = 0 => calibration of ADC_00 failed
	* cal_monitor_calibration_okay[0] = 1 => calibration of ADC_00 succesful
	* cal_monitor_calibration_okay[1] = 0 => calibration of ADC_01 failed
	* cal_monitor_calibration_okay[1] = 1 => calibration of ADC_01 succesful
	* cal_monitor_calibration_okay[2] = 0 => calibration of ADC_10 failed
	* cal_monitor_calibration_okay[2] = 1 => calibration of ADC_10 succesful
	* cal_monitor_calibration_okay[3] = 0 => calibration of ADC_11 failed
	* cal_monitor_calibration_okay[3] = 1 => calibration of ADC_11 succesful
	* Read/Write: R
	* Bits: [4:1]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CalMonitorCalibrationOkay : 4;        /*## attribute CalMonitorCalibrationOkay */
	/**
	* BitsName: cal_monitor_calibration_check_done
	* Description: cal_monitor_calibration_check_done = 0 => calibration monitor is running
	* cal_monitor_calibration_check_done = 1 => calibration monitor check is done
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CalMonitorCalibrationCheckDone : 1;        /*## attribute CalMonitorCalibrationCheckDone */
}R2M07_CalMonitorStatusBits_t;
/**
* R2M07_AdcClockControlBits_t
* RegisterName: ADC_CLOCK_CONTROL
* ADC clock control
* Address: 0x300
* ResetValue: 0x0000001F
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
	* BitsName: adcsync_skew_ctrl
	* Description: adcsync_skew_ctrl = 00 => delay set to 0 ps
	* adcsync_skew_ctrl = 01 => delay set to 100 ps
	* adcsync_skew_ctrl = 10 => delay set to 200 ps
	* adcsync_skew_ctrl = 11 => delay set to 300 ps
	* Read/Write: RW
	* Bits: [6:5]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcsyncSkewCtrl : 2;        /*## attribute AdcsyncSkewCtrl */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
}R2M07_AdcClockControlBits_t;
/**
* R2M07_CrcErrorStatus1Bits_t
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
}R2M07_CrcErrorStatus1Bits_t;
/**
* R2M07_CrcErrorStatus2Bits_t
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
}R2M07_CrcErrorStatus2Bits_t;
/**
* R2M07_CrcErrorStatus3Bits_t
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
	* Note: The status corresponds to next 32 registers listed i.e registers 95(msb) down to 64(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 32;        /*## attribute CrcErrorStatusReg3 */
}R2M07_CrcErrorStatus3Bits_t;
/**
* R2M07_CrcErrorStatus4Bits_t
* RegisterName: CRC_ERROR_STATUS4
* Status of the CRC for each register
* Address: 0xF4C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg4
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to last 22 registers listed i.e registers 117(msb) down to 96(lsb) and other bits are not valid 
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg4 : 32;        /*## attribute CrcErrorStatusReg4 */
}R2M07_CrcErrorStatus4Bits_t;
/**
* R2M07_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00075001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* The 8 msb's are derived from the 8 msb's of a 16 bit RTL parameter
	* Read/Write: R
	* Bits: [31:24]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 8;        /*## attribute Identifier */
	/**
	* BitsName: mod_id
	* Description: Module identifier. The 8 lsb's are determined by hardware ties at ADC Digital Core level
	* Read/Write: R
	* Bits: [23:16]
	* ResetValue: 0b00000111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ModId : 8;        /*## attribute ModId */
	/**
	* BitsName: major_revision
	* Description: Major revision i.e. implies software modifications
	* Derived from the 8 bit RTL parameter
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRevision : 4;        /*## attribute MajorRevision */
	/**
	* BitsName: minor_revision
	* Description: Minor revision numer i.e. with no software consequences
	* Derived from the 8 bit RTL parameter
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
}R2M07_ModuleIdBits_t;
#endif
/**
* R2M07_PonUnion_t
* R2M07_PonUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_PonBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_PonUnion_t;

/**
* R2M07_CalibrationStatusUnion_t
* R2M07_CalibrationStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CalibrationStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CalibrationStatusUnion_t;

/**
* R2M07_CalibrationStartUnion_t
* R2M07_CalibrationStartUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CalibrationStartBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CalibrationStartUnion_t;

/**
* R2M07_OutputPolarityControlUnion_t
* R2M07_OutputPolarityControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_OutputPolarityControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_OutputPolarityControlUnion_t;

/**
* R2M07_CliplevelControlUnion_t
* R2M07_CliplevelControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CliplevelControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CliplevelControlUnion_t;

/**
* R2M07_ErrorcountThresholdUnion_t
* R2M07_ErrorcountThresholdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_ErrorcountThresholdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_ErrorcountThresholdUnion_t;

/**
* R2M07_ClippingCounterOverviewUnion_t
* R2M07_ClippingCounterOverviewUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_ClippingCounterOverviewBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_ClippingCounterOverviewUnion_t;

/**
* R2M07_ErrorEventOverviewUnion_t
* R2M07_ErrorEventOverviewUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_ErrorEventOverviewBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_ErrorEventOverviewUnion_t;

/**
* R2M07_MaskCcResetErrorUnion_t
* R2M07_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_MaskCcResetErrorUnion_t;

/**
* R2M07_PowersaveControlUnion_t
* R2M07_PowersaveControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_PowersaveControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_PowersaveControlUnion_t;

/**
* R2M07_CalibrationControlUnion_t
* R2M07_CalibrationControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CalibrationControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CalibrationControlUnion_t;

/**
* R2M07_OutputmuxSettingUnion_t
* R2M07_OutputmuxSettingUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_OutputmuxSettingBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_OutputmuxSettingUnion_t;

/**
* R2M07_OutputmuxConstantUnion_t
* R2M07_OutputmuxConstantUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_OutputmuxConstantBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_OutputmuxConstantUnion_t;

/**
* R2M07_CalMonitorMaxErrorUnion_t
* R2M07_CalMonitorMaxErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CalMonitorMaxErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CalMonitorMaxErrorUnion_t;

/**
* R2M07_CalMonitorStatusUnion_t
* R2M07_CalMonitorStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CalMonitorStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CalMonitorStatusUnion_t;

/**
* R2M07_AdcClockControlUnion_t
* R2M07_AdcClockControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_AdcClockControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_AdcClockControlUnion_t;

/**
* R2M07_CrcErrorStatus1Union_t
* R2M07_CrcErrorStatus1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CrcErrorStatus1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CrcErrorStatus1Union_t;

/**
* R2M07_CrcErrorStatus2Union_t
* R2M07_CrcErrorStatus2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CrcErrorStatus2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CrcErrorStatus2Union_t;

/**
* R2M07_CrcErrorStatus3Union_t
* R2M07_CrcErrorStatus3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CrcErrorStatus3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CrcErrorStatus3Union_t;

/**
* R2M07_CrcErrorStatus4Union_t
* R2M07_CrcErrorStatus4Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_CrcErrorStatus4Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_CrcErrorStatus4Union_t;

/**
* R2M07_ModuleIdUnion_t
* R2M07_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M07_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M07_ModuleIdUnion_t;


#endif
