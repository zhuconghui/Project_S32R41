
IPA constant propagation start:
Determining dynamic type for call: Clock_Ip_SetCgmXCscCssCsGrip.part.0 (Config_3(D));
  Starting walk at: Clock_Ip_SetCgmXCscCssCsGrip.part.0 (Config_3(D));
  instance pointer: Config_3(D)  Outer instance pointer: Config_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Clock_Ip_ResetCgmXCscCssCsGrip.part.0 (Config_3(D));
  Starting walk at: Clock_Ip_ResetCgmXCscCssCsGrip.part.0 (Config_3(D));
  instance pointer: Config_3(D)  Outer instance pointer: Config_3(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17:
  Jump functions of caller  Clock_Ip_SetCgmXCscCssCsGrip.part.0/16:
  Jump functions of caller  Clock_Ip_ReportClockErrors/14:
  Jump functions of caller  Clock_Ip_TimeoutExpired/13:
  Jump functions of caller  Clock_Ip_StartTimeout/12:
  Jump functions of caller  Clock_Ip_SetCgmXCscCssCsGrip/6:
    callsite  Clock_Ip_SetCgmXCscCssCsGrip/6 -> Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Clock_Ip_ResetCgmXCscCssCsGrip/5:
    callsite  Clock_Ip_ResetCgmXCscCssCsGrip/5 -> Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4:
  Jump functions of caller  Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3:
  Jump functions of caller  Clock_Ip_SetCgmXCscCssClkswSwip/2:
  Jump functions of caller  Clock_Ip_ResetCgmXCscCssClkswSwip/1:
  Jump functions of caller  Clock_Ip_CallbackSelectorEmpty/0:

 Propagating constants:

Not considering Clock_Ip_SetCgmXCscCssCsGrip for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ResetCgmXCscCssCsGrip for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip for cloning; -fipa-cp-clone disabled.
Function Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_SetCgmXCscCssClkswSwip for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ResetCgmXCscCssClkswSwip for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_CallbackSelectorEmpty for cloning; -fipa-cp-clone disabled.

overall_size: 364, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Clock_Ip_SetCgmXCscCssCsGrip.part.0/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Clock_Ip_SetCgmXCscCssCsGrip/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetCgmXCscCssCsGrip/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetCgmXCscCssClkswSwip/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetCgmXCscCssClkswSwip/1:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_CallbackSelectorEmpty/0:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (Clock_Ip_ResetCgmXCscCssCsGrip.part.0) @0640dc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au8SoftwareMuxResetValue/15 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_axFeatureExtensions/10 (read)Clock_Ip_axFeatureExtensions/10 (read)Clock_Ip_apxCgm/11 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Clock_Ip_ResetCgmXCscCssCsGrip/5 (114863532 (estimated locally),0.53 per call) 
  Calls: Clock_Ip_StartTimeout/12 (114863532 (estimated locally),1.00 per call) Clock_Ip_TimeoutExpired/13 (1073741824 (estimated locally),9.35 per call) Clock_Ip_ReportClockErrors/14 (37904965 (estimated locally),0.33 per call) 
Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (Clock_Ip_SetCgmXCscCssCsGrip.part.0) @0640d460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au16SelectorEntryHardwareValue/9 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_axFeatureExtensions/10 (read)Clock_Ip_axFeatureExtensions/10 (read)Clock_Ip_apxCgm/11 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Clock_Ip_SetCgmXCscCssCsGrip/6 (114863532 (estimated locally),0.53 per call) 
  Calls: Clock_Ip_StartTimeout/12 (114863532 (estimated locally),1.00 per call) Clock_Ip_TimeoutExpired/13 (1073741824 (estimated locally),9.35 per call) Clock_Ip_StartTimeout/12 (57431766 (estimated locally),0.50 per call) Clock_Ip_TimeoutExpired/13 (536870910 (estimated locally),4.67 per call) Clock_Ip_ReportClockErrors/14 (18952483 (estimated locally),0.17 per call) Clock_Ip_ReportClockErrors/14 (57431766 (estimated locally),0.50 per call) 
Clock_Ip_au8SoftwareMuxResetValue/15 (Clock_Ip_au8SoftwareMuxResetValue) @06314990
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_ReportClockErrors/14 (Clock_Ip_ReportClockErrors) @0630f460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_SetCgmXCscCssClkswSwip/2 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (28715883 (estimated locally),0.09 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (9476241 (estimated locally),0.03 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (9404337 (estimated locally),0.03 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (28715883 (estimated locally),0.09 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (9476241 (estimated locally),0.03 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (9404337 (estimated locally),0.03 per call) Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (37904965 (estimated locally),0.33 per call) Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (18952483 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (57431766 (estimated locally),0.50 per call) 
  Calls: 
Clock_Ip_TimeoutExpired/13 (Clock_Ip_TimeoutExpired) @0630f380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_SetCgmXCscCssClkswSwip/2 (268435455 (estimated locally),0.80 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (536870911 (estimated locally),1.60 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (1073741824 (estimated locally),3.20 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (268435455 (estimated locally),0.80 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (536870911 (estimated locally),1.60 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (1073741824 (estimated locally),3.20 per call) Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (1073741824 (estimated locally),9.35 per call) Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (1073741824 (estimated locally),9.35 per call) Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (536870910 (estimated locally),4.67 per call) 
  Calls: 
Clock_Ip_StartTimeout/12 (Clock_Ip_StartTimeout) @0630f2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_SetCgmXCscCssClkswSwip/2 (28715883 (estimated locally),0.09 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (114863532 (estimated locally),0.34 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (28715883 (estimated locally),0.09 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (114863532 (estimated locally),0.34 per call) Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (114863532 (estimated locally),1.00 per call) Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (114863532 (estimated locally),1.00 per call) Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (57431766 (estimated locally),0.50 per call) 
  Calls: 
Clock_Ip_apxCgm/11 (Clock_Ip_apxCgm) @063143f0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axFeatureExtensions/10 (Clock_Ip_axFeatureExtensions) @063143a8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (read)Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au16SelectorEntryHardwareValue/9 (Clock_Ip_au16SelectorEntryHardwareValue) @06314360
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au8ClockFeatures/8 (Clock_Ip_au8ClockFeatures) @06314318
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (read)Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (read)Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (read)Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axSelectorCallbacks/7 (Clock_Ip_axSelectorCallbacks) @061ecbd0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_CallbackSelectorEmpty/0 (addr)Clock_Ip_CallbackSelectorEmpty/0 (addr)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (addr)Clock_Ip_SetCgmXCscCssClkswSwip/2 (addr)Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3 (addr)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (addr)Clock_Ip_ResetCgmXCscCssCsGrip/5 (addr)Clock_Ip_SetCgmXCscCssCsGrip/6 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_SetCgmXCscCssCsGrip/6 (Clock_Ip_SetCgmXCscCssCsGrip) @061ef2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/7 (addr)
  Availability: available
  Function flags: count:214818650 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_SetCgmXCscCssCsGrip.part.0/16 (114863532 (estimated locally),0.53 per call) 
Clock_Ip_ResetCgmXCscCssCsGrip/5 (Clock_Ip_ResetCgmXCscCssCsGrip) @061efee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/7 (addr)
  Availability: available
  Function flags: count:214818650 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ResetCgmXCscCssCsGrip.part.0/17 (114863532 (estimated locally),0.53 per call) 
Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip) @061efc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au16SelectorEntryHardwareValue/9 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_axFeatureExtensions/10 (read)Clock_Ip_axFeatureExtensions/10 (read)Clock_Ip_apxCgm/11 (read)
  Referring: Clock_Ip_axSelectorCallbacks/7 (addr)
  Availability: available
  Function flags: count:335701228 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ReportClockErrors/14 (57431766 (estimated locally),0.17 per call) Clock_Ip_ReportClockErrors/14 (28715883 (estimated locally),0.09 per call) Clock_Ip_ReportClockErrors/14 (9476241 (estimated locally),0.03 per call) Clock_Ip_ReportClockErrors/14 (9404337 (estimated locally),0.03 per call) Clock_Ip_TimeoutExpired/13 (268435455 (estimated locally),0.80 per call) Clock_Ip_StartTimeout/12 (28715883 (estimated locally),0.09 per call) Clock_Ip_TimeoutExpired/13 (536870911 (estimated locally),1.60 per call) Clock_Ip_StartTimeout/12 (57431766 (estimated locally),0.17 per call) Clock_Ip_TimeoutExpired/13 (1073741824 (estimated locally),3.20 per call) Clock_Ip_StartTimeout/12 (114863532 (estimated locally),0.34 per call) 
Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3 (Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip) @061ef9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/7 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_ResetCgmXCscCssClkswSwip/1 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_SetCgmXCscCssClkswSwip/2 (Clock_Ip_SetCgmXCscCssClkswSwip) @061ef700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au16SelectorEntryHardwareValue/9 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_axFeatureExtensions/10 (read)Clock_Ip_axFeatureExtensions/10 (read)Clock_Ip_apxCgm/11 (read)
  Referring: Clock_Ip_axSelectorCallbacks/7 (addr)
  Availability: available
  Function flags: count:335701228 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ReportClockErrors/14 (57431766 (estimated locally),0.17 per call) Clock_Ip_ReportClockErrors/14 (28715883 (estimated locally),0.09 per call) Clock_Ip_ReportClockErrors/14 (9476241 (estimated locally),0.03 per call) Clock_Ip_ReportClockErrors/14 (9404337 (estimated locally),0.03 per call) Clock_Ip_TimeoutExpired/13 (268435455 (estimated locally),0.80 per call) Clock_Ip_StartTimeout/12 (28715883 (estimated locally),0.09 per call) Clock_Ip_TimeoutExpired/13 (536870911 (estimated locally),1.60 per call) Clock_Ip_StartTimeout/12 (57431766 (estimated locally),0.17 per call) Clock_Ip_TimeoutExpired/13 (1073741824 (estimated locally),3.20 per call) Clock_Ip_StartTimeout/12 (114863532 (estimated locally),0.34 per call) 
Clock_Ip_ResetCgmXCscCssClkswSwip/1 (Clock_Ip_ResetCgmXCscCssClkswSwip) @061ef460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_axFeatureExtensions/10 (read)Clock_Ip_apxCgm/11 (read)
  Referring: Clock_Ip_axSelectorCallbacks/7 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_CallbackSelectorEmpty/0 (Clock_Ip_CallbackSelectorEmpty) @061ef1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/7 (addr)Clock_Ip_axSelectorCallbacks/7 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function Clock_Ip_CallbackSelectorEmpty (Clock_Ip_CallbackSelectorEmpty, funcdef_no=0, decl_uid=6375, cgraph_uid=1, symbol_order=0)

Modification phase of node Clock_Ip_CallbackSelectorEmpty/0
Clock_Ip_CallbackSelectorEmpty (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ResetCgmXCscCssClkswSwip (Clock_Ip_ResetCgmXCscCssClkswSwip, funcdef_no=1, decl_uid=6377, cgraph_uid=2, symbol_order=1)

Modification phase of node Clock_Ip_ResetCgmXCscCssClkswSwip/1
Clock_Ip_ResetCgmXCscCssClkswSwip (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 SelectorMask;
  uint32 SelectorIndex;
  uint32 Instance;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  unsigned char _4;
  unsigned char _5;
  int _6;
  volatile struct Clock_Ip_CgmMuxType * _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_14(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = Config_14(D)->Name;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][0];
  Instance_16 = (uint32) _3;
  # DEBUG Instance => Instance_16
  # DEBUG BEGIN_STMT
  _4 = Clock_Ip_au8ClockFeatures[_2][4];
  SelectorIndex_17 = (uint32) _4;
  # DEBUG SelectorIndex => SelectorIndex_17
  # DEBUG BEGIN_STMT
  _5 = Clock_Ip_au8ClockFeatures[_2][2];
  _6 = (int) _5;
  SelectorMask_18 = Clock_Ip_axFeatureExtensions[_6].SelectorValueMask;
  # DEBUG SelectorMask => SelectorMask_18
  # DEBUG BEGIN_STMT
  _7 = Clock_Ip_apxCgm[Instance_16][SelectorIndex_17];
  _8 ={v} _7->CSC;
  _9 = _8 | 8;
  _7->CSC ={v} _9;
  # DEBUG BEGIN_STMT
  _10 ={v} _7->CSC;
  _11 = ~SelectorMask_18;
  _12 = _10 & _11;
  _7->CSC ={v} _12;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip (Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip, funcdef_no=10, decl_uid=6381, cgraph_uid=4, symbol_order=3)

Modification phase of node Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3
Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  Clock_Ip_ResetCgmXCscCssClkswSwip (Config_2(D)); [tail call]
  return;

}



;; Function Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip (Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip, funcdef_no=4, decl_uid=6383, cgraph_uid=5, symbol_order=4)

Modification phase of node Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4
Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  uint32 RegValue;
  uint32 SelectorShift;
  uint32 SelectorMask;
  uint32 SelectorValue;
  uint32 SelectorIndex;
  uint32 Instance;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  unsigned char _6;
  <unnamed type> _7;
  int _8;
  short unsigned int _9;
  unsigned char _11;
  int _12;
  volatile struct Clock_Ip_CgmMuxType * _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int TimeoutTicks.3_17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int TimeoutTicks.4_21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int TimeoutTicks.5_24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  <unnamed type> _30;
  <unnamed type> _31;
  <unnamed type> _32;
  <unnamed type> _33;
  long unsigned int _38;
  long unsigned int _66;

  <bb 2> [local count: 335701228]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_39(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 21>; [30.00%]

  <bb 3> [local count: 234990860]:
  # DEBUG BEGIN_STMT
  _1 = Config_39(D)->Name;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][0];
  Instance_41 = (uint32) _3;
  # DEBUG Instance => Instance_41
  # DEBUG BEGIN_STMT
  _6 = Clock_Ip_au8ClockFeatures[_2][4];
  SelectorIndex_42 = (uint32) _6;
  # DEBUG SelectorIndex => SelectorIndex_42
  # DEBUG BEGIN_STMT
  _7 = Config_39(D)->Value;
  _8 = (int) _7;
  _9 = Clock_Ip_au16SelectorEntryHardwareValue[_8];
  SelectorValue_43 = (uint32) _9;
  # DEBUG SelectorValue => SelectorValue_43
  # DEBUG BEGIN_STMT
  _11 = Clock_Ip_au8ClockFeatures[_2][2];
  _12 = (int) _11;
  SelectorMask_44 = Clock_Ip_axFeatureExtensions[_12].SelectorValueMask;
  # DEBUG SelectorMask => SelectorMask_44
  # DEBUG BEGIN_STMT
  SelectorShift_45 = Clock_Ip_axFeatureExtensions[_12].SelectorValueShift;
  # DEBUG SelectorShift => SelectorShift_45
  # DEBUG BEGIN_STMT
  _13 = Clock_Ip_apxCgm[Instance_41][SelectorIndex_42];
  _14 ={v} _13->CSS;
  _15 = _14 & SelectorMask_44;
  _16 = _15 >> SelectorShift_45;
  if (_16 != SelectorValue_43)
    goto <bb 4>; [48.88%]
  else
    goto <bb 21>; [51.12%]

  <bb 4> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.3_17 = TimeoutTicks;
  TimeoutOccurred_48 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.3_17);
  # DEBUG TimeoutOccurred => TimeoutOccurred_48
  # DEBUG BEGIN_STMT
  _18 ={v} _13->CSS;
  _19 = _18 & 65536;
  if (_19 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686025]:
  if (TimeoutOccurred_48 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 24>; [94.50%]

  <bb 24> [local count: 958878294]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 114863532]:
  # TimeoutOccurred_4 = PHI <TimeoutOccurred_48(5), TimeoutOccurred_48(6)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_4 != 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  RegValue_50 ={v} _13->CSC;
  # DEBUG RegValue => RegValue_50
  # DEBUG BEGIN_STMT
  # DEBUG D#3 => ~SelectorMask_44
  # DEBUG RegValue => D#3 & RegValue_50
  # DEBUG BEGIN_STMT
  _20 = SelectorValue_43 << SelectorShift_45;
  _38 = _20 ^ RegValue_50;
  _66 = _38 & SelectorMask_44;
  RegValue_51 = RegValue_50 ^ _66;
  # DEBUG RegValue => RegValue_51
  # DEBUG BEGIN_STMT
  RegValue_52 = RegValue_51 | 7;
  # DEBUG RegValue => RegValue_52
  # DEBUG BEGIN_STMT
  _13->CSC ={v} RegValue_52;
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 9> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.4_21 = TimeoutTicks;
  TimeoutOccurred_56 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.4_21);
  # DEBUG TimeoutOccurred => TimeoutOccurred_56
  # DEBUG BEGIN_STMT
  _22 ={v} _13->CSS;
  _23 = _22 & 4;
  if (_23 == 0)
    goto <bb 10>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 10> [local count: 507343011]:
  if (TimeoutOccurred_56 != 0)
    goto <bb 11>; [5.50%]
  else
    goto <bb 23>; [94.50%]

  <bb 23> [local count: 479439145]:
  goto <bb 9>; [100.00%]

  <bb 11> [local count: 57431766]:
  # TimeoutOccurred_5 = PHI <TimeoutOccurred_56(9), TimeoutOccurred_56(10)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_5 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 13> [local count: 268435455]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.5_24 = TimeoutTicks;
  TimeoutOccurred_60 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.5_24);
  # DEBUG TimeoutOccurred => TimeoutOccurred_60
  # DEBUG BEGIN_STMT
  _25 ={v} _13->CSS;
  _26 = _25 & 65536;
  if (_26 != 0)
    goto <bb 14>; [94.50%]
  else
    goto <bb 15>; [5.50%]

  <bb 14> [local count: 253671505]:
  if (TimeoutOccurred_60 != 0)
    goto <bb 15>; [5.50%]
  else
    goto <bb 22>; [94.50%]

  <bb 22> [local count: 239719572]:
  goto <bb 13>; [100.00%]

  <bb 15> [local count: 28715883]:
  # TimeoutOccurred_10 = PHI <TimeoutOccurred_60(13), TimeoutOccurred_60(14)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_10 != 0)
    goto <bb 18>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 16> [local count: 19239641]:
  # DEBUG BEGIN_STMT
  _27 ={v} _13->CSS;
  _28 = _27 >> 17;
  _29 = _28 & 7;
  if (_29 != 1)
    goto <bb 17>; [48.88%]
  else
    goto <bb 21>; [51.12%]

  <bb 17> [local count: 9404337]:
  # DEBUG BEGIN_STMT
  _30 = Config_39(D)->Name;
  Clock_Ip_ReportClockErrors (3, _30);
  goto <bb 21>; [100.00%]

  <bb 18> [local count: 9476241]:
  # DEBUG BEGIN_STMT
  _31 = Config_39(D)->Name;
  Clock_Ip_ReportClockErrors (1, _31);
  goto <bb 21>; [100.00%]

  <bb 19> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  _32 = Config_39(D)->Name;
  Clock_Ip_ReportClockErrors (1, _32);
  goto <bb 21>; [100.00%]

  <bb 20> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  _33 = Config_39(D)->Name;
  Clock_Ip_ReportClockErrors (1, _33);

  <bb 21> [local count: 335701228]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Clock_Ip_SetCgmXCscCssClkswSwip (Clock_Ip_SetCgmXCscCssClkswSwip, funcdef_no=2, decl_uid=6379, cgraph_uid=3, symbol_order=2)

Modification phase of node Clock_Ip_SetCgmXCscCssClkswSwip/2
Clock_Ip_SetCgmXCscCssClkswSwip (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  uint32 RegValue;
  uint32 SelectorShift;
  uint32 SelectorMask;
  uint32 SelectorValue;
  uint32 SelectorIndex;
  uint32 Instance;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  unsigned char _6;
  <unnamed type> _7;
  int _8;
  short unsigned int _9;
  unsigned char _11;
  int _12;
  volatile struct Clock_Ip_CgmMuxType * _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int TimeoutTicks.6_17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int TimeoutTicks.7_21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int TimeoutTicks.8_24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  <unnamed type> _30;
  <unnamed type> _31;
  <unnamed type> _32;
  <unnamed type> _33;
  long unsigned int _38;
  long unsigned int _66;

  <bb 2> [local count: 335701228]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_39(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 21>; [30.00%]

  <bb 3> [local count: 234990860]:
  # DEBUG BEGIN_STMT
  _1 = Config_39(D)->Name;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][0];
  Instance_41 = (uint32) _3;
  # DEBUG Instance => Instance_41
  # DEBUG BEGIN_STMT
  _6 = Clock_Ip_au8ClockFeatures[_2][4];
  SelectorIndex_42 = (uint32) _6;
  # DEBUG SelectorIndex => SelectorIndex_42
  # DEBUG BEGIN_STMT
  _7 = Config_39(D)->Value;
  _8 = (int) _7;
  _9 = Clock_Ip_au16SelectorEntryHardwareValue[_8];
  SelectorValue_43 = (uint32) _9;
  # DEBUG SelectorValue => SelectorValue_43
  # DEBUG BEGIN_STMT
  _11 = Clock_Ip_au8ClockFeatures[_2][2];
  _12 = (int) _11;
  SelectorMask_44 = Clock_Ip_axFeatureExtensions[_12].SelectorValueMask;
  # DEBUG SelectorMask => SelectorMask_44
  # DEBUG BEGIN_STMT
  SelectorShift_45 = Clock_Ip_axFeatureExtensions[_12].SelectorValueShift;
  # DEBUG SelectorShift => SelectorShift_45
  # DEBUG BEGIN_STMT
  _13 = Clock_Ip_apxCgm[Instance_41][SelectorIndex_42];
  _14 ={v} _13->CSS;
  _15 = _14 & SelectorMask_44;
  _16 = _15 >> SelectorShift_45;
  if (_16 != SelectorValue_43)
    goto <bb 4>; [48.88%]
  else
    goto <bb 21>; [51.12%]

  <bb 4> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.6_17 = TimeoutTicks;
  TimeoutOccurred_48 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.6_17);
  # DEBUG TimeoutOccurred => TimeoutOccurred_48
  # DEBUG BEGIN_STMT
  _18 ={v} _13->CSS;
  _19 = _18 & 65536;
  if (_19 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686025]:
  if (TimeoutOccurred_48 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 24>; [94.50%]

  <bb 24> [local count: 958878294]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 114863532]:
  # TimeoutOccurred_4 = PHI <TimeoutOccurred_48(5), TimeoutOccurred_48(6)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_4 != 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  RegValue_50 ={v} _13->CSC;
  # DEBUG RegValue => RegValue_50
  # DEBUG BEGIN_STMT
  # DEBUG D#4 => ~SelectorMask_44
  # DEBUG RegValue => D#4 & RegValue_50
  # DEBUG BEGIN_STMT
  _20 = SelectorValue_43 << SelectorShift_45;
  _38 = _20 ^ RegValue_50;
  _66 = _38 & SelectorMask_44;
  RegValue_51 = RegValue_50 ^ _66;
  # DEBUG RegValue => RegValue_51
  # DEBUG BEGIN_STMT
  RegValue_52 = RegValue_51 | 4;
  # DEBUG RegValue => RegValue_52
  # DEBUG BEGIN_STMT
  _13->CSC ={v} RegValue_52;
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 9> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.7_21 = TimeoutTicks;
  TimeoutOccurred_56 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.7_21);
  # DEBUG TimeoutOccurred => TimeoutOccurred_56
  # DEBUG BEGIN_STMT
  _22 ={v} _13->CSS;
  _23 = _22 & 4;
  if (_23 == 0)
    goto <bb 10>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 10> [local count: 507343011]:
  if (TimeoutOccurred_56 != 0)
    goto <bb 11>; [5.50%]
  else
    goto <bb 23>; [94.50%]

  <bb 23> [local count: 479439145]:
  goto <bb 9>; [100.00%]

  <bb 11> [local count: 57431766]:
  # TimeoutOccurred_5 = PHI <TimeoutOccurred_56(9), TimeoutOccurred_56(10)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_5 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 13> [local count: 268435455]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.8_24 = TimeoutTicks;
  TimeoutOccurred_60 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.8_24);
  # DEBUG TimeoutOccurred => TimeoutOccurred_60
  # DEBUG BEGIN_STMT
  _25 ={v} _13->CSS;
  _26 = _25 & 65536;
  if (_26 != 0)
    goto <bb 14>; [94.50%]
  else
    goto <bb 15>; [5.50%]

  <bb 14> [local count: 253671505]:
  if (TimeoutOccurred_60 != 0)
    goto <bb 15>; [5.50%]
  else
    goto <bb 22>; [94.50%]

  <bb 22> [local count: 239719572]:
  goto <bb 13>; [100.00%]

  <bb 15> [local count: 28715883]:
  # TimeoutOccurred_10 = PHI <TimeoutOccurred_60(13), TimeoutOccurred_60(14)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_10 != 0)
    goto <bb 18>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 16> [local count: 19239641]:
  # DEBUG BEGIN_STMT
  _27 ={v} _13->CSS;
  _28 = _27 >> 17;
  _29 = _28 & 7;
  if (_29 != 1)
    goto <bb 17>; [48.88%]
  else
    goto <bb 21>; [51.12%]

  <bb 17> [local count: 9404337]:
  # DEBUG BEGIN_STMT
  _30 = Config_39(D)->Name;
  Clock_Ip_ReportClockErrors (3, _30);
  goto <bb 21>; [100.00%]

  <bb 18> [local count: 9476241]:
  # DEBUG BEGIN_STMT
  _31 = Config_39(D)->Name;
  Clock_Ip_ReportClockErrors (1, _31);
  goto <bb 21>; [100.00%]

  <bb 19> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  _32 = Config_39(D)->Name;
  Clock_Ip_ReportClockErrors (1, _32);
  goto <bb 21>; [100.00%]

  <bb 20> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  _33 = Config_39(D)->Name;
  Clock_Ip_ReportClockErrors (1, _33);

  <bb 21> [local count: 335701228]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Clock_Ip_SetCgmXCscCssCsGrip (Clock_Ip_SetCgmXCscCssCsGrip, funcdef_no=6, decl_uid=6385, cgraph_uid=7, symbol_order=6)

Modification phase of node Clock_Ip_SetCgmXCscCssCsGrip/6
Clock_Ip_SetCgmXCscCssCsGrip (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 214818650]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_3(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 114863532]:
  Clock_Ip_SetCgmXCscCssCsGrip.part.0 (Config_3(D));

  <bb 4> [local count: 214818650]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ResetCgmXCscCssCsGrip (Clock_Ip_ResetCgmXCscCssCsGrip, funcdef_no=5, decl_uid=6387, cgraph_uid=6, symbol_order=5)

Modification phase of node Clock_Ip_ResetCgmXCscCssCsGrip/5
Clock_Ip_ResetCgmXCscCssCsGrip (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 214818650]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_3(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 114863532]:
  Clock_Ip_ResetCgmXCscCssCsGrip.part.0 (Config_3(D));

  <bb 4> [local count: 214818650]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}


