
IPA constant propagation start:
Determining dynamic type for call: _40 (netif_58(D), rambuf_72, dest_57(D));
  Starting walk at: _40 (netif_58(D), rambuf_72, dest_57(D));
  instance pointer: netif_58(D)  Outer instance pointer: netif_58(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_37 = lwip_htons (_36);
  Function call may change dynamic type:_35 = lwip_htonl (identification.15_34);
  Function call may change dynamic type:_33 = lwip_htons (_32);
  Function call may change dynamic type:memcpy (_10, original_ip6hdr_66, 40);
  Function call may change dynamic type:rambuf_72 = pbuf_alloc (14, 48, 640);
  Function call may change dynamic type:mtu_60 = nd6_get_destination_mtu (dest_57(D), netif_58(D));
  Function call may change dynamic type:pbuf_free (rambuf_72);
  Function call may change dynamic type:_40 (netif_58(D), rambuf_72, dest_57(D));
  Function call may change dynamic type:_37 = lwip_htons (_36);
  Function call may change dynamic type:_35 = lwip_htonl (identification.15_34);
  Function call may change dynamic type:_33 = lwip_htons (_32);
  Function call may change dynamic type:pbuf_cat (rambuf_72, newpbuf_97);
  Function call may change dynamic type:pbuf_ref (p_41);
  Function call may change dynamic type:newpbuf_97 = pbuf_alloced_custom (0, newpbuflen_93, 65, _22, _23, newpbuflen_93);
  Function call may change dynamic type:pcr_95 = ip6_frag_alloc_pbuf_custom_ref ();
Determining dynamic type for call: _40 (netif_58(D), rambuf_72, dest_57(D));
  Starting walk at: _40 (netif_58(D), rambuf_72, dest_57(D));
  instance pointer: rambuf_72  Outer instance pointer: rambuf_72 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_37 = lwip_htons (_36);
  Function call may change dynamic type:_35 = lwip_htonl (identification.15_34);
  Function call may change dynamic type:_33 = lwip_htons (_32);
  Function call may change dynamic type:memcpy (_10, original_ip6hdr_66, 40);
  Function call may change dynamic type:rambuf_72 = pbuf_alloc (14, 48, 640);
  Function call may change dynamic type:mtu_60 = nd6_get_destination_mtu (dest_57(D), netif_58(D));
  Function call may change dynamic type:pbuf_free (rambuf_72);
  Function call may change dynamic type:_40 (netif_58(D), rambuf_72, dest_57(D));
  Function call may change dynamic type:_37 = lwip_htons (_36);
  Function call may change dynamic type:_35 = lwip_htonl (identification.15_34);
  Function call may change dynamic type:_33 = lwip_htons (_32);
  Function call may change dynamic type:pbuf_cat (rambuf_72, newpbuf_97);
  Function call may change dynamic type:pbuf_ref (p_41);
  Function call may change dynamic type:newpbuf_97 = pbuf_alloced_custom (0, newpbuflen_93, 65, _22, _23, newpbuflen_93);
  Function call may change dynamic type:pcr_95 = ip6_frag_alloc_pbuf_custom_ref ();
Determining dynamic type for call: _40 (netif_58(D), rambuf_72, dest_57(D));
  Starting walk at: _40 (netif_58(D), rambuf_72, dest_57(D));
  instance pointer: dest_57(D)  Outer instance pointer: dest_57(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_37 = lwip_htons (_36);
  Function call may change dynamic type:_35 = lwip_htonl (identification.15_34);
  Function call may change dynamic type:_33 = lwip_htons (_32);
  Function call may change dynamic type:memcpy (_10, original_ip6hdr_66, 40);
  Function call may change dynamic type:rambuf_72 = pbuf_alloc (14, 48, 640);
  Function call may change dynamic type:mtu_60 = nd6_get_destination_mtu (dest_57(D), netif_58(D));
  Function call may change dynamic type:pbuf_free (rambuf_72);
  Function call may change dynamic type:_40 (netif_58(D), rambuf_72, dest_57(D));
  Function call may change dynamic type:_37 = lwip_htons (_36);
  Function call may change dynamic type:_35 = lwip_htonl (identification.15_34);
  Function call may change dynamic type:_33 = lwip_htons (_32);
  Function call may change dynamic type:pbuf_cat (rambuf_72, newpbuf_97);
  Function call may change dynamic type:pbuf_ref (p_41);
  Function call may change dynamic type:newpbuf_97 = pbuf_alloced_custom (0, newpbuflen_93, 65, _22, _23, newpbuflen_93);
  Function call may change dynamic type:pcr_95 = ip6_frag_alloc_pbuf_custom_ref ();
Determining dynamic type for call: ip6_frag_free_pbuf_custom_ref (pcr_68);
  Starting walk at: ip6_frag_free_pbuf_custom_ref (pcr_68);
  instance pointer: pcr_68  Outer instance pointer: pcr_95 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:newpbuf_97 = pbuf_alloced_custom (0, newpbuflen_93, 65, _22, _23, newpbuflen_93);
  Function call may change dynamic type:pcr_95 = ip6_frag_alloc_pbuf_custom_ref ();
  Function call may change dynamic type:memcpy (_10, original_ip6hdr_66, 40);
  Function call may change dynamic type:rambuf_72 = pbuf_alloc (14, 48, 640);
  Function call may change dynamic type:mtu_60 = nd6_get_destination_mtu (dest_57(D), netif_58(D));
  Function call may change dynamic type:pbuf_free (rambuf_72);
  Function call may change dynamic type:_40 (netif_58(D), rambuf_72, dest_57(D));
  Function call may change dynamic type:_37 = lwip_htons (_36);
  Function call may change dynamic type:_35 = lwip_htonl (identification.15_34);
  Function call may change dynamic type:_33 = lwip_htons (_32);
  Function call may change dynamic type:pbuf_cat (rambuf_72, newpbuf_97);
  Function call may change dynamic type:pbuf_ref (p_41);
  Function call may change dynamic type:newpbuf_97 = pbuf_alloced_custom (0, newpbuflen_93, 65, _22, _23, newpbuflen_93);
  Function call may change dynamic type:pcr_95 = ip6_frag_alloc_pbuf_custom_ref ();
Determining dynamic type for call: ip6_frag_free_pbuf_custom_ref (p_4(D));
  Starting walk at: ip6_frag_free_pbuf_custom_ref (p_4(D));
  instance pointer: p_4(D)  Outer instance pointer: p_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (_1);
Determining dynamic type for call: ip6_frag_free_pbuf_custom_ref.part.0 (p_2(D));
  Starting walk at: ip6_frag_free_pbuf_custom_ref.part.0 (p_2(D));
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ip6_reass_remove_oldest_datagram (0B, _50);
  Starting walk at: ip6_reass_remove_oldest_datagram (0B, _50);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipr_192 = memp_malloc (11);
  Function call may change dynamic type:len_182 = lwip_htons (_6);
  Function call may change dynamic type:offset_180 = lwip_htons (_4);
  Function call may change dynamic type:clen_178 = pbuf_clen (p_175(D));
Determining dynamic type for call: ip6_reass_remove_oldest_datagram (ipr_129, _62);
  Starting walk at: ip6_reass_remove_oldest_datagram (ipr_129, _62);
  instance pointer: ipr_129  Outer instance pointer: ipr_129 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_182 = lwip_htons (_6);
  Function call may change dynamic type:offset_180 = lwip_htons (_4);
  Function call may change dynamic type:clen_178 = pbuf_clen (p_175(D));
  Function call may change dynamic type:memset (_172, 0, 28);
  Function call may change dynamic type:ipr_192 = memp_malloc (11);
  Function call may change dynamic type:ipr_195 = memp_malloc (11);
  Function call may change dynamic type:ip6_reass_remove_oldest_datagram (0B, _50);
Determining dynamic type for call: ip6_reass_free_complete_datagram (oldest_18);
  Starting walk at: ip6_reass_free_complete_datagram (oldest_18);
  instance pointer: oldest_18  Outer instance pointer: oldest_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ip6_reass_free_complete_datagram (oldest_18);
Determining dynamic type for call: ip6_reass_free_complete_datagram (r_4);
  Starting walk at: ip6_reass_free_complete_datagram (r_4);
  instance pointer: r_4  Outer instance pointer: r_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ip6_reass_free_complete_datagram (r_4);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  ip6_frag_free_pbuf_custom_ref.part.0/31:
  Jump functions of caller  lwip_htonl/30:
  Jump functions of caller  pbuf_ref/29:
  Jump functions of caller  pbuf_alloced_custom/28:
  Jump functions of caller  pbuf_alloc/27:
  Jump functions of caller  nd6_get_destination_mtu/25:
  Jump functions of caller  memmove/24:
  Jump functions of caller  pbuf_cat/23:
  Jump functions of caller  pbuf_remove_header/22:
  Jump functions of caller  memcpy/21:
  Jump functions of caller  memset/20:
  Jump functions of caller  memp_malloc/19:
  Jump functions of caller  lwip_htons/17:
  Jump functions of caller  memp_free/15:
  Jump functions of caller  pbuf_free/14:
  Jump functions of caller  pbuf_clen/13:
  Jump functions of caller  icmp6_time_exceeded_with_addrs/12:
  Jump functions of caller  pbuf_header_force/11:
  Jump functions of caller  ip6_frag/10:
    callsite  ip6_frag/10 -> ip6_frag_free_pbuf_custom_ref/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  ip6_frag/10 -> ip6_frag_alloc_pbuf_custom_ref/7 : 
    indirect aggregate callsite, calling param 1, offset 1504, by reference, for stmt _40 (netif_58(D), rambuf_72, dest_57(D));
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ip6_frag_free_pbuf_custom/9:
    callsite  ip6_frag_free_pbuf_custom/9 -> ip6_frag_free_pbuf_custom_ref/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ip6_frag_free_pbuf_custom_ref/8:
    callsite  ip6_frag_free_pbuf_custom_ref/8 -> ip6_frag_free_pbuf_custom_ref.part.0/31 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ip6_frag_alloc_pbuf_custom_ref/7:
  Jump functions of caller  ip6_reass/6:
    callsite  ip6_reass/6 -> ip6_reass_remove_oldest_datagram/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
    callsite  ip6_reass/6 -> ip6_reass_remove_oldest_datagram/5 : 
       param 0: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
  Jump functions of caller  ip6_reass_remove_oldest_datagram/5:
    callsite  ip6_reass_remove_oldest_datagram/5 -> ip6_reass_free_complete_datagram/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ip6_reass_free_complete_datagram/4:
  Jump functions of caller  ip6_reass_tmr/3:
    callsite  ip6_reass_tmr/3 -> ip6_reass_free_complete_datagram/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR

 Propagating constants:

Not considering ip6_frag for cloning; -fipa-cp-clone disabled.
Not considering ip6_frag_free_pbuf_custom for cloning; -fipa-cp-clone disabled.
Not considering ip6_reass for cloning; -fipa-cp-clone disabled.
Not considering ip6_reass_tmr for cloning; -fipa-cp-clone disabled.

overall_size: 649, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: ip6_frag_free_pbuf_custom_ref.part.0/31:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ip6_frag/10:
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
  Node: ip6_frag_free_pbuf_custom/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ip6_frag_free_pbuf_custom_ref/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ip6_frag_alloc_pbuf_custom_ref/7:
  Node: ip6_reass/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ip6_reass_remove_oldest_datagram/5:
    param [0]: VARIABLE
               0B [loc_time: 1, loc_size: 26, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xffff
         int [0, 65535]
        AGGS VARIABLE
  Node: ip6_reass_free_complete_datagram/4:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ip6_reass_tmr/3:

IPA decision stage:

Propagated bits info for function ip6_reass_remove_oldest_datagram/5:
 param 1: value = 0x0, mask = 0xffff

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

ip6_frag_free_pbuf_custom_ref.part.0/31 (ip6_frag_free_pbuf_custom_ref.part.0) @05f9e8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: ip6_frag_free_pbuf_custom_ref/8 (123389 (estimated locally),0.53 per call) 
  Calls: memp_free/15 (1073741824 (estimated locally),1.00 per call) 
lwip_htonl/30 (lwip_htonl) @061e0620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_frag/10 (99415 (estimated locally),0.46 per call) 
  Calls: 
pbuf_ref/29 (pbuf_ref) @061e0540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_frag/10 (1214401 (estimated locally),5.66 per call) 
  Calls: 
pbuf_alloced_custom/28 (pbuf_alloced_custom) @061e0460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_frag/10 (1260536 (estimated locally),5.87 per call) 
  Calls: 
pbuf_alloc/27 (pbuf_alloc) @061e02a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_frag/10 (202240 (estimated locally),0.94 per call) 
  Calls: 
identification.7291/26 (identification) @061d7f30
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ip6_frag/10 (read)ip6_frag/10 (write)ip6_frag/10 (read)
  Availability: available
  Varpool flags:
nd6_get_destination_mtu/25 (nd6_get_destination_mtu) @061e01c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_frag/10 (214748 (estimated locally),1.00 per call) 
  Calls: 
memmove/24 (memmove) @061858c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_reass/6 (1473 (estimated locally),0.01 per call) 
  Calls: 
pbuf_cat/23 (pbuf_cat) @061857e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_frag/10 (1214401 (estimated locally),5.66 per call) ip6_reass/6 (12297 (estimated locally),0.08 per call) 
  Calls: 
pbuf_remove_header/22 (pbuf_remove_header) @06185ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_reass/6 (12297 (estimated locally),0.08 per call) 
  Calls: 
memcpy/21 (memcpy) @06185e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_frag/10 (193439 (estimated locally),0.90 per call) ip6_reass/6 (685 (estimated locally),0.00 per call) 
  Calls: 
memset/20 (memset) @06185d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_reass/6 (1534 (estimated locally),0.01 per call) 
  Calls: 
memp_malloc/19 (memp_malloc) @06185c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_reass/6 (472 (estimated locally),0.00 per call) ip6_reass/6 (1573 (estimated locally),0.01 per call) ip6_frag_alloc_pbuf_custom_ref/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ip_data/18 (ip_data) @061d0c18
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)
  Availability: not_available
  Varpool flags:
lwip_htons/17 (lwip_htons) @06185a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_frag/10 (99415 (estimated locally),0.46 per call) ip6_frag/10 (99415 (estimated locally),0.46 per call) ip6_reass/6 (1473 (estimated locally),0.01 per call) ip6_reass/6 (52886 (estimated locally),0.33 per call) ip6_reass/6 (52886 (estimated locally),0.33 per call) 
  Calls: 
lwip_stats/16 (lwip_stats) @061d0b40
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)ip6_frag/10 (read)ip6_frag/10 (write)ip6_frag/10 (read)ip6_frag/10 (write)ip6_frag/10 (read)ip6_frag/10 (write)ip6_frag/10 (read)ip6_frag/10 (write)
  Availability: not_available
  Varpool flags:
memp_free/15 (memp_free) @06185620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_reass/6 (1164 (estimated locally),0.01 per call) ip6_frag_free_pbuf_custom_ref.part.0/31 (1073741824 (estimated locally),1.00 per call) ip6_reass_free_complete_datagram/4 (113623 (estimated locally),0.40 per call) 
  Calls: 
pbuf_free/14 (pbuf_free) @06185540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_frag/10 (99415 (estimated locally),0.46 per call) ip6_frag/10 (46136 (estimated locally),0.21 per call) ip6_frag/10 (47888 (estimated locally),0.22 per call) ip6_reass/6 (9457 (estimated locally),0.06 per call) ip6_frag_free_pbuf_custom/9 (133963 (estimated locally),0.37 per call) ip6_reass_free_complete_datagram/4 (1844881 (estimated locally),6.50 per call) ip6_reass_free_complete_datagram/4 (30898 (estimated locally),0.11 per call) 
  Calls: 
pbuf_clen/13 (pbuf_clen) @06185460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_reass/6 (1164 (estimated locally),0.01 per call) ip6_reass/6 (52886 (estimated locally),0.33 per call) ip6_reass_free_complete_datagram/4 (1952255 (estimated locally),6.88 per call) ip6_reass_free_complete_datagram/4 (30898 (estimated locally),0.11 per call) 
  Calls: 
icmp6_time_exceeded_with_addrs/12 (icmp6_time_exceeded_with_addrs) @06185380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_reass_free_complete_datagram/4 (30898 (estimated locally),0.11 per call) 
  Calls: 
pbuf_header_force/11 (pbuf_header_force) @061852a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip6_reass/6 (384 (estimated locally),0.00 per call) ip6_reass_free_complete_datagram/4 (93631 (estimated locally),0.33 per call) 
  Calls: 
ip6_frag/10 (ip6_frag) @06174c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: identification.7291/26 (read)identification.7291/26 (write)lwip_stats/16 (read)lwip_stats/16 (write)lwip_stats/16 (read)lwip_stats/16 (write)lwip_stats/16 (read)lwip_stats/16 (write)ip6_frag_free_pbuf_custom/9 (addr)identification.7291/26 (read)lwip_stats/16 (read)lwip_stats/16 (write)
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/14 (99415 (estimated locally),0.46 per call) lwip_htons/17 (99415 (estimated locally),0.46 per call) lwip_htonl/30 (99415 (estimated locally),0.46 per call) lwip_htons/17 (99415 (estimated locally),0.46 per call) pbuf_cat/23 (1214401 (estimated locally),5.66 per call) pbuf_ref/29 (1214401 (estimated locally),5.66 per call) pbuf_free/14 (46136 (estimated locally),0.21 per call) ip6_frag_free_pbuf_custom_ref/8 (46136 (estimated locally),0.21 per call) pbuf_alloced_custom/28 (1260536 (estimated locally),5.87 per call) pbuf_free/14 (47888 (estimated locally),0.22 per call) ip6_frag_alloc_pbuf_custom_ref/7 (1308425 (estimated locally),6.09 per call) memcpy/21 (193439 (estimated locally),0.90 per call) pbuf_alloc/27 (202240 (estimated locally),0.94 per call) nd6_get_destination_mtu/25 (214748 (estimated locally),1.00 per call) 
   Indirect call(99415 (estimated locally),0.46 per call)  of param:1 loaded from aggregate passed by reference at offset 1504 (vptr maybe changed)
ip6_frag_free_pbuf_custom/9 (ip6_frag_free_pbuf_custom) @061747e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: ip6_frag/10 (addr)
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: ip6_frag_free_pbuf_custom_ref/8 (250539 (estimated locally),0.70 per call) pbuf_free/14 (133963 (estimated locally),0.37 per call) 
ip6_frag_free_pbuf_custom_ref/8 (ip6_frag_free_pbuf_custom_ref) @06174540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:230763 (estimated locally) body local optimize_size
  Called by: ip6_frag/10 (46136 (estimated locally),0.21 per call) ip6_frag_free_pbuf_custom/9 (250539 (estimated locally),0.70 per call) 
  Calls: ip6_frag_free_pbuf_custom_ref.part.0/31 (123389 (estimated locally),0.53 per call) 
ip6_frag_alloc_pbuf_custom_ref/7 (ip6_frag_alloc_pbuf_custom_ref) @061742a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ip6_frag/10 (1308425 (estimated locally),6.09 per call) 
  Calls: memp_malloc/19 (1073741824 (estimated locally),1.00 per call) 
ip6_reass/6 (ip6_reass) @06174000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/16 (read)lwip_stats/16 (write)ip_data/18 (read)ip_data/18 (read)lwip_stats/16 (read)lwip_stats/16 (write)lwip_stats/16 (read)lwip_stats/16 (write)reassdatagrams/1 (read)ip_data/18 (read)ip_data/18 (read)ip_data/18 (read)ip_data/18 (read)ip_data/18 (read)ip_data/18 (read)ip_data/18 (read)ip_data/18 (read)ip_data/18 (read)ip_data/18 (read)lwip_stats/16 (read)lwip_stats/16 (write)reassdatagrams/1 (read)lwip_stats/16 (read)lwip_stats/16 (write)reassdatagrams/1 (read)reassdatagrams/1 (write)ip_data/18 (read)ip_data/18 (read)ip_data/18 (read)ip6_reass_pbufcount/2 (read)ip6_reass_pbufcount/2 (read)reassdatagrams/1 (read)lwip_stats/16 (read)lwip_stats/16 (write)lwip_stats/16 (read)lwip_stats/16 (write)lwip_stats/16 (read)lwip_stats/16 (write)lwip_stats/16 (read)lwip_stats/16 (write)ip6_reass_pbufcount/2 (read)ip6_reass_pbufcount/2 (write)ip_data/18 (read)reassdatagrams/1 (read)reassdatagrams/1 (write)ip6_reass_pbufcount/2 (read)ip6_reass_pbufcount/2 (write)lwip_stats/16 (read)lwip_stats/16 (write)
  Referring: 
  Availability: available
  Function flags: count:160260 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/14 (9457 (estimated locally),0.06 per call) pbuf_header_force/11 (384 (estimated locally),0.00 per call) pbuf_clen/13 (1164 (estimated locally),0.01 per call) memp_free/15 (1164 (estimated locally),0.01 per call) lwip_htons/17 (1473 (estimated locally),0.01 per call) memmove/24 (1473 (estimated locally),0.01 per call) pbuf_cat/23 (12297 (estimated locally),0.08 per call) pbuf_remove_header/22 (12297 (estimated locally),0.08 per call) memcpy/21 (685 (estimated locally),0.00 per call) ip6_reass_remove_oldest_datagram/5 (2965 (estimated locally),0.02 per call) memset/20 (1534 (estimated locally),0.01 per call) memp_malloc/19 (472 (estimated locally),0.00 per call) ip6_reass_remove_oldest_datagram/5 (472 (estimated locally),0.00 per call) memp_malloc/19 (1573 (estimated locally),0.01 per call) lwip_htons/17 (52886 (estimated locally),0.33 per call) lwip_htons/17 (52886 (estimated locally),0.33 per call) pbuf_clen/13 (52886 (estimated locally),0.33 per call) 
ip6_reass_remove_oldest_datagram/5 (ip6_reass_remove_oldest_datagram) @06146700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: reassdatagrams/1 (read)ip6_reass_pbufcount/2 (read)reassdatagrams/1 (read)
  Referring: 
  Availability: local
  Function flags: count:12499791 (estimated locally) body local optimize_size
  Called by: ip6_reass/6 (2965 (estimated locally),0.02 per call) ip6_reass/6 (472 (estimated locally),0.00 per call) 
  Calls: ip6_reass_free_complete_datagram/4 (60842826 (estimated locally),4.87 per call) 
ip6_reass_free_complete_datagram/4 (ip6_reass_free_complete_datagram) @06146460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: reassdatagrams/1 (read)reassdatagrams/1 (write)ip6_reass_pbufcount/2 (read)ip6_reass_pbufcount/2 (write)
  Referring: 
  Availability: local
  Function flags: count:283730 (estimated locally) body local optimize_size
  Called by: ip6_reass_tmr/3 (315357973 (estimated locally),2.67 per call) ip6_reass_remove_oldest_datagram/5 (60842826 (estimated locally),4.87 per call) 
  Calls: memp_free/15 (113623 (estimated locally),0.40 per call) pbuf_free/14 (1844881 (estimated locally),6.50 per call) pbuf_clen/13 (1952255 (estimated locally),6.88 per call) pbuf_free/14 (30898 (estimated locally),0.11 per call) pbuf_clen/13 (30898 (estimated locally),0.11 per call) icmp6_time_exceeded_with_addrs/12 (30898 (estimated locally),0.11 per call) pbuf_header_force/11 (93631 (estimated locally),0.33 per call) 
ip6_reass_tmr/3 (ip6_reass_tmr) @0613e8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reassdatagrams/1 (read)
  Referring: 
  Availability: available
  Function flags: count:118111602 (estimated locally) body optimize_size
  Called by: 
  Calls: ip6_reass_free_complete_datagram/4 (315357973 (estimated locally),2.67 per call) 
ip6_reass_pbufcount/2 (ip6_reass_pbufcount) @06142168
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ip6_reass_free_complete_datagram/4 (read)ip6_reass_free_complete_datagram/4 (write)ip6_reass_remove_oldest_datagram/5 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (write)
  Availability: available
  Varpool flags:
reassdatagrams/1 (reassdatagrams) @061420d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ip6_reass_free_complete_datagram/4 (write)ip6_reass_remove_oldest_datagram/5 (read)ip6_reass_remove_oldest_datagram/5 (read)ip6_reass_tmr/3 (read)ip6_reass_free_complete_datagram/4 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (write)ip6_reass/6 (read)ip6_reass/6 (read)ip6_reass/6 (write)
  Availability: available
  Varpool flags:

;; Function ip6_reass_free_complete_datagram (ip6_reass_free_complete_datagram, funcdef_no=2, decl_uid=7170, cgraph_uid=3, symbol_order=4)

Modification phase of node ip6_reass_free_complete_datagram/4
ip6_reass_free_complete_datagram (struct ip6_reassdata * ipr)
{
  struct ip6_addr_t dest_addr;
  struct ip6_addr_t src_addr;
  struct ip6_reass_helper * iprh;
  struct pbuf * p;
  u16_t clen;
  u16_t pbufs_freed;
  struct ip6_reassdata * prev;
  struct pbuf * _1;
  short unsigned int _2;
  struct pbuf * _3;
  void * _5;
  struct ip6_hdr * _6;
  int _7;
  short int _8;
  unsigned char _9;
  struct ip6_hdr * _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  unsigned char _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  unsigned char _20;
  int _21;
  int _22;
  int _23;
  struct ip6_reassdata * reassdatagrams.0_24;
  struct ip6_reassdata * _25;
  struct ip6_reassdata * _26;
  struct ip6_reassdata * _27;
  short unsigned int ip6_reass_pbufcount.1_28;
  short unsigned int _29;
  unsigned int _45;

  <bb 2> [local count: 283730]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pbufs_freed => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = ipr_41(D)->p;
  iprh_42 = _1->payload;
  # DEBUG iprh => iprh_42
  # DEBUG BEGIN_STMT
  _2 = iprh_42->start;
  if (_2 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 3> [local count: 93631]:
  # DEBUG BEGIN_STMT
  # DEBUG p => _1
  # DEBUG BEGIN_STMT
  _3 = iprh_42->next_pbuf;
  ipr_41(D)->p = _3;
  # DEBUG BEGIN_STMT
  _45 = MEM[(char * {ref-all})ipr_41(D) + 12B];
  MEM[(char * {ref-all})iprh_42] = _45;
  # DEBUG BEGIN_STMT
  _5 = _1->payload;
  _6 = ipr_41(D)->iphdr;
  _7 = _5 - _6;
  _8 = (short int) _7;
  _9 = pbuf_header_force (_1, _8);
  if (_9 != 0)
    goto <bb 20>; [67.00%]
  else
    goto <bb 5>; [33.00%]

  <bb 20> [local count: 62733]:

  <bb 4> [local count: 627328051]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 24> [local count: 627328051]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 30898]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = ipr_41(D)->iphdr;
  _11 = _10->src.addr[0];
  src_addr.addr[0] = _11;
  # DEBUG BEGIN_STMT
  _12 = _10->src.addr[1];
  src_addr.addr[1] = _12;
  # DEBUG BEGIN_STMT
  _13 = _10->src.addr[2];
  src_addr.addr[2] = _13;
  # DEBUG BEGIN_STMT
  _14 = _10->src.addr[3];
  src_addr.addr[3] = _14;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = ipr_41(D)->src_zone;
  src_addr.zone = _15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = _10->dest.addr[0];
  dest_addr.addr[0] = _16;
  # DEBUG BEGIN_STMT
  _17 = _10->dest.addr[1];
  dest_addr.addr[1] = _17;
  # DEBUG BEGIN_STMT
  _18 = _10->dest.addr[2];
  dest_addr.addr[2] = _18;
  # DEBUG BEGIN_STMT
  _19 = _10->dest.addr[3];
  dest_addr.addr[3] = _19;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = ipr_41(D)->dest_zone;
  dest_addr.zone = _20;
  # DEBUG BEGIN_STMT
  icmp6_time_exceeded_with_addrs (_1, 1, &src_addr, &dest_addr);
  src_addr ={v} {CLOBBER};
  dest_addr ={v} {CLOBBER};
  # DEBUG BEGIN_STMT
  clen_62 = pbuf_clen (_1);
  # DEBUG clen => clen_62
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pbufs_freed => clen_62
  # DEBUG BEGIN_STMT
  pbuf_free (_1);

  <bb 6> [local count: 220997]:
  # pbufs_freed_31 = PHI <0(2), clen_62(5)>
  # DEBUG pbufs_freed => pbufs_freed_31
  # DEBUG BEGIN_STMT
  p_65 = ipr_41(D)->p;
  # DEBUG p => p_65
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 1952255]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iprh_71 = p_33->payload;
  # DEBUG iprh => iprh_71
  # DEBUG BEGIN_STMT
  # DEBUG pcur => p_33
  # DEBUG BEGIN_STMT
  p_72 = iprh_71->next_pbuf;
  # DEBUG p => p_72
  # DEBUG BEGIN_STMT
  clen_74 = pbuf_clen (p_33);
  # DEBUG clen => clen_74
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _21 = (int) pbufs_freed_32;
  _22 = (int) clen_74;
  _23 = _21 + _22;
  if (_23 > 65535)
    goto <bb 21>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 21> [local count: 107374]:

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 25> [local count: 1073741824]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 1844881]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbufs_freed_75 = pbufs_freed_32 + clen_74;
  # DEBUG pbufs_freed => pbufs_freed_75
  # DEBUG BEGIN_STMT
  pbuf_free (p_33);

  <bb 10> [local count: 2065878]:
  # pbufs_freed_32 = PHI <pbufs_freed_31(6), pbufs_freed_75(9)>
  # p_33 = PHI <p_65(6), p_72(9)>
  # DEBUG p => p_33
  # DEBUG pbufs_freed => pbufs_freed_32
  # DEBUG BEGIN_STMT
  if (p_33 != 0B)
    goto <bb 7>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 11> [local count: 113623]:
  # pbufs_freed_4 = PHI <pbufs_freed_32(10)>
  # DEBUG BEGIN_STMT
  reassdatagrams.0_24 = reassdatagrams;
  if (reassdatagrams.0_24 == ipr_41(D))
    goto <bb 12>; [30.00%]
  else
    goto <bb 23>; [70.00%]

  <bb 23> [local count: 79536]:
  goto <bb 14>; [100.00%]

  <bb 12> [local count: 34087]:
  # DEBUG BEGIN_STMT
  _25 = ipr_41(D)->next;
  reassdatagrams = _25;
  goto <bb 17>; [100.00%]

  <bb 13> [local count: 702611]:
  # DEBUG BEGIN_STMT
  _26 = prev_30->next;
  if (_26 == ipr_41(D))
    goto <bb 15>; [5.50%]
  else
    goto <bb 27>; [94.50%]

  <bb 27> [local count: 663967]:

  <bb 14> [local count: 743504]:
  # prev_30 = PHI <reassdatagrams.0_24(23), _26(27)>
  # DEBUG prev => prev_30
  # DEBUG BEGIN_STMT
  if (prev_30 != 0B)
    goto <bb 13>; [94.50%]
  else
    goto <bb 15>; [5.50%]

  <bb 15> [local count: 79536]:
  # prev_43 = PHI <prev_30(13), prev_30(14)>
  # DEBUG BEGIN_STMT
  if (prev_43 != 0B)
    goto <bb 16>; [70.00%]
  else
    goto <bb 17>; [30.00%]

  <bb 16> [local count: 55675]:
  # DEBUG BEGIN_STMT
  _27 = ipr_41(D)->next;
  prev_43->next = _27;

  <bb 17> [local count: 113623]:
  # DEBUG BEGIN_STMT
  memp_free (11, ipr_41(D));
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ip6_reass_pbufcount.1_28 = ip6_reass_pbufcount;
  if (pbufs_freed_4 > ip6_reass_pbufcount.1_28)
    goto <bb 22>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 22> [local count: 56812]:

  <bb 18> [local count: 568117367]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 26> [local count: 568117367]:
  goto <bb 18>; [100.00%]

  <bb 19> [local count: 56812]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _29 = ip6_reass_pbufcount.1_28 - pbufs_freed_4;
  ip6_reass_pbufcount = _29;
  return;

}



;; Function ip6_reass_remove_oldest_datagram (ip6_reass_remove_oldest_datagram, funcdef_no=3, decl_uid=7173, cgraph_uid=4, symbol_order=5)

Modification phase of node ip6_reass_remove_oldest_datagram/5
Adjusting mask for param 1 to 0xffff
Setting value range of param 1 [0, 65535]
ip6_reass_remove_oldest_datagram (struct ip6_reassdata * ipr, int pbufs_needed)
{
  struct ip6_reassdata * oldest;
  struct ip6_reassdata * r;
  unsigned char _1;
  unsigned char _2;
  short unsigned int ip6_reass_pbufcount.10_3;
  int _4;
  int _5;
  struct ip6_reassdata * reassdatagrams.11_6;

  <bb 2> [local count: 12499791]:

  <bb 3> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oldest_14 = reassdatagrams;
  # DEBUG oldest => oldest_14
  # DEBUG r => oldest_14
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  if (r_7 != ipr_15(D))
    goto <bb 5>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 5> [local count: 668941157]:
  # DEBUG BEGIN_STMT
  _1 = r_7->timer;
  _2 = oldest_9->timer;
  if (_1 <= _2)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 334470578]:
  # DEBUG BEGIN_STMT
  # DEBUG oldest => r_7

  <bb 7> [local count: 955630224]:
  # oldest_8 = PHI <oldest_9(4), oldest_9(5), r_7(6)>
  # DEBUG oldest => oldest_8
  # DEBUG BEGIN_STMT
  r_19 = r_7->next;
  # DEBUG r => r_19

  <bb 8> [local count: 1073741824]:
  # r_7 = PHI <oldest_14(3), r_19(7)>
  # oldest_9 = PHI <oldest_14(3), oldest_8(7)>
  # DEBUG oldest => oldest_9
  # DEBUG r => r_7
  # DEBUG BEGIN_STMT
  if (r_7 != 0B)
    goto <bb 4>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 118111601]:
  # oldest_18 = PHI <oldest_9(8)>
  # DEBUG BEGIN_STMT
  if (ipr_15(D) == oldest_18)
    goto <bb 14>; [3.66%]
  else
    goto <bb 10>; [96.34%]

  <bb 10> [local count: 113788716]:
  # DEBUG BEGIN_STMT
  if (oldest_18 != 0B)
    goto <bb 11>; [53.47%]
  else
    goto <bb 12>; [46.53%]

  <bb 11> [local count: 60842826]:
  # DEBUG BEGIN_STMT
  ip6_reass_free_complete_datagram (oldest_18);

  <bb 12> [local count: 113788716]:
  # DEBUG BEGIN_STMT
  ip6_reass_pbufcount.10_3 = ip6_reass_pbufcount;
  _4 = (int) ip6_reass_pbufcount.10_3;
  _5 = _4 + pbufs_needed_17(D);
  if (_5 > 10)
    goto <bb 13>; [96.34%]
  else
    goto <bb 14>; [3.66%]

  <bb 13> [local count: 109624049]:
  reassdatagrams.11_6 = reassdatagrams;
  if (reassdatagrams.11_6 != 0B)
    goto <bb 15>; [96.34%]
  else
    goto <bb 14>; [3.66%]

  <bb 15> [local count: 105611809]:
  goto <bb 3>; [100.00%]

  <bb 14> [local count: 12499792]:
  return;

}



;; Function ip6_frag_free_pbuf_custom (ip6_frag_free_pbuf_custom, funcdef_no=7, decl_uid=7274, cgraph_uid=8, symbol_order=9)

Modification phase of node ip6_frag_free_pbuf_custom/9
ip6_frag_free_pbuf_custom (struct pbuf * p)
{
  struct pbuf * _1;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pcr => p_4(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_4(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct pbuf_custom_ref *)p_4(D)].original;
  if (_1 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 133963]:
  # DEBUG BEGIN_STMT
  pbuf_free (_1);

  <bb 6> [local count: 250539]:
  # DEBUG BEGIN_STMT
  ip6_frag_free_pbuf_custom_ref (p_4(D));
  return;

}



;; Function ip6_reass_tmr (ip6_reass_tmr, funcdef_no=1, decl_uid=6885, cgraph_uid=2, symbol_order=3)

Modification phase of node ip6_reass_tmr/3
ip6_reass_tmr ()
{
  struct ip6_reassdata * r;
  unsigned char _1;
  unsigned char _3;

  <bb 2> [local count: 118111602]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  r_7 = reassdatagrams;
  # DEBUG r => r_7
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = r_4->timer;
  if (_1 != 0)
    goto <bb 4>; [67.00%]
  else
    goto <bb 5>; [33.00%]

  <bb 4> [local count: 640272249]:
  # DEBUG BEGIN_STMT
  _3 = _1 + 255;
  r_4->timer = _3;
  # DEBUG BEGIN_STMT
  r_12 = r_4->next;
  # DEBUG r => r_12
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 315357973]:
  # DEBUG BEGIN_STMT
  # DEBUG tmp => r_4
  # DEBUG BEGIN_STMT
  r_9 = r_4->next;
  # DEBUG r => r_9
  # DEBUG BEGIN_STMT
  ip6_reass_free_complete_datagram (r_4);

  <bb 7> [local count: 955630222]:
  # r_2 = PHI <r_12(4), r_9(5)>

  <bb 9> [local count: 1073741824]:
  # r_4 = PHI <r_2(7), r_7(2)>
  # DEBUG r => r_4
  # DEBUG BEGIN_STMT
  if (r_4 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 8>; [11.00%]

  <bb 8> [local count: 118111601]:
  return;

}



;; Function ip6_reass (ip6_reass, funcdef_no=4, decl_uid=6887, cgraph_uid=5, symbol_order=6)

Modification phase of node ip6_reass/6
ip6_reass (struct pbuf * p)
{
  u8_t * ptr;
  struct ip6_hdr * iphdr_ptr;
  struct pbuf * next_pbuf;
  struct pbuf * q;
  u8_t valid;
  u16_t clen;
  ptrdiff_t hdrdiff;
  u16_t end;
  u16_t start;
  u16_t len;
  u16_t offset;
  struct ip6_frag_hdr * frag_hdr;
  struct ip6_reass_helper * iprh_prev;
  struct ip6_reass_helper * iprh_tmp;
  struct ip6_reass_helper * iprh;
  struct ip6_reassdata * ipr_prev;
  struct ip6_reassdata * ipr;
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  struct ip6_hdr * _5;
  short unsigned int _6;
  void * _7;
  struct ip6_hdr * _8;
  int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  int _13;
  int _14;
  int _15;
  short unsigned int _16;
  short unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  struct ip6_hdr * _21;
  long unsigned int _22;
  long unsigned int _23;
  short unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _31;
  unsigned char _32;
  unsigned char _33;
  long unsigned int _34;
  long unsigned int _36;
  long unsigned int _37;
  long unsigned int _39;
  long unsigned int _40;
  long unsigned int _42;
  long unsigned int _43;
  long unsigned int _45;
  unsigned char _46;
  unsigned char _47;
  short unsigned int _48;
  short unsigned int _49;
  int _50;
  struct ip6_reassdata * _51;
  short unsigned int _52;
  short unsigned int _53;
  struct ip6_reassdata * reassdatagrams.3_54;
  struct ip6_hdr * _55;
  unsigned char _56;
  unsigned char _57;
  long unsigned int _58;
  unsigned char _59;
  short unsigned int ip6_reass_pbufcount.4_60;
  int _61;
  int _62;
  int _63;
  short unsigned int ip6_reass_pbufcount.5_65;
  int _66;
  int _68;
  struct ip6_reassdata * _69;
  short unsigned int _70;
  short unsigned int _71;
  short unsigned int _72;
  short unsigned int _73;
  short unsigned int _74;
  short unsigned int _75;
  short unsigned int _76;
  short unsigned int _77;
  short unsigned int _78;
  short unsigned int _79;
  short unsigned int _80;
  short unsigned int _81;
  short unsigned int _82;
  struct pbuf * _83;
  short unsigned int ip6_reass_pbufcount.6_84;
  short unsigned int _85;
  struct ip6_hdr * _86;
  u8_t[8] * _87;
  struct pbuf * _88;
  short unsigned int _89;
  short unsigned int _90;
  short unsigned int _91;
  short unsigned int _92;
  struct pbuf * _93;
  struct ip6_hdr * _94;
  void * _95;
  void * _96;
  int _97;
  unsigned int _98;
  struct ip6_hdr * _99;
  short unsigned int _100;
  void * _101;
  int _102;
  short unsigned int _103;
  short unsigned int _104;
  short unsigned int _105;
  short unsigned int _106;
  unsigned char _107;
  unsigned char _108;
  unsigned char _109;
  int _110;
  int _111;
  int _112;
  sizetype _113;
  unsigned char _114;
  unsigned char _115;
  struct ip6_reassdata * reassdatagrams.7_116;
  struct ip6_reassdata * _117;
  struct ip6_reassdata * _118;
  short unsigned int ip6_reass_pbufcount.8_119;
  short unsigned int _120;
  void * _121;
  int _122;
  short int _123;
  unsigned char _124;
  short unsigned int _125;
  short unsigned int _126;
  struct pbuf * _149;
  short unsigned int _171;
  struct ip6_reassdata * _172;

  <bb 2> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG iprh_prev => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG valid => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = lwip_stats.ip6_frag.recv;
  _2 = _1 + 1;
  lwip_stats.ip6_frag.recv = _2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = p_175(D)->len;
  if (_3 <= 7)
    goto <bb 103>; [67.00%]
  else
    goto <bb 4>; [33.00%]

  <bb 103> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 112> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  frag_hdr_176 = p_175(D)->payload;
  # DEBUG frag_hdr => frag_hdr_176
  # DEBUG BEGIN_STMT
  clen_178 = pbuf_clen (p_175(D));
  # DEBUG clen => clen_178
  # DEBUG BEGIN_STMT
  _4 = frag_hdr_176->_fragment_offset;
  offset_180 = lwip_htons (_4);
  # DEBUG offset => offset_180
  # DEBUG BEGIN_STMT
  _5 = ip_data.current_ip6_header;
  _6 = MEM[(const struct ip6_hdr *)_5]._plen;
  len_182 = lwip_htons (_6);
  # DEBUG len => len_182
  # DEBUG BEGIN_STMT
  _7 = p_175(D)->payload;
  _8 = ip_data.current_ip6_header;
  hdrdiff_183 = _7 - _8;
  # DEBUG hdrdiff => hdrdiff_183
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (hdrdiff_183 > 65535)
    goto <bb 104>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 104> [local count: 26443]:

  <bb 5> [local count: 264428957]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 113> [local count: 264428957]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 26443]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (hdrdiff_183 <= 39)
    goto <bb 105>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 105> [local count: 13222]:

  <bb 7> [local count: 132214478]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 114> [local count: 132214478]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 13221]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG hdrdiff => hdrdiff_183 + -40
  # DEBUG BEGIN_STMT
  hdrdiff_184 = hdrdiff_183 + -32;
  # DEBUG hdrdiff => hdrdiff_184
  # DEBUG BEGIN_STMT
  _9 = (int) len_182;
  if (_9 < hdrdiff_184)
    goto <bb 9>; [17.38%]
  else
    goto <bb 10>; [82.62%]

  <bb 9> [local count: 2298]:
  # DEBUG BEGIN_STMT
  _10 = lwip_stats.ip6_frag.proterr;
  _11 = _10 + 1;
  lwip_stats.ip6_frag.proterr = _11;
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 101>; [100.00%]

  <bb 10> [local count: 10924]:
  # DEBUG BEGIN_STMT
  _12 = (short unsigned int) hdrdiff_184;
  len_185 = len_182 - _12;
  # DEBUG len => len_185
  # DEBUG BEGIN_STMT
  start_186 = offset_180 & 65528;
  # DEBUG start => start_186
  # DEBUG BEGIN_STMT
  _13 = (int) start_186;
  _14 = (int) len_185;
  _15 = 65535 - _14;
  if (_13 > _15)
    goto <bb 11>; [17.38%]
  else
    goto <bb 12>; [82.62%]

  <bb 11> [local count: 1899]:
  # DEBUG BEGIN_STMT
  _16 = lwip_stats.ip6_frag.proterr;
  _17 = _16 + 1;
  lwip_stats.ip6_frag.proterr = _17;
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 101>; [100.00%]

  <bb 12> [local count: 9025]:
  # DEBUG BEGIN_STMT
  ipr_187 = reassdatagrams;
  # DEBUG ipr => ipr_187
  # DEBUG ipr_prev => 0B
  goto <bb 26>; [100.00%]

  <bb 13> [local count: 155063]:
  # DEBUG BEGIN_STMT
  _18 = frag_hdr_176->_identification;
  _19 = ipr_127->identification;
  if (_18 == _19)
    goto <bb 14>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 14> [local count: 52722]:
  _20 = ip_data.current_iphdr_src.u_addr.ip6.addr[0];
  _21 = ipr_127->iphdr;
  _22 = _21->src.addr[0];
  if (_20 == _22)
    goto <bb 15>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 15> [local count: 17925]:
  _23 = ip_data.current_iphdr_src.u_addr.ip6.addr[1];
  _25 = _21->src.addr[1];
  if (_23 == _25)
    goto <bb 16>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 16> [local count: 6095]:
  _26 = ip_data.current_iphdr_src.u_addr.ip6.addr[2];
  _28 = _21->src.addr[2];
  if (_26 == _28)
    goto <bb 17>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 17> [local count: 2072]:
  _29 = ip_data.current_iphdr_src.u_addr.ip6.addr[3];
  _31 = _21->src.addr[3];
  if (_29 == _31)
    goto <bb 18>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 18> [local count: 705]:
  _32 = ip_data.current_iphdr_src.u_addr.ip6.zone;
  _33 = ipr_127->src_zone;
  if (_32 == _33)
    goto <bb 19>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 19> [local count: 240]:
  _34 = ip_data.current_iphdr_dest.u_addr.ip6.addr[0];
  _36 = _21->dest.addr[0];
  if (_34 == _36)
    goto <bb 20>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 20> [local count: 81]:
  _37 = ip_data.current_iphdr_dest.u_addr.ip6.addr[1];
  _39 = _21->dest.addr[1];
  if (_37 == _39)
    goto <bb 21>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 21> [local count: 28]:
  _40 = ip_data.current_iphdr_dest.u_addr.ip6.addr[2];
  _42 = _21->dest.addr[2];
  if (_40 == _42)
    goto <bb 22>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 22> [local count: 9]:
  _43 = ip_data.current_iphdr_dest.u_addr.ip6.addr[3];
  _45 = _21->dest.addr[3];
  if (_43 == _45)
    goto <bb 23>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 23> [local count: 3]:
  _46 = ip_data.current_iphdr_dest.u_addr.ip6.zone;
  _47 = ipr_127->dest_zone;
  if (_46 == _47)
    goto <bb 24>; [5.50%]
  else
    goto <bb 25>; [94.50%]

  <bb 24> [local count: 0]:
  # ipr_27 = PHI <ipr_127(23)>
  # ipr_prev_35 = PHI <ipr_prev_130(23)>
  # DEBUG BEGIN_STMT
  _48 = lwip_stats.ip6_frag.cachehit;
  _49 = _48 + 1;
  lwip_stats.ip6_frag.cachehit = _49;
  # DEBUG BEGIN_STMT
  goto <bb 27>; [100.00%]

  <bb 25> [local count: 155063]:
  # DEBUG BEGIN_STMT
  # DEBUG ipr_prev => ipr_127
  # DEBUG BEGIN_STMT
  ipr_190 = ipr_127->next;
  # DEBUG ipr => ipr_190

  <bb 26> [local count: 164088]:
  # ipr_127 = PHI <ipr_187(12), ipr_190(25)>
  # ipr_prev_130 = PHI <0B(12), ipr_127(25)>
  # DEBUG ipr_prev => ipr_prev_130
  # DEBUG ipr => ipr_127
  # DEBUG BEGIN_STMT
  if (ipr_127 != 0B)
    goto <bb 13>; [94.50%]
  else
    goto <bb 27>; [5.50%]

  <bb 27> [local count: 9025]:
  # ipr_30 = PHI <ipr_27(24), ipr_127(26)>
  # ipr_prev_38 = PHI <ipr_prev_35(24), ipr_prev_130(26)>
  # DEBUG BEGIN_STMT
  if (ipr_30 == 0B)
    goto <bb 28>; [17.43%]
  else
    goto <bb 35>; [82.57%]

  <bb 28> [local count: 1573]:
  # DEBUG BEGIN_STMT
  ipr_192 = memp_malloc (11);
  # DEBUG ipr => ipr_192
  # DEBUG BEGIN_STMT
  if (ipr_192 == 0B)
    goto <bb 29>; [30.00%]
  else
    goto <bb 34>; [70.00%]

  <bb 29> [local count: 472]:
  # DEBUG BEGIN_STMT
  _50 = (int) clen_178;
  ip6_reass_remove_oldest_datagram (0B, _50);
  # DEBUG BEGIN_STMT
  ipr_195 = memp_malloc (11);
  # DEBUG ipr => ipr_195
  # DEBUG BEGIN_STMT
  if (ipr_195 != 0B)
    goto <bb 30>; [91.73%]
  else
    goto <bb 33>; [8.27%]

  <bb 30> [local count: 433]:
  # DEBUG BEGIN_STMT
  ipr_prev_197 = reassdatagrams;
  # DEBUG ipr_prev => ipr_prev_197
  goto <bb 32>; [100.00%]

  <bb 31> [local count: 3824]:
  # DEBUG BEGIN_STMT
  _51 = ipr_prev_131->next;
  if (_51 == ipr_195)
    goto <bb 34>; [5.50%]
  else
    goto <bb 121>; [94.50%]

  <bb 121> [local count: 3614]:

  <bb 32> [local count: 4047]:
  # ipr_prev_131 = PHI <ipr_prev_197(30), _51(121)>
  # DEBUG ipr_prev => ipr_prev_131
  # DEBUG BEGIN_STMT
  if (ipr_prev_131 != 0B)
    goto <bb 31>; [94.50%]
  else
    goto <bb 34>; [5.50%]

  <bb 33> [local count: 39]:
  # DEBUG BEGIN_STMT
  _52 = lwip_stats.ip6_frag.memerr;
  _53 = _52 + 1;
  lwip_stats.ip6_frag.memerr = _53;
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 101>; [100.00%]

  <bb 34> [local count: 1534]:
  # ipr_128 = PHI <ipr_192(28), ipr_195(32), ipr_195(31)>
  # ipr_prev_132 = PHI <ipr_prev_38(28), ipr_prev_131(32), ipr_prev_131(31)>
  # DEBUG ipr_prev => ipr_prev_132
  # DEBUG ipr => ipr_128
  # DEBUG BEGIN_STMT
  _172 = ipr_128 + 4;
  memset (_172, 0, 28);
  # DEBUG BEGIN_STMT
  ipr_128->timer = 60;
  # DEBUG BEGIN_STMT
  reassdatagrams.3_54 = reassdatagrams;
  ipr_128->next = reassdatagrams.3_54;
  # DEBUG BEGIN_STMT
  reassdatagrams = ipr_128;
  # DEBUG BEGIN_STMT
  _55 = ip_data.current_ip6_header;
  ipr_128->iphdr = _55;
  # DEBUG BEGIN_STMT
  _56 = ip_data.current_iphdr_src.u_addr.ip6.zone;
  ipr_128->src_zone = _56;
  # DEBUG BEGIN_STMT
  _57 = ip_data.current_iphdr_dest.u_addr.ip6.zone;
  ipr_128->dest_zone = _57;
  # DEBUG BEGIN_STMT
  _58 = frag_hdr_176->_identification;
  ipr_128->identification = _58;
  # DEBUG BEGIN_STMT
  _59 = frag_hdr_176->_nexth;
  ipr_128->nexth = _59;

  <bb 35> [local count: 8986]:
  # ipr_129 = PHI <ipr_30(27), ipr_128(34)>
  # ipr_prev_133 = PHI <ipr_prev_38(27), ipr_prev_132(34)>
  # DEBUG ipr_prev => ipr_prev_133
  # DEBUG ipr => ipr_129
  # DEBUG BEGIN_STMT
  ip6_reass_pbufcount.4_60 = ip6_reass_pbufcount;
  _61 = (int) ip6_reass_pbufcount.4_60;
  _62 = (int) clen_178;
  _63 = _61 + _62;
  if (_63 > 10)
    goto <bb 36>; [33.00%]
  else
    goto <bb 41>; [67.00%]

  <bb 36> [local count: 2965]:
  # DEBUG BEGIN_STMT
  ip6_reass_remove_oldest_datagram (ipr_129, _62);
  # DEBUG BEGIN_STMT
  ip6_reass_pbufcount.5_65 = ip6_reass_pbufcount;
  _66 = (int) ip6_reass_pbufcount.5_65;
  _68 = _62 + _66;
  if (_68 <= 10)
    goto <bb 37>; [82.62%]
  else
    goto <bb 40>; [17.38%]

  <bb 37> [local count: 2450]:
  # DEBUG BEGIN_STMT
  ipr_prev_210 = reassdatagrams;
  # DEBUG ipr_prev => ipr_prev_210
  goto <bb 39>; [100.00%]

  <bb 38> [local count: 21643]:
  # DEBUG BEGIN_STMT
  _69 = ipr_prev_134->next;
  if (_69 == ipr_129)
    goto <bb 41>; [5.50%]
  else
    goto <bb 120>; [94.50%]

  <bb 120> [local count: 20453]:

  <bb 39> [local count: 22903]:
  # ipr_prev_134 = PHI <ipr_prev_210(37), _69(120)>
  # DEBUG ipr_prev => ipr_prev_134
  # DEBUG BEGIN_STMT
  if (ipr_prev_134 != 0B)
    goto <bb 38>; [94.50%]
  else
    goto <bb 41>; [5.50%]

  <bb 40> [local count: 515]:
  # DEBUG BEGIN_STMT
  _70 = lwip_stats.ip6_frag.memerr;
  _71 = _70 + 1;
  lwip_stats.ip6_frag.memerr = _71;
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 101>; [100.00%]

  <bb 41> [local count: 8471]:
  # ipr_prev_135 = PHI <ipr_prev_134(39), ipr_prev_133(35), ipr_prev_134(38)>
  # DEBUG ipr_prev => ipr_prev_135
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iprh_212 = p_175(D)->payload;
  # DEBUG iprh => iprh_212
  # DEBUG BEGIN_STMT
  # DEBUG next_pbuf => 0B
  # DEBUG BEGIN_STMT
  end_213 = len_185 + start_186;
  # DEBUG end => end_213
  # DEBUG BEGIN_STMT
  q_214 = ipr_129->p;
  # DEBUG q => q_214
  goto <bb 59>; [100.00%]

  <bb 42> [local count: 78049]:
  # DEBUG BEGIN_STMT
  iprh_tmp_215 = q_145->payload;
  # DEBUG iprh_tmp => iprh_tmp_215
  # DEBUG BEGIN_STMT
  _72 = iprh_tmp_215->start;
  if (_72 > start_186)
    goto <bb 43>; [2.75%]
  else
    goto <bb 51>; [97.25%]

  <bb 43> [local count: 2146]:
  # _24 = PHI <_72(42)>
  # iprh_prev_41 = PHI <iprh_prev_137(42)>
  # valid_189 = PHI <valid_140(42)>
  # q_64 = PHI <q_145(42)>
  # DEBUG BEGIN_STMT
  if (_24 < end_213)
    goto <bb 44>; [17.38%]
  else
    goto <bb 45>; [82.62%]

  <bb 44> [local count: 373]:
  # DEBUG BEGIN_STMT
  _73 = lwip_stats.ip6_frag.proterr;
  _74 = _73 + 1;
  lwip_stats.ip6_frag.proterr = _74;
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 101>; [100.00%]

  <bb 45> [local count: 1773]:
  # DEBUG BEGIN_STMT
  if (iprh_prev_41 != 0B)
    goto <bb 46>; [70.00%]
  else
    goto <bb 48>; [30.00%]

  <bb 46> [local count: 1241]:
  # DEBUG BEGIN_STMT
  _75 = iprh_prev_41->end;
  if (_75 > start_186)
    goto <bb 47>; [17.38%]
  else
    goto <bb 48>; [82.62%]

  <bb 47> [local count: 216]:
  # DEBUG BEGIN_STMT
  _76 = lwip_stats.ip6_frag.proterr;
  _77 = _76 + 1;
  lwip_stats.ip6_frag.proterr = _77;
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 101>; [100.00%]

  <bb 48> [local count: 1558]:
  # DEBUG BEGIN_STMT
  # DEBUG next_pbuf => q_64
  # DEBUG BEGIN_STMT
  if (iprh_prev_41 != 0B)
    goto <bb 49>; [70.00%]
  else
    goto <bb 50>; [30.00%]

  <bb 49> [local count: 1090]:
  # DEBUG BEGIN_STMT
  iprh_prev_41->next_pbuf = p_175(D);
  goto <bb 60>; [100.00%]

  <bb 50> [local count: 467]:
  # DEBUG BEGIN_STMT
  ipr_129->p = p_175(D);
  goto <bb 60>; [100.00%]

  <bb 51> [local count: 75903]:
  # DEBUG BEGIN_STMT
  if (_72 == start_186)
    goto <bb 52>; [2.75%]
  else
    goto <bb 53>; [97.25%]

  <bb 52> [local count: 2087]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 101>; [100.00%]

  <bb 53> [local count: 73815]:
  # DEBUG BEGIN_STMT
  _78 = iprh_tmp_215->end;
  if (_78 > start_186)
    goto <bb 54>; [2.75%]
  else
    goto <bb 55>; [97.25%]

  <bb 54> [local count: 2030]:
  # DEBUG BEGIN_STMT
  _79 = lwip_stats.ip6_frag.proterr;
  _80 = _79 + 1;
  lwip_stats.ip6_frag.proterr = _80;
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 101>; [100.00%]

  <bb 55> [local count: 71785]:
  # DEBUG BEGIN_STMT
  if (iprh_prev_137 != 0B)
    goto <bb 56>; [70.00%]
  else
    goto <bb 58>; [30.00%]

  <bb 56> [local count: 50250]:
  # DEBUG BEGIN_STMT
  _81 = iprh_prev_137->end;
  if (_72 != _81)
    goto <bb 57>; [66.00%]
  else
    goto <bb 58>; [34.00%]

  <bb 57> [local count: 33165]:
  # DEBUG BEGIN_STMT
  # DEBUG valid => 0

  <bb 58> [local count: 71785]:
  # valid_139 = PHI <valid_140(55), valid_140(56), 0(57)>
  # DEBUG valid => valid_139
  # DEBUG BEGIN_STMT
  q_216 = iprh_tmp_215->next_pbuf;
  # DEBUG q => q_216
  # DEBUG BEGIN_STMT
  # DEBUG iprh_prev => iprh_tmp_215

  <bb 59> [local count: 80256]:
  # iprh_prev_137 = PHI <0B(41), iprh_tmp_215(58)>
  # valid_140 = PHI <1(41), valid_139(58)>
  # q_145 = PHI <q_214(41), q_216(58)>
  # DEBUG q => q_145
  # DEBUG valid => valid_140
  # DEBUG iprh_prev => iprh_prev_137
  # DEBUG BEGIN_STMT
  if (q_145 != 0B)
    goto <bb 42>; [97.25%]
  else
    goto <bb 60>; [2.75%]

  <bb 60> [local count: 3765]:
  # next_pbuf_147 = PHI <q_64(50), 0B(59), q_64(49)>
  # iprh_prev_44 = PHI <0B(50), iprh_prev_137(59), iprh_prev_41(49)>
  # valid_198 = PHI <valid_189(50), valid_140(59), valid_189(49)>
  # q_67 = PHI <q_64(50), q_145(59), q_64(49)>
  # DEBUG next_pbuf => next_pbuf_147
  # DEBUG BEGIN_STMT
  if (q_67 == 0B)
    goto <bb 61>; [67.00%]
  else
    goto <bb 69>; [33.00%]

  <bb 61> [local count: 2522]:
  # DEBUG BEGIN_STMT
  if (iprh_prev_44 != 0B)
    goto <bb 62>; [70.00%]
  else
    goto <bb 66>; [30.00%]

  <bb 62> [local count: 1766]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _82 = iprh_prev_44->end;
  if (_82 > start_186)
    goto <bb 106>; [67.00%]
  else
    goto <bb 64>; [33.00%]

  <bb 106> [local count: 1183]:

  <bb 63> [local count: 11829542]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 115> [local count: 11829542]:
  goto <bb 63>; [100.00%]

  <bb 64> [local count: 583]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iprh_prev_44->next_pbuf = p_175(D);
  # DEBUG BEGIN_STMT
  if (_82 != start_186)
    goto <bb 65>; [66.00%]
  else
    goto <bb 69>; [34.00%]

  <bb 65> [local count: 385]:
  # DEBUG BEGIN_STMT
  # DEBUG valid => 0
  goto <bb 69>; [100.00%]

  <bb 66> [local count: 757]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _83 = ipr_129->p;
  if (_83 != 0B)
    goto <bb 111>; [67.00%]
  else
    goto <bb 68>; [33.00%]

  <bb 111> [local count: 507]:

  <bb 67> [local count: 5069804]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 119> [local count: 5069804]:
  goto <bb 67>; [100.00%]

  <bb 68> [local count: 250]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ipr_129->p = p_175(D);

  <bb 69> [local count: 2075]:
  # valid_141 = PHI <valid_198(60), 0(65), valid_198(68), valid_198(64)>
  # DEBUG valid => valid_141
  # DEBUG BEGIN_STMT
  ip6_reass_pbufcount.6_84 = ip6_reass_pbufcount;
  _85 = ip6_reass_pbufcount.6_84 + clen_178;
  ip6_reass_pbufcount = _85;
  # DEBUG BEGIN_STMT
  if (start_186 == 0)
    goto <bb 70>; [33.00%]
  else
    goto <bb 71>; [67.00%]

  <bb 70> [local count: 685]:
  # DEBUG BEGIN_STMT
  _86 = ip_data.current_ip6_header;
  ipr_129->iphdr = _86;
  # DEBUG BEGIN_STMT
  _87 = &ipr_129->orig_hdr;
  memcpy (_87, iprh_212, 8);

  <bb 71> [local count: 2075]:
  # DEBUG BEGIN_STMT
  iprh_212->next_pbuf = next_pbuf_147;
  # DEBUG BEGIN_STMT
  iprh_212->start = start_186;
  # DEBUG BEGIN_STMT
  iprh_212->end = end_213;
  # DEBUG BEGIN_STMT
  _171 = offset_180 & 1;
  if (_171 == 0)
    goto <bb 72>; [50.00%]
  else
    goto <bb 73>; [50.00%]

  <bb 72> [local count: 1037]:
  # DEBUG BEGIN_STMT
  ipr_129->datagram_len = end_213;

  <bb 73> [local count: 2075]:
  # DEBUG BEGIN_STMT
  _88 = ipr_129->p;
  iprh_tmp_233 = _88->payload;
  # DEBUG iprh_tmp => iprh_tmp_233
  # DEBUG BEGIN_STMT
  _89 = iprh_tmp_233->start;
  if (_89 != 0)
    goto <bb 74>; [50.00%]
  else
    goto <bb 75>; [50.00%]

  <bb 74> [local count: 1037]:
  # DEBUG BEGIN_STMT
  # DEBUG valid => 0

  <bb 75> [local count: 2075]:
  # valid_142 = PHI <valid_141(73), 0(74)>
  # DEBUG valid => valid_142
  # DEBUG BEGIN_STMT
  _90 = ipr_129->datagram_len;
  if (_90 == 0)
    goto <bb 76>; [50.00%]
  else
    goto <bb 77>; [50.00%]

  <bb 76> [local count: 1037]:
  # DEBUG BEGIN_STMT
  # DEBUG valid => 0

  <bb 77> [local count: 2075]:
  # valid_143 = PHI <valid_142(75), 0(76)>
  # DEBUG valid => valid_143
  # DEBUG BEGIN_STMT
  # DEBUG iprh_prev => iprh_212
  # DEBUG BEGIN_STMT
  # DEBUG q => next_pbuf_147
  # DEBUG BEGIN_STMT
  goto <bb 80>; [100.00%]

  <bb 78> [local count: 18195]:
  # DEBUG BEGIN_STMT
  iprh_234 = q_146->payload;
  # DEBUG iprh => iprh_234
  # DEBUG BEGIN_STMT
  _91 = iprh_prev_138->end;
  _92 = iprh_234->start;
  if (_91 != _92)
    goto <bb 82>; [3.66%]
  else
    goto <bb 79>; [96.34%]

  <bb 79> [local count: 17529]:
  # DEBUG BEGIN_STMT
  # DEBUG iprh_prev => iprh_234
  # DEBUG BEGIN_STMT
  q_235 = iprh_234->next_pbuf;
  # DEBUG q => q_235

  <bb 80> [local count: 19604]:
  # iprh_prev_138 = PHI <iprh_212(77), iprh_234(79)>
  # q_146 = PHI <next_pbuf_147(77), q_235(79)>
  # DEBUG q => q_146
  # DEBUG iprh_prev => iprh_prev_138
  # DEBUG BEGIN_STMT
  if (q_146 != 0B)
    goto <bb 81>; [96.34%]
  else
    goto <bb 82>; [3.66%]

  <bb 81> [local count: 18886]:
  if (valid_143 != 0)
    goto <bb 78>; [96.34%]
  else
    goto <bb 82>; [3.66%]

  <bb 82> [local count: 2075]:
  # valid_144 = PHI <0(78), valid_143(80), valid_143(81)>
  # DEBUG valid => valid_144
  # DEBUG BEGIN_STMT
  if (valid_144 != 0)
    goto <bb 110>; [71.00%]
  else
    goto <bb 102>; [29.00%]

  <bb 110> [local count: 1473]:
  goto <bb 85>; [100.00%]

  <bb 83> [local count: 13012]:
  # DEBUG BEGIN_STMT
  next_pbuf_256 = iprh_136->next_pbuf;
  # DEBUG next_pbuf => next_pbuf_256
  # DEBUG BEGIN_STMT
  if (next_pbuf_256 != 0B)
    goto <bb 84>; [94.50%]
  else
    goto <bb 86>; [5.50%]

  <bb 84> [local count: 12297]:
  # DEBUG BEGIN_STMT
  iprh_tmp_257 = next_pbuf_256->payload;
  # DEBUG iprh_tmp => iprh_tmp_257
  # DEBUG BEGIN_STMT
  pbuf_remove_header (next_pbuf_256, 8);
  # DEBUG BEGIN_STMT
  _93 = ipr_129->p;
  pbuf_cat (_93, next_pbuf_256);
  # DEBUG iprh_tmp => iprh_tmp_257
  # DEBUG BEGIN_STMT
  # DEBUG iprh => iprh_tmp_257

  <bb 85> [local count: 13770]:
  # iprh_136 = PHI <iprh_tmp_257(84), iprh_tmp_233(110)>
  # DEBUG iprh => iprh_136
  # DEBUG BEGIN_STMT
  if (iprh_136 != 0B)
    goto <bb 83>; [94.50%]
  else
    goto <bb 86>; [5.50%]

  <bb 86> [local count: 1473]:
  # DEBUG iprh_tmp => NULL
  # DEBUG iprh => NULL
  # DEBUG BEGIN_STMT
  p_236 = ipr_129->p;
  # DEBUG p => p_236
  # DEBUG BEGIN_STMT
  _94 = ipr_129->iphdr;
  _95 = _94 + 8;
  _96 = p_236->payload;
  _97 = _96 - _94;
  _98 = (unsigned int) _97;
  memmove (_95, _94, _98);
  # DEBUG BEGIN_STMT
  _99 = ipr_129->iphdr;
  iphdr_ptr_238 = _99 + 8;
  # DEBUG iphdr_ptr => iphdr_ptr_238
  # DEBUG BEGIN_STMT
  _100 = ipr_129->datagram_len;
  _101 = p_236->payload;
  _102 = _101 - iphdr_ptr_238;
  _103 = (short unsigned int) _102;
  _104 = _100 + _103;
  _105 = _104 + 65496;
  ipr_129->datagram_len = _105;
  # DEBUG BEGIN_STMT
  _106 = lwip_htons (_105);
  MEM[(struct ip6_hdr *)_99 + 8B]._plen = _106;
  # DEBUG BEGIN_STMT
  _107 = MEM[(struct ip6_hdr *)_99 + 8B]._nexth;
  if (_107 == 44)
    goto <bb 87>; [34.00%]
  else
    goto <bb 88>; [66.00%]

  <bb 87> [local count: 501]:
  # DEBUG BEGIN_STMT
  _108 = ipr_129->nexth;
  MEM[(struct ip6_hdr *)_99 + 8B]._nexth = _108;
  goto <bb 92>; [100.00%]

  <bb 88> [local count: 972]:
  # DEBUG BEGIN_STMT
  ptr_242 = &MEM[(void *)_99 + 48B];
  # DEBUG ptr => ptr_242
  # DEBUG BEGIN_STMT
  goto <bb 90>; [100.00%]

  <bb 89> [local count: 7866]:
  # DEBUG BEGIN_STMT
  _109 = MEM[(u8_t *)ptr_148 + 1B];
  _110 = (int) _109;
  _111 = _110 + 1;
  _112 = _111 * 8;
  _113 = (sizetype) _112;
  ptr_244 = ptr_148 + _113;
  # DEBUG ptr => ptr_244

  <bb 90> [local count: 8838]:
  # ptr_148 = PHI <ptr_242(88), ptr_244(89)>
  # DEBUG ptr => ptr_148
  # DEBUG BEGIN_STMT
  _114 = *ptr_148;
  if (_114 != 44)
    goto <bb 89>; [89.00%]
  else
    goto <bb 91>; [11.00%]

  <bb 91> [local count: 972]:
  # ptr_211 = PHI <ptr_148(90)>
  # DEBUG BEGIN_STMT
  _115 = ipr_129->nexth;
  *ptr_211 = _115;

  <bb 92> [local count: 1473]:
  # DEBUG BEGIN_STMT
  reassdatagrams.7_116 = reassdatagrams;
  if (reassdatagrams.7_116 == ipr_129)
    goto <bb 93>; [30.00%]
  else
    goto <bb 94>; [70.00%]

  <bb 93> [local count: 442]:
  # DEBUG BEGIN_STMT
  _117 = ipr_129->next;
  reassdatagrams = _117;
  goto <bb 97>; [100.00%]

  <bb 94> [local count: 1031]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipr_prev_135 == 0B)
    goto <bb 109>; [30.00%]
  else
    goto <bb 96>; [70.00%]

  <bb 109> [local count: 309]:

  <bb 95> [local count: 3093345]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 118> [local count: 3093345]:
  goto <bb 95>; [100.00%]

  <bb 96> [local count: 722]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _118 = ipr_129->next;
  ipr_prev_135->next = _118;

  <bb 97> [local count: 1164]:
  # DEBUG BEGIN_STMT
  memp_free (11, ipr_129);
  # DEBUG BEGIN_STMT
  clen_251 = pbuf_clen (p_236);
  # DEBUG clen => clen_251
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ip6_reass_pbufcount.8_119 = ip6_reass_pbufcount;
  if (ip6_reass_pbufcount.8_119 < clen_251)
    goto <bb 107>; [67.00%]
  else
    goto <bb 99>; [33.00%]

  <bb 107> [local count: 780]:

  <bb 98> [local count: 7796702]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 116> [local count: 7796702]:
  goto <bb 98>; [100.00%]

  <bb 99> [local count: 384]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _120 = ip6_reass_pbufcount.8_119 - clen_251;
  ip6_reass_pbufcount = _120;
  # DEBUG BEGIN_STMT
  _121 = p_236->payload;
  _122 = _121 - iphdr_ptr_238;
  _123 = (short int) _122;
  _124 = pbuf_header_force (p_236, _123);
  if (_124 != 0)
    goto <bb 108>; [66.00%]
  else
    goto <bb 102>; [34.00%]

  <bb 108> [local count: 253]:

  <bb 100> [local count: 2534510]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 117> [local count: 2534510]:
  goto <bb 100>; [100.00%]

  <bb 101> [local count: 9457]:
nullreturn:
  # DEBUG BEGIN_STMT
  _125 = lwip_stats.ip6_frag.drop;
  _126 = _125 + 1;
  lwip_stats.ip6_frag.drop = _126;
  # DEBUG BEGIN_STMT
  pbuf_free (p_175(D));
  # DEBUG BEGIN_STMT

  <bb 102> [local count: 10189]:
  # _149 = PHI <0B(101), p_236(99), 0B(82)>
  return _149;

}



;; Function ip6_frag (ip6_frag, funcdef_no=8, decl_uid=6894, cgraph_uid=9, symbol_order=10)

Modification phase of node ip6_frag/10
ip6_frag (struct pbuf * p, struct netif * netif, const struct ip6_addr_t * dest)
{
  struct pbuf_custom_ref * pcr;
  u16_t poff;
  u16_t fragment_offset;
  const u16_t nfb;
  const u16_t mtu;
  u16_t left;
  static u32_t identification;
  u16_t left_to_copy;
  u16_t newpbuflen;
  struct pbuf * newpbuf;
  struct pbuf * rambuf;
  struct ip6_hdr * ip6hdr;
  struct ip6_hdr * original_ip6hdr;
  unsigned short _1;
  long unsigned int identification.12_2;
  long unsigned int _3;
  short unsigned int _4;
  short unsigned int iftmp.13_6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  void * _10;
  void * _12;
  sizetype _13;
  void * _14;
  short unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;
  struct pbuf_custom * _22;
  void * _23;
  short unsigned int _24;
  short unsigned int _25;
  unsigned char _26;
  signed short fragment_offset.14_27;
  signed short _28;
  _Bool _29;
  signed short _30;
  signed short _31;
  short unsigned int _32;
  short unsigned int _33;
  long unsigned int identification.15_34;
  long unsigned int _35;
  short unsigned int _36;
  short unsigned int _37;
  short unsigned int _38;
  short unsigned int _39;
  err_t (*<T6bc>) (struct netif *, struct pbuf *, const struct ip6_addr_t *) _40;
  err_t _49;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG newpbuflen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mtu_60 = nd6_get_destination_mtu (dest_57(D), netif_58(D));
  # DEBUG mtu => mtu_60
  # DEBUG BEGIN_STMT
  _1 = mtu_60 + 65488;
  nfb_61 = _1 & 65528;
  # DEBUG nfb => nfb_61
  # DEBUG BEGIN_STMT
  # DEBUG fragment_offset => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG poff => 40
  # DEBUG BEGIN_STMT
  identification.12_2 = identification;
  _3 = identification.12_2 + 1;
  identification = _3;
  # DEBUG BEGIN_STMT
  original_ip6hdr_66 = p_65(D)->payload;
  # DEBUG original_ip6hdr => original_ip6hdr_66
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = p_65(D)->tot_len;
  if (_4 <= 39)
    goto <bb 23>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 23> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 25> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  left_67 = _4 + 65496;
  # DEBUG left => left_67
  # DEBUG BEGIN_STMT
  goto <bb 21>; [100.00%]

  <bb 5> [local count: 202240]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => left_46 <= nfb_61
  # DEBUG last => (u16_t) D#1
  # DEBUG BEGIN_STMT
  iftmp.13_6 = MIN_EXPR <nfb_61, left_46>;
  # DEBUG cop => iftmp.13_6
  # DEBUG BEGIN_STMT
  rambuf_72 = pbuf_alloc (14, 48, 640);
  # DEBUG rambuf => rambuf_72
  # DEBUG BEGIN_STMT
  if (rambuf_72 == 0B)
    goto <bb 6>; [2.20%]
  else
    goto <bb 7>; [97.80%]

  <bb 6> [local count: 4449]:
  # DEBUG BEGIN_STMT
  _7 = lwip_stats.ip6_frag.memerr;
  _8 = _7 + 1;
  lwip_stats.ip6_frag.memerr = _8;
  # DEBUG BEGIN_STMT
  goto <bb 22>; [100.00%]

  <bb 7> [local count: 197791]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = rambuf_72->len;
  if (_9 <= 39)
    goto <bb 24>; [2.20%]
  else
    goto <bb 9>; [97.80%]

  <bb 24> [local count: 4351]:

  <bb 8> [local count: 43514013]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 26> [local count: 43514013]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 193439]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = rambuf_72->payload;
  memcpy (_10, original_ip6hdr_66, 40);
  # DEBUG BEGIN_STMT
  ip6hdr_74 = rambuf_72->payload;
  # DEBUG ip6hdr => ip6hdr_74
  # DEBUG BEGIN_STMT
  # DEBUG frag_hdr => ip6hdr_74 + 40
  # DEBUG BEGIN_STMT
  _12 = p_42->payload;
  _13 = (sizetype) poff_48;
  _14 = _12 + _13;
  p_42->payload = _14;
  # DEBUG BEGIN_STMT
  _15 = p_42->len;
  _16 = _15 - poff_48;
  p_42->len = _16;
  # DEBUG BEGIN_STMT
  _17 = p_42->tot_len;
  _18 = _17 - poff_48;
  p_42->tot_len = _18;
  # DEBUG BEGIN_STMT
  # DEBUG left_to_copy => iftmp.13_6
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 10> [local count: 2616849]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = p_41->len;
  newpbuflen_93 = MIN_EXPR <_19, left_to_copy_45>;
  # DEBUG newpbuflen => newpbuflen_93
  # DEBUG BEGIN_STMT
  if (newpbuflen_93 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 1308425]:
  # DEBUG BEGIN_STMT
  p_109 = p_41->next;
  # DEBUG p => p_109
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 18>; [100.00%]

  <bb 12> [local count: 1308425]:
  # DEBUG BEGIN_STMT
  pcr_95 = ip6_frag_alloc_pbuf_custom_ref ();
  # DEBUG pcr => pcr_95
  # DEBUG BEGIN_STMT
  if (pcr_95 == 0B)
    goto <bb 13>; [3.66%]
  else
    goto <bb 14>; [96.34%]

  <bb 13> [local count: 47888]:
  # rambuf_62 = PHI <rambuf_72(12)>
  # DEBUG BEGIN_STMT
  pbuf_free (rambuf_62);
  # DEBUG BEGIN_STMT
  _20 = lwip_stats.ip6_frag.memerr;
  _21 = _20 + 1;
  lwip_stats.ip6_frag.memerr = _21;
  # DEBUG BEGIN_STMT
  goto <bb 22>; [100.00%]

  <bb 14> [local count: 1260536]:
  # DEBUG BEGIN_STMT
  _22 = &pcr_95->pc;
  _23 = p_41->payload;
  newpbuf_97 = pbuf_alloced_custom (0, newpbuflen_93, 65, _22, _23, newpbuflen_93);
  # DEBUG newpbuf => newpbuf_97
  # DEBUG BEGIN_STMT
  if (newpbuf_97 == 0B)
    goto <bb 15>; [3.66%]
  else
    goto <bb 16>; [96.34%]

  <bb 15> [local count: 46136]:
  # rambuf_63 = PHI <rambuf_72(14)>
  # pcr_68 = PHI <pcr_95(14)>
  # DEBUG BEGIN_STMT
  ip6_frag_free_pbuf_custom_ref (pcr_68);
  # DEBUG BEGIN_STMT
  pbuf_free (rambuf_63);
  # DEBUG BEGIN_STMT
  _24 = lwip_stats.ip6_frag.memerr;
  _25 = _24 + 1;
  lwip_stats.ip6_frag.memerr = _25;
  # DEBUG BEGIN_STMT
  goto <bb 22>; [100.00%]

  <bb 16> [local count: 1214401]:
  # DEBUG BEGIN_STMT
  pbuf_ref (p_41);
  # DEBUG BEGIN_STMT
  pcr_95->original = p_41;
  # DEBUG BEGIN_STMT
  pcr_95->pc.custom_free_function = ip6_frag_free_pbuf_custom;
  # DEBUG BEGIN_STMT
  pbuf_cat (rambuf_72, newpbuf_97);
  # DEBUG BEGIN_STMT
  left_to_copy_102 = left_to_copy_45 - newpbuflen_93;
  # DEBUG left_to_copy => left_to_copy_102
  # DEBUG BEGIN_STMT
  if (left_to_copy_102 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 17> [local count: 607200]:
  # DEBUG BEGIN_STMT
  p_103 = p_41->next;
  # DEBUG p => p_103

  <bb 18> [local count: 2522825]:
  # p_11 = PHI <p_109(11), p_41(16), p_103(17)>
  # newpbuflen_70 = PHI <0(11), newpbuflen_93(16), newpbuflen_93(17)>
  # left_to_copy_69 = PHI <left_to_copy_45(11), left_to_copy_102(16), left_to_copy_102(17)>

  <bb 19> [local count: 2716264]:
  # p_41 = PHI <p_11(18), p_42(9)>
  # newpbuflen_43 = PHI <newpbuflen_70(18), newpbuflen_44(9)>
  # left_to_copy_45 = PHI <left_to_copy_69(18), iftmp.13_6(9)>
  # DEBUG left_to_copy => left_to_copy_45
  # DEBUG newpbuflen => newpbuflen_43
  # DEBUG p => p_41
  # DEBUG BEGIN_STMT
  if (left_to_copy_45 != 0)
    goto <bb 10>; [96.34%]
  else
    goto <bb 20>; [3.66%]

  <bb 20> [local count: 99415]:
  # p_78 = PHI <p_41(19)>
  # newpbuflen_55 = PHI <newpbuflen_43(19)>
  # DEBUG BEGIN_STMT
  # DEBUG poff => newpbuflen_55
  # DEBUG BEGIN_STMT
  _26 = original_ip6hdr_66->_nexth;
  MEM[(struct ip6_frag_hdr *)ip6hdr_74 + 40B]._nexth = _26;
  # DEBUG BEGIN_STMT
  MEM[(struct ip6_frag_hdr *)ip6hdr_74 + 40B].reserved = 0;
  # DEBUG BEGIN_STMT
  fragment_offset.14_27 = (signed short) fragment_offset_47;
  _28 = fragment_offset.14_27 & -8;
  _29 = left_46 > nfb_61;
  _30 = (signed short) _29;
  _31 = _28 | _30;
  _32 = (short unsigned int) _31;
  _33 = lwip_htons (_32);
  MEM[(struct ip6_frag_hdr *)ip6hdr_74 + 40B]._fragment_offset = _33;
  # DEBUG BEGIN_STMT
  identification.15_34 = identification;
  _35 = lwip_htonl (identification.15_34);
  MEM[(struct ip6_frag_hdr *)ip6hdr_74 + 40B]._identification = _35;
  # DEBUG BEGIN_STMT
  ip6hdr_74->_nexth = 44;
  # DEBUG BEGIN_STMT
  _36 = iftmp.13_6 + 8;
  _37 = lwip_htons (_36);
  ip6hdr_74->_plen = _37;
  # DEBUG BEGIN_STMT
  _38 = lwip_stats.ip6_frag.xmit;
  _39 = _38 + 1;
  lwip_stats.ip6_frag.xmit = _39;
  # DEBUG BEGIN_STMT
  _40 = netif_58(D)->output_ip6;
  _40 (netif_58(D), rambuf_72, dest_57(D));
  # DEBUG BEGIN_STMT
  pbuf_free (rambuf_72);
  # DEBUG BEGIN_STMT
  left_91 = left_46 - iftmp.13_6;
  # DEBUG left => left_91
  # DEBUG BEGIN_STMT
  fragment_offset_92 = iftmp.13_6 + fragment_offset_47;
  # DEBUG fragment_offset => fragment_offset_92

  <bb 21> [local count: 206789]:
  # p_42 = PHI <p_65(D)(4), p_78(20)>
  # newpbuflen_44 = PHI <0(4), newpbuflen_55(20)>
  # left_46 = PHI <left_67(4), left_91(20)>
  # fragment_offset_47 = PHI <0(4), fragment_offset_92(20)>
  # poff_48 = PHI <40(4), newpbuflen_55(20)>
  # DEBUG poff => poff_48
  # DEBUG fragment_offset => fragment_offset_47
  # DEBUG left => left_46
  # DEBUG newpbuflen => newpbuflen_44
  # DEBUG p => p_42
  # DEBUG BEGIN_STMT
  if (left_46 != 0)
    goto <bb 5>; [97.80%]
  else
    goto <bb 22>; [2.20%]

  <bb 22> [local count: 103023]:
  # _49 = PHI <-1(6), -1(13), -1(15), 0(21)>
  return _49;

}


