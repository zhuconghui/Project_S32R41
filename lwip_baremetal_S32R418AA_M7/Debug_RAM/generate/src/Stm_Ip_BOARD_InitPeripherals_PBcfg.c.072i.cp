
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  StmNotification/2:

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

StmNotification/2 (StmNotification) @05ee7b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: STM_0_ChannelConfig_PB_BOARD_InitPeripherals/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
STM_0_ChannelConfig_PB_BOARD_InitPeripherals/1 (STM_0_ChannelConfig_PB_BOARD_InitPeripherals) @05eedab0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: StmNotification/2 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
STM_0_InitConfig_PB_BOARD_InitPeripherals/0 (STM_0_InitConfig_PB_BOARD_InitPeripherals) @05eeda68
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
