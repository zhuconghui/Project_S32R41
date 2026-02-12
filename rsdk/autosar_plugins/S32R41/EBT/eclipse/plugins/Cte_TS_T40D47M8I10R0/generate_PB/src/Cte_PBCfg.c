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

/*
 *  Configuration file for Cte module
 */
[!VAR "CteCfgPath"!]/AUTOSAR/TOP-LEVEL-PACKAGES/Cte/ELEMENTS/Cte[!ENDVAR!]
#include "Cte_Types.h"
 
 
/*
 * Output Configurations
 */[!// First loop is for Output Configurations
[!LOOP "/AUTOSAR/TOP-LEVEL-PACKAGES/Cte/ELEMENTS/Cte/CteOutputDefList/*"!][!VAR "cfgIndex" = "replace(node:name(.), 'CteOutputDefList_', '')"!]
Cte_SingleOutputDefType outputDefTable_[!"$cfgIndex"!][] = {[!IF "node:value('./CteOutputSignalList/CteOutputSignalSptUsage')='SPT_SIGNALS_NOT_USED'"!][!ELSE!]
    { CTE_OUTPUT_SPT_0,  [!"node:value('./CteOutputSignalList/CteOutputSignalSptUsage')"!], 0u},
    { CTE_OUTPUT_SPT_1,  [!"node:value('./CteOutputSignalList/CteOutputSignalSptUsage')"!], 0u},
    { CTE_OUTPUT_SPT_2,  [!"node:value('./CteOutputSignalList/CteOutputSignalSptUsage')"!], 0u},
    { CTE_OUTPUT_SPT_3,  [!"node:value('./CteOutputSignalList/CteOutputSignalSptUsage')"!], 0u},[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep0Usage')='CTEP0_NOT_USED'"!][!ELSE!]
    { CTE_OUTPUT_CTEP_0, [!"node:value('./CteOutputSignalList/CteOutputSignalCtep0Usage')"!], [!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep0Usage')='CTE_OUT_CLOCK'"!][!"node:value('./CteOutputSignalList/CteOutputSignalCtep0Clock')"!][!ELSE!]0[!ENDIF!]u},[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep1Usage')='CTEP1_NOT_USED'"!][!ELSE!]
    { CTE_OUTPUT_CTEP_1, [!"node:value('./CteOutputSignalList/CteOutputSignalCtep1Usage')"!], [!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep1Usage')='CTE_OUT_CLOCK'"!][!"node:value('./CteOutputSignalList/CteOutputSignalCtep1Clock')"!][!ELSE!]0[!ENDIF!]u},[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep2Usage')='CTEP2_NOT_USED'"!][!ELSE!]
    { CTE_OUTPUT_CTEP_2, [!"node:value('./CteOutputSignalList/CteOutputSignalCtep2Usage')"!], [!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep2Usage')='CTE_OUT_CLOCK'"!][!"node:value('./CteOutputSignalList/CteOutputSignalCtep2Clock')"!][!ELSE!]0[!ENDIF!]u},[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep3Usage')='CTEP3_NOT_USED'"!][!ELSE!]
    { CTE_OUTPUT_CTEP_3, [!"node:value('./CteOutputSignalList/CteOutputSignalCtep3Usage')"!], [!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep3Usage')='CTE_OUT_CLOCK'"!][!"node:value('./CteOutputSignalList/CteOutputSignalCtep3Clock')"!][!ELSE!]0[!ENDIF!]u},[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep4Usage')='CTEP4_NOT_USED'"!][!ELSE!]
    { CTE_OUTPUT_CTEP_4, [!"node:value('./CteOutputSignalList/CteOutputSignalCtep4Usage')"!], [!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep4Usage')='CTE_OUT_CLOCK'"!][!"node:value('./CteOutputSignalList/CteOutputSignalCtep4Clock')"!][!ELSE!]0[!ENDIF!]u},[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep5Usage')='CTEP5_NOT_USED'"!][!ELSE!]
    { CTE_OUTPUT_CTEP_5, [!"node:value('./CteOutputSignalList/CteOutputSignalCtep5Usage')"!], [!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep5Usage')='CTE_OUT_CLOCK'"!][!"node:value('./CteOutputSignalList/CteOutputSignalCtep5Clock')"!][!ELSE!]0[!ENDIF!]u},[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep6Usage')='CTEP6_NOT_USED'"!][!ELSE!]
    { CTE_OUTPUT_CTEP_6, [!"node:value('./CteOutputSignalList/CteOutputSignalCtep6Usage')"!], [!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep6Usage')='CTE_OUT_CLOCK'"!][!"node:value('./CteOutputSignalList/CteOutputSignalCtep6Clock')"!][!ELSE!]0[!ENDIF!]u},[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep7Usage')='CTEP7_NOT_USED'"!][!ELSE!]
    { CTE_OUTPUT_CTEP_7, [!"node:value('./CteOutputSignalList/CteOutputSignalCtep7Usage')"!], [!IF "node:value('./CteOutputSignalList/CteOutputSignalCtep7Usage')='CTE_OUT_CLOCK'"!][!"node:value('./CteOutputSignalList/CteOutputSignalCtep7Clock')"!][!ELSE!]0[!ENDIF!]u},[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalSptRfsUsage')='SPTRFS_NOT_USED'"!][!ELSE!] 
    { CTE_OUTPUT_SPT_RFS, [!"node:value('./CteOutputSignalList/CteOutputSignalSptRfsUsage')"!], 0u },[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalSptRcsUsage')='SPTRCS_NOT_USED'"!][!ELSE!] 
    { CTE_OUTPUT_SPT_RCS, [!"node:value('./CteOutputSignalList/CteOutputSignalSptRcsUsage')"!], 0u },[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalFlex0Usage')='FLEX0_NOT_USED'"!][!ELSE!] 
    { CTE_OUTPUT_FLEX_0, [!"node:value('./CteOutputSignalList/CteOutputSignalFlex0Usage')"!], 0u },[!ENDIF!][!IF "node:value('./CteOutputSignalList/CteOutputSignalFlex1Usage')='FLEX1_NOT_USED'"!][!ELSE!] 
    { CTE_OUTPUT_FLEX_1, [!"node:value('./CteOutputSignalList/CteOutputSignalFlex1Usage')"!], 0u },[!ENDIF!]
    { CTE_OUTPUT_MAX, CTE_OUT_LOGIC, 0u}
};[!ENDLOOP!]


/*
 * Time Tables Single Events Definitions [!// Second loop is for TimeTables Events
 */[!LOOP "/AUTOSAR/TOP-LEVEL-PACKAGES/Cte/ELEMENTS/Cte/CteTable/*"!][!VAR "cfgIndex" = "replace(node:name(.), 'CteTable_', '')"!][!LOOP "./CteTableEvent/*"!][!VAR "cfgIndexEv" = "replace(node:name(.), 'CteTableEvent_', '')"!]
Cte_ActionType table_[!"$cfgIndex"!]_Action_[!"$cfgIndexEv"!][] = {[!IF "node:value(./CteEventSPT_0State)!='SPT_0_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_SPT_0, {[!IF "text:concat('x', text:grep(node:value(./CteEventSPT_0State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventSPT_0State), '[A-Za-z_0-9]*HIGH_Z'))!='x'"!] CTE_LOGIC_SET_TO_HIGH_Z[!ELSE!] CTE_LOGIC_SET_TO_HIGH[!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventSPT_1State)!='SPT_1_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_SPT_1, {[!IF "text:concat('x', text:grep(node:value(./CteEventSPT_1State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventSPT_1State), '[A-Za-z_0-9]*HIGH_Z'))!='x'"!] CTE_LOGIC_SET_TO_HIGH_Z[!ELSE!] CTE_LOGIC_SET_TO_HIGH[!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventSPT_2State)!='SPT_2_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_SPT_2, {[!IF "text:concat('x', text:grep(node:value(./CteEventSPT_2State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventSPT_2State), '[A-Za-z_0-9]*HIGH_Z'))!='x'"!] CTE_LOGIC_SET_TO_HIGH_Z[!ELSE!] CTE_LOGIC_SET_TO_HIGH[!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventSPT_3State)!='SPT_3_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_SPT_3, {[!IF "text:concat('x', text:grep(node:value(./CteEventSPT_3State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventSPT_3State), '[A-Za-z_0-9]*HIGH_Z'))!='x'"!] CTE_LOGIC_SET_TO_HIGH_Z[!ELSE!] CTE_LOGIC_SET_TO_HIGH[!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventCTEP_0State)!='CTEP_0_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_CTEP_0, {[!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_0State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_0State), '[A-Za-z_0-9]*ACTIVE_SYNC'))!='x'"!] CTE_CLOCK_ACTIVE_SYNC[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_0State), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_SET_TO_HIGH[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventCTEP_1State)!='CTEP_1_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_CTEP_1, {[!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_1State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_1State), '[A-Za-z_0-9]*ACTIVE_SYNC'))!='x'"!] CTE_CLOCK_ACTIVE_SYNC[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_1State), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_SET_TO_HIGH[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventCTEP_2State)!='CTEP_2_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_CTEP_2, {[!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_2State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_2State), '[A-Za-z_0-9]*ACTIVE_SYNC'))!='x'"!] CTE_CLOCK_ACTIVE_SYNC[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_2State), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_SET_TO_HIGH[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventCTEP_3State)!='CTEP_3_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_CTEP_3, {[!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_3State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_3State), '[A-Za-z_0-9]*ACTIVE_SYNC'))!='x'"!] CTE_CLOCK_ACTIVE_SYNC[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_3State), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_SET_TO_HIGH[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventCTEP_4State)!='CTEP_4_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_CTEP_4, {[!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_4State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_4State), '[A-Za-z_0-9]*ACTIVE_SYNC'))!='x'"!] CTE_CLOCK_ACTIVE_SYNC[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_4State), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_SET_TO_HIGH[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventCTEP_5State)!='CTEP_5_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_CTEP_5, {[!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_5State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_5State), '[A-Za-z_0-9]*ACTIVE_SYNC'))!='x'"!] CTE_CLOCK_ACTIVE_SYNC[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_5State), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_SET_TO_HIGH[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventCTEP_6State)!='CTEP_6_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_CTEP_6, {[!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_6State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_6State), '[A-Za-z_0-9]*ACTIVE_SYNC'))!='x'"!] CTE_CLOCK_ACTIVE_SYNC[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_6State), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_SET_TO_HIGH[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventCTEP_7State)!='CTEP_7_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_CTEP_7, {[!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_7State), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_7State), '[A-Za-z_0-9]*ACTIVE_SYNC'))!='x'"!] CTE_CLOCK_ACTIVE_SYNC[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventCTEP_7State), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_SET_TO_HIGH[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventSPT_RCSState)!='SPT_RCS_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_SPT_RCS, {[!IF "text:concat('x', text:grep(node:value(./CteEventSPT_RCSState), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventSPT_RCSState), '[A-Za-z_0-9]*TO_HIGH'))!='x'"!] CTE_LOGIC_SET_TO_HIGH[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventSPT_RCSState), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_ACTIVE_SYNC[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!][!IF "node:value(./CteEventSPT_RFSState)!='SPT_RFS_NOT_CHANGED_or_NOT_USED'"!]
    { CTE_OUTPUT_SPT_RFS, {[!IF "text:concat('x', text:grep(node:value(./CteEventSPT_RFSState), '[A-Za-z_0-9]*TO_LOW'))!='x'"!] CTE_LOGIC_SET_TO_LOW[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventSPT_RFSState), '[A-Za-z_0-9]*TO_HIGH'))!='x'"!] CTE_LOGIC_SET_TO_HIGH[!ELSE!][!IF "text:concat('x', text:grep(node:value(./CteEventSPT_RFSState), '[A-Za-z_0-9]*CLOCK_ACTIVE'))!='x'"!] CTE_CLOCK_ACTIVE[!ELSE!] CTE_CLOCK_ACTIVE_SYNC[!ENDIF!][!ENDIF!][!ENDIF!]}},[!ENDIF!]
    { CTE_OUTPUT_MAX, {CTE_OUT_LOGIC}}
};
[!ENDLOOP!][!ENDLOOP!]

/*
 * Time Tables Events Definitions [!// Third loop is for Time Tables
 */[!LOOP "/AUTOSAR/TOP-LEVEL-PACKAGES/Cte/ELEMENTS/Cte/CteTable/*"!][!VAR "cfgIndex" = "replace(node:name(.), 'CteTable_', '')"!][!VAR "evtCount" = "count(./CteTableEvent/*)"!][!VAR "lastTime" = "0"!]
Cte_TimingEventType listEventsTable_[!"$cfgIndex"!][] = {[!LOOP "./CteTableEvent/*"!][!VAR "cfgIndexEv" = "replace(node:name(.), 'CteTableEvent_', '')"!][!VAR "crtTime" = "node:value(./CteEventTime)"!][!IF "$lastTime<$crtTime"!][!VAR "lastTime" = "$crtTime"!][!IF "$cfgIndexEv!='0'"!],[!ENDIF!]
    {[!"$crtTime"!]u, table_[!"$cfgIndex"!]_Action_[!"$cfgIndexEv"!]}[!ELSE!]
    #error "Events not in correct order"[!ENDIF!][!ENDLOOP!]    
};
[!ENDLOOP!]

/*
 * Time Tables Definitions [!// Third loop is for Time Tables
 */[!LOOP "/AUTOSAR/TOP-LEVEL-PACKAGES/Cte/ELEMENTS/Cte/CteTable/*"!][!VAR "cfgIndex" = "replace(node:name(.), 'CteTable_', '')"!][!VAR "evtCount" = "count(./CteTableEvent/*)"!]
Cte_TimeTableDefType timeTable_[!"$cfgIndex"!] = {
    [!"replace(string($evtCount), '.0', '')"!]u,
    [!"node:value(concat($CteCfgPath, '/CteTable/CteTable_', string($cfgIndex), '/CteTableTimeLimit'))"!]u,
    listEventsTable_[!"$cfgIndex"!]
};
[!ENDLOOP!]

[!//"node:name(.)"!]_[!"$cfgIndex"!]_[!"$cfgIndexEv"!]

/*
 * Complete CTE configurations
 */[!// Final loop, for time table configurations
[!LOOP "/AUTOSAR/TOP-LEVEL-PACKAGES/Cte/ELEMENTS/Cte/CteFinalConfig/*"!]
[!VAR "cfgIndex" = "replace(node:name(.), 'CteFinalConfig_', '')"!]
[!VAR "workMode" = "node:value(./CteWorkingSetup/CteWorkingMode)"!]

Cte_SetupParamsType cteSetupParam_[!"$cfgIndex"!] = {
    .cteClockFrecq = [!"node:value(./CteConfigClockFreq)"!]u,
    .cteMode = { [!"$workMode"!], [!IF "$workMode='CTE_SLAVE_CSI2'"!]{ .cteCsi2Unit = [!"node:value(./CteWorkingSetup/CteWorkingSlaveCsi2Unit)"!]}, { .cteCsi2Vc = [!"node:value(./CteWorkingSetup/CteWorkingSlaveCsi2Vc)"!]}[!ELSE!]{ .cteInternalRfsDelay = [!"node:value(./CteWorkingSetup/CteInternalRfsDelay)"!]}, { .cteInternalRcsDelay = [!"node:value(./CteWorkingSetup/CteInternalRcsDelay)"!]}[!ENDIF!]},
    .repeatCount = [!"node:value(./CteTableConfig/CteConfigTableLoop)"!]u,
    .signalDef0Ptr = outputDefTable_[!"node:value(./CteTableConfig/CteConfigOutput0)"!],
    .signalDef1Ptr = [!IF "node:value(./CteTableConfig/CteConfigTable1)>=0"!]outputDefTable_[!"node:value(./CteTableConfig/CteConfigOutput1)"!][!ELSE!]NULL_PTR[!ENDIF!],
    .timeTable0Ptr = &timeTable_[!"node:value(./CteTableConfig/CteConfigTable0)"!],
    .timeTable1Ptr = [!IF "node:value(./CteTableConfig/CteConfigTable1)>=0"!]&timeTable_[!"node:value(./CteTableConfig/CteConfigTable1)"!][!ELSE!]NULL_PTR[!ENDIF!],
    .cteIrqEvents = 0u[!IF "node:value(./CteEventsSetup/CteEventTT0Start)"!] | (CTE_IRQ_TT0_START)[!ENDIF!][!IF "node:value(./CteEventsSetup/CteEventTT1Start)"!] | (CTE_IRQ_TT1_START)[!ENDIF!][!IF "node:value(./CteEventsSetup/CteEventTT0Stop)"!] | (CTE_IRQ_TT0_END)[!ENDIF!][!IF "node:value(./CteEventsSetup/CteEventTT1Stop)"!] | (CTE_IRQ_TT1_END)[!ENDIF!][!IF "node:value(./CteEventsSetup/CteEventRFS)"!] | (CTE_IRQ_RFS)[!ENDIF!][!IF "node:value(./CteEventsSetup/CteEventRCS)"!] | (CTE_IRQ_RCS)[!ENDIF!][!IF "node:value(./CteEventsSetup/CteEventEnd)"!] | (CTE_IRQ_TABLE_EXEC_END)[!ENDIF!]
};
[!ENDLOOP!]
