/**************************************************************************************************
* Copyright 2022-2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : RFE_abstract 2.0
 *   Platform             : S32R41
 *****************************************************************************/


/*
* @page misra_violations MISRA-C:2012 violations
*
* @section rfe_low_level_c_REF_1
* Violates MISRA 2012 Required Rule 11.6
* #A cast shall not be performed between pointer to void and an arithmetic type.
* Necessary to use a physical address as pointer value.
*
* @section rfe_low_level_c_REF_2
* Violates MISRA 2012 Required Rule 5.1
* #External identifiers shall be distinct.
* Function naming template used.
*
* @section rfe_low_level_c_REF_3
* Violates MISRA 2012 Advisory Rule 10.5
* #The value of an expression should not be cast to an inappropriate essential type.
* Necessary cast as the function used returns uint16_t.
*
*/


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include "rfe_cmd_interface.h"
#include "rfe_cmd_client.h"
#include "rfe_low_level.h"
#include "rfe_cfg_blob.h"
#include "rfe_blob_access.h"
#include "rfe_register_dump.h"
#include <stddef.h>
#include "Rfe20_PCCfg.h"

/******************************************************************************
 *                              DEFINES
 *****************************************************************************/
/**
 * The shift for size part of a configuration parameter.
 */
#define RFE_CFG_PARAM_SIZE_SHF              (11UL)

/**
 * The normal size for the CRC, received or calculated
 */
#define RFE_CFG_CRC_SIZE                    (4UL)


/******************************************************************************
 *                              ENUMS AND TYPES
 *****************************************************************************/

/******************************************************************************
 *                              LOCAL VARIABLES
 *****************************************************************************/
static rfeCmdClient_update_t    updates[RFE_UPDATE_COUNT_MAX];
static uint8_t                  updateCount = 0U;


/******************************************************************************
 *                              LOCAL FUNCTIONS
 *****************************************************************************/
/*------------------------------------------------------------------------------*/
/**
 * \brief  Retrieves the size of a configuration data item.
 *
 * \pre    NIL
 *
 * \param [in]          param                       The parameter to search.
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *
 * \return The size of the specified configuration data item.
 *
 * \post   NIL
 */
static rfeCfg_size_t rfe_getParamSize(rfeCfg_param_t param, volatile rfe_error_t* rfe___error___pointer)
{
    rfeCfg_size_t size = rfeCfg_size_invalid_e;

    switch ((uint16_t)param & (uint16_t)RFE_CFG_PARAM_SIZE_MSK)
    {
        case (uint16_t)RFE_CFG_PARAM_SIZE_8_BIT:
            size = rfeCfg_size_8_bit_e;
            break;
        case (uint16_t)RFE_CFG_PARAM_SIZE_16_BIT:
            size = rfeCfg_size_16_bit_e;
            break;
        case (uint16_t)RFE_CFG_PARAM_SIZE_32_BIT:
            size = rfeCfg_size_32_bit_e;
            break;
        default:
            *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
            break;
    }
    return size;
}
/*---- rfe_getParamSize ----------------*/


/*------------------------------------------------------------------------------*/
/**
 * \brief  Retrieves the offset of a configuration data item.
 *
 * \pre    NIL
 *
 * \param [in]          section                     The section of the parameter.
 * \param [in]          param                       The parameter to search.
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *
 * \return The size of the specified configuration data item.
 *
 * \post   NIL
 */
static uint16_t rfe_getParamOffset(rfeCfg_section_t section, rfeCfg_param_t param,
                                volatile rfe_error_t* rfe___error___pointer)
{
    uint16_t offset = 0U;

    if(((uint16_t)section & (uint16_t)RFE_CFG_PARAM_SECTION_MSK) ==
                        ((uint16_t)param & (uint16_t)RFE_CFG_PARAM_SECTION_MSK))
    {
        offset  = ((uint16_t)section & (uint16_t)RFE_CFG_PARAM_OFFSET_MSK) >> RFE_CFG_PARAM_OFFSET_SHF;
        offset += ((uint16_t)param & (uint16_t)RFE_CFG_PARAM_OFFSET_MSK) >> RFE_CFG_PARAM_OFFSET_SHF;
    }
    else
    {
        *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
    }
    return offset;
}
/*---- rfe_getParamOffset ----------------*/


/*==============================================================================*/
/**
 * \brief  Reads a configuration item.
 *
 * \pre    NIL
 *
 * \param [in]          pConfig                     Pointer to the configuration item memory.
 * \param [in]          section                     The section of the parameter.
 * \param [in]          param                       The parameter.
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *
 * \return The value of the configuration item.
 *
 * \post   NIL
 */
static uint32_t rfe_read_cfg(const uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param,
                        volatile rfe_error_t* rfe___error___pointer)
{
    rfeCfg_size_t   size;
    uint32_t        value = 0UL;

    uint16_t offset = rfe_getParamOffset(section, param, rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        size = rfe_getParamSize(param, rfe___error___pointer);
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            switch (size)
            {
                case rfeCfg_size_32_bit_e:
                    value  =  (uint32_t)pConfig[offset + 0U];
                    value |= ((uint32_t)pConfig[offset + 1U]) << 8U;
                    value |= ((uint32_t)pConfig[offset + 2U]) << 16U;
                    value |= ((uint32_t)pConfig[offset + 3U]) << 24U;
                    break;
                case rfeCfg_size_16_bit_e:
                    value  =  (uint32_t)pConfig[offset + 0U];
                    value |= ((uint32_t)pConfig[offset + 1U]) << 8U;
                    break;
                case rfeCfg_size_8_bit_e:
                    value  =   (uint32_t)pConfig[offset + 0U];
                    break;
                default:
                    *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
                    break;
            }
        }
    }
    return value;
}
/*==== rfe_read_cfg ================*/


/*==============================================================================*/
/**
 * \brief  Calculate the necessary space for blob transfer, according to the blob parameters
 *
 * \pre    NIL
 *
 * \param [in]          pConfig                     Pointer to the configuration item memory.
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *
 * \return The blob length.
 *
 * \post   NIL
 */
static uint32_t rfe_get_blob_len(const uint8_t *pConfig, volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t     chirpSequenceConfigCount, chirpProfileCount, chirpSequenceProfileCount;
    uint32_t    configSize = 0;

    /* compute all necessary transfer parameters                                    */
    chirpSequenceConfigCount = (uint8_t)rfe_read_cfg(pConfig, rfeCfg_section_metadata_e,
                rfeCfg_param_metadata_chirpSequenceConfigCount_e, rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        chirpProfileCount = (uint8_t)rfe_read_cfg(pConfig, rfeCfg_section_metadata_e,
                rfeCfg_param_metadata_chirpProfileCount_e, rfe___error___pointer);
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            chirpSequenceProfileCount =
                (chirpSequenceConfigCount > chirpProfileCount) ? chirpSequenceConfigCount : chirpProfileCount;

            configSize = (uint32_t)chirpSequenceProfileCount *
                    (uint32_t)(RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE);
            configSize += (uint32_t)(RFE_CFG_SIZE_SECTION_METADATA + RFE_CFG_SIZE_SECTION_GENERAL +
                        RFE_CFG_SIZE_SECTION_MONITOR_AND_SAFETY + RFE_CFG_SIZE_SECTION_RADAR_CYCLE);
        }
    }
    return configSize;
}
/*==== rfe_get_blob_len ================*/

/*==============================================================================*/
/**
 * \brief  Fill the config transfer space with necessary data
 *
 * \pre    NIL
 *
 * \param [in]          len                     the total length of the data to be sent
 * \param [out]         msgCount                the expected number of the packets to send
 * \param [out]         lastPacketSize          the length of the last packet to be sent
 * \param [in]          isConfig                discriminator for config_blob / dynamic_table, 0 means dynamic table
 *
 * \return The blob length.
 *
 * \post   NIL
 */
static uint16_t rfe_get_transfer_param(uint16_t len, uint16_t *msgCount, uint32_t *lastPacketSize, uint8_t isConfig)
{
    uint16_t    msgNum, lenCorrection = 0U;
    uint32_t    lastP;
    
    msgNum = (uint16_t)(len / (uint16_t)RFE_CFG_MAX_DATA_LENGTH);                 // base num packets
    lastP = len % RFE_CFG_MAX_DATA_LENGTH;                  // last packet size
    if(lastP != 0U)
    {
        msgNum++;                                           // add a partial message for final packet
    }
    else
    {
        if(isConfig == 0U)
        {
            lastP = RFE_CFG_MAX_DATA_LENGTH;           // the last packet for dynamic table has maximum size
        }
        else
        {
            // for blob we do a trick to signal the last message in the flow
            if(len == RFE_CFG_SIZE_TOTAL)
            {
                lastP = RFE_CFG_MAX_DATA_LENGTH;        // the last packet for blob has maximum size, as the maximum blob length is get
            }
            else
            {
                lenCorrection = 1U;                     // adding a supplementary byte to the message
                msgNum++;                               // adding a supplementary packet of one byte
                lastP = 1U;                             // the last message has only one byte
            }
        }
    }
    *msgCount = msgNum;
    *lastPacketSize = lastP;
    return lenCorrection;
}
/*==== rfe_get_transfer_param ================*/

/*==============================================================================*/
/**
 * \brief  Fill the transfer buffer with necessary data, including CRC if necessary
 *
 * \param [in]      cfgBufPtr       pointer to the start of the buffer to be sent
 * \param [in]      bytesSent       the number of bytes already sent
 * \param [in]      bytesToSend     the length of the current packet to be sent
 * \param [in]      cfgSize         the total length of the data to be sent
 * \param [in]      crcIdx          the current CRC byte to be sent
 * \param [in]      crc             the CRC for the full configuration buffer
 *
 *
 * \return The new CRC index.
 *
 */
static uint32_t rfe_fillBuffer(void *cfgBufPtr, uint16_t bytesSent, uint16_t bytesToSend, uint32_t cfgSize, uint32_t crcIdx, uint32_t crc,
         volatile rfe_error_t* rfe___error___pointer)
{
    uint32_t crcLen;
    uint32_t crcW = crc, crcIdxW = crcIdx;

    if(((uint32_t)bytesSent + (uint32_t)bytesToSend) > (cfgSize - RFE_CFG_CRC_SIZE))
    {
        // we are including at least a part of the blob CRC in the message, so manage it
        crcLen = (uint32_t)bytesSent + (uint32_t)bytesToSend - cfgSize + RFE_CFG_CRC_SIZE;        // the number of CRC bytes to send
        // copy the blob buffer to the transfer data
        rfeCmdClient_cmdParamAddBuffer((uint8_t*)cfgBufPtr + bytesSent, (uint32_t)bytesToSend - (crcLen - crcIdxW), rfe___error___pointer);
        // adding the CRC bytes
        while(crcIdxW < crcLen)
        {
            rfeCmdClient_cmdParamAddUint8((uint8_t)(crcW >> (crcIdxW * 8UL)), rfe___error___pointer);
            crcIdxW++;
        }
    }
    else
    {
        rfeCmdClient_cmdParamAddBuffer((uint8_t*)cfgBufPtr + bytesSent, (uint32_t)bytesToSend, rfe___error___pointer);
    }
    return crcIdxW;
}
/*==== rfe_fillBuffer ================*/

/*==============================================================================*/
/**
 * \brief  Fill the monitor values with the specific RxSaturation values.
 *
 * \param [in]      monitorSelect               monitors select mask
 * \param [in]      pMonitorValues              pointer to the monitor values structure
 * \param [in]      rfe___error___pointer       pointer to the current error value
 *
 */
static void rfe_monitorReadRxSaturation(rfe_monitorSelect_t monitorSelect, rfe_monitorValues_t *pMonitorValues,
        volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t rxIndex;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if(((uint32_t)monitorSelect & RFE_MONITOR_SELECT_RX_SAT_COUNT_STAGE_1I ) != 0UL )
        {
            for(rxIndex = (uint8_t)rfe_rxIndex_1_e; rxIndex < (RFE_RX_COUNT * RFE_MAX_SUPPORTED_DEVICES); rxIndex++)
            {
                if(*rfe___error___pointer != rfe_error_none_e)
                {
                    break;
                }
                pMonitorValues->rxSaturationClippingCount[rxIndex] = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
            }
        }
    }
}
/*==== rfe_monitorReadRxSaturation ================*/

/*==============================================================================*/
/**
 * \brief  Fill the monitor values with the specific PdcClipping values.
 *
 * \param [in]      monitorSelect               monitors select mask
 * \param [in]      pMonitorValues              pointer to the monitor values structure
 * \param [in]      rfe___error___pointer       pointer to the current error value
 *
 */
static void rfe_monitorReadPdcClipping(rfe_monitorSelect_t monitorSelect, rfe_monitorValues_t *pMonitorValues,
        volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t rxIndex;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if ( ((uint32_t)monitorSelect & RFE_MONITOR_SELECT_PDC_CLIPPING_COUNT ) != 0UL )
        {
             for ( rxIndex = (uint8_t)rfe_rxIndex_1_e; rxIndex < (RFE_RX_COUNT * RFE_MAX_SUPPORTED_DEVICES); rxIndex++ )
             {
                if(*rfe___error___pointer != rfe_error_none_e)
                {
                    break;
                }
                pMonitorValues->pdcClippingCount[rxIndex] = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
             }
        }
    }
}
/*==== rfe_monitorReadPdcClipping ================*/

/*==============================================================================*/
/**
 * \brief  Fill the monitor values with the specific TemperatureBeforeChirp values.
 *
 * \param [in]      monitorSelect               monitors select mask
 * \param [in]      pMonitorValues              pointer to the monitor values structure
 * \param [in]      rfe___error___pointer       pointer to the current error value
 *
 */
static void rfe_monitorReadTempBefore(rfe_monitorSelect_t monitorSelect, rfe_monitorValues_t *pMonitorValues,
        volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t rxIndex;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if((monitorSelect & RFE_MONITOR_SELECT_TEMP_BEFORE_CHIRP_SEQ) != 0U)
        {
            for(rxIndex = (uint8_t)rfe_temperatureSensorIndex_tx1_e; rxIndex < (RFE_TEMPERATURE_SENSOR_COUNT * RFE_MAX_SUPPORTED_DEVICES); rxIndex++)
            {
                if(*rfe___error___pointer != rfe_error_none_e)
                {
                    break;
                }
                pMonitorValues->temperature_beforeChirpSequence[rxIndex] = (rfe_temperature_t)rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
            }
        }
    }
}
/*==== rfe_monitorReadTempBefore ================*/

/*==============================================================================*/
/**
 * \brief  Fill the monitor values with the specific TemperatureAfterChirp values.
 *
 * \param [in]      monitorSelect               monitors select mask
 * \param [in]      pMonitorValues              pointer to the monitor values structure
 * \param [in]      rfe___error___pointer       pointer to the current error value
 *
 */
static void rfe_monitorReadTempAfter(rfe_monitorSelect_t monitorSelect, rfe_monitorValues_t *pMonitorValues,
        volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t rxIndex;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if((monitorSelect & RFE_MONITOR_SELECT_TEMP_AFTER_CHIRP_SEQ) != 0U)
        {
            for(rxIndex = (uint8_t)rfe_temperatureSensorIndex_tx1_e; rxIndex < (RFE_TEMPERATURE_SENSOR_COUNT * RFE_MAX_SUPPORTED_DEVICES); rxIndex++)
            {
                if(*rfe___error___pointer != rfe_error_none_e)
                {
                    break;
                }
                pMonitorValues->temperature_afterChirpSequence[rxIndex] = (rfe_temperature_t)rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
            }
        }
    }
}
/*==== rfe_monitorReadTempAfter ================*/

/*==============================================================================*/
/**
 * \brief  Fill the monitor values with the specific current temperature values.
 *
 * \param [in]      monitorSelect               monitors select mask
 * \param [in]      pMonitorValues              pointer to the monitor values structure
 * \param [in]      rfe___error___pointer       pointer to the current error value
 *
 */
static void rfe_monitorReadTempNow(rfe_monitorSelect_t monitorSelect, rfe_monitorValues_t *pMonitorValues,
        volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t rxIndex;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if((monitorSelect & RFE_MONITOR_SELECT_TEMP_IMMEDIATELY) != 0U)
        {
            for(rxIndex = (uint8_t)rfe_temperatureSensorIndex_tx1_e; rxIndex < (RFE_TEMPERATURE_SENSOR_COUNT * RFE_MAX_SUPPORTED_DEVICES); rxIndex++)
            {
                if(*rfe___error___pointer != rfe_error_none_e)
                {
                    break;
                }
                pMonitorValues->temperature_immediately[rxIndex] = (rfe_temperature_t)rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
            }
        }
    }
}
/*==== rfe_monitorReadTempNow ================*/

/******************************************************************************
 *                              GLOBAL FUNCTIONS
 *****************************************************************************/


/*==============================================================================*/
/**
 *
 *  \brief This function synchronizes the rfeDriver on M7-0 core with the RFE-Fw running on M7-1 core.
 *
 *  \details This is the first RFE Driver function to be called. The first call to this
 *  function initiates the control core <-> RFE-Fw synchronization protocol and always fails.
 *  This function shall be called until the #rfe_error_api_unresponsive_e error is not set anymore,
 *  which indicates that the synchronization protocol was executed successfully.
 *  The error is get using CDD_Rfe_GetError() funtion.
 *
 *  This function can set one of following errors:
 *  - #rfe_error_api_unresponsive_e
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *
 *  \pre The RFE-Fw (M7-1 core) must be started.
 *
 *  \return NIL
 *
 *  \post RFE-Fw will be in #rfe_state_initialized_e state after the correct initialization.
 *
 *  \ingroup NIL
 *
 */
void rfe_sync(volatile rfe_error_t* rfe___error___pointer)
{
    rfe_state_t state;

    /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()                */
    *rfe___error___pointer = rfe_error_none_e;
    /* Note: The init function of the command client is non-blocking */
    /*
    * @violates @section rfe_low_level_c_REF_1, #A cast shall not be performed between pointer to void
    *                                               and an arithmetic type.
    */
    rfeCmdClient_init((void*)RFE_CMD_CLIENT_BASE_ADDRESS, rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        /*
        * @violates @section rfe_low_level_c_REF_3, #The value of an expression should not be cast to
        *                                               an inappropriate essential type.
        */
        state = (rfe_state_t)rfeCmdClient_sharedDataRead((uint32_t)rfeCmdClient_sharedParameter_state_e,
                                                            rfe___error___pointer);
        if((*rfe___error___pointer == rfe_error_none_e) && (state == rfe_state_busy_e))
        {
            *rfe___error___pointer = rfe_error_api_unresponsive_e;
        }
    }
}
/*==== rfe_sync ================*/


/*==============================================================================*/
/**
 *  \brief This function fully send the blob to the RFE-Fw.
 *
 *  All parameters are already prepared, this separate function is intended only for reducing the CCM size of the original rfe_config function.
 *
 */
static void BlobDataSend(uint8_t *pConfig, rfe_sysMemAddress_t dynamicTableAddress, uint16_t msgCountTotal, uint16_t msgCountBlob, uint32_t lastPacketSizeBlob, uint32_t blobSize,
        uint32_t crcBlob, uint32_t dynTabSize, uint32_t lastPacketSizeDynTab, volatile rfe_error_t* rfe___error___pointer)
{
    uint32_t    crcIdx, crcW = 0UL;
    uint16_t    msgIndex,               // current message index
                bytesSentBlob = 0u,     // sent bytes blob
                bytesToSend,            // current packet length
                bytesSentDynTab = 0u    // sent bytes dynamic table
                ;

    crcIdx = 0UL;                   // no CRC bytes sent
    // the blob size is in the normal range
    for(msgIndex = 0U; msgIndex < msgCountTotal; msgIndex++)
    {
        /* in this sequence the error is not checked, as the message length is not overpassed   */
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_cmdParamAddUint8((uint8_t)msgIndex, rfe___error___pointer);
        rfeCmdClient_cmdParamAddUint8((uint8_t)msgCountTotal, rfe___error___pointer);
        if (msgIndex < msgCountBlob)
        {
            // add the blob data
            bytesToSend = (msgIndex == (msgCountBlob - 1U)) ? (uint16_t)lastPacketSizeBlob : (uint16_t)RFE_CFG_MAX_DATA_LENGTH;
            crcIdx = rfe_fillBuffer(pConfig, bytesSentBlob, bytesToSend, blobSize, crcIdx, crcBlob, rfe___error___pointer);
            bytesSentBlob += (uint16_t)bytesToSend;
        }
        else
        {
            if(msgIndex == msgCountBlob)
            {       // this is the first dynamic table message, so compute the CRC for dynTable
                crcW = rfeCrc_calBuf((void*)dynamicTableAddress, dynTabSize - RFE_CFG_CRC_SIZE); // CRC for the dynTable to be sent
                crcIdx = 0;                                                                         // reset the sent bytes count for CRC
            }
            // add the dynamic table data
            bytesToSend = (msgIndex == (msgCountTotal - 1U)) ? (uint16_t)lastPacketSizeDynTab : (uint16_t)RFE_CFG_MAX_DATA_LENGTH;
            crcIdx = rfe_fillBuffer((void*)dynamicTableAddress, bytesSentDynTab, bytesToSend, dynTabSize, crcIdx, crcW, rfe___error___pointer);
            bytesSentDynTab += (uint16_t)bytesToSend;
        }
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            rfeCmdClient_call(rfeCmdServer_cmdId_configure_e, rfe___error___pointer);
        }
        if(*rfe___error___pointer != rfe_error_none_e)
        {
            /* error reported, so stop the transfer                                             */
            break;
        }
    }
}
/*==== BlobDataSend ================*/


/*==============================================================================*/
/**
 *  \brief This function fully configures the RFE-Fw.
 *
 *  \details This function copies the provided configuration and dynamic tables to the RFE-Fw and verifies the response.
 *  This function returns only after RFE-Fw has processed the command and responded.
 *  Asynchronously, after this command is processed, the RFE-Fw performs the configuration and calibrations.
 *
 *  If error occur, CDD_Rfe_GetError must return one of :
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - #rfe_error_api_invalidConfigurationSize_e
 *  - #rfe_error_api_invalidConfigurationParameterValue_e
 *  - #rfe_error_api_invalidDynamicTableSize_e
 *  - #rfe_error_api_invalidDynamicTableValue_e
 *  - #rfe_error_api_invalidRadarCycleTimeSchedule_e
 *  - Any rfe_error_api_configParamCrossCheck_... error of #rfe_error_t.
 *  - Any rfe_error_cmdInterface_... error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in #rfe_state_initialized_e state, or in #rfe_state_configured_e state.
 *
 *  \param [in]      pConfig - Pointer to Configuration Data Memory (see \ref blob)
 *  \param [in]      dynamicTableAddress - Address of the dynamic tables in system memory.
 *                   The dynamic tables created by the rfe configuration generator need
 *                   to be loaded or copied to this address in system memory before calling
 *                   this API function. Set to NULL when dynamic table is not used.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post RFE-Fw state becomes #rfe_state_busy_e and RFE-Fw performs configuration and calibrations asynchronously.
 *  When done, RFE-Fw state becomes #rfe_state_configured_e.
 *
 *  \ingroup NIL
 */
void rfe_configure(uint8_t *pConfig, rfe_sysMemAddress_t dynamicTableAddress,
                        volatile rfe_error_t* rfe___error___pointer)
{
    uint16_t    msgCountBlob,                   // blob total packets
                msgCountDynTab,                 // dynamic table total packets
                msgCountTotal = 0u             // total number of packets
                ;
    uint32_t    crcBlob = 0UL, crcCalc,         // computed CRCs
                blobSize = 0UL,                 // blob size
                dynTabSize = 0UL,               // dynamic table size
                lastPacketSizeBlob = 0UL,       // the size of the last blob packet
                lastPacketSizeDynTab = 0UL      // the size of the last packet dynamic table
                ;
    uint8_t     *crcPtr;                        // pointer to the blob CRC

    if (pConfig == NULL)
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    else
    {
        // check the blob CRC
        crcCalc = rfeCrc_calBuf((void*)pConfig, (uint32_t)RFE_CFG_OFFSET_SECTION_CRC);
        crcPtr = (uint8_t*)(void*)pConfig + RFE_CFG_OFFSET_SECTION_CRC;
        crcBlob = (((uint32_t)*(crcPtr + 3U)) << 24U) + (((uint32_t)*(crcPtr + 2U)) << 16U) + (((uint32_t)*(crcPtr + 1U)) << 8U) + (uint32_t)*(crcPtr);
        if(crcCalc != crcBlob)
        {
            *rfe___error___pointer = rfe_error_api_blob_crc_wrong_e;
        }
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCfg_CheckBlobCompatibility(pConfig, rfe___error___pointer);
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        // compute the transmission parameters
        blobSize = rfe_get_blob_len(pConfig, rfe___error___pointer) + RFE_CFG_CRC_SIZE; // blob size including "final" CRC
        blobSize += (uint32_t)rfe_get_transfer_param((uint16_t)(blobSize), &msgCountBlob, &lastPacketSizeBlob, 1U);
        crcBlob = rfeCrc_calBuf((void*)pConfig, blobSize - RFE_CFG_CRC_SIZE);           // CRC for the blob part of the message
        if(dynamicTableAddress != NULL_PTR)
        {
            dynTabSize = (uint32_t)*(uint16_t*)dynamicTableAddress + RFE_CFG_CRC_SIZE;  // dynamic table size
            (void)rfe_get_transfer_param((uint16_t)(dynTabSize), &msgCountDynTab, &lastPacketSizeDynTab, 0U);
        }
        else
        {
            msgCountDynTab = 0U;
        }
        msgCountTotal = msgCountBlob + msgCountDynTab;
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            rfeCmdClient_checkNotBusy(rfe___error___pointer);
        }
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        // continue only if no error reported
        if(blobSize > RFE_CFG_SIZE_TOTAL)
        {
            // the blob size is bigger than the bigger expected value
            *rfe___error___pointer = rfe_error_api_invalidConfigurationSize_e;
        }
        else
        {
            BlobDataSend(pConfig, dynamicTableAddress, msgCountTotal, msgCountBlob, lastPacketSizeBlob, blobSize, crcBlob,
                    dynTabSize, lastPacketSizeDynTab, rfe___error___pointer);
        }
    }
}
/*==== rfe_configure ================*/


/*==============================================================================*/
/*================================================================================================*/
/**
 *
 *  \brief This function starts the configured radar cycles.
 *
 *  \details The configured radar cycles are started at \p startTime or as soon as possible depending on the
 *  \p isScheduled parameter. The radar cycle start can be scheduled from 10 us up to 1000 ms in the future
 *  (time interval started after the reception of the API call by the RFE-Fw).
 *  This function returns only after RFE-Fw has processed the command and responded.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in #rfe_state_configured_e state.
 *
 *  \param [in]      radarCycleCount - Number of radar cycles to start.
 *                      0 indicates an infinite number of radar cycles, until stopped by Cdd_Rfe_radarCycleStop().
 *  \param [in]      isScheduled - If true, radar cycle starts at \p startTime. If false, radar cycle starts asap.
 *  \param [in]      startTime - The absolute start time delay in 25 [ns] resolution, according to the RFE-Fw time.
 *
 *  \return void
 *
 *  \post When the API call is accepted and radar cycle is started, RFE-Fw state will become #rfe_state_busy_e
 *  during the the calibration, BIST and chirp sequences.
 *  During the radar cycle idle windows the state is #rfe_state_radarCycleIdle_e.
 *  RFE-Fw state returns to #rfe_state_configured_e, when all radar cycles are completed.
 *
 *  \ingroup NIL
 */
void rfe_radarCycleStart(uint16_t radarCycleCount, bool isScheduled, uint32_t startTime,
                            volatile rfe_error_t* rfe___error___pointer)
{
    /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()                */
    *rfe___error___pointer = rfe_error_none_e;
    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        /* no other error check, as the message is short                                                */
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_cmdParamAddUint16(radarCycleCount, rfe___error___pointer);
        rfeCmdClient_cmdParamAddUint8((isScheduled ? (uint8_t)1 : (uint8_t)0), rfe___error___pointer);
        rfeCmdClient_cmdParamAddUint32(startTime, rfe___error___pointer);
        rfeCmdClient_call(rfeCmdServer_cmdId_radarCycleStart_e, rfe___error___pointer);
    }
}
/*==== rfe_radarCycleStart ================*/


/*================================================================================================*/
/**
 *
 *  \brief This function stops the active radar cycles.
 *
 *  \details The active radar cycle will not be finished, but it is stopped as soon as the command has been received.
 *  Pending parameters update will be cancelled.
 *  It can be called, for example, when the  application needs  to do a full
 *  reconfiguration or needs to go to a lower power mode or for any external event
 *  where active radar cycle needs to be stopped. It returns after RFE-Fw has accepted or rejected the call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw state must be #rfe_state_radarCycleIdle_e.
 *
 *  \return uint16  - Index of the active radar cycle at which radar cycle was stopped.
 *
 *  \post Radar cycle is stopped and RFE-Fw state returns to #rfe_state_configured_e.
 *
 *  \ingroup NIL
 */
uint16_t rfe_radarCycleStop(volatile rfe_error_t* rfe___error___pointer)
{
    uint16_t radarCycleCount = 0U;

    /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()                */
    *rfe___error___pointer = rfe_error_none_e;
    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_call(rfeCmdServer_cmdId_radarCycleStop_e, rfe___error___pointer);
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            /* update the returned value only if the command was completed correctly                                */
            radarCycleCount = rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
        }
    }
    return radarCycleCount;
}
/*==== rfe_radarCycleStop ================*/


 /*================================================================================================*/
 /**
  *
  *  \brief This function returns the RFE-Fw state.
  *
  *  \details This function does not interact with the RFE-Fw, returning the state information from the shared memory.
  *
  *  This function can return one of following errors:
  *  - #rfe_error_api_unsynchronized_e
  *  - #rfe_error_sharedData_redundancyCheckFailed_e
  *
  *  \pre NIL
  *
  *  \return Cdd_RfeStateType - The RFE-Fw state
  *
  *  \post NIL
  *
  *  \ingroup NIL
  */
rfe_state_t rfe_getState(volatile rfe_error_t* rfe___error___pointer)
{
    /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()                */
    *rfe___error___pointer = rfe_error_none_e;
    rfe_state_t state = (rfe_state_t)rfeCmdClient_sharedDataRead((uint32_t)rfeCmdClient_sharedParameter_state_e,
                                            rfe___error___pointer);
    return state;
}
/*==== rfe_getState ================*/


/*================================================================================================*/
/**
*
*  \brief This function returns the radar cycle and chirp sequence count.
*
*  \details It returns the number radar cycles and chirp sequences completed since Cdd_Rfe_radarCycleStart().
*  It can be used to keep track of the radar cycle or chirp sequence execution.
*  This function does not interact with the RFE-Fw, instead it returns information from a shared memory location.
*
*  This function can return one of following errors:
*  - #rfe_error_api_unsynchronized_e
*  - #rfe_error_sharedData_redundancyCheckFailed_e
*
*  \return Cdd_RfeRadarCycleCountType - Structure that contains the radar cycle and chirp sequence count.
*
*  \post NIL
*
*  \ingroup NIL
*/
rfe_radarCycleCount_t rfe_getRadarCycleCount(volatile rfe_error_t* rfe___error___pointer)
{
    rfe_radarCycleCount_t radarCycleCount;

    /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()                */
    *rfe___error___pointer = rfe_error_none_e;
    radarCycleCount.radarCycleCount = rfeCmdClient_sharedDataRead(
                            (uint32_t)rfeCmdClient_sharedParameter_radarCycleCount_e, rfe___error___pointer);
    radarCycleCount.chirpSequenceCount = rfeCmdClient_sharedDataRead(
                            (uint32_t)rfeCmdClient_sharedParameter_chirpSequenceCount_e, rfe___error___pointer);

    return radarCycleCount;
}
/*==== rfe_getState ================*/


/*================================================================================================*/
/**
 * \brief This function provides the RFE-Fw FuSa faults which are set in RFE-Fw FCCU.
 * \details This function has to be used when a FuSa fault occurs, which is indicated by the ERROR_N signal
 * and can also be observed by CDD_Rfe_GetState() returning #rfe_state_fuSaFault_e.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in one of the following states:
 * - #rfe_state_initialized_e
 * - #rfe_state_configured_e
 * - #rfe_state_radarCycleIdle_e
 * - #rfe_error_rfeFuSaFault_e
 *
 * \param [out]     pFuSaR1R2FaultList - Pointer to an array, where this function will store the list of
 *                  fusa faults. The size of this array must be \b RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT bytes.
 *                  The enumeration \b rfe_fuSaFault_t must be used as bit index to determine the fault from
 *                  the \b pFuSaR1R2FaultList e.g., if byte index 3 of \b pFuSaR1R2FaultList has the value
 *                  b0010000, it means bit position 5 of fuSaFaultMask3 is set, i.e rfe_fuSaFault_sr47_lo_level_max_rx1_e fault is set.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return void
 *
 * \post This function does not result in change of RFE-Fw state.
 *
 * \ingroup NIL
 */
void rfe_getFuSaFaults(uint8_t *pFuSaR1R2FaultList, volatile rfe_error_t* rfe___error___pointer)
{
	uint8_t fuSaFaultByteIndex;

    if (pFuSaR1R2FaultList == NULL)
    {
        /* report the NULL pointer value as error and stop other actions                                            */
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    else
    {
        /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()            */
        *rfe___error___pointer = rfe_error_none_e;
        rfeCmdClient_checkNotBusy(rfe___error___pointer);
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            /* only if the RFE-Fw is not busy                                                                       */
            rfeCmdClient_cmdParamStart();
            rfeCmdClient_call(rfeCmdServer_cmdId_getFuSaFaults_e, rfe___error___pointer );
            /* the possible error must be checked in one of the calling layers                                      */
            for(fuSaFaultByteIndex = 0U; fuSaFaultByteIndex < RFE_CMD_CLIENT_FUSA_FAULT_BYTE_COUNT;
                                        fuSaFaultByteIndex++ )
            {
                pFuSaR1R2FaultList[fuSaFaultByteIndex] = rfeCmdClient_cmdRespGetUint8(rfe___error___pointer);
            }
        }
    }
}
/*==== rfe_getFuSaFaults ================*/


/*================================================================================================*/
/**
 * \brief This function provides the fault statistics for R1 faults.
 * \details This function provides list of fault occurrence count for each R1 fault.
 * Whenever a R1 fault is detected, the corresponding counter is incremented.
 * Each counter can reach up to a maximum value of 0xFF and stays at this level until reset.
 * The counter is reset as part of RFE-Fw initialization upon
 *  - Functional reset.
 *  - Destructive reset.
 *  - Power on reset.
 *
 * The \b pFuSaR1FaultCountList is of fixed size #RFE_FUSA_R1_FAULT_COUNT_MAX and does
 * not decrease even when R1 fault is promoted to R2 (refer \ref thresholdValueToPromoteR1Faults ).
 * The \b pR1FaultPromotedToR2Since will indicate which R1 fault was promoted to R2.
 *
 * This function returns after RFE-Fw has accepted or rejected the call.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in one of the following states:
 * - #rfe_state_initialized_e
 * - #rfe_state_configured_e
 * - #rfe_state_radarCycleIdle_e
 * - #rfe_error_rfeFuSaFault_e
 *
 * \param [out]     pR1FaultPromotedToR2 - Indicates the R1 fault which is promoted to R2.
 * \param [out]     pRadarCycleCount - Pointer to structure which provides Radar cycle count and Chirp sequence
 *                  count. The count in \b pRadarCycleCount is updated whenever the fault occurrence count is
 *                  updated. If there is no active radar cycle, the radar cycle count and chirp sequence count
 *                  value will be 0x00 each.
 * \param [out]     pFuSaR1FaultCountList - Pointer to an array containing fault occurrence count for each R1
 *                  fault. The size of this array should be #RFE_FUSA_R1_FAULT_COUNT_MAX bytes.
 *                  The #rfe_fuSaFault_t up to index value #rfe_fuSaFault_R1_sm11_bist_tx4_sw_e bytes, must be used
 *                  to index the list to determine the fault occurrence count for the corresponding fault
 *                  e.g., the value in \b pFuSaCountList[#rfe_fuSaFault_R1_sm11_bist_tx4_sw_e]
 *                  provides the fault occurrence count for #rfe_fuSaFault_R1_sm11_bist_tx4_sw_e.
 *
 *  \return void
 *
 * \post This function does not result in change of RFE-Fw state.
 *
 * \remark
 * -# The functions CDD_Rfe_GetFuSaFaults(), CDD_Rfe_RadarCycleStart() and CDD_Rfe_RadarCycleStop()
 *  do not affect the counter values.
 * -# The \ref thresholdValueToPromoteR1Faults has no relation to the counter used in CDD_Rfe_GetFuSaFaultStatistics().
 *
 * \ingroup NIL
 */
void rfe_getFuSaFaultStatistics(uint16_t *pR1FaultPromotedToR2, rfe_radarCycleCount_t *pRadarCycleCount,
                                        uint8_t *pFuSaR1FaultCountList,	volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t fuSaFaultCountIndex;

    if ((pFuSaR1FaultCountList == NULL) || (pR1FaultPromotedToR2 == NULL) ||  (pRadarCycleCount == NULL))
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    else
    {
        /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()            */
        *rfe___error___pointer = rfe_error_none_e;
        rfeCmdClient_checkNotBusy(rfe___error___pointer);
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            rfeCmdClient_cmdParamStart();
            rfeCmdClient_call(rfeCmdServer_cmdId_getFuSaFaultStatistics_e, rfe___error___pointer);
            /* the possible error must be checked in one of the calling layers                                      */

            *pR1FaultPromotedToR2 =  rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
            pRadarCycleCount->radarCycleCount =  rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
            pRadarCycleCount->chirpSequenceCount =  rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
            for(fuSaFaultCountIndex = 0U; fuSaFaultCountIndex < RFE_FUSA_R1_FAULT_COUNT_MAX;
                                                                fuSaFaultCountIndex++)
            {            
                pFuSaR1FaultCountList[fuSaFaultCountIndex] = rfeCmdClient_cmdRespGetUint8(rfe___error___pointer);
            }
        }
    }
}
/*==== rfe_getFuSaFaultStatistics ================*/


/*================================================================================================*/
/**
 * \brief This function returns RX BIST measurement details to be used as zero hour reference data.
 *
 * \details The RFE-Fw performs the RX phase difference and RX gain difference
 * measurements upon this function call. 
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in #rfe_state_configured_e.
 *
 * \param [out]      pRxReferenceData  - pointer to structure containing zero hour RX bist reference data.
 * \param [in,out]   rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return void
 *
 * \remark
 *  -# The configuration that changed due to  execution of CDD_Rfe_GetBistZeroHourReferenceData() will be restored to
 *  configuration that existed before the function call.
 *  -# The threshold values (\ref monitorAndSafety ) to be used along with zero hour data are determined after
 * characterization.
 * \return NIL
 * \post This function does not result in change of RFE-Fw state.
 *
 * \ingroup NIL
 */
void rfe_getBistZeroHourReferenceData(rfeCfg_rxBistReferenceData_t *pRxReferenceData, volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t feIdx, antPair;

    if (pRxReferenceData == NULL)
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    else
    {
        /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()            */
        *rfe___error___pointer = rfe_error_none_e;
        rfeCmdClient_checkNotBusy(rfe___error___pointer);
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_call(rfeCmdServer_cmdId_getBistZeroHourReferenceData_e, rfe___error___pointer);
        /* the possible error must be checked in one of the calling layers                                      */
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            for(feIdx = 0; feIdx < (uint8_t)RFE_NUM_USED_FRONT_ENDS; feIdx++)
            {
                for(antPair = 0; antPair < (uint8_t)RFE_RX_BIST_COMBINATIONS; antPair++)
                {
                    pRxReferenceData[feIdx].refMag[antPair][TEF82XX_RFBIST_MIXER_TEST] = rfeCmdClient_cmdRespGetInt16(rfe___error___pointer);
                    pRxReferenceData[feIdx].refMag[antPair][TEF82XX_RFBIST_LNA_TEST] = rfeCmdClient_cmdRespGetInt16(rfe___error___pointer);
                    pRxReferenceData[feIdx].refPh[antPair][TEF82XX_RFBIST_MIXER_TEST] = rfeCmdClient_cmdRespGetInt16(rfe___error___pointer);
                    pRxReferenceData[feIdx].refPh[antPair][TEF82XX_RFBIST_LNA_TEST] = rfeCmdClient_cmdRespGetInt16(rfe___error___pointer);
                }
            }
        }
    }
}
/*==== rfe_getBistZeroHourReferenceData ================*/


/*================================================================================================*/
/**
 *
 *  \brief This function returns the RFE-Fw time.
 *
 *  \details It returns the absolute RFE-Fw time since the initialization in 25[ns] resolution.
 *  The counter wrap around time is equal to 2^32 * 25 ns, which is approximately 107 seconds.
 *  This function returns after RFE-Fw has accepted or rejected the call.
 *
* T his function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *  - #rfe_state_radarCycleIdle_e
 *
 *  \return uint32_t - Absolute RFE-Fw time since initialization in 25 [ns] resolution.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */
uint32_t rfe_getTime(volatile rfe_error_t* rfe___error___pointer)
{
    uint32_t rfeTime = 0UL;

    /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()            */
    *rfe___error___pointer = rfe_error_none_e;
    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_call(rfeCmdServer_cmdId_getTime_e, rfe___error___pointer);
        rfeTime = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
    }
    return rfeTime;
}
/*==== rfe_getTime ================*/


/*================================================================================================*/
/**
 *
 *  \brief This function returns version and variant details of the RFE-Fw hardware and firmware.
 *
 *  \details This function returns after RFE-Fw has accepted or rejected the call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *  - #rfe_state_radarCycleIdle_e
 *
 *  \return Cdd_RfeVersionType - Structure containing RFE-Fw variant and version details.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */
rfe_version_t rfe_getVersion(volatile rfe_error_t* rfe___error___pointer)
{
    rfe_version_t version = {0};

    /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()            */
    *rfe___error___pointer = rfe_error_none_e;
    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_call(rfeCmdServer_cmdId_getVersion_e, rfe___error___pointer);
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            version.hwType = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
            version.hwVariant = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
            version.hwVersion = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
            version.hwUniqueId = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
            version.fwVariant = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
            version.fwVersionReleased = rfeCmdClient_cmdRespGetBool(rfe___error___pointer);
            version.fwVersionMajor = rfeCmdClient_cmdRespGetUint8(rfe___error___pointer);
            version.fwVersionMinor = rfeCmdClient_cmdRespGetUint8(rfe___error___pointer);
            version.fwVersionPatch = rfeCmdClient_cmdRespGetUint8(rfe___error___pointer);
            version.fwHash = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
        }
    }
    return version;
}
/*==== rfe_getTime ================*/

/*================================================================================================*/
/**
 *
 *  \brief This function set tx monitor power.
 *
 *  \details
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *  - #rfe_state_radarCycleIdle_e
 *
 * \param [out]     *pMonitorValues - The monitor values will be written to this pointer
 *
 *  \return
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */
static void rfe_setMonitorTxPower(rfe_monitorValues_t *pMonitorValues, volatile rfe_error_t* rfe___error___pointer)
{
	uint8_t txIndex = 0;
	uint8_t chirpProfileIndex = 0;

	for(chirpProfileIndex = (uint8_t)rfe_chirpProfileIndex_0_e;
						 chirpProfileIndex < RFE_CHIRP_PROFILES_MAX; chirpProfileIndex++)
	{
		 if(*rfe___error___pointer != rfe_error_none_e)
		 {
			 break;
		 }
		 for (txIndex = (uint8_t)rfe_txIndex_1_e; txIndex < (RFE_TX_COUNT * RFE_MAX_SUPPORTED_DEVICES); txIndex++)
		 {
			 if(*rfe___error___pointer != rfe_error_none_e)
			 {
				 break;
			 }
			 pMonitorValues->txPower[chirpProfileIndex][txIndex] =
										 rfeCmdClient_cmdRespGetInt16(rfe___error___pointer);
		 }
	}
}

/*================================================================================================*/
/**
 *
 *  \brief This function will read-out one or more RFE-Fw monitors.
 *
 *  \details Monitors to be read are selected by \p monitorSelect.
 *
 *  This function returns after RFE-Fw has accepted or rejected the API call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *  - #rfe_state_radarCycleIdle_e (#RFE_MONITOR_SELECT_TEMP_IMMEDIATELY bit of \p monitorSelect must be '0')
 *  - #rfe_state_testContinuousWaveTransmission_e
 *
 *  \param [in]      monitorSelect - Selection of the RFE-Fw monitors to read-out
 *  \param [out]     *pMonitorValues - The monitor values will be written to this pointer
 *
 *  \return Cdd_RfeRadarCycleCountType - The radar cycle and chirp sequence count,
 *  indicating when the monitors were read.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */
rfe_radarCycleCount_t rfe_monitorRead(rfe_monitorSelect_t monitorSelect, rfe_monitorValues_t *pMonitorValues,
                                        volatile rfe_error_t* rfe___error___pointer)
{
    rfe_radarCycleCount_t           radarCycleCount = { 0U, 0U };

    /* reset the possible previous error - it is not normal, as the error is reset at rfe_geterror()            */
	*rfe___error___pointer = rfe_error_none_e;
    if ( pMonitorValues == NULL)
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
    	rfeCmdClient_checkNotBusy(rfe___error___pointer);
    }
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		rfeCmdClient_cmdParamStart();
		rfeCmdClient_cmdParamAddUint16(monitorSelect, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		rfeCmdClient_call(rfeCmdServer_cmdId_monitorRead_e, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		radarCycleCount.radarCycleCount = rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		radarCycleCount.chirpSequenceCount = rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
	}
	// Read each specific monitor parameters if it was requested
	rfe_monitorReadRxSaturation(monitorSelect, pMonitorValues, rfe___error___pointer);
	rfe_monitorReadPdcClipping(monitorSelect, pMonitorValues, rfe___error___pointer);
	rfe_monitorReadTempBefore(monitorSelect, pMonitorValues, rfe___error___pointer);
	rfe_monitorReadTempAfter(monitorSelect, pMonitorValues, rfe___error___pointer);
	rfe_monitorReadTempNow(monitorSelect, pMonitorValues, rfe___error___pointer);
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		if((monitorSelect & RFE_MONITOR_SELECT_TX_POWER ) != 0U)
		{
			rfe_setMonitorTxPower(pMonitorValues, rfe___error___pointer);
		}
    }
    return radarCycleCount;
}
/*==== rfe_monitorRead ================*/

/*================================================================================================*/
/**
 *
 *  \brief This function returns the scheduled absolute start time of the next radar cycle
 *
 *  \details The returned time is according to the RFE-Fw time.
 *  This function returns after RFE-Fw has accepted or rejected the call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in #rfe_state_radarCycleIdle_e state.
 *
 *  \param [out]     *pRadarCycleIndex - Pointer to index of the next radar cycle of which the start time is returned.
 *
 *  \return uint32   - Absolute start time of the next scheduled radar cycle in 25 [ns] resolution.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */uint32_t rfe_getNextRadarCycleStartTime(uint16_t *pRadarCycleIndex, volatile rfe_error_t* rfe___error___pointer)
{
    uint32_t startTime = 0UL;

    if (pRadarCycleIndex == NULL )
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    else
    {
        *rfe___error___pointer = rfe_error_none_e;
        rfeCmdClient_checkNotBusy(rfe___error___pointer);
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            rfeCmdClient_cmdParamStart();
            rfeCmdClient_call(rfeCmdServer_cmdId_getNextRadarCycleStartTime_e, rfe___error___pointer);
            startTime = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
            *pRadarCycleIndex = rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
        }
    }
    return startTime;
}
/*==== rfe_getNextRadarCycleStartTime ================*/


/*================================================================================================*/
/**
 *
 *  \brief This function updates the start time of the next radar cycle
 *
 *  \details Cdd_Rfe_radarCycleStart() starts one or multiple radar cycles immediately or at a schedule time,
 *  with a certain period (\ref radarCycleDuration), as per the configuration.
 *  This function updates the absolute start time of the next radar cycle according to the RFE-Fw time.
 *  That radar cycle will thereby be delayed or pulled in. Subsequent radar cycles will shift in
 *  time accordingly to maintain the configured \ref radarCycleDuration.
 *  This functionality can be used to synchronize multiple radar sensors in time.
 *  The next radar cycle start time can be delayed up to 100 ms and should not conflict with
 *  the current radar cycle time schedule (in case of pull in).
 *  This function returns after RFE-Fw has accepted or rejected the API call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in #rfe_state_radarCycleIdle_e state.
 *
 *  \param [in]      startTime - Absolute start time of the next radar cycle in 25 [ns] resolution.
 *
 *  \return uint16   - Index of the next radar cycle of which the start time is set.
 *
 *  \post Next radar cycle starts at the given start time.
 *
 *  \ingroup NIL
 */
uint16_t rfe_setNextRadarCycleStartTime(uint32_t startTime, volatile rfe_error_t* rfe___error___pointer)
{
    uint16_t radarCycleIndex = 0xffffU;

    *rfe___error___pointer = rfe_error_none_e;
    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_cmdParamAddUint32(startTime, rfe___error___pointer);
        rfeCmdClient_call(rfeCmdServer_cmdId_setNextRadarCycleStartTime_e, rfe___error___pointer);
        radarCycleIndex = rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
    }
    return radarCycleIndex;
}
/*==== rfe_setNextRadarCycleStartTime ================*/


/*================================================================================================*/
/**
 *  \brief This function begins a RFE-Fw configuration update operation.
 *
 *  \details When the RFE-Fw Configuration (as set via rfe_configure()) is required to
     be updated then this is the first function to be called.
 *  This function will clear the buffered RFE-Fw configuration.
 *  This function does not interact with the RFE-Fw, instead it buffers data locally.
 *  This function does not return any error.
 *
 *  \pre NIL
 *
 *  \return void
 *
 *  \post The functions Cdd_Rfe_updateParam() and/or Cdd_Rfe_updateDynamicTable()
 *  must be called after this function
 *  to buffer the configuration and then push the configuration
 *  into RFE FW via the configuration update via Cdd_Rfe_updatePush().
 *
 *  \ingroup NIL
 */
void rfe_updateBegin(void )
{
    updateCount = 0U;
}
/*==== rfe_updateBegin ================*/


/*================================================================================================*/
void rfe_updateParam(rfeCfg_section_t section, rfe_paramUpdate_t param, uint32_t value,
                        volatile rfe_error_t* rfe___error___pointer)
{

    if(updateCount >= RFE_UPDATE_COUNT_MAX)
    {
        *rfe___error___pointer = rfe_error_api_maxUpdateCountExceeded_e;
    }
    else
    {
        *rfe___error___pointer = rfe_error_none_e;
        updates[updateCount].section = (uint16_t)section;
        updates[updateCount].param = (uint16_t)param;
        updates[updateCount].value = value;
        updateCount++;
    }
}
/*==== rfe_updateParam ================*/


/*================================================================================================*/
void rfe_updateDynamicTable(uint8_t dynamicTableIndex, rfe_dynParamsSelect_t paramsSelect,
                                volatile rfe_error_t* rfe___error___pointer)
{
	*rfe___error___pointer = rfe_error_api_function_not_implemented_e;
	return;
    if (updateCount >= RFE_UPDATE_COUNT_MAX )
    {
        *rfe___error___pointer = rfe_error_api_maxUpdateCountExceeded_e;
    }
    else
    {
        *rfe___error___pointer = rfe_error_none_e;
        updates[updateCount].section = (uint16_t)RFE_CMD_CLIENT_UPDATE_SECTION_DYNAMIC_TABLE;
        updates[updateCount].param = (uint16_t)dynamicTableIndex;
        updates[updateCount].value = (uint32_t)paramsSelect;
        updateCount++;
    }
}
/*==== rfe_updateDynamicTable ================*/


/*================================================================================================*/
uint16_t rfe_updatePush(volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t     updateIndex;
    uint16_t    radarCycleCount = 0U;

    rfeCmdClient_checkNotBusy(rfe___error___pointer);

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if (updateCount == 0U)
        {
            *rfe___error___pointer = rfe_error_api_noUpdatesBuffered_e;
        }
        else
        {
            rfeCmdClient_cmdParamStart();

            for(updateIndex = 0U; updateIndex < updateCount; updateIndex++)
            {
                rfeCmdClient_cmdParamAddUint16(updates[updateIndex].section, rfe___error___pointer);
                rfeCmdClient_cmdParamAddUint16(updates[updateIndex].param, rfe___error___pointer);
                rfeCmdClient_cmdParamAddUint32(updates[updateIndex].value, rfe___error___pointer);
            }
            if(*rfe___error___pointer == rfe_error_none_e)
            {
                rfeCmdClient_call(rfeCmdServer_cmdId_updatePush_e, rfe___error___pointer);
            }
            radarCycleCount = rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
        }
    }
    return radarCycleCount;
}
/*==== rfe_updatePush ================*/


/*================================================================================================*/
/**
 *
 *  \brief This function start continuous wave tranmission.
 *
 *  \details It uses the RFE-Fw profile as configured via rfe_configure() as specified by \p profileIndex.
 *  The effective chirp bandwidth of this profile is neglected.
 *  The frequency is kept at the configured center frequency.
 *  This function  returns after RFE-Fw has accepted or rejected the call.
 *
 *   This function can sets one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre RFE-Fw must be in #rfe_state_configured_e state.
 *
 *  \param [in]      profileIndex - Index of the chirp profile to be used for
 *                   continuous wave transmission.
 *
 *  \return void
 *
 *  \post RFE goes to  #rfe_state_testContinuousWaveTransmission_e state.
 *
 *  \ingroup NIL
 */
/*
* @violates @section rfe_low_level_c_REF_2, #External identifiers shall be distinct.
*/
void rfe_testContinuousWaveTransmissionStart(rfe_chirpProfileIndex_t profileIndex,
                            volatile rfe_error_t* rfe___error___pointer)
{
     *rfe___error___pointer = rfe_error_none_e;
     rfeCmdClient_checkNotBusy(rfe___error___pointer);
     if(*rfe___error___pointer == rfe_error_none_e)
     {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_cmdParamAddUint8((uint8_t)profileIndex, rfe___error___pointer);
        rfeCmdClient_call(rfeCmdServer_cmdId_testContinuousWaveTransmissionStart_e, rfe___error___pointer);
     }
}
/*==== rfe_testContinuousWaveTransmissionStart ================*/


/*================================================================================================*/
/**
 *
 *  \brief This function stops continuous wave transmission.
 *
 *  \details Continuous wave transmission can be started via rfe_testContinuousWaveTransmissionStart().
 *  This function returns whether RFE-Fw has accepted or rejected the call.
 *
 *   This function can sets one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre RFE must be in #rfe_state_testContinuousWaveTransmission_e state.
 *
 *  \return void
 *
 *  \post RFE goes to  #rfe_state_configured_e state.
 *
 *  \ingroup NIL
 */
/*
* @violates @section rfe_low_level_c_REF_2, #External identifiers shall be distinct.
*/
void rfe_testContinuousWaveTransmissionStop(volatile rfe_error_t* rfe___error___pointer)
{
     *rfe___error___pointer = rfe_error_none_e;
     rfeCmdClient_checkNotBusy(rfe___error___pointer);
     if(*rfe___error___pointer == rfe_error_none_e)
     {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_call(rfeCmdServer_cmdId_testContinuousWaveTransmissionStop_e, rfe___error___pointer);
     }
}
/*==== rfe_testContinuousWaveTransmissionStop ================*/


/*================================================================================================*/
/**
 *
 *  \brief This function sets a test parameter.
 *
 *  \details According the required test :
 *      - rfe_testParam_outputDataTestPattern_e :
 *          - the \b value parameter is ignored for the moment
 *          - the function will wait for the tests to be completed on RFE-Fw
 *          - only the current Front-End will be tested
 *          - after this test the Front-End will be set to \ref rfe_state_initialized_e state
 *          - the rfe_testParamResultPtr variable will define how the response/return from RFE-Fw is processed:
 *              - if set to NULL, the result data will not be delivered
 *              - if not NULL, the memory pointed will be filled with the results
 *              - at start time, the variable value is set to NULL and the driver never set this value, only use it at the appropriate time
 *      - \ref rfe_testParam_keepTxTransmissionEnabled_e, \ref rfe_testParam_chirpPllTestPinEnable_e and \ref rfe_testParam_enableClockRetuning_e : are not implemented yet
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *
 *  \param [in]      testParam  - The test parameter to set
 *  \param [in]      value      - The value to set
 *  \param [in]      resultPtr  - pointer to the memory to receive the result
 *
 *  \return void
 *
 */
void rfe_testSetParam(rfe_testParam_t testParam, uint32_t value, volatile rfe_error_t* rfe___error___pointer)
{
    *rfe___error___pointer = rfe_error_api_function_not_implemented_e;
    return;

    *rfe___error___pointer = rfe_error_none_e;
    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_cmdParamAddUint16((uint16_t)testParam, rfe___error___pointer);
        rfeCmdClient_cmdParamAddUint32(value, rfe___error___pointer);
        rfeCmdClient_call(rfeCmdServer_cmdId_testSetParam_e, rfe___error___pointer);
    }
}
/*==== rfe_testSetParam ================*/


/*================================================================================================*/
 /**
 *
 *  \brief This function provides the Internal error occured.
 *
 *  \details This function returns internal error code.
 * This function returns whether RFE has accepted or rejected the API call.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_sharedData_redundancyCheckFailed_e
 * - #rfe_error_rfeFuSaFault_e
 *
 *  \return     the error
 *
 */
uint32_t rfe_testGetInternalError(volatile rfe_error_t* rfe___error___pointer)
{
    uint32_t internalError = (uint32_t)rfe_error_none_e;

    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_call(rfeCmdServer_cmdId_testGetInternalError_e, rfe___error___pointer);
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
    	internalError = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
    }

    return internalError;
}
/*==== rfe_testGetInternalError ================*/


/*================================================================================================*/
 /**
 *
 *  \brief This function provides the dump of the required registry.
 *
 *  \details This function returns internal error code.
 * This function returns only after the result were delivered by the RFE-Fw.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_sharedData_redundancyCheckFailed_e
 * - #rfe_error_rfeFuSaFault_e
 *
 *  \return     the error
 *
 */
static void rfe_getFeRegisterDump(uint8_t frontEndPos, rfe_moduleDumpSelect_t moduleSelection, rfe_registerDumpValues_t *dumpArrayPtr,
        uint32_t *dumpArrayIdx, uint32_t dumpArrayMaxLen, volatile rfe_error_t* rfe___error___pointer)
{
    rfe_registerDumpValues_t    *workingDumpPtr;                // the working pointer for data dump
    uint8_t     moduleIdx;                                      // module index
    uint32_t    moduleSelMask = (uint32_t)rfe_registerDump_CC;  // the mask for the current module to be read
    uint32_t    regLimit, dumpPos;
    uint16_t    dataLength;
    uint8_t     moduleRegIdx ;                                  // the index of the module and module register to be read
    uint16_t    *moduleRegOffsetPtr;                            // pointer to the list of the registers offset

    moduleIdx = 0U;
    dumpPos = *dumpArrayIdx;                                    // initialize the array position
    workingDumpPtr = &dumpArrayPtr[dumpPos];
    while((*rfe___error___pointer == rfe_error_none_e) && (moduleSelMask != 0UL))
    {
        if((moduleSelMask & (uint32_t)moduleSelection) == 0UL)
        {
            moduleSelMask <<= 1U;                           // move to the next module
            moduleIdx++;
            continue;
        }
        // a module identified, start to ask, receive and populate the response array
        moduleRegOffsetPtr = registryOffsetArrayPtr[moduleIdx];
        moduleRegIdx = 0U;                                  // the first registry ID to be read
        regLimit = rfe_regDumpModuleRegLimit[moduleIdx];    // the expected number of registry to be read
        while((*rfe___error___pointer == rfe_error_none_e) && (moduleRegIdx < regLimit) && (dumpPos < dumpArrayMaxLen))
        {
            rfeCmdClient_cmdParamStart();                       // start the list of the parameters to be used
            rfeCmdClient_cmdParamAddUint8(frontEndPos, rfe___error___pointer);
            rfeCmdClient_cmdParamAddUint8(moduleIdx, rfe___error___pointer);
            rfeCmdClient_cmdParamAddUint8(moduleRegIdx, rfe___error___pointer);
            rfeCmdClient_call(rfeCmdServer_cmdId_registerDump_e, rfe___error___pointer);
            dataLength = (rfeCmdClient_getCurrentRespLen() - 4U) >> 1u; // amount of received data uint32_t
            if(moduleIdx != (uint8_t)rfe_bcd_atb_voltage_e)
            {
                dataLength >>= 1u;                          // the data length as uint32_t
            }
            while((*rfe___error___pointer == rfe_error_none_e) && (dataLength > 0UL) && (moduleRegIdx < regLimit) && (dumpPos < dumpArrayMaxLen))
            {
                workingDumpPtr->frontEndId = frontEndPos;
                workingDumpPtr->moduleId = moduleIdx;
                workingDumpPtr->registerAddress = *moduleRegOffsetPtr;
                // set the value according to the returned value/used module
                workingDumpPtr->value = (moduleIdx != (uint8_t)rfe_bcd_atb_voltage_e) ? (uint32_t)rfeCmdClient_cmdRespGetUint32(rfe___error___pointer) :
                                (uint32_t)rfeCmdClient_cmdRespGetUint16(rfe___error___pointer);
                dataLength--;
                workingDumpPtr++;
                moduleRegIdx++;
                moduleRegOffsetPtr++;
                dumpPos++;
            }
            if((dataLength != 0U) && (dumpPos < dumpArrayMaxLen))
            {   // report error only if the array limit was not get
                *rfe___error___pointer = rfe_error_cmdInterface_invalidRspLength_e;
            }
        }
        moduleSelMask <<= 1U;                           // move to the next module
        moduleIdx++;
    }
    *dumpArrayIdx = dumpPos;                            // set the actual position of the data pointer
}
/*==== rfe_getFeRegisterDump ================*/


/*================================================================================================*/
/**
*
*   \brief      Function to get the complete registry status on one or many front-end(s)
*
*   \details    The function must be used only when the radar cycle is stopped else an error will be reported.
*               The returned values will be dumped in the result array pointed by dumpArrayPtr.
*               For the moment this function doesn't have a CDD equivalent.
*               It is the user duty to have enough space for the received data, please be aware of the :
*                   - rfe_registerDumpValues_t structure length
*                   - the expected number of registers to be dump for the requested module(s) found in rfe_register_dump.h as RFE_..._REG_NUMBER
*
* \param[in]        frontEndPos     - the Front-End to be used for registry dump
* \param[in]        moduleSelection - one or more modules to get the registry values
* \param[in]        dumpArrayPtr    - pointer to the data area to save the received data
* \param[in]        dumpArrayPtrLen - pointer to data array maximum length
* \param[out]       dumpArrayPtrLen - the pointer receive the exact number of values returned
* \param [in,out]   rfe___error___pointer - Error handling parameter:
*                   On success #*rfe___error___pointer == rfe_error_none_e is true,
*                   On failure #*rfe___error___pointer != rfe_error_none_e is true
*
*/
void rfe_getRegisterDump(uint8_t frontEndPos, rfe_moduleDumpSelect_t moduleSelection, rfe_registerDumpValues_t *dumpArrayPtr,
                        uint32_t *dumpArrayPtrLen, volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t     frontEndMask = 1U, frontEndIdx = 0U;
    uint32_t    arrayLimit;                                     // the limit for array write
    uint32_t    arrayWrIdx = 0UL;                               // the current write index for the registry array

    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        arrayLimit = *dumpArrayPtrLen;
        while((*rfe___error___pointer == rfe_error_none_e) && (frontEndMask != 0UL) && (arrayWrIdx < arrayLimit))
        {
            if((frontEndPos & frontEndMask) != 0u)
            {
                rfe_getFeRegisterDump(frontEndIdx, moduleSelection, dumpArrayPtr, &arrayWrIdx, arrayLimit, rfe___error___pointer);
            }
            frontEndIdx++;
            frontEndMask <<= 1u;
        }
        *dumpArrayPtrLen = arrayWrIdx;
    }
}

/*================================================================================================*/
/**
*
*   \brief      Function to change the associated Front-End "subject" in a cascaded setup.
*
*   \details    The function must be used only in a cascaded setup, else an error will be returned.
*               The possible errors are :
*               - unresponsive
*               - not synchronized
*               - busy
*               - operation not allowed - only this is a specific error for this operation request, returned from RFE-Fw
*               - invalid argument
*
* \param[in]        frontEndPos - the Front-End to be used as conversation subject between the two cores
* \param [in,out]   rfe___error___pointer - Error handling parameter:
*                   On success #*rfe___error___pointer == rfe_error_none_e is true,
*                   On failure #*rfe___error___pointer != rfe_error_none_e is true
*
*/
void rfe_setFrontEnd(uint8_t frontEndPos, volatile rfe_error_t* rfe___error___pointer)
{
    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_cmdParamAddUint8(frontEndPos, rfe___error___pointer);
        rfeCmdClient_call(rfeCmdServer_cmdId_setFrontEnd_e, rfe___error___pointer);
    }
}
/*==== rfe_setFrontEnd ================*/


/*================================================================================================*/
/**
*
*   \brief      Function to get the associated Front-End "subject" in a cascaded setup.
*
*   \details    The function must be used only in a cascaded setup, else an error will be returned.
*               The possible errors are :
*               - unresponsive
*               - not synchronized
*               - busy
*               - operation not allowed - only this is a specific error for this operation request, returned from RFE-Fw
*               - invalid argument
*
* \param [in,out]   rfe___error___pointer - Error handling parameter:
*                   On success #*rfe___error___pointer == rfe_error_none_e is true,
*                   On failure #*rfe___error___pointer != rfe_error_none_e is true
*
*/
uint8_t rfe_getFrontEnd(volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t rez = 0u;

    rfeCmdClient_checkNotBusy(rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeCmdClient_cmdParamStart();
        rfeCmdClient_call(rfeCmdServer_cmdId_getFrontEnd_e, rfe___error___pointer);
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            rez = rfeCmdClient_cmdRespGetUint8(rfe___error___pointer);
        }
    }
    return rez;
}
/*==== rfe_getFrontEnd ================*/


/*================================================================================================*/
/**
 * \brief This function configure the RFE firmware interrupt.
 *
 * \details rfe_configureInterrupt() configures which conditions will raise
 *          an IRQ to \p coreId, these conditions are:
 *            - RFE state changes
 *            - Radar Cycle count changes
 *            - Chirp Sequence count changes
 *            - Specific RFE API responses from the firmware
 *
 *          The \p apiWaitForInterrupt function will be called while the driver is
 *          waiting for an RFE API response, this function shall return whenever a RFE
 *          firmware interrupt is received.
 *
 *          This is a user registered call back function where wait for interrupt or
 *          functionality to give control to Operating System can be implemented as per
 *          customer need.
 *
 *          This function may be called multiple times on a single RFE API call.
 *          During this call only APIs that do not interact with the firmware are allowed.
 *
 *          This function can return one of following errors:
 *          - #rfe_error_api_unsynchronized_e
 *          - #rfe_error_api_operationNotAllowed_e
 *          - #rfe_error_api_busy_e
 *          - #rfe_error_api_invalidArgumentValue_e
 *          - Any _cmdInterface_ error of #rfe_error_t.
 *          - #rfe_error_rfeFuSaFault_e
 *
 * \note \p apiWaitForInterrupt IS NOT an interrupt handler, the application code
 *       is responsible for setting up and handle incoming RFE interrupts.
 *
 * \pre The RFE must be in one of the following states:
 * - #rfe_state_initialized_e
 * - #rfe_state_configured_e
 * - #rfe_state_radarCycleIdle_e
 * - #rfe_error_rfeFuSaFault_e
 *
 * \param [in]      coreId - Which core should the RFE interrupt be sent.
 * \param [in]      events - Bitmask of events that will trigger an interrupt.
 * \param [in]      rfeAPIs - Bitmask of RFE-APIs responses that will trigger an interrupt.
 * \param [in]      apiWaitForInterrupt - API wait for interrupt function pointer.
 *                                        This is a user registered call back function where wait for interrupt or
 *                                        functionality to give control to Operating System can be implemented as per customer need.
 * \param [in,out]  rfe___error___pointer - Error handling parameter
 *
 */void rfe_configureInterrupt(rfe_coreId_t coreId, rfe_eventsIRQ_t events, rfe_apiIRQ_t rfeAPIs, rfe_apiWaitForInterrupt_f apiWaitForInterrupt,
                 volatile rfe_error_t* rfe___error___pointer)
{
    if ( ((uint8_t)coreId < (uint8_t)rfe_coreId_max) && ((uint8_t)events < (uint8_t)RFE_EVENTS_IRQ_MAX) && ((uint32_t)rfeAPIs < (uint32_t)RFE_API_IRQ_MAX) )
    {
        rfeCmdClient_checkNotBusy(rfe___error___pointer);
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            rfeCmdClient_cmdParamStart();
            rfeCmdClient_cmdParamAddUint16((uint16_t)coreId, rfe___error___pointer);
            rfeCmdClient_cmdParamAddUint16((uint16_t)events, rfe___error___pointer);
            rfeCmdClient_cmdParamAddUint32((uint32_t)rfeAPIs, rfe___error___pointer);
            rfeCmdClient_call((rfeCmdServer_cmdId_t)rfeCmdServer_cmdId_configureInterrupt_e, rfe___error___pointer);
            if(*rfe___error___pointer == rfe_error_none_e)
            {
                rfeCmdClient_configureInterrupt(rfeAPIs, apiWaitForInterrupt);
            }
        }
    }
    else
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
}
 /*==== rfe_configureInterrupt ================*/
