/*
    Copyright 2023 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only be
    used strictly in accordance with the applicable license terms. By expressly
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be
    bound by the applicable license terms, then you may not retain, install,
    activate or otherwise use the software.
 */

/*
 * rfeSwBist.h
 *
 */

/*====================================================================================================================
 *   Project              : RFE_SW
 *   Platform             : S32R41-TEF82xx
 ====================================================================================================================*/
#ifndef RFE_SW_BIST_H
#define RFE_SW_BIST_H

/*====================================================================================================================
 *                              INCLUDES
 ====================================================================================================================*/
#include <math.h>
#include "rfe_error.h"
#include "rfe_types.h"
#include "rfe_cfg_blob.h"
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_sw_driver_state.h"

// TEF82xx LLD
#include "bc_err.h"

/*====================================================================================================================
 *                                      DEFINES
 ====================================================================================================================*/
/**
* @brief        Number of RX antennas for RFBist testing
*/
#define RSDK_TEF82XX_RFBIST_NO_ANTENNAS 4U
/**
* @brief         This define converts data type of configuration parameter from int16 to float.
*/
#define BIST_PHASE_GAIN_INT16_TO_FLOAT(x)  ((float32_t)(x) / 10.0f)
/**
* @brief         This define converts data type of configuration parameter float32_t to int16.
*/
#define BIST_PHASE_GAIN_FLOAT_TO_INT16(x)   ((int16_t)lroundf(((x) * 10.0f)))
/*====================================================================================================================
 *                                      TYPES
 ====================================================================================================================*/
/**
 * \struct rfeSwBist_rxBistReferenceData_t
 * \brief Struct to hold value of RX Bist reference data
 *
 * refMag  - Array of reference signal magnitudes difference vs 1st RX for all RX channels measured in [dB] for LNA and mixer input.
 * refPh   - Array of reference signal phase difference vs 1st RX for all RX channels measured in [rad] for LNA and mixer input.
 *
 */
typedef struct
{
    float32_t   refMag[RFE_RX_BIST_COMBINATIONS][TEF82XX_RFBIST_TESTS];
    float32_t   refPh[RFE_RX_BIST_COMBINATIONS][TEF82XX_RFBIST_TESTS];
} rfeSwBist_rxBistReferenceData_t;

/**
 * \struct rfeSwBist_rxBistParam_t
 * \brief Structure to hold the RX BIST configuration parameters.
 *
 * \details Structure to hold the RX BIST configuration parameters extracted from the rfeConfig.
 */
typedef struct {
    /** RX BIST phase threshold defined in Config blob*/
    float32_t rxBistPhaseThreshold[TEF82XX_RFBIST_TESTS];
    /** RX BIST gain threshold defined in Config blob*/
    float32_t rxBistGainThreshold[TEF82XX_RFBIST_TESTS];
    /** Zero hour data to be fetched from rfeConfig*/
    rfeSwBist_rxBistReferenceData_t zeroDayMeasurementBuff;
    /** RX BIST tone injection setting defined in Config blob*/
    rfeSwBist_InjectToneMode_t rxBistInjectToneMode;
    /** RX BIST execution and check active*/
    bool bistActive;    
} rfeSwBist_rxBistParam_t;

/*====================================================================================================================
 *                                       GLOBALS
 ====================================================================================================================*/

/*====================================================================================================================
 *                                       FUNCTIONS
====================================================================================================================*/
/**
 * \brief   Initialize the RFE RF Bist shared mem addresses.
 *
 * \details 
 * 
 * \pre Must be called before the start of FSM
 *
 *
 * \param [in] rfeRfBistBufferAddress - the location for the CSI2 data buffers.
 *
 * \param [in] rfeRfBistStatusAddress - the location for the CSI2 status.
 *
 * \post  NIL
 *
 * \return NIL
 */
void rfeSwBist_setSharedAddresses(uint32_t rfeRfBistBufferAddress);

/**
 * \brief Function used for the TEF82xx RX Bist initial config.
 *
 * \details This function performs:
 *      Static configuration
 *      Functional configuration (profile based settings) 
 *              Profile_8 is reserved for RFBIST
 *              MIPI CSI2 virtual channel 3 for data transfer
 *      Set the BIST sub-band in case of single or leader frontend. 
 * This function is called by the TEF82xx configuration function.
 *
 * \pre NIL
 * 
 * \param [in]      pDrvState  - pointer to structure containing TEF82xx persistent config data.
 * \param [in]      pRfeConfig - Pointer to the Configuration Data Memory (blob).
 * \param [in]      chirpSequence - current chirp sequence index for ADC and VCO settings
 * \param [in,out]  rfe___error___pointer - Error handling parameter
 * 
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwBist_initialConfiguration(rfeDriverPersistentMem_t *const pDrvState, 
                                    uint8_t *pRfeConfig,
		                            rfe_chirpSequenceIndex_t chirpSequence,
                                    rfe_error_t* rfe___error___pointer);

/**
 * \brief This function is the main SwBist api call
 *
 * \details This function sets the Fusa error related error codes in case of BIST failure.
 *
 * \param [in,out]   rfe___error___pointer - Error handling parameter.
 */ 
void rfeSwBist_bist(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets zero hour reference data RX bist.
 *
 * \details This function returns zero hour reference data for RX bist.
 * This function is called by the rfeCmdServerDispatcher.
 *
 * \param [in]         zeroHourData  - pointer to the buffer for store reference data.
 * \param [in,out]     rfe___error___pointer - Error handling parameter.
 * 
 * TODO - reference data for Lna and Mixer tests
 */
void rfeSwBist_getBistZeroHourReferenceData(rfeSwBist_rxBistReferenceData_t *zeroHourData,
                                            rfe_error_t* rfe___error___pointer);

/**
 * \brief This function is distributes the RX BIST config parameters to passed structures.
 *
 * \param [in]      pDrvState  - pointer to structure containing TEF82xx persistent config data.
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwBist_readBistConfig(rfeDriverPersistentMem_t* pDrvState,
                              rfe_error_t* rfe___error___pointer);

/**
 * \brief This function return the bistParams array.
 *
 * \param [in]
 * \param [in,out]
 *
 * \return pointer of bistParams array
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfeSwBist_rxBistParam_t* rfeSwBist_getBistParamsAddress(void);


#endif // !RFE_SW_BIST_H
