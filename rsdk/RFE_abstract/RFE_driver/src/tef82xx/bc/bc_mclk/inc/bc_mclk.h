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
@file bc_mclk.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>7
*/

#ifndef BC_MCLK_H
#define BC_MCLK_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API performs automatic calibration of MCLK.
 
RSNum:1448222,1701374, 1448223 
 
# Description
 
An API will trigger MCLK automatic calibration and return the calibration result as success or not.
It will be able to select to do initial calibration or re-calibration, initial calibration will take more time since it will use the initial setting for the calibration. At power on initial calibration is recommended. 
@param[in] ExtendedReCal TRUE: perform initial calibration; FALSE: perform re-calibration
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_MCLK_AutoCalib(BOOL ExtendedReCal);


/**
@brief This API checks and return if MCLK 4.8GHz PLL is locked
 
RSNum:2483102, 1448222, 510508 
 
# Description
 
An API will check and return if MCLK 4.8GHz PLL is locked or not.
An API will give the details of the calibration status.
This API will not rely on error flags, but just a single status bit in the register space, if PLL is not locked,user can use the pCalibStatus for the details.   
Related register: CALIBRATION_STATUS
 
@param[out] pLocked If MCLK PLL is locked or not. If PLL is not locked check pCalibStatus for details.
@param[out] pCalibStatus detailed calibration status structure
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_MCLK_GetCalibrationStatus(BOOL *pLocked, MCLK_CalibrationStatus_t *pCalibStatus);


/**
@brief This API sets the MCLK clk output buffers
 
RSNum:1445699, 1456418 
 
# Description
 
An API will enable/disable individual clk buffers in Master Clock.
 
@param[in] EnChirp480M Enable 480MHz clk buffer towards chirp engine (CAFC, TE, SC)
@param[in] EnSer480600M Enable 480/600MHz clk buffer towards serializer (MIPI, LVDS)
@param[in] EnADC1200M Enable 600MHz clk buffer towards ADCs
@param[in] EnSSB600M Enable 600MHz clk buffer towards SSB
@param[in] EnADC40M Enable 40MHz clk towards ADCs
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_MCLK_SetClkBuffers(BOOL EnChirp480M, BOOL EnSer480600M, BOOL EnADC1200M, BOOL EnSSB600M, BOOL EnADC40M);


/**
@brief This API sets the timing of the MSP Calibration(  requires for Cascading mode only) 
 
RSNum:1456418 
 
# Description
An API will set the different wait time required to perform the Master slave Phase Calibration(MSPC) within (used for cascading application).
 
## Note
1. Timing set by this API is only used for MSPC steps, only requires for cascading applications. 
 
@param[in] MSPCTime Total Master Slave Phase Calibration timings. 
@param[in] SkewTime wait time for the Skew Change step. 
@param[in] DelayTime wait time for the Delay Change step.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_MCLK_ConfigMSPCTiming(MCLK_MSPCWaitTime_e MSPCTime, MCLK_MSPCSkewWaitTime_e SkewTime, MCLK_MSPCDelayWaitTime_e DelayTime);


/**
@brief This API starts the MSP Calibration (requires  for Cascading mode only)
 
RSNum:1448232 
 
# Description
 
An API will perform the phase alignment functionality within MCLK (used for cascading application)              
AN API Shall perform the Master Slave Phase Calibration(MSPC).
This API need to be called for master clock phase alignment for cascading application. 
 
## Note
1. Functional reset of serializer is done after the calibration is finished to synchronize the clock.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_MCLK_StartMSPC(void);


/**
@brief This API checks the MSP Calibration status(requires  for Cascading mode only)
 
RSNum:1448232 
 
# Description
 
An API Shall check the status of the Master Slave Phase Calibration(MSPC).
An API Shall return the MSPC status.
This API internally perform check on MSPCalibration using change in clock delay value. 
Calibration correction is enabled to update the new Skew and delay after calibration if there is a difference in the values.
This API can be useful for periodic check of the MSPC status. 
 
## Note
1. Functional reset of serializer is done after the calibration is finished to syncronize the clock.
 
@param[out] pNeedCalib True/1: Application need to perform the MSPC, False/0: MSP is in Sync
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_MCLK_CheckMSPCStatus(BOOL *pNeedCalib);


/**
@brief This API sets the MSPC in manual mode (requires for Cascading mode only)
 
RSNum:1456418 
 
# Description
This API sets the MSPC in manual mode first.
This API will set the fine pitch 600MHz output clock skew. The fine adjustment per step is 104 ps. 
This API will set reference clock delay factor N. where Delay = N. (1/600MHz). N=1 to 15
 
@param[in] OutPutClkSkewCode supported code value 1 to 15, 1 code corresponds to 104ps 
@param[in] RefClkDelayCode supported code value 1 to 15, 1 code corresponds to 1.6ns
 
@return BC_ERRCODE
*/
BC_ERRCODE BC_MCLK_ConfigManualMSPC(uint8_t OutPutClkSkewCode, uint8_t RefClkDelayCode);



#if defined(__cplusplus)
}
#endif
#endif
