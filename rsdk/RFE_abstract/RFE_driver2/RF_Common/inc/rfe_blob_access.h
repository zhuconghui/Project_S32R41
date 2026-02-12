/*
* Copyright 2023 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
*/


/******************************************************************************
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_BLOB_ACCESS_H
#define RFE_BLOB_ACCESS_H

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include "rfe_types.h"
#include "rfe_cfg_blob.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @addtogroup rsdk_rfe_blob_interface
 * @{
 */


/******************************************************************************
 *                              DEFINES AND TYPES
 *****************************************************************************/
/**
 * \brief Struct to hold value of RX Bist reference data
 *
 * refMag  - Array of reference signal magnitudes difference vs 1st RX for all RX channels measured in [dB] for LNA and mixer input.
 * refPh   - Array of reference signal phase difference vs 1st RX for all RX channels measured in [rad] for LNA and mixer input.
 *
 */
typedef struct
{
    int16_t   refMag[RFE_RX_BIST_COMBINATIONS][TEF82XX_RFBIST_TESTS];
    int16_t   refPh[RFE_RX_BIST_COMBINATIONS][TEF82XX_RFBIST_TESTS];
} rfeCfg_rxBistReferenceData_t;


/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/
/**
 * \brief   Sets a different \ref chirpCount for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be changed
 * \param   chirpCount                  = the new chir count
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setChirpCount(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint16_t chirpCount, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Gets the current \ref chirpCount for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing \ref chirpCount, as uint16_t
 */
uint16_t rfeCfg_chirpSequence_getChirpCount(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Sets the number of profiles used for the selected sequence (see \ref chirpProfileSequenceLength).
 *          Useful for adding or removing profiles that will be used in the selected sequence.
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be changed
 * \param   chirpProfileSequenceLength  = the new sequence length
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \remark
 * By increasing the \ref chirpProfileSequenceLength, it is important that the newly added indexes from the list,
 * will point to a valid chirp profile (see \ref rfeCfg_chirpSequence_setChirpProfileSequence)
 * For example, if \ref chirpProfileSequenceLength = <b>3</b>, but want to increase it to <b>5</b> by calling this function,
 * then indexes 3 & 4 must be initialized with a profile index, otherwise profile "0" will be used by default:
 * - rfeCfg_param_chirpSequence_chirpProfileSequence_0_e - <i>previously initialized</i>
 * - rfeCfg_param_chirpSequence_chirpProfileSequence_1_e - <i>previously initialized</i>
 * - rfeCfg_param_chirpSequence_chirpProfileSequence_2_e - <i>previously initialized</i>
 * - rfeCfg_param_chirpSequence_chirpProfileSequence_3_e - <b>0</b>!
 * - rfeCfg_param_chirpSequence_chirpProfileSequence_4_e - <b>0</b>!
 *
 */
void rfeCfg_chirpSequence_setChirpProfileSequenceLength(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t chirpProfileSequenceLength,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Gets the number of profiles used for the selected sequence (see \ref chirpProfileSequenceLength).
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing sequence length
 */
uint8_t rfeCfg_chirpSequence_getChirpProfileSequenceLength(const uint8_t* pConfig,  rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set the \ref chirpProfileRepeatCount for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be changed
 * \param   chirpProfileRepeatCount  	= the new repeat count
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setChirpProfileRepeatCount(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t chirpProfileRepeatCount,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the \ref chirpProfileRepeatCount for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing sequence length
 */
uint8_t rfeCfg_chirpSequence_getChirpProfileRepeatCount(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);
/**
 * \brief   Sets whether the dynamic updates are enabled or disabled for the selected sequence. (see \ref dynamicUpdatesEnabled)
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be changed
 * \param   dynamicUpdatesEnabled       = the new dynamic update enablement
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setDynamicUpdatesEnabled(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, bool dynamicUpdatesEnabled,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the existing setting for \ref dynamicUpdatesEnabled
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The dynamic update current status
 */
bool rfeCfg_chirpSequence_getDynamicUpdatesEnabled(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set the \ref dynamicTableIndex for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be set
 * \param   dynamicTableIndex           = the new dynamic table index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setDynamicTableIndex(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t dynamicTableIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the \ref dynamicTableIndex for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing dynamic table index
 */
uint8_t rfeCfg_chirpSequence_getDynamicTableIndex(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Sets which RX antennas to be enabled/disabled for the selected sequence (see \ref rxEnable)
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be set
 * \param   rxEnable                    = the new value for Rx Enablement
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setRxEnable(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_rxSelect_t rxEnable, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Gets which RX antennas are enabled/disabled for the selected sequence (see \ref rxEnable)
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Rx Enablement
 */
uint8_t rfeCfg_chirpSequence_getRxEnable(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Sets which profiles to be used in the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the sequence to be updated
 * \param   chirpProfileSequenceIndex   = the index where to add the new profile, within the list
 * \param   chirpProfile                = the profile to add to the list
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \remark
 * The value range for <i>chirpProfileSequenceIndex</i>, should be [0 ... \ref chirpProfileSequenceLength - 1]
 * For example, if \ref chirpProfileSequenceLength = <b>3</b>, and this function wants to set for \ref rfeCfg_param_chirpSequence_chirpProfileSequence_5_e,
 * it will have no effect, since only indexes [0,1,2] will be used from the list:
 * - rfeCfg_param_chirpSequence_chirpProfileSequence_0_e
 * - rfeCfg_param_chirpSequence_chirpProfileSequence_1_e
 * - rfeCfg_param_chirpSequence_chirpProfileSequence_2_e
 *
 */
void rfeCfg_chirpSequence_setChirpProfileSequence(uint8_t* pConfig,
        rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t chirpProfileSequenceIndex,
        rfe_chirpProfileIndex_t chirpProfile, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Gets which profiles are used in the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the sequence to be checked
 * \param   chirpProfileSequenceIndex   = the index from which to read, within the list of profiles
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Profile Sequence
 */
uint8_t rfeCfg_chirpSequence_getChirpProfileSequence(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t chirpProfileSequenceIndex,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref effectiveSamplingFrequency in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   effectiveSamplingFrequency  = the new value for Effective Sampling Frequency
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setEffectiveSamplingFrequency(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_effectiveSamplingFrequency_t effectiveSamplingFrequency,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref effectiveSamplingFrequency value from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Effective Sampling Frequency
 */
uint8_t rfeCfg_chirpProfile_getEffectiveSamplingFrequency(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref chirpIntervalTimeTicks in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   chirpIntervalTimeTicks      = the new value for Chirp Interval Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setChirpIntervalTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint32_t chirpIntervalTimeTicks,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref chirpIntervalTimeTicks from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Interval Time Ticks
 */
uint32_t rfeCfg_chirpProfile_getChirpIntervalTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref dwellTimeTicks in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   dwellTimeTicks              = the new value for Dwell Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setDwellTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t dwellTimeTicks, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref dwellTimeTicks from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Dwell Time Ticks
 */
uint16_t rfeCfg_chirpProfile_getDwellTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref  settleTimeTicks in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   settleTimeTicks             = the new value for Settle Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setSettleTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t settleTimeTicks, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref  settleTimeTicks from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Settle Time Ticks
 */
uint16_t rfeCfg_chirpProfile_getSettleTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref acquisitionTimeTicks in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   acquisitionTimeTicks        = the new value for Acquisition Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setAcquisitionTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t acquisitionTimeTicks, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref acquisitionTimeTicks from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Acquisition Time Ticks
 */
uint16_t rfeCfg_chirpProfile_getAcquisitionTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref resetTimeTicks in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   resetTimeTicks              = the new value for Reset Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setResetTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t resetTimeTicks, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref resetTimeTicks from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Reset Time Ticks
 */
uint16_t rfeCfg_chirpProfile_getResetTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref centerFrequency in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   centerFrequency             = the new value for Center Frequency
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setCenterFrequency(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint32_t centerFrequency, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref centerFrequency from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Center Frequency
 */
uint32_t rfeCfg_chirpProfile_getCenterFrequency(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref effectiveChirpBandwidth in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   effectiveChirpBandwidth     = the new value for Effective Chirp Bandwidth
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setEffectiveChirpBandwidth(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint32_t effectiveChirpBandwidth,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref effectiveChirpBandwidth from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Effective Chirp Bandwidth
 */
uint32_t rfeCfg_chirpProfile_getEffectiveChirpBandwidth(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref chirpPllVcoSelect in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   chirpPllVcoSelect           = the new value for Chirp Pll Vco
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setChirpPllVco(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_chirpPllVco_t chirpPllVcoSelect, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current /ref chirpPllVcoSelect from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Pll Vco
 */
uint8_t rfeCfg_chirpProfile_getChirpPllVco(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref chirpSlopeDirection in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   chirpSlopeDirection         = the new value for Chirp Slope Direction
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setChirpSlopeDirection(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_chirpSlopeDirection_t chirpSlopeDirection,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref chirpSlopeDirection from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Slope Direction
 */
uint8_t rfeCfg_chirpProfile_getChirpSlopeDirection(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref chirpPllLoopFilterBandwidth in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   chirpPllLoopFilterBandwidth = the new value for Chirp Pll Loop Filter Bandwidth
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setChirpPllLoopFilterBandwidth(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_chirpPllLoopFilterBandwidth_t chirpPllLoopFilterBandwidth,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref chirpPllLoopFilterBandwidth from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Pll Loop Filter Bandwidth
 */
uint8_t rfeCfg_chirpProfile_getChirpPllLoopFilterBandwidth(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref txTransmissionEnable in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   txTransmissionEnable        = the new value for Tx Transmission Enable
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxTransmissionEnable(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_txSelect_t txTransmissionEnable,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref txTransmissionEnable from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Transmission Enable
 */
uint8_t rfeCfg_chirpProfile_getTxTransmissionEnable(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref txPower in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   txPower                     = the new value for Tx Power
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxPower(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, int16_t txPower, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref txPower from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Power
 */
int16_t rfeCfg_chirpProfile_getTxPower(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref txPhaseRotation in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   tx                          = the index value for Tx Phase Rotation
 * \param   txPhaseRotation             = the new value for Tx Phase Rotation
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxPhaseRotation(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_txIndex_t tx, rfe_phaseRotation_t txPhaseRotation,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref txPhaseRotation from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   tx                          = the index value for Tx Phase Rotation
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Phase Rotation
 */
uint8_t rfeCfg_chirpProfile_getTxPhaseRotation(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for Tx Transmission Reference Time
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   txTransmissionReferenceTime = the new value for Tx Transmission Reference Time
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxTransmissionReferenceTime(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_txTransmissionReferenceTime_t txTransmissionReferenceTime,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current Tx Transmission Reference Time
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Transmission Reference Time
 */
uint8_t rfeCfg_chirpProfile_getTxTransmissionReferenceTime(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for Tx Transmission Time Offset
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   txTransmissionTimeOffset    = the new value for Tx Transmission Time Offset
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxTransmissionTimeOffset(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t txTransmissionTimeOffset,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current Tx Transmission Time Offset
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Transmission Time Offset
 */
uint16_t rfeCfg_chirpProfile_getTxTransmissionTimeOffset(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref rxGain in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rxGain                      = the new value for Rx Gain
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setRxGain(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_rxGain_t rxGain, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref rxGain from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Rx Gain
 */
uint8_t rfeCfg_chirpProfile_getRxGain(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref rxHpfCutOffFrequency in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rxHpfCutOffFrequency        = the new value for Rx Hpf CutOff Frequency
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setRxHpfCutOffFrequency(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_rxHpfCutOffFrequency_t rxHpfCutOffFrequency,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref rxHpfCutOffFrequency from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Rx Hpf CutOff Frequency
 */
uint8_t rfeCfg_chirpProfile_getRxHpfCutOffFrequency(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref rxLpfCutOffFrequency in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rxLpfCutOffFrequency        = the new value for Rx Lpf CutOff Frequency
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setRxLpfCutOffFrequency(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_rxLpfCutOffFrequency_t rxLpfCutOffFrequency,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref rxLpfCutOffFrequency from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Rx Lpf CutOff Frequency
 */
uint8_t rfeCfg_chirpProfile_getRxLpfCutOffFrequency(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref virtualChannel in the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   virtualChannel              = the new value for Virtual Channel
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setVirtualChannel(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_virtualChannel_t virtualChannel, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref virtualChannel from the selected profile
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Virtual Channel
 */
uint8_t rfeCfg_chirpProfile_getVirtualChannel(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref radarCycleDuration
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   radarCycleDuration          = the new value for Radar Cycle Duration
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_radarCycle_setRadarCycleDuration(uint8_t* pConfig, uint32_t radarCycleDuration, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the current \ref radarCycleDuration
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Radar Cycle Duration
 */
uint32_t rfeCfg_radarCycle_getRadarCycleDuration(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer);


/******************************************************************************
 *                           FUNCTIONS
 *****************************************************************************/
/**
 * \brief This function writes a value to the configuration blob, according to the provided parameters.
 *        The provided value must be a uint32_t value, but the written value is according
 *        to the size of the parameter definition (see \ref rsdk_rfe_blob_const).
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory
 * \param [in]      section   - the required section
 * \param [in]      param     - the required parameter
 * \param [in]      value     - the value to be written - aligned to 32 bits
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 */
void rfeCfg_write(uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, uint32_t value, rfe_error_t* rfe___error___pointer);


/**
 * \brief This function reads a uint8_t value from the configuration.
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory.
 * \param [in]      section   - the required section
 * \param [in]      param     - the required parameter
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return uint8_t value
 *
 */
uint8_t rfeCfg_readB(const uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function reads a uint16_t value from the configuration.
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory.
 * \param [in]      section   - the required section
 * \param [in]      param     - the required parameter
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return uint16_t value
 *
 */
uint16_t rfeCfg_readW(const uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function reads a uint32_t value from the configuration.
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory.
 * \param [in]      section   - the required section
 * \param [in]      param     - the required parameter
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return uint32_t value
 *
 */
uint32_t rfeCfg_readDW(const uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function reads a value from the configuration.
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory.
 * \param [in]      section   - the required section
 * \param [in]      param     - the required parameter
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return the requested parameter in a uint32_t value
 *
 */
uint32_t rfeCfg_read(const uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer);

/**
 * \brief Gets the \ref chirpSequenceCount.
 *        This is useful in combination with \ref rfeCfg_radarCycle_getChirpSequence, for determining
 *        how many sequence configurations are utilized in the configured Radar Cycle and
 *        in what order they are used.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref chirpSequenceCount
 *
 */
static inline uint8_t rfeCfg_radarCycle_getChirpSequenceCount(const uint8_t *pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readB(pConfig, rfeCfg_section_radarCycle_e, rfeCfg_param_radarCycle_chirpSequenceCount_e, rfe___error___pointer);
}

/**
 * \brief This function gets the sequence configuration, that is used at the selected index.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      chirpSequenceIndex - The chirp sequence index
 * \param [in,out]  rfe___error___pointer - pointer to the error status
 *                  On success *rfe___error___pointer is no_error,
 *                  On failure *rfe___error___pointer is not no_error
 *
 * \return \ref rfeCfg_param_radarCycle_chirpSequence_0_e or similar
 *
 * \remark
 * <b>Example</b>: If the XML (blob) was generated with a Radar Cycle, that uses sequences [3,1,2], then:
 * \ref chirpSequenceCount = 3:
 * - rfeCfg_param_radarCycle_chirpSequence_0_e = 3
 * - rfeCfg_param_radarCycle_chirpSequence_1_e = 1
 * - rfeCfg_param_radarCycle_chirpSequence_2_e = 2
 *
 */
uint8_t rfeCfg_radarCycle_getChirpSequence(const uint8_t *pConfig, uint8_t chirpSequenceIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the corresponding \ref chirpSequenceStartTimeOffset .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      chirpSequenceIndex - The chirp sequence index
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_0_e or similar
 *
 */
uint32_t rfeCfg_radarCycle_getChirpSequenceStartTimeOffset(const uint8_t *pConfig, uint8_t chirpSequenceIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref chirpSequenceConfigCount .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref chirpSequenceConfigCount
 *
 */
static inline uint8_t rfeCfg_metadata_getChirpSequenceConfigCount(const uint8_t *pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readB(pConfig, rfeCfg_section_metadata_e, rfeCfg_param_metadata_chirpSequenceConfigCount_e, rfe___error___pointer);
}

/**
 * \brief This function gets the \ref chirpProfileCount .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref chirpProfileCount
 *
 */
static inline uint8_t rfeCfg_metadata_getChirpProfileCount(const uint8_t *pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readB(pConfig, rfeCfg_section_metadata_e, rfeCfg_param_metadata_chirpProfileCount_e, rfe___error___pointer);
}

/**
 * \brief This function sets the \ref powerMode .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      powerMode - \ref powerMode
 * \param [in,out]  rfe___error___pointer - pointer to the error status
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 */
void rfeCfg_general_setPowerMode(uint8_t *pConfig, rfe_powerMode_t powerMode, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref powerMode .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - pointer to the error status
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref powerMode
 *
 */
uint8_t rfeCfg_general_getPowerMode(const uint8_t *pConfig, rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * \brief   Get the \ref txCalibration (with / without transmission)
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - pointer to the error status
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return  0 - without transmission
 *          1 - with transmission
 *
 */
uint8_t rfeCfg_general_getTxCalibrationMode(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref jumpbackTimeTicks .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref jumpbackTimeTicks
 *
 */
static inline uint8_t rfeCfg_general_getJumpbackTimeTicks(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readB(pConfig, rfeCfg_section_general_e, rfeCfg_param_general_jumpbackTimeTicks_e, rfe___error___pointer);
}

/**
 * \brief This function gets the \ref fuSaFaultMask .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      fuSaFaultMaskIndex - The FuSa fault mask
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref fuSaFaultMask
 *
 */
uint8_t rfeCfg_monitorAndSafety_getFuSaFaultMask(const uint8_t *pConfig, rfe_fuSaFaultMaskIndex_t fuSaFaultMaskIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function sets the \ref injectTestTone .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      injectTestToneMode - \ref rfeCfg_param_monitorAndSafety_injectTestTone_e
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 */
void rfeCfg_monitorAndSafety_setInjectTestTone(uint8_t* pConfig, rfeSwBist_InjectToneMode_t injectTestToneMode, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref injectTestTone .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref rfeCfg_param_monitorAndSafety_injectTestTone_e.
 */
uint8_t rfeCfg_monitorAndSafety_getInjectTestTone(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function updates values, for any of the following parameters, in the in-memory blob:
 *        - \ref zeroHrRefForRxPhaseDiffLna
 *        - \ref rxPhaseDiffLnaThresholdTolerance
 *        - \ref zeroHourReferenceForRxGainDiffLna
 *        - \ref rxGainDiffLnaThresholdTolerance
 *        - \ref zeroHrRefForRxPhaseDiffMixer
 *        - \ref rxPhaseDiffMixerThresholdTolerance
 *        - \ref zeroHourReferenceForRxGainDiffMixer
 *        - \ref rxGainDiffMixerThresholdTolerance
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      param   - The BIST parameter to set, like \ref rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx2_e
 * \param [in]      value   - the new value
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 */
void rfeCfg_monitorAndSafety_setBist(uint8_t* pConfig, rfeCfg_param_t param, int16_t value, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the following values, from the in-memory blob:
 *        - \ref zeroHrRefForRxPhaseDiffLna
 *        - \ref rxPhaseDiffLnaThresholdTolerance
 *        - \ref zeroHourReferenceForRxGainDiffLna
 *        - \ref rxGainDiffLnaThresholdTolerance
 *        - \ref zeroHrRefForRxPhaseDiffMixer
 *        - \ref rxPhaseDiffMixerThresholdTolerance
 *        - \ref zeroHourReferenceForRxGainDiffMixer
 *        - \ref rxGainDiffMixerThresholdTolerance
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      param   - The BIST parameter to get, like \ref rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx2_e
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return the current value for the required parameter
 *
 */
int16_t rfeCfg_monitorAndSafety_getBist(const uint8_t* pConfig, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref bistInterval .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *
 * \return \ref bistInterval
 *
 */
static inline uint8_t rfeCfg_radarCycle_getBistInterval(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readB(pConfig, rfeCfg_section_radarCycle_e, rfeCfg_param_radarCycle_bistInterval_e, rfe___error___pointer);
}

/**
 * \brief  This function gets the \ref chirpFrequencyDriftSteps.
 *
 * \param [in]      	pConfig - Pointer to the Configuration Data Memory.
 * \param [in]          chirpProfileIndex - The chirp profile config index.
 * \param [in, out]     rfe___error___pointer - fault handling parameter:
 *                      On success *rfe___error___pointer == rfe_error_none_e is true,
 *                      On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return The Chirp Frequency Drift.
 *
 */
int32_t rfeCfg_chirpSequence_getChirpFrequencyDriftSteps(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * \brief   Get the \ref txPhaseRotation_ddma
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  Ddma enable/disable
 */
uint8_t rfeCfg_sequence_getPhaseRotationDdmaMode(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * \brief   Get the current \ref txPhaseRotation_ddma_tx1_mode
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx final pc gen mode
 */
uint8_t rfeCfg_sequence_getFinalPcGenMode(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * \brief   Get the current \ref txPhaseRotation_ddma_tx
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  use_ddma
 */
uint8_t rfeCfg_sequence_getPhaseRotationTxUseDdma(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * \brief   Get the current \ref txPhaseRotation_ddma_tx1_init
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Ddma_init_phase
 */
uint8_t rfeCfg_sequence_getTxDdmaInitPhase(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * \brief   Get the current \ref txPhaseRotation_ddma_tx1_update
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Ddma_update_phase
 */
uint8_t rfeCfg_sequence_getTxDdmaUpdatePhase(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref checkBbd_loi .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *
 * \return Loi BBD parameters
 *
 */
uint8_t rfeCfg_monitorAndSafety_getLoiBBD(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function sets the \ref checkBbd_loi .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      val     - The new value
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *
 */
void rfeCfg_monitorAndSafety_setLoiBBD(const uint8_t* pConfig, uint8_t val, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref checkBbd_tx .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *
 * \return Loi BBD parameters
 *
 */
uint8_t rfeCfg_monitorAndSafety_getTxBBD(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref checkBbd_rx .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *
 * \return Loi BBD parameters
 *
 */
uint8_t rfeCfg_monitorAndSafety_getRxBBD(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref rxSaturationThreshold .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      rxStage - The Rx stage.
 * \param [in]      rxIndex - The Rx index
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return rxSaturationThreshold
 *
 */
uint8_t rfeCfg_monitorAndSafety_getRxSaturationThresholdStage(const uint8_t *pConfig, uint8_t rxStage, uint8_t rxIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref rxSaturationCountLimit.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      rxStage - The Rx stage.
 * \param [in]      rxIndex - The Rx index
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx1_e or similar
 *
 */
uint16_t rfeCfg_monitorAndSafety_getRxSaturationCountLimitStage(const uint8_t *pConfig, uint8_t rxStage, uint8_t rxIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref rxSatCountResetEveryChirpSequence .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref rfe_paramUpdate_monitorAndSafety_rxSatCountResetEveryChirpSequence_e
 *
 */
bool rfeCfg_monitorAndSafety_getRxSatCountResetEveryChirpSequence(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref adcClippingCountResetEveryChirpSequence .
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref rfe_paramUpdate_monitorAndSafety_adcClippingCountResetEveryChirpSequence_e
 *
 */
bool rfeCfg_monitorAndSafety_getAdcClippingCountResetEveryChirpSequence(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer);
/**
 * \brief   Set a new value for \ref txPhaseRotation_ddma_tx1_update for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   tx                          = the tx index
 * \param   txDdmaUpdatePhase           = the new value for Tx Ddma_update_phase
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_sequence_setTxDdmaUpdatePhase(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_phaseRotation_t txDdmaUpdatePhase,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief  Maps chirp sequence config index to the corresponding section.
 *
 * \param [in]          chirpSequenceIndex    - The chirp sequence config index.
 * \param [in, out]     rfe___error___pointer - pointer to the error status
 *
 * \return The corresponding section.
 *
 */
rfeCfg_section_t rfeCfg_util_chirpSequenceConfigIndex(rfe_chirpSequenceIndex_t chirpSequenceIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref txPhaseRotation_ddma_tx1_init for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   tx                          = the tx index
 * \param   txDdmaInitPhase             = the new value for Tx Ddma_init_phase
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_sequence_setTxDdmaInitPhase(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_phaseRotation_t txDdmaInitPhase,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set \ref txPhaseRotation_ddma for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   enable                      = enable/disable
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_sequence_setPhaseRotationDdmaMode(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t enable, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Set a new value for \ref txPhaseRotation_ddma_tx1_mode for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   tx                          = the tx index
 * \param   txFinalPcGenMode            = the new value for Tx final pc gen mode
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_sequence_setTxFinalPcGenMode(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_PRPCGenMode_e txFinalPcGenMode,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the \ref txCalibration_thresholdHigh for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
uint16_t rfeCfg_sequence_getTxCalibrationThresholdHigh(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Get the \ref txCalibration_thresholdLow for the selected sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
uint16_t rfeCfg_sequence_getTxCalibrationThresholdLow(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief  Maps radar cycle chirp sequence index to the corresponding param.
 *
 * \param [in]          index                                The radar cycle chirp sequence index.
 * \param [in, out]     rfe___error___pointer                Error handling parameter:
 *
 * \return The corresponding param.
 *
 */
rfeCfg_param_t rfeCfg_util_radarCycleChirpSequence(uint8_t index, rfe_error_t* rfe___error___pointer);

/**
 * \brief  Maps chirp profile sequence index to the corresponding param.
 *
 * \param [in]          index                                The chirp profile sequence index.
 * \param [in, out]     rfe___error___pointer                Error handling parameter:
 *
 * \return The corresponding param.
 *
 */
rfeCfg_param_t rfeCfg_util_chirpProfileSequence(uint8_t index, rfe_error_t* rfe___error___pointer);

/**
 * \brief  Writes a configuration item.
 *
 * \param [in]          chirpProfileIndex                   The chirp profile index.
 * \param [in, out]     rfe___error___pointer               Error handling parameter:
 *
 * \return The corresponding section.
 *
 */
rfeCfg_section_t rfeCfg_util_chirpProfileIndex(rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function sets the \ref frequencyForBist .
 *
 * \param [in]      pConfig                                 Pointer to the Configuration Data Memory.
 * \param [in]      frequencyForBist                        Configuration value for \ref frequencyForBist
 * \param [in,out]  rfe___error___pointer                   Error handling parameter.
 *
 */
void rfeCfg_monitorAndSafety_setFrequencyForBist(uint8_t *pConfig, uint32_t frequencyForBist, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref frequencyForBist .
 *
 * \param [in]      pConfig                                 Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer                   Error handling parameter.
 *
 * \return \ref frequencyForBist.
 *
 */
uint32_t rfeCfg_monitorAndSafety_getFrequencyForBist(const uint8_t *pConfig, rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 * \brief  Check the blob version compatibility with the API version
 *
 * \param [in]          configPtr                   Pointer to the blob
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *
 */
void rfeCfg_CheckBlobCompatibility(void* configPtr, volatile rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the \ref pdcDecimationFilter stored in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer       Error handling parameter:
 *
 * \return pdcDecimationFilter
 *
 */
bool rfeCfg_general_getPdcBitwidth(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * \brief This function computes and writes the CRC for the existing blob configuration.
 *
 * \param [in]      pConfig   - Pointer to the blob buffer.
 *                  len       - the required length in bytes
 *
 */
void rfeCfg_calcAndWriteCrc(void* pConfig, uint32_t len);

/**
 * @}
 */


#ifdef __cplusplus
}
#endif

#endif /* RFE_BLOB_ACCESS_H */
