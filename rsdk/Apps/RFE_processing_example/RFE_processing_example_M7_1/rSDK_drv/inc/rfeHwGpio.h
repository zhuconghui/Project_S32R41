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

#ifndef RFE_HW_GPIO_H
#define RFE_HW_GPIO_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "typedefs.h"
#include "rsdk_S32R41.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define RFE_NUM_CONNECTED_FRONT_ENDS 2

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef enum
{
    IN,
    OUT,
} gpioDirection_t;

typedef struct
{
    /* MSCR register number */
    int16_t mscrNum;
    /* pointer to the GPDO/GPDI register */
    volatile void * pReg;
    /* pin direction: IN/OUT: if -1 -> pin is not to be configured, read or set */
    gpioDirection_t dir;
} gpio_t;

typedef struct
{
    /* MSCR register number */
    int16_t mscrNum;
	/* Source Signal Select */
	uint8_t sss;
    /* IMCR register number */
    int16_t imcrNum;
} spiPin_t;

typedef struct
{
    spiPin_t dspi_sck;
    spiPin_t dspi_sout;
    spiPin_t dspi_sin;
    spiPin_t dspi_pcs;
} tef82xxSpiPin_t;

typedef struct
{
    gpio_t chirpStartIn;
    gpio_t mcuIntChirpStartOut;
    gpio_t errorN;
    gpio_t errorReset;
    gpio_t tx1IPs;
    gpio_t tx2IPs;
    gpio_t tx3IPs;
    gpio_t tx1QPs;
    gpio_t tx2QPs;
    gpio_t tx3QPs;
    gpio_t hReset;
} tef82xxGpioMscr_t;

typedef SIUL2_GPDO0_tag SIUL2_GPDO_tag;
typedef SIUL2_GPDI0_tag SIUL2_GPDI_tag;

///  External Pin Id of the Barracuda
typedef enum
{
    /// The CHIRP_START pin provides precise timing of the actual chirp. The precise timing information is available in two output waveforms, which is chosen by sel_mode_for_chirp_start_out bitfield
    e_SYS_CHIRPSTART_IN_PAD = 0x01u,
    /// This pin can be configued as output pad with different functionalities like MCU_INT, Chirp start trigger or Chirp signal indicating busy/silent period of the chirp based on the configuration
    e_SYS_MCUINT_CHIRPSTART_OUT_PAD = 0x02u,
    /// ERROR_N pin is a generic error interrupt which indicates the MCU that there has a safety-related error has occurred.
    e_SYS_ERRORN = 0x03u,
    /// When a safety sensor is enabled and configured, then any error reported is latched within the module. The latched error is also propagated to inner safety monitor. The latched error is only reset by asserting the ERROR_RESET or via SPI
    e_SYS_ERRORRESET = 0x04,
    /// When the QPSK I/Os controls is set to â€œsynchronousâ€� mode, the value of the TXn_PS_I and TXn_PS_Q I/Os for each TX is sampled at a moment in time defined
    e_SYS_TX1_I_PS = 0x05u,
    e_SYS_TX2_I_PS = 0x06u,
    e_SYS_TX3_I_PS = 0x07u,
    e_SYS_TX1_Q_PS = 0x08u,
    e_SYS_TX2_Q_PS = 0x09u,
    e_SYS_TX3_Q_PS = 0x0Au,
    /// HRSET_N resets all modules to their default state and register values, except the OTP module. The OTP module is insensitive to HRESET_N. Application need to set this pin high
    e_SYS_HRESET = 0x0Fu,
    /// Option to select all external pins of Barracuda
    e_SYS_ALL_BC_PINS = 0x10u,
    e_SYS_PINID_INVALID
} SYS_ExtPinID_e;

#define GPDO(x) &(SIUL2_0.GPDO##x)
#define GPDI(x) &(SIUL2_0.GPDI##x)

/**
* @brief         Call a function when error signal from the RFE
*
* @param[in]     frontEndId -
*
* @return        void
*/
typedef void (*RfeErrorPinCallback)(uint32_t frontEndId);

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifndef USING_RTD_DRIVERS
/**
* @brief         Initialize GPIO pins
* @details       The function must do all necessary steps to correctly setup the GPIOs
*
*/
void RfeHwGpioInit(void);

/**
* @brief        Set the status for an output GPIO pin
* @details      The function must do all necessary steps to correctly update the GPIO status :
*                   - GPIO enable
*                   - GPIO set status
*
* @note         The function call use only the symbolic name of the outputs from SYS_ExtPinID_e
*
* @param[in]    frontendId - single, leader or folower
* @param[in]    HostPinID  - generic name for GPIO from SYS_ExtPinID_e
* @param[in]    pinState   - the state to be set, !=0 => high, 0 => low
*
*/
void RfeHwGpioSet(uint32_t frontendId, SYS_ExtPinID_e HostPinID, uint8_t pinState);

/**
* @brief        Get the status for an output GPIO pin
* @details      The function must do all necessary steps to correctly update the GPIO status :
*                   - GPIO enable
*                   - GPIO set status
*
* @note         The function call use only the symbolic name of the outputs from SYS_ExtPinID_e
*
* @param[in]    frontendId - single, leader or folower
* @param[in]    HostPinID  - generic name for GPIO from SYS_ExtPinID_e
* @param[out]   pinState   - the state to be set, !=0 => high, 0 => low
*
*/
void RfeHwGpioGet(uint32_t frontendId, SYS_ExtPinID_e HostPinID, uint8_t *pinState);
#endif
/**
* @brief         Enable the interrupt driven by the external Error signal from the RFE
*
* @param[in]     frontendId -
*
* @return        void
*/
void RfeHwExtErrorIntEnable(uint32_t frontendId);

/**
* @brief         Disable/mask the interrupt driven by the external Error signal from the RFE
*
* @param[in]     frontendId -
*
* @return        void
*/
void RfeHwExtErrorIntDisable(uint32_t frontendId);

/**
* @brief         External error signal interrupt handler activation.
*
* @param[in]     errorCallback - the application routine to be called if the handler is called
*
* @return        uint32_t - status code indicating success (0) or failure (!=0)
*/
uint32_t RfeHwExtErrorConnect(RfeErrorPinCallback errorCallback);

#ifdef __cplusplus
}
#endif

#endif /* RFE_HW_GPIO_H */

/** @} */
