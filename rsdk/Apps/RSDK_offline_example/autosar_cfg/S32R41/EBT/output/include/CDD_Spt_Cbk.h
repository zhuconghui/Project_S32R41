/*
 * Copyright 2021-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef CDD_SPT_CBK_H
#define CDD_SPT_CBK_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Spt.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_SPT_CBK_VENDOR_ID                          43
#define CDD_SPT_CBK_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define CDD_SPT_CBK_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define CDD_SPT_CBK_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define CDD_SPT_CBK_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define CDD_SPT_CBK_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define CDD_SPT_CBK_SW_PATCH_VERSION                   RSDK_SW_PATCH

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if CDD_Spt_Cbk header file and CDD_Spt.h header file are of the same vendor */
#if (CDD_SPT_CBK_VENDOR_ID != CDD_SPT_VENDOR_ID)
    #error "CDD_Spt_Cbk.h and CDD_Spt.h have different vendor ids"
#endif

/* Check if CDD_Spt_Cbk header file and CDD_Spt.h header file are of the same Autosar version */
#if ((CDD_SPT_CBK_AR_RELEASE_MAJOR_VERSION    != CDD_SPT_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SPT_CBK_AR_RELEASE_MINOR_VERSION    != CDD_SPT_AR_RELEASE_MINOR_VERSION) || \
     (CDD_SPT_CBK_AR_RELEASE_REVISION_VERSION != CDD_SPT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Spt_Cbk.h and CDD_Spt.h are different"
#endif

/* Check if CDD_Spt_Cbk header file and CDD_Spt.h header file are of the same Software version */
#if ((CDD_SPT_CBK_SW_MAJOR_VERSION != CDD_SPT_SW_MAJOR_VERSION) || \
     (CDD_SPT_CBK_SW_MINOR_VERSION != CDD_SPT_SW_MINOR_VERSION) || \
     (CDD_SPT_CBK_SW_PATCH_VERSION != CDD_SPT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Spt_Cbk.h and CDD_Spt.h are different"
#endif

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPT_START_SEC_CODE
#include "Spt_MemMap.h"

void Spt_EcsIsrCb(rsdkStatus_t isrStatus, uint32 errInfo);
void Spt_EvtIsrCb(rsdkStatus_t isrStatus, uint32 evtInfo);

#if(SPT_DSP_ENABLE == STD_ON)
void Spt_DspIsrCb(rsdkStatus_t isrStatus, uint32 errInfo);
void Spt_DspBootloaderCb(void);
#endif

#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
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

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_SPT_CBK_H */

