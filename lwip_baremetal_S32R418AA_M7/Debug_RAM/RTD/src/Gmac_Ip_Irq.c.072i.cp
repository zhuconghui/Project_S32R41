
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  GMAC_RxIRQHandler/13:
  Jump functions of caller  GMAC_TxIRQHandler/12:
  Jump functions of caller  GMAC_CommonIRQHandler/11:
  Jump functions of caller  GMAC1_CH1_RX_IRQHandler/10:
  Jump functions of caller  GMAC1_CH1_TX_IRQHandler/9:
  Jump functions of caller  GMAC1_CH0_RX_IRQHandler/8:
  Jump functions of caller  GMAC1_CH0_TX_IRQHandler/7:
  Jump functions of caller  GMAC1_Common_IRQHandler/6:
  Jump functions of caller  GMAC0_CH1_RX_IRQHandler/5:
  Jump functions of caller  GMAC0_CH1_TX_IRQHandler/4:
  Jump functions of caller  GMAC0_CH0_RX_IRQHandler/3:
  Jump functions of caller  GMAC0_CH0_TX_IRQHandler/2:
  Jump functions of caller  GMAC0_Common_IRQHandler/1:

 Propagating constants:

Not considering GMAC1_CH1_RX_IRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC1_CH1_TX_IRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC1_CH0_RX_IRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC1_CH0_TX_IRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC1_Common_IRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC0_CH1_RX_IRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC0_CH1_TX_IRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC0_CH0_RX_IRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC0_CH0_TX_IRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC0_Common_IRQHandler for cloning; -fipa-cp-clone disabled.

overall_size: 58, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: GMAC1_CH1_RX_IRQHandler/10:
  Node: GMAC1_CH1_TX_IRQHandler/9:
  Node: GMAC1_CH0_RX_IRQHandler/8:
  Node: GMAC1_CH0_TX_IRQHandler/7:
  Node: GMAC1_Common_IRQHandler/6:
  Node: GMAC0_CH1_RX_IRQHandler/5:
  Node: GMAC0_CH1_TX_IRQHandler/4:
  Node: GMAC0_CH0_RX_IRQHandler/3:
  Node: GMAC0_CH0_TX_IRQHandler/2:
  Node: GMAC0_Common_IRQHandler/1:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

GMAC_RxIRQHandler/13 (GMAC_RxIRQHandler) @05ebc460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GMAC1_CH1_RX_IRQHandler/10 (1073741824 (estimated locally),1.00 per call) GMAC1_CH0_RX_IRQHandler/8 (1073741824 (estimated locally),1.00 per call) GMAC0_CH1_RX_IRQHandler/5 (1073741824 (estimated locally),1.00 per call) GMAC0_CH0_RX_IRQHandler/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_TxIRQHandler/12 (GMAC_TxIRQHandler) @05ebc2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GMAC1_CH1_TX_IRQHandler/9 (1073741824 (estimated locally),1.00 per call) GMAC1_CH0_TX_IRQHandler/7 (1073741824 (estimated locally),1.00 per call) GMAC0_CH1_TX_IRQHandler/4 (1073741824 (estimated locally),1.00 per call) GMAC0_CH0_TX_IRQHandler/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_CommonIRQHandler/11 (GMAC_CommonIRQHandler) @05ebc0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GMAC1_Common_IRQHandler/6 (1073741824 (estimated locally),1.00 per call) GMAC0_Common_IRQHandler/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC1_CH1_RX_IRQHandler/10 (GMAC1_CH1_RX_IRQHandler) @05eb8620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_RxIRQHandler/13 (1073741824 (estimated locally),1.00 per call) 
GMAC1_CH1_TX_IRQHandler/9 (GMAC1_CH1_TX_IRQHandler) @05eb80e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TxIRQHandler/12 (1073741824 (estimated locally),1.00 per call) 
GMAC1_CH0_RX_IRQHandler/8 (GMAC1_CH0_RX_IRQHandler) @05eb8d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_RxIRQHandler/13 (1073741824 (estimated locally),1.00 per call) 
GMAC1_CH0_TX_IRQHandler/7 (GMAC1_CH0_TX_IRQHandler) @05eb8a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TxIRQHandler/12 (1073741824 (estimated locally),1.00 per call) 
GMAC1_Common_IRQHandler/6 (GMAC1_Common_IRQHandler) @05eb87e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_CommonIRQHandler/11 (1073741824 (estimated locally),1.00 per call) 
GMAC0_CH1_RX_IRQHandler/5 (GMAC0_CH1_RX_IRQHandler) @05eb8540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_RxIRQHandler/13 (1073741824 (estimated locally),1.00 per call) 
GMAC0_CH1_TX_IRQHandler/4 (GMAC0_CH1_TX_IRQHandler) @05eb82a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TxIRQHandler/12 (1073741824 (estimated locally),1.00 per call) 
GMAC0_CH0_RX_IRQHandler/3 (GMAC0_CH0_RX_IRQHandler) @05eb8000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_RxIRQHandler/13 (1073741824 (estimated locally),1.00 per call) 
GMAC0_CH0_TX_IRQHandler/2 (GMAC0_CH0_TX_IRQHandler) @0632fb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TxIRQHandler/12 (1073741824 (estimated locally),1.00 per call) 
GMAC0_Common_IRQHandler/1 (GMAC0_Common_IRQHandler) @0632fd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_CommonIRQHandler/11 (1073741824 (estimated locally),1.00 per call) 

;; Function GMAC0_Common_IRQHandler (GMAC0_Common_IRQHandler, funcdef_no=1, decl_uid=6681, cgraph_uid=2, symbol_order=1)

Modification phase of node GMAC0_Common_IRQHandler/1
GMAC0_Common_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_CommonIRQHandler (0);
  return;

}



;; Function GMAC0_CH0_TX_IRQHandler (GMAC0_CH0_TX_IRQHandler, funcdef_no=2, decl_uid=6683, cgraph_uid=3, symbol_order=2)

Modification phase of node GMAC0_CH0_TX_IRQHandler/2
GMAC0_CH0_TX_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_TxIRQHandler (0, 0);
  return;

}



;; Function GMAC0_CH0_RX_IRQHandler (GMAC0_CH0_RX_IRQHandler, funcdef_no=3, decl_uid=6685, cgraph_uid=4, symbol_order=3)

Modification phase of node GMAC0_CH0_RX_IRQHandler/3
GMAC0_CH0_RX_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_RxIRQHandler (0, 0);
  return;

}



;; Function GMAC0_CH1_TX_IRQHandler (GMAC0_CH1_TX_IRQHandler, funcdef_no=4, decl_uid=6687, cgraph_uid=5, symbol_order=4)

Modification phase of node GMAC0_CH1_TX_IRQHandler/4
GMAC0_CH1_TX_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_TxIRQHandler (0, 1);
  return;

}



;; Function GMAC0_CH1_RX_IRQHandler (GMAC0_CH1_RX_IRQHandler, funcdef_no=5, decl_uid=6689, cgraph_uid=6, symbol_order=5)

Modification phase of node GMAC0_CH1_RX_IRQHandler/5
GMAC0_CH1_RX_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_RxIRQHandler (0, 1);
  return;

}



;; Function GMAC1_Common_IRQHandler (GMAC1_Common_IRQHandler, funcdef_no=6, decl_uid=6691, cgraph_uid=7, symbol_order=6)

Modification phase of node GMAC1_Common_IRQHandler/6
GMAC1_Common_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_CommonIRQHandler (1);
  return;

}



;; Function GMAC1_CH0_TX_IRQHandler (GMAC1_CH0_TX_IRQHandler, funcdef_no=7, decl_uid=6693, cgraph_uid=8, symbol_order=7)

Modification phase of node GMAC1_CH0_TX_IRQHandler/7
GMAC1_CH0_TX_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_TxIRQHandler (1, 0);
  return;

}



;; Function GMAC1_CH0_RX_IRQHandler (GMAC1_CH0_RX_IRQHandler, funcdef_no=8, decl_uid=6695, cgraph_uid=9, symbol_order=8)

Modification phase of node GMAC1_CH0_RX_IRQHandler/8
GMAC1_CH0_RX_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_RxIRQHandler (1, 0);
  return;

}



;; Function GMAC1_CH1_TX_IRQHandler (GMAC1_CH1_TX_IRQHandler, funcdef_no=9, decl_uid=6697, cgraph_uid=10, symbol_order=9)

Modification phase of node GMAC1_CH1_TX_IRQHandler/9
GMAC1_CH1_TX_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_TxIRQHandler (1, 1);
  return;

}



;; Function GMAC1_CH1_RX_IRQHandler (GMAC1_CH1_RX_IRQHandler, funcdef_no=10, decl_uid=6699, cgraph_uid=11, symbol_order=10)

Modification phase of node GMAC1_CH1_RX_IRQHandler/10
GMAC1_CH1_RX_IRQHandler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  GMAC_RxIRQHandler (1, 1);
  return;

}


