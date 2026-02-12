
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








/**
*   @file
*   @implements Cte.c_Artifact
*
*   @addtogroup CTE
*   @{
*
*   clang-format off
*
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Cte_c_REF_1
* Violates MISRA 2012 Advisory Directive 4.9,
*   #A function should be used in preference to a function-like macro where they are interchangeable
* Using a macro produce a smaller code; there is a clear distinction between functions and macros,
* which use only UPPERCASE
*
* @section Cte_c_REF_2
* Violates MISRA 2012 Required Directive 4.10,
*   #Precautions shall be taken in order to prevent the contents of a header file being included more than once.
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Cte_c_REF_3
* Violates MISRA C-2012 Advisory Rule 8.9,
*   #An object should be defined at block scope if its identifier only appears in a single function.
* To not mix code and data storage, for proper memory mapping,
* some of the static variables are not defined at block scope.
*
* @section Cte_c_REF_4
* Violates MISRA C-2012 Advisory Rule 11.4,
*   #A conversion should not be performed between a pointer to object and an integer type
* Some initialization need to be done for pointers.
*
* @section Cte_c_REF_5
* Violates MISRA C-2012 Required Rule 11.6,
*   #A cast shall not be performed between pointer to void and an arithmetic type
* In some contexts, is necessary to process pointers using arithmetic operations.
*
* @section Cte_c_REF_6
* Violates MISRA C-2012 Required Rule 18.1,
*   #A pointer resulting from arithmetic on a pointer operand shall address an element of the same array
*   as that pointer operand
* Some initialization need to be done for pointers.
*
* @section Cte_c_REF_7
* Violates MISRA C-2012 Required Rule 18.4,
*   #The +, -, += and -= operators should not be applied to an  expression of pointer type
* Necessary pointer operation, not possible to use normal pointer association.
*
* @section Cte_c_REF_8
* Violates MISRA 2012 Advisory Rule 20.1,
*   #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Cte_Irq.h"
#include "Cte_Specific.h"

    #include "Det.h"
    #include "CDD_Cte_Cbk.h"
	#include "rsdk_version.h"










    #include "S32R41_CTE.h"







/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

    #define CTE_IRQ_C_VENDOR_ID                     43
    #define CTE_IRQ_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
    #define CTE_IRQ_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
    #define CTE_IRQ_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
    #define CTE_IRQ_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
    #define CTE_IRQ_C_SW_MINOR_VERSION              RSDK_SW_MINOR
    #define CTE_IRQ_C_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

    /* Check if Cte_Irq source file and Cte_Irq header file are of the same vendor */
    #if (CTE_IRQ_C_VENDOR_ID != CTE_IRQ_VENDOR_ID)
        #error "Cte_Irq.c and Cte_Irq.h have different vendor ids"
    #endif

    /* Check if Cte_Irq source file and Cte_Irq header file are of the same Autosar version */
    #if ((CTE_IRQ_C_AR_RELEASE_MAJOR_VERSION    != CTE_IRQ_AR_RELEASE_MAJOR_VERSION) || \
         (CTE_IRQ_C_AR_RELEASE_MINOR_VERSION    != CTE_IRQ_AR_RELEASE_MINOR_VERSION) || \
         (CTE_IRQ_C_AR_RELEASE_REVISION_VERSION != CTE_IRQ_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Cte_Irq.c and Cte_Irq.h are different"
    #endif

    /* Check if Cte_Irq source file and Cte_Irq header file are of the same Software version */
    #if ((CTE_IRQ_C_SW_MAJOR_VERSION != CTE_IRQ_SW_MAJOR_VERSION) || \
         (CTE_IRQ_C_SW_MINOR_VERSION != CTE_IRQ_SW_MINOR_VERSION) || \
         (CTE_IRQ_C_SW_PATCH_VERSION != CTE_IRQ_SW_PATCH_VERSION)    \
        )
        #error "Software Version Numbers of Cte_Irq.c and Cte_Irq.h are different"
    #endif

    /* Check if Cte_Irq source file and Cte_Specific header file are of the same vendor */
    #if (CTE_IRQ_C_VENDOR_ID != CTE_SPECIFIC_VENDOR_ID)
        #error "Cte_Irq.c and Cte_Specific.h have different vendor ids"
    #endif

    /* Check if Cte_Irq source file and Cte_Specific header file are of the same Autosar version */
    #if ((CTE_IRQ_C_AR_RELEASE_MAJOR_VERSION    != CTE_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
         (CTE_IRQ_C_AR_RELEASE_MINOR_VERSION    != CTE_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
         (CTE_IRQ_C_AR_RELEASE_REVISION_VERSION != CTE_SPECIFIC_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Cte_Irq.c and Cte_Specific.h are different"
    #endif

    /* Check if Cte_Irq source file and Cte_Specific header file are of the same Software version */
    #if ((CTE_IRQ_C_SW_MAJOR_VERSION != CTE_SPECIFIC_SW_MAJOR_VERSION) || \
         (CTE_IRQ_C_SW_MINOR_VERSION != CTE_SPECIFIC_SW_MINOR_VERSION) || \
         (CTE_IRQ_C_SW_PATCH_VERSION != CTE_SPECIFIC_SW_PATCH_VERSION)    \
        )
        #error "Software Version Numbers of Cte_Irq.c and Cte_Specific.h are different"
    #endif

    /* Check if Cte_Irq source file and CDD_Cte_Cbk header file are of the same vendor */
    #if (CTE_IRQ_C_VENDOR_ID != CTE_CBK_VENDOR_ID)
        #error "Cte_Irq.c and CDD_Cte_Cbk.h have different vendor ids"
    #endif

    /* Check if Cte_Irq source file and CDD_Cte_Cbk header file are of the same Autosar version */
    #if ((CTE_IRQ_C_AR_RELEASE_MAJOR_VERSION    != CTE_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (CTE_IRQ_C_AR_RELEASE_MINOR_VERSION    != CTE_CBK_AR_RELEASE_MINOR_VERSION) || \
         (CTE_IRQ_C_AR_RELEASE_REVISION_VERSION != CTE_CBK_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Cte_Irq.c and CDD_Cte_Cbk.h are different"
    #endif

    /* Check if Cte_Irq source file and CDD_Cte_Cbk header file are of the same Software version */
    #if ((CTE_IRQ_C_SW_MAJOR_VERSION != CTE_CBK_SW_MAJOR_VERSION) || \
         (CTE_IRQ_C_SW_MINOR_VERSION != CTE_CBK_SW_MINOR_VERSION) || \
         (CTE_IRQ_C_SW_PATCH_VERSION != CTE_CBK_SW_PATCH_VERSION)    \
        )
        #error "Software Version Numbers of Cte_Irq.c and CDD_Cte_Cbk.h are different"
    #endif



/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/* error report management      */
#if !defined(CTE_REPORT_ERROR)
#endif

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 ==================================================================================================*/


/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 ==================================================================================================*/
/**
 * @brief   Interrupt handler for CTE.
 * @details Low level interrupt handler for CTE driver.
 *
 */



void Cte_IrqHandler(void)
{
    uint32 cteEvents;

    cteEvents = gspCTEPtr->INTSTAT;
    gspCTEPtr->INTSTAT = cteEvents;          /* clear all bits       */
    cteEvents &= gsDriverData.cteReqEvents;

    Cte_IsrCallback(cteEvents);



}
/*=== Cte_IrqHandler ===========================*/


/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 ==================================================================================================*/
/*==================================================================================================*/
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
Std_ReturnType Cte_IrqInit(const Cte_SetupParamsType *cteInitParamsPtr)
{
    Std_ReturnType rez = (Std_ReturnType)E_OK;

    gspCTEPtr->INTEN = 0u;             /* mask all irq sources         */







    if(((uint32)cteInitParamsPtr->cteIrqEvents != 0u)



        )
    {                       /* events callback requested        */
        gspCTEPtr->INTEN = (uint32)cteInitParamsPtr->cteIrqEvents;
    }
    return rez;
}
/*=== Cte_IrqInit ===========================*/


