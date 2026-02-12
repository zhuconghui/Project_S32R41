/*
 * Copyright 2016,2019-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
@file bc_otp.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>5
*/

#ifndef BC_OTP_H
#define BC_OTP_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API loads OTP data to the host memory

RSNum:1447757, 1456417, 1447535, 510633

# Description

An API will burst read the OTP data and load it in memory of Host (PC or MCU) .
An API will check the CRC of the reading OTP data and return error.

@return BC_ERRCODE
*/

BC_ERRCODE BC_OTP_LoadOTP(void);


/**
@brief This API gets chip information

RSNum:2547534

# Description

An API will get the chip information, including mask version, wafer test and final test related information, and wafer test date.

@see OTP_ChipInfo_t

@param[out] pChipInfo Chip information loaded from OTP

@return BC_ERRCODE
*/

BC_ERRCODE BC_OTP_GetChipInfo(OTP_ChipInfo_t *pChipInfo);


/**
@brief This API parses and stores OTP values to corresponding registers

RSNum:1447757, 1456423, 1445687, 1447609, 510633

# Description

An API will parse and store OTP calibration data to the corresponding registers. The calibration data needs to be written to the correct module registers before any application or functional configuration programming is allowed.

@see OTP_Table_e

@param[in] OTPTable to select from which OTP table you want to distribute/
@param[in] StartIndex to select from which entry in this OTP table that you want to distribute the values.  the first entry is with index 0.
@param[in] EndIndex to select the last entry in this OTP table that you want to distribute the values.  All the entries in between StartIndex and EndIndex will be distributed to the corresponding registers.

@return BC_ERRCODE
*/

BC_ERRCODE BC_OTP_DistributeOTPData(OTP_Table_e OTPTable, uint8_t StartIndex, uint8_t EndIndex);


/**
@brief This  API checks if the IP access for SPI operation is enabled by OTP

RSNum:1456417

# Description
An API will check if the IP accessed by SPI operation is OTP enabled or not. If it is OTP disabled,  a error should be reported. If e_OTP_LOADED is selected as input, this API checks if OTP is successfully loaded.

@see OTP_ValidIP_e

@param[in] SelectedIP to select a IP to check. (RX, TX, phase rotator, LO_In, LO_Out, LVDS, CSI2, chirp_5g_mode)

@return BC_ERRCODE
*/

BC_ERRCODE BC_OTP_CheckValidIP(OTP_ValidIP_e SelectedIP);


/**
@brief This API reads the register value from loaded OTP table .

RSNum:1445687

# Description
An API will read the value of a selected entry from OTP table.
This API reads OTP register value from the previously loaded device.

## Note
1. BC_OTP_LoadOTP should be called before calling this API. BC_OTP_LoadOTP is part of BC_SYS_Init/BC_SYS_InitMasterSlaveMode.
2. Master Salve use case this API reads the data from the device for which OTP is loaded recently.
3. Master Slave use case if Application wants to read the OTP form specific device, Application needs to switch to device and load the OTP using the BC_OTP_LoadOTP and read the specific register.

@see BC_OTP_LoadOTP
@see BC_SYS_Init
@see BC_SYS_InitMasterSlaveMode

@param[in] Offset the offset of the selected OTP entry from which you want to get value. For the first entry, the offset is 0. range:[0,63]
@param[out] pRegData the readout OTP value

@return BC_ERRCODE
*/

BC_ERRCODE BC_OTP_GetOTPRegValue(uint16_t Offset, uint32_t *pRegData);



#if defined(__cplusplus)
}
#endif
#endif
