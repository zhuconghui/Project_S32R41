
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  nd6_get_next_hop_addr_or_queue/3:
  Jump functions of caller  ethernet_output/2:
  Jump functions of caller  ethip6_output/1:

 Propagating constants:

Not considering ethip6_output for cloning; -fipa-cp-clone disabled.

overall_size: 46, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: ethip6_output/1:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

nd6_get_next_hop_addr_or_queue/3 (nd6_get_next_hop_addr_or_queue) @060b8c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ethip6_output/1 (848578164 (estimated locally),0.79 per call) 
  Calls: 
ethernet_output/2 (ethernet_output) @060b8b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ethip6_output/1 (386722526 (estimated locally),0.36 per call) ethip6_output/1 (225163661 (estimated locally),0.21 per call) 
  Calls: 
ethip6_output/1 (ethip6_output) @060b8700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ethernet_output/2 (386722526 (estimated locally),0.36 per call) nd6_get_next_hop_addr_or_queue/3 (848578164 (estimated locally),0.79 per call) ethernet_output/2 (225163661 (estimated locally),0.21 per call) 

;; Function ethip6_output (ethip6_output, funcdef_no=1, decl_uid=6876, cgraph_uid=2, symbol_order=1)

Modification phase of node ethip6_output/1
ethip6_output (struct netif * netif, struct pbuf * q, const struct ip6_addr_t * ip6addr)
{
  err_t result;
  const u8_t * hwaddr;
  struct eth_addr dest;
  long unsigned int _1;
  long unsigned int _2;
  unsigned char _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;
  u8_t[6] * _7;
  const u8_t * hwaddr.0_8;
  u8_t[6] * _9;
  err_t _10;
  err_t _20;
  err_t _28;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = ip6addr_13(D)->addr[0];
  _2 = _1 & 255;
  if (_2 == 255)
    goto <bb 3>; [20.97%]
  else
    goto <bb 4>; [79.03%]

  <bb 3> [local count: 225163661]:
  # DEBUG BEGIN_STMT
  dest.addr[0] = 51;
  # DEBUG BEGIN_STMT
  dest.addr[1] = 51;
  # DEBUG BEGIN_STMT
  _3 = MEM[(const u8_t *)ip6addr_13(D) + 12B];
  dest.addr[2] = _3;
  # DEBUG BEGIN_STMT
  _4 = MEM[(const u8_t *)ip6addr_13(D) + 13B];
  dest.addr[3] = _4;
  # DEBUG BEGIN_STMT
  _5 = MEM[(const u8_t *)ip6addr_13(D) + 14B];
  dest.addr[4] = _5;
  # DEBUG BEGIN_STMT
  _6 = MEM[(const u8_t *)ip6addr_13(D) + 15B];
  dest.addr[5] = _6;
  # DEBUG BEGIN_STMT
  _7 = &netif_14(D)->hwaddr;
  _28 = ethernet_output (netif_14(D), q_15(D), _7, &dest, 34525);
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 848578164]:
  # DEBUG BEGIN_STMT
  result_17 = nd6_get_next_hop_addr_or_queue (netif_14(D), q_15(D), ip6addr_13(D), &hwaddr);
  # DEBUG result => result_17
  # DEBUG BEGIN_STMT
  if (result_17 != 0)
    goto <bb 7>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 560061588]:
  # DEBUG BEGIN_STMT
  hwaddr.0_8 = hwaddr;
  if (hwaddr.0_8 == 0B)
    goto <bb 7>; [30.95%]
  else
    goto <bb 6>; [69.05%]

  <bb 6> [local count: 386722526]:
  # DEBUG BEGIN_STMT
  MEM[(char * {ref-all})&dest] = MEM[(char * {ref-all})hwaddr.0_8];
  # DEBUG BEGIN_STMT
  _9 = &netif_14(D)->hwaddr;
  _20 = ethernet_output (netif_14(D), q_15(D), _9, &dest, 34525);

  <bb 7> [local count: 1073741824]:
  # _10 = PHI <_28(3), result_17(4), 0(5), _20(6)>
  dest ={v} {CLOBBER};
  hwaddr ={v} {CLOBBER};
  return _10;

}


