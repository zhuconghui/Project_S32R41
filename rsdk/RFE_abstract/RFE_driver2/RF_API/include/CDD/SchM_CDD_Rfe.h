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

#ifndef SCHM_CDD_RFE_H
#define SCHM_CDD_RFE_H

/**
*   @file
*
*   @addtogroup CDD_RFE_MODULE
*   @{
*/

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section SchM_Cdd_Rfe_h_REF_1
* Violates MISRA 2012 Required Rule 5.1, #External identifiers shall be distinct
* The names for EXCLUSIVE_AREA respect the generation rules.
*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_CDD_RFE_AR_RELEASE_MAJOR_VERSION     4
#define SCHM_CDD_RFE_AR_RELEASE_MINOR_VERSION     4
#define SCHM_CDD_RFE_AR_RELEASE_REVISION_VERSION  0
#define SCHM_CDD_RFE_SW_MAJOR_VERSION             0
#define SCHM_CDD_RFE_SW_MINOR_VERSION             8
#define SCHM_CDD_RFE_SW_PATCH_VERSION             3

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Number of cores id */
#define NUMBER_OF_CORES         (uint8)(3U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"


/* The Below part of code to be used when SCHM is integrated. */
extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_05(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_06(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_06(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_07(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_07(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_08(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_08(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_09(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_09(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_10(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_10(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_11(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_11(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_12(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_12(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_13(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_13(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_14(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_14(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_15(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_15(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_16(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_16(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_17(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_17(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_18(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_18(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_19(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_19(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_20(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_20(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_21(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_21(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_22(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_22(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_23(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_23(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_24(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_24(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_25(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_25(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_26(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_26(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_27(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_27(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_28(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_28(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_29(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_29(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_30(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_30(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_31(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_31(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_32(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_32(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_33(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_33(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_34(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_34(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_35(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_35(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_36(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_36(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_37(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_37(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_38(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_38(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_39(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_39(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_40(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_40(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_41(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_41(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_42(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_42(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_43(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_43(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_44(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_44(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_45(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_45(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_46(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_46(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_47(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_47(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_48(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_48(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_49(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_49(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_50(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_50(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_54(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_54(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_55(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_55(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_56(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_56(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_57(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_57(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_58(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_58(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_59(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_59(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_60(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_60(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_61(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_61(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_62(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_62(void);

extern void SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_63(void);
extern void SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_63(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_CDD_RFE_H */
