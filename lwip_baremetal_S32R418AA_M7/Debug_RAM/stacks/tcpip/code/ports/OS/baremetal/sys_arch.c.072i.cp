
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  OsIf_GetMilliseconds/5:
  Jump functions of caller  OsIf_Init/4:
  Jump functions of caller  sys_now/3:
  Jump functions of caller  sys_jiffies/2:
  Jump functions of caller  sys_init/1:

 Propagating constants:

Function sys_now/3 is not versionable, reason: not a tree_versionable_function.
Not considering sys_jiffies for cloning; -fipa-cp-clone disabled.
Not considering sys_init for cloning; -fipa-cp-clone disabled.

overall_size: 15, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: sys_now/3:
  Node: sys_jiffies/2:
  Node: sys_init/1:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

OsIf_GetMilliseconds/5 (OsIf_GetMilliseconds) @060362a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sys_jiffies/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
OsIf_Init/4 (OsIf_Init) @06036e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sys_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
sys_now/3 (sys_now) @060369a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: sys_jiffies/2 (1073741824 (estimated locally),1.00 per call) 
sys_jiffies/2 (sys_jiffies) @06036700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: sys_now/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: OsIf_GetMilliseconds/5 (1073741824 (estimated locally),1.00 per call) 
sys_init/1 (sys_init) @06036460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: OsIf_Init/4 (1073741824 (estimated locally),1.00 per call) 

;; Function sys_init (sys_init, funcdef_no=1, decl_uid=6507, cgraph_uid=2, symbol_order=1)

Modification phase of node sys_init/1
sys_init ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  OsIf_Init (0B);
  return;

}



;; Function sys_jiffies (sys_jiffies, funcdef_no=2, decl_uid=6509, cgraph_uid=3, symbol_order=2)

Modification phase of node sys_jiffies/2
sys_jiffies ()
{
  u32_t _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _3 = OsIf_GetMilliseconds ();
  return _3;

}



;; Function sys_now (sys_now, funcdef_no=5, decl_uid=6511, cgraph_uid=4, symbol_order=3)

Modification phase of node sys_now/3
sys_now ()
{
  u32_t retval.3;

  <bb 2> [local count: 1073741824]:
  retval.3_3 = sys_jiffies (); [tail call]
  return retval.3_3;

}


