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
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stddef.h>
#include "rfe_debug.h"

#include "rfeCmdServerDisp.h"
#include "rfe_cmd_server.h"
#include "rfe_types.h"
#include "rfe_error.h"
#include "rfe_blob_access.h"
#include "rfeSwCfgMngr.h"
#include "rfeSwFuSaMngr.h"
#include "rfeSwMainFsm.h"
#include "rfe_version.h"
#include "rfe_sw_driver_state.h"
#include "rfeSwBist.h"
#include "rfeSwDynamicTables.h"
#include "rfe_register_dump.h"
#include "rfe_tef82xx_voltage.h"

#include "rfeApiFsm.h"
#include "rfeHwLink.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#define RFE_CMD_SRV_CRC_SIZE        (4UL)           // the CRC length

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
// Variables for configuration data receiving (blob and dynamic tables)
static uint8_t  *rfeCmdServerDisp_pConfig;          // pointer to the buffer to receive the data
static bool     isDynTab = false;                   // indicator for the data destination blob/dynamic table
static uint8_t  configMsgCount = 0U;                // received messages for blob
static uint16_t configBytesReceived = 0U;           // number of bytes received for blob

/*==================================================================================================
 *                                      LOCAL FUNCTIONS PROTOTYPES
 ==================================================================================================*/
static void rfeCmdServerDisp_configureInterrupt(rfe_error_t* rfe___error___pointer);
static void rfeCmdServerDisp_registerDump(rfe_error_t* rfe___error___pointer);

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/
rfeCmdServerDispEntry_t rfeCmdServerDispTab[ RFE_CMD_IF_CMD_COUNT ] =
{
    [rfeCmdServer_cmdId_configure_e] =                          { .handler = &rfeCmdServerDisp_configure,                       .cmdDataLen = (uint8_t)RFE_CMD_SERVER_DISP_VARIABLE_LENGTH, .respDataLen = 0U },
    [rfeCmdServer_cmdId_radarCycleStart_e] =                    { .handler = &rfeCmdServerDisp_radarCycleStart,                 .cmdDataLen =  7U,                                          .respDataLen = 0U },
    [rfeCmdServer_cmdId_radarCycleStop_e] =                     { .handler = &rfeCmdServerDisp_radarCycleStop,                  .cmdDataLen =  0U,                                          .respDataLen = 2U },
    [rfeCmdServer_cmdId_getFuSaFaults_e] =                      { .handler = &rfeCmdServerDisp_getFuSaFaults,                   .cmdDataLen =  0U,                                          .respDataLen = (uint8_t)RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT },
    [rfeCmdServer_cmdId_getTime_e] =                            { .handler = &rfeCmdServerDisp_getTime,                         .cmdDataLen =  0U,                                          .respDataLen = 4U },
    [rfeCmdServer_cmdId_getVersion_e] =                         { .handler = &rfeCmdServerDisp_getVersion,                      .cmdDataLen =  0U,                                          .respDataLen = 28U },
    [rfeCmdServer_cmdId_monitorRead_e] =                        { .handler = &rfeCmdServerDisp_monitorRead,                     .cmdDataLen =  2U,                                          .respDataLen = (uint8_t)RFE_CMD_SERVER_DISP_VARIABLE_LENGTH },
    [rfeCmdServer_cmdId_getNextRadarCycleStartTime_e] =         { .handler = &rfeCmdServerDisp_getNextRadarCycleStartTime,      .cmdDataLen =  0U,                                          .respDataLen = 6U },
    [rfeCmdServer_cmdId_setNextRadarCycleStartTime_e] =         { .handler = &rfeCmdServerDisp_setNextRadarCycleStartTime,      .cmdDataLen =  4U,                                          .respDataLen = 2U },
    [rfeCmdServer_cmdId_updatePush_e] =                         { .handler = &rfeCmdServerDisp_updatePush,                      .cmdDataLen =  (uint8_t)RFE_CMD_SERVER_DISP_VARIABLE_LENGTH,.respDataLen = 2U },
    [rfeCmdServer_cmdId_testContinuousWaveTransmissionStart_e] ={ .handler = &rfeCmdServerDisp_continuousWaveTransmissionStart, .cmdDataLen =  1U,                                          .respDataLen = 0U },
    [rfeCmdServer_cmdId_testContinuousWaveTransmissionStop_e] = { .handler = &rfeCmdServerDisp_continuousWaveTransmissionStop,  .cmdDataLen =  0U,                                          .respDataLen = 0U },
    [rfeCmdServer_cmdId_testSetParam_e] =                       { .handler = &rfeCmdServerDisp_setTestparam,                    .cmdDataLen =  6U,                                          .respDataLen = 0U },
    [rfeCmdServer_cmdId_getFuSaFaultStatistics_e] =             { .handler = &rfeCmdServerDisp_getFuSaFaultStatistics,          .cmdDataLen =  0U,                                          .respDataLen = (uint8_t)(RFE_FUSA_R1_FAULT_COUNT_MAX + RFE_CMD_SERVER_DISP_FUSA_STATISTICS_SIZE ) },
    [rfeCmdServer_cmdId_getBistZeroHourReferenceData_e] =       { .handler = &rfeCmdServerDisp_getBistZeroHourReferenceData,    .cmdDataLen =  0U,                                          .respDataLen = (uint8_t)(RFE_CMD_SERVER_DISP_VARIABLE_LENGTH) },
    [rfeCmdServer_cmdId_setFrontEnd_e] =                        { .handler = &rfeCmdServer_cmdId_setFrontEnd,                   .cmdDataLen =  1U,                                          .respDataLen = 0U },
    [rfeCmdServer_cmdId_getFrontEnd_e] =                        { .handler = &rfeCmdServer_cmdId_getFrontEnd,                   .cmdDataLen =  0U,                                          .respDataLen = 1U },
    [rfeCmdServer_cmdId_testGetInternalError_e] =               { .handler = &rfeCmdServer_cmdId_getInternalError,              .cmdDataLen =  0U,                                          .respDataLen = 4U },
    [rfeCmdServer_cmdId_registerDump_e] =                       { .handler = &rfeCmdServerDisp_registerDump,              		.cmdDataLen =  3U,                                          .respDataLen = (uint8_t)RFE_CMD_SERVER_DISP_VARIABLE_LENGTH },
    [rfeCmdServer_cmdId_configureInterrupt_e] =                 { .handler = &rfeCmdServerDisp_configureInterrupt,              .cmdDataLen =  8U,                                          .respDataLen = 0U },
};

/*==================================================================================================
 *                                      LOCAL FUNCTIONS
 ==================================================================================================*/
/*-------------------------------------------------------------------
 * @brief   Function to check the received amount of blob config data against the received configuration
 *
 * @param[in]   pConfig         pointer to the received blob
 * @param[in]   bytesReceived   the total amount of data received
 * @param[in]   lastPackLen     the length of the last received packet
 *
 * @result      0 for correct data received, else error
-------------------------------------------------------------------*/
static uint8_t rfeCmdServerDisp_checkNewConfig(uint8_t *pConfig, uint16_t bytesReceived, uint16_t lastPackLen, rfe_error_t* rfe___error___pointer)
{
    // check the received blob correctness
    uint8_t rez = 0u;
    uint8_t chirpSequenceConfigCount = rfeCfg_metadata_getChirpSequenceConfigCount(pConfig, rfe___error___pointer);
    uint8_t chirpProfileCount = rfeCfg_metadata_getChirpProfileCount(pConfig, rfe___error___pointer);

    uint8_t chirpSequenceProfileCount = (chirpSequenceConfigCount > chirpProfileCount) ? chirpSequenceConfigCount : chirpProfileCount;

    uint16_t configSize = (uint16_t)(RFE_CFG_SIZE_SECTION_METADATA +
                          RFE_CFG_SIZE_SECTION_GENERAL +
                          RFE_CFG_SIZE_SECTION_MONITOR_AND_SAFETY +
                          RFE_CFG_SIZE_SECTION_RADAR_CYCLE) +
                          (uint16_t)(chirpSequenceProfileCount * (RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE + RFE_CFG_SIZE_SECTION_CHIRP_PROFILE));
    // the received length must be the exact length or with one byte more if this is done for blob/dynamic table separation
    if((configSize != bytesReceived) && (((configSize + 1U) != bytesReceived) || (lastPackLen != 1U)))
    {
        *rfe___error___pointer = rfe_error_api_invalidConfigurationSize_e;
        rez = 1u;
    }
    else
    {
        // good received configuration, update the CRC as expected, at the end of the full blob
        rfeCfg_calcAndWriteCrc((void*)pConfig, (uint32_t)RFE_CFG_OFFSET_SECTION_CRC);
    }
    return rez;
}
/*---------  rfeCmdServerDisp_checkNewConfig  ---------------------*/

/*-------------------------------------------------------------------
 * @brief   Function to move the dynamics table data
 *
 * @param[in]   pDynTable           Pointer to the first byte to be moved
 * @param[in]   dynTableLenToMove   The length to be moved
 * @param[in]   dynTableOffset      The offset to move the byte, forward or backward
 * @param[in]   goForward           The direction to make the shift, must be connected to the offset :
 *                                      true  = forward     - the offset must be "negative"
 *                                      false = backward    - the offset must be "positive"
-------------------------------------------------------------------*/
static void rfeCmdServerDisp_MemoryShift(uint8_t  *pDynTable, uint32_t dynTableLenToMove, uint32_t dynTableOffset, bool goForward)
{
    uint32_t feIdx;
    uint8_t  *pDynTableW = pDynTable;

    if(goForward)
    {
        for(feIdx = 0UL; feIdx < dynTableLenToMove; feIdx++)
        {
            pDynTableW[dynTableOffset] = *pDynTableW;                         // moving left the rest of the tables
            pDynTableW++;
        }
    }
    else
    {
        for(feIdx = 0UL; feIdx < dynTableLenToMove; feIdx++)
        {
            pDynTableW[dynTableOffset] = *pDynTableW;                         // moving left the rest of the tables
            pDynTableW--;
        }
    }
}
/*---------  rfeCmdServerDisp_MemoryShift  ---------------------*/

/*-------------------------------------------------------------------
 * @brief   Function to set the correct space for the received dynamic table, assigned to the current front-end
 *
 * @param[in]   dynTabLenReq       the length of the dynamic table to be received
 *
 * @result      pointer to the dynamic table space
-------------------------------------------------------------------*/
static uint8_t* rfeCmdServerDisp_dynTabAdjust(uint16_t dynTabLenReq, rfe_error_t* rfe___error___pointer)
{
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();
    uint32_t feId = pDrvState->frontendId;
    uint32_t feIdx, dynTableOffset = 0u, dynTableLenToMove;
    uint8_t  *pDynTable = rfeSwDynamicTables_Address(), *pDynTableWork[RFE_MAX_SUPPORTED_DEVICES], *rez = NULL_PTR;
    uint16_t dynTableLen[RFE_MAX_SUPPORTED_DEVICES];

    if(feId >= RFE_MAX_SUPPORTED_DEVICES)
    {
        // strange request, but guarded here
        *rfe___error___pointer = rfe_error_api_invalidDynamicTableValue_e;
    }
    else
    {
        // first step, get the existing status at this moment
        pDynTableWork[0] = pDynTable;
        dynTableLen[0] = *(uint16_t*)(void*)pDynTable;
        for(feIdx = 1; feIdx < RFE_MAX_SUPPORTED_DEVICES; feIdx++)
        {
            pDynTableWork[feIdx] = pDynTableWork[feIdx - 1u] + dynTableLen[feIdx - 1u];     // table pointer
            dynTableLen[feIdx] = *(uint16_t*)(void*)pDynTableWork[feIdx];                   // table length
        }
        if(feId < (RFE_MAX_SUPPORTED_DEVICES - 1u))
        {
            // only if the device is not "the last in the array"
            if(dynTableLen[feId] != dynTabLenReq)
            {
                dynTableLenToMove = 0;
                for(feIdx = feId + 1u; feIdx < RFE_MAX_SUPPORTED_DEVICES; feIdx++)
                {
                    // sum the tables to move
                    dynTableLenToMove += dynTableLen[feIdx];
                }
                dynTableOffset = (uint32_t)dynTabLenReq - (uint32_t)dynTableLen[feId];      // the necessary difference
                if(dynTableLen[feId] > dynTabLenReq)
                {
                    // the old space is bigger than tha new one
                    pDynTable = pDynTableWork[feId + 1U];                               // the start position for the move
                    rfeCmdServerDisp_MemoryShift(pDynTable, dynTableLenToMove, dynTableOffset, true);
                }
                else
                {
                    // the new required space is bigger than the existing
                    pDynTable = pDynTableWork[RFE_MAX_SUPPORTED_DEVICES - 1U] + dynTableLen[RFE_MAX_SUPPORTED_DEVICES - 1u] - 1;  // the start position for the move
                    rfeCmdServerDisp_MemoryShift(pDynTable, dynTableLenToMove, dynTableOffset, false);
                }
            }
            rez = pDynTableWork[feId];
        }
        else
        {
            rez = pDynTableWork[RFE_MAX_SUPPORTED_DEVICES - 1U];
        }
    }
    return rez;
}
/*---------  rfeCmdServerDisp_dynTabAdjust  ---------------------*/

/*-------------------------------------------------------------------
 * @brief   Function to set the correct space for the received dynamic table, assigned to the current front-end
 *
 * @param[in]   dynTabLenReq       the length of the dynamic table to be received
 *
 * @result      pointer to the dynamic table space
-------------------------------------------------------------------*/
static void rfeCmdServerDisp_updateError(rfe_error_t newError, rfe_error_t* rfe___error___pointer)
{
    if((*rfe___error___pointer == rfe_error_none_e) && (newError != rfe_error_none_e))
    {
        *rfe___error___pointer = newError;
    }
}
/*---------  rfeCmdServerDisp_updateError  ---------------------*/


/*-------------------------------------------------------------------
 * @brief   Function to read and check the blob data
 *
 * @param[in]   byteCount   the length of the blob data to be received
 *
 * @result      pointer to the dynamic table space
-------------------------------------------------------------------*/
static void rfeCmdServerDisp_receiveBlobData(uint32_t byteCount, rfe_error_t* rfe___error___pointer)
{
    uint32_t    crcCalc, crcRec;
    uint8_t     *crcPtr;

    // copy the received data to the blob buffer
    rfeCmdServer_cmdParamReadBuf(rfeCmdServerDisp_pConfig + configBytesReceived, byteCount, rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        // only if no error at this point
        configMsgCount++;
        configBytesReceived += (uint16_t)byteCount;
        if(byteCount != RFE_CFG_MAX_DATA_LENGTH)
        {
            // this is the last blob message
            // check the received data
            if(configBytesReceived > RFE_CFG_SIZE_TOTAL)
            {
                *rfe___error___pointer = rfe_error_api_invalidConfigurationSize_e;
            }
            else
            {
                // check the CRC for the received blob data
                crcCalc = rfeCrc_calBuf((void*)rfeCmdServerDisp_pConfig, (uint32_t)configBytesReceived - RFE_CMD_SRV_CRC_SIZE);  // CRC for the blob part of the message
                crcPtr = (uint8_t*)(void*)rfeCmdServerDisp_pConfig + (uint32_t)configBytesReceived - RFE_CMD_SRV_CRC_SIZE;
                crcRec = (uint32_t)*(crcPtr + 0) + ((uint32_t)*(crcPtr + 1) << 8u) + ((uint32_t)*(crcPtr + 2) << 16u) + ((uint32_t)*(crcPtr + 3) << 24u);
                if(crcCalc != crcRec)
                {
                    *rfe___error___pointer = rfe_error_api_blob_crc_wrong_e;
                }
                else
                {
                    // check the length of the received data against the received configuration
                    configBytesReceived -= (uint16_t)RFE_CMD_SRV_CRC_SIZE;              // the check routine doesn't know about CRC
                    isDynTab =
                            (rfeCmdServerDisp_checkNewConfig(rfeCmdServerDisp_pConfig, configBytesReceived, (uint16_t)byteCount, rfe___error___pointer) == 0u) ? true : false;
                }
            }
        }
    }
}
/*---------  rfeCmdServerDisp_receiveBlobData  ---------------------*/


/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/
void rfeCmdServerDisp_configure(rfe_error_t* rfe___error___pointer)
{
    static uint8_t  dynTabMsgCount = 0U;                // received messages for dynamic table
    static uint16_t dynTabBytesReceived = 0U;           // number of bytes received for dynamic table
    uint16_t        dynTabCurrentLen;                   // the current table length
    uint32_t        crcCalc, crcRec;                    // the computed/received CRC
    uint8_t*        crcPtr;                             // pointer to the received CRC
    rfe_error_t     newError;                           // the error to be reported

#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_configure: func start\n");
    }
#endif
    if(*rfe___error___pointer == rfe_error_none_e)
    {        
        uint8_t msgIndex = rfeCmdServer_cmdParamReadUint8(rfe___error___pointer);
        uint8_t msgTotal = rfeCmdServer_cmdParamReadUint8(rfe___error___pointer);
        uint32_t byteCount = rfeCmdServer_cmdParamGetByteCount(rfe___error___pointer);

        if(msgIndex == 0U)
        {          
            // First message, we reset all the reception parameters
            configMsgCount = 0U;
            configBytesReceived = 0U;
            dynTabMsgCount = 0U;
            dynTabBytesReceived = 0U;
            isDynTab = false;                                                   // first the blob data is received
            rfeCmdServerDisp_pConfig = rfeSwCfgMngr_configureBegin( rfe___error___pointer);  // get the blob configuration pointer
        }

        // received message checks
        if((configMsgCount + dynTabMsgCount) != msgIndex)
        {
            // something went wrong, the message index is not the one expected
            rfeCmdServerDisp_updateError(rfe_error_cmdInterface_invalidConfigCmdSequencing_e, rfe___error___pointer);
        }
        else
        {
            if(!isDynTab)
            {
                // receive the blob data
                rfeCmdServerDisp_receiveBlobData(byteCount, rfe___error___pointer);
            }
            else
            {
                // in dynamic table data reception
                if(dynTabMsgCount == 0U)
                {
                    // the first dynamic table message, get the correct pointer and make the necessary room
                    dynTabCurrentLen = rfeCmdServer_cmdParamReadUint16(rfe___error___pointer);
                    rfeCmdServerDisp_pConfig = rfeCmdServerDisp_dynTabAdjust(dynTabCurrentLen, rfe___error___pointer);
                    *(uint16_t*)(void*)rfeCmdServerDisp_pConfig = dynTabCurrentLen;
                    dynTabBytesReceived = 2U;
                    byteCount -= 2U;
                }
                // copy the received data to the blob buffer
                rfeCmdServer_cmdParamReadBuf(rfeCmdServerDisp_pConfig + dynTabBytesReceived, (uint32_t)byteCount, rfe___error___pointer);
                dynTabBytesReceived += (uint16_t)byteCount;
            }

            if(((msgIndex + 1U) == msgTotal) && (*rfe___error___pointer == rfe_error_none_e))
            {       // last packet received
                if(dynTabBytesReceived == 0U)
                {
                    // not really received dynamic table data, so generate a fake dynamic table and put it to the correct place
                    rfeCmdServerDisp_pConfig = rfeCmdServerDisp_dynTabAdjust(2U, rfe___error___pointer);
                    *(uint16_t*)(void*)rfeCmdServerDisp_pConfig = 2U;
                }
                else
                {
                    // CRC check for the dynamic tables
                    crcCalc = rfeCrc_calBuf((void*)rfeCmdServerDisp_pConfig, dynTabBytesReceived - RFE_CMD_SRV_CRC_SIZE);       // CRC for the blob part of the message
                    crcPtr = (uint8_t*)(void*)rfeCmdServerDisp_pConfig + dynTabBytesReceived - RFE_CMD_SRV_CRC_SIZE;
                    crcRec = (uint32_t)*(crcPtr + 0) + ((uint32_t)*(crcPtr + 1) << 8u) + ((uint32_t)*(crcPtr + 2) << 16u) + ((uint32_t)*(crcPtr + 3) << 24u);
                    newError = (crcCalc != crcRec) ? rfe_error_api_blob_crc_wrong_e : rfe_error_none_e;
                    rfeCmdServerDisp_updateError(newError, rfe___error___pointer);
                }
                rfeSwCfgMngr_configureEnd(rfe___error___pointer);
            }
        }
    }
}

void rfeCmdServerDisp_radarCycleStart(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_radarCycleStart: func start\n");
    }
#endif
    uint16_t radarCycleCountStart = rfeCmdServer_cmdParamReadUint16( rfe___error___pointer);
    bool isScheduled = rfeCmdServer_cmdParamReadBool( rfe___error___pointer);
    uint32_t startTime = rfeCmdServer_cmdParamReadUint32( rfe___error___pointer);
    rfeSwMainFsm_radarCycleStart( radarCycleCountStart, isScheduled, startTime, rfe___error___pointer);
}

void rfeCmdServerDisp_radarCycleStop(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_radarCycleStop: func start\n");
    }
#endif
    uint16_t radarCCnt =  rfeSwMainFsm_radarCycleStop(  rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint16(radarCCnt, rfe___error___pointer);
}

void rfeCmdServerDisp_getFuSaFaults(rfe_error_t* rfe___error___pointer)
{
    uint8_t fuSaFaults[RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT];
    uint8_t fuSaFaultIndex;
    for(fuSaFaultIndex = 0U; fuSaFaultIndex < (uint8_t)RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT; fuSaFaultIndex++ )
    {
        fuSaFaults[fuSaFaultIndex] = 0U;
    }
    rfeSwMainFsm_getFuSaFaults( fuSaFaults, rfe___error___pointer );
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_getFuSaFaults: func start\n");
    }
#endif
    for(fuSaFaultIndex = 0U; fuSaFaultIndex < (uint8_t)RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT; fuSaFaultIndex++ )
    {
        rfeCmdServer_cmdRespWriteUint8(fuSaFaults[fuSaFaultIndex], rfe___error___pointer);
    }
}

void rfeCmdServerDisp_getFuSaFaultStatistics(rfe_error_t* rfe___error___pointer)
{
    rfeSwFuSaMngr_fuSaFault_t fuSaFaults = { 0 };
    uint8_t fuSaFaultIndex = 0U;
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_getFuSaFaultStatistics: func start\n");
    }
#endif
    rfeSwMainFsm_getFuSaFaultStatistics( &fuSaFaults, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint16( fuSaFaults.r1FaultPromotedToR2, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint16( fuSaFaults.radaCycleCount.radarCycleCount, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint16( fuSaFaults.radaCycleCount.chirpSequenceCount, rfe___error___pointer);
    for(fuSaFaultIndex = 0U; fuSaFaultIndex < (uint8_t)rfe_fusaFault_R1_size_e; fuSaFaultIndex++ )
    {            
        rfeCmdServer_cmdRespWriteUint8( fuSaFaults.fuSaR1FaultCount[fuSaFaultIndex], rfe___error___pointer);
    }
}

void rfeCmdServerDisp_getBistZeroHourReferenceData(rfe_error_t* rfe___error___pointer)
{
    rfeSwBist_rxBistReferenceData_t zeroHourData[RFE_MAX_SUPPORTED_DEVICES];
    uint8_t feIdx;
    uint8_t antPair;

#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_getBistZeroHourReferenceData: func start\n");
    }
#endif

    rfeSwMainFsm_getBistZeroHourReferenceData(zeroHourData, rfe___error___pointer);

    if(*rfe___error___pointer == rfe_error_none_e)
    {
		for(feIdx = 0U; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
		{
			for(antPair = 0U; antPair < (uint8_t)RFE_RX_BIST_COMBINATIONS; antPair++)
			{
				rfeCmdServer_cmdRespWriteInt16(BIST_PHASE_GAIN_FLOAT_TO_INT16(zeroHourData[feIdx].refMag[antPair][TEF82XX_RFBIST_MIXER_TEST]), rfe___error___pointer);
				rfeCmdServer_cmdRespWriteInt16(BIST_PHASE_GAIN_FLOAT_TO_INT16(zeroHourData[feIdx].refMag[antPair][TEF82XX_RFBIST_LNA_TEST]), rfe___error___pointer);
				rfeCmdServer_cmdRespWriteInt16(BIST_PHASE_GAIN_FLOAT_TO_INT16(zeroHourData[feIdx].refPh[antPair][TEF82XX_RFBIST_MIXER_TEST]), rfe___error___pointer);
				rfeCmdServer_cmdRespWriteInt16(BIST_PHASE_GAIN_FLOAT_TO_INT16(zeroHourData[feIdx].refPh[antPair][TEF82XX_RFBIST_LNA_TEST]), rfe___error___pointer);
			}
		}
    }
}

void rfeCmdServerDisp_getTime(rfe_error_t* rfe___error___pointer)
{
    uint32_t rfeTime = rfeSwMainFsm_getTime( rfe___error___pointer);
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_getTime: func start\n");
    }
#endif
    rfeCmdServer_cmdRespWriteUint32( rfeTime, rfe___error___pointer);
}

void rfeCmdServerDisp_getVersion(rfe_error_t* rfe___error___pointer)
{
    rfe_version_t version = rfe_get_version( );
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_getVersion: func start\n");
    }
#endif
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();
    version.hwUniqueId= pDrvState->uniqueId;

    rfeCmdServer_cmdRespWriteUint32( version.hwType, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint32( version.hwVariant, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint32( version.hwVersion, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint32( version.hwUniqueId, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint32( version.fwVariant, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteBool( version.fwVersionReleased, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint8( version.fwVersionMajor, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint8( version.fwVersionMinor, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint8( version.fwVersionPatch, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint32( version.fwHash, rfe___error___pointer);
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_getVersion: RFE UID 0x%08x\n",version.hwUniqueId );
        RfeDbgPrintMsg("rfeCmdServerDisp_getVersion: func end\n");
    }
#endif
}

void rfeCmdServerDisp_getNextRadarCycleStartTime(rfe_error_t* rfe___error___pointer)
{
    uint16_t radarCC;
    uint32_t startTime = rfeSwMainFsm_getNextRadarCycleStartTime( &radarCC, rfe___error___pointer);
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_getNextRadarCycleStartTime: func start\n");
    }
#endif
    rfeCmdServer_cmdRespWriteUint32( startTime, rfe___error___pointer);
    rfeCmdServer_cmdRespWriteUint16( radarCC, rfe___error___pointer);
}

void rfeCmdServerDisp_setNextRadarCycleStartTime(rfe_error_t* rfe___error___pointer)
{
    uint32_t startTime = rfeCmdServer_cmdParamReadUint32( rfe___error___pointer);
    uint16_t radarCycleCnt =  rfeSwMainFsm_setNextRadarCycleStartTime( startTime, rfe___error___pointer);
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_setNextRadarCycleStartTime: func start\n");
    }
#endif
    rfeCmdServer_cmdRespWriteUint16( radarCycleCnt, rfe___error___pointer);
}


static void rfeCmdServerDisp_writeResponse32(uint32_t *valuesPtr, uint32_t limit, rfe_error_t* rfe___error___pointer)
{
    uint32_t rxIndex;

    for ( rxIndex = 0; (rxIndex < limit) && (*rfe___error___pointer == rfe_error_none_e); rxIndex++)
    {
        rfeCmdServer_cmdRespWriteUint32(valuesPtr[rxIndex], rfe___error___pointer);
    }
}

static void rfeCmdServerDisp_writeResponse16(uint16_t *valuesPtr, uint32_t limit, rfe_error_t* rfe___error___pointer)
{
    uint32_t rxIndex;

    for ( rxIndex = 0; (rxIndex < limit) && (*rfe___error___pointer == rfe_error_none_e); rxIndex++)
    {
        rfeCmdServer_cmdRespWriteUint16(valuesPtr[rxIndex], rfe___error___pointer);
    }
}

void rfeCmdServerDisp_monitorRead(rfe_error_t* rfe___error___pointer)
{
    rfe_monitorSelect_t monitorSelect = 0U;
    rfe_radarCycleCount_t cycleCount = {0};
    rfe_monitorValues_t* pMonitorValues = NULL;
    uint8_t chirpProfileIndex = 0U;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
    	monitorSelect = ( rfe_monitorSelect_t ) rfeCmdServer_cmdParamReadUint16( rfe___error___pointer);
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
    	pMonitorValues = rfeSwMainFsm_monitorRead( monitorSelect, &cycleCount, rfe___error___pointer);
    }
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_monitorRead: func start\n");
    }
#endif
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		rfeCmdServer_cmdRespWriteUint16( cycleCount.radarCycleCount, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		rfeCmdServer_cmdRespWriteUint16( cycleCount.chirpSequenceCount, rfe___error___pointer);
	}

    if ( ( monitorSelect & RFE_MONITOR_SELECT_RX_SAT_COUNT_STAGE_1I ) != 0U )
    {
        rfeCmdServerDisp_writeResponse32(pMonitorValues->rxSaturationClippingCount, RFE_RX_COUNT * RFE_MAX_SUPPORTED_DEVICES, rfe___error___pointer);
    }

    if ( ( monitorSelect & RFE_MONITOR_SELECT_PDC_CLIPPING_COUNT ) != 0U )
	{
        rfeCmdServerDisp_writeResponse32(pMonitorValues->pdcClippingCount, RFE_RX_COUNT * RFE_MAX_SUPPORTED_DEVICES, rfe___error___pointer);
	}

    if ( ( monitorSelect & RFE_MONITOR_SELECT_TEMP_BEFORE_CHIRP_SEQ ) != 0U )
    {
        rfeCmdServerDisp_writeResponse16((uint16_t*)pMonitorValues->temperature_beforeChirpSequence, RFE_TEMPERATURE_SENSOR_COUNT * RFE_MAX_SUPPORTED_DEVICES, rfe___error___pointer);
    }

    if((monitorSelect & RFE_MONITOR_SELECT_TEMP_AFTER_CHIRP_SEQ ) != 0U)
    {
        rfeCmdServerDisp_writeResponse16((uint16_t*)pMonitorValues->temperature_afterChirpSequence, RFE_TEMPERATURE_SENSOR_COUNT * RFE_MAX_SUPPORTED_DEVICES, rfe___error___pointer);
    }

    if((monitorSelect & RFE_MONITOR_SELECT_TEMP_IMMEDIATELY ) != 0U)
    {
        rfeCmdServerDisp_writeResponse16((uint16_t*)pMonitorValues->temperature_immediately, RFE_TEMPERATURE_SENSOR_COUNT * RFE_MAX_SUPPORTED_DEVICES, rfe___error___pointer);
    }

	if ( ( monitorSelect & RFE_MONITOR_SELECT_TX_POWER ) != 0U )
	{
		 for(chirpProfileIndex = 0; (chirpProfileIndex < RFE_CHIRP_PROFILES_MAX) && (*rfe___error___pointer == rfe_error_none_e); chirpProfileIndex++)
		 {
		     rfeCmdServerDisp_writeResponse16((uint16_t*)pMonitorValues->txPower[chirpProfileIndex], RFE_TX_COUNT * RFE_MAX_SUPPORTED_DEVICES, rfe___error___pointer);
		 }
	}
}

static void rfeCmdServerDisp_registerDump(rfe_error_t* rfe___error___pointer)
{
	uint32_t regDumpValues[REG_MAX_COUNT_TO_SEND] = {0UL};
	uint16_t *uint16Ptr;
	uint8_t feId = 0U;
	uint8_t moduleId = 0U;
	uint8_t regIndex = 0U;
	uint8_t regCount = 0U;
	uint8_t sendIdx = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		feId = rfeCmdServer_cmdParamReadUint8( rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		moduleId = rfeCmdServer_cmdParamReadUint8( rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		regIndex = rfeCmdServer_cmdParamReadUint8( rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
	    if(moduleId == (uint8_t)rfe_bcd_atb_voltage_e)
	    {
	        regCount = (uint8_t)getAtbVoltageMeasurements(feId, (rfe_tef82xxVoltages_t*)(void*)regDumpValues, rfe___error___pointer);
	        uint16Ptr = (uint16_t*)(void*)regDumpValues;
	    }
	    else
	    {
	        regCount = GetBcdModuleRegistersDump(feId, moduleId, regIndex, regDumpValues, rfe___error___pointer);
	    }
	}
	for(sendIdx = 0U; sendIdx < regCount; ++sendIdx)
	{
		if(*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
        if(moduleId == (uint8_t)rfe_bcd_atb_voltage_e)
        {
            rfeCmdServer_cmdRespWriteUint16(uint16Ptr[sendIdx], rfe___error___pointer);
        }
        else
        {
            rfeCmdServer_cmdRespWriteUint32(regDumpValues[sendIdx], rfe___error___pointer);
        }
	}
}

void rfeCmdServerDisp_continuousWaveTransmissionStart(rfe_error_t* rfe___error___pointer)
{
    rfe_chirpProfileIndex_t profileIndex = (rfe_chirpProfileIndex_t)rfeCmdServer_cmdParamReadUint8(rfe___error___pointer);
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_continuousWaveTransmissionStart: func start\n");
    }
#endif
    rfeMainFsm_continuousWaveTransmissionStart(profileIndex, rfe___error___pointer);
}

void rfeCmdServerDisp_continuousWaveTransmissionStop(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_continuousWaveTransmissionStop: func start\n");
    }
#endif
    rfeMainFsm_continuousWaveTransmissionStop(rfe___error___pointer);
}


void rfeCmdServerDisp_setTestparam(rfe_error_t* rfe___error___pointer)
{
	rfe_testParam_t testParam = (rfe_testParam_t)rfeCmdServer_cmdParamReadUint16(rfe___error___pointer);
    uint32_t value = rfeCmdServer_cmdParamReadUint32( rfe___error___pointer);
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_setTestparam: func start\n");
    }
#endif
    rfeSwCfgMngr_testSetParam(testParam, value, rfe___error___pointer);
}

void rfeCmdServerDisp_updatePush(rfe_error_t* rfe___error___pointer)
{
    uint16_t    byteOffset;
    uint16_t    radarCycleCountNew = 0U;
    uint8_t     updateData[RFE_CMD_SERVER_DISP_UPDATE_PUSH_DATA_SIZE_MAX];
    rfeSwCfgMngr_update_t updates[RFE_UPDATE_COUNT_MAX];
    uint32_t    updateByteCount = rfeCmdServer_cmdParamGetByteCount(rfe___error___pointer);
    uint8_t     updateCount = (uint8_t)(rfeCmdServer_cmdParamGetByteCount(rfe___error___pointer) / RFE_CMD_SERVER_DISP_UPDATE_PUSH_SINGLE_UPDATE_SIZE);
    uint8_t     updateIndex;
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServerDisp_updatePush: func start\n");
    }
#endif
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if((updateCount > RFE_UPDATE_COUNT_MAX) || ((updateByteCount % RFE_CMD_SERVER_DISP_UPDATE_PUSH_SINGLE_UPDATE_SIZE ) != 0UL))
        {
            *rfe___error___pointer = rfe_error_cmdInterface_invalidCmdLength_e;
        }
        else
        {
            rfeCmdServer_cmdParamReadBuf(updateData, updateByteCount, rfe___error___pointer);

            for(updateIndex = 0U; updateIndex < updateCount; updateIndex++)
            {
                byteOffset = (uint16_t)updateIndex * (uint16_t)RFE_CMD_SERVER_DISP_UPDATE_PUSH_SINGLE_UPDATE_SIZE;
                updates[updateIndex].section = ((uint16_t)((uint16_t)updateData[byteOffset + 1U] << 8U) | (uint16_t)updateData[byteOffset]);
                updates[updateIndex].paramIndex = (((uint16_t)updateData[byteOffset + 3U] << 8U) | (uint16_t)updateData[byteOffset + 2U]);
                updates[updateIndex].value =   ((uint32_t)updateData[byteOffset + 4U])
                                           |  (((uint32_t)updateData[byteOffset + 5U]) << 8U )
                                           |  (((uint32_t)updateData[byteOffset + 6U]) << 16U)
                                           |  (((uint32_t)updateData[byteOffset + 7U]) << 24U);
            }      
            radarCycleCountNew = rfeSwCfgMngr_updatePush( updates, updateCount, rfe___error___pointer);
            rfeCmdServer_cmdRespWriteUint16(radarCycleCountNew, rfe___error___pointer);
        }
    }
}

/*-------------------------------------------------------------------
 *  Function to set the current FE ID
-------------------------------------------------------------------*/
void rfeCmdServer_cmdId_setFrontEnd(rfe_error_t* rfe___error___pointer)
{
    uint8_t fe;
    fe = rfeCmdServer_cmdParamReadUint8(rfe___error___pointer);
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServer_cmdId_setFrontEnd: FE %d\n", fe);
    }
#endif
    if (fe >= RfeDrvStateNoFrontendsGet())
    {
        *rfe___error___pointer = rfe_error_api_invalidFrontendId_e;
    }
    else
    {
        RfeDrvStateFrontendIdSet(fe);
    }
}

/*-------------------------------------------------------------------
 *  Function to get the current FE ID
-------------------------------------------------------------------*/
void rfeCmdServer_cmdId_getFrontEnd(rfe_error_t* rfe___error___pointer)
{
    rfeDriverPersistentMem_t *pDrvState = NULL;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        pDrvState = RfeDrvStateGet();
        // out 1 byte = the current assigned FE-ID
        rfeCmdServer_cmdRespWriteUint8(pDrvState->frontendId, rfe___error___pointer);
    }
}

/*-------------------------------------------------------------------
 *  Function to retrive the internal error
-------------------------------------------------------------------*/
void rfeCmdServer_cmdId_getInternalError(rfe_error_t* rfe___error___pointer)
{
    uint32_t                    errValue;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        // out 1 uint32_t = the current internal error
        errValue = (uint32_t)rfeSwMainFsm_testGetInternalErrors(rfe___error___pointer);
        rfeCmdServer_cmdRespWriteUint32(errValue, rfe___error___pointer);
    }
}

/*-------------------------------------------------------------------
 *  Function to configure the required interrupt
-------------------------------------------------------------------*/
static void rfeCmdServerDisp_configureInterrupt(rfe_error_t* rfe___error___pointer)
{
    (void)rfe___error___pointer;                // not used parameter, required for general function signature of the dispatcher table
    rfe_error_t rfe_error = rfe_error_none_e;   // needed by the cmd param functions, the error is not propagating

    rfe_coreId_t coreId     = (rfe_coreId_t)rfeCmdServer_cmdParamReadUint16(&rfe_error);
    rfe_eventsIRQ_t events  = (rfe_eventsIRQ_t)(rfeCmdServer_cmdParamReadUint16(&rfe_error) & 0xFFU);
    rfe_apiIRQ_t rfeAPIs    = (rfe_apiIRQ_t)rfeCmdServer_cmdParamReadUint32(&rfe_error);
    rfeCmdServer_registerIRQSources( coreId, events, rfeAPIs );
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
