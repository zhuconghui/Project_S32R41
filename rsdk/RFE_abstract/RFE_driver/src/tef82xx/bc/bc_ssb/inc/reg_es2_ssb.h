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
* @reg_es2_ssb.h
*/
#ifndef REG_ES2_SSB_H
#define REG_ES2_SSB_H
#include <stdint.h>
/**
* R2M14_SSBMOD_CONTROL_U16
* RegisterName: MOD14_SSBMOD_CONTROL
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x00000000
*/
#define R2M14_SSBMOD_CONTROL_U16 (uint16_t)0x0000
/**
* R2M14_IF_CONTROL_U16
* RegisterName: MOD14_IF_CONTROL
* AccessMode: RW
* AddressRange: 0x0004 - 0x0008
* ResetValue: 0x00000020
*/
#define R2M14_IF_CONTROL_U16 (uint16_t)0x0004
/**
* R2M14_LEVEL_SET_U16
* RegisterName: MOD14_LEVEL_SET
* AccessMode: RW
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x00000020
*/
#define R2M14_LEVEL_SET_U16 (uint16_t)0x0008
/**
* R2M14_RMS_CONTROL_U16
* RegisterName: MOD14_RMS_CONTROL
* AccessMode: RW
* AddressRange: 0x000C - 0x0010
* ResetValue: 0x00000000
*/
#define R2M14_RMS_CONTROL_U16 (uint16_t)0x000C
/**
* R2M14_SYNC_START_CONTROL_U16
* RegisterName: MOD14_SYNC_START_CONTROL
* AccessMode: RW
* AddressRange: 0x0060 - 0x0064
* ResetValue: 0x00000000
*/
#define R2M14_SYNC_START_CONTROL_U16 (uint16_t)0x0060
/**
* R2M14_LOX3_GAIN_CONTROL_U16
* RegisterName: MOD14_LOX3_GAIN_CONTROL
* AccessMode: RW
* AddressRange: 0x0C00 - 0x0C04
* ResetValue: 0x00000000
*/
#define R2M14_LOX3_GAIN_CONTROL_U16 (uint16_t)0x0C00
/**
* R2M14_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD14_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0E04 - 0x0E08
* ResetValue: 0x00000000
*/
#define R2M14_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0E04
/**
* R2M14_CRC_ERROR_STATUS_U16
* RegisterName: MOD14_CRC_ERROR_STATUS
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M14_CRC_ERROR_STATUS_U16 (uint16_t)0x0F40
/**
* R2M14_MODULE_ID_U16
* RegisterName: MOD14_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x00143001
*/
#define R2M14_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M14_SsbmodControlBits_t
* RegisterName: SSBMOD_CONTROL
* This is the control register for SSB Module. This register also selects the divider ratios of varaiable dividers inside SSB Digital Module.
* i = div1_set / pow(2, div2set) / 4
* 
* q = 90' phase shift (div1_set / pow(2, div2set) / 4)
* Address: 0x000
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ssbmod_en
	* Description: SSB modulator Control
	* 0 = Disable SSB modulator
	* 1 = Enable SSB modulator
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SsbmodEn : 1;        /*## attribute SsbmodEn */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: mod_sel
	* Description: Select modulation input:
	* 0 = internal signal generator
	* 1 = external signal generator
	* 
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t ModSel : 1;        /*## attribute ModSel */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: en_rf_det
	* Description: Controls RMS Detector inside SSB Module
	* 0 = Disable RMS detector
	* 1 = Enable RMS detector
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t EnRfDet : 1;        /*## attribute EnRfDet */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: div1_set
	* Description: Select division ratio N1 of DIV1(First Divider in the divider chan in SSB Digital Module) (divider ratio = programmed value + 1)
	* Read/Write: RW
	* Bits: [16:12]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Div1Set : 5;        /*## attribute Div1Set */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: div2_set
	* Description: Select division ratio N2 of DIV2(second stage divider) inside SSB Digital Module.
	* 000 = Select the divider ratio as  1
	* 001 = Select the divider ratio as  4
	* 010 = Select the divider ratio as  16
	* 011 = Select the divider ratio as  64
	* 100 = Select the divider ratio as  256
	* 101 = Select the divider ratio as  1024 
	* 
	* Read/Write: RW
	* Bits: [22:20]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Div2Set : 3;        /*## attribute Div2Set */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: pon_ls_spi
	* Description: This enables the level shifters between digital and analogue modules
	* 0 = Disable the Level Shifters
	* 1 = Enable the Level Shifters
	* Note: the main pon_ls comes from the Central Controller. Hence not necessary to set this bit
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t PonLsSpi : 1;        /*## attribute PonLsSpi */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: clk_600_en
	* Description: This is the clock enable signal for analogue module.
	* 0 = Disable the 600Mhz Clock from MasterClock
	* 1 = Enable the 600Mhz Clock from MasterClock
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Clk600En : 1;        /*## attribute Clk600En */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
}R2M14_SsbmodControlBits_t;
/**
* R2M14_IfControlBits_t
* RegisterName: IF_CONTROL
* IF level control register
* Address: 0x004
* ResetValue: 0x00000020
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: if_level_set
	* Description: IF level control: 
	* bits [2:0] sweep in 4dB steps 
	* bit [3] provides 18dB step
	* bits [5:4] are unused/not connected
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t IfLevelSet : 6;        /*## attribute IfLevelSet */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M14_IfControlBits_t;
/**
* R2M14_LevelSetBits_t
* RegisterName: LEVEL_SET
* Control SSB modulator output level [dBm]
* 
* 
* Address: 0x008
* ResetValue: 0x00000020
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: level_set_ctrl
	* Description: Control SSB modulator output amplifier level. Recommended a fixed output level 0x3F and use the IF_LEVEL_SET bitfield in IF_CONTROL register to control the SSBMOD gain
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b100000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LevelSetCtrl : 6;        /*## attribute LevelSetCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M14_LevelSetBits_t;
/**
* R2M14_RmsControlBits_t
* RegisterName: RMS_CONTROL
* nan
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
	* BitsName: meas_in_out_level_rf
	* Description: Select input or output of power detector. 
	* 0 = input
	* 1 = output
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t MeasInOutLevelRf : 1;        /*## attribute MeasInOutLevelRf */
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
}R2M14_RmsControlBits_t;
/**
* R2M14_SyncStartControlBits_t
* RegisterName: SYNC_START_CONTROL
* Controls the synchronous start operation of the SSB across leader and follower devices. This register is used only in the context of leader-follower devices configuration
* Address: 0x060
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: enable_sync_start
	* Description: Setting this bit to '1', will reset the dividers (div1, div2, div3) and bring back the divided clocks with the same phase across the Leader-Follower chips after the internal reset release. The chirp_start signal is used for this purpose. 
	* 0: Normal operation
	* 1: Divided clock phase alignment is enabled across the chips for the leader-follower usecase
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t EnableSyncStart : 1;        /*## attribute EnableSyncStart */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: chirp_start_sync_600mhz_sel
	* Description: Chirp_start signal synchronization with ssb_600Mhz clock before resetting the dividers to align the phase. 
	* 
	* 0 : chirp_start synchronized with 600Mhz posedge
	* 
	* 1: chirp_start synchronized with 600Mhz negedge
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ChirpStartSync600MhzSel : 1;        /*## attribute ChirpStartSync600MhzSel */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M14_SyncStartControlBits_t;
/**
* R2M14_Lox3GainControlBits_t
* RegisterName: LOX3_GAIN_CONTROL
* LOX3 gain control settings
* Address: 0xC00
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: lox3_gain_ctrl
	* Description: local lox3_gain setting when lox3_gain_source is high
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b00000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Lox3GainCtrl : 5;        /*## attribute Lox3GainCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: lox3_gain_source
	* Description: Source of LOX3 gain control
	* 
	* 0: Common value for all LOI followers
	* 1: Local control from lox3_gain_ctrl[4:0] register
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Lox3GainSource : 1;        /*## attribute Lox3GainSource */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 23;        /*## attribute Reserved1 */
}R2M14_Lox3GainControlBits_t;
/**
* R2M14_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* Registers for validation purposes. Used to mask force_error from Central Controller
* Address: 0xE04
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_sup_low_reset_error
	* Description: 0 = Not Masked
	* 1 = Masked 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupLowResetError : 1;        /*## attribute MaskSupLowResetError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: 0 = Not Masked
	* 1 = Masked 
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
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M14_MaskCcResetErrorBits_t;
/**
* R2M14_CrcErrorStatusBits_t
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
	* Note: The status corresponds to first 24 registers listed i.e registers 23(msb) down to 0(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg : 32;        /*## attribute CrcErrorStatusReg */
}R2M14_CrcErrorStatusBits_t;
/**
* R2M14_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00143001
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
	* ResetValue: 0b0011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRevision : 4;        /*## attribute MajorRevision */
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000010100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M14_ModuleIdBits_t;

 #else
/**
* R2M14_SsbmodControlBits_t
* RegisterName: SSBMOD_CONTROL
* This is the control register for SSB Module. This register also selects the divider ratios of varaiable dividers inside SSB Digital Module.
* i = div1_set / pow(2, div2set) / 4
* 
* q = 90' phase shift (div1_set / pow(2, div2set) / 4)
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
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: clk_600_en
	* Description: This is the clock enable signal for analogue module.
	* 0 = Disable the 600Mhz Clock from MasterClock
	* 1 = Enable the 600Mhz Clock from MasterClock
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Clk600En : 1;        /*## attribute Clk600En */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: pon_ls_spi
	* Description: This enables the level shifters between digital and analogue modules
	* 0 = Disable the Level Shifters
	* 1 = Enable the Level Shifters
	* Note: the main pon_ls comes from the Central Controller. Hence not necessary to set this bit
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t PonLsSpi : 1;        /*## attribute PonLsSpi */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: div2_set
	* Description: Select division ratio N2 of DIV2(second stage divider) inside SSB Digital Module.
	* 000 = Select the divider ratio as  1
	* 001 = Select the divider ratio as  4
	* 010 = Select the divider ratio as  16
	* 011 = Select the divider ratio as  64
	* 100 = Select the divider ratio as  256
	* 101 = Select the divider ratio as  1024 
	* 
	* Read/Write: RW
	* Bits: [22:20]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Div2Set : 3;        /*## attribute Div2Set */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: div1_set
	* Description: Select division ratio N1 of DIV1(First Divider in the divider chan in SSB Digital Module) (divider ratio = programmed value + 1)
	* Read/Write: RW
	* Bits: [16:12]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Div1Set : 5;        /*## attribute Div1Set */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: en_rf_det
	* Description: Controls RMS Detector inside SSB Module
	* 0 = Disable RMS detector
	* 1 = Enable RMS detector
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t EnRfDet : 1;        /*## attribute EnRfDet */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: mod_sel
	* Description: Select modulation input:
	* 0 = internal signal generator
	* 1 = external signal generator
	* 
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t ModSel : 1;        /*## attribute ModSel */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: ssbmod_en
	* Description: SSB modulator Control
	* 0 = Disable SSB modulator
	* 1 = Enable SSB modulator
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SsbmodEn : 1;        /*## attribute SsbmodEn */
}R2M14_SsbmodControlBits_t;
/**
* R2M14_IfControlBits_t
* RegisterName: IF_CONTROL
* IF level control register
* Address: 0x004
* ResetValue: 0x00000020
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
	* BitsName: if_level_set
	* Description: IF level control: 
	* bits [2:0] sweep in 4dB steps 
	* bit [3] provides 18dB step
	* bits [5:4] are unused/not connected
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t IfLevelSet : 6;        /*## attribute IfLevelSet */
}R2M14_IfControlBits_t;
/**
* R2M14_LevelSetBits_t
* RegisterName: LEVEL_SET
* Control SSB modulator output level [dBm]
* 
* 
* Address: 0x008
* ResetValue: 0x00000020
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
	/**
	* BitsName: level_set_ctrl
	* Description: Control SSB modulator output amplifier level. Recommended a fixed output level 0x3F and use the IF_LEVEL_SET bitfield in IF_CONTROL register to control the SSBMOD gain
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b100000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LevelSetCtrl : 6;        /*## attribute LevelSetCtrl */
}R2M14_LevelSetBits_t;
/**
* R2M14_RmsControlBits_t
* RegisterName: RMS_CONTROL
* nan
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
	* BitsName: meas_in_out_level_rf
	* Description: Select input or output of power detector. 
	* 0 = input
	* 1 = output
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t MeasInOutLevelRf : 1;        /*## attribute MeasInOutLevelRf */
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
}R2M14_RmsControlBits_t;
/**
* R2M14_SyncStartControlBits_t
* RegisterName: SYNC_START_CONTROL
* Controls the synchronous start operation of the SSB across leader and follower devices. This register is used only in the context of leader-follower devices configuration
* Address: 0x060
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
	* BitsName: chirp_start_sync_600mhz_sel
	* Description: Chirp_start signal synchronization with ssb_600Mhz clock before resetting the dividers to align the phase. 
	* 
	* 0 : chirp_start synchronized with 600Mhz posedge
	* 
	* 1: chirp_start synchronized with 600Mhz negedge
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ChirpStartSync600MhzSel : 1;        /*## attribute ChirpStartSync600MhzSel */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: enable_sync_start
	* Description: Setting this bit to '1', will reset the dividers (div1, div2, div3) and bring back the divided clocks with the same phase across the Leader-Follower chips after the internal reset release. The chirp_start signal is used for this purpose. 
	* 0: Normal operation
	* 1: Divided clock phase alignment is enabled across the chips for the leader-follower usecase
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t EnableSyncStart : 1;        /*## attribute EnableSyncStart */
}R2M14_SyncStartControlBits_t;
/**
* R2M14_Lox3GainControlBits_t
* RegisterName: LOX3_GAIN_CONTROL
* LOX3 gain control settings
* Address: 0xC00
* ResetValue: 0x00000000
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
	* BitsName: lox3_gain_source
	* Description: Source of LOX3 gain control
	* 
	* 0: Common value for all LOI followers
	* 1: Local control from lox3_gain_ctrl[4:0] register
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Lox3GainSource : 1;        /*## attribute Lox3GainSource */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: lox3_gain_ctrl
	* Description: local lox3_gain setting when lox3_gain_source is high
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b00000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Lox3GainCtrl : 5;        /*## attribute Lox3GainCtrl */
}R2M14_Lox3GainControlBits_t;
/**
* R2M14_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* Registers for validation purposes. Used to mask force_error from Central Controller
* Address: 0xE04
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
	* BitsName: mask_reg_crc_reset_error
	* Description: 0 = Not Masked
	* 1 = Masked 
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
	* BitsName: mask_sup_low_reset_error
	* Description: 0 = Not Masked
	* 1 = Masked 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupLowResetError : 1;        /*## attribute MaskSupLowResetError */
}R2M14_MaskCcResetErrorBits_t;
/**
* R2M14_CrcErrorStatusBits_t
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
	* Note: The status corresponds to first 24 registers listed i.e registers 23(msb) down to 0(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg : 32;        /*## attribute CrcErrorStatusReg */
}R2M14_CrcErrorStatusBits_t;
/**
* R2M14_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00143001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000010100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
	/**
	* BitsName: major_revision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0011
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
}R2M14_ModuleIdBits_t;
#endif
/**
* R2M14_SsbmodControlUnion_t
* R2M14_SsbmodControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M14_SsbmodControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M14_SsbmodControlUnion_t;

/**
* R2M14_IfControlUnion_t
* R2M14_IfControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M14_IfControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M14_IfControlUnion_t;

/**
* R2M14_LevelSetUnion_t
* R2M14_LevelSetUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M14_LevelSetBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M14_LevelSetUnion_t;

/**
* R2M14_RmsControlUnion_t
* R2M14_RmsControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M14_RmsControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M14_RmsControlUnion_t;

/**
* R2M14_SyncStartControlUnion_t
* R2M14_SyncStartControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M14_SyncStartControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M14_SyncStartControlUnion_t;

/**
* R2M14_Lox3GainControlUnion_t
* R2M14_Lox3GainControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M14_Lox3GainControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M14_Lox3GainControlUnion_t;

/**
* R2M14_MaskCcResetErrorUnion_t
* R2M14_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M14_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M14_MaskCcResetErrorUnion_t;

/**
* R2M14_CrcErrorStatusUnion_t
* R2M14_CrcErrorStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M14_CrcErrorStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M14_CrcErrorStatusUnion_t;

/**
* R2M14_ModuleIdUnion_t
* R2M14_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M14_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M14_ModuleIdUnion_t;


#endif
