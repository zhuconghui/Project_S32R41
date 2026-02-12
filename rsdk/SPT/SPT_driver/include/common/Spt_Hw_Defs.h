
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









#ifndef SPT_HW_DEFS_H
#define SPT_HW_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_HW_DEFS_VENDOR_ID                          43
#define SPT_HW_DEFS_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define SPT_HW_DEFS_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define SPT_HW_DEFS_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define SPT_HW_DEFS_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define SPT_HW_DEFS_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define SPT_HW_DEFS_SW_PATCH_VERSION                   RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define SPT_CS_STATUS0_STOP_BIT         (0x8u)
#define SPT_CS_STATUS1_W1C_MASK         (0x00000FFFu)
#define SPT_CS_STATUS0_W1C_MASK         (0x8001FFFFu)
#define SPT_HIST_OVF_W1C_MASK           (0xFFFFFFFFu)

/*--------------------------------------------------*/


















/*--------------------------------------------------*/

#define SPT_MEM_ERR_STATUS_W1C_MASK     (0x10114506u)
#define SPT_HW_ACC_ERR_STATUS_W1C_MASK  (0xFFF99FEFu)
#define SPT_GBL_STATUS_W1C_MASK         (0x00030707u)
#define SPT_GBL_STATUS_ERR_W1C_MASK     (0x00030700u)  /* masks only the error flags in GBL_STATUS */

#define SPT_SCS_STATUS0_W1C_MASK        (0x0001FFFFu)
#define SPT_SCS_STATUS1_W1C_MASK        (0x00000FFFu)

#define SPT_WR_ACCESS_ERR_REG_W1C_MASK  (0x07070707u)
#define SPT_CS_EVTREG1_MASK             (0xFFFFFFFFu)  /* 32 event lines from SPT to CPU */
#define SPT_DSP_ERR_INFO_REG_MASK       (0xFFFFFFFFu)

/*--------------------------------------------------*/














/*--------------------------------------------------*/










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

#endif  /* SPT_HW_DEFS_H */
