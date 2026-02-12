/*
 * Copyright 2022-2023 NXP
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
#include "Spt_Hw_Ctrl.h"
#include "Spt_Hw_Check.h"
#include "Spt_Internals.h"
#include "Spt_Irq_Config.h"
#include "Spt_Cfg.h"




#include "CDD_Spt_Cbk.h"
#include "rsdk_version.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_HW_CTRL_C_VENDOR_ID                     43
#define SPT_HW_CTRL_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define SPT_HW_CTRL_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define SPT_HW_CTRL_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define SPT_HW_CTRL_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define SPT_HW_CTRL_C_SW_MINOR_VERSION              RSDK_SW_MINOR
#define SPT_HW_CTRL_C_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if Spt_Hw_Ctrl source file and Spt_Hw_Ctrl header file are of the same vendor */
#if (SPT_HW_CTRL_C_VENDOR_ID != SPT_HW_CTRL_VENDOR_ID)
    #error "Spt_Hw_Ctrl.c and Spt_Hw_Ctrl.h have different vendor ids"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Hw_Ctrl header file are of the same Autosar version */
#if ((SPT_HW_CTRL_C_AR_RELEASE_MAJOR_VERSION    != SPT_HW_CTRL_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_MINOR_VERSION    != SPT_HW_CTRL_AR_RELEASE_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_REVISION_VERSION != SPT_HW_CTRL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Hw_Ctrl.c and Spt_Hw_Ctrl.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Hw_Ctrl header file are of the same Software version */
#if ((SPT_HW_CTRL_C_SW_MAJOR_VERSION != SPT_HW_CTRL_SW_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_MINOR_VERSION != SPT_HW_CTRL_SW_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_PATCH_VERSION != SPT_HW_CTRL_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Hw_Ctrl.c and Spt_Hw_Ctrl.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Hw_Check header file are of the same vendor */
#if (SPT_HW_CTRL_C_VENDOR_ID != SPT_HW_CHECK_VENDOR_ID)
    #error "Spt_Hw_Ctrl.c and Spt_Hw_Check.h have different vendor ids"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Hw_Check header file are of the same Autosar version */
#if ((SPT_HW_CTRL_C_AR_RELEASE_MAJOR_VERSION    != SPT_HW_CHECK_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_MINOR_VERSION    != SPT_HW_CHECK_AR_RELEASE_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_REVISION_VERSION != SPT_HW_CHECK_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Hw_Ctrl.c and Spt_Hw_Check.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Hw_Check header file are of the same Software version */
#if ((SPT_HW_CTRL_C_SW_MAJOR_VERSION != SPT_HW_CHECK_SW_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_MINOR_VERSION != SPT_HW_CHECK_SW_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_PATCH_VERSION != SPT_HW_CHECK_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Hw_Ctrl.c and Spt_Hw_Check.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Internals header file are of the same vendor */
#if (SPT_HW_CTRL_C_VENDOR_ID != SPT_INTERNALS_VENDOR_ID)
    #error "Spt_Hw_Ctrl.c and Spt_Internals.h have different vendor ids"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Internals header file are of the same Autosar version */
#if ((SPT_HW_CTRL_C_AR_RELEASE_MAJOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_MINOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_REVISION_VERSION != SPT_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Hw_Ctrl.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Internals header file are of the same Software version */
#if ((SPT_HW_CTRL_C_SW_MAJOR_VERSION != SPT_INTERNALS_SW_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_MINOR_VERSION != SPT_INTERNALS_SW_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_PATCH_VERSION != SPT_INTERNALS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Hw_Ctrl.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Irq_Config header file are of the same vendor */
#if (SPT_HW_CTRL_C_VENDOR_ID != SPT_IRQ_CONFIG_VENDOR_ID)
    #error "Spt_Hw_Ctrl.c and Spt_Irq_Config.h have different vendor ids"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Irq_Config header file are of the same Autosar version */
#if ((SPT_HW_CTRL_C_AR_RELEASE_MAJOR_VERSION    != SPT_IRQ_CONFIG_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_MINOR_VERSION    != SPT_IRQ_CONFIG_AR_RELEASE_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_REVISION_VERSION != SPT_IRQ_CONFIG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Hw_Ctrl.c and Spt_Irq_Config.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Irq_Config header file are of the same Software version */
#if ((SPT_HW_CTRL_C_SW_MAJOR_VERSION != SPT_IRQ_CONFIG_SW_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_MINOR_VERSION != SPT_IRQ_CONFIG_SW_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_PATCH_VERSION != SPT_IRQ_CONFIG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Hw_Ctrl.c and Spt_Irq_Config.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Cfg header file are of the same vendor */
#if (SPT_HW_CTRL_C_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "Spt_Hw_Ctrl.c and Spt_Cfg.h have different vendor ids"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Cfg header file are of the same Autosar version */
#if ((SPT_HW_CTRL_C_AR_RELEASE_MAJOR_VERSION    != SPT_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Hw_Ctrl.c and Spt_Cfg.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and Spt_Cfg header file are of the same Software version */
#if ((SPT_HW_CTRL_C_SW_MAJOR_VERSION != SPT_CFG_SW_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_MINOR_VERSION != SPT_CFG_SW_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_PATCH_VERSION != SPT_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Hw_Ctrl.c and Spt_Cfg.h are different"
#endif


/* Check if Spt_Hw_Ctrl source file and CDD_Spt_Cbk header file are of the same vendor */
#if (SPT_HW_CTRL_C_VENDOR_ID != CDD_SPT_CBK_VENDOR_ID)
    #error "Spt_Hw_Ctrl.c and CDD_Spt_Cbk.h have different vendor ids"
#endif

/* Check if Spt_Hw_Ctrl source file and CDD_Spt_Cbk header file are of the same Autosar version */
#if ((SPT_HW_CTRL_C_AR_RELEASE_MAJOR_VERSION    != CDD_SPT_CBK_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_MINOR_VERSION    != CDD_SPT_CBK_AR_RELEASE_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_AR_RELEASE_REVISION_VERSION != CDD_SPT_CBK_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Hw_Ctrl.c and CDD_Spt_Cbk.h are different"
#endif

/* Check if Spt_Hw_Ctrl source file and CDD_Spt_Cbk header file are of the same Software version */
#if ((SPT_HW_CTRL_C_SW_MAJOR_VERSION != CDD_SPT_CBK_SW_MAJOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_MINOR_VERSION != CDD_SPT_CBK_SW_MINOR_VERSION) || \
     (SPT_HW_CTRL_C_SW_PATCH_VERSION != CDD_SPT_CBK_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Hw_Ctrl.c and CDD_Spt_Cbk.h are different"
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

#if(SPT_DSP_ENABLE == STD_ON)
static void Spt_DspBoot(volatile SPT_Type *pSptRegs, Spt_DriverInitType const *const pSptInitInfo)
{

    UNUSED_ARG(pSptInitInfo);

    uint32 isDspInReset = SPT_HW_READ_REG(pSptRegs->DSP_RST_REG) & 1U;

    /* DSP reset issue: it cannot be put back in reset state by the SPT Driver, so it must be booted
     * only once after board power-on. Otherwise reloading the image while BBE32 is running will trigger a
     * core exception and render it unusable. */
    if (isDspInReset == 0u)
    {
        SPT_PRINT("SPT Driver info: booting DSP. \n");

        /* Set the DSP boot mode: default or alternate location (IRAM / SRAM)
         * stall the DSP on reset
         * do not delay the DSP reset */
        SPT_HW_WRITE_REG(pSptRegs->DSP_CONFIG_REG, (uint32)(0x2U));
        /* Bring the DSP out of reset */
        SPT_HW_WRITE_REG(pSptRegs->DSP_RST_REG, 0x1U);

        /* Writing to BBE32 IRAM and DRAM is allowed only after the DSP is brought out of reset and put in stalled state.
         * For simplicity, we use the same procedure also for SRAM boot, even if the SRAM image can be loaded before
         * asserting the reset bit, and stalling the DSP is not necessary in this case call user-defined bootloader: */

        Spt_DspBootloaderCb();




        /* Un-stall the DSP */
        SPT_HW_WRITE_BITS(pSptRegs->DSP_CONFIG_REG, SPT_DSP_CONFIG_REG_DSP_RUN_STALL_MASK,
                            SPT_DSP_CONFIG_REG_DSP_RUN_STALL(0U));
    }
    else
    {
        SPT_PRINT("DSP already running. Not rebooting. \n");
    }
}
#endif /* #if(SPT_DSP_ENABLE == STD_ON) */


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

Std_ReturnType Spt_StartExec(volatile SPT_Type *pSptRegs)
{
    uint32              bits32 = 0, stopBit, startBit;
    volatile uint32     timeout = SPT_TIMEOUT_CNT_START;
    Std_ReturnType      retStatus = (Std_ReturnType)E_OK;

    /* Run the SPT code: enable program start control. */
    bits32 = SPT_HW_READ_REG(pSptRegs->GBL_CTRL);
    SPT_HW_WRITE_REG(pSptRegs->GBL_CTRL, bits32 | SPT_BITMASK_GBL_CTRL_PG_START);

    do
    {
        timeout--;
        /* Wait until CS_STATUS0[PS_STOP] = 0. Previous SPT runs leave it on '1', and there is a hw delay
         * in clearing it when a new kernel starts, causing a race condition with Spt_WaitForSptDone() */
        stopBit = SPT_HW_READ_BITS(pSptRegs->CS_STATUS0, SPT_CS_STATUS0_PS_STOP_MASK, SPT_CS_STATUS0_PS_STOP_SHIFT);

        /* Also wait for auto-clear of GBL_CTRL[PG_ST_CTRL], as per S32R ref manual: "When set, user should wait for
         * PG_ST_CTRL to be 0 to ensure that all status are cleared properly." */
        startBit = SPT_HW_READ_BITS(pSptRegs->GBL_CTRL, SPT_GBL_CTRL_PG_ST_CTRL_MASK, SPT_GBL_CTRL_PG_ST_CTRL_SHIFT);

    } while ((timeout > 0u) && ((stopBit != 0u) || (startBit != 0u)));

    if (timeout == 0u)
    {
        /* If the timeout was reached then something unexpected happened in hw which prevents normal SPT control flow */
        Spt_SetDrvState(SPT_STATE_FAULT);
        SPT_PRINT("SPT Driver error: Start Timeout!");
        retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_TIMEOUT_START, SPT_EXEC_START, SPT_E_TIMEOUT_START);
    }

    return retStatus;
}

#if(SPT_RUN_POLL == STD_ON)
Std_ReturnType Spt_WaitForSptDone(volatile SPT_Type *pSptRegs, volatile sint32 *sptRetValue)
{
    volatile uint32     timeout = SPT_TIMEOUT_CNT_BLOCK_MODE;
    Std_ReturnType      retStatus = (Std_ReturnType)E_OK;

    /* Wait until SPT finishes running the command sequence or an error occurs or the timeout counter expires */
    while (timeout > 0u)
    {
        timeout--;

        retStatus = Spt_CheckAndResetHwError(pSptRegs, &gSptMemPer.errInfo);

        if (retStatus != (Std_ReturnType)E_OK)
        {
            /* The SPT hw signaled an error during kernel execution.
             * Quit the wait loop and report the faulty state */
            Spt_SetDrvState(SPT_STATE_FAULT);

            retStatus = SPT_REPORT_ERROR((retStatus + RSDK_SPT_STATUS_BASE), SPT_EXEC_POLL, retStatus);

            break;
        }

        if (timeout == 0u)
        {
            /* SPT hw did not finish processing in due time, without reporting any specific error */
            RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, (uint16_t)RSDK_TRACE_DBG_SPT_KERNEL_TIMEOUT, 0);
            retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_TIMEOUT_BLOCK, SPT_EXEC_POLL, SPT_E_TIMEOUT_BLOCK);
            Spt_SetDrvState(SPT_STATE_FAULT);

            /* break is implicit */
        }

        if (SPT_HW_READ_BITS(pSptRegs->CS_STATUS0, SPT_CS_STATUS0_PS_STOP_MASK, SPT_CS_STATUS0_PS_STOP_SHIFT) == (uint32)1)
        {
            /* Clear the STOP bit, to be consistent with non-blocking mode processing (in SptEcsIsr() ) */
            SPT_HW_WRITE_BITS(pSptRegs->CS_STATUS0, SPT_CS_STATUS0_PS_STOP_MASK, SPT_CS_STATUS0_PS_STOP(1u));

            /* Need to check the non-command errors again, since they can appear between the last call to
             * Spt_CheckAndResetHwError and the checking of PS_STOP bit.
             * Since the S32R documentation does not provide reliable information about which exactly are the
             * non-command error bits, simply check all errors again */
            retStatus = Spt_CheckAndResetHwError(pSptRegs, &gSptMemPer.errInfo);
            if (retStatus != (Std_ReturnType)E_OK)
            {
                Spt_SetDrvState(SPT_STATE_FAULT);

                retStatus = SPT_REPORT_ERROR((retStatus + RSDK_SPT_STATUS_BASE), SPT_EXEC_POLL, retStatus);

                break;
            }

            if (Spt_CheckUnexpectedStop(pSptRegs, gSptMemPer.state) != (Std_ReturnType)E_OK)
            {
                retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_WARN_UNEXPECTED_STOP, SPT_EXEC_POLL, SPT_E_WARN_UNEXPECTED_STOP);
            }
            else
            {
                /*SPT finished the kernel execution successfully before timeout expired. */

                /* on S32R45/S32R41/SAF85XX the WRs can be read after SPT STOP */
                Spt_GetKernelRetVal(sptRetValue);
            }

            /* Everything went OK, go back to initialized state */
            Spt_SetDrvState(SPT_STATE_INITIALIZED);

            break;
        }
    }

    /* Do not clear GBL_STATUS flags, because that could cause a malfunction of the SptAcqIsr(), which is expected to
     * run even when SPT is not executing any code - HW_WRITE(pSptRegs->GBL_STATUS.R, (uint32)0x7); */

    return retStatus;
}
#endif /* #if(SPT_RUN_POLL == STD_ON) */


Std_ReturnType Spt_StopHw(void)
{
    Std_ReturnType                  retStatus = (Std_ReturnType)E_OK;
    volatile SPT_Type *const        pSptRegs = Spt_GetMemMap();
    volatile uint32                 timeout;

    /* Make sure the command sequencer has been stopped before disabling it */
    SPT_HW_WRITE_BITS(pSptRegs->CS_MODE_CTRL, SPT_CS_MODE_CTRL_ASYNCSTOP_MASK, SPT_CS_MODE_CTRL_ASYNCSTOP(1U));

    /* Wait until the hw state transition: */
    timeout = 10U * SPT_TIMEOUT_CNT_DISABLE;
    while ((SPT_HW_READ_BITS(pSptRegs->CS_STATUS3, SPT_CS_STATUS3_PROC_STATE_MASK, SPT_CS_STATUS3_PROC_STATE_SHIFT) !=
            SPT_SEQUENCER_STATE_START) && (timeout != 0u))
    {
        timeout--;
    }
    if (timeout == 0u)
    {
        retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_TIMEOUT_STOP, SPT_HW_STOP, SPT_E_TIMEOUT_STOP);
    }

    SPT_HW_WRITE_REG(pSptRegs->MEM_ERR_INT_EN, 0x0u);
    SPT_HW_WRITE_REG(pSptRegs->HW_ACC_ERR_IE, 0x0u);
    SPT_HW_WRITE_REG(pSptRegs->CS_INTEN1, 0x0u);
    SPT_HW_WRITE_REG(pSptRegs->CS_INTEN0, 0x0u);
    SPT_HW_WRITE_REG(pSptRegs->HIST_OVF_IE, 0x0u);
    /* Disable interrupts on all SPT event lines: */
    SPT_HW_WRITE_REG(pSptRegs->CS_EVT1_INTEN, 0x0u);
    /* Disable Work Register/SPR Access Error Interrupt */
    SPT_HW_WRITE_REG(pSptRegs->WR_ACCESS_ERR_INT_EN, 0x0u);
    /* Disable Global Status Interrupt */
    SPT_HW_WRITE_REG(pSptRegs->GBL_STATUS_IE, 0x0u);
    /* Disable DSP interrupts */
    SPT_HW_WRITE_REG(pSptRegs->DSP_ERR_INFO_INT_EN, 0x0u);













    /* Disable all SCSn Interrupts */
    SPT_HW_WRITE_REG(pSptRegs->SCS0_INTEN0, 0x0u);
    SPT_HW_WRITE_REG(pSptRegs->SCS1_INTEN0, 0x0u);
    SPT_HW_WRITE_REG(pSptRegs->SCS0_INTEN1, 0x0u);
    SPT_HW_WRITE_REG(pSptRegs->SCS1_INTEN1, 0x0u);


    return retStatus;
}


Std_ReturnType Spt_ConfigHw(Spt_DriverInitType const *const pSptInitInfo, volatile SPT_Type *pSptRegs)
{
    Std_ReturnType  retStatus = (Std_ReturnType)E_OK;
    uint32          sptHwState;

    sptHwState = SPT_HW_READ_BITS(pSptRegs->CS_STATUS3, SPT_CS_STATUS3_PROC_STATE_MASK, SPT_CS_STATUS3_PROC_STATE_SHIFT);
    if ((sptHwState != SPT_SEQUENCER_STATE_RST) && (sptHwState != SPT_SEQUENCER_STATE_START))
    {
        /* If the SPT is not in reset state, then it needs to be disabled before (re)initializing
         * the configuration registers: */
        retStatus = Spt_StopHw();
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        Spt_ConfigEvtInterrupts(pSptRegs);
        /* ECS interrupts are also configured in Spt_Run(), in case the operating mode changes. */
        Spt_ConfigEcsInterrupts(pSptRegs, SPT_OP_MODE_BLOCK);




        /* registration of interrupt handlers is done in the OS kernel, not in user space */


        /* Enable error detection and prefetch options in the command sequencer */
        SPT_HW_WRITE_BITS(pSptRegs->CS_MODE_CTRL, SPT_CS_MODE_CTRL_ERROR_EN_MASK, SPT_CS_MODE_CTRL_ERROR_EN(1u));
        SPT_HW_WRITE_BITS(pSptRegs->CS_MODE_CTRL, SPT_CS_MODE_CTRL_PREFETCH_MASK, SPT_CS_MODE_CTRL_PREFETCH(1u));

        SPT_HW_WRITE_REG(pSptRegs->PDMA_CONTROL, 0x0u); /* no LFSR */

        /* The DMA Burst Size of the Command Sequencer option does not exist in S32R45
         * GBL_CTRL ACQ_EN and SPT_EN bits do not exist in S32R45/S32R41/SAF85XX */

#if(SPT_DSP_ENABLE == STD_ON)
        if (pSptInitInfo->hwPlatSpec.dspEn != FALSE)
        {
            Spt_ConfigDspInterrupt(pSptRegs);
            /* Enable the BBE32 DSP to boot-up and start running the "DSP Dispatcher" */
            Spt_DspBoot(pSptRegs, pSptInitInfo);
        }
#endif /* #if(SPT_DSP_ENABLE == STD_ON) */
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        retStatus = Spt_CheckRst(pSptRegs);
    }

    return retStatus;
}


#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
