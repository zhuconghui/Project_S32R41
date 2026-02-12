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
#include "Spt_Irq_Config.h"
#include "Spt_Irq.h"
#include "Spt_Hw_Defs.h"
#include "Spt_Internals.h"
#include "Spt_Cfg.h"
#include "rsdk_version.h"





/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_IRQ_CONFIG_C_VENDOR_ID                     43
#define SPT_IRQ_CONFIG_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define SPT_IRQ_CONFIG_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define SPT_IRQ_CONFIG_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define SPT_IRQ_CONFIG_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define SPT_IRQ_CONFIG_C_SW_MINOR_VERSION              RSDK_SW_MINOR
#define SPT_IRQ_CONFIG_C_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if Spt_Irq_Config source file and Spt_Irq_Config header file are of the same vendor */
#if (SPT_IRQ_CONFIG_C_VENDOR_ID != SPT_IRQ_CONFIG_VENDOR_ID)
    #error "Spt_Irq_Config.c and Spt_Irq_Config.h have different vendor ids"
#endif

/* Check if Spt_Irq_Config source file and Spt_Irq_Config header file are of the same Autosar version */
#if ((SPT_IRQ_CONFIG_C_AR_RELEASE_MAJOR_VERSION    != SPT_IRQ_CONFIG_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_MINOR_VERSION    != SPT_IRQ_CONFIG_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_REVISION_VERSION != SPT_IRQ_CONFIG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq_Config.c and Spt_Irq_Config.h are different"
#endif

/* Check if Spt_Irq_Config source file and Spt_Irq_Config header file are of the same Software version */
#if ((SPT_IRQ_CONFIG_C_SW_MAJOR_VERSION != SPT_IRQ_CONFIG_SW_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_MINOR_VERSION != SPT_IRQ_CONFIG_SW_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_PATCH_VERSION != SPT_IRQ_CONFIG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq_Config.c and Spt_Irq_Config.h are different"
#endif

/* Check if Spt_Irq_Config source file and Spt_Irq header file are of the same vendor */
#if (SPT_IRQ_CONFIG_C_VENDOR_ID != SPT_IRQ_VENDOR_ID)
    #error "Spt_Irq_Config.c and Spt_Irq.h have different vendor ids"
#endif

/* Check if Spt_Irq_Config source file and Spt_Irq header file are of the same Autosar version */
#if ((SPT_IRQ_CONFIG_C_AR_RELEASE_MAJOR_VERSION    != SPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_MINOR_VERSION    != SPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_REVISION_VERSION != SPT_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq_Config.c and Spt_Irq.h are different"
#endif

/* Check if Spt_Irq_Config source file and Spt_Irq header file are of the same Software version */
#if ((SPT_IRQ_CONFIG_C_SW_MAJOR_VERSION != SPT_IRQ_SW_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_MINOR_VERSION != SPT_IRQ_SW_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_PATCH_VERSION != SPT_IRQ_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq_Config.c and Spt_Irq.h are different"
#endif

/* Check if Spt_Irq_Config source file and Spt_Hw_Defs header file are of the same vendor */
#if (SPT_IRQ_CONFIG_C_VENDOR_ID != SPT_HW_DEFS_VENDOR_ID)
    #error "Spt_Irq_Config.c and Spt_Hw_Defs.h have different vendor ids"
#endif

/* Check if Spt_Irq_Config source file and Spt_Hw_Defs header file are of the same Autosar version */
#if ((SPT_IRQ_CONFIG_C_AR_RELEASE_MAJOR_VERSION    != SPT_HW_DEFS_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_MINOR_VERSION    != SPT_HW_DEFS_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_REVISION_VERSION != SPT_HW_DEFS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq_Config.c and Spt_Hw_Defs.h are different"
#endif

/* Check if Spt_Irq_Config source file and Spt_Hw_Defs header file are of the same Software version */
#if ((SPT_IRQ_CONFIG_C_SW_MAJOR_VERSION != SPT_HW_DEFS_SW_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_MINOR_VERSION != SPT_HW_DEFS_SW_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_PATCH_VERSION != SPT_HW_DEFS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq_Config.c and Spt_Hw_Defs.h are different"
#endif

/* Check if Spt_Irq_Config source file and Spt_Internals header file are of the same vendor */
#if (SPT_IRQ_CONFIG_C_VENDOR_ID != SPT_INTERNALS_VENDOR_ID)
    #error "Spt_Irq_Config.c and Spt_Internals.h have different vendor ids"
#endif

/* Check if Spt_Irq_Config source file and Spt_Internals header file are of the same Autosar version */
#if ((SPT_IRQ_CONFIG_C_AR_RELEASE_MAJOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_MINOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_REVISION_VERSION != SPT_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq_Config.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Irq_Config source file and Spt_Internals header file are of the same Software version */
#if ((SPT_IRQ_CONFIG_C_SW_MAJOR_VERSION != SPT_INTERNALS_SW_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_MINOR_VERSION != SPT_INTERNALS_SW_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_PATCH_VERSION != SPT_INTERNALS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq_Config.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Irq_Config source file and Spt_Cfg header file are of the same vendor */
#if (SPT_IRQ_CONFIG_C_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "Spt_Irq_Config.c and Spt_Cfg.h have different vendor ids"
#endif

/* Check if Spt_Irq_Config source file and Spt_Cfg header file are of the same Autosar version */
#if ((SPT_IRQ_CONFIG_C_AR_RELEASE_MAJOR_VERSION    != SPT_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Irq_Config.c and Spt_Cfg.h are different"
#endif

/* Check if Spt_Irq_Config source file and Spt_Cfg header file are of the same Software version */
#if ((SPT_IRQ_CONFIG_C_SW_MAJOR_VERSION != SPT_CFG_SW_MAJOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_MINOR_VERSION != SPT_CFG_SW_MINOR_VERSION) || \
     (SPT_IRQ_CONFIG_C_SW_PATCH_VERSION != SPT_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Irq_Config.c and Spt_Cfg.h are different"
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
void Spt_ClearEcsInterruptFlags(volatile SPT_Type *pSptRegs)
{
    /*--- Clear all interrupt flags */
    SPT_HW_WRITE_REG(pSptRegs->MEM_ERR_STATUS,    SPT_MEM_ERR_STATUS_W1C_MASK);
    SPT_HW_WRITE_REG(pSptRegs->HW_ACC_ERR_STATUS, SPT_HW_ACC_ERR_STATUS_W1C_MASK);
    SPT_HW_WRITE_REG(pSptRegs->CS_STATUS1,        SPT_CS_STATUS1_W1C_MASK);
    SPT_HW_WRITE_REG(pSptRegs->CS_STATUS0,        SPT_CS_STATUS0_W1C_MASK);
    /* GBL_STATUS, SPT_HIST_OVF_STATUS0, SPT_HIST_OVF_STATUS1, WR_ACCESS_ERR_REG -> All the bits
     * in these registers are reset by the SPT hw in the SETUP state */














    /* Status reset for slave command sequencers: */
    SPT_HW_WRITE_REG(pSptRegs->SCS0_STATUS0, SPT_SCS_STATUS0_W1C_MASK);
    SPT_HW_WRITE_REG(pSptRegs->SCS1_STATUS0, SPT_SCS_STATUS0_W1C_MASK);

    SPT_HW_WRITE_REG(pSptRegs->SCS0_STATUS1, SPT_SCS_STATUS1_W1C_MASK);
    SPT_HW_WRITE_REG(pSptRegs->SCS1_STATUS1, SPT_SCS_STATUS1_W1C_MASK);

}

void Spt_ConfigEcsInterrupts(volatile SPT_Type *pSptRegs, Spt_DriverOpModeType opMode)
{
    if (opMode == SPT_OP_MODE_NONBLOCK)
    {
        /*--- Enable all error interrupt sources: */
        SPT_HW_WRITE_REG(pSptRegs->MEM_ERR_INT_EN,  SPT_MEM_ERR_STATUS_W1C_MASK);
        SPT_HW_WRITE_REG(pSptRegs->HW_ACC_ERR_IE,   SPT_HW_ACC_ERR_STATUS_W1C_MASK);
        SPT_HW_WRITE_REG(pSptRegs->CS_INTEN1,       SPT_CS_STATUS1_W1C_MASK);
        SPT_HW_WRITE_REG(pSptRegs->HIST_OVF_IE,     SPT_HIST_OVF_IE_OVF_IE_MASK);
        SPT_HW_WRITE_REG(pSptRegs->WR_ACCESS_ERR_INT_EN, SPT_WR_ACCESS_ERR_INT_EN_RF_SPR_ACC_IE_MASK);
        /* Enable only the error-signaling interrupts from GBL_STATUS_IE */
        SPT_HW_WRITE_REG(pSptRegs->GBL_STATUS_IE,   SPT_GBL_STATUS_ERR_W1C_MASK);

        /* Enable error interrupts for slave command sequencers:
         * SCS<n>_STATUS0 - contain only debug and state flags, no interrupts to be enabled here */
        SPT_HW_WRITE_REG(pSptRegs->SCS0_INTEN1,     SPT_SCS_STATUS1_W1C_MASK);
        SPT_HW_WRITE_REG(pSptRegs->SCS1_INTEN1,     SPT_SCS_STATUS1_W1C_MASK);








        /* Enable interrupt on SPT_CS_STATUS0[PS_STOP] bit */
        SPT_HW_WRITE_BITS(pSptRegs->CS_INTEN0, SPT_CS_INTEN0_PS_STOP_INTEN_MASK, SPT_CS_INTEN0_PS_STOP_INTEN(1u));
    }
    else
    {
        /* Blocking mode: disable all ECS error interrupt sources.
         * In this case all error status registers will be monitored in a polling loop */
        SPT_HW_WRITE_REG(pSptRegs->MEM_ERR_INT_EN, 0u);
        SPT_HW_WRITE_REG(pSptRegs->HW_ACC_ERR_IE,  0u);
        SPT_HW_WRITE_REG(pSptRegs->CS_INTEN1,      0u);
        SPT_HW_WRITE_REG(pSptRegs->HIST_OVF_IE,    0u);
        SPT_HW_WRITE_REG(pSptRegs->WR_ACCESS_ERR_INT_EN, 0u);
        SPT_HW_WRITE_REG(pSptRegs->GBL_STATUS_IE, 0u);

        /* Enable error interrupts for slave command sequencers:
         * SCS<n>_STATUS0 - contain only debug and state flags, no interrupts to be enabled here */
        SPT_HW_WRITE_REG(pSptRegs->SCS0_INTEN1, 0u);
        SPT_HW_WRITE_REG(pSptRegs->SCS1_INTEN1, 0u);








        /* Disable interrupt on SPT_CS_STATUS0[PS_STOP] bit */
        SPT_HW_WRITE_BITS(pSptRegs->CS_INTEN0, SPT_CS_INTEN0_PS_STOP_INTEN_MASK, SPT_CS_INTEN0_PS_STOP_INTEN(0u));
    }
}

void Spt_ConfigEvtInterrupts(volatile SPT_Type *pSptRegs)
{
    /*--- Enable interrupts on all SPT event lines: */
    SPT_HW_WRITE_REG(pSptRegs->CS_EVT1_INTEN, SPT_CS_EVTREG1_MASK);
}

void Spt_ConfigDspInterrupt(volatile SPT_Type *pSptRegs)
{
    SPT_HW_WRITE_REG(pSptRegs->DSP_ERR_INFO_INT_EN, SPT_DSP_ERR_INFO_INT_EN_DSPERRIE_MASK);
}





































#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
