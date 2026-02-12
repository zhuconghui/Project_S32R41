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
@file hal_es2_loi.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>7
*/

#ifndef HAL_ES2_LOI_H
#define HAL_ES2_LOI_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API configures buffers b1 to b4, MUX and loop through switch to different operational modes for  LO interface.
 
RSNum: 2547528, 2547530
 
# Description
 
An API will configure the LOI to one o the five predefined operation modes.
1. Off Mode: b1 off, b2 off, b3 off, b4 off, LO output
2. Standalone Operation Mode: b1 on, b2 on, b3 off, b4 off, LO output
3. Loopback Test Mode: b1 on, b2 on, b3 on, b4 on, LO input
4. Cascade Master Mode: b1 on, b2 on, b3 off, b4 on, LO output
5. Casacade Slave Mode: b1 off, b2 on, b3 on, b4 off, LO input
 
Except for the above 5 predefined modes, uses can also use different combination of  the 4 buffers and MUX  based on their own requirements.
 
## Note
1. Buffer b1 connects internal chirp signal to the LO pads and the core IPs (RX/TX/RFBIST)
2. Buffer b2 connects the LO signal either external or internal to the core IPs (RX/TX/RFBIST)
3. Buffer b3 connects external LO signal coming from LO_IN to  the core IPs (RX/TX/RFBIST)
4. Buffer b4 connects chirp signal to LO_OUT
5. Mux selects the LO source for the core IP's (RX/TX/RFbist). 
 
@param[in] EnBuffer1 FALSE: buffer b1 is disabled; TRUE: buffer b1 is enabled.
@param[in] EnBuffer2 FALSE: buffer b2 is disabled; TRUE: buffer b2 is enabled.
@param[in] EnBuffer3 FALSE: buffer b3 is disabled; TRUE: buffer b3 is enabled.
@param[in] EnBuffer4 FALSE: buffer b4 is disabled; TRUE: buffer b4 is enabled.
@param[in] MuxCtrl FALSE: LO source is connected to LO_Out & core IP; TRUE: LOin is connected to core IP
@param[in] EnCtrlSwitch FALSE: switch open; TRUE: switch closed. This switch is used to connect the output of buffer b4 to the input of buffer b3. It should be only used at wafer test.
 
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_LOI_ConfigBufferMode(BOOL EnBuffer1, BOOL EnBuffer2, BOOL EnBuffer3, BOOL EnBuffer4, BOOL MuxCtrl, BOOL EnCtrlSwitch);


/**
@brief This API enable the RMS detector.
 
RSNum:1456117, 456365, 673725, 673724
 
# Description
 
An API will enable the RMS detector required for the calibration. 
 
@param[in] EnRMSDet 0: disable RMS detector; 1: enable RMS detector
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_LOI_EnableRFLevelRMSDet(BOOL EnRMSDet);


/**
@brief This API configures LO gain.
 
RSNum:2547535, 1448226 
 
# Description
An API will configure LO gain select which is by default HW LO calibration and if manual mode then gain code is used.
 
## Note
1. This API is only supported for ES2 samples.
2. BC_SYS_Init/BC_SYS_InitMasterSlaveMode API sets the gain_control_sel = 2 which is HW calibration(default value).
 
@see LOI_GainSel_e
 
@param[in] GainSelect Select whether HW LO calibration or gaincode based
@param[in] GainCode If GainSelect is gaincodelut or gaincode direct, then this code is taken
@param[in] BinSearchFromAbove If Gainselect is HW LO calib, (TRUE)Set binary search from above or (FALSE) from below
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_LOI_ConfigLOGainCtrl(LOI_GainSel_e GainSelect, uint8_t GainCode, BOOL BinSearchFromAbove);


/**
@brief This API triggers LO gain calibration and check for calibration status.
 
RSNum:1448226 
 
# Description
An API will triggers LO gain HW calibration and if status check is enabled, it checks for calibration status after a fixed input timeout value in us. This API assumes correct LO RF Level Low and High thresholds are set in LO IP.
 
## Note
1. This API is only supported for ES2 samples.
2. Since this calibration is performed in CW calibration mode the Chirp and LO Interface modules should be out of Dynamic powering saving mode(Disable dynamic power down mode). 
3. ReadCalibStatus recommended value is FALSE/0, based on the Application usage user can read the consolidate result of all the calibration, once calibration sequence is over,  using the API BC_ISM_GetCalibrationStatus. This is optimize approached.   
 
@see BC_ISM_GetCalibrationStatus
 
@param[in] ReadCalibStatus Enable checking calibration status after LO calibration is triggered. Recommended value FALSE.
@param[in] CalCheckTimeOutUs API wait for dedicate time after calibration is triggered, in case of  ReadCalibStatus = TRUE after this wait time, calibration status is checked. Typical value is 17us.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_LOI_StartLOGainCalib(BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs);


/**
@brief This API configure the LO frequency trippler gain controls.
 
RSNum:1448227 
 
# Description
An API will configure the LOx3 gain controls for SSB, TX and RX.
 
## Note
1. This API is only supported for ES2 samples.
 
@see LOI_LOx3GainConfig_t
 
@param[in] pLOx3GainConfig Lox3 Gain controls 
@param[in] LOx3TxChannels Enable TX channels for LOx3 gain
@param[in] LOx3RxChannels Enable RX channels for LOx3 gain
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_LOI_ConfigLOx3Gain(LOI_LOx3GainConfig_t *pLOx3GainConfig, BOOL LOx3TxChannels[3], BOOL LOx3RxChannels[4]);


/**
@brief  This API updates the value of low, min, high and max trigger level for gain control based on input bandwidth.

RSNum:1456365, 1456361, 510395, 510526, 510589, 510613, 510418, 510592, 510534, 510521, 510386, 690604, 673724, 510456 

# Description
An API will update the values of low, min, high and max trigger level for gain control based on input bandwidth.
An API will shift all 4 threshold monitors in LO of 1 LSB: min and low with -1, high and max with +1 and preserves the 1 LSB difference between high-max, min-low
This updated threshold values helps to clear LOI low warnings for higher chirp band width.
 
## Note
1. This API is only supported for ES2 samples.
2. This API is needed only for high BW chirp.

@param[in] InputBW chirp BW.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_LOI_UpdateLOILevelTh(BC_FLOAT InputBW);


/**
@brief This API configure the ball break detector of LOI.

RSNum:1456361, 2483080, 3602014
 
# Description
 
An API will enable or disable ball break detector for LOI. Also, configure the sensitivity and ground settings.
 
## Note
1. For grounded interface, both the positive and negative ball of the interface are the source of the BBD DC current, this current is sunk at the DC ground connection of the interface. It requires LOI BBD enabled, high sensitivity and grounded
2. For not grounded interface, the positive ball of the interface is the source of this DC current, while the negative ball of the interface is the sink. This require LOI BBD enabled, high sensitivity and not grounded. 
 
@param[in] EnableBBDLOIN  Ball break detector enable for LOIN.
@param[in] EnableBBDLOOUT Ball break detector enable for LOOUT.
@param[in] NormalSensitivityLOIN NormalSensitivity Ball break current detection limit for LOIN. 1=50uA(Normal)   0=500uA(High) 
@param[in] GroundedLOIN Balun grounded control based on balun type for LOIN. 0 = not grounded 1 = grounded.
@param[in] NormalSensitivityLOOUT NormalSensitivity Ball break current detection limit for LOOUT. 1=50uA(Normal)   0=500uA(High) 
@param[in] GroundedLOOUT Balun grounded control based on balun type for LOOUT. 0 = not grounded 1 = grounded.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_LOI_ConfigBBD(BOOL EnableBBDLOIN, BOOL EnableBBDLOOUT, BOOL NormalSensitivityLOIN, BOOL GroundedLOIN, BOOL NormalSensitivityLOOUT, BOOL GroundedLOOUT);



#if defined(__cplusplus)
}
#endif
#endif
