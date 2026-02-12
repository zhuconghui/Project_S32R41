/*
 * Copyright 2018-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spt_Irq.h"
#include "Spt_Hw_Check.h"
#include "Spt_Hw_Defs.h"
#include "Spt_Internals.h"
#include "Spt_Cfg.h"
#include "rsdk_version.h"





/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_IRQ_C_VENDOR_ID                     43
#define SPT_IRQ_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define SPT_IRQ_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define SPT_IRQ_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define SPT_IRQ_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define SPT_IRQ_C_SW_MINOR_VERSION              RSDK_SW_MINOR
#define SPT_IRQ_C_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if Spt_Irq source file and Spt_Irq header file are of the same vendor */
#if (SPT_IRQ_C_VENDOR_ID != SPT_IRQ_VENDOR_ID)
    #error "Spt_Irq.c and Spt_Irq.h have different vendor ids"
#endif

/* Check if Spt_Irq source file and Spt_Irq header file are of the same Autosar version */
#if ((SPT_IRQ_C_AR_RELEASE_MAJOR_VERSION    != SPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_MINOR_VERSION    != SPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_REVISION_VERSION != SPT_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq.c and Spt_Irq.h are different"
#endif

/* Check if Spt_Irq source file and Spt_Irq header file are of the same Software version */
#if ((SPT_IRQ_C_SW_MAJOR_VERSION != SPT_IRQ_SW_MAJOR_VERSION) || \
     (SPT_IRQ_C_SW_MINOR_VERSION != SPT_IRQ_SW_MINOR_VERSION) || \
     (SPT_IRQ_C_SW_PATCH_VERSION != SPT_IRQ_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq.c and Spt_Irq.h are different"
#endif

/* Check if Spt_Irq source file and Spt_Irq header file are of the same vendor */
#if (SPT_IRQ_C_VENDOR_ID != SPT_HW_CHECK_VENDOR_ID)
    #error "Spt_Irq.c and Spt_Irq.h have different vendor ids"
#endif

/* Check if Spt_Irq source file and Spt_Irq header file are of the same Autosar version */
#if ((SPT_IRQ_C_AR_RELEASE_MAJOR_VERSION    != SPT_HW_CHECK_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_MINOR_VERSION    != SPT_HW_CHECK_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_REVISION_VERSION != SPT_HW_CHECK_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq.c and Spt_Irq.h are different"
#endif

/* Check if Spt_Irq source file and Spt_Irq header file are of the same Software version */
#if ((SPT_IRQ_C_SW_MAJOR_VERSION != SPT_HW_CHECK_SW_MAJOR_VERSION) || \
     (SPT_IRQ_C_SW_MINOR_VERSION != SPT_HW_CHECK_SW_MINOR_VERSION) || \
     (SPT_IRQ_C_SW_PATCH_VERSION != SPT_HW_CHECK_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq.c and Spt_Irq.h are different"
#endif

/* Check if Spt_Irq source file and Spt_Hw_Defs header file are of the same vendor */
#if (SPT_IRQ_C_VENDOR_ID != SPT_HW_DEFS_VENDOR_ID)
    #error "Spt_Irq.c and Spt_Hw_Defs.h have different vendor ids"
#endif

/* Check if Spt_Irq source file and Spt_Hw_Defs header file are of the same Autosar version */
#if ((SPT_IRQ_C_AR_RELEASE_MAJOR_VERSION    != SPT_HW_DEFS_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_MINOR_VERSION    != SPT_HW_DEFS_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_REVISION_VERSION != SPT_HW_DEFS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq.c and Spt_Hw_Defs.h are different"
#endif

/* Check if Spt_Irq source file and Spt_Hw_Defs header file are of the same Software version */
#if ((SPT_IRQ_C_SW_MAJOR_VERSION != SPT_HW_DEFS_SW_MAJOR_VERSION) || \
     (SPT_IRQ_C_SW_MINOR_VERSION != SPT_HW_DEFS_SW_MINOR_VERSION) || \
     (SPT_IRQ_C_SW_PATCH_VERSION != SPT_HW_DEFS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq.c and Spt_Hw_Defs.h are different"
#endif

/* Check if Spt_Irq source file and Spt_Internals header file are of the same vendor */
#if (SPT_IRQ_C_VENDOR_ID != SPT_INTERNALS_VENDOR_ID)
    #error "Spt_Irq.c and Spt_Internals.h have different vendor ids"
#endif

/* Check if Spt_Irq source file and Spt_Internals header file are of the same Autosar version */
#if ((SPT_IRQ_C_AR_RELEASE_MAJOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_MINOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_REVISION_VERSION != SPT_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Irq source file and Spt_Internals header file are of the same Software version */
#if ((SPT_IRQ_C_SW_MAJOR_VERSION != SPT_INTERNALS_SW_MAJOR_VERSION) || \
     (SPT_IRQ_C_SW_MINOR_VERSION != SPT_INTERNALS_SW_MINOR_VERSION) || \
     (SPT_IRQ_C_SW_PATCH_VERSION != SPT_INTERNALS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Irq source file and Spt_Cfg header file are of the same vendor */
#if (SPT_IRQ_C_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "Spt_Irq.c and Spt_Cfg.h have different vendor ids"
#endif

/* Check if Spt_Irq source file and Spt_Cfg header file are of the same Autosar version */
#if ((SPT_IRQ_C_AR_RELEASE_MAJOR_VERSION    != SPT_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_C_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq.c and Spt_Cfg.h are different"
#endif

/* Check if Spt_Irq source file and Spt_Cfg header file are of the same Software version */
#if ((SPT_IRQ_C_SW_MAJOR_VERSION != SPT_CFG_SW_MAJOR_VERSION) || \
     (SPT_IRQ_C_SW_MINOR_VERSION != SPT_CFG_SW_MINOR_VERSION) || \
     (SPT_IRQ_C_SW_PATCH_VERSION != SPT_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq.c and Spt_Cfg.h are different"
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

#define SPT_START_SEC_CODE
#include "Spt_MemMap.h"


/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief      Interrupt service routine for handling events coming on the SPT_IRQ_ECS interrupt line.
* @details    Handles interrupts related to the command sequencer status (e.g. on STOP instruction,
*             needed for non-blocking operating mode) as well as error and overflow interrupts.
*             It also calls the user-defined rsdkSptIsrCb_t callback (if configured in the rsdkSptDriverContext_t::ecsIsrCb )
*
* @param[in] none
* @param[out] none
*
* @return none
* @isr
*
*/
void Spt_EcsIsr(SPT_IRQ_ARG)
{
    volatile SPT_Type *const        pSptRegs = Spt_GetMemMap();
    rsdkStatus_t                    isrStatus = RSDK_SUCCESS;

    /* First things first: look for errors */
    isrStatus = (rsdkStatus_t)Spt_CheckAndResetHwError(pSptRegs, &gSptMemPer.errInfo);

    if (isrStatus != (rsdkStatus_t)RSDK_SUCCESS)
    {

        isrStatus = (rsdkStatus_t)((uint32)isrStatus + RSDK_SPT_STATUS_BASE);

        Spt_SetDrvState(SPT_STATE_FAULT);
    }

    /* If the SPT_CS_STATUS0[PS_STOP] bit is set, then it means the SPT has finished running the command sequence
     * attn: polling mode does not raise interrupt for PS_STOP bit */
    else if (SPT_HW_READ_BITS(pSptRegs->CS_STATUS0, SPT_CS_STATUS0_PS_STOP_MASK, SPT_CS_STATUS0_PS_STOP_SHIFT) != (uint32)0)
    {
        /* Clear the interrupt source */
        SPT_HW_WRITE_BITS(pSptRegs->CS_STATUS0, SPT_CS_STATUS0_PS_STOP_MASK, SPT_CS_STATUS0_PS_STOP(1u));

        if (Spt_CheckUnexpectedStop(pSptRegs, gSptMemPer.state) != (Std_ReturnType)E_OK)
        {
            isrStatus = RSDK_SPT_RET_WARN_UNEXPECTED_STOP;
        }
        else
        {
            RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, (uint16_t)RSDK_TRACE_DBG_SPT_KERNEL_END, 1);

            isrStatus = RSDK_SUCCESS;

            /* On S32R45/S32R41/SAF85XX the WRs can be read after SPT STOP */
            Spt_GetKernelRetVal(gSptMemPer.kernelRetPar);
        }
        Spt_SetDrvState(SPT_STATE_INITIALIZED);
    }
    else
    {
        /* Something must have gone wrong - reached this place not knowing root cause of this ISR */
        Spt_SetDrvState(SPT_STATE_FAULT);
        isrStatus = RSDK_SPT_RET_ERR_OTHER;
    }

    if (gSptMemPer.state == SPT_STATE_FAULT)
    {
        RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, (uint16_t)RSDK_TRACE_DBG_SPT_KERNEL_ERROR, gSptMemPer.errInfo);
    }


    Spt_EcsIsrCb(isrStatus, gSptMemPer.errInfo);







}

void Spt_EvtIsr(SPT_IRQ_ARG)
{
    volatile SPT_Type *const        pSptRegs = Spt_GetMemMap();
    uint32                          evtInfo = (uint32)SPT_HW_READ_REG(pSptRegs->CS_EVTREG1);

    /* Write 1 to clear the interrupt source (clear all event bits) */
    SPT_HW_WRITE_REG(pSptRegs->CS_EVTREG1, SPT_CS_EVTREG1_MASK);


    Spt_EvtIsrCb(RSDK_SUCCESS, evtInfo);







}

#if(SPT_DSP_ENABLE == STD_ON)
void Spt_DspIsr(SPT_IRQ_ARG)
{
    volatile SPT_Type *const        pSptRegs = Spt_GetMemMap();

    uint32                      dspErrCode = (uint32)SPT_HW_READ_REG(pSptRegs->DSP_ERR_INFO_REG);
    uint32                      dspErrInfo = (uint32)SPT_HW_READ_REG(pSptRegs->DSP_DEBUG1_REG);

    uint32 i;

    /* Write 1 to clear the interrupt source: */
    SPT_HW_WRITE_REG(pSptRegs->DSP_ERR_INFO_REG, SPT_DSP_ERR_INFO_REG_MASK);

    /* Translate errors to rsdk_status.h*/
    for (i = 0; i < 32U; i++)
    {
        if (((dspErrCode >> i) & 0x1U) != 1U)
        {
            continue;
        }


        Spt_DspIsrCb((rsdkStatus_t)(RSDK_DSP_STATUS_BASE + i), dspErrInfo);







    }


}
#endif /* #if(SPT_DSP_ENABLE == STD_ON) */


#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
