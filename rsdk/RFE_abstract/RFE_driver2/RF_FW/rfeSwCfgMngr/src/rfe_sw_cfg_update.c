/**************************************************************************************************
* Copyright 2023 - 2024 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

/*==================================================================================================
 *                                          INCLUDES
 ==================================================================================================*/
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"
#include "rfe_sw_cfg_update.h"
#include "rfe_types.h"
#include "rfeSwCfgMngr.h"
#include "rfe_min_max_blob.h"
#include "rfe_error.h"
#include "rfe_blob_access.h"
#include "rfeSwMainFsm.h"
#include "rfe_cfg_blob.h"
#include "rfeSwUtils.h"

#include "bc_err.h"
#include "bc_spi.h"
#include "bc_sys.h"
#include "bc_te.h"
#include "bc_mipi.h"
#include "bc_tx.h"
#include "bc_rx.h"
#include "bc_sc.h"
#include "reg_es2_ism.h"
#include "reg_es2_te.h"
#include "reg_es2_rx.h"
#include "hal_es2_te.h"
#include "helper_bcsys.h"
#include "math.h"

/*==================================================================================================
 *                                      DEFINES
==================================================================================================*/
#define INIT_PROF_LIST	0x0F //used to init sequence prof list
#define WIDEBAND		1UL	//Wideband (-6dB LPF corner (fLPF) > 40MHz)
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/
/**
 * This array is a list of all updatable RFE configuration parameters
 *
 */
static const rfeCfg_param_t update_params[RFE_SW_CFG_MNGR_UPDATABLE_PARAMS] =
{
	[rfe_paramUpdate_general_powerMode_e] = rfeCfg_param_general_powerMode_e,
	[rfe_paramUpdate_general_radarCycleStartSignalGpio_e] = 		rfeCfg_param_general_radarCycleStartSignalGpio_e,
	[rfe_paramUpdate_general_chirpSequenceActiveSignalGpio_e] = 	rfeCfg_param_general_chirpSequenceActiveSignalGpio_e,
	[rfe_paramUpdate_general_clkIoConfig_e] = 						rfeCfg_param_general_clkIoConfig_e,
	[rfe_paramUpdate_general_pdcDecimationFilter_e] = 				rfeCfg_param_general_pdcDecimationFilter_e,
	[rfe_paramUpdate_general_dataOutConfig_e] = 					rfeCfg_param_general_dataOutConfig_e,
	[rfe_paramUpdate_general_metadataPacketSwContent_e] = 			rfeCfg_param_general_metadataPacketSwContent_e,
	[rfe_paramUpdate_general_metadataPacketVirtualChannel_e] = 		rfeCfg_param_general_metadataPacketVirtualChannel_e,
	[rfe_paramUpdate_general_jumpbackTimeTicks_e] = 				rfeCfg_param_general_jumpbackTimeTicks_e,
	[rfe_paramUpdate_general_txCalibration_mode_e] = 				rfeCfg_param_general_txCalibration_mode_e,

	[rfe_paramUpdate_monitorAndSafety_rxSatCountResetEveryChirpSequence_e] = 		rfeCfg_param_monitorAndSafety_rxSatCountResetEveryChirpSequence_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx1_e] = 			rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx1_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx2_e] = 			rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx2_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx3_e] = 			rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx3_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx4_e] = 			rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx4_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage2_rx1_e] = 			rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx1_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage2_rx2_e] = 			rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx2_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage2_rx3_e] = 			rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx3_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage2_rx4_e] = 			rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx4_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx1_e] = 		rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx1_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx2_e] = 		rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx2_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx3_e] = 		rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx3_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx4_e] = 		rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx4_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage2_rx1_e] = 		rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx1_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage2_rx2_e] = 		rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx2_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage2_rx3_e] = 		rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx3_e,
	[rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage2_rx4_e] = 		rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx4_e,
	[rfe_paramUpdate_monitorAndSafety_adcClippingCountResetEveryChirpSequence_e] = 	rfeCfg_param_monitorAndSafety_adcClippingCountResetEveryChirpSequence_e,
	[rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc1_e] = 				rfeCfg_param_monitorAndSafety_adcClippingCountLimit_adc1_e,
	[rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc2_e] = 				rfeCfg_param_monitorAndSafety_adcClippingCountLimit_adc2_e,
	[rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc3_e] = 				rfeCfg_param_monitorAndSafety_adcClippingCountLimit_adc3_e,
	[rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc4_e] = 				rfeCfg_param_monitorAndSafety_adcClippingCountLimit_adc4_e,
	[rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdHigh_tx12_e] = 		rfeCfg_param_monitorAndSafety_temperatureSensorThresholdHigh_tx12_e,
	[rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdHigh_tx3_e] = 		rfeCfg_param_monitorAndSafety_temperatureSensorThresholdHigh_tx3_e,
	[rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdHigh_xo_e] = 		rfeCfg_param_monitorAndSafety_temperatureSensorThresholdHigh_xo_e,
	[rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdOver_tx12_e] = 		rfeCfg_param_monitorAndSafety_temperatureSensorThresholdOver_tx12_e,
	[rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdOver_tx3_e] = 		rfeCfg_param_monitorAndSafety_temperatureSensorThresholdOver_tx3_e,
	[rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdOver_xo_e] = 		rfeCfg_param_monitorAndSafety_temperatureSensorThresholdOver_xo_e,
	[rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdUnder_tx12_e] = 	rfeCfg_param_monitorAndSafety_temperatureSensorThresholdUnder_tx12_e,
	[rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdUnder_tx3_e] = 		rfeCfg_param_monitorAndSafety_temperatureSensorThresholdUnder_tx3_e,
	[rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdUnder_xo_e] = 		rfeCfg_param_monitorAndSafety_temperatureSensorThresholdUnder_xo_e,
	[rfe_paramUpdate_monitorAndSafety_thresholdValueToPromoteR1Faults_e] = 			rfeCfg_param_monitorAndSafety_thresholdValueToPromoteR1Faults_e,
	[rfe_paramUpdate_monitorAndSafety_frequencyForBist_e] = 						rfeCfg_param_monitorAndSafety_frequencyForBist_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx2_e] = 		rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx2_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx3_e] = 		rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx3_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx4_e] = 		rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx4_e,
	[rfe_paramUpdate_monitorAndSafety_rxPhaseDiffLnaThresholdTolerance_e] = 		rfeCfg_param_monitorAndSafety_rxPhaseDiffLnaThresholdTolerance_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx2_e] = 		rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx2_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx3_e] = 		rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx3_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx4_e] = 		rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx4_e,
	[rfe_paramUpdate_monitorAndSafety_rxGainDiffLnaThresholdTolerance_e] = 			rfeCfg_param_monitorAndSafety_rxGainDiffLnaThresholdTolerance_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx2_e] = 	rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx2_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx3_e] = 	rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx3_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx4_e] = 	rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx4_e,
	[rfe_paramUpdate_monitorAndSafety_rxPhaseDiffMixerThresholdTolerance_e] = 		rfeCfg_param_monitorAndSafety_rxPhaseDiffMixerThresholdTolerance_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx2_e] = 		rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx2_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx3_e] = 		rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx3_e,
	[rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx4_e] = 		rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx4_e,
	[rfe_paramUpdate_monitorAndSafety_rxGainDiffMixerThresholdTolerance_e] = 		rfeCfg_param_monitorAndSafety_rxGainDiffMixerThresholdTolerance_e,
	[rfe_paramUpdate_monitorAndSafety_injectTestTone_e] = 							rfeCfg_param_monitorAndSafety_injectTestTone_e,
	[rfe_paramUpdate_monitorAndSafety_checkBbd_loi_e] = 							rfeCfg_param_monitorAndSafety_checkBbd_loi_e,
	[rfe_paramUpdate_monitorAndSafety_checkBbd_tx_e] = 								rfeCfg_param_monitorAndSafety_checkBbd_tx_e,
	[rfe_paramUpdate_monitorAndSafety_checkBbd_rx_e] = 								rfeCfg_param_monitorAndSafety_checkBbd_rx_e,
	[rfe_paramUpdate_monitorAndSafety_ppdThreshold_profile0_e] = 					rfeCfg_param_monitorAndSafety_ppdThreshold_profile0_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_0_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_0_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_1_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_1_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_2_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_2_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_3_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_3_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_4_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_4_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_5_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_5_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_6_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_6_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_7_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_7_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_8_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_8_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_9_e] = 							rfeCfg_param_monitorAndSafety_fuSaFaultMask_9_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_10_e] = 						rfeCfg_param_monitorAndSafety_fuSaFaultMask_10_e,
	[rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_11_e] = 						rfeCfg_param_monitorAndSafety_fuSaFaultMask_11_e,

	[rfe_paramUpdate_radarCycle_radarCycleDuration_e] = 			rfeCfg_param_radarCycle_radarCycleDuration_e,
	[rfe_paramUpdate_radarCycle_chirpSequenceCount_e] = 			rfeCfg_param_radarCycle_chirpSequenceCount_e,
	[rfe_paramUpdate_radarCycle_chirpSequence_0_e] = 				rfeCfg_param_radarCycle_chirpSequence_0_e,
	[rfe_paramUpdate_radarCycle_chirpSequence_1_e] = 				rfeCfg_param_radarCycle_chirpSequence_1_e,
	[rfe_paramUpdate_radarCycle_chirpSequence_2_e] = 				rfeCfg_param_radarCycle_chirpSequence_2_e,
	[rfe_paramUpdate_radarCycle_chirpSequence_3_e] = 				rfeCfg_param_radarCycle_chirpSequence_3_e,
	[rfe_paramUpdate_radarCycle_chirpSequence_4_e] = 				rfeCfg_param_radarCycle_chirpSequence_4_e,
	[rfe_paramUpdate_radarCycle_chirpSequence_5_e] = 				rfeCfg_param_radarCycle_chirpSequence_5_e,
	[rfe_paramUpdate_radarCycle_chirpSequence_6_e] = 				rfeCfg_param_radarCycle_chirpSequence_6_e,
	[rfe_paramUpdate_radarCycle_chirpSequence_7_e] = 				rfeCfg_param_radarCycle_chirpSequence_7_e,
	[rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_0_e] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_0_e,
	[rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_1_e] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_1_e,
	[rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_2_e] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_2_e,
	[rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_3_e] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_3_e,
	[rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_4_e] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_4_e,
	[rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_5_e] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_5_e,
	[rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_6_e] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_6_e,
	[rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_7_e] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_7_e,
	[rfe_paramUpdate_radarCycle_recalibrateProfileDependent_0_e] = 	rfeCfg_param_radarCycle_recalibrateProfileDependent_0_e,
	[rfe_paramUpdate_radarCycle_recalibrateProfileDependent_1_e] = 	rfeCfg_param_radarCycle_recalibrateProfileDependent_1_e,
	[rfe_paramUpdate_radarCycle_recalibrateProfileDependent_2_e] = 	rfeCfg_param_radarCycle_recalibrateProfileDependent_2_e,
	[rfe_paramUpdate_radarCycle_recalibrateProfileDependent_3_e] = 	rfeCfg_param_radarCycle_recalibrateProfileDependent_3_e,
	[rfe_paramUpdate_radarCycle_recalibrateProfileDependent_4_e] = 	rfeCfg_param_radarCycle_recalibrateProfileDependent_4_e,
	[rfe_paramUpdate_radarCycle_recalibrateProfileDependent_5_e] = 	rfeCfg_param_radarCycle_recalibrateProfileDependent_5_e,
	[rfe_paramUpdate_radarCycle_recalibrateProfileDependent_6_e] = 	rfeCfg_param_radarCycle_recalibrateProfileDependent_6_e,
	[rfe_paramUpdate_radarCycle_recalibrateProfileDependent_7_e] = 	rfeCfg_param_radarCycle_recalibrateProfileDependent_7_e,
	[rfe_paramUpdate_radarCycle_recalibrateProfileIndependent_e] = 	rfeCfg_param_radarCycle_recalibrateProfileIndependent_e,
	[rfe_paramUpdate_radarCycle_bistInterval_e] = 					rfeCfg_param_radarCycle_bistInterval_e,

	[rfe_paramUpdate_chirpSequence_chirpCount_e] = 						rfeCfg_param_chirpSequence_chirpCount_e,
	[rfe_paramUpdate_chirpSequence_chirpProfileSequence_0_e] = 			rfeCfg_param_chirpSequence_chirpProfileSequence_0_e,
	[rfe_paramUpdate_chirpSequence_chirpProfileSequence_1_e] = 			rfeCfg_param_chirpSequence_chirpProfileSequence_1_e,
	[rfe_paramUpdate_chirpSequence_chirpProfileSequence_2_e] = 			rfeCfg_param_chirpSequence_chirpProfileSequence_2_e,
	[rfe_paramUpdate_chirpSequence_chirpProfileSequence_3_e] = 			rfeCfg_param_chirpSequence_chirpProfileSequence_3_e,
	[rfe_paramUpdate_chirpSequence_chirpProfileSequence_4_e] = 			rfeCfg_param_chirpSequence_chirpProfileSequence_4_e,
	[rfe_paramUpdate_chirpSequence_chirpProfileSequence_5_e] = 			rfeCfg_param_chirpSequence_chirpProfileSequence_5_e,
	[rfe_paramUpdate_chirpSequence_chirpProfileSequence_6_e] = 			rfeCfg_param_chirpSequence_chirpProfileSequence_6_e,
	[rfe_paramUpdate_chirpSequence_chirpProfileSequence_7_e] = 			rfeCfg_param_chirpSequence_chirpProfileSequence_7_e,
	[rfe_paramUpdate_chirpSequence_chirpProfileSequenceLength_e] = 		rfeCfg_param_chirpSequence_chirpProfileSequenceLength_e,
	[rfe_paramUpdate_chirpSequence_dynamicUpdatesEnabled_e] = 			rfeCfg_param_chirpSequence_dynamicUpdatesEnabled_e,
	[rfe_paramUpdate_chirpSequence_dynamicTableIndex_e] = 				rfeCfg_param_chirpSequence_dynamicTableIndex_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_e] = 			rfeCfg_param_chirpSequence_txPhaseRotation_ddma_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx_e] = 		rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx1_init_e] = 	rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_init_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx2_init_e] = 	rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx2_init_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx3_init_e] = 	rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx3_init_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx1_update_e] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_update_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx2_update_e] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx2_update_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx3_update_e] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx3_update_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx1_mode_e] = 	rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_mode_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx2_mode_e] = 	rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx2_mode_e,
	[rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx3_mode_e] = 	rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx3_mode_e,
	[rfe_paramUpdate_chirpSequence_rxEnable_e] = 						rfeCfg_param_chirpSequence_rxEnable_e,
	[rfe_paramUpdate_chirpSequence_pdcNotchFilterEnable_e] = 			rfeCfg_param_chirpSequence_pdcNotchFilterEnable_e,
	[rfe_paramUpdate_chirpSequence_txCalibration_thresholdHigh_e] = 	rfeCfg_param_chirpSequence_txCalibration_thresholdHigh_e,
	[rfe_paramUpdate_chirpSequence_txCalibration_thresholdLow_e] = 		rfeCfg_param_chirpSequence_txCalibration_thresholdLow_e,

	[rfe_paramUpdate_chirpProfile_effectiveSamplingFrequency_e] = 	rfeCfg_param_chirpProfile_effectiveSamplingFrequency_e,
	[rfe_paramUpdate_chirpProfile_chirpIntervalTimeTicks_e] = 		rfeCfg_param_chirpProfile_chirpIntervalTimeTicks_e,
	[rfe_paramUpdate_chirpProfile_dwellTimeTicks_e] = 				rfeCfg_param_chirpProfile_dwellTimeTicks_e,
	[rfe_paramUpdate_chirpProfile_settleTimeTicks_e] = 				rfeCfg_param_chirpProfile_settleTimeTicks_e,
	[rfe_paramUpdate_chirpProfile_acquisitionTimeTicks_e] = 		rfeCfg_param_chirpProfile_acquisitionTimeTicks_e,
	[rfe_paramUpdate_chirpProfile_resetTimeTicks_e] = 				rfeCfg_param_chirpProfile_resetTimeTicks_e,
	[rfe_paramUpdate_chirpProfile_centerFrequency_e] = 				rfeCfg_param_chirpProfile_centerFrequency_e,
	[rfe_paramUpdate_chirpProfile_effectiveChirpBandwidth_e] = 		rfeCfg_param_chirpProfile_effectiveChirpBandwidth_e,
	[rfe_paramUpdate_chirpProfile_chirpPllVcoSelect_e] = 			rfeCfg_param_chirpProfile_chirpPllVcoSelect_e,
	[rfe_paramUpdate_chirpProfile_chirpSlopeDirection_e] = 			rfeCfg_param_chirpProfile_chirpSlopeDirection_e,
	[rfe_paramUpdate_chirpProfile_chirpPllLoopFilterBandwidth_e] = 	rfeCfg_param_chirpProfile_chirpPllLoopFilterBandwidth_e,
	[rfe_paramUpdate_chirpProfile_txTransmissionEnable_e] = 		rfeCfg_param_chirpProfile_txTransmissionEnable_e,
	[rfe_paramUpdate_chirpProfile_txPower_e] = 						rfeCfg_param_chirpProfile_txPower_e,
	[rfe_paramUpdate_chirpProfile_txPhaseRotation_1_e] = 			rfeCfg_param_chirpProfile_txPhaseRotation_1_e,
	[rfe_paramUpdate_chirpProfile_txPhaseRotation_2_e] = 			rfeCfg_param_chirpProfile_txPhaseRotation_2_e,
	[rfe_paramUpdate_chirpProfile_txPhaseRotation_3_e] = 			rfeCfg_param_chirpProfile_txPhaseRotation_3_e,
	[rfe_paramUpdate_chirpProfile_txTransmissionReferenceTime_e] = 	rfeCfg_param_chirpProfile_txTransmissionReferenceTime_e,
	[rfe_paramUpdate_chirpProfile_txTransmissionTimeOffset_e] = 	rfeCfg_param_chirpProfile_txTransmissionTimeOffset_e,
	[rfe_paramUpdate_chirpProfile_chirpFrequencyDriftSteps_e] = 	rfeCfg_param_chirpProfile_chirpFrequencyDriftSteps_e,
	[rfe_paramUpdate_chirpProfile_rxGain_e] = 						rfeCfg_param_chirpProfile_rxGain_e,
	[rfe_paramUpdate_chirpProfile_rxHpfCutOffFrequency_e] = 		rfeCfg_param_chirpProfile_rxHpfCutOffFrequency_e,
	[rfe_paramUpdate_chirpProfile_rxLpfCutOffFrequency_e] = 		rfeCfg_param_chirpProfile_rxLpfCutOffFrequency_e,
	[rfe_paramUpdate_chirpProfile_virtualChannel_e] = 				rfeCfg_param_chirpProfile_virtualChannel_e
};
/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
 *                              		LOCAL FUNCTIONS
 ==================================================================================================*/
/**
 * \brief This function check if the update parameters are in range.
 *
 * \details This is a static function.
 *
 * \pre NIL
 *
 * \param [in]  	section - blob section,
 * \param [in]  	param - config parameter,
 * \param [in]  	paramValue - update value,
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return
 *
 * \post NIL
 *
 * \ingroup NIL
 */
static void CheckParamValue(rfeCfg_section_t section, rfe_paramUpdate_t param, uint32_t paramValue,
		rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t    sectionV = section;
	uint32_t             paramMin;
	uint32_t            paramMax;
	bool                validValue = false;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		if((section >= rfeCfg_section_chirpSequenceConfig_0_e) && (section <= rfeCfg_section_chirpSequenceConfig_7_e))
		{
			sectionV = rfeCfg_section_chirpSequenceConfig_0_e;
		}
		else if ((section >= rfeCfg_section_chirpProfile_0_e) && (section <= rfeCfg_section_chirpProfile_7_e))
		{
			sectionV = rfeCfg_section_chirpProfile_0_e;
		}
		else
		{
			//do nothing
		}

		paramMin = rfeCfg_read( rfeConfigBlobMinValues, sectionV, update_params[param], rfe___error___pointer );
		paramMax = rfeCfg_read( rfeConfigBlobMaxValues, sectionV, update_params[param], rfe___error___pointer );

		if ( paramMin <= paramMax )
		{
			// unsigned number range
			validValue = ( paramValue >= paramMin ) && ( paramValue <= paramMax );
		}
		else
		{
			// signed number range
			switch((uint16_t)update_params[param] & RFE_CFG_PARAM_SIZE_MSK )
			{
				case RFE_CFG_PARAM_SIZE_32_BIT:
				case RFE_CFG_PARAM_SIZE_32_BIT_FLOAT:
					validValue = ((int32_t)paramValue >= (int32_t)paramMin) && ((int32_t)paramValue <= (int32_t)paramMax);
					break;
				case RFE_CFG_PARAM_SIZE_16_BIT:
					validValue = ((int16_t)paramValue >= (int16_t)paramMin) && ((int16_t)paramValue <= (int16_t)paramMax);
					break;
				case RFE_CFG_PARAM_SIZE_8_BIT:
					validValue = ((int8_t)paramValue >= (int8_t)paramMin) && ((int8_t)paramValue <= (int8_t)paramMax);
					break;
				default:
					*rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_e;
					break;
			}

		}

		if ( !validValue )
		{
			*rfe___error___pointer = rfe_error_api_invalidConfigurationParameterValue_e;
		}
	}
}


static inline BOOL GetBitFromFuSaMask(uint8_t fuSaFaultMask, uint8_t bit)
{
	return (BOOL)((fuSaFaultMask >> bit) & 0x01U);
}

static void rfeSwCfgApplyfuSaFaultMask0Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_TxErrorMaskRegUnion_t TxErrorMask;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_TX_ERROR_MASK_REG_U16, &TxErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			TxErrorMask.bits_st.SupplyLowErrorFlag1V1Tx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx3_e & 0xffU);
			TxErrorMask.bits_st.SupplyLowErrorFlag1V1Tx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx2_e & 0xffU);
			TxErrorMask.bits_st.SupplyLowErrorFlag1V1Tx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx1_e & 0xffU);
			TxErrorMask.bits_st.PrErrorFlagTx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr72_pr_tx3_e & 0xffU);
			TxErrorMask.bits_st.PrErrorFlagTx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr72_pr_tx2_e & 0xffU);
			TxErrorMask.bits_st.PrErrorFlagTx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr72_pr_tx1_e & 0xffU);
			TxErrorMask.bits_st.SupplyLowErrorFlag1V8Tx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx3_e & 0xffU);
			TxErrorMask.bits_st.SupplyLowErrorFlag1V8Tx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx2_e & 0xffU);
			retVal = BC_SPI_Write(e_SYS_ISM, R2M18_TX_ERROR_MASK_REG_U16, TxErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask1Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_TxErrorMaskRegUnion_t TxErrorMask;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_TX_ERROR_MASK_REG_U16, &TxErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			TxErrorMask.bits_st.SupplyLowErrorFlag1V8Tx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx1_e & 0xffU);
			TxErrorMask.bits_st.RfLevelMaxErrorFlagTx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr69_rf_level_max_tx3_e & 0xffU);
			TxErrorMask.bits_st.RfLevelMaxErrorFlagTx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr69_rf_level_max_tx2_e & 0xffU);
			TxErrorMask.bits_st.RfLevelMaxErrorFlagTx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr69_rf_level_max_tx1_e & 0xffU);
			TxErrorMask.bits_st.RfLevelMinErrorFlagTx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr69_rf_level_min_tx3_e & 0xffU);
			TxErrorMask.bits_st.RfLevelMinErrorFlagTx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr69_rf_level_min_tx2_e & 0xffU);
			TxErrorMask.bits_st.RfLevelMinErrorFlagTx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr69_rf_level_min_tx1_e & 0xffU);
			TxErrorMask.bits_st.BbErrorFlagTx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr27_bb_tx3_e & 0xffU);
			retVal = BC_SPI_Write(e_SYS_ISM, R2M18_TX_ERROR_MASK_REG_U16, TxErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask2Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_TxErrorMaskRegUnion_t TxErrorMask;
	R2M18_RxErrorMaskRegUnion_t RxErrorMask;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_TX_ERROR_MASK_REG_U16, &TxErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			TxErrorMask.bits_st.BbErrorFlagTx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr27_bb_tx2_e & 0xffU);
			TxErrorMask.bits_st.BbErrorFlagTx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr27_bb_tx1_e & 0xffU);
			retVal = BC_SPI_Write(e_SYS_ISM, R2M18_TX_ERROR_MASK_REG_U16, TxErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RX_ERROR_MASK_REG_U16, &RxErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			RxErrorMask.bits_st.SupplyLowErrorFlag1V8Rx4Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx4_e & 0xffU);
			RxErrorMask.bits_st.SupplyLowErrorFlag1V8Rx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx3_e & 0xffU);
			RxErrorMask.bits_st.SupplyLowErrorFlag1V8Rx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx2_e & 0xffU);
			RxErrorMask.bits_st.SupplyLowErrorFlag1V8Rx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx1_e & 0xffU);
			RxErrorMask.bits_st.SupplyLowErrorFlag1V1Rx4Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx4_e & 0xffU);
			RxErrorMask.bits_st.SupplyLowErrorFlag1V1Rx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx3_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_RX_ERROR_MASK_REG_U16, RxErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask3Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_RxErrorMaskRegUnion_t RxErrorMask;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RX_ERROR_MASK_REG_U16, &RxErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			RxErrorMask.bits_st.SupplyLowErrorFlag1V1Rx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx2_e & 0xffU);
			RxErrorMask.bits_st.SupplyLowErrorFlag1V1Rx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx1_e & 0xffU);
			RxErrorMask.bits_st.LoLevelMaxErrorFlagRx4Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx4_e & 0xffU);
			RxErrorMask.bits_st.LoLevelMaxErrorFlagRx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx3_e & 0xffU);
			RxErrorMask.bits_st.LoLevelMaxErrorFlagRx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx2_e & 0xffU);
			RxErrorMask.bits_st.LoLevelMaxErrorFlagRx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx1_e & 0xffU);
			RxErrorMask.bits_st.LoLevelMinErrorFlagRx4Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx4_e & 0xffU);
			RxErrorMask.bits_st.LoLevelMinErrorFlagRx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx3_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_RX_ERROR_MASK_REG_U16, RxErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask4Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_RxErrorMaskRegUnion_t RxErrorMask;
	R2M18_ChirpErrorMaskRegUnion_t ChirpErrorMask;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RX_ERROR_MASK_REG_U16, &RxErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			RxErrorMask.bits_st.LoLevelMinErrorFlagRx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx2_e & 0xffU);
			RxErrorMask.bits_st.LoLevelMinErrorFlagRx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx1_e & 0xffU);
			RxErrorMask.bits_st.BbErrorFlagRx4Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr9_bb_rx4_e & 0xffU);
			RxErrorMask.bits_st.BbErrorFlagRx3Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr9_bb_rx3_e & 0xffU);
			RxErrorMask.bits_st.BbErrorFlagRx2Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr9_bb_rx2_e & 0xffU);
			RxErrorMask.bits_st.BbErrorFlagRx1Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr9_bb_rx1_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_RX_ERROR_MASK_REG_U16, RxErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			retVal = BC_SPI_Read(e_SYS_ISM, R2M18_CHIRP_ERROR_MASK_REG_U16, &ChirpErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			ChirpErrorMask.bits_st.AafcCalTimeoutErrorFlagChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr46_aafc_cal_timeout_chirp_e & 0xffU);
			ChirpErrorMask.bits_st.AafcErrorFlagChirpMask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr46_aafc_chirp_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_CHIRP_ERROR_MASK_REG_U16, ChirpErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask5Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_ChirpErrorMaskRegUnion_t ChirpErrorMask;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_CHIRP_ERROR_MASK_REG_U16, &ChirpErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			ChirpErrorMask.bits_st.SupplyLowErrorFlagDig1V1ChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_chirp_e & 0xffU);
			ChirpErrorMask.bits_st.SupplyLowErrorFlagVco1V8ChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_vco_1v8_chirp_e & 0xffU);
			ChirpErrorMask.bits_st.SupplyLowErrorFlagPll1V8ChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_pll_1v8_chirp_e & 0xffU);
			ChirpErrorMask.bits_st.InterfaceStuckErrorFlagChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr7_interface_stuck_chirp_e & 0xffU);
			ChirpErrorMask.bits_st.VcoFreq480ErrorFlagChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr42_vco_freq_480_chirp_e & 0xffU);
			ChirpErrorMask.bits_st.LevelMaxErrorFlagChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr45_level_max_chirp_e & 0xffU);
			ChirpErrorMask.bits_st.LevelMinErrorFlagChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr45_level_min_chirp_e & 0xffU);
			ChirpErrorMask.bits_st.UnlockErrorFlagChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr43_unlock_chirp_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_CHIRP_ERROR_MASK_REG_U16, ChirpErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask6Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_ChirpErrorMaskRegUnion_t ChirpErrorMask;
	R2M18_McLoCcIsmOtpErrorMaskRegUnion_t McLoCcIsmOtpErrorMask;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_CHIRP_ERROR_MASK_REG_U16, &ChirpErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			ChirpErrorMask.bits_st.LockStepErrorFlagChirpMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr7_lock_step_chirp_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_CHIRP_ERROR_MASK_REG_U16, ChirpErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MASK_REG_U16, &McLoCcIsmOtpErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			McLoCcIsmOtpErrorMask.bits_st.LoiLevelMaxErrorFlagInterfaceMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr48_level_max_loi_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.LoiLevelMinErrorFlagInterfaceMask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr48_level_min_loi_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.RdSpiCrcErrorFlagMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr19_rd_spi_crc_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.WrSpiCrcErrorFlagMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr19_wr_spi_crc_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.SupplyLowErrorFlag1V1InterfaceMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_loi_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.BbLoinErrorFlagInterfaceMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr17_bb_lo_in_loi_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.BbLooutErrorFlagInterfaceMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr18_bb_lo_out_loi_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MASK_REG_U16, McLoCcIsmOtpErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask7Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_SsbGbSerGldoAtbErrorMaskRegUnion_t SsbGbSerGldoAtbErrorMask;
	R2M18_McLoCcIsmOtpErrorMaskRegUnion_t McLoCcIsmOtpErrorMask;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MASK_REG_U16,
				&SsbGbSerGldoAtbErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			SsbGbSerGldoAtbErrorMask.bits_st.SupplyHighErrorFlag1V1GlobalLdoMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr57_supply_high_1v1_gldo_e & 0xffU);
			SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V1GlobalLdoMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr59_supply_low_1v1_gldo_e & 0xffU);
			SsbGbSerGldoAtbErrorMask.bits_st.SupplyHighErrorFlag1V8GlobalLdoMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr61_supply_high_1v8_gldo_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MASK_REG_U16, SsbGbSerGldoAtbErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MASK_REG_U16, &McLoCcIsmOtpErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			McLoCcIsmOtpErrorMask.bits_st.XoNoClockErrorFlagMcMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr11_xo_no_clock_mclk_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.MspcErrorFlagMcMask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr36_mspc_mclk_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.SupplyLowErrorFlag1V8McMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_mclk_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.DigFreqErrorFlagMcMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr39_dig_freq_mclk_e & 0xffU);
			McLoCcIsmOtpErrorMask.bits_st.PllLockErrorFlagMcMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr35_pll_lock_mclk_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MASK_REG_U16, McLoCcIsmOtpErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask8Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_SsbGbSerGldoAtbErrorMaskRegUnion_t SsbGbSerGldoAtbErrorMask;
	R2M18_AdcErrorMaskRegUnion_t AdcErrorMask;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MASK_REG_U16,
				&SsbGbSerGldoAtbErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8GlobalLdoMask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr63_supply_low_1v8_gldo_e     & 0xffU);
			SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8SerMask        = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_ser_e   & 0xffU);
			SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V1Csi2Mask       = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v1_csi2_e  & 0xffU);
			SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V1SerMask        = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v1_ser_e   & 0xffU);
			SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8GlobalBiasMask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_gbias_e & 0xffU);
			SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8SsbModMask     = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_ssb_e   & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MASK_REG_U16,
					SsbGbSerGldoAtbErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ADC_ERROR_MASK_REG_U16, &AdcErrorMask.val_u32);
		}
		if (retVal == BC_ERR_NOERROR)
		{
			AdcErrorMask.bits_st.SupplyLowErrorFlag1V8Adc34Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_adc34_e & 0xffU);
			AdcErrorMask.bits_st.SupplyLowErrorFlag1V8Adc12Mask = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_adc12_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_ADC_ERROR_MASK_REG_U16, AdcErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask9Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE retVal= BC_ERR_NOERROR;
	R2M18_AdcErrorMaskRegUnion_t AdcErrorMask;
	BOOL* swFusaMaskW = GetSwFusaMaskAddress();
	uint8_t fuSaFaultMask = 0U;
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		for(uint8_t index = (uint8_t)rfe_sw_fuSaFault_sr31_bist_lna_gaindiff_index_e; index < (uint8_t)rfe_sw_fuSaFault_sr31_bist_mixer_phasediff_index_e; index++ )
		{
			// Set  sr31-bist-lna-gaindiff-sw, sr31-bist-lna-phasediff-sw, sr31-bist-mixer-gaindiff-sw
			swFusaMaskW[index] = GetBitFromFuSaMask(fuSaFaultMask, index + 5U );
		}
		retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ADC_ERROR_MASK_REG_U16, &AdcErrorMask.val_u32);
		if (retVal == BC_ERR_NOERROR)
		{
			AdcErrorMask.bits_st.CalErrorFlagPersistentAdc4Mask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr34_cal_adc4_e & 0xffU);
			AdcErrorMask.bits_st.CalErrorFlagPersistentAdc3Mask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr34_cal_adc3_e & 0xffU);
			AdcErrorMask.bits_st.CalErrorFlagPersistentAdc2Mask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr34_cal_adc2_e & 0xffU);
			AdcErrorMask.bits_st.CalErrorFlagPersistentAdc1Mask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr34_cal_adc1_e & 0xffU);
			AdcErrorMask.bits_st.RegCrcErrorFlagAdc12Mask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0xffU);
			AdcErrorMask.bits_st.RegCrcErrorFlagAdc34Mask  = (uint32_t)GetBitFromFuSaMask((uint8_t)value, (uint8_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0xffU);
			retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_ADC_ERROR_MASK_REG_U16, AdcErrorMask.val_u32);
		}
		if (retVal != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(retVal);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask10Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
    (void)value;
	uint8_t fuSaFaultMask = 0U;
	BOOL* swFusaMaskL = GetSwFusaMaskAddress();
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		for(uint8_t index = (uint8_t)rfe_sw_fuSaFault_sr31_bist_mixer_phasediff_index_e; index < (uint8_t)rfe_sw_fuSaFault_sr72_tx3_pr_cal_index_e; index++)
		{
			// Set sr72-tx2-pr-cal-sw, sr72-tx1-pr-cal-sw,  sr72-tx-pr-cal-sw, sr70-tx-integrity-sw, sr44-cafc-integrity-sw, sr44-cafc-intgerity-unlock-sw,
		    //      sr44-cafc-intgerity-level-sw, sr31-bist-mixer-phasediff-sw
			swFusaMaskL[index] = GetBitFromFuSaMask(fuSaFaultMask, index - 3U);
		}
	}
}

static void rfeSwCfgApplyfuSaFaultMask11Updates(uint32_t value,	rfe_error_t* rfe___error___pointer)
{
    (void)value;
	uint8_t fuSaFaultMask = 0U;
	BOOL* swFusaMaskW = GetSwFusaMaskAddress();
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		for(uint8_t index = (uint8_t)rfe_sw_fuSaFault_sr72_tx3_pr_cal_index_e; index < ((uint8_t)rfe_sw_generic_index_e + 1U); index++)
		{
			// Set rfe-generic-sw,  sr13-input-mode-toggle-test-sw, sr14-disable-lb-toggle-test-sw, sr72-tx3-pr-cal-sw
			swFusaMaskW[index] = GetBitFromFuSaMask(fuSaFaultMask, index - 11U);
		}
	}
}

static void GetProfileParam(SYS_ProfChirpTiming_t* profChirpTiming, SYS_ProfChirpFreq_t* profChirpFreq,
		SYS_ProfChirpSampleDeci_t* profChirpSample, uint8_t	profileIdx, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer)
{
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		GetProfChirpSample(profChirpSample, profileIdx, pRfeConfig, rfe___error___pointer);
	}

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		GetProfChirpFreq(profChirpFreq, profileIdx, pRfeConfig, rfe___error___pointer);
	}

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		GetProfChirpTiming(profChirpTiming, profileIdx, pRfeConfig, rfe___error___pointer);
	}
}

static void rfeSwCfgApplyProfilScUpdate(uint8_t	profileIdx, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	SYS_ProfChirpSampleDeci_t profChirpSample;
	SYS_ProfChirpFreq_t profChirpFreq;
	SYS_ProfChirpTiming_t profChirpTiming;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		GetProfileParam(&profChirpTiming, &profChirpFreq, &profChirpSample, profileIdx, pRfeConfig, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = Helper_ConfigSC((SYS_ProfID_e)profileIdx, &profChirpTiming, &profChirpFreq, &profChirpSample);
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyJumpbackTimeTicksUpdate(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	float32_t   jumpBackTime    = 0.0f;
	uint8_t     profileIdx      = 0U;
	uint8_t	noChirpProfiles 	= 0U;
	BC_ERRCODE  errCode         = BC_ERR_NOERROR;

	jumpBackTime = (float32_t)rfeCfg_general_getJumpbackTimeTicks(pDrvState->rfeConfig, rfe___error___pointer) * TICK_TO_US;
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = HAL_ES2_TE_SetJumpBackTime(jumpBackTime);
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		noChirpProfiles = rfeCfg_metadata_getChirpProfileCount(
				pDrvState->rfeConfig, rfe___error___pointer);
	}
	for(profileIdx = 0; profileIdx < noChirpProfiles; ++profileIdx)
	{
		if(*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		rfeSwCfgApplyProfilScUpdate(profileIdx, pDrvState->rfeConfig, rfe___error___pointer);
	}
}

static void rfeSwCfgApplyGeneralUpdates(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex,
		uint32_t value, rfe_error_t* rfe___error___pointer)
{
    (void)value;

	switch(paramIndex)
	{
		case (uint16_t)rfe_paramUpdate_general_powerMode_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_general_radarCycleStartSignalGpio_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_general_chirpSequenceActiveSignalGpio_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_general_clkIoConfig_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_general_pdcDecimationFilter_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_general_dataOutConfig_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_general_metadataPacketSwContent_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_general_metadataPacketVirtualChannel_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_general_jumpbackTimeTicks_e:
		{
			rfeSwCfgApplyJumpbackTimeTicksUpdate(pDrvState, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_general_txCalibration_mode_e:
		{
			pDrvState->tef82xxDrvState.enableReduceTransmisionForVGACalib =
					!(BOOL) rfeCfg_general_getTxCalibrationMode(pDrvState->rfeConfig, rfe___error___pointer);
			break;
		}
		default:
		    *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
			break;
	}
}

static void UpdateRxSaturationThresholdStage(rfeDriverPersistentMem_t *pDrvState, rfe_rxIndex_t rxIndex, rfe_error_t* rfe___error___pointer )
{

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		switch(rxIndex)
		{
			case rfe_rxIndex_1_e:
			case rfe_rxIndex_2_e:
			{
				SetRxSaturationThresholdStage(pDrvState->rfeConfig, e_SYS_ADC12, rfe___error___pointer );
				break;
			}
			case rfe_rxIndex_3_e:
			case rfe_rxIndex_4_e:
			{
				SetRxSaturationThresholdStage(pDrvState->rfeConfig, e_SYS_ADC34, rfe___error___pointer );
				break;
			}
			default:
			{
				*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
				break;
			}
		}
	}
}

static void MonitorRxStaurationUpdate(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex, uint32_t value,
		rfe_error_t* rfe___error___pointer)
{
	switch(paramIndex)
	{
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSatCountResetEveryChirpSequence_e:
		{
			// do nothing, the rxSatCountResetEveryChirpSequence is already saved in rfeConfig
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx1_e:
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx1_e:
		{
			UpdateRxSaturationThresholdStage(pDrvState, rfe_rxIndex_1_e, rfe___error___pointer );
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx2_e:
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx2_e:
		{
			UpdateRxSaturationThresholdStage(pDrvState, rfe_rxIndex_2_e, rfe___error___pointer );
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx3_e:
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx3_e:
		{
			UpdateRxSaturationThresholdStage(pDrvState, rfe_rxIndex_3_e, rfe___error___pointer );
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx4_e:
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx4_e:
		{
			UpdateRxSaturationThresholdStage(pDrvState, rfe_rxIndex_4_e, rfe___error___pointer );
			break;
		}
		default:
		{
			//do nothing
			break;
		}
	}
}

static void MonitorAdcAndTempUpdate(uint16_t paramIndex, uint32_t value)
{
	switch(paramIndex)
	{
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_adcClippingCountResetEveryChirpSequence_e:
		{
			// do nothing, the adcClippingCountResetEveryChirpSequence is already saved in rfeConfig
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc1_e:
		{
			// do nothing, the adcClippingCountLimit_adc1 is already saved in rfeConfig
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc2_e:
		{
			// do nothing, the adcClippingCountLimit_adc2 is already saved in rfeConfig
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc3_e:
		{
			// do nothing, the adcClippingCountLimit_adc3 is already saved in rfeConfig
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc4_e:
		{
			// do nothing, the adcClippingCountLimit_adc4 is already saved in rfeConfig
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdHigh_tx12_e:
		{
			// do nothing, parameter is not use yet
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdHigh_tx3_e:
		{
			// do nothing, parameter is not use yet
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdHigh_xo_e:
		{
			// do nothing, parameter is not use yet
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdOver_tx12_e:
		{
			// do nothing, parameter is not use yet
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdOver_tx3_e:
		{
			// do nothing, parameter is not use yet
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdOver_xo_e:
		{
			// do nothing, parameter is not use yet
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdUnder_tx12_e:
		{
			// do nothing, parameter is not use yet
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdUnder_tx3_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdUnder_xo_e:
		{
			// do nothing, parameter is not use yet
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_thresholdValueToPromoteR1Faults_e:
		{
			// do nothing, parameter is not use yet
			break;
		}
		default:
		{
			//do nothing
			break;
		}
	}
}

static void rfeSwCfgApplyMonitorsUpdate(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex,
		uint32_t value, rfe_error_t* rfe___error___pointer)
{
	if((paramIndex >= (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSatCountResetEveryChirpSequence_e) &&
				(paramIndex <= (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage2_rx4_e))
	{
		MonitorRxStaurationUpdate(pDrvState, paramIndex, value, rfe___error___pointer);
	}
	else if((paramIndex >= (uint16_t)rfe_paramUpdate_monitorAndSafety_adcClippingCountResetEveryChirpSequence_e) &&
			(paramIndex <= (uint16_t)rfe_paramUpdate_monitorAndSafety_thresholdValueToPromoteR1Faults_e))
	{
		MonitorAdcAndTempUpdate(paramIndex, value);
	}
	else
	{
		//Do nothing
	}
}

static void BistUpdate_1(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex,
		uint32_t value)
{
	rfeSwBist_rxBistParam_t* bistParamPtr = rfeSwBist_getBistParamsAddress();
	switch(paramIndex)
	{
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_frequencyForBist_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx2_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refPh[0][TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value));
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx3_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refPh[1][TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value));
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx4_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refPh[2][TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value));
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxPhaseDiffLnaThresholdTolerance_e:
		{
			bistParamPtr[pDrvState->frontendId].rxBistPhaseThreshold[TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_degrees2radians(rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value)));
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx2_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refMag[0][TEF82XX_RFBIST_LNA_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx3_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refMag[1][TEF82XX_RFBIST_LNA_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx4_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refMag[2][TEF82XX_RFBIST_LNA_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxGainDiffLnaThresholdTolerance_e:
		{
			bistParamPtr[pDrvState->frontendId].rxBistGainThreshold[TEF82XX_RFBIST_LNA_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value);
			break;
		}
		default:
		{
			//do nothing
			break;
		}
	}
}

static void BistUpdate_2(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex,
		uint32_t value)
{
	rfeSwBist_rxBistParam_t* bistParamPtr = rfeSwBist_getBistParamsAddress();
	switch(paramIndex)
	{
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx2_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refPh[0][TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value));
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx3_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refPh[1][TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value));
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx4_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refPh[2][TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value));
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxPhaseDiffMixerThresholdTolerance_e:
		{
			bistParamPtr[pDrvState->frontendId].rxBistPhaseThreshold[TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value));
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx2_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refMag[0][TEF82XX_RFBIST_MIXER_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx3_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refMag[1][TEF82XX_RFBIST_MIXER_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx4_e:
		{
			bistParamPtr[pDrvState->frontendId].zeroDayMeasurementBuff.refMag[2][TEF82XX_RFBIST_MIXER_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_rxGainDiffMixerThresholdTolerance_e:
		{
			bistParamPtr[pDrvState->frontendId].rxBistGainThreshold[TEF82XX_RFBIST_MIXER_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT((int16_t)value);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_injectTestTone_e:
		{
			bistParamPtr[pDrvState->frontendId].rxBistInjectToneMode = InjectToneModeMapper((uint8_t)value);
			break;
		}
		default:
		{
			//do nothing
			break;
		}
	}
}
static void rfeSwCfgApplyBistUpdate(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex,
		uint32_t value)
{
	if((paramIndex >= (uint16_t)rfe_paramUpdate_monitorAndSafety_frequencyForBist_e) &&
			(paramIndex <= (uint16_t)rfe_paramUpdate_monitorAndSafety_rxGainDiffLnaThresholdTolerance_e))
	{
		BistUpdate_1(pDrvState, paramIndex, value);
	}
	else if((paramIndex >= (uint16_t)rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx2_e) &&
			(paramIndex <= (uint16_t)rfe_paramUpdate_monitorAndSafety_injectTestTone_e))
	{
		BistUpdate_2(pDrvState, paramIndex, value);
	}
	else
	{
		//Do nothing
	}
}

static void UpdateTxBbd(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE	errCode = BC_ERR_NOERROR;
	uint8_t bbd = 0;
	BOOL bbdTxEneble = (BOOL)FALSE;
	BOOL bbdTxSensitivity = (BOOL)FALSE;
	BOOL bbdTxGrounded = (BOOL)FALSE;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		bbd = rfeCfg_monitorAndSafety_getTxBBD(pDrvState->rfeConfig, rfe___error___pointer);
		bbdTxEneble = (BOOL)((bbd >> 2U) & 0x01U);
		bbdTxSensitivity = (BOOL) ((bbd >> 1U) & 0x01U);
		bbdTxGrounded = (BOOL) (bbd & 0x01U);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_TX_ConfigBBD(e_SYS_TXMC, bbdTxEneble, bbdTxSensitivity, bbdTxGrounded);
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void UpdateRxBbd(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	uint8_t bbd = 0;
	BOOL bbdRxEneble = (BOOL)FALSE;
	BOOL bbdRxSensitivity = (BOOL)FALSE;
	BOOL bbdRxGrounded = (BOOL)FALSE;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		bbd = rfeCfg_monitorAndSafety_getRxBBD(pDrvState->rfeConfig, rfe___error___pointer);
		bbdRxEneble = (BOOL)((bbd >> 2U) & 0x01U);
		bbdRxSensitivity = (BOOL) ((bbd >> 1U) & 0x01U);
		bbdRxGrounded = (BOOL) (bbd & 0x01U);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_RX_ConfigBBD(e_SYS_RXMC, bbdRxEneble, bbdRxSensitivity, bbdRxGrounded);
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyBbdUpdate(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex,
		uint32_t value, rfe_error_t* rfe___error___pointer)
{
	switch(paramIndex)
	{
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_checkBbd_loi_e:
		{
			pDrvState->tef82xxDrvState.loiBbdEn         = (BOOL)((value >> 4u) & 0x01U);
			pDrvState->tef82xxDrvState.LoOutSensitivity = (BOOL)((value >> 3u) & 0x01U);
			pDrvState->tef82xxDrvState.LoOutGrounded    = (BOOL)((value >> 2u) & 0x01U);
			pDrvState->tef82xxDrvState.LoISensitivity   = (BOOL)((value >> 1u) & 0x01U);
			pDrvState->tef82xxDrvState.LoIGrounded      = (BOOL)((value >> 0u) & 0x01U);
			rfeCfg_monitorAndSafety_setLoiBBD(pDrvState->rfeConfig, (uint8_t)value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_checkBbd_tx_e:
		{
			UpdateTxBbd(pDrvState, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_checkBbd_rx_e:
		{
			UpdateRxBbd(pDrvState, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_ppdThreshold_profile0_e:
		{
			break;
		}
		default:
		{
			// do nothing
			break;
		}
	}
}

static void rfeSwCfgApplyFusaUpdate(uint16_t paramIndex, uint32_t value, rfe_error_t* rfe___error___pointer)
{
	switch(paramIndex)
	{
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_ppdThreshold_profile0_e:
		{
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_0_e:
		{
			rfeSwCfgApplyfuSaFaultMask0Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_1_e:
		{
			rfeSwCfgApplyfuSaFaultMask1Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_2_e:
		{
			rfeSwCfgApplyfuSaFaultMask2Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_3_e:
		{
			rfeSwCfgApplyfuSaFaultMask3Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_4_e:
		{
			rfeSwCfgApplyfuSaFaultMask4Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_5_e:
		{
			rfeSwCfgApplyfuSaFaultMask5Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_6_e:
		{
			rfeSwCfgApplyfuSaFaultMask6Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_7_e:
		{
			rfeSwCfgApplyfuSaFaultMask7Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_8_e:
		{
			rfeSwCfgApplyfuSaFaultMask8Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_9_e:
		{
			rfeSwCfgApplyfuSaFaultMask9Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_10_e:
		{
			rfeSwCfgApplyfuSaFaultMask10Updates(value, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_11_e:
		{
			rfeSwCfgApplyfuSaFaultMask11Updates(value, rfe___error___pointer);
			break;
		}
		default:
		{
			// do nothing
			break;
		}
	}
}

static void rfeSwCfgApplyMonitorAndSafetyUpdates(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex,
		uint32_t value, rfe_error_t* rfe___error___pointer)
{
    if(*rfe___error___pointer == rfe_error_none_e)
    {
		if((paramIndex >= (uint16_t)rfe_paramUpdate_monitorAndSafety_rxSatCountResetEveryChirpSequence_e) &&
				(paramIndex <= (uint16_t)rfe_paramUpdate_monitorAndSafety_thresholdValueToPromoteR1Faults_e))
		{
			rfeSwCfgApplyMonitorsUpdate(pDrvState, paramIndex, value, rfe___error___pointer);
		}
		else if((paramIndex >= (uint16_t)rfe_paramUpdate_monitorAndSafety_frequencyForBist_e) &&
				(paramIndex <= (uint16_t)rfe_paramUpdate_monitorAndSafety_injectTestTone_e))
		{
			rfeSwCfgApplyBistUpdate(pDrvState, paramIndex, value);
		}
		else if((paramIndex >= (uint16_t)rfe_paramUpdate_monitorAndSafety_checkBbd_loi_e) &&
					(paramIndex <= (uint16_t)rfe_paramUpdate_monitorAndSafety_ppdThreshold_profile0_e))
		{
			rfeSwCfgApplyBbdUpdate(pDrvState, paramIndex, value, rfe___error___pointer);
		}
		else if((paramIndex >= (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_0_e) &&
						(paramIndex <= (uint16_t)rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_11_e))
		{
			rfeSwCfgApplyFusaUpdate(paramIndex, value, rfe___error___pointer);
		}
		else
		{
			*rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
		}
    }
}

static void rfeSwCfgApplyRadarCycleChirpSequenceUpdates(rfeDriverPersistentMem_t *pDrvState, rfe_paramUpdate_t paramIndex,
		rfe_error_t* rfe___error___pointer)
{
	uint8_t sequenceConfigCount = rfeCfg_metadata_getChirpSequenceConfigCount(pDrvState->rfeConfig, rfe___error___pointer);

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		if(sequenceConfigCount > ((uint8_t)paramIndex - (uint8_t)rfe_paramUpdate_radarCycle_chirpSequence_0_e))
		{
		    // TODO : check if the result of the next function to be used or let it as is
			(void)rfeSwMainFsm_calcRadarCycleTimingSchedule( pDrvState->rfeConfig, rfe___error___pointer);
		}
		else
		{
			*rfe___error___pointer = rfe_error_api_maxUpdateCountExceeded_e;
		}
	}
}

static void rfeSwCfgApplyRadarCycleChirpSequenceStartTimeOffsetUpdates(rfeDriverPersistentMem_t *pDrvState, rfe_paramUpdate_t paramIndex, rfe_error_t* rfe___error___pointer)
{
	uint8_t sequenceConfigCount = rfeCfg_metadata_getChirpSequenceConfigCount(pDrvState->rfeConfig, rfe___error___pointer);
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		if(sequenceConfigCount > ((uint8_t)paramIndex - (uint8_t)rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_0_e))
		{
            // TODO : check if the result of the next function to be used or let it as is
			(void)rfeSwMainFsm_calcRadarCycleTimingSchedule(pDrvState->rfeConfig, rfe___error___pointer);
		}
		else
		{
			*rfe___error___pointer = rfe_error_api_maxUpdateCountExceeded_e;
		}
	}
}

static void rfeSwCfgApplyRadarCycleUpdates(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex,
		uint32_t value, rfe_error_t* rfe___error___pointer)
{
	uint8_t sequenceConfigCount = 0U;

	switch(paramIndex)
	{
		case (uint16_t)rfe_paramUpdate_radarCycle_radarCycleDuration_e:
		{
			// TODO : check if the result of the next function to be used or let it as is
			(void)rfeSwMainFsm_calcRadarCycleTimingSchedule(pDrvState->rfeConfig, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequenceCount_e:
		{
			sequenceConfigCount = rfeCfg_metadata_getChirpSequenceConfigCount(pDrvState->rfeConfig, rfe___error___pointer);
			if(*rfe___error___pointer == rfe_error_none_e)
			{
				if(value < sequenceConfigCount)
				{
					pDrvState->tef82xxDrvState.radarCycleParams.noRadarSequences = (uint8_t)value;
					// TODO : check if the result of the next function to be used or let it as is
					(void)rfeSwMainFsm_calcRadarCycleTimingSchedule( pDrvState->rfeConfig, rfe___error___pointer);
				}
				else
				{
					*rfe___error___pointer = rfe_error_api_maxUpdateCountExceeded_e;
				}
			}
			break;
		}
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequence_0_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequence_1_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequence_2_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequence_3_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequence_4_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequence_5_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequence_6_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequence_7_e:
		{
			rfeSwCfgApplyRadarCycleChirpSequenceUpdates(pDrvState, (rfe_paramUpdate_t)paramIndex, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_0_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_1_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_2_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_3_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_4_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_5_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_6_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_7_e:
		{
			rfeSwCfgApplyRadarCycleChirpSequenceStartTimeOffsetUpdates(pDrvState, (rfe_paramUpdate_t)paramIndex, rfe___error___pointer);
			break;
		}
		case (uint16_t)rfe_paramUpdate_radarCycle_recalibrateProfileDependent_0_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_recalibrateProfileDependent_1_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_recalibrateProfileDependent_2_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_recalibrateProfileDependent_3_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_recalibrateProfileDependent_4_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_recalibrateProfileDependent_5_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_recalibrateProfileDependent_6_e:
		case (uint16_t)rfe_paramUpdate_radarCycle_recalibrateProfileDependent_7_e:
		{
			//not implemented yet
			break;
		}
		case (uint16_t)rfe_paramUpdate_radarCycle_bistInterval_e:
		{
			rfeSwBist_rxBistParam_t* bistParamsL = rfeSwBist_getBistParamsAddress();
			if(value == (uint32_t)rfe_bistInterval_none_e)
			{
				bistParamsL[pDrvState->frontendId].bistActive = false;
			}
			else
			{
				bistParamsL[pDrvState->frontendId].bistActive = true;
			}
			break;
		}
		default:
		{
			// do nothing
			break;
		}
	}
}

static uint8_t GetSequenceUpdate(uint16_t section, rfe_error_t* rfe___error___pointer)
{
	uint8_t sequence = 0;

	switch(section)
	{
		case (uint16_t)rfeCfg_section_chirpSequenceConfig_0_e:
		{
			sequence = (uint8_t)rfe_chirpSequenceIndex_0_e;
			break;
		}
		case (uint16_t)rfeCfg_section_chirpSequenceConfig_1_e:
		{
			sequence = (uint8_t)rfe_chirpSequenceIndex_1_e;
			break;
		}
		case (uint16_t)rfeCfg_section_chirpSequenceConfig_2_e:
		{
			sequence = (uint8_t)rfe_chirpSequenceIndex_2_e;
			break;
		}
		case (uint16_t)rfeCfg_section_chirpSequenceConfig_3_e:
		{
			sequence = (uint8_t)rfe_chirpSequenceIndex_3_e;
			break;
		}
		case (uint16_t)rfeCfg_section_chirpSequenceConfig_4_e:
		{
			sequence = (uint8_t)rfe_chirpSequenceIndex_4_e;
			break;
		}
		case (uint16_t)rfeCfg_section_chirpSequenceConfig_5_e:
		{
			sequence = (uint8_t)rfe_chirpSequenceIndex_5_e;
			break;
		}
		case (uint16_t)rfeCfg_section_chirpSequenceConfig_6_e:
		{
			sequence = (uint8_t)rfe_chirpSequenceIndex_6_e;
			break;
		}
		case (uint16_t)rfeCfg_section_chirpSequenceConfig_7_e:
		{
			sequence = (uint8_t)rfe_chirpSequenceIndex_7_e;
			break;
		}
		default:
			*rfe___error___pointer = rfe_error_bc_inputOutOfRange;
			break;
	}
	return sequence;
}

static void rfeSwCfgApplyChirpProfileSequenceUpdates(rfeDriverPersistentMem_t *pDrvState, uint8_t sequence,
		rfe_error_t* rfe___error___pointer)
{
	uint8_t chirpProfileSequenceLength = 0U;
	uint8_t idx = 0U;
	BOOL customPatern = (BOOL)FALSE;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		chirpProfileSequenceLength = rfeCfg_chirpSequence_getChirpProfileSequenceLength(pDrvState->rfeConfig, rfeChirpSequenceMapper(sequence), rfe___error___pointer);
	}
	for(idx = 0; idx < (uint8_t)RFE_MAX_CHIRP_PROFILES; ++idx)
	{
		if(*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profList[idx] = (uint8_t)INIT_PROF_LIST;
	}
	for(idx = 0; idx < chirpProfileSequenceLength; ++idx)
	{
		if(*rfe___error___pointer != rfe_error_none_e)
		{
				break;
		}
		pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profList[idx] =
				(uint8_t)rfeCfg_chirpSequence_getChirpProfileSequence(pDrvState->rfeConfig, rfeChirpSequenceMapper(sequence), idx, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		// more then one chirp profile in sequence
		if(chirpProfileSequenceLength > 1U)
		{
			for(idx = 0; idx < chirpProfileSequenceLength; ++idx)
			{
				if(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profList[idx] != idx)
				{
					customPatern = TRUE;
					break;
				}
			}
			if(customPatern == TRUE)
			{
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profModeSel = USE_PROFILE_LIST;
			}
			else
			{
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profModeSel = chirpProfileSequenceLength + (uint8_t)PROFILE_GREAT_ONE_OFFSET;
			}
		}
		else
		{
			// single profile
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profModeSel =
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profList[0];
		}
		// more then one chirp profile in sequence
		if(chirpProfileSequenceLength > 1U)
		{
			// fit chirp profile sequence in BC regs
			for(idx = 0; idx < chirpProfileSequenceLength; ++idx)
			{
				if(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profList[idx] != idx)
				{
					customPatern = TRUE;
					break;
				}
			}
			if(customPatern == TRUE)
			{
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profModeSel = (uint8_t)USE_PROFILE_LIST;
			}
			else
			{
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profModeSel = chirpProfileSequenceLength + (uint8_t)PROFILE_GREAT_ONE_OFFSET;
			}
		}
		else
		{
			// single profile
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profModeSel =
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].profList[0];
		}
	}
	TE_ConfigProfileSequencing(sequence, rfe___error___pointer);
	TE_ConfigStatic(sequence, pDrvState->rfeConfig, rfe___error___pointer);
	rfeSwBist_initialConfiguration(pDrvState, pDrvState->rfeConfig, rfeChirpSequenceMapper(sequence), rfe___error___pointer);
}

static void rfeSwCfgApplyRxEnableUpdates(rfeDriverPersistentMem_t *pDrvState, uint8_t sequence,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	uint8_t noChirpProfiles = 0;
	uint8_t	rxEn[RFE_MAX_RX_CHANNELS];
	uint16_t CtrlReg3Addr;
	R2M04_TimingControl3Profile0Union_t Ctr3ProfX;
	uint8_t idx = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		noChirpProfiles = rfeCfg_metadata_getChirpProfileCount(pDrvState->rfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].rxChannelEnable =
			(uint8_t)rfeCfg_chirpSequence_getRxEnable(pDrvState->rfeConfig, rfeChirpSequenceMapper(sequence), rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		// RX is enabled the same for all profiles
		rxEn[0] = (pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].rxChannelEnable >> RFE_RX_CHANNEL_0) & 0x01U;
		rxEn[1] = (pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].rxChannelEnable >> RFE_RX_CHANNEL_1) & 0x01U;
		rxEn[2] = (pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].rxChannelEnable >> RFE_RX_CHANNEL_2) & 0x01U;
		rxEn[3] = (pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].rxChannelEnable >> RFE_RX_CHANNEL_3) & 0x01U;
		errCode = BC_ERR_NOERROR;
		for(idx = 0; idx < noChirpProfiles; ++idx)
		{
			if(errCode != BC_ERR_NOERROR)
			{
				break;
			}
			Ctr3ProfX.val_u32 = 0u;
			CtrlReg3Addr = R2M04_TIMING_CONTROL_3_PROFILE0_U16 + (((uint16_t)idx - (uint16_t)e_SYS_PROFILE_0) *
					(R2M04_TIMING_CONTROL_3_PROFILE1_U16 - R2M04_TIMING_CONTROL_3_PROFILE0_U16));
			errCode = BC_SPI_Read(e_SYS_TE, CtrlReg3Addr, &Ctr3ProfX.val_u32);
			if (BC_ERR_NOERROR == errCode)
			{
				Ctr3ProfX.bits_st.Rx1ActiveProfile0 = (uint8_t)rxEn[0];
				Ctr3ProfX.bits_st.Rx2ActiveProfile0 = (uint8_t)rxEn[1];
				Ctr3ProfX.bits_st.Rx3ActiveProfile0 = (uint8_t)rxEn[2];
				Ctr3ProfX.bits_st.Rx4ActiveProfile0 = (uint8_t)rxEn[3];
				errCode = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg3Addr, Ctr3ProfX.val_u32);
			}
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyChirpSequenceUpdates(rfeDriverPersistentMem_t *pDrvState, uint16_t section,
		uint16_t paramIndex, rfe_error_t* rfe___error___pointer)
{
	uint8_t 			sequence = 0;

	sequence = GetSequenceUpdate(section, rfe___error___pointer);
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		switch(paramIndex)
		{
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpCount_e:
			{
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequence].nrChirpsInFrame =
							rfeCfg_chirpSequence_getChirpCount(pDrvState->rfeConfig, (rfe_chirpSequenceIndex_t)sequence, rfe___error___pointer);
				(void)rfeSwMainFsm_calcRadarCycleTimingSchedule(pDrvState->rfeConfig, rfe___error___pointer);
				TE_ConfigStatic((uint8_t)sequence, pDrvState->rfeConfig, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpProfileSequence_0_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpProfileSequence_1_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpProfileSequence_2_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpProfileSequence_3_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpProfileSequence_4_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpProfileSequence_5_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpProfileSequence_6_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpProfileSequence_7_e:
			{
				rfeSwCfgApplyChirpProfileSequenceUpdates(pDrvState, sequence, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpSequence_chirpProfileSequenceLength_e:
			{
				// do nothing, the chirpProfileSequenceLength is already saved in rfeConfig
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpSequence_dynamicUpdatesEnabled_e:
			{
				// do nothing, the chirpSequence_dynamicUpdatesEnabled is already saved in rfeConfig
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpSequence_dynamicTableIndex_e:
			{
				// do nothing, the chirpSequence_dynamicTableIndex is already saved in rfeConfig
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx1_init_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx2_init_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx3_init_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx1_update_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx2_update_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx3_update_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx1_mode_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx2_mode_e:
			case (uint16_t)rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx3_mode_e:
			{
				rfeSwCfg_PhaseRotatorPhaseControl(pDrvState->rfeConfig, rfeChirpSequenceMapper(sequence), rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpSequence_rxEnable_e:
			{
				rfeSwCfgApplyRxEnableUpdates(pDrvState, sequence, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpSequence_pdcNotchFilterEnable_e:
			{
				// not used yet
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpSequence_txCalibration_thresholdHigh_e:
			{
				// do nothing, the txCalibration_thresholdHigh is already saved in rfeConfig
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpSequence_txCalibration_thresholdLow_e:
			{
				// do nothing, the txCalibration_thresholdLow is already saved in rfeConfig
				break;
			}
			default:
			{
				//do nothing
				break;
			}
		}
	}
}

static BC_ERRCODE DwellTimeUpdate(uint8_t profileIdx, SYS_ProfChirpTiming_t* profChirpTiming)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	uint32_t tmpDwellTime;
	uint16_t CtrlReg1Addr;
	R2M04_TimingControl1Profile0Union_t Ctr1ProfX;

	tmpDwellTime = (uint32_t)lroundf(profChirpTiming->TDwell * 1000.0f / 25.0f);
	/*Dwell time - allowed values: 0x002 to 0xFFE*/
	if ((tmpDwellTime <= 0x001u) || (tmpDwellTime >= 0xFFFu))
	{
		errCode = BC_ERR_TE_DWELLTIME;
	}
	if(errCode == BC_ERR_NOERROR)
	{
		if (((profChirpTiming->TriggerTXSWAndBPSAtTSettle == FALSE) && (profChirpTiming->TXSWAndBPSDelay >= (float32_t)tmpDwellTime))) /*Trigger point is start of Tdwell*/
		{
			errCode = BC_ERR_TE_DELAYFROMREFPT;
		}
	}
	if(errCode == BC_ERR_NOERROR)
	{
		CtrlReg1Addr = R2M04_TIMING_CONTROL_1_PROFILE0_U16 +
				(((uint16_t)profileIdx - (uint16_t)e_SYS_PROFILE_0) * (R2M04_TIMING_CONTROL_1_PROFILE1_U16 - R2M04_TIMING_CONTROL_1_PROFILE0_U16));
		errCode = BC_SPI_Read(e_SYS_TE, CtrlReg1Addr, &Ctr1ProfX.val_u32);
	}
	if (BC_ERR_NOERROR == errCode)
	{
		Ctr1ProfX.bits_st.DwellTimeProfile0 = (uint16_t)tmpDwellTime;
		errCode = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg1Addr, Ctr1ProfX.val_u32);
	}
	return errCode;
}

static BC_ERRCODE SettleTimeUpdate(uint8_t profileIdx, SYS_ProfChirpTiming_t* profChirpTiming)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	R2M04_TimingControl2Profile0Union_t Ctr2ProfX;
	uint16_t CtrlReg2Addr;
	uint32_t tmpSettleTime;

	CtrlReg2Addr = R2M04_TIMING_CONTROL_2_PROFILE0_U16 + (((uint16_t)profileIdx - (uint16_t)e_SYS_PROFILE_0) * (R2M04_TIMING_CONTROL_2_PROFILE1_U16 - R2M04_TIMING_CONTROL_2_PROFILE0_U16));
	errCode = BC_SPI_Read(e_SYS_TE, CtrlReg2Addr, &Ctr2ProfX.val_u32);
	if(errCode == BC_ERR_NOERROR)
	{
		 tmpSettleTime = (uint32_t)lroundf((profChirpTiming->TSettle * 1000.0f)/ 25.0f);
		/*2. Allowed values 0x001 to 0xFFE*/
		if (!((tmpSettleTime >= 1u) && (tmpSettleTime < 0xFFFu)))
		{
			errCode = BC_ERR_TE_SETTLETIME;
		}
	}
	if(errCode == BC_ERR_NOERROR)
	{
		Ctr2ProfX.bits_st.SettleTimeProfile0 = (uint16_t)tmpSettleTime;
		errCode = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg2Addr, Ctr2ProfX.val_u32);
	}
	return errCode;
}

static BC_ERRCODE ChirpPeriodUpdate(uint8_t profileIdx, SYS_ProfChirpTiming_t* profChirpTiming)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	R2M04_TimingControl3Profile0Union_t Ctr3ProfX;
	uint16_t CtrlReg3Addr;
	uint32_t tmpChirpPeriod;

	/*Converting to 25ns base*/
	tmpChirpPeriod = (uint32_t)lroundf((profChirpTiming->TChirp * 1000.0f) / 25.0f);
	/* It should be of 22 bits */
	if (tmpChirpPeriod > 0x3FFFFFu)
	{
		errCode = BC_ERR_TE_CHIRPINTERVAL;
	}
	if(errCode == BC_ERR_NOERROR)
	{
		CtrlReg3Addr = R2M04_TIMING_CONTROL_3_PROFILE0_U16 + (((uint16_t)profileIdx - (uint16_t)e_SYS_PROFILE_0) * (R2M04_TIMING_CONTROL_3_PROFILE1_U16 - R2M04_TIMING_CONTROL_3_PROFILE0_U16));
		errCode = BC_SPI_Read(e_SYS_TE, CtrlReg3Addr, &Ctr3ProfX.val_u32);
	}
	if(errCode == BC_ERR_NOERROR)
	{
		Ctr3ProfX.bits_st.ChirpIntervalTimerProfile0 = tmpChirpPeriod;
		errCode = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg3Addr, Ctr3ProfX.val_u32);
	}
	return errCode;
}

static void rfeSwCfgApplyChirpTimingUpdates(uint8_t	profileIdx, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	SYS_ProfChirpSampleDeci_t profChirpSample   = { 0 };
	SYS_ProfChirpFreq_t profChirpFreq           = { 0 };
	SYS_ProfChirpTiming_t profChirpTiming       = { 0.0f };
	uint8_t seqIdx;
	uint8_t sequenceCount = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		GetProfileParam(&profChirpTiming, &profChirpFreq, &profChirpSample, profileIdx, pRfeConfig, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		sequenceCount = rfeCfg_metadata_getChirpSequenceConfigCount(pRfeConfig, rfe___error___pointer);
	}
	for(seqIdx = 0; seqIdx < sequenceCount; ++seqIdx)
	{
		if(*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		SetSequenceProfChirpParam(pRfeConfig, seqIdx, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = Helper_ConfigSC((SYS_ProfID_e)profileIdx, &profChirpTiming, &profChirpFreq, &profChirpSample);
		if(errCode == BC_ERR_NOERROR)
		{
			errCode = DwellTimeUpdate(profileIdx, &profChirpTiming);
		}
		if(errCode == BC_ERR_NOERROR)
		{
			errCode = SettleTimeUpdate(profileIdx, &profChirpTiming);
		}
		if(errCode == BC_ERR_NOERROR)
		{
			errCode = ChirpPeriodUpdate(profileIdx, &profChirpTiming);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyChirpFrequencyUpdates(uint8_t	profileIdx, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	SYS_ProfChirpSampleDeci_t profChirpSample = {0};
	SYS_ProfChirpFreq_t profChirpFreq = {0};
	SYS_ProfChirpTiming_t profChirpTiming = { 0.0f };
	uint8_t seqIdx;
	uint8_t sequenceCount = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		GetProfileParam(&profChirpTiming, &profChirpFreq, &profChirpSample, profileIdx, pRfeConfig,
						rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		sequenceCount = rfeCfg_metadata_getChirpSequenceConfigCount(pRfeConfig, rfe___error___pointer);
	}
	for(seqIdx = 0; seqIdx < sequenceCount; ++seqIdx)
	{
		if(*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		SetSequenceProfChirpParam(pRfeConfig, seqIdx, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = Helper_ConfigSC((SYS_ProfID_e)profileIdx, &profChirpTiming, &profChirpFreq, &profChirpSample);
		if(errCode == BC_ERR_NOERROR)
		{
			errCode = Helper_ConfigCAFC((SYS_ProfID_e)profileIdx, &profChirpFreq);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyEffectiveSamplingFrequencyUpdates(uint8_t profile, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	rfe_effectiveSamplingFrequency_t samplingFrequency;
	MIPI_DataRate_e mipiDataRate;
	uint8_t mipiNumLanes = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		samplingFrequency = EffectiveSamplingFrequencyMapper(rfeCfg_chirpProfile_getEffectiveSamplingFrequency(pRfeConfig,
				rfeChirpProfileMapper(profile), rfe___error___pointer));
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		switch (samplingFrequency)
		{
			case rfe_effectiveSamplingFrequency_5MHz_e:
			{
				mipiNumLanes = 1U;
				mipiDataRate = e_MIPI_DATARATE_240;
				break;
			}
			case rfe_effectiveSamplingFrequency_10MHz_e:
			{
				mipiNumLanes = 2U;
				mipiDataRate = e_MIPI_DATARATE_240;
				break;
			}
			case rfe_effectiveSamplingFrequency_20MHz_e:
			{
				mipiNumLanes = 4U;
				mipiDataRate = e_MIPI_DATARATE_240;
			}
				break;
			default:
			{
				mipiNumLanes = 4U;
				mipiDataRate = e_MIPI_DATARATE_480;
				break;
			}
		}
		errCode = BC_MIPI_Config(mipiNumLanes, mipiDataRate);
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}

	}
}

static void rfeSwCfgApplyTxTransmissionEnableUpdates(rfeDriverPersistentMem_t *pDrvState, uint8_t profile,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	R2M04_TimingControl1Profile0Union_t Ctr1ProfX;
	R2M04_TimingControl3Profile0Union_t Ctr3ProfX;
	uint8_t txEn[RFE_MAX_TX_CHANNELS];
	uint16_t CtrlReg1Addr = 0U;
	uint16_t CtrlReg3Addr = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState->tef82xxDrvState.txChannelEnable[profile] = (uint32_t)rfeCfg_chirpProfile_getTxTransmissionEnable(
				pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		txEn[0] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profile] >> RFE_TX_CHANNEL_0) & 0x01U;
		txEn[1] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profile] >> RFE_TX_CHANNEL_1) & 0x01U;
		txEn[2] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profile] >> RFE_TX_CHANNEL_2) & 0x01U;
		CtrlReg1Addr = R2M04_TIMING_CONTROL_1_PROFILE0_U16 + (((uint16_t)profile - (uint16_t)e_SYS_PROFILE_0) *
				(R2M04_TIMING_CONTROL_1_PROFILE1_U16 - R2M04_TIMING_CONTROL_1_PROFILE0_U16));
		errCode = BC_SPI_Read(e_SYS_TE, CtrlReg1Addr, &Ctr1ProfX.val_u32);
		if(errCode == BC_ERR_NOERROR)
		{
			Ctr1ProfX.bits_st.Tx1TransmissionEnableProfile0 = txEn[0];
			Ctr1ProfX.bits_st.Tx2TransmissionEnableProfile0 = txEn[1];
			Ctr1ProfX.bits_st.Tx3TransmissionEnableProfile0 = txEn[2];
			errCode = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg1Addr, Ctr1ProfX.val_u32);
		}
		if(errCode == BC_ERR_NOERROR)
		{
			CtrlReg3Addr = R2M04_TIMING_CONTROL_3_PROFILE0_U16 + (((uint16_t)profile - (uint16_t)e_SYS_PROFILE_0) *
					(R2M04_TIMING_CONTROL_3_PROFILE1_U16 - R2M04_TIMING_CONTROL_3_PROFILE0_U16));
			errCode = BC_SPI_Read(e_SYS_TE, CtrlReg3Addr, &Ctr3ProfX.val_u32);
		}
		if(errCode == BC_ERR_NOERROR)
		{
			Ctr3ProfX.bits_st.Tx1ActiveProfile0 = (uint8_t)txEn[0];
			Ctr3ProfX.bits_st.Tx2ActiveProfile0 = (uint8_t)txEn[1];
			Ctr3ProfX.bits_st.Tx3ActiveProfile0 = (uint8_t)txEn[2];
			errCode = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg3Addr, Ctr3ProfX.val_u32);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyTxPowerUpdates(rfeDriverPersistentMem_t *pDrvState, uint8_t profile,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	uint8_t txEn[RFE_MAX_TX_CHANNELS];
	float32_t txPower = 0.0f;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		txPower = (float32_t)rfeCfg_chirpProfile_getTxPower(pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe___error___pointer) / TENTHS_OF_DB_TO_DB;
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		txEn[0] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profile] >> RFE_TX_CHANNEL_0) & 0x01U;
		txEn[1] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profile] >> RFE_TX_CHANNEL_1) & 0x01U;
		txEn[2] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profile] >> RFE_TX_CHANNEL_2) & 0x01U;
		if(txEn[0] != 0U)
		{
			pDrvState->tef82xxDrvState.txChannelPower[profile][RFE_TX_CHANNEL_0] = txPower;
		}
		else
		{
			pDrvState->tef82xxDrvState.txChannelPower[profile][RFE_TX_CHANNEL_0] = TEF82XX_DISABLED_TX;
		}
		if(txEn[1] != 0U)
		{
			pDrvState->tef82xxDrvState.txChannelPower[profile][RFE_TX_CHANNEL_1] = txPower;
		}
		else
		{
			pDrvState->tef82xxDrvState.txChannelPower[profile][RFE_TX_CHANNEL_1] = TEF82XX_DISABLED_TX;
		}
		if(txEn[2] != 0U)
		{
			pDrvState->tef82xxDrvState.txChannelPower[profile][RFE_TX_CHANNEL_2] = txPower;
		}
		else
		{
			pDrvState->tef82xxDrvState.txChannelPower[profile][RFE_TX_CHANNEL_2] = TEF82XX_DISABLED_TX;
		}
		if (fabsf(txPower - RFE_TEF82XX_SET_MAX_SAFE_TX_POWER) < DELTA_FLOAT)
		{
			errCode = BC_TX_SetMaxSafePOutTarget(rfeProfModeSelMapper(profile), e_SYS_TXMC, 3U);
		}
		else
		{
			if (((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profile]) != 0UL)
			{
				errCode = BC_TX_SetRFTargetPower(rfeProfModeSelMapper(profile), e_SYS_TXMC, txPower);
			}
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyTxPhaseRotationUpdates(rfeDriverPersistentMem_t *pDrvState, uint16_t paramIndex,
		uint8_t profile, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	float32_t prTx = 0.0f;
	uint16_t CtrlReg4Addr = 0U;
	uint32_t tmpPRPhaseCtrlTx = 0UL;
	R2M04_TimingControl4Profile0Union_t Ctr4ProfX;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		if(paramIndex == (uint16_t)rfe_paramUpdate_chirpProfile_txPhaseRotation_1_e)
		{
			prTx = (float32_t)rfeCfg_chirpProfile_getTxPhaseRotation(pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe_txIndex_1_e, rfe___error___pointer) *
					BLOB_PHASE_TO_PHASE_DEGREE;
		}
		else if(paramIndex == (uint16_t)rfe_paramUpdate_chirpProfile_txPhaseRotation_2_e)
		{
			prTx = (float32_t)rfeCfg_chirpProfile_getTxPhaseRotation(pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe_txIndex_2_e, rfe___error___pointer) *
					BLOB_PHASE_TO_PHASE_DEGREE;
		}
		else
		{
			prTx = (float32_t) rfeCfg_chirpProfile_getTxPhaseRotation(pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe_txIndex_3_e, rfe___error___pointer) *
					BLOB_PHASE_TO_PHASE_DEGREE;
		}
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		CtrlReg4Addr = R2M04_TIMING_CONTROL_4_PROFILE0_U16 + (((uint16_t)profile - (uint16_t)e_SYS_PROFILE_0) *
				(R2M04_TIMING_CONTROL_4_PROFILE1_U16 - R2M04_TIMING_CONTROL_4_PROFILE0_U16));
		errCode = BC_SPI_Read(e_SYS_TE, CtrlReg4Addr, &Ctr4ProfX.val_u32);
		if (BC_ERR_NOERROR == errCode)
		{
			tmpPRPhaseCtrlTx = (uint32_t)lroundf((64.0f * prTx) / 360.0f);
			if(paramIndex == (uint16_t)rfe_paramUpdate_chirpProfile_txPhaseRotation_1_e)
			{
				Ctr4ProfX.bits_st.Tx1PrPhaseControlProfile0 = (uint8_t)(tmpPRPhaseCtrlTx & 0x3Fu);
			}
			else if(paramIndex == (uint16_t)rfe_paramUpdate_chirpProfile_txPhaseRotation_2_e)
			{
				Ctr4ProfX.bits_st.Tx2PrPhaseControlProfile0 = (uint8_t)(tmpPRPhaseCtrlTx & 0x3Fu);
			}
			else
			{
				Ctr4ProfX.bits_st.Tx3PrPhaseControlProfile0 = (uint8_t)(tmpPRPhaseCtrlTx & 0x3Fu);
			}
			errCode = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg4Addr, Ctr4ProfX.val_u32);
			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
		}
	}
}

static void rfeSwCfgApplyFrequencyDriftStepsUpdates(rfeDriverPersistentMem_t *pDrvState, uint8_t profile,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	float32_t freqDriftHz = 0.0f;
	float32_t tReset = 0.0f;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		freqDriftHz = (float32_t) rfeCfg_chirpSequence_getChirpFrequencyDriftSteps(pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		tReset = (float32_t)rfeCfg_chirpProfile_getResetTimeTicks(pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe___error___pointer) * TICK_TO_US;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_SC_ConfigSlowDriftChirp(rfeProfModeSelMapper(profile), freqDriftHz, tReset, 0.0f);
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyRxGainUpdates(rfeDriverPersistentMem_t *pDrvState, uint8_t profile,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	uint8_t idx = 0U;
	rfe_rxGain_t rxCfgGain = rfe_rxGain_25dB_e;
	uint16_t SetRXProfileGain;
	R2M0D_GainRxSetProfile0Union_t GainRxSetProfile;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		rxCfgGain = RxGainMapper(rfeCfg_chirpProfile_getRxGain(pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe___error___pointer));
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		SetRXProfileGain = R2M0D_GAIN_RX_SET_PROFILE0_U16 + (((uint16_t)profile - (uint16_t)e_SYS_PROFILE_0) *
				(R2M0D_GAIN_RX_SET_PROFILE1_U16 - R2M0D_GAIN_RX_SET_PROFILE0_U16));
		GainRxSetProfile.val_u32 = 0u;
		GainRxSetProfile.bits_st.GainRxSetCtrlProfile0 = (uint32_t)rfeRxGainMapper((uint8_t)rxCfgGain);
		for(idx = 0; idx < (uint8_t)RFE_MAX_RX_CHANNELS; ++idx)
		{
			if(errCode != BC_ERR_NOERROR)
			{
				break;
			}
			errCode = BC_SPI_Write(SYS_IPNumMapper(((uint8_t)e_SYS_RX1 + idx)), SetRXProfileGain, GainRxSetProfile.val_u32);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyRxHpfCutOffFrequencyUpdates(rfeDriverPersistentMem_t *pDrvState, uint8_t profile,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	rfeRxHpfCutOff_t hpfCutOff = RFE_RX_HPF_CUTOFF_100KHZ;
	R2M0D_HpfRxSetProfile0Union_t HpfRxSetProfile;
	uint8_t idx = 0U;
	uint16_t SetRXHPFFreq;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		hpfCutOff = rfeRxHpfCutOffMapper(rfeCfg_chirpProfile_getRxHpfCutOffFrequency(pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe___error___pointer));
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		SetRXHPFFreq = R2M0D_HPF_RX_SET_PROFILE0_U16 + (((uint16_t)profile - (uint16_t)e_SYS_PROFILE_0) *
				(R2M0D_HPF_RX_SET_PROFILE1_U16 - R2M0D_HPF_RX_SET_PROFILE0_U16));
		HpfRxSetProfile.val_u32 = 0u;
		HpfRxSetProfile.bits_st.HpfRxSetCtrlProfile0 = (uint8_t)rfeRxHPFMapper(hpfCutOff);
		for(idx = 0; idx < (uint8_t)RFE_MAX_RX_CHANNELS; ++idx)
		{
			if(errCode != BC_ERR_NOERROR)
			{
				break;
			}
			errCode = BC_SPI_Write(SYS_IPNumMapper(((uint8_t)e_SYS_RX1 + idx)), SetRXHPFFreq, HpfRxSetProfile.val_u32);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyRxLpfCutOffFrequencyUpdates(rfeDriverPersistentMem_t *pDrvState, uint8_t profile,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	uint8_t idx = 0U;
	rfeRxLpfCutOff_t lpfCutOff = RFE_RX_LPF_CUTOFF_12_5MHZ;
	uint16_t SetRXLPFFreq;
	R2M0D_LpfRxSetProfile0Union_t 		LpfRxSetProfile;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		lpfCutOff = rfeRxLpfCutOffMapper(rfeCfg_chirpProfile_getRxLpfCutOffFrequency(pDrvState->rfeConfig, rfeChirpProfileMapper(profile), rfe___error___pointer));
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		SetRXLPFFreq = R2M0D_LPF_RX_SET_PROFILE0_U16 + (((uint16_t)profile - (uint16_t)e_SYS_PROFILE_0) *
				(R2M0D_LPF_RX_SET_PROFILE1_U16 - R2M0D_LPF_RX_SET_PROFILE0_U16));
		LpfRxSetProfile.val_u32 = 0u;
		if((uint8_t)lpfCutOff == (uint8_t)e_SYS_RXLPF_WIDE)
		{
			LpfRxSetProfile.bits_st.LpfRxSetCtrlProfile0 = WIDEBAND;
		}
		if(lpfCutOff == RFE_RX_LPF_CUTOFF_WIDE)
		{
			lpfCutOff = RFE_RX_LPF_CUTOFF_12_5MHZ;
		}
		LpfRxSetProfile.bits_st.LpfRxCornerSetProfile0 = (uint8_t)rfeRxLPFMapper(lpfCutOff);
		for(idx = 0; idx < (uint8_t)RFE_MAX_RX_CHANNELS; ++idx)
		{
			if(errCode != BC_ERR_NOERROR)
			{
				break;
			}
			errCode = BC_SPI_Write(SYS_IPNumMapper(((uint8_t)e_SYS_RX1 + idx)), SetRXLPFFreq, LpfRxSetProfile.val_u32);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwCfgApplyVirtualChannelUpdates(rfeDriverPersistentMem_t *pDrvState, uint8_t profile,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	R2M04_TimingControl4Profile0Union_t Ctr4ProfX;
	MIPI_VCNum_t selectVCs = { 0 };
	MIPI_VCClearFrame_t clearFrameVCs = { 0 };
	rfe_virtualChannel_t vitrualChannel = rfe_virtualChannel_0_e;
	uint16_t CtrlReg4Addr = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		vitrualChannel = VirtualChannelMapper(rfeCfg_chirpProfile_getVirtualChannel(pDrvState->rfeConfig,
				rfeChirpProfileMapper(profile), rfe___error___pointer));
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		switch(vitrualChannel)
		{
		case rfe_virtualChannel_0_e:
			selectVCs.SelectVC0 = TRUE;
			clearFrameVCs.ClearFrameVC0 = TRUE;
			break;
		case rfe_virtualChannel_1_e:
			selectVCs.SelectVC1 = TRUE;
			clearFrameVCs.ClearFrameVC1 = TRUE;
			break;
		case rfe_virtualChannel_2_e:
			selectVCs.SelectVC2 = TRUE;
			clearFrameVCs.ClearFrameVC2 = TRUE;
			break;
		default:
			errCode = BC_ERR_TE_VIRTUALCHANNEL;
			break;
		}
		if(errCode == BC_ERR_NOERROR)
		{
			errCode = BC_MIPI_ConfigVC(&selectVCs, &clearFrameVCs);
		}
		if(errCode == BC_ERR_NOERROR)
		{
			CtrlReg4Addr = R2M04_TIMING_CONTROL_4_PROFILE0_U16 + (((uint16_t)profile - (uint16_t)e_SYS_PROFILE_0) *
					(R2M04_TIMING_CONTROL_4_PROFILE1_U16 - R2M04_TIMING_CONTROL_4_PROFILE0_U16));
			errCode = BC_SPI_Read(e_SYS_TE, CtrlReg4Addr, &Ctr4ProfX.val_u32);
		}
		if(errCode == BC_ERR_NOERROR)
		{
			Ctr4ProfX.bits_st.VirtualChannelProfile0 = (uint32_t)rfeVirtualChannelMapper((uint8_t)vitrualChannel);
			errCode = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg4Addr, Ctr4ProfX.val_u32);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static uint8_t GetUpdateProfile(uint16_t section, rfe_error_t* rfe___error___pointer)
{
	uint8_t profile = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		switch(section)
		{
			case (uint16_t)rfeCfg_section_chirpProfile_0_e:
			{
				profile = (uint8_t)rfe_chirpProfileIndex_0_e;
				break;
			}
			case (uint16_t)rfeCfg_section_chirpProfile_1_e:
			{
				profile = (uint8_t)rfe_chirpProfileIndex_1_e;
				break;
			}
			case (uint16_t)rfeCfg_section_chirpProfile_2_e:
			{
				profile = (uint8_t)rfe_chirpProfileIndex_2_e;
				break;
			}
			case (uint16_t)rfeCfg_section_chirpProfile_3_e:
			{
				profile = (uint8_t)rfe_chirpProfileIndex_3_e;
				break;
			}
			case (uint16_t)rfeCfg_section_chirpProfile_4_e:
			{
				profile = (uint8_t)rfe_chirpProfileIndex_4_e;
				break;
			}
			case (uint16_t)rfeCfg_section_chirpProfile_5_e:
			{
				profile = (uint8_t)rfe_chirpProfileIndex_5_e;
				break;
			}
			case (uint16_t)rfeCfg_section_chirpProfile_6_e:
			{
				profile = (uint8_t)rfe_chirpProfileIndex_6_e;
				break;
			}
			case (uint16_t)rfeCfg_section_chirpProfile_7_e:
			{
				profile = (uint8_t)rfe_chirpProfileIndex_7_e;
				break;
			}
			default:
				*rfe___error___pointer = rfe_error_bc_inputOutOfRange;
				break;
		}
	}
	return profile;
}

static void rfeSwCfgApplyChirpProfileUpdates(rfeDriverPersistentMem_t *pDrvState, uint16_t section,
		uint16_t paramIndex, rfe_error_t* rfe___error___pointer)
{
    uint8_t profile = 0U;

	profile = GetUpdateProfile(section, rfe___error___pointer);

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		switch(paramIndex)
		{
			case (uint16_t)rfe_paramUpdate_chirpProfile_effectiveSamplingFrequency_e:
			{
				rfeSwCfgApplyEffectiveSamplingFrequencyUpdates(profile, pDrvState->rfeConfig,
						rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_chirpIntervalTimeTicks_e:
			case (uint16_t)rfe_paramUpdate_chirpProfile_dwellTimeTicks_e:
			case (uint16_t)rfe_paramUpdate_chirpProfile_settleTimeTicks_e:
			case (uint16_t)rfe_paramUpdate_chirpProfile_acquisitionTimeTicks_e:
			case (uint16_t)rfe_paramUpdate_chirpProfile_resetTimeTicks_e:
			{
				rfeSwCfgApplyChirpTimingUpdates(profile, pDrvState->rfeConfig, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_centerFrequency_e:
			case (uint16_t)rfe_paramUpdate_chirpProfile_effectiveChirpBandwidth_e:
			case (uint16_t)rfe_paramUpdate_chirpProfile_chirpPllVcoSelect_e:
			case (uint16_t)rfe_paramUpdate_chirpProfile_chirpSlopeDirection_e:
			{
				rfeSwCfgApplyChirpFrequencyUpdates(profile, pDrvState->rfeConfig, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_chirpPllLoopFilterBandwidth_e:
			{
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[profile].cafcLoopBandwidth =
								GetPllLoopFilterBw(profile, pDrvState->rfeConfig, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_txTransmissionEnable_e:
			{
				rfeSwCfgApplyTxTransmissionEnableUpdates(pDrvState, profile, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_txPower_e:
			{
				rfeSwCfgApplyTxPowerUpdates(pDrvState, profile, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_txPhaseRotation_1_e:
			case (uint16_t)rfe_paramUpdate_chirpProfile_txPhaseRotation_2_e:
			case (uint16_t)rfe_paramUpdate_chirpProfile_txPhaseRotation_3_e:
			{
				rfeSwCfgApplyTxPhaseRotationUpdates(pDrvState, paramIndex, profile, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_txTransmissionReferenceTime_e:
			{
				// not used yet
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_txTransmissionTimeOffset_e:
			{
				// not used yet
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_chirpFrequencyDriftSteps_e:
			{
				rfeSwCfgApplyFrequencyDriftStepsUpdates(pDrvState, profile,	rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_rxGain_e:
			{
				rfeSwCfgApplyRxGainUpdates(pDrvState, profile, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_rxHpfCutOffFrequency_e:
			{
				rfeSwCfgApplyRxHpfCutOffFrequencyUpdates(pDrvState, profile, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_rxLpfCutOffFrequency_e:
			{
				rfeSwCfgApplyRxLpfCutOffFrequencyUpdates(pDrvState, profile, rfe___error___pointer);
				break;
			}
			case (uint16_t)rfe_paramUpdate_chirpProfile_virtualChannel_e:
			{
				rfeSwCfgApplyVirtualChannelUpdates(pDrvState, profile, rfe___error___pointer);
				break;
			}
			default:
			{
				//do nothing
				break;
			}
		}
	}
}

static BOOL ApplyParamUpdates(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	uint8_t idx = 0;
	BOOL updatesApplied = FALSE;

	if(pDrvState->updateCountCfg != 0U)
	{
		rfeSwUtils_SelectFe((uint8_t)pDrvState->frontendId);
		for(idx = 0; idx < pDrvState->updateCountCfg; ++idx)
		{
			if(*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			updatesApplied = TRUE;
			switch(pDrvState->updatesCfg[idx].section)
				{
				case (uint16_t)rfeCfg_section_general_e:
				{
					rfeSwCfgApplyGeneralUpdates(pDrvState, pDrvState->updatesCfg[idx].paramIndex,
							pDrvState->updatesCfg[idx].value, rfe___error___pointer);
					break;
				}
				case (uint16_t)rfeCfg_section_monitorAndSafety_e:
				{
					rfeSwCfgApplyMonitorAndSafetyUpdates(pDrvState, pDrvState->updatesCfg[idx].paramIndex,
							pDrvState->updatesCfg[idx].value, rfe___error___pointer);
					break;
				}
				case (uint16_t)rfeCfg_section_radarCycle_e:
				{
					rfeSwCfgApplyRadarCycleUpdates(pDrvState, pDrvState->updatesCfg[idx].paramIndex,
							pDrvState->updatesCfg[idx].value, rfe___error___pointer);
					break;
				}
				case (uint16_t)rfeCfg_section_chirpSequenceConfig_0_e:
				case (uint16_t)rfeCfg_section_chirpSequenceConfig_1_e:
				case (uint16_t)rfeCfg_section_chirpSequenceConfig_2_e:
				case (uint16_t)rfeCfg_section_chirpSequenceConfig_3_e:
				case (uint16_t)rfeCfg_section_chirpSequenceConfig_4_e:
				case (uint16_t)rfeCfg_section_chirpSequenceConfig_5_e:
				case (uint16_t)rfeCfg_section_chirpSequenceConfig_6_e:
				case (uint16_t)rfeCfg_section_chirpSequenceConfig_7_e:
				{
					rfeSwCfgApplyChirpSequenceUpdates(pDrvState, pDrvState->updatesCfg[idx].section,
							pDrvState->updatesCfg[idx].paramIndex, rfe___error___pointer);
					break;
				}
				case (uint16_t)rfeCfg_section_chirpProfile_0_e:
				case (uint16_t)rfeCfg_section_chirpProfile_1_e:
				case (uint16_t)rfeCfg_section_chirpProfile_2_e:
				case (uint16_t)rfeCfg_section_chirpProfile_3_e:
				case (uint16_t)rfeCfg_section_chirpProfile_4_e:
				case (uint16_t)rfeCfg_section_chirpProfile_5_e:
				case (uint16_t)rfeCfg_section_chirpProfile_6_e:
				case (uint16_t)rfeCfg_section_chirpProfile_7_e:
				{
					rfeSwCfgApplyChirpProfileUpdates(pDrvState, pDrvState->updatesCfg[idx].section,
							pDrvState->updatesCfg[idx].paramIndex,	rfe___error___pointer);
					break;
				}
				default:
				{
					updatesApplied = FALSE;
					break;
				}
			}
		}
		pDrvState->updateCountCfg = 0U;
	}
	return updatesApplied;
}
/*==================================================================================================
 *                              PUBLIC FUNCTIONS
 ==================================================================================================*/

uint16_t rfeSwCfgUpdatePush(const rfeSwCfgMngr_update_t* pUpdates, uint8_t updateCount, rfe_error_t* rfe___error___pointer)
{
	uint8_t updateIndex = 0;
	bool isRadarCycleActive;
	rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();
	rfe_radarCycleCount_t radarCycleCountL = rfeSwMainFsm_getRadarCycleCount( &isRadarCycleActive );

	if ( updateCount > RFE_UPDATE_COUNT_MAX )
	{
		*rfe___error___pointer = rfe_error_api_maxUpdateCountExceeded_e;
	}
	else
	{
		pDrvState->updateCountCfg = updateCount;
		for ( updateIndex = 0; updateIndex < updateCount; updateIndex++ )
		{
			pDrvState->updatesCfg[updateIndex].section = pUpdates[updateIndex].section;
			pDrvState->updatesCfg[updateIndex].paramIndex = pUpdates[updateIndex].paramIndex;
			pDrvState->updatesCfg[updateIndex].value = pUpdates[updateIndex].value;

			CheckParamValue((rfeCfg_section_t) pUpdates[updateIndex].section,
					(rfe_paramUpdate_t) pUpdates[updateIndex].paramIndex, pUpdates[updateIndex].value, rfe___error___pointer);
			if(*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			rfeCfg_write(pDrvState->rfeConfig, (rfeCfg_section_t)pUpdates[updateIndex].section, (rfeCfg_param_t)update_params[pUpdates[updateIndex].paramIndex],
					pUpdates[updateIndex].value, rfe___error___pointer);
			if(*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
		}
	}
	return ( isRadarCycleActive ? ( radarCycleCountL.radarCycleCount + 1U ) : 0U );
}

BOOL rfeSwCfgApplyParamUpdates(rfe_error_t* rfe___error___pointer)
{
	rfeDriverPersistentMem_t *pDrvState = NULL;
	uint8_t actualFeId = RfeDrvStateFrontendIdGet();
	BOOL updatesApplied = FALSE;
	uint8_t fe_idx = 0;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		// Start Leader update config
		// Set Leader device
		rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
		pDrvState = RfeDrvStateGet();
		updatesApplied = ApplyParamUpdates(pDrvState, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		// Start Followers update config
		for(fe_idx = (uint8_t)rfeFrontEndId_1; fe_idx < RfeDrvStateNoFrontendsGet(); ++fe_idx)
		{
			// Set Follower device
			rfeSwUtils_SelectFe(fe_idx);
			pDrvState = RfeDrvStateGet();
			updatesApplied = (ApplyParamUpdates(pDrvState, rfe___error___pointer) == TRUE) ? TRUE : updatesApplied;
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
		}
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		rfeSwUtils_SelectFe(actualFeId);
	}
	return updatesApplied;
}


