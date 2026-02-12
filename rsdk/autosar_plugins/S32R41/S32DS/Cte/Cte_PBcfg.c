/*==================================================================================================
 * Copyright 2022-2024 NXP Semiconductors
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

#include "Cte_Types.h"
 
[!
/*  Variable defintions to be used for the code generation  */
var configSet            = this[0];
var CteGeneral           = configSet.getChildById("CteDriverCodeParameters").getChildById("CteGeneralConfiguration");
var CteOutputList        = configSet.getChildById("CteOutputConfigurationList").getChildById("CteDriverMainContainer");
var CteFinalConfigTable  = configSet.getChildById("CteFinalConfig").getChildById("CteDriverFinalConfigContainer");
var outputConfigList = [];



    /*********************** START - Output Definition ***********************/


    for each (var node in CteOutputList.getChildren())
    {
        var cteOutputSignalStructure_Name = node.getChild("CteOutputConfigName").getValue();
        outputConfigList.push(cteOutputSignalStructure_Name)
        var cteOutput_SptUsage = node.getChild("CteOutputSignalUsage").getChild("CteSptSignalUsage").getValue();
        
        var cteOutput_Ctep0Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep0Usage").getValue();
        var cteOutput_Ctep0Clock = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep0Clock").getValue();
        
        var cteOutput_Ctep1Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep1Usage").getValue();
        var cteOutput_Ctep1Clock = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep1Clock").getValue();
        
        var cteOutput_Ctep2Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep2Usage").getValue();
        var cteOutput_Ctep2Clock = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep2Clock").getValue();
        
        var cteOutput_Ctep3Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep3Usage").getValue();
        var cteOutput_Ctep3Clock = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep3Clock").getValue();
        
        var cteOutput_Ctep4Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep4Usage").getValue();
        var cteOutput_Ctep4Clock = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep4Clock").getValue();
        
        var cteOutput_Ctep5Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep5Usage").getValue();
        var cteOutput_Ctep5Clock = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep5Clock").getValue();
        
        var cteOutput_Ctep6Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep6Usage").getValue();
        var cteOutput_Ctep6Clock = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep6Clock").getValue();
        
        var cteOutput_Ctep7Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep7Usage").getValue();
        var cteOutput_Ctep7Clock = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalCtep7Clock").getValue();
        
        var cteOutput_SptRcsUsage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalSptRcsUsage").getValue();
        var cteOutput_SptRfsUsage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalSptRfsUsage").getValue();
        var cteOutput_Flex0Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalFlex0Usage").getValue();
        var cteOutput_Flex1Usage = node.getChild("CteOutputSignalUsage").getChild("CteOutputSignalFlex1Usage").getValue();
        

<code>
/*
 * Output Configuration $(outputConfigList.length-1)$
 */
Cte_SingleOutputDefType $cteOutputSignalStructure_Name$[] = {
</code>

        if(cteOutput_SptUsage != "SPT_SIGNALS_NOT_USED")
        {
<code>
    { CTE_OUTPUT_SPT_0, $cteOutput_SptUsage$, 0u },
    { CTE_OUTPUT_SPT_1, $cteOutput_SptUsage$, 0u },
    { CTE_OUTPUT_SPT_2, $cteOutput_SptUsage$, 0u },
    { CTE_OUTPUT_SPT_3, $cteOutput_SptUsage$, 0u },
</code>
        }
        
        
        if(cteOutput_Ctep0Usage != "CTEP0_NOT_USED")
        {
            if(cteOutput_Ctep0Usage == "CTE_OUT_CLOCK")
            {
<code>
    { CTE_OUTPUT_CTEP_0, $cteOutput_Ctep0Usage$, $cteOutput_Ctep0Clock$u },
</code>
            }
            else
            {
<code>
    { CTE_OUTPUT_CTEP_0, $cteOutput_Ctep0Usage$, 0u },
</code>
            }
        }
        
        
        if(cteOutput_Ctep1Usage != "CTEP1_NOT_USED")
        {
            if(cteOutput_Ctep1Usage == "CTE_OUT_CLOCK")
            {
<code>
    { CTE_OUTPUT_CTEP_1, $cteOutput_Ctep1Usage$, $cteOutput_Ctep1Clock$u },
</code>
            }
            else
            {
<code>
    { CTE_OUTPUT_CTEP_1, $cteOutput_Ctep1Usage$, 0u },
</code>
            }
        }


        if(cteOutput_Ctep2Usage != "CTEP2_NOT_USED")
        {
            if(cteOutput_Ctep2Usage == "CTE_OUT_CLOCK")
            {
<code>
    { CTE_OUTPUT_CTEP_2, $cteOutput_Ctep2Usage$, $cteOutput_Ctep2Clock$u },
</code>
            }
            else
            {
<code>
    { CTE_OUTPUT_CTEP_2, $cteOutput_Ctep2Usage$, 0u },
</code>
            }
        }


        if(cteOutput_Ctep3Usage != "CTEP3_NOT_USED")
        {
            if(cteOutput_Ctep3Usage == "CTE_OUT_CLOCK")
            {
<code>
    { CTE_OUTPUT_CTEP_3, $cteOutput_Ctep3Usage$, $cteOutput_Ctep3Clock$u },
</code>
            }
            else
            {
<code>
    { CTE_OUTPUT_CTEP_3, $cteOutput_Ctep3Usage$, 0u },
</code>
            }
        }


        if(cteOutput_Ctep4Usage != "CTEP4_NOT_USED")
        {
            if(cteOutput_Ctep4Usage == "CTE_OUT_CLOCK")
            {
<code>
    { CTE_OUTPUT_CTEP_4, $cteOutput_Ctep4Usage$, $cteOutput_Ctep4Clock$u },
</code>
            }
            else
            {
<code>
    { CTE_OUTPUT_CTEP_4, $cteOutput_Ctep4Usage$, 0u },
</code>
            }
        }


        if(cteOutput_Ctep5Usage != "CTEP5_NOT_USED")
        {
            if(cteOutput_Ctep5Usage == "CTE_OUT_CLOCK")
            {
<code>
    { CTE_OUTPUT_CTEP_5, $cteOutput_Ctep5Usage$, $cteOutput_Ctep5Clock$u },
</code>
            }
            else
            {
<code>
    { CTE_OUTPUT_CTEP_5, $cteOutput_Ctep5Usage$, 0u },
</code>
            }
        }


        if(cteOutput_Ctep6Usage != "CTEP6_NOT_USED")
        {
            if(cteOutput_Ctep6Usage == "CTE_OUT_CLOCK")
            {
<code>
    { CTE_OUTPUT_CTEP_6, $cteOutput_Ctep6Usage$, $cteOutput_Ctep6Clock$u },
</code>
            }
            else
            {
<code>
    { CTE_OUTPUT_CTEP_6, $cteOutput_Ctep6Usage$, 0u },
</code>
            }
        }


        if(cteOutput_Ctep7Usage != "CTEP7_NOT_USED")
        {
            if(cteOutput_Ctep7Usage == "CTE_OUT_CLOCK")
            {
<code>
    { CTE_OUTPUT_CTEP_7, $cteOutput_Ctep7Usage$, $cteOutput_Ctep7Clock$u },
</code>
            }
            else
            {
<code>
    { CTE_OUTPUT_CTEP_7, $cteOutput_Ctep7Usage$, 0u },
</code>
            }
        }


        if(cteOutput_SptRcsUsage != "SPTRCS_NOT_USED")
        {
<code>
    { CTE_OUTPUT_SPT_RCS, $cteOutput_SptRcsUsage$, 0u },
</code>
        }


        if(cteOutput_SptRfsUsage != "SPTRFS_NOT_USED")
        {
<code>
    { CTE_OUTPUT_SPT_RFS, $cteOutput_SptRfsUsage$, 0u },
</code>
        }


        if(cteOutput_Flex0Usage != "FLEX0_NOT_USED")
        {
<code>
    { CTE_OUTPUT_FLEX_0, $cteOutput_Flex0Usage$, 0u },
</code>
        }


        if(cteOutput_Flex1Usage != "FLEX1_NOT_USED")
        {
<code>
    { CTE_OUTPUT_FLEX_1, $cteOutput_Flex1Usage$, 0u },
</code>
        }

<code>
    { CTE_OUTPUT_MAX, CTE_OUT_LOGIC, 0u }
</code>

<code>
};

</code>
    }
    /*********************** END - Output Definition ***********************/
    
    
    /*********************** START - Actions Definitions ***********************/
    
/*var CteOutputList        = configSet.getChildById("CteOutputConfigurationList").getChildById("CteDriverMainContainer");*/

<code>
/*
 * Time Tables Single Events Definitions 
 */
</code>

    for each (var nodeO in CteOutputList.getChildren())
    {
        var CteTimeTableList = nodeO.getChildById("CteOutputSignalUsage").getChildById("CteDriverTimeTableContainer");
        
        for each (var nodeT in CteTimeTableList.getChildren())
        {
            var CteEventList = nodeT.getChildById("CteDriverEventsContainer");

            for each (var nodeE in CteEventList.getChildren())
            {
                var CteActionList = nodeE.getChildById("CteDriverActionsContainer");
<code>
Cte_ActionType $nodeE.getChildById("CteActionsConfigName").getValue()$[] = {
</code>
                for each (var nodeA in CteActionList.getChildren())
                {
                    
                    if(nodeA.getChildById("CteOutputSignalToggleType").isAvailable())
                    {
<code>
    { $nodeA.getChildById("CteActionsOutputType").getValue()$, { $nodeA.getChildById("CteOutputSignalToggleType").getValue()$ }},
</code>
                    }
                    else if(nodeA.getChildById("CteOutputSignalLogicType").isAvailable())
                    {
<code>
    { $nodeA.getChildById("CteActionsOutputType").getValue()$, { $nodeA.getChildById("CteOutputSignalLogicType").getValue()$ }},
</code>
                    }
                    else if(nodeA.getChildById("CteOutputSignalClockType").isAvailable())
                    {
<code>
    { $nodeA.getChildById("CteActionsOutputType").getValue()$, { $nodeA.getChildById("CteOutputSignalClockType").getValue()$ }},
</code>
                    }
                    else
                    {
<code>
    { $nodeA.getChildById("CteActionsOutputType").getValue()$, { $nodeA.getChildById("CteOutputSignalHIZType").getValue()$ }},
</code>
                    }
                }
<code>
    { CTE_OUTPUT_MAX, {CTE_OUT_LOGIC}}
};

</code>
            }
        }
        
    }

    /*********************** END - Actions Definitions ***********************/


    /*********************** START - Event List Definitions ***********************/
    
    /*var CteOutputList        = configSet.getChildById("CteOutputConfigurationList").getChildById("CteDriverMainContainer");*/
    var idx_ListEvents = 0;
    var idx_Actions = 0;

<code>
/*
 * Time Tables Events Definitions 
 */
</code>
    for each (var nodeO in CteOutputList.getChildren())
    {
        var CteTimeTableList = nodeO.getChildById("CteOutputSignalUsage").getChildById("CteDriverTimeTableContainer");
        
        for each (var nodeT in CteTimeTableList.getChildren())
        {
            var CteEventList = nodeT.getChildById("CteDriverEventsContainer");
            
<code>
Cte_TimingEventType listEventsTable_$idx_ListEvents$[] = {
</code>
            
            idx_Actions = 0;
            
            for each (var nodeE in CteEventList.getChildren())
            {
                if( idx_Actions < (CteEventList.getChildren().length - 1))
                {
<code>
    {$nodeE.getChildById("CteActionExecTime").getValue()$, table_$idx_ListEvents$_Action_$idx_Actions$},
</code>
                }
                else
                {
<code>
    {$nodeE.getChildById("CteActionExecTime").getValue()$, table_$idx_ListEvents$_Action_$idx_Actions$}
</code>
                }
                idx_Actions++;
            }
            idx_ListEvents++;
<code>
};

</code>
        }
    }
    
    /*********************** END - Event List Definitions ***********************/
    
    /*********************** START - Time Table Definitions ***********************/
    
    /*var CteOutputList        = configSet.getChildById("CteOutputConfigurationList").getChildById("CteDriverMainContainer");*/
    var idx_TimeTable = 0;
    var idx_Actions = 0;

<code>
/*
 * Time Tables Definitions 
 */
</code>

    for each (var nodeO in CteOutputList.getChildren())
    {
        var CteTimeTableList = nodeO.getChildById("CteOutputSignalUsage").getChildById("CteDriverTimeTableContainer");
        
        for each (var nodeT in CteTimeTableList.getChildren())
        {
            var CteEventList = nodeT.getChildById("CteDriverEventsContainer");
            
<code>
Cte_TimeTableDefType timeTable_$idx_TimeTable$ = {
</code>
            
            idx_Actions = 0;
            
            for each (var nodeE in CteEventList.getChildren())
            {
                idx_Actions++;
            }
<code>
    $idx_Actions$u,
    $nodeT.getChildById("CteTimeTableMaxExecTime").getValue()$u,
    listEventsTable_$idx_TimeTable$
</code>
            idx_TimeTable++;
<code>
};

</code>
        }
    }
    
    /*********************** END - Event List Definitions ***********************/
    
    /*********************** START - Time Table Definitions ***********************/


    for each (var nodeC in CteFinalConfigTable.getChildren())
    {
<code>
/*
 * Complete CTE configurations
 */

Cte_SetupParamsType $nodeC.getChildById("CteConfigName").getValue()$ = {
    .cteClockFrecq = $nodeC.getChildById("CteConfigClockFreq").getValue()$u,
</code>
        if(nodeC.getChildById("CteWorkingSetup").getValue() != "CTE_SLAVE_CSI2")
        {
<code>
    .cteMode = { $nodeC.getChildById("CteWorkingSetup").getValue()$, { .cteInternalRfsDelay = $nodeC.getChildById("CteInternalRfsDelay").getValue()$}, { .cteInternalRcsDelay = $nodeC.getChildById("CteInternalRcsDelay").getValue()$}},
</code>
        }
        else
        {
<code>
    .cteMode = { $nodeC.getChildById("CteWorkingSetup").getValue()$, { .cteCsi2Unit = $nodeC.getChildById("CteWorkingSlaveCsi2Unit").getValue()$}, { .cteCsi2Vc = $nodeC.getChildById("CteWorkingSlaveCsi2UnitVc").getValue()$}},
</code>
        }
<code>
    .repeatCount = $nodeC.getChildById("CteRepeatCount").getValue()$u,
    .signalDef0Ptr = $nodeC.getChildById("CteSignalDefPtr0").getValue()$,
    .signalDef1Ptr = $nodeC.getChildById("CteSignalDefPtr1").getValue()$,
    .timeTable0Ptr = &$nodeC.getChildById("CteTimeTablePtr0").getValue()$,
    .timeTable1Ptr = $nodeC.getChildById("CteSignalDefPtr1").getValue() == "NULL_PTR" ? "NULL_PTR" : "&" + nodeC.getChildById("CteTimeTablePtr1").getValue()$,
    .cteIrqEvents = 0u$(nodeC.getChild("CteEventTT0Start").getValue()) ? " | (CTE_IRQ_TT0_START)":""$</code>
                <code>$(nodeC.getChild("CteEventTT0Stop").getValue()) ? " | (CTE_IRQ_TT0_END)":""$</code>
                <code>$(nodeC.getChild("CteEventTT1Start").getValue()) ? " | (CTE_IRQ_TT1_START)":""$</code>
                <code>$(nodeC.getChild("CteEventTT1Stop").getValue()) ? " | (CTE_IRQ_TT1_END)":""$</code>
                <code>$(nodeC.getChild("CteEventRFS").getValue()) ? " | (CTE_IRQ_RFS)":""$</code>
                <code>$(nodeC.getChild("CteEventRCS").getValue()) ? " | (CTE_IRQ_RCS)":""$</code>
                <code>$(nodeC.getChild("CteEventEnd").getValue()) ? " | (CTE_IRQ_TABLE_EXEC_END)":""$</code>
<code>

};

</code>
    }
    /*********************** END - Event List Definitions ***********************/
 !]