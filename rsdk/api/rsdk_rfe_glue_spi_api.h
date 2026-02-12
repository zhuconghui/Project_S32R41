/**************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2018-2021 NXP
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

#ifndef RSDK_RFE_GLUE_SPI_API_H
#define RSDK_RFE_GLUE_SPI_API_H

/** @addtogroup rsdk_rfe_glue_spi
 * @{
 *  @brief
 *  RFE Abstract component of RadarSDK depends on application provided API for communicating over SPI.
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include <stdint.h>

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
#define SPI_GLUE_SUCCESS                0
#define SPI_GLUE_ERR_WRG_UNIT_ID       10
#define SPI_GLUE_ERR_INVALID_LEN       20
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @brief        RFE glue layer function that initializes the SPI interface - Provided by application
* @details      This function will be called by RFE abstract to initialize the SPI interface. As the SPI peripheral
*               can be shared by multiple external devices the management of the interface is left to the application
*
* @param[in]    glueLayerId - Unique identifier passed from the driver to the glue layer to help the application
*               use the correct SPI channel to communicate with the frontend. This is the same value passed in
*               rsdkRfeInitializationParams_t::glueLayerId
*
* @return       uint32_t - status code indicating success (0) or failure (!=0)
*/
extern uint32_t RsdkRfeGlueSpiInit(uint32_t glueLayerId);

/**
* @brief        RFE glue layer function used to communicate with the frontend using SPI - Provided by application
* @details      This function will be called by RFE abstract to communicate with the frontend using SPI transfers.
*               As the SPI peripheral can be shared by multiple external devices the management of the interface is left
*               to the application
*
* @param[in]    glueLayerId - Unique identifier passed from the driver to the glue layer to help the application
*               use the correct SPI channel to communicate with the frontend. This is the same value passed in
*               rsdkRfeInitializationParams_t::glueLayerId
* @param[in]    pTxData - pointer to the data to be transfered
* @param[out]   pRxData - pointer to the received data
* @param[in]    length - the length of the transfer in bytes
*
* @return       uint32_t - status code indicating success (0) or failure (!=0)
*
* @pre          RsdkRfeGlueSpiInit() must be invoked prior to communicating over SPI
*               When using RFE Abstract, this is automatically done, without need from application, but when using
*               a low level driver directly, it is application's responsibility to do this initialization
*/

extern uint32_t RsdkRfeGlueSpiTransfer(uint32_t glueLayerId, uint8_t *pTxData, uint8_t *pRxData, uint16_t length);

#ifdef __cplusplus
}
#endif

#endif /* RSDK_RFE_GLUE_SPI_API_H */

/** @} */
