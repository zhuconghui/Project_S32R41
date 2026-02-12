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
* @reg_es2_gbias.h
*/
#ifndef REG_ES2_GBIAS_H
#define REG_ES2_GBIAS_H
#include <stdint.h>
/**
* R2M09_GLOBBIAS_TX1_U16
* RegisterName: MOD09_GLOBBIAS_TX1
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x00002828
*/
#define R2M09_GLOBBIAS_TX1_U16 (uint16_t)0x0000
/**
* R2M09_GLOBBIAS_TX2_U16
* RegisterName: MOD09_GLOBBIAS_TX2
* AccessMode: RW
* AddressRange: 0x0004 - 0x0008
* ResetValue: 0x00002828
*/
#define R2M09_GLOBBIAS_TX2_U16 (uint16_t)0x0004
/**
* R2M09_GLOBBIAS_TX3_U16
* RegisterName: MOD09_GLOBBIAS_TX3
* AccessMode: RW
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x00002828
*/
#define R2M09_GLOBBIAS_TX3_U16 (uint16_t)0x0008
/**
* R2M09_GLOBBIAS_RX1_U16
* RegisterName: MOD09_GLOBBIAS_RX1
* AccessMode: RW
* AddressRange: 0x000C - 0x0010
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_RX1_U16 (uint16_t)0x000C
/**
* R2M09_GLOBBIAS_RX2_U16
* RegisterName: MOD09_GLOBBIAS_RX2
* AccessMode: RW
* AddressRange: 0x0010 - 0x0014
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_RX2_U16 (uint16_t)0x0010
/**
* R2M09_GLOBBIAS_RX3_U16
* RegisterName: MOD09_GLOBBIAS_RX3
* AccessMode: RW
* AddressRange: 0x0014 - 0x0018
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_RX3_U16 (uint16_t)0x0014
/**
* R2M09_GLOBBIAS_RX4_U16
* RegisterName: MOD09_GLOBBIAS_RX4
* AccessMode: RW
* AddressRange: 0x0018 - 0x001C
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_RX4_U16 (uint16_t)0x0018
/**
* R2M09_GLOBBIAS_MASTERCLK_U16
* RegisterName: MOD09_GLOBBIAS_MASTERCLK
* AccessMode: RW
* AddressRange: 0x001C - 0x0020
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_MASTERCLK_U16 (uint16_t)0x001C
/**
* R2M09_GLOBBIAS_CHIRPGEN_U16
* RegisterName: MOD09_GLOBBIAS_CHIRPGEN
* AccessMode: RW
* AddressRange: 0x0020 - 0x0024
* ResetValue: 0x00282828
*/
#define R2M09_GLOBBIAS_CHIRPGEN_U16 (uint16_t)0x0020
/**
* R2M09_GLOBBIAS_LO_INTERFACE_U16
* RegisterName: MOD09_GLOBBIAS_LO_INTERFACE
* AccessMode: RW
* AddressRange: 0x0024 - 0x0028
* ResetValue: 0x00002828
*/
#define R2M09_GLOBBIAS_LO_INTERFACE_U16 (uint16_t)0x0024
/**
* R2M09_GLOBBIAS_ADC12_U16
* RegisterName: MOD09_GLOBBIAS_ADC12
* AccessMode: RW
* AddressRange: 0x0028 - 0x002C
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_ADC12_U16 (uint16_t)0x0028
/**
* R2M09_GLOBBIAS_ADC34_U16
* RegisterName: MOD09_GLOBBIAS_ADC34
* AccessMode: RW
* AddressRange: 0x002C - 0x0030
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_ADC34_U16 (uint16_t)0x002C
/**
* R2M09_GLOBBIAS_ATBIP_U16
* RegisterName: MOD09_GLOBBIAS_ATBIP
* AccessMode: RW
* AddressRange: 0x0030 - 0x0034
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_ATBIP_U16 (uint16_t)0x0030
/**
* R2M09_GLOBBIAS_SSBMOD_U16
* RegisterName: MOD09_GLOBBIAS_SSBMOD
* AccessMode: RW
* AddressRange: 0x0034 - 0x0038
* ResetValue: 0x00282828
*/
#define R2M09_GLOBBIAS_SSBMOD_U16 (uint16_t)0x0034
/**
* R2M09_GLOBBIAS_BBD_U16
* RegisterName: MOD09_GLOBBIAS_BBD
* AccessMode: RW
* AddressRange: 0x0038 - 0x003C
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_BBD_U16 (uint16_t)0x0038
/**
* R2M09_GLOBBIAS_CLOCKPLL_U16
* RegisterName: MOD09_GLOBBIAS_CLOCKPLL
* AccessMode: RW
* AddressRange: 0x003C - 0x0040
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_CLOCKPLL_U16 (uint16_t)0x003C
/**
* R2M09_GLOBBIAS_RX_BG_U16
* RegisterName: MOD09_GLOBBIAS_RX_BG
* AccessMode: RW
* AddressRange: 0x0040 - 0x0044
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_RX_BG_U16 (uint16_t)0x0040
/**
* R2M09_GLOBBIAS_SNS_U16
* RegisterName: MOD09_GLOBBIAS_SNS
* AccessMode: RW
* AddressRange: 0x0044 - 0x0048
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_SNS_U16 (uint16_t)0x0044
/**
* R2M09_GLOBBIAS_IREF_LOCAL_LDO_U16
* RegisterName: MOD09_GLOBBIAS_IREF_LOCAL_LDO
* AccessMode: RW
* AddressRange: 0x0048 - 0x004C
* ResetValue: 0x0000000D
*/
#define R2M09_GLOBBIAS_IREF_LOCAL_LDO_U16 (uint16_t)0x0048
/**
* R2M09_GLOBBIAS_PTAT_OFFSET_CALIB_U16
* RegisterName: MOD09_GLOBBIAS_PTAT_OFFSET_CALIB
* AccessMode: RW
* AddressRange: 0x005C - 0x0060
* ResetValue: 0x00000000
*/
#define R2M09_GLOBBIAS_PTAT_OFFSET_CALIB_U16 (uint16_t)0x005C
/**
* R2M09_GLOBBIAS_PON_IREF_LOCAL_LDO_U16
* RegisterName: MOD09_GLOBBIAS_PON_IREF_LOCAL_LDO
* AccessMode: RW
* AddressRange: 0x0060 - 0x0064
* ResetValue: 0x00000000
*/
#define R2M09_GLOBBIAS_PON_IREF_LOCAL_LDO_U16 (uint16_t)0x0060
/**
* R2M09_GLOBBIAS_AMPMON_U16
* RegisterName: MOD09_GLOBBIAS_AMPMON
* AccessMode: RW
* AddressRange: 0x006C - 0x0070
* ResetValue: 0x00002828
*/
#define R2M09_GLOBBIAS_AMPMON_U16 (uint16_t)0x006C
/**
* R2M09_GLOBBIAS_IREF_ALL_IP_U16
* RegisterName: MOD09_GLOBBIAS_IREF_ALL_IP
* AccessMode: RW
* AddressRange: 0x0080 - 0x0084
* ResetValue: 0x00282828
*/
#define R2M09_GLOBBIAS_IREF_ALL_IP_U16 (uint16_t)0x0080
/**
* R2M09_GLOBBIAS_SPARE_U16
* RegisterName: MOD09_GLOBBIAS_SPARE
* AccessMode: RW
* AddressRange: 0x0100 - 0x0104
* ResetValue: 0x00000028
*/
#define R2M09_GLOBBIAS_SPARE_U16 (uint16_t)0x0100
/**
* R2M09_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD09_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0E04 - 0x0E08
* ResetValue: 0x00000000
*/
#define R2M09_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0E04
/**
* R2M09_CRC_ERROR_STATUS1_U16
* RegisterName: MOD09_CRC_ERROR_STATUS1
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M09_CRC_ERROR_STATUS1_U16 (uint16_t)0x0F40
/**
* R2M09_CRC_ERROR_STATUS2_U16
* RegisterName: MOD09_CRC_ERROR_STATUS2
* AccessMode: R
* AddressRange: 0x0F44 - 0x0F48
* ResetValue: 0x00000000
*/
#define R2M09_CRC_ERROR_STATUS2_U16 (uint16_t)0x0F44
/**
* R2M09_MODULE_ID_U16
* RegisterName: MOD09_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x00093001
*/
#define R2M09_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M09_GlobbiasTx1Bits_t
* RegisterName: GLOBBIAS_TX1
* TX1 bias current settings.
* 
* Address: 0x000
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_tx1_bg
	* Description: Control BG bias current for TX1. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx1Bg : 6;        /*## attribute CtrlIrefTx1Bg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_tx1_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx1Ptat : 6;        /*## attribute CtrlIrefTx1Ptat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 18;        /*## attribute Reserved1 */
}R2M09_GlobbiasTx1Bits_t;
/**
* R2M09_GlobbiasTx2Bits_t
* RegisterName: GLOBBIAS_TX2
* TX2 bias current settings
* Address: 0x004
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_tx2_bg
	* Description: Control BG bias current for TX2. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx2Bg : 6;        /*## attribute CtrlIrefTx2Bg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_tx2_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx2Ptat : 6;        /*## attribute CtrlIrefTx2Ptat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 18;        /*## attribute Reserved1 */
}R2M09_GlobbiasTx2Bits_t;
/**
* R2M09_GlobbiasTx3Bits_t
* RegisterName: GLOBBIAS_TX3
* TX3 bias current settings
* Address: 0x008
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_tx3_bg
	* Description: Control BG bias current for TX3. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx3Bg : 6;        /*## attribute CtrlIrefTx3Bg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_tx3_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx3Ptat : 6;        /*## attribute CtrlIrefTx3Ptat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 18;        /*## attribute Reserved1 */
}R2M09_GlobbiasTx3Bits_t;
/**
* R2M09_GlobbiasRx1Bits_t
* RegisterName: GLOBBIAS_RX1
* RX1 bias current settings
* Address: 0x00C
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_rx1_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRx1Ptat : 6;        /*## attribute CtrlIrefRx1Ptat */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasRx1Bits_t;
/**
* R2M09_GlobbiasRx2Bits_t
* RegisterName: GLOBBIAS_RX2
* RX2 bias current settings
* Address: 0x010
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_rx2_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRx2Ptat : 6;        /*## attribute CtrlIrefRx2Ptat */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasRx2Bits_t;
/**
* R2M09_GlobbiasRx3Bits_t
* RegisterName: GLOBBIAS_RX3
* RX3 bias current settings
* Address: 0x014
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_rx3_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRx3Ptat : 6;        /*## attribute CtrlIrefRx3Ptat */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasRx3Bits_t;
/**
* R2M09_GlobbiasRx4Bits_t
* RegisterName: GLOBBIAS_RX4
* RX4 bias current settings
* Address: 0x018
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_rx4_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRx4Ptat : 6;        /*## attribute CtrlIrefRx4Ptat */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasRx4Bits_t;
/**
* R2M09_GlobbiasMasterclkBits_t
* RegisterName: GLOBBIAS_MASTERCLK
* Master clock bias current settings
* Address: 0x01C
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_masterclk_bgr
	* Description: Buffers BG:
	* Control BGR bias current for master clock. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefMasterclkBgr : 6;        /*## attribute CtrlIrefMasterclkBgr */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasMasterclkBits_t;
/**
* R2M09_GlobbiasChirpgenBits_t
* RegisterName: GLOBBIAS_CHIRPGEN
* Chirpgen bias current settings
* Address: 0x020
* ResetValue: 0x00282828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_chirpgen_bg
	* Description: Control BG   bias current for chirp generator. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefChirpgenBg : 6;        /*## attribute CtrlIrefChirpgenBg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_chirpgen_bgr
	* Description: Control BGR bias current for chirp generator. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefChirpgenBgr : 6;        /*## attribute CtrlIrefChirpgenBgr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_chirpgen_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefChirpgenPtat : 6;        /*## attribute CtrlIrefChirpgenPtat */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 10;        /*## attribute Reserved2 */
}R2M09_GlobbiasChirpgenBits_t;
/**
* R2M09_GlobbiasLoInterfaceBits_t
* RegisterName: GLOBBIAS_LO_INTERFACE
* Lo interface bias current settings
* Address: 0x024
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_interface_bg
	* Description: Control BG bias current for interface. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefInterfaceBg : 6;        /*## attribute CtrlIrefInterfaceBg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_interface_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefInterfacePtat : 6;        /*## attribute CtrlIrefInterfacePtat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 18;        /*## attribute Reserved1 */
}R2M09_GlobbiasLoInterfaceBits_t;
/**
* R2M09_GlobbiasAdc12Bits_t
* RegisterName: GLOBBIAS_ADC12
* ADC12  bias current settings
* Address: 0x028
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_adc12_bgr
	* Description: Control BGR bias current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAdc12Bgr : 6;        /*## attribute CtrlIrefAdc12Bgr */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasAdc12Bits_t;
/**
* R2M09_GlobbiasAdc34Bits_t
* RegisterName: GLOBBIAS_ADC34
* ADC34  bias current settings
* Address: 0x02C
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_adc34_bgr
	* Description: Control BGR bias current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAdc34Bgr : 6;        /*## attribute CtrlIrefAdc34Bgr */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasAdc34Bits_t;
/**
* R2M09_GlobbiasAtbipBits_t
* RegisterName: GLOBBIAS_ATBIP
* ATB  bias current settings
* Address: 0x030
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_atbip_bgr
	* Description: Control BGR test  current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAtbipBgr : 6;        /*## attribute CtrlIrefAtbipBgr */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasAtbipBits_t;
/**
* R2M09_GlobbiasSsbmodBits_t
* RegisterName: GLOBBIAS_SSBMOD
* RFBIST/SSBMOD  bias current settings
* Address: 0x034
* ResetValue: 0x00282828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_ssbmod_bg
	* Description: Control BG bias current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefSsbmodBg : 6;        /*## attribute CtrlIrefSsbmodBg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_ssbmod_bgr
	* Description: Control BGR test  current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefSsbmodBgr : 6;        /*## attribute CtrlIrefSsbmodBgr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_ssbmod_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefSsbmodPtat : 6;        /*## attribute CtrlIrefSsbmodPtat */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 10;        /*## attribute Reserved2 */
}R2M09_GlobbiasSsbmodBits_t;
/**
* R2M09_GlobbiasBbdBits_t
* RegisterName: GLOBBIAS_BBD
* Ball break detector  bias current settings
* Address: 0x038
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_ballbreakdet_bg
	* Description: Control bias BG current for ball break detector. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefBallbreakdetBg : 6;        /*## attribute CtrlIrefBallbreakdetBg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasBbdBits_t;
/**
* R2M09_GlobbiasClockpllBits_t
* RegisterName: GLOBBIAS_CLOCKPLL
* PLL bias current settings
* Address: 0x03C
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_clockpll_bg
	* Description: Control bias current for pll. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefClockpllBg : 6;        /*## attribute CtrlIrefClockpllBg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasClockpllBits_t;
/**
* R2M09_GlobbiasRxBgBits_t
* RegisterName: GLOBBIAS_RX_BG
* Bg bias current settings for RX
* Address: 0x040
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_rx_bg
	* Description: Control bias BG current for RX. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRxBg : 6;        /*## attribute CtrlIrefRxBg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasRxBgBits_t;
/**
* R2M09_GlobbiasSnsBits_t
* RegisterName: GLOBBIAS_SNS
* LVDS bias current settings
* Address: 0x044
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_sns_bgr
	* Description: Control BGR bias current for Serializer LVDS voltage. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefSnsBgr : 6;        /*## attribute CtrlIrefSnsBgr */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M09_GlobbiasSnsBits_t;
/**
* R2M09_GlobbiasIrefLocalLdoBits_t
* RegisterName: GLOBBIAS_IREF_LOCAL_LDO
* Local ldo bias current settings
* Address: 0x048
* ResetValue: 0x0000000D
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_local_ldo
	* Description: Control bias current for ldo1v1 5 bits control, range 5uA-40uA, step 1,167uA
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01101
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefLocalLdo : 5;        /*## attribute CtrlIrefLocalLdo */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
}R2M09_GlobbiasIrefLocalLdoBits_t;
/**
* R2M09_GlobbiasPtatOffsetCalibBits_t
* RegisterName: GLOBBIAS_PTAT_OFFSET_CALIB
* Control settings for the ptat calibration
* Address: 0x05C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ptat_offset_calib_ctrl
	* Description: PTAT reference current offset correction
	* [6]: sign bit; 0 = current subtracted; 1 = current added
	* [5:0] current setting; 0 = minimum current; 63 = maximum  current
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t PtatOffsetCalibCtrl : 7;        /*## attribute PtatOffsetCalibCtrl */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 25;        /*## attribute Reserved0 */
}R2M09_GlobbiasPtatOffsetCalibBits_t;
/**
* R2M09_GlobbiasPonIrefLocalLdoBits_t
* RegisterName: GLOBBIAS_PON_IREF_LOCAL_LDO
* power on local LDO reference current generation
* Address: 0x060
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pon_iref_local_ldo
	* Description: power on local LDO reference current generation
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonIrefLocalLdo : 1;        /*## attribute PonIrefLocalLdo */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M09_GlobbiasPonIrefLocalLdoBits_t;
/**
* R2M09_GlobbiasAmpmonBits_t
* RegisterName: GLOBBIAS_AMPMON
* Control settings for the Amplitude monitor bgr, ptatr 
* Address: 0x06C
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_ampmon_bgr
	* Description: Control BGR bias current for pll, Serializer. 6 bits control, range 0-157.5uA, step 2.5uA , @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAmpmonBgr : 6;        /*## attribute CtrlIrefAmpmonBgr */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_ampmon_ptatr
	* Description: Control PTATR bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAmpmonPtatr : 6;        /*## attribute CtrlIrefAmpmonPtatr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 18;        /*## attribute Reserved1 */
}R2M09_GlobbiasAmpmonBits_t;
/**
* R2M09_GlobbiasIrefAllIpBits_t
* RegisterName: GLOBBIAS_IREF_ALL_IP
* Global control for bg, bgr and ptat for all Ips
* Address: 0x080
* ResetValue: 0x00282828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctrl_iref_all_ip_bg
	* Description: Control bias BG current for ball break detector. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpBg : 6;        /*## attribute CtrlIrefAllIpBg */
	/**
	* BitsName: ctrl_iref_all_ip_bg_enable
	* Description: Enable common BG (ctrl_iref_all_ip_bg) for all ips 
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpBgEnable : 1;        /*## attribute CtrlIrefAllIpBgEnable */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_all_ip_bgr
	* Description: Control BGR test  current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpBgr : 6;        /*## attribute CtrlIrefAllIpBgr */
	/**
	* BitsName: ctrl_iref_all_ip_bgr_enable
	* Description: Enable common BGR (ctrl_iref_all_ip_bgr) for all ips 
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpBgrEnable : 1;        /*## attribute CtrlIrefAllIpBgrEnable */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_all_ip_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b101000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpPtat : 6;        /*## attribute CtrlIrefAllIpPtat */
	/**
	* BitsName: ctrl_iref_all_ip_ptat_enable
	* Description: Enable common PTAT (ctrl_iref_all_ip_ptat) for all ips
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b0
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpPtatEnable : 1;        /*## attribute CtrlIrefAllIpPtatEnable */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 9;        /*## attribute Reserved2 */
}R2M09_GlobbiasIrefAllIpBits_t;
/**
* R2M09_GlobbiasSpareBits_t
* RegisterName: GLOBBIAS_SPARE
* Spare bits for future use
* Address: 0x100
* ResetValue: 0x00000028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: spare_bits
	* Description: spare bits to control analog
	* spare_bits[5:0]:
	* Control PTATR bias current for RX: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* ES2: Default value changed to 0x28
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000000101000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SpareBits : 16;        /*## attribute SpareBits */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M09_GlobbiasSpareBits_t;
/**
* R2M09_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This register is kept for validation and not to be used in the functional context
* Address: 0xE04
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_supply_low_reset_error
	* Description: If set to '1', the reset_error from central control is masked and will not be forwarded to the sensor
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
	* BitsName: mask_reg_crc_reset_error
	* Description: If set to '1', the reset_error from central control is masked and will not be forwarded to the sensor
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
}R2M09_MaskCcResetErrorBits_t;
/**
* R2M09_CrcErrorStatus1Bits_t
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
}R2M09_CrcErrorStatus1Bits_t;
/**
* R2M09_CrcErrorStatus2Bits_t
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
	* Note: The status corresponds to last 14 registers listed i.e registers 45(msb) down to 32(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 32;        /*## attribute CrcErrorStatusReg2 */
}R2M09_CrcErrorStatus2Bits_t;
/**
* R2M09_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00093001
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
	* ResetValue: 0b0000000000001001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M09_ModuleIdBits_t;

 #else
/**
* R2M09_GlobbiasTx1Bits_t
* RegisterName: GLOBBIAS_TX1
* TX1 bias current settings.
* 
* Address: 0x000
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 18;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_tx1_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx1Ptat : 6;        /*## attribute CtrlIrefTx1Ptat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_tx1_bg
	* Description: Control BG bias current for TX1. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx1Bg : 6;        /*## attribute CtrlIrefTx1Bg */
}R2M09_GlobbiasTx1Bits_t;
/**
* R2M09_GlobbiasTx2Bits_t
* RegisterName: GLOBBIAS_TX2
* TX2 bias current settings
* Address: 0x004
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 18;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_tx2_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx2Ptat : 6;        /*## attribute CtrlIrefTx2Ptat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_tx2_bg
	* Description: Control BG bias current for TX2. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx2Bg : 6;        /*## attribute CtrlIrefTx2Bg */
}R2M09_GlobbiasTx2Bits_t;
/**
* R2M09_GlobbiasTx3Bits_t
* RegisterName: GLOBBIAS_TX3
* TX3 bias current settings
* Address: 0x008
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 18;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_tx3_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx3Ptat : 6;        /*## attribute CtrlIrefTx3Ptat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_tx3_bg
	* Description: Control BG bias current for TX3. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefTx3Bg : 6;        /*## attribute CtrlIrefTx3Bg */
}R2M09_GlobbiasTx3Bits_t;
/**
* R2M09_GlobbiasRx1Bits_t
* RegisterName: GLOBBIAS_RX1
* RX1 bias current settings
* Address: 0x00C
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_rx1_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRx1Ptat : 6;        /*## attribute CtrlIrefRx1Ptat */
}R2M09_GlobbiasRx1Bits_t;
/**
* R2M09_GlobbiasRx2Bits_t
* RegisterName: GLOBBIAS_RX2
* RX2 bias current settings
* Address: 0x010
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_rx2_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRx2Ptat : 6;        /*## attribute CtrlIrefRx2Ptat */
}R2M09_GlobbiasRx2Bits_t;
/**
* R2M09_GlobbiasRx3Bits_t
* RegisterName: GLOBBIAS_RX3
* RX3 bias current settings
* Address: 0x014
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_rx3_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRx3Ptat : 6;        /*## attribute CtrlIrefRx3Ptat */
}R2M09_GlobbiasRx3Bits_t;
/**
* R2M09_GlobbiasRx4Bits_t
* RegisterName: GLOBBIAS_RX4
* RX4 bias current settings
* Address: 0x018
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_rx4_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRx4Ptat : 6;        /*## attribute CtrlIrefRx4Ptat */
}R2M09_GlobbiasRx4Bits_t;
/**
* R2M09_GlobbiasMasterclkBits_t
* RegisterName: GLOBBIAS_MASTERCLK
* Master clock bias current settings
* Address: 0x01C
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_masterclk_bgr
	* Description: Buffers BG:
	* Control BGR bias current for master clock. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefMasterclkBgr : 6;        /*## attribute CtrlIrefMasterclkBgr */
}R2M09_GlobbiasMasterclkBits_t;
/**
* R2M09_GlobbiasChirpgenBits_t
* RegisterName: GLOBBIAS_CHIRPGEN
* Chirpgen bias current settings
* Address: 0x020
* ResetValue: 0x00282828
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
	* BitsName: ctrl_iref_chirpgen_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefChirpgenPtat : 6;        /*## attribute CtrlIrefChirpgenPtat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_chirpgen_bgr
	* Description: Control BGR bias current for chirp generator. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefChirpgenBgr : 6;        /*## attribute CtrlIrefChirpgenBgr */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctrl_iref_chirpgen_bg
	* Description: Control BG   bias current for chirp generator. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefChirpgenBg : 6;        /*## attribute CtrlIrefChirpgenBg */
}R2M09_GlobbiasChirpgenBits_t;
/**
* R2M09_GlobbiasLoInterfaceBits_t
* RegisterName: GLOBBIAS_LO_INTERFACE
* Lo interface bias current settings
* Address: 0x024
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 18;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_interface_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefInterfacePtat : 6;        /*## attribute CtrlIrefInterfacePtat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_interface_bg
	* Description: Control BG bias current for interface. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefInterfaceBg : 6;        /*## attribute CtrlIrefInterfaceBg */
}R2M09_GlobbiasLoInterfaceBits_t;
/**
* R2M09_GlobbiasAdc12Bits_t
* RegisterName: GLOBBIAS_ADC12
* ADC12  bias current settings
* Address: 0x028
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_adc12_bgr
	* Description: Control BGR bias current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAdc12Bgr : 6;        /*## attribute CtrlIrefAdc12Bgr */
}R2M09_GlobbiasAdc12Bits_t;
/**
* R2M09_GlobbiasAdc34Bits_t
* RegisterName: GLOBBIAS_ADC34
* ADC34  bias current settings
* Address: 0x02C
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_adc34_bgr
	* Description: Control BGR bias current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAdc34Bgr : 6;        /*## attribute CtrlIrefAdc34Bgr */
}R2M09_GlobbiasAdc34Bits_t;
/**
* R2M09_GlobbiasAtbipBits_t
* RegisterName: GLOBBIAS_ATBIP
* ATB  bias current settings
* Address: 0x030
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_atbip_bgr
	* Description: Control BGR test  current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAtbipBgr : 6;        /*## attribute CtrlIrefAtbipBgr */
}R2M09_GlobbiasAtbipBits_t;
/**
* R2M09_GlobbiasSsbmodBits_t
* RegisterName: GLOBBIAS_SSBMOD
* RFBIST/SSBMOD  bias current settings
* Address: 0x034
* ResetValue: 0x00282828
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
	* BitsName: ctrl_iref_ssbmod_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefSsbmodPtat : 6;        /*## attribute CtrlIrefSsbmodPtat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_ssbmod_bgr
	* Description: Control BGR test  current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefSsbmodBgr : 6;        /*## attribute CtrlIrefSsbmodBgr */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctrl_iref_ssbmod_bg
	* Description: Control BG bias current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefSsbmodBg : 6;        /*## attribute CtrlIrefSsbmodBg */
}R2M09_GlobbiasSsbmodBits_t;
/**
* R2M09_GlobbiasBbdBits_t
* RegisterName: GLOBBIAS_BBD
* Ball break detector  bias current settings
* Address: 0x038
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_ballbreakdet_bg
	* Description: Control bias BG current for ball break detector. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefBallbreakdetBg : 6;        /*## attribute CtrlIrefBallbreakdetBg */
}R2M09_GlobbiasBbdBits_t;
/**
* R2M09_GlobbiasClockpllBits_t
* RegisterName: GLOBBIAS_CLOCKPLL
* PLL bias current settings
* Address: 0x03C
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_clockpll_bg
	* Description: Control bias current for pll. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefClockpllBg : 6;        /*## attribute CtrlIrefClockpllBg */
}R2M09_GlobbiasClockpllBits_t;
/**
* R2M09_GlobbiasRxBgBits_t
* RegisterName: GLOBBIAS_RX_BG
* Bg bias current settings for RX
* Address: 0x040
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_rx_bg
	* Description: Control bias BG current for RX. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefRxBg : 6;        /*## attribute CtrlIrefRxBg */
}R2M09_GlobbiasRxBgBits_t;
/**
* R2M09_GlobbiasSnsBits_t
* RegisterName: GLOBBIAS_SNS
* LVDS bias current settings
* Address: 0x044
* ResetValue: 0x00000028
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
	* BitsName: ctrl_iref_sns_bgr
	* Description: Control BGR bias current for Serializer LVDS voltage. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefSnsBgr : 6;        /*## attribute CtrlIrefSnsBgr */
}R2M09_GlobbiasSnsBits_t;
/**
* R2M09_GlobbiasIrefLocalLdoBits_t
* RegisterName: GLOBBIAS_IREF_LOCAL_LDO
* Local ldo bias current settings
* Address: 0x048
* ResetValue: 0x0000000D
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
	* BitsName: ctrl_iref_local_ldo
	* Description: Control bias current for ldo1v1 5 bits control, range 5uA-40uA, step 1,167uA
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01101
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefLocalLdo : 5;        /*## attribute CtrlIrefLocalLdo */
}R2M09_GlobbiasIrefLocalLdoBits_t;
/**
* R2M09_GlobbiasPtatOffsetCalibBits_t
* RegisterName: GLOBBIAS_PTAT_OFFSET_CALIB
* Control settings for the ptat calibration
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
	uint32_t Reserved0 : 25;        /*## attribute Reserved0 */
	/**
	* BitsName: ptat_offset_calib_ctrl
	* Description: PTAT reference current offset correction
	* [6]: sign bit; 0 = current subtracted; 1 = current added
	* [5:0] current setting; 0 = minimum current; 63 = maximum  current
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t PtatOffsetCalibCtrl : 7;        /*## attribute PtatOffsetCalibCtrl */
}R2M09_GlobbiasPtatOffsetCalibBits_t;
/**
* R2M09_GlobbiasPonIrefLocalLdoBits_t
* RegisterName: GLOBBIAS_PON_IREF_LOCAL_LDO
* power on local LDO reference current generation
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
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: pon_iref_local_ldo
	* Description: power on local LDO reference current generation
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PonIrefLocalLdo : 1;        /*## attribute PonIrefLocalLdo */
}R2M09_GlobbiasPonIrefLocalLdoBits_t;
/**
* R2M09_GlobbiasAmpmonBits_t
* RegisterName: GLOBBIAS_AMPMON
* Control settings for the Amplitude monitor bgr, ptatr 
* Address: 0x06C
* ResetValue: 0x00002828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 18;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_ampmon_ptatr
	* Description: Control PTATR bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAmpmonPtatr : 6;        /*## attribute CtrlIrefAmpmonPtatr */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_ampmon_bgr
	* Description: Control BGR bias current for pll, Serializer. 6 bits control, range 0-157.5uA, step 2.5uA , @25C
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t CtrlIrefAmpmonBgr : 6;        /*## attribute CtrlIrefAmpmonBgr */
}R2M09_GlobbiasAmpmonBits_t;
/**
* R2M09_GlobbiasIrefAllIpBits_t
* RegisterName: GLOBBIAS_IREF_ALL_IP
* Global control for bg, bgr and ptat for all Ips
* Address: 0x080
* ResetValue: 0x00282828
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctrl_iref_all_ip_ptat_enable
	* Description: Enable common PTAT (ctrl_iref_all_ip_ptat) for all ips
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b0
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpPtatEnable : 1;        /*## attribute CtrlIrefAllIpPtatEnable */
	/**
	* BitsName: ctrl_iref_all_ip_ptat
	* Description: Control PTAT bias current: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b101000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpPtat : 6;        /*## attribute CtrlIrefAllIpPtat */
	/**
	* BitsName: Reserved_1 
	* Description: not used 
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: ctrl_iref_all_ip_bgr_enable
	* Description: Enable common BGR (ctrl_iref_all_ip_bgr) for all ips 
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpBgrEnable : 1;        /*## attribute CtrlIrefAllIpBgrEnable */
	/**
	* BitsName: ctrl_iref_all_ip_bgr
	* Description: Control BGR test  current: 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b101000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpBgr : 6;        /*## attribute CtrlIrefAllIpBgr */
	/**
	* BitsName: Reserved_2 
	* Description: not used 
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: ctrl_iref_all_ip_bg_enable
	* Description: Enable common BG (ctrl_iref_all_ip_bg) for all ips 
	* Read/Write: RW
	* Bits: [6]
	* ResetValue: 0b0
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpBgEnable : 1;        /*## attribute CtrlIrefAllIpBgEnable */
	/**
	* BitsName: ctrl_iref_all_ip_bg
	* Description: Control bias BG current for ball break detector. 6 bits control, range 0-157.5uA, step 2.5uA
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101000
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtrlIrefAllIpBg : 6;        /*## attribute CtrlIrefAllIpBg */
}R2M09_GlobbiasIrefAllIpBits_t;
/**
* R2M09_GlobbiasSpareBits_t
* RegisterName: GLOBBIAS_SPARE
* Spare bits for future use
* Address: 0x100
* ResetValue: 0x00000028
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
	* BitsName: spare_bits
	* Description: spare bits to control analog
	* spare_bits[5:0]:
	* Control PTATR bias current for RX: 6 bits control, range 0-157.5uA, step 2.5uA, @25C
	* ES2: Default value changed to 0x28
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000000101000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t SpareBits : 16;        /*## attribute SpareBits */
}R2M09_GlobbiasSpareBits_t;
/**
* R2M09_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This register is kept for validation and not to be used in the functional context
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
	* Description: If set to '1', the reset_error from central control is masked and will not be forwarded to the sensor
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
	* BitsName: mask_supply_low_reset_error
	* Description: If set to '1', the reset_error from central control is masked and will not be forwarded to the sensor
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyLowResetError : 1;        /*## attribute MaskSupplyLowResetError */
}R2M09_MaskCcResetErrorBits_t;
/**
* R2M09_CrcErrorStatus1Bits_t
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
}R2M09_CrcErrorStatus1Bits_t;
/**
* R2M09_CrcErrorStatus2Bits_t
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
	* Note: The status corresponds to last 14 registers listed i.e registers 45(msb) down to 32(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 32;        /*## attribute CrcErrorStatusReg2 */
}R2M09_CrcErrorStatus2Bits_t;
/**
* R2M09_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00093001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000001001
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
}R2M09_ModuleIdBits_t;
#endif
/**
* R2M09_GlobbiasTx1Union_t
* R2M09_GlobbiasTx1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasTx1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasTx1Union_t;

/**
* R2M09_GlobbiasTx2Union_t
* R2M09_GlobbiasTx2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasTx2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasTx2Union_t;

/**
* R2M09_GlobbiasTx3Union_t
* R2M09_GlobbiasTx3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasTx3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasTx3Union_t;

/**
* R2M09_GlobbiasRx1Union_t
* R2M09_GlobbiasRx1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasRx1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasRx1Union_t;

/**
* R2M09_GlobbiasRx2Union_t
* R2M09_GlobbiasRx2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasRx2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasRx2Union_t;

/**
* R2M09_GlobbiasRx3Union_t
* R2M09_GlobbiasRx3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasRx3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasRx3Union_t;

/**
* R2M09_GlobbiasRx4Union_t
* R2M09_GlobbiasRx4Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasRx4Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasRx4Union_t;

/**
* R2M09_GlobbiasMasterclkUnion_t
* R2M09_GlobbiasMasterclkUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasMasterclkBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasMasterclkUnion_t;

/**
* R2M09_GlobbiasChirpgenUnion_t
* R2M09_GlobbiasChirpgenUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasChirpgenBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasChirpgenUnion_t;

/**
* R2M09_GlobbiasLoInterfaceUnion_t
* R2M09_GlobbiasLoInterfaceUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasLoInterfaceBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasLoInterfaceUnion_t;

/**
* R2M09_GlobbiasAdc12Union_t
* R2M09_GlobbiasAdc12Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasAdc12Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasAdc12Union_t;

/**
* R2M09_GlobbiasAdc34Union_t
* R2M09_GlobbiasAdc34Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasAdc34Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasAdc34Union_t;

/**
* R2M09_GlobbiasAtbipUnion_t
* R2M09_GlobbiasAtbipUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasAtbipBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasAtbipUnion_t;

/**
* R2M09_GlobbiasSsbmodUnion_t
* R2M09_GlobbiasSsbmodUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasSsbmodBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasSsbmodUnion_t;

/**
* R2M09_GlobbiasBbdUnion_t
* R2M09_GlobbiasBbdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasBbdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasBbdUnion_t;

/**
* R2M09_GlobbiasClockpllUnion_t
* R2M09_GlobbiasClockpllUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasClockpllBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasClockpllUnion_t;

/**
* R2M09_GlobbiasRxBgUnion_t
* R2M09_GlobbiasRxBgUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasRxBgBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasRxBgUnion_t;

/**
* R2M09_GlobbiasSnsUnion_t
* R2M09_GlobbiasSnsUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasSnsBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasSnsUnion_t;

/**
* R2M09_GlobbiasIrefLocalLdoUnion_t
* R2M09_GlobbiasIrefLocalLdoUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasIrefLocalLdoBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasIrefLocalLdoUnion_t;

/**
* R2M09_GlobbiasPtatOffsetCalibUnion_t
* R2M09_GlobbiasPtatOffsetCalibUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasPtatOffsetCalibBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasPtatOffsetCalibUnion_t;

/**
* R2M09_GlobbiasPonIrefLocalLdoUnion_t
* R2M09_GlobbiasPonIrefLocalLdoUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasPonIrefLocalLdoBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasPonIrefLocalLdoUnion_t;

/**
* R2M09_GlobbiasAmpmonUnion_t
* R2M09_GlobbiasAmpmonUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasAmpmonBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasAmpmonUnion_t;

/**
* R2M09_GlobbiasIrefAllIpUnion_t
* R2M09_GlobbiasIrefAllIpUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasIrefAllIpBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasIrefAllIpUnion_t;

/**
* R2M09_GlobbiasSpareUnion_t
* R2M09_GlobbiasSpareUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_GlobbiasSpareBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_GlobbiasSpareUnion_t;

/**
* R2M09_MaskCcResetErrorUnion_t
* R2M09_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_MaskCcResetErrorUnion_t;

/**
* R2M09_CrcErrorStatus1Union_t
* R2M09_CrcErrorStatus1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_CrcErrorStatus1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_CrcErrorStatus1Union_t;

/**
* R2M09_CrcErrorStatus2Union_t
* R2M09_CrcErrorStatus2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_CrcErrorStatus2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_CrcErrorStatus2Union_t;

/**
* R2M09_ModuleIdUnion_t
* R2M09_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M09_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M09_ModuleIdUnion_t;


#endif
