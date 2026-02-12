/*
    Copyright 2022 - 2023 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only be
    used strictly in accordance with the applicable license terms. By expressly
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be
    bound by the applicable license terms, then you may not retain, install,
    activate or otherwise use the software.
 */


/******************************************************************************
 *   Project              : RFE_abstract 2.0
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_ERROR_COMMON_H
#define RFE_ERROR_COMMON_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
*   @addtogroup rsdk_rfe_const
*   @{
*
*/

/******************************************************************************
 *                              DEFINITIONS
 *****************************************************************************/
/**
 * This macro defines the start of RFE-Fw Internal Errors.
 */
#define RFE_ERROR_RFE_INTERNAL_ERROR_BIT                    (1UL<<24u)

/**
 * This macro defines the maximum number of R1 FUSA errors.
 */
#define RFE_FUSA_R1_FAULT_COUNT_MAX                         (29UL) /* TODO: Exact count needs to be updated once R1/R2 Fault classification is complete */

/**
 * This macro defines the maximum number of R2 FUSA faults.
 */
#define RFE_FUSA_R2_FAULT_COUNT_MAX                         (12UL) /* TODO: Exact count needs to be updated once R1/R2 Fault classification is complete */

/**
 * This macro defines the maximum number of R1, R2 FUSA faults.
 */
#define RFE_FUSA_R1_R2_FAULT_COUNT_MAX                      (RFE_FUSA_R1_FAULT_COUNT_MAX + RFE_FUSA_R2_FAULT_COUNT_MAX)

/**
 * This macro defines the number of bytes used in RFE-FW Configuration BLOB
 * for masking or unmasking the R1, R2 FuSa Faults of total 12 bytes.
 */
#define RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT         (12UL)

/**
*   @}
*   @addtogroup rsdk_rfe_interface
*   @{
*
*/

/******************************************************************************
 *                              ENUMS AND TYPEDEFS
 *****************************************************************************/
/**
 * All defined return error codes.
 */
typedef enum
{
    /** No error occurred */
    rfe_error_none_e = 0UL,
    /** RFE-Fw is unresponsive. */
    rfe_error_api_unresponsive_e = 1UL,
    /** Operation is not allowed if the rfeDriver is not synchronized with the RFE-Fw. */
    rfe_error_api_unsynchronized_e = 2UL,
    /** Operation is not allowed in this state. */
    rfe_error_api_operationNotAllowed_e = 3UL,
    /** RFE-Fw is busy. */
    rfe_error_api_busy_e = 4UL,
    /** API function argument has an invalid value. */
    rfe_error_api_invalidArgumentValue_e = 5UL,
    /** The configuration blob has an invalid size. */
    rfe_error_api_invalidConfigurationSize_e = 6UL,
    /** The configuration blob contains a parameter that has an invalid value. */
    rfe_error_api_invalidConfigurationParameterValue_e = 7UL,
    /** The dynamic table blob has an invalid size. */
    rfe_error_api_invalidDynamicTableSize_e = 8UL,
    /** The dynamic table contains an entry that has an invalid value. */
    rfe_error_api_invalidDynamicTableValue_e = 9UL,
    /** No updates were buffered using rfe_updateParam() or rfe_updateDynamicTable(). */
    rfe_error_api_noUpdatesBuffered_e = 10UL,
    /** Update count is exceeding #RFE_UPDATE_COUNT_MAX. */
    rfe_error_api_maxUpdateCountExceeded_e = 11UL,
    /** An update is already pending. Only 1 update per radar cycle is supported. */
    rfe_error_api_updateAlreadyPending_e = 12UL,
    /** Invalid parameter provided for update. */
    rfe_error_api_invalidParameterForUpdate_e = 13UL,
    /** Dynamic tables have not been configured. */
    rfe_error_api_dynamicTablesNotConfigured_e = 14UL,
    /** Given #rfeCfg_section_t section is not matching with the given parameter. */
    rfe_error_api_cfgSectionMismatch_external_e = 15UL,
    /** Given #rfeCfg_param_t is containing an invalid parameter size. */
    rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e = 16UL,
    /** The configured radar cycle time schedule is invalid. */
    rfe_error_api_invalidRadarCycleTimeSchedule_e = 17UL,
    /**
     * Configuration parameter cross-check failed:
     * The sum of \ref dwellTimeTicks and \ref settleTimeTicks of all chirp profiles used
     * in \ref chirpProfileSequence should be larger than 120 ticks (i.e. 3 microseconds)
     * if \ref dynamicUpdatesEnabled is true.
     */
    rfe_error_api_configParamCrossCheck_dwellSettleTimeTooShort_e = 19UL,
    /**
     * Configuration parameter cross-check failed:
     * The sum of \ref acquisitionTimeTicks, \ref jumpbackTimeTicks and \ref resetTimeTicks of all chirp profiles used
     * in \ref chirpProfileSequence should be larger than 200 ticks (i.e. 5 microseconds)
     * if \ref dynamicUpdatesEnabled is true.
     */
    rfe_error_api_configParamCrossCheck_acqJumpbackResetTimeTooShort_e = 20UL,
    /**
     * Configuration parameter cross-check failed:
     * \ref chirpIntervalTimeTicks should be larger than the sum of \ref dwellTimeTicks,
     * \ref settleTimeTicks, \ref acquisitionTimeTicks, \ref jumpbackTimeTicks, and \ref resetTimeTicks.
     */
    rfe_error_api_configParamCrossCheck_chirpIntervalTimeTooShort_e = 21UL,
    /**
     * Configuration parameter cross-check failed:
     * chirp sequences contains a chirp sequence that has not been configured.
     */
    rfe_error_api_configParamCrossCheck_unconfiguredChirpSequence_e = 22UL,
    /**
     * Configuration parameter cross-check failed:
     * \ref chirpProfileSequence contains a chirp profile that has not been configured.
     */
    rfe_error_api_configParamCrossCheck_unconfiguredChirpProfile_e = 23UL,
    /**
     * Configuration parameter cross-check failed:
     * \ref dynamicTableIndex refers to a dynamic table that has not been configured.
     */
    rfe_error_api_configParamCrossCheck_unconfiguredDynamicTable_e = 24UL,
    /** The configuration blob version is incompatible with the RFE-Fw */
    rfe_error_api_invalidConfigurationVersion_e = 25UL,
    /** Front End ID is invalid */
    rfe_error_api_invalidFrontendId_e = 26UL,
    /** API function not implemented yet
     * to be removed after all functions will be implemented */
    rfe_error_api_function_not_implemented_e = 27UL,
	/** Number of connected front ends cannot be set after the FSM start */
	rfe_error_api_fsm_was_started_e = 28UL,
	/** Invalid number of connected front ends  */
	rfe_error_api_invalid_num_frontends_e = 29UL,
	/** Invalid front ends configuration, e.g. multiple single TEF82xx  */
	rfe_error_api_invalid_frontends_conf_e = 30UL,
	/** The blob has a wrong CRC value and could be corrupted           */
    rfe_error_api_blob_crc_wrong_e = 31UL,

    /*
        CMD Interface Errors [EXTERNAL] 100-199
    */
    /** Invalid command id. */
    rfe_error_cmdInterface_invalidCmdId_e = 100UL,
    /** Invalid command length. */
    rfe_error_cmdInterface_invalidCmdLength_e = 101UL,
    /** Invalid command response Length. */
    rfe_error_cmdInterface_invalidRspLength_e = 102UL,
    /** Command has an invalid CRC. */
    rfe_error_cmdInterface_invalidCrc_e = 103UL,
    /** Response is not matching command. */
    rfe_error_cmdInterface_invalidResponse_e = 104UL,
    /** Invalid sequencing of configuration commands. */
    rfe_error_cmdInterface_invalidConfigCmdSequencing_e = 105UL,

    /* Shared Data Errors [EXTERNAL] 200-299 */
    /** Invalid shared data index. */
    rfe_error_sharedData_invalidIndex_e = 200UL,
    /** Shared data redundacy check failed. */
    rfe_error_sharedData_redundancyCheckFailed_e = 201UL,

    /*
       FW Internal Errors [INTERNAL]
    */
    /** RFE FuSa fault occurred, check rfe_getFuSaFault() */
    rfe_error_rfeFuSaFault_e = RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Undefined error */
    rfe_error_undefined_e = 1UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    rfe_error_rfeInErrorState_e = 9UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error due to invalid pointer */
    rfe_error_invalidPointer_e = 10UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because parameter is out of allowed range */
    rfe_error_parameterOutOfRange_e = 12UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    rfe_error_saturationInOperation_e = 13UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,           //!< Error due to a saturation in an arithmetic operation
    rfe_error_invalidSamplesNumber_e = 14UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,            //!< Error due to an invalid number of samples (not greater than zero)
    rfe_error_sharedMemoryAddresOverlapping_e = 15UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,   //<! Error indicating that two memory addresses are overlapping in system shared memory
    rfe_error_addressOutOfValidSharedMemory_e = 16UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,   //<! Error indicating that the provided address is out of shared memory boundaries
    rfe_error_unknown_ip_e = 17UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,                      //!< Unknwon IP selected
    rfe_error_1_e = 18UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,                               //!< Error ...
    rfe_error_2_e = 19UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,                               //!< Error ...
    rfe_error_3_e = 20UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,                               //!< Error ...
    rfe_error_cmdServerInternal_no_cmd_received_e = 21UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,         //!< A command was tried to be handled, but no command is available
    rfe_error_cmdServerDft_invalidParam_e = 22UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,           //!< An invalid parameter was received over the command interface
    rfe_error_cmdServerInternal_undefined_cmd_handler_e = 23UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,           //!< An undefined command was received
    rfe_error_cmdServerInternal_out_of_seq_e = 24UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,              //!< A command counter ouf ot sequence was received. This indicats loss of a command
    rfe_error_cmdServerInternal_resplen_wrong_e = 26UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,           //!< A function implementation returned an unexpected amount of result data
    rfe_error_cmdServerInternal_cmdbuf_overflow_e = 27UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,         //!< A function made the command or response buffer overflow
    rfe_error_utils_memcpy_range_error_e = 29UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,        //!< memcopy got dangerous pointers provided
    rfe_error_notAnExternalErrorCode_e = 31UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because operation is not allowed when rfe is uninitialized */
    rfe_error_uninitialized_e = 32UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that value for arithmetic shift is invalid*/
    rfe_error_invalidShiftingParam_e = 33UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    rfe_error_invalidFractionBits_e = 34UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT, //<! Error due to an invalid input of number of fraction bits
    rfe_error_nullPointer_e = 35UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,       //<! Error NULL pointer in inputs
    rfe_error_invalidValue_e = 36UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,       //<! Error invalid value in input data
    /** Error because not yet implemented */
    rfe_error_notYetImplemented_e = 37UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because of invalid FlexIO configuration */
    rfe_error_invalidFlexIOConfig_e = 38UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because of invalid RFE Access CSR configuration */
    rfe_error_invalidRfeAccessCsrConfig_e = 39UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because of failed Fault Injection Test FIT 1 procedure */
    rfe_error_fit1ProcedureFailed_e = 40UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because of failed Fault Injection Test FIT 2 procedure */
    rfe_error_fit2ProcedureFailed_e = 41UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because of failed Functional Integrity Check FIC 1 procedure */
    rfe_error_fic1ProcedureFailed_e = 42UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because of failed Functional Integrity Check FIC 2 procedure */
    rfe_error_fic2ProcedureFailed_e = 43UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that input vectors size do not fit in shared memory */
    rfe_error_noSpaceLeftinSharedMemory_e = 44UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the max and min for x axis in hostogram function are wrong min > max */
    rfe_error_histogramWrongXAxisLimit_e = 45UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the length of histogram output vector is not an integer*/
    rfe_error_histogramWrongOutputSize_e = 46UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that configured bits for ADC are not supported */
    rfe_error_invalidADCNumberOfBits_e  = 47UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that number of samples given to FFT are not mulitple of 2*/
    rfe_error_fftSamplesCountNot2Multiple_e = 48UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the number of averages for DFT/FFT is not in a valid range*/
    rfe_error_fftNumberOfAveragesOutOfBounds_e = 49UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the selected output for FFT is invalid*/
    rfe_error_fftInvalidOutputSelected_e = 50UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that FFT samples count is not divisble by number of average*/
    rfe_error_fftSamplesCountAndNumberOfAveragesNotMultiples_e = 51UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating the FFT output selected is not supported for the input setting selected */
    rfe_error_fftNotSupported_e = 52UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that number of samples given to DFT are not mulitple of 2*/
    rfe_error_dftSamplesCountNot2Multiple_e = 53UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the number of averages for DFT is not in a valid range*/
    rfe_error_dftNumberOfAveragesOutOfBounds_e = 54UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the selected output for DFT is invalid*/
    rfe_error_dftInvalidOutputSelected_e = 55UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that FFT samples count is not divisble by number of average*/
    rfe_error_dftSamplesCountAndNumberOfAveragesNotMultiples_e = 56UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating the DFT selected ouput option is not supported */
    rfe_error_dftNotSupported_e = 57UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that dft configuration was for more than on single bin output and this is not supported*/
    rfe_error_dftOnlySingleBinSupported_e = 58UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that dft configuration was set for complex input and that is not supported*/
    rfe_error_dftRealOnlySupported_e = 59UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Given #rfeCfg_param_t is containing an invalid parameter size.
     *  This error is treated as internal error, it has the _api_ prefix because it is used in rfeCfg which exist in rfeDriver and in rfeFw */
    rfe_error_api_cfgInvalidParameterSize_e = 60UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    rfe_error_param_invalidParam_e  = 61UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    rfe_error_param_invalidValue_e  = 62UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Given #rfeCfg_section_t section is not matching with the given parameter.
     *  This error is treated as internal error, it has the _api_ prefix because it is used in rfeCfg which exist in rfeDriver and in rfeFw */
    rfe_error_api_cfgSectionMismatch_e = 63UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because timer was not stopped (implicit resource release)  before being re-used  */
    rfe_error_timerInUse_e = 69UL| RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because maximum nesting level for WaitDo's reached */
     rfe_error_boundedWaitResourcesExhausted_e = 70UL| RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
   /** Error indicatin that chirp PLL VCO calibration fails*/
    rfe_error_chirpPllVcoCalibrationFailed_e = 71UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected atb bus is invalid*/
    rfe_error_atbInvalidAtbMaster_e = 72UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that atb selected trimming resistor is invalid*/
    rfe_error_atbInvalidTrimmingSelectedResistor_e = 73UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that operational mode for atb is invalid*/
    rfe_error_atbInvalidOperationalMode_e = 74UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that atb operational mode is not set so now switches will be enabled out of default*/
    rfe_error_atbModeOfOperationNotSet_e = 75UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that atb is trying to measure current without the trimming resistors enabled*/
    rfe_error_atbCurrentMeasurementWithoutResistors_e = 76UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the feature is not supported or implemented */
    rfe_error_atbNotSupported_e = 77UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that ATB is being set in mode to measure external voltage but the operational mode is not set accordingly to enable that*/
    rfe_error_atbCrossSwitchNotEnabled_e = 78UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that ATB BAnd GAP in charged of providing voltage reference for ATB ADC's failed */
    rfe_error_atbBandGapNotStarted_e = 79UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that BandGap output voltage set is not supported by ATB HW and therefore invalid*/
    rfe_error_atbBandGapInvalidVout_e = 80UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the input selected to configure the pull down resistors in ATB is not applicable, since resistors should not be enable for that input*/
    rfe_error_atbInvalidPullDownInput_e = 81UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected input in differential mode towards the ATB ADC's is wrong*/
    rfe_error_atbInvalidAdcInputDiffMode_e = 82UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected adc input in signle mode is wrong*/
    rfe_error_atbInvalidAdcSelSingleMode_e = 83UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected input in signle mode towards the ATB ADC's is wrong*/
    rfe_error_atbInvalidAdcSingleModeGround_e = 84UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that adc ground is trying to be set when ADC is not working in single mode*/
    rfe_error_atbAdcNotInSingleMode_e = 85UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that adc was not configured properly to sample*/
    rfe_error_atbAdcNotConfiguredToSample_e = 86UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the number of samples selected for the ATB ADC are incorrect or not supported*/
    rfe_error_atbAdcInvalidAveragingSamples_e = 87UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because pit timer not initialized */
    rfe_error_hwPitNotInitialized_e = 88UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because not a valid resource for this function */
    rfe_error_boundedWaitNotValidResource_e = 89UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating ??*/
    rfeError_error_api_TimerInUse_e = 90UL| RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error because maximum nesting level for WaitDo's reached */
    rfeError_error_api_boundedWaitResourcesExhausted_e = 91UL| RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating reading of rx1 saturation status fails */
    rfe_error_rx1SaturationStatusReadingFailure_e= 92UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating reading of rx2 saturation status fails */
    rfe_error_rx2SaturationStatusReadingFailure_e= 93UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating reading of rx3 saturation status fails */
    rfe_error_rx3SaturationStatusReadingFailure_e= 94UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating reading of rx4 saturation status fails */
    rfe_error_rx4SaturationStatusReadingFailure_e= 95UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the chosen submodule for Tx is invalid*/
    rfe_error_txInvalidSubcomponent_e = 100UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected power profile for Tx is invalid*/
    rfe_error_txInvalidPowerProfile_e = 101UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected gain for PR BUF2A exceeds allowed range*/
    rfe_error_txGainBuf2AExceedRange_e = 102UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected gain for PR BUF2BC exceeds allowed range*/
    rfe_error_txGainBuf2BCExceedRange_e = 103UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected gain for PA current exceeds allowed range*/
    rfe_error_txPaGainCExceedRange_e = 104UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected calibration FSM state to skip is invalid*/
    rfe_error_txInvalidCalibrationFSMState_e = 105UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected connection in Tx ADC is not valid*/
    rfe_error_txInvalidAdcConnection_e = 106UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the tx index is not valid*/
    rfe_error_txIndexInvalid_e = 107UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that the phase value force into the PR exceeds allowed range*/
    rfe_error_txPRPhaseExceedRange_e = 108UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that dynamic programming was not finished before chirp acquisition */
    rfe_error_dynamicProgrammingDuringAcquisition_e = 109UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected PDC index is invalid*/
    rfe_error_pcdIndexInvalid_e = 118UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected sampling rate for PDC is invalid*/
    rfe_error_pcdSamplingFrequencyInvalid_e = 119UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected profile for PDC is invalid */
    rfe_error_pcdProfileIndexInvalid_e = 120UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that set phase correction for I or Q component exceeds its numeric range*/
    rfe_error_pcdPhaseCorrectionInvalid_e = 121UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected input via INP_SEL is not supported, but it might be if implemented*/
    rfe_error_pcdSlectedInputNotImplemented_e = 122UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that set correlation integration time exceeds range*/
    rfe_error_pcdCorrelatorIntegrationTimeInvalid_e = 123UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that rfeSwCfgMngr distribution group does not exist */
    rfe_error_distrGroupDoesNotExist_e = 124UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Configured radar cycle timing is invalid */
    rfe_error_invalidRadarCycleTiming_e = 125UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Event is already active, main and radar cycle fsm each support only 1 event active at the same time */
    rfe_error_mainFsm_eventAlreadyActive_e = 126UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** A radar cycle state exceeded the scheduled end time */
    rfe_error_radarCycleFsm_stateEndTimeExceeded_e = 127UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Triggered main fsm event is not allowed in the current state */
    rfe_error_mainFsm_eventNotAllowed_e = 128UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Chirp started earlier than expected, RFE FW was still busy */
    rfe_error_chirpStartedTooEarly_e = 129UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Chirp start interrupt was not received before timeout */
    rfe_error_mainFsm_chirpStartInterruptTimeout_e = 130UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Chirp sequence end interrupt was not received before timeout */
    rfe_error_mainFsm_chirpSequenceEndInterruptTimeout_e = 131UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Chirp acquisition start interrupt was not received before timeout */
    rfe_error_mainFsm_chirpAcquisitionStartInterruptTimeout_e = 132UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Mcgen ADPLL not in lock when chirp sequence started */
    rfe_error_mainFsm_mcgenAdpllNotLocked_e = 133UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that selected temperature sensor is invalid */
    rfe_error_tSenseInvalidModeOfOperation_e = 135UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that temperature selected resolution is invalid */
    rfe_error_tSenseInvalidResolutionTime_e = 136UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that a temperature query was carried out when the conversion was not finished */
    rfe_error_tSenseConversionInProgress_e = 137UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that temperature threshold either for over-temperature and under-temperature is invalid*/
    rfe_error_tSenseInvalidOverUndeThresholds_e = 138UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that warning temperature threshold is invalid*/
    rfe_error_tSenseInvalidWarningThreshold_e = 139UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that hysteresis temperature threshold is invalid*/
    rfe_error_tSenseInvalidHysteresisThreshold_e = 140UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that converting temperature via raw ADC value issued a division by zero*/
    rfe_error_tSenseDivisionByZero_e = 141UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that rfeHwRxAdc_adcModuleId_t is unidentified */
    rfe_error_rxAdcModuleIdUnidentified_e = 142UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that rfeHwRxAdc_inputI_rx_e or rfeHwRxAdc_inputQ_rx_e is unidentified */
    rfe_error_rxAdcInputUnidentified_e = 143UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll loop filter C1 value is not valid*/
    rfe_error_chirpPllLoopfilterC1NotOk_e = 144UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll loop filter C2Fast value is not valid*/
    rfe_error_chirpPllLoopfilterC2FastNotOk_e = 145UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll loop filter C2Slow value is not valid*/
    rfe_error_chirpPllLoopfilterC2SlowNotOk_e = 146UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll loop filter C3Fast value is not valid*/
    rfe_error_chirpPllLoopfilterC3FastNotOk_e = 147UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll loop filter C3Slow value is not valid*/
    rfe_error_chirpPllLoopfilterC3SlowNotOk_e = 148UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll loop filter R1 value is not valid*/
    rfe_error_chirpPllLoopfilterR1NotOk_e = 149UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll loop filter R2 value is not valid*/
    rfe_error_chirpPllLoopfilterR2NotOk_e = 150UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll loop filter charge pump value is not valid*/
    rfe_error_chirpPllLoopfilterCpNotOk_e = 151UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating invalid ATB ADC selection */
    rfe_error_atbInvalidAtbAdc_e = 152UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating invalid ATB ADC gain mode selection */
    rfe_error_atbInvalidAtbAdcGainMode_e = 153UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll bandgap is not functional*/
    rfe_error_chirpPllBandgapNotOk_e = 154UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll VCO HVLDO is not functional*/
    rfe_error_chirpPllHvLdoVcoNotOk_e = 155UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll CP HVLDO is not functional*/
    rfe_error_chirpPllHvLdoCpNotOk_e = 156UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll PDIV LDO is not functional*/
    rfe_error_chirpPllPdivLdoNotOk_e = 157UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll LVLDO is not functional*/
    rfe_error_chirpPllLvLdoNotOk_e = 158UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
     /** Error indicating that rx calibration target is invalid */
    rfe_error_rxCalibrationTargetInvalid_e = 159UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that rx calibration target is invalid */
    rfe_error_rxCalibrationIfStageInvalid_e = 160UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that Mcgen 0v9 ana signal is not functional*/
    rfe_error_mcgen0v9AnaNotOk_e = 161UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that Mcgen XO det clock is not functional*/
    rfe_error_mcgenXoDetPllClkError_e = 162UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that Mcgen Ad pll out vdd 0v9 dig signal is not functional*/
    rfe_error_mcgenAdpllOutVdd0v9DigNotOk_e = 163UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that Mcgen ADPLL is not locked*/
    rfe_error_mcgenAdpllLockDetNotLocked_e = 164UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating RTM error from ISM is reported*/
    /** This error is only used during RFE initialization, FCCU error outside of init will not trigger a SW Error*/
    rfe_error_initRtmErrorReported = 165UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that Mcgen 0v9 ana signal is not functional*/
    rfe_error_initMcgen0v9AnaNotOk_e = 166UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that RX profile target combination is not supported*/
    rfe_error_rxTargetSettingsCombinationIsNotSupported_e = 167UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** didt test fails */
    rfe_error_didt_test_failure_e = 168UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Test buffer overflow */
    rfe_error_testBufferOverflow_e = 169UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that chirp pll VCO calibration amplittude level is out of range*/
    rfe_error_chirpPllVcoCalAmpOutOfRange_e = 170UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error LpUart not active */
    rfe_error_lpUartNotActive_e = 191UL| RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** TX PR calibration took longer than the reserved time budget*/
    rfe_error_txPrCalibrationTimeout_e = 192UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    rfe_error_registerComparisonFailed_e = 200UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    rfe_error_spiTransactionError_e = 201UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    rfe_error_spiTransactionTimeout_e = 202UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Access to register for a write operation is locked in Hardware. */
    rfe_error_HwRegister_lock_e = 203UL| RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /**Startup sequence is not configured as described in the ISM/FCCU Init Sequence */
    rfe_error_startup_seq_failed_e = 204UL| RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** PLL lock failed */
    rfe_error_csi2PllLockTimeOut_e = 205UL| RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** PLL PHY calibration failed */
    rfe_error_csi2PllcalibrationTimeOut_e = 206UL| RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** FCCU error occurred (does not override active SW error, so FCCU error was first) */
    rfe_error_fcc_e = 207UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** Error indicating that PPD VOUT is above Max value */
    rfe_error_ppdVoutAboveMax_e = 208UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
     /** Error indicating that LLDO PDC power not okay*/
    rfe_error_initLldoPdcPowerNotOk_e = 209UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /**Error indicating that ATB input source selected is invalid */
    rfe_error_atbInvalidInputSource_e = 500UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /**Error indicating that ATB ADC is not calibrated and therefore unreliable to be used */
    rfe_error_atbAdcNoCalibrated_e = 501UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /*zero hour reference data not generated */
    rfe_error_bistZeroHourDataNotGenerated_e = 600UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** BIST: Error indication RX Bist parameter is out of range */
    rfe_error_rxbistParameterOutOfRange_e = 610UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that an invalid stream is selected for WDMA operation*/
    rfe_error_wdmaIncorrectStreamSelected_e = 700UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that an invalid address is selected for buffer in WDMA operation*/
    rfe_error_wdmaBufferOutOfBounds_e = 701UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that the selected buffer address is not aligned with the bit-width of the AXI bus*/
    rfe_error_wdmaBufferAddressNotAligned_e = 702UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that the selected burst-length is out of allowed bounds as per AXI standard*/
    rfe_error_wdmaBurstLengthOutOfBounds_e = 703UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that the incorrect value is passed for AXI burst length field*/
    rfe_error_wdmaWrongValueForaxiBurstModeField_e = 704UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that the buffer address is not set prior to triggering a stream on OR clearing the destination buffer*/
    rfe_error_wdmaBufferAddressNotSet_e = 705UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that the buffer length (or size) is not set prior to triggering a stream on OR clearing the destination buffer*/
    rfe_error_wdmaBufferLengthNotSet_e = 706UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that the buffer overwrite mode is not set prior to triggering a stream on*/
    rfe_error_wdmaBufferOverwriteModeNotSet_e = 707UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that the AXI burst length is not set prior to triggering a stream on*/
    rfe_error_wdmaAxiBurstLengthNotSet_e = 708UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that the AXI burst mode is not set prior to triggering a stream on*/
    rfe_error_wdmaAxiBurstModeNotSet_e = 709UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that an incorrect interrupt source has been selected*/
    rfe_error_wdmaIncorrectInterruptSourceSelected_e = 710UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** WDMA: Error indicating that an incorrect number of streams has been selected*/
    rfe_error_wdmaIncorrectNumberOfStreamsSelected_e = 711UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** error if invalid code for R and C banks is selected */
    rfe_error_rxIfCalibrationInvalidRcCode_e = 800UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** error if invalid code for R and C banks is selected within RX driver API */
    rfe_error_rxInvalidRcCode_e = 801UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** error if invalid code for RXBIST SSB control is selected within RX BIST API */
    rfe_error_rxbistInvalidSsbCode_e = 802UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** error indicating that selected channel for RX IF calibration is wrong     */
    rfe_error_rxIfCalibrationInvalidChannel = 803UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** error indicating that rx if calibration has failed */
    rfe_error_rxIfCalibrationFailed = 804UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
    /** error indicating that rx if calibration settings are invalid*/
    rfe_error_rxIfCalibrationInvalidSettings = 805UL | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,


	// ***** General Error BC Codes (0x50xxxu) *****
	// The low nibble of byte 2 represent which FE report an error
	// To see the error need to (error & 0xfffff0ff)
	// To see the front end which report the error need to (error & 0x00000f00)

	/// Input parameters out of range
	rfe_error_bc_inputOutOfRange = 0x50001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Access to a not-existing function
	rfe_error_bc_funcNoExist = 0x50002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// CRC error injection failure
	rfe_error_bc_failToInjectCrcErr = 0x50003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Serializer mode other than MIPI/LVDS selected
	rfe_error_bc_wrongInterface = 0x50004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Access to an OTP disabled IP
	rfe_error_bc_ipDisabled = 0x50005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** SYS Error Codes (0x51xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_sys_ipHasNoAtbConnection = 0x51001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_cannotFindCafcDacCode = 0x51002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/* Gap */
	rfe_error_bc_sys_adcInvalid = 0x51005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_fileError = 0x51006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_jsonStringNoExisted = 0x51007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/* Gap */
	/// Failed reading temperature data of TX after multiple retries
	rfe_error_bc_sys_txTempReadTimeout = 0x5100AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// MCLK for serializer(LVDS/MIPI) is not within range. Expected MCLK is 480MHz with a minor drift of +/- 500KHz.
	rfe_error_bc_sys_mclkIntegrityFailed = 0x5100BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_wrongAppconfig = 0x5100CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Invalid CRC trigger event is given as input
	rfe_error_bc_sys_invalidInput = 0x5100DU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/* Gap */
	rfe_error_bc_sys_wrongProfileNoRecovery = 0x5100FU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_errorRecoveryFailed = 0x51010U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// This error is related to CAFC sensor integrity check where known errors are injected and checked whether corresponding CAFC errors are triggered. This error is reported when VCOLevelMinErr is FALSE while TRUE is expected.
	rfe_error_bc_sys_cafcIntegrityCheckLevel = 0x51011U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// This error is related to CAFC sensor integrity check where known errors are injected and checked whether corresponding CAFC errors are triggered. This error is reported when PLLUnlockErr is FALSE while TRUE is expected.
	rfe_error_bc_sys_cafcIntegrityCheckUnlock = 0x51012U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/* Gap */
	/// Wrong data interface configuration. LVDS or MIPI interface need to be set in App configuration before initializing data interface
	rfe_error_bc_sys_wrongDataInterfaceConfig = 0x51014U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// ERROR_N Pin should be high at the end of successful startup sequence completion. This error code indicates there are some errors and ERROR_N Pin is low.
	rfe_error_bc_sys_error_N = 0x51016U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_invalidProfile = 0x51017U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_faultInjectionFail = 0x51018U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_wrongMidNoRecovery = 0x51019U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_spiAccessCheckFail = 0x5101AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Failed reading temperature data of CAFC after multiple retries
	rfe_error_bc_sys_cafcTempReadTimeout = 0x5101BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/* Gap */

	/// CAFC module has to be disabled for slave device. This error occur if the CAFC module is enable for slave device
	rfe_error_bc_sys_slaveWrongAppConfig = 0x51026U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/* Gap */
	rfe_error_bc_sys_subBandIncOutOfRange = 0x5105CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/* Gap */
	rfe_error_bc_sys_ptrAddrNull = 0x51061U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_aafcAutoNotSupported = 0x51062U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// RawNumSample is the chirp active or acquisition time. This is affected by the decimation factor. The error means RawNumSample is not a factor of decimation or zero.
	rfe_error_bc_sys_rawNumSampleInvalid = 0x51063U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Reset time should be less or equal to chirp active time.
	rfe_error_bc_sys_invalidResetTime = 0x51064U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Calculated total (full ramp) bandwidth = BW TSettle + BW Acquisition + BW TJumpback, is going out of range for corresponding VCO bandwidth.
	rfe_error_bc_sys_totalBwOutOfRange = 0x51065U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// CAFC integrity check failure due to PLL unlock and/or VCO level min error, API is not able to clear the unlock and/or VCO level min error
	rfe_error_bc_sys_cafcIntegrityCheckFailed = 0x51066U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Restoring of CHIRP_GLOBAL_CONTROL register failed while CAFC integrity check
	rfe_error_bc_sys_restoreChirpGlobalFailed = 0x51067U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// ISM register CRC error is reported, even after clearing the error injection
	rfe_error_bc_sys_regCrcIsmModuleErrorSet = 0x51068U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_regCrcTriggerFailed = 0x51069U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Write check failed while setting defaults for TX_CONTROL_ENABLE register
	rfe_error_bc_sys_txCtrlEnableWriteCheckBase = 0x51070U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_tx1CtrlEnableWriteCheck = 0x51071U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_tx2CtrlEnableWriteCheck = 0x51072U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_tx1Tx2CtrlEnableWriteCheck = 0x51073U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_tx3CtrlEnableWriteCheck = 0x51074U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_tx1Tx3CtrlEnableWriteCheck = 0x51075U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_tx2Tx3CtrlEnableWriteCheck = 0x51076U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_tx1Tx2Tx3CtrlEnableWriteCheck = 0x51077U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// LOI Ball Break error
	rfe_error_bc_sys_loiInBallBreakDetected = 0x51078U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_sys_loiOutBallBreakDetected = 0x51079U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** ALG Error Codes (0x52xxx) *****
	// For Cascaded byte 2 represent which FE report an error

	rfe_error_bc_algDummyError = 0x52001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT, //dummy, change this name when you define the first error

	// **** BC_SPI Error Codes (0x53xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_spiWriteReadCrcError = 0x53001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_spiWriteCheckFail = 0x53002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_readFail = 0x53003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	//0x54xxx is used by PLF layer.

	// ***** CC Error Codes (0x60xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_ccSysConfNotSet = 0x60001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ccPtrAddrNull = 0x60002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** LVDS Error Codes (0x61xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	/// LVDS test mode setting is incorrect
	rfe_error_bc_lvdsInvalidInput = 0x61001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_lvdsPtrAddrNull = 0x61002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_lvdsSammplesShiftInvalid = 0x61003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_lvdsClkEdgeInvalid = 0x61004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_lvdsAdcClkFromInvalid = 0x61005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_lvdsFreqCounterDeviation = 0x61006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_lvdsCountPeriodInvalid = 0x01007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Busy wait read of Frequency Counter register failed after max retries
	rfe_error_bc_lvdsFreqCountTimeout = 0x61008U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Restoring of the frequency counter register failed
	rfe_error_bc_lvdsrestoreFreqCounter = 0x61009U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** MIPI Error Codes (0x62xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_mipiDeviceReadyTimeout = 0x62001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Busy wait read of Frequency Counter register failed after max retries
	rfe_error_bc_mipiFreqCountTimeout = 0x62002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// CountPeriod Period in us for doing the frequency measurement is out of range
	rfe_error_bc_mipiFreqCntOutOfRange = 0x62003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_mipiPtrAddrNull = 0x62004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Restoring of the frequency counter register failed
	rfe_error_bc_mipiRestoreFreqCounter = 0x62005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** TE Error Codes (0x64xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_tePrSafetyDelay = 0x64001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tePrCalibDelay = 0x64002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teRxActiveDelay = 0x64003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/// Invalid HPF Reset Release Delay from reference point
	rfe_error_bc_teHpfResetDelay = 0x64004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teDcPowOnDelay = 0x64005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Invalid safety monitor delay from reference point
	rfe_error_bc_teDcSafetyDelay = 0x64006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teDdmaSetting = 0x64007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teDdmaMode = 0x64008U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teJumpBack = 0x64009U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/// Either TX or RX group delay is greater than DC power on delay
	rfe_error_bc_teTxRxGrpDelay = 0x6400AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teFineGrpDelay = 0x6400BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Invalid Profile or profile combination
	rfe_error_bc_teProfileList = 0x6400CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tePrCalTimeout = 0x6400DU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teBiasDelay = 0x6400EU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teInputNull = 0x6400FU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Invalid profile repeat count
	rfe_error_bc_tePrfRepeatCnt = 0x64010U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teChirpSeqInterval = 0x64011U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teSettleTime = 0x64012U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teOutputSampRate = 0x64013U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teChirpInterval = 0x64014U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teVirtualChannel = 0x64015U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teDwllTime = 0x64016U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Invalid Transmission ON delay from timing reference point
	rfe_error_bc_teDelayFromRefpt = 0x64017U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Polling for the completion of chirp sequence failed after multiple retries
	rfe_error_bc_teFreqCntTimeout = 0x64018U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teChirpSequence = 0x64019U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teChirpTrgMode = 0x6401AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/* Gap */
	rfe_error_bc_tePhaseOutOfRange = 0x6401EU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teHpfResetWrongTriggerPoint = 0x6401FU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/// Write check failed while setting defaults for TX_CAL_ENABLE register
	rfe_error_bc_teTxCalEnableWriteCheckBase = 0x64020U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teTx1CalEnableWriteCheck = 0x64021U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teTx2CalEnableWriteCheck = 0x64022U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teTx1Tx2CalEnableWriteCheck = 0x64023U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teTx3CalEnableWriteCheck = 0x64024U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teTx1Tx3CalEnableWriteCheck = 0x64025U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teTx2Tx3CalEnableWriteCheck = 0x64026U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_teTx1Tx2Tx3CalEnableWriteCheck = 0x64027U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/// Write check failed while setting chirp enable
	rfe_error_bc_teChirpEnableWriteCheckFailed = 0x64028U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** SC Error Codes (0x65xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_scProfile = 0x65001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_scOperatingFreqOutOfRange = 0x65002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_scPtrAddrNull = 0x65003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Frequency Drift value greater than the chirp bandwidth
	rfe_error_bc_scInputFreqDriftInvalid = 0x65004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Bandwidth is outside the range what hardware is capable of
	rfe_error_bc_scUserBwOutOfRange = 0x65005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Ramp time outside the practical range.
	rfe_error_bc_scRampTimeOutOfRange = 0x65006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Reset time outside the practical range.
	rfe_error_bc_scResetTimeOutOfRange = 0x65007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** CAFC Error Codes (0x66xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_cafcFreqCntTimeout = 0x66001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcSbOutOfRange = 0x66002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcInputOutOfRange = 0x66003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Wrong VCO selected
	rfe_error_bc_cafcBwOutOfRange = 0x66004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Compensated slice number is 0, which is is invalid
	rfe_error_bc_cafcConfigLoopFilterFail = 0x66005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcLoopBwOutOfRange = 0x66006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcPtrAddrNull = 0x66007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcWrongProfileid = 0x66008U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/// Busy status for aafc, kvco and dvdt
	rfe_error_bc_cafcAafcKvCodVdtTimeout = 0x66009U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcVcoCalibAafcFail = 0x6600AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcVcoCalibKvCodVdtFail = 0x6600BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcNoStoreInProfileSelected = 0x6600CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcDvdtCountWrong = 0x6600DU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcKvcoCountStatusErr = 0x6600EU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcWrongKvco = 0x66010U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_cafcWrongAcquisitionDuration = 0x66011U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** ADC Error Codes (0x67xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	/// ADC calibration failure
	rfe_error_bc_adcCalibrationFailed = 0x67001u | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// ADC calibration timeout failure
	rfe_error_bc_adcCalibrationTimeout = 0x67002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// ADC calibration Check not done
	rfe_error_bc_adcCalibarationCheckNotDone = 0x67003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** GBIAS Error Codes (0x69xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_gbiasDummy = 0x69001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** LOI Error Codes (0x6Axxx) *****
	// For Cascaded byte 2 represent which FE report an error
	/* Gap */
	/// LO LUT Gain code out of range
	rfe_error_bc_loiLutGainCodeOutOfRange = 0x6A003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/* Gap */
	/// LO Gain cal busy
	rfe_error_bc_loiCalBusy = 0x6A005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// LO Gain cal error
	rfe_error_bc_loiCalError = 0x6A006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_loiPtrAddrNull = 0x6A007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** MCLK Error Codes (0x6Cxxx) *****
	// For Cascaded byte 2 represent which FE report an error
	/* Gap */
	rfe_error_bc_mclkPllCalibrationFailed = 0x6C003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_mclkPllCalibrationNotFinished = 0x6C004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_mclkMspcCalibrationError = 0x6C006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_mclkMspcTimeout = 0x6C007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/* Gap */
	rfe_error_bc_mclkPtrAddrNull = 0x6C00AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,


	// ***** RX Error Codes (0x6Dxxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_rxInputOutOfRange = 0x6D001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rxCalBusy = 0x6D002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1CalBusy = 0x6D003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2CalBusy = 0x6D004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx3CalBusy = 0x6D005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx4CalBusy = 0x6D006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rxCalError = 0x6D007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1CalError = 0x6D008U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2CalError = 0x6D009U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2CalError = 0x6D00AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx3CalError = 0x6D00BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx3CalError = 0x6D00CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2Rx3CalError = 0x6D00DU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2Rx3CalError = 0x6D00EU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx4CalError = 0x6D00FU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx4CalError = 0x6D010U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2Rx4CalError = 0x6D011U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2Rx4CalError = 0x6D012U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx3Rx4CalError = 0x6D013U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx3Rx4CalError = 0x6D014U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2Rx3Rx4CalError = 0x6D015U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2Rx3Rx4CalError = 0x6D016U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rxPrtAddrNull = 0x6D017U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rxWrngCalTargetOffset = 0x6D018U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Write check failed while enabling Functional Safety Mon Level for RX
	rfe_error_bc_rxFusaEnableWriteCheckBase = 0x6D020U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1FusaEnableWritecheck = 0x6D021U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2FusaEnableWritecheck = 0x6D022U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2FusaEnableWritecheck = 0x6D023U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx3FusaEnableWritecheck = 0x6D024U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx3FusaEnableWritecheck = 0x6D025U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2Rx3FusaEnableWritecheck = 0x6D026U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2Rx3FusaEnableWritecheck = 0x6D027U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx4FusaEnableWritecheck = 0x6D028U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx4FusaEnableWritecheck = 0x6D029U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2Rx4FusaEnableWritecheck = 0x6D02AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2Rx4FusaEnableWritecheck = 0x6D02BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx3Rx4FusaEnableWritecheck = 0x6D02CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx3Rx4FusaEnableWritecheck = 0x6D02DU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2Rx3Rx4FusaEnableWritecheck = 0x6D02EU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2Rx3Rx4FusaEnableWritecheck = 0x6D02FU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Write check failed for Rx BBD Enable
	rfe_error_bc_rxBbdEnableWritecheckBase = 0x6D030U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1BbdEnableWritecheck = 0x6D031U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2BbdEnableWritecheck = 0x6D032U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2BbdEnableWritecheck = 0x6D033U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx3BbdEnableWritecheck = 0x6D034U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx3BbdEnableWritecheck = 0x6D035U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2Rx3BbdEnableWritecheck = 0x6D036U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2Rx3BbdEnableWritecheck = 0x6D037U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx4BbdEnableWritecheck = 0x6D038U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx4BbdEnableWritecheck = 0x6D039U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2Rx4BbdEnableWritecheck = 0x6D03AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2Rx4BbdEnableWritecheck = 0x6D03BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx3Rx4BbdEnableWritecheck = 0x6D03CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx3Rx4BbdEnableWritecheck = 0x6D03DU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx2Rx3Rx4BbdEnableWritecheck = 0x6D03EU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_rx1Rx2Rx3Rx4BbdEnableWritecheck = 0x6D03FU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** TX Error Codes (0x71xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_txInputOutOfRange = 0x71001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txPrcAdcTimeout = 0x71002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txSensorFitFail = 0x71003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txCalBusy = 0x71004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1CalBusy = 0x71005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2CalBusy = 0x71006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx3CalBusy = 0x71007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txCalError = 0x71008U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1CalError = 0x71009U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2CalError = 0x7100AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx2CalError = 0x7100BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx3CalError = 0x7100CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx3CalError = 0x7100DU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2Tx3CalError = 0x7100EU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx2Tx3CalError = 0x7100FU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txSafetyBusy = 0x71010U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1SafetyBusy = 0x71011U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2SafetyBusy = 0x71012U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx3SafetyBusy = 0x71013U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txSafetyError = 0x71014U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1SafetyError = 0x71015U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2SafetyError = 0x71016U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx2SafetyError = 0x71017U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx3SafetyError = 0x71018U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx3SafetyError = 0x71019U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2Tx3SafetyError = 0x7101AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx2Tx3SafetyError = 0x7101BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txPtrAddrNull = 0x7101CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txNoStoreInProfileSelected = 0x7101DU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txPoutVgaReduceTxNotSupported = 0x7101EU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_txRfMinCodeOutOfRange = 0x7101FU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/// Write check failed for while enabling Functional Safety Mon Level enabling for TX
	rfe_error_bc_txFusaEnableWriteCheckBase = 0x71020U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1FusaEnableWriteCheck = 0x71021U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2FusaEnableWriteCheck = 0x71022U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx2FusaEnableWriteCheck = 0x71023U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx3FusaEnableWriteCheck = 0x71024U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx3FusaEnableWriteCheck = 0x71025U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2Tx3FusaEnableWriteCheck = 0x71026U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx2Tx3FusaEnableWriteCheck = 0x71027U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// If the TX calibration is not complete, setting bias current will not succeed
	rfe_error_bc_txCalibBiasCurrWriteFailed = 0x71028U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/// TX calibration failed with timeout
	rfe_error_bc_txCalibTimeout = 0x71029U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Write check failed while enabling BBD for TX
	rfe_error_bc_txBbdEnableWritecheckBase = 0x71030U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1BbdEnableWritecheck = 0x71031U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2BbdEnableWritecheck = 0x71032U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1tx2BbdEnableWritecheck = 0x71033U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx3BbdEnableWritecheck = 0x71034U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx3BbdEnableWritecheck = 0x71035U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx2Tx3BbdEnableWritecheck = 0x71036U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_tx1Tx2Tx3BbdEnableWritecheck = 0x71037U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** SSB Error Codes (0x74xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	/// Connected signal node to a wrong ATB
	rfe_error_bc_ssbSignalNotExistOnSelectedAtb = 0x74001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// Input out of range
	rfe_error_bc_ssbInputOutOfRange = 0x74002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** GLDO Error Codes (0x75xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_gldoSnsError = 0x75001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_gldoSnsForceError = 0x75002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_gldoSnsResetError = 0x75003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** ATB Error Codes (0x76xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	/// BISTADC data collection timeout
	rfe_error_bc_atbBistAdcTimeout = 0x76001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// selected a wrong ATB
	rfe_error_bc_atbWrongAtbNoSelected = 0x76002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** OTP Error Codes (0x77xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	/// Fail to read OTP table
	rfe_error_bc_otpFailToRead = 0x77001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// CRC check failure
	rfe_error_bc_otpCrcCheckFailure = 0x77002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// IP is disabled
	rfe_error_bc_otpIpIsDisabled = 0x77003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/// OTP is not loaded.
	rfe_error_bc_otpOtpIsNotLoaded = 0x77004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	/* Gap */
	// None of the OTP memory is enabled
	rfe_error_bc_otpAllMemDisabled = 0x77006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** ISM Error Codes (0x78xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	rfe_error_bc_ismInvalidInput = 0x078001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismPtrAddrNull = 0x078002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismStartupSeqConfigFailed = 0x078003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismInputModeToggleTestFailed = 0x078004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismOutputModeToggleTestFailed = 0x078005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitErrorN_High = 0x078006U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitResetStateChangeFailed = 0x078007U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitResetErrorFailed = 0x078008U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitForceStateChangeFailed = 0x078009U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitForceErrorFailed = 0x07800AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitFailed = 0x07800BU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitStatusFailed = 0x07800CU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitTxStatusFailed = 0x07800DU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitRxStatusFailed = 0x07800EU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitAdcStatusFailed = 0x07800FU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitChirpStatusFailed = 0x078010U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitMclkLoIsmOtpCcStatusFailed = 0x078011U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismFitSsbSerGbGldoAAtbStatusFailed = 0x078012U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismCalBusy = 0x078013U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismCalError = 0x078014U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismCalSuccess = 0x078015U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_bc_ismDisableLbToggleTestFailed = 0x078016U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	// ***** Sys Error Codes (0x79xxx) *****
	// For Cascaded byte 2 represent which FE report an error
	// ex: 0x07910A = SPI_ERR_WRG_UNIT_ID on FE 1
	rfe_error_sys_spi_wrg_unit_id = 0x07900AU | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_sys_spi_invalid_len = 0x079014U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_sys_timer_cm7_init = 0x079001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_sys_FE_chip_es2_not_supported = 0x079002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,

	/****** Specific errors for Fault Injection Tests   ******/
	rfe_error_ic_wrg_input_params_e = 0x7a000U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,            /**< wrong input parameter(s), usually NULL pointer      */

	/****** Specific errors for RFBIST   ******/
	rfe_error_rxbist_frequency_fail = 0x7B000U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_rxbist_missing_signal = 0x7B001U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_rxbist_lna_gain_fail_e = 0x7B002U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_rxbist_lna_phase_fail_e = 0x7B003U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_rxbist_mixer_gain_fail_e = 0x7B004U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
	rfe_error_rxbist_mixer_phase_fail_e = 0x7B005U | RFE_ERROR_RFE_INTERNAL_ERROR_BIT,
} rfe_error_t;


/**
 * In cascaded mode when report an error need to do (rfe_error_t || (fe index << 8))
 * ex: rfe_error_sys_FE_chip_es2_not_supported || (1 << 8)
 *
 * In cascaded mode when check a reported error need to do:
 * 	- ((rfe_error_t & 0x00000F00U) >> 8) to see which fe reported the error
 * 	- (rfe_error_t & 0xFFFFF0FFU) to see the error
 * ex: for this error 0x079102U
 * 		- 0x079102U & 0x00000F00U >> 8 = 0x000001U => fe_1
 * 		- 0x079102U & 0xFFFFF0FFU = 0x079002U => rfe_error_sys_FE_chip_es2_not_supported
 *
 * Or you can use the masks like :
 *      rfe_error_fe_0 = 0x000000U,
 *      rfe_error_fe_1 = 0x000100U,
 *      rfe_error_fe_2 = 0x000200U,
 *      ...
 */


/**
 *  This enumeration data type is used for FuSa faults
 *  - In RFE Configuration (\ref fuSaFaultMask), the enumeration must be used as bitwise index to mask or unmask the corresponding fault.
 *  - In rfe_getFuSaFaults(), the enumeration must be used as bitwise index to get the fault status for the corresponding fault.
 *  - The MSB represent byte index and LSB represent bitwise index.
 *  - Bitwise index = 0 to 7
 *  - Byte index = 0 to 11
 *  - for example this error "rfe_fuSaFault_sr65_sr67_supply_low_1v8_rx3_e = 0x0203U" will be find in byte index 2 fusa fault array at bit 3
 *    
 */
typedef enum
{
	/** TX3 supply low error (1V1) */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx3_e = 0x0000U,
	/** TX2 supply low error (1V1) */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx2_e = 0x0001U,
	/** TX1 supply low error (1V1) */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx1_e = 0x0002U,
	/** Phase rotator error for TX3 */
	rfe_fuSaFault_R2_sr72_pr_tx3_e = 0x0003U,
	/** Phase rotator error for TX2 */
	rfe_fuSaFault_R2_sr72_pr_tx2_e = 0x0004U,
	/** Phase rotator error for TX1 */
	rfe_fuSaFault_R2_sr72_pr_tx1_e = 0x0005U,
	/** TX3 supply low error (1V8) */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx3_e = 0x0006U,
	/** TX2 supply low error (1V8) */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx2_e = 0x0007U,
	/** TX1 supply low error (1V8) */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx1_e = 0x0100U,
	/** Max level monitoring error indicating TX3 RF level reached beyond max limit */
	rfe_fuSaFault_R2_sr69_rf_level_max_tx3_e = 0x0101U,
	/** Max level monitoring error indicating TX2 RF level reached beyond max limit */
	rfe_fuSaFault_R2_sr69_rf_level_max_tx2_e = 0x0102U,
	/** Max level monitoring error indicating TX1 RF level reached beyond max limit */
	rfe_fuSaFault_R2_sr69_rf_level_max_tx1_e = 0x0103U,
	/** Min level monitoring error indicating TX3 RF level reached below min limit */
	rfe_fuSaFault_R2_sr69_rf_level_min_tx3_e = 0x0104U,
	/** Min level monitoring error indicating TX2 RF level reached below min limit */
	rfe_fuSaFault_R2_sr69_rf_level_min_tx2_e = 0x0105U,
	/** Min level monitoring error indicating TX1 RF level reached below min limit */
	rfe_fuSaFault_R2_sr69_rf_level_min_tx1_e = 0x0106U,
	/** RF connectivity to external antenna port error for TX3 */
	rfe_fuSaFault_R2_sr27_bb_tx3_e = 0x0107U,
	/** RF connectivity to external antenna port error for TX2 */
	rfe_fuSaFault_R2_sr27_bb_tx2_e = 0x0200U,
	/** RF connectivity to external antenna port error for TX1 */
	rfe_fuSaFault_R2_sr27_bb_tx1_e = 0x0201U,
	/** Supply 1v8 low error RX4 */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx4_e = 0x0202U,
	/** Supply 1v8 low error RX3 */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx3_e = 0x0203U,
	/** Supply 1v8 low error RX2 */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx2_e = 0x0204U,
	/** Supply 1v8 low error RX1 */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx1_e = 0x0205U,
	/** Supply 1v1 low error RX4 */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx4_e = 0x0206U,
	/** Supply 1v1 low error RX3 */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx3_e = 0x0207U,
	/** Supply 1v1 low error RX2 */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx2_e = 0x0300U,
	/** Supply 1v1 low error RX1 */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx1_e = 0x0301U,
	/** Max Level monitoring error flag indicating RX4 LO level reached beyond max limit */
	rfe_fuSaFault_R2_sr47_lo_level_max_rx4_e = 0x0302U,
	/** Max Level monitoring error flag indicating RX3 LO level reached beyond max limit */
	rfe_fuSaFault_R2_sr47_lo_level_max_rx3_e = 0x0303U,
	/** Max Level monitoring error flag indicating RX2 LO level reached beyond max limit */
	rfe_fuSaFault_R2_sr47_lo_level_max_rx2_e = 0x0304U,
	/** Max Level monitoring error flag indicating RX1 LO level reached beyond max limit */
	rfe_fuSaFault_R2_sr47_lo_level_max_rx1_e = 0x0305U,
	/** Min Level monitoring error flag indicating RX4 LO level reached below min limit */
	rfe_fuSaFault_R2_sr47_lo_level_min_rx4_e = 0x0306U,
	/** Min Level monitoring error flag indicating RX3 LO level reached below min limit */
	rfe_fuSaFault_R2_sr47_lo_level_min_rx3_e = 0x0307U,
	/** Min Level monitoring error flag indicating RX2 LO level reached below min limit */
	rfe_fuSaFault_R2_sr47_lo_level_min_rx2_e = 0x0400U,
	/** Min Level monitoring error flag indicating RX1 LO level reached below min limit */
	rfe_fuSaFault_R2_sr47_lo_level_min_rx1_e = 0x0401U,
	/** RF connectivity to external antenna port error for RX4 */
	rfe_fuSaFault_R2_sr9_bb_rx4_e = 0x0402U,
	/** RF connectivity to external antenna port error for RX3 */
	rfe_fuSaFault_R2_sr9_bb_rx3_e = 0x0403U,
	/** RF connectivity to external antenna port error for RX2 */
	rfe_fuSaFault_R2_sr9_bb_rx2_e = 0x0404U,
	/** RF connectivity to external antenna port error for RX1 */
	rfe_fuSaFault_R2_sr9_bb_rx1_e = 0x0405U,
	/** AAFC calibration timeout error for chirp digital */
	rfe_fuSaFault_R2_sr46_aafc_cal_timeout_chirp_e = 0x0406U,
	/** AAFC calibration error for chirp digital */
	rfe_fuSaFault_R2_sr46_aafc_chirp_e = 0x0407U,
	/** Supply 1V1 low error for chirp digital */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_chirp_e = 0x0500U,
	/** Supply 1V8 low error for chirp VCO */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_vco_1v8_chirp_e = 0x0501U,
	/** Supply 1V8 low error for chirp PLL */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_pll_1v8_chirp_e = 0x0502U,
	/** Stuck on chirp_seq_active, safety_monitoring, window_active detected */
	rfe_fuSaFault_R2_sr7_interface_stuck_chirp_e = 0x0503U,
	/** Error indicating VCO ouput frequency to the chirp digital logic is beyond programmable limit */
	rfe_fuSaFault_R2_sr42_vco_freq_480_chirp_e = 0x0504U,
	/** Max Level monitoring error flag indicating VCO output level reached beyond max limit */
	rfe_fuSaFault_R2_sr45_level_max_chirp_e = 0x0505U,
	/** Min Level monitoring error flag indicating VCO output level reached below min limit */
	rfe_fuSaFault_R2_sr45_level_min_chirp_e = 0x0506U,
	/** Error indicating chirp PLL in unlock condition */
	rfe_fuSaFault_R2_sr43_unlock_chirp_e = 0x0507U,
	/** Error indicating chirp digital logic in stuck condition or transient logic failure */
	rfe_fuSaFault_R2_sr7_lock_step_chirp_e = 0x0600U,
	/** Max Level monitoring error flag indicating LOI level reached beyond max limit */
	rfe_fuSaFault_R2_sr48_level_max_loi_e = 0x0601U,
	/** Min Level monitoring error flag indicating LOI level reached below min limit */
	rfe_fuSaFault_R2_sr48_level_min_loi_e = 0x0602U,
	/** SPI CRC read error */
	rfe_fuSaFault_R2_sr19_rd_spi_crc_e = 0x0603U,
	/** SPI CRC write error */
	rfe_fuSaFault_R2_sr19_wr_spi_crc_e = 0x0604U,
	/** Supply low error from LO interface */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_loi_e = 0x0605U,
	/** RF connectivity issues in LO-in interface */
	rfe_fuSaFault_R2_sr17_bb_lo_in_loi_e = 0x0606U,
	/** RF connectivity issues in LO-out interface */
	rfe_fuSaFault_R2_sr18_bb_lo_out_loi_e = 0x0607U,
	/** Clock failure (no clock error) from master clock  */
	rfe_fuSaFault_R2_sr11_xo_no_clock_mclk_e = 0x0700U,
	/** Leader-Follower phase calibration error */
	rfe_fuSaFault_R2_sr36_mspc_mclk_e = 0x0701U,
	/** Supply error form master clock (1V8) */
	rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_mclk_e = 0x0702U,
	/** Error indicating master clock digital ouput frequency not in range */
	rfe_fuSaFault_R2_sr39_dig_freq_mclk_e = 0x0703U,
	/** Error indicating Pll in unlock condition */
	rfe_fuSaFault_R2_sr35_pll_lock_mclk_e = 0x0704U,
	/** Global 1V1 LDO supply high sensor error */
	rfe_fuSaFault_R2_sr57_supply_high_1v1_gldo_e = 0x0705U,
	/** Global 1V1 LDO supply low sensor error */
	rfe_fuSaFault_R2_sr59_supply_low_1v1_gldo_e = 0x0706U,
	/** Global 1V8 LDO supply high sensor error */
	rfe_fuSaFault_R2_sr61_supply_high_1v8_gldo_e = 0x0707U,
	/** Global 1V8 LDO supply low sensor error */
	rfe_fuSaFault_R2_sr63_supply_low_1v8_gldo_e = 0x0800U,
	/** Supply 1V8 low sensor error for serializer */
	rfe_fuSaFault_R2_sr65_67_supply_low_1v8_ser_e = 0x0801U,
	/** Supply 1V1 low sensor error for serializer CSI2 */
	rfe_fuSaFault_R2_sr65_67_supply_low_1v1_csi2_e = 0x0802U,
	/** Supply 1V1 low sensor error for serializer digital and LVDS */
	rfe_fuSaFault_R2_sr65_67_supply_low_1v1_ser_e = 0x0803U,
	/** Supply 1V8 low sensor error for global bias */
	rfe_fuSaFault_R2_sr65_67_supply_low_1v8_gbias_e = 0x0804U,
	/** Supply 1V8 low sensor error for SSB MOD */
	rfe_fuSaFault_R2_sr65_67_supply_low_1v8_ssb_e = 0x0805U,
	/** Supply low (1v8) for ADC34 */
	rfe_fuSaFault_R2_sr65_67_supply_low_1v8_adc34_e = 0x0806U,
	/** Supply low (1v8) for ADC12 */
	rfe_fuSaFault_R2_sr65_67_supply_low_1v8_adc12_e = 0x0807U,
	/** Calibration error for ADC4 */
	rfe_fuSaFault_R2_sr34_cal_adc4_e = 0x0900U,
	/** Calibration error for ADC3 */
	rfe_fuSaFault_R2_sr34_cal_adc3_e = 0x0901U,
	/** Calibration error for ADC2 */
	rfe_fuSaFault_R2_sr34_cal_adc2_e = 0x0902U,
	/** Calibration error for ADC1 */
	rfe_fuSaFault_R2_sr34_cal_adc1_e = 0x0903U,
	/** Register CRC error */
	rfe_fuSaFault_R2_sr3_reg_crc_e = 0x0904U,
	/** RFBIST LNA gain test error */
	rfe_fuSaFault_R2_sr31_bist_lna_gaindiff_sw_e = 0x905U,
	/** RFBIST LNA phase test error */
	rfe_fuSaFault_R2_sr31_bist_lna_phasediff_sw_e = 0x906U,
	/** RFBIST mixer gain test error */
	rfe_fuSaFault_R2_sr31_bist_mixer_gaindiff_sw_e = 0x907U,
	/** RFBIST mixer phase test error */
	rfe_fuSaFault_R2_sr31_bist_mixer_phasediff_sw_e = 0xA00U,
	/** CAFC level detector integrity check error */
	rfe_fuSaFault_R2_sr44_cafc_integrity_level_sw_e = 0xA01U,
	/** CAFC unlock detector integrity check error*/
	rfe_fuSaFault_R2_sr44_cafc_integrity_unlock_sw_e = 0xA02U,
	/** CAFC integrity check error*/
	rfe_fuSaFault_R2_sr44_cafc_integrity_sw_e = 0xA03U,
	/** TX integrity check error */
	rfe_fuSaFault_R2_sr70_tx_integrity_sw_e = 0xA04U,
	/** TX phase rotator calibration check error */
	rfe_fuSaFault_R2_sr72_tx_pr_cal_sw_e = 0xA05U,
	/** TX1 phase rotator calibration check error*/
	rfe_fuSaFault_R2_sr72_tx1_pr_cal_sw_e = 0xA06U,
	/** TX2 phase rotator calibration check error*/
	rfe_fuSaFault_R2_sr72_tx2_pr_cal_sw_e = 0xA07U,
	/** PLL /VCO level is too low or too high*/
	rfe_fuSaFault_R2_sr37_pll_level_mclk_e = 0x0B00U,
	/** TX3 phase rotator calibration check error*/
	rfe_fuSaFault_R2_sr72_tx3_pr_cal_sw_e = 0xB01U,
	/**Disable loopback toggle test*/
	rfe_fuSaFault_R2_sr14_disable_lb_toggle_test_sw_e = 0xB02U,
	/** Input mode toggle test */
	rfe_fuSaFault_R2_sr13_input_mode_toggle_test_sw_e = 0xB03U,
	/**SW generic error */
	rfe_generic_sw_e = 0xB04U

} rfe_fuSaFault_t;

typedef enum
{
	/** TX1 Temperature is too high if operation continue */
	rfe_fuSaFault_R1_tempErrorFlagTx1_e = 0x0000U,
	/** TX2 Temperature is too high if operation continue */
	rfe_fuSaFault_R1_tempErrorFlagTx2_e = 0x0001U,
	/** TX3 Temperature is too high if operation continue */
	rfe_fuSaFault_R1_tempErrorFlagTx3_e = 0x0002U,
	/** TX1 RF level reached below  a programmed low  level  limits */
	rfe_fuSaFault_R1_rfLevelLowErrorFlagTx1_e = 0x0003U,
	/** TX2 RF level reached below  a programmed low  level  limits */
	rfe_fuSaFault_R1_rfLevelLowErrorFlagTx2_e = 0x0004U,
	/** TX3 RF level reached below  a programmed low  level  limits */
	rfe_fuSaFault_R1_rfLevelLowErrorFlagTx3_e = 0x0005U,
	/** TX1 RF level reached beyond a programmed high level  limits */
	rfe_fuSaFault_R1_rfLevelHighErrorFlagTx1_e = 0x0006U,
	/** TX2 RF level reached beyond a programmed high level  limits */
	rfe_fuSaFault_R1_rfLevelHighErrorFlagTx2_e = 0x0007U,
	/** TX3 RF level reached beyond a programmed high level  limits */
	rfe_fuSaFault_R1_rfLevelHighErrorFlagTx3_e = 0x0008U,

	/** RX1 LO level reached below  a programmed low  level  limits */
	rfe_fuSaFault_R1_loLevelLowErrorFlagRx1_e = 0x0009U,
	/** RX2 LO level reached below  a programmed low  level  limits */
	rfe_fuSaFault_R1_loLevelLowErrorFlagRx2_e = 0x000AU,
	/** RX3 LO level reached below  a programmed low  level  limits */
	rfe_fuSaFault_R1_loLevelLowErrorFlagRx3_e = 0x000BU,
	/** RX4 LO level reached below  a programmed low  level  limits */
	rfe_fuSaFault_R1_loLevelLowErrorFlagRx4_e = 0x000CU,
	/** RX1 LO level reached beyond a programmed high level  limits */
	rfe_fuSaFault_R1_loLevelHighErrorFlagRx1_e = 0x000DU,
	/** RX2 LO level reached beyond a programmed high level  limits */
	rfe_fuSaFault_R1_loLevelHighErrorFlagRx2_e = 0x000EU,
	/** RX3 LO level reached beyond a programmed high level  limits */
	rfe_fuSaFault_R1_loLevelHighErrorFlagRx3_e = 0x000FU,
	/** RX4 LO level reached beyond a programmed high level  limits */
	rfe_fuSaFault_R1_loLevelHighErrorFlagRx4_e = 0x0010U,

	/** Chirp temperature is too high if operation continue */
	rfe_fuSaFault_R1_tempErrorFlagChirp_e = 0x0011U,
	/** Chirp Vtune level reached below  a programmed low  level  limits */
	rfe_fuSaFault_R1_vtuneLowErrorFlagChirp_e = 0x0012U,
	/** Chirp Vtune level reached above  a programmed high level  limits */
	rfe_fuSaFault_R1_vtuneHighErrorFlagChirp_e = 0x0013U,
	/** Chirp VCO level  reached below  a programmed low  level  limits */
	rfe_fuSaFault_R1_levelLowErrorFlagChirp_e = 0x0014U,
	/** Chirp VCO level reached above  a programmed high   level  limits */
	rfe_fuSaFault_R1_levelHighErrorFlagChirp_e = 0x0015U,

	/** Main pll (4.8GHz) calibration issues */
	rfe_fuSaFault_R1_pllFreqCalErrorFlagMc_e = 0x0016U,
	/** Level low flag mask  for LOI */
	rfe_fuSaFault_R1_loiLevelLowErrorFlagInterface_e = 0x0017U,
	/** Level high flag mask  for LOI */
	rfe_fuSaFault_R1_loiLevelHighErrorFlagInterface_e = 0x0018U,

	/** Status monitoring flag mask ADC1 */
	rfe_fuSaFault_R1_hardClippingFlagPersistentAdc1_e = 0x0019U,
	/** Status monitoring flag mask ADC2 */
	rfe_fuSaFault_R1_hardClippingFlagPersistentAdc2_e = 0x001AU,
	/** Status monitoring flag mask ADC3 */
	rfe_fuSaFault_R1_hardClippingFlagPersistentAdc3_e = 0x001BU,
	/** Status monitoring flag mask ADC4 */
	rfe_fuSaFault_R1_hardClippingFlagPersistentAdc4_e = 0x001CU,

	rfe_fusaFault_R1_size_e = 0x001DU

} rfe_fusaFault_R1_t;
/** @} */

#ifdef __cplusplus
}
#endif


#endif // !RFE_ERROR_H

