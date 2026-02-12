/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

// Obtain printf function
#if defined(DEBUG_VERSION) // As used in M7_0
  #include <stdio.h>
  #include <string.h>
  #include "debug_tools.h"
#elif defined(RFE_DEBUG)  // As used in M7_1
  #include <string.h>
  #include <stdio.h>
  #include "rfeHwLink.h"
#else
  #error "No debug printing supported"
#endif

#include "rfe_types.h"
#include "rfe_error.h"
#include "rfe_error_debug.h"


/*****************************************************************************
* local defines
*****************************************************************************/

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

#if defined(DEBUG_VERSION)
// Map RfeDbgPrintMsg to DbgPrintMsg
#define  RfeDbgPrintMsg DbgPrintMsg
#elif defined(RFE_DEBUG)
// use RfeDbgPrintMsg
#else
// use dummy func
static void RfeDbgPrintMsg(const char *fmt, ...)
{
	return;
}
#endif


/*****************************************************************************
* local types
*****************************************************************************/
typedef struct {
	uint32_t index;
	const char *string ;
} string_list_t;

/*****************************************************************************
* local functions (prototypes)
*****************************************************************************/
const char *RfeDbg_FusaStringGet(rfe_fuSaFault_t fuSaFault);
const char *RfeDbg_ErrStringGet (rfe_error_t error);

/*****************************************************************************
* exported variables
*****************************************************************************/

/*****************************************************************************
* local variables
*****************************************************************************/
static const char nullstring[1] = "";

static const string_list_t gsFusaDescriptors[] = {
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v1_tx3_e, "TX3 supply low error (1V1)"												 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v1_tx2_e, "TX2 supply low error (1V1)"												 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v1_tx1_e, "TX1 supply low error (1V1)"												 },
		{ rfe_fuSaFault_sr72_pr_tx3_e, "Phase rotator error for TX3"																 },
		{ rfe_fuSaFault_sr72_pr_tx2_e, "Phase rotator error for TX2"																 },
		{ rfe_fuSaFault_sr72_pr_tx1_e, "Phase rotator error for TX1"																 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v8_tx3_e, "TX3 supply low error (1V8)"												 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v8_tx2_e, "TX2 supply low error (1V8)"												 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v8_tx1_e, "TX1 supply low error (1V8)"												 },
		{ rfe_fuSaFault_sr69_rf_level_max_tx3_e, "Max level monitoring error indicating TX3 RF level reached beyond max limit"		 },
		{ rfe_fuSaFault_sr69_rf_level_max_tx2_e, "Max level monitoring error indicating TX2 RF level reached beyond max limit"		 },
		{ rfe_fuSaFault_sr69_rf_level_max_tx1_e, "Max level monitoring error indicating TX1 RF level reached beyond max limit"		 },
		{ rfe_fuSaFault_sr69_rf_level_min_tx3_e, "Min level monitoring error indicating TX3 RF level reached below min limit"		 },
		{ rfe_fuSaFault_sr69_rf_level_min_tx2_e, "Min level monitoring error indicating TX2 RF level reached below min limit"		 },
		{ rfe_fuSaFault_sr69_rf_level_min_tx1_e, "Min level monitoring error indicating TX1 RF level reached below min limit"		 },
		{ rfe_fuSaFault_sr27_bb_tx3_e, "RF connectivity to external antenna port error for TX3"										 },
		{ rfe_fuSaFault_sr27_bb_tx2_e, "RF connectivity to external antenna port error for TX2"										 },
		{ rfe_fuSaFault_sr27_bb_tx1_e, "RF connectivity to external antenna port error for TX1"										 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v8_rx4_e, "Supply 1v8 low error RX4"													 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v8_rx3_e, "Supply 1v8 low error RX3"													 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v8_rx2_e, "Supply 1v8 low error RX2"													 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v8_rx1_e, "Supply 1v8 low error RX1"													 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v1_rx4_e, "Supply 1v1 low error RX4"													 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v1_rx3_e, "Supply 1v1 low error RX3"													 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v1_rx2_e, "Supply 1v1 low error RX2"													 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v1_rx1_e, "Supply 1v1 low error RX1"													 },
		{ rfe_fuSaFault_sr47_lo_level_max_rx4_e, "Max Level monitoring error flag indicating RX4 LO level reached beyond max limit"	 },
		{ rfe_fuSaFault_sr47_lo_level_max_rx3_e, "Max Level monitoring error flag indicating RX3 LO level reached beyond max limit"	 },
		{ rfe_fuSaFault_sr47_lo_level_max_rx2_e, "Max Level monitoring error flag indicating RX2 LO level reached beyond max limit"	 },
		{ rfe_fuSaFault_sr47_lo_level_max_rx1_e, "Max Level monitoring error flag indicating RX1 LO level reached beyond max limit"	 },
		{ rfe_fuSaFault_sr47_lo_level_min_rx4_e, "Min Level monitoring error flag indicating RX4 LO level reached below min limit"	 },
		{ rfe_fuSaFault_sr47_lo_level_min_rx3_e, "Min Level monitoring error flag indicating RX3 LO level reached below min limit"	 },
		{ rfe_fuSaFault_sr47_lo_level_min_rx2_e, "Min Level monitoring error flag indicating RX2 LO level reached below min limit"	 },
		{ rfe_fuSaFault_sr47_lo_level_min_rx1_e, "Min Level monitoring error flag indicating RX1 LO level reached below min limit"	 },
		{ rfe_fuSaFault_sr9_bb_rx4_e, "RF connectivity to external antenna port error for RX4"										 },
		{ rfe_fuSaFault_sr9_bb_rx3_e, "RF connectivity to external antenna port error for RX3"										 },
		{ rfe_fuSaFault_sr9_bb_rx2_e, "RF connectivity to external antenna port error for RX2"										 },
		{ rfe_fuSaFault_sr9_bb_rx1_e, "RF connectivity to external antenna port error for RX1"										 },
		{ rfe_fuSaFault_sr46_aafc_cal_timeout_chirp_e, "AAFC calibration timeout error for chirp digital"							 },
		{ rfe_fuSaFault_sr46_aafc_chirp_e, "AAFC calibration error for chirp digital"												 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v1_chirp_e, "Supply 1V1 low error for chirp digital"									 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_vco_1v8_chirp_e, "Supply 1V8 low error for chirp VCO"									 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_pll_1v8_chirp_e, "Supply 1V8 low error for chirp PLL"									 },
		{ rfe_fuSaFault_sr7_interface_stuck_chirp_e, "Stuck on chirp_seq_active, safety_monitoring, window_active detected"			 },
		{ rfe_fuSaFault_sr42_vco_freq_480_chirp_e, "Error indicating VCO ouput frequency to the chirp digital logic is beyond programmable limit"	 },
		{ rfe_fuSaFault_sr45_level_max_chirp_e, "Max Level monitoring error flag indicating VCO output level reached beyond max limit"	 },
		{ rfe_fuSaFault_sr45_level_min_chirp_e, "Min Level monitoring error flag indicating VCO output level reached below min limit"	 },
		{ rfe_fuSaFault_sr43_unlock_chirp_e, "Error indicating chirp PLL in unlock condition"										 },
		{ rfe_fuSaFault_sr7_lock_step_chirp_e, "Error indicating chirp digital logic in stuck condition or transient logic failure"	 },
		{ rfe_fuSaFault_sr48_level_max_loi_e, "Max Level monitoring error flag indicating LOI level reached beyond max limit"		 },
		{ rfe_fuSaFault_sr48_level_min_loi_e, "Min Level monitoring error flag indicating LOI level reached below min limit"		 },
		{ rfe_fuSaFault_sr19_rd_spi_crc_e, "SPI CRC read error"														 },
		{ rfe_fuSaFault_sr19_wr_spi_crc_e, "SPI CRC write error"													 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v1_loi_e, "Supply low error from LO interface"						 },
		{ rfe_fuSaFault_sr17_bb_lo_in_loi_e, "RF connectivity issues in LO-in interface"							 },
		{ rfe_fuSaFault_sr18_bb_lo_out_loi_e, "RF connectivity issues in LO-out interface"							 },
		{ rfe_fuSaFault_sr11_xo_no_clock_mclk_e, "Clock failure (no clock error) from master clock "				 },
		{ rfe_fuSaFault_sr36_mspc_mclk_e, "Leader-Follower phase calibration error"									 },
		{ rfe_fuSaFault_sr65_sr67_supply_low_1v8_mclk_e, "Supply error form master clock (1V8)"						 },
		{ rfe_fuSaFault_sr39_dig_freq_mclk_e, "Error indicating master clock digital ouput frequency not in range"	 },
		{ rfe_fuSaFault_sr35_pll_lock_mclk_e, "Error indicating Pll in unlock condition"							 },
		{ rfe_fuSaFault_sr57_supply_high_1v1_gldo_e, "Global 1V1 LDO supply high sensor error"						 },
		{ rfe_fuSaFault_sr59_supply_low_1v1_gldo_e, "Global 1V1 LDO supply low sensor error"						 },
		{ rfe_fuSaFault_sr61_supply_high_1v8_gldo_e, "Global 1V8 LDO supply high sensor error"						 },
		{ rfe_fuSaFault_sr63_supply_low_1v8_gldo_e, "Global 1V8 LDO supply low sensor error"						 },
		{ rfe_fuSaFault_sr65_67_supply_low_1v8_ser_e, "Supply 1V8 low sensor error for serializer"					 },
		{ rfe_fuSaFault_sr65_67_supply_low_1v1_csi2_e, "Supply 1V1 low sensor error for serializer CSI2"			 },
		{ rfe_fuSaFault_sr65_67_supply_low_1v1_ser_e, "Supply 1V1 low sensor error for serializer digital and LVDS"	 },
		{ rfe_fuSaFault_sr65_67_supply_low_1v8_gbias_e, "Supply 1V8 low sensor error for global bias"				 },
		{ rfe_fuSaFault_sr65_67_supply_low_1v8_ssb_e, "Supply 1V8 low sensor error for SSB MOD"				 },
		{ rfe_fuSaFault_sr65_67_supply_low_1v8_adc34_e, "Supply low (1v8) for ADC34"						 },
		{ rfe_fuSaFault_sr65_67_supply_low_1v8_adc12_e, "Supply low (1v8) for ADC12"						 },
		{ rfe_fuSaFault_sr34_cal_adc4_e, "Calibration error for ADC4"										 },
		{ rfe_fuSaFault_sr34_cal_adc3_e, "Calibration error for ADC3"										 },
		{ rfe_fuSaFault_sr34_cal_adc2_e, "Calibration error for ADC2"										 },
		{ rfe_fuSaFault_sr34_cal_adc1_e, "Calibration error for ADC1"										 },
		{ rfe_fuSaFault_sr3_reg_crc_e, "Register CRC error"													 },
		{ rfe_fuSaFault_sr31_bist_lna_gaindiff_sw_e, "RFBIST LNA gain test error"							 },
		{ rfe_fuSaFault_sr31_bist_lna_phasediff_sw_e, "RFBIST LNA phase test error"							 },
		{ rfe_fuSaFault_sr31_bist_mixer_gaindiff_sw_e, "RFBIST mixer gain test error"						 },
		{ rfe_fuSaFault_sr31_bist_mixer_phasediff_sw_e, "RFBIST mixer phase test error"						 },
		{ rfe_fuSaFault_sr44_cafc_integrity_level_sw_e, "CAFC level detector integrity check error"			 },
		{ rfe_fuSaFault_sr44_cafc_integrity_unlock_sw_e, "CAFC unlock detector integrity check error"		 },
		{ rfe_fuSaFault_sr44_cafc_integrity_sw_e, "CAFC integrity check error"								 },
		{ rfe_fuSaFault_sr70_tx_integrity_sw_e, "TX integrity check error "									 },
		{ rfe_fuSaFault_sr72_tx_pr_cal_sw_e, "TX phase rotator calibration check error "					 },
		{ rfe_fuSaFault_sr72_tx1_pr_cal_sw_e, "TX1 phase rotator calibration check error"					 },
		{ rfe_fuSaFault_sr72_tx2_pr_cal_sw_e, "TX2 phase rotator calibration check error"					 },
		{ rfe_fuSaFault_sr72_tx3_pr_cal_sw_e, "TX3 phase rotator calibration check error"					 },
		{ rfe_fuSaFault_sr14_disable_lb_toggle_test_sw_e, "Disable loopback toggle test"					 },
		{ rfe_fuSaFault_sr13_input_mode_toggle_test_sw_e, "Input mode toggle test "							 },
		{ rfe_generic_sw_e, "SW generic error"	 }
};

static const string_list_t gsRfeErrorDescriptors[] = {
		{ rfe_error_none_e, "rfe_error_none_e" },
		{ rfe_error_api_unresponsive_e, "rfe_error_api_unresponsive_e" },
		{ rfe_error_api_unsynchronized_e, "rfe_error_api_unsynchronized_e" },
		{ rfe_error_api_operationNotAllowed_e, "rfe_error_api_operationNotAllowed_e" },
		{ rfe_error_api_busy_e, "rfe_error_api_busy_e" },
		{ rfe_error_api_invalidArgumentValue_e, "rfe_error_api_invalidArgumentValue_e" },
		{ rfe_error_api_invalidConfigurationSize_e, "rfe_error_api_invalidConfigurationSize_e" },
		{ rfe_error_api_invalidConfigurationParameterValue_e, "rfe_error_api_invalidConfigurationParameterValue_e" },
		{ rfe_error_api_invalidDynamicTableSize_e, "rfe_error_api_invalidDynamicTableSize_e" },
		{ rfe_error_api_invalidDynamicTableValue_e, "rfe_error_api_invalidDynamicTableValue_e" },
		{ rfe_error_api_noUpdatesBuffered_e, "rfe_error_api_noUpdatesBuffered_e" },
		{ rfe_error_api_maxUpdateCountExceeded_e, "rfe_error_api_maxUpdateCountExceeded_e" },
		{ rfe_error_api_updateAlreadyPending_e, "rfe_error_api_updateAlreadyPending_e" },
		{ rfe_error_api_invalidParameterForUpdate_e, "rfe_error_api_invalidParameterForUpdate_e" },
		{ rfe_error_api_dynamicTablesNotConfigured_e, "rfe_error_api_dynamicTablesNotConfigured_e" },
		{ rfe_error_api_cfgSectionMismatch_external_e, "rfe_error_api_cfgSectionMismatch_external_e" },
		{ rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e, "rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e" },
		{ rfe_error_api_invalidRadarCycleTimeSchedule_e, "rfe_error_api_invalidRadarCycleTimeSchedule_e" },
		{ rfe_error_api_configParamCrossCheck_dwellSettleTimeTooShort_e, "rfe_error_api_configParamCrossCheck_dwellSettleTimeTooShort_e" },
		{ rfe_error_api_configParamCrossCheck_acqJumpbackResetTimeTooShort_e, "rfe_error_api_configParamCrossCheck_acqJumpbackResetTimeTooShort_e" },
		{ rfe_error_api_configParamCrossCheck_chirpIntervalTimeTooShort_e, "rfe_error_api_configParamCrossCheck_chirpIntervalTimeTooShort_e" },
		{ rfe_error_api_configParamCrossCheck_unconfiguredChirpSequence_e, "rfe_error_api_configParamCrossCheck_unconfiguredChirpSequence_e" },
		{ rfe_error_api_configParamCrossCheck_unconfiguredChirpProfile_e, "rfe_error_api_configParamCrossCheck_unconfiguredChirpProfile_e" },
		{ rfe_error_api_configParamCrossCheck_unconfiguredDynamicTable_e, "rfe_error_api_configParamCrossCheck_unconfiguredDynamicTable_e" },
		{ rfe_error_api_invalidConfigurationVersion_e, "rfe_error_api_invalidConfigurationVersion_e" },
		{ rfe_error_api_invalidFrontendId_e, "rfe_error_api_invalidFrontendId_e" },
		{ rfe_error_api_function_not_implemented_e, "rfe_error_api_function_not_implemented_e" },
		{ rfe_error_api_fsm_was_started_e, "rfe_error_api_fsm_was_started_e" },
		{ rfe_error_api_invalid_num_frontends_e, "rfe_error_api_invalid_num_frontends_e" },
		{ rfe_error_api_invalid_frontends_conf_e, "rfe_error_api_invalid_frontends_conf_e" },

		/* CMD Interface Errors [EXTERNAL] 100-199 */
		{ rfe_error_cmdInterface_invalidCmdId_e, "rfe_error_cmdInterface_invalidCmdId_e" },
		{ rfe_error_cmdInterface_invalidCmdLength_e, "rfe_error_cmdInterface_invalidCmdLength_e" },
		{ rfe_error_cmdInterface_invalidRspLength_e, "rfe_error_cmdInterface_invalidRspLength_e" },
		{ rfe_error_cmdInterface_invalidCrc_e, "rfe_error_cmdInterface_invalidCrc_e" },
		{ rfe_error_cmdInterface_invalidResponse_e, "rfe_error_cmdInterface_invalidResponse_e" },
		{ rfe_error_cmdInterface_invalidConfigCmdSequencing_e, "rfe_error_cmdInterface_invalidConfigCmdSequencing_e" },

		/* Shared Data Errors [EXTERNAL] 200-299 */
		{ rfe_error_sharedData_invalidIndex_e, "rfe_error_sharedData_invalidIndex_e" },
		{ rfe_error_sharedData_redundancyCheckFailed_e, "rfe_error_sharedData_redundancyCheckFailed_e" },

		/* FW Internal Errors [INTERNAL]*/
		{ rfe_error_rfeFuSaFault_e, "rfe_error_rfeFuSaFault_e" },
		{ rfe_error_undefined_e, "rfe_error_undefined_e" },
		{ rfe_error_rfeInErrorState_e, "rfe_error_rfeInErrorState_e" },
		{ rfe_error_invalidPointer_e, "rfe_error_invalidPointer_e" },
		{ rfe_error_parameterOutOfRange_e, "rfe_error_parameterOutOfRange_e" },
		{ rfe_error_saturationInOperation_e, "rfe_error_saturationInOperation_e" },
		{ rfe_error_invalidSamplesNumber_e, "rfe_error_invalidSamplesNumber_e" },
		{ rfe_error_sharedMemoryAddresOverlapping_e, "rfe_error_sharedMemoryAddresOverlapping_e" },
		{ rfe_error_addressOutOfValidSharedMemory_e, "rfe_error_addressOutOfValidSharedMemory_e" },
		{ rfe_error_unknown_ip_e, "rfe_error_unknown_ip_e" },
		{ rfe_error_1_e, "rfe_error_1_e" },
		{ rfe_error_2_e, "rfe_error_2_e" },
		{ rfe_error_3_e, "rfe_error_3_e" },
		{ rfe_error_cmdServerInternal_no_cmd_received_e, "rfe_error_cmdServerInternal_no_cmd_received_e" },
		{ rfe_error_cmdServerDft_invalidParam_e, "rfe_error_cmdServerDft_invalidParam_e" },
		{ rfe_error_cmdServerInternal_undefined_cmd_handler_e, "rfe_error_cmdServerInternal_undefined_cmd_handler_e" },
		{ rfe_error_cmdServerInternal_out_of_seq_e, "rfe_error_cmdServerInternal_out_of_seq_e" },
		{ rfe_error_cmdServerInternal_resplen_wrong_e, "rfe_error_cmdServerInternal_resplen_wrong_e" },
		{ rfe_error_cmdServerInternal_cmdbuf_overflow_e, "rfe_error_cmdServerInternal_cmdbuf_overflow_e" },
		{ rfe_error_utils_memcpy_range_error_e, "rfe_error_utils_memcpy_range_error_e" },
		{ rfe_error_notAnExternalErrorCode_e, "rfe_error_notAnExternalErrorCode_e" },
		{ rfe_error_uninitialized_e, "rfe_error_uninitialized_e" },
		{ rfe_error_invalidShiftingParam_e, "rfe_error_invalidShiftingParam_e" },
		{ rfe_error_invalidFractionBits_e, "rfe_error_invalidFractionBits_e" },
		{ rfe_error_nullPointer_e, "rfe_error_nullPointer_e" },
		{ rfe_error_invalidValue_e, "rfe_error_invalidValue_e" },
		{ rfe_error_notYetImplemented_e, "rfe_error_notYetImplemented_e" },
		{ rfe_error_invalidFlexIOConfig_e, "rfe_error_invalidFlexIOConfig_e" },
		{ rfe_error_invalidRfeAccessCsrConfig_e, "rfe_error_invalidRfeAccessCsrConfig_e" },
		{ rfe_error_fit1ProcedureFailed_e, "rfe_error_fit1ProcedureFailed_e" },
		{ rfe_error_fit2ProcedureFailed_e, "rfe_error_fit2ProcedureFailed_e" },
		{ rfe_error_fic1ProcedureFailed_e, "rfe_error_fic1ProcedureFailed_e" },
		{ rfe_error_fic2ProcedureFailed_e, "rfe_error_fic2ProcedureFailed_e" },
		{ rfe_error_noSpaceLeftinSharedMemory_e, "rfe_error_noSpaceLeftinSharedMemory_e" },
		{ rfe_error_histogramWrongXAxisLimit_e, "rfe_error_histogramWrongXAxisLimit_e" },
		{ rfe_error_histogramWrongOutputSize_e, "rfe_error_histogramWrongOutputSize_e" },
		{ rfe_error_invalidADCNumberOfBits_e , "rfe_error_invalidADCNumberOfBits_e " },
		{ rfe_error_fftSamplesCountNot2Multiple_e, "rfe_error_fftSamplesCountNot2Multiple_e" },
		{ rfe_error_fftNumberOfAveragesOutOfBounds_e, "rfe_error_fftNumberOfAveragesOutOfBounds_e" },
		{ rfe_error_fftInvalidOutputSelected_e, "rfe_error_fftInvalidOutputSelected_e" },
		{ rfe_error_fftSamplesCountAndNumberOfAveragesNotMultiples_e, "rfe_error_fftSamplesCountAndNumberOfAveragesNotMultiples_e" },
		{ rfe_error_fftNotSupported_e, "rfe_error_fftNotSupported_e" },
		{ rfe_error_dftSamplesCountNot2Multiple_e, "rfe_error_dftSamplesCountNot2Multiple_e" },
		{ rfe_error_dftNumberOfAveragesOutOfBounds_e, "rfe_error_dftNumberOfAveragesOutOfBounds_e" },
		{ rfe_error_dftInvalidOutputSelected_e, "rfe_error_dftInvalidOutputSelected_e" },
		{ rfe_error_dftSamplesCountAndNumberOfAveragesNotMultiples_e, "rfe_error_dftSamplesCountAndNumberOfAveragesNotMultiples_e" },
		{ rfe_error_dftNotSupported_e, "rfe_error_dftNotSupported_e" },
		{ rfe_error_dftOnlySingleBinSupported_e, "rfe_error_dftOnlySingleBinSupported_e" },
		{ rfe_error_dftRealOnlySupported_e, "rfe_error_dftRealOnlySupported_e" },
		{ rfe_error_api_cfgInvalidParameterSize_e, "rfe_error_api_cfgInvalidParameterSize_e" },
		{ rfe_error_param_invalidParam_e , "rfe_error_param_invalidParam_e " },
		{ rfe_error_param_invalidValue_e , "rfe_error_param_invalidValue_e " },
		{ rfe_error_api_cfgSectionMismatch_e, "rfe_error_api_cfgSectionMismatch_e" },
		{ rfe_error_timerInUse_e, "rfe_error_timerInUse_e" },
		{ rfe_error_boundedWaitResourcesExhausted_e, "rfe_error_boundedWaitResourcesExhausted_e" },
		{ rfe_error_chirpPllVcoCalibrationFailed_e, "rfe_error_chirpPllVcoCalibrationFailed_e" },
		{ rfe_error_atbInvalidAtbMaster_e, "rfe_error_atbInvalidAtbMaster_e" },
		{ rfe_error_atbInvalidTrimmingSelectedResistor_e, "rfe_error_atbInvalidTrimmingSelectedResistor_e" },
		{ rfe_error_atbInvalidOperationalMode_e, "rfe_error_atbInvalidOperationalMode_e" },
		{ rfe_error_atbModeOfOperationNotSet_e, "rfe_error_atbModeOfOperationNotSet_e" },
		{ rfe_error_atbCurrentMeasurementWithoutResistors_e, "rfe_error_atbCurrentMeasurementWithoutResistors_e" },
		{ rfe_error_atbNotSupported_e, "rfe_error_atbNotSupported_e" },
		{ rfe_error_atbCrossSwitchNotEnabled_e, "rfe_error_atbCrossSwitchNotEnabled_e" },
		{ rfe_error_atbBandGapNotStarted_e, "rfe_error_atbBandGapNotStarted_e" },
		{ rfe_error_atbBandGapInvalidVout_e, "rfe_error_atbBandGapInvalidVout_e" },
		{ rfe_error_atbInvalidPullDownInput_e, "rfe_error_atbInvalidPullDownInput_e" },
		{ rfe_error_atbInvalidAdcInputDiffMode_e, "rfe_error_atbInvalidAdcInputDiffMode_e" },
		{ rfe_error_atbInvalidAdcSelSingleMode_e, "rfe_error_atbInvalidAdcSelSingleMode_e" },
		{ rfe_error_atbInvalidAdcSingleModeGround_e, "rfe_error_atbInvalidAdcSingleModeGround_e" },
		{ rfe_error_atbAdcNotInSingleMode_e, "rfe_error_atbAdcNotInSingleMode_e" },
		{ rfe_error_atbAdcNotConfiguredToSample_e, "rfe_error_atbAdcNotConfiguredToSample_e" },
		{ rfe_error_atbAdcInvalidAveragingSamples_e, "rfe_error_atbAdcInvalidAveragingSamples_e" },
		{ rfe_error_hwPitNotInitialized_e, "rfe_error_hwPitNotInitialized_e" },
		{ rfe_error_boundedWaitNotValidResource_e, "rfe_error_boundedWaitNotValidResource_e" },
		{ rfeError_error_api_TimerInUse_e, "rfeError_error_api_TimerInUse_e" },
		{ rfeError_error_api_boundedWaitResourcesExhausted_e, "rfeError_error_api_boundedWaitResourcesExhausted_e" },
		{ rfe_error_rx1SaturationStatusReadingFailure_e, "rfe_error_rx1SaturationStatusReadingFailure_e" },
		{ rfe_error_rx2SaturationStatusReadingFailure_e, "rfe_error_rx2SaturationStatusReadingFailure_e" },
		{ rfe_error_rx3SaturationStatusReadingFailure_e, "rfe_error_rx3SaturationStatusReadingFailure_e" },
		{ rfe_error_rx4SaturationStatusReadingFailure_e, "rfe_error_rx4SaturationStatusReadingFailure_e" },
		{ rfe_error_txInvalidSubcomponent_e, "rfe_error_txInvalidSubcomponent_e" },
		{ rfe_error_txInvalidPowerProfile_e, "rfe_error_txInvalidPowerProfile_e" },
		{ rfe_error_txGainBuf2AExceedRange_e, "rfe_error_txGainBuf2AExceedRange_e" },
		{ rfe_error_txGainBuf2BCExceedRange_e, "rfe_error_txGainBuf2BCExceedRange_e" },
		{ rfe_error_txPaGainCExceedRange_e, "rfe_error_txPaGainCExceedRange_e" },
		{ rfe_error_txInvalidCalibrationFSMState_e, "rfe_error_txInvalidCalibrationFSMState_e" },
		{ rfe_error_txInvalidAdcConnection_e, "rfe_error_txInvalidAdcConnection_e" },
		{ rfe_error_txIndexInvalid_e, "rfe_error_txIndexInvalid_e" },
		{ rfe_error_txPRPhaseExceedRange_e, "rfe_error_txPRPhaseExceedRange_e" },
		{ rfe_error_dynamicProgrammingDuringAcquisition_e, "rfe_error_dynamicProgrammingDuringAcquisition_e" },
		{ rfe_error_pcdIndexInvalid_e, "rfe_error_pcdIndexInvalid_e" },
		{ rfe_error_pcdSamplingFrequencyInvalid_e, "rfe_error_pcdSamplingFrequencyInvalid_e" },
		{ rfe_error_pcdProfileIndexInvalid_e, "rfe_error_pcdProfileIndexInvalid_e" },
		{ rfe_error_pcdPhaseCorrectionInvalid_e, "rfe_error_pcdPhaseCorrectionInvalid_e" },
		{ rfe_error_pcdSlectedInputNotImplemented_e, "rfe_error_pcdSlectedInputNotImplemented_e" },
		{ rfe_error_pcdCorrelatorIntegrationTimeInvalid_e, "rfe_error_pcdCorrelatorIntegrationTimeInvalid_e" },
		{ rfe_error_distrGroupDoesNotExist_e, "rfe_error_distrGroupDoesNotExist_e" },
		{ rfe_error_invalidRadarCycleTiming_e, "rfe_error_invalidRadarCycleTiming_e" },
		{ rfe_error_mainFsm_eventAlreadyActive_e, "rfe_error_mainFsm_eventAlreadyActive_e" },
		{ rfe_error_radarCycleFsm_stateEndTimeExceeded_e, "rfe_error_radarCycleFsm_stateEndTimeExceeded_e" },
		{ rfe_error_mainFsm_eventNotAllowed_e, "rfe_error_mainFsm_eventNotAllowed_e" },
		{ rfe_error_chirpStartedTooEarly_e, "rfe_error_chirpStartedTooEarly_e" },
		{ rfe_error_mainFsm_chirpStartInterruptTimeout_e, "rfe_error_mainFsm_chirpStartInterruptTimeout_e" },
		{ rfe_error_mainFsm_chirpSequenceEndInterruptTimeout_e, "rfe_error_mainFsm_chirpSequenceEndInterruptTimeout_e" },
		{ rfe_error_mainFsm_chirpAcquisitionStartInterruptTimeout_e, "rfe_error_mainFsm_chirpAcquisitionStartInterruptTimeout_e" },
		{ rfe_error_mainFsm_mcgenAdpllNotLocked_e, "rfe_error_mainFsm_mcgenAdpllNotLocked_e" },
		{ rfe_error_tSenseInvalidModeOfOperation_e, "rfe_error_tSenseInvalidModeOfOperation_e" },
		{ rfe_error_tSenseInvalidResolutionTime_e, "rfe_error_tSenseInvalidResolutionTime_e" },
		{ rfe_error_tSenseConversionInProgress_e, "rfe_error_tSenseConversionInProgress_e" },
		{ rfe_error_tSenseInvalidOverUndeThresholds_e, "rfe_error_tSenseInvalidOverUndeThresholds_e" },
		{ rfe_error_tSenseInvalidWarningThreshold_e, "rfe_error_tSenseInvalidWarningThreshold_e" },
		{ rfe_error_tSenseInvalidHysteresisThreshold_e, "rfe_error_tSenseInvalidHysteresisThreshold_e" },
		{ rfe_error_tSenseDivisionByZero_e, "rfe_error_tSenseDivisionByZero_e" },
		{ rfe_error_rxAdcModuleIdUnidentified_e, "rfe_error_rxAdcModuleIdUnidentified_e" },
		{ rfe_error_rxAdcInputUnidentified_e, "rfe_error_rxAdcInputUnidentified_e" },
		{ rfe_error_chirpPllLoopfilterC1NotOk_e, "rfe_error_chirpPllLoopfilterC1NotOk_e" },
		{ rfe_error_chirpPllLoopfilterC2FastNotOk_e, "rfe_error_chirpPllLoopfilterC2FastNotOk_e" },
		{ rfe_error_chirpPllLoopfilterC2SlowNotOk_e, "rfe_error_chirpPllLoopfilterC2SlowNotOk_e" },
		{ rfe_error_chirpPllLoopfilterC3FastNotOk_e, "rfe_error_chirpPllLoopfilterC3FastNotOk_e" },
		{ rfe_error_chirpPllLoopfilterC3SlowNotOk_e, "rfe_error_chirpPllLoopfilterC3SlowNotOk_e" },
		{ rfe_error_chirpPllLoopfilterR1NotOk_e, "rfe_error_chirpPllLoopfilterR1NotOk_e" },
		{ rfe_error_chirpPllLoopfilterR2NotOk_e, "rfe_error_chirpPllLoopfilterR2NotOk_e" },
		{ rfe_error_chirpPllLoopfilterCpNotOk_e, "rfe_error_chirpPllLoopfilterCpNotOk_e" },
		{ rfe_error_atbInvalidAtbAdc_e, "rfe_error_atbInvalidAtbAdc_e" },
		{ rfe_error_atbInvalidAtbAdcGainMode_e, "rfe_error_atbInvalidAtbAdcGainMode_e" },
		{ rfe_error_chirpPllBandgapNotOk_e, "rfe_error_chirpPllBandgapNotOk_e" },
		{ rfe_error_chirpPllHvLdoVcoNotOk_e, "rfe_error_chirpPllHvLdoVcoNotOk_e" },
		{ rfe_error_chirpPllHvLdoCpNotOk_e, "rfe_error_chirpPllHvLdoCpNotOk_e" },
		{ rfe_error_chirpPllPdivLdoNotOk_e, "rfe_error_chirpPllPdivLdoNotOk_e" },
		{ rfe_error_chirpPllLvLdoNotOk_e, "rfe_error_chirpPllLvLdoNotOk_e" },
		{ rfe_error_rxCalibrationTargetInvalid_e, "rfe_error_rxCalibrationTargetInvalid_e" },
		{ rfe_error_rxCalibrationIfStageInvalid_e, "rfe_error_rxCalibrationIfStageInvalid_e" },
		{ rfe_error_mcgen0v9AnaNotOk_e, "rfe_error_mcgen0v9AnaNotOk_e" },
		{ rfe_error_mcgenXoDetPllClkError_e, "rfe_error_mcgenXoDetPllClkError_e" },
		{ rfe_error_mcgenAdpllOutVdd0v9DigNotOk_e, "rfe_error_mcgenAdpllOutVdd0v9DigNotOk_e" },
		{ rfe_error_mcgenAdpllLockDetNotLocked_e, "rfe_error_mcgenAdpllLockDetNotLocked_e" },
		{ rfe_error_initRtmErrorReported, "rfe_error_initRtmErrorReported" },
		{ rfe_error_initMcgen0v9AnaNotOk_e, "rfe_error_initMcgen0v9AnaNotOk_e" },
		{ rfe_error_rxTargetSettingsCombinationIsNotSupported_e, "rfe_error_rxTargetSettingsCombinationIsNotSupported_e" },
		{ rfe_error_didt_test_failure_e, "rfe_error_didt_test_failure_e" },
		{ rfe_error_testBufferOverflow_e, "rfe_error_testBufferOverflow_e" },
		{ rfe_error_chirpPllVcoCalAmpOutOfRange_e, "rfe_error_chirpPllVcoCalAmpOutOfRange_e" },
		{ rfe_error_lpUartNotActive_e, "rfe_error_lpUartNotActive_e" },
		{ rfe_error_txPrCalibrationTimeout_e, "rfe_error_txPrCalibrationTimeout_e" },
		{ rfe_error_registerComparisonFailed_e, "rfe_error_registerComparisonFailed_e" },
		{ rfe_error_spiTransactionError_e, "rfe_error_spiTransactionError_e" },
		{ rfe_error_spiTransactionTimeout_e, "rfe_error_spiTransactionTimeout_e" },
		{ rfe_error_HwRegister_lock_e, "rfe_error_HwRegister_lock_e" },
		{ rfe_error_startup_seq_failed_e, "rfe_error_startup_seq_failed_e" },
		{ rfe_error_csi2PllLockTimeOut_e, "rfe_error_csi2PllLockTimeOut_e" },
		{ rfe_error_csi2PllcalibrationTimeOut_e, "rfe_error_csi2PllcalibrationTimeOut_e" },
		{ rfe_error_fcc_e, "rfe_error_fcc_e" },
		{ rfe_error_ppdVoutAboveMax_e, "rfe_error_ppdVoutAboveMax_e" },
		{ rfe_error_initLldoPdcPowerNotOk_e, "rfe_error_initLldoPdcPowerNotOk_e" },
		{ rfe_error_atbInvalidInputSource_e, "rfe_error_atbInvalidInputSource_e" },
		{ rfe_error_atbAdcNoCalibrated_e, "rfe_error_atbAdcNoCalibrated_e" },
		{ rfe_error_bistZeroHourDataNotGenerated_e, "rfe_error_bistZeroHourDataNotGenerated_e" },
		{ rfe_error_rxbistParameterOutOfRange_e, "rfe_error_rxbistParameterOutOfRange_e" },
		{ rfe_error_wdmaIncorrectStreamSelected_e, "rfe_error_wdmaIncorrectStreamSelected_e" },
		{ rfe_error_wdmaBufferOutOfBounds_e, "rfe_error_wdmaBufferOutOfBounds_e" },
		{ rfe_error_wdmaBufferAddressNotAligned_e, "rfe_error_wdmaBufferAddressNotAligned_e" },
		{ rfe_error_wdmaBurstLengthOutOfBounds_e, "rfe_error_wdmaBurstLengthOutOfBounds_e" },
		{ rfe_error_wdmaWrongValueForaxiBurstModeField_e, "rfe_error_wdmaWrongValueForaxiBurstModeField_e" },
		{ rfe_error_wdmaBufferAddressNotSet_e, "rfe_error_wdmaBufferAddressNotSet_e" },
		{ rfe_error_wdmaBufferLengthNotSet_e, "rfe_error_wdmaBufferLengthNotSet_e" },
		{ rfe_error_wdmaBufferOverwriteModeNotSet_e, "rfe_error_wdmaBufferOverwriteModeNotSet_e" },
		{ rfe_error_wdmaAxiBurstLengthNotSet_e, "rfe_error_wdmaAxiBurstLengthNotSet_e" },
		{ rfe_error_wdmaAxiBurstModeNotSet_e, "rfe_error_wdmaAxiBurstModeNotSet_e" },
		{ rfe_error_wdmaIncorrectInterruptSourceSelected_e, "rfe_error_wdmaIncorrectInterruptSourceSelected_e" },
		{ rfe_error_wdmaIncorrectNumberOfStreamsSelected_e, "rfe_error_wdmaIncorrectNumberOfStreamsSelected_e" },
		{ rfe_error_rxIfCalibrationInvalidRcCode_e, "rfe_error_rxIfCalibrationInvalidRcCode_e" },
		{ rfe_error_rxInvalidRcCode_e, "rfe_error_rxInvalidRcCode_e" },
		{ rfe_error_rxbistInvalidSsbCode_e, "rfe_error_rxbistInvalidSsbCode_e" },
		{ rfe_error_rxIfCalibrationInvalidChannel, "rfe_error_rxIfCalibrationInvalidChannel" },
		{ rfe_error_rxIfCalibrationFailed, "rfe_error_rxIfCalibrationFailed" },
		{ rfe_error_rxIfCalibrationInvalidSettings, "rfe_error_rxIfCalibrationInvalidSettings" },

		// ***** General Error BC Codes (0x50xxxu) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_inputOutOfRange, "rfe_error_bc_inputOutOfRange" },
		{ rfe_error_bc_funcNoExist, "rfe_error_bc_funcNoExist" },
		{ rfe_error_bc_failToInjectCrcErr, "rfe_error_bc_failToInjectCrcErr" },
		{ rfe_error_bc_wrongInterface, "rfe_error_bc_wrongInterface" },
		{ rfe_error_bc_ipDisabled, "rfe_error_bc_ipDisabled" },

		// ***** SYS Error Codes (0x51xxx) *****
		{ rfe_error_bc_sys_ipHasNoAtbConnection, "rfe_error_bc_sys_ipHasNoAtbConnection" },
		{ rfe_error_bc_sys_cannotFindCafcDacCode, "rfe_error_bc_sys_cannotFindCafcDacCode" },
		{ rfe_error_bc_sys_adcInvalid, "rfe_error_bc_sys_adcInvalid" },
		{ rfe_error_bc_sys_fileError, "rfe_error_bc_sys_fileError" },
		{ rfe_error_bc_sys_jsonStringNoExisted, "rfe_error_bc_sys_jsonStringNoExisted" },
		{ rfe_error_bc_sys_txTempReadTimeout, "rfe_error_bc_sys_txTempReadTimeout" },
		{ rfe_error_bc_sys_mclkIntegrityFailed, "rfe_error_bc_sys_mclkIntegrityFailed" },
		{ rfe_error_bc_sys_wrongAppconfig, "rfe_error_bc_sys_wrongAppconfig" },
		{ rfe_error_bc_sys_invalidInput, "rfe_error_bc_sys_invalidInput" },
		{ rfe_error_bc_sys_wrongProfileNoRecovery, "rfe_error_bc_sys_wrongProfileNoRecovery" },
		{ rfe_error_bc_sys_errorRecoveryFailed, "rfe_error_bc_sys_errorRecoveryFailed" },
		{ rfe_error_bc_sys_cafcIntegrityCheckLevel, "rfe_error_bc_sys_cafcIntegrityCheckLevel" },
		{ rfe_error_bc_sys_cafcIntegrityCheckUnlock, "rfe_error_bc_sys_cafcIntegrityCheckUnlock" },
		{ rfe_error_bc_sys_wrongDataInterfaceConfig, "rfe_error_bc_sys_wrongDataInterfaceConfig" },
		{ rfe_error_bc_sys_error_N, "rfe_error_bc_sys_error_N" },
		{ rfe_error_bc_sys_invalidProfile, "rfe_error_bc_sys_invalidProfile" },
		{ rfe_error_bc_sys_faultInjectionFail, "rfe_error_bc_sys_faultInjectionFail" },
		{ rfe_error_bc_sys_wrongMidNoRecovery, "rfe_error_bc_sys_wrongMidNoRecovery" },
		{ rfe_error_bc_sys_spiAccessCheckFail, "rfe_error_bc_sys_spiAccessCheckFail" },
		{ rfe_error_bc_sys_cafcTempReadTimeout, "rfe_error_bc_sys_cafcTempReadTimeout" },
		{ rfe_error_bc_sys_slaveWrongAppConfig, "rfe_error_bc_sys_slaveWrongAppConfig" },
		{ rfe_error_bc_sys_subBandIncOutOfRange, "rfe_error_bc_sys_subBandIncOutOfRange" },
		{ rfe_error_bc_sys_ptrAddrNull, "rfe_error_bc_sys_ptrAddrNull" },
		{ rfe_error_bc_sys_aafcAutoNotSupported, "rfe_error_bc_sys_aafcAutoNotSupported" },
		{ rfe_error_bc_sys_rawNumSampleInvalid, "rfe_error_bc_sys_rawNumSampleInvalid" },
		{ rfe_error_bc_sys_invalidResetTime, "rfe_error_bc_sys_invalidResetTime" },
		{ rfe_error_bc_sys_totalBwOutOfRange, "rfe_error_bc_sys_totalBwOutOfRange" },
		{ rfe_error_bc_sys_cafcIntegrityCheckFailed, "rfe_error_bc_sys_cafcIntegrityCheckFailed" },
		{ rfe_error_bc_sys_restoreChirpGlobalFailed, "rfe_error_bc_sys_restoreChirpGlobalFailed" },
		{ rfe_error_bc_sys_regCrcIsmModuleErrorSet, "rfe_error_bc_sys_regCrcIsmModuleErrorSet" },
		{ rfe_error_bc_sys_regCrcTriggerFailed, "rfe_error_bc_sys_regCrcTriggerFailed" },
		{ rfe_error_bc_sys_txCtrlEnableWriteCheckBase, "rfe_error_bc_sys_txCtrlEnableWriteCheckBase" },
		{ rfe_error_bc_sys_tx1CtrlEnableWriteCheck, "rfe_error_bc_sys_tx1CtrlEnableWriteCheck" },
		{ rfe_error_bc_sys_tx2CtrlEnableWriteCheck, "rfe_error_bc_sys_tx2CtrlEnableWriteCheck" },
		{ rfe_error_bc_sys_tx1Tx2CtrlEnableWriteCheck, "rfe_error_bc_sys_tx1Tx2CtrlEnableWriteCheck" },
		{ rfe_error_bc_sys_tx3CtrlEnableWriteCheck, "rfe_error_bc_sys_tx3CtrlEnableWriteCheck" },
		{ rfe_error_bc_sys_tx1Tx3CtrlEnableWriteCheck, "rfe_error_bc_sys_tx1Tx3CtrlEnableWriteCheck" },
		{ rfe_error_bc_sys_tx2Tx3CtrlEnableWriteCheck, "rfe_error_bc_sys_tx2Tx3CtrlEnableWriteCheck" },
		{ rfe_error_bc_sys_tx1Tx2Tx3CtrlEnableWriteCheck, "rfe_error_bc_sys_tx1Tx2Tx3CtrlEnableWriteCheck" },
		{ rfe_error_bc_sys_loiInBallBreakDetected, "rfe_error_bc_sys_loiInBallBreakDetected" },
		{ rfe_error_bc_sys_loiOutBallBreakDetected, "rfe_error_bc_sys_loiOutBallBreakDetected" },

		// ***** ALG Error Codes (0x52xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_algDummyError, "rfe_error_bc_algDummyError" },

		// **** BC_SPI Error Codes (0x53xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_spiWriteReadCrcError, "rfe_error_bc_spiWriteReadCrcError" },
		{ rfe_error_bc_spiWriteCheckFail, "rfe_error_bc_spiWriteCheckFail" },
		{ rfe_error_bc_readFail, "rfe_error_bc_readFail" },
		//0x54xxx is used by PLF layer.

		// ***** CC Error Codes (0x60xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_ccSysConfNotSet, "rfe_error_bc_ccSysConfNotSet" },
		{ rfe_error_bc_ccPtrAddrNull, "rfe_error_bc_ccPtrAddrNull" },

		// ***** LVDS Error Codes (0x61xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		/// LVDS test mode setting is incorrect
		{ rfe_error_bc_lvdsInvalidInput, "rfe_error_bc_lvdsInvalidInput" },
		{ rfe_error_bc_lvdsPtrAddrNull, "rfe_error_bc_lvdsPtrAddrNull" },
		{ rfe_error_bc_lvdsSammplesShiftInvalid, "rfe_error_bc_lvdsSammplesShiftInvalid" },
		{ rfe_error_bc_lvdsClkEdgeInvalid, "rfe_error_bc_lvdsClkEdgeInvalid" },
		{ rfe_error_bc_lvdsAdcClkFromInvalid, "rfe_error_bc_lvdsAdcClkFromInvalid" },
		{ rfe_error_bc_lvdsFreqCounterDeviation, "rfe_error_bc_lvdsFreqCounterDeviation" },
		{ rfe_error_bc_lvdsCountPeriodInvalid, "rfe_error_bc_lvdsCountPeriodInvalid" },
		/// Busy wait read of Frequency Counter register failed after max retries
		{ rfe_error_bc_lvdsFreqCountTimeout, "rfe_error_bc_lvdsFreqCountTimeout" },
		/// Restoring of the frequency counter register failed
		{ rfe_error_bc_lvdsrestoreFreqCounter, "rfe_error_bc_lvdsrestoreFreqCounter" },

		// ***** MIPI Error Codes (0x62xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_mipiDeviceReadyTimeout, "rfe_error_bc_mipiDeviceReadyTimeout" },
		/// Busy wait read of Frequency Counter register failed after max retries
		{ rfe_error_bc_mipiFreqCountTimeout, "rfe_error_bc_mipiFreqCountTimeout" },
		/// CountPeriod Period in us for doing the frequency measurement is out of range
		{ rfe_error_bc_mipiFreqCntOutOfRange, "rfe_error_bc_mipiFreqCntOutOfRange" },
		{ rfe_error_bc_mipiPtrAddrNull, "rfe_error_bc_mipiPtrAddrNull" },
		/// Restoring of the frequency counter register failed
		{ rfe_error_bc_mipiRestoreFreqCounter, "rfe_error_bc_mipiRestoreFreqCounter" },

		// ***** TE Error Codes (0x64xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_tePrSafetyDelay, "rfe_error_bc_tePrSafetyDelay" },
		{ rfe_error_bc_tePrCalibDelay, "rfe_error_bc_tePrCalibDelay" },
		{ rfe_error_bc_teRxActiveDelay, "rfe_error_bc_teRxActiveDelay" },

		/// Invalid HPF Reset Release Delay from reference point
		{ rfe_error_bc_teHpfResetDelay, "rfe_error_bc_teHpfResetDelay" },
		{ rfe_error_bc_teDcPowOnDelay, "rfe_error_bc_teDcPowOnDelay" },
		/// Invalid safety monitor delay from reference point
		{ rfe_error_bc_teDcSafetyDelay, "rfe_error_bc_teDcSafetyDelay" },
		{ rfe_error_bc_teDdmaSetting, "rfe_error_bc_teDdmaSetting" },
		{ rfe_error_bc_teDdmaMode, "rfe_error_bc_teDdmaMode" },
		{ rfe_error_bc_teJumpBack, "rfe_error_bc_teJumpBack" },

		/// Either TX or RX group delay is greater than DC power on delay
		{ rfe_error_bc_teTxRxGrpDelay, "rfe_error_bc_teTxRxGrpDelay" },
		{ rfe_error_bc_teFineGrpDelay, "rfe_error_bc_teFineGrpDelay" },
		/// Invalid Profile or profile combination
		{ rfe_error_bc_teProfileList, "rfe_error_bc_teProfileList" },
		{ rfe_error_bc_tePrCalTimeout, "rfe_error_bc_tePrCalTimeout" },
		{ rfe_error_bc_teBiasDelay, "rfe_error_bc_teBiasDelay" },
		{ rfe_error_bc_teInputNull, "rfe_error_bc_teInputNull" },
		/// Invalid profile repeat count
		{ rfe_error_bc_tePrfRepeatCnt, "rfe_error_bc_tePrfRepeatCnt" },
		{ rfe_error_bc_teChirpSeqInterval, "rfe_error_bc_teChirpSeqInterval" },
		{ rfe_error_bc_teSettleTime, "rfe_error_bc_teSettleTime" },
		{ rfe_error_bc_teOutputSampRate, "rfe_error_bc_teOutputSampRate" },
		{ rfe_error_bc_teChirpInterval, "rfe_error_bc_teChirpInterval" },
		{ rfe_error_bc_teVirtualChannel, "rfe_error_bc_teVirtualChannel" },
		{ rfe_error_bc_teDwllTime, "rfe_error_bc_teDwllTime" },
		/// Invalid Transmission ON delay from timing reference point
		{ rfe_error_bc_teDelayFromRefpt, "rfe_error_bc_teDelayFromRefpt" },
		/// Polling for the completion of chirp sequence failed after multiple retries
		{ rfe_error_bc_teFreqCntTimeout, "rfe_error_bc_teFreqCntTimeout" },
		{ rfe_error_bc_teChirpSequence, "rfe_error_bc_teChirpSequence" },
		{ rfe_error_bc_teChirpTrgMode, "rfe_error_bc_teChirpTrgMode" },
		/* Gap */
		{ rfe_error_bc_tePhaseOutOfRange, "rfe_error_bc_tePhaseOutOfRange" },
		{ rfe_error_bc_teHpfResetWrongTriggerPoint, "rfe_error_bc_teHpfResetWrongTriggerPoint" },

		/// Write check failed while setting defaults for TX_CAL_ENABLE register
		{ rfe_error_bc_teTxCalEnableWriteCheckBase, "rfe_error_bc_teTxCalEnableWriteCheckBase" },
		{ rfe_error_bc_teTx1CalEnableWriteCheck, "rfe_error_bc_teTx1CalEnableWriteCheck" },
		{ rfe_error_bc_teTx2CalEnableWriteCheck, "rfe_error_bc_teTx2CalEnableWriteCheck" },
		{ rfe_error_bc_teTx1Tx2CalEnableWriteCheck, "rfe_error_bc_teTx1Tx2CalEnableWriteCheck" },
		{ rfe_error_bc_teTx3CalEnableWriteCheck, "rfe_error_bc_teTx3CalEnableWriteCheck" },
		{ rfe_error_bc_teTx1Tx3CalEnableWriteCheck, "rfe_error_bc_teTx1Tx3CalEnableWriteCheck" },
		{ rfe_error_bc_teTx2Tx3CalEnableWriteCheck, "rfe_error_bc_teTx2Tx3CalEnableWriteCheck" },
		{ rfe_error_bc_teTx1Tx2Tx3CalEnableWriteCheck, "rfe_error_bc_teTx1Tx2Tx3CalEnableWriteCheck" },

		/// Write check failed while setting chirp enable
		{ rfe_error_bc_teChirpEnableWriteCheckFailed, "rfe_error_bc_teChirpEnableWriteCheckFailed" },

		// ***** SC Error Codes (0x65xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_scProfile, "rfe_error_bc_scProfile" },
		{ rfe_error_bc_scOperatingFreqOutOfRange, "rfe_error_bc_scOperatingFreqOutOfRange" },
		{ rfe_error_bc_scPtrAddrNull, "rfe_error_bc_scPtrAddrNull" },
		/// Frequency Drift value greater than the chirp bandwidth
		{ rfe_error_bc_scInputFreqDriftInvalid, "rfe_error_bc_scInputFreqDriftInvalid" },
		/// Bandwidth is outside the range what hardware is capable of
		{ rfe_error_bc_scUserBwOutOfRange, "rfe_error_bc_scUserBwOutOfRange" },
		/// Ramp time outside the practical range.
		{ rfe_error_bc_scRampTimeOutOfRange, "rfe_error_bc_scRampTimeOutOfRange" },
		/// Reset time outside the practical range.
		{ rfe_error_bc_scResetTimeOutOfRange, "rfe_error_bc_scResetTimeOutOfRange" },

		// ***** CAFC Error Codes (0x66xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_cafcFreqCntTimeout, "rfe_error_bc_cafcFreqCntTimeout" },
		{ rfe_error_bc_cafcSbOutOfRange, "rfe_error_bc_cafcSbOutOfRange" },
		{ rfe_error_bc_cafcInputOutOfRange, "rfe_error_bc_cafcInputOutOfRange" },
		/// Wrong VCO selected
		{ rfe_error_bc_cafcBwOutOfRange, "rfe_error_bc_cafcBwOutOfRange" },
		/// Compensated slice number is 0, which is is invalid
		{ rfe_error_bc_cafcConfigLoopFilterFail, "rfe_error_bc_cafcConfigLoopFilterFail" },
		{ rfe_error_bc_cafcLoopBwOutOfRange, "rfe_error_bc_cafcLoopBwOutOfRange" },
		{ rfe_error_bc_cafcPtrAddrNull, "rfe_error_bc_cafcPtrAddrNull" },
		{ rfe_error_bc_cafcWrongProfileid, "rfe_error_bc_cafcWrongProfileid" },

		/// Busy status for aafc, kvco and dvdt
		{ rfe_error_bc_cafcAafcKvCodVdtTimeout, "rfe_error_bc_cafcAafcKvCodVdtTimeout" },
		{ rfe_error_bc_cafcVcoCalibAafcFail, "rfe_error_bc_cafcVcoCalibAafcFail" },
		{ rfe_error_bc_cafcVcoCalibKvCodVdtFail, "rfe_error_bc_cafcVcoCalibKvCodVdtFail" },
		{ rfe_error_bc_cafcNoStoreInProfileSelected, "rfe_error_bc_cafcNoStoreInProfileSelected" },
		{ rfe_error_bc_cafcDvdtCountWrong, "rfe_error_bc_cafcDvdtCountWrong" },
		{ rfe_error_bc_cafcKvcoCountStatusErr, "rfe_error_bc_cafcKvcoCountStatusErr" },
		{ rfe_error_bc_cafcWrongKvco, "rfe_error_bc_cafcWrongKvco" },
		{ rfe_error_bc_cafcWrongAcquisitionDuration, "rfe_error_bc_cafcWrongAcquisitionDuration" },

		// ***** ADC Error Codes (0x67xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		/// ADC calibration failure
		{ rfe_error_bc_adcCalibrationFailed, "rfe_error_bc_adcCalibrationFailed" },
		/// ADC calibration timeout failure
		{ rfe_error_bc_adcCalibrationTimeout, "rfe_error_bc_adcCalibrationTimeout" },
		/// ADC calibration Check not done
		{ rfe_error_bc_adcCalibarationCheckNotDone, "rfe_error_bc_adcCalibarationCheckNotDone" },

		// ***** GBIAS Error Codes (0x69xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_gbiasDummy, "rfe_error_bc_gbiasDummy" },

		// ***** LOI Error Codes (0x6Axxx) *****
		// For Cascaded byte 2 represent which FE report an error
		/* Gap */
		/// LO LUT Gain code out of range
		{ rfe_error_bc_loiLutGainCodeOutOfRange, "rfe_error_bc_loiLutGainCodeOutOfRange" },
		/* Gap */
		/// LO Gain cal busy
		{ rfe_error_bc_loiCalBusy, "rfe_error_bc_loiCalBusy" },
		/// LO Gain cal error
		{ rfe_error_bc_loiCalError, "rfe_error_bc_loiCalError" },
		{ rfe_error_bc_loiPtrAddrNull, "rfe_error_bc_loiPtrAddrNull" },

		// ***** MCLK Error Codes (0x6Cxxx) *****
		// For Cascaded byte 2 represent which FE report an error
		/* Gap */
		{ rfe_error_bc_mclkPllCalibrationFailed, "rfe_error_bc_mclkPllCalibrationFailed" },
		{ rfe_error_bc_mclkPllCalibrationNotFinished, "rfe_error_bc_mclkPllCalibrationNotFinished" },
		{ rfe_error_bc_mclkMspcCalibrationError, "rfe_error_bc_mclkMspcCalibrationError" },
		{ rfe_error_bc_mclkMspcTimeout, "rfe_error_bc_mclkMspcTimeout" },
		/* Gap */
		{ rfe_error_bc_mclkPtrAddrNull, "rfe_error_bc_mclkPtrAddrNull" },


		// ***** RX Error Codes (0x6Dxxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_rxInputOutOfRange, "rfe_error_bc_rxInputOutOfRange" },
		{ rfe_error_bc_rxCalBusy, "rfe_error_bc_rxCalBusy" },
		{ rfe_error_bc_rx1CalBusy, "rfe_error_bc_rx1CalBusy" },
		{ rfe_error_bc_rx2CalBusy, "rfe_error_bc_rx2CalBusy" },
		{ rfe_error_bc_rx3CalBusy, "rfe_error_bc_rx3CalBusy" },
		{ rfe_error_bc_rx4CalBusy, "rfe_error_bc_rx4CalBusy" },
		{ rfe_error_bc_rxCalError, "rfe_error_bc_rxCalError" },
		{ rfe_error_bc_rx1CalError, "rfe_error_bc_rx1CalError" },
		{ rfe_error_bc_rx2CalError, "rfe_error_bc_rx2CalError" },
		{ rfe_error_bc_rx1Rx2CalError, "rfe_error_bc_rx1Rx2CalError" },
		{ rfe_error_bc_rx3CalError, "rfe_error_bc_rx3CalError" },
		{ rfe_error_bc_rx1Rx3CalError, "rfe_error_bc_rx1Rx3CalError" },
		{ rfe_error_bc_rx2Rx3CalError, "rfe_error_bc_rx2Rx3CalError" },
		{ rfe_error_bc_rx1Rx2Rx3CalError, "rfe_error_bc_rx1Rx2Rx3CalError" },
		{ rfe_error_bc_rx4CalError, "rfe_error_bc_rx4CalError" },
		{ rfe_error_bc_rx1Rx4CalError, "rfe_error_bc_rx1Rx4CalError" },
		{ rfe_error_bc_rx2Rx4CalError, "rfe_error_bc_rx2Rx4CalError" },
		{ rfe_error_bc_rx1Rx2Rx4CalError, "rfe_error_bc_rx1Rx2Rx4CalError" },
		{ rfe_error_bc_rx3Rx4CalError, "rfe_error_bc_rx3Rx4CalError" },
		{ rfe_error_bc_rx1Rx3Rx4CalError, "rfe_error_bc_rx1Rx3Rx4CalError" },
		{ rfe_error_bc_rx2Rx3Rx4CalError, "rfe_error_bc_rx2Rx3Rx4CalError" },
		{ rfe_error_bc_rx1Rx2Rx3Rx4CalError, "rfe_error_bc_rx1Rx2Rx3Rx4CalError" },
		{ rfe_error_bc_rxPrtAddrNull, "rfe_error_bc_rxPrtAddrNull" },
		{ rfe_error_bc_rxWrngCalTargetOffset, "rfe_error_bc_rxWrngCalTargetOffset" },
		/// Write check failed while enabling Functional Safety Mon Level for RX
		{ rfe_error_bc_rxFusaEnableWriteCheckBase, "rfe_error_bc_rxFusaEnableWriteCheckBase" },
		{ rfe_error_bc_rx1FusaEnableWritecheck, "rfe_error_bc_rx1FusaEnableWritecheck" },
		{ rfe_error_bc_rx2FusaEnableWritecheck, "rfe_error_bc_rx2FusaEnableWritecheck" },
		{ rfe_error_bc_rx1Rx2FusaEnableWritecheck, "rfe_error_bc_rx1Rx2FusaEnableWritecheck" },
		{ rfe_error_bc_rx3FusaEnableWritecheck, "rfe_error_bc_rx3FusaEnableWritecheck" },
		{ rfe_error_bc_rx1Rx3FusaEnableWritecheck, "rfe_error_bc_rx1Rx3FusaEnableWritecheck" },
		{ rfe_error_bc_rx2Rx3FusaEnableWritecheck, "rfe_error_bc_rx2Rx3FusaEnableWritecheck" },
		{ rfe_error_bc_rx1Rx2Rx3FusaEnableWritecheck, "rfe_error_bc_rx1Rx2Rx3FusaEnableWritecheck" },
		{ rfe_error_bc_rx4FusaEnableWritecheck, "rfe_error_bc_rx4FusaEnableWritecheck" },
		{ rfe_error_bc_rx1Rx4FusaEnableWritecheck, "rfe_error_bc_rx1Rx4FusaEnableWritecheck" },
		{ rfe_error_bc_rx2Rx4FusaEnableWritecheck, "rfe_error_bc_rx2Rx4FusaEnableWritecheck" },
		{ rfe_error_bc_rx1Rx2Rx4FusaEnableWritecheck, "rfe_error_bc_rx1Rx2Rx4FusaEnableWritecheck" },
		{ rfe_error_bc_rx3Rx4FusaEnableWritecheck, "rfe_error_bc_rx3Rx4FusaEnableWritecheck" },
		{ rfe_error_bc_rx1Rx3Rx4FusaEnableWritecheck, "rfe_error_bc_rx1Rx3Rx4FusaEnableWritecheck" },
		{ rfe_error_bc_rx2Rx3Rx4FusaEnableWritecheck, "rfe_error_bc_rx2Rx3Rx4FusaEnableWritecheck" },
		{ rfe_error_bc_rx1Rx2Rx3Rx4FusaEnableWritecheck, "rfe_error_bc_rx1Rx2Rx3Rx4FusaEnableWritecheck" },
		/// Write check failed for Rx BBD Enable
		{ rfe_error_bc_rxBbdEnableWritecheckBase, "rfe_error_bc_rxBbdEnableWritecheckBase" },
		{ rfe_error_bc_rx1BbdEnableWritecheck, "rfe_error_bc_rx1BbdEnableWritecheck" },
		{ rfe_error_bc_rx2BbdEnableWritecheck, "rfe_error_bc_rx2BbdEnableWritecheck" },
		{ rfe_error_bc_rx1Rx2BbdEnableWritecheck, "rfe_error_bc_rx1Rx2BbdEnableWritecheck" },
		{ rfe_error_bc_rx3BbdEnableWritecheck, "rfe_error_bc_rx3BbdEnableWritecheck" },
		{ rfe_error_bc_rx1Rx3BbdEnableWritecheck, "rfe_error_bc_rx1Rx3BbdEnableWritecheck" },
		{ rfe_error_bc_rx2Rx3BbdEnableWritecheck, "rfe_error_bc_rx2Rx3BbdEnableWritecheck" },
		{ rfe_error_bc_rx1Rx2Rx3BbdEnableWritecheck, "rfe_error_bc_rx1Rx2Rx3BbdEnableWritecheck" },
		{ rfe_error_bc_rx4BbdEnableWritecheck, "rfe_error_bc_rx4BbdEnableWritecheck" },
		{ rfe_error_bc_rx1Rx4BbdEnableWritecheck, "rfe_error_bc_rx1Rx4BbdEnableWritecheck" },
		{ rfe_error_bc_rx2Rx4BbdEnableWritecheck, "rfe_error_bc_rx2Rx4BbdEnableWritecheck" },
		{ rfe_error_bc_rx1Rx2Rx4BbdEnableWritecheck, "rfe_error_bc_rx1Rx2Rx4BbdEnableWritecheck" },
		{ rfe_error_bc_rx3Rx4BbdEnableWritecheck, "rfe_error_bc_rx3Rx4BbdEnableWritecheck" },
		{ rfe_error_bc_rx1Rx3Rx4BbdEnableWritecheck, "rfe_error_bc_rx1Rx3Rx4BbdEnableWritecheck" },
		{ rfe_error_bc_rx2Rx3Rx4BbdEnableWritecheck, "rfe_error_bc_rx2Rx3Rx4BbdEnableWritecheck" },
		{ rfe_error_bc_rx1Rx2Rx3Rx4BbdEnableWritecheck, "rfe_error_bc_rx1Rx2Rx3Rx4BbdEnableWritecheck" },

		// ***** TX Error Codes (0x71xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_txInputOutOfRange, "rfe_error_bc_txInputOutOfRange" },
		{ rfe_error_bc_txPrcAdcTimeout, "rfe_error_bc_txPrcAdcTimeout" },
		{ rfe_error_bc_txSensorFitFail, "rfe_error_bc_txSensorFitFail" },
		{ rfe_error_bc_txCalBusy, "rfe_error_bc_txCalBusy" },
		{ rfe_error_bc_tx1CalBusy, "rfe_error_bc_tx1CalBusy" },
		{ rfe_error_bc_tx2CalBusy, "rfe_error_bc_tx2CalBusy" },
		{ rfe_error_bc_tx3CalBusy, "rfe_error_bc_tx3CalBusy" },
		{ rfe_error_bc_txCalError, "rfe_error_bc_txCalError" },
		{ rfe_error_bc_tx1CalError, "rfe_error_bc_tx1CalError" },
		{ rfe_error_bc_tx2CalError, "rfe_error_bc_tx2CalError" },
		{ rfe_error_bc_tx1Tx2CalError, "rfe_error_bc_tx1Tx2CalError" },
		{ rfe_error_bc_tx3CalError, "rfe_error_bc_tx3CalError" },
		{ rfe_error_bc_tx1Tx3CalError, "rfe_error_bc_tx1Tx3CalError" },
		{ rfe_error_bc_tx2Tx3CalError, "rfe_error_bc_tx2Tx3CalError" },
		{ rfe_error_bc_tx1Tx2Tx3CalError, "rfe_error_bc_tx1Tx2Tx3CalError" },
		{ rfe_error_bc_txSafetyBusy, "rfe_error_bc_txSafetyBusy" },
		{ rfe_error_bc_tx1SafetyBusy, "rfe_error_bc_tx1SafetyBusy" },
		{ rfe_error_bc_tx2SafetyBusy, "rfe_error_bc_tx2SafetyBusy" },
		{ rfe_error_bc_tx3SafetyBusy, "rfe_error_bc_tx3SafetyBusy" },
		{ rfe_error_bc_txSafetyError, "rfe_error_bc_txSafetyError" },
		{ rfe_error_bc_tx1SafetyError, "rfe_error_bc_tx1SafetyError" },
		{ rfe_error_bc_tx2SafetyError, "rfe_error_bc_tx2SafetyError" },
		{ rfe_error_bc_tx1Tx2SafetyError, "rfe_error_bc_tx1Tx2SafetyError" },
		{ rfe_error_bc_tx3SafetyError, "rfe_error_bc_tx3SafetyError" },
		{ rfe_error_bc_tx1Tx3SafetyError, "rfe_error_bc_tx1Tx3SafetyError" },
		{ rfe_error_bc_tx2Tx3SafetyError, "rfe_error_bc_tx2Tx3SafetyError" },
		{ rfe_error_bc_tx1Tx2Tx3SafetyError, "rfe_error_bc_tx1Tx2Tx3SafetyError" },
		{ rfe_error_bc_txPtrAddrNull, "rfe_error_bc_txPtrAddrNull" },
		{ rfe_error_bc_txNoStoreInProfileSelected, "rfe_error_bc_txNoStoreInProfileSelected" },
		{ rfe_error_bc_txPoutVgaReduceTxNotSupported, "rfe_error_bc_txPoutVgaReduceTxNotSupported" },
		{ rfe_error_bc_txRfMinCodeOutOfRange, "rfe_error_bc_txRfMinCodeOutOfRange" },

		/// Write check failed for while enabling Functional Safety Mon Level enabling for TX
		{ rfe_error_bc_txFusaEnableWriteCheckBase, "rfe_error_bc_txFusaEnableWriteCheckBase" },
		{ rfe_error_bc_tx1FusaEnableWriteCheck, "rfe_error_bc_tx1FusaEnableWriteCheck" },
		{ rfe_error_bc_tx2FusaEnableWriteCheck, "rfe_error_bc_tx2FusaEnableWriteCheck" },
		{ rfe_error_bc_tx1Tx2FusaEnableWriteCheck, "rfe_error_bc_tx1Tx2FusaEnableWriteCheck" },
		{ rfe_error_bc_tx3FusaEnableWriteCheck, "rfe_error_bc_tx3FusaEnableWriteCheck" },
		{ rfe_error_bc_tx1Tx3FusaEnableWriteCheck, "rfe_error_bc_tx1Tx3FusaEnableWriteCheck" },
		{ rfe_error_bc_tx2Tx3FusaEnableWriteCheck, "rfe_error_bc_tx2Tx3FusaEnableWriteCheck" },
		{ rfe_error_bc_tx1Tx2Tx3FusaEnableWriteCheck, "rfe_error_bc_tx1Tx2Tx3FusaEnableWriteCheck" },
		/// If the TX calibration is not complete, setting bias current will not succeed
		{ rfe_error_bc_txCalibBiasCurrWriteFailed, "rfe_error_bc_txCalibBiasCurrWriteFailed" },

		/// TX calibration failed with timeout
		{ rfe_error_bc_txCalibTimeout, "rfe_error_bc_txCalibTimeout" },
		/// Write check failed while enabling BBD for TX
		{ rfe_error_bc_txBbdEnableWritecheckBase, "rfe_error_bc_txBbdEnableWritecheckBase" },
		{ rfe_error_bc_tx1BbdEnableWritecheck, "rfe_error_bc_tx1BbdEnableWritecheck" },
		{ rfe_error_bc_tx2BbdEnableWritecheck, "rfe_error_bc_tx2BbdEnableWritecheck" },
		{ rfe_error_bc_tx1tx2BbdEnableWritecheck, "rfe_error_bc_tx1tx2BbdEnableWritecheck" },
		{ rfe_error_bc_tx3BbdEnableWritecheck, "rfe_error_bc_tx3BbdEnableWritecheck" },
		{ rfe_error_bc_tx1Tx3BbdEnableWritecheck, "rfe_error_bc_tx1Tx3BbdEnableWritecheck" },
		{ rfe_error_bc_tx2Tx3BbdEnableWritecheck, "rfe_error_bc_tx2Tx3BbdEnableWritecheck" },
		{ rfe_error_bc_tx1Tx2Tx3BbdEnableWritecheck, "rfe_error_bc_tx1Tx2Tx3BbdEnableWritecheck" },

		// ***** SSB Error Codes (0x74xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		/// Connected signal node to a wrong ATB
		{ rfe_error_bc_ssbSignalNotExistOnSelectedAtb, "rfe_error_bc_ssbSignalNotExistOnSelectedAtb" },
		/// Input out of range
		{ rfe_error_bc_ssbInputOutOfRange, "rfe_error_bc_ssbInputOutOfRange" },

		// ***** GLDO Error Codes (0x75xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_gldoSnsError, "rfe_error_bc_gldoSnsError" },
		{ rfe_error_bc_gldoSnsForceError, "rfe_error_bc_gldoSnsForceError" },
		{ rfe_error_bc_gldoSnsResetError, "rfe_error_bc_gldoSnsResetError" },

		// ***** ATB Error Codes (0x76xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		/// BISTADC data collection timeout
		{ rfe_error_bc_atbBistAdcTimeout, "rfe_error_bc_atbBistAdcTimeout" },
		/// selected a wrong ATB
		{ rfe_error_bc_atbWrongAtbNoSelected, "rfe_error_bc_atbWrongAtbNoSelected" },

		// ***** OTP Error Codes (0x77xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		/// Fail to read OTP table
		{ rfe_error_bc_otpFailToRead, "rfe_error_bc_otpFailToRead" },
		/// CRC check failure
		{ rfe_error_bc_otpCrcCheckFailure, "rfe_error_bc_otpCrcCheckFailure" },
		/// IP is disabled
		{ rfe_error_bc_otpIpIsDisabled, "rfe_error_bc_otpIpIsDisabled" },
		/// OTP is not loaded.
		{ rfe_error_bc_otpOtpIsNotLoaded, "rfe_error_bc_otpOtpIsNotLoaded" },
		/* Gap */
		// None of the OTP memory is enabled
		{ rfe_error_bc_otpAllMemDisabled, "rfe_error_bc_otpAllMemDisabled" },

		// ***** ISM Error Codes (0x78xxx) *****
		// For Cascaded byte 2 represent which FE report an error
		{ rfe_error_bc_ismInvalidInput, "rfe_error_bc_ismInvalidInput" },
		{ rfe_error_bc_ismPtrAddrNull, "rfe_error_bc_ismPtrAddrNull" },
		{ rfe_error_bc_ismStartupSeqConfigFailed, "rfe_error_bc_ismStartupSeqConfigFailed" },
		{ rfe_error_bc_ismInputModeToggleTestFailed, "rfe_error_bc_ismInputModeToggleTestFailed" },
		{ rfe_error_bc_ismOutputModeToggleTestFailed, "rfe_error_bc_ismOutputModeToggleTestFailed" },
		{ rfe_error_bc_ismFitErrorN_High, "rfe_error_bc_ismFitErrorN_High" },
		{ rfe_error_bc_ismFitResetStateChangeFailed, "rfe_error_bc_ismFitResetStateChangeFailed" },
		{ rfe_error_bc_ismFitResetErrorFailed, "rfe_error_bc_ismFitResetErrorFailed" },
		{ rfe_error_bc_ismFitForceStateChangeFailed, "rfe_error_bc_ismFitForceStateChangeFailed" },
		{ rfe_error_bc_ismFitForceErrorFailed, "rfe_error_bc_ismFitForceErrorFailed" },
		{ rfe_error_bc_ismFitFailed, "rfe_error_bc_ismFitFailed" },
		{ rfe_error_bc_ismFitStatusFailed, "rfe_error_bc_ismFitStatusFailed" },
		{ rfe_error_bc_ismFitTxStatusFailed, "rfe_error_bc_ismFitTxStatusFailed" },
		{ rfe_error_bc_ismFitRxStatusFailed, "rfe_error_bc_ismFitRxStatusFailed" },
		{ rfe_error_bc_ismFitAdcStatusFailed, "rfe_error_bc_ismFitAdcStatusFailed" },
		{ rfe_error_bc_ismFitChirpStatusFailed, "rfe_error_bc_ismFitChirpStatusFailed" },
		{ rfe_error_bc_ismFitMclkLoIsmOtpCcStatusFailed, "rfe_error_bc_ismFitMclkLoIsmOtpCcStatusFailed" },
		{ rfe_error_bc_ismFitSsbSerGbGldoAAtbStatusFailed, "rfe_error_bc_ismFitSsbSerGbGldoAAtbStatusFailed" },
		{ rfe_error_bc_ismCalBusy, "rfe_error_bc_ismCalBusy" },
		{ rfe_error_bc_ismCalError, "rfe_error_bc_ismCalError" },
		{ rfe_error_bc_ismCalSuccess, "rfe_error_bc_ismCalSuccess" },
		{ rfe_error_bc_ismDisableLbToggleTestFailed, "rfe_error_bc_ismDisableLbToggleTestFailed" },

		// ***** Sys Error Codes (0x79xxx) *****
		{ rfe_error_sys_spi_wrg_unit_id, "rfe_error_sys_spi_wrg_unit_id" },
		{ rfe_error_sys_spi_invalid_len, "rfe_error_sys_spi_invalid_len" },
		{ rfe_error_sys_timer_cm7_init, "rfe_error_sys_timer_cm7_init" },
		{ rfe_error_sys_FE_chip_es2_not_supported, "rfe_error_sys_FE_chip_es2_not_supported" },

		/****** Specific errors for Fault Injection Tests   ******/
		{ rfe_error_ic_wrg_input_params_e, "rfe_error_ic_wrg_input_params_e" },

		/****** Specific errors for RFBIST   ******/
		{ rfe_error_rxbist_frequency_fail, "rfe_error_rxbist_frequency_fail" },
		{ rfe_error_rxbist_missing_signal, "rfe_error_rxbist_missing_signal" },
		{ rfe_error_rxbist_lna_gain_fail_e, "rfe_error_rxbist_lna_gain_fail_e"},
		{ rfe_error_rxbist_lna_phase_fail_e, "rfe_error_rxbist_lna_phase_fail_e"},
		{ rfe_error_rxbist_mixer_gain_fail_e, "rfe_error_rxbist_mixer_gain_fail_e"},
		{ rfe_error_rxbist_mixer_phase_fail_e, "rfe_error_rxbist_mixer_phase_fail_e"},
};


/*--------------------------------------------------------------------------------*/
const char *RfeDbg_ErrStringGet (rfe_error_t error)
{
	uint16_t errIdx;

	for (errIdx = 0; errIdx < sizeof(gsRfeErrorDescriptors)/sizeof(gsRfeErrorDescriptors[0]); errIdx++)
	{
		if ((gsRfeErrorDescriptors[errIdx].index == (uint32_t)error) && gsRfeErrorDescriptors[errIdx].string != NULL_PTR)
		{
			return (gsRfeErrorDescriptors[errIdx].string);
		}
	}
	return nullstring;
}

const char *RfeDbg_FusaStringGet( rfe_fuSaFault_t fuSaFaultId );
{
	uint8_t i;

	// Search for fuSaFaultId in list of descriptors
	for (i = 0; i < sizeof(gsFusaDescriptors)/sizeof(gsFusaDescriptors[0]); i++)
	{
		if ((gsFusaDescriptors[i].index == (uint32_t)fuSaFaultId) && gsFusaDescriptors[i].string != NULL_PTR)
		{
			return (gsFusaDescriptors[i].string);
		}
	}
	return nullstring;
}
