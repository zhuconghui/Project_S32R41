/*
 * Copyright 2022-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef DSPHD_CMD_CLIENT_H
#define DSPHD_CMD_CLIENT_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Dsphd_Types.h"
#include "rsdk_version.h"

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPHD_CMD_CLIENT_VENDOR_ID                     43

#define DSPHD_CMD_CLIENT_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define DSPHD_CMD_CLIENT_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define DSPHD_CMD_CLIENT_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV

#define DSPHD_CMD_CLIENT_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define DSPHD_CMD_CLIENT_SW_MINOR_VERSION              RSDK_SW_MINOR
#define DSPHD_CMD_CLIENT_SW_PATCH_VERSION              RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Verify vendor ID and version numbers for included header file: Dsphd_Types.h */
#if (DSPHD_CMD_CLIENT_VENDOR_ID != DSPHD_TYPES_VENDOR_ID)
    #error "Dsphd_cmd_client.h and Dsphd_Types.h have different vendor IDs"
#endif

#if ((DSPHD_CMD_CLIENT_AR_RELEASE_MAJOR_VERSION    != DSPHD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (DSPHD_CMD_CLIENT_AR_RELEASE_MINOR_VERSION    != DSPHD_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (DSPHD_CMD_CLIENT_AR_RELEASE_REVISION_VERSION != DSPHD_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dsphd_cmd_client.h and Dsphd_Types.h are different"
#endif

#if ((DSPHD_CMD_CLIENT_SW_MAJOR_VERSION != DSPHD_TYPES_SW_MAJOR_VERSION) || \
     (DSPHD_CMD_CLIENT_SW_MINOR_VERSION != DSPHD_TYPES_SW_MINOR_VERSION) || \
     (DSPHD_CMD_CLIENT_SW_PATCH_VERSION != DSPHD_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Dsphd_cmd_client.h and Dsphd_Types.h are different"
#endif


/*==================================================================================================
*                                      MACROS
==================================================================================================*/

/*==================================================================================================
*                          TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#define DSPHD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dsphd_MemMap.h"


typedef struct {
    Dsphd_MsgTypeType type;
    uint32 payload;
    uint8 crc;
} rsdkDspHDMsg_t;


#define DSPHD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dsphd_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /*DSPHD_CMD_CLIENT_H*/
