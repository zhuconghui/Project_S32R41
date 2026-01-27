
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  gmac_ethernetif_shutdown/6:
  Jump functions of caller  strncmp/5:
  Jump functions of caller  end_tcpip_execution/4:
  Jump functions of caller  is_netif_shutdown_command/3:
  Jump functions of caller  set_software_breakpoint/2:

 Propagating constants:

Not considering end_tcpip_execution for cloning; -fipa-cp-clone disabled.
Not considering is_netif_shutdown_command for cloning; -fipa-cp-clone disabled.
Not considering set_software_breakpoint for cloning; -fipa-cp-clone disabled.

overall_size: 24, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: end_tcpip_execution/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: is_netif_shutdown_command/3:
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
  Node: set_software_breakpoint/2:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

gmac_ethernetif_shutdown/6 (gmac_ethernetif_shutdown) @06ff8b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: end_tcpip_execution/4 (574129754 (estimated locally),0.53 per call) 
  Calls: 
strncmp/5 (strncmp) @06ff89a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: is_netif_shutdown_command/3 (365072220 (estimated locally),0.34 per call) 
  Calls: 
end_tcpip_execution/4 (end_tcpip_execution) @06ff8460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: gmac_ethernetif_shutdown/6 (574129754 (estimated locally),0.53 per call) 
is_netif_shutdown_command/3 (is_netif_shutdown_command) @06ff81c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: netif_shutdown_cmd/1 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: strncmp/5 (365072220 (estimated locally),0.34 per call) 
set_software_breakpoint/2 (set_software_breakpoint) @06ff5e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
netif_shutdown_cmd/1 (netif_shutdown_cmd) @06caec18
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: is_netif_shutdown_command/3 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function set_software_breakpoint (set_software_breakpoint, funcdef_no=1, decl_uid=6897, cgraph_uid=2, symbol_order=2)

Modification phase of node set_software_breakpoint/2
set_software_breakpoint ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0");
  return;

}



;; Function is_netif_shutdown_command (is_netif_shutdown_command, funcdef_no=2, decl_uid=6900, cgraph_uid=3, symbol_order=3)

Modification phase of node is_netif_shutdown_command/3
is_netif_shutdown_command (char * buf_ptr, uint16_t buf_len)
{
  int _1;
  _Bool _2;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  if (buf_len_3(D) == 14)
    goto <bb 3>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 3> [local count: 365072220]:
  _1 = strncmp (buf_ptr_5(D), &netif_shutdown_cmd, 14);
  if (_1 == 0)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 124124555]:
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  # _2 = PHI <1(4), 0(3), 0(2)>
  return _2;

}



;; Function end_tcpip_execution (end_tcpip_execution, funcdef_no=3, decl_uid=6902, cgraph_uid=4, symbol_order=4)

Modification phase of node end_tcpip_execution/4
end_tcpip_execution (struct netif * netif)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (netif_2(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  gmac_ethernetif_shutdown (netif_2(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY set_software_breakpoint
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0");
  return;

}


