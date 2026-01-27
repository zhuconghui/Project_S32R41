
IPA constant propagation start:
Determining dynamic type for call: icmp_send_response (p_5(D), 11, t_6(D));
  Starting walk at: icmp_send_response (p_5(D), 11, t_6(D));
  instance pointer: p_5(D)  Outer instance pointer: p_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: icmp_send_response (p_5(D), 3, t_6(D));
  Starting walk at: icmp_send_response (p_5(D), 3, t_6(D));
  instance pointer: p_5(D)  Outer instance pointer: p_5(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  ip4_route/15:
  Jump functions of caller  ip4_output_if/14:
  Jump functions of caller  pbuf_copy/13:
  Jump functions of caller  pbuf_remove_header/12:
  Jump functions of caller  memcpy/11:
  Jump functions of caller  pbuf_free/10:
  Jump functions of caller  pbuf_alloc/9:
  Jump functions of caller  pbuf_add_header/8:
  Jump functions of caller  ip4_addr_isbroadcast_u32/7:
  Jump functions of caller  icmp_send_response/4:
  Jump functions of caller  icmp_time_exceeded/3:
    callsite  icmp_time_exceeded/3 -> icmp_send_response/4 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 11
         value: 0xb, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  icmp_dest_unreach/2:
    callsite  icmp_dest_unreach/2 -> icmp_send_response/4 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  icmp_input/1:

 Propagating constants:

Not considering icmp_time_exceeded for cloning; -fipa-cp-clone disabled.
Not considering icmp_dest_unreach for cloning; -fipa-cp-clone disabled.
Not considering icmp_input for cloning; -fipa-cp-clone disabled.

overall_size: 281, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: icmp_send_response/4:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 3 [loc_time: 1, loc_size: 58, prop_time: 0, prop_size: 0]
               11 [loc_time: 1, loc_size: 58, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0xb, mask = 0x8
         u8_t [3, 11]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: icmp_time_exceeded/3:
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
  Node: icmp_dest_unreach/2:
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
  Node: icmp_input/1:
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

IPA decision stage:

Propagated bits info for function icmp_send_response/4:
 param 1: value = 0xb, mask = 0x8

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

ip4_route/15 (ip4_route) @060ae700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp_send_response/4 (52886 (estimated locally),0.27 per call) 
  Calls: 
ip4_output_if/14 (ip4_output_if) @060ae460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp_input/1 (43714 (estimated locally),0.00 per call) icmp_send_response/4 (28278 (estimated locally),0.14 per call) 
  Calls: 
pbuf_copy/13 (pbuf_copy) @060ae380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp_input/1 (38020 (estimated locally),0.00 per call) 
  Calls: 
pbuf_remove_header/12 (pbuf_remove_header) @060ae2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp_input/1 (214748 (estimated locally),0.01 per call) icmp_input/1 (115213 (estimated locally),0.01 per call) 
  Calls: 
memcpy/11 (memcpy) @060ae1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp_input/1 (115213 (estimated locally),0.01 per call) icmp_send_response/4 (52886 (estimated locally),0.27 per call) 
  Calls: 
pbuf_free/10 (pbuf_free) @060ae0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp_input/1 (2106191 (estimated locally),0.10 per call) icmp_input/1 (12746407 (estimated locally),0.60 per call) icmp_input/1 (6340064 (estimated locally),0.30 per call) icmp_input/1 (25093 (estimated locally),0.00 per call) icmp_input/1 (12927 (estimated locally),0.00 per call) icmp_input/1 (59352 (estimated locally),0.00 per call) icmp_send_response/4 (52886 (estimated locally),0.27 per call) 
  Calls: 
pbuf_alloc/9 (pbuf_alloc) @060ae000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp_input/1 (213119 (estimated locally),0.01 per call) icmp_send_response/4 (195653 (estimated locally),1.00 per call) 
  Calls: 
pbuf_add_header/8 (pbuf_add_header) @06099d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp_input/1 (132467 (estimated locally),0.01 per call) icmp_input/1 (650752 (estimated locally),0.03 per call) 
  Calls: 
ip4_addr_isbroadcast_u32/7 (ip4_addr_isbroadcast_u32) @060992a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp_input/1 (2017159 (estimated locally),0.09 per call) 
  Calls: 
ip_data/6 (ip_data) @060ad090
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: icmp_input/1 (read)icmp_input/1 (read)icmp_input/1 (read)icmp_input/1 (read)icmp_input/1 (read)icmp_input/1 (addr)
  Availability: not_available
  Varpool flags:
lwip_stats/5 (lwip_stats) @060ad048
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: icmp_send_response/4 (read)icmp_send_response/4 (write)icmp_dest_unreach/2 (read)icmp_dest_unreach/2 (write)icmp_send_response/4 (read)icmp_send_response/4 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_send_response/4 (read)icmp_send_response/4 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_input/1 (read)icmp_input/1 (write)icmp_time_exceeded/3 (read)icmp_time_exceeded/3 (write)
  Availability: not_available
  Varpool flags:
icmp_send_response/4 (icmp_send_response) @06099c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)
  Referring: 
  Availability: local
  Function flags: count:195653 (estimated locally) body local optimize_size
  Called by: icmp_time_exceeded/3 (1073741824 (estimated locally),1.00 per call) icmp_dest_unreach/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_free/10 (52886 (estimated locally),0.27 per call) ip4_output_if/14 (28278 (estimated locally),0.14 per call) ip4_route/15 (52886 (estimated locally),0.27 per call) memcpy/11 (52886 (estimated locally),0.27 per call) pbuf_alloc/9 (195653 (estimated locally),1.00 per call) 
icmp_time_exceeded/3 (icmp_time_exceeded) @060991c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/5 (read)lwip_stats/5 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: icmp_send_response/4 (1073741824 (estimated locally),1.00 per call) 
icmp_dest_unreach/2 (icmp_dest_unreach) @06089ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/5 (read)lwip_stats/5 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: icmp_send_response/4 (1073741824 (estimated locally),1.00 per call) 
icmp_input/1 (icmp_input) @06089e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)ip_data/6 (read)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)ip_data/6 (addr)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)lwip_stats/5 (read)lwip_stats/5 (write)
  Referring: 
  Availability: available
  Function flags: count:21378161 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/10 (2106191 (estimated locally),0.10 per call) pbuf_free/10 (12746407 (estimated locally),0.60 per call) pbuf_free/10 (6340064 (estimated locally),0.30 per call) ip4_output_if/14 (43714 (estimated locally),0.00 per call) pbuf_add_header/8 (132467 (estimated locally),0.01 per call) pbuf_remove_header/12 (214748 (estimated locally),0.01 per call) pbuf_free/10 (25093 (estimated locally),0.00 per call) pbuf_free/10 (12927 (estimated locally),0.00 per call) pbuf_copy/13 (38020 (estimated locally),0.00 per call) pbuf_remove_header/12 (115213 (estimated locally),0.01 per call) memcpy/11 (115213 (estimated locally),0.01 per call) pbuf_free/10 (59352 (estimated locally),0.00 per call) pbuf_alloc/9 (213119 (estimated locally),0.01 per call) pbuf_add_header/8 (650752 (estimated locally),0.03 per call) ip4_addr_isbroadcast_u32/7 (2017159 (estimated locally),0.09 per call) 

;; Function icmp_send_response (icmp_send_response, funcdef_no=4, decl_uid=7186, cgraph_uid=5, symbol_order=4)

Modification phase of node icmp_send_response/4
Adjusting mask for param 1 to 0x8
Setting value range of param 1 [3, 11]
icmp_send_response (struct pbuf * p, u8_t type, u8_t code)
{
  u16_t response_pkt_len;
  struct netif * netif;
  struct ip4_addr_t iphdr_src;
  struct icmp_echo_hdr * icmphdr;
  struct ip_hdr * iphdr;
  struct pbuf * q;
  long unsigned int _1;
  long unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  short unsigned int _7;
  unsigned int _8;
  unsigned int _9;
  unsigned int _10;
  void * _11;
  long unsigned int _12;
  short unsigned int _13;
  short unsigned int _14;

  <bb 2> [local count: 195653]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = lwip_stats.mib2.icmpoutmsgs;
  _2 = _1 + 1;
  lwip_stats.mib2.icmpoutmsgs = _2;
  # DEBUG BEGIN_STMT
  # DEBUG response_pkt_len => 28
  # DEBUG BEGIN_STMT
  _3 = p_21(D)->tot_len;
  if (_3 <= 27)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 97827]:
  # DEBUG BEGIN_STMT
  # DEBUG response_pkt_len => _3

  <bb 4> [local count: 195653]:
  # response_pkt_len_15 = PHI <28(2), _3(3)>
  # DEBUG response_pkt_len => response_pkt_len_15
  # DEBUG BEGIN_STMT
  _4 = response_pkt_len_15 + 8;
  q_23 = pbuf_alloc (54, _4, 640);
  # DEBUG q => q_23
  # DEBUG BEGIN_STMT
  if (q_23 == 0B)
    goto <bb 5>; [18.09%]
  else
    goto <bb 6>; [81.91%]

  <bb 5> [local count: 35394]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = lwip_stats.mib2.icmpouterrors;
  _6 = _5 + 1;
  lwip_stats.mib2.icmpouterrors = _6;
  # DEBUG BEGIN_STMT
  iphdr_src ={v} {CLOBBER};
  goto <bb 11>; [100.00%]

  <bb 6> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = q_23->len;
  _8 = (unsigned int) _7;
  _9 = (unsigned int) response_pkt_len_15;
  _10 = _9 + 8;
  if (_8 < _10)
    goto <bb 12>; [67.00%]
  else
    goto <bb 8>; [33.00%]

  <bb 12> [local count: 107374]:

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iphdr_24 = p_21(D)->payload;
  # DEBUG iphdr => iphdr_24
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  icmphdr_25 = q_23->payload;
  # DEBUG icmphdr => icmphdr_25
  # DEBUG BEGIN_STMT
  icmphdr_25->type = type_26(D);
  # DEBUG BEGIN_STMT
  icmphdr_25->code = code_28(D);
  # DEBUG BEGIN_STMT
  icmphdr_25->id = 0;
  # DEBUG BEGIN_STMT
  icmphdr_25->seqno = 0;
  # DEBUG BEGIN_STMT
  _11 = icmphdr_25 + 8;
  memcpy (_11, iphdr_24, _9);
  # DEBUG BEGIN_STMT
  _12 = iphdr_24->src.addr;
  iphdr_src.addr = _12;
  # DEBUG BEGIN_STMT
  netif_35 = ip4_route (&iphdr_src);
  # DEBUG netif => netif_35
  # DEBUG BEGIN_STMT
  if (netif_35 != 0B)
    goto <bb 9>; [53.47%]
  else
    goto <bb 10>; [46.53%]

  <bb 9> [local count: 28278]:
  # DEBUG BEGIN_STMT
  icmphdr_25->chksum = 0;
  # DEBUG BEGIN_STMT
  _13 = lwip_stats.icmp.xmit;
  _14 = _13 + 1;
  lwip_stats.icmp.xmit = _14;
  # DEBUG BEGIN_STMT
  ip4_output_if (q_23, 0B, &iphdr_src, 255, 0, 1, netif_35);

  <bb 10> [local count: 52886]:
  # DEBUG BEGIN_STMT
  pbuf_free (q_23);
  iphdr_src ={v} {CLOBBER};

  <bb 11> [local count: 88279]:
  return;

}



;; Function icmp_input (icmp_input, funcdef_no=1, decl_uid=6897, cgraph_uid=2, symbol_order=1)

Modification phase of node icmp_input/1
icmp_input (struct pbuf * p, struct netif * inp)
{
  struct ip_hdr * iphdr;
  u16_t alloc_len;
  struct pbuf * r;
  u16_t hlen;
  const struct ip_hdr * iphdr_in;
  struct icmp_echo_hdr * iecho;
  u8_t type;
  short unsigned int _1;
  short unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  short unsigned int _8;
  void * _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  struct netif * _16;
  unsigned char _17;
  short unsigned int _18;
  int _19;
  int _20;
  unsigned int _21;
  unsigned char _22;
  short unsigned int _23;
  short unsigned int _24;
  unsigned int _25;
  unsigned int _26;
  unsigned int _27;
  void * _28;
  unsigned char _29;
  signed char _30;
  unsigned char _31;
  unsigned int _32;
  unsigned char _33;
  long unsigned int _34;
  long unsigned int _35;
  short unsigned int _36;
  short unsigned int _37;
  long unsigned int _38;
  long unsigned int _39;
  long unsigned int _40;
  long unsigned int _41;
  long unsigned int _42;
  long unsigned int _43;
  long unsigned int _44;
  long unsigned int _45;
  long unsigned int _46;
  long unsigned int _47;
  long unsigned int _48;
  long unsigned int _49;
  long unsigned int _50;
  long unsigned int _51;
  long unsigned int _52;
  long unsigned int _53;
  long unsigned int _54;
  long unsigned int _55;
  long unsigned int _56;
  long unsigned int _57;
  long unsigned int _58;
  long unsigned int _59;
  short unsigned int _60;
  short unsigned int _61;
  short unsigned int _62;
  short unsigned int _63;
  short unsigned int _64;
  short unsigned int _65;
  long unsigned int _66;
  long unsigned int _67;
  short unsigned int _68;
  short unsigned int _69;
  long unsigned int _70;
  long unsigned int _71;

  <bb 2> [local count: 21378161]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = lwip_stats.icmp.recv;
  _2 = _1 + 1;
  lwip_stats.icmp.recv = _2;
  # DEBUG BEGIN_STMT
  _3 = lwip_stats.mib2.icmpinmsgs;
  _4 = _3 + 1;
  lwip_stats.mib2.icmpinmsgs = _4;
  # DEBUG BEGIN_STMT
  iphdr_in_85 = ip_data.current_ip4_header;
  # DEBUG iphdr_in => iphdr_in_85
  # DEBUG BEGIN_STMT
  _5 = iphdr_in_85->_v_hl;
  _6 = _5 & 15;
  _7 = _6 * 4;
  hlen_86 = (u16_t) _7;
  # DEBUG hlen => hlen_86
  # DEBUG BEGIN_STMT
  if (hlen_86 <= 19)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 7268575]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 50>; [100.00%]

  <bb 4> [local count: 14109586]:
  # DEBUG BEGIN_STMT
  _8 = p_87(D)->len;
  if (_8 <= 3)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 4797259]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 50>; [100.00%]

  <bb 6> [local count: 9312327]:
  # DEBUG BEGIN_STMT
  _9 = p_87(D)->payload;
  type_88 = MEM[(u8_t *)_9];
  # DEBUG type => type_88
  # DEBUG BEGIN_STMT
  switch (type_88) <default: <L38> [33.33%], case 0: <L4> [33.33%], case 8: <L5> [33.33%]>

  <bb 7> [local count: 3103798]:
<L4>:
  # DEBUG BEGIN_STMT
  _10 = lwip_stats.mib2.icmpinechoreps;
  _11 = _10 + 1;
  lwip_stats.mib2.icmpinechoreps = _11;
  # DEBUG BEGIN_STMT
  goto <bb 49>; [100.00%]

  <bb 8> [local count: 3103798]:
<L5>:
  # DEBUG BEGIN_STMT
  _12 = lwip_stats.mib2.icmpinechos;
  _13 = _12 + 1;
  lwip_stats.mib2.icmpinechos = _13;
  # DEBUG BEGIN_STMT
  # DEBUG src => &ip_data.current_iphdr_dest.u_addr.ip4
  # DEBUG BEGIN_STMT
  _14 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  _15 = _14 & 240;
  if (_15 == 224)
    goto <bb 9>; [35.01%]
  else
    goto <bb 10>; [64.99%]

  <bb 9> [local count: 1086640]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 51>; [100.00%]

  <bb 10> [local count: 2017159]:
  # DEBUG BEGIN_STMT
  _16 = ip_data.current_netif;
  _17 = ip4_addr_isbroadcast_u32 (_14, _16);
  if (_17 != 0)
    goto <bb 11>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 11> [local count: 685834]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 51>; [100.00%]

  <bb 12> [local count: 1331325]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _18 = p_87(D)->tot_len;
  if (_18 <= 7)
    goto <bb 13>; [51.12%]
  else
    goto <bb 14>; [48.88%]

  <bb 13> [local count: 680573]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 50>; [100.00%]

  <bb 14> [local count: 650752]:
  # DEBUG BEGIN_STMT
  _19 = (int) _7;
  _20 = _19 + 14;
  _21 = (unsigned int) _20;
  _22 = pbuf_add_header (p_87(D), _21);
  if (_22 != 0)
    goto <bb 15>; [67.00%]
  else
    goto <bb 26>; [33.00%]

  <bb 15> [local count: 436004]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = p_87(D)->tot_len;
  alloc_len_94 = _23 + hlen_86;
  # DEBUG alloc_len => alloc_len_94
  # DEBUG BEGIN_STMT
  if (_23 > alloc_len_94)
    goto <bb 16>; [51.12%]
  else
    goto <bb 17>; [48.88%]

  <bb 16> [local count: 222885]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 51>; [100.00%]

  <bb 17> [local count: 213119]:
  # DEBUG BEGIN_STMT
  r_96 = pbuf_alloc (14, alloc_len_94, 640);
  # DEBUG r => r_96
  # DEBUG BEGIN_STMT
  if (r_96 == 0B)
    goto <bb 18>; [18.09%]
  else
    goto <bb 19>; [81.91%]

  <bb 18> [local count: 38553]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 51>; [100.00%]

  <bb 19> [local count: 174565]:
  # DEBUG BEGIN_STMT
  _24 = r_96->len;
  _25 = (unsigned int) _24;
  _26 = (unsigned int) _7;
  _27 = _26 + 8;
  if (_25 < _27)
    goto <bb 20>; [34.00%]
  else
    goto <bb 21>; [66.00%]

  <bb 20> [local count: 59352]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (r_96);
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 51>; [100.00%]

  <bb 21> [local count: 115213]:
  # DEBUG BEGIN_STMT
  _28 = r_96->payload;
  memcpy (_28, iphdr_in_85, _26);
  # DEBUG BEGIN_STMT
  _29 = pbuf_remove_header (r_96, _26);
  if (_29 != 0)
    goto <bb 53>; [67.00%]
  else
    goto <bb 23>; [33.00%]

  <bb 53> [local count: 77193]:

  <bb 22> [local count: 771929413]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 55> [local count: 771929413]:
  goto <bb 22>; [100.00%]

  <bb 23> [local count: 38020]:
  # DEBUG BEGIN_STMT
  _30 = pbuf_copy (r_96, p_87(D));
  if (_30 != 0)
    goto <bb 24>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 24> [local count: 12927]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (r_96);
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 51>; [100.00%]

  <bb 25> [local count: 25093]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_87(D));
  # DEBUG BEGIN_STMT
  # DEBUG p => r_96
  goto <bb 28>; [100.00%]

  <bb 26> [local count: 214748]:
  # DEBUG BEGIN_STMT
  _31 = pbuf_remove_header (p_87(D), _21);
  if (_31 != 0)
    goto <bb 54>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 54> [local count: 107374]:

  <bb 27> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 56> [local count: 1073741824]:
  goto <bb 27>; [100.00%]

  <bb 28> [local count: 132467]:
  # p_72 = PHI <r_96(25), p_87(D)(26)>
  # DEBUG p => p_72
  # DEBUG BEGIN_STMT
  iecho_104 = p_72->payload;
  # DEBUG iecho => iecho_104
  # DEBUG BEGIN_STMT
  _32 = (unsigned int) _7;
  _33 = pbuf_add_header (p_72, _32);
  if (_33 != 0)
    goto <bb 49>; [67.00%]
  else
    goto <bb 29>; [33.00%]

  <bb 29> [local count: 43714]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iphdr_106 = p_72->payload;
  # DEBUG iphdr => iphdr_106
  # DEBUG BEGIN_STMT
  _34 = MEM[(const struct ip4_addr_t *)&ip_data + 44B].addr;
  iphdr_106->src.addr = _34;
  # DEBUG BEGIN_STMT
  _35 = ip_data.current_iphdr_src.u_addr.ip4.addr;
  iphdr_106->dest.addr = _35;
  # DEBUG BEGIN_STMT
  iecho_104->type = 0;
  # DEBUG BEGIN_STMT
  iecho_104->chksum = 0;
  # DEBUG BEGIN_STMT
  iphdr_106->_ttl = 255;
  # DEBUG BEGIN_STMT
  iphdr_106->_chksum = 0;
  # DEBUG BEGIN_STMT
  _36 = lwip_stats.icmp.xmit;
  _37 = _36 + 1;
  lwip_stats.icmp.xmit = _37;
  # DEBUG BEGIN_STMT
  _38 = lwip_stats.mib2.icmpoutmsgs;
  _39 = _38 + 1;
  lwip_stats.mib2.icmpoutmsgs = _39;
  # DEBUG BEGIN_STMT
  _40 = lwip_stats.mib2.icmpoutechoreps;
  _41 = _40 + 1;
  lwip_stats.mib2.icmpoutechoreps = _41;
  # DEBUG BEGIN_STMT
  ip4_output_if (p_72, &ip_data.current_iphdr_dest.u_addr.ip4, 0B, 255, 0, 1, inp_116(D));
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  goto <bb 49>; [100.00%]

  <bb 30> [local count: 3103798]:
<L38>:
  # DEBUG BEGIN_STMT
  if (type_88 == 3)
    goto <bb 31>; [34.00%]
  else
    goto <bb 32>; [66.00%]

  <bb 31> [local count: 1055291]:
  # DEBUG BEGIN_STMT
  _42 = lwip_stats.mib2.icmpindestunreachs;
  _43 = _42 + 1;
  lwip_stats.mib2.icmpindestunreachs = _43;
  goto <bb 48>; [100.00%]

  <bb 32> [local count: 2048507]:
  # DEBUG BEGIN_STMT
  if (type_88 == 11)
    goto <bb 33>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 33> [local count: 696492]:
  # DEBUG BEGIN_STMT
  _44 = lwip_stats.mib2.icmpintimeexcds;
  _45 = _44 + 1;
  lwip_stats.mib2.icmpintimeexcds = _45;
  goto <bb 48>; [100.00%]

  <bb 34> [local count: 1352015]:
  # DEBUG BEGIN_STMT
  if (type_88 == 12)
    goto <bb 35>; [34.00%]
  else
    goto <bb 36>; [66.00%]

  <bb 35> [local count: 459685]:
  # DEBUG BEGIN_STMT
  _46 = lwip_stats.mib2.icmpinparmprobs;
  _47 = _46 + 1;
  lwip_stats.mib2.icmpinparmprobs = _47;
  goto <bb 48>; [100.00%]

  <bb 36> [local count: 892330]:
  # DEBUG BEGIN_STMT
  if (type_88 == 4)
    goto <bb 37>; [34.00%]
  else
    goto <bb 38>; [66.00%]

  <bb 37> [local count: 303392]:
  # DEBUG BEGIN_STMT
  _48 = lwip_stats.mib2.icmpinsrcquenchs;
  _49 = _48 + 1;
  lwip_stats.mib2.icmpinsrcquenchs = _49;
  goto <bb 48>; [100.00%]

  <bb 38> [local count: 588938]:
  # DEBUG BEGIN_STMT
  if (type_88 == 5)
    goto <bb 39>; [34.00%]
  else
    goto <bb 40>; [66.00%]

  <bb 39> [local count: 200239]:
  # DEBUG BEGIN_STMT
  _50 = lwip_stats.mib2.icmpinredirects;
  _51 = _50 + 1;
  lwip_stats.mib2.icmpinredirects = _51;
  goto <bb 48>; [100.00%]

  <bb 40> [local count: 388699]:
  # DEBUG BEGIN_STMT
  if (type_88 == 13)
    goto <bb 41>; [34.00%]
  else
    goto <bb 42>; [66.00%]

  <bb 41> [local count: 132158]:
  # DEBUG BEGIN_STMT
  _52 = lwip_stats.mib2.icmpintimestamps;
  _53 = _52 + 1;
  lwip_stats.mib2.icmpintimestamps = _53;
  goto <bb 48>; [100.00%]

  <bb 42> [local count: 256541]:
  # DEBUG BEGIN_STMT
  if (type_88 == 14)
    goto <bb 43>; [34.00%]
  else
    goto <bb 44>; [66.00%]

  <bb 43> [local count: 87224]:
  # DEBUG BEGIN_STMT
  _54 = lwip_stats.mib2.icmpintimestampreps;
  _55 = _54 + 1;
  lwip_stats.mib2.icmpintimestampreps = _55;
  goto <bb 48>; [100.00%]

  <bb 44> [local count: 169317]:
  # DEBUG BEGIN_STMT
  if (type_88 == 17)
    goto <bb 45>; [34.00%]
  else
    goto <bb 46>; [66.00%]

  <bb 45> [local count: 57568]:
  # DEBUG BEGIN_STMT
  _56 = lwip_stats.mib2.icmpinaddrmasks;
  _57 = _56 + 1;
  lwip_stats.mib2.icmpinaddrmasks = _57;
  goto <bb 48>; [100.00%]

  <bb 46> [local count: 111749]:
  # DEBUG BEGIN_STMT
  if (type_88 == 18)
    goto <bb 47>; [34.00%]
  else
    goto <bb 48>; [66.00%]

  <bb 47> [local count: 37995]:
  # DEBUG BEGIN_STMT
  _58 = lwip_stats.mib2.icmpinaddrmaskreps;
  _59 = _58 + 1;
  lwip_stats.mib2.icmpinaddrmaskreps = _59;

  <bb 48> [local count: 3103798]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _60 = lwip_stats.icmp.proterr;
  _61 = _60 + 1;
  lwip_stats.icmp.proterr = _61;
  # DEBUG BEGIN_STMT
  _62 = lwip_stats.icmp.drop;
  _63 = _62 + 1;
  lwip_stats.icmp.drop = _63;

  <bb 49> [local count: 6340064]:
  # p_73 = PHI <p_87(D)(7), p_72(29), p_87(D)(48), p_72(28)>
  # DEBUG p => p_73
  # DEBUG BEGIN_STMT
  pbuf_free (p_73);
  # DEBUG BEGIN_STMT
  goto <bb 52>; [100.00%]

  <bb 50> [local count: 12746407]:
lenerr:
  # DEBUG BEGIN_STMT
  pbuf_free (p_87(D));
  # DEBUG BEGIN_STMT
  _64 = lwip_stats.icmp.lenerr;
  _65 = _64 + 1;
  lwip_stats.icmp.lenerr = _65;
  # DEBUG BEGIN_STMT
  _66 = lwip_stats.mib2.icmpinerrors;
  _67 = _66 + 1;
  lwip_stats.mib2.icmpinerrors = _67;
  # DEBUG BEGIN_STMT
  goto <bb 52>; [100.00%]

  <bb 51> [local count: 2106191]:
icmperr:
  # DEBUG BEGIN_STMT
  pbuf_free (p_87(D));
  # DEBUG BEGIN_STMT
  _68 = lwip_stats.icmp.err;
  _69 = _68 + 1;
  lwip_stats.icmp.err = _69;
  # DEBUG BEGIN_STMT
  _70 = lwip_stats.mib2.icmpinerrors;
  _71 = _70 + 1;
  lwip_stats.mib2.icmpinerrors = _71;
  # DEBUG BEGIN_STMT

  <bb 52> [local count: 21192663]:
  return;

}



;; Function icmp_dest_unreach (icmp_dest_unreach, funcdef_no=2, decl_uid=6900, cgraph_uid=3, symbol_order=2)

Modification phase of node icmp_dest_unreach/2
icmp_dest_unreach (struct pbuf * p, icmp_dur_type t)
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = lwip_stats.mib2.icmpoutdestunreachs;
  _2 = _1 + 1;
  lwip_stats.mib2.icmpoutdestunreachs = _2;
  # DEBUG BEGIN_STMT
  icmp_send_response (p_5(D), 3, t_6(D));
  return;

}



;; Function icmp_time_exceeded (icmp_time_exceeded, funcdef_no=3, decl_uid=6903, cgraph_uid=4, symbol_order=3)

Modification phase of node icmp_time_exceeded/3
icmp_time_exceeded (struct pbuf * p, icmp_te_type t)
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = lwip_stats.mib2.icmpouttimeexcds;
  _2 = _1 + 1;
  lwip_stats.mib2.icmpouttimeexcds = _2;
  # DEBUG BEGIN_STMT
  icmp_send_response (p_5(D), 11, t_6(D));
  return;

}


