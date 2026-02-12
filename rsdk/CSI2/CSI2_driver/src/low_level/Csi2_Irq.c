
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









/**
*   @file
*   @implements Csi2_Irq.c_Artifact
*
*   @addtogroup CSI2
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Csi2_Irq_c_REF_1
* Violates MISRA 2012 Advisory Directive 4.9,
* #A function should be used in preference to a function-like macro where they are interchangeable
* Using a macro produce a smaller code; there is a clear distinction between functions and macros,
* which use only UPPERCASE
*
* @section Csi2_Irq_c_REF_2
* Violates MISRA C-2012 Advisory Rule 8.9,
* #An object should be defined at block scope if its identifier only appears in a single function.
* To not mix code and data storage, for proper memory mapping,
* some of the static variables are not defined at block scope.
*
* @section Csi2_Irq_c_REF_3
* Violates MISRA C-2012 Advisory Rule 11.3,
* #A cast shall not be performed between a pointer to object type and a pointer to a different object type
* This is the only possibility to get the correct pointer to the data to be processed.
*
* @section Csi2_Irq_c_REF_4
* Violates MISRA C-2012 Required Rule 18.4,
* #The +, -, += and -= operators should not be applied to an  expression of pointer type
* Necessary pointer operation, not possible to use normal pointer association.
*
* @section Csi2_Irq_c_REF_5
* Violates MISRA 2012 Advisory Rule 20.1,
* #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Csi2_Cfg.h"
#include "Csi2_Types.h"
#include "CDD_Csi2.h"
#include "Csi2_Irq.h"

    #include "SchM_Csi2.h"
	#include "rsdk_version.h"






    #include "string.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

    #define CSI2_IRQ_C_VENDOR_ID                     43
    #define CSI2_IRQ_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
    #define CSI2_IRQ_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
    #define CSI2_IRQ_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
    #define CSI2_IRQ_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
    #define CSI2_IRQ_C_SW_MINOR_VERSION              RSDK_SW_MINOR
    #define CSI2_IRQ_C_SW_PATCH_VERSION  			 RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

    /* Check if Csi2_Irq source file and Csi2 header file are of the same vendor */
    #if (CSI2_IRQ_C_VENDOR_ID != CSI2_VENDOR_ID)
        #error "Csi2.c and Csi2.h have different vendor ids"
    #endif

    /* Check if Csi2_Irq source file and Csi2 header file are of the same Autosar version */
    #if ((CSI2_IRQ_C_AR_RELEASE_MAJOR_VERSION    != CSI2_AR_RELEASE_MAJOR_VERSION) || \
         (CSI2_IRQ_C_AR_RELEASE_MINOR_VERSION    != CSI2_AR_RELEASE_MINOR_VERSION) || \
         (CSI2_IRQ_C_AR_RELEASE_REVISION_VERSION != CSI2_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Csi2_Irq.c and Csi2.h are different"
    #endif

    /* Check if Csi2_Irq source file and Csi2 header file are of the same Software version */
    #if ((CSI2_IRQ_C_SW_MAJOR_VERSION != CSI2_SW_MAJOR_VERSION) || \
         (CSI2_IRQ_C_SW_MINOR_VERSION != CSI2_SW_MINOR_VERSION) || \
         (CSI2_IRQ_C_SW_PATCH_VERSION != CSI2_SW_PATCH_VERSION)    \
        )
        #error "Software Version Numbers of Csi2_Irq.c and Csi2.h are different"
    #endif


    /* Check if Csi2_Irq source file and Csi2_Irq header file are of the same vendor */
    #if (CSI2_IRQ_C_VENDOR_ID != CSI2_IRQ_VENDOR_ID)
        #error "Csi2_Irq.c and Csi2_Irq.h have different vendor ids"
    #endif

    /* Check if Csi2_Irq source file and Csi2_Irq header file are of the same Autosar version */
    #if ((CSI2_IRQ_C_AR_RELEASE_MAJOR_VERSION    != CSI2_IRQ_AR_RELEASE_MAJOR_VERSION) || \
         (CSI2_IRQ_C_AR_RELEASE_MINOR_VERSION    != CSI2_IRQ_AR_RELEASE_MINOR_VERSION) || \
         (CSI2_IRQ_C_AR_RELEASE_REVISION_VERSION != CSI2_IRQ_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Csi2_Irq.c and Csi2_Irq.h are different"
    #endif

    /* Check if Csi2_Irq source file and Csi2_Irq header file are of the same Software version */
    #if ((CSI2_IRQ_C_SW_MAJOR_VERSION != CSI2_IRQ_SW_MAJOR_VERSION) || \
         (CSI2_IRQ_C_SW_MINOR_VERSION != CSI2_IRQ_SW_MINOR_VERSION) || \
         (CSI2_IRQ_C_SW_PATCH_VERSION != CSI2_IRQ_SW_PATCH_VERSION)    \
        )
        #error "Software Version Numbers of Csi2_Irq.c and Csi2_Irq.h are different"
    #endif


    /* Check if Csi2_Irq source file and Csi2_Cfg header file are of the same vendor */
    #if (CSI2_IRQ_C_VENDOR_ID != CSI2_CFG_VENDOR_ID)
        #error "Csi2_Irq.c and Csi2_Irq.h have different vendor ids"
    #endif

    /* Check if Csi2_Irq source file and Csi2_Cfg header file are of the same Autosar version */
    #if ((CSI2_IRQ_C_AR_RELEASE_MAJOR_VERSION    != CSI2_CFG_AR_RELEASE_MAJOR_VERSION) || \
         (CSI2_IRQ_C_AR_RELEASE_MINOR_VERSION    != CSI2_CFG_AR_RELEASE_MINOR_VERSION) || \
         (CSI2_IRQ_C_AR_RELEASE_REVISION_VERSION != CSI2_CFG_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Csi2_Irq.c and Csi2_Cfg.h are different"
    #endif

    /* Check if Csi2_Irq source file and Csi2_Cfg header file are of the same Software version */
    #if ((CSI2_IRQ_C_SW_MAJOR_VERSION != CSI2_CFG_SW_MAJOR_VERSION) || \
         (CSI2_IRQ_C_SW_MINOR_VERSION != CSI2_CFG_SW_MINOR_VERSION) || \
         (CSI2_IRQ_C_SW_PATCH_VERSION != CSI2_CFG_SW_PATCH_VERSION)    \
        )
        #error "Software Version Numbers of Csi2_Irq.c and Csi2_Cfg.h are different"
    #endif


    #if !defined(DISABLE_MCAL_INTERMODULE_ASR_CHECK)
        /* Check if Csi2_Irq source file and SchM_Csi2 header file are of the same Autosar version */
        #if ((CSI2_IRQ_C_AR_RELEASE_MAJOR_VERSION    != SCHM_CSI2_AR_RELEASE_MAJOR_VERSION) ||  \
             (CSI2_IRQ_C_AR_RELEASE_MINOR_VERSION    != SCHM_CSI2_AR_RELEASE_MINOR_VERSION)     \
            )
            #error "AutoSar Version Numbers of Csi2_Irq.c and SchM_Csi2.h are different"
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
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

    #define CSI2_START_SEC_CODE
    /*
    * @section Csi2_Irq_c_REF_5
    * Violates MISRA 2012 Advisory Rule 20.1,
    * #Include directives should only be preceded by preprocessor directives or comments.
    * <MA>_MemMap.h is included after each section define to set the current memory section as defined by AUTOSAR.
    */
    #include "Csi2_MemMap.h"



    // Individual irq unit handlers for Rx errors if defined only local






























/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

































/*==================================================================================================
*                                        GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
/* The necessary ISR callbacks                                                                      */


/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/*
 * @brief       Enable for Rx errors interrupt on the specified VC.
 *
 * @param[in]   vcId    - VC ID, CSI2_VC_0 ... CSI2_MAX_VC
 * @param[in]   regsPtr - pointer to unit registry
 * @param[in]   val     - value to be set, usually 0 or 0xffffffff
 *
 */
static void Csi2_SetVCRxIrq(const uint32 vcId, volatile GENERIC_CSI2_Type *regsPtr, uint32 val)
{
    regsPtr->RX_VC[vcId].PPERRIE = val;
}
/* Csi2_SetVCRxIrq *************************/


/*================================================================================================*/
/*
 * @brief       Init for Rx errors interrupt.
 * @details     This procedure is called after the general unit setup was done.
 *
 * @param[in]   regsPtr - pointer to unit registry
 * @param[in]   paramsPtr - pointer to CSI2 unit setup parameters
 *
 */
static void Csi2_InitRxIrq(volatile GENERIC_CSI2_Type *regsPtr, const Csi2_SetupParamsType *paramsPtr)
{

    uint32                  vcId;                       /* VC ID, from CSI2_VC_0 to MAX                           */

    /* real irq enablement                                                                                        */

    regsPtr->RX_PHYERRIE = 0xffffffffu;                   /* enable all error flags                               */

    for (vcId = (uint32)CSI2_VC_0; vcId < (uint32)CSI2_MAX_VC; vcId++)  /* check all VC                           */
    {
        if (paramsPtr->vcConfigPtr[vcId] != (Csi2_VCParamsType*)NULL_PTR)   /* only for active VC                 */
        {
            Csi2_SetVCRxIrq(vcId, regsPtr, 0xffffffffu);  /* enable the interrupts                                */
        }
        else
        {
            Csi2_SetVCRxIrq(vcId, regsPtr, 0u);           /* disable the interrupts                               */
        }
    }
}
/* Csi2_InitRxIrq *************************/


/*================================================================================================*/
/*
 * @brief       Setup for Path errors interrupt.
 * @details     This procedure is called after the general unit setup was done.
 *
 * @param[in]   regsPtr     - pointer to unit registry
 *
 */
static void Csi2_InitPathIrq(volatile GENERIC_CSI2_Type *regsPtr)
{
    /* real irq enablement                                                                                      */
    regsPtr->CONTROLLER_ERR_IE = 0xffffffffu;
    /* enable all the possible errors on channel data                                                           */
    /*
    * @section Csi2_Irq_c_REF_1
    * Violates MISRA 2012 Advisory Directive 4.9,
    * #A function should be used in preference to a function-like macro where they are interchangeable
    * Using a macro produce a smaller code; there is a clear distinction between functions and macros,
    * which use only UPPERCASE
    */



    CSI2_SET_REGISTRY32(&regsPtr->RX_CHNL_INTRE, MIPICSI2_RX_CHNL_INTRE_BUFFOVFIE_MASK,
                                                                            MIPICSI2_RX_CHNL_INTRE_BUFFOVFIE(1u));

    regsPtr->CBUF_INTRE = 0xffffffu;                                      /* enable all interrupts for line len & cnt */
}
/* Csi2_InitPathIrq *************************/


/*================================================================================================*/
/*
 * @brief       Enable for events interrupt on VC.
 * @details     This procedure is called after the general unit initialization was done.
 *
 * @param[in]   iUnit   - unit ID, RSDK_CSI2_UNIT_0 ... RSDK_CSI2_MAX_UNITS
 * @param[in]   regsPtr - pointer to unit registry
 * @param[in]   val     - single bit value, 0=disable, 1=enable
 *
 */
static void Csi2_SetVCEventIrq(const uint32 vcId, volatile GENERIC_CSI2_Type *regsPtr, uint8 evtMask,
                              uint8 numeLinesTrigger)
{
    uint8   valFS;
    uint8   valFE;

    valFS = ((evtMask & (uint8)CSI2_EVT_FRAME_START) != 0u) ? 1u : 0u;
    valFE = ((evtMask & (uint8)CSI2_EVT_FRAME_END) != 0u) ? 1u : 0u;
    /* set all ie bits                                                                                              */
    switch (vcId)                   /* set the necessary enable bit, to the appropriate registry                    */
    {
        default:                    /* RSDK_CSI2_VC_0                                                               */
            /*
            * @section Csi2_Irq_c_REF_1
            * Violates MISRA 2012 Advisory Directive 4.9,
            * #A function should be used in preference to a function-like macro where they are interchangeable
            * Using a macro produce a smaller code; there is a clear distinction between functions and macros,
            * which use only UPPERCASE
            */







            CSI2_SET_REGISTRY32(
                &regsPtr->RX_VCINTRE,
                MIPICSI2_RX_VCINTRE_GNSPIE0_MASK | MIPICSI2_RX_VCINTRE_FSIE0_MASK | MIPICSI2_RX_VCINTRE_FEIE0_MASK,
                MIPICSI2_RX_VCINTRE_GNSPIE0(valFE) | MIPICSI2_RX_VCINTRE_FSIE0(valFS) | MIPICSI2_RX_VCINTRE_FEIE0(valFE)
                );

            regsPtr->RX[0].CBUF_LPDI = (uint8)numeLinesTrigger;   /* trigger after each chirp (for stat. process)     */
            break;
        case (uint32)CSI2_VC_1:
            /*
            * @section Csi2_Irq_c_REF_1
            * Violates MISRA 2012 Advisory Directive 4.9,
            * #A function should be used in preference to a function-like macro where they are interchangeable
            * Using a macro produce a smaller code; there is a clear distinction between functions and macros,
            * which use only UPPERCASE
            */







            CSI2_SET_REGISTRY32(
                &regsPtr->RX_VCINTRE,
                MIPICSI2_RX_VCINTRE_GNSPIE1_MASK | MIPICSI2_RX_VCINTRE_FSIE1_MASK | MIPICSI2_RX_VCINTRE_FEIE1_MASK,
                MIPICSI2_RX_VCINTRE_GNSPIE1(valFE) | MIPICSI2_RX_VCINTRE_FSIE1(valFS) | MIPICSI2_RX_VCINTRE_FEIE1(valFE)
                );

            regsPtr->RX[1u].CBUF_LPDI = (uint8)numeLinesTrigger;
            break;
        case (uint32)CSI2_VC_2:
            /*
            * @section Csi2_Irq_c_REF_1
            * Violates MISRA 2012 Advisory Directive 4.9,
            * #A function should be used in preference to a function-like macro where they are interchangeable
            * Using a macro produce a smaller code; there is a clear distinction between functions and macros,
            * which use only UPPERCASE
            */







            CSI2_SET_REGISTRY32(
                &regsPtr->RX_VCINTRE,
                MIPICSI2_RX_VCINTRE_GNSPIE2_MASK | MIPICSI2_RX_VCINTRE_FSIE2_MASK | MIPICSI2_RX_VCINTRE_FEIE2_MASK,
                MIPICSI2_RX_VCINTRE_GNSPIE2(valFE) | MIPICSI2_RX_VCINTRE_FSIE2(valFS) | MIPICSI2_RX_VCINTRE_FEIE2(valFE)
                );

            regsPtr->RX[2].CBUF_LPDI = (uint8)numeLinesTrigger;
            break;
        case (uint32)CSI2_VC_3:
            /*
            * @section Csi2_Irq_c_REF_1
            * Violates MISRA 2012 Advisory Directive 4.9,
            * #A function should be used in preference to a function-like macro where they are interchangeable
            * Using a macro produce a smaller code; there is a clear distinction between functions and macros,
            * which use only UPPERCASE
            */







            CSI2_SET_REGISTRY32(
                &regsPtr->RX_VCINTRE,
                MIPICSI2_RX_VCINTRE_GNSPIE3_MASK | MIPICSI2_RX_VCINTRE_FSIE3_MASK | MIPICSI2_RX_VCINTRE_FEIE3_MASK,
                MIPICSI2_RX_VCINTRE_GNSPIE3(valFE) | MIPICSI2_RX_VCINTRE_FSIE3(valFS) | MIPICSI2_RX_VCINTRE_FEIE3(valFE)
                );

            regsPtr->RX[3].CBUF_LPDI = (uint8)numeLinesTrigger;
            break;
    }  /* switch    */
}
/* Csi2_SetVCEventIrq *************************/


/*================================================================================================*/
/*
 * @brief       Init for events interrupt.
 * @details     Init for events interrupt. All possibilities will be set.
 *
 * @param[in]   iUnit     - unit ID, RSDK_CSI2_UNIT_0 ... MAX
 * @param[in]   regsPtr   - pointer to unit registry
 * @param[in]   paramsPtr - pointer to CSI2 unit initialization parameters
 *
 */
static void Csi2_InitEventIrq(const Csi2_UnitIdType iUnit, volatile GENERIC_CSI2_Type *regsPtr,
                                     const Csi2_SetupParamsType *paramsPtr)
{
    uint32                      vcId;                       /* VC ID, from CSI2_VC_0 to MAX                         */
    uint8                       setLDevt;                   /* set LINEDONE event                                   */
    const Csi2_DriverParamsType *driverStatePtr;            /* pointer to unit driver state                         */





        driverStatePtr = &gCsi2Settings[(uint8)iUnit];


        /* irq enablement for skew calibration                                                                       */
        regsPtr->RX_VCINTRE = 0u;                       /* first disable the interrupts                              */
        setLDevt = 0u;                                  /* no LINEDONE request                                       */
        for (vcId = (uint32)CSI2_VC_0; vcId < (uint32)CSI2_MAX_VC; vcId++)  /* check all VC                          */
        {
            if (paramsPtr->vcConfigPtr[vcId] != (Csi2_VCParamsType*)NULL_PTR)   /* only for active VC                */
            {
                /* enable the interrupts for active VC, FE must be processed anyway                                  */
                Csi2_SetVCEventIrq(vcId, regsPtr,
                                (uint8)paramsPtr->vcConfigPtr[vcId]->vcEventsReq | (uint8)CSI2_EVT_FRAME_END,
                                paramsPtr->vcConfigPtr[vcId]->bufNumLinesTrigger);
            }
            else
            {
                Csi2_SetVCEventIrq(vcId, regsPtr, 0u, 0u);  /* disable the interrupts for inactive VC                */
            }
            setLDevt |= ((uint8)driverStatePtr->workingParamVC[vcId].eventsMask & (uint8)CSI2_EVT_LINE_END);
        }
        /* enable the "line done" interrupt, for internal purposes at least                                          */
        if (
#if (CSI2_AUTO_DC_COMPENSATION == STD_ON)
                (driverStatePtr->statisticsFlag == CSI2_AUTODC_EVERY_LINE) ||
#endif
                (setLDevt != 0u))
        {       /* process all chirps statistics            */
            /*
            * @section Csi2_Irq_c_REF_1
            * Violates MISRA 2012 Advisory Directive 4.9,
            * #A function should be used in preference to a function-like macro where they are interchangeable
            * Using a macro produce a smaller code; there is a clear distinction between functions and macros,
            * which use only UPPERCASE
            */




            CSI2_SET_REGISTRY32(&regsPtr->RX_CHNL_INTRE, MIPICSI2_RX_CHNL_INTRE_LINEDONEIE_MASK,
                                                        MIPICSI2_RX_CHNL_INTRE_LINEDONEIE(1u));

        }
        else
        {       /* do not process statistics at LINEDONE    */
            /*
            * @section Csi2_Irq_c_REF_1
            * Violates MISRA 2012 Advisory Directive 4.9,
            * #A function should be used in preference to a function-like macro where they are interchangeable
            * Using a macro produce a smaller code; there is a clear distinction between functions and macros,
            * which use only UPPERCASE
            */



            CSI2_SET_REGISTRY32(&regsPtr->RX_CHNL_INTRE, MIPICSI2_RX_CHNL_INTRE_LINEDONEIE_MASK, 0u);

        }
}
/* Csi2_InitEventIrq *************************/


/*==================================================================================================
*                                         GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/*
 * @brief       Interrupt handler for unit 0/ PHY error irq.
 *
 */



void Csi2_IrqHandlerRxErr0(void)
{
    Csi2_IrqHandlerRxErr(CSI2_UNIT_0);
}
/* Csi2_IrqHandlerRxErr0 *************************/


/*================================================================================================*/
/*
 * @brief       Interrupt handler for unit 1/ PHY error irq.
 *
 */



void Csi2_IrqHandlerRxErr1(void)
    {
        Csi2_IrqHandlerRxErr(CSI2_UNIT_1);
    }
/* Csi2_IrqHandlerRxErr1 *************************/
































/*================================================================================================*/
/*
 * @brief       Irq handler for unit 0/ errors in protocol & packet level irq.
 *
 */



 void Csi2_IrqHandlerPathErr0(void)
{
    Csi2_IrqHandlerPathErr(CSI2_UNIT_0);
}
/* Csi2_IrqHandlerPathErr0 *************************/


/*================================================================================================*/
/*
 * @brief       Irq handler for unit 1/ errors in protocol & packet level irq.
 *
 */



 void Csi2_IrqHandlerPathErr1(void)
    {
        Csi2_IrqHandlerPathErr(CSI2_UNIT_1);
    }
/* Csi2_IrqHandlerPathErr1 *************************/
































/*================================================================================================*/
/*
 * @brief       Irq handler for unit 0/ events irq.
 *
 */



 void Csi2_IrqHandlerEvents0(void)
{
    Csi2_IrqHandlerEvents(CSI2_UNIT_0);
}
/* Csi2_IrqHandlerEvents0 *************************/


/*================================================================================================*/
/*
 * @brief       Irq handler for unit 1/ events irq.
 *
 */



void Csi2_IrqHandlerEvents1(void)
{
    Csi2_IrqHandlerEvents(CSI2_UNIT_1);
}
/* Csi2_IrqHandlerEvents1 *************************/

































/*================================================================================================*/
/*
 * @brief       Initialize interrupts at Unit level
 *
 * @param[in]   iUnit     - unit ID, RSDK_CSI2_UNIT_0 ... MAX
 * @param[in]   regsPtr   - pointer to unit registry
 * @param[in]   paramsPtr - pointer to CSI2 unit initialization parameters
 *
 */

void



Csi2_SetupUIrq(const Csi2_UnitIdType iUnit, volatile GENERIC_CSI2_Type *regsPtr,
                          const Csi2_SetupParamsType *initParamsPtr)
{











































        Csi2_InitEventIrq(iUnit, regsPtr, initParamsPtr);
        Csi2_InitPathIrq(regsPtr);
#if (!defined(SAF85XX) && !defined(SAF86XX)) || (defined(SAF85XX) && (CSI2_SAF85XX_PHY_USED == STD_ON)) || \
                                                (defined(SAF86XX) && (CSI2_SAF86XX_PHY_USED == STD_ON))
        Csi2_InitRxIrq(regsPtr, initParamsPtr);
#endif







}
/* Csi2InitUIrq *************************/



    #define CSI2_STOP_SEC_CODE
    /*
    * @section Csi2_Irq_c_REF_5
    * Violates MISRA 2012 Advisory Rule 20.1,
    * #Include directives should only be preceded by preprocessor directives or comments.
    * <MA>_MemMap.h is included after each section define to set the current memory section as defined by RSDK_AUTOSAR.
    */
    #include "Csi2_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */




