
IPA constant propagation start:
Determining dynamic type for call: Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0 (Config_4(D), Index_6(D));
  Starting walk at: Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0 (Config_4(D), Index_6(D));
  instance pointer: Config_4(D)  Outer instance pointer: Config_4(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22:
  Jump functions of caller  SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01/20:
  Jump functions of caller  Clock_Ip_TimeoutExpired/19:
  Jump functions of caller  Clock_Ip_StartTimeout/18:
  Jump functions of caller  SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01/17:
  Jump functions of caller  Clock_Ip_ReportClockErrors/14:
  Jump functions of caller  Clock_Ip_CMU_ClockFailInt/9:
  Jump functions of caller  Clock_Ip_CMU_GetInterruptStatus/8:
  Jump functions of caller  Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/7:
  Jump functions of caller  Clock_Ip_SetCmuFcFceRefCntLfrefHfref/6:
    callsite  Clock_Ip_SetCmuFcFceRefCntLfrefHfref/6 -> Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/5:
    callsite  Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/5 -> Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4:
  Jump functions of caller  Clock_Ip_ClockMonitorEmpty_Disable/3:
  Jump functions of caller  Clock_Ip_ClockMonitorEmpty_Set/2:
  Jump functions of caller  Clock_Ip_ClockMonitorEmpty/1:

 Propagating constants:

Not considering Clock_Ip_CMU_ClockFailInt for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_CMU_GetInterruptStatus for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_EnableCmuFcFceRefCntLfrefHfref for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SetCmuFcFceRefCntLfrefHfref for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ResetCmuFcFceRefCntLfrefHfref for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_DisableCmuFcFceRefCntLfrefHfref for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ClockMonitorEmpty_Disable for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ClockMonitorEmpty_Set for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ClockMonitorEmpty for cloning; -fipa-cp-clone disabled.

overall_size: 178, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 2.000000
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22:
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
  Node: Clock_Ip_CMU_ClockFailInt/9:
  Node: Clock_Ip_CMU_GetInterruptStatus/8:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetCmuFcFceRefCntLfrefHfref/6:
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
  Node: Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ClockMonitorEmpty_Disable/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ClockMonitorEmpty_Set/2:
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
  Node: Clock_Ip_ClockMonitorEmpty/1:
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

Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0) @064082a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: Clock_Ip_au8ClockFeatures/15 (read)Clock_Ip_axCmuInfo/16 (read)HashCmu/0 (read)HashCmu/0 (write)Clock_Ip_pxConfig/12 (read)Clock_Ip_axCmuInfo/16 (read)Clock_Ip_FreqIds/21 (read)Clock_Ip_axCmuInfo/16 (read)Clock_Ip_FreqIds/21 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Clock_Ip_SetCmuFcFceRefCntLfrefHfref/6 (375809639 (estimated locally),0.35 per call) 
  Calls: 
Clock_Ip_FreqIds/21 (Clock_Ip_FreqIds) @063ff0d8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (read)Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (read)
  Availability: not_available
  Varpool flags:
SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01/20 (SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01) @06375460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (348071309 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_TimeoutExpired/19 (Clock_Ip_TimeoutExpired) @06375380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (1073741824 (estimated locally),3.08 per call) 
  Calls: 
Clock_Ip_StartTimeout/18 (Clock_Ip_StartTimeout) @063752a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (114863532 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01/17 (SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01) @063751c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (348071309 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_axCmuInfo/16 (Clock_Ip_axCmuInfo) @06372750
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/7 (read)Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (read)Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (read)Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (read)Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au8ClockFeatures/15 (Clock_Ip_au8ClockFeatures) @06372708
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/7 (read)Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (read)Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_ReportClockErrors/14 (Clock_Ip_ReportClockErrors) @06357380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_CMU_ClockFailInt/9 (238857090 (estimated locally),6.01 per call) Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (37904965 (estimated locally),0.11 per call) 
  Calls: 
Clock_Ip_aeCmuNames/13 (Clock_Ip_aeCmuNames) @06372438
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CMU_ClockFailInt/9 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_pxConfig/12 (Clock_Ip_pxConfig) @063723f0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (read)Clock_Ip_CMU_ClockFailInt/9 (read)
  Availability: not_available
  Varpool flags:
Clock_Ip_apxCmu/11 (Clock_Ip_apxCmu) @06372048
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CMU_GetInterruptStatus/8 (read)Clock_Ip_CMU_ClockFailInt/9 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axCmuCallbacks/10 (Clock_Ip_axCmuCallbacks) @0634fcf0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_ClockMonitorEmpty/1 (addr)Clock_Ip_ClockMonitorEmpty_Set/2 (addr)Clock_Ip_ClockMonitorEmpty_Disable/3 (addr)Clock_Ip_ClockMonitorEmpty/1 (addr)Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/5 (addr)Clock_Ip_SetCmuFcFceRefCntLfrefHfref/6 (addr)Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (addr)Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/7 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_CMU_ClockFailInt/9 (Clock_Ip_CMU_ClockFailInt) @06357a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_apxCmu/11 (read)Clock_Ip_pxConfig/12 (read)Clock_Ip_aeCmuNames/13 (read)
  Referring: 
  Availability: available
  Function flags: count:39728448 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ReportClockErrors/14 (238857090 (estimated locally),6.01 per call) 
Clock_Ip_CMU_GetInterruptStatus/8 (Clock_Ip_CMU_GetInterruptStatus) @063577e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_apxCmu/11 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/7 (Clock_Ip_EnableCmuFcFceRefCntLfrefHfref) @06357540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/15 (read)Clock_Ip_axCmuInfo/16 (read)
  Referring: Clock_Ip_axCmuCallbacks/10 (addr)
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_SetCmuFcFceRefCntLfrefHfref/6 (Clock_Ip_SetCmuFcFceRefCntLfrefHfref) @063572a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/10 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (375809639 (estimated locally),0.35 per call) 
Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/5 (Clock_Ip_ResetCmuFcFceRefCntLfrefHfref) @06357000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/10 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (574129754 (estimated locally),0.53 per call) 
Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4 (Clock_Ip_DisableCmuFcFceRefCntLfrefHfref) @06350a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/15 (read)Clock_Ip_axCmuInfo/16 (read)
  Referring: Clock_Ip_axCmuCallbacks/10 (addr)
  Availability: available
  Function flags: count:348071309 (estimated locally) body optimize_size
  Called by: Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/5 (574129754 (estimated locally),0.53 per call) 
  Calls: SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01/20 (348071309 (estimated locally),1.00 per call) Clock_Ip_ReportClockErrors/14 (37904965 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/19 (1073741824 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/18 (114863532 (estimated locally),0.33 per call) SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01/17 (348071309 (estimated locally),1.00 per call) 
Clock_Ip_ClockMonitorEmpty_Disable/3 (Clock_Ip_ClockMonitorEmpty_Disable) @06350ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/10 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ClockMonitorEmpty_Set/2 (Clock_Ip_ClockMonitorEmpty_Set) @06350c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/10 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ClockMonitorEmpty/1 (Clock_Ip_ClockMonitorEmpty) @063509a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/10 (addr)Clock_Ip_axCmuCallbacks/10 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
HashCmu/0 (HashCmu) @0634f1f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (read)Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0/22 (write)
  Availability: available
  Varpool flags:

;; Function Clock_Ip_ClockMonitorEmpty (Clock_Ip_ClockMonitorEmpty, funcdef_no=0, decl_uid=6388, cgraph_uid=1, symbol_order=1)

Modification phase of node Clock_Ip_ClockMonitorEmpty/1
Clock_Ip_ClockMonitorEmpty (const struct Clock_Ip_CmuConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ClockMonitorEmpty_Set (Clock_Ip_ClockMonitorEmpty_Set, funcdef_no=1, decl_uid=6391, cgraph_uid=2, symbol_order=2)

Modification phase of node Clock_Ip_ClockMonitorEmpty_Set/2
Clock_Ip_ClockMonitorEmpty_Set (const struct Clock_Ip_CmuConfigType * Config, uint32 Index)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ClockMonitorEmpty_Disable (Clock_Ip_ClockMonitorEmpty_Disable, funcdef_no=2, decl_uid=6393, cgraph_uid=3, symbol_order=3)

Modification phase of node Clock_Ip_ClockMonitorEmpty_Disable/3
Clock_Ip_ClockMonitorEmpty_Disable (Clock_Ip_NameType Name)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_EnableCmuFcFceRefCntLfrefHfref (Clock_Ip_EnableCmuFcFceRefCntLfrefHfref, funcdef_no=6, decl_uid=6402, cgraph_uid=7, symbol_order=7)

Modification phase of node Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/7
Clock_Ip_EnableCmuFcFceRefCntLfrefHfref (const struct Clock_Ip_CmuConfigType * Config)
{
  struct Clock_Ip_ClockMonitorType * CmuFc;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  int _4;
  unsigned char _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_11(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 751619277]:
  # DEBUG BEGIN_STMT
  _1 = Config_11(D)->Name;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][8];
  _4 = (int) _3;
  # DEBUG D#2 => &Clock_Ip_axCmuInfo[_4]
  # DEBUG CmuInformation => D#2
  # DEBUG BEGIN_STMT
  CmuFc_13 = MEM[(const struct Clock_Ip_CmuInfoType *)&Clock_Ip_axCmuInfo][_4].CmuInstance;
  # DEBUG CmuFc => CmuFc_13
  # DEBUG BEGIN_STMT
  _5 = Config_11(D)->Enable;
  if (_5 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _6 = CmuFc_13->GCR;
  _7 = _6 | 1;
  CmuFc_13->GCR = _7;
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _8 = CmuFc_13->GCR;
  _9 = _8 & 4294967294;
  CmuFc_13->GCR = _9;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_DisableCmuFcFceRefCntLfrefHfref (Clock_Ip_DisableCmuFcFceRefCntLfrefHfref, funcdef_no=3, decl_uid=6400, cgraph_uid=4, symbol_order=4)

Modification phase of node Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/4
Clock_Ip_DisableCmuFcFceRefCntLfrefHfref (Clock_Ip_NameType Name)
{
  uint32 FrequencyCheckStatus;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  struct Clock_Ip_ClockMonitorType * const CmuFc;
  int _1;
  unsigned char _2;
  int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int TimeoutTicks.1_7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;

  <bb 2> [local count: 348071309]:
  # DEBUG BEGIN_STMT
  _1 = (int) Name_17(D);
  _2 = Clock_Ip_au8ClockFeatures[_1][8];
  _3 = (int) _2;
  # DEBUG D#3 => &Clock_Ip_axCmuInfo[_3]
  # DEBUG CmuInformation => D#3
  # DEBUG BEGIN_STMT
  CmuFc_20 = MEM[(const struct Clock_Ip_CmuInfoType *)&Clock_Ip_axCmuInfo][_3].CmuInstance;
  # DEBUG CmuFc => CmuFc_20
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01 ();
  # DEBUG BEGIN_STMT
  _4 = CmuFc_20->GCR;
  _5 = _4 & 1;
  if (_5 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 3> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 ={v} CmuFc_20->SR;
  FrequencyCheckStatus_23 = _6 & 16;
  # DEBUG FrequencyCheckStatus => FrequencyCheckStatus_23
  # DEBUG BEGIN_STMT
  TimeoutTicks.1_7 = TimeoutTicks;
  TimeoutOccurred_25 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.1_7);
  # DEBUG TimeoutOccurred => TimeoutOccurred_25
  # DEBUG BEGIN_STMT
  if (FrequencyCheckStatus_23 == 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 5> [local count: 1014686025]:
  if (TimeoutOccurred_25 != 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 10>; [94.50%]

  <bb 10> [local count: 958878292]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 114863532]:
  # TimeoutOccurred_19 = PHI <TimeoutOccurred_25(4), TimeoutOccurred_25(5)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_19 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (1, Name_17(D));

  <bb 8> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _8 = CmuFc_20->GCR;
  _9 = _8 & 4294967294;
  CmuFc_20->GCR = _9;

  <bb 9> [local count: 348071309]:
  # DEBUG BEGIN_STMT
  _10 = CmuFc_20->IER;
  _11 = _10 & 4294967280;
  CmuFc_20->IER = _11;
  # DEBUG BEGIN_STMT
  _12 ={v} CmuFc_20->SR;
  _13 = _12 | 3;
  CmuFc_20->SR ={v} _13;
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01 ();
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Clock_Ip_ResetCmuFcFceRefCntLfrefHfref (Clock_Ip_ResetCmuFcFceRefCntLfrefHfref, funcdef_no=4, decl_uid=6395, cgraph_uid=5, symbol_order=5)

Modification phase of node Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/5
Clock_Ip_ResetCmuFcFceRefCntLfrefHfref (const struct Clock_Ip_CmuConfigType * Config)
{
  <unnamed type> _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (Config_3(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _1 = Config_3(D)->Name;
  Clock_Ip_DisableCmuFcFceRefCntLfrefHfref (_1);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Clock_Ip_SetCmuFcFceRefCntLfrefHfref (Clock_Ip_SetCmuFcFceRefCntLfrefHfref, funcdef_no=5, decl_uid=6398, cgraph_uid=6, symbol_order=6)

Modification phase of node Clock_Ip_SetCmuFcFceRefCntLfrefHfref/6
Clock_Ip_SetCmuFcFceRefCntLfrefHfref (const struct Clock_Ip_CmuConfigType * Config, uint32 Index)
{
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ReferenceClk => 0
  # DEBUG BEGIN_STMT
  # DEBUG MonitoredClk => 0
  # DEBUG BEGIN_STMT
  # DEBUG BusClk => 0
  # DEBUG BEGIN_STMT
  # DEBUG RefCount => 0
  # DEBUG BEGIN_STMT
  # DEBUG HfRef => 0
  # DEBUG BEGIN_STMT
  # DEBUG LfRef => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619278]:
  _1 = Config_4(D)->Enable;
  if (_1 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 375809639]:
  Clock_Ip_SetCmuFcFceRefCntLfrefHfref.part.0 (Config_4(D), Index_6(D));

  <bb 5> [local count: 1073741824]:
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
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_CMU_GetInterruptStatus (Clock_Ip_CMU_GetInterruptStatus, funcdef_no=7, decl_uid=6357, cgraph_uid=8, symbol_order=8)

Modification phase of node Clock_Ip_CMU_GetInterruptStatus/8
Clock_Ip_CMU_GetInterruptStatus (uint8 IndexCmu)
{
  uint32 CmuIsrValue;
  int _1;
  struct Clock_Ip_ClockMonitorType * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) IndexCmu_4(D);
  _2 = Clock_Ip_apxCmu[_1];
  _3 ={v} _2->SR;
  CmuIsrValue_6 = _3 & 3;
  # DEBUG CmuIsrValue => CmuIsrValue_6
  # DEBUG BEGIN_STMT
  return CmuIsrValue_6;

}



;; Function Clock_Ip_CMU_ClockFailInt (Clock_Ip_CMU_ClockFailInt, funcdef_no=8, decl_uid=6359, cgraph_uid=9, symbol_order=9)

Modification phase of node Clock_Ip_CMU_ClockFailInt/9
Clock_Ip_CMU_ClockFailInt ()
{
  uint32 IndexCmu;
  uint32 CmuIsrValue;
  struct Clock_Ip_ClockMonitorType * _1;
  long unsigned int _2;
  const struct Clock_Ip_ClockConfigType * Clock_Ip_pxConfig.0_3;
  long unsigned int _4;
  <unnamed type> _5;

  <bb 2> [local count: 39728448]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG CmuIsrValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG IndexCmu => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 1034013377]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_apxCmu[IndexCmu_6];
  _2 ={v} _1->SR;
  CmuIsrValue_10 = _2 & 3;
  # DEBUG CmuIsrValue => CmuIsrValue_10
  # DEBUG BEGIN_STMT
  Clock_Ip_pxConfig.0_3 = Clock_Ip_pxConfig;
  if (Clock_Ip_pxConfig.0_3 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 4> [local count: 723809364]:
  # DEBUG BEGIN_STMT
  _4 = _1->IER;
  # DEBUG CmuIerValue => _4 & 3
  # DEBUG BEGIN_STMT
  CmuIsrValue_12 = _4 & CmuIsrValue_10;
  # DEBUG CmuIsrValue => CmuIsrValue_12
  # DEBUG BEGIN_STMT
  if (CmuIsrValue_12 != 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 5> [local count: 238857090]:
  # DEBUG BEGIN_STMT
  _1->SR ={v} CmuIsrValue_12;
  # DEBUG BEGIN_STMT
  _5 = Clock_Ip_aeCmuNames[IndexCmu_6];
  Clock_Ip_ReportClockErrors (0, _5);
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 310204013]:
  # DEBUG BEGIN_STMT
  _1->SR ={v} CmuIsrValue_10;

  <bb 7> [local count: 1034013377]:
  # DEBUG BEGIN_STMT
  IndexCmu_15 = IndexCmu_6 + 1;
  # DEBUG IndexCmu => IndexCmu_15

  <bb 8> [local count: 1073741824]:
  # IndexCmu_6 = PHI <0(2), IndexCmu_15(7)>
  # DEBUG IndexCmu => IndexCmu_6
  # DEBUG BEGIN_STMT
  if (IndexCmu_6 != 26)
    goto <bb 3>; [96.30%]
  else
    goto <bb 9>; [3.70%]

  <bb 9> [local count: 39728448]:
  return;

}


