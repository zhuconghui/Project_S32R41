/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_P03_D2404_ASR_REL_4_7_REV_0000_20240405
*
*   Copyright 2021 - 2024 NXP
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
*   @file
*   @internal
*   @addtogroup UART
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Uart_Ipw.h"
#include "Uart_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define UART_IPW_VENDOR_ID_C                    43
#define UART_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define UART_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define UART_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define UART_IPW_SW_MAJOR_VERSION_C             2
#define UART_IPW_SW_MINOR_VERSION_C             0
#define UART_IPW_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/*Checks against Uart_Ipw.h */
#if (UART_IPW_VENDOR_ID_C!= UART_IPW_VENDOR_ID)
    #error "Uart_Ipw.c and Uart_Ipw.h have different vendor ids"
#endif
#if ((UART_IPW_AR_RELEASE_MAJOR_VERSION_C   != UART_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (UART_IPW_AR_RELEASE_MINOR_VERSION_C   != UART_IPW_AR_RELEASE_MINOR_VERSION) || \
     (UART_IPW_AR_RELEASE_REVISION_VERSION_C!= UART_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Uart_Ipw.c and Uart_Ipw.h are different"
#endif
#if ((UART_IPW_SW_MAJOR_VERSION_C!= UART_IPW_SW_MAJOR_VERSION) || \
     (UART_IPW_SW_MINOR_VERSION_C!= UART_IPW_SW_MINOR_VERSION) || \
     (UART_IPW_SW_PATCH_VERSION_C!= UART_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Uart_Ipw.c and Uart_Ipw.h are different"
#endif

/* Checks against Uart_Ipw_Cfg.h */
#if (UART_IPW_VENDOR_ID_C != UART_IPW_CFG_VENDOR_ID)
    #error "Uart_Ipw.c and Uart_Ipw_Cfg.h have different vendor ids"
#endif
#if ((UART_IPW_AR_RELEASE_MAJOR_VERSION_C    != UART_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (UART_IPW_AR_RELEASE_MINOR_VERSION_C    != UART_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (UART_IPW_AR_RELEASE_REVISION_VERSION_C != UART_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Uart_Ipw.c and Uart_Ipw_Cfg.h are different"
#endif
#if ((UART_IPW_SW_MAJOR_VERSION_C != UART_IPW_CFG_SW_MAJOR_VERSION) || \
     (UART_IPW_SW_MINOR_VERSION_C != UART_IPW_CFG_SW_MINOR_VERSION) || \
     (UART_IPW_SW_PATCH_VERSION_C != UART_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Uart_Ipw.c and Uart_Ipw_Cfg.h are different"
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
#if (UART_CALLBACK_DECLARED == STD_ON)
#define UART_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Uart_MemMap.h"

static sint8 Uart_Ipw_s8HwMapping[LINFLEXD_INSTANCE_COUNT] = UART_IPW_HW_CHANNELS_MAPPING_FOR_INIT;

#define UART_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Uart_MemMap.h"
#endif /* #if (UART_CALLBACK_DECLARED == STD_ON) */

#define UART_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"

static const Uart_Ipw_HwConfigType *Uart_Ipw_apChnConfig[UART_CH_MAX_CONFIG];

#define UART_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Uart_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define UART_START_SEC_CODE
#include "Uart_MemMap.h"

/* Convert Linflexd Status type to Standard status type */
static Uart_StatusType Uart_Ipw_ConvertStatus(Linflexd_Uart_Ip_StatusType Status);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @internal
* @brief   Initialize an Uart channel.
* @details This function calls a LLD function initializes all hardware registers needed to
*          start the Uart functionality on the selected channel.
*
* @param   [in]    Channel  Uart channel to be initialized.
*          [in]    Config Configuration pointer containing hardware specific settings.
*
* @return            void.
*
*/
void Uart_Ipw_Init(uint8 Channel, const Uart_Ipw_HwConfigType* Config)
{
    uint32 HwUnit = Config->UartHwChannel;

#if (UART_CALLBACK_DECLARED == STD_ON)
    /* Save the mapping between hardware instance and logical channel */
    Uart_Ipw_s8HwMapping[HwUnit] = (sint8)Channel;
#endif /* #if (UART_CALLBACK_DECLARED == STD_ON) */
    /* Save the channel settings */
    Uart_Ipw_apChnConfig[Channel] = Config;
    /* Call the LLD Initialization function */
    Linflexd_Uart_Ip_Init((uint8)HwUnit, Config->UserConfig->LinflexdUserConfig);
}
/**
* @internal
* @brief   De-initialize an Uart channel.
* @details This function calls a LLD function de-initializes an Uart Hw instance and resets the current
            information regarding the current channel
*
* @param[in] Channel  Uart channel to be de-initialized.
*
* @return            void.
*
*/
void Uart_Ipw_Deinit(uint8 Channel)
{
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    /* Remove refference to the current channel configuration */
    Uart_Ipw_apChnConfig[Channel] = NULL_PTR;
#if (UART_CALLBACK_DECLARED == STD_ON)
    /* Remove the current hw to logic mapping */
    Uart_Ipw_s8HwMapping[HwUnit] = -1;
#endif /* #if (UART_CALLBACK_DECLARED == STD_ON) */
    (void)Linflexd_Uart_Ip_Deinit((uint8)HwUnit);
}
/**
* @internal
* @brief  Set a baudrate value for the current channel.
* @details This function calls a LLD function which sets a baudrate value for a given channel,
*
* @param[in] Channel          Uart channel where the baudrate shall be configured
* @param[in] BaudRateValue     The baudrate value to be configured.
* @param[in] ClockFrequency  The clock frequency set for the Uart module.
*
* @return   E_OK:     Baud rate successfully configured
*           E_NOT_OK: Baud rate wasn't successfully configured
*
*/
Std_ReturnType Uart_Ipw_SetBaudrate(uint8 Channel, Uart_BaudrateType BaudRateValue, uint32 ClockFrequency)
{
    Linflexd_Uart_Ip_StatusType IpStatus;
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    IpStatus = (Linflexd_Uart_Ip_StatusType)Linflexd_Uart_Ip_SetBaudrate((uint8)HwUnit, (Linflexd_Uart_Ip_BaudrateType)BaudRateValue, ClockFrequency);

    if (LINFLEXD_UART_IP_STATUS_SUCCESS == IpStatus)
    {
        TempStatus = (uint8)E_OK;
    }

    return TempStatus;
}
/**
* @internal
* @brief  Retrieves the baudrate value configured for the current channel.
* @details This function calls a LLD function returns the baudrate value configured for the given channel
* via a pointer parameter provided by user.
*
* @param[in] Channel           Uart channel where the baudrate shall be configured
* @param[out] BaudrateValue     The pointer which will contain the baudrate value.
*
* @return   void
*
*/
void Uart_Ipw_GetBaudrate(uint8 Channel, uint32 *BaudrateValue)
{
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    Linflexd_Uart_Ip_GetBaudrate((uint8)HwUnit, BaudrateValue);
}
/**
* @internal
* @brief  Aborts an on-going transmission.
* @details This function calls a LLD function which ends a transfer earlier.
*
* @param[in] Channel          Uart channel where the transmission shall be ended.
*
* @return   E_OK:     The transfer ended successfully
*           E_NOT_OK: The transfer didn't end successfully
*
*/
Std_ReturnType Uart_Ipw_AbortSendingData(uint8 Channel)
{
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    if (LINFLEXD_UART_IP_STATUS_SUCCESS == (Linflexd_Uart_Ip_StatusType)Linflexd_Uart_Ip_AbortSendingData((uint8)HwUnit))
    {
        TempStatus = (uint8)E_OK;
    }
    return TempStatus;
}
/**
* @internal
* @brief  Aborts an on-going reception.
* @details This function calls a LLD function which ends a reception earlier.
*
* @param[in] Channel          Uart channel where the reception shall be ended.
*
* @return   E_OK:     The reception ended successfully
*           E_NOT_OK: The reception didn't end successfully
*
*/
Std_ReturnType Uart_Ipw_AbortReceivingData(uint8 Channel)
{
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    if (LINFLEXD_UART_IP_STATUS_SUCCESS == (Linflexd_Uart_Ip_StatusType)Linflexd_Uart_Ip_AbortReceivingData((uint8)HwUnit))
    {
        TempStatus = (uint8)E_OK;
    }
    return TempStatus;
}
/**
* @internal
* @brief  Sets a tx buffer.
* @details This function calls a LLD function which sets a buffer for continuos transmission.
*
* @param[in] Channel  Uart channel where to set the buffer.
*
* @return  void
*/
void Uart_Ipw_SetTxBuffer(uint8 Channel, const uint8 *Buffer, uint32 BufferSize)
{
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    Linflexd_Uart_Ip_SetTxBuffer((uint8)HwUnit, Buffer, BufferSize);
}
/**
* @brief  Sets a rx buffer.
* @details This function calls a LLD function which sets a buffer for continuos reception.
*
* @param[in] Channel  Uart channel where to set the buffer.
*
* @return  void
*/
void Uart_Ipw_SetRxBuffer(uint8 Channel, uint8 *Buffer, uint32 BufferSize)
{
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    Linflexd_Uart_Ip_SetRxBuffer((uint8)HwUnit, Buffer, BufferSize);
}
/**
* @internal
* @brief  Sends a buffer synchronously.
* @details This function calls a LLD function which sends BufferSize bytes using polling method.
*
* @param[in] Channel     Uart channel used for transmission.
* @param[in] Buffer      Buffer to send.
* @param[in] BufferSize  The number of bytes to send.
* @param[in] Timeout     The timeout value in us.
*
*
* @return   E_OK:                   Tranmission ended successfully
*           UART_STATUS_TIMEOUT:         Tranmission has timeout
*/

Std_ReturnType Uart_Ipw_SyncSend(uint8 Channel, const uint8 *Buffer, uint32 BufferSize, uint32 Timeout)
{
    Linflexd_Uart_Ip_StatusType IpStatus;
    Std_ReturnType TempStatus;
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    IpStatus = (Linflexd_Uart_Ip_StatusType)Linflexd_Uart_Ip_SyncSend((uint8)HwUnit,
                                                                      Buffer,
                                                                      BufferSize,
                                                                      Timeout);
    if (LINFLEXD_UART_IP_STATUS_SUCCESS == IpStatus)
    {
        TempStatus = (uint8)E_OK;
    }
    else if (LINFLEXD_UART_IP_STATUS_TIMEOUT == IpStatus)
    {
        TempStatus = (uint8)UART_STATUS_TIMEOUT;
    }
    else
    {
        TempStatus = (uint8)E_NOT_OK;
    }

    return TempStatus;
}
/**
* @internal
* @brief  Receives a buffer synchronously.
* @details This function calls a LLD function which receives BufferSize bytes using polling method.
*
* @param[in] Channel      Uart channel used for reception.
* @param[in] Buffer        Buffer to receive.
* @param[in] BufferSize  The number of bytes to receive.
* @param[in] Timeout        The timeout value in us.
*
*
* @return   E_OK:               Reception ended successfully
*           E_NOT_OK:           Reception didn't end successfully
*           UART_STATUS_TIMEOUT:     Reception has timeout
*/
Std_ReturnType Uart_Ipw_SyncReceive(uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout)
{
    Linflexd_Uart_Ip_StatusType IpStatus;
    Std_ReturnType TempStatus;
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    IpStatus = (Linflexd_Uart_Ip_StatusType)Linflexd_Uart_Ip_SyncReceive((uint8)HwUnit,
                                                                         Buffer,
                                                                         BufferSize,
                                                                         Timeout);

    if (LINFLEXD_UART_IP_STATUS_SUCCESS == IpStatus)
    {
        TempStatus = (uint8)E_OK;
    }
    else if (LINFLEXD_UART_IP_STATUS_TIMEOUT == IpStatus)
    {
        TempStatus = (uint8)UART_STATUS_TIMEOUT;
    }
    else
    {
        TempStatus = (uint8)E_NOT_OK;
    }

    return TempStatus;
}
/**
* @internal
* @brief  Receives a buffer asynchronously.
* @details This function calls a LLD function which receives BufferSize bytes using an asynchornous method.
*
* @param[in] Channel      Uart channel used for reception.
* @param[in] Buffer        Buffer to receive.
* @param[in] BufferSize  The number of bytes to receive.
*
*
* @return   E_OK:               Reception started successfully
            E_NOT_OK:           Reception didn't start successfully
*/
Std_ReturnType Uart_Ipw_AsyncReceive(uint8 Channel, uint8 *Buffer, uint32 BufferSize)
{
    Linflexd_Uart_Ip_StatusType IpStatus;
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    IpStatus = (Linflexd_Uart_Ip_StatusType)Linflexd_Uart_Ip_AsyncReceive((uint8)HwUnit,
                                                                          Buffer,
                                                                          BufferSize);
    if (LINFLEXD_UART_IP_STATUS_SUCCESS == IpStatus)
    {
        TempStatus = (uint8)E_OK;
    }

    return TempStatus;
}
/**
* @internal
* @brief  Sends a buffer asynchronously.
* @details This function calls a LLD function which sends BufferSize bytes using an asynchornous method.
*
* @param[in] Channel      Uart channel used for transmission.
* @param[in] Buffer        Buffer to send.
* @param[in] BufferSize  The number of bytes to send.
*
*
* @return   E_OK:               Transmission started successfully
            E_NOT_OK:           Transmission didn't start successfully
*/
Std_ReturnType Uart_Ipw_AsyncSend(uint8 Channel, const uint8 *Buffer, uint32 BufferSize)
{
    Linflexd_Uart_Ip_StatusType IpStatus;
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    IpStatus = (Linflexd_Uart_Ip_StatusType)Linflexd_Uart_Ip_AsyncSend((uint8)HwUnit,
                                                                       Buffer,
                                                                       BufferSize);
    if (LINFLEXD_UART_IP_STATUS_SUCCESS == IpStatus)
    {
        TempStatus = (uint8)E_OK;
    }

    return TempStatus;
}


/**
* @internal
* @brief  Retrieves the status of the previous transfer.
* @details This function calls a LLD function which retrieves the status of the previous transfer
*          and the number of the remaining bytes to send.
*
* @param[in] Channel   Uart channel.
* @param[out] BytesRemaining   The pointer where to write the number of remaining bytes
*
*
* @return   UART_NO_ERR0R:                  The previous transfer ended successfully
            UART_STATUS_OPERATION_ONGOING      The transfer is still on going
            UART_STATUS_ABORTED            The previous transfer was aborted
            UART_STATUS_TIMEOUT          The previous transfer was timeout

*/
Uart_StatusType Uart_Ipw_GetTransmitStatus(uint8 Channel, uint32 *BytesRemaining)
{
    Linflexd_Uart_Ip_StatusType IpStatus;
    Uart_StatusType TempStatus;
    uint32 HwUnit = Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    IpStatus = Linflexd_Uart_Ip_GetTransmitStatus((uint8)HwUnit, BytesRemaining);
    TempStatus = Uart_Ipw_ConvertStatus(IpStatus);

    return TempStatus;
}

/**
* @internal
* @brief  Retrieves the status of the previous reception.
* @details This function calls a LLD function which retrieves the status of the previous reception
*          and the number of the remaining bytes to receive.
*
* @param[in] Channel   Uart channel.
* @param[out] BytesRemaining   The pointer where to write the number of remaining bytes
*
*
* @return   UART_NO_ERR0R:                  The previous transfer ended successfully
            UART_STATUS_OPERATION_ONGOING      The reception is still on going
            UART_STATUS_ABORTED            The previous reception was aborted
            UART_STATUS_FRAMING_ERROR     Uart framing error
            UART_STATUS_RX_OVERRUN_ERROR  Uart overrun error
            UART_STATUS_PARITY_ERROR       Uart overrun error
            UART_STATUS_TIMEOUT          Uart operation has timeout

*/
Uart_StatusType Uart_Ipw_GetReceiveStatus(uint8 Channel, uint32 *BytesRemaining)
{
    Linflexd_Uart_Ip_StatusType IpStatus;
    Uart_StatusType TempStatus;
    uint32 HwUnit = (uint8)Uart_Ipw_apChnConfig[Channel]->UartHwChannel;

    IpStatus = Linflexd_Uart_Ip_GetReceiveStatus((uint8)HwUnit, BytesRemaining);
    TempStatus = Uart_Ipw_ConvertStatus(IpStatus);

    return TempStatus;

}

/**
* @internal
* @brief  Convert Uart IP layer return status to standard return status.
* @details This function receives Uart IP layer return status and convert to standard return status.
* @param[in] Status        Uart IP status
*
*
* @return   Standard status
* This is not a public API as it is called from other driver functions.
*/
static Uart_StatusType Uart_Ipw_ConvertStatus(Linflexd_Uart_Ip_StatusType Status)
{
    Uart_StatusType TempStatus = UART_STATUS_TIMEOUT;

    switch (Status)
    {
        case LINFLEXD_UART_IP_STATUS_SUCCESS:
            TempStatus = UART_STATUS_NO_ERROR;
            break;

        case LINFLEXD_UART_IP_STATUS_BUSY:
            TempStatus = UART_STATUS_OPERATION_ONGOING;
            break;

        case LINFLEXD_UART_IP_STATUS_ABORTED:
            TempStatus = UART_STATUS_ABORTED;
            break;

        case LINFLEXD_UART_IP_STATUS_TIMEOUT:
            TempStatus = UART_STATUS_TIMEOUT;
            break;

        case LINFLEXD_UART_IP_STATUS_FRAMING_ERROR:
            TempStatus = UART_STATUS_FRAMING_ERROR;
            break;

        case LINFLEXD_UART_IP_STATUS_RX_OVERRUN:
            TempStatus = UART_STATUS_RX_OVERRUN_ERROR;
            break;
        case LINFLEXD_UART_IP_STATUS_NOISE_ERROR:
            TempStatus = UART_STATUS_NOISE_ERROR;
            break;
        case LINFLEXD_UART_IP_STATUS_PARITY_ERROR:
            TempStatus = UART_STATUS_PARITY_ERROR;
            break;
        case LINFLEXD_UART_IP_STATUS_DMA_ERROR:
            TempStatus = UART_STATUS_DMA_ERROR;
            break;
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
        case LINFLEXD_UART_IP_STATUS_RX_IDLE_STATE:
            TempStatus = UART_STATUS_RX_IDLE_STATE;
            break;
#endif
        default:
            /* Do nothing */
            break;
    }

    return TempStatus;
}
#if (UART_CALLBACK_DECLARED == STD_ON)
/**
* @internal
* @internal
* @brief   Low level driver User callback
* @details This function is called by the low level driver in the ISR.
*
*
* This is not a public API as it is called from other driver functions.
*/
void Uart_Ipw_Callback(const uint8 HwInstance,const Linflexd_Uart_Ip_EventType Event, void *UserData)
{
    (void)UserData;
    uint8 Channel = (uint8)Uart_Ipw_s8HwMapping[HwInstance];

    if (Uart_Ipw_apChnConfig[Channel]->Callback != NULL_PTR)
    {
        Uart_Ipw_apChnConfig[Channel]->Callback(Channel, (Uart_EventType)Event);
    }
}

#endif /* #if (UART_CALLBACK_DECLARED == STD_ON) */


#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
