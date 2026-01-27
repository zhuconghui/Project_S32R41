
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4:
  Jump functions of caller  Clock_Ip_ProgressiveFrequencyClockSwitchEmpty/3:

 Propagating constants:

Not considering Clock_Ip_CgmXPcfsSdurDivcDiveDivs for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ProgressiveFrequencyClockSwitchEmpty for cloning; -fipa-cp-clone disabled.

overall_size: 86, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 2.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4:
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
  Node: Clock_Ip_ProgressiveFrequencyClockSwitchEmpty/3:
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


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Clock_Ip_FreqIds/9 (Clock_Ip_FreqIds) @063de798
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (read)
  Availability: not_available
  Varpool flags:
Clock_Ip_pxConfig/8 (Clock_Ip_pxConfig) @063de750
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (read)
  Availability: not_available
  Varpool flags:
Clock_Ip_apxCgmPcfs/7 (Clock_Ip_apxCgmPcfs) @063de708
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au8ClockFeatures/6 (Clock_Ip_au8ClockFeatures) @063de6c0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (read)Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axPcfsCallbacks/5 (Clock_Ip_axPcfsCallbacks) @0635bd80
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_ProgressiveFrequencyClockSwitchEmpty/3 (addr)Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (Clock_Ip_CgmXPcfsSdurDivcDiveDivs) @0635e8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/6 (read)Clock_Ip_apxCgmPcfs/7 (read)Clock_Ip_au8ClockFeatures/6 (read)HashPfs/2 (read)HashPfs/2 (write)Clock_Ip_pxConfig/8 (read)Clock_Ip_FreqIds/9 (read)AMax/0 (read)PcfsRate/1 (read)
  Referring: Clock_Ip_axPcfsCallbacks/5 (addr)
  Availability: available
  Function flags: count:255652813 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ProgressiveFrequencyClockSwitchEmpty/3 (Clock_Ip_ProgressiveFrequencyClockSwitchEmpty) @0635e1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axPcfsCallbacks/5 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
HashPfs/2 (HashPfs) @0635b708
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (read)Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (write)
  Availability: available
  Varpool flags:
PcfsRate/1 (PcfsRate) @0635b678
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
AMax/0 (AMax) @0635b5e8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function Clock_Ip_ProgressiveFrequencyClockSwitchEmpty (Clock_Ip_ProgressiveFrequencyClockSwitchEmpty, funcdef_no=0, decl_uid=6372, cgraph_uid=1, symbol_order=3)

Modification phase of node Clock_Ip_ProgressiveFrequencyClockSwitchEmpty/3
Clock_Ip_ProgressiveFrequencyClockSwitchEmpty (const struct Clock_Ip_PcfsConfigType * Config, uint32 Index)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_CgmXPcfsSdurDivcDiveDivs (Clock_Ip_CgmXPcfsSdurDivcDiveDivs, funcdef_no=1, decl_uid=6375, cgraph_uid=2, symbol_order=4)

Modification phase of node Clock_Ip_CgmXPcfsSdurDivcDiveDivs/4
Clock_Ip_CgmXPcfsSdurDivcDiveDivs (const struct Clock_Ip_PcfsConfigType * Config, uint32 CfgIndex)
{
  uint32 DivEndValue;
  uint32 DivStartValue;
  uint32 DivcInit;
  uint32 Sdur;
  uint32 K;
  uint32 Var3;
  uint32 Var2;
  uint32 Var1;
  uint32 Index;
  uint32 Rate;
  uint32 AmaxBrut;
  uint32 Fsafe;
  uint32 Finput;
  uint32 HwIndex;
  volatile struct Clock_Ip_CgmPcfsType * CgmPcfsBase;
  <unnamed type> _1;
  int _2;
  unsigned char _3;
  int _4;
  <unnamed type> _5;
  int _6;
  unsigned char _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  const struct Clock_Ip_ClockConfigType * Clock_Ip_pxConfig.0_19;
  const struct Clock_Ip_ConfiguredFrequencyType[<unknown>] * _20;
  unsigned char _21;
  int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  long unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _35;
  long unsigned int _36;
  long unsigned int _37;
  long unsigned int _38;
  long unsigned int _39;
  long unsigned int _40;
  long unsigned int _41;
  long unsigned int _42;
  long unsigned int _43;
  long unsigned int _44;
  long unsigned int _45;
  long unsigned int _46;
  long unsigned int _47;

  <bb 2> [local count: 255652813]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Finput => 0
  # DEBUG BEGIN_STMT
  # DEBUG Fsafe => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Rate => 0
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
  if (Config_59(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 19>; [30.00%]

  <bb 3> [local count: 178956969]:
  # DEBUG BEGIN_STMT
  _1 = Config_59(D)->SelectorName;
  _2 = (int) _1;
  _3 = Clock_Ip_au8ClockFeatures[_2][0];
  _4 = (int) _3;
  CgmPcfsBase_61 = Clock_Ip_apxCgmPcfs[_4];
  # DEBUG CgmPcfsBase => CgmPcfsBase_61
  # DEBUG BEGIN_STMT
  _5 = Config_59(D)->Name;
  _6 = (int) _5;
  _7 = Clock_Ip_au8ClockFeatures[_6][7];
  HwIndex_62 = (uint32) _7;
  # DEBUG HwIndex => HwIndex_62
  # DEBUG BEGIN_STMT
  _8 = HashPfs[CfgIndex_63(D)];
  _9 = Config_59(D)->ClockSourceFrequency;
  _10 = Config_59(D)->MaxAllowableIDDchange;
  _11 = _9 ^ _10;
  _12 = (long unsigned int) _5;
  _13 = _11 ^ _12;
  _15 = (long unsigned int) _1;
  _16 = _13 ^ _15;
  _17 = Config_59(D)->StepDuration;
  _18 = _16 ^ _17;
  if (_8 != _18)
    goto <bb 4>; [66.00%]
  else
    goto <bb 19>; [34.00%]

  <bb 4> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  HashPfs[CfgIndex_63(D)] = _18;
  # DEBUG BEGIN_STMT
  Finput_65 = _9 / 1000000;
  # DEBUG Finput => Finput_65
  # DEBUG BEGIN_STMT
  Clock_Ip_pxConfig.0_19 = Clock_Ip_pxConfig;
  _20 = Clock_Ip_pxConfig.0_19->ConfiguredFrequencies;
  _21 = Clock_Ip_FreqIds[1];
  _22 = (int) _21;
  _23 = *_20[_22].ConfiguredFrequencyValue;
  Fsafe_66 = _23 / 1000000;
  # DEBUG Fsafe => Fsafe_66
  # DEBUG BEGIN_STMT
  _24 = _10 * 1000000;
  _25 = Finput_65 * 2360;
  AmaxBrut_67 = _24 / _25;
  # DEBUG AmaxBrut => AmaxBrut_67
  # DEBUG BEGIN_STMT
  # DEBUG Rate => AmaxBrut_67
  # DEBUG BEGIN_STMT
  if (AmaxBrut_67 <= 5)
    goto <bb 10>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  if (AmaxBrut_67 > 199)
    goto <bb 10>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 21> [local count: 29527900]:
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _26 = Index_51 + 4294967295;
  _27 = AMax[_26];
  if (_27 < AmaxBrut_67)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 44291850]:
  # DEBUG BEGIN_STMT
  Rate_68 = PcfsRate[_26];
  # DEBUG Rate => Rate_68

  <bb 8> [local count: 88583700]:
  # Rate_48 = PHI <Rate_49(6), Rate_68(7)>
  # DEBUG Rate => Rate_48
  # DEBUG BEGIN_STMT
  Index_69 = Index_51 + 1;
  # DEBUG Index => Index_69

  <bb 9> [local count: 118111600]:
  # Rate_49 = PHI <Rate_48(8), AmaxBrut_67(21)>
  # Index_51 = PHI <Index_69(8), 1(21)>
  # DEBUG Index => Index_51
  # DEBUG Rate => Rate_49
  # DEBUG BEGIN_STMT
  if (Index_51 != 4)
    goto <bb 6>; [75.00%]
  else
    goto <bb 10>; [25.00%]

  <bb 10> [local count: 118111600]:
  # Rate_50 = PHI <12(4), 184(5), Rate_49(9)>
  # DEBUG Rate => Rate_50
  # DEBUG BEGIN_STMT
  _28 = Finput_65 * 2048000;
  _29 = Rate_50 * Fsafe_66;
  _30 = _28 / _29;
  _31 = 2048000 / Rate_50;
  _32 = _30 - _31;
  Var1_70 = _32 + 256;
  # DEBUG Var1 => Var1_70
  # DEBUG BEGIN_STMT
  # DEBUG Var2 => 1073741824
  # DEBUG BEGIN_STMT
  # DEBUG Var3 => 0
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 955630219]:
  # DEBUG BEGIN_STMT
  Var2_84 = Var2_54 >> 2;
  # DEBUG Var2 => Var2_84

  <bb 12> [local count: 1073741819]:
  # Var2_54 = PHI <1073741824(10), Var2_84(11)>
  # DEBUG Var2 => Var2_54
  # DEBUG BEGIN_STMT
  if (Var2_54 > Var1_70)
    goto <bb 11>; [89.00%]
  else
    goto <bb 20>; [11.00%]

  <bb 20> [local count: 118111600]:
  goto <bb 17>; [100.00%]

  <bb 14> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  _33 = Var2_55 + Var3_57;
  if (_33 <= Var1_53)
    goto <bb 15>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 15> [local count: 477815112]:
  # DEBUG BEGIN_STMT
  Var1_80 = Var1_53 - _33;
  # DEBUG Var1 => Var1_80
  # DEBUG BEGIN_STMT
  _34 = Var2_55 << 1;
  Var3_81 = _34 + Var3_57;
  # DEBUG Var3 => Var3_81

  <bb 16> [local count: 955630224]:
  # Var1_52 = PHI <Var1_53(14), Var1_80(15)>
  # Var3_56 = PHI <Var3_57(14), Var3_81(15)>
  # DEBUG Var3 => Var3_56
  # DEBUG Var1 => Var1_52
  # DEBUG BEGIN_STMT
  Var3_82 = Var3_56 >> 1;
  # DEBUG Var3 => Var3_82
  # DEBUG BEGIN_STMT
  Var2_83 = Var2_55 >> 2;
  # DEBUG Var2 => Var2_83

  <bb 17> [local count: 1073741824]:
  # Var1_53 = PHI <Var1_52(16), Var1_70(20)>
  # Var2_55 = PHI <Var2_83(16), Var2_54(20)>
  # Var3_57 = PHI <Var3_82(16), 0(20)>
  # DEBUG Var3 => Var3_57
  # DEBUG Var2 => Var2_55
  # DEBUG Var1 => Var1_53
  # DEBUG BEGIN_STMT
  if (Var2_55 != 0)
    goto <bb 14>; [89.00%]
  else
    goto <bb 18>; [11.00%]

  <bb 18> [local count: 118111601]:
  # Var3_14 = PHI <Var3_57(17)>
  # DEBUG BEGIN_STMT
  _35 = Var3_14 << 2;
  _36 = _35 + 191;
  K_71 = _36 >> 7;
  # DEBUG K => K_71
  # DEBUG BEGIN_STMT
  Sdur_72 = _17 * Fsafe_66;
  # DEBUG Sdur => Sdur_72
  # DEBUG BEGIN_STMT
  DivcInit_73 = Rate_50 * K_71;
  # DEBUG DivcInit => DivcInit_73
  # DEBUG BEGIN_STMT
  # DEBUG DivcRate => Rate_50
  # DEBUG BEGIN_STMT
  _37 = K_71 + 1;
  _38 = _37 * DivcInit_73;
  _39 = _38 >> 1;
  DivStartValue_74 = _39 + 999;
  # DEBUG DivStartValue => DivStartValue_74
  # DEBUG BEGIN_STMT
  _40 = Finput_65 * 1000;
  _41 = _40 / Fsafe_66;
  DivEndValue_75 = _41 + 4294967295;
  # DEBUG DivEndValue => DivEndValue_75
  # DEBUG BEGIN_STMT
  _42 = Sdur_72 & 65535;
  CgmPcfsBase_61->PCFS_SDUR ={v} _42;
  # DEBUG BEGIN_STMT
  _43 = Rate_50 & 255;
  _44 = DivcInit_73 << 16;
  _45 = _43 | _44;
  CgmPcfsBase_61->PCFS[HwIndex_62].DIVC ={v} _45;
  # DEBUG BEGIN_STMT
  _46 = DivEndValue_75 & 1048575;
  CgmPcfsBase_61->PCFS[HwIndex_62].DIVE ={v} _46;
  # DEBUG BEGIN_STMT
  _47 = DivStartValue_74 & 1048575;
  CgmPcfsBase_61->PCFS[HwIndex_62].DIVS ={v} _47;

  <bb 19> [local count: 255652814]:
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
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}


