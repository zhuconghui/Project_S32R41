
/*
 * Copyright 2017-2023 NXP
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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <string.h>

#include "CDD_Spt.h"
#include "Spt_Cfg.h"
#include "Spt_Internals.h"
#include "Spt_Irq_Config.h"
#include "Spt_Hw_Check.h"
#include "Spt_Hw_Ctrl.h"
#include "rsdk_version.h"


#include "Spt_Seq_Ctrl.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_SPT_C_VENDOR_ID                     43
#define CDD_SPT_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define CDD_SPT_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define CDD_SPT_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define CDD_SPT_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define CDD_SPT_C_SW_MINOR_VERSION              RSDK_SW_MINOR
#define CDD_SPT_C_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if CDD_Spt source file and Spt header file are of the same vendor */
#if (CDD_SPT_C_VENDOR_ID != CDD_SPT_VENDOR_ID)
    #error "CDD_Spt.c and Spt.h have different vendor ids"
#endif

/* Check if CDD_Spt source file and Spt header file are of the same Autosar version */
#if ((CDD_SPT_C_AR_RELEASE_MAJOR_VERSION    != CDD_SPT_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_MINOR_VERSION    != CDD_SPT_AR_RELEASE_MINOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_REVISION_VERSION != CDD_SPT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Spt.c and Spt.h are different"
#endif

/* Check if CDD_Spt source file and Spt header file are of the same Software version */
#if ((CDD_SPT_C_SW_MAJOR_VERSION != CDD_SPT_SW_MAJOR_VERSION) || \
     (CDD_SPT_C_SW_MINOR_VERSION != CDD_SPT_SW_MINOR_VERSION) || \
     (CDD_SPT_C_SW_PATCH_VERSION != CDD_SPT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Spt.c and Spt.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Cfg header file are of the same vendor */
#if (CDD_SPT_C_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "CDD_Spt.c and Spt_Cfg.h have different vendor ids"
#endif

/* Check if CDD_Spt source file and Spt_Cfg header file are of the same Autosar version */
#if ((CDD_SPT_C_AR_RELEASE_MAJOR_VERSION    != SPT_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Spt.c and Spt_Cfg.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Cfg header file are of the same Software version */
#if ((CDD_SPT_C_SW_MAJOR_VERSION != SPT_CFG_SW_MAJOR_VERSION) || \
     (CDD_SPT_C_SW_MINOR_VERSION != SPT_CFG_SW_MINOR_VERSION) || \
     (CDD_SPT_C_SW_PATCH_VERSION != SPT_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Spt.c and Spt_Cfg.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Internals header file are of the same vendor */
#if (CDD_SPT_C_VENDOR_ID != SPT_INTERNALS_VENDOR_ID)
    #error "CDD_Spt.c and Spt_Internals.h have different vendor ids"
#endif

/* Check if CDD_Spt source file and Spt_Internals header file are of the same Autosar version */
#if ((CDD_SPT_C_AR_RELEASE_MAJOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_MINOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_REVISION_VERSION != SPT_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Spt.c and Spt_Internals.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Internals header file are of the same Software version */
#if ((CDD_SPT_C_SW_MAJOR_VERSION != SPT_INTERNALS_SW_MAJOR_VERSION) || \
     (CDD_SPT_C_SW_MINOR_VERSION != SPT_INTERNALS_SW_MINOR_VERSION) || \
     (CDD_SPT_C_SW_PATCH_VERSION != SPT_INTERNALS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Spt.c and Spt_Internals.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Irq_Config header file are of the same vendor */
#if (CDD_SPT_C_VENDOR_ID != SPT_IRQ_CONFIG_VENDOR_ID)
    #error "CDD_Spt.c and Spt_Irq_Config.h have different vendor ids"
#endif

/* Check if CDD_Spt source file and Spt_Irq_Config header file are of the same Autosar version */
#if ((CDD_SPT_C_AR_RELEASE_MAJOR_VERSION    != SPT_IRQ_CONFIG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_MINOR_VERSION    != SPT_IRQ_CONFIG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_REVISION_VERSION != SPT_IRQ_CONFIG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Spt.c and Spt_Irq_Config.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Irq_Config header file are of the same Software version */
#if ((CDD_SPT_C_SW_MAJOR_VERSION != SPT_IRQ_CONFIG_SW_MAJOR_VERSION) || \
     (CDD_SPT_C_SW_MINOR_VERSION != SPT_IRQ_CONFIG_SW_MINOR_VERSION) || \
     (CDD_SPT_C_SW_PATCH_VERSION != SPT_IRQ_CONFIG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Spt.c and Spt_Irq_Config.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Hw_Check header file are of the same vendor */
#if (CDD_SPT_C_VENDOR_ID != SPT_HW_CHECK_VENDOR_ID)
    #error "CDD_Spt.c and Spt_Hw_Check.h have different vendor ids"
#endif

/* Check if CDD_Spt source file and Spt_Hw_Check header file are of the same Autosar version */
#if ((CDD_SPT_C_AR_RELEASE_MAJOR_VERSION    != SPT_HW_CHECK_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_MINOR_VERSION    != SPT_HW_CHECK_AR_RELEASE_MINOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_REVISION_VERSION != SPT_HW_CHECK_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Spt.c and Spt_Hw_Check.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Hw_Check header file are of the same Software version */
#if ((CDD_SPT_C_SW_MAJOR_VERSION != SPT_HW_CHECK_SW_MAJOR_VERSION) || \
     (CDD_SPT_C_SW_MINOR_VERSION != SPT_HW_CHECK_SW_MINOR_VERSION) || \
     (CDD_SPT_C_SW_PATCH_VERSION != SPT_HW_CHECK_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Spt.c and Spt_Hw_Check.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Hw_Ctrl header file are of the same vendor */
#if (CDD_SPT_C_VENDOR_ID != SPT_HW_CTRL_VENDOR_ID)
    #error "CDD_Spt.c and Spt_Hw_Ctrl.h have different vendor ids"
#endif

/* Check if CDD_Spt source file and Spt_Hw_Ctrl header file are of the same Autosar version */
#if ((CDD_SPT_C_AR_RELEASE_MAJOR_VERSION    != SPT_HW_CTRL_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_MINOR_VERSION    != SPT_HW_CTRL_AR_RELEASE_MINOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_REVISION_VERSION != SPT_HW_CTRL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Spt.c and Spt_Hw_Ctrl.h are different"
#endif

/* Check if CDD_Spt source file and Spt_Hw_Ctrl header file are of the same Software version */
#if ((CDD_SPT_C_SW_MAJOR_VERSION != SPT_HW_CTRL_SW_MAJOR_VERSION) || \
     (CDD_SPT_C_SW_MINOR_VERSION != SPT_HW_CTRL_SW_MINOR_VERSION) || \
     (CDD_SPT_C_SW_PATCH_VERSION != SPT_HW_CTRL_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Spt.c and Spt_Hw_Ctrl.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if CDD_Spt.c file and Det header file are of the same AutoSar version */
#if ((CDD_SPT_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SPT_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of CDD_Spt.c and Det.h are different"
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

Std_ReturnType Spt_Run(Spt_DriverContextType const *const sptContext)
{
    Std_ReturnType                  retStatus = (Std_ReturnType)E_OK;
    volatile SPT_Type *const        pSptRegs = Spt_GetMemMap();





    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_SPT_DRV_RUN, (uint32)gSptMemPer.state);






#if (SPT_SINGLE_THREAD == STD_OFF)
    retStatus = Spt_ApiSequenceTryEnter();
#endif



#if (SPT_DEV_ERROR_DETECT == STD_ON)
#if ((!RSDK_OSENV_SA) || (defined(RSDK_AUTOSAR) && (SPT_SINGLE_THREAD == STD_OFF)))
    if (retStatus == (Std_ReturnType)E_OK)
#endif
    {
        retStatus = Spt_ParamCheckRun(sptContext, gSptMemPer.state);
    }
#endif

    if (retStatus == (Std_ReturnType)E_OK)
    {
        retStatus = Spt_CheckRst(pSptRegs);
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        /* Copy information to persistent memory to make it visible from the ISR: */




        gSptMemPer.kernelRetPar = sptContext->kernelRetPar;

        /* Prevent erroneous flags that could remain from a previous error */
        Spt_ClearEcsInterruptFlags(pSptRegs);

        if (gSptMemPer.prevOpMode != sptContext->opMode)
        {
            gSptMemPer.prevOpMode = sptContext->opMode;
            Spt_ConfigEcsInterrupts(pSptRegs, sptContext->opMode);
        }

        /* Initialize program start address register */
        SPT_HW_WRITE_BITS(pSptRegs->CS_PG_ST_ADDR, SPT_CS_PG_ST_ADDR_PG_ST_ADDR_MASK,
                            SPT_CS_PG_ST_ADDR_PG_ST_ADDR(sptContext->kernelCodeAddr));

        /* Parse parameter list and pass them to SPT according to the calling convention: */
        retStatus = Spt_SetInputParams(sptContext->kernelParList);
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        Spt_SetDrvState(SPT_STATE_HW_BUSY);

        RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, (uint16_t)RSDK_TRACE_DBG_SPT_KERNEL_START, 0u);

        retStatus = Spt_StartExec(pSptRegs);
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        if (sptContext->opMode == SPT_OP_MODE_NONBLOCK)
        {
            /* Do not wait for SPT completion, exit immediately to make the CPU available
             * Now the driver state can only be changed asynchronously by SptEcsIsr, or by
             * the user calling Spt_Stop or Spt_Setup */
        }
#if(SPT_RUN_POLL == STD_ON)
        else  /* Assume OP_MODE_BLOCK */
        {
            retStatus = Spt_WaitForSptDone(pSptRegs, sptContext->kernelRetPar);
        }
#endif
    }










#if (SPT_SINGLE_THREAD == STD_OFF)
    Spt_ApiSequenceExit();
#endif



    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_SPT_DRV_RUN, (uint32)gSptMemPer.state);

    return retStatus;
}

/*================================================================================================*/
Std_ReturnType Spt_Setup(Spt_DriverInitType const *const pSptInitInfo)
{
    volatile SPT_Type *         pSptRegs = NULL_PTR;
    Std_ReturnType              retStatus = (Std_ReturnType)E_OK;
    Spt_DrvStateType            drvState = gSptMemPer.state;




    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_SPT_DRV_INIT, (uint32)gSptMemPer.state);












#if (SPT_SINGLE_THREAD == STD_OFF)
    retStatus = Spt_ApiSequenceTryEnter();
#endif



#if (SPT_DEV_ERROR_DETECT == STD_ON)
#if ((!RSDK_OSENV_SA) || (defined(RSDK_AUTOSAR) && (SPT_SINGLE_THREAD == STD_OFF)))
    if (retStatus == (Std_ReturnType)E_OK)
#endif
    {
        retStatus = Spt_ParamCheckInit(pSptInitInfo);
    }
#endif

    if (retStatus == (Std_ReturnType)E_OK)
    {
        /* If this is not the first call to Spt_Setup and the user did not do a clean shutdown of the Driver
         * (using Spt_Stop), then we need to clean up previously allocated Driver resources */
        if ((drvState == SPT_STATE_INITIALIZED) || (drvState == SPT_STATE_HW_BUSY) || (drvState == SPT_STATE_FAULT))
        {
            retStatus = Spt_UnmapMem();






        }
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        /* Initialize driver's persistent memory.
         * This must be done after the 'cleanup' section above, but before calling Spt_GetMemMap() */
        Spt_InitPersistentMem(&gSptMemPer, pSptInitInfo);

        /* Map SPT peripheral memory to the driver: */
        pSptRegs = Spt_GetMemMap();









        retStatus = Spt_ConfigHw(pSptInitInfo, pSptRegs);
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        Spt_SetDrvState(SPT_STATE_INITIALIZED);
    }










#if (SPT_SINGLE_THREAD == STD_OFF)
    Spt_ApiSequenceExit();
#endif



    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_SPT_DRV_INIT, (uint32)gSptMemPer.state);

    return retStatus;
}

/*================================================================================================*/
Std_ReturnType Spt_Command(Spt_DriverCommandType const *const pSptCommand, Spt_DriverCmdResType *const pSptCmdResult)
{
    Std_ReturnType                  retStatus = (Std_ReturnType)E_OK;
    Spt_DrvStateType                drvState = gSptMemPer.state;
    volatile SPT_Type *const        pSptRegs = Spt_GetMemMap();




    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_SPT_DRV_CMD, (uint32)gSptMemPer.state);





#if (SPT_SINGLE_THREAD == STD_OFF)
    retStatus = Spt_ApiSequenceTryEnter();
#endif



#if (SPT_DEV_ERROR_DETECT == STD_ON)
#if ((!RSDK_OSENV_SA) || (defined(RSDK_AUTOSAR) && (SPT_SINGLE_THREAD == STD_OFF)))
    if ((retStatus == (Std_ReturnType)E_OK) && ((pSptCommand == NULL_PTR) || (pSptCmdResult == NULL_PTR)))
#else
    if ((pSptCommand == NULL_PTR) || (pSptCmdResult == NULL_PTR))
#endif
    {
        retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_PARAM, SPT_API_CALL, SPT_E_INVALID_PARAM);
    }
#endif /* #if (SPT_DEV_ERROR_DETECT == STD_ON) */

    if ((retStatus == (Std_ReturnType)E_OK) && ((drvState == SPT_STATE_DISABLED) || (drvState == SPT_STATE_FAULT)))
    {
        retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_STATE, SPT_API_CALL, SPT_E_INVALID_STATE);
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        retStatus = Spt_CheckRst(pSptRegs);
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        switch ((uint32)pSptCommand->cmdId)
        {
#if(SPT_DSP_ENABLE == STD_ON)
            case (uint32)SPT_CMD_GEN_DSP_CMD_CRC:
                {
#if (SPT_DEV_ERROR_DETECT == STD_ON)
                    if((pSptCommand->cmdParam == (uintptr_t)NULL_PTR))
                    {
                        retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_PARAM, SPT_API_CALL, SPT_E_INVALID_PARAM);
                    }
                    else
#endif /* #if (SPT_DEV_ERROR_DETECT == STD_ON) */
                    {
                        Spt_DspCmdType* pDspCmd = (Spt_DspCmdType*)pSptCommand->cmdParam;
                        uint8 dspCmdVec[sizeof(pDspCmd->id)+sizeof(pDspCmd->arg)];

                        (void)memcpy(&dspCmdVec[0], &(pDspCmd->id), sizeof(pDspCmd->id));
                        (void)memcpy(&dspCmdVec[sizeof(pDspCmd->id)], (uint8*)(&pDspCmd->arg), sizeof(pDspCmd->arg));

                        /* Compute 8-bit CRC on the DSP commmand "id" and "arg" fields. */
                        pDspCmd->crc = Spt_GenCrc8(dspCmdVec, (uint8)sizeof(dspCmdVec));
                    }
                }
                break;
#endif /* #if(SPT_DSP_ENABLE == STD_ON) */
            case (uint32)SPT_CMD_MEM_ERR_INJECT_EN:
                /* Enable injection of all possible parity errors for OPRAM and TRAM */
                SPT_HW_WRITE_BITS(pSptRegs->MEM_ERR_INJECT_CTRL, SPT_MEM_ERR_INJECT_CTRL_OR_PAR_ERR_INJ_MASK,
                                    SPT_MEM_ERR_INJECT_CTRL_OR_PAR_ERR_INJ(0xFu));
                SPT_HW_WRITE_BITS(pSptRegs->MEM_ERR_INJECT_CTRL, SPT_MEM_ERR_INJECT_CTRL_TR_PAR_ERR_INJ_MASK,
                                    SPT_MEM_ERR_INJECT_CTRL_TR_PAR_ERR_INJ(0xFu));
                break;
            case (uint32)SPT_CMD_MEM_ERR_INJECT_DIS:
                SPT_HW_WRITE_BITS(pSptRegs->MEM_ERR_INJECT_CTRL, SPT_MEM_ERR_INJECT_CTRL_OR_PAR_ERR_INJ_MASK,
                                    SPT_MEM_ERR_INJECT_CTRL_OR_PAR_ERR_INJ(0x0u));
                SPT_HW_WRITE_BITS(pSptRegs->MEM_ERR_INJECT_CTRL, SPT_MEM_ERR_INJECT_CTRL_TR_PAR_ERR_INJ_MASK,
                                    SPT_MEM_ERR_INJECT_CTRL_TR_PAR_ERR_INJ(0x0u));
                break;
            case (uint32)SPT_CMD_TRIGGER_SW_EVENT:
                /* Set all bits to cover all possible events configured in the SPT "wait" instruction */
                SPT_HW_WRITE_BITS(pSptRegs->CS_SW_EVTREG, SPT_CS_SW_EVTREG_SW_EVTREG_MASK,
                                    SPT_CS_SW_EVTREG_SW_EVTREG(pSptCommand->cmdParam));
                break;





            default:
                retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_PARAM, SPT_API_CALL, SPT_E_INVALID_PARAM);
                break;
        }
    }










#if (SPT_SINGLE_THREAD == STD_OFF)
    Spt_ApiSequenceExit();
#endif



    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_SPT_DRV_CMD, (uint32)gSptMemPer.state);

    return retStatus;
}
/*================================================================================================*/
Std_ReturnType Spt_Stop(void)
{
    Std_ReturnType      retStatus = (Std_ReturnType)E_OK;
    Spt_DrvStateType    drvState = gSptMemPer.state;




    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_SPT_DRV_STOP, (uint32)gSptMemPer.state);





#if (SPT_SINGLE_THREAD == STD_OFF)
    retStatus = Spt_ApiSequenceTryEnter();
#endif



#if ((!RSDK_OSENV_SA) || (defined(RSDK_AUTOSAR) && (SPT_SINGLE_THREAD == STD_OFF)))
    if (retStatus == (Std_ReturnType)E_OK)
#endif
    {
        if ((drvState <= SPT_STATE_DISABLED) || (drvState > SPT_STATE_FAULT))
        {
            /* In this case consider Spt_Setup() has not been called prior to this point as expected, so there is nothing to stop. */
            retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_STATE, SPT_API_CALL, SPT_E_INVALID_STATE);
        }
        else
        {
            retStatus = Spt_StopHw();
        }
    }

    if (retStatus == (Std_ReturnType)E_OK)
    {
        retStatus = Spt_UnmapMem();






        if (retStatus == (Std_ReturnType)E_OK)
        {
            Spt_SetDrvState(SPT_STATE_DISABLED);
        }
    }











#if (SPT_SINGLE_THREAD == STD_OFF)
    Spt_ApiSequenceExit();
#endif



    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_SPT_DRV_STOP, (uint32)gSptMemPer.state);

    return retStatus;
}


#if (SPT_VERSION_INFO_API == STD_ON)
/*================================================================================================*/
/**
 * @brief       The function returns the version info for the module.
 * @details     The function returns the version info for the module.
 *
 * @param[in]   versioninfo    - pointer to a version structure to receive the data
 *
 * @return      void
 *
 * @pre         It can be called when the reception need to be stopped. The unit must be in INITIALIZED state.
 *
 */
void Spt_GetVersionInfo(Std_VersionInfoType* versionInfoPtr)
{
#if (SPT_DEV_ERROR_DETECT == STD_ON)
    if (versionInfoPtr == NULL_PTR)
    {
        (void)SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_PARAM, SPT_VERSION_INFO_CHECK, SPT_E_INVALID_PARAM);
    }
    else
#endif
    {
        versionInfoPtr->moduleID           = (uint16)CDD_SPT_MODULE_ID;
        versionInfoPtr->vendorID           = (uint16)CDD_SPT_VENDOR_ID;
        versionInfoPtr->sw_major_version   = (uint8) CDD_SPT_SW_MAJOR_VERSION;
        versionInfoPtr->sw_minor_version   = (uint8) CDD_SPT_SW_MINOR_VERSION;
        versionInfoPtr->sw_patch_version   = (uint8) CDD_SPT_SW_PATCH_VERSION;
    }
}
/* Spt_GetVersionInfo *************************/
#endif /* (SPT_VERSION_INFO_API == STD_ON)     */



#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


/*================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
