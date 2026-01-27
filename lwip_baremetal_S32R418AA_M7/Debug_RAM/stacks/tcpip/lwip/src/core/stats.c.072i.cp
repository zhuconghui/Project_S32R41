
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  stats_init/2:

 Propagating constants:

Not considering stats_init for cloning; -fipa-cp-clone disabled.

overall_size: 3, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: stats_init/2:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

stats_init/2 (stats_init) @060ac620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
lwip_stats/1 (lwip_stats) @05f34f30
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags:

;; Function stats_init (stats_init, funcdef_no=1, decl_uid=6410, cgraph_uid=2, symbol_order=2)

Modification phase of node stats_init/2
stats_init ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}


