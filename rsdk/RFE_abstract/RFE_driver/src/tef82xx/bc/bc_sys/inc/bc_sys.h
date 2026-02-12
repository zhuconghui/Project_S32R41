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
@file bc_sys.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>16
*/

#ifndef BC_SYS_H
#define BC_SYS_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API initializes Barracuda chip

RSNum:1446670,1445683,1446671,1445699,1701374,1445688

# Description
An API will initialize Barracuda, with certain predefined steps. These steps will be strictly complaint to the official initialization sequence, with all functional safety procedure and checks done in a proper way. By default this API will initialize all available normal IPs (except the IPs for testing, e.g. ATB)
If after this API call, user doesn't need FS feature or doesn't need certain IPs to be powered on, user should mask errors or turn off IPs by himself.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init(void);


/**
@brief This API Returns the Barracuda API release version.

RSNum:2547558

# Description
This API Returns the Barracuda API release version.

@param[out] pVersion struct containing released version information

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_GetAPISWVersion(SYS_ApiVersion_t *pVersion);


/**
@brief This API programs a chirp profile (settings that are profile based) to user specified settings

RSNum:1445690, 1446591, 1446589, 1445694, 1452538

# Description

An API will program a chirp profile in the user selected profile. The chirp profile includes various timings, chirp frequency related parameters, sampling parameters and TX/RX profile parameters. It provides "one-call to configure all" functionality for chirp profiles.
This API may call HAL APIs from different IPs. If a validation test case requires different behavior, it may use these individual HAL APIs differently to achieve it.

## Note
1. In pChirpFreq. when InputChirpBW is set to 0, this API will configure the chirp profiles to a state to achieve CW mode, with which user should be able to still perform a "fake" chirp (since it's CW) and capture data from digital data interface.
2.For ES1, in pChirpFreq, when SBSearch is set to e_SYS_SBSEARCH_AAFC_AUTO, this API will perform HW-automatic subband selection (AAFC: automatic amplitude and frequency control). Otherwise(e_SYS_SBSEARCH_FORCE) this API must receive the subband number to be used as input.
3. In pChirpTiming  when TChirp<TDwell+TSettle+NumSamples(TAcq)+TJumpback+TReset, then minimal TChirp can be used, otherwise the actual needed TChirp will be programmed to TE.

@param[in] ProfID The profile number under configuration
@param[in] pChirpTiming Chirp profile timing parameters, @see SYS_ProfChirpTiming_t
@param[in] pChirpFreq Chirp profile frequency parameter, @see SYS_ProfChirpFreq_t
@param[in] pProfSampleDeci Chirp profile sample and decimation parameters, @see pProfSampleDeci
@param[in] TXBPS TX bipolar phase shift settings, TRUE:180deg; FALSE:0deg. Array of 3
@param[in] PhaseRotation TX multi-bit phase rotator phase shift settings, array of 3.
@param[in] TXFastSW TX RF transmission switch settings, closed(TRUE), open(FALSE). Array of 3.
@param[in] TXEN TX DC power enable, enabled(TRUE), array of 3
@param[in] RXEN RX DC power enable, enabled(TRUE), array of 4
@param[in] RXGain RX chain gain setting, 0(27dB)-7(45dB) in step of 3dB. Array of 4
@param[in] RXLPF RX low pass filter setting, unit of Hz
@param[in] RXHPF RX high pass filter setting, unit of Hz

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_ProgramChirp(SYS_ProfID_e ProfID, SYS_ProfChirpTiming_t *pChirpTiming,  SYS_ProfChirpFreq_t *pChirpFreq,  SYS_ProfChirpSampleDeci_t *pProfSampleDeci, BOOL TXBPS[3], float32_t PhaseRotation[3], BOOL TXFastSW[3], BOOL TXEN[3], BOOL RXEN[4], RX_Gain_Control_e RXGain[4],  SYS_RXLPF_CornerFreq_e RXLPF[4], SYS_RXHPF_CornerFreq_e  RXHPF[4]);


/**
@brief This API changes start frequency of a chirp (or CWMode) and can search/set a new suitable subband

RSNum:2547533

# Description

An API will only change the fstart of a chirp (or in CWMode), and if user chooses, to also change to a suitable subband for this new frequency.

## Note
1. BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
2. ProgramChirp must have been called once to setup the full configuration of a chirp or CWMode before calling this function.
3. User have multiple options to select for a new suitable subband, check SYS_SBChangeMode for detailed options.

@see BC_SYS_ProgramChirp

@param[in] ProfID Select which profile's start frequency to change
@param[in] StartFreqHz Start frequency or CW frequency to change to, unit in Hz
@param[in] Mode Mode for searching/forcing for new subband, user can also choose to keep current subband untouched.
@param[inout] pSubband When e_SYS_SBCHG_FORCESB is used in Mode, then pSubband is input to pass desired forced subband. When other options are used in Mode, then pSubband is output to indicate the subband search/force result.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_ChangeFStart(SYS_ProfID_e ProfID,  BC_FLOAT  StartFreqHz, SYS_SBChangeMode_e Mode, uint8_t *pSubband);


/**
@brief This API sets CW mode for calibration.

RSNum:1448226, 1448227

# Description
This API sets the  VCO to CW (non chirp mode) mode, with the option to keep center frequency or start frequency for the given profile.
This is API is pre-requisite for LO B2 Calibration, LOx3 Gain Calibration, Tx Gain Calibration, TX PR current calibration, TxPR Calibration.

@see BC_LOI_CalibrateLOGain
@see BC_LOI_CalibrateLOx3Gain
@see BC_SYS_CalibrateTXOutputPower

@param[in] ProfileID Load the selected profile
@param[in] KeepMiddleFreq 1/TRUE: keep VCO tuned to center frequency; 0/FALSE: keep VCO tuned to start frequency

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_CalibrationCWMode(SYS_ProfID_e ProfileID, BOOL KeepMiddleFreq);


/**
@brief This API copies profile in one IP, to the selected profiles in the same IP.

RSNum:1452538

# Description

This API copies profile in one IP, to the selected profiles in the same IP. The selected profiles can be one single profile or multiple profiles using type ::e_SYS_PROFILES_0_TO_5

@param[in] IPNum IP number, the profile in this IP will be copied
@param[in] SrcProfID Source profile ID, must be a single profile. So  e_SYS_PROFILES_0_TO_5 is not a valid option.
@param[in] DestProfID Destination profile ID, the profile from Profile[SrcProfID] in IPNum module will be copied to Profile[DestProfID] in the same IP. DestProfID can be multiple profiles, e.g.  e_SYS_PROFILES_0_TO_5.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_CopyProfile(SYS_IPNum_e IPNum, SYS_ProfID_e SrcProfID, SYS_ProfID_e DestProfID);


/**
@brief This API configs TX PR in predefined modes.

RSNum:1446592, 1456429, 1446593, 1445695, 1445698

# Description
An API will config TX PR in predefined modes.

## Note
1. For TX(s) that choose non-DDMA mode, the corresponding pDDMAInitPhase and pDDMAPhaseUpdate will be 'do-not-care'.
2. When using QPSK I/O's as controls, corresponding settings to be done separately.
3. For TE based initial phase code and/or BPSK control, corresponding settings to be done separately.
4. For DDMA phase code calculation we use 10bits so the resolution is increased to  0.3515625(360/1024),
5. DDMA phase code calculation uses the 10bit which has, integer and fractional part. 6 MSBs are integer phase in steps of 5.625 degree, 4LSBs are fractional part.
6. Final phase calculation only uses MSB 6 bits hence we will have output phase resolution of 360/64 = 5.625 degree only.
7. The phase starting point and increment both can be fractional, but at the end only the integer part is sent to the phase rotator.
   Therefore using fractional increment does not result in fractional phase variation (this is limited by the capability of the phase rotator circuit),
   but results in phase code (integer part) to change not every chirp, but less often, resulting is "stair-like" shape of phase versus chirp number.
   For example, using an increment value of 47.8125 degree ( phase code 0x88 or b00_1000_1000) results in phase values (assuming zero starting code)
   sent to phase rotator of 0 - 8 - 17 - 25 - 34 - 42... for chirps 1 - 2 - 3 - 4 - 5 this will result in chirp phase 0 - 45 - 95.625 - 140.625 - 191.25 degree.
8. Only positive values are allowed for DDMAInitPhase and DDMAPhaseUpdate.
9. The phase of the first chirp in the sequence will be equal to pDDMAInitPhase when a reset_ddma(BC_TE_ResetTxPRDDMA) is applied before a chirp seqence

@see TE_DDMAMod_e
@see TE_PRPCGenMode_e
@see BC_TE_ResetTxPRDDMA

@param[in] pUseDDMA : Source of the initial phase code. 0/FALSE: TE; 1/ TRUE: DDMA
@param[in] DDMAMode : DDMA mode common for the TXs that choose DDMA as source of initial phase code.
@param[in] pDDMAInitPhase: Initial phase value in degrees for DDMA mode.
@param[in] pDDMAPhaseUpdate: Phase update size in degrees for DDMA mode.
@param[in] pFinalPCGenMode : Final phase code generation mode
@param[in] pBPSKSource : Source of BPSK control. 0/FALSE: TE; 1/TRUE: QPSK[0]

@return BC_ERRCODE
*/
BC_ERRCODE BC_SYS_ConfigTXPR(BOOL pUseDDMA[3], TE_DDMAMod_e DDMAMode, float32_t pDDMAInitPhase[3], float32_t pDDMAPhaseUpdate[3], TE_PRPCGenMode_e pFinalPCGenMode[3], BOOL pBPSKSource[3]);


/**
@brief This API initializes the chip for master or slave mode.

RSNum:1445685, 2547528, 2547530, 2547531

# Description

An API will initialize Barracuda with necessary steps for the master and slave modes respectively. The default initialization is  to start master mode.

## Note.
1. Salve mode CAFC module should be disabled in BC_CC_SetAppConfiguration

@see BC_CC_SetAppConfiguration

@param[in] EnSlaveMode FALSE: the chip is set to master mode; TRUE: the chip is set to slave mode

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_InitMasterSlaveMode(BOOL EnSlaveMode);


/**
@brief This API to configures the CRC Trigger event for checking CRC.

RSNum:1456114, 510379

# Description
An API will trigger the CRC check at different CRC trigger event.

## Note
1. During CRC trigger event e_SYS_CRC_TRIGGER_EVENT_AT_START_OF_CHIRP, the local register MASK_CC_RESET_ERROR -> mask_reg_crc_reset_error of all modules to be set '1'.
2. e_SYS_CRC_TRIGGER_EVENT_MCU_TRIGGER will trigger CRC check internally.

@see SYS_CRC_Trigger_Event_e

@param[in]  CRCTriggerEvent : CRC check trigger event with different options
NO_CRC_TRIGGER, START OF CHIRP, END_OF_CHIRP, MCU_TRIGGER.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_RegCRCCheckCtrl(SYS_CRC_Trigger_Event_e CRCTriggerEvent);


/**
@brief This API checks the integrity of Master Clock.

RSNum:1456377, 510513

# Description
An API will check the integrity of Master Clock.
This API check the Serialiser(MIPI/LVDS) clock frequency with the reference clock frequency.
If the clock at the Serialiser(MIPI/LVDS) is not equal to the  reference clock, API return error.

## Note
1. This is not a FIT API

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_MCLKIntegrityCheck(void);


/**
@brief An API will check the integrity of the TX Sensor.

RSNum:1447766, 1616515

# Description
An API will check the integrity of the TX Sensor An API will check the integrity of the TX RF level Sensor. This is a FuSa API. This is FIT API.
API injects TX Rf level min error and by restoring the values, the error is cleared.
-For ES1, to inject error level min error API varies LOI and TX current gain.
-For ES2, to inject level min error  API uses local TX switch.

## Note
1. This API needs to be called after all the IPs are calibrated. CAFC, LOB2, Lox3, TxPR Current, Tx Current gain.
2. This API needs to be called in calibrate CW mode.
3. Only for the ES1, this API needs all the required IPs in PON mode.
4. The TX_CONTROL register is set to reset value after the Integrity check is complete to reduce the SPI cycle.
5. During the sensor integrity check, since Tx FastSwich is closed, Barracuda will be transmitting for a short duration.
6. Only For ES2, this API disables the dynamic power-saving mode for Chirp, LOI, and TX modules, in case the modules are in dynamic power-saving mode and restores the setting before exiting the API function
7. If the error code is BC_ERRCODE or BC_ERR_TX_SENSORFITFAIL, restoration of module registers are successful. In case of any other error codes, restoration of TX_CONTROL, TX_ERROR_MON, DYNAMIC_POWER_CONTROL and ISM_ERROR_MCU_RESET might not be done. API user need to invoke relevant API's to restore these register values.

@return BC_ERRCODE
*/
BC_ERRCODE BC_SYS_TXSensorIntegrityCheck(void);


/**
@brief An API will check the integrity of the CAFC sensor.

RSNum:1447767, 1616522

# Description
An API will check the integrity of the CAFC sensor by forcing a VCO level min error and PLL unlock error. This is a FuSa API. This is FIT API.
This API Triggers the chirp in SPI mode. In case the chirp trigger mode is in external trigger mode, this API will change the chirp trigger mode to SPI trigger mode and restore the mode at the end of the API.
This API triggers 3 chirp sequences, the first one for generating VCO level error injection, the second one for generating VCO unlock error and the third one is for clearing VCO unlock error and VCO level error.
At the end, API checks whether unlock and level errors are cleared for profile ChirpProfSel. The ChirpProfSel profile need to be programmed and calibrated for atleast CAFC IP, otherwise this API will return with error.
This API will rely on the register CHIRP_GLOBAL_CONTROL-> ChirpStart to set to 0 as an indication of Chirp sequence over.
To time optimize the API following steps are implemented.
1.) Set the number of chirp in a sequence time based on the NumChirp parameter. Restore back before exiting the API function.
2.) Disabled auto-trigger the PR safety checks at the end of the sequence, in case, enabled and restore back before exiting the API function.
3.) Set the chirp sequence interval time based on the NumChirp parameter. Restore back before exiting the API function.

## Note
1. In case the chirp trigger is set in external trigger mode,  this API converts the trigger mode to SPI trigger mode and at the end of function restores the trigger mode.
2. In SPI trigger mode, to trigger another BC the chirp start pad to be configured to O/P mode.
3. For the cascade use case, all followers will also get a chirp trigger, which may cause ISM errors.
4. For the cascade use case, to avoid chirp trigger for follower devices, CHIRP_GLOBAL_CONTROL->ChirpEnable should be set to FASLE for all follower devices, the application can use the BC_TE_EnableChirp API to set ChirpEnable.
5. For the cascade use case, in case ChirpEnable is not set to FALSE application needs to call BC_ISM_ResetISMErr for all the followers after BC_SYS_CAFCSensorIntegrityCheck API.
6. This API needs to be called after the ChirpProfSel profile is programmed, VCO is configured and ChirpProfSel profile CAFC calibration is done properly.
7. If the error code is BC_ERR_NOERROR, BC_ERR_SYS_CAFCINTEGRITY_CHECK_UNLOCK or BC_ERR_SYS_CAFCINTEGRITY_CHECK_LEVEL, restoration of module registers are successful. In case of any other error codes, restoration of CHIRP_SEQUENCE_CONTROL, CHIRP_GLOBAL_CONTROL, CHIRP_SEQUENCE_INTERVAL_CONTROL, CHIRP_TRIGGER_MODE_CONTROL and PR_DELAY_CONTROL might not be done. API user need to invoke relevant API's to restore these register values.


@see BC_TE_EnableChirp
@see BC_ISM_ResetISMErr
@see BC_SYS_ProgramChirp
@see BC_CAFC_CalibAAFCInjDAC


@param[in] ChirpProfSel Profile to be used for the integrity check
@param[in] NumChirp Number of chirps
@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_CAFCSensorIntegrityCheck(SYS_ProfID_e ChirpProfSel, uint16_t NumChirp);


/**
@brief This API configures Chirp Start (CS) Out

RSNum:2547559

# Description
This API configures chirp trigger mode control.
This API configures the functionality for chirpstart_out(CSOUT), chirpstart_in, ready_int, csi2_frame and selection mode for chirpstart_out.
ready_int, csi2_frame is configured, as per user input, if CSOUT functional selection is CSOUT interrupt event and selection mode for CSOUT is configured, as per user input, if CSOUT functional selection is based on the sel_mode_for_chirp_start_out event.

## Note
1. Based on the settings, the chirp start in / out pads to be configured as input or output using the CC ConfigPad API.
2. Using BC_CC_SwitchMcuIntCSOut API  to configure appropriate signal.
3. CSI2FrameMode input parameter is ignored/not used by API. Bitfield csi2_frame_mode_sel reset value(0, CSI2 frame deactivation at end of a  sequence) is used.  Passing any other value for TE_CSI2FrameMode_e will be discarded since hardware doesn't support it.

@see TE_CSOutCfg_t
@see BC_CC_ConfigPad
@see BC_CC_SwitchMcuIntCSOut

@param[in] pCSOutCfg pointer to the config structure

@return BC_ERRCODE
*/
BC_ERRCODE BC_SYS_SetCSOut(TE_CSOutCfg_t *pCSOutCfg);


/**
@brief This API reads the selected temperature sensor using CC module and returns temperature in Kelvin

RSNum:1456406

# Description

An API will read user selected temperature sensor using CC module and returns temperature in Kelvin by configuring the TEMP DIGITIZER FUNC CONTROL register.

## Note
1. TXs transmission should be turned ON to get the right temperature measurement for TX IP.
2. Call BC_TX_ConfigLocalCtrl function to enable TXs transmission.
3. Disable TXs transmission once the temperature measurement is done.

@see BC_TX_ConfigLocalCtrl

@param[inout] pKelvinTX1 Input as 0.0f disable the temperature measurement for TX1 IP, 1.0f enable the temperature measurement for TX1 IP, Output : pKelvinTX1 Final measured and converted temperature in unit of Kelvin
@param[inout] pKelvinTX2 Input as 0.0f disable the temperature measurement for TX2 IP, 1.0f enable the temperature measurement for TX2 IP, Output : pKelvinTX2 Final measured and converted temperature in unit of Kelvin
@param[inout] pKelvinTX3 Input as 0.0f disable the temperature measurement for TX3 IP, 1.0f enable the temperature measurement for TX3 IP, Output : pKelvinTX3 Final measured and converted temperature in unit of Kelvin
@param[inout] pKelvinChirp Input as 0.0f disable the temperature measurement for Chirp IP, 1.0f enable the temperature measurement for Chirp IP, Output : pKelvinChirp Final measured and converted temperature in unit of Kelvin

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_ReadTempSensor(float32_t *pKelvinTX1,float32_t *pKelvinTX2,float32_t *pKelvinTX3,float32_t *pKelvinChirp);


/**
@brief This API enables the Automatic sub band switching.

RSNum:1446590

# Description
An API shell enables/disable the automatic sub band switching.
If automatic sub-band switching option enabled/disable internally enables/disables the progressive chirp respectively.
This API has option to set the sub-band increment and decrement while sub-band switching.
When sub-band automatic switching  is allowed, VCO tuning voltage monitor (VTM) errors are disabled.
This API is required to implement the slow drift modulation use case.

## Note
1. SubbandSteps  value is used by API only when Enable is TRUE.

@see BC_SC_ConfigSlowDriftChirp
@see BC_SC_SetSweepCtrlMode

@param[in] Enable  1/TRUE Enable the automatic sub-band increment/decrement ; 0/FALSE disable the auto switching
@param[in] SubbandSteps  sub-band auto increment and decrement value, range [0-15], value depend upon the Frequency drift value( typical 1 for low drift)

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_AutoSubbandSwitching(BOOL Enable, uint8_t SubbandSteps);


/**
@brief This API sets a Barracuda device as target of operation including platform layer

RSNum:1445685

# Description

An API will set a Barracuda device as target of operation. Operation includes App configuration, SPI access APIs, IO/interrupt APIs etc.
This API will call the call the  PLF_SYS_SetTarget, BC_CC_SetMSDevice and perform a dummy write to scratch register.

## Note
1. This API is only required for Cascade use case,
2. This API will switch the device if input TargetDevice is different from the current device

@see  PLF_SYS_SetTarget
@see BC_CC_SetMSDevice

E.g. in a cascading system, if a user sets e_PLF_MASTER as target, then all API calls are effective only to the master barracuda. Same principle applies to slave barracuda chips.

@param[in] TargetDevice The Barracuda device

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_SetDevice(PLF_SPITarget_e TargetDevice);

/**
@brief This API Checks the integrity of register CRC MCU trigger

RSNum: 1456114, 510379

# Description

This API will check the stuck at 0 fault for crc_check_trigger_mcu bitfield.
This API is needed only if application is performing the registers CRC check using the MCU_TRIGGER.
This API will use the error injection at ISM module for the integrity check.
This API use fault injection for checking the integrity.

## Note
1. This API is will not check for stuck at 1 fault for crc_check_trigger_mcu bitfield.
2. Error other then BC_ERR_SYS_REGCRC_CCMODULE_ERROR_SET and BC_ERR_SYS_REGCRC_TRIGGER_FAILED might not restore the CC_CRC_ERROR_INJECTION and REG_CRC_CHECK_CTRL registers.
3. Calling this API will result in ErrorN pin assertion.

@see BC_SYS_RegCRCCheckCtrl
@see SYS_CRC_Trigger_Event_e


@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_RegCRCMCUTrigIntCheck(void);

/**
@brief This API perform Ball Break detection check for LO IN and OUT interface.

RSNum: 1456361, 2483080, 3602014

# Description

This API perform BBD check for LO IN and OUT in case of non grounded configuration. 


@see BC_LOI_ConfigBBD

## Note
1. This API will check only LO IN or OUT interface at a time for one device.
2. For BBD check to be performed, LOI must be out of dynamic Power down mode.
3. BBD check has is to be performed for every connected Local Oscillator Interface.
4. For example: in a quad Barracuda system, when BBD check of LO IN of follower 1 is performed, the BBD for the LO OUT of the leader and the LO IN of the leader and followers 2 and 3 should be disabled. 
5. API user need to disable LO IN/OUT of other leader/followers in the system by invoking BC_LOI_ConfigBBD 


@param[in] CheckLOIN  Check ball break detector of LOIN for TRUE. Check BBD of LOOUT for FALSE
@param[in] NormalSensitivityLOIN NormalSensitivity Ball break current detection limit for LOIN. 1=50uA(Normal)   0=500uA(High) 
@param[in] GroundedLOIN Balun grounded control based on balun type for LOIN. 0 = not grounded 1 = grounded.
@param[in] NormalSensitivityLOOUT NormalSensitivity Ball break current detection limit for LOOUT. 1=50uA(Normal)   0=500uA(High) 
@param[in] GroundedLOOUT Balun grounded control based on balun type for LOOUT. 0 = not grounded 1 = grounded.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_LoiBBDCheck(BOOL CheckLOIN, BOOL NormalSensitivityLOIN, BOOL GroundedLOIN, BOOL NormalSensitivityLOOUT, BOOL GroundedLOOUT);

#if defined(__cplusplus)
}
#endif
#endif
