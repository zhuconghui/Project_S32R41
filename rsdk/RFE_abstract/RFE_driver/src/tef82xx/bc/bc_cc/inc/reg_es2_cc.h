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
* @reg_es2_cc.h
*/
#ifndef REG_ES2_CC_H
#define REG_ES2_CC_H
#include <stdint.h>
/**
* R2M00_SERIALISER_MODE_SEL_U16
* RegisterName: MOD00_SERIALISER_MODE_SEL
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x00000000
*/
#define R2M00_SERIALISER_MODE_SEL_U16 (uint16_t)0x0000
/**
* R2M00_LDO_CONTROL_U16
* RegisterName: MOD00_LDO_CONTROL
* AccessMode: RW
* AddressRange: 0x0004 - 0x0008
* ResetValue: 0x00000000
*/
#define R2M00_LDO_CONTROL_U16 (uint16_t)0x0004
/**
* R2M00_LDO_ENABLE_U16
* RegisterName: MOD00_LDO_ENABLE
* AccessMode: RW
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x00000000
*/
#define R2M00_LDO_ENABLE_U16 (uint16_t)0x0008
/**
* R2M00_MCUINT_CHIRPSTART_OUT_PAD_CONTROL_U16
* RegisterName: MOD00_MCUINT_CHIRPSTART_OUT_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x000C - 0x0010
* ResetValue: 0x00000361
*/
#define R2M00_MCUINT_CHIRPSTART_OUT_PAD_CONTROL_U16 (uint16_t)0x000C
/**
* R2M00_CHIRPSTART_IN_PAD_CONTROL_U16
* RegisterName: MOD00_CHIRPSTART_IN_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x0010 - 0x0014
* ResetValue: 0x00000361
*/
#define R2M00_CHIRPSTART_IN_PAD_CONTROL_U16 (uint16_t)0x0010
/**
* R2M00_ERROR_N_PAD_CONTROL_U16
* RegisterName: MOD00_ERROR_N_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x0014 - 0x0018
* ResetValue: 0x00000361
*/
#define R2M00_ERROR_N_PAD_CONTROL_U16 (uint16_t)0x0014
/**
* R2M00_ERROR_RESET_PAD_CONTROL_U16
* RegisterName: MOD00_ERROR_RESET_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x0018 - 0x001C
* ResetValue: 0x00000361
*/
#define R2M00_ERROR_RESET_PAD_CONTROL_U16 (uint16_t)0x0018
/**
* R2M00_TX1_PS_I_PAD_CONTROL_U16
* RegisterName: MOD00_TX1_PS_I_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x001C - 0x0020
* ResetValue: 0x00001361
*/
#define R2M00_TX1_PS_I_PAD_CONTROL_U16 (uint16_t)0x001C
/**
* R2M00_TX1_PS_Q_PAD_CONTROL_U16
* RegisterName: MOD00_TX1_PS_Q_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x0020 - 0x0024
* ResetValue: 0x00001361
*/
#define R2M00_TX1_PS_Q_PAD_CONTROL_U16 (uint16_t)0x0020
/**
* R2M00_TX2_PS_I_PAD_CONTROL_U16
* RegisterName: MOD00_TX2_PS_I_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x0024 - 0x0028
* ResetValue: 0x00001361
*/
#define R2M00_TX2_PS_I_PAD_CONTROL_U16 (uint16_t)0x0024
/**
* R2M00_TX2_PS_Q_PAD_CONTROL_U16
* RegisterName: MOD00_TX2_PS_Q_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x0028 - 0x002C
* ResetValue: 0x00001361
*/
#define R2M00_TX2_PS_Q_PAD_CONTROL_U16 (uint16_t)0x0028
/**
* R2M00_TX3_PS_I_PAD_CONTROL_U16
* RegisterName: MOD00_TX3_PS_I_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x002C - 0x0030
* ResetValue: 0x00001361
*/
#define R2M00_TX3_PS_I_PAD_CONTROL_U16 (uint16_t)0x002C
/**
* R2M00_TX3_PS_Q_PAD_CONTROL_U16
* RegisterName: MOD00_TX3_PS_Q_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x0030 - 0x0034
* ResetValue: 0x00001361
*/
#define R2M00_TX3_PS_Q_PAD_CONTROL_U16 (uint16_t)0x0030
/**
* R2M00_MISO_PAD_CONTROL_U16
* RegisterName: MOD00_MISO_PAD_CONTROL
* AccessMode: RW
* AddressRange: 0x0034 - 0x0038
* ResetValue: 0x00001370
*/
#define R2M00_MISO_PAD_CONTROL_U16 (uint16_t)0x0034
/**
* R2M00_MCU_INT_CONTROL_U16
* RegisterName: MOD00_MCU_INT_CONTROL
* AccessMode: RW
* AddressRange: 0x0040 - 0x0044
* ResetValue: 0x01000090
*/
#define R2M00_MCU_INT_CONTROL_U16 (uint16_t)0x0040
/**
* R2M00_INT_ENABLE_U16
* RegisterName: MOD00_INT_ENABLE
* AccessMode: RW
* AddressRange: 0x0044 - 0x0048
* ResetValue: 0x00000000
*/
#define R2M00_INT_ENABLE_U16 (uint16_t)0x0044
/**
* R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16
* RegisterName: MOD00_DYNAMIC_POWER_CONTROL_ENABLE
* AccessMode: RW
* AddressRange: 0x0048 - 0x004C
* ResetValue: 0x00000000
*/
#define R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16 (uint16_t)0x0048
/**
* R2M00_DYNAMIC_POWER_CONTROL_DELAY_U16
* RegisterName: MOD00_DYNAMIC_POWER_CONTROL_DELAY
* AccessMode: RW
* AddressRange: 0x004C - 0x0050
* ResetValue: 0x00C800C8
*/
#define R2M00_DYNAMIC_POWER_CONTROL_DELAY_U16 (uint16_t)0x004C
/**
* R2M00_IP_LEVEL_CLOCK_ENABLE_U16
* RegisterName: MOD00_IP_LEVEL_CLOCK_ENABLE
* AccessMode: RW
* AddressRange: 0x0050 - 0x0054
* ResetValue: 0x00060000
*/
#define R2M00_IP_LEVEL_CLOCK_ENABLE_U16 (uint16_t)0x0050
/**
* R2M00_IP_LEVEL_PON_ENABLE_U16
* RegisterName: MOD00_IP_LEVEL_PON_ENABLE
* AccessMode: RW
* AddressRange: 0x0054 - 0x0058
* ResetValue: 0x00000000
*/
#define R2M00_IP_LEVEL_PON_ENABLE_U16 (uint16_t)0x0054
/**
* R2M00_IP_RESET_CONTROL_U16
* RegisterName: MOD00_IP_RESET_CONTROL
* AccessMode: RW
* AddressRange: 0x0058 - 0x005C
* ResetValue: 0x00040000
*/
#define R2M00_IP_RESET_CONTROL_U16 (uint16_t)0x0058
/**
* R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16
* RegisterName: MOD00_IP_FUNCTIONAL_RESET_CONTROL
* AccessMode: RW
* AddressRange: 0x005C - 0x0060
* ResetValue: 0x00040000
*/
#define R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16 (uint16_t)0x005C
/**
* R2M00_TEMP_DIGITIZER_ADC_CONTROL_U16
* RegisterName: MOD00_TEMP_DIGITIZER_ADC_CONTROL
* AccessMode: RW
* AddressRange: 0x0060 - 0x0064
* ResetValue: 0x00000680
*/
#define R2M00_TEMP_DIGITIZER_ADC_CONTROL_U16 (uint16_t)0x0060
/**
* R2M00_TEMP_DIGITIZER_FUNC_CONTROL_U16
* RegisterName: MOD00_TEMP_DIGITIZER_FUNC_CONTROL
* AccessMode: RW
* AddressRange: 0x0064 - 0x0068
* ResetValue: 0x00000000
*/
#define R2M00_TEMP_DIGITIZER_FUNC_CONTROL_U16 (uint16_t)0x0064
/**
* R2M00_TEMP_DIGITIZER_DATA_TX_U16
* RegisterName: MOD00_TEMP_DIGITIZER_DATA_TX
* AccessMode: R
* AddressRange: 0x0068 - 0x006C
* ResetValue: 0x00000000
*/
#define R2M00_TEMP_DIGITIZER_DATA_TX_U16 (uint16_t)0x0068
/**
* R2M00_TEMP_DIGITIZER_DATA_CHIRP_U16
* RegisterName: MOD00_TEMP_DIGITIZER_DATA_CHIRP
* AccessMode: R
* AddressRange: 0x006C - 0x0070
* ResetValue: 0x00000000
*/
#define R2M00_TEMP_DIGITIZER_DATA_CHIRP_U16 (uint16_t)0x006C
/**
* R2M00_SCRATCH_REGISTER1_U16
* RegisterName: MOD00_SCRATCH_REGISTER1
* AccessMode: RW
* AddressRange: 0x0080 - 0x0084
* ResetValue: 0x00000000
*/
#define R2M00_SCRATCH_REGISTER1_U16 (uint16_t)0x0080
/**
* R2M00_SCRATCH_REGISTER2_U16
* RegisterName: MOD00_SCRATCH_REGISTER2
* AccessMode: RW
* AddressRange: 0x0084 - 0x0088
* ResetValue: 0x00000000
*/
#define R2M00_SCRATCH_REGISTER2_U16 (uint16_t)0x0084
/**
* R2M00_SCRATCH_REGISTER3_U16
* RegisterName: MOD00_SCRATCH_REGISTER3
* AccessMode: RW
* AddressRange: 0x0088 - 0x008C
* ResetValue: 0x00000000
*/
#define R2M00_SCRATCH_REGISTER3_U16 (uint16_t)0x0088
/**
* R2M00_SCRATCH_REGISTER4_U16
* RegisterName: MOD00_SCRATCH_REGISTER4
* AccessMode: RW
* AddressRange: 0x008C - 0x0090
* ResetValue: 0x00000000
*/
#define R2M00_SCRATCH_REGISTER4_U16 (uint16_t)0x008C
/**
* R2M00_SCRATCH_REGISTER5_U16
* RegisterName: MOD00_SCRATCH_REGISTER5
* AccessMode: RW
* AddressRange: 0x0090 - 0x0094
* ResetValue: 0x00000000
*/
#define R2M00_SCRATCH_REGISTER5_U16 (uint16_t)0x0090
/**
* R2M00_SCRATCH_REGISTER6_U16
* RegisterName: MOD00_SCRATCH_REGISTER6
* AccessMode: RW
* AddressRange: 0x0094 - 0x0098
* ResetValue: 0x00000000
*/
#define R2M00_SCRATCH_REGISTER6_U16 (uint16_t)0x0094
/**
* R2M00_SCRATCH_REGISTER7_U16
* RegisterName: MOD00_SCRATCH_REGISTER7
* AccessMode: RW
* AddressRange: 0x0098 - 0x009C
* ResetValue: 0x00000000
*/
#define R2M00_SCRATCH_REGISTER7_U16 (uint16_t)0x0098
/**
* R2M00_SCRATCH_REGISTER8_U16
* RegisterName: MOD00_SCRATCH_REGISTER8
* AccessMode: RW
* AddressRange: 0x009C - 0x00A0
* ResetValue: 0x00000000
*/
#define R2M00_SCRATCH_REGISTER8_U16 (uint16_t)0x009C
/**
* R2M00_PIN_MUX_U16
* RegisterName: MOD00_PIN_MUX
* AccessMode: RW
* AddressRange: 0x0300 - 0x0304
* ResetValue: 0x00000000
*/
#define R2M00_PIN_MUX_U16 (uint16_t)0x0300
/**
* R2M00_TEMP_DIGITIZER_TX_TEMP_COEFF_U16
* RegisterName: MOD00_TEMP_DIGITIZER_TX_TEMP_COEFF
* AccessMode: RW
* AddressRange: 0x0318 - 0x031C
* ResetValue: 0x2E0B82E0
*/
#define R2M00_TEMP_DIGITIZER_TX_TEMP_COEFF_U16 (uint16_t)0x0318
/**
* R2M00_TEMP_DIGITIZER_CHIRP_TEMP_COEFF_U16
* RegisterName: MOD00_TEMP_DIGITIZER_CHIRP_TEMP_COEFF
* AccessMode: RW
* AddressRange: 0x031C - 0x0320
* ResetValue: 0x000002E0
*/
#define R2M00_TEMP_DIGITIZER_CHIRP_TEMP_COEFF_U16 (uint16_t)0x031C
/**
* R2M00_INT_SET_U16
* RegisterName: MOD00_INT_SET
* AccessMode: W
* AddressRange: 0x0600 - 0x0604
* ResetValue: 0x00000000
*/
#define R2M00_INT_SET_U16 (uint16_t)0x0600
/**
* R2M00_INT_CLR_U16
* RegisterName: MOD00_INT_CLR
* AccessMode: W
* AddressRange: 0x0604 - 0x0608
* ResetValue: 0x00000000
*/
#define R2M00_INT_CLR_U16 (uint16_t)0x0604
/**
* R2M00_INT_RAW_STATUS_U16
* RegisterName: MOD00_INT_RAW_STATUS
* AccessMode: R
* AddressRange: 0x0800 - 0x0804
* ResetValue: 0x00000000
*/
#define R2M00_INT_RAW_STATUS_U16 (uint16_t)0x0800
/**
* R2M00_INT_MASKED_STATUS_U16
* RegisterName: MOD00_INT_MASKED_STATUS
* AccessMode: R
* AddressRange: 0x0804 - 0x0808
* ResetValue: 0x00000000
*/
#define R2M00_INT_MASKED_STATUS_U16 (uint16_t)0x0804
/**
* R2M00_RDL_SITE_STATUS_U16
* RegisterName: MOD00_RDL_SITE_STATUS
* AccessMode: R
* AddressRange: 0x0810 - 0x0814
* ResetValue: 0x00000000
*/
#define R2M00_RDL_SITE_STATUS_U16 (uint16_t)0x0810
/**
* R2M00_CRC_ERROR_STATUS1_U16
* RegisterName: MOD00_CRC_ERROR_STATUS1
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M00_CRC_ERROR_STATUS1_U16 (uint16_t)0x0F40
/**
* R2M00_CRC_ERROR_STATUS2_U16
* RegisterName: MOD00_CRC_ERROR_STATUS2
* AccessMode: R
* AddressRange: 0x0F44 - 0x0F48
* ResetValue: 0x00000000
*/
#define R2M00_CRC_ERROR_STATUS2_U16 (uint16_t)0x0F44
/**
* R2M00_CRC_ERROR_STATUS3_U16
* RegisterName: MOD00_CRC_ERROR_STATUS3
* AccessMode: R
* AddressRange: 0x0F48 - 0x0F4C
* ResetValue: 0x00000000
*/
#define R2M00_CRC_ERROR_STATUS3_U16 (uint16_t)0x0F48
/**
* R2M00_MODULE_ID_U16
* RegisterName: MOD00_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x00004004
*/
#define R2M00_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M00_SerialiserModeSelBits_t
* RegisterName: SERIALISER_MODE_SEL
* Software control register to select  the data interface. This register is active only if the respective functions are enabled through OTP.  For example if CSI2 is disabled through OTP, then it is not possible to select CSI2 mode through software
* Address: 0x000
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: sw_ctrl_ser_mode_sel
	* Description: This register is a conditionally writable register
	* 01: CSI2 mode
	* 10: LVDS
	* others: None enabled
	* The serializer mode can also be controlled  through OTP.
	*
	* Note: CSI2 and LVDS chip packages are different and one of the interface is disabled by default. So this option is used only for deselection of the interface and enabling of the only one available interface
	*
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwCtrlSerModeSel : 2;        /*## attribute SwCtrlSerModeSel */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
}R2M00_SerialiserModeSelBits_t;
/**
* R2M00_LdoControlBits_t
* RegisterName: LDO_CONTROL
* Local LDO controls for the ADC, Serialiser and SSBMOD from OTP
*
* Address: 0x004
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ldo_sel_vout_adc
	* Description: set output voltage of local LDO.
	* The values to be set will be coming from the  OTP
	*
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b00000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVoutAdc : 5;        /*## attribute LdoSelVoutAdc */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: ldo_sel_vout_serialiser_ser
	* Description: set output voltage of local LDO.
	* The values to be set will be coming from the  OTP
	* Read/Write: RW
	* Bits: [12:8]
	* ResetValue: 0b00000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVoutSerialiserSer : 5;        /*## attribute LdoSelVoutSerialiserSer */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ldo_sel_vout_serialiser_csi2
	* Description: set output voltage of local LDO.
	* The values to be set will be coming from the  OTP
	*
	* Read/Write: RW
	* Bits: [20:16]
	* ResetValue: 0b00000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVoutSerialiserCsi2 : 5;        /*## attribute LdoSelVoutSerialiserCsi2 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ldo_sel_vout_ssbmod
	* Description: set output voltage of local LDO.
	* The values to be set will be coming from the  OTP
	*
	* Read/Write: RW
	* Bits: [28:24]
	* ResetValue: 0b00000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVoutSsbmod : 5;        /*## attribute LdoSelVoutSsbmod */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
}R2M00_LdoControlBits_t;
/**
* R2M00_LdoEnableBits_t
* RegisterName: LDO_ENABLE
* Local LDO enables for the ADC, Serialiser and SSBMOD
*
* Address: 0x008
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ldo_en_adc
	* Description: Enables local LDO of the ADC
	* 0: LDO is disabled
	* 1: LDO is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdoEnAdc : 1;        /*## attribute LdoEnAdc */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: ldo_en_serialiser_ser
	* Description: Enables local LDO of the Serialiser
	* 0: LDO is disabled
	* 1: LDO is enabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdoEnSerialiserSer : 1;        /*## attribute LdoEnSerialiserSer */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ldo_en_serialiser_csi2
	* Description: Enables local LDO of the CSI2
	* 0: LDO is disabled
	* 1: LDO is enabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdoEnSerialiserCsi2 : 1;        /*## attribute LdoEnSerialiserCsi2 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ldo_en_ssbmod
	* Description: Enables local LDO
	* 0: LDO is disabled
	* 1: LDO is enabled
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdoEnSsbmod : 1;        /*## attribute LdoEnSsbmod */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M00_LdoEnableBits_t;
/**
* R2M00_McuintChirpstartOutPadControlBits_t
* RegisterName: MCUINT_CHIRPSTART_OUT_PAD_CONTROL
* This register controls the pad configuration.
*
* Multifunctional IO can perform the following operation
*
* Output Mode
* -------------------
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: followe chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
*
*
*
* Default values are sufficient for most of the use cases and application
*
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
* Address: 0x00C
* ResetValue: 0x00000361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mcuint_chirpstart_mfio_en
	* Description: Disable  O/P  driver
	* 0 => O/P enabled
	* 1 => O/P disabled
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEn : 1;        /*## attribute McuintChirpstartMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: mcuint_chirpstart_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEnzi : 1;        /*## attribute McuintChirpstartMfioEnzi */
	/**
	* BitsName: mcuint_chirpstart_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEpun : 1;        /*## attribute McuintChirpstartMfioEpun */
	/**
	* BitsName: mcuint_chirpstart_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEpd : 1;        /*## attribute McuintChirpstartMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: mcuint_chirpstart_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEhs0 : 1;        /*## attribute McuintChirpstartMfioEhs0 */
	/**
	* BitsName: mcuint_chirpstart_mfio_ehs1
	* Description: IO Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEhs1 : 1;        /*## attribute McuintChirpstartMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 22;        /*## attribute Reserved2 */
}R2M00_McuintChirpstartOutPadControlBits_t;
/**
* R2M00_ChirpstartInPadControlBits_t
* RegisterName: CHIRPSTART_IN_PAD_CONTROL
* chirp_start pin pad controls.
* Default values are sufficient for most of the use cases
*
* This multi function IO can be used both input and output mode.
*
* Input Mode
* ----------------
* a.. To trigger the chip for data acquisition by MCU or another chip i.e chirp_start trigger
*
* Output Mode
* ------------------
* a. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
* b. Routes the interrupt events from chip towards external world
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
* Address: 0x010
* ResetValue: 0x00000361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: chirpstart_mfio_en
	* Description: Disable  O/P  driver
	* 0 => O/P enabled
	* 1 => O/P disabled
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEn : 1;        /*## attribute ChirpstartMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: chirpstart_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEnzi : 1;        /*## attribute ChirpstartMfioEnzi */
	/**
	* BitsName: chirpstart_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEpun : 1;        /*## attribute ChirpstartMfioEpun */
	/**
	* BitsName: chirpstart_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEpd : 1;        /*## attribute ChirpstartMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: chirpstart_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEhs0 : 1;        /*## attribute ChirpstartMfioEhs0 */
	/**
	* BitsName: chirpstart_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEhs1 : 1;        /*## attribute ChirpstartMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: chirpstart_in_route_en
	* Description: Selection bit for routing chirpstart_in pad input to chirpstart_in pin of chirp module. This is disabled by default. This field needs to be configured along with chirpstart_mfio_en=1 to enable the chirpstart in input mode.
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line chirpstart_in from CC towards chirp module will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpstartInRouteEn : 1;        /*## attribute ChirpstartInRouteEn */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: chirpstart_out_route_en
	* Description: Selection bit for routing multifunction signal from chirp module to chirpstart_in pad output. This is disabled by default. This field needs to be configured along with chirpstart_mfio_en=0 to enable the chirp module multifunction in the output mode.
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The chirpstart_in pad output will be tied to 0
	*
	* Note: Please refer the chirp multifunction signal that can be enabled in the output mode of this pad in the register chirp_trigger_mode_control, field chirpstart_in_pad_func_sel in the Chirp module
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpstartOutRouteEn : 1;        /*## attribute ChirpstartOutRouteEn */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 15;        /*## attribute Reserved4 */
}R2M00_ChirpstartInPadControlBits_t;
/**
* R2M00_ErrorNPadControlBits_t
* RegisterName: ERROR_N_PAD_CONTROL
* error_n pin  pad controls.
* Default values are sufficient for most use cases, except the O/P control(bit 0).
* The O/P need to be explicitly enabled to the MCU at the end of  the Chip start up process.
*
* This pin is used for reporting safety errors within the Chip.  By default (on reset) this pin will remain in input mode ( O/P not driven). An external pull down resistor (4.7k)  has to be used  to pull this pin to low on start.  Once MCU complete the required start-up of the IC, then this pin can be configured to O/P mode.  If there are no underlying errors within the IC, and start up is Ok, then the inner safety monitor with drive this pin to a logic high value.  If an error is reported within the IC, this pin is driven low indicating a safety issue within the Chip.
*
*
* Address: 0x014
* ResetValue: 0x00000361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: error_n_mfio_en
	* Description: Disable  O/P  driver
	* 0 => O/P enabled
	* 1 => O/P disabled
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorNMfioEn : 1;        /*## attribute ErrorNMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: error_n_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorNMfioEnzi : 1;        /*## attribute ErrorNMfioEnzi */
	/**
	* BitsName: error_n_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorNMfioEpun : 1;        /*## attribute ErrorNMfioEpun */
	/**
	* BitsName: error_n_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorNMfioEpd : 1;        /*## attribute ErrorNMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: error_n_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorNMfioEhs0 : 1;        /*## attribute ErrorNMfioEhs0 */
	/**
	* BitsName: error_n_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorNMfioEhs1 : 1;        /*## attribute ErrorNMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 22;        /*## attribute Reserved2 */
}R2M00_ErrorNPadControlBits_t;
/**
* R2M00_ErrorResetPadControlBits_t
* RegisterName: ERROR_RESET_PAD_CONTROL
* error_reset  pin  pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* This pin can be used by MCU  to reset a functional safety error within the IC.   Typically this will clear all the latched errors within the inner safety monitors. However if  fresh errors are reported, then the error_n pin may remain low.
* Please note that it  is also possible to reset  errors within the IC through a SPI register write
*
*
* Address: 0x018
* ResetValue: 0x00000361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: error_reset_mfio_en
	* Description: Disable  O/P  driver
	* 0 => O/P enabled
	* 1 => O/P disabled
	* In a functional context the O/P is never enabled
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEn : 1;        /*## attribute ErrorResetMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: error_reset_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEnzi : 1;        /*## attribute ErrorResetMfioEnzi */
	/**
	* BitsName: error_reset_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEpun : 1;        /*## attribute ErrorResetMfioEpun */
	/**
	* BitsName: error_reset_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEpd : 1;        /*## attribute ErrorResetMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: error_reset_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEhs0 : 1;        /*## attribute ErrorResetMfioEhs0 */
	/**
	* BitsName: error_reset_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEhs1 : 1;        /*## attribute ErrorResetMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 22;        /*## attribute Reserved2 */
}R2M00_ErrorResetPadControlBits_t;
/**
* R2M00_Tx1PsIPadControlBits_t
* RegisterName: TX1_PS_I_PAD_CONTROL
* TX unit 1 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x01C
* ResetValue: 0x00001361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: tx1_ps_i_mfio_en
	* Description: Disable  O/P  driver  (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEn : 1;        /*## attribute Tx1PsIMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: tx1_ps_i_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEnzi : 1;        /*## attribute Tx1PsIMfioEnzi */
	/**
	* BitsName: tx1_ps_i_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEpun : 1;        /*## attribute Tx1PsIMfioEpun */
	/**
	* BitsName: tx1_ps_i_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEpd : 1;        /*## attribute Tx1PsIMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: tx1_ps_i_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEhs0 : 1;        /*## attribute Tx1PsIMfioEhs0 */
	/**
	* BitsName: tx1_ps_i_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEhs1 : 1;        /*## attribute Tx1PsIMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: tx1_ps_i_ext_en
	* Description: Selection bit for routing tx1_ps pad input to ps_tx1_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx1_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIExtEn : 1;        /*## attribute Tx1PsIExtEn */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M00_Tx1PsIPadControlBits_t;
/**
* R2M00_Tx1PsQPadControlBits_t
* RegisterName: TX1_PS_Q_PAD_CONTROL
* TX unit 1 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, except the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x020
* ResetValue: 0x00001361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: tx1_ps_q_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEn : 1;        /*## attribute Tx1PsQMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: tx1_ps_q_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEnzi : 1;        /*## attribute Tx1PsQMfioEnzi */
	/**
	* BitsName: tx1_ps_q_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEpun : 1;        /*## attribute Tx1PsQMfioEpun */
	/**
	* BitsName: tx1_ps_q_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEpd : 1;        /*## attribute Tx1PsQMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: tx1_ps_q_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEhs0 : 1;        /*## attribute Tx1PsQMfioEhs0 */
	/**
	* BitsName: tx1_ps_q_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEhs1 : 1;        /*## attribute Tx1PsQMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: tx1_ps_q_ext_en
	* Description: Selection bit for routing tx1_ps pad input to ps_tx1_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx1_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQExtEn : 1;        /*## attribute Tx1PsQExtEn */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M00_Tx1PsQPadControlBits_t;
/**
* R2M00_Tx2PsIPadControlBits_t
* RegisterName: TX2_PS_I_PAD_CONTROL
* TX unit 2 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x024
* ResetValue: 0x00001361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: tx2_ps_i_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEn : 1;        /*## attribute Tx2PsIMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: tx2_ps_i_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEnzi : 1;        /*## attribute Tx2PsIMfioEnzi */
	/**
	* BitsName: tx2_ps_i_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEpun : 1;        /*## attribute Tx2PsIMfioEpun */
	/**
	* BitsName: tx2_ps_i_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEpd : 1;        /*## attribute Tx2PsIMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: tx2_ps_i_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEhs0 : 1;        /*## attribute Tx2PsIMfioEhs0 */
	/**
	* BitsName: tx2_ps_i_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEhs1 : 1;        /*## attribute Tx2PsIMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: tx2_ps_i_ext_en
	* Description: Selection bit for routing tx2_ps pad input to ps_tx2_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx2_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIExtEn : 1;        /*## attribute Tx2PsIExtEn */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M00_Tx2PsIPadControlBits_t;
/**
* R2M00_Tx2PsQPadControlBits_t
* RegisterName: TX2_PS_Q_PAD_CONTROL
* TX unit 2 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x028
* ResetValue: 0x00001361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: tx2_ps_q_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEn : 1;        /*## attribute Tx2PsQMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: tx2_ps_q_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEnzi : 1;        /*## attribute Tx2PsQMfioEnzi */
	/**
	* BitsName: tx2_ps_q_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEpun : 1;        /*## attribute Tx2PsQMfioEpun */
	/**
	* BitsName: tx2_ps_q_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEpd : 1;        /*## attribute Tx2PsQMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: tx2_ps_q_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEhs0 : 1;        /*## attribute Tx2PsQMfioEhs0 */
	/**
	* BitsName: tx2_ps_q_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEhs1 : 1;        /*## attribute Tx2PsQMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: tx2_ps_q_ext_en
	* Description: Selection bit for routing tx2_ps pad input to ps_tx2_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx2_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQExtEn : 1;        /*## attribute Tx2PsQExtEn */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M00_Tx2PsQPadControlBits_t;
/**
* R2M00_Tx3PsIPadControlBits_t
* RegisterName: TX3_PS_I_PAD_CONTROL
* TX unit 3 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x02C
* ResetValue: 0x00001361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: tx3_ps_i_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEn : 1;        /*## attribute Tx3PsIMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: tx3_ps_i_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEnzi : 1;        /*## attribute Tx3PsIMfioEnzi */
	/**
	* BitsName: tx3_ps_i_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEpun : 1;        /*## attribute Tx3PsIMfioEpun */
	/**
	* BitsName: tx3_ps_i_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEpd : 1;        /*## attribute Tx3PsIMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: tx3_ps_i_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEhs0 : 1;        /*## attribute Tx3PsIMfioEhs0 */
	/**
	* BitsName: tx3_ps_i_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEhs1 : 1;        /*## attribute Tx3PsIMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: tx3_ps_i_ext_en
	* Description: Selection bit for routing tx3_ps pad input to ps_tx3_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx3_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIExtEn : 1;        /*## attribute Tx3PsIExtEn */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M00_Tx3PsIPadControlBits_t;
/**
* R2M00_Tx3PsQPadControlBits_t
* RegisterName: TX3_PS_Q_PAD_CONTROL
* TX unit 3 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x030
* ResetValue: 0x00001361
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: tx3_ps_q_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEn : 1;        /*## attribute Tx3PsQMfioEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: tx3_ps_q_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEnzi : 1;        /*## attribute Tx3PsQMfioEnzi */
	/**
	* BitsName: tx3_ps_q_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEpun : 1;        /*## attribute Tx3PsQMfioEpun */
	/**
	* BitsName: tx3_ps_q_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEpd : 1;        /*## attribute Tx3PsQMfioEpd */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: tx3_ps_q_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEhs0 : 1;        /*## attribute Tx3PsQMfioEhs0 */
	/**
	* BitsName: tx3_ps_q_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEhs1 : 1;        /*## attribute Tx3PsQMfioEhs1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: tx3_ps_q_ext_en
	* Description: Selection bit for routing tx3_ps pad input to ps_tx3_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx3_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQExtEn : 1;        /*## attribute Tx3PsQExtEn */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 19;        /*## attribute Reserved3 */
}R2M00_Tx3PsQPadControlBits_t;
/**
* R2M00_MisoPadControlBits_t
* RegisterName: MISO_PAD_CONTROL
* MISO   pin pad controls.
* Default values are sufficient for most use cases
* This pad is  an O./P  pad and is directly controlled by the SS_N pin
*
* Address: 0x034
* ResetValue: 0x00001370
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
	* BitsName: miso_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t MisoMfioEnzi : 1;        /*## attribute MisoMfioEnzi */
	/**
	* BitsName: miso_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MisoMfioEpun : 1;        /*## attribute MisoMfioEpun */
	/**
	* BitsName: miso_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MisoMfioEpd : 1;        /*## attribute MisoMfioEpd */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: miso_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MisoMfioEhs0 : 1;        /*## attribute MisoMfioEhs0 */
	/**
	* BitsName: miso_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MisoMfioEhs1 : 1;        /*## attribute MisoMfioEhs1 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: miso_en_ctrl
	* Description: This bit controls the MISO pad enable alongwith the SS_N/CS_N chip input
	*
	* Normally MISO pad enable is selected by the chip select signal coming from SS_N/CS_N pad i.e whenever the chip is addressed, the MISO pad output is enabled.
	*
	* This selection (SS_N/CS_N) is used with this control bit to enable the MISO pad in the output mode. This is kept incase application decides to disable/tristate the MISO pad.
	*
	* 0 : MISO output pad disabled
	* 1:  MISO output pad is enabled with SS_N/CS_N
	*
	* Note: This feature might be useful in the  Leader-Follower configuration, where MCU wants to read from a particular chip or in general for debugging
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t MisoEnCtrl : 1;        /*## attribute MisoEnCtrl */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 19;        /*## attribute Reserved4 */
}R2M00_MisoPadControlBits_t;
/**
* R2M00_McuIntControlBits_t
* RegisterName: MCU_INT_CONTROL
* Software control register to control the interrupt polarity, and the type of interrupt required.
* Address: 0x040
* ResetValue: 0x01000090
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: interrupt_period
	* Description: Activation Period for Ready Interrupt based on 40MHz(25 ns -Xtal Clock)
	* default: 3.6us(144). This period is applicable only for edge triggered interrupt mode.
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b10010000
	* Source: Application
	* FuSa: No
	*/
	uint32_t InterruptPeriod : 8;        /*## attribute InterruptPeriod */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: interrupt_level_or_pulse
	* Description: 1: Edge triggered interrupt. Ready Interrupt is activated for the time period mentioned in the ReadyInt_period.
	* 0: Level triggered interrupt. Once Ready Interrupt is activated, is cleared by MCU by writing through interrupt clear register
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t InterruptLevelOrPulse : 1;        /*## attribute InterruptLevelOrPulse */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 7;        /*## attribute Reserved1 */
	/**
	* BitsName: interrupt_polarity
	* Description:  0 Active low interrupt
	*  1: Active High interrupt
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t InterruptPolarity : 1;        /*## attribute InterruptPolarity */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 7;        /*## attribute Reserved2 */
}R2M00_McuIntControlBits_t;
/**
* R2M00_IntEnableBits_t
* RegisterName: INT_ENABLE
* Interrupt enable register. If corresponding bit is set, then the interrupt is passed to MCU
*
* status_flag_int_en: Interrupt is raised when a warning status flag is set
*
* crc_error_int:  Interrupt is raised  when a CRC checksum error is reported on the MISO lane ( For SPI write  complete payload is protected by CRC, for SPI read only on the command +address field)
*
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the IC ( power down to TX,RX or chirp base don excessive power levels or temperature)
*
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
*
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
*
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int/. The delay depends on the decimation factor selected
*
* chirp_int : Indicates one of the following chirp events from timing engine
* a. end of a  sequence
* b. end of chirp
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
*
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
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: chirp_int_en
	* Description:
	* 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	*
	*
	*
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntEn : 1;        /*## attribute ChirpIntEn */
	/**
	* BitsName: end_of_data_tnfr_int_en
	* Description:
	*
	* 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	*
	*
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntEn : 1;        /*## attribute EndOfDataTnfrIntEn */
	/**
	* BitsName: status_wdt_int_en
	* Description:
	*
	* 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	*
	*
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntEn : 1;        /*## attribute StatusWdtIntEn */
	/**
	* BitsName: rtm_int_en
	* Description:
	*
	* 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	*
	*
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntEn : 1;        /*## attribute RtmIntEn */
	/**
	* BitsName: rf_powerdown_int_en
	* Description: 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntEn : 1;        /*## attribute RfPowerdownIntEn */
	/**
	* BitsName: crc_error_int_en
	* Description: 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntEn : 1;        /*## attribute CrcErrorIntEn */
	/**
	* BitsName: status_flag_int_en
	* Description: 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntEn : 1;        /*## attribute StatusFlagIntEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 24;        /*## attribute Reserved1 */
}R2M00_IntEnableBits_t;
/**
* R2M00_DynamicPowerControlEnableBits_t
* RegisterName: DYNAMIC_POWER_CONTROL_ENABLE
* Register to control the dynamic power of the chip.
*
* Dynamic power control is  possible  at two level
* 1. Dynamic power  control at chirp sequence level: When a module is selected for power control , then power to the module  is disabled outside  chirp sequence active period
* 2. Dynamic power control at individual chirp level.: When a module is selected for power control , then power to the module  is disabled outside  individual chirp  active period
*
* The following modules  can be brought under dynamic power control
* 1. Chirp
* 2. Individual TX units
* 3. Individual RX units
* 4. Serializer
* 5. ADC
* 6 .LO interface  (only in stand alone the chip)
*
* Within Dynamic power control, it is also possible to  choose  modules that are part of dynamic power control .
*
*
* Address: 0x048
* ResetValue: 0x00000000
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
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: chirp_dy_power_control
	* Description: 0: Chirp unit   is not under dynamic power control
	* 1: Chirp unit    power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpDyPowerControl : 1;        /*## attribute ChirpDyPowerControl */
	/**
	* BitsName: adc_dy_power_control
	* Description: 0: ADC12 and ADC34 is not under dynamic power control
	* 1: ADC12 and ADC34  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AdcDyPowerControl : 1;        /*## attribute AdcDyPowerControl */
	/**
	* BitsName: lo_interface_dy_power_control
	* Description: 0: LO Interface is not under dynamic power control
	* 1: LO Interface  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LoInterfaceDyPowerControl : 1;        /*## attribute LoInterfaceDyPowerControl */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: rx1_dy_power_control
	* Description: 0: RX1  unit is not under dynamic power control
	* 1: RX1  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx1DyPowerControl : 1;        /*## attribute Rx1DyPowerControl */
	/**
	* BitsName: rx2_dy_power_control
	* Description: 0: RX2  unit is not under dynamic power control
	* 1: RX2  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx2DyPowerControl : 1;        /*## attribute Rx2DyPowerControl */
	/**
	* BitsName: rx3_dy_power_control
	* Description: 0: RX3  unit is not under dynamic power control
	* 1: RX3  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx3DyPowerControl : 1;        /*## attribute Rx3DyPowerControl */
	/**
	* BitsName: rx4_dy_power_control
	* Description: 0: RX4  unit is not under dynamic power control
	* 1: RX4  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx4DyPowerControl : 1;        /*## attribute Rx4DyPowerControl */
	/**
	* BitsName: tx1_dy_power_control
	* Description: 0: TX1  unit is not under dynamic power control
	* 1: TX1  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx1DyPowerControl : 1;        /*## attribute Tx1DyPowerControl */
	/**
	* BitsName: tx2_dy_power_control
	* Description: 0: TX2  unit is not under dynamic power control
	* 1: TX2  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx2DyPowerControl : 1;        /*## attribute Tx2DyPowerControl */
	/**
	* BitsName: tx3_dy_power_control
	* Description: 0: TX3 unit is not under dynamic power control
	* 1: TX3 power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx3DyPowerControl : 1;        /*## attribute Tx3DyPowerControl */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: chirp_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpDyPowerModeSel : 1;        /*## attribute ChirpDyPowerModeSel */
	/**
	* BitsName: adc_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp mically
	*
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AdcDyPowerModeSel : 1;        /*## attribute AdcDyPowerModeSel */
	/**
	* BitsName: lo_interface_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LoInterfaceDyPowerModeSel : 1;        /*## attribute LoInterfaceDyPowerModeSel */
	/**
	* BitsName: adc_bg_calib_mode_sel
	* Description: These bits will decide whether the ADC background calibration to be triggered during the dynamic powerdown mode of ADC before entering into the standby mode. For each weight of the ADC, the background calibration runs for approx 600 us.
	*
	* In general, at the end of the every chirp sequence, ADC calibration is triggered in dynamic powerdown mode as it allows more time for background calibration. But if the usecase has sufficient time between the chirps in dynamic powerdown mode, the adc background calibration can be triggered. After the background calibration, the ADC will get into standby mode.
	*
	* 00 : ADC background calibration is triggered at the end of the chirp sequence in the dynamic powerdown mode (Default Mode)
	* 01 : ADC background calibration is triggered at the end of every chirp in the dynamic powerdown mode
	* 10 : Set automatically when trigger_bg_cal_manual is written 1b1
	* 11:  No adc background calibration during dynamic powerdown mode
	*
	* Note1: From timing point of view, the background calibration enable is asserted before (atleast minimum of 2 cycles) the ADC pon is deasserted
	* Note2: In mode 00, 01 and 10 switching adc_dy_power_control from 0 to 1 can trigger a background calibration. If this is undesired the following sequence can be used:
	* a. set adc_bg_calib_mode_sel = 2b11
	* b. subsequently set adc_bg_calib_mode_sel= 2b00 or 2b01 depending on the mode required
	* c. then change adc_dy_power_control from 0 to 1
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t AdcBgCalibModeSel : 2;        /*## attribute AdcBgCalibModeSel */
	/**
	* BitsName: trigger_bg_cal_manual
	* Description: Write 1 to trigger ADC BG calibration manually. The "adc_bg_calib_mode_sel" field bits will be set to 2b10 automatically until next chirp sequence. Auto clear bit.
	* Read/Write: W
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t TriggerBgCalManual : 1;        /*## attribute TriggerBgCalManual */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: rx1_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx1DyPowerModeSel : 1;        /*## attribute Rx1DyPowerModeSel */
	/**
	* BitsName: rx2_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp ally
	*
	* Read/Write: RW
	* Bits: [25]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx2DyPowerModeSel : 1;        /*## attribute Rx2DyPowerModeSel */
	/**
	* BitsName: rx3_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [26]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx3DyPowerModeSel : 1;        /*## attribute Rx3DyPowerModeSel */
	/**
	* BitsName: rx4_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [27]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx4DyPowerModeSel : 1;        /*## attribute Rx4DyPowerModeSel */
	/**
	* BitsName: tx1_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx1DyPowerModeSel : 1;        /*## attribute Tx1DyPowerModeSel */
	/**
	* BitsName: tx2_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx2DyPowerModeSel : 1;        /*## attribute Tx2DyPowerModeSel */
	/**
	* BitsName: tx3_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx3DyPowerModeSel : 1;        /*## attribute Tx3DyPowerModeSel */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 1;        /*## attribute Reserved6 */
}R2M00_DynamicPowerControlEnableBits_t;
/**
* R2M00_DynamicPowerControlDelayBits_t
* RegisterName: DYNAMIC_POWER_CONTROL_DELAY
* At the end of data acquisition (chirp sequence level or at individual chirp level)  a timer delay is provided to switch off the power to the respective modules ..  This is primarily to avoid any race conditions within the system  (for example acquired data is flushed out completely before disabling the units). The timings are depends on the decimation  factor used.
* Minimum values
*
*
* This value has to be  minimum  equal to the typical chirp reset time duration
*
*
* Address: 0x04C
* ResetValue: 0x00C800C8
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: dy_pd_delay_val_seq
	* Description: This control delays the powerdown of the modules which are configured for chirp sequence based powerdown
	*
	*
	* This value has to be  minimum  equal to the typical chirp reset time duration
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000011001000
	* Source: Application
	* FuSa: No
	*/
	uint32_t DyPdDelayValSeq : 16;        /*## attribute DyPdDelayValSeq */
	/**
	* BitsName: dy_pd_delay_val_chirp
	* Description: This control delays the powerdown of the modules which are configured for chirp based powerdown
	*
	*
	* This value has to be  minimum  equal to the typical chirp reset time duration
	* Read/Write: RW
	* Bits: [31:16]
	* ResetValue: 0b0000000011001000
	* Source: Application
	* FuSa: No
	*/
	uint32_t DyPdDelayValChirp : 16;        /*## attribute DyPdDelayValChirp */
}R2M00_DynamicPowerControlDelayBits_t;
/**
* R2M00_IpLevelClockEnableBits_t
* RegisterName: IP_LEVEL_CLOCK_ENABLE
* Before accessing a block, the 40 MHz clock has to be enabled for that block.
* By default  clock to all functional  modules are disabled  (barring OTP , ISM ).
* Clock to  a module shall be enabled before accessing the IP.  Generally this is done as part of the start up process.  Clock to specific modules   shall be  disabled at the  end of a configuration write primarily as a mechanism to reduce interference.  However in general not  required or recommended .
* Address: 0x050
* ResetValue: 0x00060000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: clk40_ser
	* Description: Enable  40 MHz  clock to serialzer (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Ser : 1;        /*## attribute Clk40Ser */
	/**
	* BitsName: clk40_chirp
	* Description: Enable  40 MHz  clock to Chirp  (register access as well as functional clock to timing engine)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Chirp : 1;        /*## attribute Clk40Chirp */
	/**
	* BitsName: clk40_adc12
	* Description: Enable  40 MHz  clock to ADC 1&2  (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Adc12 : 1;        /*## attribute Clk40Adc12 */
	/**
	* BitsName: clk40_adc34
	* Description: Enable  40 MHz  clock to ADC 3&4  (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Adc34 : 1;        /*## attribute Clk40Adc34 */
	/**
	* BitsName: clk40_global_bias
	* Description: Enable  40 MHz  clock to global bias  (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40GlobalBias : 1;        /*## attribute Clk40GlobalBias */
	/**
	* BitsName: clk40_lo_interface
	* Description: Enable  40 MHz  clock to LO interface  (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40LoInterface : 1;        /*## attribute Clk40LoInterface */
	/**
	* BitsName: clk40_master_clk
	* Description: Enable  40 MHz  clock to master clock ATB. By default xtal clock is enabled so the register access is possible after reset
	* 0 : Clock not enabled for ATB access
	* 1: Clock is enabled for ATB access
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40MasterClk : 1;        /*## attribute Clk40MasterClk */
	/**
	* BitsName: clk40_rx1
	* Description: Enable  40 MHz  clock to RX1   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Rx1 : 1;        /*## attribute Clk40Rx1 */
	/**
	* BitsName: clk40_rx2
	* Description: Enable  40 MHz  clock to RX2   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Rx2 : 1;        /*## attribute Clk40Rx2 */
	/**
	* BitsName: clk40_rx3
	* Description: Enable  40 MHz  clock to RX3   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Rx3 : 1;        /*## attribute Clk40Rx3 */
	/**
	* BitsName: clk40_rx4
	* Description: Enable  40 MHz  clock to RX4   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Rx4 : 1;        /*## attribute Clk40Rx4 */
	/**
	* BitsName: clk40_tx1
	* Description: Enable  40 MHz  clock to TX1   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Tx1 : 1;        /*## attribute Clk40Tx1 */
	/**
	* BitsName: clk40_tx2
	* Description: Enable  40 MHz  clock to TX2   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Tx2 : 1;        /*## attribute Clk40Tx2 */
	/**
	* BitsName: clk40_tx3
	* Description: Enable  40 MHz  clock to TX3   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Tx3 : 1;        /*## attribute Clk40Tx3 */
	/**
	* BitsName: clk40_ssbmod
	* Description: Enable  40 MHz  clock to SSBMOD/RFBIST   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Ssbmod : 1;        /*## attribute Clk40Ssbmod */
	/**
	* BitsName: clk40_global_ldo
	* Description: Enable  40 MHz  clock to global LDO (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40GlobalLdo : 1;        /*## attribute Clk40GlobalLdo */
	/**
	* BitsName: clk40_atb
	* Description: Enable  40 MHz  clock to ATB (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Atb : 1;        /*## attribute Clk40Atb */
	/**
	* BitsName: clk40_otp
	* Description: Enable  40 MHz  clock to OTP (register access).
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Otp : 1;        /*## attribute Clk40Otp */
	/**
	* BitsName: clk40_ism
	* Description: Enable  40 MHz  clock to ISM  (register  access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Ism : 1;        /*## attribute Clk40Ism */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 13;        /*## attribute Reserved0 */
}R2M00_IpLevelClockEnableBits_t;
/**
* R2M00_IpLevelPonEnableBits_t
* RegisterName: IP_LEVEL_PON_ENABLE
* Analog power enables to individual modules. The modules which are not enabled from OTP will be always read back as disabled.
*
* These are static power enable signals to corresponding IP's ..  Once this bit is set, then actual application of power  can be controllerd through the dynamic_power_control_enable (0x44)  register.. ( power is always applied or controlled per chirp sequence level)
* Address: 0x054
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pon_ser_en
	* Description: Enable  power to Serialiser
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonSerEn : 1;        /*## attribute PonSerEn */
	/**
	* BitsName: pon_chirp_en
	* Description: Enable  power to Chirp
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonChirpEn : 1;        /*## attribute PonChirpEn */
	/**
	* BitsName: pon_adc12_en
	* Description: Enable  power to ADC 1&2
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonAdc12En : 1;        /*## attribute PonAdc12En */
	/**
	* BitsName: pon_adc34_en
	* Description: Enable  power to ADC 3&4
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonAdc34En : 1;        /*## attribute PonAdc34En */
	/**
	* BitsName: pon_global_bias_en
	* Description: Enable  power to global bias
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonGlobalBiasEn : 1;        /*## attribute PonGlobalBiasEn */
	/**
	* BitsName: pon_lo_interface_en
	* Description: Enable  power to LO interface
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonLoInterfaceEn : 1;        /*## attribute PonLoInterfaceEn */
	/**
	* BitsName: pon_master_clk_en
	* Description: Enable  power to Master_clk PLL ATB
	* 0 : power not enabled for ATB
	* 1: power is enabled for ATB
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonMasterClkEn : 1;        /*## attribute PonMasterClkEn */
	/**
	* BitsName: pon_rx1_en
	* Description: Enable  power to RX1
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonRx1En : 1;        /*## attribute PonRx1En */
	/**
	* BitsName: pon_rx2_en
	* Description: Enable  power to RX2
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonRx2En : 1;        /*## attribute PonRx2En */
	/**
	* BitsName: pon_rx3_en
	* Description: Enable  power to RX3
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonRx3En : 1;        /*## attribute PonRx3En */
	/**
	* BitsName: pon_rx4_en
	* Description: Enable  power to RX4
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonRx4En : 1;        /*## attribute PonRx4En */
	/**
	* BitsName: pon_tx1_en
	* Description: Enable  power to TX1
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonTx1En : 1;        /*## attribute PonTx1En */
	/**
	* BitsName: pon_tx2_en
	* Description: Enable  power to TX2
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonTx2En : 1;        /*## attribute PonTx2En */
	/**
	* BitsName: pon_tx3_en
	* Description: Enable  power to TX3
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonTx3En : 1;        /*## attribute PonTx3En */
	/**
	* BitsName: pon_ssbmod_en
	* Description: Enable  power to SSBMOD/RFBIST
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonSsbmodEn : 1;        /*## attribute PonSsbmodEn */
	/**
	* BitsName: pon_global_ldo_en
	* Description: Has to be set as '1' for proper functioning of LDO.
	* Even though Global LDO is enabled on powerup, pon_ldo enables measurement of LDO signals for ATB.
	* 0 : Global LDO is not enabled for ATB Measurement
	* 1 : Global LDO is enabled for ATB Measurement
	*
	* For normal IP operation the default value is sufficient.
	*
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonGlobalLdoEn : 1;        /*## attribute PonGlobalLdoEn */
	/**
	* BitsName: pon_atb_en
	* Description: Enable  power to ATB
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonAtbEn : 1;        /*## attribute PonAtbEn */
	/**
	* BitsName: pon_otp_en
	* Description: Enable  power to ATB
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonOtpEn : 1;        /*## attribute PonOtpEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: pon_temp_digitizer_en
	* Description: Enable temp digitizer
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonTempDigitizerEn : 1;        /*## attribute PonTempDigitizerEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 12;        /*## attribute Reserved1 */
}R2M00_IpLevelPonEnableBits_t;
/**
* R2M00_IpResetControlBits_t
* RegisterName: IP_RESET_CONTROL
* IP  level reset control
* On power on or on application of reset  ( on reset release)  the reset to ISM space is automatically released by  Tef810x itself
* OTP module can be resetted only  by power cycle ( pin reset is not  connected to OTP mnodule)
* This register is used to apply a total reset ( register space and functional space of the IP)
* Address: 0x058
* ResetValue: 0x00040000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: reset_ser
	* Description: Reset serializer register space and function reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetSer : 1;        /*## attribute ResetSer */
	/**
	* BitsName: reset_chirp
	* Description: Reset chirp register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetChirp : 1;        /*## attribute ResetChirp */
	/**
	* BitsName: reset_adc12
	* Description: Reset ADC12 register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetAdc12 : 1;        /*## attribute ResetAdc12 */
	/**
	* BitsName: reset_adc34
	* Description: Reset ADC34 register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetAdc34 : 1;        /*## attribute ResetAdc34 */
	/**
	* BitsName: reset_global_bias
	* Description: Reset global bias register space and function
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetGlobalBias : 1;        /*## attribute ResetGlobalBias */
	/**
	* BitsName: reset_lo_interface
	* Description: Reset lo interface register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetLoInterface : 1;        /*## attribute ResetLoInterface */
	/**
	* BitsName: reset_master_clk
	* Description: Reset MC register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetMasterClk : 1;        /*## attribute ResetMasterClk */
	/**
	* BitsName: reset_rx1
	* Description: Reset chirp RX1  register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetRx1 : 1;        /*## attribute ResetRx1 */
	/**
	* BitsName: reset_rx2
	* Description: Reset chirp RX2  register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetRx2 : 1;        /*## attribute ResetRx2 */
	/**
	* BitsName: reset_rx3
	* Description: Reset chirp RX3 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetRx3 : 1;        /*## attribute ResetRx3 */
	/**
	* BitsName: reset_rx4
	* Description: Reset chirp  RX4 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetRx4 : 1;        /*## attribute ResetRx4 */
	/**
	* BitsName: reset_tx1
	* Description: Reset chirp TX1 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetTx1 : 1;        /*## attribute ResetTx1 */
	/**
	* BitsName: reset_tx2
	* Description: Reset chirp TX2 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetTx2 : 1;        /*## attribute ResetTx2 */
	/**
	* BitsName: reset_tx3
	* Description: Reset chirp TX3 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetTx3 : 1;        /*## attribute ResetTx3 */
	/**
	* BitsName: reset_ssbmod
	* Description: Reset chirp  SSBMOD register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetSsbmod : 1;        /*## attribute ResetSsbmod */
	/**
	* BitsName: reset_global_ldo
	* Description: Reset global LDO   register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetGlobalLdo : 1;        /*## attribute ResetGlobalLdo */
	/**
	* BitsName: reset_atb
	* Description: Reset ATB     register  space and function reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetAtb : 1;        /*## attribute ResetAtb */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: reset_ism
	* Description: Reset ISM register  space and function reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Note: ISM is out of reset after a POR  to support start up
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetIsm : 1;        /*## attribute ResetIsm */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 13;        /*## attribute Reserved1 */
}R2M00_IpResetControlBits_t;
/**
* R2M00_IpFunctionalResetControlBits_t
* RegisterName: IP_FUNCTIONAL_RESET_CONTROL
* IP level functional reset control
* On power on or on application of reset  ( on reset release)  the reset to ISM space is automatically released
* OTP module can be resetted only  by power cycle ( pin reset is not  connected to OTP mnodule)
* This register is used to apply a reset to the functional space of the IP
* Address: 0x05C
* ResetValue: 0x00040000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: fn_reset_ser
	* Description: Reset serializer  function
	* 0: IP functional space in reset state
	* 1: IP functional space out of reset
	* On start-up after application of power (PON), this reset shall be released after primary configuration of the register space.
	*
	* This reset shall be applied, during any internal (re)configuration change that impacts the external serializer interface operation. MCLK Calibration, MCLK M/S Phase Calibration, PDC change (lane speed) are some examples which will have influence on the Serializer clock and data. To avoid error states, the external receiver should be disabled (or configured to ignore the interface state changes) during these configuration changes.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetSer : 1;        /*## attribute FnResetSer */
	/**
	* BitsName: fn_reset_chirp
	* Description: Reset chirp  function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space..
	* In an application context this reset can be applied  based on application scenario  ( for example to stop an ongoing acquisition prematurely)
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetChirp : 1;        /*## attribute FnResetChirp */
	/**
	* BitsName: fn_reset_adc12
	* Description: Reset ADC12   function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. The IP shall not be placed under reset in an application context
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetAdc12 : 1;        /*## attribute FnResetAdc12 */
	/**
	* BitsName: fn_reset_adc34
	* Description: Reset ADC34 function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. The IP shall not be placed under reset in an application context
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetAdc34 : 1;        /*## attribute FnResetAdc34 */
	/**
	* BitsName: fn_reset_global_bias
	* Description: Reset global bias   function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. The IP shall not be placed under reset in an application context. This bit is not used
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetGlobalBias : 1;        /*## attribute FnResetGlobalBias */
	/**
	* BitsName: fn_reset_lo_interface
	* Description: Reset lo interface function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetLoInterface : 1;        /*## attribute FnResetLoInterface */
	/**
	* BitsName: fn_reset_master_clk
	* Description: Reset MC    function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	* On start up after application of power (PON), this reset shall be applied once after configuring the register space. The IP shall not be placed under functional reset in an application context, unless the master clock must be recovered from an error
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetMasterClk : 1;        /*## attribute FnResetMasterClk */
	/**
	* BitsName: fn_reset_rx1
	* Description: Not Used
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FnResetRx1 : 1;        /*## attribute FnResetRx1 */
	/**
	* BitsName: fn_reset_rx2
	* Description: Not Used
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FnResetRx2 : 1;        /*## attribute FnResetRx2 */
	/**
	* BitsName: fn_reset_rx3
	* Description: Not Used
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FnResetRx3 : 1;        /*## attribute FnResetRx3 */
	/**
	* BitsName: fn_reset_rx4
	* Description: Not Used
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FnResetRx4 : 1;        /*## attribute FnResetRx4 */
	/**
	* BitsName: fn_reset_tx1
	* Description: Reset  TX1  function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetTx1 : 1;        /*## attribute FnResetTx1 */
	/**
	* BitsName: fn_reset_tx2
	* Description: Reset  TX2 function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetTx2 : 1;        /*## attribute FnResetTx2 */
	/**
	* BitsName: fn_reset_tx3
	* Description: Reset TX3 function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetTx3 : 1;        /*## attribute FnResetTx3 */
	/**
	* BitsName: fn_reset_ssbmod
	* Description: Reset SSBMOD  function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetSsbmod : 1;        /*## attribute FnResetSsbmod */
	/**
	* BitsName: fn_reset_global_ldo
	* Description: Reset global LDO    function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* This reset is not used within the global LDO module
	*
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetGlobalLdo : 1;        /*## attribute FnResetGlobalLdo */
	/**
	* BitsName: fn_reset_atb
	* Description: Reset ATB    function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetAtb : 1;        /*## attribute FnResetAtb */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: fn_reset_ism
	* Description: Reset ISM     function
	* 0 : IP functional space in reset state
	* 1:  IP functional space out of reset
	* Note: ISM is out of reset after a POR  to support start up
	*
	* In an application context, this reset shall not be used  ( no use case to apply this reset)
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetIsm : 1;        /*## attribute FnResetIsm */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 13;        /*## attribute Reserved1 */
}R2M00_IpFunctionalResetControlBits_t;
/**
* R2M00_TempDigitizerAdcControlBits_t
* RegisterName: TEMP_DIGITIZER_ADC_CONTROL
* Temp Digitizer ADC related settings
* Address: 0x060
* ResetValue: 0x00000680
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: temp_digitizer_adc_clock_freq
	* Description: Controls the clock frequency of the temp digitizer ADC
	*
	* 2'h0: ADC frequency is 10 MHz
	* 2'h1: ADC frequency is   5 MHz
	* 2'h2: ADC frequency is  2.5 MHz
	* 3'h3: ADC frequency is  1.25 MHz
	* Other values: Not used and will result into default 4'h0
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDigitizerAdcClockFreq : 2;        /*## attribute TempDigitizerAdcClockFreq */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
	/**
	* BitsName: temp_digitizer_adc_samples
	* Description: The number of adc samples represented as power of 2
	* eg reset value => pow(2,6) = 64 samples
	*
	* Functional value => pow(2,4) = 16 samples
	*
	* Note: Max of 256 samples is supported i.e pow(2,8). 0 is not a valid value
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TempDigitizerAdcSamples : 4;        /*## attribute TempDigitizerAdcSamples */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 20;        /*## attribute Reserved2 */
}R2M00_TempDigitizerAdcControlBits_t;
/**
* R2M00_TempDigitizerFuncControlBits_t
* RegisterName: TEMP_DIGITIZER_FUNC_CONTROL
* TEMP digitizer related settings
* Address: 0x064
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: temp_digitizer_ts_module_select
	* Description: Selects the module from which the temp readout to be done. Setting multiple bits trigger the corresponding modules one after other. The time taken for temp read out of one module  = 10 us + 2 * num adc samples programmed * adc_clock_period (programmed) + 50 * 25 ns. Depending on the selected modules, the software has to wait before reading the temp. Alternatively ready bit (TEMP_DIGITIZER_DATA_*) can be polled
	*
	* 0th bit: TX1
	* 1st bit: TX2
	* 2nd bit: TX3
	* 3'rd bit: Chirp
	* Note: temp_digitizer_mux_ctrl[3:0] signal and temp_digitizer_active[3:0] signal at the interface is one hot encoded  based on this selection.
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDigitizerTsModuleSelect : 4;        /*## attribute TempDigitizerTsModuleSelect */
	/**
	* BitsName: trigger_temp_digitizer
	* Description: Trigger temp digitizer statemachine. This bit is cleared automatically when the temp digitizer operation is completed. Adc clock is supplied only when this bit is set.
	*
	* 0: Idle
	* 1: Enable while write/Read indicates busy
	*
	* Note: SW has to sample '0' before triggering
	* Read/Write: W
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TriggerTempDigitizer : 1;        /*## attribute TriggerTempDigitizer */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: enable_temp_digitizer
	* Description: Enable temp digitizer.
	*
	* 0: Disable. All functionalities related to temp digitizer are disabled.
	* 1: Enable. All functionalities related to temp digitizer are enabled
	*
	* Note: This bit needs to be set both in functional mode and debug mode as it controls all the functionalities related to temp digitizer
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t EnableTempDigitizer : 1;        /*## attribute EnableTempDigitizer */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 23;        /*## attribute Reserved1 */
}R2M00_TempDigitizerFuncControlBits_t;
/**
* R2M00_TempDigitizerDataTxBits_t
* RegisterName: TEMP_DIGITIZER_DATA_TX
* Temp (in Kelvin) read out data register for tx1, tx2, tx3
* Address: 0x068
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: temp_data_tx1
	* Description: The value represents the temp in Kelvin
	* Read/Write: R
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDataTx1 : 9;        /*## attribute TempDataTx1 */
	/**
	* BitsName: temp_data_tx2
	* Description: The value represents the temp in Kelvin
	* Read/Write: R
	* Bits: [17:9]
	* ResetValue: 0b000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDataTx2 : 9;        /*## attribute TempDataTx2 */
	/**
	* BitsName: temp_data_tx3
	* Description: The value represents the temp in Kelvin
	* Read/Write: R
	* Bits: [26:18]
	* ResetValue: 0b000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDataTx3 : 9;        /*## attribute TempDataTx3 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: temp_digitizer_ready_tx
	* Description: Data (temp) is valid only when ready is '1'
	* Read/Write: R
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDigitizerReadyTx : 1;        /*## attribute TempDigitizerReadyTx */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
}R2M00_TempDigitizerDataTxBits_t;
/**
* R2M00_TempDigitizerDataChirpBits_t
* RegisterName: TEMP_DIGITIZER_DATA_CHIRP
* Temp (in Kelvin) read out data register for chirp
* Address: 0x06C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: temp_data_chirp
	* Description: The value represents the temp in Kelvin
	* Read/Write: R
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDataChirp : 9;        /*## attribute TempDataChirp */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: temp_digitizer_ready_chirp
	* Description: Data (temp) is valid only when ready is '1'
	* Read/Write: R
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDigitizerReadyChirp : 1;        /*## attribute TempDigitizerReadyChirp */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 19;        /*## attribute Reserved1 */
}R2M00_TempDigitizerDataChirpBits_t;
/**
* R2M00_ScratchRegister1Bits_t
* RegisterName: SCRATCH_REGISTER1
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x080
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register1
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ScratchCtrlRegister1 : 32;        /*## attribute ScratchCtrlRegister1 */
}R2M00_ScratchRegister1Bits_t;
/**
* R2M00_ScratchRegister2Bits_t
* RegisterName: SCRATCH_REGISTER2
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x084
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register2
	* Description: nan
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister2 : 32;        /*## attribute ScratchCtrlRegister2 */
}R2M00_ScratchRegister2Bits_t;
/**
* R2M00_ScratchRegister3Bits_t
* RegisterName: SCRATCH_REGISTER3
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x088
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register3
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister3 : 32;        /*## attribute ScratchCtrlRegister3 */
}R2M00_ScratchRegister3Bits_t;
/**
* R2M00_ScratchRegister4Bits_t
* RegisterName: SCRATCH_REGISTER4
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x08C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register4
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister4 : 32;        /*## attribute ScratchCtrlRegister4 */
}R2M00_ScratchRegister4Bits_t;
/**
* R2M00_ScratchRegister5Bits_t
* RegisterName: SCRATCH_REGISTER5
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x090
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register5
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister5 : 32;        /*## attribute ScratchCtrlRegister5 */
}R2M00_ScratchRegister5Bits_t;
/**
* R2M00_ScratchRegister6Bits_t
* RegisterName: SCRATCH_REGISTER6
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x094
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register6
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister6 : 32;        /*## attribute ScratchCtrlRegister6 */
}R2M00_ScratchRegister6Bits_t;
/**
* R2M00_ScratchRegister7Bits_t
* RegisterName: SCRATCH_REGISTER7
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x098
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register7
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister7 : 32;        /*## attribute ScratchCtrlRegister7 */
}R2M00_ScratchRegister7Bits_t;
/**
* R2M00_ScratchRegister8Bits_t
* RegisterName: SCRATCH_REGISTER8
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x09C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register8
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister8 : 32;        /*## attribute ScratchCtrlRegister8 */
}R2M00_ScratchRegister8Bits_t;
/**
* R2M00_PinMuxBits_t
* RegisterName: PIN_MUX
* A register to support IC validation. Using this register, important signals from Central controller can be brought out to the pin interface.
*
* Address: 0x300
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pinmux_sel
	* Description: The value on pinmux_sel will decide the signal to be routed through mcu_int_mfio_a (formerly ready_int)
	* 00: interrupt_out is routed
	* 01: chirp event is routed i.e signal mcuint_chirpstart_out
	* (a. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
	* b. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip)
	* 10: Routes the signals based on validation_group_sel field in the same register (used only for validation and not for application)
	* 11: (Fsource& ~prconfigdone)
	*
	* Note: For 01 value, Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PinmuxSel : 2;        /*## attribute PinmuxSel */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
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
	uint32_t Reserved4 : 21;        /*## attribute Reserved4 */
}R2M00_PinMuxBits_t;
/**
* R2M00_TempDigitizerTxTempCoeffBits_t
* RegisterName: TEMP_DIGITIZER_TX_TEMP_COEFF
* Temp coefficient for TX1, TX2, TX3 from OTP
*
* Example Calculation:
*
* Temp provided =140c -> 140+273=413kelvin
* Adc reading for tx (with temp_digitizer_ts_swap_cur_dvbe_val = 1 and temp_digitizer_ts_buf_chopper_val = 0 (with negative chopper polarity))
* = (512-221)
*
* Adc reading for tx (with temp_digitizer_ts_swap_cur_dvbe_val = 0 and temp_digitizer_ts_buf_chopper_val = 1 (with positive chopper polarity))
* = (796-512)
*
* Avg adc reading for tx = (512-221)+(796-512)=575
* Coeff=(413/575)*1024=735.49=735.5
* Final temp read out =(735.5*575)/1024 =413kelvin
*
* Address: 0x318
* ResetValue: 0x2E0B82E0
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: tx1_temp_coefficient
	* Description: Temp coefficient for TX1
	*
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b1011100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Tx1TempCoefficient : 10;        /*## attribute Tx1TempCoefficient */
	/**
	* BitsName: tx2_temp_coefficient
	* Description: Temp coefficient for TX2
	*
	* Read/Write: RW
	* Bits: [19:10]
	* ResetValue: 0b1011100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Tx2TempCoefficient : 10;        /*## attribute Tx2TempCoefficient */
	/**
	* BitsName: tx3_temp_coefficient
	* Description: Temp coefficient for TX3
	*
	* Read/Write: RW
	* Bits: [29:20]
	* ResetValue: 0b1011100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Tx3TempCoefficient : 10;        /*## attribute Tx3TempCoefficient */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
}R2M00_TempDigitizerTxTempCoeffBits_t;
/**
* R2M00_TempDigitizerChirpTempCoeffBits_t
* RegisterName: TEMP_DIGITIZER_CHIRP_TEMP_COEFF
* Temp coefficient for Chirp from OTP
*
*
* Example Calculation:
*
* Temp provided =140c -> 140+273=413kelvin
* Adc reading for chirp (with temp_digitizer_ts_swap_cur_dvbe_val = 1 and temp_digitizer_ts_buf_chopper_val = 0 (with negative chopper polarity))
* = (512-221)
*
* Adc reading for chirp (with temp_digitizer_ts_swap_cur_dvbe_val = 0 and temp_digitizer_ts_buf_chopper_val = 1 (with positive chopper polarity))
* = (796-512)
*
* Avg adc reading for chirp = (512-221)+(796-512)=575
* Coeff=(413/575)*1024=735.49=735.5
* Final temp read out =(735.5*575)/1024 =413kelvin
* Address: 0x31C
* ResetValue: 0x000002E0
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: chirp_temp_coefficient
	* Description: Temp coefficient for Chirp
	*
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b1011100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t ChirpTempCoefficient : 10;        /*## attribute ChirpTempCoefficient */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 22;        /*## attribute Reserved0 */
}R2M00_TempDigitizerChirpTempCoeffBits_t;
/**
* R2M00_IntSetBits_t
* RegisterName: INT_SET
* Interrupt set register.A write will set the interrupt status. This register can be used for testing the interrupt functions at the MCU without actually creating an interrupt event
*
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the chip ( power down to TX,RX or chirp base don excessive power levels or temperature)
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int/. The delay depends on the decimation factor selected
* chirp_int : Indicates one of the following chirp events from timing engine
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
* Address: 0x600
* ResetValue: 0x00000000
* Read/Write: W
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: chirp_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntSet : 1;        /*## attribute ChirpIntSet */
	/**
	* BitsName: end_of_data_tnfr_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntSet : 1;        /*## attribute EndOfDataTnfrIntSet */
	/**
	* BitsName: status_wdt_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntSet : 1;        /*## attribute StatusWdtIntSet */
	/**
	* BitsName: rtm_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntSet : 1;        /*## attribute RtmIntSet */
	/**
	* BitsName: rf_powerdown_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntSet : 1;        /*## attribute RfPowerdownIntSet */
	/**
	* BitsName: crc_error_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntSet : 1;        /*## attribute CrcErrorIntSet */
	/**
	* BitsName: status_flag_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntSet : 1;        /*## attribute StatusFlagIntSet */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 24;        /*## attribute Reserved1 */
}R2M00_IntSetBits_t;
/**
* R2M00_IntClrBits_t
* RegisterName: INT_CLR
* Interrupt clear register.A write will clear the interrupt status , provided there are no underlying interrupt present.
* While clearing  it is possible to read back the  status of the interrupt before clearing. For this  in the SPI protocol C/S command bit need to be set to '0'
*
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the IC ( power down to TX,RX or chirp base don excessive power levels or temperature)
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int/. The delay depends on the decimation factor selected
* chirp_int : Indicates one of the following chirp events from timing engine
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
*
* Address: 0x604
* ResetValue: 0x00000000
* Read/Write: W
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: chirp_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntClr : 1;        /*## attribute ChirpIntClr */
	/**
	* BitsName: end_of_data_tnfr_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntClr : 1;        /*## attribute EndOfDataTnfrIntClr */
	/**
	* BitsName: status_wdt_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntClr : 1;        /*## attribute StatusWdtIntClr */
	/**
	* BitsName: rtm_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntClr : 1;        /*## attribute RtmIntClr */
	/**
	* BitsName: rf_powerdown_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntClr : 1;        /*## attribute RfPowerdownIntClr */
	/**
	* BitsName: crc_error_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntClr : 1;        /*## attribute CrcErrorIntClr */
	/**
	* BitsName: status_flag_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntClr : 1;        /*## attribute StatusFlagIntClr */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 24;        /*## attribute Reserved1 */
}R2M00_IntClrBits_t;
/**
* R2M00_IntRawStatusBits_t
* RegisterName: INT_RAW_STATUS
* Indicates the RAW interrupt status from the source.
* Useful for debugging
*
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the IC ( power down to TX,RX or chirp base don excessive power levels or temperature)
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int. The delay depends on the decimation factor selected
* chirp_int : Indicates one of the following chirp events from timing engine
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
* Address: 0x800
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: chirp_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntStatusRaw : 1;        /*## attribute ChirpIntStatusRaw */
	/**
	* BitsName: end_of_data_tnfr_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntStatusRaw : 1;        /*## attribute EndOfDataTnfrIntStatusRaw */
	/**
	* BitsName: status_wdt_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntStatusRaw : 1;        /*## attribute StatusWdtIntStatusRaw */
	/**
	* BitsName: rtm_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntStatusRaw : 1;        /*## attribute RtmIntStatusRaw */
	/**
	* BitsName: rf_powerdown_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntStatusRaw : 1;        /*## attribute RfPowerdownIntStatusRaw */
	/**
	* BitsName: crc_error_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntStatusRaw : 1;        /*## attribute CrcErrorIntStatusRaw */
	/**
	* BitsName: status_flag_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntStatusRaw : 1;        /*## attribute StatusFlagIntStatusRaw */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 24;        /*## attribute Reserved1 */
}R2M00_IntRawStatusBits_t;
/**
* R2M00_IntMaskedStatusBits_t
* RegisterName: INT_MASKED_STATUS
* Indicates the masked  interrupt status ( based on corresponding interrupt enable bit addr 0x54)
* crc_error_int: Interrupt is raised when a CRC error happens on SPI write data packet or in the SPI read command packet
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the Chip ( power down to TX,RX or chirp base don excessive power levels or temperature)
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int/. The delay depends on the decimation factor selected
* chirp_int : Indicates one of the following chirp events from timing engine
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
*
* Address: 0x804
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: chirp_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntStatusMasked : 1;        /*## attribute ChirpIntStatusMasked */
	/**
	* BitsName: end_of_data_tnfr_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntStatusMasked : 1;        /*## attribute EndOfDataTnfrIntStatusMasked */
	/**
	* BitsName: status_wdt_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntStatusMasked : 1;        /*## attribute StatusWdtIntStatusMasked */
	/**
	* BitsName: rtm_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntStatusMasked : 1;        /*## attribute RtmIntStatusMasked */
	/**
	* BitsName: rf_powerdown_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntStatusMasked : 1;        /*## attribute RfPowerdownIntStatusMasked */
	/**
	* BitsName: crc_error_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntStatusMasked : 1;        /*## attribute CrcErrorIntStatusMasked */
	/**
	* BitsName: status_flag_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntStatusMasked : 1;        /*## attribute StatusFlagIntStatusMasked */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 24;        /*## attribute Reserved1 */
}R2M00_IntMaskedStatusBits_t;
/**
* R2M00_RdlSiteStatusBits_t
* RegisterName: RDL_SITE_STATUS
* Indicates the manufacturing site that produced the package (RDL)
* Address: 0x810
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: rdl_site_status_reg_val
	* Description: 0: ATEP
	* 1: ASE
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RdlSiteStatusRegVal : 1;        /*## attribute RdlSiteStatusRegVal */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M00_RdlSiteStatusBits_t;
/**
* R2M00_CrcErrorStatus1Bits_t
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
}R2M00_CrcErrorStatus1Bits_t;
/**
* R2M00_CrcErrorStatus2Bits_t
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
}R2M00_CrcErrorStatus2Bits_t;
/**
* R2M00_CrcErrorStatus3Bits_t
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
	* Note: The status corresponds to last 2 registers listed i.e registers 65(msb) down to 64(lsb) and rest of the bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 32;        /*## attribute CrcErrorStatusReg3 */
}R2M00_CrcErrorStatus3Bits_t;
/**
* R2M00_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register
* Address: 0xFFC
* ResetValue: 0x00004004
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: idcode
	* Description: JTAG ID of tap module. {Major_TO, Minor_TO) => 01_00
	* Read/Write: R
	* Bits: [3:0]
	* ResetValue: 0b0100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Idcode : 4;        /*## attribute Idcode */
	/**
	* BitsName: aperture
	* Description: Aperture
	* Read/Write: R
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Aperture : 4;        /*## attribute Aperture */
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
	* ResetValue: 0b0000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M00_ModuleIdBits_t;

 #else
/**
* R2M00_SerialiserModeSelBits_t
* RegisterName: SERIALISER_MODE_SEL
* Software control register to select  the data interface. This register is active only if the respective functions are enabled through OTP.  For example if CSI2 is disabled through OTP, then it is not possible to select CSI2 mode through software
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
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
	/**
	* BitsName: sw_ctrl_ser_mode_sel
	* Description: This register is a conditionally writable register
	* 01: CSI2 mode
	* 10: LVDS
	* others: None enabled
	* The serializer mode can also be controlled  through OTP.
	*
	* Note: CSI2 and LVDS chip packages are different and one of the interface is disabled by default. So this option is used only for deselection of the interface and enabling of the only one available interface
	*
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t SwCtrlSerModeSel : 2;        /*## attribute SwCtrlSerModeSel */
}R2M00_SerialiserModeSelBits_t;
/**
* R2M00_LdoControlBits_t
* RegisterName: LDO_CONTROL
* Local LDO controls for the ADC, Serialiser and SSBMOD from OTP
*
* Address: 0x004
* ResetValue: 0x00000000
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
	* BitsName: ldo_sel_vout_ssbmod
	* Description: set output voltage of local LDO.
	* The values to be set will be coming from the  OTP
	*
	* Read/Write: RW
	* Bits: [28:24]
	* ResetValue: 0b00000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVoutSsbmod : 5;        /*## attribute LdoSelVoutSsbmod */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ldo_sel_vout_serialiser_csi2
	* Description: set output voltage of local LDO.
	* The values to be set will be coming from the  OTP
	*
	* Read/Write: RW
	* Bits: [20:16]
	* ResetValue: 0b00000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVoutSerialiserCsi2 : 5;        /*## attribute LdoSelVoutSerialiserCsi2 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ldo_sel_vout_serialiser_ser
	* Description: set output voltage of local LDO.
	* The values to be set will be coming from the  OTP
	* Read/Write: RW
	* Bits: [12:8]
	* ResetValue: 0b00000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVoutSerialiserSer : 5;        /*## attribute LdoSelVoutSerialiserSer */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ldo_sel_vout_adc
	* Description: set output voltage of local LDO.
	* The values to be set will be coming from the  OTP
	*
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b00000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LdoSelVoutAdc : 5;        /*## attribute LdoSelVoutAdc */
}R2M00_LdoControlBits_t;
/**
* R2M00_LdoEnableBits_t
* RegisterName: LDO_ENABLE
* Local LDO enables for the ADC, Serialiser and SSBMOD
*
* Address: 0x008
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
	* BitsName: ldo_en_ssbmod
	* Description: Enables local LDO
	* 0: LDO is disabled
	* 1: LDO is enabled
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdoEnSsbmod : 1;        /*## attribute LdoEnSsbmod */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ldo_en_serialiser_csi2
	* Description: Enables local LDO of the CSI2
	* 0: LDO is disabled
	* 1: LDO is enabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdoEnSerialiserCsi2 : 1;        /*## attribute LdoEnSerialiserCsi2 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ldo_en_serialiser_ser
	* Description: Enables local LDO of the Serialiser
	* 0: LDO is disabled
	* 1: LDO is enabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdoEnSerialiserSer : 1;        /*## attribute LdoEnSerialiserSer */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ldo_en_adc
	* Description: Enables local LDO of the ADC
	* 0: LDO is disabled
	* 1: LDO is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdoEnAdc : 1;        /*## attribute LdoEnAdc */
}R2M00_LdoEnableBits_t;
/**
* R2M00_McuintChirpstartOutPadControlBits_t
* RegisterName: MCUINT_CHIRPSTART_OUT_PAD_CONTROL
* This register controls the pad configuration.
*
* Multifunctional IO can perform the following operation
*
* Output Mode
* -------------------
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: followe chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
*
*
*
* Default values are sufficient for most of the use cases and application
*
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
* Address: 0x00C
* ResetValue: 0x00000361
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
	* BitsName: mcuint_chirpstart_mfio_ehs1
	* Description: IO Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEhs1 : 1;        /*## attribute McuintChirpstartMfioEhs1 */
	/**
	* BitsName: mcuint_chirpstart_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEhs0 : 1;        /*## attribute McuintChirpstartMfioEhs0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: mcuint_chirpstart_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEpd : 1;        /*## attribute McuintChirpstartMfioEpd */
	/**
	* BitsName: mcuint_chirpstart_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEpun : 1;        /*## attribute McuintChirpstartMfioEpun */
	/**
	* BitsName: mcuint_chirpstart_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEnzi : 1;        /*## attribute McuintChirpstartMfioEnzi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mcuint_chirpstart_mfio_en
	* Description: Disable  O/P  driver
	* 0 => O/P enabled
	* 1 => O/P disabled
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t McuintChirpstartMfioEn : 1;        /*## attribute McuintChirpstartMfioEn */
}R2M00_McuintChirpstartOutPadControlBits_t;
/**
* R2M00_ChirpstartInPadControlBits_t
* RegisterName: CHIRPSTART_IN_PAD_CONTROL
* chirp_start pin pad controls.
* Default values are sufficient for most of the use cases
*
* This multi function IO can be used both input and output mode.
*
* Input Mode
* ----------------
* a.. To trigger the chip for data acquisition by MCU or another chip i.e chirp_start trigger
*
* Output Mode
* ------------------
* a. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
* b. Routes the interrupt events from chip towards external world
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
* Address: 0x010
* ResetValue: 0x00000361
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
	* BitsName: chirpstart_out_route_en
	* Description: Selection bit for routing multifunction signal from chirp module to chirpstart_in pad output. This is disabled by default. This field needs to be configured along with chirpstart_mfio_en=0 to enable the chirp module multifunction in the output mode.
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The chirpstart_in pad output will be tied to 0
	*
	* Note: Please refer the chirp multifunction signal that can be enabled in the output mode of this pad in the register chirp_trigger_mode_control, field chirpstart_in_pad_func_sel in the Chirp module
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpstartOutRouteEn : 1;        /*## attribute ChirpstartOutRouteEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: chirpstart_in_route_en
	* Description: Selection bit for routing chirpstart_in pad input to chirpstart_in pin of chirp module. This is disabled by default. This field needs to be configured along with chirpstart_mfio_en=1 to enable the chirpstart in input mode.
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line chirpstart_in from CC towards chirp module will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpstartInRouteEn : 1;        /*## attribute ChirpstartInRouteEn */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: chirpstart_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEhs1 : 1;        /*## attribute ChirpstartMfioEhs1 */
	/**
	* BitsName: chirpstart_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEhs0 : 1;        /*## attribute ChirpstartMfioEhs0 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: chirpstart_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEpd : 1;        /*## attribute ChirpstartMfioEpd */
	/**
	* BitsName: chirpstart_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEpun : 1;        /*## attribute ChirpstartMfioEpun */
	/**
	* BitsName: chirpstart_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEnzi : 1;        /*## attribute ChirpstartMfioEnzi */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: chirpstart_mfio_en
	* Description: Disable  O/P  driver
	* 0 => O/P enabled
	* 1 => O/P disabled
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpstartMfioEn : 1;        /*## attribute ChirpstartMfioEn */
}R2M00_ChirpstartInPadControlBits_t;
/**
* R2M00_ErrorNPadControlBits_t
* RegisterName: ERROR_N_PAD_CONTROL
* error_n pin  pad controls.
* Default values are sufficient for most use cases, except the O/P control(bit 0).
* The O/P need to be explicitly enabled to the MCU at the end of  the Chip start up process.
*
* This pin is used for reporting safety errors within the Chip.  By default (on reset) this pin will remain in input mode ( O/P not driven). An external pull down resistor (4.7k)  has to be used  to pull this pin to low on start.  Once MCU complete the required start-up of the IC, then this pin can be configured to O/P mode.  If there are no underlying errors within the IC, and start up is Ok, then the inner safety monitor with drive this pin to a logic high value.  If an error is reported within the IC, this pin is driven low indicating a safety issue within the Chip.
*
*
* Address: 0x014
* ResetValue: 0x00000361
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
	* BitsName: error_n_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorNMfioEhs1 : 1;        /*## attribute ErrorNMfioEhs1 */
	/**
	* BitsName: error_n_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorNMfioEhs0 : 1;        /*## attribute ErrorNMfioEhs0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: error_n_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorNMfioEpd : 1;        /*## attribute ErrorNMfioEpd */
	/**
	* BitsName: error_n_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorNMfioEpun : 1;        /*## attribute ErrorNMfioEpun */
	/**
	* BitsName: error_n_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorNMfioEnzi : 1;        /*## attribute ErrorNMfioEnzi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: error_n_mfio_en
	* Description: Disable  O/P  driver
	* 0 => O/P enabled
	* 1 => O/P disabled
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorNMfioEn : 1;        /*## attribute ErrorNMfioEn */
}R2M00_ErrorNPadControlBits_t;
/**
* R2M00_ErrorResetPadControlBits_t
* RegisterName: ERROR_RESET_PAD_CONTROL
* error_reset  pin  pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* This pin can be used by MCU  to reset a functional safety error within the IC.   Typically this will clear all the latched errors within the inner safety monitors. However if  fresh errors are reported, then the error_n pin may remain low.
* Please note that it  is also possible to reset  errors within the IC through a SPI register write
*
*
* Address: 0x018
* ResetValue: 0x00000361
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
	* BitsName: error_reset_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEhs1 : 1;        /*## attribute ErrorResetMfioEhs1 */
	/**
	* BitsName: error_reset_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEhs0 : 1;        /*## attribute ErrorResetMfioEhs0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: error_reset_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEpd : 1;        /*## attribute ErrorResetMfioEpd */
	/**
	* BitsName: error_reset_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEpun : 1;        /*## attribute ErrorResetMfioEpun */
	/**
	* BitsName: error_reset_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEnzi : 1;        /*## attribute ErrorResetMfioEnzi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: error_reset_mfio_en
	* Description: Disable  O/P  driver
	* 0 => O/P enabled
	* 1 => O/P disabled
	* In a functional context the O/P is never enabled
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ErrorResetMfioEn : 1;        /*## attribute ErrorResetMfioEn */
}R2M00_ErrorResetPadControlBits_t;
/**
* R2M00_Tx1PsIPadControlBits_t
* RegisterName: TX1_PS_I_PAD_CONTROL
* TX unit 1 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x01C
* ResetValue: 0x00001361
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
	* BitsName: tx1_ps_i_ext_en
	* Description: Selection bit for routing tx1_ps pad input to ps_tx1_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx1_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIExtEn : 1;        /*## attribute Tx1PsIExtEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: tx1_ps_i_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEhs1 : 1;        /*## attribute Tx1PsIMfioEhs1 */
	/**
	* BitsName: tx1_ps_i_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEhs0 : 1;        /*## attribute Tx1PsIMfioEhs0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: tx1_ps_i_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEpd : 1;        /*## attribute Tx1PsIMfioEpd */
	/**
	* BitsName: tx1_ps_i_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEpun : 1;        /*## attribute Tx1PsIMfioEpun */
	/**
	* BitsName: tx1_ps_i_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEnzi : 1;        /*## attribute Tx1PsIMfioEnzi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: tx1_ps_i_mfio_en
	* Description: Disable  O/P  driver  (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsIMfioEn : 1;        /*## attribute Tx1PsIMfioEn */
}R2M00_Tx1PsIPadControlBits_t;
/**
* R2M00_Tx1PsQPadControlBits_t
* RegisterName: TX1_PS_Q_PAD_CONTROL
* TX unit 1 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, except the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x020
* ResetValue: 0x00001361
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
	* BitsName: tx1_ps_q_ext_en
	* Description: Selection bit for routing tx1_ps pad input to ps_tx1_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx1_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQExtEn : 1;        /*## attribute Tx1PsQExtEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: tx1_ps_q_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEhs1 : 1;        /*## attribute Tx1PsQMfioEhs1 */
	/**
	* BitsName: tx1_ps_q_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEhs0 : 1;        /*## attribute Tx1PsQMfioEhs0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: tx1_ps_q_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEpd : 1;        /*## attribute Tx1PsQMfioEpd */
	/**
	* BitsName: tx1_ps_q_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEpun : 1;        /*## attribute Tx1PsQMfioEpun */
	/**
	* BitsName: tx1_ps_q_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEnzi : 1;        /*## attribute Tx1PsQMfioEnzi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: tx1_ps_q_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx1PsQMfioEn : 1;        /*## attribute Tx1PsQMfioEn */
}R2M00_Tx1PsQPadControlBits_t;
/**
* R2M00_Tx2PsIPadControlBits_t
* RegisterName: TX2_PS_I_PAD_CONTROL
* TX unit 2 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x024
* ResetValue: 0x00001361
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
	* BitsName: tx2_ps_i_ext_en
	* Description: Selection bit for routing tx2_ps pad input to ps_tx2_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx2_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIExtEn : 1;        /*## attribute Tx2PsIExtEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: tx2_ps_i_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEhs1 : 1;        /*## attribute Tx2PsIMfioEhs1 */
	/**
	* BitsName: tx2_ps_i_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEhs0 : 1;        /*## attribute Tx2PsIMfioEhs0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: tx2_ps_i_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEpd : 1;        /*## attribute Tx2PsIMfioEpd */
	/**
	* BitsName: tx2_ps_i_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEpun : 1;        /*## attribute Tx2PsIMfioEpun */
	/**
	* BitsName: tx2_ps_i_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEnzi : 1;        /*## attribute Tx2PsIMfioEnzi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: tx2_ps_i_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsIMfioEn : 1;        /*## attribute Tx2PsIMfioEn */
}R2M00_Tx2PsIPadControlBits_t;
/**
* R2M00_Tx2PsQPadControlBits_t
* RegisterName: TX2_PS_Q_PAD_CONTROL
* TX unit 2 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x028
* ResetValue: 0x00001361
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
	* BitsName: tx2_ps_q_ext_en
	* Description: Selection bit for routing tx2_ps pad input to ps_tx2_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx2_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQExtEn : 1;        /*## attribute Tx2PsQExtEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: tx2_ps_q_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEhs1 : 1;        /*## attribute Tx2PsQMfioEhs1 */
	/**
	* BitsName: tx2_ps_q_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEhs0 : 1;        /*## attribute Tx2PsQMfioEhs0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: tx2_ps_q_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEpd : 1;        /*## attribute Tx2PsQMfioEpd */
	/**
	* BitsName: tx2_ps_q_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEpun : 1;        /*## attribute Tx2PsQMfioEpun */
	/**
	* BitsName: tx2_ps_q_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEnzi : 1;        /*## attribute Tx2PsQMfioEnzi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: tx2_ps_q_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx2PsQMfioEn : 1;        /*## attribute Tx2PsQMfioEn */
}R2M00_Tx2PsQPadControlBits_t;
/**
* R2M00_Tx3PsIPadControlBits_t
* RegisterName: TX3_PS_I_PAD_CONTROL
* TX unit 3 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x02C
* ResetValue: 0x00001361
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
	* BitsName: tx3_ps_i_ext_en
	* Description: Selection bit for routing tx3_ps pad input to ps_tx3_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx3_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIExtEn : 1;        /*## attribute Tx3PsIExtEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: tx3_ps_i_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEhs1 : 1;        /*## attribute Tx3PsIMfioEhs1 */
	/**
	* BitsName: tx3_ps_i_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEhs0 : 1;        /*## attribute Tx3PsIMfioEhs0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: tx3_ps_i_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEpd : 1;        /*## attribute Tx3PsIMfioEpd */
	/**
	* BitsName: tx3_ps_i_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEpun : 1;        /*## attribute Tx3PsIMfioEpun */
	/**
	* BitsName: tx3_ps_i_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEnzi : 1;        /*## attribute Tx3PsIMfioEnzi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: tx3_ps_i_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsIMfioEn : 1;        /*## attribute Tx3PsIMfioEn */
}R2M00_Tx3PsIPadControlBits_t;
/**
* R2M00_Tx3PsQPadControlBits_t
* RegisterName: TX3_PS_Q_PAD_CONTROL
* TX unit 3 binary phase control  pin pad controls.
* Default values are sufficient for most use cases, expect the O/P control(bit 0).
* This is an input pin.  Do not enable the O/P in functional mode.
*
* Address: 0x030
* ResetValue: 0x00001361
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
	* BitsName: tx3_ps_q_ext_en
	* Description: Selection bit for routing tx3_ps pad input to ps_tx3_ext. This is enabled by default
	*       1 -> Routing is enabled
	*       0 -> Routing is disabled. The output line ps_tx3_ext from CC will be tied to 0
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQExtEn : 1;        /*## attribute Tx3PsQExtEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: tx3_ps_q_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEhs1 : 1;        /*## attribute Tx3PsQMfioEhs1 */
	/**
	* BitsName: tx3_ps_q_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEhs0 : 1;        /*## attribute Tx3PsQMfioEhs0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: tx3_ps_q_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEpd : 1;        /*## attribute Tx3PsQMfioEpd */
	/**
	* BitsName: tx3_ps_q_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEpun : 1;        /*## attribute Tx3PsQMfioEpun */
	/**
	* BitsName: tx3_ps_q_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEnzi : 1;        /*## attribute Tx3PsQMfioEnzi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: tx3_ps_q_mfio_en
	* Description: Disable  O/P  driver (pad uses active-low control to set the output mode)
	* 0 => O/P enabled
	* 1 => O/P disabled
	* This is an input pin.
	* Do not enable the O/P in functional mode.
	*
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Tx3PsQMfioEn : 1;        /*## attribute Tx3PsQMfioEn */
}R2M00_Tx3PsQPadControlBits_t;
/**
* R2M00_MisoPadControlBits_t
* RegisterName: MISO_PAD_CONTROL
* MISO   pin pad controls.
* Default values are sufficient for most use cases
* This pad is  an O./P  pad and is directly controlled by the SS_N pin
*
* Address: 0x034
* ResetValue: 0x00001370
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
	* BitsName: miso_en_ctrl
	* Description: This bit controls the MISO pad enable alongwith the SS_N/CS_N chip input
	*
	* Normally MISO pad enable is selected by the chip select signal coming from SS_N/CS_N pad i.e whenever the chip is addressed, the MISO pad output is enabled.
	*
	* This selection (SS_N/CS_N) is used with this control bit to enable the MISO pad in the output mode. This is kept incase application decides to disable/tristate the MISO pad.
	*
	* 0 : MISO output pad disabled
	* 1:  MISO output pad is enabled with SS_N/CS_N
	*
	* Note: This feature might be useful in the  Leader-Follower configuration, where MCU wants to read from a particular chip or in general for debugging
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t MisoEnCtrl : 1;        /*## attribute MisoEnCtrl */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: miso_mfio_ehs1
	* Description: Speed Selection Bit1 (MSB).Combination of ehs1 and ehs 0 determines the speed of the PAD.
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MisoMfioEhs1 : 1;        /*## attribute MisoMfioEhs1 */
	/**
	* BitsName: miso_mfio_ehs0
	* Description: Speed Selection Bit0 (LSB)
	* ehs1  ehs0
	* 0       0    =>  low speed (12.5MHz)
	* 0       1    =>  normal speed (25MHz)
	* 1       0    =>  fast speed (50MHz)
	* 1       1   =>  high speed (80MHz)
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MisoMfioEhs0 : 1;        /*## attribute MisoMfioEhs0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: miso_mfio_epd
	* Description: Enable weak pull-down
	* 0 => pull down disabled
	* 1 => pull down enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MisoMfioEpd : 1;        /*## attribute MisoMfioEpd */
	/**
	* BitsName: miso_mfio_epun
	* Description: Enable weak pull-up
	* 0 => pull up enabled
	* 1 => pull up disabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MisoMfioEpun : 1;        /*## attribute MisoMfioEpun */
	/**
	* BitsName: miso_mfio_enzi
	* Description: Disable receiver function
	* This is not used in functional context.
	* 0: Receiver is enabled
	* 1: Receiver is disabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t MisoMfioEnzi : 1;        /*## attribute MisoMfioEnzi */
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
}R2M00_MisoPadControlBits_t;
/**
* R2M00_McuIntControlBits_t
* RegisterName: MCU_INT_CONTROL
* Software control register to control the interrupt polarity, and the type of interrupt required.
* Address: 0x040
* ResetValue: 0x01000090
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
	* BitsName: interrupt_polarity
	* Description:  0 Active low interrupt
	*  1: Active High interrupt
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t InterruptPolarity : 1;        /*## attribute InterruptPolarity */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 7;        /*## attribute Reserved1 */
	/**
	* BitsName: interrupt_level_or_pulse
	* Description: 1: Edge triggered interrupt. Ready Interrupt is activated for the time period mentioned in the ReadyInt_period.
	* 0: Level triggered interrupt. Once Ready Interrupt is activated, is cleared by MCU by writing through interrupt clear register
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t InterruptLevelOrPulse : 1;        /*## attribute InterruptLevelOrPulse */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 8;        /*## attribute Reserved2 */
	/**
	* BitsName: interrupt_period
	* Description: Activation Period for Ready Interrupt based on 40MHz(25 ns -Xtal Clock)
	* default: 3.6us(144). This period is applicable only for edge triggered interrupt mode.
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b10010000
	* Source: Application
	* FuSa: No
	*/
	uint32_t InterruptPeriod : 8;        /*## attribute InterruptPeriod */
}R2M00_McuIntControlBits_t;
/**
* R2M00_IntEnableBits_t
* RegisterName: INT_ENABLE
* Interrupt enable register. If corresponding bit is set, then the interrupt is passed to MCU
*
* status_flag_int_en: Interrupt is raised when a warning status flag is set
*
* crc_error_int:  Interrupt is raised  when a CRC checksum error is reported on the MISO lane ( For SPI write  complete payload is protected by CRC, for SPI read only on the command +address field)
*
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the IC ( power down to TX,RX or chirp base don excessive power levels or temperature)
*
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
*
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
*
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int/. The delay depends on the decimation factor selected
*
* chirp_int : Indicates one of the following chirp events from timing engine
* a. end of a  sequence
* b. end of chirp
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
*
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
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
	/**
	* BitsName: status_flag_int_en
	* Description: 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntEn : 1;        /*## attribute StatusFlagIntEn */
	/**
	* BitsName: crc_error_int_en
	* Description: 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntEn : 1;        /*## attribute CrcErrorIntEn */
	/**
	* BitsName: rf_powerdown_int_en
	* Description: 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntEn : 1;        /*## attribute RfPowerdownIntEn */
	/**
	* BitsName: rtm_int_en
	* Description:
	*
	* 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	*
	*
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntEn : 1;        /*## attribute RtmIntEn */
	/**
	* BitsName: status_wdt_int_en
	* Description:
	*
	* 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	*
	*
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntEn : 1;        /*## attribute StatusWdtIntEn */
	/**
	* BitsName: end_of_data_tnfr_int_en
	* Description:
	*
	* 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	*
	*
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntEn : 1;        /*## attribute EndOfDataTnfrIntEn */
	/**
	* BitsName: chirp_int_en
	* Description:
	* 0: Interrupt is not enabled
	* 1: Interrupt is enabled
	*
	*
	*
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntEn : 1;        /*## attribute ChirpIntEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
}R2M00_IntEnableBits_t;
/**
* R2M00_DynamicPowerControlEnableBits_t
* RegisterName: DYNAMIC_POWER_CONTROL_ENABLE
* Register to control the dynamic power of the chip.
*
* Dynamic power control is  possible  at two level
* 1. Dynamic power  control at chirp sequence level: When a module is selected for power control , then power to the module  is disabled outside  chirp sequence active period
* 2. Dynamic power control at individual chirp level.: When a module is selected for power control , then power to the module  is disabled outside  individual chirp  active period
*
* The following modules  can be brought under dynamic power control
* 1. Chirp
* 2. Individual TX units
* 3. Individual RX units
* 4. Serializer
* 5. ADC
* 6 .LO interface  (only in stand alone the chip)
*
* Within Dynamic power control, it is also possible to  choose  modules that are part of dynamic power control .
*
*
* Address: 0x048
* ResetValue: 0x00000000
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
	* BitsName: tx3_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx3DyPowerModeSel : 1;        /*## attribute Tx3DyPowerModeSel */
	/**
	* BitsName: tx2_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	* Read/Write: RW
	* Bits: [29]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx2DyPowerModeSel : 1;        /*## attribute Tx2DyPowerModeSel */
	/**
	* BitsName: tx1_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx1DyPowerModeSel : 1;        /*## attribute Tx1DyPowerModeSel */
	/**
	* BitsName: rx4_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [27]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx4DyPowerModeSel : 1;        /*## attribute Rx4DyPowerModeSel */
	/**
	* BitsName: rx3_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [26]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx3DyPowerModeSel : 1;        /*## attribute Rx3DyPowerModeSel */
	/**
	* BitsName: rx2_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp ally
	*
	* Read/Write: RW
	* Bits: [25]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx2DyPowerModeSel : 1;        /*## attribute Rx2DyPowerModeSel */
	/**
	* BitsName: rx1_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx1DyPowerModeSel : 1;        /*## attribute Rx1DyPowerModeSel */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: trigger_bg_cal_manual
	* Description: Write 1 to trigger ADC BG calibration manually. The "adc_bg_calib_mode_sel" field bits will be set to 2b10 automatically until next chirp sequence. Auto clear bit.
	* Read/Write: W
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t TriggerBgCalManual : 1;        /*## attribute TriggerBgCalManual */
	/**
	* BitsName: adc_bg_calib_mode_sel
	* Description: These bits will decide whether the ADC background calibration to be triggered during the dynamic powerdown mode of ADC before entering into the standby mode. For each weight of the ADC, the background calibration runs for approx 600 us.
	*
	* In general, at the end of the every chirp sequence, ADC calibration is triggered in dynamic powerdown mode as it allows more time for background calibration. But if the usecase has sufficient time between the chirps in dynamic powerdown mode, the adc background calibration can be triggered. After the background calibration, the ADC will get into standby mode.
	*
	* 00 : ADC background calibration is triggered at the end of the chirp sequence in the dynamic powerdown mode (Default Mode)
	* 01 : ADC background calibration is triggered at the end of every chirp in the dynamic powerdown mode
	* 10 : Set automatically when trigger_bg_cal_manual is written 1b1
	* 11:  No adc background calibration during dynamic powerdown mode
	*
	* Note1: From timing point of view, the background calibration enable is asserted before (atleast minimum of 2 cycles) the ADC pon is deasserted
	* Note2: In mode 00, 01 and 10 switching adc_dy_power_control from 0 to 1 can trigger a background calibration. If this is undesired the following sequence can be used:
	* a. set adc_bg_calib_mode_sel = 2b11
	* b. subsequently set adc_bg_calib_mode_sel= 2b00 or 2b01 depending on the mode required
	* c. then change adc_dy_power_control from 0 to 1
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t AdcBgCalibModeSel : 2;        /*## attribute AdcBgCalibModeSel */
	/**
	* BitsName: lo_interface_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LoInterfaceDyPowerModeSel : 1;        /*## attribute LoInterfaceDyPowerModeSel */
	/**
	* BitsName: adc_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp mically
	*
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AdcDyPowerModeSel : 1;        /*## attribute AdcDyPowerModeSel */
	/**
	* BitsName: chirp_dy_power_mode_sel
	* Description: Decides the control signal for dynamic power control
	* 0: Dynamic power is  controlled at chirp sequence level
	* 1: Dynamic power is controlled at individual chirp
	*
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpDyPowerModeSel : 1;        /*## attribute ChirpDyPowerModeSel */
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
	* BitsName: tx3_dy_power_control
	* Description: 0: TX3 unit is not under dynamic power control
	* 1: TX3 power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx3DyPowerControl : 1;        /*## attribute Tx3DyPowerControl */
	/**
	* BitsName: tx2_dy_power_control
	* Description: 0: TX2  unit is not under dynamic power control
	* 1: TX2  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx2DyPowerControl : 1;        /*## attribute Tx2DyPowerControl */
	/**
	* BitsName: tx1_dy_power_control
	* Description: 0: TX1  unit is not under dynamic power control
	* 1: TX1  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Tx1DyPowerControl : 1;        /*## attribute Tx1DyPowerControl */
	/**
	* BitsName: rx4_dy_power_control
	* Description: 0: RX4  unit is not under dynamic power control
	* 1: RX4  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx4DyPowerControl : 1;        /*## attribute Rx4DyPowerControl */
	/**
	* BitsName: rx3_dy_power_control
	* Description: 0: RX3  unit is not under dynamic power control
	* 1: RX3  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx3DyPowerControl : 1;        /*## attribute Rx3DyPowerControl */
	/**
	* BitsName: rx2_dy_power_control
	* Description: 0: RX2  unit is not under dynamic power control
	* 1: RX2  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx2DyPowerControl : 1;        /*## attribute Rx2DyPowerControl */
	/**
	* BitsName: rx1_dy_power_control
	* Description: 0: RX1  unit is not under dynamic power control
	* 1: RX1  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Rx1DyPowerControl : 1;        /*## attribute Rx1DyPowerControl */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: lo_interface_dy_power_control
	* Description: 0: LO Interface is not under dynamic power control
	* 1: LO Interface  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LoInterfaceDyPowerControl : 1;        /*## attribute LoInterfaceDyPowerControl */
	/**
	* BitsName: adc_dy_power_control
	* Description: 0: ADC12 and ADC34 is not under dynamic power control
	* 1: ADC12 and ADC34  power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AdcDyPowerControl : 1;        /*## attribute AdcDyPowerControl */
	/**
	* BitsName: chirp_dy_power_control
	* Description: 0: Chirp unit   is not under dynamic power control
	* 1: Chirp unit    power is  controlled dynamically
	*
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpDyPowerControl : 1;        /*## attribute ChirpDyPowerControl */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 1;        /*## attribute Reserved6 */
}R2M00_DynamicPowerControlEnableBits_t;
/**
* R2M00_DynamicPowerControlDelayBits_t
* RegisterName: DYNAMIC_POWER_CONTROL_DELAY
* At the end of data acquisition (chirp sequence level or at individual chirp level)  a timer delay is provided to switch off the power to the respective modules ..  This is primarily to avoid any race conditions within the system  (for example acquired data is flushed out completely before disabling the units). The timings are depends on the decimation  factor used.
* Minimum values
*
*
* This value has to be  minimum  equal to the typical chirp reset time duration
*
*
* Address: 0x04C
* ResetValue: 0x00C800C8
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: dy_pd_delay_val_chirp
	* Description: This control delays the powerdown of the modules which are configured for chirp based powerdown
	*
	*
	* This value has to be  minimum  equal to the typical chirp reset time duration
	* Read/Write: RW
	* Bits: [31:16]
	* ResetValue: 0b0000000011001000
	* Source: Application
	* FuSa: No
	*/
	uint32_t DyPdDelayValChirp : 16;        /*## attribute DyPdDelayValChirp */
	/**
	* BitsName: dy_pd_delay_val_seq
	* Description: This control delays the powerdown of the modules which are configured for chirp sequence based powerdown
	*
	*
	* This value has to be  minimum  equal to the typical chirp reset time duration
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000011001000
	* Source: Application
	* FuSa: No
	*/
	uint32_t DyPdDelayValSeq : 16;        /*## attribute DyPdDelayValSeq */
}R2M00_DynamicPowerControlDelayBits_t;
/**
* R2M00_IpLevelClockEnableBits_t
* RegisterName: IP_LEVEL_CLOCK_ENABLE
* Before accessing a block, the 40 MHz clock has to be enabled for that block.
* By default  clock to all functional  modules are disabled  (barring OTP , ISM ).
* Clock to  a module shall be enabled before accessing the IP.  Generally this is done as part of the start up process.  Clock to specific modules   shall be  disabled at the  end of a configuration write primarily as a mechanism to reduce interference.  However in general not  required or recommended .
* Address: 0x050
* ResetValue: 0x00060000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 13;        /*## attribute Reserved0 */
	/**
	* BitsName: clk40_ism
	* Description: Enable  40 MHz  clock to ISM  (register  access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Ism : 1;        /*## attribute Clk40Ism */
	/**
	* BitsName: clk40_otp
	* Description: Enable  40 MHz  clock to OTP (register access).
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Otp : 1;        /*## attribute Clk40Otp */
	/**
	* BitsName: clk40_atb
	* Description: Enable  40 MHz  clock to ATB (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Atb : 1;        /*## attribute Clk40Atb */
	/**
	* BitsName: clk40_global_ldo
	* Description: Enable  40 MHz  clock to global LDO (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40GlobalLdo : 1;        /*## attribute Clk40GlobalLdo */
	/**
	* BitsName: clk40_ssbmod
	* Description: Enable  40 MHz  clock to SSBMOD/RFBIST   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Ssbmod : 1;        /*## attribute Clk40Ssbmod */
	/**
	* BitsName: clk40_tx3
	* Description: Enable  40 MHz  clock to TX3   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Tx3 : 1;        /*## attribute Clk40Tx3 */
	/**
	* BitsName: clk40_tx2
	* Description: Enable  40 MHz  clock to TX2   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Tx2 : 1;        /*## attribute Clk40Tx2 */
	/**
	* BitsName: clk40_tx1
	* Description: Enable  40 MHz  clock to TX1   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Tx1 : 1;        /*## attribute Clk40Tx1 */
	/**
	* BitsName: clk40_rx4
	* Description: Enable  40 MHz  clock to RX4   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Rx4 : 1;        /*## attribute Clk40Rx4 */
	/**
	* BitsName: clk40_rx3
	* Description: Enable  40 MHz  clock to RX3   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Rx3 : 1;        /*## attribute Clk40Rx3 */
	/**
	* BitsName: clk40_rx2
	* Description: Enable  40 MHz  clock to RX2   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Rx2 : 1;        /*## attribute Clk40Rx2 */
	/**
	* BitsName: clk40_rx1
	* Description: Enable  40 MHz  clock to RX1   (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Rx1 : 1;        /*## attribute Clk40Rx1 */
	/**
	* BitsName: clk40_master_clk
	* Description: Enable  40 MHz  clock to master clock ATB. By default xtal clock is enabled so the register access is possible after reset
	* 0 : Clock not enabled for ATB access
	* 1: Clock is enabled for ATB access
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40MasterClk : 1;        /*## attribute Clk40MasterClk */
	/**
	* BitsName: clk40_lo_interface
	* Description: Enable  40 MHz  clock to LO interface  (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40LoInterface : 1;        /*## attribute Clk40LoInterface */
	/**
	* BitsName: clk40_global_bias
	* Description: Enable  40 MHz  clock to global bias  (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40GlobalBias : 1;        /*## attribute Clk40GlobalBias */
	/**
	* BitsName: clk40_adc34
	* Description: Enable  40 MHz  clock to ADC 3&4  (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Adc34 : 1;        /*## attribute Clk40Adc34 */
	/**
	* BitsName: clk40_adc12
	* Description: Enable  40 MHz  clock to ADC 1&2  (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Adc12 : 1;        /*## attribute Clk40Adc12 */
	/**
	* BitsName: clk40_chirp
	* Description: Enable  40 MHz  clock to Chirp  (register access as well as functional clock to timing engine)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Chirp : 1;        /*## attribute Clk40Chirp */
	/**
	* BitsName: clk40_ser
	* Description: Enable  40 MHz  clock to serialzer (register access)
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t Clk40Ser : 1;        /*## attribute Clk40Ser */
}R2M00_IpLevelClockEnableBits_t;
/**
* R2M00_IpLevelPonEnableBits_t
* RegisterName: IP_LEVEL_PON_ENABLE
* Analog power enables to individual modules. The modules which are not enabled from OTP will be always read back as disabled.
*
* These are static power enable signals to corresponding IP's ..  Once this bit is set, then actual application of power  can be controllerd through the dynamic_power_control_enable (0x44)  register.. ( power is always applied or controlled per chirp sequence level)
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
	uint32_t Reserved0 : 12;        /*## attribute Reserved0 */
	/**
	* BitsName: pon_temp_digitizer_en
	* Description: Enable temp digitizer
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonTempDigitizerEn : 1;        /*## attribute PonTempDigitizerEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: pon_otp_en
	* Description: Enable  power to ATB
	* 0 : Clock not enabled
	* 1: Clock is enabled
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonOtpEn : 1;        /*## attribute PonOtpEn */
	/**
	* BitsName: pon_atb_en
	* Description: Enable  power to ATB
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonAtbEn : 1;        /*## attribute PonAtbEn */
	/**
	* BitsName: pon_global_ldo_en
	* Description: Has to be set as '1' for proper functioning of LDO.
	* Even though Global LDO is enabled on powerup, pon_ldo enables measurement of LDO signals for ATB.
	* 0 : Global LDO is not enabled for ATB Measurement
	* 1 : Global LDO is enabled for ATB Measurement
	*
	* For normal IP operation the default value is sufficient.
	*
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonGlobalLdoEn : 1;        /*## attribute PonGlobalLdoEn */
	/**
	* BitsName: pon_ssbmod_en
	* Description: Enable  power to SSBMOD/RFBIST
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonSsbmodEn : 1;        /*## attribute PonSsbmodEn */
	/**
	* BitsName: pon_tx3_en
	* Description: Enable  power to TX3
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonTx3En : 1;        /*## attribute PonTx3En */
	/**
	* BitsName: pon_tx2_en
	* Description: Enable  power to TX2
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonTx2En : 1;        /*## attribute PonTx2En */
	/**
	* BitsName: pon_tx1_en
	* Description: Enable  power to TX1
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonTx1En : 1;        /*## attribute PonTx1En */
	/**
	* BitsName: pon_rx4_en
	* Description: Enable  power to RX4
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonRx4En : 1;        /*## attribute PonRx4En */
	/**
	* BitsName: pon_rx3_en
	* Description: Enable  power to RX3
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonRx3En : 1;        /*## attribute PonRx3En */
	/**
	* BitsName: pon_rx2_en
	* Description: Enable  power to RX2
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonRx2En : 1;        /*## attribute PonRx2En */
	/**
	* BitsName: pon_rx1_en
	* Description: Enable  power to RX1
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonRx1En : 1;        /*## attribute PonRx1En */
	/**
	* BitsName: pon_master_clk_en
	* Description: Enable  power to Master_clk PLL ATB
	* 0 : power not enabled for ATB
	* 1: power is enabled for ATB
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonMasterClkEn : 1;        /*## attribute PonMasterClkEn */
	/**
	* BitsName: pon_lo_interface_en
	* Description: Enable  power to LO interface
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonLoInterfaceEn : 1;        /*## attribute PonLoInterfaceEn */
	/**
	* BitsName: pon_global_bias_en
	* Description: Enable  power to global bias
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonGlobalBiasEn : 1;        /*## attribute PonGlobalBiasEn */
	/**
	* BitsName: pon_adc34_en
	* Description: Enable  power to ADC 3&4
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonAdc34En : 1;        /*## attribute PonAdc34En */
	/**
	* BitsName: pon_adc12_en
	* Description: Enable  power to ADC 1&2
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonAdc12En : 1;        /*## attribute PonAdc12En */
	/**
	* BitsName: pon_chirp_en
	* Description: Enable  power to Chirp
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonChirpEn : 1;        /*## attribute PonChirpEn */
	/**
	* BitsName: pon_ser_en
	* Description: Enable  power to Serialiser
	* 0 : power not enabled
	* 1: power is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonSerEn : 1;        /*## attribute PonSerEn */
}R2M00_IpLevelPonEnableBits_t;
/**
* R2M00_IpResetControlBits_t
* RegisterName: IP_RESET_CONTROL
* IP  level reset control
* On power on or on application of reset  ( on reset release)  the reset to ISM space is automatically released by  Tef810x itself
* OTP module can be resetted only  by power cycle ( pin reset is not  connected to OTP mnodule)
* This register is used to apply a total reset ( register space and functional space of the IP)
* Address: 0x058
* ResetValue: 0x00040000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 13;        /*## attribute Reserved0 */
	/**
	* BitsName: reset_ism
	* Description: Reset ISM register  space and function reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Note: ISM is out of reset after a POR  to support start up
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetIsm : 1;        /*## attribute ResetIsm */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: reset_atb
	* Description: Reset ATB     register  space and function reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetAtb : 1;        /*## attribute ResetAtb */
	/**
	* BitsName: reset_global_ldo
	* Description: Reset global LDO   register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetGlobalLdo : 1;        /*## attribute ResetGlobalLdo */
	/**
	* BitsName: reset_ssbmod
	* Description: Reset chirp  SSBMOD register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetSsbmod : 1;        /*## attribute ResetSsbmod */
	/**
	* BitsName: reset_tx3
	* Description: Reset chirp TX3 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetTx3 : 1;        /*## attribute ResetTx3 */
	/**
	* BitsName: reset_tx2
	* Description: Reset chirp TX2 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetTx2 : 1;        /*## attribute ResetTx2 */
	/**
	* BitsName: reset_tx1
	* Description: Reset chirp TX1 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetTx1 : 1;        /*## attribute ResetTx1 */
	/**
	* BitsName: reset_rx4
	* Description: Reset chirp  RX4 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetRx4 : 1;        /*## attribute ResetRx4 */
	/**
	* BitsName: reset_rx3
	* Description: Reset chirp RX3 register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetRx3 : 1;        /*## attribute ResetRx3 */
	/**
	* BitsName: reset_rx2
	* Description: Reset chirp RX2  register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetRx2 : 1;        /*## attribute ResetRx2 */
	/**
	* BitsName: reset_rx1
	* Description: Reset chirp RX1  register  space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetRx1 : 1;        /*## attribute ResetRx1 */
	/**
	* BitsName: reset_master_clk
	* Description: Reset MC register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetMasterClk : 1;        /*## attribute ResetMasterClk */
	/**
	* BitsName: reset_lo_interface
	* Description: Reset lo interface register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetLoInterface : 1;        /*## attribute ResetLoInterface */
	/**
	* BitsName: reset_global_bias
	* Description: Reset global bias register space and function
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetGlobalBias : 1;        /*## attribute ResetGlobalBias */
	/**
	* BitsName: reset_adc34
	* Description: Reset ADC34 register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetAdc34 : 1;        /*## attribute ResetAdc34 */
	/**
	* BitsName: reset_adc12
	* Description: Reset ADC12 register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetAdc12 : 1;        /*## attribute ResetAdc12 */
	/**
	* BitsName: reset_chirp
	* Description: Reset chirp register space and function  reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetChirp : 1;        /*## attribute ResetChirp */
	/**
	* BitsName: reset_ser
	* Description: Reset serializer register space and function reset
	* 0 : IP registers and functions are  in reset state
	* 1: IP register and functions are out of reset
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ResetSer : 1;        /*## attribute ResetSer */
}R2M00_IpResetControlBits_t;
/**
* R2M00_IpFunctionalResetControlBits_t
* RegisterName: IP_FUNCTIONAL_RESET_CONTROL
* IP level functional reset control
* On power on or on application of reset  ( on reset release)  the reset to ISM space is automatically released
* OTP module can be resetted only  by power cycle ( pin reset is not  connected to OTP mnodule)
* This register is used to apply a reset to the functional space of the IP
* Address: 0x05C
* ResetValue: 0x00040000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 13;        /*## attribute Reserved0 */
	/**
	* BitsName: fn_reset_ism
	* Description: Reset ISM     function
	* 0 : IP functional space in reset state
	* 1:  IP functional space out of reset
	* Note: ISM is out of reset after a POR  to support start up
	*
	* In an application context, this reset shall not be used  ( no use case to apply this reset)
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetIsm : 1;        /*## attribute FnResetIsm */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: fn_reset_atb
	* Description: Reset ATB    function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetAtb : 1;        /*## attribute FnResetAtb */
	/**
	* BitsName: fn_reset_global_ldo
	* Description: Reset global LDO    function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* This reset is not used within the global LDO module
	*
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetGlobalLdo : 1;        /*## attribute FnResetGlobalLdo */
	/**
	* BitsName: fn_reset_ssbmod
	* Description: Reset SSBMOD  function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetSsbmod : 1;        /*## attribute FnResetSsbmod */
	/**
	* BitsName: fn_reset_tx3
	* Description: Reset TX3 function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetTx3 : 1;        /*## attribute FnResetTx3 */
	/**
	* BitsName: fn_reset_tx2
	* Description: Reset  TX2 function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetTx2 : 1;        /*## attribute FnResetTx2 */
	/**
	* BitsName: fn_reset_tx1
	* Description: Reset  TX1  function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [11]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetTx1 : 1;        /*## attribute FnResetTx1 */
	/**
	* BitsName: fn_reset_rx4
	* Description: Not Used
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FnResetRx4 : 1;        /*## attribute FnResetRx4 */
	/**
	* BitsName: fn_reset_rx3
	* Description: Not Used
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FnResetRx3 : 1;        /*## attribute FnResetRx3 */
	/**
	* BitsName: fn_reset_rx2
	* Description: Not Used
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FnResetRx2 : 1;        /*## attribute FnResetRx2 */
	/**
	* BitsName: fn_reset_rx1
	* Description: Not Used
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FnResetRx1 : 1;        /*## attribute FnResetRx1 */
	/**
	* BitsName: fn_reset_master_clk
	* Description: Reset MC    function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	* On start up after application of power (PON), this reset shall be applied once after configuring the register space. The IP shall not be placed under functional reset in an application context, unless the master clock must be recovered from an error
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetMasterClk : 1;        /*## attribute FnResetMasterClk */
	/**
	* BitsName: fn_reset_lo_interface
	* Description: Reset lo interface function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. No reason to apply this reset afterwards
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetLoInterface : 1;        /*## attribute FnResetLoInterface */
	/**
	* BitsName: fn_reset_global_bias
	* Description: Reset global bias   function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. The IP shall not be placed under reset in an application context. This bit is not used
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetGlobalBias : 1;        /*## attribute FnResetGlobalBias */
	/**
	* BitsName: fn_reset_adc34
	* Description: Reset ADC34 function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. The IP shall not be placed under reset in an application context
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetAdc34 : 1;        /*## attribute FnResetAdc34 */
	/**
	* BitsName: fn_reset_adc12
	* Description: Reset ADC12   function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space.. The IP shall not be placed under reset in an application context
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetAdc12 : 1;        /*## attribute FnResetAdc12 */
	/**
	* BitsName: fn_reset_chirp
	* Description: Reset chirp  function
	* 0 : IP functional space  in reset state
	* 1:  IP functional space  out of reset
	*
	*
	* On start up after  application of power ( PON), this reset shall be applied once after configuring the register space..
	* In an application context this reset can be applied  based on application scenario  ( for example to stop an ongoing acquisition prematurely)
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetChirp : 1;        /*## attribute FnResetChirp */
	/**
	* BitsName: fn_reset_ser
	* Description: Reset serializer  function
	* 0: IP functional space in reset state
	* 1: IP functional space out of reset
	* On start-up after application of power (PON), this reset shall be released after primary configuration of the register space.
	*
	* This reset shall be applied, during any internal (re)configuration change that impacts the external serializer interface operation. MCLK Calibration, MCLK M/S Phase Calibration, PDC change (lane speed) are some examples which will have influence on the Serializer clock and data. To avoid error states, the external receiver should be disabled (or configured to ignore the interface state changes) during these configuration changes.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t FnResetSer : 1;        /*## attribute FnResetSer */
}R2M00_IpFunctionalResetControlBits_t;
/**
* R2M00_TempDigitizerAdcControlBits_t
* RegisterName: TEMP_DIGITIZER_ADC_CONTROL
* Temp Digitizer ADC related settings
* Address: 0x060
* ResetValue: 0x00000680
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 20;        /*## attribute Reserved0 */
	/**
	* BitsName: temp_digitizer_adc_samples
	* Description: The number of adc samples represented as power of 2
	* eg reset value => pow(2,6) = 64 samples
	*
	* Functional value => pow(2,4) = 16 samples
	*
	* Note: Max of 256 samples is supported i.e pow(2,8). 0 is not a valid value
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t TempDigitizerAdcSamples : 4;        /*## attribute TempDigitizerAdcSamples */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: temp_digitizer_adc_clock_freq
	* Description: Controls the clock frequency of the temp digitizer ADC
	*
	* 2'h0: ADC frequency is 10 MHz
	* 2'h1: ADC frequency is   5 MHz
	* 2'h2: ADC frequency is  2.5 MHz
	* 3'h3: ADC frequency is  1.25 MHz
	* Other values: Not used and will result into default 4'h0
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDigitizerAdcClockFreq : 2;        /*## attribute TempDigitizerAdcClockFreq */
}R2M00_TempDigitizerAdcControlBits_t;
/**
* R2M00_TempDigitizerFuncControlBits_t
* RegisterName: TEMP_DIGITIZER_FUNC_CONTROL
* TEMP digitizer related settings
* Address: 0x064
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
	* BitsName: enable_temp_digitizer
	* Description: Enable temp digitizer.
	*
	* 0: Disable. All functionalities related to temp digitizer are disabled.
	* 1: Enable. All functionalities related to temp digitizer are enabled
	*
	* Note: This bit needs to be set both in functional mode and debug mode as it controls all the functionalities related to temp digitizer
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t EnableTempDigitizer : 1;        /*## attribute EnableTempDigitizer */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: trigger_temp_digitizer
	* Description: Trigger temp digitizer statemachine. This bit is cleared automatically when the temp digitizer operation is completed. Adc clock is supplied only when this bit is set.
	*
	* 0: Idle
	* 1: Enable while write/Read indicates busy
	*
	* Note: SW has to sample '0' before triggering
	* Read/Write: W
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TriggerTempDigitizer : 1;        /*## attribute TriggerTempDigitizer */
	/**
	* BitsName: temp_digitizer_ts_module_select
	* Description: Selects the module from which the temp readout to be done. Setting multiple bits trigger the corresponding modules one after other. The time taken for temp read out of one module  = 10 us + 2 * num adc samples programmed * adc_clock_period (programmed) + 50 * 25 ns. Depending on the selected modules, the software has to wait before reading the temp. Alternatively ready bit (TEMP_DIGITIZER_DATA_*) can be polled
	*
	* 0th bit: TX1
	* 1st bit: TX2
	* 2nd bit: TX3
	* 3'rd bit: Chirp
	* Note: temp_digitizer_mux_ctrl[3:0] signal and temp_digitizer_active[3:0] signal at the interface is one hot encoded  based on this selection.
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDigitizerTsModuleSelect : 4;        /*## attribute TempDigitizerTsModuleSelect */
}R2M00_TempDigitizerFuncControlBits_t;
/**
* R2M00_TempDigitizerDataTxBits_t
* RegisterName: TEMP_DIGITIZER_DATA_TX
* Temp (in Kelvin) read out data register for tx1, tx2, tx3
* Address: 0x068
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: temp_digitizer_ready_tx
	* Description: Data (temp) is valid only when ready is '1'
	* Read/Write: R
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDigitizerReadyTx : 1;        /*## attribute TempDigitizerReadyTx */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: temp_data_tx3
	* Description: The value represents the temp in Kelvin
	* Read/Write: R
	* Bits: [26:18]
	* ResetValue: 0b000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDataTx3 : 9;        /*## attribute TempDataTx3 */
	/**
	* BitsName: temp_data_tx2
	* Description: The value represents the temp in Kelvin
	* Read/Write: R
	* Bits: [17:9]
	* ResetValue: 0b000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDataTx2 : 9;        /*## attribute TempDataTx2 */
	/**
	* BitsName: temp_data_tx1
	* Description: The value represents the temp in Kelvin
	* Read/Write: R
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDataTx1 : 9;        /*## attribute TempDataTx1 */
}R2M00_TempDigitizerDataTxBits_t;
/**
* R2M00_TempDigitizerDataChirpBits_t
* RegisterName: TEMP_DIGITIZER_DATA_CHIRP
* Temp (in Kelvin) read out data register for chirp
* Address: 0x06C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: temp_digitizer_ready_chirp
	* Description: Data (temp) is valid only when ready is '1'
	* Read/Write: R
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDigitizerReadyChirp : 1;        /*## attribute TempDigitizerReadyChirp */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: temp_data_chirp
	* Description: The value represents the temp in Kelvin
	* Read/Write: R
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TempDataChirp : 9;        /*## attribute TempDataChirp */
}R2M00_TempDigitizerDataChirpBits_t;
/**
* R2M00_ScratchRegister1Bits_t
* RegisterName: SCRATCH_REGISTER1
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x080
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register1
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ScratchCtrlRegister1 : 32;        /*## attribute ScratchCtrlRegister1 */
}R2M00_ScratchRegister1Bits_t;
/**
* R2M00_ScratchRegister2Bits_t
* RegisterName: SCRATCH_REGISTER2
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x084
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register2
	* Description: nan
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister2 : 32;        /*## attribute ScratchCtrlRegister2 */
}R2M00_ScratchRegister2Bits_t;
/**
* R2M00_ScratchRegister3Bits_t
* RegisterName: SCRATCH_REGISTER3
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x088
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register3
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister3 : 32;        /*## attribute ScratchCtrlRegister3 */
}R2M00_ScratchRegister3Bits_t;
/**
* R2M00_ScratchRegister4Bits_t
* RegisterName: SCRATCH_REGISTER4
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x08C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register4
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister4 : 32;        /*## attribute ScratchCtrlRegister4 */
}R2M00_ScratchRegister4Bits_t;
/**
* R2M00_ScratchRegister5Bits_t
* RegisterName: SCRATCH_REGISTER5
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x090
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register5
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister5 : 32;        /*## attribute ScratchCtrlRegister5 */
}R2M00_ScratchRegister5Bits_t;
/**
* R2M00_ScratchRegister6Bits_t
* RegisterName: SCRATCH_REGISTER6
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x094
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register6
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister6 : 32;        /*## attribute ScratchCtrlRegister6 */
}R2M00_ScratchRegister6Bits_t;
/**
* R2M00_ScratchRegister7Bits_t
* RegisterName: SCRATCH_REGISTER7
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x098
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register7
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister7 : 32;        /*## attribute ScratchCtrlRegister7 */
}R2M00_ScratchRegister7Bits_t;
/**
* R2M00_ScratchRegister8Bits_t
* RegisterName: SCRATCH_REGISTER8
* RW register to store information during debugging/validation.
* This register is implemented with non-resettable flops. So after powerup, this register to be initialized with the proper value for further usage
* Address: 0x09C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: scratch_ctrl_register8
	* Description: RW register to store information during debugging/validation
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ScratchCtrlRegister8 : 32;        /*## attribute ScratchCtrlRegister8 */
}R2M00_ScratchRegister8Bits_t;
/**
* R2M00_PinMuxBits_t
* RegisterName: PIN_MUX
* A register to support IC validation. Using this register, important signals from Central controller can be brought out to the pin interface.
*
* Address: 0x300
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 21;        /*## attribute Reserved0 */
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
	uint32_t Reserved4 : 2;        /*## attribute Reserved4 */
	/**
	* BitsName: pinmux_sel
	* Description: The value on pinmux_sel will decide the signal to be routed through mcu_int_mfio_a (formerly ready_int)
	* 00: interrupt_out is routed
	* 01: chirp event is routed i.e signal mcuint_chirpstart_out
	* (a. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
	* b. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip)
	* 10: Routes the signals based on validation_group_sel field in the same register (used only for validation and not for application)
	* 11: (Fsource& ~prconfigdone)
	*
	* Note: For 01 value, Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PinmuxSel : 2;        /*## attribute PinmuxSel */
}R2M00_PinMuxBits_t;
/**
* R2M00_TempDigitizerTxTempCoeffBits_t
* RegisterName: TEMP_DIGITIZER_TX_TEMP_COEFF
* Temp coefficient for TX1, TX2, TX3 from OTP
*
* Example Calculation:
*
* Temp provided =140c -> 140+273=413kelvin
* Adc reading for tx (with temp_digitizer_ts_swap_cur_dvbe_val = 1 and temp_digitizer_ts_buf_chopper_val = 0 (with negative chopper polarity))
* = (512-221)
*
* Adc reading for tx (with temp_digitizer_ts_swap_cur_dvbe_val = 0 and temp_digitizer_ts_buf_chopper_val = 1 (with positive chopper polarity))
* = (796-512)
*
* Avg adc reading for tx = (512-221)+(796-512)=575
* Coeff=(413/575)*1024=735.49=735.5
* Final temp read out =(735.5*575)/1024 =413kelvin
*
* Address: 0x318
* ResetValue: 0x2E0B82E0
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
	* BitsName: tx3_temp_coefficient
	* Description: Temp coefficient for TX3
	*
	* Read/Write: RW
	* Bits: [29:20]
	* ResetValue: 0b1011100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Tx3TempCoefficient : 10;        /*## attribute Tx3TempCoefficient */
	/**
	* BitsName: tx2_temp_coefficient
	* Description: Temp coefficient for TX2
	*
	* Read/Write: RW
	* Bits: [19:10]
	* ResetValue: 0b1011100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Tx2TempCoefficient : 10;        /*## attribute Tx2TempCoefficient */
	/**
	* BitsName: tx1_temp_coefficient
	* Description: Temp coefficient for TX1
	*
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b1011100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t Tx1TempCoefficient : 10;        /*## attribute Tx1TempCoefficient */
}R2M00_TempDigitizerTxTempCoeffBits_t;
/**
* R2M00_TempDigitizerChirpTempCoeffBits_t
* RegisterName: TEMP_DIGITIZER_CHIRP_TEMP_COEFF
* Temp coefficient for Chirp from OTP
*
*
* Example Calculation:
*
* Temp provided =140c -> 140+273=413kelvin
* Adc reading for chirp (with temp_digitizer_ts_swap_cur_dvbe_val = 1 and temp_digitizer_ts_buf_chopper_val = 0 (with negative chopper polarity))
* = (512-221)
*
* Adc reading for chirp (with temp_digitizer_ts_swap_cur_dvbe_val = 0 and temp_digitizer_ts_buf_chopper_val = 1 (with positive chopper polarity))
* = (796-512)
*
* Avg adc reading for chirp = (512-221)+(796-512)=575
* Coeff=(413/575)*1024=735.49=735.5
* Final temp read out =(735.5*575)/1024 =413kelvin
* Address: 0x31C
* ResetValue: 0x000002E0
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
	* BitsName: chirp_temp_coefficient
	* Description: Temp coefficient for Chirp
	*
	* Read/Write: RW
	* Bits: [9:0]
	* ResetValue: 0b1011100000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t ChirpTempCoefficient : 10;        /*## attribute ChirpTempCoefficient */
}R2M00_TempDigitizerChirpTempCoeffBits_t;
/**
* R2M00_IntSetBits_t
* RegisterName: INT_SET
* Interrupt set register.A write will set the interrupt status. This register can be used for testing the interrupt functions at the MCU without actually creating an interrupt event
*
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the chip ( power down to TX,RX or chirp base don excessive power levels or temperature)
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int/. The delay depends on the decimation factor selected
* chirp_int : Indicates one of the following chirp events from timing engine
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
* Address: 0x600
* ResetValue: 0x00000000
* Read/Write: W
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
	/**
	* BitsName: status_flag_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntSet : 1;        /*## attribute StatusFlagIntSet */
	/**
	* BitsName: crc_error_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntSet : 1;        /*## attribute CrcErrorIntSet */
	/**
	* BitsName: rf_powerdown_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntSet : 1;        /*## attribute RfPowerdownIntSet */
	/**
	* BitsName: rtm_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntSet : 1;        /*## attribute RtmIntSet */
	/**
	* BitsName: status_wdt_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntSet : 1;        /*## attribute StatusWdtIntSet */
	/**
	* BitsName: end_of_data_tnfr_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntSet : 1;        /*## attribute EndOfDataTnfrIntSet */
	/**
	* BitsName: chirp_int_set
	* Description: 0: no action
	* 1: Generate an interrupt
	* Read/Write: W
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntSet : 1;        /*## attribute ChirpIntSet */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
}R2M00_IntSetBits_t;
/**
* R2M00_IntClrBits_t
* RegisterName: INT_CLR
* Interrupt clear register.A write will clear the interrupt status , provided there are no underlying interrupt present.
* While clearing  it is possible to read back the  status of the interrupt before clearing. For this  in the SPI protocol C/S command bit need to be set to '0'
*
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the IC ( power down to TX,RX or chirp base don excessive power levels or temperature)
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int/. The delay depends on the decimation factor selected
* chirp_int : Indicates one of the following chirp events from timing engine
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
*
* Address: 0x604
* ResetValue: 0x00000000
* Read/Write: W
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
	/**
	* BitsName: status_flag_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntClr : 1;        /*## attribute StatusFlagIntClr */
	/**
	* BitsName: crc_error_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntClr : 1;        /*## attribute CrcErrorIntClr */
	/**
	* BitsName: rf_powerdown_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntClr : 1;        /*## attribute RfPowerdownIntClr */
	/**
	* BitsName: rtm_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntClr : 1;        /*## attribute RtmIntClr */
	/**
	* BitsName: status_wdt_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntClr : 1;        /*## attribute StatusWdtIntClr */
	/**
	* BitsName: end_of_data_tnfr_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntClr : 1;        /*## attribute EndOfDataTnfrIntClr */
	/**
	* BitsName: chirp_int_clr
	* Description: 0: no action
	* 1: clear pending interrupt ( clear only the latch)
	* Read/Write: W
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntClr : 1;        /*## attribute ChirpIntClr */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
}R2M00_IntClrBits_t;
/**
* R2M00_IntRawStatusBits_t
* RegisterName: INT_RAW_STATUS
* Indicates the RAW interrupt status from the source.
* Useful for debugging
*
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the IC ( power down to TX,RX or chirp base don excessive power levels or temperature)
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int. The delay depends on the decimation factor selected
* chirp_int : Indicates one of the following chirp events from timing engine
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
* Address: 0x800
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
	/**
	* BitsName: status_flag_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntStatusRaw : 1;        /*## attribute StatusFlagIntStatusRaw */
	/**
	* BitsName: crc_error_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntStatusRaw : 1;        /*## attribute CrcErrorIntStatusRaw */
	/**
	* BitsName: rf_powerdown_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntStatusRaw : 1;        /*## attribute RfPowerdownIntStatusRaw */
	/**
	* BitsName: rtm_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntStatusRaw : 1;        /*## attribute RtmIntStatusRaw */
	/**
	* BitsName: status_wdt_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntStatusRaw : 1;        /*## attribute StatusWdtIntStatusRaw */
	/**
	* BitsName: end_of_data_tnfr_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntStatusRaw : 1;        /*## attribute EndOfDataTnfrIntStatusRaw */
	/**
	* BitsName: chirp_int_status_raw
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntStatusRaw : 1;        /*## attribute ChirpIntStatusRaw */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
}R2M00_IntRawStatusBits_t;
/**
* R2M00_IntMaskedStatusBits_t
* RegisterName: INT_MASKED_STATUS
* Indicates the masked  interrupt status ( based on corresponding interrupt enable bit addr 0x54)
* crc_error_int: Interrupt is raised when a CRC error happens on SPI write data packet or in the SPI read command packet
* rf_powerdown_int : Interrupt is raised, when a RF power down event is triggered within the Chip ( power down to TX,RX or chirp base don excessive power levels or temperature)
* rtm_int : Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
* status_wdt_int: Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
* end_of_data_tnfr_int : Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.  This is a delayed version of the end_of_data_acq_int/. The delay depends on the decimation factor selected
* chirp_int : Indicates one of the following chirp events from timing engine
*
* a. Routes the interrupt events from chip towards external world
* b. Routes the chirp_start signal towards the other chips. eg: follower chip chirp_start trigger
* c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
*
* Note: Please refer CHIRP_TRIGGER_MODE_CONTROL register (addr: 0x098) in the timing engine for all the functional configuration
*
* Address: 0x804
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
	/**
	* BitsName: status_flag_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusFlagIntStatusMasked : 1;        /*## attribute StatusFlagIntStatusMasked */
	/**
	* BitsName: crc_error_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CrcErrorIntStatusMasked : 1;        /*## attribute CrcErrorIntStatusMasked */
	/**
	* BitsName: rf_powerdown_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [5]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RfPowerdownIntStatusMasked : 1;        /*## attribute RfPowerdownIntStatusMasked */
	/**
	* BitsName: rtm_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t RtmIntStatusMasked : 1;        /*## attribute RtmIntStatusMasked */
	/**
	* BitsName: status_wdt_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StatusWdtIntStatusMasked : 1;        /*## attribute StatusWdtIntStatusMasked */
	/**
	* BitsName: end_of_data_tnfr_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [2]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EndOfDataTnfrIntStatusMasked : 1;        /*## attribute EndOfDataTnfrIntStatusMasked */
	/**
	* BitsName: chirp_int_status_masked
	* Description: 0: interrupt not set
	* 1: interrupt set
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpIntStatusMasked : 1;        /*## attribute ChirpIntStatusMasked */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
}R2M00_IntMaskedStatusBits_t;
/**
* R2M00_RdlSiteStatusBits_t
* RegisterName: RDL_SITE_STATUS
* Indicates the manufacturing site that produced the package (RDL)
* Address: 0x810
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
	* BitsName: rdl_site_status_reg_val
	* Description: 0: ATEP
	* 1: ASE
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t RdlSiteStatusRegVal : 1;        /*## attribute RdlSiteStatusRegVal */
}R2M00_RdlSiteStatusBits_t;
/**
* R2M00_CrcErrorStatus1Bits_t
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
}R2M00_CrcErrorStatus1Bits_t;
/**
* R2M00_CrcErrorStatus2Bits_t
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
}R2M00_CrcErrorStatus2Bits_t;
/**
* R2M00_CrcErrorStatus3Bits_t
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
	* Note: The status corresponds to last 2 registers listed i.e registers 65(msb) down to 64(lsb) and rest of the bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 32;        /*## attribute CrcErrorStatusReg3 */
}R2M00_CrcErrorStatus3Bits_t;
/**
* R2M00_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register
* Address: 0xFFC
* ResetValue: 0x00004004
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000000000
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
	* Description: Aperture
	* Read/Write: R
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Aperture : 4;        /*## attribute Aperture */
	/**
	* BitsName: idcode
	* Description: JTAG ID of tap module. {Major_TO, Minor_TO) => 01_00
	* Read/Write: R
	* Bits: [3:0]
	* ResetValue: 0b0100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Idcode : 4;        /*## attribute Idcode */
}R2M00_ModuleIdBits_t;
#endif
/**
* R2M00_SerialiserModeSelUnion_t
* R2M00_SerialiserModeSelUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_SerialiserModeSelBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_SerialiserModeSelUnion_t;

/**
* R2M00_LdoControlUnion_t
* R2M00_LdoControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_LdoControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_LdoControlUnion_t;

/**
* R2M00_LdoEnableUnion_t
* R2M00_LdoEnableUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_LdoEnableBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_LdoEnableUnion_t;

/**
* R2M00_McuintChirpstartOutPadControlUnion_t
* R2M00_McuintChirpstartOutPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_McuintChirpstartOutPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_McuintChirpstartOutPadControlUnion_t;

/**
* R2M00_ChirpstartInPadControlUnion_t
* R2M00_ChirpstartInPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ChirpstartInPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ChirpstartInPadControlUnion_t;

/**
* R2M00_ErrorNPadControlUnion_t
* R2M00_ErrorNPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ErrorNPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ErrorNPadControlUnion_t;

/**
* R2M00_ErrorResetPadControlUnion_t
* R2M00_ErrorResetPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ErrorResetPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ErrorResetPadControlUnion_t;

/**
* R2M00_Tx1PsIPadControlUnion_t
* R2M00_Tx1PsIPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_Tx1PsIPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_Tx1PsIPadControlUnion_t;

/**
* R2M00_Tx1PsQPadControlUnion_t
* R2M00_Tx1PsQPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_Tx1PsQPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_Tx1PsQPadControlUnion_t;

/**
* R2M00_Tx2PsIPadControlUnion_t
* R2M00_Tx2PsIPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_Tx2PsIPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_Tx2PsIPadControlUnion_t;

/**
* R2M00_Tx2PsQPadControlUnion_t
* R2M00_Tx2PsQPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_Tx2PsQPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_Tx2PsQPadControlUnion_t;

/**
* R2M00_Tx3PsIPadControlUnion_t
* R2M00_Tx3PsIPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_Tx3PsIPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_Tx3PsIPadControlUnion_t;

/**
* R2M00_Tx3PsQPadControlUnion_t
* R2M00_Tx3PsQPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_Tx3PsQPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_Tx3PsQPadControlUnion_t;

/**
* R2M00_MisoPadControlUnion_t
* R2M00_MisoPadControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_MisoPadControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_MisoPadControlUnion_t;

/**
* R2M00_McuIntControlUnion_t
* R2M00_McuIntControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_McuIntControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_McuIntControlUnion_t;

/**
* R2M00_IntEnableUnion_t
* R2M00_IntEnableUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_IntEnableBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_IntEnableUnion_t;

/**
* R2M00_DynamicPowerControlEnableUnion_t
* R2M00_DynamicPowerControlEnableUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_DynamicPowerControlEnableBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_DynamicPowerControlEnableUnion_t;

/**
* R2M00_DynamicPowerControlDelayUnion_t
* R2M00_DynamicPowerControlDelayUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_DynamicPowerControlDelayBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_DynamicPowerControlDelayUnion_t;

/**
* R2M00_IpLevelClockEnableUnion_t
* R2M00_IpLevelClockEnableUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_IpLevelClockEnableBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_IpLevelClockEnableUnion_t;

/**
* R2M00_IpLevelPonEnableUnion_t
* R2M00_IpLevelPonEnableUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_IpLevelPonEnableBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_IpLevelPonEnableUnion_t;

/**
* R2M00_IpResetControlUnion_t
* R2M00_IpResetControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_IpResetControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_IpResetControlUnion_t;

/**
* R2M00_IpFunctionalResetControlUnion_t
* R2M00_IpFunctionalResetControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_IpFunctionalResetControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_IpFunctionalResetControlUnion_t;

/**
* R2M00_TempDigitizerAdcControlUnion_t
* R2M00_TempDigitizerAdcControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_TempDigitizerAdcControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_TempDigitizerAdcControlUnion_t;

/**
* R2M00_TempDigitizerFuncControlUnion_t
* R2M00_TempDigitizerFuncControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_TempDigitizerFuncControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_TempDigitizerFuncControlUnion_t;

/**
* R2M00_TempDigitizerDataTxUnion_t
* R2M00_TempDigitizerDataTxUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_TempDigitizerDataTxBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_TempDigitizerDataTxUnion_t;

/**
* R2M00_TempDigitizerDataChirpUnion_t
* R2M00_TempDigitizerDataChirpUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_TempDigitizerDataChirpBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_TempDigitizerDataChirpUnion_t;

/**
* R2M00_ScratchRegister1Union_t
* R2M00_ScratchRegister1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ScratchRegister1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ScratchRegister1Union_t;

/**
* R2M00_ScratchRegister2Union_t
* R2M00_ScratchRegister2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ScratchRegister2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ScratchRegister2Union_t;

/**
* R2M00_ScratchRegister3Union_t
* R2M00_ScratchRegister3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ScratchRegister3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ScratchRegister3Union_t;

/**
* R2M00_ScratchRegister4Union_t
* R2M00_ScratchRegister4Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ScratchRegister4Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ScratchRegister4Union_t;

/**
* R2M00_ScratchRegister5Union_t
* R2M00_ScratchRegister5Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ScratchRegister5Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ScratchRegister5Union_t;

/**
* R2M00_ScratchRegister6Union_t
* R2M00_ScratchRegister6Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ScratchRegister6Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ScratchRegister6Union_t;

/**
* R2M00_ScratchRegister7Union_t
* R2M00_ScratchRegister7Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ScratchRegister7Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ScratchRegister7Union_t;

/**
* R2M00_ScratchRegister8Union_t
* R2M00_ScratchRegister8Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ScratchRegister8Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ScratchRegister8Union_t;

/**
* R2M00_PinMuxUnion_t
* R2M00_PinMuxUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_PinMuxBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_PinMuxUnion_t;

/**
* R2M00_TempDigitizerTxTempCoeffUnion_t
* R2M00_TempDigitizerTxTempCoeffUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_TempDigitizerTxTempCoeffBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_TempDigitizerTxTempCoeffUnion_t;

/**
* R2M00_TempDigitizerChirpTempCoeffUnion_t
* R2M00_TempDigitizerChirpTempCoeffUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_TempDigitizerChirpTempCoeffBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_TempDigitizerChirpTempCoeffUnion_t;

/**
* R2M00_IntSetUnion_t
* R2M00_IntSetUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_IntSetBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_IntSetUnion_t;

/**
* R2M00_IntClrUnion_t
* R2M00_IntClrUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_IntClrBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_IntClrUnion_t;

/**
* R2M00_IntRawStatusUnion_t
* R2M00_IntRawStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_IntRawStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_IntRawStatusUnion_t;

/**
* R2M00_IntMaskedStatusUnion_t
* R2M00_IntMaskedStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_IntMaskedStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_IntMaskedStatusUnion_t;

/**
* R2M00_RdlSiteStatusUnion_t
* R2M00_RdlSiteStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_RdlSiteStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_RdlSiteStatusUnion_t;

/**
* R2M00_CrcErrorStatus1Union_t
* R2M00_CrcErrorStatus1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_CrcErrorStatus1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_CrcErrorStatus1Union_t;

/**
* R2M00_CrcErrorStatus2Union_t
* R2M00_CrcErrorStatus2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_CrcErrorStatus2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_CrcErrorStatus2Union_t;

/**
* R2M00_CrcErrorStatus3Union_t
* R2M00_CrcErrorStatus3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_CrcErrorStatus3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_CrcErrorStatus3Union_t;

/**
* R2M00_ModuleIdUnion_t
* R2M00_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M00_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M00_ModuleIdUnion_t;


#endif
