
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  start_example/2:
  Jump functions of caller  device_init/1:
  Jump functions of caller  main/0:

 Propagating constants:

Not considering main for cloning; -fipa-cp-clone disabled.

overall_size: 5, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: main/0:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

start_example/2 (start_example) @05ea5540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: main/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
device_init/1 (device_init) @05ea5460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: main/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
main/0 (main) @05ea5000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body only_called_at_startup executed_once optimize_size
  Called by: 
  Calls: start_example/2 (1073741824 (estimated locally),1.00 per call) device_init/1 (1073741824 (estimated locally),1.00 per call) 

;; Function main (main, funcdef_no=0, decl_uid=5404, cgraph_uid=1, symbol_order=0) (executed once)

Modification phase of node main/0
main ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  device_init ();
  # DEBUG BEGIN_STMT
  start_example ();
  # DEBUG BEGIN_STMT
  return 0;

}


