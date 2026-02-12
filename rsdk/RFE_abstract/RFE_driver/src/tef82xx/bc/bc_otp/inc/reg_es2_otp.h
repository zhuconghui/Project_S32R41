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
* @reg_es2_otp.h
*/
#ifndef REG_ES2_OTP_H
#define REG_ES2_OTP_H
#include <stdint.h>
/**
* R2M17_OTP_STATUS_U16
* RegisterName: MOD17_OTP_STATUS
* AccessMode: R
* AddressRange: 0x0040 - 0x0044
* ResetValue: 0x00000007
*/
#define R2M17_OTP_STATUS_U16 (uint16_t)0x0040
/**
* R2M17_OTP_DATA_RD_REG_U16
* RegisterName: MOD17_OTP_DATA_RD_REG
* AccessMode: R
* AddressRange: 0x0200 - 0x0204
* ResetValue: 0x00000000
*/
#define R2M17_OTP_DATA_RD_REG_U16 (uint16_t)0x0200
/**
* R2M17_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD17_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0404 - 0x0408
* ResetValue: 0x00000000
*/
#define R2M17_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0404
/**
* R2M17_CRC_ERROR_STATUS_U16
* RegisterName: MOD17_CRC_ERROR_STATUS
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M17_CRC_ERROR_STATUS_U16 (uint16_t)0x0F40
/**
* R2M17_MODULE_ID_U16
* RegisterName: MOD17_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x00172201
*/
#define R2M17_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M17_OtpStatusBits_t
* RegisterName: OTP_STATUS
* OTP status register 
* Address: 0x040
* ResetValue: 0x00000007
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ready_for_read
	* Description: Read to OTP_DATA_REG should happen only if this bit is HIGH associated with prreaddone
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ReadyForRead : 1;        /*## attribute ReadyForRead */
	/**
	* BitsName: ready_for_write
	* Description: write to OTP_DATA_REG should happen only if this bit is HIGH associated with prreaddone
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ReadyForWrite : 1;        /*## attribute ReadyForWrite */
	/**
	* BitsName: prreaddone
	* Description: High indicates power on reset read is completed. This read is internally initiated by the OTP controller. So this bit will automatically set to '1' few clock cycles after power on reset.  
	* Read/Write: R
	* Bits: [2]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Prreaddone : 1;        /*## attribute Prreaddone */
	/**
	* BitsName: time_out_error
	* Description: High indicates FSOURCE active time exceeded the maximum allowable time
	* Read/Write: R
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TimeOutError : 1;        /*## attribute TimeOutError */
	/**
	* BitsName: otp_cmd_error
	* Description: Goes high when any read/write comes to OTP_DATA_REG register when ready_for_read/ read_for_wrtie  flag respectively is low or prreaddone flag is low. Also goes high if write comes and prconfigdone is high.                                           Gets cleared when STATUS register is read.
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t OtpCmdError : 1;        /*## attribute OtpCmdError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: fsource_active_count
	* Description: FSOURCE active value is tracked through an up counter inside the OTP controller. This up counter active value can be read through FSOURCE_ACTIVE_COUNT these register bits. It is an up counter and software can program the max value using FSOURCE_MAX register.         FSOURCE_ACTIVE time = (FSOURCE_ACTIVE_COUNT) * 25 ns  Note:  FSOURCE_ACTIVE_COUNT is value is invalid, if Time out error = 1' 
	* Read/Write: R
	* Bits: [31:12]
	* ResetValue: 0b00000000000000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t FsourceActiveCount : 20;        /*## attribute FsourceActiveCount */
}R2M17_OtpStatusBits_t;
/**
* R2M17_OtpDataRdRegBits_t
* RegisterName: OTP_DATA_RD_REG
* OTP data read register Range: 200 - 2FF
* Address: 0x200
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: otp_data_rd_reg_loc
	* Description: OTP_DATA_REG provides read access to the controller to OTP memory.  Read access to this register trigger the read operation (pre-fetch) inside OTP controller.  Only burst read is supported in OTP. In every burst 1st data will be invalid data and Software should ignore this. This is due to the internal memory/controller latency requirement.                       NOTE: Read to this register is only possible when ready_for_read is '1' and prreaddone is '1'
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t OtpDataRdRegLoc : 32;        /*## attribute OtpDataRdRegLoc */
}R2M17_OtpDataRdRegBits_t;
/**
* R2M17_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* Registers for validation purposes. Used to mask force_error from Central Controller
* Address: 0x404
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: 0 = Not Masked
	* 1 = Masked 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskRegCrcResetError : 1;        /*## attribute MaskRegCrcResetError */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M17_MaskCcResetErrorBits_t;
/**
* R2M17_CrcErrorStatusBits_t
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
	* Note: The status corresponds to first 23 registers listed i.e registers 22(msb) down to 0(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [22:0]
	* ResetValue: 0b00000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg : 23;        /*## attribute CrcErrorStatusReg */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
}R2M17_CrcErrorStatusBits_t;
/**
* R2M17_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00172201
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
	* ResetValue: 0b0010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MinorRivision : 4;        /*## attribute MinorRivision */
	/**
	* BitsName: major_rivision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRivision : 4;        /*## attribute MajorRivision */
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000010111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M17_ModuleIdBits_t;

 #else
/**
* R2M17_OtpStatusBits_t
* RegisterName: OTP_STATUS
* OTP status register 
* Address: 0x040
* ResetValue: 0x00000007
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: fsource_active_count
	* Description: FSOURCE active value is tracked through an up counter inside the OTP controller. This up counter active value can be read through FSOURCE_ACTIVE_COUNT these register bits. It is an up counter and software can program the max value using FSOURCE_MAX register.         FSOURCE_ACTIVE time = (FSOURCE_ACTIVE_COUNT) * 25 ns  Note:  FSOURCE_ACTIVE_COUNT is value is invalid, if Time out error = 1' 
	* Read/Write: R
	* Bits: [31:12]
	* ResetValue: 0b00000000000000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t FsourceActiveCount : 20;        /*## attribute FsourceActiveCount */
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: otp_cmd_error
	* Description: Goes high when any read/write comes to OTP_DATA_REG register when ready_for_read/ read_for_wrtie  flag respectively is low or prreaddone flag is low. Also goes high if write comes and prconfigdone is high.                                           Gets cleared when STATUS register is read.
	* Read/Write: R
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t OtpCmdError : 1;        /*## attribute OtpCmdError */
	/**
	* BitsName: time_out_error
	* Description: High indicates FSOURCE active time exceeded the maximum allowable time
	* Read/Write: R
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t TimeOutError : 1;        /*## attribute TimeOutError */
	/**
	* BitsName: prreaddone
	* Description: High indicates power on reset read is completed. This read is internally initiated by the OTP controller. So this bit will automatically set to '1' few clock cycles after power on reset.  
	* Read/Write: R
	* Bits: [2]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t Prreaddone : 1;        /*## attribute Prreaddone */
	/**
	* BitsName: ready_for_write
	* Description: write to OTP_DATA_REG should happen only if this bit is HIGH associated with prreaddone
	* Read/Write: R
	* Bits: [1]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ReadyForWrite : 1;        /*## attribute ReadyForWrite */
	/**
	* BitsName: ready_for_read
	* Description: Read to OTP_DATA_REG should happen only if this bit is HIGH associated with prreaddone
	* Read/Write: R
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t ReadyForRead : 1;        /*## attribute ReadyForRead */
}R2M17_OtpStatusBits_t;
/**
* R2M17_OtpDataRdRegBits_t
* RegisterName: OTP_DATA_RD_REG
* OTP data read register Range: 200 - 2FF
* Address: 0x200
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: otp_data_rd_reg_loc
	* Description: OTP_DATA_REG provides read access to the controller to OTP memory.  Read access to this register trigger the read operation (pre-fetch) inside OTP controller.  Only burst read is supported in OTP. In every burst 1st data will be invalid data and Software should ignore this. This is due to the internal memory/controller latency requirement.                       NOTE: Read to this register is only possible when ready_for_read is '1' and prreaddone is '1'
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t OtpDataRdRegLoc : 32;        /*## attribute OtpDataRdRegLoc */
}R2M17_OtpDataRdRegBits_t;
/**
* R2M17_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* Registers for validation purposes. Used to mask force_error from Central Controller
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
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_reg_crc_reset_error
	* Description: 0 = Not Masked
	* 1 = Masked 
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskRegCrcResetError : 1;        /*## attribute MaskRegCrcResetError */
}R2M17_MaskCcResetErrorBits_t;
/**
* R2M17_CrcErrorStatusBits_t
* RegisterName: CRC_ERROR_STATUS
* Status of the CRC for each register
* Address: 0xF40
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0 
	* Description: not used 
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: crc_error_status_reg
	* Description: Each bit represent the error status of the corresponding register
	* 
	* 0 : No error
	* 1 : CRC error
	* 
	* Note: The status corresponds to first 23 registers listed i.e registers 22(msb) down to 0(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [22:0]
	* ResetValue: 0b00000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg : 23;        /*## attribute CrcErrorStatusReg */
}R2M17_CrcErrorStatusBits_t;
/**
* R2M17_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register 
* Address: 0xFFC
* ResetValue: 0x00172201
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000010111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
	/**
	* BitsName: major_rivision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0010
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRivision : 4;        /*## attribute MajorRivision */
	/**
	* BitsName: minor_rivision
	* Description: Minor revision number i.e. with no software consequences
	* Read/Write: R
	* Bits: [11:8]
	* ResetValue: 0b0010
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
}R2M17_ModuleIdBits_t;
#endif
/**
* R2M17_OtpStatusUnion_t
* R2M17_OtpStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M17_OtpStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M17_OtpStatusUnion_t;

/**
* R2M17_OtpDataRdRegUnion_t
* R2M17_OtpDataRdRegUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M17_OtpDataRdRegBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M17_OtpDataRdRegUnion_t;

/**
* R2M17_MaskCcResetErrorUnion_t
* R2M17_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M17_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M17_MaskCcResetErrorUnion_t;

/**
* R2M17_CrcErrorStatusUnion_t
* R2M17_CrcErrorStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M17_CrcErrorStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M17_CrcErrorStatusUnion_t;

/**
* R2M17_ModuleIdUnion_t
* R2M17_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M17_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M17_ModuleIdUnion_t;


#endif
