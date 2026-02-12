/*
 * Copyright 2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef SPT_HW_CTRL_H
#define SPT_HW_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spt_Types.h"
#include "Spt_Cfg.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_HW_CTRL_VENDOR_ID                          43
#define SPT_HW_CTRL_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define SPT_HW_CTRL_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define SPT_HW_CTRL_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define SPT_HW_CTRL_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define SPT_HW_CTRL_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define SPT_HW_CTRL_SW_PATCH_VERSION                   RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if Spt_Hw_Ctrl header file and Spt_Types header file are of the same vendor */
#if (SPT_HW_CTRL_VENDOR_ID != SPT_TYPES_VENDOR_ID)
    #error "Spt_Hw_Ctrl.h and Spt_Types.h have different vendor ids"
#endif

/* Check if Spt_Hw_Ctrl header file and Spt_Types header file are of the same Autosar version */
#if ((SPT_HW_CTRL_AR_RELEASE_MAJOR_VERSION    != SPT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_HW_CTRL_AR_RELEASE_MINOR_VERSION    != SPT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SPT_HW_CTRL_AR_RELEASE_REVISION_VERSION != SPT_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Hw_Ctrl.h and Spt_Types.h are different"
#endif

/* Check if Spt_Hw_Ctrl header file and Spt_Types header file are of the same Software version */
#if ((SPT_HW_CTRL_SW_MAJOR_VERSION != SPT_TYPES_SW_MAJOR_VERSION) || \
     (SPT_HW_CTRL_SW_MINOR_VERSION != SPT_TYPES_SW_MINOR_VERSION) || \
     (SPT_HW_CTRL_SW_PATCH_VERSION != SPT_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Hw_Ctrl.h and Spt_Types.h are different"
#endif

/* Check if Spt_Hw_Ctrl header file and Spt_Cfg header file are of the same vendor */
#if (SPT_HW_CTRL_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "Spt_Hw_Ctrl.h and Spt_Cfg.h have different vendor ids"
#endif

/* Check if Spt_Hw_Ctrl header file and Spt_Cfg header file are of the same Autosar version */
#if ((SPT_HW_CTRL_AR_RELEASE_MAJOR_VERSION    != SPT_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_HW_CTRL_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SPT_HW_CTRL_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Hw_Ctrl.h and Spt_Cfg.h are different"
#endif

/* Check if Spt_Hw_Ctrl header file and Spt_Cfg header file are of the same Software version */
#if ((SPT_HW_CTRL_SW_MAJOR_VERSION != SPT_CFG_SW_MAJOR_VERSION) || \
     (SPT_HW_CTRL_SW_MINOR_VERSION != SPT_CFG_SW_MINOR_VERSION) || \
     (SPT_HW_CTRL_SW_PATCH_VERSION != SPT_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Hw_Ctrl.h and Spt_Cfg.h are different"
#endif



/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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


Std_ReturnType  Spt_StartExec(volatile SPT_Type *pSptRegs);
#if(SPT_RUN_POLL == STD_ON)
Std_ReturnType  Spt_WaitForSptDone(volatile SPT_Type *pSptRegs, volatile sint32 *sptRetValue);
#endif
Std_ReturnType  Spt_StopHw(void);
Std_ReturnType  Spt_ConfigHw(Spt_DriverInitType const *const pSptInitInfo, volatile SPT_Type *pSptRegs);


#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SPT_HW_CTRL_H */
