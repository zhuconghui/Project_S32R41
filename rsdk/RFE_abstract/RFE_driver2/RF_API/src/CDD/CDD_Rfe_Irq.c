/*==================================================================================================
* Copyright 2022-2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
==================================================================================================*/

/**
*   @file
*   @implements CDD_Rfe_Irq.c_Artifact
*
*   @addtogroup CDD_RFE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Rfe_Irq.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_RFE_IRQ_C_VENDOR_ID                     43 
#define CDD_RFE_IRQ_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define CDD_RFE_IRQ_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define CDD_RFE_IRQ_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define CDD_RFE_IRQ_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define CDD_RFE_IRQ_C_SW_MINOR_VERSION              RSDK_SW_MINOR
#define CDD_RFE_IRQ_C_SW_PATCH_VERSION              RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if(CDD_RFE_VERSION_INFO_API == STD_ON)

/* Check if CDD_Rfe source file and CDD_Rfe_Irq header file are of the same vendor */
#if (CDD_RFE_IRQ_C_VENDOR_ID != CDD_RFE_IRQ_VENDOR_ID)
    #error "CDD_Rfe_Irq.c and CDD_Rfe_Irq.h have different vendor ids"
#endif

/* Check if CDD_Rfe_Irq.c source file and CDD_Rfe_Irq.h header file are of the same Autosar version */
#if ( \
     (CDD_RFE_IRQ_C_AR_RELEASE_MAJOR_VERSION    != CDD_RFE_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_RFE_IRQ_C_AR_RELEASE_MINOR_VERSION    != CDD_RFE_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (CDD_RFE_IRQ_C_AR_RELEASE_REVISION_VERSION != CDD_RFE_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Rfe_Irq.c and CDD_Rfe_Irq.h are different"
#endif


/* Check if CDD_Rfe_Irq.h source file and CDD_Rfe_Irq.h header file are of the same Autosar version */
#if ( \
     (CDD_RFE_IRQ_C_SW_MAJOR_VERSION != CDD_RFE_IRQ_SW_MAJOR_VERSION) || \
     (CDD_RFE_IRQ_C_SW_MINOR_VERSION != CDD_RFE_IRQ_SW_MINOR_VERSION) || \
     (CDD_RFE_IRQ_C_SW_PATCH_VERSION != CDD_RFE_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rfe_Irq.c and CDD_Rfe_Irq.h are different"
#endif

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

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                              GLOBAL FUNCTIONS
==================================================================================================*/


/*================================================================================================*/

#ifdef __cplusplus
}
#endif
