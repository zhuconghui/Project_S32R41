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
        (OSTASKENTRY) &FuncRsdkMain, /* entry point of task */
        0U, /* top of task stack */
        0U, /* bottom of task stack */
        0U | OSTSKACTIVATE, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT, OSTSKFLOATINGPOINT */
        0U, /* task id (task number in the task table) */
    }, /* RsdkMain */
};
const    OSISRCFGTYPE   OsIsrCfg[OSNISR + 1] =  /*Interrupts config table*/
{
    {
        OS_isr_Bbe32_RxHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        18U,  
        2U|0x80U, /* ISR PRIORITY */
    }, /* Bbe32_RxHandler */
    {
        OS_isr_Csi2_EventsHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        196U,  
        10U|0x80U, /* ISR PRIORITY */
    }, /* Csi2_EventsHandler */
    {
        OS_isr_Csi2_PathErrHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        195U,  
        10U|0x80U, /* ISR PRIORITY */
    }, /* Csi2_PathErrHandler */
    {
        OS_isr_Csi2_RxErrHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        194U,  
        10U|0x80U, /* ISR PRIORITY */
    }, /* Csi2_RxErrHandler */
    {
        OS_isr_Spt_DspHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        204U,  
        2U|0x80U, /* ISR PRIORITY */
    }, /* Spt_DspHandler */
    {
        OS_isr_Spt_EcsHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        206U,  
        2U|0x80U, /* ISR PRIORITY */
    }, /* Spt_EcsHandler */
    {
        OS_isr_Spt_EvtHandler, /* actual ISR function */
        OSISR1, /* ISR type */
        205U,  
        2U|0x80U, /* ISR PRIORITY */
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
   /*190*/ OSNISR, OSNISR, OSNISR, OSNISR,     3U,     2U,     1U, OSNISR, OSNISR, OSNISR,
   /*200*/ OSNISR, OSNISR, OSNISR, OSNISR,     4U,     6U,     5U, OSNISR, OSNISR, OSNISR,
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

