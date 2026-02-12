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
* @reg_es2_loi.h
*/
#ifndef REG_ES2_LOI_H
#define REG_ES2_LOI_H
#include <stdint.h>
/**
* R2M0A_LO_INTERFACE_CONTROL_U16
* RegisterName: MOD0A_LO_INTERFACE_CONTROL
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x00110000
*/
#define R2M0A_LO_INTERFACE_CONTROL_U16 (uint16_t)0x0000
/**
* R2M0A_LO_INTERFACE_GAIN_CONTROL_U16
* RegisterName: MOD0A_LO_INTERFACE_GAIN_CONTROL
* AccessMode: RW
* AddressRange: 0x0004 - 0x0008
* ResetValue: 0x0000020F
*/
#define R2M0A_LO_INTERFACE_GAIN_CONTROL_U16 (uint16_t)0x0004
/**
* R2M0A_BBD_CONTROL_U16
* RegisterName: MOD0A_BBD_CONTROL
* AccessMode: RW
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x00100100
*/
#define R2M0A_BBD_CONTROL_U16 (uint16_t)0x0008
/**
* R2M0A_FUNCSAFE_MON_LEVEL_SETTINGS_U16
* RegisterName: MOD0A_FUNCSAFE_MON_LEVEL_SETTINGS
* AccessMode: RW
* AddressRange: 0x000C - 0x0010
* ResetValue: 0x00000000
*/
#define R2M0A_FUNCSAFE_MON_LEVEL_SETTINGS_U16 (uint16_t)0x000C
/**
* R2M0A_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16
* RegisterName: MOD0A_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE
* AccessMode: RW
* AddressRange: 0x0010 - 0x0014
* ResetValue: 0x00000000
*/
#define R2M0A_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16 (uint16_t)0x0010
/**
* R2M0A_LOX3_GAIN_CONTROL_U16
* RegisterName: MOD0A_LOX3_GAIN_CONTROL
* AccessMode: RW
* AddressRange: 0x0018 - 0x001C
* ResetValue: 0x10001000
*/
#define R2M0A_LOX3_GAIN_CONTROL_U16 (uint16_t)0x0018
/**
* R2M0A_LOI_LUT_SEL_U16
* RegisterName: MOD0A_LOI_LUT_SEL
* AccessMode: RW
* AddressRange: 0x001C - 0x0020
* ResetValue: 0x00000000
*/
#define R2M0A_LOI_LUT_SEL_U16 (uint16_t)0x001C
/**
* R2M0A_LOX3_CHANNEL_DISABLE_U16
* RegisterName: MOD0A_LOX3_CHANNEL_DISABLE
* AccessMode: RW
* AddressRange: 0x0024 - 0x0028
* ResetValue: 0x00000000
*/
#define R2M0A_LOX3_CHANNEL_DISABLE_U16 (uint16_t)0x0024
/**
* R2M0A_LOX3_GAIN_CODE_EVAL_STATUS_U16
* RegisterName: MOD0A_LOX3_GAIN_CODE_EVAL_STATUS
* AccessMode: R
* AddressRange: 0x0028 - 0x002C
* ResetValue: 0x0000000F
*/
#define R2M0A_LOX3_GAIN_CODE_EVAL_STATUS_U16 (uint16_t)0x0028
/**
* R2M0A_RMS_CONTROL_U16
* RegisterName: MOD0A_RMS_CONTROL
* AccessMode: RW
* AddressRange: 0x0040 - 0x0044
* ResetValue: 0x00001000
*/
#define R2M0A_RMS_CONTROL_U16 (uint16_t)0x0040
/**
* R2M0A_RMS_MON_PTAT_BGR_CONTROL_U16
* RegisterName: MOD0A_RMS_MON_PTAT_BGR_CONTROL
* AccessMode: RW
* AddressRange: 0x0044 - 0x0048
* ResetValue: 0x00000088
*/
#define R2M0A_RMS_MON_PTAT_BGR_CONTROL_U16 (uint16_t)0x0044
/**
* R2M0A_LO_ACTIVE_CONTROL_U16
* RegisterName: MOD0A_LO_ACTIVE_CONTROL
* AccessMode: RW
* AddressRange: 0x0048 - 0x004C
* ResetValue: 0x00010028
*/
#define R2M0A_LO_ACTIVE_CONTROL_U16 (uint16_t)0x0048
/**
* R2M0A_LO_INTERFACE_B2_GAIN_CAL_START_U16
* RegisterName: MOD0A_LO_INTERFACE_B2_GAIN_CAL_START
* AccessMode: W
* AddressRange: 0x0060 - 0x0064
* ResetValue: 0x00000000
*/
#define R2M0A_LO_INTERFACE_B2_GAIN_CAL_START_U16 (uint16_t)0x0060
/**
* R2M0A_LO_INTERFACE_B2_GAIN_CAL_CONTROL_U16
* RegisterName: MOD0A_LO_INTERFACE_B2_GAIN_CAL_CONTROL
* AccessMode: RW
* AddressRange: 0x0064 - 0x0068
* ResetValue: 0x00280004
*/
#define R2M0A_LO_INTERFACE_B2_GAIN_CAL_CONTROL_U16 (uint16_t)0x0064
/**
* R2M0A_LO_INTERFACE_B2_GAIN_CAL_STATUS_U16
* RegisterName: MOD0A_LO_INTERFACE_B2_GAIN_CAL_STATUS
* AccessMode: R
* AddressRange: 0x0068 - 0x006C
* ResetValue: 0x00000000
*/
#define R2M0A_LO_INTERFACE_B2_GAIN_CAL_STATUS_U16 (uint16_t)0x0068
/**
* R2M0A_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD0A_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0E04 - 0x0E08
* ResetValue: 0x00000110
*/
#define R2M0A_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0E04
/**
* R2M0A_CRC_ERROR_STATUS_U16
* RegisterName: MOD0A_CRC_ERROR_STATUS
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M0A_CRC_ERROR_STATUS_U16 (uint16_t)0x0F40
/**
* R2M0A_MODULE_ID_U16
* RegisterName: MOD0A_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x000A5001
*/
#define R2M0A_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M0A_LoInterfaceControlBits_t
* RegisterName: LO_INTERFACE_CONTROL
* LO control settings register. Please refer LO interface specification to get the better understanding of the control bits
* Address: 0x000
* ResetValue: 0x00110000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: gain_code_direct
	* Description: Direct 8 bit control for the gain_code
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t GainCodeDirect : 8;        /*## attribute GainCodeDirect */
	/**
	* BitsName: cntr_mux_lo_spi
	* Description: Select the LO source: 
	* 0 = LO from chirp, 
	* 1 = external LO (LO-in port)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CntrMuxLoSpi : 1;        /*## attribute CntrMuxLoSpi */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: en_rterm_loio
	* Description: not_used
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnRtermLoio : 1;        /*## attribute EnRtermLoio */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: en_b1
	* Description: en_b1 Description: 
	* "Enable buffer b1. This buffer connects internal Chirp signal to buffer b4 and  MUX. This bit also needs to be set when doing the loop back test. 
	* 0=Disable 
	* 1=Enable"
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnB1 : 1;        /*## attribute EnB1 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: en_b2
	* Description: "Enable buffer b2. This buffer connects the LO signal either external or internal to the core IP's (RX/TX/RFbist). This bit also needs to be set when doing the loop back test. 
	* 0=Disable 
	* 1=Enable" 
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnB2 : 1;        /*## attribute EnB2 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: en_b3
	* Description: "Enable buffer b3. Connect external LO signal comming from lo_in to the  MUX. 
	* This bit also needs to be set when doing the loop back test. 
	* 0=Disable 
	* 1=Enable"
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnB3 : 1;        /*## attribute EnB3 */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: en_b4
	* Description: "Enable buffer b4. Connect Chirp signal to lo_out (to send external to chip). This bit also needs to be set when doing the loop back test. 
	* 0=Disable 
	* 1=Enable"
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnB4 : 1;        /*## attribute EnB4 */
	/**
	* BitsName: ctrl_switch
	* Description: turn on/OFF the loopthrough switch which connect the output of buffer B4 to the input of buffer B3. Used only at wafer test.
	* 0=switch open
	* 1=switch closed
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtrlSwitch : 1;        /*## attribute CtrlSwitch */
	/**
	* BitsName: pon_ls_spi
	* Description: 
	* This bit controls the level shifter. This is used for validation purpose only. In the functional context, the central control pon register is used for enabling the level shifter
	* 1 = pon enable for the level shifter
	* 0 = pon disable for the level shifter
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonLsSpi : 1;        /*## attribute PonLsSpi */
	/**
	* BitsName: en_lo
	* Description: 1= enable LO
	* 0 =disable LO
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnLo : 1;        /*## attribute EnLo */
}R2M0A_LoInterfaceControlBits_t;
/**
* R2M0A_LoInterfaceGainControlBits_t
* RegisterName: LO_INTERFACE_GAIN_CONTROL
* LO Gain control register 
* Address: 0x004
* ResetValue: 0x0000020F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: gain_code_lut
	* Description: LOI B2 level setting if LUT mode is used (bitfield gain_control_sel[1:0] = 0)
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: Application
	* FuSa: No
	*/
	uint32_t GainCodeLut : 5;        /*## attribute GainCodeLut */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: gain_control_sel
	* Description: 00 : Gain Code output comes out of gain_code_lut[4:0] defined in this register
	* 01 :  Direct 8 bit gain code from lo_interface_control register  field gain_code_direct (only for debug purpose)
	* 10 : Gain code derived out of the calibration : Default Setting
	* 11 : RESERVED
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b10
	* Source: Application
	* FuSa: No
	*/
	uint32_t GainControlSel : 2;        /*## attribute GainControlSel */
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
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M0A_LoInterfaceGainControlBits_t;
/**
* R2M0A_BbdControlBits_t
* RegisterName: BBD_CONTROL
* This register is used to set the controls for the ball break detector
* Address: 0x008
* ResetValue: 0x00100100
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: bb_loout_grounded_spi
	* Description: Balun grounded. 
	* 0 = not grounded 
	* 1 = grounded
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLooutGroundedSpi : 1;        /*## attribute BbLooutGroundedSpi */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: bb_loout_idetect_spi
	* Description: Ball break current detection. 
	* 1=normal sensitivity (50uA test) 
	* 0=high sensitivity for long differential antenna feed-lines (500uA)
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLooutIdetectSpi : 1;        /*## attribute BbLooutIdetectSpi */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: bb_loout_en_spi
	* Description: Ball break detector enable. By default it is enabled
	* 1: Enabled
	* 0: Disabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLooutEnSpi : 1;        /*## attribute BbLooutEnSpi */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: bb_loin_grounded_spi
	* Description: Balun grounded. 
	* 0 = not grounded 
	* 1 = grounded
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLoinGroundedSpi : 1;        /*## attribute BbLoinGroundedSpi */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: bb_loin_idetect_spi
	* Description: Ball break current detection. 
	* 1=normal sensitivity (50uA test) 
	* 0=high sensitivity for long differential antenna feed-lines (500uA)
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLoinIdetectSpi : 1;        /*## attribute BbLoinIdetectSpi */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: bb_loin_en_spi
	* Description: Ball break detector enable. By default it is enabled
	* 1: Enabled
	* 0: Disabled
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLoinEnSpi : 1;        /*## attribute BbLoinEnSpi */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 11;        /*## attribute Reserved5 */
}R2M0A_BbdControlBits_t;
/**
* R2M0A_FuncsafeMonLevelSettingsBits_t
* RegisterName: FUNCSAFE_MON_LEVEL_SETTINGS
* LOI level  sensor settings
* Address: 0x00C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: level_loi_min_spi
	* Description: Min trigger level for Gain Control, 
	* 
	* V_thresh_min=0.9*10^(((level_loi_min_spi  - 63)*0.29)/20)
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LevelLoiMinSpi : 6;        /*## attribute LevelLoiMinSpi */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: level_loi_low_spi
	* Description: Low trigger level for Gain Control, 
	* V_thresh_low=0.9*10^((((level_loi_low_spi  - 63)*0.29)/20)
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LevelLoiLowSpi : 6;        /*## attribute LevelLoiLowSpi */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: level_loi_high_spi
	* Description: High trigger level for Gain Control,
	* 
	* V_thresh_high=0.9*10^((((level_loi_high_spi  - 63)*0.29)/20)
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LevelLoiHighSpi : 6;        /*## attribute LevelLoiHighSpi */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: level_loi_max_spi
	* Description: Max trigger level for Gain Control, 
	* 
	* V_thresh_max=0.9*10^(((level_loi_max_spi - 63)*0.29)/20)
	* Read/Write: RW
	* Bits: [29:24]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LevelLoiMaxSpi : 6;        /*## attribute LevelLoiMaxSpi */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
}R2M0A_FuncsafeMonLevelSettingsBits_t;
/**
* R2M0A_FuncsafeMonLevelSettingsEnableBits_t
* RegisterName: FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE
* This register is used to enable the LOI level detectors
* Address: 0x010
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: en_rmsdet_loi
	* Description: Enable LO level detector
	* 1: Enable
	* 0: Disable
	* 
	* Set this to '1'  always in application
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t EnRmsdetLoi : 1;        /*## attribute EnRmsdetLoi */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M0A_FuncsafeMonLevelSettingsEnableBits_t;
/**
* R2M0A_Lox3GainControlBits_t
* RegisterName: LOX3_GAIN_CONTROL
* Control the lox3 gain of TX, RX, SSB from LO. There are also local lox3_gain settings in TX, RX, SSB to override this value
* Address: 0x018
* ResetValue: 0x10001000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: lox3_gain_ctrl
	* Description: Control of the lox3 gain of RX, SSB. 
	* Note: local override in subsystems possible
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Lox3GainCtrl : 5;        /*## attribute Lox3GainCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: rx_lox3_min_max_avg_sel
	* Description: This field controls how the combined RX LOX3 gain code is calculated from the individual RX LOX3 calibration results
	* 00: max
	* 01: min
	* 10: avg
	* 11: RESERVED
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RxLox3MinMaxAvgSel : 2;        /*## attribute RxLox3MinMaxAvgSel */
	/**
	* BitsName: rx_lox3_gain_sel
	* Description: 00: rx_lox3_min_max_avg_val
	* 01: rx_lox3_gain_ctrl_reg
	* 10: tx_lox3_gain_ctrl_reg
	* 11: tx_lox3_min_max_avg_val
	* Read/Write: RW
	* Bits: [11:10]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RxLox3GainSel : 2;        /*## attribute RxLox3GainSel */
	/**
	* BitsName: rx_lox3_gain_avg_round_up
	* Description: 0: round-down
	* 1: round-up
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RxLox3GainAvgRoundUp : 1;        /*## attribute RxLox3GainAvgRoundUp */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: tx_lox3_gain_ctrl
	* Description: Control of the lox3 gain of TX 
	* Note: local override in subsystems possible
	* Read/Write: RW
	* Bits: [20:16]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t TxLox3GainCtrl : 5;        /*## attribute TxLox3GainCtrl */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: tx_lox3_min_max_avg_sel
	* Description: This field controls how the combined TX LOX3 gain code is calculated from the individual TX LOX3 calibration results
	* 00: max
	* 01: min
	* 10: avg
	* 11: RESERVED
	* Read/Write: RW
	* Bits: [25:24]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t TxLox3MinMaxAvgSel : 2;        /*## attribute TxLox3MinMaxAvgSel */
	/**
	* BitsName: tx_lox3_gain_sel
	* Description: 00: tx_lox3_min_max_avg_val
	* 01: tx_lox3_gain_ctrl_reg
	* 10: rx_lox3_gain_ctrl_reg
	* 11: rx_lox3_min_max_avg_val
	* Read/Write: RW
	* Bits: [27:26]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t TxLox3GainSel : 2;        /*## attribute TxLox3GainSel */
	/**
	* BitsName: tx_lox3_gain_avg_round_up
	* Description: 0: round-down
	* 1: round-up
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t TxLox3GainAvgRoundUp : 1;        /*## attribute TxLox3GainAvgRoundUp */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
}R2M0A_Lox3GainControlBits_t;
/**
* R2M0A_LoiLutSelBits_t
* RegisterName: LOI_LUT_SEL
* LOI LUT selection based on the sample corner
* Address: 0x01C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: loi_lut_sel_ctrl
	* Description: LUT table selection: 0, 1, 2 (from OTP) to select which of the 3 LUT's needs to be used
	* 00 = Med
	* 01 = Low
	* 10 = High
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LoiLutSelCtrl : 2;        /*## attribute LoiLutSelCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
}R2M0A_LoiLutSelBits_t;
/**
* R2M0A_Lox3ChannelDisableBits_t
* RegisterName: LOX3_CHANNEL_DISABLE
* This register is used to locally disable (default enabled) a particular TX/RX channel for LOX3 gain calculation. 
* Address: 0x024
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: rx1_disabled
	* Description: Local RX Channel 1 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Rx1Disabled : 1;        /*## attribute Rx1Disabled */
	/**
	* BitsName: rx2_disabled
	* Description: Local RX Channel 2 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Rx2Disabled : 1;        /*## attribute Rx2Disabled */
	/**
	* BitsName: rx3_disabled
	* Description: Local RX Channel 3 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Rx3Disabled : 1;        /*## attribute Rx3Disabled */
	/**
	* BitsName: rx4_disabled
	* Description: Local RX Channel 4 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Rx4Disabled : 1;        /*## attribute Rx4Disabled */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 12;        /*## attribute Reserved0 */
	/**
	* BitsName: tx1_disabled
	* Description: Local TX Channel 1 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Tx1Disabled : 1;        /*## attribute Tx1Disabled */
	/**
	* BitsName: tx2_disabled
	* Description: Local TX Channel 2 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Tx2Disabled : 1;        /*## attribute Tx2Disabled */
	/**
	* BitsName: tx3_disabled
	* Description: Local TX Channel 3 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Tx3Disabled : 1;        /*## attribute Tx3Disabled */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 13;        /*## attribute Reserved1 */
}R2M0A_Lox3ChannelDisableBits_t;
/**
* R2M0A_Lox3GainCodeEvalStatusBits_t
* RegisterName: LOX3_GAIN_CODE_EVAL_STATUS
* LOX3 gain_codes are selected from a varied combinations of TX and RX gain_codes based on the LOX3_gain_control register configuration. This status register gives the final selected lox3 gain code for TX and RX. The  rx_lox3_gain_code value is also driven to the SSBMOD instance
* Address: 0x028
* ResetValue: 0x0000000F
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: rx_lox3_gain_code_value
	* Description: lox3_gain_code selected to be transmitted to the 4 RX instances and the SSBMOD instance
	* Read/Write: R
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxLox3GainCodeValue : 5;        /*## attribute RxLox3GainCodeValue */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 11;        /*## attribute Reserved0 */
	/**
	* BitsName: tx_lox3_gain_code_value
	* Description: lox3_gain_code selected to be transmitted to the 3 TX instances
	* Read/Write: R
	* Bits: [20:16]
	* ResetValue: 0b00000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxLox3GainCodeValue : 5;        /*## attribute TxLox3GainCodeValue */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 11;        /*## attribute Reserved1 */
}R2M0A_Lox3GainCodeEvalStatusBits_t;
/**
* R2M0A_RmsControlBits_t
* RegisterName: RMS_CONTROL
* calibration control setting for the rms detector
* Address: 0x040
* ResetValue: 0x00001000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 6;        /*## attribute Reserved0 */
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
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: loi_level_rf_meas_in_out_spi
	* Description: Select input or output of power detector. 
	* 0=input
	* 1=output
	* 
	* Set this bit to '1' in application
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t LoiLevelRfMeasInOutSpi : 1;        /*## attribute LoiLevelRfMeasInOutSpi */
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
	uint32_t Reserved8 : 11;        /*## attribute Reserved8 */
}R2M0A_RmsControlBits_t;
/**
* R2M0A_RmsMonPtatBgrControlBits_t
* RegisterName: RMS_MON_PTAT_BGR_CONTROL
* PTAT & BGR control for RMS_MON
* Address: 0x044
* ResetValue: 0x00000088
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_rms_mon_bgr_ctrl
	* Description: Control for RMS_MON Bias current bgr
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b1000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtrlIrefRmsMonBgrCtrl : 4;        /*## attribute CtrlIrefRmsMonBgrCtrl */
	/**
	* BitsName: ctrl_iref_rms_mon_ptat_ctrl
	* Description: Control for RMS_MON Bias current ptat
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b1000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtrlIrefRmsMonPtatCtrl : 4;        /*## attribute CtrlIrefRmsMonPtatCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
}R2M0A_RmsMonPtatBgrControlBits_t;
/**
* R2M0A_LoActiveControlBits_t
* RegisterName: LO_ACTIVE_CONTROL
* LO active generation delay control
* Address: 0x048
* ResetValue: 0x00010028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: lo_active_delay_ctrl
	* Description: The control to lo_active from lo_en assertion point to enable precharge
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00101000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoActiveDelayCtrl : 8;        /*## attribute LoActiveDelayCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: lo_active_via_spi
	* Description: This bit will enable the lo_active through a user control
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoActiveViaSpi : 1;        /*## attribute LoActiveViaSpi */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 15;        /*## attribute Reserved1 */
}R2M0A_LoActiveControlBits_t;
/**
* R2M0A_LoInterfaceB2GainCalStartBits_t
* RegisterName: LO_INTERFACE_B2_GAIN_CAL_START
* Calibration initiation
* Address: 0x060
* ResetValue: 0x00000000
* Read/Write: W
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: loi_start_cal
	* Description: When set to 1 by user, calibration will start (cleared automatically)
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LoiStartCal : 1;        /*## attribute LoiStartCal */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M0A_LoInterfaceB2GainCalStartBits_t;
/**
* R2M0A_LoInterfaceB2GainCalControlBits_t
* RegisterName: LO_INTERFACE_B2_GAIN_CAL_CONTROL
* Calibration counters configuration
* Address: 0x064
* ResetValue: 0x00280004
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: loi_mon_cnt_threshold
	* Description: MON counter threshold - default 100ns
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiMonCntThreshold : 8;        /*## attribute LoiMonCntThreshold */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: loi_det_cnt_threshold
	* Description: DET counter threshold - default 1us
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00101000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiDetCntThreshold : 8;        /*## attribute LoiDetCntThreshold */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
	/**
	* BitsName: bin_search_from_above
	* Description: Enable the search-from-above feature
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BinSearchFromAbove : 1;        /*## attribute BinSearchFromAbove */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
}R2M0A_LoInterfaceB2GainCalControlBits_t;
/**
* R2M0A_LoInterfaceB2GainCalStatusBits_t
* RegisterName: LO_INTERFACE_B2_GAIN_CAL_STATUS
* LO Calibration status bits
* Address: 0x068
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: loi_cal_error
	* Description: Error only as status based on the error flags at the end of calibration given by:
	* level_loi_low_error_flag || level_loi_high_error_flag
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiCalError : 1;        /*## attribute LoiCalError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: loi_cal_busy
	* Description: Set to 1 when calibration is ongoing
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiCalBusy : 1;        /*## attribute LoiCalBusy */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: loi_bin_search_gain_code_direct
	* Description: Calibration based gain_code_direct which is updated after every stage of the binary search
	* Read/Write: R
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiBinSearchGainCodeDirect : 8;        /*## attribute LoiBinSearchGainCodeDirect */
	/**
	* BitsName: loi_cal_done
	* Description: Calibration completion status. 1 indicates cal_done - the status remains high until a reset or until the initiation of another calibration 
	* Read/Write: R
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiCalDone : 1;        /*## attribute LoiCalDone */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 15;        /*## attribute Reserved2 */
}R2M0A_LoInterfaceB2GainCalStatusBits_t;
/**
* R2M0A_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This register is kept for validation and not to be used in the functional context
* Address: 0xE04
* ResetValue: 0x00000110
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_supply_low_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1: Mask the reset error
	* 0: Unmask the reset error
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
	* BitsName: mask_bb_loout_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1: Mask the reset error
	* 0: Unmask the reset error
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskBbLooutResetError : 1;        /*## attribute MaskBbLooutResetError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mask_bb_loin_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1: Mask the reset error
	* 0: Unmask the reset error
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskBbLoinResetError : 1;        /*## attribute MaskBbLoinResetError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1: Mask the reset error
	* 0: Unmask the reset error
	* Read/Write: RW
	* Bits: [12]
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
	* BitsName: mask_level_loi_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor = Level min
	* 1: Mask the reset error
	* 0: Unmask the reset error
	* 
	* Note: There is only one level_reset_error towards analog. 
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskLevelLoiResetError : 1;        /*## attribute MaskLevelLoiResetError */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 15;        /*## attribute Reserved4 */
}R2M0A_MaskCcResetErrorBits_t;
/**
* R2M0A_CrcErrorStatusBits_t
* RegisterName: CRC_ERROR_STATUS
* Status of the CRC for each register
* Address: 0xF40
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to first 26 registers listed i.e registers 25(msb) down to 0(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg : 32;        /*## attribute CrcErrorStatusReg */
}R2M0A_CrcErrorStatusBits_t;
/**
* R2M0A_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x000A5001
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
	* ResetValue: 0b0000000000001010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M0A_ModuleIdBits_t;

 #else
/**
* R2M0A_LoInterfaceControlBits_t
* RegisterName: LO_INTERFACE_CONTROL
* LO control settings register. Please refer LO interface specification to get the better understanding of the control bits
* Address: 0x000
* ResetValue: 0x00110000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: en_lo
	* Description: 1= enable LO
	* 0 =disable LO
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnLo : 1;        /*## attribute EnLo */
	/**
	* BitsName: pon_ls_spi
	* Description: 
	* This bit controls the level shifter. This is used for validation purpose only. In the functional context, the central control pon register is used for enabling the level shifter
	* 1 = pon enable for the level shifter
	* 0 = pon disable for the level shifter
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonLsSpi : 1;        /*## attribute PonLsSpi */
	/**
	* BitsName: ctrl_switch
	* Description: turn on/OFF the loopthrough switch which connect the output of buffer B4 to the input of buffer B3. Used only at wafer test.
	* 0=switch open
	* 1=switch closed
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtrlSwitch : 1;        /*## attribute CtrlSwitch */
	/**
	* BitsName: en_b4
	* Description: "Enable buffer b4. Connect Chirp signal to lo_out (to send external to chip). This bit also needs to be set when doing the loop back test. 
	* 0=Disable 
	* 1=Enable"
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnB4 : 1;        /*## attribute EnB4 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: en_b3
	* Description: "Enable buffer b3. Connect external LO signal comming from lo_in to the  MUX. 
	* This bit also needs to be set when doing the loop back test. 
	* 0=Disable 
	* 1=Enable"
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnB3 : 1;        /*## attribute EnB3 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: en_b2
	* Description: "Enable buffer b2. This buffer connects the LO signal either external or internal to the core IP's (RX/TX/RFbist). This bit also needs to be set when doing the loop back test. 
	* 0=Disable 
	* 1=Enable" 
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnB2 : 1;        /*## attribute EnB2 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: en_b1
	* Description: en_b1 Description: 
	* "Enable buffer b1. This buffer connects internal Chirp signal to buffer b4 and  MUX. This bit also needs to be set when doing the loop back test. 
	* 0=Disable 
	* 1=Enable"
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnB1 : 1;        /*## attribute EnB1 */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: en_rterm_loio
	* Description: not_used
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnRtermLoio : 1;        /*## attribute EnRtermLoio */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: cntr_mux_lo_spi
	* Description: Select the LO source: 
	* 0 = LO from chirp, 
	* 1 = external LO (LO-in port)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CntrMuxLoSpi : 1;        /*## attribute CntrMuxLoSpi */
	/**
	* BitsName: gain_code_direct
	* Description: Direct 8 bit control for the gain_code
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t GainCodeDirect : 8;        /*## attribute GainCodeDirect */
}R2M0A_LoInterfaceControlBits_t;
/**
* R2M0A_LoInterfaceGainControlBits_t
* RegisterName: LO_INTERFACE_GAIN_CONTROL
* LO Gain control register 
* Address: 0x004
* ResetValue: 0x0000020F
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
	* BitsName: gain_control_sel
	* Description: 00 : Gain Code output comes out of gain_code_lut[4:0] defined in this register
	* 01 :  Direct 8 bit gain code from lo_interface_control register  field gain_code_direct (only for debug purpose)
	* 10 : Gain code derived out of the calibration : Default Setting
	* 11 : RESERVED
	* 
	* 
	* 
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b10
	* Source: Application
	* FuSa: No
	*/
	uint32_t GainControlSel : 2;        /*## attribute GainControlSel */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: gain_code_lut
	* Description: LOI B2 level setting if LUT mode is used (bitfield gain_control_sel[1:0] = 0)
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: Application
	* FuSa: No
	*/
	uint32_t GainCodeLut : 5;        /*## attribute GainCodeLut */
}R2M0A_LoInterfaceGainControlBits_t;
/**
* R2M0A_BbdControlBits_t
* RegisterName: BBD_CONTROL
* This register is used to set the controls for the ball break detector
* Address: 0x008
* ResetValue: 0x00100100
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 11;        /*## attribute Reserved0 */
	/**
	* BitsName: bb_loin_en_spi
	* Description: Ball break detector enable. By default it is enabled
	* 1: Enabled
	* 0: Disabled
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLoinEnSpi : 1;        /*## attribute BbLoinEnSpi */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: bb_loin_idetect_spi
	* Description: Ball break current detection. 
	* 1=normal sensitivity (50uA test) 
	* 0=high sensitivity for long differential antenna feed-lines (500uA)
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLoinIdetectSpi : 1;        /*## attribute BbLoinIdetectSpi */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: bb_loin_grounded_spi
	* Description: Balun grounded. 
	* 0 = not grounded 
	* 1 = grounded
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLoinGroundedSpi : 1;        /*## attribute BbLoinGroundedSpi */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: bb_loout_en_spi
	* Description: Ball break detector enable. By default it is enabled
	* 1: Enabled
	* 0: Disabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLooutEnSpi : 1;        /*## attribute BbLooutEnSpi */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: bb_loout_idetect_spi
	* Description: Ball break current detection. 
	* 1=normal sensitivity (50uA test) 
	* 0=high sensitivity for long differential antenna feed-lines (500uA)
	* Leave as reset if not needed explicitly.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLooutIdetectSpi : 1;        /*## attribute BbLooutIdetectSpi */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: bb_loout_grounded_spi
	* Description: Balun grounded. 
	* 0 = not grounded 
	* 1 = grounded
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t BbLooutGroundedSpi : 1;        /*## attribute BbLooutGroundedSpi */
}R2M0A_BbdControlBits_t;
/**
* R2M0A_FuncsafeMonLevelSettingsBits_t
* RegisterName: FUNCSAFE_MON_LEVEL_SETTINGS
* LOI level  sensor settings
* Address: 0x00C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: level_loi_max_spi
	* Description: Max trigger level for Gain Control, 
	* 
	* V_thresh_max=0.9*10^(((level_loi_max_spi - 63)*0.29)/20)
	* Read/Write: RW
	* Bits: [29:24]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LevelLoiMaxSpi : 6;        /*## attribute LevelLoiMaxSpi */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: level_loi_high_spi
	* Description: High trigger level for Gain Control,
	* 
	* V_thresh_high=0.9*10^((((level_loi_high_spi  - 63)*0.29)/20)
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LevelLoiHighSpi : 6;        /*## attribute LevelLoiHighSpi */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: level_loi_low_spi
	* Description: Low trigger level for Gain Control, 
	* V_thresh_low=0.9*10^((((level_loi_low_spi  - 63)*0.29)/20)
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LevelLoiLowSpi : 6;        /*## attribute LevelLoiLowSpi */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: level_loi_min_spi
	* Description: Min trigger level for Gain Control, 
	* 
	* V_thresh_min=0.9*10^(((level_loi_min_spi  - 63)*0.29)/20)
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LevelLoiMinSpi : 6;        /*## attribute LevelLoiMinSpi */
}R2M0A_FuncsafeMonLevelSettingsBits_t;
/**
* R2M0A_FuncsafeMonLevelSettingsEnableBits_t
* RegisterName: FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE
* This register is used to enable the LOI level detectors
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
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: en_rmsdet_loi
	* Description: Enable LO level detector
	* 1: Enable
	* 0: Disable
	* 
	* Set this to '1'  always in application
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t EnRmsdetLoi : 1;        /*## attribute EnRmsdetLoi */
}R2M0A_FuncsafeMonLevelSettingsEnableBits_t;
/**
* R2M0A_Lox3GainControlBits_t
* RegisterName: LOX3_GAIN_CONTROL
* Control the lox3 gain of TX, RX, SSB from LO. There are also local lox3_gain settings in TX, RX, SSB to override this value
* Address: 0x018
* ResetValue: 0x10001000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: tx_lox3_gain_avg_round_up
	* Description: 0: round-down
	* 1: round-up
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t TxLox3GainAvgRoundUp : 1;        /*## attribute TxLox3GainAvgRoundUp */
	/**
	* BitsName: tx_lox3_gain_sel
	* Description: 00: tx_lox3_min_max_avg_val
	* 01: tx_lox3_gain_ctrl_reg
	* 10: rx_lox3_gain_ctrl_reg
	* 11: rx_lox3_min_max_avg_val
	* Read/Write: RW
	* Bits: [27:26]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t TxLox3GainSel : 2;        /*## attribute TxLox3GainSel */
	/**
	* BitsName: tx_lox3_min_max_avg_sel
	* Description: This field controls how the combined TX LOX3 gain code is calculated from the individual TX LOX3 calibration results
	* 00: max
	* 01: min
	* 10: avg
	* 11: RESERVED
	* Read/Write: RW
	* Bits: [25:24]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t TxLox3MinMaxAvgSel : 2;        /*## attribute TxLox3MinMaxAvgSel */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: tx_lox3_gain_ctrl
	* Description: Control of the lox3 gain of TX 
	* Note: local override in subsystems possible
	* Read/Write: RW
	* Bits: [20:16]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t TxLox3GainCtrl : 5;        /*## attribute TxLox3GainCtrl */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: rx_lox3_gain_avg_round_up
	* Description: 0: round-down
	* 1: round-up
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RxLox3GainAvgRoundUp : 1;        /*## attribute RxLox3GainAvgRoundUp */
	/**
	* BitsName: rx_lox3_gain_sel
	* Description: 00: rx_lox3_min_max_avg_val
	* 01: rx_lox3_gain_ctrl_reg
	* 10: tx_lox3_gain_ctrl_reg
	* 11: tx_lox3_min_max_avg_val
	* Read/Write: RW
	* Bits: [11:10]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RxLox3GainSel : 2;        /*## attribute RxLox3GainSel */
	/**
	* BitsName: rx_lox3_min_max_avg_sel
	* Description: This field controls how the combined RX LOX3 gain code is calculated from the individual RX LOX3 calibration results
	* 00: max
	* 01: min
	* 10: avg
	* 11: RESERVED
	* Read/Write: RW
	* Bits: [9:8]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RxLox3MinMaxAvgSel : 2;        /*## attribute RxLox3MinMaxAvgSel */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: lox3_gain_ctrl
	* Description: Control of the lox3 gain of RX, SSB. 
	* Note: local override in subsystems possible
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Lox3GainCtrl : 5;        /*## attribute Lox3GainCtrl */
}R2M0A_Lox3GainControlBits_t;
/**
* R2M0A_LoiLutSelBits_t
* RegisterName: LOI_LUT_SEL
* LOI LUT selection based on the sample corner
* Address: 0x01C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
	/**
	* BitsName: loi_lut_sel_ctrl
	* Description: LUT table selection: 0, 1, 2 (from OTP) to select which of the 3 LUT's needs to be used
	* 00 = Med
	* 01 = Low
	* 10 = High
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t LoiLutSelCtrl : 2;        /*## attribute LoiLutSelCtrl */
}R2M0A_LoiLutSelBits_t;
/**
* R2M0A_Lox3ChannelDisableBits_t
* RegisterName: LOX3_CHANNEL_DISABLE
* This register is used to locally disable (default enabled) a particular TX/RX channel for LOX3 gain calculation. 
* Address: 0x024
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 13;        /*## attribute Reserved0 */
	/**
	* BitsName: tx3_disabled
	* Description: Local TX Channel 3 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Tx3Disabled : 1;        /*## attribute Tx3Disabled */
	/**
	* BitsName: tx2_disabled
	* Description: Local TX Channel 2 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Tx2Disabled : 1;        /*## attribute Tx2Disabled */
	/**
	* BitsName: tx1_disabled
	* Description: Local TX Channel 1 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Tx1Disabled : 1;        /*## attribute Tx1Disabled */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 12;        /*## attribute Reserved1 */
	/**
	* BitsName: rx4_disabled
	* Description: Local RX Channel 4 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Rx4Disabled : 1;        /*## attribute Rx4Disabled */
	/**
	* BitsName: rx3_disabled
	* Description: Local RX Channel 3 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Rx3Disabled : 1;        /*## attribute Rx3Disabled */
	/**
	* BitsName: rx2_disabled
	* Description: Local RX Channel 2 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Rx2Disabled : 1;        /*## attribute Rx2Disabled */
	/**
	* BitsName: rx1_disabled
	* Description: Local RX Channel 1 Disable
	* 0 = channel enabled
	* 1 = channel disabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Rx1Disabled : 1;        /*## attribute Rx1Disabled */
}R2M0A_Lox3ChannelDisableBits_t;
/**
* R2M0A_Lox3GainCodeEvalStatusBits_t
* RegisterName: LOX3_GAIN_CODE_EVAL_STATUS
* LOX3 gain_codes are selected from a varied combinations of TX and RX gain_codes based on the LOX3_gain_control register configuration. This status register gives the final selected lox3 gain code for TX and RX. The  rx_lox3_gain_code value is also driven to the SSBMOD instance
* Address: 0x028
* ResetValue: 0x0000000F
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
	* BitsName: tx_lox3_gain_code_value
	* Description: lox3_gain_code selected to be transmitted to the 3 TX instances
	* Read/Write: R
	* Bits: [20:16]
	* ResetValue: 0b00000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TxLox3GainCodeValue : 5;        /*## attribute TxLox3GainCodeValue */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 11;        /*## attribute Reserved1 */
	/**
	* BitsName: rx_lox3_gain_code_value
	* Description: lox3_gain_code selected to be transmitted to the 4 RX instances and the SSBMOD instance
	* Read/Write: R
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RxLox3GainCodeValue : 5;        /*## attribute RxLox3GainCodeValue */
}R2M0A_Lox3GainCodeEvalStatusBits_t;
/**
* R2M0A_RmsControlBits_t
* RegisterName: RMS_CONTROL
* calibration control setting for the rms detector
* Address: 0x040
* ResetValue: 0x00001000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 11;        /*## attribute Reserved0 */
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
	* BitsName: loi_level_rf_meas_in_out_spi
	* Description: Select input or output of power detector. 
	* 0=input
	* 1=output
	* 
	* Set this bit to '1' in application
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t LoiLevelRfMeasInOutSpi : 1;        /*## attribute LoiLevelRfMeasInOutSpi */
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
	uint32_t Reserved7 : 2;        /*## attribute Reserved7 */
	/**
	* BitsName: Reserved_8 
	* Description: not used 
	*/
	uint32_t Reserved8 : 6;        /*## attribute Reserved8 */
}R2M0A_RmsControlBits_t;
/**
* R2M0A_RmsMonPtatBgrControlBits_t
* RegisterName: RMS_MON_PTAT_BGR_CONTROL
* PTAT & BGR control for RMS_MON
* Address: 0x044
* ResetValue: 0x00000088
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
	* BitsName: ctrl_iref_rms_mon_ptat_ctrl
	* Description: Control for RMS_MON Bias current ptat
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b1000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtrlIrefRmsMonPtatCtrl : 4;        /*## attribute CtrlIrefRmsMonPtatCtrl */
	/**
	* BitsName: ctrl_iref_rms_mon_bgr_ctrl
	* Description: Control for RMS_MON Bias current bgr
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b1000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtrlIrefRmsMonBgrCtrl : 4;        /*## attribute CtrlIrefRmsMonBgrCtrl */
}R2M0A_RmsMonPtatBgrControlBits_t;
/**
* R2M0A_LoActiveControlBits_t
* RegisterName: LO_ACTIVE_CONTROL
* LO active generation delay control
* Address: 0x048
* ResetValue: 0x00010028
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
	* BitsName: lo_active_via_spi
	* Description: This bit will enable the lo_active through a user control
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoActiveViaSpi : 1;        /*## attribute LoActiveViaSpi */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 8;        /*## attribute Reserved1 */
	/**
	* BitsName: lo_active_delay_ctrl
	* Description: The control to lo_active from lo_en assertion point to enable precharge
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00101000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoActiveDelayCtrl : 8;        /*## attribute LoActiveDelayCtrl */
}R2M0A_LoActiveControlBits_t;
/**
* R2M0A_LoInterfaceB2GainCalStartBits_t
* RegisterName: LO_INTERFACE_B2_GAIN_CAL_START
* Calibration initiation
* Address: 0x060
* ResetValue: 0x00000000
* Read/Write: W
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: loi_start_cal
	* Description: When set to 1 by user, calibration will start (cleared automatically)
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LoiStartCal : 1;        /*## attribute LoiStartCal */
}R2M0A_LoInterfaceB2GainCalStartBits_t;
/**
* R2M0A_LoInterfaceB2GainCalControlBits_t
* RegisterName: LO_INTERFACE_B2_GAIN_CAL_CONTROL
* Calibration counters configuration
* Address: 0x064
* ResetValue: 0x00280004
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
	* BitsName: bin_search_from_above
	* Description: Enable the search-from-above feature
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BinSearchFromAbove : 1;        /*## attribute BinSearchFromAbove */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
	/**
	* BitsName: loi_det_cnt_threshold
	* Description: DET counter threshold - default 1us
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b00101000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiDetCntThreshold : 8;        /*## attribute LoiDetCntThreshold */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 8;        /*## attribute Reserved2 */
	/**
	* BitsName: loi_mon_cnt_threshold
	* Description: MON counter threshold - default 100ns
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiMonCntThreshold : 8;        /*## attribute LoiMonCntThreshold */
}R2M0A_LoInterfaceB2GainCalControlBits_t;
/**
* R2M0A_LoInterfaceB2GainCalStatusBits_t
* RegisterName: LO_INTERFACE_B2_GAIN_CAL_STATUS
* LO Calibration status bits
* Address: 0x068
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 15;        /*## attribute Reserved0 */
	/**
	* BitsName: loi_cal_done
	* Description: Calibration completion status. 1 indicates cal_done - the status remains high until a reset or until the initiation of another calibration 
	* Read/Write: R
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiCalDone : 1;        /*## attribute LoiCalDone */
	/**
	* BitsName: loi_bin_search_gain_code_direct
	* Description: Calibration based gain_code_direct which is updated after every stage of the binary search
	* Read/Write: R
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiBinSearchGainCodeDirect : 8;        /*## attribute LoiBinSearchGainCodeDirect */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: loi_cal_busy
	* Description: Set to 1 when calibration is ongoing
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiCalBusy : 1;        /*## attribute LoiCalBusy */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: loi_cal_error
	* Description: Error only as status based on the error flags at the end of calibration given by:
	* level_loi_low_error_flag || level_loi_high_error_flag
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoiCalError : 1;        /*## attribute LoiCalError */
}R2M0A_LoInterfaceB2GainCalStatusBits_t;
/**
* R2M0A_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This register is kept for validation and not to be used in the functional context
* Address: 0xE04
* ResetValue: 0x00000110
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
	* BitsName: mask_level_loi_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor = Level min
	* 1: Mask the reset error
	* 0: Unmask the reset error
	* 
	* Note: There is only one level_reset_error towards analog. 
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskLevelLoiResetError : 1;        /*## attribute MaskLevelLoiResetError */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1: Mask the reset error
	* 0: Unmask the reset error
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskRegCrcResetError : 1;        /*## attribute MaskRegCrcResetError */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_bb_loin_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1: Mask the reset error
	* 0: Unmask the reset error
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskBbLoinResetError : 1;        /*## attribute MaskBbLoinResetError */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mask_bb_loout_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1: Mask the reset error
	* 0: Unmask the reset error
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskBbLooutResetError : 1;        /*## attribute MaskBbLooutResetError */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: mask_supply_low_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1: Mask the reset error
	* 0: Unmask the reset error
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyLowResetError : 1;        /*## attribute MaskSupplyLowResetError */
}R2M0A_MaskCcResetErrorBits_t;
/**
* R2M0A_CrcErrorStatusBits_t
* RegisterName: CRC_ERROR_STATUS
* Status of the CRC for each register
* Address: 0xF40
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to first 26 registers listed i.e registers 25(msb) down to 0(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg : 32;        /*## attribute CrcErrorStatusReg */
}R2M0A_CrcErrorStatusBits_t;
/**
* R2M0A_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x000A5001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000001010
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
}R2M0A_ModuleIdBits_t;
#endif
/**
* R2M0A_LoInterfaceControlUnion_t
* R2M0A_LoInterfaceControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_LoInterfaceControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_LoInterfaceControlUnion_t;

/**
* R2M0A_LoInterfaceGainControlUnion_t
* R2M0A_LoInterfaceGainControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_LoInterfaceGainControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_LoInterfaceGainControlUnion_t;

/**
* R2M0A_BbdControlUnion_t
* R2M0A_BbdControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_BbdControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_BbdControlUnion_t;

/**
* R2M0A_FuncsafeMonLevelSettingsUnion_t
* R2M0A_FuncsafeMonLevelSettingsUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_FuncsafeMonLevelSettingsBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_FuncsafeMonLevelSettingsUnion_t;

/**
* R2M0A_FuncsafeMonLevelSettingsEnableUnion_t
* R2M0A_FuncsafeMonLevelSettingsEnableUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_FuncsafeMonLevelSettingsEnableBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_FuncsafeMonLevelSettingsEnableUnion_t;

/**
* R2M0A_Lox3GainControlUnion_t
* R2M0A_Lox3GainControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_Lox3GainControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_Lox3GainControlUnion_t;

/**
* R2M0A_LoiLutSelUnion_t
* R2M0A_LoiLutSelUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_LoiLutSelBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_LoiLutSelUnion_t;

/**
* R2M0A_Lox3ChannelDisableUnion_t
* R2M0A_Lox3ChannelDisableUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_Lox3ChannelDisableBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_Lox3ChannelDisableUnion_t;

/**
* R2M0A_Lox3GainCodeEvalStatusUnion_t
* R2M0A_Lox3GainCodeEvalStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_Lox3GainCodeEvalStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_Lox3GainCodeEvalStatusUnion_t;

/**
* R2M0A_RmsControlUnion_t
* R2M0A_RmsControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_RmsControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_RmsControlUnion_t;

/**
* R2M0A_RmsMonPtatBgrControlUnion_t
* R2M0A_RmsMonPtatBgrControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_RmsMonPtatBgrControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_RmsMonPtatBgrControlUnion_t;

/**
* R2M0A_LoActiveControlUnion_t
* R2M0A_LoActiveControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_LoActiveControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_LoActiveControlUnion_t;

/**
* R2M0A_LoInterfaceB2GainCalStartUnion_t
* R2M0A_LoInterfaceB2GainCalStartUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_LoInterfaceB2GainCalStartBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_LoInterfaceB2GainCalStartUnion_t;

/**
* R2M0A_LoInterfaceB2GainCalControlUnion_t
* R2M0A_LoInterfaceB2GainCalControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_LoInterfaceB2GainCalControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_LoInterfaceB2GainCalControlUnion_t;

/**
* R2M0A_LoInterfaceB2GainCalStatusUnion_t
* R2M0A_LoInterfaceB2GainCalStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_LoInterfaceB2GainCalStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_LoInterfaceB2GainCalStatusUnion_t;

/**
* R2M0A_MaskCcResetErrorUnion_t
* R2M0A_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_MaskCcResetErrorUnion_t;

/**
* R2M0A_CrcErrorStatusUnion_t
* R2M0A_CrcErrorStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_CrcErrorStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_CrcErrorStatusUnion_t;

/**
* R2M0A_ModuleIdUnion_t
* R2M0A_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M0A_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M0A_ModuleIdUnion_t;


#endif
