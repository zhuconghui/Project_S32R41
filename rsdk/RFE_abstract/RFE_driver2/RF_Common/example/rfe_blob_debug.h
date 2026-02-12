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

#ifndef _RFE_BLOB_DEBUG_H_
#define _RFE_BLOB_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif


/*
 * To use below defined structures to debug an rfeConfig0/1 Blob in the Application, define a pointer as follows:
 * Note: it is recommended to run a size-check on the blob, to match the typedef struct:
 *
 *
 *   #include "rfeConfig.h"
 *   #include "rfe_blob_debug.h"
 *   pRfeConfigBlob_t pRfeConfig0_dbg = NULL_PTR;
 *   pRfeConfigBlob_t pRfeConfig1_dbg = NULL_PTR;
 *
 *   your_func( ... )
 *   {
 *     // Initialized debug pointers
 *     if (sizeof(pRfeConfigBlob_t)!=RFE_CFG_SIZE_TOTAL)
 *     {
 *        DbgPrintMsg("Warning: Blob size mismatch against struct pRfeConfigBlob_t!\n");
 *     } else {
 *        pRfeConfig0_dbg = (pRfeConfigBlob_t)rfeConfig0;
 *        pRfeConfig1_dbg = (pRfeConfigBlob_t)rfeConfig1;
 *       HALT_HERE; // Halt your debugger, and add a watch on pRfeConfig0_dbg/pRfeConfig1_dbg
 *     }
 *  }
 */

/*****************************************************************************
* exported functions
*****************************************************************************/

/**
*
*   \brief      Function to print a formatted overview of all items in an RFE config blob
*
*   \details    The function will simply call the following functions in sequence
*                - RfeDbg_Blob_MetadataList
*                - RfeDbg_Blob_RadarCyclesList
*                - RfeDbg_Blob_SeqProfilesList
*                - RfeDbg_Blob_ChirpProfilesList
*
*   @param[in]  pConfig   - pointer to Rfe Config blob
*   @param[in]  bTranslate - boolean to indicate if printing human-readable text or plain numbers
*
*/
extern void RfeDbg_BlobSummary(const uint8_t *pConfig, bool bTranslate);

/**
*
*   \brief      Function to print a formatted overview of all Metadata and General items of an RFE config blob
*
*   \details    The function will print Meta data information :
*                - meta.version (major.minor.patch)
*                - meta.chirpSequenceConfigCount
*                - meta.chirpProfileCount
*                - general.powerMode
*                - general.radarCycleStartSignalGpio
*                - general.chirpSequenceActiveSignalGpio
*                - general.clkIoConfig
*                - general.pdcDecimationFilter
*                - general.dataOutConfig
*                - general.metadataPacketSwContent
*                - general.metadataPacketVirtualChannel
*                - general.jumpbackTimeTicks
*
*   @param[in]  pConfig   - pointer to Rfe Config blob
*   @param[in]  bTranslate - boolean to indicate if printing human-readable text (T) or plain numbers (F)
*
*/
extern void RfeDbg_MetadataList(const uint8_t *pConfig, bool bTranslate);

/**
*
*   \brief      Function to print a formatted overview of all RadarCycle items of an RFE config blob
*
*   \details    The function will print Radar Cycle data information :
*                - radarCycle.duration (ticks/us)
*                - chirpSequenceCount (number of sequences)
*                - bist Interval
*                - Table (8 columns, 3 rows) with
*                  > chirpSequence Id used by this cycle
*                  > Start-Time Offset (ticks/us) for chirpId
*                  > recalibrateProfileIndependent (?)
*
*   @param[in]  pConfig   - pointer to Rfe Config blob
*   @param[in]  bTranslate - boolean to indicate if printing human-readable text (T) or plain numbers (F)
*
*/
extern void RfeDbg_RadarCyclesList(const uint8_t *pConfig, bool bTranslate);

/**
*
*   \brief      Function to print a formatted overview of all Chirp Sequence items of an RFE config blob
*
*   \details    The function will print table Chirp-Sequence data information :
*                - chirpCount - number of chirps in sequence
*                - chirpProfileSequence_0..7  : The Profile ID for 1st, 2nd, .. 8th chirp
*                - chirpProfileSequenceLength : Number of Profile Ids to use in Sequency
*                - dynamicUpdatesEnabled      :
*                - dynamicTableIndex          :
*/
extern void RfeDbg_SeqProfilesList(const uint8_t *pConfig, bool bTranslate);

/**
*
*   \brief      Function to print a formatted overview of all ChirpProfiles items of an RFE config blob
*
*   \details    The function will print table Chirp-Profile data information :
*                - effectiveSamplingFrequency
*                - chirpIntervalTimeTicks
*                - dwellTimeTicks
*                - settleTimeTicks
*                - acquisitionTimeTicks
*                - resetTimeTicks
*                - centerFrequency
*                - effectiveChirpBandwidth
*                - chirpPllVcoSelect
*                - chirpSlopeDirection
*                - chirpPllLoopFilterBandwidth
*                - txTransmissionEnable
*                - txPower
*                - PhaseRotatiom TX1, TX2, TX3
*                - txTransmissionReferenceTime
*                - txTransmissionTimeOffset
*                - chirpFrequencyDriftSteps
*                - rxGain
*                - rxHpfCutOffFrequency
*                - rxLpfCutOffFrequency
*                - virtualChannel
*
*   @param[in]  pConfig   - pointer to Rfe Config blob
*   @param[in]  bTranslate - boolean to indicate if printing human-readable text (T) or plain numbers (F)
*
*/
extern void RfeDbg_ChirpProfilesList(const uint8_t *pConfig, bool bTranslate);

/* *****************************************************
 * Typedefs
 *
 *  USE WITH EXTREME CARE - if the Blob configuration changes, the typedefs must be updated carefully !
 *  May only be used for debugging to observe if values in rfeConfig blob are matching expectations
 *
 *  Usage: add 'pRfeConfigBlob_t pCfgDbg = rfeConfig0;' to your code, to create a pointer to a struct with blob data.
 *         Then, add watch on variable pCfgDbg and browse the sections and parameters of the blob.
 */
typedef struct __attribute__((packed)) {
    uint8_t chirpSequenceConfigCount;                       // (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | RFE_CFG_PARAM_SIZE_8_BIT  | 0ul),
    uint8_t chirpProfileCount;                              // (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | RFE_CFG_PARAM_SIZE_8_BIT  | 1ul),
    uint8_t majorVersion;                                   // (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | RFE_CFG_PARAM_SIZE_8_BIT  | 2ul),
    uint8_t minorVersion;                                   // (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | RFE_CFG_PARAM_SIZE_8_BIT  | 3ul),
    uint8_t patchVersion;                                   // (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | RFE_CFG_PARAM_SIZE_8_BIT  | 4ul),
	uint8_t hashVersion;                                    // (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | RFE_CFG_PARAM_SIZE_8_BIT  | 5ul),
} rfeCfg_param_metadata_t, *pRfeCfg_param_metadata_t;

typedef struct __attribute__((packed)) {
    uint8_t powerMode;                                        // (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | RFE_CFG_PARAM_SIZE_8_BIT  | 0ul),
    uint8_t radarCycleStartSignalGpio;                        // (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | RFE_CFG_PARAM_SIZE_8_BIT  | 1ul),
    uint8_t chirpSequenceActiveSignalGpio;                    // (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | RFE_CFG_PARAM_SIZE_8_BIT  | 2ul),
    uint8_t clkIoConfig;                                      // (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | RFE_CFG_PARAM_SIZE_8_BIT  | 3ul),
    uint8_t pdcDecimationFilter;                              // (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | RFE_CFG_PARAM_SIZE_8_BIT  | 4ul),
    uint8_t dataOutConfig;                                    // (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | RFE_CFG_PARAM_SIZE_8_BIT  | 5ul),
    uint8_t metadataPacketSwContent;                          // (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | RFE_CFG_PARAM_SIZE_8_BIT  | 6ul),
    uint8_t metadataPacketVirtualChannel;                     // (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | RFE_CFG_PARAM_SIZE_8_BIT  | 7ul),
    uint8_t jumpbackTimeTicks;                                // (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | RFE_CFG_PARAM_SIZE_8_BIT  | 8ul),
} rfeCfg_param_general_t, *pRfeCfg_param_general_t;


typedef struct __attribute__((packed)) {
    uint8_t  rxSatCountResetEveryChirpSequence;       // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 0ul),
    uint8_t  rxSaturationThresholdStage1_rx1;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 1ul),
    uint8_t  rxSaturationThresholdStage1_rx2;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 2ul),
    uint8_t  rxSaturationThresholdStage1_rx3;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 3ul),
    uint8_t  rxSaturationThresholdStage1_rx4;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 4ul),
    uint8_t  rxSaturationThresholdStage2_rx1;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 5ul),
    uint8_t  rxSaturationThresholdStage2_rx2;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 6ul),
    uint8_t  rxSaturationThresholdStage2_rx3;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 7ul),
    uint8_t  rxSaturationThresholdStage2_rx4;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 8ul),
    uint32_t rxSaturationCountLimitStage1_rx1;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 9ul),
    uint32_t rxSaturationCountLimitStage1_rx2;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 13ul),
    uint32_t rxSaturationCountLimitStage1_rx3;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 17ul),
    uint32_t rxSaturationCountLimitStage1_rx4;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 21ul),
    uint32_t rxSaturationCountLimitStage2_rx1;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 25ul),
    uint32_t rxSaturationCountLimitStage2_rx2;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 29ul),
    uint32_t rxSaturationCountLimitStage2_rx3;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 33ul),
    uint32_t rxSaturationCountLimitStage2_rx4;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 37ul),
    uint8_t  adcClippingCountResetEveryChirpSequence; // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 41ul),
    uint32_t adcClippingCountLimit_adc1;              // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 42ul),
    uint32_t adcClippingCountLimit_adc2;              // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 46ul),
    uint32_t adcClippingCountLimit_adc3;              // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 50ul),
    uint32_t adcClippingCountLimit_adc4;              // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 54ul),
    uint16_t temperatureSensorThresholdHigh_tx12;     // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 58ul),
    uint16_t temperatureSensorThresholdHigh_tx3;      // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 60ul),
    uint16_t temperatureSensorThresholdHigh_xo;       // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 62ul),
    uint16_t temperatureSensorThresholdOver_tx12;     // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 64ul),
    uint16_t temperatureSensorThresholdOver_tx3;      // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 66ul),
    uint16_t temperatureSensorThresholdOver_xo;       // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 68ul),
    uint16_t temperatureSensorThresholdUnder_tx12;    // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 70ul),
    uint16_t temperatureSensorThresholdUnder_tx3;     // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 72ul),
    uint16_t temperatureSensorThresholdUnder_xo;      // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 74ul),
    uint8_t  thresholdValueToPromoteR1Faults;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 76ul),
    float frequencyForBist;                        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 77ul),
    float zeroHrRefForRxPhaseDiffLna_rx1_rx2;      // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 81ul), revised
    float zeroHrRefForRxPhaseDiffLna_rx1_rx3;      // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 85ul),
    float zeroHrRefForRxPhaseDiffLna_rx1_rx4;      // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 89ul),
    float rxPhaseDiffLnaThresholdTolerance;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 93ul),
    float zeroHrRefForRxGainDiffLna_rx1_rx2;       // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 97ul),
    float zeroHrRefForRxGainDiffLna_rx1_rx3;       // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 101ul),
    float zeroHrRefForRxGainDiffLna_rx1_rx4;       // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 105ul),
    float rxGainDiffLnaThresholdTolerance;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 109ul),
    float zeroHrRefForRxPhaseDiffMxr_rx1_rx2;      // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 113ul),
    float zeroHrRefForRxPhaseDiffMxr_rx1_rx3;      // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 117ul),
    float zeroHrRefForRxPhaseDiffMxr_rx1_rx4;      // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 121ul),
    float rxPhaseDiffMxrThresholdTolerance;        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 125ul),
    float zeroHrRefForRxGainDiffMxr_rx1_rx2;       // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 129ul),
    float zeroHrRefForRxGainDiffMxr_rx1_rx3;       // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 133ul),
    float zeroHrRefForRxGainDiffMxr_rx1_rx4;       // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 137ul),
    float  rxGainDiffMxrThresholdTolerance;         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 141ul),
    uint8_t  injectTestTone;                          // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 145ul),
    uint8_t  checkBbd_loi;                            // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 146ul),
    uint8_t  checkBbd_tx;                             // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 147ul),
    uint8_t  checkBbd_rx;                             // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 148ul),  end revised
    uint8_t  ppdThreshold_profile0;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 149ul),
    uint8_t  ppdThreshold_profile1;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 150ul),
    uint8_t  ppdThreshold_profile2;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 151ul),
    uint8_t  ppdThreshold_profile3;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 152ul),
    uint8_t  ppdThreshold_profile4;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 153ul),
    uint8_t  ppdThreshold_profile5;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 154ul),
    uint8_t  ppdThreshold_profile6;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 155ul),
    uint8_t  ppdThreshold_profile7;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 156ul),
    uint8_t  fuSaFaultMask_0;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 157ul),
    uint8_t  fuSaFaultMask_1;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 158ul),
    uint8_t  fuSaFaultMask_2;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 159ul),
    uint8_t  fuSaFaultMask_3;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 160ul),
    uint8_t  fuSaFaultMask_4;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 161ul),
    uint8_t  fuSaFaultMask_5;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 162ul),
    uint8_t  fuSaFaultMask_6;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 163ul),
    uint8_t  fuSaFaultMask_7;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 164ul),
    uint8_t  fuSaFaultMask_8;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 165ul),
    uint8_t  fuSaFaultMask_9;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 166ul),
    uint8_t  fuSaFaultMask_10;                        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 167ul),
    uint8_t  fuSaFaultMask_11;                        // (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 168ul),
} rfeCfg_param_monitorAndSafety_t, *pRfeCfg_param_monitorAndSafety_t;

typedef struct __attribute__((packed)) {
    uint32_t radarCycleDuration;                            // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 0ul),
    uint8_t  chirpSequenceCount;                            // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 4ul),
    uint8_t  chirpSequence_0;                               // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 5ul),
    uint8_t  chirpSequence_1;                               // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 6ul),
    uint8_t  chirpSequence_2;                               // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 7ul),
    uint8_t  chirpSequence_3;                               // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 8ul),
    uint8_t  chirpSequence_4;                               // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 9ul),
    uint8_t  chirpSequence_5;                               // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 10ul),
    uint8_t  chirpSequence_6;                               // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 11ul),
    uint8_t  chirpSequence_7;                               // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 12ul),
    uint32_t chirpSequenceStartTimeOffset_0;                // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 13ul),
    uint32_t chirpSequenceStartTimeOffset_1;                // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 17ul),
    uint32_t chirpSequenceStartTimeOffset_2;                // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 21ul),
    uint32_t chirpSequenceStartTimeOffset_3;                // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 25ul),
    uint32_t chirpSequenceStartTimeOffset_4;                // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 29ul),
    uint32_t chirpSequenceStartTimeOffset_5;                // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 33ul),
    uint32_t chirpSequenceStartTimeOffset_6;                // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 37ul),
    uint32_t chirpSequenceStartTimeOffset_7;                // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 41ul),
    uint8_t  recalibrateProfileDependent_0;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 45ul),
    uint8_t  recalibrateProfileDependent_1;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 46ul),
    uint8_t  recalibrateProfileDependent_2;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 47ul),
    uint8_t  recalibrateProfileDependent_3;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 48ul),
    uint8_t  recalibrateProfileDependent_4;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 49ul),
    uint8_t  recalibrateProfileDependent_5;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 50ul),
    uint8_t  recalibrateProfileDependent_6;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 51ul),
    uint8_t  recalibrateProfileDependent_7;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 52ul),
    uint8_t  recalibrateProfileIndependent;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 53ul),
    uint8_t  bistInterval;                                  // (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 54ul),
} rfeCfg_param_radarCycle_t, *pRfeCfg_param_radarCycle_t;

typedef struct __attribute__((packed)) {
    uint16_t chirpCount;                               // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_16_BIT | 0ul),
    uint8_t chirpProfileSequence_0;                    // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 2ul),
    uint8_t chirpProfileSequence_1;                    // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 3ul),
    uint8_t chirpProfileSequence_2;                    // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 4ul),
    uint8_t chirpProfileSequence_3;                    // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 5ul),
    uint8_t chirpProfileSequence_4;                    // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 6ul),
    uint8_t chirpProfileSequence_5;                    // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 7ul),
    uint8_t chirpProfileSequence_6;                    // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 8ul),
    uint8_t chirpProfileSequence_7;                    // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 9ul),
    uint8_t chirpProfileSequenceLength;                // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 10ul),
    uint8_t dynamicUpdatesEnabled;                     // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 11ul),
    uint8_t dynamicTableIndex;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 12ul),
    uint8_t txPhaseRotation_ddma;                      // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 13ul),
    uint8_t txPhaseRotation_ddma_tx;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 14ul),
	uint8_t txPhaseRotation_ddma_tx1_init;             // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 15ul),
	uint8_t txPhaseRotation_ddma_tx2_init;             // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 16ul),
	uint8_t txPhaseRotation_ddma_tx3_init;             // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 17ul),
	uint8_t txPhaseRotation_ddma_tx1_update;           // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 18ul),
	uint8_t txPhaseRotation_ddma_tx2_update;           // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 19ul),
	uint8_t txPhaseRotation_ddma_tx3_update;           // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 20ul),
	uint8_t txPhaseRotation_ddma_tx1_mode;             // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 21ul),
	uint8_t txPhaseRotation_ddma_tx2_mode;             // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 22ul),
	uint8_t txPhaseRotation_ddma_tx3_mode;             // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 23ul),
	uint8_t fastResetEnable;                           // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 24ul),
    uint8_t txEnable;                                  // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 25ul),
    uint8_t rxEnable;                                  // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 26ul),
    uint8_t pdcNotchFilterEnable;                      // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 27ul),
} rfeCfg_param_chirpSequence_t, *pRfeCfg_param_chirpSequence_t;

typedef struct __attribute__((packed)) {
    uint8_t effectiveSamplingFrequency;       // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 0ul),
    uint32_t chirpIntervalTimeTicks;          // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_32_BIT | 1ul),
    uint16_t dwellTimeTicks;                  // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 5ul),
    uint16_t settleTimeTicks;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 7ul),
    uint16_t acquisitionTimeTicks;            // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 9ul),
    uint16_t resetTimeTicks;                  // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 11ul),
    uint32_t centerFrequency;                 // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_32_BIT | 13ul),
    uint32_t effectiveChirpBandwidth;         // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_32_BIT | 17ul),
    uint8_t chirpPllVcoSelect;                // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 21ul),
    uint8_t chirpSlopeDirection;              // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 22ul),
    uint8_t chirpPllLoopFilterBandwidth;      // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 23ul),
    uint8_t txTransmissionEnable;             // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 24ul),
    uint16_t txPower;                         // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT  | 25ul),
    uint8_t txPhaseRotation_1;                // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 27ul),
    uint8_t txPhaseRotation_2;                // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 28ul),
    uint8_t txPhaseRotation_3;                // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 29ul),
    uint8_t txTransmissionReferenceTime;      // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 30ul),
    uint16_t txTransmissionTimeOffset;        // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 31ul),
    uint32_t chirpFrequencyDriftSteps;        // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_32_BIT | 33ul),
    uint8_t rxGain;                           // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 37ul),
    uint8_t rxHpfCutOffFrequency;             // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 38ul),
    uint8_t rxLpfCutOffFrequency;             // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 39ul),
    uint8_t virtualChannel;                   // (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 40ul)
} rfeCfg_param_chirpProfile_t, *pRfeCfg_param_chirpProfile_t;

typedef struct  __attribute__((packed)) {
	rfeCfg_param_chirpSequence_t sequence;
	rfeCfg_param_chirpProfile_t  profile;
} rfeCfg_param_chirp_t, *pRfeCfg_param_chirp_t;


typedef struct  __attribute__((packed)) {
	rfeCfg_param_metadata_t				metadata;
	rfeCfg_param_general_t				general;
	rfeCfg_param_monitorAndSafety_t		monitor_and_safety;
	rfeCfg_param_radarCycle_t			radarcycle;
	rfeCfg_param_chirp_t				chirpConfig[8];
} rfeConfigBlob_t, *pRfeConfigBlob_t ;


#ifdef __cplusplus
}
#endif

#endif // _RFE_BLOB_DEBUG_H_

