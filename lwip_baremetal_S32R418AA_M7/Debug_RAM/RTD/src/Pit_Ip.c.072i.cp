
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03/39:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03/38:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09/37:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09/36:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01/35:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01/34:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02/33:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02/32:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00/31:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00/30:
  Jump functions of caller  PIT_0_ISR/29:
    callsite  PIT_0_ISR/29 -> Pit_Ip_ProcessCommonInterrupt/18 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 7]
  Jump functions of caller  Pit_Ip_GetLifetimeTimer/28:
  Jump functions of caller  Pit_Ip_SetLifetimeTimer/27:
    callsite  Pit_Ip_SetLifetimeTimer/27 -> Pit_Ip_EnableTimer/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_SetLifetimeTimer/27 -> Pit_Ip_EnableTimer/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_SetLifetimeTimer/27 -> Pit_Ip_SetChainMode/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_SetLifetimeTimer/27 -> Pit_Ip_SetEnableInterruptFlag/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Pit_Ip_DisableChannelInterrupt/26:
    callsite  Pit_Ip_DisableChannelInterrupt/26 -> Pit_Ip_ClearInterruptStatusFlag/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Pit_Ip_DisableChannelInterrupt/26 -> Pit_Ip_SetEnableInterruptFlag/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Pit_Ip_EnableChannelInterrupt/25:
    callsite  Pit_Ip_EnableChannelInterrupt/25 -> Pit_Ip_SetEnableInterruptFlag/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_EnableChannelInterrupt/25 -> Pit_Ip_ClearInterruptStatusFlag/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Pit_Ip_GetCurrentTimer/24:
  Jump functions of caller  Pit_Ip_StopChannel/23:
    callsite  Pit_Ip_StopChannel/23 -> Pit_Ip_ClearInterruptStatusFlag/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Pit_Ip_StopChannel/23 -> Pit_Ip_EnableTimer/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Pit_Ip_StartChannel/22:
    callsite  Pit_Ip_StartChannel/22 -> Pit_Ip_EnableTimer/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  Pit_Ip_Deinit/21:
    callsite  Pit_Ip_Deinit/21 -> Pit_Ip_Reset/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 7]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_InitChannel/20:
    callsite  Pit_Ip_InitChannel/20 -> Pit_Ip_ClearInterruptStatusFlag/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Pit_Ip_InitChannel/20 -> Pit_Ip_SetEnableInterruptFlag/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_InitChannel/20 -> Pit_Ip_EnableTimer/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Pit_Ip_Init/19:
    callsite  Pit_Ip_Init/19 -> Pit_Ip_SetDebugMode/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_Init/19 -> Pit_Ip_EnableModule/4 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Pit_Ip_ProcessCommonInterrupt/18:
    callsite  Pit_Ip_ProcessCommonInterrupt/18 -> Pit_Ip_StopChannel/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Pit_Ip_ProcessCommonInterrupt/18 -> Pit_Ip_ClearInterruptStatusFlag/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt callback_11 (callbackParam_13);
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Pit_Ip_ClearInterruptStatusFlag/13:
  Jump functions of caller  Pit_Ip_SetEnableInterruptFlag/12:
  Jump functions of caller  Pit_Ip_Reset/8:
  Jump functions of caller  Pit_Ip_SetChainMode/7:
  Jump functions of caller  Pit_Ip_SetDebugMode/6:
  Jump functions of caller  Pit_Ip_EnableTimer/5:
  Jump functions of caller  Pit_Ip_EnableModule/4:
  Jump functions of caller  Pit_Ip_GetLoadValue/3:

 Propagating constants:

Not considering PIT_0_ISR for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_GetLifetimeTimer for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_SetLifetimeTimer for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_DisableChannelInterrupt for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_EnableChannelInterrupt for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_GetCurrentTimer for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_StopChannel for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_StartChannel for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_Deinit for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_InitChannel for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_Init for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_GetLoadValue for cloning; -fipa-cp-clone disabled.

overall_size: 286, max_new_size: 11001
 - context independent values, size: 38, time_benefit: 51.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 13, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 7, time_benefit: 53.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 6, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: PIT_0_ISR/29:
  Node: Pit_Ip_GetLifetimeTimer/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_SetLifetimeTimer/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_DisableChannelInterrupt/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_EnableChannelInterrupt/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_GetCurrentTimer/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_StopChannel/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_StartChannel/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_Deinit/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_InitChannel/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_Init/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_ProcessCommonInterrupt/18:
    param [0]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint8 [0, 7]
        AGGS VARIABLE
  Node: Pit_Ip_ClearInterruptStatusFlag/13:
    param [0]: VARIABLE
               0 [loc_time: 49, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Pit_Ip_SetEnableInterruptFlag/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               1 [loc_time: 49, loc_size: 15, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 1 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
               0 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         boolean [0, 1]
        AGGS VARIABLE
  Node: Pit_Ip_Reset/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint8 [0, 7]
        AGGS VARIABLE
    param [2]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         boolean [0, 0]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Pit_Ip_SetChainMode/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         uint8 [1, 1]
        AGGS VARIABLE
    param [2]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         boolean [1, 1]
        AGGS VARIABLE
  Node: Pit_Ip_SetDebugMode/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Pit_Ip_EnableTimer/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               1 [loc_time: 49, loc_size: 15, prop_time: 0, prop_size: 0]
               0 [loc_time: 49, loc_size: 15, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 0 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         boolean [0, 1]
        AGGS VARIABLE
  Node: Pit_Ip_EnableModule/4:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
  Node: Pit_Ip_GetLoadValue/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:

 - Creating a specialized node of Pit_Ip_ProcessCommonInterrupt/18 for all known contexts.
    replacing param #0 instance with const 0
 - Creating a specialized node of Pit_Ip_Reset/8 for all known contexts.
    replacing param #2 available with const 0
 - Creating a specialized node of Pit_Ip_SetChainMode/7 for all known contexts.
    replacing param #1 channel with const 1
    replacing param #2 enable with const 1
 - Creating a specialized node of Pit_Ip_EnableModule/4 for all known contexts.
    replacing param #1 timerType with const 0
Propagated bits info for function Pit_Ip_EnableModule.constprop/46:
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function Pit_Ip_SetChainMode.constprop/45:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x1, mask = 0x0
Propagated bits info for function Pit_Ip_Reset.constprop/44:
 param 1: value = 0x0, mask = 0x7
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function Pit_Ip_ProcessCommonInterrupt.constprop/43:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x0, mask = 0x7
Propagated bits info for function Pit_Ip_ProcessCommonInterrupt/18:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x0, mask = 0x7
Propagated bits info for function Pit_Ip_Reset/8:
 param 1: value = 0x0, mask = 0x7
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function Pit_Ip_SetChainMode/7:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x1, mask = 0x0
Propagated bits info for function Pit_Ip_EnableModule/4:
 param 1: value = 0x0, mask = 0x0

IPA constant propagation end

Reclaiming functions: Pit_Ip_ProcessCommonInterrupt/18 Pit_Ip_Reset/8 Pit_Ip_SetChainMode/7 Pit_Ip_EnableModule/4
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Pit_Ip_EnableModule.constprop.0/46 (Pit_Ip_EnableModule.constprop) @061f88c0
  Type: function definition analyzed
  Visibility:
  References: pitBase/1 (read)
  Referring: 
  Clone of Pit_Ip_EnableModule/4
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Pit_Ip_Init/19 (248034361 (estimated locally),0.23 per call) 
  Calls: 
Pit_Ip_SetChainMode.constprop.0/45 (Pit_Ip_SetChainMode.constprop) @061f8620
  Type: function definition analyzed
  Visibility:
  References: pitBase/1 (read)pitBase/1 (read)
  Referring: 
  Clone of Pit_Ip_SetChainMode/7
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Pit_Ip_SetLifetimeTimer/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01/34 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01/35 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_Reset.constprop.0/44 (Pit_Ip_Reset.constprop) @061f89a0
  Type: function definition analyzed
  Visibility:
  References: pitBase/1 (read)pitBase/1 (read)
  Referring: 
  Clone of Pit_Ip_Reset/8
  Availability: local
  Function flags: count:134217728 (estimated locally) local optimize_size
  Called by: Pit_Ip_Deinit/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Pit_Ip_ProcessCommonInterrupt.constprop.0/43 (Pit_Ip_ProcessCommonInterrupt.constprop) @061f8460
  Type: function definition analyzed
  Visibility:
  References: pitBase/1 (read)Pit_Ip_u32ChState/2 (read)Pit_Ip_u32ChState/2 (read)Pit_Ip_u32ChState/2 (read)Pit_Ip_u32ChState/2 (read)
  Referring: 
  Clone of Pit_Ip_ProcessCommonInterrupt/18
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: PIT_0_ISR/29 (939524097 (estimated locally),7.00 per call) 
  Calls: SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03/38 (177167401 (estimated locally),0.17 per call) Pit_Ip_ClearInterruptStatusFlag/13 (29232621 (estimated locally),0.03 per call) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03/39 (177167401 (estimated locally),0.17 per call) Pit_Ip_StopChannel/23 (8964670 (estimated locally),0.01 per call) 
   Indirect call(15502148 (estimated locally),0.01 per call) 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03/39 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03) @0610b8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_ProcessCommonInterrupt.constprop/43 (177167401 (estimated locally),0.17 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03/38 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03) @0610b7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_ProcessCommonInterrupt.constprop/43 (177167401 (estimated locally),0.17 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09/37 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09) @0610b380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_GetLifetimeTimer/28 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09/36 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09) @0610b2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_GetLifetimeTimer/28 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01/35 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01) @0610b0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_SetChainMode.constprop/45 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01/34 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01) @0610b000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_SetChainMode.constprop/45 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02/33 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02) @060fe380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_SetEnableInterruptFlag/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02/32 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02) @060fe2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_SetEnableInterruptFlag/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00/31 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00) @060fe0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_EnableTimer/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00/30 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00) @060fe000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_EnableTimer/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
PIT_0_ISR/29 (PIT_0_ISR) @060f39a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:134217728 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_ProcessCommonInterrupt.constprop/43 (939524097 (estimated locally),7.00 per call) 
Pit_Ip_GetLifetimeTimer/28 (Pit_Ip_GetLifetimeTimer) @060f3700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09/37 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09/36 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_SetLifetimeTimer/27 (Pit_Ip_SetLifetimeTimer) @060f3460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_EnableTimer/5 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableTimer/5 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetChainMode.constprop/45 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetEnableInterruptFlag/12 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_DisableChannelInterrupt/26 (Pit_Ip_DisableChannelInterrupt) @060f31c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_ClearInterruptStatusFlag/13 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetEnableInterruptFlag/12 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_EnableChannelInterrupt/25 (Pit_Ip_EnableChannelInterrupt) @060e4d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_SetEnableInterruptFlag/12 (1073741824 (estimated locally),1.00 per call) Pit_Ip_ClearInterruptStatusFlag/13 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_GetCurrentTimer/24 (Pit_Ip_GetCurrentTimer) @060e47e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_StopChannel/23 (Pit_Ip_StopChannel) @060e42a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Pit_Ip_ProcessCommonInterrupt.constprop/43 (8964670 (estimated locally),0.01 per call) 
  Calls: Pit_Ip_ClearInterruptStatusFlag/13 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableTimer/5 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_StartChannel/22 (Pit_Ip_StartChannel) @060e4ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_EnableTimer/5 (354334802 (estimated locally),0.33 per call) 
Pit_Ip_Deinit/21 (Pit_Ip_Deinit) @060e4c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_Reset.constprop/44 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_InitChannel/20 (Pit_Ip_InitChannel) @060e49a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/1 (read)Pit_Ip_u32ChState/2 (write)Pit_Ip_u32ChState/2 (write)Pit_Ip_u32ChState/2 (write)Pit_Ip_u32ChState/2 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_ClearInterruptStatusFlag/13 (574129754 (estimated locally),0.53 per call) Pit_Ip_SetEnableInterruptFlag/12 (574129754 (estimated locally),0.53 per call) Pit_Ip_EnableTimer/5 (574129754 (estimated locally),0.53 per call) 
Pit_Ip_Init/19 (Pit_Ip_Init) @060e4700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_SetDebugMode/6 (751619278 (estimated locally),0.70 per call) Pit_Ip_EnableModule.constprop/46 (248034361 (estimated locally),0.23 per call) 
Pit_Ip_ProcessCommonInterrupt/18 (Pit_Ip_ProcessCommonInterrupt) @060e4460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_ClearInterruptStatusFlag/13 (Pit_Ip_ClearInterruptStatusFlag) @061f8e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pitBase/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Pit_Ip_ProcessCommonInterrupt.constprop/43 (29232621 (estimated locally),0.03 per call) Pit_Ip_DisableChannelInterrupt/26 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableChannelInterrupt/25 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StopChannel/23 (1073741824 (estimated locally),1.00 per call) Pit_Ip_InitChannel/20 (574129754 (estimated locally),0.53 per call) 
  Calls: 
Pit_Ip_SetEnableInterruptFlag/12 (Pit_Ip_SetEnableInterruptFlag) @061f8b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pitBase/1 (read)pitBase/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Pit_Ip_SetLifetimeTimer/27 (1073741824 (estimated locally),1.00 per call) Pit_Ip_DisableChannelInterrupt/26 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableChannelInterrupt/25 (1073741824 (estimated locally),1.00 per call) Pit_Ip_InitChannel/20 (574129754 (estimated locally),0.53 per call) 
  Calls: SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02/33 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02/32 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_Reset/8 (Pit_Ip_Reset) @061f80e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:134217728 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_SetChainMode/7 (Pit_Ip_SetChainMode) @061f2d20
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_SetDebugMode/6 (Pit_Ip_SetDebugMode) @061f2a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pitBase/1 (read)pitBase/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Pit_Ip_Init/19 (751619278 (estimated locally),0.70 per call) 
  Calls: 
Pit_Ip_EnableTimer/5 (Pit_Ip_EnableTimer) @061f27e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pitBase/1 (read)pitBase/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Pit_Ip_SetLifetimeTimer/27 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetLifetimeTimer/27 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StopChannel/23 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StartChannel/22 (354334802 (estimated locally),0.33 per call) Pit_Ip_InitChannel/20 (574129754 (estimated locally),0.53 per call) 
  Calls: SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00/31 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00/30 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_EnableModule/4 (Pit_Ip_EnableModule) @061f2540
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_GetLoadValue/3 (Pit_Ip_GetLoadValue) @061f22a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_u32ChState/2 (Pit_Ip_u32ChState) @05fe1240
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Pit_Ip_InitChannel/20 (write)Pit_Ip_InitChannel/20 (write)Pit_Ip_InitChannel/20 (write)Pit_Ip_InitChannel/20 (write)Pit_Ip_ProcessCommonInterrupt.constprop.0/43 (read)Pit_Ip_ProcessCommonInterrupt.constprop.0/43 (read)Pit_Ip_ProcessCommonInterrupt.constprop.0/43 (read)Pit_Ip_ProcessCommonInterrupt.constprop.0/43 (read)
  Availability: available
  Varpool flags: initialized
pitBase/1 (pitBase) @05fd9d38
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: Pit_Ip_SetEnableInterruptFlag/12 (read)Pit_Ip_Reset.constprop.0/44 (read)Pit_Ip_SetLifetimeTimer/27 (read)Pit_Ip_Reset.constprop.0/44 (read)Pit_Ip_EnableModule.constprop.0/46 (read)Pit_Ip_ClearInterruptStatusFlag/13 (read)Pit_Ip_SetEnableInterruptFlag/12 (read)Pit_Ip_StartChannel/22 (read)Pit_Ip_SetDebugMode/6 (read)Pit_Ip_EnableTimer/5 (read)Pit_Ip_SetChainMode.constprop.0/45 (read)Pit_Ip_Init/19 (read)Pit_Ip_SetChainMode.constprop.0/45 (read)Pit_Ip_InitChannel/20 (read)Pit_Ip_ProcessCommonInterrupt.constprop.0/43 (read)Pit_Ip_GetLoadValue/3 (read)Pit_Ip_SetDebugMode/6 (read)Pit_Ip_GetCurrentTimer/24 (read)Pit_Ip_EnableTimer/5 (read)Pit_Ip_GetLifetimeTimer/28 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function Pit_Ip_GetLoadValue (Pit_Ip_GetLoadValue, funcdef_no=1, decl_uid=5871, cgraph_uid=2, symbol_order=3)

Modification phase of node Pit_Ip_GetLoadValue/3
Pit_Ip_GetLoadValue (uint8 instance, uint8 channel)
{
  uint32 periodValue;
  int _1;
  struct PIT_Type * _2;
  int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG periodValue => 0
  # DEBUG BEGIN_STMT
  _1 = (int) instance_4(D);
  _2 = pitBase[_1];
  _3 = (int) channel_6(D);
  periodValue_7 ={v} _2->TIMER[_3].LDVAL;
  # DEBUG periodValue => periodValue_7
  # DEBUG BEGIN_STMT
  return periodValue_7;

}



;; Function Pit_Ip_Init (Pit_Ip_Init, funcdef_no=17, decl_uid=5874, cgraph_uid=18, symbol_order=19)

Modification phase of node Pit_Ip_Init/19
Pit_Ip_Init (uint8 instance, const struct Pit_Ip_InstanceConfigType * config)
{
  _Bool _1;
  _Bool _2;
  int _7;
  struct PIT_Type * _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_6(D)
  # DEBUG INLINE_ENTRY Pit_Ip_ValidateInstCall
  # DEBUG BEGIN_STMT
  _7 = (int) instance_6(D);
  _11 = pitBase[_7];
  # DEBUG D#1 => _11 == 0B
  # DEBUG instance => NULL
  # DEBUG status => (<unnamed type>) D#1
  # DEBUG BEGIN_STMT
  if (_11 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = config_8(D)->enableStandardTimers;
  if (_1 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 248034361]:
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableModule (instance_6(D), 0);

  <bb 5> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _2 = config_8(D)->stopRunInDebug;
  Pit_Ip_SetDebugMode (instance_6(D), _2);

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function Pit_Ip_InitChannel (Pit_Ip_InitChannel, funcdef_no=18, decl_uid=5877, cgraph_uid=19, symbol_order=20)

Modification phase of node Pit_Ip_InitChannel/20
Pit_Ip_InitChannel (uint8 instance, const struct Pit_Ip_ChannelConfigType * chnlConfig)
{
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  unsigned char _4;
  int _5;
  void (*<T4b6>) (uint8) _6;
  unsigned char _7;
  <unnamed type> _8;
  int _12;
  struct PIT_Type * _21;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_11(D)
  # DEBUG INLINE_ENTRY Pit_Ip_ValidateInstCall
  # DEBUG BEGIN_STMT
  _12 = (int) instance_11(D);
  _21 = pitBase[_12];
  # DEBUG D#2 => _21 == 0B
  # DEBUG instance => NULL
  # DEBUG status => (<unnamed type>) D#2
  # DEBUG BEGIN_STMT
  if (_21 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _1 = chnlConfig_13(D)->hwChannel;
  Pit_Ip_EnableTimer (instance_11(D), _1, 0);
  # DEBUG BEGIN_STMT
  _2 = chnlConfig_13(D)->hwChannel;
  Pit_Ip_SetEnableInterruptFlag (instance_11(D), _2, 0);
  # DEBUG BEGIN_STMT
  _3 = chnlConfig_13(D)->hwChannel;
  Pit_Ip_ClearInterruptStatusFlag (instance_11(D), _3);
  # DEBUG BEGIN_STMT
  _4 = chnlConfig_13(D)->hwChannel;
  _5 = (int) _4;
  Pit_Ip_u32ChState[_12][_5].chInit = 1;
  # DEBUG BEGIN_STMT
  _6 = chnlConfig_13(D)->callback;
  Pit_Ip_u32ChState[_12][_5].callback = _6;
  # DEBUG BEGIN_STMT
  _7 = chnlConfig_13(D)->callbackParam;
  Pit_Ip_u32ChState[_12][_5].callbackParam = _7;
  # DEBUG BEGIN_STMT
  _8 = chnlConfig_13(D)->channelMode;
  Pit_Ip_u32ChState[_12][_5].channelMode = _8;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Pit_Ip_Deinit (Pit_Ip_Deinit, funcdef_no=19, decl_uid=5879, cgraph_uid=20, symbol_order=21)

Modification phase of node Pit_Ip_Deinit/21
Pit_Ip_Deinit (uint8 instance)
{
  boolean mdisBitExists;
  uint8 channelNum;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG channelNum => 0
  # DEBUG BEGIN_STMT
  # DEBUG rtiChannelExists => 0
  # DEBUG BEGIN_STMT
  # DEBUG mdisBitExists => 0
  # DEBUG BEGIN_STMT
  switch (instance_3(D)) <default: <L2> [50.00%], case 0: <L4> [50.00%], case 2: <L4> [50.00%]>

  <bb 3> [local count: 536870913]:
<L2>:
  # DEBUG BEGIN_STMT
  # DEBUG channelNum => 0
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # channelNum_1 = PHI <7(2), 0(3)>
  # mdisBitExists_2 = PHI <1(2), 0(3)>
<L4>:
  # DEBUG mdisBitExists => mdisBitExists_2
  # DEBUG channelNum => channelNum_1
  # DEBUG BEGIN_STMT
  Pit_Ip_Reset (instance_3(D), channelNum_1, 0, mdisBitExists_2);
  return;

}



;; Function Pit_Ip_StartChannel (Pit_Ip_StartChannel, funcdef_no=20, decl_uid=5883, cgraph_uid=21, symbol_order=22)

Modification phase of node Pit_Ip_StartChannel/22
Pit_Ip_StartChannel (uint8 instance, uint8 channel, uint32 countValue)
{
  boolean isRunning;
  Pit_Ip_StatusType status;
  long unsigned int _1;
  int _9;
  struct PIT_Type * _10;
  int _11;
  long unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG isRunning => 0
  # DEBUG BEGIN_STMT
  # DEBUG status => 1
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_5(D)
  # DEBUG channel => channel_6(D)
  # DEBUG INLINE_ENTRY Pit_Ip_IsChannelRunning
  # DEBUG BEGIN_STMT
  # DEBUG isRunning => 0
  # DEBUG BEGIN_STMT
  _9 = (int) instance_5(D);
  _10 = pitBase[_9];
  _11 = (int) channel_6(D);
  _12 ={v} _10->TIMER[_11].TCTRL;
  isRunning_13 = (boolean) _12;
  # DEBUG isRunning => isRunning_13
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG isRunning => NULL
  # DEBUG isRunning => isRunning_13
  # DEBUG BEGIN_STMT
  if (isRunning_13 != 0)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _1 = countValue_7(D) + 4294967295;
  # DEBUG instance => instance_5(D)
  # DEBUG channel => channel_6(D)
  # DEBUG value => _1
  # DEBUG INLINE_ENTRY Pit_Ip_SetCounterValue
  # DEBUG BEGIN_STMT
  _10->TIMER[_11].LDVAL ={v} _1;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableTimer (instance_5(D), channel_6(D), 1);
  # DEBUG BEGIN_STMT
  # DEBUG status => 0

  <bb 4> [local count: 1073741824]:
  # status_2 = PHI <1(2), 0(3)>
  # DEBUG status => status_2
  # DEBUG BEGIN_STMT
  return status_2;

}



;; Function Pit_Ip_StopChannel (Pit_Ip_StopChannel, funcdef_no=21, decl_uid=5886, cgraph_uid=22, symbol_order=23)

Modification phase of node Pit_Ip_StopChannel/23
Pit_Ip_StopChannel (uint8 instance, uint8 channel)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableTimer (instance_2(D), channel_3(D), 0);
  # DEBUG BEGIN_STMT
  Pit_Ip_ClearInterruptStatusFlag (instance_2(D), channel_3(D));
  return;

}



;; Function Pit_Ip_GetCurrentTimer (Pit_Ip_GetCurrentTimer, funcdef_no=22, decl_uid=5889, cgraph_uid=23, symbol_order=24)

Modification phase of node Pit_Ip_GetCurrentTimer/24
Pit_Ip_GetCurrentTimer (uint8 instance, uint8 channel)
{
  uint32 counterValue;
  uint64 counterValue;
  int _5;
  struct PIT_Type * _6;
  int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG counterValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG channel => channel_3(D)
  # DEBUG INLINE_ENTRY Pit_Ip_GetCounterValue
  # DEBUG BEGIN_STMT
  # DEBUG counterValue => 0
  # DEBUG BEGIN_STMT
  _5 = (int) instance_2(D);
  _6 = pitBase[_5];
  _7 = (int) channel_3(D);
  counterValue_8 ={v} _6->TIMER[_7].CVAL;
  # DEBUG counterValue => counterValue_8
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG counterValue => NULL
  counterValue_4 = (uint64) counterValue_8;
  # DEBUG counterValue => counterValue_4
  # DEBUG BEGIN_STMT
  return counterValue_4;

}



;; Function Pit_Ip_EnableChannelInterrupt (Pit_Ip_EnableChannelInterrupt, funcdef_no=23, decl_uid=5892, cgraph_uid=24, symbol_order=25)

Modification phase of node Pit_Ip_EnableChannelInterrupt/25
Pit_Ip_EnableChannelInterrupt (uint8 instance, uint8 channel)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Pit_Ip_ClearInterruptStatusFlag (instance_2(D), channel_3(D));
  # DEBUG BEGIN_STMT
  Pit_Ip_SetEnableInterruptFlag (instance_2(D), channel_3(D), 1);
  return;

}



;; Function Pit_Ip_DisableChannelInterrupt (Pit_Ip_DisableChannelInterrupt, funcdef_no=24, decl_uid=5895, cgraph_uid=25, symbol_order=26)

Modification phase of node Pit_Ip_DisableChannelInterrupt/26
Pit_Ip_DisableChannelInterrupt (uint8 instance, uint8 channel)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Pit_Ip_SetEnableInterruptFlag (instance_2(D), channel_3(D), 0);
  # DEBUG BEGIN_STMT
  Pit_Ip_ClearInterruptStatusFlag (instance_2(D), channel_3(D));
  return;

}



;; Function Pit_Ip_SetLifetimeTimer (Pit_Ip_SetLifetimeTimer, funcdef_no=25, decl_uid=5897, cgraph_uid=26, symbol_order=27)

Modification phase of node Pit_Ip_SetLifetimeTimer/27
Pit_Ip_SetLifetimeTimer (uint8 instance)
{
  int _7;
  struct PIT_Type * _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG channel => 1
  # DEBUG value => 4294967295
  # DEBUG INLINE_ENTRY Pit_Ip_SetCounterValue
  # DEBUG BEGIN_STMT
  _7 = (int) instance_2(D);
  _8 = pitBase[_7];
  _8->TIMER[1].LDVAL ={v} 4294967295;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  Pit_Ip_SetEnableInterruptFlag (instance_2(D), 1, 0);
  # DEBUG BEGIN_STMT
  Pit_Ip_SetChainMode (instance_2(D), 1, 1);
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableTimer (instance_2(D), 1, 1);
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG channel => 0
  # DEBUG value => 4294967295
  # DEBUG INLINE_ENTRY Pit_Ip_SetCounterValue
  # DEBUG BEGIN_STMT
  _8->TIMER[0].LDVAL ={v} 4294967295;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableTimer (instance_2(D), 0, 1);
  return;

}



;; Function Pit_Ip_GetLifetimeTimer (Pit_Ip_GetLifetimeTimer, funcdef_no=26, decl_uid=5899, cgraph_uid=27, symbol_order=28)

Modification phase of node Pit_Ip_GetLifetimeTimer/28
Pit_Ip_GetLifetimeTimer (uint8 instance)
{
  uint32 upperValue;
  uint32 lowerValue;
  uint64 lifeTimeValue;
  long long unsigned int _1;
  long long unsigned int _2;
  long long unsigned int _3;
  int _10;
  struct PIT_Type * _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG lifeTimeValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG valueH => 0
  # DEBUG BEGIN_STMT
  # DEBUG valueL => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09 ();
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_6(D)
  # DEBUG INLINE_ENTRY Pit_Ip_GetUpperLifetimerValue
  # DEBUG BEGIN_STMT
  # DEBUG upperValue => 0
  # DEBUG BEGIN_STMT
  _10 = (int) instance_6(D);
  _11 = pitBase[_10];
  upperValue_12 ={v} _11->LTMR64H;
  # DEBUG upperValue => upperValue_12
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG upperValue => NULL
  # DEBUG valueH => upperValue_12
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_6(D)
  # DEBUG INLINE_ENTRY Pit_Ip_GetLowerLifetimerValue
  # DEBUG BEGIN_STMT
  # DEBUG lowerValue => 0
  # DEBUG BEGIN_STMT
  lowerValue_9 ={v} _11->LTMR64L;
  # DEBUG lowerValue => lowerValue_9
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG lowerValue => NULL
  # DEBUG valueL => lowerValue_9
  # DEBUG BEGIN_STMT
  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09 ();
  # DEBUG BEGIN_STMT
  _1 = (long long unsigned int) upperValue_12;
  _2 = _1 << 32;
  _3 = (long long unsigned int) lowerValue_9;
  lifeTimeValue_8 = _2 + _3;
  # DEBUG lifeTimeValue => lifeTimeValue_8
  # DEBUG BEGIN_STMT
  return lifeTimeValue_8;

}



;; Function PIT_0_ISR (PIT_0_ISR, funcdef_no=27, decl_uid=5903, cgraph_uid=28, symbol_order=29)

Modification phase of node PIT_0_ISR/29
PIT_0_ISR ()
{
  uint8 channel;

  <bb 2> [local count: 134217728]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG instance => 0
  # DEBUG BEGIN_STMT
  # DEBUG channel => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 939524097]:
  # DEBUG BEGIN_STMT
  Pit_Ip_ProcessCommonInterrupt (0, channel_1);
  # DEBUG BEGIN_STMT
  channel_5 = channel_1 + 1;
  # DEBUG channel => channel_5

  <bb 4> [local count: 1073741824]:
  # channel_1 = PHI <0(2), channel_5(3)>
  # DEBUG channel => channel_1
  # DEBUG BEGIN_STMT
  if (channel_1 != 7)
    goto <bb 3>; [87.50%]
  else
    goto <bb 5>; [12.50%]

  <bb 5> [local count: 134217728]:
  return;

}


