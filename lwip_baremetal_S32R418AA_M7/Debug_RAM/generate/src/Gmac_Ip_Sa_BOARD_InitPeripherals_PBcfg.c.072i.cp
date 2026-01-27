
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  GmacIf_RxNotification/11:
  Jump functions of caller  GmacIf_TxNotification/9:

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

GmacIf_RxNotification/11 (GmacIf_RxNotification) @06e8d700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: GMAC_0_aRxRingConfigPB_BOARD_INITPERIPHERALS/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
GMAC_0_RxRing_0_DescBuffer/10 (GMAC_0_RxRing_0_DescBuffer) @06e8e318
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: GMAC_0_aRxRingConfigPB_BOARD_INITPERIPHERALS/2 (addr)
  Availability: not_available
  Varpool flags:
GmacIf_TxNotification/9 (GmacIf_TxNotification) @06e8d620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: GMAC_0_aTxRingConfigPB_BOARD_INITPERIPHERALS/3 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
GMAC_0_TxRing_0_DescBuffer/8 (GMAC_0_TxRing_0_DescBuffer) @06e8e2d0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: GMAC_0_aTxRingConfigPB_BOARD_INITPERIPHERALS/3 (addr)
  Availability: not_available
  Varpool flags:
GMAC_0_StateStructure/7 (GMAC_0_StateStructure) @06e8e288
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Gmac_0_ConfigPB_BOARD_INITPERIPHERALS/6 (addr)
  Availability: not_available
  Varpool flags:
Gmac_0_ConfigPB_BOARD_INITPERIPHERALS/6 (Gmac_0_ConfigPB_BOARD_INITPERIPHERALS) @06e8e168
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: GMAC_0_StateStructure/7 (addr)GMAC_0_InitConfigPB_BOARD_INITPERIPHERALS/4 (addr)GMAC_0_aRxRingConfigPB_BOARD_INITPERIPHERALS/2 (addr)GMAC_0_aTxRingConfigPB_BOARD_INITPERIPHERALS/3 (addr)GMAC_0_au8MacAddrPB_BOARD_INITPERIPHERALS/1 (addr)GMAC_0_pTxTimeShaperPB_BOARD_INITPERIPHERALS/5 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
GMAC_0_pTxTimeShaperPB_BOARD_INITPERIPHERALS/5 (GMAC_0_pTxTimeShaperPB_BOARD_INITPERIPHERALS) @06e8e048
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: GMAC_0_GateControlListPB_BOARD_INITPERIPHERALS/0 (addr)
  Referring: Gmac_0_ConfigPB_BOARD_INITPERIPHERALS/6 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
GMAC_0_InitConfigPB_BOARD_INITPERIPHERALS/4 (GMAC_0_InitConfigPB_BOARD_INITPERIPHERALS) @06e88ea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Gmac_0_ConfigPB_BOARD_INITPERIPHERALS/6 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
GMAC_0_aTxRingConfigPB_BOARD_INITPERIPHERALS/3 (GMAC_0_aTxRingConfigPB_BOARD_INITPERIPHERALS) @06e88ee8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: GMAC_0_TxRing_0_DescBuffer/8 (addr)GmacIf_TxNotification/9 (addr)
  Referring: Gmac_0_ConfigPB_BOARD_INITPERIPHERALS/6 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
GMAC_0_aRxRingConfigPB_BOARD_INITPERIPHERALS/2 (GMAC_0_aRxRingConfigPB_BOARD_INITPERIPHERALS) @06e88e10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: GMAC_0_RxRing_0_DescBuffer/10 (addr)GmacIf_RxNotification/11 (addr)
  Referring: Gmac_0_ConfigPB_BOARD_INITPERIPHERALS/6 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
GMAC_0_au8MacAddrPB_BOARD_INITPERIPHERALS/1 (GMAC_0_au8MacAddrPB_BOARD_INITPERIPHERALS) @06e88d38
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Gmac_0_ConfigPB_BOARD_INITPERIPHERALS/6 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
GMAC_0_GateControlListPB_BOARD_INITPERIPHERALS/0 (GMAC_0_GateControlListPB_BOARD_INITPERIPHERALS) @06e88c60
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: GMAC_0_pTxTimeShaperPB_BOARD_INITPERIPHERALS/5 (addr)
  Availability: available
  Varpool flags: initialized
