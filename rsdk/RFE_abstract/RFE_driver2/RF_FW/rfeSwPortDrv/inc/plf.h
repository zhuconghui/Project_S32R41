/**************************************************************************************************
* Copyright 2022 - 2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFESWPORTDRV_INC_PLF_H_
#define RFESWPORTDRV_INC_PLF_H_

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include <stdint.h>

#include "plf_err.h"
#include "plf_types.h"
#include "bc_types.h"
/******************************************************************************
 *                              DEFINES
 *****************************************************************************/

/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

/**
@brief This API sets a TEF82XX device as target of operation
RSNum:1201001

# Description

An API will set a TEF82XX device as target of operation. Operation includes SPI access APIs, IO/interrupt APIs etc.

E.g. in a cascading system, if a user sets e_PLF_MASTER as target, then all API calls are effective only to the master TEF82XX. Same principle applies to slave TEF82XX chips.

@param[in] TargetDevice The TEF82XX device

@return PLF_ERRCODE
*/

PLF_ERRCODE PLF_SYS_SetTarget(PLF_SPITarget_e TargetDevice);


/**
@brief This API writes to one or more SPI registers and reads back at the same time using burst access method

RSNum:1007963

# Description

An API will write one or more 32-bits to a series of SPI registers starting from RegAddr at the same time read via SPI MISO line.

## RepMode (repetition mode or S/R bit in SPI command)

TEF82XX allows burst access to its internal registers by extending the SPI cycles by a multiple of 32 cycles for each additional access. Burst write is restricted within the same module. You may use RepMode to control to write to the same register multiple times or write sequentially to many registers in a row within one module. TRUE: write to the same register(RegAddr), NumWords times. FALSE: write to a series of consecutive registers starting at RegAddr, until RegAddr + 4*(NumWords - 1). This only works within the same ModAddr.

## ReadMode (C/S bit in SPI command)

TEF82XX provides an option to read back the data over MISO when the current access is write. Two options available based on the param ReadMode:
TRUE(1): Stored register access: the content of the last written register over SPI interface is send over the MISO interface
FALSE(0): Current register access: the existing content of the current register accessed is send over the MISO interface

## Loopback

When loopback is enabled, MISO line will return what is sent over MOSI, in total 64 bits for a complete SPI frame (32bit control info, 32bit data). First 32bits are returned via pRetData, second 32bits are returned via pRdData.

@param[in] ModAddr Module address
@param[in] RegAddr Register address
@param[in] RepMode Repetition mode, TRUE: write to the same register(RegAddr), NumWords times. FALSE: write to a series of consecutive registers starting at RegAddr, until RegAddr + 4*(NumWords - 1). This only works within the same ModAddr.
@param[in] ReadMode TRUE(1): Stored register access: the content of the last written register over SPI interface is send over the MISO interface; FALSE(0): Current register access: the existing content of the current register accessed is send over the MISO interface
@param[in] Loopback When loopback is enabled, MISO line will return what is sent over MOSI, in total 64 bits for a complete SPI frame (32bit control info, 32bit data). First 32bits are returned via RetData, second 32bits are returned via pRdData.
@param[in] NumWords Number of repetitions of the write operation
@param[in] pWrData Data to be written, must have the length of NumWords
@param[out] pRdData Read data, must have the length of NumWords, when Loopback is TRUE, pRdData returns the 2nd 32bits data looped back from MOSI.
@param[out] pRetData Returned data, the first 32bits of MISO data. Used mainly when Loopback is enabled.

@return PLF_ERRCODE
*/

PLF_ERRCODE PLF_SPI_BurstWriteRead(SYS_IPNum_e ModAddr, uint16_t RegAddr, BOOL RepMode, BOOL ReadMode, BOOL Loopback, uint8_t NumWords, uint32_t *pWrData, uint32_t *pRdData, uint32_t *pRetData);


/**
@brief This API reads one or more SPI registers using burst access method

RSNum:1007964

# Description

An API will read one or more 32-bits data from a series of SPI registers starting from RegAddr. This API will allow user to choose if it reads from a series of consecutive register addresses or reads repeatedly from the same register address.

@param[in] ModAddr Module address
@param[in] RegAddr Register address
@param[in] RepMode Repetition mode, TRUE: read from the same register(RegAddr), NumWords times. FALSE: read from a series of consecutive registers starting at RegAddr, until RegAddr + 4*(NumWords - 1). This only works within the same ModAddr.
@param[in] NumWords Number of repetitions of the read operation
@param[out] pRdData Read data, must have the length of NumWords

@return PLF_ERRCODE
*/

PLF_ERRCODE PLF_SPI_BurstRead(SYS_IPNum_e ModAddr, uint16_t RegAddr, BOOL RepMode, uint8_t NumWords, uint32_t *pRdData);



/**
@brief This API does busy-sleep in the unit of microseconds

RSNum:901396

# Description

An API will be able to add a busy-sleep in microseconds

@param[in] USec The sleep duration in us, resolution is also 1us.

@return PLF_ERRCODE
*/

PLF_ERRCODE PLF_TM_Sleep(uint32_t USec);


/**
@brief This API sets the selected host digital output pin status

RSNum:908013

# Description

An API will set host digital output pin status.

In PLF.h, PIN MARCOs will be defined. And these MARCOs will be input for the first parameter HostPinID. PLF implementer can change the MARCO definitions to fit to his host of choice.

@param[in] PinId Pin number to be configured.
@param[in] SetHigh Output status, set to high (TRUE) or low (FALSE)

@return PLF_ERRCODE
*/

PLF_ERRCODE PLF_HIO_SetIO(SYS_ExtPinID_e HostPinID, BOOL SetHigh);


/**
@brief This API gets the selected host digital input pin status

RSNum:908021

# Description

An API will get host digital input pin status.

In PLF.h, PIN MARCOs will be defined. And these MARCOs will be input for the first parameter HostPinID. PLF implementer can change the MARCO definitions to fit to his host of choice.
@param[in] PinId Pin number to be configured.
@param[out] pHigh Input status, input is high(TRUE) or low(FALSE)

@return PLF_ERRCODE
*/

PLF_ERRCODE PLF_HIO_GetIO(SYS_ExtPinID_e HostPinID, BOOL *pHigh);


#endif /* RFESWPORTDRV_INC_PLF_H_ */
