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

#ifndef RFE_SW_STATUS_TEF82XX_H_
#define RFE_SW_STATUS_TEF82XX_H_

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include "rfe_error.h"
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_tef82xx_voltage.h"
#include "rfeSwFuSaMngr.h"

/******************************************************************************
 *                              DEFINES
 *****************************************************************************/
#define FULL_STATUS_RESPONSE_SIZE	16	//number of words reported by BC
#define SW_ERROR_COUNT              15   //number of sw errors exposed to customers via config xml file, 14 FUSA sw errors plus 1 generic sw error
/******************************************************************************
 *                              TYPES
 *****************************************************************************/
/**
* @brief        TEF82XX device status fields
* @details      To use these device specific parameters when the status is read they must be linked to the
*               rfeStatusReport_t field. The driver will read the appropriate device
*               registers and will fill the fields of this structure with the relevant information.
*
* @note         Knowledge of the TEF82XX is needed to interpret these values
*/
typedef struct
{
    /** Fields for reported Front End state */
    union
	{
    	struct
		{
		    /** Device TX Temperatures */
		    float32_t txTemperature[RFE_MAX_TX_CHANNELS];	/**< Array of TX temperatures in Kelvin. Disabled
		     	 	 	 	 	 	 	 	 	 	 	 	 	 	* Disabled TX modules will return a value of 0	 */
		    float32_t chirpIpTemperature;	/**< Chirp IP temperature in Kelvin */
		}statusResponse;
	}fildsReported;
} rfeStatusReport_t;

/**
* @brief     sw error index for all sw errros from FUSA fault list
*/
typedef enum
{
    rfe_sw_fuSaFault_sr31_bist_lna_gaindiff_index_e = 0U,
	rfe_sw_fuSaFault_sr31_bist_lna_phasediff_index_e,
	rfe_sw_fuSaFault_sr31_bist_mixer_gaindiff_index_e,
	rfe_sw_fuSaFault_sr31_bist_mixer_phasediff_index_e,
	rfe_sw_fuSaFault_sr44_cafc_integrity_level_index_e,
	rfe_sw_fuSaFault_sr44_cafc_integrity_unlock_index_e,
	rfe_sw_fuSaFault_sr44_cafc_integrity_index_e,
	rfe_sw_fuSaFault_sr70_tx_integrity_index_e,
	rfe_sw_fuSaFault_sr72_tx_pr_cal_index_e,
	rfe_sw_fuSaFault_sr72_tx1_pr_cal_index_e,
	rfe_sw_fuSaFault_sr72_tx2_pr_cal_index_e,
	rfe_sw_fuSaFault_sr72_tx3_pr_cal_index_e,
	rfe_sw_fuSaFault_sr14_disable_lb_toggle_test_index_e,
	rfe_sw_fuSaFault_sr13_input_mode_toggle_test_index_e,
	rfe_sw_generic_index_e
} rfe_sw_fusaFault_index_t;


/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

/**
 * \brief This function get the status of the TEF82XX.
 *
 * \details This function get the status of the frontend
 *
 *
 * \pre NIL
 *
 * \param out       devStatus  - status report
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void rfeSwStatusTef82xxDeviceStatus(rfeStatusReport_t* pDevStatus, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the fusa fault status of front end
 *
 * \details This function gets the fusa fault status from list rfe_fuSaFault_t of front end 
 *
 *
 * \pre NIL
 *
 * \param [in,out]  pFusaFaults  - Pointer to an array, where this function will
 *                  store the list of all fusa faults. The size of this array must be #RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void rfeFusaStatusTef82xxDeviceStatus( uint8_t *pFusaFaults, rfe_error_t* rfe___error___pointer );

/**
 * \brief This function sets the sw related fusa faults from list #rfe_fuSaFault_t.
 *
 * \details This function sets the sw related fusa faults from list #rfe_fuSaFault_t. Array #swErrorStatus will be updated in this function. 
 *
 *
 * \pre NIL
 *
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void setSwError( rfe_error_t* rfe___error___pointer );

/**
 * \brief This function gets the BCD module registers dump
 *
 * \details
 *
 *
 * \pre NIL
 *
 *
 * \param [in]  fe - front end index
 * \param [in]  moduleId - module Id
 * \param [in]  regindex - start index of register to read
 *
 * \param [out] - regDump pointer to registers dump array
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return register count
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
uint8_t GetBcdModuleRegistersDump(uint8_t fe, uint8_t moduleId, uint8_t regindex, uint32_t* regDump, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function reads the ATB voltages measured by the Front-End
 *
 * \param [in]  feIdx - front end index
 * \param [in]  voltagesPtr - pointer to the voltages structure
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return voltages count
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
uint32_t getAtbVoltageMeasurements(uint8_t feIdx, rfe_tef82xxVoltages_t* voltagesPtr, rfe_error_t* rfe___error___pointer);


#if defined(TEF82XX_STATUS_DEBUG_HELPER) && defined(RFE_DEBUG)
void rfeSwStatusTef82xxDebugHelperDeviceStatus(rfeStatusReport_t* devStatus, uint32_t fe,
		rfe_error_t* rfe___error___pointer);
#endif

#endif /* RFE_SW_STATUS_TEF82XX_H_ */
