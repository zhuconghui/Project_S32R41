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
@file hal_es2_mipi.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>10
*/

#ifndef HAL_ES2_MIPI_H
#define HAL_ES2_MIPI_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API to initialize the MIPI interface.
 
RSNum:2547540
 
# Description
An API will initialize the MIPI(CSI2) interface registers to its initial values.
This API initializes MIPI interface with following settings:
1. Global MIPI pads for normal operation and enabled
2. MFIO pad speed set to 85MHz
3.  MIPI output set as 12 bit RAW unsigned.
4.  Enable Setting for the fast lock after reset release.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_MIPI_Init(void);


/**
@brief This API configure the MIPI interface.
 
RSNum:1456427
 
# Description
 
An API will configure the MIPI(CSI2) interface.
An API will have option to choose data rates(480, 240,120 Mbps).
An API will have option to select number of lanes(1 to 4).
 
This API internally enable default virtual channel, enables data valid pad, perform default trim setting. perform default pDhy setting also it will set default Raw12 mode. 
At the end of the this API enables MIPI transmission. This API should only be called when the CSI2 Receiver is DISABLED/PowerOff state, due Functional Reset assertion.

Addition configuration of PDC and Virtual channel
 
@see BC_MIPI_ConfigPDC
@see BC_MIPI_ConfigVC
 
@param[in] NLanes choose number of lanes.
@param[in] DataRate choose data rates. 
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE HAL_ES2_MIPI_Config(uint8_t NLanes, MIPI_DataRate_e DataRate);


/**
@brief This API configure the PDC of MIPI.
 
RSNum:2547540
 
# Description
 
An API will configure the PDC of MIPI(CSI2) interface.
An API will have option to enable and disable PDC filter.
An API will enable PDC sync.
An API will enable window active processing.
An API will enable unsigned CSI2 output data.
An API will have option to set the window active delay(delay b/w the input and output window active of PDC) for all 4 PDC delay decimation modes supported.
 
## Note
1. pDecModeDelays = NULL is a valid input for this API, NULL value will not change the delay settings. 
 
For configuration of MIPI
@see BC_MIPI_Config
 
@param[in]  DisPDCFilter True: filter inside PDC disabled, False: enable PDC filter.
@param[in]  EnPDCSync True: enable PDC sync, False: disable PDC sync.
@param[in]  EnWAProcess True: PDC only process within window active, False: PDC will always process.
@param[in]  EnUnsignedOut True: PDC out is unsigned 12bit, False: PDC output data is signed 12bit.
@param[in] pDecModeDelays array of delays for each decimation mode in order 1,2,3,4. Value 1 represent 25 nanosecond.
 
@return BC_ERRCODE
 
*/

BC_ERRCODE HAL_ES2_MIPI_ConfigPDC(BOOL DisPDCFilter, BOOL EnPDCSync, BOOL EnWAProcess, BOOL EnUnsignedOut, uint8_t pDecModeDelays[4]);


/**
@brief This API configure the Virtual Channel of MIPI interface.
 
RSNum:1445703
 
# Description
An API will Configure the virtual channels(VC) for MIPI.
An API should have option to select any available virtual channel.
An API should have option to clear the MIPI frame count for selected virtual channel.
MIPI frame count is part of the MIPI package header.

For addition configuration of MIPI interface.
@see BC_MIPI_Config
 
@param[in] pSelectVCs True: to select the VC, False: deselect the VC.
@param[in] pClearFrameVCs True: clear VC MIPI frame count for each chirp sequence, False: clear VC MIPI frame counter at the reset of the serializer.
 
@return BC_ERRCODE
*/
 
 
BC_ERRCODE HAL_ES2_MIPI_ConfigVC(MIPI_VCNum_t *pSelectVCs, MIPI_VCClearFrame_t *pClearFrameVCs);


/**
@brief This API to get the Master clock frequency.
 
RSNum:1456377, 510513
 
# Description
 
An API will get the frequency counter value.
An API will start the frequency start trigger.
An API will have option to number of LSB bits to be ignored while comparing the final frequency counter read value.
An API will verify the frequency read counter value with ref counter read value.
 
@param[in]  FreqDeviationValue choose number of LSB bits to be ignored while comparing frequency counter.
@param[in] CountPeriod Period in us for doing the frequency measurement
@param[out] pFrequency output frequency.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_MIPI_MeasureFreq(MIPI_FreqCountDeviation_e FreqDeviationValue, float32_t CountPeriod, float32_t *pFrequency);


/**
@brief This API to configure the MIPI adapter.
 
RSNum:1447611, 510567, 510568
 
# Description
 
An API will configure adapter(ADAPT).
An API will have option to disable the individual ADC channel.
An API will have option of output pattern type for the disabled channel.
An API will have option to select the register bit for chirp number clear.
An API will have option to clear internal chirp number counter.
An API will have option to send CRC as the footer packet.
An API will have option to append the header packet with data packet.
 
## Note
1. For details of DisADCChanDataSelect value True : Send the "TestData" for disabled channel
 
@param[in] pDisADCChannels struct of channels, True: disable the selected ADC channel
@param[in] DisADCChanDataSelect True: Send the TestData set for disabled channel, False : send zero for disabled channel.
@param[in] EnChirpNumClearReg chirp number clear options
@param[in] EnPacketCRCFooter True: 32 bit CRC added in MIPI packet footer, False: No CRC  
@param[in] EnPacketHeader True: Packet header is sent with transmitted data packet, False: No packet header
 
@see HAL_ESx_MIPI_ConfigTestMode
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE HAL_ES2_MIPI_ConfigADAPT(MIPI_DisableADCChannels_t *pDisADCChannels, BOOL DisADCChanDataSelect, MIPI_ClearChirpNum_e EnChirpNumClearReg, BOOL EnPacketCRCFooter, BOOL EnPacketHeader);


/**
@brief This API to enable transmission.
 
RSNum:1456427
 
# Description
 
An API will enable and disable the MIPI(CSI2) transmission. 
 
@param[in] EnableDataTx True: enable transmission, False: disable transmission  
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE HAL_ES2_MIPI_EnTransmission(BOOL EnableDataTx);


/**
@brief This API to configure MIPI interface test mode.
 
RSNum:1447544, 510448
 
# Description
 
An API will enable the test mode for the MIPI(CSI2) interface.
An API will have option to skip the PDC from the loop.
An API API will have option to support the Fixed, sawtooth, sine wave and PRBS test modes.
An API will option to enable the delay data pattern.
An API will provide the test data for fixed mode.
 
## Note:
1. When the test mode is PRBS, the testModeTestData should be 0xFFF (12 1's)
 
@param[in] EnTest True: enable test mode, False: disable test mode
@param[in] pTestParameters parameters to config the MIPI test mode
 
@return BC_ERRCODE
 
*/

BC_ERRCODE HAL_ES2_MIPI_ConfigTestMode(BOOL EnTest, MIPI_ConfigTestParms_t *pTestParameters);


/**
@brief This API to configure MIPI metadata long packet.
 
RSNum:2547542
 
# Description
 
An API will configure the long packet configuration to enable or disable the metadata long packet along with the ADC data. 
Configuration contains long packet data type, long packet enable, user field enable, virtual channel selection, length. start delay and user info . 
user defined packet data type selected should be within the range of 0x30- 0x37 as per CSI2 specification.
Virtual channel can be selected are 0,1,2,3.
Start delay Delay between end of final chirp and start of meta data, counter is  w.r.t 40Mhz internal clock.
Minimum packet length will be 80 bytes when userfiled_en is enabled
 
## Note:
1. This API is only supported for ES2 samples.
 
@param[in] pConfigMetaData pointer to the structure configuring long packet data type, long packet enable, user field enable, virtual channel selection, length. and user info.
 
@return BC_ERRCODE
 
*/

BC_ERRCODE HAL_ES2_MIPI_ConfigMetaData(MIPI_ConfigMetaData_t *pConfigMetaData);


/**
@brief API to configure MIPI Continuous Clock mode.
 
RSNum:1456427, 2547540  
 
# Description
This API will enable/disable the Continuous Clock mode of MIPI(CSI2) interface 
This API is required to place the CLK lane in controlled LP-11 STOP state, or resume Continuous Clock operation via LP-01 to request HS transaction 

## Note:
1. The application should check the CSI2 Receiver RX_CLKCS[CSTOP] bit, if the lane is in STOP state before invoking this API

For configuration of MIPI
@see BC_MIPI_Config

@param[in] EnableContClock  1/TRUE: Enable Continuous Clock ; 0/FALSE: Disable Continuous Clock
 
@return BC_ERRCODE
*/

BC_ERRCODE HAL_ES2_MIPI_EnContinuousClock(BOOL EnableContClock);



#if defined(__cplusplus)
}
#endif
#endif
