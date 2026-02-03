
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  STM_0_ISR/2:

 Propagating constants:


overall_size: 0, max_new_size: 11001

IPA lattices after all propagation:

Lattices:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

STM_0_ISR/2 (STM_0_ISR) @06aac380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: aIrqConfiguration1/0 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
IntCtrlConfig_0/1 (IntCtrlConfig_0) @07317c60
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: aIrqConfiguration1/0 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
aIrqConfiguration1/0 (aIrqConfiguration1) @07317c18
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: STM_0_ISR/2 (addr)
  Referring: IntCtrlConfig_0/1 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
