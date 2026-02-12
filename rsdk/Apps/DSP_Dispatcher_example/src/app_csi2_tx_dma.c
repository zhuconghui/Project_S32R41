/**************************************************************************************************
 * Copyright 2016-2023 NXP
 **************************************************************************************************
 * NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms.  By expressly accepting such terms or by
 * downloading, installing, activating and/or otherwise using the software, you are agreeing that
 * you have read, and that you agree to comply with and are bound by, such license terms.
 * If you do not agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
 **************************************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <xtensa/xos.h>
#include "stddef.h"
#include "CDD_Csi2TxDma.h"
#include "Csi2TxDma_IpwIrq.h"
#include "hw_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                          TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef struct
{
    uint32_t pInBuf;
    uint32_t numBytesPerChirp;
} appDspTxDmaParams_t;

/*==================================================================================================
*                                       MACROS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

Csi2TxDma_SingleConfigType singleConfigDma = {
        .bufferLength = 0,
        .bufferPtr = NULL,
        .chirpsNumber = 128,
        .metadataDelay = 2000,
        .metadataType = CSI2TXDMA_METADATA_NO,
        .usedVC = CSI2TXDMA_VIRTUAL_CHANNEL_0
};

Csi2TxDma_SingleSetupType simpleSetup = {
        .endDelay = 10000,
        .eventsRequest = CSI2TXDMA_EVENT_CHIRP_END, // | CSI2TXDMA_EVENT_LAST_CHIRP_SENT, //select the events for which the Csi2TxDma_IsrCallback is called
        .interChirpDelay = 42200,   //this value was determined empirically. The actual delay depends also on the Csi2TxDma_SingleConfigType::bufferLength
        .startDelay = 10000,
        .workingMode = CSI2TXDMA_DMA_MODE_SINGLE_CIRCULAR,
        .workingModeParamPtr = &singleConfigDma
};


Csi2TxDma_PhySetupType csi2TxDmaPhySetup = {
        .lanesMapping = CSI2TXDMA_LANES_MAP_NORMAL,
        .lanesSwap = CSI2TXDMA_LANES_SWAP_LANE0 | CSI2TXDMA_LANES_SWAP_LANE1
};

uint32_t metaDataValues[4] = {0x11111111, 0x22222222, 0x33333333, 0x44444444};
volatile Csi2TxDma_CallbackEventsType txDmaEvtInfo = 0u;

/*==================================================================================================
*                                   FUNCTION PROTOTYPES
==================================================================================================*/
// Callback definition for CSI2TxDma driver

/*==================================================================================================
*                                       FUNCTIONS
==================================================================================================*/
void Csi2TxDma_IsrCallback(Csi2TxDma_ErrorReportType *errorPtr)
{
    if((errorPtr->eventAndError & CSI2TXDMA_EVENT_CHIRP_END) != 0U)
    {
        txDmaEvtInfo |= CSI2TXDMA_EVENT_CHIRP_END;
    }
    else if((errorPtr->eventAndError & CSI2TXDMA_EVENT_LAST_CHIRP_SENT) != 0U)
    {
        txDmaEvtInfo |= CSI2TXDMA_EVENT_LAST_CHIRP_SENT;
        errorPtr->metaPtr = metaDataValues;
    }
    else // an error occurred, save the whole status info
    {
        txDmaEvtInfo = errorPtr->eventAndError;
    }
}

void AppDspCsi2TxDmaConfig(uintptr_t argList)
{
    uint32_t i;
    int32_t xosStatus;
    rsdkStatus_t dspStatus;
    appDspTxDmaParams_t* pDspTxDmaInitParams = ((appDspTxDmaParams_t **)argList)[0];

    //configure the CSI2 Tx DMA interrupt handler:
    xosStatus = xos_register_interrupt_handler(XCHAL_EXTINT19_NUM, Csi2TxDma_InterruptHandler, NULL);
    if(xosStatus != XOS_OK)
    {
        SetDspError(xosStatus);
    }
    else
    {
        xosStatus = xos_interrupt_enable(XCHAL_EXTINT19_NUM);
        if(xosStatus != XOS_OK)
        {
            SetDspError(xosStatus);
        }
    }

    singleConfigDma.bufferPtr = (uintptr_t)pDspTxDmaInitParams->pInBuf;
    singleConfigDma.bufferLength = pDspTxDmaInitParams->numBytesPerChirp;

    dspStatus = Csi2TxDma_SingleSetup(&simpleSetup, &csi2TxDmaPhySetup);
    if( dspStatus != RSDK_SUCCESS)
    {
        SetDspError(dspStatus);
    }
}

void AppDspCsi2TxDmaRun(uintptr_t argList)
{
    rsdkStatus_t dspStatus;
    static bool csi2TxDmaStarted = false;

    if(csi2TxDmaStarted == false)
    {
        dspStatus = Csi2TxDma_Start();
        if( dspStatus != RSDK_SUCCESS)
        {
            SetDspError(dspStatus);
        }
        else
        {
            csi2TxDmaStarted = true;
        }
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
