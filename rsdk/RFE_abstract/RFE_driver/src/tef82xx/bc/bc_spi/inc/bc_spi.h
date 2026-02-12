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
@file bc_spi.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>5
*/

#ifndef BC_SPI_H
#define BC_SPI_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

#ifdef BC_CALCULATE_SPICOUNT
extern uint32_t gBCWriteCheckCount;
extern uint32_t gBCWriteCount;
extern uint32_t gBCReadCount;
#endif

/**
@brief This API writes to a single SPI register

RSNum:1447534 

# Description
 
An API will write the 32bit in to the given register address of a module.
This API should also verify OTP and PON disabled IPs (this information is part of the system configuration information) and should fail on writing to disabled IPs and return error codes accordingly.


@param[in] ModAddr Module address
@param[in] RegAddr Register address
@param[in] WrData Data to be written

@return BC_ERRCODE
*/
 
BC_ERRCODE BC_SPI_Write(SYS_IPNum_e ModAddr, uint16_t RegAddr, uint32_t WrData);


/**
@brief This API writes to a single SPI register and verify the register content is correct or not after writing

RSNum:1447534 

# Description
 
An API will write the 32bit in to the given register address of a module.
This API should also verify OTP and PON disabled IPs (this information is part of the system configuration information) and should fail on writing to disabled IPs and return error codes accordingly.
After write, this API will verify if the target register content is the expected write value, if not, return an error code.

@param[in] ModAddr Module address
@param[in] RegAddr Register address
@param[in] WrData Data to be written

@return BC_ERRCODE
*/
 
BC_ERRCODE BC_SPI_WriteCheck(SYS_IPNum_e ModAddr, uint16_t RegAddr, uint32_t WrData);


/**
@brief This API writes to a single SPI register and verify the register content is correct or not after writing

RSNum:1447534 

# Description
 
An API will read 32bit value from the given register address of a module. If SPI driver fails with any reason, this API will return an error code.

@param[in] ModAddr Module address
@param[in] RegAddr Register address
@param[out] pRdData Read data result

@return BC_ERRCODE
*/
 
BC_ERRCODE BC_SPI_Read(SYS_IPNum_e ModAddr, uint16_t RegAddr, uint32_t *pRdData);


/**
@brief This API writes to one or more SPI registers using burst access method

RSNum:1447534 

# Description
 
An API will write one or more 32-bits words to a series of SPI registers starting from RegAddr. This API will allow user to choose if it writes to a series of consecutive register addresses or writes repeatedly to the same register address.
 
@param[in] ModAddr Module address
@param[in] RegAddr Register address
@param[in] RepMode Repetition mode, TRUE: write to the same register(RegAddr), NumWords times. FALSE: write to a series of consecutive registers starting at RegAddr, until RegAddr + 4*(NumWords - 1). This only works within the same ModAddr.
@param[in] NumWords Number of repetitions of the write operation
@param[in] pWrData Data to be written, must have the length of NumWords

@return BC_ERRCODE
*/
 
BC_ERRCODE BC_SPI_BurstWrite(SYS_IPNum_e ModAddr, uint16_t RegAddr, BOOL RepMode, uint8_t NumWords, uint32_t *pWrData);


/**
@brief This API reads one or more SPI registers using burst access method

RSNum:1447534 

# Description
 
An API will read one or more 32-bits data from a series of SPI registers starting from RegAddr. This API will allow user to choose if it reads from a series of consecutive register addresses or reads repeatedly from the same register address.
 
@param[in] ModAddr Module address
@param[in] RegAddr Register address
@param[in] RepMode Repetition mode, TRUE: read from the same register(RegAddr), NumWords times. FALSE: read from a series of consecutive registers starting at RegAddr, until RegAddr + 4*(NumWords - 1). This only works within the same ModAddr.
@param[in] NumWords Number of repetitions of the read operation
@param[out] pRdData Read data, must have the length of NumWords

@return BC_ERRCODE
*/
 
BC_ERRCODE BC_SPI_BurstRead(SYS_IPNum_e ModAddr, uint16_t RegAddr, BOOL RepMode, uint8_t NumWords, uint32_t *pRdData);



#if defined(__cplusplus)
}
#endif
#endif
