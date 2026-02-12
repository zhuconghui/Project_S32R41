/**************************************************************************************************
* Copyright 2022 - 2023 NXP
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

#ifndef RFE_CFG_BLOB_H
#define RFE_CFG_BLOB_H

#include <stdint.h>
#include "rfe_error.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
 *                           RFE CONFIG BLOB
 *****************************************************************************/
/**
 * \addtogroup rsdk_rfe_blob_const
 *
 * Here we describe the RFE configuration binary object (blob) which is to be
 * provided as input to rfe_configure() API function. The blob consists of multiple
 * memory sections as shown in the below table. The RFE Configuration BLOB
 * can be created by the RFE configuration generator. The functions in rfe_blob_access.h are
 * used to retrieve or update the blob configuration data at run time. After local manipulation, 
 * (i.e. updating the blob in the platform memory) the configuration
 * needs to be reloaded to the RFE by calling rfe_configure(). This will
 * reconfigure and calibrate the full RFE, which takes in the order of
 * tens of milliseconds depending on the amount of chirp profiles used.
 * To update a subset of RFE parameters in a timely manner (tens of microseconds)
 * it is recommend to use the rfe_update.h functions. These updates can even
 * take place when the radar cycle is active, during the radar cycle idle time.
 *
 * Section                  | Multiplicity                     | Description
 * ------------------------ | -------------------------------- | ----------------------------------------------------------------------------------------------
 * \ref metadata            | 1                                | Contains the number of sequences, chirp profiles and tool version
 * \ref general             | 1                                | Contains the general parameters
 * \ref monitorAndSafety    | 1                                | Contains the monitor and safety parameters
 * \ref radarCycle          | 1                                | Contains the radar cycle parameters
 * \ref chirpSequenceConfig | #RFE_CHIRP_SEQUENCE_CONFIGS_MAX  | Contains the chirp sequence parameters for each chirp sequence configuration
 * \ref chirpProfile        | #RFE_CHIRP_PROFILES_MAX          | Contains the chirp profile parameters for each profile
 *
 *
 * \section metadata
 *
 * This section describes the metadata section of the RFE Configuration BLOB.
 *
 * Parameter                        | Type                  | Min           | Max                               | Set                                           | Get
 * -------------------------------- | --------------------- | ------------- | --------------------------------- | --------------------------------------------- | ---------------------------------------------
 * \ref chirpSequenceConfigCount    | uint8_t               | 1             | #RFE_CHIRP_SEQUENCE_CONFIGS_MAX   | ---                                           | rfeCfg_metadata_getChirpSequenceConfigCount()
 * \ref chirpProfileCount           | uint8_t               | 1             | #RFE_CHIRP_PROFILES_MAX           | ---                                           | rfeCfg_metadata_getChirpProfileCount()
 * \ref majorVersion                | uint8_t               | 0             | 0                                 | ---                                           | ---
 * \ref minorVersion                | uint8_t               | 8             | 8                                 | ---                                           | ---
 * \ref patchVersion                | uint8_t               | 13            | 13                                | ---                                           | ---
 *
 * \subsection chirpSequenceConfigCount
 * The number of chirp <b>sequence</b> configurations that will be configured on the Front-End.
 *
 * \subsection chirpProfileCount
 * The number of chirp <b>profile</b> configurations that will be stored on the Front-End.
 *
 * \subsection majorVersion
 * The major version number of the binary RFE configuration format.
 *
 * \subsection minorVersion
 * The minor version number of the binary RFE configuration format.
 *
 * \subsection patchVersion
 * The patch version number of the binary RFE configuration format.
 *
 * \subsection hashVersion
 * The hash version number of the binary RFE configuration format.
 *
 * \section general
 *
 * This section describes the general section of the RFE Configuration BLOB.
 *
 * Parameter                            | Type                 | Min       | Max       | Set                                               | Get
 * ------------------------------------ | -------------------- | --------- | --------- | ------------------------------------------------- | --------------------------------------------------
 * \ref powerMode                       | uint8_t              | 0         | 1         | rfeCfg_general_setPowerMode()                     | rfeCfg_general_getPowerMode()
 * \ref pdcDecimationFilter             | uint8_t              | 0         | 1         | ---                                               | rfeCfg_general_getPdcBitwidth()
 * \ref jumpbackTimeTicks               | uint8_t              | 1         | 254       | ---                                               | rfeCfg_general_getJumpbackTimeTicks()
 * \ref txCalibration (optional)        | uint8_t              | 0         | 1         | ---                                               | rfeCfg_general_getTxCalibrationMode()
 *
 * \subsection powerMode
 * Selects the powerMode of the rfe:
 * - 0: lower power
 * - 1: active
 *
 * \warning
 * If a sequence uses multiple profiles with different TXs enabled (see \ref txTransmissionEnable),
 * this setting must be configured to "lower power" otherwise a lock-step error would be triggered from ISM.
 *
 * \subsection pdcDecimationFilter
 * Selects the decimation filter of the programmable decimation chain. This option reduces the effective sampling rate of the
 * ADC as follows:
 * - 0: <b>Narrow</b> bandwidth with a passband response up to 0.4 x f<sub>EFFECTIVE_SAMPLE_RATE</sub>.
 * - 1: <b>Wide</b> bandwidth with a passband response up to 0.5 x f<sub>EFFECTIVE_SAMPLE_RATE</sub>.
 *
 * \remark
 * For a detailed description, please refer to the Reference Manual (RM00227), chapter "Programmable decimation chain".
 *
 * \subsection jumpbackTimeTicks
 * The chirp jumpback time for all chirps in 25 [ns] resolution.
 *
 * \subsection txCalibration
 * Configures whether the TX antennas will perform calibration with <b>normal radiation levels</b>,
 * or <b>significantly reduced radiation levels</b>.<br>
 * In case of calibration with <i>reduced</i> transmission radiation,
 * the \ref txCalibration_thresholdHigh and \ref txCalibration_thresholdLow must also be set.
 * \remark
 * <b>Default value</b>: 1 (i.e. <b>with transmission</b>, if omitted from XML when generating)
 *
 * \section monitorAndSafety
 *
 * This section describes the monitorAndSafety section of the RFE Configuration BLOB.
 *
 * Parameter                                    | Type            | Min           | Max           | Set                                           | Get
 * -------------------------------------------- | --------------- | ------------- | ------------- | --------------------------------------------- | ---------------------------------------------------------------------
 * \ref rxSatCountResetEveryChirpSequence       | uint8_t         | 0             | 1             | ---                                           | rfeCfg_monitorAndSafety_getRxSatCountResetEveryChirpSequence()
 * \ref rxSaturationThreshold                   | uint8_t         | 0             | 0x0F          | ---                                           | rfeCfg_monitorAndSafety_getRxSaturationThresholdStage()
 * \ref rxSaturationCountLimit                  | uint16_t        | 0             | 0x3FFFFF      | ---                                           | rfeCfg_monitorAndSafety_getRxSaturationCountLimitStage()
 * \ref adcClippingCountResetEveryChirpSequence | bool            | 0             | 1             | ---                                           | rfeCfg_monitorAndSafety_getAdcClippingCountResetEveryChirpSequence()
 * \ref frequencyForBist                        | uint32_t        | 75000000      | 82000000      | rfeCfg_monitorAndSafety_setFrequencyForBist() | rfeCfg_monitorAndSafety_getFrequencyForBist()
 * \ref zeroHrRefForRxPhaseDiffLna              | float32_t       | -1800         | 1800          | rfeCfg_monitorAndSafety_setBist()             | rfeCfg_monitorAndSafety_getBist()
 * \ref rxPhaseDiffLnaThresholdTolerance        | float32_t       | 0             | 400           | rfeCfg_monitorAndSafety_setBist()             | rfeCfg_monitorAndSafety_getBist()
 * \ref zeroHourReferenceForRxGainDiffLna       | float32_t       | -400          | 400           | rfeCfg_monitorAndSafety_setBist()             | rfeCfg_monitorAndSafety_getBist()
 * \ref rxGainDiffLnaThresholdTolerance         | float32_t       | 0             | 400           | rfeCfg_monitorAndSafety_setBist()             | rfeCfg_monitorAndSafety_getBist()
 * \ref zeroHrRefForRxPhaseDiffMixer            | float32_t       | -1800         | 1800          | rfeCfg_monitorAndSafety_setBist()             | rfeCfg_monitorAndSafety_getBist()
 * \ref rxPhaseDiffMixerThresholdTolerance      | float32_t       | 0             | 400           | rfeCfg_monitorAndSafety_setBist()             | rfeCfg_monitorAndSafety_getBist()
 * \ref zeroHourReferenceForRxGainDiffMixer     | float32_t       | -400          | 400           | rfeCfg_monitorAndSafety_setBist()             | rfeCfg_monitorAndSafety_getBist()
 * \ref rxGainDiffMixerThresholdTolerance       | float32_t       | 0             | 400           | rfeCfg_monitorAndSafety_setBist()             | rfeCfg_monitorAndSafety_getBist()
 * \ref injectTestTone                          | bool            | 0             | 2             | rfeCfg_monitorAndSafety_setInjectTestTone()   | rfeCfg_monitorAndSafety_getInjectTestTone()
 * \ref checkBbd_loi                            | uint8_t         | 0             | 31            | rfeCfg_monitorAndSafety_setLoiBBD()           | rfeCfg_monitorAndSafety_getLoiBBD()
 * \ref checkBbd_tx                             | uint8_t         | 0             | 7             | ---                                           | rfeCfg_monitorAndSafety_getTxBBD()
 * \ref checkBbd_rx                             | uint8_t         | 0             | 7             | ---                                           | rfeCfg_monitorAndSafety_getRxBBD()
 * \ref fuSaFaultMask                           | uint8_t         | 0             | 0xFF          | ---                                           | rfeCfg_monitorAndSafety_getFuSaFaultMask()
 *
 * \subsection rxSatCountResetEveryChirpSequence
 * Reset the Rx saturation error counter after each Chirp Sequence.
 *
 * \subsection rxSaturationThreshold
 * ADC output level that triggers the clipping detector for each RX antenna.
 *
 * \subsection rxSaturationCountLimit
 * The number of ADC clipping events, that triggers an error.
 *
 * \subsection adcClippingCountResetEveryChirpSequence
 * If <b>enabled</b>, the clipping counter is reset every chirp sequence.<br>
 * If <b>disabled</b>, read out of the monitors via rfe_monitorRead() will also
 * reset these counters.
 *
 * \subsection frequencyForBist
 * The center frequency in kHz, to be used for RX BIST.
 *
 * \subsection zeroHrRefForRxPhaseDiffLna
 * Reference signal phase difference of all RX channels against the 1st RX (in degrees, for LNA input. See \ref injectTestTone).
 * \remark
 *  -# The RX BIST is for the fixed combination RX1-RX2, RX1-RX3 and RX1-RX4.
 *  -# The RX BIST will be executed for enabled RX channels for the combination mentioned above.
 *  -# The RX BIST will be skipped if RX1 is not enabled.
 *
 * \subsection rxPhaseDiffLnaThresholdTolerance
 *  The allowed difference between the <i>measured RX to RX phase difference</i> and the <i>zero hour data</i> (in degrees, for LNA input. See \ref injectTestTone).
 *  If the measured value exceeds the threshold for any of the measured combinations (RX1-RX2, RX1-RX3 and RX1-RX4),
 *  the RX BIST will be marked as failed and ERROR_N will be asserted.
 *
 * \subsection zeroHourReferenceForRxGainDiffLna
 * The reference RX-RX gain difference which will be compared with measured values during RX BIST (in dB, for LNA input. See \ref injectTestTone).
 *
 * \subsection rxGainDiffLnaThresholdTolerance
 * The allowed difference between the <i>measured RX to RX gain difference</i> and the <i>zero hour data</i> (in dB, for LNA input. See \ref injectTestTone).
 * If the measured value exceeds the threshold for any of the measured combinations  (RX1-RX2, RX1-RX3 and RX1-RX4),
 * the RX BIST will be marked as failed and ERROR_N will be asserted.
 * \remark
 *  -# The RX BIST is for the fixed combination RX1-RX2, RX1-RX3 and RX1-RX4.
 *  -# The RX BIST will be executed for enabled RX channels for the combination mentioned above.
 *  -# The RX BIST will be skipped if RX1 is not enabled.
 *
 * \subsection zeroHrRefForRxPhaseDiffMixer
 * Same as \ref zeroHrRefForRxPhaseDiffLna but for <b>Mixer</b> input instead of LNA. (See \ref injectTestTone)
 *
 * \subsection rxPhaseDiffMixerThresholdTolerance
 * Same as \ref rxPhaseDiffLnaThresholdTolerance but for <b>Mixer</b> input instead of LNA. (See \ref injectTestTone)
 *
 * \subsection zeroHourReferenceForRxGainDiffMixer
 * Same as \ref zeroHourReferenceForRxGainDiffLna but for <b>Mixer</b> input instead of LNA. (See \ref injectTestTone)
 *
 * \subsection rxGainDiffMixerThresholdTolerance
 * Same as \ref rxGainDiffLnaThresholdTolerance but for <b>Mixer</b> input instead of LNA. (See \ref injectTestTone)
 *
 * \subsection injectTestTone
 * Configures the injection point of the test tone during RX BIST.
 * When \b injectTestTone is set to 0, the test tone is injected twice every RX BIST sequence, once before <b>LNA</b> & once before <b>Mixer</b>.
 * when \b injectTestTone is set to 1, the test tone is injected every RX BIST sequence only before Mixer.
 * when \b injectTestTone is set to 2, injection point of the test tone repeatedly alternates between <b>before LNA</b> and <b>before Mixer</b> with each RX BIST sequence.
 *
 * \subsection checkBbd_loi
 * Configures the following settings, bitwise encoded:
 * - 000<b>1</b> 0000 : <b>Enables</b>/Disables the Ball Break detector for LO Interface.
 * - 0000 <b>1</b>000 : <b>High</b>/Normal current sensitivity for the LO-out Ball Break detector.
 * - 0000 0<b>1</b>00 : <b>Grounded</b>/Not Grounded Ball Break detector <b>balun</b>, for the LO-out.
 * - 0000 00<b>1</b>0 : <b>High</b>/Normal current sensitivity for the LO-in Ball Break detector.
 * - 0000 000<b>1</b> : <b>Grounded</b>/Not Grounded Ball Break detector <b>balun</b>, for the LO-in.
 *
 * \subsection checkBbd_tx
 * Configures the following settings, bitwise encoded:
 * - 0000 0<b>1</b>00 : <b>Enables</b>/Disables the Ball Break detector for TX antennas.
 * - 0000 00<b>1</b>0 : <b>High</b>/Normal current sensitivity for the TX antennas Ball Break detector.
 * - 0000 000<b>1</b> : <b>Grounded</b>/Not Grounded Ball Break detector <b>balun</b>, for the TX antennas Ball.
 *
 * \subsection checkBbd_rx
 * Configures the following settings, bitwise encoded:
 * - 0000 0<b>1</b>00 : <b>Enables</b>/Disables the Ball Break detector for RX antennas.
 * - 0000 00<b>1</b>0 : <b>High</b>/Normal current sensitivity for the RX antennas Ball Break detector.
 * - 0000 000<b>1</b> : <b>Grounded</b>/Not Grounded Ball Break detector <b>balun</b>, for the RX antennas Ball.
 *
 * \subsection fuSaFaultMask
 * Functional safety faults to be masked/unmasked. Masked faults do not assert the ERROR_N signal.<br>
 * The enumeration from \ref rfe_fuSaFault_t must be used as bitwise index to mask
 * or unmask the corresponding fault.
 * To mask, set the desired bit to ‘1’, to unmask, set to ‘0’.<br>
 * \remark
 *  - NXP does not recommend the user to mask the faults, as they will not be detected, which may violate the safety goal.
 *  - \ref rfe_generic_sw_e - is a generic software error that is raised by any \ref rfe_error_t triggered, therefore it cannot be masked!
 *                            It is kept however in this list for visibility.
 *
 * \section radarCycle
 *
 * This section describes the radarCycle section of the RFE Configuration BLOB.
 *
 * Parameter                          | Type       | Min    | Max      | Set                                                  | Get
 * ---------------------------------- | ---------- | ------ | -------- | ---------------------------------------------------- | ----------------------------------------------------
 * \ref radarCycleDuration            | uint32_t   | 400000 | 20000000 | rfeCfg_radarCycle_setRadarCycleDuration()            | rfeCfg_radarCycle_getRadarCycleDuration()
 * \ref chirpSequenceCount            | uint8_t    | 1      | 8        | ---                                                  | rfeCfg_radarCycle_getChirpSequenceCount()
 * \ref chirpSequence                 | uint8_t    | 0      | 7        | ---                                                  | rfeCfg_radarCycle_getChirpSequence()
 * \ref chirpSequenceStartTimeOffset  | uint32_t   | 0      | 20000000 | ---                                                  | rfeCfg_radarCycle_getChirpSequenceStartTimeOffset()
 * \ref bistInterval                  | uint8_t    | 0      | 3        | ---                                                  | rfeCfg_radarCycle_getBistInterval()
 *
 * \subsection radarCycleDuration
 * Radar cycle duration in 25 [ns] resolution.
 *
 * \subsection chirpSequenceCount
 * Number of chirp sequences configured for the radar cycle.
 *
 * \subsection chirpSequence
 * Contains the chirp sequence configurations, in the order they were configured in the XML at generation time.<br>
 * Based on \ref chirpSequenceCount, how many of the \ref rfeCfg_param_radarCycle_chirpSequence_0_e --> \ref rfeCfg_param_radarCycle_chirpSequence_7_e contain<br>
 * a configuration that is intended to be used in the radar cycle.
 *
 * \subsection chirpSequenceStartTimeOffset
 * The chirp sequence time offset in 25 [ns] resolution with respect to the start time of the radar cycle.
 * The offset is defined as the time difference between the start of the dwell time of the first chirp and the start time of the radar cycle.<br>
 * If using \ref powerMode = 1, then an additional DC_Power_on_Delay value in the order of hundreds of microseconds will be added before the dwell time
 * of the first chirp.
 * The start time of chirp sequence 0 is fixed at design time. For the first sequence in the radar cycle, the time checking is disabled
 * because the init chirp sequence and recalibration may take longer, otherwise the timing will not be optimal for the radar system.
 *
 * \subsection bistInterval
 * The interval to perform RFE built-in-self-tests. The selections are:
 * - 0 : No BIST.
 * - 1 : Every radar cycle. (recommended)
 * - 2 : Once in two radar cycles.
 * - 3 : Once in four radar cycles.
 * The rationale is that RX BIST must be executed once per Fault Handling Time Interval (FHTI). FHTI is associated with 1 radar cycle in radar safety concept.
 * Doing it less often than 1 radar cycle is not recommended. For more information on RX BIST and FHTI relation please refer to Functional Safety Manual.
 *
 * \section chirpSequenceConfig
 *
 * This section describes the RFE_CHIRP_SEQUENCE_CONFIGS_MAX chirpSequenceConfig sections of the RFE Configuration BLOB.
 *
 * Parameter                                   | Type               | Min         | Max        | Set                                                  | Get
 * ------------------------------------------- | ------------------ | ----------- | ---------- | ---------------------------------------------------- | ----------------------------------------------------
 * \ref chirpCount                             | uint16_t           | 1           | 4096       | rfeCfg_chirpSequence_setChirpCount()                 | rfeCfg_chirpSequence_getChirpCount()
 * \ref chirpProfileSequence                   | uint8_t            | 0           | 7          | rfeCfg_chirpSequence_setChirpProfileSequence()       | rfeCfg_chirpSequence_getChirpProfileSequence()
 * \ref chirpProfileSequenceLength             | uint8_t            | 1           | 8          | rfeCfg_chirpSequence_setChirpProfileSequenceLength() | rfeCfg_chirpSequence_getChirpProfileSequenceLength()
 * \ref chirpProfileRepeatCount                | uint8_t            | 1           | 127        | rfeCfg_chirpSequence_setChirpProfileRepeatCount()    | rfeCfg_chirpSequence_getChirpProfileRepeatCount()
 * \ref dynamicUpdatesEnabled                  | bool               | 0           | 1          | rfeCfg_chirpSequence_setDynamicUpdatesEnabled()      | rfeCfg_chirpSequence_getDynamicUpdatesEnabled()
 * \ref dynamicTableIndex                      | uint8_t            | 0           | 7          | rfeCfg_chirpSequence_setDynamicTableIndex()          | rfeCfg_chirpSequence_getDynamicTableIndex()
 * \ref txPhaseRotation_ddma                   | uint8_t            | 0           | 3          | rfeCfg_sequence_setPhaseRotationDdmaMode()           | rfeCfg_sequence_getPhaseRotationDdmaMode()
 * \ref txPhaseRotation_ddma_tx                | uint8_t            | 0           | 7          | ---                                                  | rfeCfg_sequence_getPhaseRotationTxUseDdma()
 * \ref txPhaseRotation_ddma_tx1_init          | uint8_t            | 0           | 63         | rfeCfg_sequence_setTxDdmaInitPhase()                 | rfeCfg_sequence_getTxDdmaInitPhase()
 * \ref txPhaseRotation_ddma_tx1_update        | uint8_t            | 0           | 63         | rfeCfg_sequence_setTxDdmaUpdatePhase()               | rfeCfg_sequence_getTxDdmaUpdatePhase()
 * \ref txPhaseRotation_ddma_tx1_mode          | uint8_t            | 0           | 2          | rfeCfg_sequence_setTxFinalPcGenMode()                | rfeCfg_sequence_getFinalPcGenMode()
 * \ref rxEnable                               | rfe_rxSelect_t     | 0x0         | 0xF        | rfeCfg_chirpSequence_setRxEnable()                   | rfeCfg_chirpSequence_getRxEnable()
 * \ref txCalibration_thresholdHigh (optional) | uint16_t           | 0           | 400        | ---                                                  | rfeCfg_sequence_getTxCalibrationThresholdHigh()
 * \ref txCalibration_thresholdLow (optional)  | uint16_t           | 0           | 400        | ---                                                  | rfeCfg_sequence_getTxCalibrationThresholdLow()
 *
 * \subsection chirpCount
 * The number of chirps within the chirp sequence.
 *
 * \subsection chirpProfileSequence
 * The list of profiles that are used for the current sequence, and their order.
 * Based on the \ref chirpProfileSequenceLength, determines how many profiles should be considered, and how many should be ignored,<br>
 * from the list \ref rfeCfg_param_chirpSequence_chirpProfileSequence_0_e --> \ref rfeCfg_param_chirpSequence_chirpProfileSequence_7_e.
 *
 * \subsection chirpProfileSequenceLength
 * The number of chirp profiles, that are configured for the current sequence.<br>
 * This parameter determines how many \ref rfeCfg_param_chirpSequence_chirpProfileSequence_0_e --> \ref rfeCfg_param_chirpSequence_chirpProfileSequence_7_e should be used, and which should be ignored.
 *
 * \subsection chirpProfileRepeatCount
 * Configures the number of times a profile will be repeated within the chirp sequence,
 * before switching to the next profile in the list (e.g. using profileRepeatCount = 3, and
 * chirpProfileSequence = "0 1 2" will result in the following profiles being used: 0, 0, 0, 1, 1, 1, 2, 2, 2.
 * Otherwise, with profileRepeatCount = 1 -> 0, 1, 2, 0, 1, 2, 0, 1, 2.
 *
 * - Example 1: Chirp sequence: 0-0-0-0-0-0-.. \n
 *   \ref chirpProfileSequence = {\ref rfe_chirpProfileIndex_0_e}; \n
 *   \ref chirpProfileRepeatCount = 1;
 * - Example 2: Chirp sequence: 1-1-1-1-1-1-.. \n
 *   \ref chirpProfileSequence = {\ref rfe_chirpProfileIndex_1_e}; \n
 *   \ref chirpProfileRepeatCount = 1;
 * - Example 3: Interleaved chirp sequence 0-0-0-1-1-1-2-2-2.. \n
 *   \ref chirpProfileSequence = {\ref rfe_chirpProfileIndex_0_e, \ref rfe_chirpProfileIndex_1_e, \ref rfe_chirpProfileIndex_2_e}; \n
 *   \ref chirpProfileRepeatCount = 3;
 * - Example 4: Interleaved chirp sequence 0-1-2-0-1-2-0-1-2.. \n
 *   \ref chirpProfileSequence = {\ref rfe_chirpProfileIndex_0_e, \ref rfe_chirpProfileIndex_1_e, \ref rfe_chirpProfileIndex_2_e}; \n
 *   \ref chirpProfileRepeatCount = 1;
 *
 * \subsection dynamicUpdatesEnabled
 * Sets whether the dynamic updates, i.e. parameter updates per chirp,
 * are enabled or disabled.
 *
 * \subsection dynamicTableIndex
 * The index of the dynamic table to be used for the chirp sequence. This
 * table contains the values for each dynamic parameter for each chirp.
 *
 * \subsection txPhaseRotation_ddma
 * Configures the DDMA control mode. Values are:
 * - 0: disabled
 * - 1: functional mode
 * - 2: test mode (phase code step is incremented during chirp @ 40 MHz)
 * - 3: test no chirp DDMA test mode with non-chirp mode (phase code step is incremented during chirp @ 40 MHz)
 *
 * \subsection txPhaseRotation_ddma_tx
 * - 0000 000<b>1</b> (TX1): 0 -> Phase code is taken from Profile | 1 -> Phase code is taken from DDMA generator.
 * - 0000 00<b>1</b>0 (TX2): 0 -> Phase code is taken from Profile | 1 -> Phase code is taken from DDMA generator.
 * - 0000 0<b>1</b>00 (TX3): 0 -> Phase code is taken from Profile | 1 -> Phase code is taken from DDMA generator.
 *
 *
 * \subsection txPhaseRotation_ddma_tx1_init
 * Configures the PR DDMA initial phase for TX 1. (in steps of 5.625 degrees).
 * \remark
 * A similar parameter exists for TX2 & TX3.
 *
 * \subsection txPhaseRotation_ddma_tx1_update
 * Configures the PR DDMA phase increment for TX 1. (in steps of 5.625 degrees).
 * \remark
 * A similar parameter exists for TX2 & TX3.
 *
 * \subsection txPhaseRotation_ddma_tx1_mode
 * Configures how the phase code is generated for TX 1. Values are:
 * - 0: No change to phase code.
 * - 1: Replace two MSB bits of phase code with the QPSK[1:0] bits
 * - 2: Add the QPSK[1:0] bits to two MSB bits of initial phase code
 * \remark
 * A similar parameter exists for TX2 & TX3.
 *
 * \subsection rxEnable
 * Selection of receivers that are enabled during the chirp sequence.
 * - 0000 000<b>1</b> : RX1 <b>Enabled</b>/Disabled
 * - 0000 00<b>1</b>0 : RX2 <b>Enabled</b>/Disabled
 * - 0000 0<b>1</b>00 : RX3 <b>Enabled</b>/Disabled
 * - 0000 <b>1</b>000 : RX4 <b>Enabled</b>/Disabled
 *
 * \subsection txCalibration_thresholdHigh
 * Configures the threshold that once reached, would cause the TX antenna output power to be decreased.<br>
 * Values coming from the blob are in dB, multiplied by 100 to account for 2 digits. [0.01 .. 4]
 * This setting is only valid when \ref txCalibration is set to 0.
 * \remark
 * TEF82xx takes values in steps of 0.29dB. Any value within the accepted range can be used
 * but the value that ends up on the front-end will be the closest multiple of 0.29dB, relative to the value
 * that was used when generating the blob.
 *
 * \subsection txCalibration_thresholdLow
 * Configures the threshold that once reached, would cause the TX antenna output power to be increased.<br>
 * Values coming from the blob are in dB, multiplied by 100 to account for 2 digits. [0.01 .. 4]
 * This setting is only valid when \ref txCalibration is set to 0.
 * \remark
 * TEF82xx takes values in steps of 0.29dB. Any value within the accepted range can be used
 * but the value that ends up on the front-end will be the closest multiple of 0.29dB, relative to the value
 * that was used when generating the blob.
 *
 * \section chirpProfile
 *
 * This section describes the RFE_CHIRP_PROFILES_MAX chirpProfile sections of the RFE Configuration BLOB.
 *
 * Parameter                        | Type          | Min         | Max        | Set                                                   | Get
 * -------------------------------- | --------------| ----------- | --------   | ----------------------------------------------------- | ----------------------------------------------------
 * \ref effectiveSamplingFrequency  | uint8_t       | 0           | 3          | rfeCfg_chirpProfile_setEffectiveSamplingFrequency()   | rfeCfg_chirpProfile_getEffectiveSamplingFrequency()
 * \ref chirpIntervalTimeTicks      | uint32_t      | 400         | 4194303    | rfeCfg_chirpProfile_setChirpIntervalTimeTicks()       | rfeCfg_chirpProfile_getChirpIntervalTimeTicks()
 * \ref dwellTimeTicks              | uint16_t      | 40          | 4094       | rfeCfg_chirpProfile_setDwellTimeTicks()               | rfeCfg_chirpProfile_getDwellTimeTicks()
 * \ref settleTimeTicks             | uint16_t      | 80          | 4094       | rfeCfg_chirpProfile_setSettleTimeTicks()              | rfeCfg_chirpProfile_getSettleTimeTicks()
 * \ref acquisitionTimeTicks        | uint16_t      | 8           | 8192       | rfeCfg_chirpProfile_setAcquisitionTimeTicks()         | rfeCfg_chirpProfile_getAcquisitionTimeTicks()
 * \ref resetTimeTicks              | uint16_t      | 30          | 4094       | rfeCfg_chirpProfile_setResetTimeTicks()               | rfeCfg_chirpProfile_getResetTimeTicks()
 * \ref centerFrequency             | uint32_t      | 76000000    | 81000000   | rfeCfg_chirpProfile_setCenterFrequency()              | rfeCfg_chirpProfile_getCenterFrequency()
 * \ref effectiveChirpBandwidth     | uint32_t      | 0           | 4000000    | rfeCfg_chirpProfile_setEffectiveChirpBandwidth()      | rfeCfg_chirpProfile_getEffectiveChirpBandwidth()
 * \ref chirpPllVcoSelect           | uint8_t       | 0           | 2          | rfeCfg_chirpProfile_setChirpPllVco()                  | rfeCfg_chirpProfile_getChirpPllVco()
 * \ref chirpSlopeDirection         | uint8_t       | 0           | 1          | rfeCfg_chirpProfile_setChirpSlopeDirection()          | rfeCfg_chirpProfile_getChirpSlopeDirection()
 * \ref chirpPllLoopFilterBandwidth | uint8_t       | 0           | 30         | rfeCfg_chirpProfile_setChirpPllLoopFilterBandwidth()  | rfeCfg_chirpProfile_getChirpPllLoopFilterBandwidth()
 * \ref txTransmissionEnable        | uint8_t       | 0           | 7          | rfeCfg_chirpProfile_setTxTransmissionEnable()         | rfeCfg_chirpProfile_getTxTransmissionEnable()
 * \ref txPower                     | int16_t       | 30          | 150        | rfeCfg_chirpProfile_setTxPower()                      | rfeCfg_chirpProfile_getTxPower()
 * \ref txPhaseRotation             | uint8_t       | 0           | 63         | rfeCfg_chirpProfile_setTxPhaseRotation()              | rfeCfg_chirpProfile_getTxPhaseRotation()
 * \ref chirpFrequencyDriftSteps    | int32_t       | 0           | 932068     | ---                                                   | rfeCfg_chirpSequence_getChirpFrequencyDriftSteps()
 * \ref rxGain                      | uint8_t       | 1           | 7          | rfeCfg_chirpProfile_setRxGain()                       | rfeCfg_chirpProfile_getRxGain()
 * \ref rxHpfCutOffFrequency        | uint8_t       | 0           | 6          | rfeCfg_chirpProfile_setRxHpfCutOffFrequency()         | rfeCfg_chirpProfile_getRxHpfCutOffFrequency()
 * \ref rxLpfCutOffFrequency        | uint8_t       | 0           | 4          | rfeCfg_chirpProfile_setRxLpfCutOffFrequency()         | rfeCfg_chirpProfile_getRxLpfCutOffFrequency()
 * \ref virtualChannel              | uint8_t       | 0           | 2          | rfeCfg_chirpProfile_setVirtualChannel()               | rfeCfg_chirpProfile_getVirtualChannel()
 *
 * \subsection effectiveSamplingFrequency
 * The effective sampling frequency of the chirp. Here 'effective' indicates
 * that this is the sampling frequency after decimation, i.e. of the output samples.
 *
 * \subsection chirpIntervalTimeTicks
 * The chirp interval time in 25 [ns] resolution. It is the time between the start
 * of subsequent chirps and this parameter can be used to introduce additional idle
 * time between chirps. The value for this parameter must be equal or larger than the sum
 * of its components: \ref dwellTimeTicks, \ref settleTimeTicks, \ref acquisitionTimeTicks,
 * \ref jumpbackTimeTicks, and \ref resetTimeTicks.
 *
 * \subsection dwellTimeTicks
 * The chirp dwell time in 25 [ns] resolution.
 *
 * \subsection settleTimeTicks
 * The chirp settle time in 25 [ns] resolution.
 *
 * \subsection acquisitionTimeTicks
 * The chirp acquisition time in 25 [ns] resolution.
 *
 * \subsection resetTimeTicks
 * The chirp reset time in 25 [ns] resolution.
 *
 * \subsection centerFrequency
 * The center frequency of the chirp in [kHz].
 *
 * \subsection effectiveChirpBandwidth
 * The effective bandwidth in [kHz]. This is the bandwidth used
 * during the chirp acquisition. A bandwidth of 0 results in
 * a 'chirp' with constant frequency.
 * The actual effective chirp bandwidth is rounded to a multiple of \ref acquisitionTimeTicks * RFE_CHIRP_FREQUENCY_DRIFT_STEPS_HZ.
 *
 * \subsection chirpPllVcoSelect
 * Selection of the VCO that the chirp PLL uses to generate the chirp:
 * - 0: 1GHz VCO
 * - 1: 2GHz VCO
 * - 2: 4GHz VCO
 *
 * \subsection chirpSlopeDirection
 * Selection of the direction of the chirp slope: rising or falling.
 *
 * \subsection chirpPllLoopFilterBandwidth
 * Selects the chirp PLL loop filter bandwidth. <br>
 * See \ref rfe_chirpPllLoopFilterBandwidth_t for all the values.
 * \attention
 * Values that can be selected, depend on the VCO parameter from above. In
 * order to achieve the highest recommended chirp steepness per VCO, the values below are sugested, which also ensure the lowest
 * phase noise:
 * - For 1GHz VCO -> 200kHz | 250kHz | 300kHz
 * - For 2GHz VCO -> 250kHz | 300kHz
 * - For 4GHz VCO -> 300kHz | 350kHz
 *
 * \subsection txTransmissionEnable
 * Selection of transmitters that transmit the chirp.
 * - 0000 000<b>1</b> : TX1 <b>Enabled</b>/Disabled
 * - 0000 00<b>1</b>0 : TX2 <b>Enabled</b>/Disabled
 * - 0000 0<b>1</b>00 : TX3 <b>Enabled</b>/Disabled
 *
 * \warning
 * If a Sequence uses multiple profiles, that has different TXs enabled, then \ref powerMode
 * must be configured to <b>0</b> (<i>"lower power"</i>) otherwise a lock-step error would be triggered from ISM.
 *
 * \subsection txPower
 * Output power of the transmitters in the steps of 0.1 [dBm].
 * The value coming from the blob is multiplied by 10, to account for the 1 decimal.
 *
 * \subsection txPhaseRotation
 * Phase rotation for each transmitter (in steps of 5.625 degrees).
 *
 * \subsection chirpFrequencyDriftSteps
 * The frequency of the chirp (i.e., start & end frequency of the chirp frequency sweep) increments (positive) or decrements
 * (negative) by x * 42.9153 Hz each chirp, after chirp 1. A value of 0 will disable the drift. Values other than 0 are not supported, when the
 * chirp sequence consists of chirps with different Center Frequencies (i.e. center-frequency-kHz)
 * \remark
 * When \ref chirpFrequencyDriftSteps is enabled (i.e. value != 0), if using different \ref centerFrequency in the same sequence,<br>
 * the first \ref centerFrequency value will be used, and the rest will be ignored. Front-End will issue no warning for such case.
 *
 * \subsection rxGain
 * The gain of the receivers. Values are:
 * - 1: 27dB
 * - 2: 30dB
 * - 3: 33dB
 * - 4: 36dB
 * - 5: 39dB
 * - 6: 42dB
 * - 7: 45dB
 *
 * \subsection rxHpfCutOffFrequency
 * The cut-off frequency of receivers' high-pass filters:
 * - 0: 100 kHz
 * - 1: 200 kHz
 * - 2: 300 kHz
 * - 3: 400 kHz
 * - 4: 800 kHz
 * - 5: 1600 kHz
 * - 6: 3200 kHz
 *
 * \subsection rxLpfCutOffFrequency
 * The cut-off frequency of receivers' low-pass filters.
 * - 0: 15 MHz
 * - 1: 20 MHz
 * - 2: 25 MHz
 * - 3: 40 MHz
 *
 * \subsection virtualChannel
 * The virtual channel applied on data for the chirps using this profile.
 *
 */


/*
* @page misra_violations MISRA-C:2012 violations
*
* @section rfe_cfg_blob_c_REF_1
* Violates MISRA 2012 Required Rule 5.2
* Identifiers declared in the same scope and name space shall be distinct.
* Function naming template used.
*
*/


/******************************************************************************
 *                           DEFINITIONS
 *****************************************************************************/
 /** @{ */
/**
 * The size (in bytes) of the metadata section of the configuration data memory.
 */
#define RFE_CFG_MAX_DATA_LENGTH                     (RFE_CMD_IF_MAXDATLEN - 2UL)

/**
 * The size (in bytes) of the metadata section of the configuration data memory.
 */
#define RFE_CFG_SIZE_SECTION_METADATA               (6UL)

/**
 * The size (in bytes) of the general section of the configuration data memory.
 */
#define RFE_CFG_SIZE_SECTION_GENERAL                (10UL)

/**
 * The size (in bytes) of the monitor and safety section of the configuration data memory.
 */
#define RFE_CFG_SIZE_SECTION_MONITOR_AND_SAFETY     (179UL)

/**
 * The size (in bytes) of the radar cycle section of the configuration data memory.
 */
#define RFE_CFG_SIZE_SECTION_RADAR_CYCLE            (55UL)

/**
 * The size (in bytes) of a chirp sequence section of the configuration data memory.
 */
#define RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE         (31UL)

/**
 * The size (in bytes) of a chirp profile section of the configuration data memory.
 */
#define RFE_CFG_SIZE_SECTION_CHIRP_PROFILE          (41UL)

/**
 * The size (in bytes) of the CRC section of the configuration data memory.
 */
#define RFE_CFG_SIZE_SECTION_CRC                    (4UL)


/**
 * The offset (in bytes) of the metadata section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_METADATA                                     ((uint16_t)(0x000UL                                   + 0x000UL))

/**
 * The offset (in bytes) of the general section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_GENERAL                                      ((uint16_t)(RFE_CFG_OFFSET_SECTION_METADATA           + RFE_CFG_SIZE_SECTION_METADATA))

/**
 * The offset (in bytes) of the monitor and safety section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_MONITOR_AND_SAFETY                           ((uint16_t)(RFE_CFG_OFFSET_SECTION_GENERAL            + RFE_CFG_SIZE_SECTION_GENERAL))

/**
 * The offset (in bytes) of the radar cycle section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_RADAR_CYCLE                                  ((uint16_t)(RFE_CFG_OFFSET_SECTION_MONITOR_AND_SAFETY + RFE_CFG_SIZE_SECTION_MONITOR_AND_SAFETY))

/**
 * The offset (in bytes) of the chirp sequence 0 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_0                             ((uint16_t)(RFE_CFG_OFFSET_SECTION_RADAR_CYCLE        + RFE_CFG_SIZE_SECTION_RADAR_CYCLE))

/**
 * The offset (in bytes) of the chirp profile 0 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_0                              ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_0   + RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE))

/**
 * The offset (in bytes) of the chirp sequence 1 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_1                             ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_0    + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE))

/**
 * The offset (in bytes) of the chirp profile 1 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_1                              ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_1   + RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE))

/**
 * The offset (in bytes) of the chirp sequence 2 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_2                             ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_1    + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE))

/**
 * The offset (in bytes) of the chirp profile 2 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_2                              ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_2   + RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE))

/**
 * The offset (in bytes) of the chirp sequence 3 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_3                             ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_2    + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE))

/**
 * The offset (in bytes) of the chirp profile 3 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_3                              ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_3   + RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE))

/**
 * The offset (in bytes) of the chirp sequence 4 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_4                             ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_3    + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE))

/**
 * The offset (in bytes) of the chirp profile 4 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_4                              ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_4   + RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE))

/**
 * The offset (in bytes) of the chirp sequence 5 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_5                             ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_4    + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE))

/**
 * The offset (in bytes) of the chirp profile 5 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_5                              ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_5   + RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE))

/**
 * The offset (in bytes) of the chirp sequence 6 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_6                             ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_5    + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE))

/**
 * The offset (in bytes) of the chirp profile 6 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_6                              ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_6   + RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE))

/**
 * The offset (in bytes) of the chirp sequence 7 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_7                             ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_6    + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE))

/**
 * The offset (in bytes) of the chirp profile 7 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_7                              ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_7   + RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE))

/**
 * The offset (in bytes) of the chirp profile 7 section of the configuration data memory.
 */
#define RFE_CFG_OFFSET_SECTION_CRC                                          ((uint16_t)(RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_7   + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE))

/**
 * The total size (in bytes) of the configuration data memory.
 */
#define RFE_CFG_SIZE_TOTAL                                                  (RFE_CFG_OFFSET_SECTION_CRC + RFE_CFG_SIZE_SECTION_CRC)

/**
 * The mask for section part of a configuration parameter.
 */
#define RFE_CFG_PARAM_SECTION_MSK                                           ((uint16_t)((1UL<<15) | ((1UL<<14) | (1UL<<13))))

/**
 * The mask for size part of a configuration parameter.
 */
#define RFE_CFG_PARAM_SIZE_MSK                                              ((uint16_t)((1UL<<12) | (1UL<<11)))

/**
 * The mask for offset part of a configuration parameter.
 */
#define RFE_CFG_PARAM_OFFSET_MSK                                            ((uint16_t)(0x07ffUL))

/**
 * The encoding of the metadata section part into a configuration parameter.
 */
#define RFE_CFG_PARAM_SECTION_METADATA                                      ((uint16_t)((0UL<<15) | ((0UL<<14) | (0UL<<13))))

/**
 * The encoding of the general section part into a configuration parameter.
 */
#define RFE_CFG_PARAM_SECTION_GENERAL                                       ((uint16_t)((0UL<<15) | ((0UL<<14) | (1UL<<13))))

/**
 * The encoding of the monitor and safery section part into a configuration parameter.
 */
#define RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY                            ((uint16_t)((0UL<<15) | ((1UL<<14) | (0UL<<13))))

/**
 * The encoding of the radar cycle section part into a configuration parameter.
 */
#define RFE_CFG_PARAM_SECTION_RADAR_CYCLE                                   ((uint16_t)((0UL<<15) | ((1UL<<14) | (1UL<<13))))

/**
 * The encoding of the chirp sequence section part into a configuration parameter.
 */
#define RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG                         ((uint16_t)((1UL<<15) | ((0UL<<14) | (0UL<<13))))

/**
 * The encoding of the chirp profile section part into a configuration parameter.
 */
#define RFE_CFG_PARAM_SECTION_CHIRP_PROFILE                                 ((uint16_t)((1UL<<15) | ((0UL<<14) | (1UL<<13))))

/**
 * The encoding of the chirp profile section part into a configuration parameter.
 */
#define RFE_CFG_PARAM_SECTION_CRC                                           ((uint16_t)((1UL<<15) | ((1UL<<14) | (1UL<<13))))

/**
 * The encoding of the size part into a configuration parameter for an 8 bit value.
 */
#define RFE_CFG_PARAM_SIZE_8_BIT                                            ((uint16_t)((0UL<<12) | (0UL<<11)))

/**
 * The encoding of the size part into a configuration parameter for a 16 bit value.
 */
#define RFE_CFG_PARAM_SIZE_16_BIT                                           ((uint16_t)((0UL<<12) | (1UL<<11)))

/**
 * The encoding of the size part into a configuration parameter for a 32 bit value.
 */
#define RFE_CFG_PARAM_SIZE_32_BIT                                           ((uint16_t)((1UL<<12) | (0UL<<11)))

/**
 * The encoding of the size part into a configuration parameter for a 32 bit float value.
 */
#define RFE_CFG_PARAM_SIZE_32_BIT_FLOAT                                     ((uint16_t)((1UL<<12) | (1UL<<11)))

/**
 *
 * This macro defines the maximum number of chirp sequence configs.
 * #rfe_chirpSequenceIndex_t defines the chirp sequence config indices.
 */
#define RFE_CHIRP_SEQUENCE_CONFIGS_MAX                  (8UL)

/**
 * The shift for offset part of a configuration parameter.
 */
#define RFE_CFG_PARAM_OFFSET_SHF                        ((uint8_t)(0UL))

/**
 * This macro defines the maximum chirp profile sequence length.
 */
#define RFE_CHIRP_PROFILE_SEQUENCE_LENGTH_MAX           (8UL)

/**
 * This macro defines the maximum number of configurable profiles.
 * #rfe_chirpProfileIndex_t defines the chirp profile indices.
 */
#define RFE_CHIRP_PROFILES_MAX                          (8UL)

/**
* This macro defines the number of transmitters.
* #rfe_txIndex_t defines the transmitter indices.
*/
#define RFE_TX_COUNT                                    (3UL)

/**
 * This macro defines the maximum supported chirp sequences per radar cycle.
 */
#define RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX         (8UL)

/**
 * This macro defines the number of bytes used in RFE Configuration BLOB
 * for masking or unmasking the FuSa Faults of total 12 bytes.
 */
#define RFE_FUSA_FAULT_MASK_PARAM_COUNT          (12UL)

/**
 * This macro defines the total number of configuration parameters.
 */

/** This macro defines the size of the general parameters */
#define RFE_SW_CFG_MNGR_GENRAL_PARAMS                                               ( (uint16_t) 19UL )
/** This macro defines the size of the monitor and safety parameters */
#define RFE_SW_CFG_MNGR_MONITOR_AND_SAFETY_PARAMS                                   ( (uint16_t) 83UL )
/** This macro defines the size of the radar cycle parameters */
#define RFE_SW_CFG_MNGR_RADAR_CYCLE_PARAMS                                          ( (uint16_t) 28UL )
/** This macro defines the size of the chirp sequence parameters */
#define RFE_SW_CFG_MNGR_CHIRP_SEQUENCE_PARAMS                                       ( (uint16_t) 21UL )
/** This macro defines the size of the chirp profile parameters */
#define RFE_SW_CFG_MNGR_CHIRP_PROFILE_PARAMS                                        ( (uint16_t) 22UL )
/** This macro defines the size of the non updatable parameters */
#define RFE_SW_CFG_MNGR_NON_UPDATABLE_PARAMS                                        ( (uint16_t) 10UL )
/** This macro defines the number of sections */
#define RFE_SW_CFG_MNGR_NO_OF_SECTION                                               ( (uint16_t) 6UL )
/** This macro defines the number of updatable parameters */
#define RFE_SW_CFG_MNGR_UPDATABLE_PARAMS                                            ( (uint16_t) 156UL )

/******************************************************************************
 *                           TYPES
 *****************************************************************************/
 /**
 * This type defines the phase rotation as Q7 for 360 degrees, 45 deg = 0x10.
 */
typedef uint8_t rfe_phaseRotation_t;

/**
 * This enumerated type defines the time reference for the tx transmission enable and setting of the phase rotation.
 */
typedef enum
{
    rfe_txTransmissionReferenceTime_startOfDwellTime_e,
    rfe_txTransmissionReferenceTime_startOfSettleTime_e
} rfe_txTransmissionReferenceTime_t;

/**
 * This enumerated type defines the chirp PLL loop filter bandwidths.
 */
typedef enum
{
    rfe_chirpPllLoopFilterBandwidth_200kHz_e = 0U,
    rfe_chirpPllLoopFilterBandwidth_250kHz_e = 1U,
    rfe_chirpPllLoopFilterBandwidth_300kHz_e = 2U,
    rfe_chirpPllLoopFilterBandwidth_350kHz_e = 3U,
    rfe_chirpPllLoopFilterBandwidth_400kHz_e = 4U,
    rfe_chirpPllLoopFilterBandwidth_450kHz_e = 5U,
    rfe_chirpPllLoopFilterBandwidth_500kHz_e = 6U,
    rfe_chirpPllLoopFilterBandwidth_550kHz_e = 7U,
    rfe_chirpPllLoopFilterBandwidth_600kHz_e = 8U,
    rfe_chirpPllLoopFilterBandwidth_650kHz_e = 9U,
    rfe_chirpPllLoopFilterBandwidth_700kHz_e = 10U,
    rfe_chirpPllLoopFilterBandwidth_750kHz_e = 11U,
    rfe_chirpPllLoopFilterBandwidth_800kHz_e = 12U,
    rfe_chirpPllLoopFilterBandwidth_850kHz_e = 13U,
    rfe_chirpPllLoopFilterBandwidth_900kHz_e = 14U,
    rfe_chirpPllLoopFilterBandwidth_950kHz_e = 15U,
    rfe_chirpPllLoopFilterBandwidth_1000kHz_e = 16U,
    rfe_chirpPllLoopFilterBandwidth_1050kHz_e = 17U,
    rfe_chirpPllLoopFilterBandwidth_1100kHz_e = 18U,
    rfe_chirpPllLoopFilterBandwidth_1150kHz_e = 19U,
    rfe_chirpPllLoopFilterBandwidth_1200kHz_e = 20U,
    rfe_chirpPllLoopFilterBandwidth_1250kHz_e = 21U,
    rfe_chirpPllLoopFilterBandwidth_1300kHz_e = 22U,
    rfe_chirpPllLoopFilterBandwidth_1350kHz_e = 23U,
    rfe_chirpPllLoopFilterBandwidth_1400kHz_e = 24U,
    rfe_chirpPllLoopFilterBandwidth_1450kHz_e = 25U,
    rfe_chirpPllLoopFilterBandwidth_1500kHz_e = 26U,
    rfe_chirpPllLoopFilterBandwidth_1550kHz_e = 27U,
    rfe_chirpPllLoopFilterBandwidth_1600kHz_e = 28U,
    rfe_chirpPllLoopFilterBandwidth_1650kHz_e = 29U,
    rfe_chirpPllLoopFilterBandwidth_1700kHz_e = 30U,
	rfe_chirpPllLoopFilterBandwidth_invalid_e
} rfe_chirpPllLoopFilterBandwidth_t;

/**
 * This enumerated type defines the effective sampling frequency of the chirp.
 * Effective means the sampling frequency after decimation, i.e. of the output samples.
 */
typedef enum
{
    rfe_effectiveSamplingFrequency_40MHz_e,
    rfe_effectiveSamplingFrequency_20MHz_e,
    rfe_effectiveSamplingFrequency_10MHz_e,
    rfe_effectiveSamplingFrequency_5MHz_e,
	rfe_effectiveSamplingFrequency_invalid_e
} rfe_effectiveSamplingFrequency_t;

 /** @} */

/**
 *  @addtogroup rsdk_rfe_interface
 *  @{
 *
 *  This enumerated type defines indices for the chirp sequence configuration array.
 */
typedef enum
{
    rfe_chirpSequenceIndex_0_e,
    rfe_chirpSequenceIndex_1_e,
    rfe_chirpSequenceIndex_2_e,
    rfe_chirpSequenceIndex_3_e,
    rfe_chirpSequenceIndex_4_e,
    rfe_chirpSequenceIndex_5_e,
    rfe_chirpSequenceIndex_6_e,
    rfe_chirpSequenceIndex_7_e,
	rfe_chirpSequenceIndex_invalid_e
} rfe_chirpSequenceIndex_t;


/**
 * The defined parameters.
 */
typedef enum
{
    rfeCfg_param_metadata_chirpSequenceConfigCount_e                        = (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | (RFE_CFG_PARAM_SIZE_8_BIT  | 0UL)),
    rfeCfg_param_metadata_chirpProfileCount_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | (RFE_CFG_PARAM_SIZE_8_BIT  | 1UL)),
    rfeCfg_param_metadata_majorVersion_e                                    = (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | (RFE_CFG_PARAM_SIZE_8_BIT  | 2UL)),
    rfeCfg_param_metadata_minorVersion_e                                    = (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | (RFE_CFG_PARAM_SIZE_8_BIT  | 3UL)),
    rfeCfg_param_metadata_patchVersion_e                                    = (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | (RFE_CFG_PARAM_SIZE_8_BIT  | 4UL)),
    rfeCfg_param_metadata_hashVersion_e                                     = (uint16_t)(RFE_CFG_PARAM_SECTION_METADATA | (RFE_CFG_PARAM_SIZE_8_BIT  | 5UL)),

    rfeCfg_param_general_powerMode_e                                        = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 0UL)),
    rfeCfg_param_general_radarCycleStartSignalGpio_e                        = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 1UL)),
    rfeCfg_param_general_chirpSequenceActiveSignalGpio_e                    = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 2UL)),
    rfeCfg_param_general_clkIoConfig_e                                      = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 3UL)),
    rfeCfg_param_general_pdcDecimationFilter_e                              = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 4UL)),
    rfeCfg_param_general_dataOutConfig_e                                    = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 5UL)),
    rfeCfg_param_general_metadataPacketSwContent_e                          = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 6UL)),
    rfeCfg_param_general_metadataPacketVirtualChannel_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 7UL)),
    rfeCfg_param_general_jumpbackTimeTicks_e                                = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 8UL)),
	rfeCfg_param_general_txCalibration_mode_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_GENERAL | (RFE_CFG_PARAM_SIZE_8_BIT  | 9UL)),

    rfeCfg_param_monitorAndSafety_rxSatCountResetEveryChirpSequence_e       = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 0UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx1_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 1UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx2_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 2UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx3_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 3UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx4_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 4UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx1_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 5UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx2_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 6UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx3_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 7UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx4_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 8UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx1_e        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 9UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx2_e        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 13UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx3_e        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 17UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx4_e        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 21UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx1_e        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 25UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx2_e        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 29UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx3_e        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 33UL)),
    rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx4_e        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 37UL)),
    rfeCfg_param_monitorAndSafety_adcClippingCountResetEveryChirpSequence_e = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_8_BIT  | 41UL)),
    rfeCfg_param_monitorAndSafety_adcClippingCountLimit_adc1_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 42UL)),
    rfeCfg_param_monitorAndSafety_adcClippingCountLimit_adc2_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 46UL)),
    rfeCfg_param_monitorAndSafety_adcClippingCountLimit_adc3_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 50UL)),
    rfeCfg_param_monitorAndSafety_adcClippingCountLimit_adc4_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | (RFE_CFG_PARAM_SIZE_32_BIT | 54UL)),
    /*
    * @violates @section rfe_cfg_blob_c_REF_1, Identifiers declared in the same scope and name space shall be distinct.
    */
    rfeCfg_param_monitorAndSafety_temperatureSensorThresholdHigh_tx12_e     = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 58UL),
    /*
    * @violates @section rfe_cfg_blob_c_REF_1, Identifiers declared in the same scope and name space shall be distinct.
    */
    rfeCfg_param_monitorAndSafety_temperatureSensorThresholdHigh_tx3_e      = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 62UL),
    rfeCfg_param_monitorAndSafety_temperatureSensorThresholdHigh_xo_e       = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 66UL),
    /*
    * @violates @section rfe_cfg_blob_c_REF_1, Identifiers declared in the same scope and name space shall be distinct.
    */
    rfeCfg_param_monitorAndSafety_temperatureSensorThresholdOver_tx12_e     = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 70UL),
    /*
    * @violates @section rfe_cfg_blob_c_REF_1, Identifiers declared in the same scope and name space shall be distinct.
    */
    rfeCfg_param_monitorAndSafety_temperatureSensorThresholdOver_tx3_e      = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 74UL),
    rfeCfg_param_monitorAndSafety_temperatureSensorThresholdOver_xo_e       = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 78UL),
    /*
    * @violates @section rfe_cfg_blob_c_REF_1, Identifiers declared in the same scope and name space shall be distinct.
    */
    rfeCfg_param_monitorAndSafety_temperatureSensorThresholdUnder_tx12_e    = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 82UL),
    /*
    * @violates @section rfe_cfg_blob_c_REF_1, Identifiers declared in the same scope and name space shall be distinct.
    */
    rfeCfg_param_monitorAndSafety_temperatureSensorThresholdUnder_tx3_e     = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 86UL),
    rfeCfg_param_monitorAndSafety_temperatureSensorThresholdUnder_xo_e      = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 90UL),
    rfeCfg_param_monitorAndSafety_thresholdValueToPromoteR1Faults_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 94UL),
    rfeCfg_param_monitorAndSafety_frequencyForBist_e                        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 95UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx2_e      = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 99UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx3_e      = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 101UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx4_e      = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 103UL),
    rfeCfg_param_monitorAndSafety_rxPhaseDiffLnaThresholdTolerance_e        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 105UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx2_e       = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 107UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx3_e       = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 109UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx4_e       = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 111UL),
    rfeCfg_param_monitorAndSafety_rxGainDiffLnaThresholdTolerance_e         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 113UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx2_e    = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 115UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx3_e    = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 117UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx4_e    = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 119UL),
    rfeCfg_param_monitorAndSafety_rxPhaseDiffMixerThresholdTolerance_e      = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 121UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx2_e     = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 123UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx3_e     = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 125UL),
    rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx4_e     = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 127UL),
    rfeCfg_param_monitorAndSafety_rxGainDiffMixerThresholdTolerance_e       = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_16_BIT | 129UL),
    rfeCfg_param_monitorAndSafety_injectTestTone_e                          = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 131UL),
    rfeCfg_param_monitorAndSafety_checkBbd_loi_e                            = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 132UL),
    rfeCfg_param_monitorAndSafety_checkBbd_tx_e                             = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 133UL),
    rfeCfg_param_monitorAndSafety_checkBbd_rx_e                             = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 134L),
    rfeCfg_param_monitorAndSafety_ppdThreshold_profile0_e                   = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 135UL),
    rfeCfg_param_monitorAndSafety_ppdThreshold_profile1_e                   = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 139UL),
    rfeCfg_param_monitorAndSafety_ppdThreshold_profile2_e                   = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 143UL),
    rfeCfg_param_monitorAndSafety_ppdThreshold_profile3_e                   = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 147UL),
    rfeCfg_param_monitorAndSafety_ppdThreshold_profile4_e                   = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 151UL),
    rfeCfg_param_monitorAndSafety_ppdThreshold_profile5_e                   = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 155UL),
    rfeCfg_param_monitorAndSafety_ppdThreshold_profile6_e                   = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 159UL),
    rfeCfg_param_monitorAndSafety_ppdThreshold_profile7_e                   = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_32_BIT | 163UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_0_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 167UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_1_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 168UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_2_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 169UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_3_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 170UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_4_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 171UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_5_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 172UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_6_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 173UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_7_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 174UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_8_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 175UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_9_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 176UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_10_e                        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 177UL),
    rfeCfg_param_monitorAndSafety_fuSaFaultMask_11_e                        = (uint16_t)(RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY | RFE_CFG_PARAM_SIZE_8_BIT  | 178UL),

    rfeCfg_param_radarCycle_radarCycleDuration_e                            = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 0UL),
    rfeCfg_param_radarCycle_chirpSequenceCount_e                            = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 4UL),
    rfeCfg_param_radarCycle_chirpSequence_0_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 5UL),
    rfeCfg_param_radarCycle_chirpSequence_1_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 6UL),
    rfeCfg_param_radarCycle_chirpSequence_2_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 7UL),
    rfeCfg_param_radarCycle_chirpSequence_3_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 8UL),
    rfeCfg_param_radarCycle_chirpSequence_4_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 9UL),
    rfeCfg_param_radarCycle_chirpSequence_5_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 10UL),
    rfeCfg_param_radarCycle_chirpSequence_6_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 11UL),
    rfeCfg_param_radarCycle_chirpSequence_7_e                               = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 12UL),
    rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_0_e                = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 13UL),
    rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_1_e                = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 17UL),
    rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_2_e                = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 21UL),
    rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_3_e                = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 25UL),
    rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_4_e                = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 29UL),
    rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_5_e                = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 33UL),
    rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_6_e                = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 37UL),
    rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_7_e                = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_32_BIT | 41UL),
    rfeCfg_param_radarCycle_recalibrateProfileDependent_0_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 45UL),
    rfeCfg_param_radarCycle_recalibrateProfileDependent_1_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 46UL),
    rfeCfg_param_radarCycle_recalibrateProfileDependent_2_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 47UL),
    rfeCfg_param_radarCycle_recalibrateProfileDependent_3_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 48UL),
    rfeCfg_param_radarCycle_recalibrateProfileDependent_4_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 49UL),
    rfeCfg_param_radarCycle_recalibrateProfileDependent_5_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 50UL),
    rfeCfg_param_radarCycle_recalibrateProfileDependent_6_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 51UL),
    rfeCfg_param_radarCycle_recalibrateProfileDependent_7_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 52UL),
    rfeCfg_param_radarCycle_recalibrateProfileIndependent_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 53UL),
    rfeCfg_param_radarCycle_bistInterval_e                                  = (uint16_t)(RFE_CFG_PARAM_SECTION_RADAR_CYCLE | RFE_CFG_PARAM_SIZE_8_BIT  | 54UL),

    rfeCfg_param_chirpSequence_chirpCount_e                                 = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_16_BIT | 0UL),
    rfeCfg_param_chirpSequence_chirpProfileSequence_0_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 2UL),
    rfeCfg_param_chirpSequence_chirpProfileSequence_1_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 3UL),
    rfeCfg_param_chirpSequence_chirpProfileSequence_2_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 4UL),
    rfeCfg_param_chirpSequence_chirpProfileSequence_3_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 5UL),
    rfeCfg_param_chirpSequence_chirpProfileSequence_4_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 6UL),
    rfeCfg_param_chirpSequence_chirpProfileSequence_5_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 7UL),
    rfeCfg_param_chirpSequence_chirpProfileSequence_6_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 8UL),
    rfeCfg_param_chirpSequence_chirpProfileSequence_7_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 9UL),
    rfeCfg_param_chirpSequence_chirpProfileSequenceLength_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 10UL),
    rfeCfg_param_chirpSequence_chirpProfileRepeatCount_e                    = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 11UL),
    rfeCfg_param_chirpSequence_dynamicUpdatesEnabled_e                      = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 12UL),
    rfeCfg_param_chirpSequence_dynamicTableIndex_e                          = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 13UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_e                       = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 14UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx_e                    = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 15UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_init_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 16UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx2_init_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 17UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx3_init_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 18UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_update_e            = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 19UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx2_update_e            = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 20UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx3_update_e            = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 21UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_mode_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 22UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx2_mode_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 23UL),
    rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx3_mode_e              = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 24UL),
    rfeCfg_param_chirpSequence_rxEnable_e                                   = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 25UL),
    rfeCfg_param_chirpSequence_pdcNotchFilterEnable_e                       = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_8_BIT  | 26UL),
    rfeCfg_param_chirpSequence_txCalibration_thresholdHigh_e                = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_16_BIT | 27UL),
	rfeCfg_param_chirpSequence_txCalibration_thresholdLow_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG | RFE_CFG_PARAM_SIZE_16_BIT | 29UL),

    rfeCfg_param_chirpProfile_effectiveSamplingFrequency_e                  = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 0UL),
    rfeCfg_param_chirpProfile_chirpIntervalTimeTicks_e                      = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_32_BIT | 1UL),
    rfeCfg_param_chirpProfile_dwellTimeTicks_e                              = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 5UL),
    rfeCfg_param_chirpProfile_settleTimeTicks_e                             = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 7UL),
    rfeCfg_param_chirpProfile_acquisitionTimeTicks_e                        = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 9UL),
    rfeCfg_param_chirpProfile_resetTimeTicks_e                              = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 11UL),
    rfeCfg_param_chirpProfile_centerFrequency_e                             = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_32_BIT | 13UL),
    rfeCfg_param_chirpProfile_effectiveChirpBandwidth_e                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_32_BIT | 17UL),
    rfeCfg_param_chirpProfile_chirpPllVcoSelect_e                           = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 21UL),
    rfeCfg_param_chirpProfile_chirpSlopeDirection_e                         = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 22UL),
    rfeCfg_param_chirpProfile_chirpPllLoopFilterBandwidth_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 23UL),
    rfeCfg_param_chirpProfile_txTransmissionEnable_e                        = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 24UL),
    rfeCfg_param_chirpProfile_txPower_e                                     = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 25UL),
    rfeCfg_param_chirpProfile_txPhaseRotation_1_e                           = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 27UL),
    rfeCfg_param_chirpProfile_txPhaseRotation_2_e                           = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 28UL),
    rfeCfg_param_chirpProfile_txPhaseRotation_3_e                           = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 29UL),
    rfeCfg_param_chirpProfile_txTransmissionReferenceTime_e                 = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 30UL),
    rfeCfg_param_chirpProfile_txTransmissionTimeOffset_e                    = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_16_BIT | 31UL),
    rfeCfg_param_chirpProfile_chirpFrequencyDriftSteps_e                    = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_32_BIT | 33UL),
    rfeCfg_param_chirpProfile_rxGain_e                                      = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 37UL),
    rfeCfg_param_chirpProfile_rxHpfCutOffFrequency_e                        = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 38UL),
    rfeCfg_param_chirpProfile_rxLpfCutOffFrequency_e                        = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 39UL),
    rfeCfg_param_chirpProfile_virtualChannel_e                              = (uint16_t)(RFE_CFG_PARAM_SECTION_CHIRP_PROFILE | RFE_CFG_PARAM_SIZE_8_BIT  | 40UL),

    rfeCfg_param_metadata_crc                                               = (uint16_t)(RFE_CFG_PARAM_SECTION_CRC | (RFE_CFG_PARAM_SIZE_32_BIT | 0UL))
} rfeCfg_param_t;


/**
 * The defined sections.
 */
typedef enum
{
    rfeCfg_section_metadata_e                                               = RFE_CFG_PARAM_SECTION_METADATA                    | RFE_CFG_OFFSET_SECTION_METADATA,
    rfeCfg_section_general_e                                                = RFE_CFG_PARAM_SECTION_GENERAL                     | RFE_CFG_OFFSET_SECTION_GENERAL,
    rfeCfg_section_monitorAndSafety_e                                       = RFE_CFG_PARAM_SECTION_MONITOR_AND_SAFETY          | RFE_CFG_OFFSET_SECTION_MONITOR_AND_SAFETY,
    rfeCfg_section_radarCycle_e                                             = RFE_CFG_PARAM_SECTION_RADAR_CYCLE                 | RFE_CFG_OFFSET_SECTION_RADAR_CYCLE,
    rfeCfg_section_chirpSequenceConfig_0_e                                  = RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG       | RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_0,
    rfeCfg_section_chirpProfile_0_e                                         = RFE_CFG_PARAM_SECTION_CHIRP_PROFILE               | RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_0,
    rfeCfg_section_chirpSequenceConfig_1_e                                  = RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG       | RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_1,
    rfeCfg_section_chirpProfile_1_e                                         = RFE_CFG_PARAM_SECTION_CHIRP_PROFILE               | RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_1,
    rfeCfg_section_chirpSequenceConfig_2_e                                  = RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG       | RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_2,
    rfeCfg_section_chirpProfile_2_e                                         = RFE_CFG_PARAM_SECTION_CHIRP_PROFILE               | RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_2,
    rfeCfg_section_chirpSequenceConfig_3_e                                  = RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG       | RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_3,
    rfeCfg_section_chirpProfile_3_e                                         = RFE_CFG_PARAM_SECTION_CHIRP_PROFILE               | RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_3,
    rfeCfg_section_chirpSequenceConfig_4_e                                  = RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG       | RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_4,
    rfeCfg_section_chirpProfile_4_e                                         = RFE_CFG_PARAM_SECTION_CHIRP_PROFILE               | RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_4,
    rfeCfg_section_chirpSequenceConfig_5_e                                  = RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG       | RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_5,
    rfeCfg_section_chirpProfile_5_e                                         = RFE_CFG_PARAM_SECTION_CHIRP_PROFILE               | RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_5,
    rfeCfg_section_chirpSequenceConfig_6_e                                  = RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG       | RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_6,
    rfeCfg_section_chirpProfile_6_e                                         = RFE_CFG_PARAM_SECTION_CHIRP_PROFILE               | RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_6,
    rfeCfg_section_chirpSequenceConfig_7_e                                  = RFE_CFG_PARAM_SECTION_CHIRP_SEQUENCE_CONFIG       | RFE_CFG_OFFSET_SECTION_CHIRP_SEQUENCE_7,
    rfeCfg_section_chirpProfile_7_e                                         = RFE_CFG_PARAM_SECTION_CHIRP_PROFILE               | RFE_CFG_OFFSET_SECTION_CHIRP_PROFILE_7,
    rfeCfg_section_crc                                                      = RFE_CFG_PARAM_SECTION_CRC                         | RFE_CFG_OFFSET_SECTION_CRC
} rfeCfg_section_t;


/**
 * Size of the configuration data item.
 */
typedef enum
{
    rfeCfg_size_8_bit_e = 0U,                                               //!<  8 bit data size.
    rfeCfg_size_16_bit_e,                                                   //!< 16 bit data size.
    rfeCfg_size_32_bit_e,                                                   //!< 32 bit data size.
    rfeCfg_size_invalid_e                                                   //!< invalide bit data size.
} rfeCfg_size_t;

/**
 * This enumerated types defines the RFE-Fw parameters that can be updated.
 */
typedef enum
{
    rfe_paramUpdate_general_powerMode_e,
    rfe_paramUpdate_general_radarCycleStartSignalGpio_e,
    rfe_paramUpdate_general_chirpSequenceActiveSignalGpio_e,
    rfe_paramUpdate_general_clkIoConfig_e,
    rfe_paramUpdate_general_pdcDecimationFilter_e,
    rfe_paramUpdate_general_dataOutConfig_e,
    rfe_paramUpdate_general_metadataPacketSwContent_e,
    rfe_paramUpdate_general_metadataPacketVirtualChannel_e,
    rfe_paramUpdate_general_jumpbackTimeTicks_e,
	rfe_paramUpdate_general_txCalibration_mode_e,

    rfe_paramUpdate_monitorAndSafety_rxSatCountResetEveryChirpSequence_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx1_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx2_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx3_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage1_rx4_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage2_rx1_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage2_rx2_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage2_rx3_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationThresholdStage2_rx4_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx1_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx2_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx3_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage1_rx4_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage2_rx1_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage2_rx2_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage2_rx3_e,
    rfe_paramUpdate_monitorAndSafety_rxSaturationCountLimitStage2_rx4_e,
    rfe_paramUpdate_monitorAndSafety_adcClippingCountResetEveryChirpSequence_e,
    rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc1_e,
    rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc2_e,
    rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc3_e,
    rfe_paramUpdate_monitorAndSafety_adcClippingCountLimit_adc4_e,
    rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdHigh_tx12_e,
    rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdHigh_tx3_e,
    rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdHigh_xo_e,
    rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdOver_tx12_e,
    rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdOver_tx3_e,
    rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdOver_xo_e,
    rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdUnder_tx12_e,
    rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdUnder_tx3_e,
    rfe_paramUpdate_monitorAndSafety_temperatureSensorThresholdUnder_xo_e,
    rfe_paramUpdate_monitorAndSafety_thresholdValueToPromoteR1Faults_e,
    rfe_paramUpdate_monitorAndSafety_frequencyForBist_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx2_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx3_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx4_e,
    rfe_paramUpdate_monitorAndSafety_rxPhaseDiffLnaThresholdTolerance_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx2_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx3_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx4_e,
    rfe_paramUpdate_monitorAndSafety_rxGainDiffLnaThresholdTolerance_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx2_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx3_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx4_e,
    rfe_paramUpdate_monitorAndSafety_rxPhaseDiffMixerThresholdTolerance_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx2_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx3_e,
    rfe_paramUpdate_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx4_e,
    rfe_paramUpdate_monitorAndSafety_rxGainDiffMixerThresholdTolerance_e,
    rfe_paramUpdate_monitorAndSafety_injectTestTone_e,
    rfe_paramUpdate_monitorAndSafety_checkBbd_loi_e,
    rfe_paramUpdate_monitorAndSafety_checkBbd_tx_e,
    rfe_paramUpdate_monitorAndSafety_checkBbd_rx_e,
    rfe_paramUpdate_monitorAndSafety_ppdThreshold_profile0_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_0_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_1_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_2_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_3_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_4_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_5_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_6_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_7_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_8_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_9_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_10_e,
    rfe_paramUpdate_monitorAndSafety_fuSaFaultMask_11_e,

    rfe_paramUpdate_radarCycle_radarCycleDuration_e,
    rfe_paramUpdate_radarCycle_chirpSequenceCount_e,
    rfe_paramUpdate_radarCycle_chirpSequence_0_e,
    rfe_paramUpdate_radarCycle_chirpSequence_1_e,
    rfe_paramUpdate_radarCycle_chirpSequence_2_e,
    rfe_paramUpdate_radarCycle_chirpSequence_3_e,
    rfe_paramUpdate_radarCycle_chirpSequence_4_e,
    rfe_paramUpdate_radarCycle_chirpSequence_5_e,
    rfe_paramUpdate_radarCycle_chirpSequence_6_e,
    rfe_paramUpdate_radarCycle_chirpSequence_7_e,
    rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_0_e,
    rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_1_e,
    rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_2_e,
    rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_3_e,
    rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_4_e,
    rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_5_e,
    rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_6_e,
    rfe_paramUpdate_radarCycle_chirpSequenceStartTimeOffset_7_e,
    rfe_paramUpdate_radarCycle_recalibrateProfileDependent_0_e,
    rfe_paramUpdate_radarCycle_recalibrateProfileDependent_1_e,
    rfe_paramUpdate_radarCycle_recalibrateProfileDependent_2_e,
    rfe_paramUpdate_radarCycle_recalibrateProfileDependent_3_e,
    rfe_paramUpdate_radarCycle_recalibrateProfileDependent_4_e,
    rfe_paramUpdate_radarCycle_recalibrateProfileDependent_5_e,
    rfe_paramUpdate_radarCycle_recalibrateProfileDependent_6_e,
    rfe_paramUpdate_radarCycle_recalibrateProfileDependent_7_e,
    rfe_paramUpdate_radarCycle_recalibrateProfileIndependent_e,
    rfe_paramUpdate_radarCycle_bistInterval_e,

    rfe_paramUpdate_chirpSequence_chirpCount_e,
    rfe_paramUpdate_chirpSequence_chirpProfileSequence_0_e,
    rfe_paramUpdate_chirpSequence_chirpProfileSequence_1_e,
    rfe_paramUpdate_chirpSequence_chirpProfileSequence_2_e,
    rfe_paramUpdate_chirpSequence_chirpProfileSequence_3_e,
    rfe_paramUpdate_chirpSequence_chirpProfileSequence_4_e,
    rfe_paramUpdate_chirpSequence_chirpProfileSequence_5_e,
    rfe_paramUpdate_chirpSequence_chirpProfileSequence_6_e,
    rfe_paramUpdate_chirpSequence_chirpProfileSequence_7_e,
    rfe_paramUpdate_chirpSequence_chirpProfileSequenceLength_e,
    rfe_paramUpdate_chirpSequence_dynamicUpdatesEnabled_e,
    rfe_paramUpdate_chirpSequence_dynamicTableIndex_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx1_init_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx2_init_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx3_init_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx1_update_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx2_update_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx3_update_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx1_mode_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx2_mode_e,
    rfe_paramUpdate_chirpSequence_txPhaseRotation_ddma_tx3_mode_e,
    rfe_paramUpdate_chirpSequence_rxEnable_e,
    rfe_paramUpdate_chirpSequence_pdcNotchFilterEnable_e,
	rfe_paramUpdate_chirpSequence_txCalibration_thresholdHigh_e,
	rfe_paramUpdate_chirpSequence_txCalibration_thresholdLow_e,

    rfe_paramUpdate_chirpProfile_effectiveSamplingFrequency_e,
    rfe_paramUpdate_chirpProfile_chirpIntervalTimeTicks_e,
    rfe_paramUpdate_chirpProfile_dwellTimeTicks_e,
    rfe_paramUpdate_chirpProfile_settleTimeTicks_e,
    rfe_paramUpdate_chirpProfile_acquisitionTimeTicks_e,
    rfe_paramUpdate_chirpProfile_resetTimeTicks_e,
    rfe_paramUpdate_chirpProfile_centerFrequency_e,
    rfe_paramUpdate_chirpProfile_effectiveChirpBandwidth_e,
    rfe_paramUpdate_chirpProfile_chirpPllVcoSelect_e,
    rfe_paramUpdate_chirpProfile_chirpSlopeDirection_e,
    rfe_paramUpdate_chirpProfile_chirpPllLoopFilterBandwidth_e,
    rfe_paramUpdate_chirpProfile_txTransmissionEnable_e,
    rfe_paramUpdate_chirpProfile_txPower_e,
    rfe_paramUpdate_chirpProfile_txPhaseRotation_1_e,
    rfe_paramUpdate_chirpProfile_txPhaseRotation_2_e,
    rfe_paramUpdate_chirpProfile_txPhaseRotation_3_e,
    rfe_paramUpdate_chirpProfile_txTransmissionReferenceTime_e,
    rfe_paramUpdate_chirpProfile_txTransmissionTimeOffset_e,
    rfe_paramUpdate_chirpProfile_chirpFrequencyDriftSteps_e,
    rfe_paramUpdate_chirpProfile_rxGain_e,
    rfe_paramUpdate_chirpProfile_rxHpfCutOffFrequency_e,
    rfe_paramUpdate_chirpProfile_rxLpfCutOffFrequency_e,
    rfe_paramUpdate_chirpProfile_virtualChannel_e
} rfe_paramUpdate_t;

/******************************************************************************
 *                           CONSTANTS
 *****************************************************************************/


/******************************************************************************
 *                           EXTERNAL FUNCTIONS
 *****************************************************************************/
/*
 * Definition for the necessary function to compute the CRC over the blob buffer.
 * A similar function must be used on the Configurator and on the Server side.
 * The usual implementation get exact results as the CRC hardware computation on S32R41, using the configuration :
 *  - polynomial = CRC-32
 *  - all the other configuration bits set to 1, as required for CRC-32 calculation :
 *      swap_bytewise, swap_bitwise, swap and inversion
 * For software implementation, the explicit operation are :
 *  - the polynomial is 0x1EDC6F41 (CRC-32C), this is the polynomial used by the Configurator to compute CRC
 *  - start CRC computation value is 0xffffffff
 *  - input bytes are used reversing the bits order
 *  - the final result is the bit toggled value of the computed result, after swapping the bits and the bytes
 */
extern uint32_t rfeCrc_calBuf(void* bufPtr, uint32_t len);

/** @} */

 
#ifdef __cplusplus
}
#endif


#endif // !RFE_CFG_BLOB_H
