/*
    Copyright 2024 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only be
    used strictly in accordance with the applicable license terms. By expressly
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be
    bound by the applicable license terms, then you may not retain, install,
    activate or otherwise use the software.
 */

/*
 * rfeSwDynamicTables.c
 */

/*==================================================================================================
 *   Project              : RFE_SW
 *   Platform             : S32R41-TEF82xx
 ==================================================================================================*/

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include <stddef.h>
#include <string.h>
#include "rfe_sw_cfg_tef82xx_timing_req.h"
#include "rfeSwDynamicTables.h"
#include "rfe_types.h"
#include "rfe_debug.h"
#include "rfe_blob_access.h"
#include "rfe_sw_driver_state.h"
#include "rfeHwLink.h"

// BCD LLD
#include "bc_err.h"
#include "bc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*====================================================================================================================
 *                                          CONSTANTS
 ====================================================================================================================*/

/*====================================================================================================================
 *                                      TYPES
 ====================================================================================================================*/

/*====================================================================================================================
 *                                      DEFINES AND MACROS
 ====================================================================================================================*/
// For debugging and testing purposes uncomment the next line
// "#define REVERSE_I_Q
/*====================================================================================================================
 *                                   LOCAL VARIABLES
======================================================================================================================*/
// Full dynamic tables buffer, for all connected frontends
static uint8_t          dynTbl[MAX_DYN_TBL_SIZE]                             __attribute__((section(".dtcm_bss")));
// For speed
static uint8_t          noFe                                                 __attribute__((section(".dtcm_bss")));
// Current dyn table 
static rfeTableInfo_t   activeTable[RFE_MAX_SUPPORTED_DEVICES]               __attribute__((section(".dtcm_bss")));
// Index in current dyn table
static uint16_t         tblIndex[RFE_MAX_SUPPORTED_DEVICES]                  __attribute__((section(".dtcm_bss")));
// Enable or disable IQ pins updates
static bool             updateEnable                                         __attribute__((section(".dtcm_bss")))  = false;
// Timing var used for delay update based on Dwell time, Settle time and DC group delay on first chirp
static float32_t        dwellSettleTime, dcGroupDelay                        __attribute__((section(".dtcm_bss")));
static bool             addDCGroupDelay                                      __attribute__((section(".dtcm_bss")));
static bool             firstRunUpdater                                      __attribute__((section(".dtcm_bss")));

/*====================================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
======================================================================================================================*/
static void delayUs(int32_t us);

static uint16_t getTableIdx(uint8_t feIndex);
/*====================================================================================================================
 *                                       LOCAL FUNCTIONS
======================================================================================================================*/
#pragma GCC push_options
#pragma GCC optimize ("O0")      
static void delayUs(int32_t us)
{
    volatile int32_t ns = us * 50; // at 400Mhz => 2.5ns delay per instruction ~ 8 instructions
    // TODO: add exact asm generated code 
    while(ns > 0)
    {
        ns--;
    }
}
#pragma GCC pop_options
/*====================================================================================================================*/
static uint16_t getTableIdx(uint8_t feIndex)
{
    uint16_t feTblIdx = 0U;
    uint8_t  idx;

    for( idx = 0; idx < feIndex; idx++)
    {
        feTblIdx += ((uint16_t *)dynTbl)[feTblIdx];
    }
    return feTblIdx;
}
/*====================================================================================================================
 *                                       GLOBAL FUNCTIONS
====================================================================================================================*/
uint8_t * rfeSwDynamicTables_Address(void)
{
    static bool firstRun = true;
    uint8_t feIndex;
    if (firstRun)
    {   
        // Init noFe for speed gain
        noFe = RfeDrvStateNoFrontendsGet();
        // init dyn tbls
        for(feIndex = 0; feIndex < RFE_MAX_SUPPORTED_DEVICES; feIndex++)
        {
            ((uint16_t*)dynTbl)[feIndex] = 2u;
        }
        firstRun = false;
    }
    return dynTbl;
}

void rfeSwDynamicTables_TableSet(rfeDriverPersistentMem_t *const pDrvState, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    uint8_t    feIndex;
    uint8_t    tblNumber;
    uint16_t   tblIdx;
    uint16_t   feTblIdx;
/*
Table header :
	Table blob index in bytes - uint16
	Table size in bytes -  uint16
Dynamic tables structure in blob:
 
1 - Total size (blob size in bytes) = uint16
2 - Number of tables (y)- uint8
3 - Tbl header 0. Table header 1 .... Table header (y-1)
*/

	if (*rfe___error___pointer == rfe_error_none_e)
	{
        feIndex = (uint8_t)pDrvState->frontendId;
        // Get dyn tbl index for sequence  
        if (rfeCfg_chirpSequence_getDynamicUpdatesEnabled(pDrvState->rfeConfig, chirpSequenceConfigIndex, rfe___error___pointer))
        {
            // Setup TEF82xx QPSK control
            // Get dyn tbl numer used in current sequence
            tblNumber = rfeCfg_chirpSequence_getDynamicTableIndex(pDrvState->rfeConfig, chirpSequenceConfigIndex, rfe___error___pointer);
            // Get table header index
            feTblIdx = getTableIdx(feIndex);
            // this is the significance of the next line : tblIdx = sizeof(uint16_t) + sizeof(uint8_t) + tblNumber * (sizeof(uint16_t) + sizeof(uint16_t))
            tblIdx = 3U + (((uint16_t)tblNumber * 4U) + feTblIdx);
            // check for overflow
            if (((feTblIdx >= MAX_DYN_TBL_SIZE) || ((tblIdx + 2U) >= MAX_DYN_TBL_SIZE)) && (*rfe___error___pointer == rfe_error_none_e))
            {
                *rfe___error___pointer = rfe_error_parameterOutOfRange_e;
            }
            else
            {
                activeTable[feIndex].startOfTable = *((uint16_t *)(dynTbl + tblIdx)) + feTblIdx;
                activeTable[feIndex].sizeOfTable = *((uint16_t *)(dynTbl + tblIdx + 2U));
                activeTable[feIndex].active = TRUE;
                tblIndex[feIndex] = 0U;
                // Get max Dwell time of chirp profiles
                RfeSwCfgTimingReq_GetDynIQUpdatesTiming(&dwellSettleTime, &dcGroupDelay);
                // Reset group delay apply logic
                addDCGroupDelay = false;
                if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled == TRUE)
                {   // No DCGroup delay for CPM
                    firstRunUpdater = false;
                }
                else
                {
                    firstRunUpdater = true;
                }
#ifdef RFE_DEBUG
                if (gRfeDebugLevel <= e_rfe_debug_level_dyn_tbl)
                {
                    RfeDbgPrintMsg("rfeSwDynamicTables_TableSet: FE: %d Table start: %d Table size: %d\n", feIndex, activeTable[feIndex].startOfTable, activeTable[feIndex].sizeOfTable);
                    RfeDbgPrintMsg(" --");
                    for(tblIdx = 0; tblIdx < activeTable[feIndex].sizeOfTable; tblIdx++)
                    {
                        RfeDbgPrintMsg(" %x", dynTbl[activeTable[feIndex].startOfTable + tblIdx]);
                    }
                    RfeDbgPrintMsg("\n");
                    RfeDbgPrintMsg("rfeSwDynamicTables_TableSet: FE: %d dwellSettleTime: %d : dcGroupDelay %d\n", feIndex, (int32_t)dwellSettleTime, (int32_t)dcGroupDelay);                
                }
#endif       
            }         
        }
        else
        {
            activeTable[feIndex].active = FALSE;
        }
    }
}
/*====================================================================================================================*/
void rfeSwDynamicTables_IQUpdate(void)
{
    uint8_t     feIndex;
    uint16_t    tblIdx;
    uint8_t     Q1, Q2, Q3, I1, I2, I3;
    int32_t     us;
    float32_t   fVal;

    if(updateEnable)
    {
        // Wait to be sure that we apply I and Q pins values after dwell and settle on current chirp
        if (addDCGroupDelay)
        {
            fVal = (dwellSettleTime + dcGroupDelay);
            us = (int32_t)fVal;
            addDCGroupDelay = false;
        }
        else
        {
            us = (int32_t)dwellSettleTime;
        }
        delayUs(us);
        if (firstRunUpdater)
        {
            addDCGroupDelay = true;
            firstRunUpdater = false;
        }
        for(feIndex = 0; feIndex < noFe; feIndex++)
        {
            if (activeTable[feIndex].active == TRUE)
            {            
                // Get index of data in table
                tblIdx = activeTable[feIndex].startOfTable + (tblIndex[feIndex] % activeTable[feIndex].sizeOfTable);
                // Get Q and I from byte
                Q1 = (dynTbl[tblIdx] & 0x01U); // Q1
                I1 = ((dynTbl[tblIdx] >> 1U) & 0x01U); // I1
                Q2 = ((dynTbl[tblIdx] >> 2U) & 0x01U); // Q2
                I2 = ((dynTbl[tblIdx] >> 3U) & 0x01U); // I2
                Q3 = ((dynTbl[tblIdx] >> 4U) & 0x01U); // Q3
                I3 = ((dynTbl[tblIdx] >> 5U) & 0x01U); // I3
                // Set Q and I pins
#ifndef REVERSE_I_Q            
                RfeHwGpioSet((uint32_t)feIndex, e_TX1_Q_PS, Q1);
                RfeHwGpioSet((uint32_t)feIndex, e_TX1_I_PS, I1);
                RfeHwGpioSet((uint32_t)feIndex, e_TX2_Q_PS, Q2);
                RfeHwGpioSet((uint32_t)feIndex, e_TX2_I_PS, I2);
                RfeHwGpioSet((uint32_t)feIndex, e_TX3_Q_PS, Q3);
                RfeHwGpioSet((uint32_t)feIndex, e_TX3_I_PS, I3);
#else
                RfeHwGpioSet(feIndex, e_TX1_Q_PS, I1);
                RfeHwGpioSet(feIndex, e_TX1_I_PS, Q1);
                RfeHwGpioSet(feIndex, e_TX2_Q_PS, I2);
                RfeHwGpioSet(feIndex, e_TX2_I_PS, Q2);
                RfeHwGpioSet(feIndex, e_TX3_Q_PS, I3);
                RfeHwGpioSet(feIndex, e_TX3_I_PS, Q3);
#endif
                // Increment index in table
                tblIndex[feIndex]++;
            } // if (activeTable[feIndex].active)
        } // for( feIndex = 0; feIndex < noFe; feIndex++)
    } // if (updateEnable)
}
/*====================================================================================================================*/
void rfeSwDynamicTables_IQUpdateEnabled(bool enable)
{
    updateEnable = enable;
}
/*====================================================================================================================*/

#ifdef __cplusplus
}
#endif

/*====================================================================================================================
 * EOF
 *====================================================================================================================*/

/** @} */
