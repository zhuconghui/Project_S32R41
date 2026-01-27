
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Core_Cache_Init/9:
  Jump functions of caller  Core_MPU_Init/8:
  Jump functions of caller  Core_FPU_Init/7:
  Jump functions of caller  Core_IC_Init/6:
  Jump functions of caller  SystemInit/5:
    callsite  SystemInit/5 -> Sys_EnablePartitions/3 : 
  Jump functions of caller  Sys_EnablePartitions/3:
  Jump functions of caller  Sys_GetCoreID/2:
  Jump functions of caller  startup_go_to_user_mode/1:

 Propagating constants:

Not considering SystemInit for cloning; -fipa-cp-clone disabled.
Not considering Sys_GetCoreID for cloning; -fipa-cp-clone disabled.
Not considering startup_go_to_user_mode for cloning; -fipa-cp-clone disabled.

overall_size: 72, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: SystemInit/5:
  Node: Sys_EnablePartitions/3:
  Node: Sys_GetCoreID/2:
  Node: startup_go_to_user_mode/1:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

CSWTCH.4/11 (CSWTCH.4) @061a6750
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: SystemInit/5 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Core_Cache_Init/9 (Core_Cache_Init) @05f489a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SystemInit/5 (10737418 (estimated locally),1.00 per call) 
  Calls: 
Core_MPU_Init/8 (Core_MPU_Init) @05f488c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SystemInit/5 (10737418 (estimated locally),1.00 per call) 
  Calls: 
Core_FPU_Init/7 (Core_FPU_Init) @05f487e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SystemInit/5 (10737418 (estimated locally),1.00 per call) 
  Calls: 
Core_IC_Init/6 (Core_IC_Init) @05f48000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SystemInit/5 (10737418 (estimated locally),1.00 per call) 
  Calls: 
SystemInit/5 (SystemInit) @05f480e0
  Type: function definition analyzed
  Visibility: externally_visible public section:.systeminit
  References: CSWTCH.4/11 (read)
  Referring: 
  Availability: available
  Function flags: count:10737418 (estimated locally) body optimize_size
  Called by: 
  Calls: Core_Cache_Init/9 (10737418 (estimated locally),1.00 per call) Core_MPU_Init/8 (10737418 (estimated locally),1.00 per call) Core_FPU_Init/7 (10737418 (estimated locally),1.00 per call) Core_IC_Init/6 (10737418 (estimated locally),1.00 per call) Sys_EnablePartitions/3 (10737418 (estimated locally),1.00 per call) 
Sys_EnablePartitions/3 (Sys_EnablePartitions) @05f3b7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:236223197 (estimated locally) body local optimize_size
  Called by: SystemInit/5 (10737418 (estimated locally),1.00 per call) 
  Calls: 
Sys_GetCoreID/2 (Sys_GetCoreID) @05f3bc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
startup_go_to_user_mode/1 (startup_go_to_user_mode) @05f3b9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
RESET_CATCH_CORE/0 (RESET_CATCH_CORE) @05f42af8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags:

;; Function startup_go_to_user_mode (startup_go_to_user_mode, funcdef_no=0, decl_uid=5791, cgraph_uid=1, symbol_order=1)

Modification phase of node startup_go_to_user_mode/1
startup_go_to_user_mode ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Sys_GetCoreID (Sys_GetCoreID, funcdef_no=1, decl_uid=5547, cgraph_uid=2, symbol_order=2)

Modification phase of node Sys_GetCoreID/2
Sys_GetCoreID ()
{
  long unsigned int _1;
  unsigned char _2;
  uint8 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MSCM_Type *)1073807360B].CPXNUM;
  _2 = (unsigned char) _1;
  _4 = _2 & 3;
  return _4;

}



;; Function SystemInit (SystemInit, funcdef_no=3, decl_uid=5553, cgraph_uid=5, symbol_order=5)

Modification phase of node SystemInit/5
__attribute__((section (".systeminit")))
SystemInit ()
{
  uint32 coreMask;
  uint32 i;
  unsigned char _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  unsigned char _9;
  long unsigned int _10;
  long unsigned int _19;
  unsigned char _20;
  unsigned char _21;

  <bb 2> [local count: 10737418]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Sys_GetCoreID
  # DEBUG BEGIN_STMT
  _19 ={v} MEM[(struct MSCM_Type *)1073807360B].CPXNUM;
  _20 = (unsigned char) _19;
  _21 = _20 & 3;
  # DEBUG coreId => (uint32) _21
  # DEBUG BEGIN_STMT
  _9 = _21;
  if (_9 <= 2)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 5368709]:
<L9>:
  coreMask_11 = 0;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 5368709]:
<L10>:
  _1 = CSWTCH.4[_9];
  _10 = (long unsigned int) _1;
  coreMask_22 = _10;

  <bb 5> [local count: 10737418]:
  # coreMask_6 = PHI <coreMask_22(4), coreMask_11(3)>
<L11>:
<L8>:
  # DEBUG coreMask => coreMask_6
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 1063004407]:
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct MSCM_Type *)1073807360B].IRSPRC[i_5];
  _3 = (short unsigned int) coreMask_6;
  _4 = _2 | _3;
  MEM[(struct MSCM_Type *)1073807360B].IRSPRC[i_5] ={v} _4;
  # DEBUG BEGIN_STMT
  i_18 = i_5 + 1;
  # DEBUG i => i_18

  <bb 7> [local count: 1073741824]:
  # i_5 = PHI <0(5), i_18(6)>
  # DEBUG i => i_5
  # DEBUG BEGIN_STMT
  if (i_5 != 240)
    goto <bb 6>; [99.00%]
  else
    goto <bb 8>; [1.00%]

  <bb 8> [local count: 10737418]:
  # DEBUG BEGIN_STMT
  Sys_EnablePartitions ();
  # DEBUG BEGIN_STMT
  Core_IC_Init ();
  # DEBUG BEGIN_STMT
  Core_FPU_Init ();
  # DEBUG BEGIN_STMT
  Core_MPU_Init ();
  # DEBUG BEGIN_STMT
  Core_Cache_Init ();
  return;

}


