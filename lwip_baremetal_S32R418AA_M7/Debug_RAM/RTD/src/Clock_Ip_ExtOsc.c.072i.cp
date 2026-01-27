
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_ReportClockErrors/12:
  Jump functions of caller  Clock_Ip_TimeoutExpired/11:
  Jump functions of caller  Clock_Ip_StartTimeout/10:
  Jump functions of caller  Clock_Ip_EnableFxoscOsconBypEocvGmSel/6:
  Jump functions of caller  Clock_Ip_DisableFxoscOsconBypEocvGmSel/5:
  Jump functions of caller  Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4:
  Jump functions of caller  Clock_Ip_SetFxoscOsconBypEocvGmSel/3:
  Jump functions of caller  Clock_Ip_ResetFxoscOsconBypEocvGmSel/2:
  Jump functions of caller  Clock_Ip_DisableClockIpExternalOscillatorEmpty/1:
  Jump functions of caller  Clock_Ip_ExternalOscillatorEmpty/0:

 Propagating constants:

Not considering Clock_Ip_EnableFxoscOsconBypEocvGmSel for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_DisableFxoscOsconBypEocvGmSel for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_CompleteFxoscOsconBypEocvGmSel for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SetFxoscOsconBypEocvGmSel for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ResetFxoscOsconBypEocvGmSel for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_DisableClockIpExternalOscillatorEmpty for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ExternalOscillatorEmpty for cloning; -fipa-cp-clone disabled.

overall_size: 135, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_EnableFxoscOsconBypEocvGmSel/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_DisableFxoscOsconBypEocvGmSel/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetFxoscOsconBypEocvGmSel/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetFxoscOsconBypEocvGmSel/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_DisableClockIpExternalOscillatorEmpty/1:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ExternalOscillatorEmpty/0:
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

Clock_Ip_ReportClockErrors/12 (Clock_Ip_ReportClockErrors) @06374700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4 (93952410 (estimated locally),0.09 per call) Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4 (31004295 (estimated locally),0.03 per call) Clock_Ip_DisableFxoscOsconBypEocvGmSel/5 (37904965 (estimated locally),0.33 per call) 
  Calls: 
Clock_Ip_TimeoutExpired/11 (Clock_Ip_TimeoutExpired) @06374620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4 (878265103 (estimated locally),0.82 per call) Clock_Ip_DisableFxoscOsconBypEocvGmSel/5 (1073741824 (estimated locally),9.35 per call) 
  Calls: 
Clock_Ip_StartTimeout/10 (Clock_Ip_StartTimeout) @06374540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4 (93952410 (estimated locally),0.09 per call) Clock_Ip_DisableFxoscOsconBypEocvGmSel/5 (114863532 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_apxXosc/9 (Clock_Ip_apxXosc) @063771f8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_EnableFxoscOsconBypEocvGmSel/6 (read)Clock_Ip_ResetFxoscOsconBypEocvGmSel/2 (read)Clock_Ip_DisableFxoscOsconBypEocvGmSel/5 (read)Clock_Ip_SetFxoscOsconBypEocvGmSel/3 (read)Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au8ClockFeatures/8 (Clock_Ip_au8ClockFeatures) @063771b0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ResetFxoscOsconBypEocvGmSel/2 (read)Clock_Ip_SetFxoscOsconBypEocvGmSel/3 (read)Clock_Ip_EnableFxoscOsconBypEocvGmSel/6 (read)Clock_Ip_DisableFxoscOsconBypEocvGmSel/5 (read)Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axExtOscCallbacks/7 (Clock_Ip_axExtOscCallbacks) @0625cdc8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_ExternalOscillatorEmpty/0 (addr)Clock_Ip_ExternalOscillatorEmpty/0 (addr)Clock_Ip_ExternalOscillatorEmpty/0 (addr)Clock_Ip_DisableClockIpExternalOscillatorEmpty/1 (addr)Clock_Ip_ExternalOscillatorEmpty/0 (addr)Clock_Ip_ResetFxoscOsconBypEocvGmSel/2 (addr)Clock_Ip_SetFxoscOsconBypEocvGmSel/3 (addr)Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4 (addr)Clock_Ip_DisableFxoscOsconBypEocvGmSel/5 (addr)Clock_Ip_EnableFxoscOsconBypEocvGmSel/6 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_EnableFxoscOsconBypEocvGmSel/6 (Clock_Ip_EnableFxoscOsconBypEocvGmSel) @0625fb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_apxXosc/9 (read)
  Referring: Clock_Ip_axExtOscCallbacks/7 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_DisableFxoscOsconBypEocvGmSel/5 (Clock_Ip_DisableFxoscOsconBypEocvGmSel) @0625f0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_apxXosc/9 (read)
  Referring: Clock_Ip_axExtOscCallbacks/7 (addr)
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ReportClockErrors/12 (37904965 (estimated locally),0.33 per call) Clock_Ip_TimeoutExpired/11 (1073741824 (estimated locally),9.35 per call) Clock_Ip_StartTimeout/10 (114863532 (estimated locally),1.00 per call) 
Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4 (Clock_Ip_CompleteFxoscOsconBypEocvGmSel) @0625fd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_apxXosc/9 (read)
  Referring: Clock_Ip_axExtOscCallbacks/7 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ReportClockErrors/12 (93952410 (estimated locally),0.09 per call) Clock_Ip_ReportClockErrors/12 (31004295 (estimated locally),0.03 per call) Clock_Ip_TimeoutExpired/11 (878265103 (estimated locally),0.82 per call) Clock_Ip_StartTimeout/10 (93952410 (estimated locally),0.09 per call) 
Clock_Ip_SetFxoscOsconBypEocvGmSel/3 (Clock_Ip_SetFxoscOsconBypEocvGmSel) @0625fa80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_apxXosc/9 (read)
  Referring: Clock_Ip_axExtOscCallbacks/7 (addr)
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ResetFxoscOsconBypEocvGmSel/2 (Clock_Ip_ResetFxoscOsconBypEocvGmSel) @0625f2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/8 (read)Clock_Ip_apxXosc/9 (read)
  Referring: Clock_Ip_axExtOscCallbacks/7 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_DisableClockIpExternalOscillatorEmpty/1 (Clock_Ip_DisableClockIpExternalOscillatorEmpty) @0625f000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axExtOscCallbacks/7 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ExternalOscillatorEmpty/0 (Clock_Ip_ExternalOscillatorEmpty) @0625ae00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axExtOscCallbacks/7 (addr)Clock_Ip_axExtOscCallbacks/7 (addr)Clock_Ip_axExtOscCallbacks/7 (addr)Clock_Ip_axExtOscCallbacks/7 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function Clock_Ip_ExternalOscillatorEmpty (Clock_Ip_ExternalOscillatorEmpty, funcdef_no=0, decl_uid=6368, cgraph_uid=1, symbol_order=0)

Modification phase of node Clock_Ip_ExternalOscillatorEmpty/0
Clock_Ip_ExternalOscillatorEmpty (const struct Clock_Ip_XoscConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_DisableClockIpExternalOscillatorEmpty (Clock_Ip_DisableClockIpExternalOscillatorEmpty, funcdef_no=1, decl_uid=6370, cgraph_uid=2, symbol_order=1)

Modification phase of node Clock_Ip_DisableClockIpExternalOscillatorEmpty/1
Clock_Ip_DisableClockIpExternalOscillatorEmpty (Clock_Ip_NameType XoscName)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ResetFxoscOsconBypEocvGmSel (Clock_Ip_ResetFxoscOsconBypEocvGmSel, funcdef_no=2, decl_uid=6372, cgraph_uid=3, symbol_order=2)

Modification phase of node Clock_Ip_ResetFxoscOsconBypEocvGmSel/2
Clock_Ip_ResetFxoscOsconBypEocvGmSel (const struct Clock_Ip_XoscConfigType * Config)
{
  uint32 Instance;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  volatile struct Clock_Ip_ExtOSCType * _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_8(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = Config_8(D)->Name;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][0];
  Instance_10 = (uint32) _3;
  # DEBUG Instance => Instance_10
  # DEBUG BEGIN_STMT
  _4 = Clock_Ip_apxXosc[Instance_10];
  _5 ={v} _4->CTRL;
  _6 = _5 & 4294967294;
  _4->CTRL ={v} _6;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_SetFxoscOsconBypEocvGmSel (Clock_Ip_SetFxoscOsconBypEocvGmSel, funcdef_no=3, decl_uid=6374, cgraph_uid=4, symbol_order=3)

Modification phase of node Clock_Ip_SetFxoscOsconBypEocvGmSel/3
Clock_Ip_SetFxoscOsconBypEocvGmSel (const struct Clock_Ip_XoscConfigType * Config)
{
  uint32 Instance;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  short unsigned int _4;
  unsigned char _5;
  long unsigned int _6;
  long unsigned int _7;
  short unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  unsigned char _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  unsigned char _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  unsigned char _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  volatile struct Clock_Ip_ExtOSCType * _28;
  long unsigned int _29;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_31(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619277]:
  # DEBUG BEGIN_STMT
  _1 = Config_31(D)->Name;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][0];
  Instance_33 = (uint32) _3;
  # DEBUG Instance => Instance_33
  # DEBUG BEGIN_STMT
  _4 = Config_31(D)->Enable;
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _5 = Config_31(D)->BypassOption;
  _6 = (long unsigned int) _5;
  _7 = _6 << 31;
  _8 = Config_31(D)->StartupDelay;
  _9 = (long unsigned int) _8;
  _10 = _9 << 16;
  _11 = _10 & 16711680;
  _12 = _7 | _11;
  _13 = Config_31(D)->TransConductance;
  _14 = (long unsigned int) _13;
  _15 = _14 << 4;
  _16 = _15 & 255;
  _17 = _12 | _16;
  _18 = Config_31(D)->CompEn;
  _19 = (long unsigned int) _18;
  _20 = _19 << 24;
  _21 = _20 & 16777216;
  _22 = _17 | _21;
  _23 = Config_31(D)->AutoLevelController;
  _24 = (long unsigned int) _23;
  _25 = _24 << 2;
  _26 = _25 & 4;
  _27 = _22 | _26;
  _28 = Clock_Ip_apxXosc[Instance_33];
  _29 = _27 | 1;
  _28->CTRL ={v} _29;

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_EnableFxoscOsconBypEocvGmSel (Clock_Ip_EnableFxoscOsconBypEocvGmSel, funcdef_no=6, decl_uid=6380, cgraph_uid=7, symbol_order=6)

Modification phase of node Clock_Ip_EnableFxoscOsconBypEocvGmSel/6
Clock_Ip_EnableFxoscOsconBypEocvGmSel (const struct Clock_Ip_XoscConfigType * Config)
{
  uint32 Instance;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  short unsigned int _4;
  volatile struct Clock_Ip_ExtOSCType * _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_9(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = Config_9(D)->Name;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][0];
  Instance_11 = (uint32) _3;
  # DEBUG Instance => Instance_11
  # DEBUG BEGIN_STMT
  _4 = Config_9(D)->Enable;
  if (_4 == 1)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 255550554]:
  # DEBUG BEGIN_STMT
  _5 = Clock_Ip_apxXosc[Instance_11];
  _6 ={v} _5->CTRL;
  _7 = _6 | 1;
  _5->CTRL ={v} _7;

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_DisableFxoscOsconBypEocvGmSel (Clock_Ip_DisableFxoscOsconBypEocvGmSel, funcdef_no=5, decl_uid=6378, cgraph_uid=6, symbol_order=5)

Modification phase of node Clock_Ip_DisableFxoscOsconBypEocvGmSel/5
Clock_Ip_DisableFxoscOsconBypEocvGmSel (Clock_Ip_NameType XoscName)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  uint32 Instance;
  int _1;
  unsigned char _2;
  volatile struct Clock_Ip_ExtOSCType * _3;
  long unsigned int _4;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int TimeoutTicks.0_9;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _1 = (int) XoscName_12(D);
  _2 = Clock_Ip_au8ClockFeatures[_1][0];
  Instance_14 = (uint32) _2;
  # DEBUG Instance => Instance_14
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = Clock_Ip_apxXosc[Instance_14];
  _4 ={v} _3->CTRL;
  _6 = _4 & 4294967294;
  _3->CTRL ={v} _6;
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 ={v} _3->STAT;
  _8 = _7 >> 31;
  # DEBUG FxoscStatus => _8
  # DEBUG BEGIN_STMT
  TimeoutTicks.0_9 = TimeoutTicks;
  TimeoutOccurred_18 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.0_9);
  # DEBUG TimeoutOccurred => TimeoutOccurred_18
  # DEBUG BEGIN_STMT
  if (_8 == 1)
    goto <bb 4>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 4> [local count: 1014686025]:
  if (TimeoutOccurred_18 != 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 8> [local count: 958878293]:
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 114863532]:
  # TimeoutOccurred_5 = PHI <TimeoutOccurred_18(3), TimeoutOccurred_18(4)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_5 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (1, XoscName_12(D));

  <bb 7> [local count: 114863532]:
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Clock_Ip_CompleteFxoscOsconBypEocvGmSel (Clock_Ip_CompleteFxoscOsconBypEocvGmSel, funcdef_no=4, decl_uid=6376, cgraph_uid=5, symbol_order=4)

Modification phase of node Clock_Ip_CompleteFxoscOsconBypEocvGmSel/4
Clock_Ip_CompleteFxoscOsconBypEocvGmSel (const struct Clock_Ip_XoscConfigType * Config)
{
  uint32 Instance;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  short unsigned int _4;
  unsigned char _5;
  unsigned char _6;
  volatile struct Clock_Ip_ExtOSCType * _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int TimeoutTicks.1_10;
  <unnamed type> _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_15(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 12>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = Config_15(D)->Name;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][0];
  Instance_17 = (uint32) _3;
  # DEBUG Instance => Instance_17
  # DEBUG BEGIN_STMT
  _4 = Config_15(D)->Enable;
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 4> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  _5 = Config_15(D)->CompEn;
  if (_5 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 5> [local count: 187904819]:
  # DEBUG BEGIN_STMT
  _6 = Config_15(D)->BypassOption;
  if (_6 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 6> [local count: 93952410]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 7> [local count: 878265103]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = Clock_Ip_apxXosc[Instance_17];
  _8 ={v} _7->STAT;
  _9 = _8 >> 31;
  # DEBUG FxoscStatus => _9
  # DEBUG BEGIN_STMT
  TimeoutTicks.1_10 = TimeoutTicks;
  TimeoutOccurred_21 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.1_10);
  # DEBUG TimeoutOccurred => TimeoutOccurred_21
  # DEBUG BEGIN_STMT
  if (_9 == 0)
    goto <bb 8>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 8> [local count: 829960522]:
  if (TimeoutOccurred_21 != 0)
    goto <bb 9>; [5.50%]
  else
    goto <bb 13>; [94.50%]

  <bb 13> [local count: 784312694]:
  goto <bb 7>; [100.00%]

  <bb 9> [local count: 93952409]:
  # TimeoutOccurred_12 = PHI <TimeoutOccurred_21(7), TimeoutOccurred_21(8)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_12 != 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 10> [local count: 31004295]:
  # DEBUG BEGIN_STMT
  _11 = Config_15(D)->Name;
  Clock_Ip_ReportClockErrors (1, _11);
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 93952410]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (2, _1);

  <bb 12> [local count: 1073741824]:
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


