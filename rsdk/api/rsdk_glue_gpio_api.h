/**************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2019-2023 NXP
 * All Rights Reserved
 *
 *****************************************************************************
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 **************************************************************************************************/

#ifndef RSDK_GLUE_GPIO_API_H
#define RSDK_GLUE_GPIO_API_H

/** @addtogroup rsdk_glue_gpio_api
 * @{
 * @brief
 * RadarSDK components (eg RFE Abstract) depend on application provided API for GPIO manipulation.
 * @details
 * Specifically, the drivers need to get or set a generic GPIO pad, according to driver needs,
 * but the other details for this (effective pad, platform implementation of the GPIO access, etc.) 
 * need to be provided by the application. Below specified function prototypes are to be implemented 
 * at application level and linked in the final executable. 
 * RadarSDK provide example implementation for these functions for various environments. 
 * @ifnot S32R45_DOCS See @ref rsdk_sa_multi_rfe. @endif
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "rsdk_status.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

// clang-format off

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

#define RSDK_GLUE_ID_SET(x)    (((x) & 0x3u) << 12u)
#define RSDK_GLUE_ID_GET(x)    (((x) >> 12u) & 0x3u)
#define RSDK_PIN_ID_SET_GET(x) ((x) & 0xFFFu)
/**
* @brief    List of GPIO generic names used for TEF810X pin input/output.
* @note     Do not remove or change these names. Only the values can be changed 
*            according the effective implementation.
*
*/
/**
* @anchor   Anchor_DOLPHIN_EXTPIO_CHIRPSTART
*/
#define DOLPHIN_EXTPIO_CHIRPSTART   0x100u
#define DOLPHIN_EXTPO_READYINT      0x200u
#define DOLPHIN_EXTPO_ERRORN        0x300u
#define DOLPHIN_EXTPO_ERRORRESET    0x400u
#define DOLPHIN_PI_TX1PS            0x500u
#define DOLPHIN_PI_TX2PS            0x600u
/**
* @anchor   Anchor_DOLPHIN_PI_TX3PS
*/
#define DOLPHIN_PI_TX3PS            0x700u
#define DOLPHIN_EXTPO_HRESET		0x800u

/**
* @brief    List of GPIO generic names used for TEF82XX pin input/output.
* @note     Do not remove or change these names. Only the values can be changed
*            according the effective implementation.
*
*/
#define TEF82XX_CHIRPSTART_IN           0x01u
#define TEF82XX_MCUINT_CHIRPSTART_OUT   0x02u
#define TEF82XX_ERRORN                  0x03u
#define TEF82XX_ERRORRESET              0x04u
#define TEF82XX_TX1_I_PS                0x05u
#define TEF82XX_TX2_I_PS                0x06u
#define TEF82XX_TX3_I_PS                0x07u
#define TEF82XX_TX1_Q_PS                0x08u
#define TEF82XX_TX2_Q_PS                0x09u
#define TEF82XX_TX3_Q_PS                0x0Au
#define TEF82XX_HRESET                  0x0Fu

// clang-format on

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief         Platform implementation to initialize GPIO pins
* @details       The function must do all necessary steps to correctly setup the GPIOs
*
*/
extern uint32_t RsdkGlueGPIOInit(void);

/**
* @brief         Platform implementation to de-initialize GPIO pins
* @details       The function must do all necessary steps to correctly release the GPIOs
*
*/
extern uint32_t RsdkGlueGPIODelete(void);

/**
* @brief         Platform implementation to set the status for an output GPIO pin
* @details       The function must do all necessary steps to correctly update the GPIO status :
*                   - GPIO enable
*                   - GPIO set status
*
* @note          The function call use only the symbolic name of the outputs: #DOLPHIN_EXTPIO_CHIRPSTART ... #DOLPHIN_PI_TX3PS.
*
* @param[in]    glueLayerId - generic name for GPIO, #DOLPHIN_EXTPIO_CHIRPSTART ... #DOLPHIN_PI_TX3PS
* @param[in]    val         - the state to be set, !=0 => high, 0 => low
*
* @return       rsdkStatus_t - RSDK_SUCCESS 			- if selected PIN is configured
* 							 - RSDK_RFE_GLUE_GPIO_ERROR - if selected PIN is not configured
*
*/
extern rsdkStatus_t RsdkGlueGPIOSet(uint32_t glueLayerId, uint8_t val);

/**
* @brief         Platform implementation to get the status for an output GPIO pin
* @details       The function do all necessary steps to correctly update the GPIO status :
*                   - GPIO enable
*                   - wait for input value to stabilize
*                   - GPIO get status
*
* @note          The function call use only the symbolic name of the outputs: #DOLPHIN_EXTPIO_CHIRPSTART ... #DOLPHIN_PI_TX3PS.
*
* @param[in]    glueLayerId - generic name for GPIO, #DOLPHIN_EXTPIO_CHIRPSTART ... #DOLPHIN_PI_TX3PS
* @param[in]    val         - pointer to the state value to be returned (1 => high, 0 => low)
*
* @return       rsdkStatus_t - RSDK_SUCCESS 			- if selected PIN is configured
* 							 - RSDK_RFE_GLUE_GPIO_ERROR - if selected PIN is not configured
*
*/
extern rsdkStatus_t RsdkGlueGPIOGet(uint32_t glueLayerId, uint8_t *val);

/**
* @brief         Platform implementation to enable the interrupt driven by the external Error signal from the RFE
*
* @param[in]     glueLayerId - generic name for GPIO, #DOLPHIN_EXTPIO_CHIRPSTART ... #DOLPHIN_PI_TX3PS
*
* @return       uint32_t - status code indicating success (0) or failure (!=0)
*/
extern uint32_t RsdkGlueExtErrorIntEnable(uint32_t glueLayerId);

/**
* @brief         Platform implementation to disable/mask the interrupt driven by the external Error signal from the RFE
*
* @param[in]     glueLayerId - generic name frontend index (instance)
*
* @return       uint32_t - status code indicating success (0) or failure (!=0)
*/
extern uint32_t RsdkGlueExtErrorIntDisable(uint32_t glueLayerId);

/**
* @brief         Platform implementation to call a function when error signal from the RFE
*
* @param[in]     glueLayerMask - mask for the front-end reported the error : (1 << frontEndId)
*                               where frontEndId is from 0 to RSDK_CSI2_MAX_UNITS
*
* @return        void
*/
typedef void (*RfeErrorPinCallback)(uint32_t glueLayerMask);

/**
* @brief         External error signal interrupt handler activation.
*
* @param[in]     errorCallback - the application routin to be called if the handler is called
*
* @return        uint32_t - status code indicating success (0) or failure (!=0)
*/
extern uint32_t RsdkGlueExtErrorConnect(RfeErrorPinCallback errorCallback);


#ifdef __cplusplus
}
#endif

#endif /* RSDK_GLUE_GPIO_API_H */

/** @} */
