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
 *                                       INCLUDES
 ==================================================================================================*/

#include <string.h>
#include "rfe_sw_driver_state.h"

/*==================================================================================================
 *                                        DEFINES
==================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
static rfeGlobalPersistentMem_t gsRfeGlobalMem __attribute__((section(".RSDK_RFE_INTERNAL_MEMORY")))
																		= {{{0}}};

/*==================================================================================================
 *                                LOCAL FUNCTIONS PROTOTYPES
==================================================================================================*/
// This function init the TEF82XX global data.
// Make the whole state 0 and then adjust the parameters that need special values
static void RfeDrvStateDefaultInitTef82XX(tef82xxPersistentMem_t *const pDriverState);
/*==================================================================================================
 *                                     INTERNAL FUNCTIONS
 ==================================================================================================*/
static void RfeDrvStateDefaultInitTef82XX(tef82xxPersistentMem_t *const pDriverState)
{
    /* The return value from memset isn't relevant */
    (void)memset(pDriverState, 0, sizeof(tef82xxPersistentMem_t));
}

/*==================================================================================================
 *                                      PUBLIC FUNCTIONS
 ==================================================================================================*/
rfeDriverPersistentMem_t *RfeDrvStateGet(void)
{
    return &gsRfeGlobalMem.driverPersistentMem[gsRfeGlobalMem.frontendId];
}

rfeDriverPersistentMem_t *RfeDrvStateWithIdGet(uint32_t frontendId)
{
    return &gsRfeGlobalMem.driverPersistentMem[frontendId];
}

// Make the whole state 0 and then ajust the parameters that need special values
void RfeDrvStateDefaultInit(rfeDriverPersistentMem_t *const pDriverState)
{
	// clang-format off
	/* The return value from memset isn't relevant */
	(void)memset(pDriverState, 0, sizeof(rfeDriverPersistentMem_t));

	RfeDrvStateDefaultInitTef82XX(&pDriverState->tef82xxDrvState);
}

void RfeDrvStateFrontendIdSet(uint32_t feId)
{
    gsRfeGlobalMem.frontendId = feId;
}

uint8_t RfeDrvStateFrontendIdGet(void)
{
    return (uint8_t)gsRfeGlobalMem.frontendId;
}

void RfeDrvStateNoFrontendsSet(uint8_t nbrFe)
{
    gsRfeGlobalMem.numConnectedFrontends = nbrFe;
}

uint8_t RfeDrvStateNoFrontendsGet(void)
{
    return gsRfeGlobalMem.numConnectedFrontends;
}

void RfeDrvStateConfigurationSet(rfeFrontEnd_Configuration_t  feConfigType)
{
    gsRfeGlobalMem.feConfigType = feConfigType;
}

rfeFrontEnd_Configuration_t RfeDrvStateConfigurationGet(void)
{
    return gsRfeGlobalMem.feConfigType;
}
