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

#ifndef SPT_IRQ_H
#define SPT_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spt_Types.h"
#include "Spt_Cfg.h"
#include "rsdk_version.h"




#include "OsIf_Internal.h"
#include "CDD_Spt_Cbk.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_IRQ_VENDOR_ID                          43
#define SPT_IRQ_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define SPT_IRQ_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define SPT_IRQ_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define SPT_IRQ_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define SPT_IRQ_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define SPT_IRQ_SW_PATCH_VERSION                   RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if Spt_Irq header file and Spt_Types header file are of the same vendor */
#if (SPT_IRQ_VENDOR_ID != SPT_TYPES_VENDOR_ID)
    #error "Spt_Irq.h and Spt_Types.h have different vendor ids"
#endif

/* Check if Spt_Irq header file and Spt_Types header file are of the same Autosar version */
#if ((SPT_IRQ_AR_RELEASE_MAJOR_VERSION    != SPT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_AR_RELEASE_MINOR_VERSION    != SPT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_AR_RELEASE_REVISION_VERSION != SPT_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq.h and Spt_Types.h are different"
#endif

/* Check if Spt_Irq header file and Spt_Types header file are of the same Software version */
#if ((SPT_IRQ_SW_MAJOR_VERSION != SPT_TYPES_SW_MAJOR_VERSION) || \
     (SPT_IRQ_SW_MINOR_VERSION != SPT_TYPES_SW_MINOR_VERSION) || \
     (SPT_IRQ_SW_PATCH_VERSION != SPT_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq.h and Spt_Types.h are different"
#endif

/* Check if Spt_Irq header file and Spt_Cfg header file are of the same vendor                                */
#if (SPT_IRQ_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "Spt_Irq.h and Spt_Cfg.h have different vendor ids"
#endif

/* Check if Spt_Irq header file and Spt_Cfg configuration header file are of the same Autosar version         */
#if ((SPT_IRQ_AR_RELEASE_MAJOR_VERSION   != SPT_CFG_AR_RELEASE_MAJOR_VERSION) ||   \
    (SPT_IRQ_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) ||   \
    (SPT_IRQ_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Spt_Irq.h and Spt_Cfg.h are different"
#endif

/* Check if Spt_Irq header file and Spt_Cfg configuration header file are of the same software version        */
#if ((SPT_IRQ_SW_MAJOR_VERSION   != SPT_CFG_SW_MAJOR_VERSION) ||     \
    (SPT_IRQ_SW_MINOR_VERSION    != SPT_CFG_SW_MINOR_VERSION) ||     \
    (SPT_IRQ_SW_PATCH_VERSION    != SPT_CFG_SW_PATCH_VERSION)        \
    )
    #error "Software Version Numbers of Spt_Irq.h and Spt_Cfg.h are different"
#endif

/* Check if Spt_Irq header file and CDD_Spt_Cbk header file are of the same vendor                  */
#if (SPT_IRQ_VENDOR_ID != CDD_SPT_CBK_VENDOR_ID)
    #error "Spt_Irq.h and CDD_Spt_Cbk.h have different vendor ids"
#endif

/* Check if Spt_Irq header file and CDD_Spt_Cbk header file are of the same Autosar version         */
#if ((SPT_IRQ_AR_RELEASE_MAJOR_VERSION   != CDD_SPT_CBK_AR_RELEASE_MAJOR_VERSION) ||   \
    (SPT_IRQ_AR_RELEASE_MINOR_VERSION    != CDD_SPT_CBK_AR_RELEASE_MINOR_VERSION) ||   \
    (SPT_IRQ_AR_RELEASE_REVISION_VERSION != CDD_SPT_CBK_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Spt_Irq.h and CDD_Spt_Cbk.h are different"
#endif

/* Check if Spt_Irq header file and CDD_Spt_Cbk header file are of the same software version        */
#if ((SPT_IRQ_SW_MAJOR_VERSION   != CDD_SPT_CBK_SW_MAJOR_VERSION) ||     \
    (SPT_IRQ_SW_MINOR_VERSION    != CDD_SPT_CBK_SW_MINOR_VERSION) ||     \
    (SPT_IRQ_SW_PATCH_VERSION    != CDD_SPT_CBK_SW_PATCH_VERSION)        \
    )
    #error "Software Version Numbers of Spt_Irq.h and CDD_Spt_Cbk.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Spt_Irq.h file and OsIf_Internal header file are of the same AutoSar version */
#if ((SPT_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Spt_Irq.h and OsIf_Internal.h are different"
#endif
#endif



/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define SPT_IRQ_ARG void

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define SPT_START_SEC_CODE
#include "Spt_MemMap.h"




ISR(Spt_EcsIsr);
ISR(Spt_EvtIsr);
#if(SPT_DSP_ENABLE == STD_ON)
ISR(Spt_DspIsr);
#endif










#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SPT_IRQ_H */
