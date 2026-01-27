
IPA constant propagation start:
Determining dynamic type for call: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest (&Config);
  Starting walk at: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest (&Config);
  instance pointer: &Config  Outer instance pointer: Config offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_ReportClockErrors/13:
  Jump functions of caller  Clock_Ip_TimeoutExpired/11:
  Jump functions of caller  Clock_Ip_StartTimeout/10:
  Jump functions of caller  Clock_Ip_McMeEnterKey/9:
  Jump functions of caller  Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest/3:
    callsite  Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest/3 -> Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2:
  Jump functions of caller  Clock_Ip_ClockUpdateGateEmpty/1:
  Jump functions of caller  Clock_Ip_ClockSetGateEmpty/0:

 Propagating constants:

Not considering Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ClockUpdateGateEmpty for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ClockSetGateEmpty for cloning; -fipa-cp-clone disabled.

overall_size: 110, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 2.000000
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest/3:
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
  Node: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ClockUpdateGateEmpty/1:
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
  Node: Clock_Ip_ClockSetGateEmpty/0:
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

Clock_Ip_ReportClockErrors/13 (Clock_Ip_ReportClockErrors) @062f5b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (37904965 (estimated locally),0.04 per call) Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (37904965 (estimated locally),0.04 per call) 
  Calls: 
Clock_Ip_apxMcMeGetPartitions/12 (Clock_Ip_apxMcMeGetPartitions) @062fc5a0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_TimeoutExpired/11 (Clock_Ip_TimeoutExpired) @062f5a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (1073741824 (estimated locally),1.08 per call) Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (1073741824 (estimated locally),1.08 per call) 
  Calls: 
Clock_Ip_StartTimeout/10 (Clock_Ip_StartTimeout) @062f59a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (114863532 (estimated locally),0.12 per call) Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (114863532 (estimated locally),0.12 per call) 
  Calls: 
Clock_Ip_McMeEnterKey/9 (Clock_Ip_McMeEnterKey) @062f58c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (114863532 (estimated locally),0.12 per call) Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (114863532 (estimated locally),0.12 per call) 
  Calls: 
Clock_Ip_apxMcMeTriggerPartitions/8 (Clock_Ip_apxMcMeTriggerPartitions) @062fc480
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_apxMcMeSetPartitions/7 (Clock_Ip_apxMcMeSetPartitions) @062fc438
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axGateInfo/6 (Clock_Ip_axGateInfo) @062fc3f0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au8ClockFeatures/5 (Clock_Ip_au8ClockFeatures) @062fc3a8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axGateCallbacks/4 (Clock_Ip_axGateCallbacks) @062eb900
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_ClockSetGateEmpty/0 (addr)Clock_Ip_ClockUpdateGateEmpty/1 (addr)Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (addr)Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest/3 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest/3 (Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest) @062f51c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axGateCallbacks/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2 (Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest) @062e9e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/5 (read)Clock_Ip_axGateInfo/6 (read)Clock_Ip_axGateInfo/6 (read)Clock_Ip_axGateInfo/6 (read)Clock_Ip_apxMcMeSetPartitions/7 (read)Clock_Ip_apxMcMeTriggerPartitions/8 (read)Clock_Ip_apxMcMeGetPartitions/12 (read)Clock_Ip_apxMcMeSetPartitions/7 (read)Clock_Ip_apxMcMeTriggerPartitions/8 (read)Clock_Ip_apxMcMeGetPartitions/12 (read)
  Referring: Clock_Ip_axGateCallbacks/4 (addr)
  Availability: available
  Function flags: count:994489456 (estimated locally) body optimize_size
  Called by: Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: Clock_Ip_ReportClockErrors/13 (37904965 (estimated locally),0.04 per call) Clock_Ip_TimeoutExpired/11 (1073741824 (estimated locally),1.08 per call) Clock_Ip_StartTimeout/10 (114863532 (estimated locally),0.12 per call) Clock_Ip_McMeEnterKey/9 (114863532 (estimated locally),0.12 per call) Clock_Ip_ReportClockErrors/13 (37904965 (estimated locally),0.04 per call) Clock_Ip_TimeoutExpired/11 (1073741824 (estimated locally),1.08 per call) Clock_Ip_StartTimeout/10 (114863532 (estimated locally),0.12 per call) Clock_Ip_McMeEnterKey/9 (114863532 (estimated locally),0.12 per call) 
Clock_Ip_ClockUpdateGateEmpty/1 (Clock_Ip_ClockUpdateGateEmpty) @062e9000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axGateCallbacks/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ClockSetGateEmpty/0 (Clock_Ip_ClockSetGateEmpty) @062e9d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axGateCallbacks/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function Clock_Ip_ClockSetGateEmpty (Clock_Ip_ClockSetGateEmpty, funcdef_no=0, decl_uid=6368, cgraph_uid=1, symbol_order=0)

Modification phase of node Clock_Ip_ClockSetGateEmpty/0
Clock_Ip_ClockSetGateEmpty (const struct Clock_Ip_GateConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ClockUpdateGateEmpty (Clock_Ip_ClockUpdateGateEmpty, funcdef_no=1, decl_uid=6371, cgraph_uid=2, symbol_order=1)

Modification phase of node Clock_Ip_ClockUpdateGateEmpty/1
Clock_Ip_ClockUpdateGateEmpty (Clock_Ip_NameType ClockName, boolean Gate)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest (Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest, funcdef_no=2, decl_uid=6373, cgraph_uid=3, symbol_order=2)

Modification phase of node Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest/2
Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest (const struct Clock_Ip_GateConfigType * Config)
{
  uint32 EnableRequest;
  uint32 Collection;
  uint32 Partition;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  int _4;
  unsigned char _5;
  unsigned char _6;
  short unsigned int _7;
  volatile struct Clock_Ip_McmePartitionSetType * _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  volatile struct Clock_Ip_McmePartitionTriggerType * _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int TimeoutTicks.0_18;
  const volatile struct Clock_Ip_McmePartitionGetType * _19;
  long unsigned int _20;
  long unsigned int _21;
  <unnamed type> _22;
  volatile struct Clock_Ip_McmePartitionSetType * _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _30;
  volatile struct Clock_Ip_McmePartitionTriggerType * _31;
  long unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _35;
  long unsigned int TimeoutTicks.1_36;
  const volatile struct Clock_Ip_McmePartitionGetType * _37;
  long unsigned int _38;
  long unsigned int _39;
  <unnamed type> _40;

  <bb 2> [local count: 994489456]:
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_44(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 16>; [30.00%]

  <bb 3> [local count: 696142620]:
  # DEBUG BEGIN_STMT
  _1 = Config_44(D)->Name;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][6];
  _4 = (int) _3;
  # DEBUG D#1 => &Clock_Ip_axGateInfo[_4]
  # DEBUG GateInformation => D#1
  # DEBUG BEGIN_STMT
  _5 = MEM[(const struct Clock_Ip_GateInfoType *)&Clock_Ip_axGateInfo][_4].PartitionValue;
  Partition_46 = (uint32) _5;
  # DEBUG Partition => Partition_46
  # DEBUG BEGIN_STMT
  _6 = MEM[(const struct Clock_Ip_GateInfoType *)&Clock_Ip_axGateInfo][_4].ColectionValue;
  Collection_47 = (uint32) _6;
  # DEBUG Collection => Collection_47
  # DEBUG BEGIN_STMT
  EnableRequest_48 = MEM[(const struct Clock_Ip_GateInfoType *)&Clock_Ip_axGateInfo][_4].RequestValueMask;
  # DEBUG EnableRequest => EnableRequest_48
  # DEBUG BEGIN_STMT
  _7 = Config_44(D)->Enable;
  if (_7 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 4> [local count: 348071310]:
  # DEBUG BEGIN_STMT
  _8 = Clock_Ip_apxMcMeSetPartitions[Partition_46];
  _9 ={v} _8->PRTN_COFB_CLKEN[Collection_47];
  _10 = _9 & EnableRequest_48;
  if (_10 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 5> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _11 ={v} _8->PRTN_COFB_CLKEN[Collection_47];
  _12 = _11 | EnableRequest_48;
  _8->PRTN_COFB_CLKEN[Collection_47] ={v} _12;
  # DEBUG BEGIN_STMT
  _13 = Clock_Ip_apxMcMeTriggerPartitions[Partition_46];
  _14 ={v} _13->PRTN_PCONF;
  _15 = _14 | 1;
  _13->PRTN_PCONF ={v} _15;
  # DEBUG BEGIN_STMT
  _16 ={v} _13->PRTN_PUPD;
  _17 = _16 | 1;
  _13->PRTN_PUPD ={v} _17;
  # DEBUG BEGIN_STMT
  Clock_Ip_McMeEnterKey ();
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.0_18 = TimeoutTicks;
  TimeoutOccurred_63 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.0_18);
  # DEBUG TimeoutOccurred => TimeoutOccurred_63
  # DEBUG BEGIN_STMT
  _19 = Clock_Ip_apxMcMeGetPartitions[Partition_46];
  _20 ={v} _19->PRTN_COFB_STAT[Collection_47];
  _21 = _20 & EnableRequest_48;
  if (_21 == 0)
    goto <bb 7>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 7> [local count: 1014686025]:
  if (TimeoutOccurred_63 != 0)
    goto <bb 8>; [5.50%]
  else
    goto <bb 17>; [94.50%]

  <bb 17> [local count: 958878293]:
  goto <bb 6>; [100.00%]

  <bb 8> [local count: 114863532]:
  # TimeoutOccurred_29 = PHI <TimeoutOccurred_63(6), TimeoutOccurred_63(7)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_29 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 9> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  _22 = Config_44(D)->Name;
  Clock_Ip_ReportClockErrors (1, _22);
  goto <bb 16>; [100.00%]

  <bb 10> [local count: 348071310]:
  # DEBUG BEGIN_STMT
  _23 = Clock_Ip_apxMcMeSetPartitions[Partition_46];
  _24 ={v} _23->PRTN_COFB_CLKEN[Collection_47];
  _25 = _24 & EnableRequest_48;
  if (_25 != 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 11> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _27 ={v} _23->PRTN_COFB_CLKEN[Collection_47];
  _28 = ~EnableRequest_48;
  _30 = _27 & _28;
  _23->PRTN_COFB_CLKEN[Collection_47] ={v} _30;
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_apxMcMeTriggerPartitions[Partition_46];
  _32 ={v} _31->PRTN_PCONF;
  _33 = _32 | 1;
  _31->PRTN_PCONF ={v} _33;
  # DEBUG BEGIN_STMT
  _34 ={v} _31->PRTN_PUPD;
  _35 = _34 | 1;
  _31->PRTN_PUPD ={v} _35;
  # DEBUG BEGIN_STMT
  Clock_Ip_McMeEnterKey ();
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 12> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.1_36 = TimeoutTicks;
  TimeoutOccurred_55 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.1_36);
  # DEBUG TimeoutOccurred => TimeoutOccurred_55
  # DEBUG BEGIN_STMT
  _37 = Clock_Ip_apxMcMeGetPartitions[Partition_46];
  _38 ={v} _37->PRTN_COFB_STAT[Collection_47];
  _39 = _38 & EnableRequest_48;
  if (_39 != 0)
    goto <bb 13>; [94.50%]
  else
    goto <bb 14>; [5.50%]

  <bb 13> [local count: 1014686025]:
  if (TimeoutOccurred_55 != 0)
    goto <bb 14>; [5.50%]
  else
    goto <bb 18>; [94.50%]

  <bb 18> [local count: 958878293]:
  goto <bb 12>; [100.00%]

  <bb 14> [local count: 114863532]:
  # TimeoutOccurred_26 = PHI <TimeoutOccurred_55(12), TimeoutOccurred_55(13)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_26 != 0)
    goto <bb 15>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 15> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  _40 = Config_44(D)->Name;
  Clock_Ip_ReportClockErrors (1, _40);

  <bb 16> [local count: 994489455]:
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



;; Function Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest (Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest, funcdef_no=3, decl_uid=6376, cgraph_uid=4, symbol_order=3)

Modification phase of node Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest/3
Clock_Ip_ClockUpdateGateMcMePartitionCollectionClockRequest (Clock_Ip_NameType ClockName, boolean Gate)
{
  struct Clock_Ip_GateConfigType Config;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Config.Name = ClockName_3(D);
  # DEBUG BEGIN_STMT
  if (Gate_5(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Config.Enable = 0;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Config.Enable = 1;

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ClockSetGateMcMePartitionCollectionClockRequest (&Config);
  Config ={v} {CLOBBER};
  return;

}


