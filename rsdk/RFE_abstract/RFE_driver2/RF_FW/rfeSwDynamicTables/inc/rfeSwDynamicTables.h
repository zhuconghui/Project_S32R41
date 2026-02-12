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
 * rfeSwDynamicTables.h
 *
 */

/*====================================================================================================================
 *   Project              : RFE_SW
 *   Platform             : S32R41-TEF82xx
 ====================================================================================================================*/
#ifndef RFE_SW_DYNAMIC_TABLES_H
#define RFE_SW_DYNAMIC_TABLES_H

/*====================================================================================================================
 *                              INCLUDES
 ====================================================================================================================*/
#include "rfe_error.h"
#include "rfe_types.h"
#include "bc_types.h"
#include "rfe_sw_driver_state.h"
/*====================================================================================================================
 *                                      DEFINES
 ====================================================================================================================*/
#define MAX_DYN_TBL_SIZE (49152U) // 48Kbytes in bytes
/*====================================================================================================================
 *                                      TYPES
 ====================================================================================================================*/
typedef struct 
{
    uint16_t    sizeOfTable;
    uint16_t    startOfTable;
    BOOL        active;
} rfeTableInfo_t;
/*====================================================================================================================
 *                                       GLOBALS
 ====================================================================================================================*/

/*====================================================================================================================
 *                                       FUNCTIONS
====================================================================================================================*/
/**
 * \brief Returns the address for dynamic tables buffer
 *
 * \details On first call, init the table and prepare for dyn tables operations.
 * 
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \return NIL
 */
uint8_t * rfeSwDynamicTables_Address(void);

/**
 * \brief Function used for frontend I and Q pins updates
 *
 * \param [in,out]  none
 *
 * \return NIL
 */
void rfeSwDynamicTables_IQUpdate(void);

/**
 * \brief Setup QPSK update for current sequence  
 *
 * \pre rfeSwDynamicTables_Address
 * 
 * \param [in]      pDrvState - frontend persistent memory state, data and settings
 * \param [in]      chirpSequenceConfigIndex - current chirp sequence
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \return NIL
 */
void rfeSwDynamicTables_TableSet(rfeDriverPersistentMem_t *const pDrvState, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief Function used for activating rfeSwDynamicTables_IQUpdate
 *
 * \details It is needed for guarding false update from int trigger on toggle test
 * 
 * \param [in,out]  none
 *
 * \return NIL
 */
void rfeSwDynamicTables_IQUpdateEnabled(bool enable);

#endif // !RFE_SW_DYNAMIC_TABLES_H
