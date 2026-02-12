/**************************************************************************************************
* Copyright 2023 NXP
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

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include <stdbool.h>
#include "rfeApiFsm.h"
#include "rfe_sw_driver_state.h"
#include "rfeSwMainFsm.h"
#include "rfeSwBist.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/
static uint8_t guNumConnectedFrrontends = RFE_MAX_SUPPORTED_DEVICES;
static rfeFrontEnd_Configuration_t gFEConfigType = rfeFrontEnd_Cascaded_e;
static bool gFsmStarted = false;

/*==================================================================================================
 *                                      LOCAL FUNCTIONS
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/
rfeSwMainFsm_mainState_t rfeMainFsm(rfeSwMainFsm_mainState_t state, rfe_error_t* rfe___error___pointer)
{
    rfeSwMainFsm_mainState_t returnState;

    if (!gFsmStarted)
    {
        *rfe___error___pointer = rfe_error_none_e;
        gFsmStarted = true;
        RfeDrvStateNoFrontendsSet(guNumConnectedFrrontends);
        RfeDrvStateConfigurationSet(gFEConfigType);
    }
    returnState = rfeSwMainFsm_mainFsm(state, rfe___error___pointer);
    return returnState;
}

void rfeSetFrontendsConfiguration(rfeFrontEnd_Configuration_t feConfigType, uint8_t numConnectedFrrontends, rfe_error_t* rfe___error___pointer)
{
    if (numConnectedFrrontends > RFE_MAX_SUPPORTED_DEVICES)
    {
        *rfe___error___pointer = rfe_error_api_invalid_num_frontends_e;
    }
    if ((*rfe___error___pointer == rfe_error_none_e) && (gFsmStarted))
    {
        *rfe___error___pointer = rfe_error_api_fsm_was_started_e;
    }
    if ((*rfe___error___pointer == rfe_error_none_e) && (feConfigType == rfeFrontEnd_Single_e) && (numConnectedFrrontends > 1U))
    {
        *rfe___error___pointer = rfe_error_api_invalid_frontends_conf_e;
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {
        guNumConnectedFrrontends = numConnectedFrrontends;
        gFEConfigType = feConfigType;
    }
}

void rfeSetSharedAdresses(uint32_t rfeRfBistBufferAddressParam)
{
    rfeSwBist_setSharedAddresses(rfeRfBistBufferAddressParam);
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
