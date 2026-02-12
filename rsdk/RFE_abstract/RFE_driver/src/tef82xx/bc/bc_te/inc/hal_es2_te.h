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
@file hal_es2_te.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>23
*/

#ifndef HAL_ES2_TE_H
#define HAL_ES2_TE_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API configures the TE profile information
 
RSNum:1446589, 1445696 
 
# Description
This API will configure Timing Engine Profile information.
 
@see TE_ConfigProfile_t
 
@param[in] pConfigProfile pointer to the profile information structure
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_ConfigProfile(TE_ConfigProfile_t *pConfigProfile);


/**
@brief This API configures different the chirp mode and interfacing options.
 
RSNum:1456436
 
# Description
This API configures :
1.  Chirp trigger mode: SPI trigger or external trigger.
2. Chirp power mode: dynamic or not
3.  Chirp start delay w.r.t 40MHz (no delay or one clock delay)
 
## Note
1. With external trigger mode, the chirp start pad to be configured to I/P mode to get the signal into BC.
2. In SPI trigger mode, to trigger another BC the chirp start pad to be configured to O/P mode.
3. BC_TE_EnableChirp must be called before trigger chirp for external trigger mode.
 
@see TE_ChirpTrgMode_t
@see BC_CC_ConfigPad
@see BC_CC_EnDisClrInt
@see BC_TE_SetMCUPadConfig
@see BC_TE_EnableChirp
 
@param[in] pChirpTrgMode pointer to the chirp trigger mode config structure
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_SetChirpTrgMode(TE_ChirpTrgMode_t *pChirpTrgMode);


/**
@brief This API starts chirp
 
RSNum:1447767, 2547544, 1616522
 
# Description
This API starts chirp as per the configuration.
 
@see TE_ChirpTrgMode_t
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_StartChirp(void);


/** 
@brief This API enables the chirp engine.
 
RSNum:1456436
 
# Description
This API enables the chirp engine to make it ready to take a start chirp command.
 
## Note
1. This API needs to be called to enable chirp if external trigger is selected.
 
@param[in] Enable 0/FALSE: chirp engine is disabled; 1/TRUE: chirp engine is enabled.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_EnableChirp(BOOL Enable);


/**
@brief This API waits for the chirp sequence to finish.
 
RSNum:1447767, 2547545, 1616522, 
 
# Description
This API waits for the chirp sequence to finish as per the mode selected by polling for the completion of chirp sequence.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_WaitForReady(void);


/**
@brief This API loads the selected profile or profile list.
 
RSNum:1448226, 1448227
 
# Description
This API loads the selected profile or a random profile or the profiles in sequence as per the profile list.
 
@see BC_TE_ConfigProfileSequencing
@see SYS_ProfID_e
 
@param[in] ChirpProfSel Chirp profile selection value
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_LoadProfile(SYS_ProfID_e ChirpProfSel);


/**
@brief This API configures different RX filter controls
 
RSNum:1456440
 
# Description
This API configures RX filter controls
1.  RX HPF reset deassertion reference point and its delay from the same
2.  RX filter enable reference point and its delay from the same
 
## Note
1. Delay for  HPFResetReleaseDelay  and RxActiveDelay should be from T2,
2. RxActiveDelay = 0.025us and HPFResetReleaseDelay = 1us is recommended values
3. The order of switching should be TxBpsAndTransmissionEnTimeProfile0, then RxActiveDelay and then HPFResetReleaseDelay
 
@param[in] HPFResetReleaseCtrl HPF reset deassertion reference point  0/FALSE: Tdwell(T1), 1/TRUE: Tsettle(T2)
@param[in] RxActiveCtrl RX filter reset reference point 0/FALSE: Tdwell(T1), 1/TRUE: Tsettle(T2)
@param[in] HPFResetReleaseDelay Delay in us, from the reference point for the HPF release deassertion.
@param[in] RxActiveDelay Delay in us, from the reference point for the RX filter activation
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_SetRxFilterCtrls(BOOL HPFResetReleaseCtrl, BOOL RxActiveCtrl, float32_t HPFResetReleaseDelay, float32_t RxActiveDelay);


/**
@brief This API configures static parameters for TE
 
RSNum:1456433
 
# Description
This API configures static parameters DC power On delay, TX RX group delay, Jumpback time, Chirp sequence interval, Number of chirp in a sequence & Number of sequence in a burst for TE.
A check is performed on these parameters verifying that they are within a valid range and/or with a valid value. If any of the values are invalid, an error is returned.
The DC Power On Delay should be higher or equal than TX and RX group delays. The allowed values for the DC Power On Delay is 10us to 1638.35us. 
The allowed values for the jumpback time is 0.025us to 6.35us.
The allowed values for the chirp sequence interval is 0.025us to 107374.18ms.
The allowed values for the number of chirp in a sequence is 0x01 to 0xFFFE.
The allowed values for the number of sequence in a burst is 0x01 to 0xFFFFFFFE.

@see TE_StaticConfig_t
 
@param[in] pStaticConfig Static configuration structure of TE
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_ConfigStatic(TE_StaticConfig_t *pStaticConfig);


/**
@brief This API controls final phase code generation
 
RSNum:1445693, 1446592, 1456429, 1446593, 1445695, 1445698 
 
# Description
 
This API controls the final phase code generation by configuring
1. Source of the BPSK control and
2. Modes of sampling of BPSK IO and QPSK IO
3. Final phase code generation method: No change to initial phase code (PC) or replace two MSB bits of PC with QPSK[1:0] or add QPSK[1:0] to the two MSB bits of PC.
 
## Note
1. Arrays of 3 for the three TX instances.
 
@see TE_PRPCGenMode_e
 
@param[in] pEnBPCtrlFromQPSKIO BPSK control 0/FALSE: From profile (TE); 1/TRUE: From QPSK[0] IO pin
@param[in] EnAsyncBPSKSamp Sampling mode of BPSK IO. 0/FALSE: Synchronous; 1/TRUE: Asynchronous
@param[in] EnAsyncQPSKSamp Sampling mode of QPSK IO. 0/FALSE: Synchronous; 1/TRUE: Asynchronous
@param[in] pFinalPCGenMode  Generating final phase case from initial phase code - With no change (or) replace two MBS bits with QPSK (or) add QPSK to two MSB bits
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_SetPhaseCtrls(BOOL pEnBPCtrlFromQPSKIO[3], BOOL EnAsyncBPSKSamp, BOOL EnAsyncQPSKSamp, TE_PRPCGenMode_e pFinalPCGenMode[3]);


/**
@brief This API updates timing information of a profile
 
RSNum:1446589, 1445694, 1445692, 1445696 
 
# Description
 
This API updates timing information of a profile
 
## Note
1. Dwell time value varies with application usage. e.g. In case of dynamic power down per chirp(for Tx, Rx and chirp module) dwell time value should be more than 5us.
2. Dwell time minimum value is 200ns if SWEEP_DIV_RST_CONTROL-> sweep_div_rst_enable_chirp/sweep_div_rst_enable_frame is not set
3. Dwell time minimum value should be greater than SWEEP_DIV_RST_CONTROL-> sweep_div_rst_delay if SWEEP_DIV_RST_CONTROL-> sweep_div_rst_enable_chirp/sweep_div_rst_enable_frame is set
4. For details of dwell time setting refer bit field "TIMING_CONTROL_1_PROFILE0->DwellTimeProfile0" description.
5. Lower dwell time might not get good performance.
 
@see SYS_ProfID_e
 
@param[in] ProfileNum Profile in which update is needed
@param[in] DwellTime Dwell time in us. Recommended value for DwellTime is 1.25us.
@param[in] TxOnDelayFromRefPoint Transmission on delay from timing reference point in us
@param[in] TrigPoint  Trigger point (timing reference point). 0/FALSE: Trigger point is start of Tdwell; 1/FALSE: Trigger point is start of Tsettle
@param[in] pBPPhaseCtrlTx Array of binary phase controls for TXs. 0/FALSE: in phase ; 1/TRUE: out of phase.
@param[in] pEnTx:  Array of transmission control for TXs. 0/FALSE: Transmission disabled; 1/TRUE: Transmission enabled.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TE_UpdateProfTiming(SYS_ProfID_e ProfileNum, float32_t DwellTime, float32_t TxOnDelayFromRefPoint, BOOL TrigPoint, BOOL pBPPhaseCtrlTx[3], BOOL pEnTx[3]);


/**
@brief This API updates settle time and number of samples of a profile
 
RSNum:1446589
 
# Description
This API updates settle time and number of samples of a profile
 
## Note
1. The output sample rate depends on the ADC sampling frequency mode. So, the related API has to be called prior to this API.
 
@see SYS_ProfID_e
@see TE_OutputSampRate_e
 
@param[in] ProfileNum Profile in which update is needed
@param[in] PDCBWWide Bandwidth of PDC decimation filter. 0/FALSE: Narrow; 1/TRUE: Wide
@param[in] NumSamples: Number of ADC samples
@param[in] SettleTime : Settle time in us
@param[in] OutSampRate: Output sample rate, which depends on ADC sampling mode.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TE_UpdateProfADC(SYS_ProfID_e ProfileNum, BOOL PDCBWWide, uint16_t NumSamples, float32_t SettleTime, TE_OutputSampRate_e OutSampRate);


/**
@brief This API updates TX PR phase shift values of a profile
 
RSNum:1445703, 1445696 
 
# Description
This API updates the TX PR phase shift values of a profile
 
## Note
1. The phase shift values will be rounded to nearest multiple of 5.625 degrees.
2. Only positive phase shift values are supported.
 
@see SYS_ProfID_e
@see SYS_VCN_e
 
@param[in] ProfileNum Profile in which update is needed
@param[in] pPRPhaseCtrlTx  Array of new PR phase shift values for the TXs respectively, in degrees.
@param[in] VirtualChNo Virtual channel number, applicable for CSI2 interface only.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TE_UpdateProfPRCtrl(SYS_ProfID_e ProfileNum, float32_t pPRPhaseCtrlTx[3], SYS_VCN_e VirtualChNo);


/**
@brief This API sets the DC power-on delay and safety monitor activation on delay
 
RSNum:1456433
 
# Description
This API sets the DC power-on delay for TX, RX and chirp analog circuit in normal chirp mode and safety monitor activation on delay
 
## Note:
1. In power save mode, the DC power on delay value is not used and it is considered within the dwell time.  So dwell time should be minimum 10 us in power save mode.
 
@see BC_TE_ConfigStatic
 
@param[in] DCPowerOnDelay In normal mode the time delay in us, after the chirp trigger to provide DC power to TX, RX and chirp analog circuit.
@param[in] SafetyMontrDelay The time delay in us, for starting the safety monitoring from the reference point.
@param[in] SafetyMontrActCtrl  Safety monitoring activation control. 0/FALSE: Monitoring starts at the expiry of safety monitor delay timer; 1/TRUE: Monitoring starts at (settle time - safety monitor delay)
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TE_SetDCPowOnDelay(float32_t DCPowerOnDelay, float32_t SafetyMontrDelay, BOOL SafetyMontrActCtrl);


/**
@brief This API configures the TX and RX DC power on group delay values
 
RSNum:1456433, 1456440 
 
# Description
This API configures TX and RX DC power on group delay and their finer values.
 
## Note
1. Recommended values for application:  DC power on group delay value for TX 0.025 us and for RX 1us
2. Fine control is an array of 4. The first three values are for TX1/RX1, TX2/RX2, TX3/RX3 pairs respectively and forth value is for RX4. The recommended fine control values are 0us, 0.8us, 1.6us and 3.2us respectively.
 
@see BC_TE_SetDCPowOnDelay
@see BC_TE_ConfigStatic
 
@param[in] TXDCPowOnGrpDelay The DC power on delay in us, of all TX together from the chirp start trigger. Range 0.025 us to less than the DC power on delay
@param[in] RXDCPowOnGrpDelay The DC power on delay in us, of all RX together from the chirp start trigger. Range 0.025 us to less than the DC power on delay
@param[in] pFineControl The delays in us to enable TX and RX pairs in a staggered way to control the power fluctuations.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_ConfigTXRXDCGrpDelay(float32_t TXDCPowOnGrpDelay, float32_t RXDCPowOnGrpDelay, float32_t pFineControl[4]);


/**
@brief This API sets the jump back time
 
RSNum:1456433
 
# Description
This API set the jump back time after the active ADC sample acquisition and before resetting the chirp.
 
@see BC_TE_ConfigStatic
 
@param[in] JumpBackTime Jump back time in us.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_SetJumpBackTime(float32_t JumpBackTime);


/**
@brief This API sets the time gap between the chirp sequence.
 
RSNum:1456433
 
# Description
This API sets the time gap between the chirp sequence when the number of sequences is more than on.
 
@param[in] SeqInterval Duration of a chirp sequence in us. In case of burst mode, it also includes idle time between sequences.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TE_SetChirpSeqInterval(float32_t SeqInterval);


/**
@brief This API sets the bias switch controls
 
RSNum:1456433
 
# Description
This API controls fast bias switch and replica bias switch by enabling them and by setting their delay values.
 
@see BC_TE_ConfigStatic
 
@param[in] EnFastBiasSwitch Fast bias switch control. 0/FALSE: Fast bias not used; 1/TRUE: Fast switching is enabled
@param[in] FastBiasSwitchDelay Duration in us, of the fast switch closure from the chirp start.
@param[in] EnReplicaBiasBypass Replica bias circuit control. 0/FALSE: Replica bias is not bypassed; 1/TRUE Replica bias is bypassed for the programmed delay
@param[in] ReplicaBiasBypassDelay Delay duration in us, for the replica bias circuit in bypass.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TE_SetBiasSwitchCtrl(BOOL EnFastBiasSwitch, float32_t FastBiasSwitchDelay, BOOL EnReplicaBiasBypass, float32_t ReplicaBiasBypassDelay);


/**
@brief This API updates the chirp period of a profile
 
RSNum:1446589, 1445696 
 
# Description
This API updates the chirp period and enable/disable settings of RXs and TXs of a profile
 
@see SYS_ProfID_e
 
@param[in] ProfileNum Profile in which update is needed
@param[in] ChirpPeriod Chirp interval time in us.
@param[in] pActiveRx  Bool array for RXs control . 1/TRUE: RX is enabled; 0/FALSE: RX is disabled
@param[in] pActiveTx  Bool array for TXs control. 1/TRUE: TX is enabled; 0/FALSE: TX is disabled
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TE_UpdateProfChirpPeriod(SYS_ProfID_e ProfileNum, float32_t ChirpPeriod, BOOL pActiveRx[4], BOOL pActiveTx[3]);


/**
@brief This API configures profile sequence
 
RSNum:1445697, 1610912, 1456438
 
# Description
This API configures the profile sequence, profile list, repeat count, reset behavior and enables/disables the chirp engine. The profile selection can be a specific profile or a predefined sequence of profiles or the profiles as per the profile list.
 
@see SYS_ProfID_e
 
@param[in] ChirpProfSel  Chirp profile selection value
@param[in] pProfileList Profile list entries 0-7. Valid values 0-7.  With other values, no profile will be selected for this entry.
@param[in] ProfileRepeatCount Profile repeat count. Valid range: 0x01u to 0x7Fu
@param[in] EnProfileReset Profile reset behavior between chirp sequences. 0/FALSE: Start from the last active profile. 1/TRUE: Start afresh for new chirp sequence.
@param[in] EnChirp Chirp engine enable control. 0/FALSE: Chirp engine is inactive. 1/TRUE: Chirp engine is enabled and ready to take a start chirp command.
@param[in] PRSeed Initial seed value for pseudo random generation. Applicable only when ChirpProfSel is  e_TE_PROFILE_PSRB.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TE_ConfigProfileSequencing(SYS_ProfID_e ChirpProfSel, uint8_t pProfileList[8], uint8_t ProfileRepeatCount, BOOL EnProfileReset, BOOL EnChirp, uint16_t PRSeed);


/**
@brief  This API sets the chirp sequence control.
 
RSNum:1456433
 
# Description
This API sets the number of chirp sequences and the number of chirps within a sequence.
 
@see BC_TE_ConfigStatic
 
@param[in]  NumSeqInBurst Number of chirp sequences in a burst with a chirp start trigger. (Range 0x01u to 0xFEu) for ES1,
(Range 0x01u to 0xFFFFFFFEu) for ES2.
@param[in]  NumChirpInSeq Number of chirps within a chirp sequence (Range 0x0001u to 0xFFFEu).
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_SetChirpSeqCtrl(uint32_t NumSeqInBurst, uint16_t NumChirpInSeq);


/**
@brief This API configures DDMA ramp generator
 
RSNum:1456429, 1445698 
 
# Description
This API configures DDMA ramp generator mode, individual TXs initial phases, and phase step sizes.
 
## Note
1. The DDMA mode is common for the TXs which choose DDMA mode.
2. For DDMA phase code calculation we use 10bits so the resolution is increased to  0.3515625(360/1024), 
3. DDMA phase code calculation uses the 10bit which has, integer and fractional part. 6 MSBs are integer phase in steps of 5.625 degree, 4LSBs are fractional part.
4. Final phase calculation only uses  MSB 6 bits hence we will have output phase resolution of  360/64 = 5.625 degree only.
5. The phase starting point and increment both can be fractional, but at the end only the integer part is sent to the phase rotator. 
   Therefore using fractional increment does not result in fractional phase variation (this is limited by the capability of the phase rotator circuit),
   but results in phase code (integer part) to change not every chirp, but less often, resulting is "stair-like" shape of phase versus chirp number. 
   For example, using an increment value of 47.8125 degree ( phase code 0x88 or b00_1000_1000) results in phase values (assuming zero starting code)
   sent to phase rotator of 0 - 8 - 17 - 25 - 34 - 42... for chirps 1 - 2 - 3 - 4 - 5 this will result in chirp phase 0 - 45 - 95.625 - 140.625 - 191.25 degree.
6. When a TX  not using DDMA mode, its DDMA init phase and phase step values are 'do not care'.
7. When using QPSK I/O's for phase controls, corresponding settings to be done separately.
8. Only positive values are allowed for DDMAInitPhase and DDMAPhaseUpdate.
9. The phase of the first chirp in the sequence will be equal to pDDMAInitPhase when a reset_ddma(BC_TE_ResetTxPRDDMA) is applied before a chirp seqence
 
@see TE_DDMAMod_e
@see BC_TE_ResetTxPRDDMA

@param[in] pUseDDMA 0/FALSE: Use profile register, 1/TRUE: use DDMA
@param[in] DDMAMode DDMA mode selection.
@param[in] pDDMAInitPhase  Initial phase in degrees.
@param[in] pDDMAPhaseUpdate Phase step in degrees.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_SetPRDDMACtrls(BOOL pUseDDMA[3], TE_DDMAMod_e DDMAMode, float32_t pDDMAInitPhase[3], float32_t pDDMAPhaseUpdate[3]);


/**
@brief This API reset TxPR DDMA Mode phase.
 
RSNum:1445696
 
# Description
This API reset TxPR DDMA Mode phase.
This API can be used only for DDMA mode, this function reset the DDMA phase to start from the initial value.
 
@see BC_TE_SetPRDDMACtrls
@see BC_SYS_ConfigTXPR
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_ResetTxPRDDMA(void);


/**
@brief This API controls TX Phase Rotator safety checks
 
RSNum:1456440, 2483565
 
# Description
This API controls TX Phase Rotator safety checks:
1. By enabling or disabling the safety check with in (just after the last chirp) chirp sequence (frame)
2. By setting the start points of safety check when enabled, delay between last chirp and start of safety check.
 
## Note
1. This API is only supported in ES2 samples.
2. If safety check is enabled, this PRSafetyStartDelay should be added in SeqInterval time.  
3. Safety Check error can be get using BC_ISM_GetCalibrationStatus API.
4. If dynamic power mode is used, BC_CC_SetDynPowModeDown parameter PowDownDelayPerSequence should also add time required for PR Safety check.
 
@see TE_StaticConfig_t
@see BC_ISM_GetCalibrationStatus
@see BC_CC_SetDynPowModeDown
 
@param[in] EnPRSafetyCheck 0/FALSE: PR Safety check disabled; 1/TRUE: PR Safety check enabled.
@param[in] PRSafetyStartDelay Delay in us, at the end of the chirp sequence to start the safety check.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TE_TXPRSafetyCheckDelay(BOOL EnPRSafetyCheck, float32_t PRSafetyStartDelay);



#if defined(__cplusplus)
}
#endif
#endif
