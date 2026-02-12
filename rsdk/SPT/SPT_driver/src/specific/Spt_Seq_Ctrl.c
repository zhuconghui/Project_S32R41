/*
 * Copyright 2019-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Spt_Seq_Ctrl.h"
#include "Spt_Internals.h"
#include "Spt_Cfg.h"

#include "SchM_Spt.h"


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_SEQ_CTRL_C_VENDOR_ID                     43
#define SPT_SEQ_CTRL_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define SPT_SEQ_CTRL_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define SPT_SEQ_CTRL_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define SPT_SEQ_CTRL_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define SPT_SEQ_CTRL_C_SW_MINOR_VERSION              RSDK_SW_MINOR
#define SPT_SEQ_CTRL_C_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if Spt_Seq_Ctrl source file and Spt_Seq_Ctrl header file are of the same vendor */
#if (SPT_SEQ_CTRL_C_VENDOR_ID != SPT_SEQ_CTRL_VENDOR_ID)
    #error "Spt_Seq_Ctrl.c and Spt_Seq_Ctrl.h have different vendor ids"
#endif

/* Check if Spt_Seq_Ctrl source file and Spt_Seq_Ctrl header file are of the same Autosar version */
#if ((SPT_SEQ_CTRL_C_AR_RELEASE_MAJOR_VERSION    != SPT_SEQ_CTRL_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_SEQ_CTRL_C_AR_RELEASE_MINOR_VERSION    != SPT_SEQ_CTRL_AR_RELEASE_MINOR_VERSION) || \
     (SPT_SEQ_CTRL_C_AR_RELEASE_REVISION_VERSION != SPT_SEQ_CTRL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Seq_Ctrl.c and Spt_Seq_Ctrl.h are different"
#endif

/* Check if Spt_Seq_Ctrl source file and Spt_Seq_Ctrl header file are of the same Software version */
#if ((SPT_SEQ_CTRL_C_SW_MAJOR_VERSION != SPT_SEQ_CTRL_SW_MAJOR_VERSION) || \
     (SPT_SEQ_CTRL_C_SW_MINOR_VERSION != SPT_SEQ_CTRL_SW_MINOR_VERSION) || \
     (SPT_SEQ_CTRL_C_SW_PATCH_VERSION != SPT_SEQ_CTRL_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Seq_Ctrl.c and Spt_Seq_Ctrl.h are different"
#endif

/* Check if Spt_Seq_Ctrl source file and Spt_Internals header file are of the same vendor */
#if (SPT_SEQ_CTRL_C_VENDOR_ID != SPT_INTERNALS_VENDOR_ID)
    #error "Spt_Seq_Ctrl.c and Spt_Internals.h have different vendor ids"
#endif

/* Check if Spt_Seq_Ctrl source file and Spt_Internals header file are of the same Autosar version */
#if ((SPT_SEQ_CTRL_C_AR_RELEASE_MAJOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_SEQ_CTRL_C_AR_RELEASE_MINOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (SPT_SEQ_CTRL_C_AR_RELEASE_REVISION_VERSION != SPT_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Seq_Ctrl.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Seq_Ctrl source file and Spt_Internals header file are of the same Software version */
#if ((SPT_SEQ_CTRL_C_SW_MAJOR_VERSION != SPT_INTERNALS_SW_MAJOR_VERSION) || \
     (SPT_SEQ_CTRL_C_SW_MINOR_VERSION != SPT_INTERNALS_SW_MINOR_VERSION) || \
     (SPT_SEQ_CTRL_C_SW_PATCH_VERSION != SPT_INTERNALS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Seq_Ctrl.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Seq_Ctrl source file and Spt_Cfg header file are of the same vendor */
#if (SPT_SEQ_CTRL_C_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "Spt_Seq_Ctrl.c and Spt_Cfg.h have different vendor ids"
#endif

/* Check if Spt_Seq_Ctrl source file and Spt_Cfg header file are of the same Autosar version */
#if ((SPT_SEQ_CTRL_C_AR_RELEASE_MAJOR_VERSION    != SPT_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_SEQ_CTRL_C_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SPT_SEQ_CTRL_C_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Seq_Ctrl.c and Spt_Cfg.h are different"
#endif

/* Check if Spt_Seq_Ctrl source file and Spt_Cfg header file are of the same Software version */
#if ((SPT_SEQ_CTRL_C_SW_MAJOR_VERSION != SPT_CFG_SW_MAJOR_VERSION) || \
     (SPT_SEQ_CTRL_C_SW_MINOR_VERSION != SPT_CFG_SW_MINOR_VERSION) || \
     (SPT_SEQ_CTRL_C_SW_PATCH_VERSION != SPT_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Seq_Ctrl.c and Spt_Cfg.h are different"
#endif



/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define SPT_START_SEC_CODE
#include "Spt_MemMap.h"


/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/



#if (SPT_SINGLE_THREAD == STD_OFF)
Std_ReturnType Spt_ApiSequenceTryEnter(void)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;

    SchM_Enter_Spt_SPT_EXCLUSIVE_AREA_00();

    if (gSptMemPer.drvBusyFlag == FALSE)
    {
        gSptMemPer.drvBusyFlag = TRUE;
    }
    else
    {
        status = SPT_REPORT_ERROR(RSDK_SPT_RET_WARN_DRV_BUSY, SPT_API_CALL, SPT_E_WARN_DRV_BUSY);
    }

    SchM_Exit_Spt_SPT_EXCLUSIVE_AREA_00();

    return status;
}

void Spt_ApiSequenceExit(void)
{
    SchM_Enter_Spt_SPT_EXCLUSIVE_AREA_01();

    gSptMemPer.drvBusyFlag = FALSE;

    SchM_Exit_Spt_SPT_EXCLUSIVE_AREA_01();
}
#endif /* #if (SPT_SINGLE_THREAD == STD_OFF) */













































































#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
