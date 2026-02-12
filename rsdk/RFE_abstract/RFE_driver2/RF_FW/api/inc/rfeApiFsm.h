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


/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_API_FSM_H
#define RFE_API_FSM_H



/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include <stdint.h>
#include "rfe_error.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*   @addtogroup rsdk_rfe_api_fsm_const
*   @{
*/

/**
 * This macro defines the number of main states.
 */
#define RFE_SW_MAIN_FSM_MAIN_STATE_COUNT ( 9UL )

/**
 * @}
 */

/**
* @addtogroup rsdk_rfe_api_fsm_api
* @{
*/
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ==================================================================================================*/
/**
 * This enumerated type defines the main states.
 */
typedef enum
{
    rfeSwMainFsm_mainState_initializing_e = 0U,
    rfeSwMainFsm_mainState_waitingForSync_e = 1U,
    rfeSwMainFsm_mainState_initialized_e = 2U,
    rfeSwMainFsm_mainState_configuring_e = 3U,
    rfeSwMainFsm_mainState_configured_e = 4U,
    rfeSwMainFsm_mainState_startRadarCycles_e = 5U,
    rfeSwMainFsm_mainState_radarCycles_e = 6U,
    rfeSwMainFsm_mainState_testContinuousWaveTransmission_e = 7U,
    rfeSwMainFsm_mainState_fuSaFault_e = 8U
} rfeSwMainFsm_mainState_t;
/**
 * This enumerated type defines the possible TEF82xx configurations.
 */
typedef enum
{
    rfeFrontEnd_Single_e = 0U,
    rfeFrontEnd_Cascaded_e = 1U
} rfeFrontEnd_Configuration_t;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * \brief This function performs the main finite-state-machine.
 *
 * \details This function shall be called by the RFE abstraction 2 main app.
 * This function will perform all needed function on the TEF82xx frontend.
 *
 * \pre Call rfeSetSharedAdresses for shared memory addresses settings.
 *      Call rfeSetFrontendsConfiguration or default will be used rfeFrontEnd_Cascaded_e with RFE_MAX_SUPPORTED_DEVICES
 *
 * \param [in]      state - Start state or the state at which to continue.
 * \param [in,out]  rfe___error___pointer  - Error handling parameter.
 *
 * \return rfeSwMainFsm_mainState_t - The next state.
 * This return value can be used as argument to the next invocation of this function. In this
 * way we can step through the state machine, state by state.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfeSwMainFsm_mainState_t rfeMainFsm(rfeSwMainFsm_mainState_t state, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function set the number of connected frontends and the configuration used.
 *
 * \details This function must be called before the start of the main fsm, before the TEF82xx init.
 *          Default configuration is rfeFrontEnd_Cascaded_e with RFE_MAX_SUPPORTED_DEVICES.
 *          Note that single mode on multiple TEF82xx is not supported e.g. rfeFrontEnd_Single_e with NUM_FRONTENDS_MAX
 *
 * \pre NIL
 *
 * \param [in]      feConfigType           - Frontend configuration type.
 * \param [in]      numConnectedFrrontends - Number of frontends that are connected to the SOC.
 * \param [in,out]  rfe___error___pointer  - Error handling parameter.
 *
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSetFrontendsConfiguration(rfeFrontEnd_Configuration_t feConfigType, uint8_t numConnectedFrrontends, rfe_error_t* rfe___error___pointer);

/**
* \brief   Set the shared addresses for the cores intercommunication.
*
* \pre NIL
*
* \param [in] rfeRfBistBufferAddressParam        - the location for the MIPI CSI2 data buffers.
* 
*/
void rfeSetSharedAdresses(uint32_t rfeRfBistBufferAddressParam);

/**
 * @}
 */

#endif // RFE_API_FSM_H

