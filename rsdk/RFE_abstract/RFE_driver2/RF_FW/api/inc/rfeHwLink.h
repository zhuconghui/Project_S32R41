/**************************************************************************************************
* Copyright 2023-2024 NXP
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
/**
 * \file
 *
 * Software unit for accessing hardware units.
 */
#ifndef RFE_HW_LINK_H
#define RFE_HW_LINK_H

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "rfe_types.h"
#include "rfe_error.h"

/**
*   @addtogroup rsdk_rfe_hw_api_gpio
*   @{
*/
/*==================================================================================================
 *                                        DEFINES
 ==================================================================================================*/


/*==================================================================================================
 *                                        TYPES/ENUMS
 ==================================================================================================*/


/**
 * External Pin Id of the TEF82XX.
 */
typedef enum
{
    /// The CHIRP_START pin provides precise timing of the actual chirp. The precise timing information is available in two output waveforms, which is chosen by sel_mode_for_chirp_start_out bitfield
    e_CHIRPSTART_IN_PAD = 0x01u,
    /// This pin can be configued as output pad with different functionalities like MCU_INT, Chirp start trigger or Chirp signal indicating busy/silent period of the chirp based on the configuration
    e_MCUINT_CHIRPSTART_OUT_PAD = 0x02u,
    /// ERROR_N pin is a generic error interrupt which indicates the MCU that there has a safety-related error has occurred.
    e_ERRORN = 0x03u,
    /// When a safety sensor is enabled and configured, then any error reported is latched within the module. The latched error is also propagated to inner safety monitor. The latched error is only reset by asserting the ERROR_RESET or via SPI
    e_ERRORRESET = 0x04,
    /// When the QPSK I/Os controls is set to asynchronous mode, the value of the TXn_PS_I and TXn_PS_Q I/Os for each TX is sampled at a moment in time defined
    e_TX1_I_PS = 0x05u,
    e_TX2_I_PS = 0x06u,
    e_TX3_I_PS = 0x07u,
    e_TX1_Q_PS = 0x08u,
    e_TX2_Q_PS = 0x09u,
    e_TX3_Q_PS = 0x0Au,
    /// HRSET_N resets all modules to their default state and register values, except the OTP module. The OTP module is insensitive to HRESET_N. Application need to set this pin high
    e_HRESET = 0x0Fu,
    /// Option to select all external pins of TEF82XX
    e_ALL_BC_PINS = 0x10u,
    e_PINID_INVALID
} TEF82XX_ExtPinID_e;


/**
 * @}
 */

/**
*   @addtogroup rsdk_rfe_hw_api_timers
*   @{
*/
/*==================================================================================================
 *                              FUNCTIONS
 ==================================================================================================*/
/** \brief          Init timers
  * \details        Init all hw timers for RFE FSM good functionality: 25ns tick timer and others.
  * \param[in,out]  rfe___error___pointer   Error parameter.
  */
extern void RfeHwTimersInit(rfe_error_t* rfe___error___pointer);

/**
 * \brief Returns heart beat value that represents 25ns system ticks.
 *
 * \param[in,out]  rfe___error___pointer   Error parameter.
 *
 * * \return     value                     Timer value in 25ns units.
 */
extern uint32_t RfeHwHeartBeatTimerGetValue(rfe_error_t* rfe___error___pointer);

/** \brief      Application provided function to delay execution with us microseconds.
  * \param[in]  us delay time in microseconds
  * \pre        Invoke RfeHwTimersInit() as initialization code, prior to calling this function for the first time
  */
extern void RfeHwDelayUs(uint32_t us);

/**
 * @}
 */

/**
*   @addtogroup rsdk_rfe_hw_api_spi
*   @{
*/

/**
* \brief          RFE function that initializes the SPI interface
* \details        This function will be called to initialize the SPI interface. The SPI peripheral
*                 can't be shared by multiple external devices
*
* \param[in]      frontEndId - Unique identifier associated with SPI used to communicate with the frontend.
* \param[in,out]  rfe___error___pointer   Error parameter.
*
*/
extern void RfeHwSpiInitialize(uint32_t frontEndId, rfe_error_t* rfe___error___pointer);

/**
* \brief        RFE uses to communicate with the frontend using SPI
* \details      This function will be called to communicate with the frontend using SPI transfers.
*
* \param[in]    frontEndId - Unique identifier associated with SPI used to communicate with the frontend.
* \param[in]    pTxData - pointer to the data to be transfered
* \param[out]   pRxData - pointer to the received data
* \param[in]    length - the length of the transfer in bytes
*
* \return       uint32_t - status code indicating success (0) or failure (!=0)
*
* \pre          RfeHwSpiInit() must be invoked prior to communicating over SPI
*/
extern uint32_t RfeHwSpiTransfer(uint32_t frontEndId, uint8_t *pTxData, uint8_t *pRxData, uint16_t length);

/**
* \brief          Initialize GPIO pins
* \details        The function must do all necessary steps to correctly setup the GPIOs
*
*/

/**
 * @}
 */

/**
*   @addtogroup rsdk_rfe_hw_api_gpio
*   @{
*/
extern void RfeHwGpioInit(void);

/**
* @brief        Set the status for an output GPIO pin
* @details      The function must do all necessary steps to correctly update the GPIO status :
*                   - GPIO enable
*                   - GPIO set status
*
* @note         The function call use only the symbolic name of the outputs from SYS_ExtPinID_e
*
* @param[in]    frontendId - single, leader or follower
* @param[in]    HostPinID  - generic name for GPIO from TEF82XX_ExtPinID_e
* @param[in]    pinState   - the state to be set, !=0 => high, 0 => low
*
*/
extern void RfeHwGpioSet(uint32_t frontendId, TEF82XX_ExtPinID_e HostPinID, uint8_t pinState);

/**
* @brief        Get the status for an output GPIO pin
* @details      The function must do all necessary steps to correctly update the GPIO status :
*                   - GPIO enable
*                   - GPIO set status
*
* @note         The function call use only the symbolic name of the outputs from SYS_ExtPinID_e
*
* @param[in]    frontendId - single, leader or follower
* @param[in]    HostPinID  - generic name for GPIO from TEF82XX_ExtPinID_e
* @param[out]   pinState   - the state to be set, !=0 => high, 0 => low
*
*/
extern void RfeHwGpioGet(uint32_t frontendId, TEF82XX_ExtPinID_e HostPinID, uint8_t *pinState);

/**
* @brief        Function for initialization of the IRQ channel or other related initialization
* @details      Define in this function any necessary initialization
*
* @note
*
*
*/

/**
 * @}
 */

/**
*   @addtogroup rsdk_rfe_hw_api_irq
*   @{
*/
extern void RfeHwSetIRQ(void);


/**
* @brief        Raise IRQ to specified core
* @details      Call any necessary low level or IPCF routine in order to signal an event or command completion
*
* @note
*
* @param[in]    apiIrq     - command id or 0xFFFFFFFF if event
* @param[in]    eventIrq   - event id or 0xFF if command
*
*/
extern void RfeHwRaiseIRQ(uint32_t apiIrq, uint32_t eventIrq);

/**
 * @}
 */


#ifdef RFE_DEBUG
/**
*   @addtogroup rsdk_rfe_hw_api_dbg
*   @{
*/

/**
 *
* \brief          Initialize debug mechanism for RFE
* \details        The function must do all necessary steps to correctly setup the debug UART console
*
* \param[in,out]  rfe___error___pointer   Error parameter.
*
*/
extern void RfeInitDebug(rfe_error_t* rfe___error___pointer);

/**
* \brief       Perform simple printf()-like functionality over UART console
* \pre         RfeInitDebug() must be called before using this function. The code must be built with a valid combination of preprocessor macros
*
* \param[in] fmt -  String to be output
*
*/
extern void RfeDbgPrintMsg(const char *fmt, ...);

/**
 * @}
 */

#endif


#endif // RFE_HW_LINK_H

