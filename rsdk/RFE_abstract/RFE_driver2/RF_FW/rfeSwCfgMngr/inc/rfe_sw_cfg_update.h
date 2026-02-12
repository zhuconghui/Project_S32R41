/**************************************************************************************************
* Copyright 2023 - 2024 NXP
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

#ifndef RFE_SW_CFG_UPDATE_TEF82XX_H_
#define RFE_SW_CFG_UPDATE_TEF82XX_H_

/*==================================================================================================
 *                                          INCLUDES
 ==================================================================================================*/
#include "rfe_sw_driver_state.h"
/*==================================================================================================
 *                          TYPEDEFS (UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
 *                                         Functions
 ==================================================================================================*/

/**
 * \brief This function updates a set of parameters
 *
 * \details This function will validate a set of parameters to update and. If radar cycle is inactive,
 * it will also applies them (via rfeSwCfgMngr_applyParamUpdates()). This function is called by the cmd server
 * dispatcher to handle the rfe_updatePush() API function. The RFE has to be configured before.
 * If not successfull an error is returned.
 *
 * \pre
 * - State must be #rfeSwCfgMngr_state_configured_e
 *
 * \param [in]      pUpdates - Pointer to an array with the updates.
 * \param [in]      updateCount - Number of parameter updates
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return uint16_t - The radar cycle index at which the configuration gets updated.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
uint16_t rfeSwCfgUpdatePush(const rfeSwCfgMngr_update_t* pUpdates, uint8_t updateCount, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function applies a set of update parameters
 *
 *
 * \pre
 *
 * \param [in]
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return BOOL - TRUE : the updates was applied
 * 				  FALSE : the updates was not applied
 *
 * \post NIL
 *
 * \ingroup NIL
 */
BOOL rfeSwCfgApplyParamUpdates(rfe_error_t* rfe___error___pointer);

#endif /* RFE_SW_CFG_UPDATE_TEF82XX_H_ */
