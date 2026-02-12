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
@file hal_es2_sc.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>8
*/

#ifndef HAL_ES2_SC_H
#define HAL_ES2_SC_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API configures the sweep control profile information.
 
RSNum:1446589, 1452538
 
# Description
This API configures the sweep control profile information.
 
## Note
1. BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
 
@see SYS_ProfID_e
 
@param[in] ProfileNum Profile number.
@param[in] StartFreq start frequency in Hz of the chirp profile.
@param[in] usedBW Bandwidth in Hz of the chirp profile.
@param[in] RampTime Ramp-up time in us, of the chirp profile.
@param[in] DownChirp Type of chirp 0/FALSE: Positive chirp; 1/TRUE: Negative chirp.
@param[in] ResetTime Reset time in us, of the chirp
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SC_ConfigProfile(SYS_ProfID_e ProfileNum, BC_FLOAT StartFreq, BC_FLOAT usedBW, float32_t RampTime, BOOL DownChirp, float32_t ResetTime);


/**
@brief This API configures the sweep control mode settings
 
RSNum:1446590
 
# Description
This API configures the sweep control mode settings (i) Type of chirp - progressive or restart with start frequency (ii) Chirp reset depends on TE or sweep control profile setting
@param[in] ChirpType Type of chirp 0/FALSE: non-progressive 1/TRUE: progressive
@param[in] SweepRstCtrl Sweep reset control mode. 0/FALSE: Based on TE; 1/TRUE: Based on sweep control profile setting.
 
## Note
1. With progressive chirp mode the next chirp will follow from where the previous chirp reset.  With non-progressive chirp mode, chirps always start with profile start frequency.
2. With reset control from TE: at the end of data acquisition based on the number of ADC samples programmed in TE plus jump back time chirp reset will be triggered.  With reset control from SC itself, once the maximum number of steps are reached, chirp reset will be triggered.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SC_SetSweepCtrlMode(BOOL ChirpType, BOOL SweepRstCtrl);


/**
@brief This API enables the slow drift modulation.
 
RSNum:1446590, 1452538
 
# Description 
An API will have option to select the profile for slow drift chirp.
An API shell have option to slow drift chirp frequency from chirp to chirp.
 
## Note 
1. This API should be called after the chirp configuration for the particular profile is done BC_SYS_ProgramChirp API . 
2. This API is required to implement the slow drift modulation use case together with BC_SYS_AutoSubbandSwitching.
3. Higher value of the FreqDriftHz may not result in the good chip behaviour. 
4. InputBWFullRamp value 0 is special value to ignore the parameter.
5. User can set InputBWFullRamp to improve the precision of the drift in chirp. 
6. The function BC_SYS_ProgramChirp structure  SYS_ProfChirpTiming_t variable TReset should be used to set TReset value in this API, this is required to increase the precision.
7. BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
8. Negative value of FreqDriftHz will increase the reset BW over acquisition BW, irrespective of Chirp polarity.  
9. Negative value FreqDriftHz is not normal use case, user can use it but this might cause unlock error, since auto sub-band switching is not supported for negative value of FreqDriftHz.
10. Negative value FreqDriftHz can work and will not cause the unlock error as long as the current frequency is supported by the current sub-band.
 
@see BC_SYS_AutoSubbandSwitching
@see BC_SYS_ProgramChirp
@see SYS_ProfChirpTiming_t 
 
@param[in] ProfID The profile number under configuration. 
@param[in] FreqDriftHz required frequency drift in Hz, typical value < 40MHz
@param[in] TReset Chirp reset time in microsecond, typical value 1. This should be same as BC_SYS_ProgramChirp  SYS_ProfChirpTiming_t variable TReset.
@param[in] InputBWFullRamp Chirp Bandwidth for full ramp, special value 0 can be used to ignore this parameter, API will calculate the BW based on the setting done in BC_SYS_ProgramChirp.  
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SC_ConfigSlowDriftChirp(SYS_ProfID_e ProfID, BC_FLOAT FreqDriftHz, float32_t TReset, BC_FLOAT InputBWFullRamp);


/**
@brief This API sets the frequency for the continuous wave mode.
 
RSNum:1446589
 
# Description
This API sets the start frequency of the selected profile as the frequency for the continuous wave mode.
 
@see SYS_ProfID_e
 
@param[in] ProfileNum Profile number
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SC_SetZeroRamp(SYS_ProfID_e ProfileNum);


/**
@brief This API configures center frequency settings in SC for AAFC in CAFC.
 
RSNum:1445691
 
# Description
 
In AAFC operation in CAFC IP, there is possibility to search for subband and VCO amplitude for chirp center frequency instead of just start frequency. This API lets the user to choose among fcenter/fstart and automatic/manual center frequency and MDes calculation
 
## Note
1. BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
 
@see BC_CAFC_ConfigAAFC
 
@param[in] CAFCTXCalMode Modes in CAFC AAFC and TX PR calibrations. See the type doc for detailed information.
@param[in] Fc Manual input of center frequency (77GHz range) of a chirp (valid only when first option contains "MAN" mean manual calculation mode)
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_SC_ConfigAAFCFc(SYS_CAFCTXCalFreqMode_e CAFCTXCalMode, BC_FLOAT Fc);


/**
@brief This API keeps the middle frequency.
 
RSNum:1448225
 
# Description
This API keeps the middle frequency  in CW mode for TX output power calibration, LO calibration, LOx3 calibration, TXPR calibration and PR current calibration.
 
@param[in] KeepMidFreq 1/TRUE: Keep the middle frequency in CW mode; 0/FALSE: Release keep in middle frequency.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_SC_KeepMiddleFrequency(BOOL KeepMidFreq);


/**
@brief This API enable/disable option for the div_rst generated and hardware functional reset.
 
RSNum:1701374
 
# Description
This API enable/disable option for the div_rst generated and hardware functional reset.
 
## Note
1. This API is only supported for ES2 samples.

@param[in] EnDivRstFrame if TRUE Enable for div_rst generated from hardware during dwell time of every seq
@param[in] EnDivRstChirp if TRUE Enable for div_rst generated from hardware during dwell time of every chirp
@param[in] EnHardFuncRstFrame if TRUE Enable hardware functional reset at every sequence start.
@param[in] EnHardFuncRstChirp if TRUE Enable hardware functional reset at every chirp dwell start.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_SC_EnDivHardFuncReset(BOOL EnDivRstFrame, BOOL EnDivRstChirp, BOOL EnHardFuncRstFrame, BOOL EnHardFuncRstChirp);


/**
@brief This API configures dither control in SC.
 
RSNum:1446590
 
# Description
This API controls to reduce the chirp spurs with distributing the start freq and dwell time.
 
## Note
1. This API is only supported for ES2 samples.
2. The feature of modulating Fstart of chirp in pseudo-random way from chirp to chirp is not working and will therefore not be used.
Feature is controlled through NumLevelsStartFreqDither and StepSizeStartFreqDither of SC_DitherControl_t, use the value NumLevelsStartFreqDither = 0 and StepSizeStartFreqDither = 0.
 
@see SC_DitherControl_t
 
@param[in] pDitherControl Pointer to structure which configures dither control in SC.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_SC_ConfigDitherCtrl(SC_DitherControl_t *pDitherControl);



#if defined(__cplusplus)
}
#endif
#endif
