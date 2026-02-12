/*
    Copyright 2024 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only be
    used strictly in accordance with the applicable license terms. By expressly
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be
    bound by the applicable license terms, then you may not retain, install,
    activate or otherwise use the software.
 */

/*
 * rfeSwUtils.h
 *
 */

/*====================================================================================================================
 *   Project              : RFE_SW
 *   Platform             : S32R41-TEF82xx
 ====================================================================================================================*/
#ifndef RFE_SW_UTILS_H
#define RFE_SW_UTILS_H

/*====================================================================================================================
 *                              INCLUDES
 ====================================================================================================================*/
#include <stdint.h>
#include "typedefs.h"
#include "rfe_error.h"
#include "rfe_types.h"
/*====================================================================================================================
 *                                      DEFINES
 ====================================================================================================================*/

/*====================================================================================================================
 *                                      TYPES
 ====================================================================================================================*/

/*====================================================================================================================
 *                                       GLOBALS
 ====================================================================================================================*/

/*====================================================================================================================
 *                                       FUNCTIONS
====================================================================================================================*/
/**
 * \brief This function set the active TEF82xx
 *
 * \details Set the global fe ID and in LLD the active SPI for communication.
 *
 * \pre NIL
 *
 * \param [in]  feIdx - front end ID
 *
 * \return NIL
 *
 * \post NIL
 */
void rfeSwUtils_SelectFe(uint8_t feIdx);

/**
 * \brief This function packs the rfe error and frontend ID in the same value
 *
 * \details The feIdx value is using bits 8,9 .. 15.
 *
 * \pre NIL
 *
 * \param [in]  rfeError - actual error
 * \param [in]  feIdx    - front end ID
 *
 * \return - error including fe id
 *
 * \post NIL
 */
rfe_error_t rfeSwUtils_SetError(rfe_error_t rfeError, uint8_t feIdx);

/**
 * \brief This function maps read bist interval value from blob in rfe_bistInterval_t enum
 *
 * \param [in]  interval - blob bist interval value
 *
 * \return - rfe_bistInterval_t enum
 *
 * \post NIL
 */
rfe_bistInterval_t rfeSwUtils_BistIntervalMapper(uint8_t interval);

/**
 * \brief This function maps read bist inject tone mode value from blob in rfeSwBist_InjectToneMode_t enum
 *
 * \param [in]  injectMode - blob bist inject tone mode
 *
 * \return - rfeSwBist_InjectToneMode_t enum
 *
 * \post NIL
 */
rfeSwBist_InjectToneMode_t rfeSwUtils_BistInjectToneMode(uint8_t injectMode);

/**
 * \brief This function maps read sampling frequency value from blob in rfe_effectiveSamplingFrequency_t enum
 *
 * \param [in]  samplingFreq - sampling frequency value
 *
 * \return - rfe_effectiveSamplingFrequency_t enum
 *
 * \post NIL
 */
rfe_effectiveSamplingFrequency_t rfeSwUtils_SamplingFrequency(uint8_t samplingFreq);

/**
 * \brief This function converts radians in degrees
 *
 * \param [in]  radians
 *
 * \return - degrees
 *
 * \post NIL
 */
float32_t rfeSwUtils_radians2degrees(float32_t radians);

/**
 * \brief This function converts degrees in radians
 *
 * \param [in] degrees
 *
 * \return - radians
 *
 * \post NIL
 */
float32_t rfeSwUtils_degrees2radians(float32_t degrees);

#endif // !RFE_SW_BIST_H
