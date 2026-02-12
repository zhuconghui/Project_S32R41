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

#ifndef RFESWCALIBRATION_INC_RFE_SW_CALIB_TEF82XX_H_
#define RFESWCALIBRATION_INC_RFE_SW_CALIB_TEF82XX_H_

/*==================================================================================================
 *                              INCLUDES
 ==================================================================================================*/
#include <stdbool.h>
#include "rfe_error.h"
/*==================================================================================================
 *                              TYPES
 ==================================================================================================*/

/*==================================================================================================
 *                              DEFINES
 ==================================================================================================*/


/**
* @brief        Recommended time-out for TX Phase Rotator Gain calibration (uS)
*/
#define RSDK_TEF82XX_TXCAL_PR_TIMEOUT 120U

/**
* @brief        Recommended calibration time-out for TX variable gain amplifier (uS)
*/
#define RSDK_TEF82XX_TXCAL_VGA_TIMEOUT 120U

/**
* @brief        Recommended time-out for TX peak-power detector calibration (uS)
*/
#define RSDK_TEF82XX_TXCAL_PPD_OFFSET_TIMEOUT 92U

/**
* @brief        Recommended time-out for TX Phase Rotator Phase calibration (uS)
*/
#define RSDK_TEF82XX_TXCAL_PR_PHASE_TIMEOUT 180U

/**
* @brief        Recommended time-out for TX output power calibration (uS)
*/
#define RSDK_TEF82XX_TXCAL_POUT_TIMEOUT 70U


/*==================================================================================================
 *                              FUNCTIONS
 ==================================================================================================*/

/**
 * \brief This function performs the calibration of the TEF82XX frontends.
 *
 * \param [in]      currentChirpSequenceIndex - calibration is performed based on this chirp sequence 
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 */
void rfeSwCalibTef82xxCalibration(uint8_t currentChirpSequenceIndexPar, rfe_error_t *rfe___error___pointer);

/**
 * \brief Enable or disable ADC background calibration
 *
 * \param [in]      flag - TRUE - enable; FALSE - disable
 *
 * \return 		    BC_ERRCODE - TEF82xx error code
 *
 */
BC_ERRCODE AdcBkgrdCalibEnable(BOOL flag);

/**
 * \brief           Check if ADC was calibrated successfully and perform recovery if not
 *
 * \param [in,out]	rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 * 
 * \return 		    true - if ADC background calibration failed ; false - if OK
 * 
 */
bool CheckAdcCalibration(rfe_error_t* rfe___error___pointer);

#endif /* RFESWCALIBRATION_INC_RFE_SW_CALIB_TEF82XX_H_ */
