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

#ifndef RFE_SW_DRIVER_STATE_H_
#define RFE_SW_DRIVER_STATE_H_

/*==================================================================================================
 *                              INCLUDES
 ==================================================================================================*/
#include "rfe_sw_cfg_tef82xx.h"
#include "rfeApiFsm.h"
#include "rfe_error.h"
#include "rfe_sw_status_tef82xx.h"
#include "rfe_types.h"
#include "rfe_cfg_blob.h"
#include "rfeSwCfgMngr.h"
#include "rfeSwFuSaMngr.h"

/*==================================================================================================
 *                              DEFINES
 ==================================================================================================*/

/*==================================================================================================
 *                              TYPES
 ==================================================================================================*/
typedef struct
{
    // Needed by FSM
    rfeRadarCycleParams_t       radarCycleParams;
    rfeRadarGeneral_t           radarGeneral;
    // Needed by calibration
    uint8_t                     meanCenterFreqProf;                   // Profile used for mean center frequency calculation. Init in Profile config.
    SYS_ProfChirpTiming_t       meanCenterFreqProfTiming;             // Profile timing used for mean center frequency calculation. Init in Profile config.
	SYS_ProfChirpFreq_t         meanCenterFreqProfFreq;               // Profile frequency used for mean center frequency calculation. Init in Profile config.
	SYS_ProfChirpFreq_t         profChirpFreqRFBIST;                  // Profile frequency used for BIST. Init in Profile config.
	float32_t                   txChannelPower[RFE_MAX_CHIRP_PROFILES][RFE_MAX_TX_CHANNELS]; // Tx channel power in dBm. Init in Profile config.
    uint32_t                    txChannelEnable[RFE_MAX_CHIRP_PROFILES];            // Tx channel enable. Init in Profile config.
    uint8_t						txCurrGain[RFE_MAX_CHIRP_PROFILES][RFE_MAX_TX_CHANNELS]; // Tx channel gain current. Update after each calibrate.
    BOOL						firstCalib;
    // Needed by BBD
    BOOL 						loiBbdEn;
    BOOL 						LoOutSensitivity;
    BOOL 						LoOutGrounded;
    BOOL 						LoISensitivity;
    BOOL 						LoIGrounded;
    uint8_t	                    chirpPowerSavingEnabled;              // power saving mode control (Chirp Power Mode, CPM)
    uint8_t						txPhaseErrorWa1Enabled;				  // TX Phase error due to load imbalance on the LOI, depends on enabled TX channels
    uint8_t						enableTxIntegrityCheck;
    BOOL						sequencesUsesPhaseRotator;			  // = TRUE if one of the chirp sequences uses the phase rotator
    BOOL						enableReduceTransmisionForVGACalib;
    BOOL						enableIQPinsTogleTest;				  // This flag enable(TRUE)/disable(FALSE) I and Q TEF82xx toggle test
} tef82xxPersistentMem_t;

typedef struct
{
    uint32_t                    frontendId;                           // Identifier used to identify frontend
    rfeFrontendMode_t           frontendMode;                         // Indicates the frontend mode used (stand-alone or cascading master/slave) 
    uint8_t                     rfeConfig[RFE_CFG_SIZE_TOTAL];        // Config data (blob)
    tef82xxPersistentMem_t      tef82xxDrvState;                      // TEF82xx global data
	uint8_t                     txBuff[RFE_SPI_TX_BUFF_SIZE];         // SPI TX buffer
	uint8_t                     rxBuff[RFE_SPI_RX_BUFF_SIZE];         // SPI RX buffer
    rfeStatusReport_t           devStatus;                            // TEF82XX device status fields
    uint8_t 					configured;                           // Flag for signaling if TEF82xx is configured 
    uint32_t                    uniqueId;
    rfeSwCfgMngr_update_t 		updatesCfg[RFE_UPDATE_COUNT_MAX];	  // Update config array
    uint8_t 					updateCountCfg;						  // Number of updates stored in updatesCfg
    uint8_t						csi2TxClkNonContinuousMode;			  // Flag for signalling the TEF82xx CSI2 CLK is set to non-continuous mode
    rfeSwFuSaMngr_fuSaFault_t	fusaStatistic;						  // FUSA statistic structure
} rfeDriverPersistentMem_t;

typedef struct
{
	rfeDriverPersistentMem_t     driverPersistentMem[RFE_MAX_SUPPORTED_DEVICES];
     /* Be very careful with this state variable, if it's modified during a call
     * to the driver it can lead to operation being executed on a different frontend. */
    uint32_t                     frontendId;                          // Curent selected fronted   
    uint8_t                      numConnectedFrontends;               // Number of connected frontends 
    rfeFrontEnd_Configuration_t  feConfigType;                        // Configuration type (single mode or cascaded)
} rfeGlobalPersistentMem_t;

/*==================================================================================================
 *                              FUNCTIONS
 ==================================================================================================*/

/**
 * \brief This function get the driver state pointer.
 *
 * \details This function get the driver state pointer of the current frontend
 *
 * \return frontend driver state pointer
 *
 */
rfeDriverPersistentMem_t *RfeDrvStateGet(void);

/**
 * \brief This function get the frontendId driver state pointer for a certain id.
 *
 *
 * \param [in]  frontendId - frontend id
 *
 * \return frontend driver state pointer
 *
 */
rfeDriverPersistentMem_t *RfeDrvStateWithIdGet(uint32_t frontendId);

/**
 * \brief This function init driver state structure.
 *
 * \param [in]	pDriverState - driver state pointer
 *
 */
void RfeDrvStateDefaultInit(rfeDriverPersistentMem_t *const pDriverState);

/**
 * \brief This function set current frontend id.
 *
 * \param [in]		feId - frontend id
 *
 * \return NIL
 */
void RfeDrvStateFrontendIdSet(uint32_t feId);

/**
 * \brief This function get the current selected frontend.
 *
 * \return frontend id
 */
uint8_t RfeDrvStateFrontendIdGet(void);

/**
 * \brief This function set the number of connected frontends.
 *
 * \pre NIL
 *
 * \param [in]      noFe - number of connected frontends
 *
 * \return NIL
 */
void RfeDrvStateNoFrontendsSet(uint8_t nbrFe);

/**
 * \brief This function returns the number of connected frontends.
 *
 * \pre NIL
 *
 * \return number of connected frontends
 */
uint8_t RfeDrvStateNoFrontendsGet(void);

/**
 * \brief This function set the frontends configuration type.
 *
 * \details Configuration can be: Single mode or Cascaded mode
 * 
 * \pre NIL
 *
 * \param [in]      feConfigType - rfeFrontEnd_Single_e or rfeFrontEnd_Cascaded_e
 *
 * \return NIL
 */
void RfeDrvStateConfigurationSet(rfeFrontEnd_Configuration_t  feConfigType);

/**
 * \brief This function returns the frontends configuration type.
 *
 * \pre NIL
 *
 * \return frontends configuration type
 */
rfeFrontEnd_Configuration_t RfeDrvStateConfigurationGet(void);

#endif /* RFE_SW_DRIVER_STATE_H_ */
