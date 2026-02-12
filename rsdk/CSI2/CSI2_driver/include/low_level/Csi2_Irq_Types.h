/*
 * Copyright 2021-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef CSI2_IRQ_TYPES_H
#define CSI2_IRQ_TYPES_H

/**
*   @file
*   @implements Csi2_Ip.h_Artifact
*
*   @internal
*   @addtogroup
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

    #include "StandardTypes.h"
	#include "rsdk_version.h"




/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

    #define CSI2_IRQ_TYPES_VENDOR_ID                          43
    #define CSI2_IRQ_TYPES_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
    #define CSI2_IRQ_TYPES_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
    #define CSI2_IRQ_TYPES_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
    #define CSI2_IRQ_TYPES_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
    #define CSI2_IRQ_TYPES_SW_MINOR_VERSION                   RSDK_SW_MINOR
    #define CSIRSDK_SW_PATCH_IRQ_TYPES_SW_PATCH_VERSION       RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if header file and StandardTypes header file are of the same AutoSar version */
        #if ((CSI2_IRQ_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
             (CSI2_IRQ_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CSI2_Irq_Types.h and StandardTypes.h are different"
        #endif
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


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CSI2_IRQ_TYPES_H */
