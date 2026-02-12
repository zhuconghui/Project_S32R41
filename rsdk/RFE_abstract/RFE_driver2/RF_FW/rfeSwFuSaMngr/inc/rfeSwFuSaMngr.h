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

#ifndef RFE_SW_FUSA_MNGR_H
#define RFE_SW_FUSA_MNGR_H


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_error.h"
#include "rfe_types.h"


/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/**
 * This struct contains the HW error codes returned by rfeSwMainFsm_getFuSaFaults().
 */
typedef struct
{
    uint8_t fuSaR1FaultCount[rfe_fusaFault_R1_size_e];
    uint8_t fuSaR1R2FaultStatus[RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT];
    uint16_t r1FaultPromotedToR2;
    rfe_radarCycleCount_t radaCycleCount;
} rfeSwFuSaMngr_fuSaFault_t;

/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/
/**
 * \brief This function update FUSA fault statistic for all front ends
 *
 * \details	This function do not change the current front end
 *
 *
 * \pre NIL
 *
 *
 * \param [in]
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void rfeFusaFaultStatisticsUpdateTef82xx(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function reset FUSA fault statisticfor all front ends
 *
 * \details This function do not change the current front end
 *
 *
 * \pre NIL
 *
 *
 * \param [in]
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void rfeFusaFaultStatisticsResetTef82xx(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function get actual FUSA fault statistic for current front end
 *
 * \details This function do not change the current front end
 *
 *
 * \pre NIL
 *
 *
 * \param [in]
 * \param [out] -   pFuSaFaults pointer to fusa statistic structure
 *
 *
 * \return
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void rfeGetFusaFaultStatisticsTef82xx(rfeSwFuSaMngr_fuSaFault_t *pFuSaFaults);
    
#endif // !RFE_SW_FUSA_MNGR_H

