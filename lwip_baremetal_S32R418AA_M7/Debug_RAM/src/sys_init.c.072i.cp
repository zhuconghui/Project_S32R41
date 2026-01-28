
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Sys_GetCoreID/26:
  Jump functions of caller  Core_clearPendingIsrSource/25:
  Jump functions of caller  Core_registerIsrHandler/24:
  Jump functions of caller  Core_enableIsrSource/23:
  Jump functions of caller  Core_disableIsrSource/22:
  Jump functions of caller  EUnit_GetCoreID/21:
  Jump functions of caller  sys_stop/20:
  Jump functions of caller  sys_halt/19:
  Jump functions of caller  sys_init_clock_full/18:
    callsite  sys_init_clock_full/18 -> Init_COFB/17 : 
    callsite  sys_init_clock_full/18 -> Init_MC_CGM/12 : 
    callsite  sys_init_clock_full/18 -> Init_Peripheral_DFS/11 : 
    callsite  sys_init_clock_full/18 -> Init_Peripheral_PLL/10 : 
    callsite  sys_init_clock_full/18 -> Init_Core_PLL/9 : 
    callsite  sys_init_clock_full/18 -> Init_FXOSC/8 : 
    callsite  sys_init_clock_full/18 -> Switch_Peripheral_FIRC/7 : 
    callsite  sys_init_clock_full/18 -> Switch_Core_FIRC/6 : 
  Jump functions of caller  Init_COFB/17:
  Jump functions of caller  Init_MC_CGM_3/16:
  Jump functions of caller  Init_MC_CGM_2/15:
  Jump functions of caller  Init_MC_CGM_1/14:
  Jump functions of caller  Init_MC_CGM_0/13:
  Jump functions of caller  Init_MC_CGM/12:
    callsite  Init_MC_CGM/12 -> Init_MC_CGM_3/16 : 
    callsite  Init_MC_CGM/12 -> Init_MC_CGM_2/15 : 
    callsite  Init_MC_CGM/12 -> Init_MC_CGM_1/14 : 
    callsite  Init_MC_CGM/12 -> Init_MC_CGM_0/13 : 
  Jump functions of caller  Init_Peripheral_DFS/11:
  Jump functions of caller  Init_Peripheral_PLL/10:
  Jump functions of caller  Init_Core_PLL/9:
  Jump functions of caller  Init_FXOSC/8:
  Jump functions of caller  Switch_Peripheral_FIRC/7:
  Jump functions of caller  Switch_Core_FIRC/6:
  Jump functions of caller  sys_clearIntPending/5:
  Jump functions of caller  sys_registerIsrHandler/4:
  Jump functions of caller  sys_enableIsrSource/3:
  Jump functions of caller  sys_disableIsrSource/2:
  Jump functions of caller  sys_disableAllInterrupts/1:
  Jump functions of caller  sys_enableAllInterrupts/0:

 Propagating constants:

Not considering EUnit_GetCoreID for cloning; -fipa-cp-clone disabled.
Function sys_stop/20 is not versionable, reason: not a tree_versionable_function.
Not considering sys_halt for cloning; -fipa-cp-clone disabled.
Not considering sys_init_clock_full for cloning; -fipa-cp-clone disabled.
Not considering sys_clearIntPending for cloning; -fipa-cp-clone disabled.
Not considering sys_registerIsrHandler for cloning; -fipa-cp-clone disabled.
Not considering sys_enableIsrSource for cloning; -fipa-cp-clone disabled.
Not considering sys_disableIsrSource for cloning; -fipa-cp-clone disabled.
Not considering sys_disableAllInterrupts for cloning; -fipa-cp-clone disabled.
Not considering sys_enableAllInterrupts for cloning; -fipa-cp-clone disabled.

overall_size: 2567, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: EUnit_GetCoreID/21:
  Node: sys_stop/20:
  Node: sys_halt/19:
  Node: sys_init_clock_full/18:
  Node: Init_COFB/17:
  Node: Init_MC_CGM_3/16:
  Node: Init_MC_CGM_2/15:
  Node: Init_MC_CGM_1/14:
  Node: Init_MC_CGM_0/13:
  Node: Init_MC_CGM/12:
  Node: Init_Peripheral_DFS/11:
  Node: Init_Peripheral_PLL/10:
  Node: Init_Core_PLL/9:
  Node: Init_FXOSC/8:
  Node: Switch_Peripheral_FIRC/7:
  Node: Switch_Core_FIRC/6:
  Node: sys_clearIntPending/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: sys_registerIsrHandler/4:
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
  Node: sys_enableIsrSource/3:
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
  Node: sys_disableIsrSource/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: sys_disableAllInterrupts/1:
  Node: sys_enableAllInterrupts/0:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Sys_GetCoreID/26 (Sys_GetCoreID) @06df2540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: EUnit_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Core_clearPendingIsrSource/25 (Core_clearPendingIsrSource) @06dc4d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sys_clearIntPending/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Core_registerIsrHandler/24 (Core_registerIsrHandler) @06dc4b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sys_registerIsrHandler/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Core_enableIsrSource/23 (Core_enableIsrSource) @06dc49a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sys_enableIsrSource/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Core_disableIsrSource/22 (Core_disableIsrSource) @06dc47e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sys_disableIsrSource/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
EUnit_GetCoreID/21 (EUnit_GetCoreID) @06dc41c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/26 (1073741824 (estimated locally),1.00 per call) 
sys_stop/20 (sys_stop) @06dbad20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: sys_halt/19 (1073741824 (estimated locally),1.00 per call) 
sys_halt/19 (sys_halt) @06dbaee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: sys_stop/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
sys_init_clock_full/18 (sys_init_clock_full) @06dbac40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Init_COFB/17 (1073741824 (estimated locally),1.00 per call) Init_MC_CGM/12 (1073741824 (estimated locally),1.00 per call) Init_Peripheral_DFS/11 (1073741824 (estimated locally),1.00 per call) Init_Peripheral_PLL/10 (1073741824 (estimated locally),1.00 per call) Init_Core_PLL/9 (1073741824 (estimated locally),1.00 per call) Init_FXOSC/8 (1073741824 (estimated locally),1.00 per call) Switch_Peripheral_FIRC/7 (1073741824 (estimated locally),1.00 per call) Switch_Core_FIRC/6 (1073741824 (estimated locally),1.00 per call) 
Init_COFB/17 (Init_COFB) @06dba9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: sys_init_clock_full/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Init_MC_CGM_3/16 (Init_MC_CGM_3) @06dba700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Init_MC_CGM/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Init_MC_CGM_2/15 (Init_MC_CGM_2) @06daf460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Init_MC_CGM/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Init_MC_CGM_1/14 (Init_MC_CGM_1) @06da5380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Init_MC_CGM/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Init_MC_CGM_0/13 (Init_MC_CGM_0) @06d4bd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Init_MC_CGM/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Init_MC_CGM/12 (Init_MC_CGM) @06d3aee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: sys_init_clock_full/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: Init_MC_CGM_3/16 (1073741824 (estimated locally),1.00 per call) Init_MC_CGM_2/15 (1073741824 (estimated locally),1.00 per call) Init_MC_CGM_1/14 (1073741824 (estimated locally),1.00 per call) Init_MC_CGM_0/13 (1073741824 (estimated locally),1.00 per call) 
Init_Peripheral_DFS/11 (Init_Peripheral_DFS) @06d3ac40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: sys_init_clock_full/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Init_Peripheral_PLL/10 (Init_Peripheral_PLL) @06d3a0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: sys_init_clock_full/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Init_Core_PLL/9 (Init_Core_PLL) @06d31000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: sys_init_clock_full/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Init_FXOSC/8 (Init_FXOSC) @06ca5d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: sys_init_clock_full/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Switch_Peripheral_FIRC/7 (Switch_Peripheral_FIRC) @06ca5620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: sys_init_clock_full/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Switch_Core_FIRC/6 (Switch_Core_FIRC) @06c87000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: sys_init_clock_full/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
sys_clearIntPending/5 (sys_clearIntPending) @06c84540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Core_clearPendingIsrSource/25 (1073741824 (estimated locally),1.00 per call) 
sys_registerIsrHandler/4 (sys_registerIsrHandler) @06c84ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Core_registerIsrHandler/24 (1073741824 (estimated locally),1.00 per call) 
sys_enableIsrSource/3 (sys_enableIsrSource) @06c84c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Core_enableIsrSource/23 (1073741824 (estimated locally),1.00 per call) 
sys_disableIsrSource/2 (sys_disableIsrSource) @06c849a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Core_disableIsrSource/22 (1073741824 (estimated locally),1.00 per call) 
sys_disableAllInterrupts/1 (sys_disableAllInterrupts) @06c84700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sys_enableAllInterrupts/0 (sys_enableAllInterrupts) @06c84460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function sys_enableAllInterrupts (sys_enableAllInterrupts, funcdef_no=0, decl_uid=5565, cgraph_uid=1, symbol_order=0)

Modification phase of node sys_enableAllInterrupts/0
sys_enableAllInterrupts ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsie i");
  return;

}



;; Function sys_disableAllInterrupts (sys_disableAllInterrupts, funcdef_no=1, decl_uid=5567, cgraph_uid=2, symbol_order=1)

Modification phase of node sys_disableAllInterrupts/1
sys_disableAllInterrupts ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsid i");
  return;

}



;; Function sys_disableIsrSource (sys_disableIsrSource, funcdef_no=2, decl_uid=5555, cgraph_uid=3, symbol_order=2)

Modification phase of node sys_disableIsrSource/2
sys_disableIsrSource (uint16 id)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Core_disableIsrSource (id_2(D));
  return;

}



;; Function sys_enableIsrSource (sys_enableIsrSource, funcdef_no=3, decl_uid=5558, cgraph_uid=4, symbol_order=3)

Modification phase of node sys_enableIsrSource/3
sys_enableIsrSource (uint16 id, uint8 prio)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Core_enableIsrSource (id_2(D), prio_3(D));
  return;

}



;; Function sys_registerIsrHandler (sys_registerIsrHandler, funcdef_no=4, decl_uid=5561, cgraph_uid=5, symbol_order=4)

Modification phase of node sys_registerIsrHandler/4
sys_registerIsrHandler (uint16 irq_id, void (*int_function_t) (void) isr_handler)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsid i");
  # DEBUG BEGIN_STMT
  Core_registerIsrHandler (irq_id_3(D), isr_handler_4(D));
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsie i");
  return;

}



;; Function sys_clearIntPending (sys_clearIntPending, funcdef_no=5, decl_uid=5563, cgraph_uid=6, symbol_order=5)

Modification phase of node sys_clearIntPending/5
sys_clearIntPending (uint16 irq_id)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Core_clearPendingIsrSource (irq_id_2(D));
  return;

}



;; Function sys_init_clock_full (sys_init_clock_full, funcdef_no=18, decl_uid=6377, cgraph_uid=19, symbol_order=18)

Modification phase of node sys_init_clock_full/18
sys_init_clock_full ()
{
  volatile int status;
  int status.0_1;
  int _2;
  int status.1_3;
  int _4;
  int status.2_5;
  int _6;
  int status.3_7;
  int _8;
  int status.4_9;
  int _10;
  int status.5_11;
  int _12;
  int status.6_13;
  int _14;
  int status.7_15;
  int _16;
  int status.8_17;
  _Bool _18;
  int _22;
  int _25;
  int _28;
  int _31;
  int _34;
  int _37;
  int _40;
  int _43;
  Std_ReturnType _45;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  status ={v} 0;
  # DEBUG BEGIN_STMT
  _22 = Switch_Core_FIRC ();
  status.0_1 ={v} status;
  _2 = status.0_1 + _22;
  status ={v} _2;
  # DEBUG BEGIN_STMT
  _25 = Switch_Peripheral_FIRC ();
  status.1_3 ={v} status;
  _4 = status.1_3 + _25;
  status ={v} _4;
  # DEBUG BEGIN_STMT
  _28 = Init_FXOSC ();
  status.2_5 ={v} status;
  _6 = status.2_5 + _28;
  status ={v} _6;
  # DEBUG BEGIN_STMT
  _31 = Init_Core_PLL ();
  status.3_7 ={v} status;
  _8 = status.3_7 + _31;
  status ={v} _8;
  # DEBUG BEGIN_STMT
  _34 = Init_Peripheral_PLL ();
  status.4_9 ={v} status;
  _10 = status.4_9 + _34;
  status ={v} _10;
  # DEBUG BEGIN_STMT
  _37 = Init_Peripheral_DFS ();
  status.5_11 ={v} status;
  _12 = status.5_11 + _37;
  status ={v} _12;
  # DEBUG BEGIN_STMT
  _40 = Init_MC_CGM ();
  status.6_13 ={v} status;
  _14 = status.6_13 + _40;
  status ={v} _14;
  # DEBUG BEGIN_STMT
  _43 = Init_COFB ();
  status.7_15 ={v} status;
  _16 = status.7_15 + _43;
  status ={v} _16;
  # DEBUG BEGIN_STMT
  status.8_17 ={v} status;
  _18 = status.8_17 != 0;
  _45 = (Std_ReturnType) _18;
  return _45;

}



;; Function sys_halt (sys_halt, funcdef_no=19, decl_uid=5571, cgraph_uid=20, symbol_order=19)

Modification phase of node sys_halt/19
sys_halt ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("  wfi");
  # DEBUG BEGIN_STMT
  return;

}



;; Function sys_stop (sys_stop, funcdef_no=23, decl_uid=5573, cgraph_uid=21, symbol_order=20)

Modification phase of node sys_stop/20
sys_stop ()
{
  <bb 2> [local count: 1073741824]:
  sys_halt (); [tail call]
  return;

}



;; Function EUnit_GetCoreID (EUnit_GetCoreID, funcdef_no=21, decl_uid=5575, cgraph_uid=22, symbol_order=21)

Modification phase of node EUnit_GetCoreID/21
EUnit_GetCoreID ()
{
  uint8 _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _3 = Sys_GetCoreID ();
  return _3;

}


