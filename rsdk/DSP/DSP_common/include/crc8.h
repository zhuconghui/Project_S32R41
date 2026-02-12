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

#ifndef DSP_CRC8_H
#define DSP_CRC8_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#ifdef RSDK_AUTOSAR
#include "Std_Types.h"
#include "rsdk_version.h"
#else
#include "typedefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RSDK_AUTOSAR
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRC8_VENDOR_ID                     43

#define CRC8_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define CRC8_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define CRC8_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV

#define CRC8_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define CRC8_SW_MINOR_VERSION              RSDK_SW_MINOR
#define CRC8_SW_PATCH_VERSION              RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Verify vendor ID and version numbers for included header file: Std_Types.h */
#if (CRC8_VENDOR_ID != STD_VENDOR_ID)
    #error "crc8.h and Std_Types.h have different vendor IDs"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CRC8_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CRC8_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION) || \
         (CRC8_AR_RELEASE_REVISION_VERSION != STD_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of crc8.h and Std_Types.h are different"
    #endif
#endif


#endif /* RSDK_AUTOSAR */
/*==================================================================================================
*                                      MACROS
==================================================================================================*/

/*==================================================================================================
*                          TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef RSDK_AUTOSAR
#define DSPHD_START_SEC_CODE
#include "Dsphd_MemMap.h"
#endif

uint8 GenCrc8(const uint8* inData, uint8 numBytes);

#ifdef RSDK_AUTOSAR
#define DSPHD_STOP_SEC_CODE
#include "Dsphd_MemMap.h"
#endif


#ifdef __cplusplus
}
#endif

#endif  /*DSP_CRC8_H*/
