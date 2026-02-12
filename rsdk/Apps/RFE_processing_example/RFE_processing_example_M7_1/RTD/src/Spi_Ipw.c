/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_P03_D2404_ASR_REL_4_7_REV_0000_20240405
*
*   Copyright 2021 - 2024 NXP NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file    Spi_Ipw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Isolation level file for SPI driver.
*   @details Implementation file for function definition on isolation level between high and low level driver.
*
*   @addtogroup SPI_DRIVER Spi Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spi_Ipw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_VENDOR_ID_C                       43
#define SPI_IPW_AR_RELEASE_MAJOR_VERSION_C        4
#define SPI_IPW_AR_RELEASE_MINOR_VERSION_C        7
#define SPI_IPW_AR_RELEASE_REVISION_VERSION_C     0
#define SPI_IPW_SW_MAJOR_VERSION_C                2
#define SPI_IPW_SW_MINOR_VERSION_C                0
#define SPI_IPW_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ipw.c and Spi_Ipw.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID_C != SPI_IPW_VENDOR_ID)
    #error "Spi_Ipw.c and Spi_Ipw.h have different vendor ids"
#endif
/* Check if Spi_Ipw.c file and Spi_Ipw.h file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION_C != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION_C != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION_C != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Ipw.c and Spi_Ipw.h are different"
#endif
#if ((SPI_IPW_SW_MAJOR_VERSION_C != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_IPW_SW_MINOR_VERSION_C != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_IPW_SW_PATCH_VERSION_C != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Ipw.c and Spi_Ipw.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define   SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

extern Spi_HWUnitQueue Spi_axSpiHwUnitQueueArray[SPI_MAX_HWUNIT];

extern Spi_Ip_StateStructureType* Spi_Ip_apxStateStructureArray[SPI_INSTANCE_COUNT];

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief Mapping between spi channel id and instance id
*/
static Spi_HWUnitType Spi_Ipw_au8SpiHWUnitMapping[SPI_INSTANCE_COUNT];
#endif

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static void Spi_Ipw_Callback(uint8 Instance, Spi_Ip_EventType Event);
static void Spi_Ipw_EndChannelCallback(uint8 Instance, Spi_JobResultType JobResult);
#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
static void Spi_Ipw_SequenceDmaFastTransfer(const Spi_SequenceConfigType *SequenceConfig, uint8 HWUnit, uint32 SpiCoreID);
#endif
#endif

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
static Spi_Ip_StatusType Spi_Ipw_SyncTransmitProcess
    (
        const Spi_Ip_ExternalDeviceType* DspiExternalDevice,
        const Spi_ChannelConfigType *ChannelConfig,
        Spi_DataBufferType *RxBuffer,
        const Spi_DataBufferType *TxBuffer,
        Spi_NumberOfDataType NumberOfBytes
    );
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
static Spi_Ip_StatusType Spi_Ipw_SyncTransmitProcess
    (
        const Spi_Ip_ExternalDeviceType* DspiExternalDevice,
        const Spi_ChannelConfigType *ChannelConfig,
        Spi_DataBufferType *RxBuffer,
        const Spi_DataBufferType *TxBuffer,
        Spi_NumberOfDataType NumberOfBytes
    )
{
    Spi_Ip_StatusType SpiStatus;
    /* update default data, Frame size, Lsb mode */
    DspiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
    DspiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
    DspiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
    SpiStatus = Spi_Ip_SyncTransmit(DspiExternalDevice, TxBuffer, RxBuffer, NumberOfBytes, SPI_TIMEOUT_COUNTER_U32);
    
    return SpiStatus;
}
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/* Spi_Ipw_Init */
void Spi_Ipw_Init(const Spi_HWUnitType HWUnitId, const Spi_HWUnitConfigType *HWUnit)
{
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;
    if (HWUnit->IpType == SPI_OVER_SPI)
    {
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
        Spi_Ipw_au8SpiHWUnitMapping[HWUnit->Instance] = HWUnitId;
    #else
        (void)HWUnitId;
    #endif
        Status = Spi_Ip_Init(HWUnit->IpConfig.DspiIpConfig);
    }
    else
    {
        /* Do nothing */
    }
    /* HLD do not require return value. This code to avoid misra violation */
    (void) Status;
}

/* Spi_Ipw_DeInit */
void Spi_Ipw_DeInit(Spi_HWUnitType HWUnit, uint32 SpiCoreID)
{
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;
    if (Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IpType == SPI_OVER_SPI)
    {
        Status = Spi_Ip_DeInit(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance);
    }
    else
    {
        /* Do nothing */
    } 
    /* HLD do not require return value. This code to avoid misra violation */
    (void) Status;
}

/* Spi_Ipw_SyncTransmit */
#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
Std_ReturnType Spi_Ipw_SyncTransmit(const Spi_JobConfigType *JobConfig, uint32 SpiCoreID)
{

    Std_ReturnType Ipw_Status = (Std_ReturnType)E_OK;
    const Spi_Ip_ExternalDeviceType* DspiExternalDevice;
    Spi_NumberOfDataType NumberOfBytes;
    Spi_DataBufferType *RxBuffer;
    const Spi_DataBufferType *TxBuffer;
    Spi_Ip_StatusType SpiStatus;
    const Spi_ChannelConfigType *ChannelConfig;
    Spi_ChannelType ChannelID;
    Spi_ChannelType NumChannelsInJob;
    Spi_ChannelType ChannelIndex;
    
    NumChannelsInJob = JobConfig->NumChannels;
    for (ChannelIndex = (Spi_ChannelType)0; ChannelIndex < NumChannelsInJob; ChannelIndex++)
    {
        ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
        ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[ChannelID].ChannelCfg;
        NumberOfBytes = ChannelConfig->ChannelState->Length;
        RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if(0u != (ChannelConfig->ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            TxBuffer = NULL_PTR;
        }
        else
        {
            if(EB == ChannelConfig->BufferType)
            {
                TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
            }
            else
            {
                TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
            }
        }
        
        if (JobConfig->ExternalDeviceConfig->ExDeviceConfig->IpType == SPI_OVER_SPI)
        {
            DspiExternalDevice = JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.DspiExternalDeviceConfig;            
            if(ChannelIndex == (NumChannelsInJob - 1u))
            {
                /* Clear CS after current channel */
                Spi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->KeepCs = (boolean)FALSE;
            }
            else
            {
                Spi_Ip_apxStateStructureArray[JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance]->KeepCs = (boolean)TRUE;
            }
            
            /* Process tranfer */
            SpiStatus = Spi_Ipw_SyncTransmitProcess(DspiExternalDevice, ChannelConfig, RxBuffer, (const uint8*)TxBuffer, NumberOfBytes);
            
            if(SPI_IP_STATUS_SUCCESS != SpiStatus)
            {
                Ipw_Status = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    return Ipw_Status;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) ) */


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Spi_Ipw_IrqPoll */
void Spi_Ipw_IrqPoll(Spi_HWUnitType HWUnit, uint32 SpiCoreID)
{
    if (Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IpType == SPI_OVER_SPI)
    {
        if(SPI_IP_POLLING == Spi_Ip_apxStateStructureArray[Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance]->TransferMode)
        {
            Spi_Ip_ManageBuffers(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance);
        }
    }
    else
    {
        /* Do nothing */
    }
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Spi_Ipw_IrqConfig */
void Spi_Ipw_IrqConfig(Spi_HWUnitType HWUnit, Spi_AsyncModeType Mode, uint32 SpiCoreID)
{
    Spi_Ip_StatusType Spi_Ip_Status = SPI_IP_STATUS_SUCCESS;
    if (Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IpType == SPI_OVER_SPI)
    {
        if (SPI_POLLING_MODE == Mode)
        {
            Spi_Ip_Status = Spi_Ip_UpdateTransferMode(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance, SPI_IP_POLLING);
        }
        else
        {
            Spi_Ip_Status = Spi_Ip_UpdateTransferMode(Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->Instance, SPI_IP_INTERRUPT);
        }
    }
    else
    {
        /* Do nothing */
    }
    /* HLD do not require return value. This code to avoid misra violation */
    (void) Spi_Ip_Status;
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Function to manage switching between channels. */
static void Spi_Ipw_EndChannelCallback(uint8 Instance, Spi_JobResultType JobResult)
{
    uint32 SpiCoreID;
    Spi_HWUnitType HwUnit = 0;
    Spi_ChannelType ChannelIndex, NumberOfChannels, ChannelNumber;
    Spi_JobType Job;
    const Spi_Ip_ExternalDeviceType *DspiExternalDevice;
    const Spi_ChannelConfigType *ChannelConfig;
    Spi_NumberOfDataType NumberOfBytes;
    Spi_DataBufferType *RxBuffer;
    const Spi_DataBufferType *TxBuffer; 
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;
    
    HwUnit = Spi_Ipw_au8SpiHWUnitMapping[Instance];
    ChannelIndex = Spi_axSpiHwUnitQueueArray[HwUnit].Channel;
    Job = Spi_axSpiHwUnitQueueArray[HwUnit].Job;
    NumberOfChannels = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg->NumChannels;
   
    if (((ChannelIndex + 1u) < NumberOfChannels) && (SPI_JOB_OK == JobResult))
    {
        Spi_axSpiHwUnitQueueArray[HwUnit].Channel++;
        ChannelIndex++;
        ChannelNumber = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg->ChannelIndexList[ChannelIndex];
        DspiExternalDevice = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.DspiExternalDeviceConfig;
        ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[ChannelNumber].ChannelCfg;
        NumberOfBytes = ChannelConfig->ChannelState->Length;
        RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if(EB == ChannelConfig->BufferType)
        {
            TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
        }
        else
        {
            TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
        }
        if(ChannelIndex == (NumberOfChannels - 1u))
        {
            /* Clear CS after current channel */
            Spi_Ip_apxStateStructureArray[Instance]->KeepCs = (boolean)FALSE;
        }
        else
        {
            Spi_Ip_apxStateStructureArray[Instance]->KeepCs = (boolean)TRUE;
        }        
        /* update default data, Frame size, Lsb mode */
        DspiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
        DspiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
        DspiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
        (void)Spi_Ip_AsyncTransmit(DspiExternalDevice, (const uint8*)TxBuffer, RxBuffer, NumberOfBytes, &Spi_Ipw_Callback);
    }
    else
    {
        Spi_JobTransferFinished(Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg, JobResult);
    }
 }

/* DSPI/SPI end of channel callback. */
static void Spi_Ipw_Callback(uint8 Instance, Spi_Ip_EventType Event)
{
    if (Event != SPI_IP_EVENT_END_TRANSFER)
    {
        Spi_Ipw_EndChannelCallback(Instance, SPI_JOB_FAILED);
    }
    else
    {
        Spi_Ipw_EndChannelCallback(Instance, SPI_JOB_OK);
    }
}

#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
static void Spi_Ipw_SequenceDmaFastTransfer(const Spi_SequenceConfigType *SequenceConfig, uint8 HWUnit, uint32 SpiCoreID)
{
    Spi_Ip_FastTransferType *DmaFastTransferCfg = Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IpConfig.DspiFastTransferCfg;
    uint8 TransferCount = 0u;
    Spi_JobType JobsCount;
    const Spi_JobType *JobIndexList;
    const Spi_JobConfigType *JobConfig;
    const Spi_ChannelConfigType *ChannelConfig;
    Spi_ChannelType ChannelID;
    Spi_ChannelType NumChannelsInJob;
    Spi_ChannelType ChannelIndex;

    /* Get the number of Jobs in the sequence */
    JobsCount = SequenceConfig->NumJobs;
    JobIndexList = SequenceConfig->JobIndexList;
    while (0u < JobsCount)
    {
        /* Set the Job Status as pending */
        Spi_axSpiJobState[*JobIndexList].Result = SPI_JOB_PENDING;
        JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[*JobIndexList].JobCfg;
        NumChannelsInJob = JobConfig->NumChannels;
        for (ChannelIndex = (Spi_ChannelType)0; ChannelIndex < NumChannelsInJob; ChannelIndex++)
        {
            ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
            ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[ChannelID].ChannelCfg;
            DmaFastTransferCfg[TransferCount].Length = ChannelConfig->ChannelState->Length;
            DmaFastTransferCfg[TransferCount].RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
            if(0u != (ChannelConfig->ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
            {
                DmaFastTransferCfg[TransferCount].TxBuffer = NULL_PTR;
            }
            else
            {
                if(EB == ChannelConfig->BufferType)
                {
                    DmaFastTransferCfg[TransferCount].TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
                }
                else
                {
                    DmaFastTransferCfg[TransferCount].TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
                }
            }
            
            if (JobConfig->ExternalDeviceConfig->ExDeviceConfig->IpType == SPI_OVER_SPI)
            {
                DmaFastTransferCfg[TransferCount].ExternalDevice = JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.DspiExternalDeviceConfig;
                if(ChannelIndex == (NumChannelsInJob - 1u))
                {
                    /* Clear CS after current channel */
                    DmaFastTransferCfg[TransferCount].KeepCs = (boolean)FALSE;
                }
                else
                {
                    DmaFastTransferCfg[TransferCount].KeepCs = (boolean)TRUE;
                }
                /* For Dma Fast transfer, All transfers use the same HWUnit and in Master Mode only. Only some parameters can be changed as Continuous CS, PCS.
                Some parameters such as Baudrate, Clock Polarity, Clock Phase, Delays timming configuration, Bit Order, Frame Size
                must be the same between transfers. So, make sure they are configured the same in each External Device, Channel allocated to Jobs for Dma Fast Transfers. */
                /* update default data */
                DmaFastTransferCfg[TransferCount].DefaultData = ChannelConfig->DefaultTransmitValue;
                (void)Spi_Ip_UpdateFrameSize(DmaFastTransferCfg[TransferCount].ExternalDevice, ChannelConfig->FrameSize);
                (void)Spi_Ip_UpdateLsb(DmaFastTransferCfg[TransferCount].ExternalDevice, ChannelConfig->Lsb);
            }
            else
            {
                /* Do nothing */
            }
            TransferCount++;
        }
        /* iterate to next Job in sequence */
        JobIndexList++;
        JobsCount--;
    } /* while (JobsCount > 0u) */

    /* Because of all Channels and all Jobs are transferred successfully when Spi_Ipw_Callback called.
    So, remaining of Channels in current Job must set to 0, this will lead to Spi_JobTransferFinished() called when Spi_Ipw_Callback called.
    And Spi_JobTransferFinished() will set remainning of Job to 0 and set all Jobs result to SPI_JOB_OK, unlock all Jobs for this Dma Fast Sequence. */
    Spi_axSpiHwUnitQueueArray[HWUnit].Channel = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Spi_axSpiHwUnitQueueArray[HWUnit].Job].JobCfg->NumChannels - 1u;

    (void)Spi_Ip_AsyncTransmitFast(DmaFastTransferCfg, TransferCount, &Spi_Ipw_Callback);
}
#endif

/* Triggers first channel of the Job. */
void Spi_Ipw_JobTransfer(const Spi_JobConfigType *JobConfig)
{
    const Spi_Ip_ExternalDeviceType *DspiExternalDevice;
    uint8 Instance;
    const Spi_ChannelConfigType *ChannelConfig;
    Spi_NumberOfDataType NumberOfBytes;
    Spi_DataBufferType *RxBuffer;
    const Spi_DataBufferType *TxBuffer;
    uint32 SpiCoreID;
    #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
    const Spi_SequenceConfigType *SequenceConfig = JobConfig->JobState->AsyncCrtSequenceState->Sequence;
    #endif

    /* get core ID */
    SpiCoreID = Spi_GetCoreID;
    /* Perform Job StartNotification (if there is one) */
    if (NULL_PTR != JobConfig->StartNotification)
    {
        JobConfig->StartNotification();
    }
    else
    {
        /* Do nothing */
    }
    
    #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
    if((boolean)TRUE == SequenceConfig->EnableDmaFastTransfer)
    {
        Spi_Ipw_SequenceDmaFastTransfer(SequenceConfig, JobConfig->HWUnit, SpiCoreID);
    }
    else
    #endif
    {
        if (Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[JobConfig->HWUnit].PhyUnitConfig->IpType == SPI_OVER_SPI)
        {
            DspiExternalDevice = JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig.DspiExternalDeviceConfig;
            Instance = JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance;
            ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[JobConfig->ChannelIndexList[0]].ChannelCfg;
            NumberOfBytes = ChannelConfig->ChannelState->Length;
            RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
            if(0u != (ChannelConfig->ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
            {
                TxBuffer = NULL_PTR;
            }
            else
            {
                if(EB == ChannelConfig->BufferType)
                {
                    TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
                }
                else
                {
                    TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
                }
            }

            if(1u == JobConfig->NumChannels)
            {
                /* Clear CS after current channel */
                Spi_Ip_apxStateStructureArray[Instance]->KeepCs = (boolean)FALSE;
            }
            else
            {
                Spi_Ip_apxStateStructureArray[Instance]->KeepCs = (boolean)TRUE;
            }
            /* update default data, Frame size, Lsb mode */
            DspiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
            DspiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
            DspiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
            (void)Spi_Ip_AsyncTransmit(DspiExternalDevice, (const uint8*)TxBuffer, RxBuffer, NumberOfBytes, &Spi_Ipw_Callback);
        }
        else
        {
            /* Do nothing */
        }
    }   
} 
#endif

#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_CANCEL_API == STD_ON))
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
void Spi_Ipw_SlaveCancel(const Spi_JobConfigType *JobConfig)
{
    boolean SlaveMode;
    if (JobConfig->ExternalDeviceConfig->ExDeviceConfig->IpType == SPI_OVER_SPI)
    {
        SlaveMode = Spi_apxSpiConfigPtr[Spi_GetCoreID]->HWUnitConfig[JobConfig->HWUnit].PhyUnitConfig->IpConfig.DspiIpConfig->SlaveMode;
        if((boolean)TRUE == SlaveMode)
        {
            Spi_Ip_Cancel(JobConfig->ExternalDeviceConfig->ExDeviceConfig->Instance);
            Spi_JobTransferFinished(JobConfig, SPI_JOB_FAILED);
        }
    }
    else
    {
        /* Do nothing */
    }
}
    #endif
#endif

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
void Spi_Ipw_SetClockMode(Spi_DualClockModeType ClockMode, const Spi_HWUnitConfigType * HWUnitConfig)
{
    if (HWUnitConfig->IpType == SPI_OVER_SPI)
    {
        Spi_Ip_SetClockMode(HWUnitConfig->Instance, (Spi_Ip_DualClockModeType)ClockMode);
    }
    else
    {
        /* Do nothing */
    }
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
