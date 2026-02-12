
/*==================================================================================================
 * Copyright 2022-2023 NXP Semiconductors
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
==================================================================================================*/








#ifndef CTE_IRQ_H
#define CTE_IRQ_H

/**
*   @file
*   @implements Cte_Irq.h_Artifact
*
*   @addtogroup CTE_ASR
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Cte_Irq_h_REF_1
* Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Cte_Cfg.h"
#include "Cte_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

    #define CTE_IRQ_VENDOR_ID                          43
    #define CTE_IRQ_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
    #define CTE_IRQ_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
    #define CTE_IRQ_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
    #define CTE_IRQ_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
    #define CTE_IRQ_SW_MINOR_VERSION                   RSDK_SW_MINOR
    #define CTE_IRQ_SW_PATCH_VERSION                   RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

    /* Check Cte_Types.h versions                                                                                */
    #if (CTE_IRQ_VENDOR_ID != CTE_TYPES_VENDOR_ID)
        #error "Cte_Irq.h and Cte_Types.h have different vendor ids"
    #endif

    /* Check if Cte_Ip header file and Cte_Types configuration header file are of the same Autosar version       */
    #if ((CTE_IRQ_AR_RELEASE_MAJOR_VERSION    != CTE_TYPES_AR_RELEASE_MAJOR_VERSION) ||   \
         (CTE_IRQ_AR_RELEASE_MINOR_VERSION    != CTE_TYPES_AR_RELEASE_MINOR_VERSION) ||   \
         (CTE_IRQ_AR_RELEASE_REVISION_VERSION != CTE_TYPES_AR_RELEASE_REVISION_VERSION)   \
        )
        #error "AutoSar Version Numbers of Cte_Irq.h and Cte_Types.h are different"
    #endif

    /* Check if Cte_Ip header file and Cte_Types configuration header file are of the same software version      */
    #if ((CTE_IRQ_SW_MAJOR_VERSION    != CTE_TYPES_SW_MAJOR_VERSION) ||     \
         (CTE_IRQ_SW_MINOR_VERSION    != CTE_TYPES_SW_MINOR_VERSION) ||     \
         (CTE_IRQ_SW_PATCH_VERSION    != CTE_TYPES_SW_PATCH_VERSION)        \
        )
        #error "Software Version Numbers of Cte_Irq.h and Cte_Types.h are different"
    #endif

    /* Check Cte_Cfg.h versions                                                                                      */
    #if (CTE_IRQ_VENDOR_ID != CTE_CFG_VENDOR_ID)
        #error "Cte_Irq.h and Cte_Cfg.h have different vendor ids"
    #endif

    /* Check if Cte_Ip header file and Cte_Cfg configuration header file are of the same Autosar version            */
    #if ((CTE_IRQ_AR_RELEASE_MAJOR_VERSION    != CTE_CFG_AR_RELEASE_MAJOR_VERSION) ||   \
         (CTE_IRQ_AR_RELEASE_MINOR_VERSION    != CTE_CFG_AR_RELEASE_MINOR_VERSION) ||   \
         (CTE_IRQ_AR_RELEASE_REVISION_VERSION != CTE_CFG_AR_RELEASE_REVISION_VERSION)   \
        )
        #error "AutoSar Version Numbers of Cte_Irq.h and Cte_Cfg.h are different"
    #endif

    /* Check if Cte_Ip header file and Cte_Cfg configuration header file are of the same software version           */
    #if ((CTE_IRQ_SW_MAJOR_VERSION    != CTE_CFG_SW_MAJOR_VERSION) ||      \
         (CTE_IRQ_SW_MINOR_VERSION    != CTE_CFG_SW_MINOR_VERSION) ||      \
         (CTE_IRQ_SW_PATCH_VERSION    != CTE_CFG_SW_PATCH_VERSION)         \
        )
        #error "Software Version Numbers of Cte_Irq.h and Cte_Cfg.h are different"
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

    void Cte_IrqHandler(void);







/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

    #define CTE_START_SEC_CODE
    #include "Cte_MemMap.h"


/**
 * @brief   Procedure to define the necessary clock periods.
 * @details The hardware can use up to 4 clock dividers, so up to 4 periods available.
 *          If more clocks required, intermediate periods will be used, to reduce the deviation below 40%.
 *          If it is not possible to have up to 4 clocks and all the required periods to enter 40% deviation,
 *          an error will be returned.
 *
 * @param[in]   pointers to the initialization params
 * @return      E_OK/RSDK_SUCCESS = success; other = error
 *
 */
Std_ReturnType Cte_IrqInit(const Cte_SetupParamsType *cteInitParamsPtr);



    #define CTE_STOP_SEC_CODE
    /*
    * @section Cte_Irq_h_REF_1
    * Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
    * <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
    */
    #include "Cte_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CTE_IRQ_H */
