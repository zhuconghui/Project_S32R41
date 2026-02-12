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
* @reg_es2_lvds.h
*/
#ifndef REG_ES2_LVDS_H
#define REG_ES2_LVDS_H
#include <stdint.h>
/**
* R2M01_IDLE_PATTERN_U16
* RegisterName: MOD01_IDLE_PATTERN
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x000002AB
*/
#define R2M01_IDLE_PATTERN_U16 (uint16_t)0x0000
/**
* R2M01_CLOCK_CH_TX_DATA_12X1_U16
* RegisterName: MOD01_CLOCK_CH_TX_DATA_12X1
* AccessMode: RW
* AddressRange: 0x0004 - 0x0008
* ResetValue: 0x00000FC0
*/
#define R2M01_CLOCK_CH_TX_DATA_12X1_U16 (uint16_t)0x0004
/**
* R2M01_TRANSMIT_PHASE_CONTROL_U16
* RegisterName: MOD01_TRANSMIT_PHASE_CONTROL
* AccessMode: RW
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x00000011
*/
#define R2M01_TRANSMIT_PHASE_CONTROL_U16 (uint16_t)0x0008
/**
* R2M01_MSB_LSB_CONTROL_U16
* RegisterName: MOD01_MSB_LSB_CONTROL
* AccessMode: RW
* AddressRange: 0x000C - 0x0010
* ResetValue: 0x00000001
*/
#define R2M01_MSB_LSB_CONTROL_U16 (uint16_t)0x000C
/**
* R2M01_LVDS_CONFIG_REG_U16
* RegisterName: MOD01_LVDS_CONFIG_REG
* AccessMode: RW
* AddressRange: 0x0010 - 0x0014
* ResetValue: 0x10000000
*/
#define R2M01_LVDS_CONFIG_REG_U16 (uint16_t)0x0010
/**
* R2M01_LVDS_CRC_CTRL1_U16
* RegisterName: MOD01_LVDS_CRC_CTRL1
* AccessMode: RW
* AddressRange: 0x0014 - 0x0018
* ResetValue: 0xFFFFFFFF
*/
#define R2M01_LVDS_CRC_CTRL1_U16 (uint16_t)0x0014
/**
* R2M01_LVDS_CRC_CTRL2_U16
* RegisterName: MOD01_LVDS_CRC_CTRL2
* AccessMode: RW
* AddressRange: 0x0018 - 0x001C
* ResetValue: 0xFFFFFFFF
*/
#define R2M01_LVDS_CRC_CTRL2_U16 (uint16_t)0x0018
/**
* R2M01_LVDS_CRC_CTRL3_U16
* RegisterName: MOD01_LVDS_CRC_CTRL3
* AccessMode: RW
* AddressRange: 0x001C - 0x0020
* ResetValue: 0x0FF00110
*/
#define R2M01_LVDS_CRC_CTRL3_U16 (uint16_t)0x001C
/**
* R2M01_PDC_CONFIG_REG_U16
* RegisterName: MOD01_PDC_CONFIG_REG
* AccessMode: RW
* AddressRange: 0x0020 - 0x0024
* ResetValue: 0x01A9A700
*/
#define R2M01_PDC_CONFIG_REG_U16 (uint16_t)0x0020
/**
* R2M01_LVDS_OUTPUT_INVERT_CTRL_U16
* RegisterName: MOD01_LVDS_OUTPUT_INVERT_CTRL
* AccessMode: RW
* AddressRange: 0x0024 - 0x0028
* ResetValue: 0x00000000
*/
#define R2M01_LVDS_OUTPUT_INVERT_CTRL_U16 (uint16_t)0x0024
/**
* R2M01_LVDS_SER_GLOBAL_PAD_CTRL_U16
* RegisterName: MOD01_LVDS_SER_GLOBAL_PAD_CTRL
* AccessMode: RW
* AddressRange: 0x0028 - 0x002C
* ResetValue: 0x00001000
*/
#define R2M01_LVDS_SER_GLOBAL_PAD_CTRL_U16 (uint16_t)0x0028
/**
* R2M01_LVDS_SER_PAD_CTRL1_U16
* RegisterName: MOD01_LVDS_SER_PAD_CTRL1
* AccessMode: RW
* AddressRange: 0x002C - 0x0030
* ResetValue: 0x00000000
*/
#define R2M01_LVDS_SER_PAD_CTRL1_U16 (uint16_t)0x002C
/**
* R2M01_LVDS_SER_PAD_CTRL2_U16
* RegisterName: MOD01_LVDS_SER_PAD_CTRL2
* AccessMode: RW
* AddressRange: 0x0030 - 0x0034
* ResetValue: 0x00000000
*/
#define R2M01_LVDS_SER_PAD_CTRL2_U16 (uint16_t)0x0030
/**
* R2M01_LVDS_SER_PAD_CTRL3_U16
* RegisterName: MOD01_LVDS_SER_PAD_CTRL3
* AccessMode: RW
* AddressRange: 0x0034 - 0x0038
* ResetValue: 0x00000131
*/
#define R2M01_LVDS_SER_PAD_CTRL3_U16 (uint16_t)0x0034
/**
* R2M01_SPARE_REG1_U16
* RegisterName: MOD01_SPARE_REG1
* AccessMode: RW
* AddressRange: 0x0038 - 0x003C
* ResetValue: 0x00000000
*/
#define R2M01_SPARE_REG1_U16 (uint16_t)0x0038
/**
* R2M01_LVDS_TX_CONTROL_U16
* RegisterName: MOD01_LVDS_TX_CONTROL
* AccessMode: RW
* AddressRange: 0x0050 - 0x0054
* ResetValue: 0x00000000
*/
#define R2M01_LVDS_TX_CONTROL_U16 (uint16_t)0x0050
/**
* R2M01_ADC_TEST_DATA_MUX_U16
* RegisterName: MOD01_ADC_TEST_DATA_MUX
* AccessMode: RW
* AddressRange: 0x0060 - 0x0064
* ResetValue: 0x00000FFF
*/
#define R2M01_ADC_TEST_DATA_MUX_U16 (uint16_t)0x0060
/**
* R2M01_PRBS_CONTROL_U16
* RegisterName: MOD01_PRBS_CONTROL
* AccessMode: RW
* AddressRange: 0x0064 - 0x0068
* ResetValue: 0x00000FFF
*/
#define R2M01_PRBS_CONTROL_U16 (uint16_t)0x0064
/**
* R2M01_WINDOW_ACTIVE_SEL_U16
* RegisterName: MOD01_WINDOW_ACTIVE_SEL
* AccessMode: RW
* AddressRange: 0x0068 - 0x006C
* ResetValue: 0x00000000
*/
#define R2M01_WINDOW_ACTIVE_SEL_U16 (uint16_t)0x0068
/**
* R2M01_MASTER_IDIV_CTRL_U16
* RegisterName: MOD01_MASTER_IDIV_CTRL
* AccessMode: RW
* AddressRange: 0x006C - 0x0070
* ResetValue: 0x000400B0
*/
#define R2M01_MASTER_IDIV_CTRL_U16 (uint16_t)0x006C
/**
* R2M01_PDC_SHIFT_REG_IDIV_CTRL_U16
* RegisterName: MOD01_PDC_SHIFT_REG_IDIV_CTRL
* AccessMode: RW
* AddressRange: 0x0070 - 0x0074
* ResetValue: 0x00010001
*/
#define R2M01_PDC_SHIFT_REG_IDIV_CTRL_U16 (uint16_t)0x0070
/**
* R2M01_LVDS_VCM_U16
* RegisterName: MOD01_LVDS_VCM
* AccessMode: RW
* AddressRange: 0x0108 - 0x010C
* ResetValue: 0x00000000
*/
#define R2M01_LVDS_VCM_U16 (uint16_t)0x0108
/**
* R2M01_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD01_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0404 - 0x0408
* ResetValue: 0x00000000
*/
#define R2M01_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0404
/**
* R2M01_REF_CNTR_INIT_U16
* RegisterName: MOD01_REF_CNTR_INIT
* AccessMode: RW
* AddressRange: 0x0500 - 0x0504
* ResetValue: 0x01E00028
*/
#define R2M01_REF_CNTR_INIT_U16 (uint16_t)0x0500
/**
* R2M01_FREQ_COUNTER_START_U16
* RegisterName: MOD01_FREQ_COUNTER_START
* AccessMode: RW
* AddressRange: 0x0504 - 0x0508
* ResetValue: 0x00000100
*/
#define R2M01_FREQ_COUNTER_START_U16 (uint16_t)0x0504
/**
* R2M01_FREQ_COUNTER_READ_VALUE_U16
* RegisterName: MOD01_FREQ_COUNTER_READ_VALUE
* AccessMode: R
* AddressRange: 0x0508 - 0x050C
* ResetValue: 0x00000000
*/
#define R2M01_FREQ_COUNTER_READ_VALUE_U16 (uint16_t)0x0508
/**
* R2M01_REF_COUNTER_READ_VALUE_U16
* RegisterName: MOD01_REF_COUNTER_READ_VALUE
* AccessMode: R
* AddressRange: 0x050C - 0x0510
* ResetValue: 0x00000000
*/
#define R2M01_REF_COUNTER_READ_VALUE_U16 (uint16_t)0x050C
/**
* R2M01_CRC_ERROR_STATUS1_U16
* RegisterName: MOD01_CRC_ERROR_STATUS1
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M01_CRC_ERROR_STATUS1_U16 (uint16_t)0x0F40
/**
* R2M01_CRC_ERROR_STATUS2_U16
* RegisterName: MOD01_CRC_ERROR_STATUS2
* AccessMode: R
* AddressRange: 0x0F44 - 0x0F48
* ResetValue: 0x00000000
*/
#define R2M01_CRC_ERROR_STATUS2_U16 (uint16_t)0x0F44
/**
* R2M01_MODULE_ID_U16
* RegisterName: MOD01_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x00014101
*/
#define R2M01_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M01_IdlePatternBits_t
* RegisterName: IDLE_PATTERN
* This register is used in RAW mode.
* Address: 0x000
* ResetValue: 0x000002AB
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: idlepattern
	* Description: Idle pattern sent in RAW mode outside the valid data window.
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b001010101011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Idlepattern : 12;        /*## attribute Idlepattern */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 20;        /*## attribute Reserved0 */
}R2M01_IdlePatternBits_t;
/**
* R2M01_ClockChTxData12X1Bits_t
* RegisterName: CLOCK_CH_TX_DATA_12X1
* This register is used in RAW mode for controlling Frame clock pattern (duty cycle) send over LVDS Link.
* Address: 0x004
* ResetValue: 0x00000FC0
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: clockchtxdata12x1
	* Description: Frame Clock pattern to be send  on LVDS frame clock channel in RAW mode. This register can be used to vary the duty cycle of the frame clock
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b111111000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Clockchtxdata12X1 : 12;        /*## attribute Clockchtxdata12X1 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 4;        /*## attribute Reserved0 */
	/**
	* BitsName: lvds_lane_calibration_en
	* Description: Calibration Mode : When set , this bit ensures that all the LVDS lines start from zero irrespective of the frame_clock/bit_clock phase. And, it also enables the toggling of frame_clock to appear on the output line even in frame_clock gated mode.
	* 0: Normal mode of opeartion.
	* 1: All LVDS Lines start from zero + disable the window_active based frame_clock gating
	* 
	* During Calibration Low_power_mode towards serializer from the Central Control should not be set.
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsLaneCalibrationEn : 1;        /*## attribute LvdsLaneCalibrationEn */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 15;        /*## attribute Reserved1 */
}R2M01_ClockChTxData12X1Bits_t;
/**
* R2M01_TransmitPhaseControlBits_t
* RegisterName: TRANSMIT_PHASE_CONTROL
* This register is common for all the modes.Used for controlling phase of bit_clk and frame_clk sent over LVDS link.
* Address: 0x008
* ResetValue: 0x00000011
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: bit_clk_phase
	* Description: Within a frame boundary
	* 0:  first serial bit starts with bit_clk Fall edge
	* 1: first serial bit starts with bit_clk rise edge. 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BitClkPhase : 1;        /*## attribute BitClkPhase */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: frame_clk_phase
	* Description: Within a frame boundary
	* 0: Serial bit starts from Rise edge of frame_clk
	* 1: Serial bit starts from Fall edge of frame clk.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FrameClkPhase : 1;        /*## attribute FrameClkPhase */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M01_TransmitPhaseControlBits_t;
/**
* R2M01_MsbLsbControlBits_t
* RegisterName: MSB_LSB_CONTROL
* This register is common for all the modes.In serial to parallel conversion this register determines whether MSB/LSB of the parallal word sent first.
* Address: 0x00C
* ResetValue: 0x00000001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: msb_first
	* Description: LSB/MSB of the Parallel word send first:
	* 0:LSB first
	* 1: MSB first
	* Note: This setting applies to all the bits (header + data payload + footer)
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MsbFirst : 1;        /*## attribute MsbFirst */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: packet_endianness
	* Description: 0: Sends MS first in Packet Header and Packet Footer(crc)
	* 1: Send LS first in Packet Header and Packet Footer(crc)
	* Note: This is only applicable to Packet Header and Packet Footer not for Data.
	*           packeten field should be set to enable the header. lvds_crc_control field should be set to enable the CRC footer.
	* 
	* Note: CRC is 32 bit and WordCount is 16 bit, so it is split into MS and LS halfs before parallel to serial conversion.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PacketEndianness : 1;        /*## attribute PacketEndianness */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M01_MsbLsbControlBits_t;
/**
* R2M01_LvdsConfigRegBits_t
* RegisterName: LVDS_CONFIG_REG
* This register is common for all the modes.
* Address: 0x010
* ResetValue: 0x10000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: lvds_crc_control
	* Description: 
	* 1 = ADC data will be CRC protected, the resultant 32-bit CRC is appended to packet Footer ( send as two 16-bit halfwords) 
	* 0 =  No CRC Footer
	* 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LvdsCrcControl : 1;        /*## attribute LvdsCrcControl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: packeten
	* Description: Packet Header Enable :
	* 0: no Packet Header on transmitted data Packet.
	* 1: Packet Header is appended to the  Data Packet.
	* Note:Packet header contains Chirp No and Sample Count(no of ADC samples sent over the LVDS Link)
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Packeten : 1;        /*## attribute Packeten */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: adc_data_streaming_mode_en
	* Description: adc_data_streaming mode enable:Used for ADC validation
	* 0: IDLE pattern is send outside the valid data window
	* 1:ADC data is send outside the valid data window.
	* 
	* Note: mask_input_w_wa should be set to '0' to enable the adc streaming mode.
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcDataStreamingModeEn : 1;        /*## attribute AdcDataStreamingModeEn */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: packet_header_format
	* Description: Defines the order in which the  words are arranged in packet header.
	* 0:  Chirp Number(MS) -> Word Count(MS) -> Word Count(LS) -> Chirp Number(LS)
	* 1:  Chirp Number(MS) -> Chirp Number(LS) -> Word Count(MS) -> Word Count(LS).
	* Note: Chirp num and Word Count are 16-bit each. There are zero padded to convert to 24bits. The zero padded 24bit value is split into two halfs, MS & LS of 12 bits each. Thess are appended to data as part of packet header.
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PacketHeaderFormat : 1;        /*## attribute PacketHeaderFormat */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: disable_lvds_lanes_during_idle_time
	* Description: 0: All LVDS lanes are enabled all the time.
	* 1: All LVDS lanes (bit_clk, frame_clk, data lanes) are disabled when ADC sampling is not active. Lanes enabled only during window_active.
	* 
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DisableLvdsLanesDuringIdleTime : 1;        /*## attribute DisableLvdsLanesDuringIdleTime */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 7;        /*## attribute Reserved4 */
	/**
	* BitsName: data_valid_delay_ctrl
	* Description: Data valid signals comes through an MFIO pad.We can delay the data valid w.r.t to internal bit clock. 
	* 00 : No delay
	* 01 : 1 clk delay
	* 10 : 2 clock delay
	* 11 :3 clock delay
	* Internal bit clock sclaes with different decimation factor.(eg : 480/240/120/60 MHz for RAW mode and 600/300/150/75/37.5 MHz for 8b10b mode)
	* For practical purpose, reset value is OK
	* Read/Write: RW
	* Bits: [25:24]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DataValidDelayCtrl : 2;        /*## attribute DataValidDelayCtrl */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 2;        /*## attribute Reserved5 */
	/**
	* BitsName: frame_clk_gating
	* Description: Frame clock can be gated outside the valid data window.
	* 0: frame_clk is always free running 
	* 1: frame_clk is gated outside data_valid.
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t FrameClkGating : 1;        /*## attribute FrameClkGating */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
}R2M01_LvdsConfigRegBits_t;
/**
* R2M01_LvdsCrcCtrl1Bits_t
* RegisterName: LVDS_CRC_CTRL1
* CRC-32 control register
* Address: 0x014
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
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CrcInitValue : 32;        /*## attribute CrcInitValue */
}R2M01_LvdsCrcCtrl1Bits_t;
/**
* R2M01_LvdsCrcCtrl2Bits_t
* RegisterName: LVDS_CRC_CTRL2
* CRC-32 control register
* Address: 0x018
* ResetValue: 0xFFFFFFFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: crc_xor_out_value
	* Description: Final CRC is EX-OR ed with this value..It is a CRC Engine configuration parameter
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b11111111111111111111111111111111
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CrcXorOutValue : 32;        /*## attribute CrcXorOutValue */
}R2M01_LvdsCrcCtrl2Bits_t;
/**
* R2M01_LvdsCrcCtrl3Bits_t
* RegisterName: LVDS_CRC_CTRL3
* CRC-32 control register
* Address: 0x01C
* ResetValue: 0x0FF00110
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: crc_endianness
	* Description: Enable/Disable CRC data Swapping :
	* The IC uses 32-bit CRC engine. So input data to be con-catinated.  After con-catination 32 bit data is swapped before inputting the date to the CRC engine
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
	* 1: Bit order is swapped around the middle of the input 32 bit data(default)..It is a CRC Engine configuration parameter
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
	* 1 : Bit order is swapped around the middle of the CRC result.(default)..It is a CRC Engine configuration parameter
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
	* BitsName: crc_16x1_frame_patttern
	* Description: 32 bit CRC is being sent as two 16x1 halfwords.This register holds the frame clock pattern(duty cycle) while sending crc in 16x1 format  
	* Read/Write: RW
	* Bits: [27:12]
	* ResetValue: 0b1111111100000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Crc16X1FramePatttern : 16;        /*## attribute Crc16X1FramePatttern */
	/**
	* BitsName: dummy_zero_position
	* Description: CRC is calculated using a 32-bit input CRC engine.Two consecutive adc samples concatinated [data1,4'b0000 : data0,4'b0000] and given to the CRC engine.Zero padding can be done at LSB side or MSB side.
	* 
	* 0: Zero padding at LSB position (default)
	* 1: Zero padding at MSB position
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t DummyZeroPosition : 1;        /*## attribute DummyZeroPosition */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
}R2M01_LvdsCrcCtrl3Bits_t;
/**
* R2M01_PdcConfigRegBits_t
* RegisterName: PDC_CONFIG_REG
* PDC Config register
* Address: 0x020
* ResetValue: 0x01A9A700
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: make_output_unsigned
	* Description: 0: PDC output is Signed 12 bit
	* 1: PDC output is UnSigned 12 bit
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
	* 1: PDC will get reset for every Chirp
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
	* Description: 1 : Filter inside PDC is disabled (Only down sampling)
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
}R2M01_PdcConfigRegBits_t;
/**
* R2M01_LvdsOutputInvertCtrlBits_t
* RegisterName: LVDS_OUTPUT_INVERT_CTRL
* Invert LVDS output  Lines Control. Can be used for  inverting th eO/P polarity of the LVDS lanes
* Address: 0x024
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: invert_lvds_outputs
	* Description: [6] : Invert bit_clk  -> 0 : no invert & 1 : invert 
	* [5]: Invert frame_clk  -> 0 : no invert & 1 : invert 
	* [4]: Invert ser3          -> 0 : no invert & 1 : invert 
	* [3]: Invert ser2           -> 0 : no invert & 1 : invert 
	* [2]: Invert ser1           -> 0 : no invert & 1 : invert 
	* [1]: Invert ser0           -> 0 : no invert & 1 : invert 
	* [0]: Invert data_valid    -> 0 : no invert & 1 : invert 
	* 
	* Note: Take care of frame_clk_phase & bit_clk_phase while inverting lanes.
	* 
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t InvertLvdsOutputs : 7;        /*## attribute InvertLvdsOutputs */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 25;        /*## attribute Reserved0 */
}R2M01_LvdsOutputInvertCtrlBits_t;
/**
* R2M01_LvdsSerGlobalPadCtrlBits_t
* RegisterName: LVDS_SER_GLOBAL_PAD_CTRL
* Global Pad Control Register,by default all the LVDS and mfio pads are in Cell power-down, high impedance state.
* Address: 0x028
* ResetValue: 0x00001000
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
	* BitsName: lvds_ser_global_pad_epwr
	* Description: Global LVDS driver  Power down (Applicable for all pads)
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerGlobalPadEpwr : 1;        /*## attribute LvdsSerGlobalPadEpwr */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_ser_global_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerGlobalPadEpd : 1;        /*## attribute LvdsSerGlobalPadEpd */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: lvds_ser_global_mfio_pad_en
	* Description: Global pad enable/disable for  LVDS data interface
	* 
	* 0: Pad enabled
	* 1: Pad disabled.
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerGlobalMfioPadEn : 1;        /*## attribute LvdsSerGlobalMfioPadEn */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 19;        /*## attribute Reserved4 */
}R2M01_LvdsSerGlobalPadCtrlBits_t;
/**
* R2M01_LvdsSerPadCtrl1Bits_t
* RegisterName: LVDS_SER_PAD_CTRL1
* LVDS Pad control register.By default all the LVDS pads are in Cell power-down, high impedance state.
* Address: 0x02C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: lvds_ser_adc1_data_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc1DataPadLpwr : 1;        /*## attribute LvdsSerAdc1DataPadLpwr */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: lvds_ser_adc1_data_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc1DataPadEpwr : 1;        /*## attribute LvdsSerAdc1DataPadEpwr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_ser_adc1_data_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc1DataPadEpd : 1;        /*## attribute LvdsSerAdc1DataPadEpd */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_ser_adc2_data_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc2DataPadLpwr : 1;        /*## attribute LvdsSerAdc2DataPadLpwr */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: lvds_ser_adc2_data_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc2DataPadEpwr : 1;        /*## attribute LvdsSerAdc2DataPadEpwr */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: lvds_ser_adc2_data_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc2DataPadEpd : 1;        /*## attribute LvdsSerAdc2DataPadEpd */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: lvds_ser_adc3_data_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc3DataPadLpwr : 1;        /*## attribute LvdsSerAdc3DataPadLpwr */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: lvds_ser_adc3_data_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc3DataPadEpwr : 1;        /*## attribute LvdsSerAdc3DataPadEpwr */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 2;        /*## attribute Reserved7 */
	/**
	* BitsName: lvds_ser_adc3_data_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc3DataPadEpd : 1;        /*## attribute LvdsSerAdc3DataPadEpd */
}R2M01_LvdsSerPadCtrl1Bits_t;
/**
* R2M01_LvdsSerPadCtrl2Bits_t
* RegisterName: LVDS_SER_PAD_CTRL2
* LVDS Pad control register.By default all the LVDS pads are in Cell power-down, high impedance state.
* Address: 0x030
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: lvds_ser_adc4_data_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc4DataPadLpwr : 1;        /*## attribute LvdsSerAdc4DataPadLpwr */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: lvds_ser_adc4_data_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc4DataPadEpwr : 1;        /*## attribute LvdsSerAdc4DataPadEpwr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_ser_adc4_data_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc4DataPadEpd : 1;        /*## attribute LvdsSerAdc4DataPadEpd */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_bit_clk_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsBitClkPadLpwr : 1;        /*## attribute LvdsBitClkPadLpwr */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: lvds_bit_clk_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsBitClkPadEpwr : 1;        /*## attribute LvdsBitClkPadEpwr */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: lvds_bit_clk_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsBitClkPadEpd : 1;        /*## attribute LvdsBitClkPadEpd */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: lvds_frame_clk_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsFrameClkPadLpwr : 1;        /*## attribute LvdsFrameClkPadLpwr */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: lvds_frame_clk_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsFrameClkPadEpwr : 1;        /*## attribute LvdsFrameClkPadEpwr */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 2;        /*## attribute Reserved7 */
	/**
	* BitsName: lvds_frame_clk_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsFrameClkPadEpd : 1;        /*## attribute LvdsFrameClkPadEpd */
}R2M01_LvdsSerPadCtrl2Bits_t;
/**
* R2M01_LvdsSerPadCtrl3Bits_t
* RegisterName: LVDS_SER_PAD_CTRL3
* LVDS MFIO PAD control
* Address: 0x034
* ResetValue: 0x00000131
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
	* BitsName: lvds_csi2_datavalid_mfio_epun
	* Description: Enable weak pull-up (Active Low)
	* 1: weak pull-up Disabled
	* 0: weak pull-up Enabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEpun : 1;        /*## attribute LvdsCsi2DatavalidMfioEpun */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_epd
	* Description: Enable weak pull-down(active high)
	* 1: weak pull-down Enabled
	* 0: weak pull-down Disabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEpd : 1;        /*## attribute LvdsCsi2DatavalidMfioEpd */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_ehs0
	* Description: speed selection bit 0
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEhs0 : 1;        /*## attribute LvdsCsi2DatavalidMfioEhs0 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_ehs1
	* Description: MFIO Speed Selection [ehs1 ehs0] :
	* [0         0] : 20 MHz
	* [0         1] : 40 MHz
	* [1         0] : 85 MHz
	* [1         1] : 125 MHz"
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEhs1 : 1;        /*## attribute LvdsCsi2DatavalidMfioEhs1 */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 22;        /*## attribute Reserved2 */
}R2M01_LvdsSerPadCtrl3Bits_t;
/**
* R2M01_SpareReg1Bits_t
* RegisterName: SPARE_REG1
* Spare and ATB trim bits
* Address: 0x038
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
	* Description: spare bits
	* Read/Write: RW
	* Bits: [31:6]
	* ResetValue: 0b00000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SpareBits1 : 26;        /*## attribute SpareBits1 */
}R2M01_SpareReg1Bits_t;
/**
* R2M01_LvdsTxControlBits_t
* RegisterName: LVDS_TX_CONTROL
* Transmission enable for All LVDS Channels
* Address: 0x050
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: serialisertxen
	* Description: Transmission Enable for  LVDS Channels 
	* [0] : ch0 enable: 1- enable & 0 - disable
	* [1] : ch1 enable: 1- enable & 0 - disable
	* [2] : ch2 enable: 1- enable & 0 - disable
	* [3] : ch3 enable: 1- enable & 0 - disable
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t Serialisertxen : 4;        /*## attribute Serialisertxen */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 28;        /*## attribute Reserved0 */
}R2M01_LvdsTxControlBits_t;
/**
* R2M01_AdcTestDataMuxBits_t
* RegisterName: ADC_TEST_DATA_MUX
* This register is used for Testing Purpose. (only for internal validation and debug purpose)
* Address: 0x060
* ResetValue: 0x00000FFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: lvds_testmode_test_data
	* Description: Test data to be transmitted across LVDS lanes when testmode enabled
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b111111111111
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LvdsTestmodeTestData : 12;        /*## attribute LvdsTestmodeTestData */
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
	* BitsName: lvds_testmode_skip_pdc
	* Description: 0: test data inserted at the input of PDC
	* 1: test data inserted at the output of PDC
	* Note: During the test mode lvds_testmode_skip_pdc should be "1" to test the SER link
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LvdsTestmodeSkipPdc : 1;        /*## attribute LvdsTestmodeSkipPdc */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_testmode_data_sel
	* Description:  
	* 00 : lvds_testmode_test_data register field data as test data   
	* 01: Sinewave as test data (78.125 KHz)   
	* 10: Incremental Pattern as test data  ( 0x001 ->FFF)  
	* 11: PRBS7 (  X ^ 7 + X ^6 + 1)
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LvdsTestmodeDataSel : 2;        /*## attribute LvdsTestmodeDataSel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_testmode_en
	* Description: 
	* 0: PDC functional data as input to LVDS Channel
	* 1: Test data is input to LVDS Channel
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LvdsTestmodeEn : 1;        /*## attribute LvdsTestmodeEn */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 7;        /*## attribute Reserved3 */
}R2M01_AdcTestDataMuxBits_t;
/**
* R2M01_PrbsControlBits_t
* RegisterName: PRBS_CONTROL
* PRBS test generator controls
* Address: 0x064
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
	* Source: Reset
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
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t InvertPrbsPattern : 1;        /*## attribute InvertPrbsPattern */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
}R2M01_PrbsControlBits_t;
/**
* R2M01_WindowActiveSelBits_t
* RegisterName: WINDOW_ACTIVE_SEL
* This register is used for Testing Purpose.
* By using this register, the external data_valid can be forced  through register. Can be used for testing the interface along with ADC_TEST_DATA_MUX register
* Address: 0x068
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: window_active_sel_val
	* Description: 0: Window active from register set to '0'
	* 1: Window active from register set to '1'
	* Note: window_active_reg_control field should be set to '1' 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t WindowActiveSelVal : 1;        /*## attribute WindowActiveSelVal */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: window_active_reg_control
	* Description: 0: Window active is from timing engine
	* 1: Window active from register field window_active_sel_val
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t WindowActiveRegControl : 1;        /*## attribute WindowActiveRegControl */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M01_WindowActiveSelBits_t;
/**
* R2M01_MasterIdivCtrlBits_t
* RegisterName: MASTER_IDIV_CTRL
* Serialiser clock divider control.
* As part of  LVDS interface initialisation, the O/P frequency need to be set  and interface enabled . This register can be used for setting the O/P clock to the desired value.  
* 
* the Chip allows dynamic decimation at individual chirp level over LVDS interface.  It means,  the O/P frequency of the interface and the decimation values are controlled from chirp.  However the values from chirp module will take effect only when the chirp engine is triggered for data acquisition. Until such a time, the output frequncy control is driven from this register.  Its a good practice to make sure that the first profile values used from chirp engine and the IDIV setting are matched to avoid  sudden frequency changes at the O/P 
* Address: 0x06C
* ResetValue: 0x000400B0
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: master_idiv_rst
	* Description: Debug Feature :
	* Active high soft reset for master clk divider.This reset is only to the clock divider and has no effect on other blocks such as PDC,CRC etc.
	* 0: No reset
	* 1: Assert reset to the clock divider.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MasterIdivRst : 1;        /*## attribute MasterIdivRst */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: master_idiv_value
	* Description: Input clock to the divider is  480 MHz.
	* Valid combination are given below.
	* 00_0000  Bypass        o/p clock = 480 MHz
	* 00_0001  Divide by 2   o/p clock = 240 MHz
	* 00_0010  Divide by 3   o/p clock = 160 MHz
	* 00_0011  Divide by 4   o/p clock = 120 MHz
	* .
	* 11_1111  Divide by 64
	* By defualt LVDS o/p clock is set to 40 MHz.Software can use this field for getting the desired bit  clock at the o/p before the correct decimation factor comes from chirp.After the first profile load, the design will  always selects idiv from LUT based on decimation
	* 
	* Note : When a soft reset or functional(from cc) reset is applied to the serialiser,the internal mux will again select the idiv value from register till the next profile load comes.
	* 
	* Read/Write: RW
	* Bits: [9:4]
	* ResetValue: 0b001011
	* Source: Application
	* FuSa: No
	*/
	uint32_t MasterIdivValue : 6;        /*## attribute MasterIdivValue */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: master_idiv_sel_reg_lut
	* Description: This bit can be used to tune the LVDS o/p clock to required frequency before the first Profile Load Signal or required Decimation factor comes from Chirp.After the first profile load, the design will overide this selection and always selects idiv from LUT based on decimation.
	* 0 : select idiv value from the LUT based on decimation
	* 1 : select idiv value from the register.
	* Note : When a soft reset or functional(from cc) reset is applied to the serialiser, the internal mux will again select the idiv value from register till the next profile load comes.
	* 
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MasterIdivSelRegLut : 1;        /*## attribute MasterIdivSelRegLut */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: master_idiv_blk_cnt
	* Description: This register is used for configuring the output clock blocking time. Output clock is blocked to avoid the propagation of glitches during clock switching. This register value need not change for the normal use cases.
	* Note: Counter is running at 40 MHz
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b000100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MasterIdivBlkCnt : 6;        /*## attribute MasterIdivBlkCnt */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 10;        /*## attribute Reserved3 */
}R2M01_MasterIdivCtrlBits_t;
/**
* R2M01_PdcShiftRegIdivCtrlBits_t
* RegisterName: PDC_SHIFT_REG_IDIV_CTRL
* ADC Data Sampling Control
* Address: 0x070
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
	* 
	* Use model:  The value to be used has to come form Validation . The end user can use  the proposed value from validation
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
	* Description: ADC data is sampled on serialiser 480MHz clock using a clock aligner logic.Sampling pulse  is generated with an edge detector on  adc_strobe path.
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
	* Description: ADC clock selection logic. The selected ADC clock is used as data_valid to sample the ADC data.
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
	* Description: Window Active is sampled on serialiser 480MHz clock using a clock aligner logic.Sampling pulse  is generated with an edge detector on adc_strobe signal 
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
	* Description: WA Capturing :The pulse can be moved right in steps of 480 MHz clock using this register field.
	* 000: sampling pulse is right shifted by two 480/600 clks from the selected adc_strobe signal
	* 001:sampling pulse is right shifted by three 480/600 clks
	* 010:sampling pulse is right shifted by four 480/600 clks
	* .
	* .
	* 111: sampling pulse is right shifted by nine 480/600 clks
	* 
	* Use model:  The value to be used has to come form Validation. The end user can use the proposed value from validation
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
	* Description: 0: WA is directly captured with the adc data sampling pulse.(ADC clocks and WA are aligned)
	* 1: WA is double synchronized and captured with the adc data sampling pulse
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
}R2M01_PdcShiftRegIdivCtrlBits_t;
/**
* R2M01_LvdsVcmBits_t
* RegisterName: LVDS_VCM
* This register is used to set the common-mode reference voltage for all the LVDS pads
* Address: 0x108
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: lvds_vcm_set
	* Description: This is to program the reference voltage (common mode LVDS voltage)  generator inside serialiser ana, which generates lvds_vra (1.2 v common mode voltage )  for the  LVDS pads.
	* To generate 1.2V  lvds_vcm_set (formerly called lvds_set_trim_r_n)  should be  0x1F
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LvdsVcmSet : 6;        /*## attribute LvdsVcmSet */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M01_LvdsVcmBits_t;
/**
* R2M01_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* Functional Safety Register debug feature
* Address: 0x404
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
}R2M01_MaskCcResetErrorBits_t;
/**
* R2M01_RefCntrInitBits_t
* RegisterName: REF_CNTR_INIT
* Functional safety related sensor logic
* Frequency Counter : Used for measuring Serialiser Clock 480MHz/600MHz )frequency
* Address: 0x500
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
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t RefCountValue : 16;        /*## attribute RefCountValue */
	/**
	* BitsName: ideal_480_count_value
	* Description: This is applicable when the freq counter trigger is based on window_active (for func safety). The correct value to be programmed which is compared against the freq counter read value in the hardware. The value is restricted to 16 bits (as against 18 bit in the freq read counter value) as this triggered one time during active period of the window active and the bit width is sufficient to cover the frequency counting considering the variation of the chirp period
	* Read/Write: RW
	* Bits: [31:16]
	* ResetValue: 0b0000000111100000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Ideal480CountValue : 16;        /*## attribute Ideal480CountValue */
}R2M01_RefCntrInitBits_t;
/**
* R2M01_FreqCounterStartBits_t
* RegisterName: FREQ_COUNTER_START
* Functional safety related sensor logic
* Frequency Counter : Used for measuring the frequency of the input clock (480/600 MHz) to the serialzier .
* The input clock is supplied by the master clock IP
* 480/600  mode selection also done within master clock based on the serailzier mode configuration
* Address: 0x504
* ResetValue: 0x00000100
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: freq_start
	* Description: Trigger  frequency counter
	* 0 = idle, 1 = Trigger frequency counter
	* 
	* Note: this is a autoclear register field
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
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
}R2M01_FreqCounterStartBits_t;
/**
* R2M01_FreqCounterReadValueBits_t
* RegisterName: FREQ_COUNTER_READ_VALUE
* Frequency Counter : Used for measuring Serialiser Clock 480/600 MHz )frequency
* Address: 0x508
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
	* Description: Indicates that a freq count value is valid. Write to freq counter start clear this bit
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
}R2M01_FreqCounterReadValueBits_t;
/**
* R2M01_RefCounterReadValueBits_t
* RegisterName: REF_COUNTER_READ_VALUE
* Frequency Counter : Used for measuring Serialiser Clock 480/600 MHz )frequency
* Address: 0x50C
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
}R2M01_RefCounterReadValueBits_t;
/**
* R2M01_CrcErrorStatus1Bits_t
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
}R2M01_CrcErrorStatus1Bits_t;
/**
* R2M01_CrcErrorStatus2Bits_t
* RegisterName: CRC_ERROR_STATUS2
* Status of the CRC for each register,  total 40 RW registers for LVDS
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
	* Note: The status corresponds to next 14 registers listed i.e registers 45(msb) down to 32(lsb) and rest of the bits are not valid
	* Read/Write: R
	* Bits: [13:0]
	* ResetValue: 0b00000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 14;        /*## attribute CrcErrorStatusReg2 */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 18;        /*## attribute Reserved0 */
}R2M01_CrcErrorStatus2Bits_t;
/**
* R2M01_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00014101
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
	* ResetValue: 0b0001
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
	* ResetValue: 0b0000000000000001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M01_ModuleIdBits_t;

 #else
/**
* R2M01_IdlePatternBits_t
* RegisterName: IDLE_PATTERN
* This register is used in RAW mode.
* Address: 0x000
* ResetValue: 0x000002AB
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
	* BitsName: idlepattern
	* Description: Idle pattern sent in RAW mode outside the valid data window.
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b001010101011
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Idlepattern : 12;        /*## attribute Idlepattern */
}R2M01_IdlePatternBits_t;
/**
* R2M01_ClockChTxData12X1Bits_t
* RegisterName: CLOCK_CH_TX_DATA_12X1
* This register is used in RAW mode for controlling Frame clock pattern (duty cycle) send over LVDS Link.
* Address: 0x004
* ResetValue: 0x00000FC0
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
	* BitsName: lvds_lane_calibration_en
	* Description: Calibration Mode : When set , this bit ensures that all the LVDS lines start from zero irrespective of the frame_clock/bit_clock phase. And, it also enables the toggling of frame_clock to appear on the output line even in frame_clock gated mode.
	* 0: Normal mode of opeartion.
	* 1: All LVDS Lines start from zero + disable the window_active based frame_clock gating
	* 
	* During Calibration Low_power_mode towards serializer from the Central Control should not be set.
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsLaneCalibrationEn : 1;        /*## attribute LvdsLaneCalibrationEn */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
	/**
	* BitsName: clockchtxdata12x1
	* Description: Frame Clock pattern to be send  on LVDS frame clock channel in RAW mode. This register can be used to vary the duty cycle of the frame clock
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b111111000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Clockchtxdata12X1 : 12;        /*## attribute Clockchtxdata12X1 */
}R2M01_ClockChTxData12X1Bits_t;
/**
* R2M01_TransmitPhaseControlBits_t
* RegisterName: TRANSMIT_PHASE_CONTROL
* This register is common for all the modes.Used for controlling phase of bit_clk and frame_clk sent over LVDS link.
* Address: 0x008
* ResetValue: 0x00000011
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
	* BitsName: frame_clk_phase
	* Description: Within a frame boundary
	* 0: Serial bit starts from Rise edge of frame_clk
	* 1: Serial bit starts from Fall edge of frame clk.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t FrameClkPhase : 1;        /*## attribute FrameClkPhase */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: bit_clk_phase
	* Description: Within a frame boundary
	* 0:  first serial bit starts with bit_clk Fall edge
	* 1: first serial bit starts with bit_clk rise edge. 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t BitClkPhase : 1;        /*## attribute BitClkPhase */
}R2M01_TransmitPhaseControlBits_t;
/**
* R2M01_MsbLsbControlBits_t
* RegisterName: MSB_LSB_CONTROL
* This register is common for all the modes.In serial to parallel conversion this register determines whether MSB/LSB of the parallal word sent first.
* Address: 0x00C
* ResetValue: 0x00000001
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
	* BitsName: packet_endianness
	* Description: 0: Sends MS first in Packet Header and Packet Footer(crc)
	* 1: Send LS first in Packet Header and Packet Footer(crc)
	* Note: This is only applicable to Packet Header and Packet Footer not for Data.
	*           packeten field should be set to enable the header. lvds_crc_control field should be set to enable the CRC footer.
	* 
	* Note: CRC is 32 bit and WordCount is 16 bit, so it is split into MS and LS halfs before parallel to serial conversion.
	* Read/Write: RW
	* Bits: [4]
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
	* BitsName: msb_first
	* Description: LSB/MSB of the Parallel word send first:
	* 0:LSB first
	* 1: MSB first
	* Note: This setting applies to all the bits (header + data payload + footer)
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MsbFirst : 1;        /*## attribute MsbFirst */
}R2M01_MsbLsbControlBits_t;
/**
* R2M01_LvdsConfigRegBits_t
* RegisterName: LVDS_CONFIG_REG
* This register is common for all the modes.
* Address: 0x010
* ResetValue: 0x10000000
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
	* BitsName: frame_clk_gating
	* Description: Frame clock can be gated outside the valid data window.
	* 0: frame_clk is always free running 
	* 1: frame_clk is gated outside data_valid.
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t FrameClkGating : 1;        /*## attribute FrameClkGating */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: data_valid_delay_ctrl
	* Description: Data valid signals comes through an MFIO pad.We can delay the data valid w.r.t to internal bit clock. 
	* 00 : No delay
	* 01 : 1 clk delay
	* 10 : 2 clock delay
	* 11 :3 clock delay
	* Internal bit clock sclaes with different decimation factor.(eg : 480/240/120/60 MHz for RAW mode and 600/300/150/75/37.5 MHz for 8b10b mode)
	* For practical purpose, reset value is OK
	* Read/Write: RW
	* Bits: [25:24]
	* ResetValue: 0b00
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DataValidDelayCtrl : 2;        /*## attribute DataValidDelayCtrl */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 7;        /*## attribute Reserved2 */
	/**
	* BitsName: disable_lvds_lanes_during_idle_time
	* Description: 0: All LVDS lanes are enabled all the time.
	* 1: All LVDS lanes (bit_clk, frame_clk, data lanes) are disabled when ADC sampling is not active. Lanes enabled only during window_active.
	* 
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DisableLvdsLanesDuringIdleTime : 1;        /*## attribute DisableLvdsLanesDuringIdleTime */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: packet_header_format
	* Description: Defines the order in which the  words are arranged in packet header.
	* 0:  Chirp Number(MS) -> Word Count(MS) -> Word Count(LS) -> Chirp Number(LS)
	* 1:  Chirp Number(MS) -> Chirp Number(LS) -> Word Count(MS) -> Word Count(LS).
	* Note: Chirp num and Word Count are 16-bit each. There are zero padded to convert to 24bits. The zero padded 24bit value is split into two halfs, MS & LS of 12 bits each. Thess are appended to data as part of packet header.
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PacketHeaderFormat : 1;        /*## attribute PacketHeaderFormat */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: adc_data_streaming_mode_en
	* Description: adc_data_streaming mode enable:Used for ADC validation
	* 0: IDLE pattern is send outside the valid data window
	* 1:ADC data is send outside the valid data window.
	* 
	* Note: mask_input_w_wa should be set to '0' to enable the adc streaming mode.
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcDataStreamingModeEn : 1;        /*## attribute AdcDataStreamingModeEn */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: packeten
	* Description: Packet Header Enable :
	* 0: no Packet Header on transmitted data Packet.
	* 1: Packet Header is appended to the  Data Packet.
	* Note:Packet header contains Chirp No and Sample Count(no of ADC samples sent over the LVDS Link)
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Packeten : 1;        /*## attribute Packeten */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: lvds_crc_control
	* Description: 
	* 1 = ADC data will be CRC protected, the resultant 32-bit CRC is appended to packet Footer ( send as two 16-bit halfwords) 
	* 0 =  No CRC Footer
	* 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LvdsCrcControl : 1;        /*## attribute LvdsCrcControl */
}R2M01_LvdsConfigRegBits_t;
/**
* R2M01_LvdsCrcCtrl1Bits_t
* RegisterName: LVDS_CRC_CTRL1
* CRC-32 control register
* Address: 0x014
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
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CrcInitValue : 32;        /*## attribute CrcInitValue */
}R2M01_LvdsCrcCtrl1Bits_t;
/**
* R2M01_LvdsCrcCtrl2Bits_t
* RegisterName: LVDS_CRC_CTRL2
* CRC-32 control register
* Address: 0x018
* ResetValue: 0xFFFFFFFF
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: crc_xor_out_value
	* Description: Final CRC is EX-OR ed with this value..It is a CRC Engine configuration parameter
	* Read/Write: RW
	* Bits: [31:0]
	* ResetValue: 0b11111111111111111111111111111111
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CrcXorOutValue : 32;        /*## attribute CrcXorOutValue */
}R2M01_LvdsCrcCtrl2Bits_t;
/**
* R2M01_LvdsCrcCtrl3Bits_t
* RegisterName: LVDS_CRC_CTRL3
* CRC-32 control register
* Address: 0x01C
* ResetValue: 0x0FF00110
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
	* BitsName: dummy_zero_position
	* Description: CRC is calculated using a 32-bit input CRC engine.Two consecutive adc samples concatinated [data1,4'b0000 : data0,4'b0000] and given to the CRC engine.Zero padding can be done at LSB side or MSB side.
	* 
	* 0: Zero padding at LSB position (default)
	* 1: Zero padding at MSB position
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t DummyZeroPosition : 1;        /*## attribute DummyZeroPosition */
	/**
	* BitsName: crc_16x1_frame_patttern
	* Description: 32 bit CRC is being sent as two 16x1 halfwords.This register holds the frame clock pattern(duty cycle) while sending crc in 16x1 format  
	* Read/Write: RW
	* Bits: [27:12]
	* ResetValue: 0b1111111100000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Crc16X1FramePatttern : 16;        /*## attribute Crc16X1FramePatttern */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: reflect_output
	* Description: For reflecting the final CRC ouput bits before final XOR .
	* 0 : No swapping 
	* 1 : Bit order is swapped around the middle of the CRC result.(default)..It is a CRC Engine configuration parameter
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
	* 1: Bit order is swapped around the middle of the input 32 bit data(default)..It is a CRC Engine configuration parameter
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
	* The IC uses 32-bit CRC engine. So input data to be con-catinated.  After con-catination 32 bit data is swapped before inputting the date to the CRC engine
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
}R2M01_LvdsCrcCtrl3Bits_t;
/**
* R2M01_PdcConfigRegBits_t
* RegisterName: PDC_CONFIG_REG
* PDC Config register
* Address: 0x020
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
	* Description: 1 : Filter inside PDC is disabled (Only down sampling)
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
	* 1: PDC will get reset for every Chirp
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
	* Description: 0: PDC output is Signed 12 bit
	* 1: PDC output is UnSigned 12 bit
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MakeOutputUnsigned : 1;        /*## attribute MakeOutputUnsigned */
}R2M01_PdcConfigRegBits_t;
/**
* R2M01_LvdsOutputInvertCtrlBits_t
* RegisterName: LVDS_OUTPUT_INVERT_CTRL
* Invert LVDS output  Lines Control. Can be used for  inverting th eO/P polarity of the LVDS lanes
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
	uint32_t Reserved0 : 25;        /*## attribute Reserved0 */
	/**
	* BitsName: invert_lvds_outputs
	* Description: [6] : Invert bit_clk  -> 0 : no invert & 1 : invert 
	* [5]: Invert frame_clk  -> 0 : no invert & 1 : invert 
	* [4]: Invert ser3          -> 0 : no invert & 1 : invert 
	* [3]: Invert ser2           -> 0 : no invert & 1 : invert 
	* [2]: Invert ser1           -> 0 : no invert & 1 : invert 
	* [1]: Invert ser0           -> 0 : no invert & 1 : invert 
	* [0]: Invert data_valid    -> 0 : no invert & 1 : invert 
	* 
	* Note: Take care of frame_clk_phase & bit_clk_phase while inverting lanes.
	* 
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t InvertLvdsOutputs : 7;        /*## attribute InvertLvdsOutputs */
}R2M01_LvdsOutputInvertCtrlBits_t;
/**
* R2M01_LvdsSerGlobalPadCtrlBits_t
* RegisterName: LVDS_SER_GLOBAL_PAD_CTRL
* Global Pad Control Register,by default all the LVDS and mfio pads are in Cell power-down, high impedance state.
* Address: 0x028
* ResetValue: 0x00001000
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
	* BitsName: lvds_ser_global_mfio_pad_en
	* Description: Global pad enable/disable for  LVDS data interface
	* 
	* 0: Pad enabled
	* 1: Pad disabled.
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerGlobalMfioPadEn : 1;        /*## attribute LvdsSerGlobalMfioPadEn */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_ser_global_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerGlobalPadEpd : 1;        /*## attribute LvdsSerGlobalPadEpd */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_ser_global_pad_epwr
	* Description: Global LVDS driver  Power down (Applicable for all pads)
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerGlobalPadEpwr : 1;        /*## attribute LvdsSerGlobalPadEpwr */
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
}R2M01_LvdsSerGlobalPadCtrlBits_t;
/**
* R2M01_LvdsSerPadCtrl1Bits_t
* RegisterName: LVDS_SER_PAD_CTRL1
* LVDS Pad control register.By default all the LVDS pads are in Cell power-down, high impedance state.
* Address: 0x02C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: lvds_ser_adc3_data_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc3DataPadEpd : 1;        /*## attribute LvdsSerAdc3DataPadEpd */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: lvds_ser_adc3_data_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc3DataPadEpwr : 1;        /*## attribute LvdsSerAdc3DataPadEpwr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_ser_adc3_data_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc3DataPadLpwr : 1;        /*## attribute LvdsSerAdc3DataPadLpwr */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_ser_adc2_data_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc2DataPadEpd : 1;        /*## attribute LvdsSerAdc2DataPadEpd */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: lvds_ser_adc2_data_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc2DataPadEpwr : 1;        /*## attribute LvdsSerAdc2DataPadEpwr */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: lvds_ser_adc2_data_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc2DataPadLpwr : 1;        /*## attribute LvdsSerAdc2DataPadLpwr */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: lvds_ser_adc1_data_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc1DataPadEpd : 1;        /*## attribute LvdsSerAdc1DataPadEpd */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: lvds_ser_adc1_data_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc1DataPadEpwr : 1;        /*## attribute LvdsSerAdc1DataPadEpwr */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 3;        /*## attribute Reserved7 */
	/**
	* BitsName: lvds_ser_adc1_data_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc1DataPadLpwr : 1;        /*## attribute LvdsSerAdc1DataPadLpwr */
}R2M01_LvdsSerPadCtrl1Bits_t;
/**
* R2M01_LvdsSerPadCtrl2Bits_t
* RegisterName: LVDS_SER_PAD_CTRL2
* LVDS Pad control register.By default all the LVDS pads are in Cell power-down, high impedance state.
* Address: 0x030
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: lvds_frame_clk_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsFrameClkPadEpd : 1;        /*## attribute LvdsFrameClkPadEpd */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: lvds_frame_clk_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsFrameClkPadEpwr : 1;        /*## attribute LvdsFrameClkPadEpwr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_frame_clk_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsFrameClkPadLpwr : 1;        /*## attribute LvdsFrameClkPadLpwr */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_bit_clk_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsBitClkPadEpd : 1;        /*## attribute LvdsBitClkPadEpd */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: lvds_bit_clk_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsBitClkPadEpwr : 1;        /*## attribute LvdsBitClkPadEpwr */
	/**
	* BitsName: Reserved_4 
	* Description: not used 
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: lvds_bit_clk_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsBitClkPadLpwr : 1;        /*## attribute LvdsBitClkPadLpwr */
	/**
	* BitsName: Reserved_5 
	* Description: not used 
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: lvds_ser_adc4_data_pad_epd
	* Description: Enable Weak Pull Down
	* 1: Enable Weak Pull Down
	* 0: No pull Down
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc4DataPadEpd : 1;        /*## attribute LvdsSerAdc4DataPadEpd */
	/**
	* BitsName: Reserved_6 
	* Description: not used 
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: lvds_ser_adc4_data_pad_epwr
	* Description: Transmitter Power down. 
	* 1: normal operation;
	* 0: powered down.
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc4DataPadEpwr : 1;        /*## attribute LvdsSerAdc4DataPadEpwr */
	/**
	* BitsName: Reserved_7 
	* Description: not used 
	*/
	uint32_t Reserved7 : 3;        /*## attribute Reserved7 */
	/**
	* BitsName: lvds_ser_adc4_data_pad_lpwr
	* Description: Low Power Mode
	* 1:  Low power mode
	* 0: normal operation;
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsSerAdc4DataPadLpwr : 1;        /*## attribute LvdsSerAdc4DataPadLpwr */
}R2M01_LvdsSerPadCtrl2Bits_t;
/**
* R2M01_LvdsSerPadCtrl3Bits_t
* RegisterName: LVDS_SER_PAD_CTRL3
* LVDS MFIO PAD control
* Address: 0x034
* ResetValue: 0x00000131
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
	* BitsName: lvds_csi2_datavalid_mfio_ehs1
	* Description: MFIO Speed Selection [ehs1 ehs0] :
	* [0         0] : 20 MHz
	* [0         1] : 40 MHz
	* [1         0] : 85 MHz
	* [1         1] : 125 MHz"
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEhs1 : 1;        /*## attribute LvdsCsi2DatavalidMfioEhs1 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_ehs0
	* Description: speed selection bit 0
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEhs0 : 1;        /*## attribute LvdsCsi2DatavalidMfioEhs0 */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_epd
	* Description: Enable weak pull-down(active high)
	* 1: weak pull-down Enabled
	* 0: weak pull-down Disabled
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEpd : 1;        /*## attribute LvdsCsi2DatavalidMfioEpd */
	/**
	* BitsName: lvds_csi2_datavalid_mfio_epun
	* Description: Enable weak pull-up (Active Low)
	* 1: weak pull-up Disabled
	* 0: weak pull-up Enabled
	* Read/Write: RW
	* Bits: [5]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LvdsCsi2DatavalidMfioEpun : 1;        /*## attribute LvdsCsi2DatavalidMfioEpun */
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
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
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
}R2M01_LvdsSerPadCtrl3Bits_t;
/**
* R2M01_SpareReg1Bits_t
* RegisterName: SPARE_REG1
* Spare and ATB trim bits
* Address: 0x038
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: spare_bits_1
	* Description: spare bits
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
}R2M01_SpareReg1Bits_t;
/**
* R2M01_LvdsTxControlBits_t
* RegisterName: LVDS_TX_CONTROL
* Transmission enable for All LVDS Channels
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
	uint32_t Reserved0 : 28;        /*## attribute Reserved0 */
	/**
	* BitsName: serialisertxen
	* Description: Transmission Enable for  LVDS Channels 
	* [0] : ch0 enable: 1- enable & 0 - disable
	* [1] : ch1 enable: 1- enable & 0 - disable
	* [2] : ch2 enable: 1- enable & 0 - disable
	* [3] : ch3 enable: 1- enable & 0 - disable
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: Application
	* FuSa: No
	*/
	uint32_t Serialisertxen : 4;        /*## attribute Serialisertxen */
}R2M01_LvdsTxControlBits_t;
/**
* R2M01_AdcTestDataMuxBits_t
* RegisterName: ADC_TEST_DATA_MUX
* This register is used for Testing Purpose. (only for internal validation and debug purpose)
* Address: 0x060
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
	* BitsName: lvds_testmode_en
	* Description: 
	* 0: PDC functional data as input to LVDS Channel
	* 1: Test data is input to LVDS Channel
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LvdsTestmodeEn : 1;        /*## attribute LvdsTestmodeEn */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: lvds_testmode_data_sel
	* Description:  
	* 00 : lvds_testmode_test_data register field data as test data   
	* 01: Sinewave as test data (78.125 KHz)   
	* 10: Incremental Pattern as test data  ( 0x001 ->FFF)  
	* 11: PRBS7 (  X ^ 7 + X ^6 + 1)
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LvdsTestmodeDataSel : 2;        /*## attribute LvdsTestmodeDataSel */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: lvds_testmode_skip_pdc
	* Description: 0: test data inserted at the input of PDC
	* 1: test data inserted at the output of PDC
	* Note: During the test mode lvds_testmode_skip_pdc should be "1" to test the SER link
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LvdsTestmodeSkipPdc : 1;        /*## attribute LvdsTestmodeSkipPdc */
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
	* BitsName: lvds_testmode_test_data
	* Description: Test data to be transmitted across LVDS lanes when testmode enabled
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b111111111111
	* Source: Application
	* FuSa: Y
	*/
	uint32_t LvdsTestmodeTestData : 12;        /*## attribute LvdsTestmodeTestData */
}R2M01_AdcTestDataMuxBits_t;
/**
* R2M01_PrbsControlBits_t
* RegisterName: PRBS_CONTROL
* PRBS test generator controls
* Address: 0x064
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
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t InvertPrbsPattern : 1;        /*## attribute InvertPrbsPattern */
	/**
	* BitsName: prbs_initial_value
	* Description: Initial value for the PRBS Test pattern Generator
	* Read/Write: RW
	* Bits: [11:0]
	* ResetValue: 0b111111111111
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t PrbsInitialValue : 12;        /*## attribute PrbsInitialValue */
}R2M01_PrbsControlBits_t;
/**
* R2M01_WindowActiveSelBits_t
* RegisterName: WINDOW_ACTIVE_SEL
* This register is used for Testing Purpose.
* By using this register, the external data_valid can be forced  through register. Can be used for testing the interface along with ADC_TEST_DATA_MUX register
* Address: 0x068
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
	* BitsName: window_active_reg_control
	* Description: 0: Window active is from timing engine
	* 1: Window active from register field window_active_sel_val
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t WindowActiveRegControl : 1;        /*## attribute WindowActiveRegControl */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: window_active_sel_val
	* Description: 0: Window active from register set to '0'
	* 1: Window active from register set to '1'
	* Note: window_active_reg_control field should be set to '1' 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t WindowActiveSelVal : 1;        /*## attribute WindowActiveSelVal */
}R2M01_WindowActiveSelBits_t;
/**
* R2M01_MasterIdivCtrlBits_t
* RegisterName: MASTER_IDIV_CTRL
* Serialiser clock divider control.
* As part of  LVDS interface initialisation, the O/P frequency need to be set  and interface enabled . This register can be used for setting the O/P clock to the desired value.  
* 
* the Chip allows dynamic decimation at individual chirp level over LVDS interface.  It means,  the O/P frequency of the interface and the decimation values are controlled from chirp.  However the values from chirp module will take effect only when the chirp engine is triggered for data acquisition. Until such a time, the output frequncy control is driven from this register.  Its a good practice to make sure that the first profile values used from chirp engine and the IDIV setting are matched to avoid  sudden frequency changes at the O/P 
* Address: 0x06C
* ResetValue: 0x000400B0
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
	* BitsName: master_idiv_blk_cnt
	* Description: This register is used for configuring the output clock blocking time. Output clock is blocked to avoid the propagation of glitches during clock switching. This register value need not change for the normal use cases.
	* Note: Counter is running at 40 MHz
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b000100
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MasterIdivBlkCnt : 6;        /*## attribute MasterIdivBlkCnt */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: master_idiv_sel_reg_lut
	* Description: This bit can be used to tune the LVDS o/p clock to required frequency before the first Profile Load Signal or required Decimation factor comes from Chirp.After the first profile load, the design will overide this selection and always selects idiv from LUT based on decimation.
	* 0 : select idiv value from the LUT based on decimation
	* 1 : select idiv value from the register.
	* Note : When a soft reset or functional(from cc) reset is applied to the serialiser, the internal mux will again select the idiv value from register till the next profile load comes.
	* 
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MasterIdivSelRegLut : 1;        /*## attribute MasterIdivSelRegLut */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: master_idiv_value
	* Description: Input clock to the divider is  480 MHz.
	* Valid combination are given below.
	* 00_0000  Bypass        o/p clock = 480 MHz
	* 00_0001  Divide by 2   o/p clock = 240 MHz
	* 00_0010  Divide by 3   o/p clock = 160 MHz
	* 00_0011  Divide by 4   o/p clock = 120 MHz
	* .
	* 11_1111  Divide by 64
	* By defualt LVDS o/p clock is set to 40 MHz.Software can use this field for getting the desired bit  clock at the o/p before the correct decimation factor comes from chirp.After the first profile load, the design will  always selects idiv from LUT based on decimation
	* 
	* Note : When a soft reset or functional(from cc) reset is applied to the serialiser,the internal mux will again select the idiv value from register till the next profile load comes.
	* 
	* Read/Write: RW
	* Bits: [9:4]
	* ResetValue: 0b001011
	* Source: Application
	* FuSa: No
	*/
	uint32_t MasterIdivValue : 6;        /*## attribute MasterIdivValue */
	/**
	* BitsName: Reserved_3 
	* Description: not used 
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: master_idiv_rst
	* Description: Debug Feature :
	* Active high soft reset for master clk divider.This reset is only to the clock divider and has no effect on other blocks such as PDC,CRC etc.
	* 0: No reset
	* 1: Assert reset to the clock divider.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MasterIdivRst : 1;        /*## attribute MasterIdivRst */
}R2M01_MasterIdivCtrlBits_t;
/**
* R2M01_PdcShiftRegIdivCtrlBits_t
* RegisterName: PDC_SHIFT_REG_IDIV_CTRL
* ADC Data Sampling Control
* Address: 0x070
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
	* Description: 0: WA is directly captured with the adc data sampling pulse.(ADC clocks and WA are aligned)
	* 1: WA is double synchronized and captured with the adc data sampling pulse
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
	* Description: WA Capturing :The pulse can be moved right in steps of 480 MHz clock using this register field.
	* 000: sampling pulse is right shifted by two 480/600 clks from the selected adc_strobe signal
	* 001:sampling pulse is right shifted by three 480/600 clks
	* 010:sampling pulse is right shifted by four 480/600 clks
	* .
	* .
	* 111: sampling pulse is right shifted by nine 480/600 clks
	* 
	* Use model:  The value to be used has to come form Validation. The end user can use the proposed value from validation
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
	* Description: Window Active is sampled on serialiser 480MHz clock using a clock aligner logic.Sampling pulse  is generated with an edge detector on adc_strobe signal 
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
	* Description: ADC clock selection logic. The selected ADC clock is used as data_valid to sample the ADC data.
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
	* Description: ADC data is sampled on serialiser 480MHz clock using a clock aligner logic.Sampling pulse  is generated with an edge detector on  adc_strobe path.
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
	* 
	* Use model:  The value to be used has to come form Validation . The end user can use  the proposed value from validation
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AdcDataSamplingPoint : 3;        /*## attribute AdcDataSamplingPoint */
}R2M01_PdcShiftRegIdivCtrlBits_t;
/**
* R2M01_LvdsVcmBits_t
* RegisterName: LVDS_VCM
* This register is used to set the common-mode reference voltage for all the LVDS pads
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
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
	/**
	* BitsName: lvds_vcm_set
	* Description: This is to program the reference voltage (common mode LVDS voltage)  generator inside serialiser ana, which generates lvds_vra (1.2 v common mode voltage )  for the  LVDS pads.
	* To generate 1.2V  lvds_vcm_set (formerly called lvds_set_trim_r_n)  should be  0x1F
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t LvdsVcmSet : 6;        /*## attribute LvdsVcmSet */
}R2M01_LvdsVcmBits_t;
/**
* R2M01_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* Functional Safety Register debug feature
* Address: 0x404
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
}R2M01_MaskCcResetErrorBits_t;
/**
* R2M01_RefCntrInitBits_t
* RegisterName: REF_CNTR_INIT
* Functional safety related sensor logic
* Frequency Counter : Used for measuring Serialiser Clock 480MHz/600MHz )frequency
* Address: 0x500
* ResetValue: 0x01E00028
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ideal_480_count_value
	* Description: This is applicable when the freq counter trigger is based on window_active (for func safety). The correct value to be programmed which is compared against the freq counter read value in the hardware. The value is restricted to 16 bits (as against 18 bit in the freq read counter value) as this triggered one time during active period of the window active and the bit width is sufficient to cover the frequency counting considering the variation of the chirp period
	* Read/Write: RW
	* Bits: [31:16]
	* ResetValue: 0b0000000111100000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Ideal480CountValue : 16;        /*## attribute Ideal480CountValue */
	/**
	* BitsName: ref_count_value
	* Description: value for the reference count time (40 MHz= 25 ns base time) default is d'40. This is used as reference count in both spi triggered mode and window_active triggered mode
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000000101000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t RefCountValue : 16;        /*## attribute RefCountValue */
}R2M01_RefCntrInitBits_t;
/**
* R2M01_FreqCounterStartBits_t
* RegisterName: FREQ_COUNTER_START
* Functional safety related sensor logic
* Frequency Counter : Used for measuring the frequency of the input clock (480/600 MHz) to the serialzier .
* The input clock is supplied by the master clock IP
* 480/600  mode selection also done within master clock based on the serailzier mode configuration
* Address: 0x504
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
	* Description: Trigger  frequency counter
	* 0 = idle, 1 = Trigger frequency counter
	* 
	* Note: this is a autoclear register field
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t FreqStart : 1;        /*## attribute FreqStart */
}R2M01_FreqCounterStartBits_t;
/**
* R2M01_FreqCounterReadValueBits_t
* RegisterName: FREQ_COUNTER_READ_VALUE
* Frequency Counter : Used for measuring Serialiser Clock 480/600 MHz )frequency
* Address: 0x508
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
	* Description: Indicates that a freq count value is valid. Write to freq counter start clear this bit
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
}R2M01_FreqCounterReadValueBits_t;
/**
* R2M01_RefCounterReadValueBits_t
* RegisterName: REF_COUNTER_READ_VALUE
* Frequency Counter : Used for measuring Serialiser Clock 480/600 MHz )frequency
* Address: 0x50C
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
}R2M01_RefCounterReadValueBits_t;
/**
* R2M01_CrcErrorStatus1Bits_t
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
}R2M01_CrcErrorStatus1Bits_t;
/**
* R2M01_CrcErrorStatus2Bits_t
* RegisterName: CRC_ERROR_STATUS2
* Status of the CRC for each register,  total 40 RW registers for LVDS
* Address: 0xF44
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 18;        /*## attribute Reserved0 */
	/**
	* BitsName: crc_error_status_reg2
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to next 14 registers listed i.e registers 45(msb) down to 32(lsb) and rest of the bits are not valid
	* Read/Write: R
	* Bits: [13:0]
	* ResetValue: 0b00000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 14;        /*## attribute CrcErrorStatusReg2 */
}R2M01_CrcErrorStatus2Bits_t;
/**
* R2M01_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00014101
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000000001
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
	* ResetValue: 0b0001
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
}R2M01_ModuleIdBits_t;
#endif
/**
* R2M01_IdlePatternUnion_t
* R2M01_IdlePatternUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_IdlePatternBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_IdlePatternUnion_t;

/**
* R2M01_ClockChTxData12X1Union_t
* R2M01_ClockChTxData12X1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_ClockChTxData12X1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_ClockChTxData12X1Union_t;

/**
* R2M01_TransmitPhaseControlUnion_t
* R2M01_TransmitPhaseControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_TransmitPhaseControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_TransmitPhaseControlUnion_t;

/**
* R2M01_MsbLsbControlUnion_t
* R2M01_MsbLsbControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_MsbLsbControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_MsbLsbControlUnion_t;

/**
* R2M01_LvdsConfigRegUnion_t
* R2M01_LvdsConfigRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsConfigRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsConfigRegUnion_t;

/**
* R2M01_LvdsCrcCtrl1Union_t
* R2M01_LvdsCrcCtrl1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsCrcCtrl1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsCrcCtrl1Union_t;

/**
* R2M01_LvdsCrcCtrl2Union_t
* R2M01_LvdsCrcCtrl2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsCrcCtrl2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsCrcCtrl2Union_t;

/**
* R2M01_LvdsCrcCtrl3Union_t
* R2M01_LvdsCrcCtrl3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsCrcCtrl3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsCrcCtrl3Union_t;

/**
* R2M01_PdcConfigRegUnion_t
* R2M01_PdcConfigRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_PdcConfigRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_PdcConfigRegUnion_t;

/**
* R2M01_LvdsOutputInvertCtrlUnion_t
* R2M01_LvdsOutputInvertCtrlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsOutputInvertCtrlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsOutputInvertCtrlUnion_t;

/**
* R2M01_LvdsSerGlobalPadCtrlUnion_t
* R2M01_LvdsSerGlobalPadCtrlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsSerGlobalPadCtrlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsSerGlobalPadCtrlUnion_t;

/**
* R2M01_LvdsSerPadCtrl1Union_t
* R2M01_LvdsSerPadCtrl1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsSerPadCtrl1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsSerPadCtrl1Union_t;

/**
* R2M01_LvdsSerPadCtrl2Union_t
* R2M01_LvdsSerPadCtrl2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsSerPadCtrl2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsSerPadCtrl2Union_t;

/**
* R2M01_LvdsSerPadCtrl3Union_t
* R2M01_LvdsSerPadCtrl3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsSerPadCtrl3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsSerPadCtrl3Union_t;

/**
* R2M01_SpareReg1Union_t
* R2M01_SpareReg1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_SpareReg1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_SpareReg1Union_t;

/**
* R2M01_LvdsTxControlUnion_t
* R2M01_LvdsTxControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsTxControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsTxControlUnion_t;

/**
* R2M01_AdcTestDataMuxUnion_t
* R2M01_AdcTestDataMuxUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_AdcTestDataMuxBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_AdcTestDataMuxUnion_t;

/**
* R2M01_PrbsControlUnion_t
* R2M01_PrbsControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_PrbsControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_PrbsControlUnion_t;

/**
* R2M01_WindowActiveSelUnion_t
* R2M01_WindowActiveSelUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_WindowActiveSelBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_WindowActiveSelUnion_t;

/**
* R2M01_MasterIdivCtrlUnion_t
* R2M01_MasterIdivCtrlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_MasterIdivCtrlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_MasterIdivCtrlUnion_t;

/**
* R2M01_PdcShiftRegIdivCtrlUnion_t
* R2M01_PdcShiftRegIdivCtrlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_PdcShiftRegIdivCtrlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_PdcShiftRegIdivCtrlUnion_t;

/**
* R2M01_LvdsVcmUnion_t
* R2M01_LvdsVcmUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_LvdsVcmBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_LvdsVcmUnion_t;

/**
* R2M01_MaskCcResetErrorUnion_t
* R2M01_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_MaskCcResetErrorUnion_t;

/**
* R2M01_RefCntrInitUnion_t
* R2M01_RefCntrInitUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_RefCntrInitBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_RefCntrInitUnion_t;

/**
* R2M01_FreqCounterStartUnion_t
* R2M01_FreqCounterStartUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_FreqCounterStartBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_FreqCounterStartUnion_t;

/**
* R2M01_FreqCounterReadValueUnion_t
* R2M01_FreqCounterReadValueUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_FreqCounterReadValueBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_FreqCounterReadValueUnion_t;

/**
* R2M01_RefCounterReadValueUnion_t
* R2M01_RefCounterReadValueUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_RefCounterReadValueBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_RefCounterReadValueUnion_t;

/**
* R2M01_CrcErrorStatus1Union_t
* R2M01_CrcErrorStatus1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_CrcErrorStatus1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_CrcErrorStatus1Union_t;

/**
* R2M01_CrcErrorStatus2Union_t
* R2M01_CrcErrorStatus2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_CrcErrorStatus2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_CrcErrorStatus2Union_t;

/**
* R2M01_ModuleIdUnion_t
* R2M01_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M01_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M01_ModuleIdUnion_t;


#endif
