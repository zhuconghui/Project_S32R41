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
@file hal_es2_cafc.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>21
*/

#ifndef HAL_ES2_CAFC_H
#define HAL_ES2_CAFC_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API reads built-in frequency counter after 26GHz signal is divided by the PLL dividers
 
RSNum:2547547
 
# Description
 
An API will be able to read Chirp PLL's frequency counter and return the value in the 26GHz range, with unit of Hz.
The frequency measurement is by default done without modifying any loop conditions (e.g. open/close loop, forced dividers). If user wants to measure the frequency under specified loop conditions, use HAL_ESx_CAFC_ForceLoopConditions before calling this API.
 
@see BC_CAFC_ForceLoopConditions
 
@param[in] CntDurationMicroSec Specify counter counting duration in us, this will influence measurement accuracy, the longer you measure, the more accurate the result is. Frequently used values: 10us -100us
@param[out] pRawFreqResultHz Raw frequency measurement result at the frequency counter, after the full divider chain in PLL, in the range of 4xxMHz, unit in Hz
@param[out] pRFFreqResultHz Frequency measurement result, multiplied by the full divider values, as CAFC RF output, in the range of 26GHz, unit in Hz
@param[in] ProfID Choose which profile's PLL divider value to use. This input will NOT be considered if PLL divider is forced in CAFC. This API will check if the divider is force or not.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_ReadFreqCounter(float32_t CntDurationMicroSec, float32_t *pRawFreqResultHz, float32_t *pRFFreqResultHz, SYS_ProfID_e ProfID);


/**
@brief This API disables the AAFC and forces the PLL loop condition manually
 
RSNum:1456434, 2547547
 
# Description
 
An API will be able to force CAFC PLL loop conditions. It's good to first disable AAFC using API HAL_ESx_CAFC_ConfigAAFC
 
@see BC_CAFC_ConfigAAFC
 
@param[in] EnableLoopFilter TRUE: enable loop filter, FALSE: disable(disconnect) loop filter
@param[in] ForcedDACCode Choose forced DAC code from 0-128 (this will also enable the Vtune forcing using DAC); Use 128 if user does not want to force a code (this will also disable the Vtune forcing)
@param[in] ProfID Profile to be configured, VCO selection and subband are in profile registers.
@param[in] VCOBWSel Choose from 1G, 5G narrow band (2GHz) or 5G wide band (4GHz) VCO
@param[in] Subband Choose subband from 0-127; Use 128 if user wants to keep current subband number in the register unchanged
@param[in] ForcedDividerValue Forced PLL fractional divider value, in decimal number, e.g. 27.345(this action will also enable divider force). This number will be translated to integer and fractional part and write to corresponding registers; Use 0 if user does not want to force a divider value.(this will also cancel the divider force). When this number is an integer(e.g. 28), the force will be done using CAFC, when this number is an decimal number, the force is done via SC. Use 1 if user wants to keep current divider force settings untouched (neither force nor cancel force)
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_ForceLoopConditions(BOOL EnableLoopFilter, uint8_t ForcedDACCode, SYS_ProfID_e ProfID, CAFC_VCOBWSel_e VCOBWSel, uint8_t Subband, float32_t ForcedDividerValue);


/**
@brief This API will generate VCO subband frequency table with AAFC disabled
 
RSNum:2547547
 
# Description
 
An API will measure all VCO subband frequency boundaries (FBegin, FEnd) and create a full table in a global array for later use. This is a manual measurement function with AAFC disabled.
The global will include FBegin, FEnd, BW.
StartSB starts from 0.
 
@param[in] VCOBWSel Choose from 1G, 5G narrow band (2GHz) or 5G wide band (4GHz) VCO
@param[in] HighDACCode DAC code to be forced when measuring the higher frequency boundary of a subband
@param[in] LowDACCode DAC code to be forced when measuring the lower frequency boundary of a subband
@param[in] StartSB Starting subband number to be measured, first subband is subband 0
@param[in] NumItems Number of subbands user wants to measure in total, e.g. if StartSB is 4, NumItems is 5, then subband 4,5,6,7,8 will be measured.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_GenSBTable(CAFC_VCOBWSel_e VCOBWSel, uint8_t HighDACCode, uint8_t LowDACCode, uint8_t StartSB, uint8_t NumItems);


/**
@brief This API returns the full VCO table of user's choice
 
RSNum:2547547
 
# Description
 
This API will return the full VCO table, with subband begin frequency, end frequency and total bandwidth. Before using this API, user should use HAL_ESx_CAFC_GenSBTable to first generate the table. This API returns always the full table with 128 subbands. The data returned for unmeasured subbands will always be 0.
 
## Note
1. BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
 
@param[in] VCOBWSel Choose from 1G, 5G narrow band (2GHz) or 5G wide band (5GHz) VCO
@param[out] pFBegin Begin frequency array, length must be 128
@param[out] pFEnd End frequency array, length must be 128
@param[out] pBW Total used bandwidth array, length must be 128
 
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_GetSBTable(CAFC_VCOBWSel_e VCOBWSel, BC_FLOAT pFBegin[128], BC_FLOAT pFEnd[128], BC_FLOAT pBW[128]);


/**
@brief This API enables/disables VCO
 
RSNum:1456431
 
# Description
 
An API will enable/disable the VCOs.
Related registers: LPF_ADDITIONAL_SETTINGS
 
@param[in] Enable Enable(TRUE) or disable(FALSE) VCO
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_EnableVCO(BOOL Enable);


/**
@brief This API configures CAFC PLL loop filter
 
RSNum:1456434
 
# Description
 
An API will configure loop filter related settings according to user selected entry in the selected LoopFilterLUT.
The LoopFilterLUT is a const static precomputed table which contains various settings for different loop bandwidth. There are multiple LoopFilterLUTs, e.g. for 1GHz VCO and 5GHz VCO(narrow and wide band)
This API will also perform necessary compensation (e.g. KVCO) according to EffFc.
For ES2 this API also sets the Lock detectors setting based on the, Chirp Polarity ( DownChirp) and the VCO used LPFLUTSel.
Since these setting are common for all the profiles the last written value will be used.
If application is using the Different VCO and chirp polarity, for different sequence,
application need to change set the appropriate LD settings by using BC_CAFC_ConfigMonitor API.
This API will also updates initial override value is based on the VCO type, for 1G we start search from the SB 60. For 4G VCO and 2G VCO sub band search start from 30.
 
## Note
1. BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
2. For ES1, 1G VCO PLL Loop BW starts from 200kHz and ends at 1600kHz mode. For ES2, 1G VCO PLL Loop BW starts from 200kHz and ends at 2400kHz mode.
3. For ES1, 2G VCO starts from 250kHz  and ends at 1650kHz. For ES2, 2G VCO starts from 250kHz  and ends at 2400 kHz.
4. For ES1, 4G VCO PLL Loop BW starts from 300kHz  and ends at 1700kHz. For ES2, 4G VCO PLL Loop BW starts from 300kHz  and ends at 2800kHz.
5. PLL BW to be provided in multiples of 50kHz. For the values other than multiples of 50kHz will be rounded off to the nearest multiple of 50kHz BW.
6. For ES1, DownChirp parameter is not used by API.
7. This API set the LD setting base in chirp and VCO types, For 4GVCO chirp bandwidth less than 1000MHz, setting might not work user need to increase the Window offset using BC_CAFC_ConfigMonitor API .
8. Use of gear shifting and injection DAC to speed up the return time is by default compatible with chirp PLL loop bandwidth (up to and including 300kHz for 1G and 2G, and 350kHz for 4G). For a higher loop bandwidth, the loop is fast enough to achieve fast rerun times and Gear shifting and iDAC should be disabled.
 
@see CAFC_LoopFilterLUTSel_e
@see BC_CAFC_ConfigMonitor
 
 
@param[in] PLLLPFSel The PLL LPF setting item to select. Note that there are 4 entries for PLL LPF settings, while there are 9 individual profiles, they are connected by CAFC VCO profile setting.
@param[in] LPFLUTSel Choose which loop filter setting LUT table to be used
@param[in] PLLLoopBW PLL Loop bandwidth in Hz.
@param[in] EffFc Effective center frequency of the chirp, this will be used to perform loop gain compensation.
@param[in] DownChirp Type of chirp 0/FALSE: Positive chirp; 1/TRUE: Negative chirp.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_ConfigLoopFilter(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, BC_FLOAT EffFc, BOOL DownChirp);


/**
@brief This API updates CAFC PLL loop filter charge pump settings
 
RSNum:1456434
 
# Description
 
An API will update loop filter charge pump settings that vary with temperature.
The LoopFilterLUT is a const static precomputed table which contains various settings for different loop bandwidth. There are multiple LoopFilterLUTs, e.g. for 1GHz VCO and 5GHz VCO(narrow and wide band)
This API will also perform necessary compensation (e.g. KVCO) according to EffFc.
 
## Note
1. BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
2. For 1G VCO PLL Loop BW starts from 200kHz and ends at 2400kHz mode.
3. For 2G VCO starts from 250kHz  and ends at 2400kHz,
4. For 4G VCO PLL Loop BW starts from 300kHz  and ends at 2800kHz.
5. PLL BW to be provided in multiples of 50kHz. For the values other than multiples of 50kHz will be rounded off to the nearest multiple of 50kHz BW.
6. It is recommended to call this API after BC_CAFC_CalibAAFCInjDAC in every radar cycle to achieve optimal phase noise performance.
7. This API is only supported for ES2 samples
8. Since this calibration is performed in CW calibration mode the Chirp module IP should be out of Dynamic powering saving mode(Disable dynamic power down mode)..
 
@see CAFC_LoopFilterLUTSel_e
@see BC_CAFC_CalibAAFCInjDAC
 
@param[in] PLLLPFSel The PLL LPF setting item to select. Note that there are 4 entries for PLL LPF settings, while there are 9 individual profiles, they are connected by CAFC VCO profile setting.
@param[in] LPFLUTSel Choose which loop filter setting LUT table to be used
@param[in] PLLLoopBW PLL Loop bandwidth in Hz.
@param[in] KvcoAverage The Kvco average count value calculated and returned as an output in BC_CAFC_CalibAAFCInjDAC. If this param is input as 0, then KvcoAverage read from KVCO_COUNT_STATUS register, this will increase one SPI read operation.
@param[in] DownChirp Type of chirp 0/FALSE: Positive chirp; 1/TRUE: Negative chirp.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_UpdateLoopFilterCP(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, float32_t KvcoAverage, BOOL DownChirp);


/**
@brief This API returns one entry from the user selected loop filter LUT table
 
RSNum:1456434
 
# Description
 
This API returns one entry from the user selected loop filter LUT table
 
## Note
1. For ES1, 1G VCO PLL Loop BW starts from 200kHz and ends at 1600kHz mode. For ES2, 1G VCO PLL Loop BW starts from 200kHz and ends at 2400kHz mode.
2. For ES1, 2G VCO starts from 250kHz  and ends at 1650kHz. For ES2, 2G VCO starts from 250kHz  and ends at 2400 kHz.
3. For ES1, 4G VCO PLL Loop BW starts from 300kHz  and ends at 1700kHz. For ES2, 4G VCO PLL Loop BW starts from 300kHz  and ends at 2800kHz.
4. BW to be provided in multiples of 50kHz. For the values other than multiples of 50kHz will be rounded off to the nearest multiple of 50kHz BW.
 
@param[in] LPFLUTSel Choose which loop filter setting LUT table to be used
@param[in] PLLLoopBW PLL Loop bandwidth in Hz.
@param[out] pTableEntry Returned data for that entry
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE HAL_ES2_CAFC_GetLoopFilterEntry(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, CAFC_LPFLUTEntry_t *pTableEntry);


/**
@brief This API configures VCO settings for a chosen profile
 
RSNum:1456419
 
# Description
 
This API configures for the selected profile, which VCO (and narrow/wide band if 5GHz VCO is selected), which PLL LPF filter settings to use and allow user to choose to force iVCOFine and subband or use automatic calibration.
 
@param[in] ProfID The profile ID to be programmed.
@param[in] VCOSel VCO selection, 5GHz VCO has two mode (4GHz, 2GHz), and 1GHz VCO
@param[in] PLLLPFSel Choose one of the 4 PLL LPF settings, these settings has to be pre-configured using BC_CAFC_ConfigLoopFilter.
@param[in] iVCOFine The current that decide VCO output amplitude, if 64 or larger value is used, this setting will be kept untouched inside the API.
@param[in] Subband The subband which will be used in the selected profile, if 128 (or 64 when 4GHz VCO is used) or larger value is used, this setting will be kept untouched inside the API.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_ConfigVCOProfile(SYS_ProfID_e ProfID, CAFC_VCOBWSel_e VCOSel, CAFC_PLLLPFSel_e PLLLPFSel, uint8_t iVCOFine, uint8_t Subband);


/**
@brief This API configures detail setting for CAFC fast return features
 
RSNum:1456428
 
# Description
 
An API will configure chirp fast return related(timing) settings. This API is called only once before profile settings.
 
## Note
1. Detailed settings are done by this API internally. 
2. Use of gear shifting and injection DAC to speed up the return time is by default compatible with chirp PLL loop bandwidth (up to and including 300kHz for 1G and 2G, and 350kHz for 4G). For a higher loop bandwidth, the loop is fast enough to achieve fast rerun times and Gear shifting and iDAC should be disabled.
 
@param[in] EnableGS CAFC FastReturn mechanism control: Enable(TRUE) or disable(FALSE) Gear Switching (including switching LPF capacitors and switching of CP current slice).
@param[in] EnableINJ CAFC FastReturn mechanism control: Enable(TRUE) or disable(FALSE) Current Injection
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_ConfigFastReturn(BOOL EnableGS, BOOL EnableINJ);


/**
@brief This API configures static settings of CAFC
 
RSNum:1456430
 
# Description
 
An API will configure static settings for CAFC. Static settings means settings that are (most of the time) configured once and not changed during the whole application.
 
@param[in] EnableCP Enable(TRUE) or disable charge pump
@param[in] EnableVCOLDO Enable(TRUE) or disable VCO LDO
@param[in] EnableDividerLDO Enable(TRUE) or disable divider LDO
@param[in] EnableCPPFDLDO Enable(TRUE) or disable CPPFD LDO
@param[in] EnableAllBias Enable(TRUE) or disable all bias of CAFC
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_ConfigStatic(BOOL EnableCP, BOOL EnableVCOLDO, BOOL EnableDividerLDO, BOOL EnableCPPFDLDO, BOOL EnableAllBias);


/**
@brief This API configures CAFC functional safety monitors
 
RSNum:1456117, 1447767
 
# Description
 
An API will enable/disable amplitude monitor and lock detector in CAFC
These 2 monitors are not profile based, so they are also static configuration.
 
## Note
1. LockDetWinSize parameter is only used by ES1 sample.
2. For ES2 DownChirp/NegativeChirp the use lock detector polarity positive, for UpChirp/PositiveChirp use lock detector polarity negative.
 
@param[in] EnableAmpMon Enable(TRUE) or disable VCO amplitude monitor
@param[in] EnableLockDet Enable(TRUE) or disable PLL lock detector
@param[in] pLockDetSettings Detailed lock detector settings.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_ConfigMonitor(BOOL EnableAmpMon, BOOL EnableLockDet, CAFC_LockDetSettings *pLockDetSettings);


/**
@brief This API configs CAFC Automatic Amplitude and Frequency Control function
 
RSNum:1456419
 
# Description
An API will be able to enable/disable AFC and AAC feature and configure detailed settings of AAFC.
- Related registers:
 -- CHIRP_CALIBRATION_AAC_CONTROL1/2,
 -- CHIRP_CALIBRATION_AFC_CONTROL1/2
 
## Note
1. EnableAAFC parameter is only used by ES1 sample.
 
@param[in] EnableAAFC Enable(TRUE) or disable AAFC (AFC and AAC together, cannot separate, only used by ES1)
@param[in] pAACSettings Detailed AAC settings, see the type definition
@param[in] pAFCSettings Detailed AFC settings, see the type definition.
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_ConfigAAFC(BOOL EnableAAFC, CAFC_AACSettings_t *pAACSettings, CAFC_AFCSettings_t *pAFCSettings);


/**
@brief This API checks the CAFC Automatic Amplitude and Frequency Control status
 
RSNum:1448224
 
# Description
An API will be able to check AAFC status to output if AAC and AFC lock is achieved and if there is any error in the process. It will also report the resulted subband and VCO current selected by the AAFC.
 
@param[out] pAACLocked Report if AAC loop is locked(TRUE) or not.
@param[out] pAFCLocked Report if AFC loop is locked(TRUE) or not.
@param[out] pAACError Report if AAC loop has an error(TRUE) or not
@param[out] pAFCError Report if AFC loop has an error(TRUE) or not
@param[out] pAFCSubbandChoice Report AFC selected subband number
@param[out] pAACiVCOChoice Report AAC selected VCO current
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_GetAAFCStatus(BOOL *pAACLocked, BOOL *pAFCLocked, BOOL *pAACError, BOOL *pAFCError, uint8_t *pAFCSubbandChoice, uint8_t *pAACiVCOChoice);


/**
@brief This API enable CAFC output RF level RMS detector
 
RSNum:1456117, 1456419
 
# Description
 
An API will enable/disable the RMS detector for CAFC RF level.
An API will select the RMS detector based on VCO selected.
 
@param[in] EnRMSDet Enable(TRUE) or disable RMS detector
@param[in] VCOSel VCO selection, 5GHz VCO has two mode (4GHz, 2GHz), and 1GHz VCO
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_EnableRFLevelRMSDet(BOOL EnRMSDet, CAFC_VCOBWSel_e VCOSel);


/**
@brief This API will to Set force Vtune voltage
 
RSNum:1456432
 
# Description
 
An API will be able to set the force Vtune voltage for start and frequency center 
- Related register:
-- LPF_ENABLE_SETTINGS
 
## Note
1. Relation between code and voltage, Voltage(mv) = 8.59(mv) * ForceVtuneStartVolt/ ForceVtuneCenterVolt
2. Vtune is reverse of the Fos (frequency oscillator)
 
@param[in] ForceVtuneStartVolt  code for force Vtune voltage of start/edge frequency Range[0 - 0x7F]. Recommended value is 103.
@param[in] ForceVtuneCenterVolt code for force Vtune voltage of center frequency, Range[0 - 0x7F]. Recommended value is 64
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_CAFC_SetVtuneVoltage(uint8_t ForceVtuneStartVolt, uint8_t ForceVtuneCenterVolt);


/**
@brief This API get VCO calibration status.
RSNum:1448224
# Description
An API will be able to check AAFC status to output if AAC and AFC lock is achieved and if there is any error in the process.
It will also report the resulted sub-band and VCO current selected by the AAFC.
An API will be able to check KVCO error status with KVCO high and low value.
An API will be able to check DVDT error status with DVDT C1 count.
- Related registers:
-- AAFC_LOCK_DVDT_COUNT_STATUS, KVCO_COUNT_STATUS, CHIRP_CALIBRATION_STATUS.
 
## Note
1. This API is only supported for ES2 samples.
 
@param[out] pAAFCStatus structure for AAF Calibration status
@param[out] pKVCOStatus structure for KVCO measurement status
@param[out] pDVDTStatus structure for DVDT measurement status
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_CAFC_GetVCOCalibStatus(CAFC_AAFCStatus_t *pAAFCStatus, CAFC_KVCOStatus_t *pKVCOStatus, CAFC_DVDTStatus_t *pDVDTStatus);


/**
@brief This API trigger Chirp module calibration and corrections.
RSNum:1448225, 1448224, 
# Description
An API will be able to trigger the AAF calibration together with KVCO and DVDT measurement.  
An API will be able to check AAFC, KVCO and DVDT error status.
On success full calibration of the calibration API will copy the calibrated values to selected profiles.
An API will also store  sub-band,  VCO current, calculated Injection DAC acquisition(C1,C2,C3)  and calculated Injection DAC reset (C1,C2,C3) to selected profile.
An API will also retune the KVCOAverage value, in case of KVCO and DVDT is performed.
This API will also perform correction logic. Sub-band jump is added, for 1G and 2G in case of subband 64 is skipped based on OTP subband Correction and for 4G in case of subband 32 is skipped based on OTP Subband Correction.
if ((VCO == 1G ) and (subband == 64)) then subband = 64 + skip1g_64
if ((VCO == 2G ) and (subband == 64)) then subband = 64 + skip2g_64
If (VCO = 4G) and (subband = 32) then subband = 32 + skip4g_32          
- Related registers:
-- CHIRP_CALIBRATION_SW_CONTROL, AAFC_LOCK_DVDT_COUNT_STATUS, KVCO_COUNT_STATUS, LPF_INJ_ACQ_RST_COMMON.
 
## Note
1. This API is only supported for ES2 samples.
2. This API will replacement of ES1 API   BC_SYS_ConfigAAFCSearchHW and BC_CAFC_CalibrateInjCurr API
3. AAFC is performed first on calling this API.
4. Calibration sequence is AAFC then KVCO then DVDT
5. Injection DAC acquisition Value will be calculated and stored only if both PerformKVCO  and PerformDVDT parameters are TRUE.
6. In case of both PerformKVCO and/or PerformDVDT variable is TRUE, CalibTimeOutUs can be set to lesser value since effective delay will be 3 SPI read operations time plus CalibTimeOutUs. 
 
@see BC_CAFC_SetVCOCalibTimeOut
@see BC_CAFC_UpdateLoopFilterCP
 
@param[in] PerformKVCO  TRUE trigger the KVCO measurement, FALSE no KVCO measurement  
@param[in] PerformDVDT TRUE trigger the DVDT measurement, FALSE no DVDT measurement
@param[in] pChirpFreq Chirp profile frequency parameter, @see SYS_ProfChirpFreq_t. This parameter can be set to NULL if any one or both PerformKVCO and/or PerformDVDT variables are FALSE.
@param[in] pChirpTiming Chirp profile timing parameters, @see SYS_ProfChirpTiming_t. This parameter can be set to NULL if any one or both PerformKVCO and/or PerformDVDT variables are FALSE.
@param[in] CalibrateProfID  ProfileID used for calibration valid input e_SYS_PROFILE_0 to e_SYS_PROFILE_8
@param[in] pStoreInProfiles structure for storing the calibration results, TRUE profile register will updated  with calibrated values, FALSE no update on particular profile.
@param[in] CalibTimeOutUs  VCO timeout value after the start of VCO calibration, default value is 200us, value should be same as set by  BC_CAFC_SetVCOCalibTimeOut API.
@param[in] TempKelvinChirp special value 0.0f this parameter is ignored no subband search start point calculation, other value this temperature is used to calculate the subband search start point, temperature in unit of Kelvin
@param[out] pKvcoAverage Kvco average count value. This parameter can be set to NULL if BC_CAFC_UpdateLoopFilterCP is not called within radar cycle. This parameter is update only if both PerformKVCO and PerformDVDT variable is TRUE.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_CAFC_CalibAAFCInjDAC(BOOL PerformKVCO, BOOL PerformDVDT, SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfID_e CalibrateProfID, SYS_StoreInProfile_t *pStoreInProfiles, float32_t CalibTimeOutUs, float32_t TempKelvinChirp, float32_t *pKvcoAverage);


/**
@brief This API set Chirp calibration timeout.
RSNum:1456419
# Description
An API will be able to set the VCO calibration timeout.
An API will set the one timeout for all three calibration AAFC, KVCO and DVDT  for all thre calibration  delay  trigger  
The timeout counter is used only when the chirp is in cw mode and chirp aafc calibration is triggered.
- Related registers:
-- CHIRP_CALIBRATION_TIMEOUT_DELAY.
 
## Note
1. This API is only supported for ES2 samples.
2. This is the wait time for state matching for the AAF calibration together with KVCO and DVDT measurement.
 
@see BC_CAFC_CalibAAFCInjDAC
 
@param[in] CalibTimeOutUs  VCO timeout value after the start of AAFC and InjDAC calibration, default value is 200us, same value should be used for  BC_CAFC_CalibAAFCInjDAC API.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_SetVCOCalibTimeOut(float32_t CalibTimeOutUs);


/**
@brief This API loads the selected profile without changing the CHIRP_GLOBAL_CONTROL register.
RSNum:1448226, 1448227, 1448224
# Description
An API will loads the selected profile without updating the CHIRP_GLOBAL_CONTROL register.
An API will use the CAFC register to load the profile.
This is a Software based profile load for loading the profile information in Chirp TX and RX for Calibration.
Based on the profile_load_sw trigger use_profile_for_caibration is selected in the profile sequencer to generate the active profile value.
once it is triggered the ChirpProfSel will be active till the chirp start.
- Related registers:
 -- CHIRP_CALIBRATION_SW_CONTROL.
 
## Note
1. This API is only supported for ES2 samples.
2. This API will not update the CHIRP_GLOBAL_CONTROL register.
3. This is an optimize API to load profile .
 
@param[in] ChirpProfSel profile to load the information for Tx and Rx calibration               
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_LoadProfile(SYS_ProfID_e ChirpProfSel);


/**
@brief This API bias to Chirp PLL instantly.  
 
RSNum:1447766, 1616515
 
# Description
 
An API will bias the chirp PLL instantly by toggling the ctl_ibias_speed_up.
This API is needed only in case if Chirp module is disabled the dynamic power mode and in next step we are not performing the Chirp AAFC calibration.
 
## Note
1. This API is only needed if the Chirp module dynamic power mode is disabled and chirp AAFC is not performed in the next step.
2. In the case of Chirp AAFC (BC_CAFC_CalibAAFCInjDAC) and Chirp triggered, Fast biasing of chirp PLL is done by the internal hardware state machine.
3. This API should be used only in CW mode.
4. This API is needed in case the chirp module is waking up from dynamic power mode and we want to fast bias the chirp PLL, without using the Chirp AAF calibration.
 
@see BC_CC_SetDynPowModeDown
@see BC_CAFC_CalibAAFCInjDAC
 
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_CAFC_FastBiasChirpPll(void);



#if defined(__cplusplus)
}
#endif
#endif
