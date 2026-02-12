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

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/

#include <stdio.h>
#include "rfeHwSpi.h"
#include "rsdk_S32R41.h"
#include "rsdk_system_timer_cm7.h"
#include "RfeHwConfig.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
 ==================================================================================================*/ 

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static uint32_t map_spi_device(uint32_t frontEndId, volatile struct SPI_tag **SPI_DEVICE);

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
static uint32_t map_spi_device(uint32_t frontEndId, volatile struct SPI_tag **SPI_DEVICE)
{
    uint32_t result = 0;
    *SPI_DEVICE = gsTef82xxConf[frontEndId].spiDevice;
    return result;
}

/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/
uint32_t RfeHwSpiInit(uint32_t frontEndId)
{
    uint32_t result;
    volatile struct SPI_tag *SPI_DEVICE;
    
    result = map_spi_device(frontEndId, &SPI_DEVICE);

    if (result == SPI_SUCCESS)
    {
        // MCR initialization:
        SPI_DEVICE->MCR.B.MSTR = 1;       // Enable Master mode
        SPI_DEVICE->MCR.B.CONT_SCKE = 0;  // No continuous clock
        SPI_DEVICE->MCR.B.DCONF = 0;      // SPI
        SPI_DEVICE->MCR.B.FRZ = 0;        // Do not halt in debug mode
        SPI_DEVICE->MCR.B.MTFE = 0;       // Modified transfer format
        SPI_DEVICE->MCR.B.ROOE = 0;       // Receive FIFO overflow -> ignore incoming data
        SPI_DEVICE->MCR.B.PCSIS = 0xf;    // PCS inactive state is high (I dont understand why!)
        SPI_DEVICE->MCR.B.MDIS = 0;       // Enable module
        SPI_DEVICE->MCR.B.DIS_TXF = 0;    // Enable TX FIFO
        SPI_DEVICE->MCR.B.DIS_RXF = 0;    // Enable RX FIFO
        SPI_DEVICE->MCR.B.CLR_TXF = 1;    // Clear TX FIFO
        SPI_DEVICE->MCR.B.CLR_RXF = 1;    // Clear RX FIFO
        SPI_DEVICE->MCR.B.PES = 0;        // Don't stop on parity error
        SPI_DEVICE->MCR.B.HALT = 1;       // Keep HALT=1 (stop transfers)
        SPI_DEVICE->MCR.B.MDIS = 0;       // Enable module

        /* CTAR0 initialization used for 8 bit data transfers
        * no double baudrate, frame size 8-bits, SCK polarity is high, data is changed on leading (falling edge) and captured on following (rising) edge (CPOL = CPHA = 1), MSB first,
        * PCS to SCK delay is 2, after SCK delay is 4, delay after transfer is 64, baudrate depends on function argument
        */

        SPI_DEVICE->MODE.CTAR[0].B.DBR = 0;     // No double baud rate
        SPI_DEVICE->MODE.CTAR[0].B.FMSZ = 7;    // Frame size = 8-bits
        SPI_DEVICE->MODE.CTAR[0].B.CPOL = 0;    // Inactive state of SCK is high
        SPI_DEVICE->MODE.CTAR[0].B.CPHA = 0;    // Data is changed on the leading edge and captured on the following edge
        SPI_DEVICE->MODE.CTAR[0].B.LSBFE = 0;   // MSB transmitted first
        SPI_DEVICE->MODE.CTAR[0].B.PCSSCK = 0;  // PCS to SCK delay prescaler = 1
        SPI_DEVICE->MODE.CTAR[0].B.PASC = 0;    // After SCK delay prescaler = 1
        SPI_DEVICE->MODE.CTAR[0].B.PDT = 0;     // Delay after transfer prescaler = 1
        SPI_DEVICE->MODE.CTAR[0].B.PBR = 0;     // Baud rate prescaler = 0 ( /2 )
        SPI_DEVICE->MODE.CTAR[0].B.CSSCK = 0;   // PCS to SCK delay scaler = 2
        SPI_DEVICE->MODE.CTAR[0].B.ASC = 1;     // After SCK delay scaler = 4
        SPI_DEVICE->MODE.CTAR[0].B.DT = 5;      // Delay after transfer delay scaler = 64
        SPI_DEVICE->MODE.CTAR[0].B.BR = 1;      // Baud rate scaler = 2 -> baud rate = (100/2 / 4) = 12.5MHz

        SPI_DEVICE->SR.R = 0xFFFFFFFF;  // clear all flags
        SPI_DEVICE->MCR.B.HALT = 0;     // start transfers
    }

    return result;
}
#ifndef USING_RTD_DRIVERS
uint32_t RfeHwSpiTransfer(uint32_t frontEndId, uint8_t *pTxData, uint8_t *pRxData, uint16_t length)
{
    uint32_t result = SPI_SUCCESS;
    uint32_t byteIdx = 0;
    uint32_t receivedValue;
    volatile struct SPI_tag *SPI_DEVICE;

    if (length == 0)
    {
        result = SPI_ERR_INVALID_LEN;
    }

    if (result == SPI_SUCCESS)
    {
        result = map_spi_device(frontEndId, &SPI_DEVICE);
    }

    if (result == SPI_SUCCESS)
    {
        SPI_DEVICE->MCR.B.CLR_RXF = 1u;  // Clear Rx FIFO
        SPI_DEVICE->MCR.B.CLR_TXF = 1u;  // Clear Tx FIFO
        SPI_DEVICE->SR.R = 0xFFFFFFFFu;  // Clear all flags

        for (byteIdx = 0; byteIdx < length - 1; byteIdx++)
        {
            // Wait for TX FIFO to have some space
            while (SPI_DEVICE->SR.B.TFFF == 0)
            {
            }
            SPI_DEVICE->PUSHR.PUSHR.R = 0x80010000u | pTxData[byteIdx]; //TODO: confirm if the same Chip select mask applies to SPI_2 
            /* During testing it was observed that the a53 at 1GHz when poping the data from the FIFO it will be corrupted if too fast
            * This also happens if the code waits for the FIFO to have data */
            RsdkSysTimerCm7DelayUs(2);

            // Wait for the RX FIFO to have data
            while (SPI_DEVICE->SR.B.RFDF == 0)
            {
            }
            receivedValue = SPI_DEVICE->POPR.R;
            pRxData[byteIdx] = (uint8_t)(receivedValue & 0xFFu);
        }

        // Send the last byte
        // Wait for TX FIFO to have some space
        while (SPI_DEVICE->SR.B.TFFF == 0)
        {
        }
        SPI_DEVICE->PUSHR.PUSHR.R = 0x08010000u | pTxData[byteIdx];
        RsdkSysTimerCm7DelayUs(2);

        while (SPI_DEVICE->SR.B.RFDF == 0)
        {
        }
        pRxData[byteIdx] = SPI_DEVICE->POPR.R;
    }
    
    return result;	
}
#endif
#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
