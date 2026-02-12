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
@file bc_lvds.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>8
*/

#ifndef BC_LVDS_H
#define BC_LVDS_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API initializes the LVDS
 
RSNum:2547541
 
# Description
This API initializes LVDS interface with following settings:
1. Global LVDS pads for normal operation and enabled
2.  Disable LVDS receiver
3.  Disable both weak pull-up and pull-down
4.  MFIO speed 85MHz
5.  Frame clock is free running
6.  No data valid delay
7.  MS first in packet, disable CRC and with no packet header
8.  Output unsigned, etc.,
 
@return BC_ERRCODE
*/
BC_ERRCODE BC_LVDS_Init(void);


/**
@brief This API configures the LVDS interface.
 
RSNum:1611001, 510567
 
# Description
This API configures various LVDS interface related parameters.
 
@see LVDS_Config_t
@see LVDS_OptConfig_t 
 
@param[in] pLVDSConfig pointer to the LVDS configuration structure
@param[in] pLVDSOptConfig pointer to the LVDS optional configuration structure
 
@return BC_ERRCODE
*/
BC_ERRCODE BC_LVDS_Config(LVDS_Config_t *pLVDSConfig, LVDS_OptConfig_t *pLVDSOptConfig);


/**
@brief This API configures the PDC of LVDS interface.
 
RSNum:2547541
 
# Description
This API configures the various settings of PDC of LVDS interface
@param[in] DisPDCFilter Filter disable control. 0/FALSE: Not disabled; 1/TRUE: Disabled
@param[in] EnPDCSync Reset control of PDC with respect to PDC reset signal from Chirp. 0/FALSE: No reset; 1/TRUE: Reset for every rise edge.
@param[in] EnWAProcess Processing control of input data. 0/FALSE: Always process input data. 1/TRUE: PDC processes samples within the WA.
@param[in] EnUnsignedOut PDC output sign control. 0/FALSE: Signed 12-bit; 1/TRUE: unsigned 12-bit
@param[in] pDecModeDelays Window active delay control values for decimation modes 1, 2, 3 & 4 with respect to 40 MHz clock. Valid range 0-15
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_LVDS_ConfigPDC(BOOL DisPDCFilter, BOOL EnPDCSync, BOOL EnWAProcess, BOOL EnUnsignedOut, uint8_t pDecModeDelays[4]);


/**
@brief This API measures the serialiser frequency.
 
RSNum:1456377, 510513
 
# Description
This API measures the serialiser frequency by configuring Ideal count, reference counter, frequency counter trigger selection, frequency deviation value and starts the frequency measurement. Once the measurement is done upon measurement success frequency is calculated.
 
@see LVDS_Feq_Dev_e
 
@param[in] FreqDevVal Frequency counter deviation setting
@param[in] CountPeriod Period in us for doing the frequency measurement
@param[out]  pFrequency LVDS Frequency
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_LVDS_MeasureFreq(LVDS_Feq_Dev_e FreqDevVal, float32_t CountPeriod, float32_t *pFrequency);


/**
@brief This API enables LVDS channels
 
RSNum:2547541
 
# Description
This API enables LVDS transmission channels.
 
## Note
1. Array of four to independently enable or disable LVDS transmission channels
 
@param[in] pTxChannels Channels 0/FALSE: Transmission  disabled; 1/TRUE: Transmission enabled
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_LVDS_EnTransmission(BOOL pTxChannels[4]);


/**
@brief This API configures the LVDS test mode parameters
 
RSNum:1447543, 510442
 
# Description
This API configures the LVDS test mode parameters.
 
@see LVDS_ConfigTestParms_t
 
@param[in] EnTest True: enable test mode, False: disable test mode
@param[in] pTestConfig Test configuration settings.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_LVDS_ConfigTestMode(BOOL EnTest, LVDS_ConfigTestParms_t *pTestConfig);


/**
@brief This API configures window active control.
 
RSNum:2547541
 
# Description
This API configures the window active control
@param[in] SelFromRegField Source of WA. 0/FALSE: From TE; 1/TRUE: From register field
@param[in] EnWA WA value with register field as source.  0/FALSE: WA disabled; 1/TRUE: WA enabled.
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_LVDS_ChooseWinActiveSel(BOOL SelFromRegField, BOOL EnWA);


/**
@brief This API switches the LVDS modes.
 
RSNum:2547541
 
# Description
This API switches the LVDS from functional mode to calibration mode and vice-versa. Also set the frame clock pattern and idle patterns.
@param[in] SwitchToCalMode LVDS mode control. 0/FALSE: Normal mode; 1/TRUE: Calibration mode.
@param[in] ClockChTxData12x1 Frame clock pattern (12-bit) to be sent in RAW mode
@param[in] IdlePattern Idle pattern sent in RAW mode outside the valid data window.
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_LVDS_SwitchMode(BOOL SwitchToCalMode, uint16_t ClockChTxData12x1, uint16_t IdlePattern);



#if defined(__cplusplus)
}
#endif
#endif
