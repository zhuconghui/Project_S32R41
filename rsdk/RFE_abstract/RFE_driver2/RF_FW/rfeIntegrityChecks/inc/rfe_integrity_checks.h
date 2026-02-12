/*
* Copyright 2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
*/


/**********************************************************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *********************************************************************************************************************/

#ifndef RFE_FAULT_INJECTION_TEST_H
#define RFE_FAULT_INJECTION_TEST_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rfe_error.h"


/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                    TYPES DEFINITIONS
==================================================================================================*/
/**
 * @brief   Type for the Integrity Checks test to be called
 *
 * @details This enum describe the requested tests as a set of masks.
 *
 */
typedef enum {
    rfe_ic_test_none_e = 0x0u,         /**< Dummy value, to have a null reference in this enum                     */
    rfe_ic_cafc_test_e = 0x1u,         /**< CAFC monitor integrity check                                           */
    rfe_ic_tx_sensor_test_e = 0x2u,    /**< TX monitor integrity check                                             */
    rfe_ic_tx_calib_status_e = 0x4u,   /**< Transmitter local calibration status                                   */
    rfe_ic_toggle_test_e = 0x8u,       /**< Digital signals toggle test                                            */
	rfe_ic_loi_bbd_test_e = 0x10u,     /**< Loi BBD test*/
	rfe_ic_max_test_e                  /**< Digital signals toggle test                                            */
}rfe_icFaultInjectionTest_t;;


/**
 * @brief   Type for Front-End to be tested
 *
 * @details This enum describe the requested Front-End as a set of masks.
 *
 */
typedef enum {
    rfe_ic_front_end_none_e = 0x0u,                    /**< Dummy value, to have a null reference in the enum      */
    rfe_ic_front_end_leader_or_standalone_e = 0x1u,    /**< The requested Front-End is the leader or standalone    */
    rfe_ic_front_end_follower1_e = 0x2u,               /**< The requested Front-End is the first follower          */




    rfe_ic_front_end_max_e                             /**< The Front-End mask limit                               */
}rfe_icFrontEnd_t;

/**
 * @brief   Type for Front-End digital signal (GPIO) to be tested
 *
 * @details This enumeration describe the requested digital signal as a set of masks.
 *
 */
typedef enum {
    rfe_ic_gpio_none_e = 0x0u,                          /**< Dummy value, to have a null reference in the enum      */
    rfe_ic_gpio_chirp_start_in_e = 0x1u,                /**< Chirp Start In signal to be tested                     */
    rfe_ic_gpio_chirp_start_out_e = 0x2u,               /**< Chirp Start Out signal to be tested                    */
    rfe_ic_gpio_error_n_e = 0x4u,                       /**< Error_N signal to be tested                            */
    rfe_ic_gpio_error_reset_e = 0x8u,                   /**< Error_Reset signal to be tested                        */
    rfe_ic_gpio_tx1_i_e = 0x10u,                        /**< TX1_I signal to be tested                              */
    rfe_ic_gpio_tx2_i_e = 0x20u,                        /**< TX2_I signal to be tested                              */
    rfe_ic_gpio_tx3_i_e = 0x40u,                        /**< TX3_I signal to be tested                              */
    rfe_ic_gpio_tx1_q_e = 0x80u,                        /**< TX1_Q signal to be tested                              */
    rfe_ic_gpio_tx2_q_e = 0x100u,                       /**< TX2_Q signal to be tested                              */
    rfe_ic_gpio_tx3_q_e = 0x200u,                       /**< TX3_Q signal to be tested                              */
    rfe_ic_gpio_max_e = rfe_ic_gpio_tx3_q_e * 2u        /**< first value not allowed to be tested                   */
}rfe_icGpioSignal_t;


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/*****************************************************************************
 * @brief   Call for a Fault Injection Tests sequence
 * @detail  The function performs the requested set of tests for the requested number of Front-Ends
 *          in the quickest possible succession.
 *
 * @param[in]   frontEnd                = the requested front-end to be tested
 * @param[in]   integrityCheckMask      = tests to be performed, as a single mask
 * @param[in]   gpioMask                = GPIO mask to be checked, used only if toggle test is required to be performed
 * @param[in]   lastCycleSequence       = the last sequence in cycle
 * @param[in]   rfe___error___pointer   = pointer to the error location to be returned
 *                                        if all functions succeed, pointed value will be rfe_error_none_e
 *                                        else a specific error will be set :
 *                                         rfe_error_ic_wrg_input_params_e = at least one of frontEndMask, ftiToDo or
 *                                                                              rfe___error___pointer are null
 *                                         rfe_error_ic_leader_cafc_test_e = CAFC test error on leader side
 *                                         rfe_error_ic_follower_cafc_test_e = CAFC test error on a follower side
 *                                         rfe_error_ic_leader_tx_sensor_test_e = Tx sensor test error on leader
 *                                         rfe_error_ic_follower_tx_sensor_test_e = Tx sensor test error on a follower
 *                                         rfe_error_ic_leader_tx_calib_status_e = Tx calibration error on leader
 *                                         rfe_error_ic_follower_tx_calib_status_e = Tx calibration error on a follower
 *                                         rfe_error_ic_leader_toggle_test_e = toggle test error on leader
 *                                         rfe_error_ic_follower_toggle_test_e = toggle test error on a follower
 */
void rfeIcTest(uint8_t frontEndId, rfe_icFaultInjectionTest_t integrityCheckMask,
                rfe_icGpioSignal_t gpioMask, uint8_t lastCycleSequence, rfe_error_t *rfe___error___pointer);


#endif /* RFE_FAULT_INJECTION_TEST_H */
