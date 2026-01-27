
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_SpecificPlatformInitClock.isra.0/14:
    callsite  Clock_Ip_SpecificPlatformInitClock.isra.0/14 -> Clock_Ip_PowerClockIpModules/1 : 
  Jump functions of caller  Clock_Ip_ReportClockErrors/13:
  Jump functions of caller  Clock_Ip_TimeoutExpired/12:
  Jump functions of caller  Clock_Ip_StartTimeout/11:
  Jump functions of caller  Sys_GetCoreID/8:
  Jump functions of caller  SRAMController_SetRamIWS/7:
  Jump functions of caller  Clock_Ip_Command/6:
    callsite  Clock_Ip_Command/6 -> Clock_Ip_SpecificPlatformInitClock.isra.0/14 : 
  Jump functions of caller  Clock_Ip_McMeEnterKey/4:
  Jump functions of caller  Clock_Ip_SetRamWaitStates/3:
    callsite  Clock_Ip_SetRamWaitStates/3 -> SRAMController_SetRamIWS/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
  Jump functions of caller  Clock_Ip_PowerClockIpModules/1:
    callsite  Clock_Ip_PowerClockIpModules/1 -> Clock_Ip_McMeEnterKey/4 : 
    callsite  Clock_Ip_PowerClockIpModules/1 -> Clock_Ip_McMeEnterKey/4 : 

 Propagating constants:

Not considering SRAMController_SetRamIWS for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Command for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_McMeEnterKey for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SetRamWaitStates for cloning; -fipa-cp-clone disabled.

overall_size: 233, max_new_size: 11001
 - context independent values, size: 6, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_SpecificPlatformInitClock.isra.0/14:
  Node: SRAMController_SetRamIWS/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_Command/6:
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
  Node: Clock_Ip_McMeEnterKey/4:
  Node: Clock_Ip_SetRamWaitStates/3:
  Node: Clock_Ip_PowerClockIpModules/1:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Clock_Ip_SpecificPlatformInitClock.isra.0/14 (Clock_Ip_SpecificPlatformInitClock.isra.0) @063a72a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Clock_Ip_Command/6 (217325345 (estimated locally),0.20 per call) 
  Calls: Clock_Ip_PowerClockIpModules/1 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_ReportClockErrors/13 (Clock_Ip_ReportClockErrors) @063272a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SRAMController_SetRamIWS/7 (310556958 (estimated locally),2.95 per call) SRAMController_SetRamIWS/7 (37904966 (estimated locally),0.36 per call) Clock_Ip_PowerClockIpModules/1 (12508639 (estimated locally),0.11 per call) Clock_Ip_PowerClockIpModules/1 (37904965 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/1 (12508639 (estimated locally),0.11 per call) 
  Calls: 
Clock_Ip_TimeoutExpired/12 (Clock_Ip_TimeoutExpired) @063271c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SRAMController_SetRamIWS/7 (1073741824 (estimated locally),10.21 per call) Clock_Ip_PowerClockIpModules/1 (354334801 (estimated locally),3.08 per call) Clock_Ip_PowerClockIpModules/1 (1073741824 (estimated locally),9.35 per call) Clock_Ip_PowerClockIpModules/1 (354334803 (estimated locally),3.08 per call) 
  Calls: 
Clock_Ip_StartTimeout/11 (Clock_Ip_StartTimeout) @063270e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SRAMController_SetRamIWS/7 (114863532 (estimated locally),1.09 per call) Clock_Ip_PowerClockIpModules/1 (37904965 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/1 (114863532 (estimated locally),1.00 per call) Clock_Ip_PowerClockIpModules/1 (37904966 (estimated locally),0.33 per call) 
  Calls: 
Clock_Ip_FreqIds/10 (Clock_Ip_FreqIds) @06317990
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetRamWaitStates/3 (read)Clock_Ip_SetRamWaitStates/3 (read)
  Availability: not_available
  Varpool flags:
Clock_Ip_pxConfig/9 (Clock_Ip_pxConfig) @06317948
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetRamWaitStates/3 (read)Clock_Ip_SetRamWaitStates/3 (read)
  Availability: not_available
  Varpool flags:
Sys_GetCoreID/8 (Sys_GetCoreID) @0631cd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_SetRamWaitStates/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SRAMController_SetRamIWS/7 (SRAMController_SetRamIWS) @0631c8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:105160121 (estimated locally) body optimize_size
  Called by: Clock_Ip_SetRamWaitStates/3 (1073634451 (estimated locally),1.00 per call) 
  Calls: Clock_Ip_ReportClockErrors/13 (310556958 (estimated locally),2.95 per call) Clock_Ip_ReportClockErrors/13 (37904966 (estimated locally),0.36 per call) Clock_Ip_TimeoutExpired/12 (1073741824 (estimated locally),10.21 per call) Clock_Ip_StartTimeout/11 (114863532 (estimated locally),1.09 per call) 
Clock_Ip_Command/6 (Clock_Ip_Command) @0631c460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_SpecificPlatformInitClock.isra.0/14 (217325345 (estimated locally),0.20 per call) 
Clock_Ip_McMeEnterKey/4 (Clock_Ip_McMeEnterKey) @062fcd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_PowerClockIpModules/1 (37904965 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/1 (37904966 (estimated locally),0.33 per call) 
  Calls: 
Clock_Ip_SetRamWaitStates/3 (Clock_Ip_SetRamWaitStates) @062fca80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_pxConfig/9 (read)Clock_Ip_FreqIds/10 (read)Clock_Ip_pxConfig/9 (read)Clock_Ip_FreqIds/10 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SRAMController_SetRamIWS/7 (1073634451 (estimated locally),1.00 per call) Sys_GetCoreID/8 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_PowerClockIpModules/1 (Clock_Ip_PowerClockIpModules) @062fc540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Clock_Ip_SpecificPlatformInitClock.isra.0/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: Clock_Ip_ReportClockErrors/13 (12508639 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/12 (354334801 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/11 (37904965 (estimated locally),0.33 per call) Clock_Ip_McMeEnterKey/4 (37904965 (estimated locally),0.33 per call) Clock_Ip_ReportClockErrors/13 (37904965 (estimated locally),0.33 per call) Clock_Ip_TimeoutExpired/12 (1073741824 (estimated locally),9.35 per call) Clock_Ip_StartTimeout/11 (114863532 (estimated locally),1.00 per call) Clock_Ip_ReportClockErrors/13 (12508639 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/12 (354334803 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/11 (37904966 (estimated locally),0.33 per call) Clock_Ip_McMeEnterKey/4 (37904966 (estimated locally),0.33 per call) 

;; Function Clock_Ip_McMeEnterKey (Clock_Ip_McMeEnterKey, funcdef_no=3, decl_uid=6186, cgraph_uid=4, symbol_order=4)

Modification phase of node Clock_Ip_McMeEnterKey/4
Clock_Ip_McMeEnterKey ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  MEM[(struct MC_ME_Type *)1074593792B].CTL_KEY ={v} 23280;
  # DEBUG BEGIN_STMT
  MEM[(struct MC_ME_Type *)1074593792B].CTL_KEY ={v} 42255;
  return;

}



;; Function Clock_Ip_Command (Clock_Ip_Command, funcdef_no=5, decl_uid=6357, cgraph_uid=6, symbol_order=6)

Modification phase of node Clock_Ip_Command/6
Clock_Ip_Command (const struct Clock_Ip_ClockConfigType * Config, Clock_Ip_CommandType Command)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (Command_2(D) == 1)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 217325345]:
<L0>:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => Config_4(D)
  Clock_Ip_SpecificPlatformInitClock.isra.0 ();
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function SRAMController_SetRamIWS (SRAMController_SetRamIWS, funcdef_no=6, decl_uid=6371, cgraph_uid=7, symbol_order=7)

Modification phase of node SRAMController_SetRamIWS/7
SRAMController_SetRamIWS (uint32 IwsSetting)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  uint32 Index;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int TimeoutTicks.5_12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;

  <bb 2> [local count: 105160121]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Index => 0
  goto <bb 14>; [100.00%]

  <bb 3> [local count: 850840980]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct SRAMC_Type *)1140883456B].PRAMCR;
  _2 = _1 & 1;
  if (_2 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 425420490]:
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct SRAMC_Type *)1140883456B].PRAMCR;
  _4 = _3 & 4294967289;
  _5 = IwsSetting_35(D) << 1;
  _6 = _5 & 6;
  _7 = _4 | _6;
  MEM[(struct SRAMC_Type *)1140883456B].PRAMCR ={v} _7;
  goto <bb 13>; [100.00%]

  <bb 5> [local count: 425420490]:
  # DEBUG BEGIN_STMT
  _8 ={v} MEM[(struct SRAMC_Type *)1140883456B].PRAMSR;
  _9 = _8 & 1;
  if (_9 != 0)
    goto <bb 6>; [27.00%]
  else
    goto <bb 12>; [73.00%]

  <bb 6> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 ={v} MEM[(struct SRAMC_Type *)1140883456B].PRAMSR;
  _11 = _10 | 1;
  MEM[(struct SRAMC_Type *)1140883456B].PRAMSR ={v} _11;
  # DEBUG BEGIN_STMT
  TimeoutTicks.5_12 = TimeoutTicks;
  TimeoutOccurred_33 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.5_12);
  # DEBUG TimeoutOccurred => TimeoutOccurred_33
  # DEBUG BEGIN_STMT
  _13 ={v} MEM[(struct SRAMC_Type *)1140883456B].PRAMCR;
  _14 = _13 & 1;
  if (_14 != 0)
    goto <bb 8>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 8> [local count: 1014686025]:
  if (TimeoutOccurred_33 != 0)
    goto <bb 9>; [5.50%]
  else
    goto <bb 16>; [94.50%]

  <bb 16> [local count: 958878294]:
  goto <bb 7>; [100.00%]

  <bb 9> [local count: 114863532]:
  # TimeoutOccurred_24 = PHI <TimeoutOccurred_33(7), TimeoutOccurred_33(8)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_24 != 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 10> [local count: 76958566]:
  # DEBUG BEGIN_STMT
  _15 ={v} MEM[(struct SRAMC_Type *)1140883456B].PRAMCR;
  _16 = _15 & 4294967289;
  _17 = IwsSetting_35(D) << 1;
  _18 = _17 & 6;
  _19 = _16 | _18;
  MEM[(struct SRAMC_Type *)1140883456B].PRAMCR ={v} _19;
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 37904966]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (11, 154);
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 310556958]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (11, 154);

  <bb 13> [local count: 850840980]:
  # Index_22 = PHI <1(12), 1(11), 1(4), 1(10)>

  <bb 14> [local count: 956001103]:
  # Index_20 = PHI <Index_22(13), 0(2)>
  # DEBUG Index => Index_20
  # DEBUG BEGIN_STMT
  if (Index_20 == 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 15>; [11.00%]

  <bb 15> [local count: 105160121]:
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Clock_Ip_SetRamWaitStates (Clock_Ip_SetRamWaitStates, funcdef_no=2, decl_uid=6354, cgraph_uid=3, symbol_order=3)

Modification phase of node Clock_Ip_SetRamWaitStates/3
Clock_Ip_SetRamWaitStates ()
{
  uint32 ConfiguredCoreClock;
  uint32 IwsSetting;
  unsigned char _1;
  const struct Clock_Ip_ClockConfigType * Clock_Ip_pxConfig.0_2;
  const struct Clock_Ip_ConfiguredFrequencyType[<unknown>] * _3;
  unsigned char _4;
  int _5;
  const struct Clock_Ip_ClockConfigType * Clock_Ip_pxConfig.1_6;
  const struct Clock_Ip_ConfiguredFrequencyType[<unknown>] * _7;
  unsigned char _8;
  int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Sys_GetCoreID ();
  # DEBUG coreId => (uint32) _1
  # DEBUG BEGIN_STMT
  # DEBUG IwsSetting => 0
  # DEBUG BEGIN_STMT
  # DEBUG ConfiguredCoreClock => 0
  # DEBUG BEGIN_STMT
  # DEBUG IwsSetting => 3
  # DEBUG BEGIN_STMT
  switch (_1) <default: <L5> [33.33%], case 0 ... 1: <L1> [33.33%], case 2: <L0> [33.33%]>

  <bb 3> [local count: 357878150]:
<L0>:
  # DEBUG BEGIN_STMT
  Clock_Ip_pxConfig.0_2 = Clock_Ip_pxConfig;
  _3 = Clock_Ip_pxConfig.0_2->ConfiguredFrequencies;
  _4 = Clock_Ip_FreqIds[40];
  _5 = (int) _4;
  ConfiguredCoreClock_13 = *_3[_5].ConfiguredFrequencyValue;
  # DEBUG ConfiguredCoreClock => ConfiguredCoreClock_13
  # DEBUG BEGIN_STMT
  # DEBUG ConfiguredCoreClockFrequnecy => ConfiguredCoreClock_13
  # DEBUG Threshold0 => 200000000
  # DEBUG Threshold1 => 400000000
  # DEBUG Threshold2 => 600000000
  # DEBUG INLINE_ENTRY Clock_Ip_GetIwsSetting
  # DEBUG BEGIN_STMT
  # DEBUG IwsSetting => 0
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 > 599999999)
    goto <bb 11>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 4> [local count: 232620798]:
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 > 399999999)
    goto <bb 11>; [35.00%]
  else
    goto <bb 5>; [65.00%]

  <bb 5> [local count: 151203519]:
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 > 199999999)
    goto <bb 6>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 6> [local count: 75601759]:
  # DEBUG BEGIN_STMT
  # DEBUG IwsSetting => 1
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 357878150]:
<L1>:
  # DEBUG BEGIN_STMT
  Clock_Ip_pxConfig.1_6 = Clock_Ip_pxConfig;
  _7 = Clock_Ip_pxConfig.1_6->ConfiguredFrequencies;
  _8 = Clock_Ip_FreqIds[35];
  _9 = (int) _8;
  ConfiguredCoreClock_14 = *_7[_9].ConfiguredFrequencyValue;
  # DEBUG ConfiguredCoreClock => ConfiguredCoreClock_14
  # DEBUG BEGIN_STMT
  # DEBUG ConfiguredCoreClockFrequnecy => ConfiguredCoreClock_14
  # DEBUG Threshold0 => 100000000
  # DEBUG Threshold1 => 200000000
  # DEBUG Threshold2 => 300000000
  # DEBUG INLINE_ENTRY Clock_Ip_GetIwsSetting
  # DEBUG BEGIN_STMT
  # DEBUG IwsSetting => 0
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_14 > 299999999)
    goto <bb 11>; [35.00%]
  else
    goto <bb 8>; [65.00%]

  <bb 8> [local count: 232620798]:
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_14 > 199999999)
    goto <bb 11>; [35.00%]
  else
    goto <bb 9>; [65.00%]

  <bb 9> [local count: 151203519]:
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_14 > 99999999)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 75601759]:
  # DEBUG BEGIN_STMT
  # DEBUG IwsSetting => 1

  <bb 11> [local count: 1073634451]:
  # IwsSetting_10 = PHI <2(4), 2(8), 3(2), 3(7), 1(10), 0(9), 3(3), 1(6), 0(5)>
<L5>:
  # DEBUG ConfiguredCoreClockFrequnecy => NULL
  # DEBUG Threshold0 => NULL
  # DEBUG Threshold1 => NULL
  # DEBUG Threshold2 => NULL
  # DEBUG IwsSetting => NULL
  # DEBUG ConfiguredCoreClockFrequnecy => NULL
  # DEBUG Threshold0 => NULL
  # DEBUG Threshold1 => NULL
  # DEBUG Threshold2 => NULL
  # DEBUG IwsSetting => NULL
  # DEBUG IwsSetting => IwsSetting_10
  # DEBUG BEGIN_STMT
  SRAMController_SetRamIWS (IwsSetting_10);
  return;

}


