/*
    Copyright 2021, 2023-2024 NXP  
    NXP Confidential. This software is owned or controlled by NXP and may only be 
    used strictly in accordance with the applicable license terms. By expressly 
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be 
    bound by the applicable license terms, then you may not retain, install, 
    activate or otherwise use the software.
 */

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_SW_CALIBRATION_DURATION_H
#define RFE_SW_CALIBRATION_DURATION_H


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_error.h"


/******************************************************************************
 *                              TYPES
 *****************************************************************************/

#ifdef RFE_DEBUG
/**
 * Maximal duration of one profile-independent recalibration, need extra 350 if enable PR
 */
#define RFE_SW_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS      ( 2500ul * RFE_TIME_TICKS_PER_US )

/**
 * Maximal duration of one profile-dependent recalibration
 */
#define RFE_SW_CALIBRATION_MAX_PROFILE_DEPENDENT_DURATION_TICKS        ( 1250ul * RFE_TIME_TICKS_PER_US )
#else // RFE_RELEASE
/**
 * Maximal duration of one profile-independent recalibration 1820 us
 */
#define RFE_SW_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS      ( ( 1820ul + 250ul ) * RFE_TIME_TICKS_PER_US )

/**
 * Maximal duration of one profile-dependent recalibration 755 us
 */
#define RFE_SW_CALIBRATION_MAX_PROFILE_DEPENDENT_DURATION_TICKS        ( ( 755ul + 250ul + 750ul ) * RFE_TIME_TICKS_PER_US )
#endif


/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

/**
 * \brief This function calculates the recalibration duration of the given \p chirpSequenceIndex.
 * 
 * \details This function is used by the MainFSM to define the radar cycle timing schedule.
 *
 * \pre NIL
 *
 * \param [in]      pRfeConfig - Pointer to configuration blob
 * \param [in]      chirpSequenceIndex - Index of the chirp sequence, for which to
 *                  calculate the recalibration time.
 * \param [in,out]  rfe_error_t* rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return  recalibration duration in (40MHz) ticks
 *
 * \post NIL
 *
 * \ingroup NIL
 */
uint32_t rfeSwCalibration_calcRecalibrationDuration(
    const uint8_t* pRfeConfig,
    uint8_t chirpSequenceIndex,
    rfe_error_t* rfe___error___pointer
);

#ifdef NXP_INTERNAL_CALIBRATION_CALCULATION_MODE
/**
 * \brief This function calculates the profile dependent Calibration duration of the given 
 *        \p chirpSequenceIndex.
 * 
 * \details This function is used internally to get detailed Calibration timings.
 *
 * \pre NIL
 *
 * \param [in]      chirpSequenceIndex - Index of the chirp sequence, for which to
 *                  calculate the recalibration time.
 * \param [in,out]  rfe_error_t* rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return  recalibration duration in (40MHz) ticks
 *
 * \post NIL
 *
 * \ingroup NIL
 */
uint32_t rfeSwCalibration_calcProfileDependentCalibrationDuration(
    uint8_t chirpSequenceIndex,
    rfe_error_t* rfe___error___pointer
);

/**
 * \brief This function calculates the profile independent Calibration duration of the given 
 *        \p chirpSequenceIndex.
 * 
 * \details This function is used internally to get detailed Calibration timings.
 *
 * \pre NIL
 *
 * \param [in]      chirpSequenceIndex - Index of the chirp sequence, for which to
 *                  calculate the recalibration time.
 * \param [in,out]  rfe_error_t* rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return  recalibration duration in (40MHz) ticks
 *
 * \post NIL
 *
 * \ingroup NIL
 */
uint32_t rfeSwCalibration_calcProfileIndependentCalibrationDuration(
    uint8_t chirpSequenceIndex,
    rfe_error_t* rfe___error___pointer
);

#endif  //NXP_INTERNAL_CALIBRATION_CALCULATION_MODE
#endif // !RFE_SW_CALIBRATION_DURATION_H

