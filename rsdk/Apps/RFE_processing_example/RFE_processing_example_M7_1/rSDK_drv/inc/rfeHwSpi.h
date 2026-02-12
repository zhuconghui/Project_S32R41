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

#ifndef RFE_HW_SPI_H
#define RFE_HW_SPI_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "typedefs.h"

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
#define SPI_SUCCESS                0
#define SPI_ERR_WRG_UNIT_ID       10
#define SPI_ERR_INVALID_LEN       20

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
* @brief        RFE function that initializes the SPI interface
* @details      This function will be called to initialize the SPI interface. The SPI peripheral
*               can't be shared by multiple external devices
*
* @param[in]    frontEndId - Unique identifier associated with SPI used to communicate with the frontend.
*
* @return       uint32_t - status code indicating success (0) or failure (!=0)
*/
uint32_t RfeHwSpiInit(uint32_t frontEndId);

/**
* @brief        RFE used to communicate with the frontend using SPI
* @details      This function will be called to communicate with the frontend using SPI transfers.
*
* @param[in]    frontEndId - Unique identifier associated with SPI used to communicate with the frontend.
* @param[in]    pTxData - pointer to the data to be transfered
* @param[out]   pRxData - pointer to the received data
* @param[in]    length - the length of the transfer in bytes
*
* @return       uint32_t - status code indicating success (0) or failure (!=0)
*
* @pre          RfeSpiInit() must be invoked prior to communicating over SPI
*/
uint32_t RfeHwSpiTransfer(uint32_t frontEndId, uint8_t *pTxData, uint8_t *pRxData, uint16_t length);

#ifdef __cplusplus
}
#endif

#endif /* RFE_HW_SPI_H */

/** @} */
