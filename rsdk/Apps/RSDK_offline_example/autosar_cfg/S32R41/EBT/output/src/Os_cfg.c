/******************************************************************************
*
*       NXP(TM) and the NXP logo are trademarks of NXP.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2013-2016
*       Copyright 2024 NXP
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF NXP.
*
*       Description: Configuration Data file
*
*       Note: The implementation that was used is: AUTOSAR_S32R41
*       System Generator for AUTOSAR OS/S32R41 - Version: 4.7 Build 4.7.160
*
********************************************************************************/
#include    <Os.h>
#include    <Os_internal_config.h>
#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"


/* Task Configuration table */
const    OSTSK   OsTaskCfgTable[OSNTSKS] = 
{
    {
        (OSTASKENTRY) &FuncRSDK_Main, /* entry point of task */
        0U, /* top of task stack */
        0U, /* bottom of task stack */
        0U | OSTSKACTIVATE, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT, OSTSKFLOATINGPOINT */
        0U, /* task id (task number in the task table) */
    }, /* RSDK_Main */
};
const    OSISRCFGTYPE   OsIsrCfg[OSNISR + 1] =  /*Interrupts config table*/
{
    {
        OS_isr_Bbe32_RxHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        18U,  
        4U|0x80U, /* ISR PRIORITY */
    }, /* Bbe32_RxHandler */
    {
        OS_isr_Spt_DspHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        204U,  
        4U|0x80U, /* ISR PRIORITY */
    }, /* Spt_DspHandler */
    {
        OS_isr_Spt_EcsHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        206U,  
        4U|0x80U, /* ISR PRIORITY */
    }, /* Spt_EcsHandler */
    {
        OS_isr_Spt_EvtHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        205U,  
        4U|0x80U, /* ISR PRIORITY */
    }, /* Spt_EvtHandler */
    {
        OSISRException, /* actual ISR function */
        OSSYSINTERRUPT, /* ISR type */
        OSISREXCEPTIONIDX, /* Index of interrupt */
        OSISREXCEPTIONPRIO, /* Interrupt priority */
    }, /* Exception */
};
const    OSSHORT   OsIsr[OSNINTC] =  /* OSNINTERRUPTS external interrupt handlers table */
{
   /*  0*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 10*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,     0U, OSNISR,
   /* 20*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 30*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 40*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 50*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 60*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 70*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 80*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 90*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*100*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*110*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*120*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*130*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*140*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*150*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*160*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*170*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*180*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*190*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*200*/ OSNISR, OSNISR, OSNISR, OSNISR,     1U,     3U,     2U, OSNISR, OSNISR, OSNISR,
   /*210*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*220*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*230*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*240*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*250*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
};

const    OSRESCFG   OsResCfg[OSNALLRES] = 
{
    { 0U, /* Resource priority for task resources */ }, /* RES_SCHEDULER */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

