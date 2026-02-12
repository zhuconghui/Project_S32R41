
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








#ifndef SPT_INTERNALS_H
#define SPT_INTERNALS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Spt.h"
#include "Spt_Internals_Types.h"
#include "Spt_Cfg.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_INTERNALS_VENDOR_ID                          43
#define SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define SPT_INTERNALS_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define SPT_INTERNALS_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define SPT_INTERNALS_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define SPT_INTERNALS_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define SPT_INTERNALS_SW_PATCH_VERSION                   RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check CDD_Spt.h versions                                                                              */
#if (SPT_INTERNALS_VENDOR_ID != CDD_SPT_VENDOR_ID)
    #error "Spt_Internals.h and CDD_Spt.h have different vendor ids"
#endif

/* Check if Spt_Internals header file and CDD_Spt header file are of the same Autosar version       */
#if ((SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION   != CDD_SPT_AR_RELEASE_MAJOR_VERSION) ||   \
    (SPT_INTERNALS_AR_RELEASE_MINOR_VERSION    != CDD_SPT_AR_RELEASE_MINOR_VERSION) ||   \
    (SPT_INTERNALS_AR_RELEASE_REVISION_VERSION != CDD_SPT_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Spt_Internals.h and CDD_Spt.h are different"
#endif

/* Check if Spt_Internals header file and CDD_Spt header file are of the same software version      */
#if ((SPT_INTERNALS_SW_MAJOR_VERSION   != CDD_SPT_SW_MAJOR_VERSION) ||   \
    (SPT_INTERNALS_SW_MINOR_VERSION    != CDD_SPT_SW_MINOR_VERSION) ||   \
    (SPT_INTERNALS_SW_PATCH_VERSION    != CDD_SPT_SW_PATCH_VERSION)      \
    )
    #error "Software Version Numbers of Spt_Internals.h and CDD_Spt.h are different"
#endif

/* Check Spt_Internals_Types.h versions                                                                              */
#if (SPT_INTERNALS_VENDOR_ID != SPT_INTERNALS_TYPES_VENDOR_ID)
    #error "Spt_Internals_.h and Spt_Internals_Types.h have different vendor ids"
#endif

/* Check if Spt_Internals header file and Spt_Internals_Types header file are of the same Autosar version       */
#if ((SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION   != SPT_INTERNALS_TYPES_AR_RELEASE_MAJOR_VERSION) ||   \
    (SPT_INTERNALS_AR_RELEASE_MINOR_VERSION    != SPT_INTERNALS_TYPES_AR_RELEASE_MINOR_VERSION) ||   \
    (SPT_INTERNALS_AR_RELEASE_REVISION_VERSION != SPT_INTERNALS_TYPES_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Spt_Internals.h and Spt_Internals_Types.h are different"
#endif

/* Check if Spt_Internals header file and Spt_Internals_Types header file are of the same software version      */
#if ((SPT_INTERNALS_SW_MAJOR_VERSION   != SPT_INTERNALS_TYPES_SW_MAJOR_VERSION) ||   \
    (SPT_INTERNALS_SW_MINOR_VERSION    != SPT_INTERNALS_TYPES_SW_MINOR_VERSION) ||   \
    (SPT_INTERNALS_SW_PATCH_VERSION    != SPT_INTERNALS_TYPES_SW_PATCH_VERSION)      \
    )
    #error "Software Version Numbers of Spt_Internals.h and Spt_Internals_Types.h are different"
#endif

/* Check Spt_Cfg.h versions                                                                                */
#if (SPT_INTERNALS_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "Spt.h and Spt_Cfg.h have different vendor ids"
#endif

/* Check if Spt_Internals header file and Spt_Cfg configuration header file are of the same Autosar version         */
#if ((SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION   != SPT_CFG_AR_RELEASE_MAJOR_VERSION) ||   \
    (SPT_INTERNALS_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) ||   \
    (SPT_INTERNALS_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Spt_Internals.h and Spt_Cfg.h are different"
#endif

/* Check if Spt_Internals header file and Spt_Cfg configuration header file are of the same software version        */
#if ((SPT_INTERNALS_SW_MAJOR_VERSION   != SPT_CFG_SW_MAJOR_VERSION) ||     \
    (SPT_INTERNALS_SW_MINOR_VERSION    != SPT_CFG_SW_MINOR_VERSION) ||     \
    (SPT_INTERNALS_SW_PATCH_VERSION    != SPT_CFG_SW_PATCH_VERSION)        \
    )
    #error "Software Version Numbers of Spt_Internals.h and Spt_Cfg.h are different"
#endif



/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*
* @brief   Macro to read a register
* */
#define SPT_HW_READ_REG(reg) (reg)

/*
* @brief   Macro to read a field of a register based on a mask and a shift value for the mask
* */
#define SPT_HW_READ_BITS(reg, mask, shift) (((reg) & ((uint32)mask)) >> ((uint32)shift))

/*
* @brief   Macro to write a register
* */
#define SPT_HW_WRITE_REG(reg, value) ((reg) = ((uint32)value))

/*
* @brief   Macro to write a field of a register using a mask
*  */
#define SPT_HW_WRITE_BITS(reg, mask, value) ((reg) = (((reg) & (~((uint32)mask))) | ((uint32)value)))


#define SPT_PRINT(...)




#ifndef TRACE_ENABLE
#define RsdkTraceLogEvent(event, extra1, extra2)
#endif

#if !defined(SPT_REPORT_ERROR)
#define SPT_REPORT_ERROR(a, b, c)   RSDK_REPORT_ERROR((rsdkStatus_t)a, (uint16)CDD_SPT_MODULE_ID,   \
                                    (uint8)SPT_INSTANCE_ID, (uint8)b, (uint8)c);                    \
                                    SPT_HALT_ON_ERROR;
#endif

#if !defined(UNUSED_ARG) && defined(RSDK_AUTOSAR)
#define UNUSED_ARG(ARG) (void)(ARG)
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern Spt_DrvMemPerType gSptMemPer;

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define SPT_START_SEC_CODE
#include "Spt_MemMap.h"


 static inline void Spt_SetDrvState(Spt_DrvStateType newState)
{
    gSptMemPer.state = newState;
}

volatile SPT_Type *Spt_GetMemMap(void);
Std_ReturnType     Spt_UnmapMem(void);

void               Spt_InitPersistentMem(Spt_DrvMemPerType *pSptMemPer, Spt_DriverInitType const *const pSptInitInfo);

Std_ReturnType     Spt_SetInputParams(Spt_DrvParamType const paramList[]);
Std_ReturnType     Spt_ParamCheckRun(Spt_DriverContextType const *const sptContext, const Spt_DrvStateType state);
Std_ReturnType     Spt_ParamCheckInit(Spt_DriverInitType const *const pSptInitInfo);
void               Spt_GetKernelRetVal(volatile sint32 *kernelRetPar);

#if(SPT_DSP_ENABLE == STD_ON)
uint8              Spt_GenCrc8(const uint8* inData, uint8 numBytes);
#endif


#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SPT_INTERNALS_H */
