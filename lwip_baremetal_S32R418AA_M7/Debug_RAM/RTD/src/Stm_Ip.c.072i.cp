
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11/38:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11/37:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_39/36:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_39/35:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31/34:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31/33:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30/32:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30/31:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29/30:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29/29:
  Jump functions of caller  STM_0_ISR/28:
    callsite  STM_0_ISR/28 -> Stm_Ip_ProcessCommonInterrupt/16 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 4]
  Jump functions of caller  Stm_Ip_PredefCounting/27:
    callsite  Stm_Ip_PredefCounting/27 -> Stm_Ip_TimerEnable/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Stm_Ip_PredefCounting/27 -> Stm_Ip_SetDebugMode/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Stm_Ip_PredefCounting/27 -> Stm_Ip_SetDebugMode/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Stm_Ip_PredefCounting/27 -> Stm_Ip_SetPrescaler/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Stm_Ip_GetCompareValue/26:
  Jump functions of caller  Stm_Ip_GetCounterValue/25:
  Jump functions of caller  Stm_Ip_DisableChannel/24:
    callsite  Stm_Ip_DisableChannel/24 -> Stm_Ip_SetInterruptEnableFlag/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Stm_Ip_EnableChannel/23:
    callsite  Stm_Ip_EnableChannel/23 -> Stm_Ip_SetInterruptEnableFlag/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  Stm_Ip_StopTimer/22:
    callsite  Stm_Ip_StopTimer/22 -> Stm_Ip_TimerEnable/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Stm_Ip_StartTimer/21:
    callsite  Stm_Ip_StartTimer/21 -> Stm_Ip_TimerEnable/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  Stm_Ip_StartCounting/20:
    callsite  Stm_Ip_StartCounting/20 -> Stm_Ip_SetInterruptEnableFlag/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  Stm_Ip_Deinit/19:
    callsite  Stm_Ip_Deinit/19 -> Stm_Ip_TimerEnable/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Stm_Ip_Deinit/19 -> Stm_Ip_SetPrescaler/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Stm_Ip_Deinit/19 -> Stm_Ip_SetInterruptEnableFlag/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 4]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Stm_Ip_InitChannel/18:
    callsite  Stm_Ip_InitChannel/18 -> Stm_Ip_SetInterruptEnableFlag/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Stm_Ip_Init/17:
    callsite  Stm_Ip_Init/17 -> Stm_Ip_TimerEnable/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Stm_Ip_Init/17 -> Stm_Ip_SetPrescaler/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Stm_Ip_Init/17 -> Stm_Ip_SetDebugMode/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Stm_Ip_ProcessCommonInterrupt/16:
    callsite  Stm_Ip_ProcessCommonInterrupt/16 -> Stm_Ip_DisableChannel/24 : 
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
  Jump functions of caller  Stm_Ip_SetInterruptEnableFlag/9:
  Jump functions of caller  Stm_Ip_SetPrescaler/8:
  Jump functions of caller  Stm_Ip_TimerEnable/6:
  Jump functions of caller  Stm_Ip_SetDebugMode/5:

 Propagating constants:

Not considering STM_0_ISR for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_PredefCounting for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_GetCompareValue for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_GetCounterValue for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_DisableChannel for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_EnableChannel for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_StopTimer for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_StartTimer for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_StartCounting for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_Deinit for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_InitChannel for cloning; -fipa-cp-clone disabled.
Not considering Stm_Ip_Init for cloning; -fipa-cp-clone disabled.

overall_size: 238, max_new_size: 11001
 - context independent values, size: 39, time_benefit: 51.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: STM_0_ISR/28:
  Node: Stm_Ip_PredefCounting/27:
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
  Node: Stm_Ip_GetCompareValue/26:
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
  Node: Stm_Ip_GetCounterValue/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Stm_Ip_DisableChannel/24:
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
  Node: Stm_Ip_EnableChannel/23:
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
  Node: Stm_Ip_StopTimer/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Stm_Ip_StartTimer/21:
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
  Node: Stm_Ip_StartCounting/20:
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
  Node: Stm_Ip_Deinit/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Stm_Ip_InitChannel/18:
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
  Node: Stm_Ip_Init/17:
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
  Node: Stm_Ip_ProcessCommonInterrupt/16:
    param [0]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint8 [0, 4]
        AGGS VARIABLE
  Node: Stm_Ip_SetInterruptEnableFlag/9:
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
    param [2]: 0 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         boolean [0, 1]
        AGGS VARIABLE
  Node: Stm_Ip_SetPrescaler/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 2, loc_size: 8, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Stm_Ip_TimerEnable/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         boolean [0, 1]
        AGGS VARIABLE
  Node: Stm_Ip_SetDebugMode/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               1 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
               0 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of Stm_Ip_ProcessCommonInterrupt/16 for all known contexts.
    replacing param #0 instance with const 0
Propagated bits info for function Stm_Ip_ProcessCommonInterrupt.constprop/50:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x0, mask = 0x7
Propagated bits info for function Stm_Ip_ProcessCommonInterrupt/16:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x0, mask = 0x7

IPA constant propagation end

Reclaiming functions: Stm_Ip_ProcessCommonInterrupt/16
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Stm_Ip_ProcessCommonInterrupt.constprop.0/50 (Stm_Ip_ProcessCommonInterrupt.constprop) @054c1540
  Type: function definition analyzed
  Visibility:
  References: stmBase/3 (read)Stm_Ip_u32ChState/4 (read)Stm_Ip_u32ChState/4 (read)Stm_Ip_u32ChState/4 (read)Stm_Ip_u32ChState/4 (read)Stm_Ip_u32TargetValue/1 (read)
  Referring: 
  Clone of Stm_Ip_ProcessCommonInterrupt/16
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: STM_0_ISR/28 (858993459 (estimated locally),4.00 per call) 
  Calls: SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11/37 (177167401 (estimated locally),0.17 per call) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11/38 (177167401 (estimated locally),0.17 per call) Stm_Ip_DisableChannel/24 (8964670 (estimated locally),0.01 per call) 
   Indirect call(15502148 (estimated locally),0.01 per call) 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11/38 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11) @0364bc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_ProcessCommonInterrupt.constprop/50 (177167401 (estimated locally),0.17 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11/37 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11) @0364bb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_ProcessCommonInterrupt.constprop/50 (177167401 (estimated locally),0.17 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_39/36 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_39) @0364b000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_StartCounting/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_39/35 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_39) @054f3ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_StartCounting/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31/34 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31) @054f3a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_SetInterruptEnableFlag/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31/33 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31) @054f39a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_SetInterruptEnableFlag/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30/32 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30) @054f3700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_TimerEnable/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30/31 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30) @054f3620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_TimerEnable/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29/30 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29) @054f3380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_SetDebugMode/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29/29 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29) @054f32a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Stm_Ip_SetDebugMode/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
STM_0_ISR/28 (STM_0_ISR) @054ec620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:214748364 (estimated locally) body optimize_size
  Called by: 
  Calls: Stm_Ip_ProcessCommonInterrupt.constprop/50 (858993459 (estimated locally),4.00 per call) 
Stm_Ip_PredefCounting/27 (Stm_Ip_PredefCounting) @054ec0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Stm_Ip_TimerEnable/6 (354334802 (estimated locally),0.33 per call) Stm_Ip_SetDebugMode/5 (177167401 (estimated locally),0.17 per call) Stm_Ip_SetDebugMode/5 (177167401 (estimated locally),0.17 per call) Stm_Ip_SetPrescaler/8 (354334802 (estimated locally),0.33 per call) 
Stm_Ip_GetCompareValue/26 (Stm_Ip_GetCompareValue) @054ecd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Stm_Ip_GetCounterValue/25 (Stm_Ip_GetCounterValue) @054eca80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Stm_Ip_DisableChannel/24 (Stm_Ip_DisableChannel) @054ec7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Stm_Ip_ProcessCommonInterrupt.constprop/50 (8964670 (estimated locally),0.01 per call) 
  Calls: Stm_Ip_SetInterruptEnableFlag/9 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_EnableChannel/23 (Stm_Ip_EnableChannel) @054ec540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Stm_Ip_SetInterruptEnableFlag/9 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_StopTimer/22 (Stm_Ip_StopTimer) @054ec2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Stm_Ip_TimerEnable/6 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_StartTimer/21 (Stm_Ip_StartTimer) @054ec000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Stm_Ip_TimerEnable/6 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_StartCounting/20 (Stm_Ip_StartCounting) @054c1b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)Stm_Ip_u32TargetValue/1 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Stm_Ip_SetInterruptEnableFlag/9 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_39/36 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_39/35 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_Deinit/19 (Stm_Ip_Deinit) @054c1620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)
  Referring: 
  Availability: available
  Function flags: count:214748364 (estimated locally) body optimize_size
  Called by: 
  Calls: Stm_Ip_TimerEnable/6 (214748365 (estimated locally),1.00 per call) Stm_Ip_SetPrescaler/8 (214748365 (estimated locally),1.00 per call) Stm_Ip_SetInterruptEnableFlag/9 (858993459 (estimated locally),4.00 per call) 
Stm_Ip_InitChannel/18 (Stm_Ip_InitChannel) @054c10e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)Stm_Ip_u32ChState/4 (write)Stm_Ip_u32ChState/4 (write)Stm_Ip_u32ChState/4 (write)Stm_Ip_u32ChState/4 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Stm_Ip_SetInterruptEnableFlag/9 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_Init/17 (Stm_Ip_Init) @054c1d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: stmBase/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Stm_Ip_TimerEnable/6 (1073741824 (estimated locally),1.00 per call) Stm_Ip_SetPrescaler/8 (1073741824 (estimated locally),1.00 per call) Stm_Ip_SetDebugMode/5 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_ProcessCommonInterrupt/16 (Stm_Ip_ProcessCommonInterrupt) @054c1a80
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Stm_Ip_SetInterruptEnableFlag/9 (Stm_Ip_SetInterruptEnableFlag) @054b9ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: stmBase/3 (read)stmBase/3 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Stm_Ip_DisableChannel/24 (1073741824 (estimated locally),1.00 per call) Stm_Ip_EnableChannel/23 (1073741824 (estimated locally),1.00 per call) Stm_Ip_StartCounting/20 (1073741824 (estimated locally),1.00 per call) Stm_Ip_Deinit/19 (858993459 (estimated locally),4.00 per call) Stm_Ip_InitChannel/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31/34 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31/33 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_SetPrescaler/8 (Stm_Ip_SetPrescaler) @054b9c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: stmBase/3 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Stm_Ip_PredefCounting/27 (354334802 (estimated locally),0.33 per call) Stm_Ip_Deinit/19 (214748365 (estimated locally),1.00 per call) Stm_Ip_Init/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Stm_Ip_TimerEnable/6 (Stm_Ip_TimerEnable) @054b9620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: stmBase/3 (read)stmBase/3 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Stm_Ip_PredefCounting/27 (354334802 (estimated locally),0.33 per call) Stm_Ip_StopTimer/22 (1073741824 (estimated locally),1.00 per call) Stm_Ip_StartTimer/21 (1073741824 (estimated locally),1.00 per call) Stm_Ip_Deinit/19 (214748365 (estimated locally),1.00 per call) Stm_Ip_Init/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30/32 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30/31 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_SetDebugMode/5 (Stm_Ip_SetDebugMode) @054b9380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: stmBase/3 (read)stmBase/3 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Stm_Ip_PredefCounting/27 (177167401 (estimated locally),0.17 per call) Stm_Ip_PredefCounting/27 (177167401 (estimated locally),0.17 per call) Stm_Ip_Init/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29/30 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29/29 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_u32ChState/4 (Stm_Ip_u32ChState) @054b6048
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Stm_Ip_InitChannel/18 (write)Stm_Ip_InitChannel/18 (write)Stm_Ip_InitChannel/18 (write)Stm_Ip_InitChannel/18 (write)Stm_Ip_ProcessCommonInterrupt.constprop.0/50 (read)Stm_Ip_ProcessCommonInterrupt.constprop.0/50 (read)Stm_Ip_ProcessCommonInterrupt.constprop.0/50 (read)Stm_Ip_ProcessCommonInterrupt.constprop.0/50 (read)
  Availability: available
  Varpool flags: initialized
stmBase/3 (stmBase) @053bff78
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: Stm_Ip_StartTimer/21 (read)Stm_Ip_DisableChannel/24 (read)Stm_Ip_TimerEnable/6 (read)Stm_Ip_TimerEnable/6 (read)Stm_Ip_Deinit/19 (read)Stm_Ip_SetPrescaler/8 (read)Stm_Ip_StartCounting/20 (read)Stm_Ip_GetCounterValue/25 (read)Stm_Ip_SetDebugMode/5 (read)Stm_Ip_SetDebugMode/5 (read)Stm_Ip_ProcessCommonInterrupt.constprop.0/50 (read)Stm_Ip_GetCompareValue/26 (read)Stm_Ip_EnableChannel/23 (read)Stm_Ip_SetInterruptEnableFlag/9 (read)Stm_Ip_SetInterruptEnableFlag/9 (read)Stm_Ip_Init/17 (read)Stm_Ip_InitChannel/18 (read)Stm_Ip_PredefCounting/27 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Stm_Ip_u32NextTargetValue/2 (Stm_Ip_u32NextTargetValue) @053bf798
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags:
Stm_Ip_u32TargetValue/1 (Stm_Ip_u32TargetValue) @053bf750
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: Stm_Ip_StartCounting/20 (write)Stm_Ip_ProcessCommonInterrupt.constprop.0/50 (read)
  Availability: available
  Varpool flags:

;; Function Stm_Ip_Init (Stm_Ip_Init, funcdef_no=13, decl_uid=5869, cgraph_uid=14, symbol_order=17)

Modification phase of node Stm_Ip_Init/17
Stm_Ip_Init (uint8 instance, const struct Stm_Ip_InstanceConfigType * configPtr)
{
  _Bool _1;
  unsigned char _2;
  int _9;
  struct STM_Type * _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_4(D)
  # DEBUG counterValue => 0
  # DEBUG INLINE_ENTRY Stm_Ip_SetCntValue
  # DEBUG BEGIN_STMT
  _9 = (int) instance_4(D);
  _10 = stmBase[_9];
  _10->CNT ={v} 0;
  # DEBUG instance => NULL
  # DEBUG counterValue => NULL
  # DEBUG BEGIN_STMT
  _1 = configPtr_5(D)->stopInDebugMode;
  Stm_Ip_SetDebugMode (instance_4(D), _1);
  # DEBUG BEGIN_STMT
  _2 = configPtr_5(D)->clockPrescaler;
  Stm_Ip_SetPrescaler (instance_4(D), _2);
  # DEBUG BEGIN_STMT
  Stm_Ip_TimerEnable (instance_4(D), 1);
  return;

}



;; Function Stm_Ip_InitChannel (Stm_Ip_InitChannel, funcdef_no=14, decl_uid=5872, cgraph_uid=15, symbol_order=18)

Modification phase of node Stm_Ip_InitChannel/18
Stm_Ip_InitChannel (uint8 instance, const struct Stm_Ip_ChannelConfigType * configPtr)
{
  unsigned char _1;
  unsigned char _2;
  void (*<T4b1>) (uint8) _3;
  unsigned char _4;
  <unnamed type> _5;
  int _14;
  struct STM_Type * _15;
  int _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = configPtr_7(D)->hwChannel;
  Stm_Ip_SetInterruptEnableFlag (instance_8(D), _1, 0);
  # DEBUG BEGIN_STMT
  _2 = configPtr_7(D)->hwChannel;
  # DEBUG instance => instance_8(D)
  # DEBUG channel => _2
  # DEBUG INLINE_ENTRY Stm_Ip_ClearInterruptStatusFlag
  # DEBUG BEGIN_STMT
  _14 = (int) instance_8(D);
  _15 = stmBase[_14];
  _16 = (int) _2;
  _15->CHANNEL[_16].CIR ={v} 1;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_8(D)
  # DEBUG channel => _2
  # DEBUG compareValue => 0
  # DEBUG INLINE_ENTRY Stm_Ip_SetCmpValue
  # DEBUG BEGIN_STMT
  _15->CHANNEL[_16].CMP ={v} 0;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG compareValue => NULL
  # DEBUG BEGIN_STMT
  Stm_Ip_u32ChState[_14][_16].chInit = 1;
  # DEBUG BEGIN_STMT
  _3 = configPtr_7(D)->callback;
  Stm_Ip_u32ChState[_14][_16].callback = _3;
  # DEBUG BEGIN_STMT
  _4 = configPtr_7(D)->callbackParam;
  Stm_Ip_u32ChState[_14][_16].callbackParam = _4;
  # DEBUG BEGIN_STMT
  _5 = configPtr_7(D)->channelMode;
  Stm_Ip_u32ChState[_14][_16].channelMode = _5;
  return;

}



;; Function Stm_Ip_Deinit (Stm_Ip_Deinit, funcdef_no=15, decl_uid=5874, cgraph_uid=16, symbol_order=19)

Modification phase of node Stm_Ip_Deinit/19
Stm_Ip_Deinit (uint8 instance)
{
  uint8 channelIndex;
  int _9;
  struct STM_Type * _10;
  int _11;

  <bb 2> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG channelIndex => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  Stm_Ip_SetInterruptEnableFlag (instance_4(D), channelIndex_1, 0);
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_4(D)
  # DEBUG channel => channelIndex_1
  # DEBUG INLINE_ENTRY Stm_Ip_ClearInterruptStatusFlag
  # DEBUG BEGIN_STMT
  _9 = (int) instance_4(D);
  _10 = stmBase[_9];
  _11 = (int) channelIndex_1;
  _10->CHANNEL[_11].CIR ={v} 1;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_4(D)
  # DEBUG channel => channelIndex_1
  # DEBUG compareValue => 0
  # DEBUG INLINE_ENTRY Stm_Ip_SetCmpValue
  # DEBUG BEGIN_STMT
  _10->CHANNEL[_11].CMP ={v} 0;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG compareValue => NULL
  # DEBUG BEGIN_STMT
  channelIndex_8 = channelIndex_1 + 1;
  # DEBUG channelIndex => channelIndex_8

  <bb 4> [local count: 1073741824]:
  # channelIndex_1 = PHI <0(2), channelIndex_8(3)>
  # DEBUG channelIndex => channelIndex_1
  # DEBUG BEGIN_STMT
  if (channelIndex_1 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 5>; [20.00%]

  <bb 5> [local count: 214748365]:
  # DEBUG BEGIN_STMT
  Stm_Ip_SetPrescaler (instance_4(D), 0);
  # DEBUG BEGIN_STMT
  Stm_Ip_TimerEnable (instance_4(D), 0);
  return;

}



;; Function Stm_Ip_StartCounting (Stm_Ip_StartCounting, funcdef_no=16, decl_uid=5878, cgraph_uid=17, symbol_order=20)

Modification phase of node Stm_Ip_StartCounting/20
Stm_Ip_StartCounting (uint8 instance, uint8 channel, uint32 compareValue)
{
  uint32 currentCntValue;
  long unsigned int _1;
  int _10;
  int _11;
  struct STM_Type * _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_39 ();
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_4(D)
  # DEBUG INLINE_ENTRY Stm_Ip_GetCntValue
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = (int) instance_4(D);
  _12 = stmBase[_11];
  currentCntValue_13 ={v} _12->CNT;
  # DEBUG currentCntValue => currentCntValue_13
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG currentCntValue => NULL
  # DEBUG currentCntValue => currentCntValue_13
  # DEBUG BEGIN_STMT
  _1 = compareValue_5(D) + currentCntValue_13;
  # DEBUG instance => instance_4(D)
  # DEBUG channel => channel_6(D)
  # DEBUG compareValue => _1
  # DEBUG INLINE_ENTRY Stm_Ip_SetCmpValue
  # DEBUG BEGIN_STMT
  _10 = (int) channel_6(D);
  _12->CHANNEL[_10].CMP ={v} _1;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG compareValue => NULL
  # DEBUG BEGIN_STMT
  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_39 ();
  # DEBUG BEGIN_STMT
  Stm_Ip_u32TargetValue[_11][_10] = compareValue_5(D);
  # DEBUG BEGIN_STMT
  Stm_Ip_SetInterruptEnableFlag (instance_4(D), channel_6(D), 1);
  return;

}



;; Function Stm_Ip_StartTimer (Stm_Ip_StartTimer, funcdef_no=17, decl_uid=5881, cgraph_uid=18, symbol_order=21)

Modification phase of node Stm_Ip_StartTimer/21
Stm_Ip_StartTimer (uint8 instance, uint32 startValue)
{
  int _5;
  struct STM_Type * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG counterValue => startValue_3(D)
  # DEBUG INLINE_ENTRY Stm_Ip_SetCntValue
  # DEBUG BEGIN_STMT
  _5 = (int) instance_2(D);
  _6 = stmBase[_5];
  _6->CNT ={v} startValue_3(D);
  # DEBUG instance => NULL
  # DEBUG counterValue => NULL
  # DEBUG BEGIN_STMT
  Stm_Ip_TimerEnable (instance_2(D), 1);
  return;

}



;; Function Stm_Ip_StopTimer (Stm_Ip_StopTimer, funcdef_no=18, decl_uid=5883, cgraph_uid=19, symbol_order=22)

Modification phase of node Stm_Ip_StopTimer/22
Stm_Ip_StopTimer (uint8 instance)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Stm_Ip_TimerEnable (instance_2(D), 0);
  return;

}



;; Function Stm_Ip_EnableChannel (Stm_Ip_EnableChannel, funcdef_no=19, decl_uid=5886, cgraph_uid=20, symbol_order=23)

Modification phase of node Stm_Ip_EnableChannel/23
Stm_Ip_EnableChannel (uint8 instance, uint8 channel)
{
  int _5;
  struct STM_Type * _6;
  int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG channel => channel_3(D)
  # DEBUG INLINE_ENTRY Stm_Ip_ClearInterruptStatusFlag
  # DEBUG BEGIN_STMT
  _5 = (int) instance_2(D);
  _6 = stmBase[_5];
  _7 = (int) channel_3(D);
  _6->CHANNEL[_7].CIR ={v} 1;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG BEGIN_STMT
  Stm_Ip_SetInterruptEnableFlag (instance_2(D), channel_3(D), 1);
  return;

}



;; Function Stm_Ip_DisableChannel (Stm_Ip_DisableChannel, funcdef_no=20, decl_uid=5889, cgraph_uid=21, symbol_order=24)

Modification phase of node Stm_Ip_DisableChannel/24
Stm_Ip_DisableChannel (uint8 instance, uint8 channel)
{
  int _5;
  struct STM_Type * _6;
  int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Stm_Ip_SetInterruptEnableFlag (instance_2(D), channel_3(D), 0);
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG channel => channel_3(D)
  # DEBUG INLINE_ENTRY Stm_Ip_ClearInterruptStatusFlag
  # DEBUG BEGIN_STMT
  _5 = (int) instance_2(D);
  _6 = stmBase[_5];
  _7 = (int) channel_3(D);
  _6->CHANNEL[_7].CIR ={v} 1;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  return;

}



;; Function Stm_Ip_GetCounterValue (Stm_Ip_GetCounterValue, funcdef_no=21, decl_uid=5891, cgraph_uid=22, symbol_order=25)

Modification phase of node Stm_Ip_GetCounterValue/25
Stm_Ip_GetCounterValue (uint8 instance)
{
  uint32 currentCntValue;
  int _3;
  struct STM_Type * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG currentCounterValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG INLINE_ENTRY Stm_Ip_GetCntValue
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = (int) instance_2(D);
  _4 = stmBase[_3];
  currentCntValue_5 ={v} _4->CNT;
  # DEBUG currentCntValue => currentCntValue_5
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG currentCntValue => NULL
  # DEBUG currentCounterValue => currentCntValue_5
  # DEBUG BEGIN_STMT
  return currentCntValue_5;

}



;; Function Stm_Ip_GetCompareValue (Stm_Ip_GetCompareValue, funcdef_no=22, decl_uid=5894, cgraph_uid=23, symbol_order=26)

Modification phase of node Stm_Ip_GetCompareValue/26
Stm_Ip_GetCompareValue (uint8 instance, uint8 channel)
{
  uint32 currentCmpValue;
  int _4;
  struct STM_Type * _5;
  int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG currentCompareValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG channel => channel_3(D)
  # DEBUG INLINE_ENTRY Stm_Ip_GetCmpValue
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = (int) instance_2(D);
  _5 = stmBase[_4];
  _6 = (int) channel_3(D);
  currentCmpValue_7 ={v} _5->CHANNEL[_6].CMP;
  # DEBUG currentCmpValue => currentCmpValue_7
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG currentCmpValue => NULL
  # DEBUG currentCompareValue => currentCmpValue_7
  # DEBUG BEGIN_STMT
  return currentCmpValue_7;

}



;; Function Stm_Ip_PredefCounting (Stm_Ip_PredefCounting, funcdef_no=23, decl_uid=5898, cgraph_uid=24, symbol_order=27)

Modification phase of node Stm_Ip_PredefCounting/27
Stm_Ip_PredefCounting (uint8 instance, uint8 prescaler, boolean freezeEnable)
{
  uint32 flag;
  int _11;
  struct STM_Type * _12;
  long unsigned int _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_4(D)
  # DEBUG INLINE_ENTRY Stm_Ip_GetTimerEnableBit
  # DEBUG BEGIN_STMT
  # DEBUG flag => 0
  # DEBUG BEGIN_STMT
  _11 = (int) instance_4(D);
  _12 = stmBase[_11];
  _13 ={v} _12->CR;
  flag_14 = _13 & 1;
  # DEBUG flag => flag_14
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG flag => NULL
  if (flag_14 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_4(D)
  # DEBUG counterValue => 0
  # DEBUG INLINE_ENTRY Stm_Ip_SetCntValue
  # DEBUG BEGIN_STMT
  _12->CNT ={v} 0;
  # DEBUG instance => NULL
  # DEBUG counterValue => NULL
  # DEBUG BEGIN_STMT
  Stm_Ip_SetPrescaler (instance_4(D), prescaler_5(D));
  # DEBUG BEGIN_STMT
  if (freezeEnable_7(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  Stm_Ip_SetDebugMode (instance_4(D), 1);
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  Stm_Ip_SetDebugMode (instance_4(D), 0);

  <bb 6> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Stm_Ip_TimerEnable (instance_4(D), 1);

  <bb 7> [local count: 1073741824]:
  return;

}



;; Function STM_0_ISR (STM_0_ISR, funcdef_no=24, decl_uid=5940, cgraph_uid=25, symbol_order=28)

Modification phase of node STM_0_ISR/28
STM_0_ISR ()
{
  uint8 channel;

  <bb 2> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG instance => 0
  # DEBUG BEGIN_STMT
  # DEBUG channel => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  Stm_Ip_ProcessCommonInterrupt (0, channel_1);
  # DEBUG BEGIN_STMT
  channel_5 = channel_1 + 1;
  # DEBUG channel => channel_5

  <bb 4> [local count: 1073741824]:
  # channel_1 = PHI <0(2), channel_5(3)>
  # DEBUG channel => channel_1
  # DEBUG BEGIN_STMT
  if (channel_1 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 5>; [20.00%]

  <bb 5> [local count: 214748365]:
  return;

}


