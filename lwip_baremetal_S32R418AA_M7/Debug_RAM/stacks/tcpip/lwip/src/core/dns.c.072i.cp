
IPA constant propagation start:
Determining dynamic type for call: _3 (_7, addr_9(D), _8);
  Starting walk at: _3 (_7, addr_9(D), _8);
  instance pointer: _7  Outer instance pointer: &dns_table[_6].name offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 (_7, addr_9(D), _8);
Determining dynamic type for call: _3 (_7, addr_9(D), _8);
  Starting walk at: _3 (_7, addr_9(D), _8);
  instance pointer: addr_9(D)  Outer instance pointer: addr_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 (_7, addr_9(D), _8);
Determining dynamic type for call: _3 (_7, addr_9(D), _8);
  Starting walk at: _3 (_7, addr_9(D), _8);
  instance pointer: _8  Outer instance pointer: _8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 (_7, addr_9(D), _8);
Determining dynamic type for call: _5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  Starting walk at: _5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  instance pointer: hostname_21(D)  Outer instance pointer: hostname_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = ipaddr_aton (hostname_21(D), addr_20(D));
Determining dynamic type for call: _5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  Starting walk at: _5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  instance pointer: addr_20(D)  Outer instance pointer: addr_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = ipaddr_aton (hostname_21(D), addr_20(D));
Determining dynamic type for call: _7 = dns_lookup (hostname_21(D), addr_20(D), fallback_14);
  Starting walk at: _7 = dns_lookup (hostname_21(D), addr_20(D), fallback_14);
  instance pointer: hostname_21(D)  Outer instance pointer: hostname_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  Function call may change dynamic type:_2 = ipaddr_aton (hostname_21(D), addr_20(D));
Determining dynamic type for call: _7 = dns_lookup (hostname_21(D), addr_20(D), fallback_14);
  Starting walk at: _7 = dns_lookup (hostname_21(D), addr_20(D), fallback_14);
  instance pointer: addr_20(D)  Outer instance pointer: addr_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  Function call may change dynamic type:_2 = ipaddr_aton (hostname_21(D), addr_20(D));
Determining dynamic type for call: _33 = dns_enqueue (hostname_21(D), hostnamelen_23, found_30(D), callback_arg_31(D), dns_addrtype_25(D));
  Starting walk at: _33 = dns_enqueue (hostname_21(D), hostnamelen_23, found_30(D), callback_arg_31(D), dns_addrtype_25(D));
  instance pointer: hostname_21(D)  Outer instance pointer: hostname_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  Function call may change dynamic type:_2 = ipaddr_aton (hostname_21(D), addr_20(D));
  Function call may change dynamic type:_7 = dns_lookup (hostname_21(D), addr_20(D), fallback_14);
Determining dynamic type for call: _33 = dns_enqueue (hostname_21(D), hostnamelen_23, found_30(D), callback_arg_31(D), dns_addrtype_25(D));
  Starting walk at: _33 = dns_enqueue (hostname_21(D), hostnamelen_23, found_30(D), callback_arg_31(D), dns_addrtype_25(D));
  instance pointer: found_30(D)  Outer instance pointer: found_30(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  Function call may change dynamic type:_2 = ipaddr_aton (hostname_21(D), addr_20(D));
  Function call may change dynamic type:_7 = dns_lookup (hostname_21(D), addr_20(D), fallback_14);
Determining dynamic type for call: _33 = dns_enqueue (hostname_21(D), hostnamelen_23, found_30(D), callback_arg_31(D), dns_addrtype_25(D));
  Starting walk at: _33 = dns_enqueue (hostname_21(D), hostnamelen_23, found_30(D), callback_arg_31(D), dns_addrtype_25(D));
  instance pointer: callback_arg_31(D)  Outer instance pointer: callback_arg_31(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  Function call may change dynamic type:_2 = ipaddr_aton (hostname_21(D), addr_20(D));
  Function call may change dynamic type:_7 = dns_lookup (hostname_21(D), addr_20(D), fallback_14);
Determining dynamic type for call: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 2);
  Starting walk at: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 2);
  instance pointer: hostname_2(D)  Outer instance pointer: hostname_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 2);
  Starting walk at: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 2);
  instance pointer: addr_3(D)  Outer instance pointer: addr_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 2);
  Starting walk at: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 2);
  instance pointer: found_4(D)  Outer instance pointer: found_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 2);
  Starting walk at: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 2);
  instance pointer: callback_arg_5(D)  Outer instance pointer: callback_arg_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_idx_93 = dns_compare_name (_31, p_78(D), 12);
  Starting walk at: res_idx_93 = dns_compare_name (_31, p_78(D), 12);
  instance pointer: _31  Outer instance pointer: &MEM[(struct dns_table_entry *)&dns_table][_89].name offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:nanswers_87 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_85 = lwip_htons (_7);
  Function call may change dynamic type:txid_81 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_78(D), &hdr, 12, 0);
Determining dynamic type for call: res_idx_93 = dns_compare_name (_31, p_78(D), 12);
  Starting walk at: res_idx_93 = dns_compare_name (_31, p_78(D), 12);
  instance pointer: p_78(D)  Outer instance pointer: p_78(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:nanswers_87 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_85 = lwip_htons (_7);
  Function call may change dynamic type:txid_81 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_78(D), &hdr, 12, 0);
Determining dynamic type for call: res_idx_97 = dns_skip_name (p_78(D), res_idx_68);
  Starting walk at: res_idx_97 = dns_skip_name (p_78(D), res_idx_68);
  instance pointer: p_78(D)  Outer instance pointer: p_78(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_63 = lwip_htons (_62);
  Function call may change dynamic type:_59 = lwip_htons (_58);
  Function call may change dynamic type:_39 = pbuf_copy_partial (p_78(D), &ans, 10, res_idx_97);
  Function call may change dynamic type:res_idx_97 = dns_skip_name (p_78(D), res_idx_68);
  Function call may change dynamic type:_32 = pbuf_copy_partial (p_78(D), &qry, 4, res_idx_93);
  Function call may change dynamic type:res_idx_93 = dns_compare_name (_31, p_78(D), 12);
  Function call may change dynamic type:nanswers_87 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_85 = lwip_htons (_7);
  Function call may change dynamic type:txid_81 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_78(D), &hdr, 12, 0);
Determining dynamic type for call: _38 = dns_backupserver_available (entry_28);
  Starting walk at: _38 = dns_backupserver_available (entry_28);
  instance pointer: entry_28  Outer instance pointer: &dns_table[_4] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_32 = pbuf_copy_partial (p_78(D), &qry, 4, res_idx_93);
  Function call may change dynamic type:res_idx_93 = dns_compare_name (_31, p_78(D), 12);
  Function call may change dynamic type:nanswers_87 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_85 = lwip_htons (_7);
  Function call may change dynamic type:txid_81 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_78(D), &hdr, 12, 0);
Determining dynamic type for call: dns_call_found.part.0 (i_15, 0B);
  Starting walk at: dns_call_found.part.0 (i_15, 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_78(D));
  Function call may change dynamic type:_32 = pbuf_copy_partial (p_78(D), &qry, 4, res_idx_93);
  Function call may change dynamic type:res_idx_93 = dns_compare_name (_31, p_78(D), 12);
  Function call may change dynamic type:nanswers_87 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_85 = lwip_htons (_7);
  Function call may change dynamic type:txid_81 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_78(D), &hdr, 12, 0);
  Function call may change dynamic type:_63 = lwip_htons (_62);
  Function call may change dynamic type:_59 = lwip_htons (_58);
  Function call may change dynamic type:_39 = pbuf_copy_partial (p_78(D), &ans, 10, res_idx_97);
  Function call may change dynamic type:res_idx_97 = dns_skip_name (p_78(D), res_idx_68);
Determining dynamic type for call: dns_call_found (idx_7(D), _2);
  Starting walk at: dns_call_found (idx_7(D), _2);
  instance pointer: _2  Outer instance pointer: &MEM[(struct dns_table_entry *)&dns_table][_1].ipaddr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = dns_backupserver_available (entry_19);
  Starting walk at: _8 = dns_backupserver_available (entry_19);
  instance pointer: entry_19  Outer instance pointer: &dns_table[_1] offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: dns_call_found.part.0 (i_18(D), 0B);
  Starting walk at: dns_call_found.part.0 (i_18(D), 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: dns_call_found.part.0 (idx_13(D), addr_11(D));
  Starting walk at: dns_call_found.part.0 (idx_13(D), addr_11(D));
  instance pointer: addr_11(D)  Outer instance pointer: addr_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: dns_call_found.part.0 (idx_45(D), 0B);
  Starting walk at: dns_call_found.part.0 (idx_45(D), 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  dns_call_found.part.0/53:
    indirect simple callsite, calling param -1, offset 0, for stmt _3 (_7, addr_9(D), _8);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  dns_backupserver_available.part.0/52:
  Jump functions of caller  pbuf_try_get_at/50:
  Jump functions of caller  lwip_htonl/49:
  Jump functions of caller  pbuf_copy_partial/48:
  Jump functions of caller  udp_recv/47:
  Jump functions of caller  udp_bind/45:
  Jump functions of caller  udp_new_ip_type/44:
  Jump functions of caller  memcpy/43:
  Jump functions of caller  lwip_strnicmp/42:
  Jump functions of caller  ipaddr_aton/41:
  Jump functions of caller  udp_sendto/40:
  Jump functions of caller  pbuf_take_at/39:
  Jump functions of caller  pbuf_put_at/38:
  Jump functions of caller  pbuf_free/37:
  Jump functions of caller  pbuf_take/36:
  Jump functions of caller  lwip_htons/35:
  Jump functions of caller  memset/34:
  Jump functions of caller  pbuf_alloc/33:
  Jump functions of caller  strlen/32:
  Jump functions of caller  udp_remove/31:
  Jump functions of caller  rand/30:
  Jump functions of caller  dns_gethostbyname_addrtype/28:
    callsite  dns_gethostbyname_addrtype/28 -> dns_enqueue/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7fffffff
         VR  [0, 2147483645]
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  dns_gethostbyname_addrtype/28 -> dns_lookup/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
    callsite  dns_gethostbyname_addrtype/28 -> dns_lookup/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  dns_gethostbyname/27:
    callsite  dns_gethostbyname/27 -> dns_gethostbyname_addrtype/28 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
  Jump functions of caller  dns_enqueue/26:
    callsite  dns_enqueue/26 -> dns_check_entry/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  dns_enqueue/26 -> dns_alloc_pcb/18 : 
  Jump functions of caller  dns_recv/25:
    callsite  dns_recv/25 -> dns_call_found.part.0/53 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
    callsite  dns_recv/25 -> dns_check_entry/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
    callsite  dns_recv/25 -> dns_correct_response/24 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  dns_recv/25 -> dns_correct_response/24 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  dns_recv/25 -> dns_skip_name/15 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  dns_recv/25 -> dns_check_entry/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
    callsite  dns_recv/25 -> dns_backupserver_available/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  dns_recv/25 -> dns_compare_name/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 12
         value: 0xc, mask: 0x0
         Unknown VR
  Jump functions of caller  dns_correct_response/24:
    callsite  dns_correct_response/24 -> dns_call_found/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  dns_check_entries/23:
    callsite  dns_check_entries/23 -> dns_check_entry/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 4]
  Jump functions of caller  dns_check_entry/22:
    callsite  dns_check_entry/22 -> dns_send/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  dns_check_entry/22 -> dns_call_found.part.0/53 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
    callsite  dns_check_entry/22 -> dns_backupserver_available/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  dns_check_entry/22 -> dns_send/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  dns_check_entry/22 -> dns_create_txid/20 : 
  Jump functions of caller  dns_backupserver_available/21:
    callsite  dns_backupserver_available/21 -> dns_backupserver_available.part.0/52 : 
  Jump functions of caller  dns_create_txid/20:
  Jump functions of caller  dns_call_found/19:
    callsite  dns_call_found/19 -> dns_call_found.part.0/53 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  dns_alloc_pcb/18:
    callsite  dns_alloc_pcb/18 -> dns_alloc_random_port/17 : 
  Jump functions of caller  dns_alloc_random_port/17:
  Jump functions of caller  dns_send/16:
    callsite  dns_send/16 -> dns_call_found.part.0/53 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  dns_skip_name/15:
  Jump functions of caller  dns_compare_name/14:
  Jump functions of caller  dns_lookup/13:
  Jump functions of caller  dns_tmr/12:
    callsite  dns_tmr/12 -> dns_check_entries/23 : 
  Jump functions of caller  dns_getserver/11:
  Jump functions of caller  dns_setserver/10:
  Jump functions of caller  dns_init/9:

 Propagating constants:

Not considering dns_gethostbyname_addrtype for cloning; -fipa-cp-clone disabled.
Not considering dns_gethostbyname for cloning; -fipa-cp-clone disabled.
Not considering dns_recv for cloning; -fipa-cp-clone disabled.
Not considering dns_tmr for cloning; -fipa-cp-clone disabled.
Not considering dns_getserver for cloning; -fipa-cp-clone disabled.
Not considering dns_setserver for cloning; -fipa-cp-clone disabled.
Not considering dns_init for cloning; -fipa-cp-clone disabled.

overall_size: 973, max_new_size: 11001
 - context independent values, size: 252, time_benefit: 3.000000
 - context independent values, size: 57, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: dns_call_found.part.0/53:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0B [loc_time: 1, loc_size: 42, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_backupserver_available.part.0/52:
  Node: dns_gethostbyname_addrtype/28:
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
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: dns_gethostbyname/27:
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
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: dns_enqueue/26:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7fffffff
         size_t [0, 2147483645]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_recv/25:
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
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: dns_correct_response/24:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x3
         u8_t [0, 3]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_check_entries/23:
  Node: dns_check_entry/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_backupserver_available/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct dns_table_entry * ~[0B, 0B]
        AGGS VARIABLE
  Node: dns_create_txid/20:
  Node: dns_call_found/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x3
         u8_t [0, 3]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct ip_addr_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: dns_alloc_pcb/18:
  Node: dns_alloc_random_port/17:
  Node: dns_send/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_skip_name/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_compare_name/14:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const char * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 12 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0xc, mask = 0x0
         u16_t [12, 12]
        AGGS VARIABLE
  Node: dns_lookup/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_tmr/12:
  Node: dns_getserver/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: dns_setserver/10:
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
  Node: dns_init/9:

IPA decision stage:

 - Creating a specialized node of dns_compare_name/14 for all known contexts.
    replacing param #2 start_offset with const 12
Propagated bits info for function dns_compare_name.constprop/57:
 param 2: value = 0xc, mask = 0x0
Propagated bits info for function dns_enqueue/26:
 param 1: value = 0x0, mask = 0x7fffffff
Propagated bits info for function dns_correct_response/24:
 param 0: value = 0x0, mask = 0x3
Propagated bits info for function dns_backupserver_available/21:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function dns_call_found/19:
 param 0: value = 0x0, mask = 0x3
Propagated bits info for function dns_compare_name/14:
 param 2: value = 0xc, mask = 0x0

IPA constant propagation end

Reclaiming functions: dns_compare_name/14
Reclaiming variables:
Clearing address taken flags:
Symbol table:

dns_compare_name.constprop.0/57 (dns_compare_name.constprop) @06299540
  Type: function definition analyzed
  Visibility:
  References: _ctype_/51 (addr)_ctype_/51 (addr)
  Referring: 
  Clone of dns_compare_name/14
  Availability: local
  Function flags: count:92050635 (estimated locally) local optimize_size
  Called by: dns_recv/25 (518831 (estimated locally),0.00 per call) 
  Calls: pbuf_try_get_at/50 (120409230 (estimated locally),1.31 per call) pbuf_try_get_at/50 (1044213925 (estimated locally),11.34 per call) pbuf_try_get_at/50 (29527900 (estimated locally),0.32 per call) 
dns_call_found.part.0/53 (dns_call_found.part.0) @06299c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: dns_requests/5 (read)dns_requests/5 (read)dns_table/4 (addr)dns_requests/5 (read)dns_requests/5 (write)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (write)dns_table/4 (read)dns_pcbs/1 (read)dns_table/4 (read)dns_pcbs/1 (write)dns_table/4 (write)
  Referring: 
  Availability: local
  Function flags: count:214748364 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: dns_recv/25 (13586 (estimated locally),0.00 per call) dns_check_entry/22 (1205 (estimated locally),0.01 per call) dns_send/16 (25369 (estimated locally),0.14 per call) dns_call_found/19 (261720 (estimated locally),0.64 per call) 
  Calls: udp_remove/31 (70866960 (estimated locally),0.33 per call) 
   Indirect call(204440443 (estimated locally),0.95 per call) 
dns_backupserver_available.part.0/52 (dns_backupserver_available.part.0) @060048c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: dns_backupserver_available/21 (375809639 (estimated locally),0.35 per call) 
  Calls: 
_ctype_/51 (_ctype_) @062f7a20
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: dns_compare_name.constprop.0/57 (addr)dns_compare_name.constprop.0/57 (addr)
  Availability: not_available
  Varpool flags: read-only
pbuf_try_get_at/50 (pbuf_try_get_at) @062caee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_compare_name.constprop/57 (120409230 (estimated locally),1.31 per call) dns_compare_name.constprop/57 (1044213925 (estimated locally),11.34 per call) dns_compare_name.constprop/57 (29527900 (estimated locally),0.32 per call) dns_skip_name/15 (990385272 (estimated locally),8.08 per call) dns_skip_name/15 (1073741824 (estimated locally),8.76 per call) 
  Calls: 
lwip_htonl/49 (lwip_htonl) @062cab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_recv/25 (57 (estimated locally),0.00 per call) dns_recv/25 (19 (estimated locally),0.00 per call) 
  Calls: 
pbuf_copy_partial/48 (pbuf_copy_partial) @062ca9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_recv/25 (282 (estimated locally),0.00 per call) dns_recv/25 (94 (estimated locally),0.00 per call) dns_recv/25 (125731 (estimated locally),0.00 per call) dns_recv/25 (337188 (estimated locally),0.00 per call) dns_recv/25 (524845004 (estimated locally),0.49 per call) 
  Calls: 
udp_recv/47 (udp_recv) @062ca620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/17 (10734218 (estimated locally),0.76 per call) 
  Calls: 
ip_addr_any_type/46 (ip_addr_any_type) @062c7d38
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: dns_alloc_random_port/17 (addr)
  Availability: not_available
  Varpool flags: read-only
udp_bind/45 (udp_bind) @062ca540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/17 (118111601 (estimated locally),8.34 per call) 
  Calls: 
udp_new_ip_type/44 (udp_new_ip_type) @062ca460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/17 (14163606 (estimated locally),1.00 per call) 
  Calls: 
memcpy/43 (memcpy) @062ca0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_enqueue/26 (114504709 (estimated locally),0.52 per call) 
  Calls: 
lwip_strnicmp/42 (lwip_strnicmp) @062b5c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_enqueue/26 (173860276 (estimated locally),0.79 per call) dns_lookup/13 (173860276 (estimated locally),0.79 per call) 
  Calls: 
ipaddr_aton/41 (ipaddr_aton) @062b57e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_gethostbyname_addrtype/28 (1031024857 (estimated locally),0.96 per call) 
  Calls: 
udp_sendto/40 (udp_sendto) @062b5380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/16 (23511 (estimated locally),0.13 per call) 
  Calls: 
pbuf_take_at/39 (pbuf_take_at) @062b52a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/16 (23511 (estimated locally),0.13 per call) dns_send/16 (427466 (estimated locally),2.35 per call) 
  Calls: 
pbuf_put_at/38 (pbuf_put_at) @062b51c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/16 (23511 (estimated locally),0.13 per call) dns_send/16 (427466 (estimated locally),2.35 per call) 
  Calls: 
pbuf_free/37 (pbuf_free) @062b50e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_recv/25 (1073725993 (estimated locally),1.00 per call) dns_recv/25 (13586 (estimated locally),0.00 per call) dns_recv/25 (2169 (estimated locally),0.00 per call) dns_recv/25 (57 (estimated locally),0.00 per call) dns_recv/25 (19 (estimated locally),0.00 per call) dns_send/16 (23511 (estimated locally),0.13 per call) dns_send/16 (24879 (estimated locally),0.14 per call) 
  Calls: 
pbuf_take/36 (pbuf_take) @062b5000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/16 (48390 (estimated locally),0.27 per call) 
  Calls: 
lwip_htons/35 (lwip_htons) @062997e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_recv/25 (117968 (estimated locally),0.00 per call) dns_recv/25 (120376 (estimated locally),0.00 per call) dns_recv/25 (7392912 (estimated locally),0.01 per call) dns_recv/25 (7392912 (estimated locally),0.01 per call) dns_recv/25 (106228629 (estimated locally),0.10 per call) dns_send/16 (48390 (estimated locally),0.27 per call) 
  Calls: 
memset/34 (memset) @06299ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/16 (48390 (estimated locally),0.27 per call) 
  Calls: 
pbuf_alloc/33 (pbuf_alloc) @06299e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/16 (49246 (estimated locally),0.27 per call) 
  Calls: 
strlen/32 (strlen) @06299d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_gethostbyname_addrtype/28 (1053033253 (estimated locally),0.98 per call) dns_send/16 (49246 (estimated locally),0.27 per call) 
  Calls: 
udp_remove/31 (udp_remove) @062998c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/17 (2258058 (estimated locally),0.16 per call) dns_call_found.part.0/53 (70866960 (estimated locally),0.33 per call) 
  Calls: 
rand/30 (rand) @062992a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/17 (1073741824 (estimated locally),75.81 per call) dns_create_txid/20 (230811542 (estimated locally),1.07 per call) 
  Calls: 
ip_addr_any/29 (ip_addr_any) @06239cf0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: dns_setserver/10 (read)dns_getserver/11 (addr)
  Availability: not_available
  Varpool flags: read-only
dns_gethostbyname_addrtype/28 (dns_gethostbyname_addrtype) @062909a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: dns_gethostbyname/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: dns_enqueue/26 (444030678 (estimated locally),0.41 per call) dns_lookup/13 (216057050 (estimated locally),0.20 per call) dns_lookup/13 (798436991 (estimated locally),0.74 per call) ipaddr_aton/41 (1031024857 (estimated locally),0.96 per call) strlen/32 (1053033253 (estimated locally),0.98 per call) 
dns_gethostbyname/27 (dns_gethostbyname) @06290380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: dns_gethostbyname_addrtype/28 (1073741824 (estimated locally),1.00 per call) 
dns_enqueue/26 (dns_enqueue) @062900e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (read)dns_table/4 (addr)dns_table/4 (read)dns_requests/5 (read)dns_requests/5 (write)dns_requests/5 (write)dns_requests/5 (write)dns_requests/5 (write)dns_table/4 (addr)dns_table/4 (read)dns_seqno/3 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (addr)dns_requests/5 (read)dns_requests/5 (addr)dns_seqno/3 (read)dns_seqno/3 (read)dns_seqno/3 (write)
  Referring: 
  Availability: local
  Function flags: count:219120380 (estimated locally) body local optimize_size
  Called by: dns_gethostbyname_addrtype/28 (444030678 (estimated locally),0.41 per call) 
  Calls: dns_check_entry/22 (55969902 (estimated locally),0.26 per call) dns_alloc_pcb/18 (114504709 (estimated locally),0.52 per call) memcpy/43 (114504709 (estimated locally),0.52 per call) lwip_strnicmp/42 (173860276 (estimated locally),0.79 per call) 
dns_recv/25 (dns_recv) @0626db60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: dns_table/4 (addr)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_table/4 (addr)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)
  Referring: dns_alloc_random_port/17 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/37 (1073725993 (estimated locally),1.00 per call) dns_call_found.part.0/53 (13586 (estimated locally),0.00 per call) pbuf_free/37 (13586 (estimated locally),0.00 per call) dns_check_entry/22 (2169 (estimated locally),0.00 per call) pbuf_free/37 (2169 (estimated locally),0.00 per call) lwip_htons/35 (117968 (estimated locally),0.00 per call) lwip_htons/35 (120376 (estimated locally),0.00 per call) dns_correct_response/24 (57 (estimated locally),0.00 per call) lwip_htonl/49 (57 (estimated locally),0.00 per call) pbuf_free/37 (57 (estimated locally),0.00 per call) pbuf_copy_partial/48 (282 (estimated locally),0.00 per call) dns_correct_response/24 (19 (estimated locally),0.00 per call) lwip_htonl/49 (19 (estimated locally),0.00 per call) pbuf_free/37 (19 (estimated locally),0.00 per call) pbuf_copy_partial/48 (94 (estimated locally),0.00 per call) pbuf_copy_partial/48 (125731 (estimated locally),0.00 per call) dns_skip_name/15 (128297 (estimated locally),0.00 per call) dns_check_entry/22 (5154 (estimated locally),0.00 per call) dns_backupserver_available/21 (15619 (estimated locally),0.00 per call) pbuf_copy_partial/48 (337188 (estimated locally),0.00 per call) dns_compare_name.constprop/57 (518831 (estimated locally),0.00 per call) lwip_htons/35 (7392912 (estimated locally),0.01 per call) lwip_htons/35 (7392912 (estimated locally),0.01 per call) lwip_htons/35 (106228629 (estimated locally),0.10 per call) pbuf_copy_partial/48 (524845004 (estimated locally),0.49 per call) 
dns_correct_response/24 (dns_correct_response) @06232d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (addr)dns_table/4 (read)dns_table/4 (read)dns_table/4 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: dns_recv/25 (57 (estimated locally),0.00 per call) dns_recv/25 (19 (estimated locally),0.00 per call) 
  Calls: dns_call_found/19 (1073741824 (estimated locally),1.00 per call) 
dns_check_entries/23 (dns_check_entries) @062328c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748364 (estimated locally) body local optimize_size
  Called by: dns_tmr/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: dns_check_entry/22 (858993459 (estimated locally),4.00 per call) 
dns_check_entry/22 (dns_check_entry) @06232620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (addr)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: dns_recv/25 (2169 (estimated locally),0.00 per call) dns_recv/25 (5154 (estimated locally),0.00 per call) dns_enqueue/26 (55969902 (estimated locally),0.26 per call) dns_check_entries/23 (858993459 (estimated locally),4.00 per call) 
  Calls: dns_send/16 (9533 (estimated locally),0.04 per call) dns_call_found.part.0/53 (1205 (estimated locally),0.01 per call) dns_backupserver_available/21 (3651 (estimated locally),0.02 per call) dns_send/16 (21475 (estimated locally),0.10 per call) dns_create_txid/20 (21475 (estimated locally),0.10 per call) 
dns_backupserver_available/21 (dns_backupserver_available) @062322a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: dns_recv/25 (15619 (estimated locally),0.00 per call) dns_check_entry/22 (3651 (estimated locally),0.02 per call) 
  Calls: dns_backupserver_available.part.0/52 (375809639 (estimated locally),0.35 per call) 
dns_create_txid/20 (dns_create_txid) @06220d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (read)dns_table/4 (read)
  Referring: 
  Availability: local
  Function flags: count:214748364 (estimated locally) body local optimize_size
  Called by: dns_check_entry/22 (21475 (estimated locally),0.10 per call) 
  Calls: rand/30 (230811542 (estimated locally),1.07 per call) 
dns_call_found/19 (dns_call_found) @06220a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (read)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)
  Referring: 
  Availability: local
  Function flags: count:411785 (estimated locally) body local optimize_size
  Called by: dns_correct_response/24 (1073741824 (estimated locally),1.00 per call) 
  Calls: dns_call_found.part.0/53 (261720 (estimated locally),0.64 per call) 
dns_alloc_pcb/18 (dns_alloc_pcb) @062207e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_pcbs/1 (read)dns_pcbs/1 (write)dns_last_pcb_idx/2 (write)dns_last_pcb_idx/2 (read)dns_pcbs/1 (read)dns_last_pcb_idx/2 (write)
  Referring: 
  Availability: local
  Function flags: count:261993004 (estimated locally) body local optimize_size
  Called by: dns_enqueue/26 (114504709 (estimated locally),0.52 per call) 
  Calls: dns_alloc_random_port/17 (128062181 (estimated locally),0.49 per call) 
dns_alloc_random_port/17 (dns_alloc_random_port) @06220540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ip_addr_any_type/46 (addr)dns_recv/25 (addr)
  Referring: 
  Availability: local
  Function flags: count:14163606 (estimated locally) body local optimize_size
  Called by: dns_alloc_pcb/18 (128062181 (estimated locally),0.49 per call) 
  Calls: udp_recv/47 (10734218 (estimated locally),0.76 per call) udp_remove/31 (2258058 (estimated locally),0.16 per call) udp_bind/45 (118111601 (estimated locally),8.34 per call) rand/30 (1073741824 (estimated locally),75.81 per call) udp_new_ip_type/44 (14163606 (estimated locally),1.00 per call) 
dns_send/16 (dns_send) @062202a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_servers/6 (read)dns_table/4 (write)dns_table/4 (addr)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_servers/6 (addr)dns_pcbs/1 (read)
  Referring: 
  Availability: local
  Function flags: count:181990 (estimated locally) body local optimize_size
  Called by: dns_check_entry/22 (9533 (estimated locally),0.04 per call) dns_check_entry/22 (21475 (estimated locally),0.10 per call) 
  Calls: pbuf_free/37 (23511 (estimated locally),0.13 per call) udp_sendto/40 (23511 (estimated locally),0.13 per call) pbuf_take_at/39 (23511 (estimated locally),0.13 per call) pbuf_put_at/38 (23511 (estimated locally),0.13 per call) pbuf_take_at/39 (427466 (estimated locally),2.35 per call) pbuf_put_at/38 (427466 (estimated locally),2.35 per call) pbuf_free/37 (24879 (estimated locally),0.14 per call) pbuf_take/36 (48390 (estimated locally),0.27 per call) lwip_htons/35 (48390 (estimated locally),0.27 per call) memset/34 (48390 (estimated locally),0.27 per call) pbuf_alloc/33 (49246 (estimated locally),0.27 per call) strlen/32 (49246 (estimated locally),0.27 per call) dns_call_found.part.0/53 (25369 (estimated locally),0.14 per call) 
dns_skip_name/15 (dns_skip_name) @06213d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:122575812 (estimated locally) body local optimize_size
  Called by: dns_recv/25 (128297 (estimated locally),0.00 per call) 
  Calls: pbuf_try_get_at/50 (990385272 (estimated locally),8.08 per call) pbuf_try_get_at/50 (1073741824 (estimated locally),8.76 per call) 
dns_compare_name/14 (dns_compare_name) @06213a80
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:92050635 (estimated locally) body optimize_size
  Called by: 
  Calls: 
dns_lookup/13 (dns_lookup) @06213460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (read)dns_table/4 (addr)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)
  Referring: 
  Availability: local
  Function flags: count:219529524 (estimated locally) body local optimize_size
  Called by: dns_gethostbyname_addrtype/28 (216057050 (estimated locally),0.20 per call) dns_gethostbyname_addrtype/28 (798436991 (estimated locally),0.74 per call) 
  Calls: lwip_strnicmp/42 (173860276 (estimated locally),0.79 per call) 
dns_tmr/12 (dns_tmr) @061b6a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: dns_check_entries/23 (1073741824 (estimated locally),1.00 per call) 
dns_getserver/11 (dns_getserver) @061b67e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: dns_servers/6 (addr)ip_addr_any/29 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
dns_setserver/10 (dns_setserver) @061b6540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: dns_servers/6 (write)dns_servers/6 (write)ip_addr_any/29 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
dns_init/9 (dns_init) @061b62a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
dns_mquery_v6group/8 (dns_mquery_v6group) @061adee8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
dns_mquery_v4group/7 (dns_mquery_v4group) @05fc9240
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
dns_servers/6 (dns_servers) @061adea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_send/16 (read)dns_send/16 (addr)dns_recv/25 (read)dns_backupserver_available.part.0/52 (read)dns_backupserver_available.part.0/52 (read)dns_backupserver_available.part.0/52 (read)dns_backupserver_available.part.0/52 (read)dns_backupserver_available.part.0/52 (read)dns_backupserver_available.part.0/52 (read)dns_send/16 (read)dns_recv/25 (read)dns_recv/25 (read)dns_recv/25 (read)dns_recv/25 (read)dns_setserver/10 (write)dns_getserver/11 (addr)dns_send/16 (read)dns_send/16 (read)dns_send/16 (read)dns_send/16 (read)dns_recv/25 (read)dns_setserver/10 (write)dns_recv/25 (read)dns_gethostbyname_addrtype/28 (read)dns_gethostbyname_addrtype/28 (read)dns_gethostbyname_addrtype/28 (read)dns_gethostbyname_addrtype/28 (read)dns_gethostbyname_addrtype/28 (read)dns_gethostbyname_addrtype/28 (read)
  Availability: available
  Varpool flags:
dns_requests/5 (dns_requests) @061ade10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_call_found.part.0/53 (write)dns_call_found.part.0/53 (read)dns_call_found.part.0/53 (read)dns_call_found.part.0/53 (read)dns_enqueue/26 (read)dns_enqueue/26 (write)dns_enqueue/26 (write)dns_enqueue/26 (write)dns_enqueue/26 (write)dns_enqueue/26 (read)dns_enqueue/26 (addr)
  Availability: available
  Varpool flags:
dns_table/4 (dns_table) @061add80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_correct_response/24 (write)dns_lookup/13 (read)dns_create_txid/20 (read)dns_check_entry/22 (write)dns_check_entry/22 (read)dns_check_entry/22 (write)dns_check_entry/22 (read)dns_check_entry/22 (write)dns_check_entry/22 (read)dns_check_entry/22 (write)dns_check_entry/22 (write)dns_lookup/13 (read)dns_lookup/13 (read)dns_lookup/13 (read)dns_lookup/13 (read)dns_lookup/13 (read)dns_enqueue/26 (read)dns_enqueue/26 (addr)dns_call_found/19 (write)dns_lookup/13 (read)dns_lookup/13 (addr)dns_lookup/13 (read)dns_lookup/13 (read)dns_enqueue/26 (read)dns_enqueue/26 (addr)dns_enqueue/26 (read)dns_enqueue/26 (addr)dns_enqueue/26 (read)dns_enqueue/26 (read)dns_create_txid/20 (read)dns_send/16 (read)dns_check_entry/22 (write)dns_check_entry/22 (write)dns_check_entry/22 (write)dns_check_entry/22 (read)dns_check_entry/22 (write)dns_check_entry/22 (write)dns_check_entry/22 (write)dns_check_entry/22 (read)dns_check_entry/22 (write)dns_check_entry/22 (write)dns_check_entry/22 (write)dns_call_found.part.0/53 (write)dns_call_found.part.0/53 (read)dns_call_found.part.0/53 (read)dns_call_found.part.0/53 (write)dns_call_found.part.0/53 (addr)dns_call_found.part.0/53 (read)dns_call_found.part.0/53 (read)dns_call_found.part.0/53 (read)dns_call_found/19 (read)dns_call_found/19 (write)dns_call_found/19 (read)dns_correct_response/24 (write)dns_correct_response/24 (write)dns_correct_response/24 (write)dns_correct_response/24 (addr)dns_correct_response/24 (read)dns_correct_response/24 (read)dns_send/16 (read)dns_send/16 (write)dns_send/16 (addr)dns_send/16 (read)dns_send/16 (read)dns_send/16 (read)dns_check_entry/22 (addr)dns_recv/25 (addr)dns_recv/25 (read)dns_recv/25 (read)dns_recv/25 (read)dns_recv/25 (addr)dns_recv/25 (read)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (read)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (read)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (read)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)dns_recv/25 (write)
  Availability: available
  Varpool flags:
dns_seqno/3 (dns_seqno) @061adcf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_enqueue/26 (read)dns_enqueue/26 (read)dns_enqueue/26 (read)dns_enqueue/26 (write)
  Availability: available
  Varpool flags:
dns_last_pcb_idx/2 (dns_last_pcb_idx) @061adc60
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_alloc_pcb/18 (write)dns_alloc_pcb/18 (read)dns_alloc_pcb/18 (write)
  Availability: available
  Varpool flags:
dns_pcbs/1 (dns_pcbs) @061adbd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_call_found.part.0/53 (read)dns_call_found.part.0/53 (write)dns_send/16 (read)dns_alloc_pcb/18 (read)dns_alloc_pcb/18 (write)dns_alloc_pcb/18 (read)
  Availability: available
  Varpool flags:

;; Function dns_lookup (dns_lookup, funcdef_no=5, decl_uid=7227, cgraph_uid=6, symbol_order=13)

Modification phase of node dns_lookup/13
dns_lookup (const char * name, struct ip_addr_t * addr, u8_t dns_addrtype)
{
  u8_t i;
  int _1;
  unsigned char _2;
  int _3;
  char[256] * _4;
  int _5;
  unsigned char _6;
  unsigned char _7;
  unsigned char _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  unsigned char _13;
  long unsigned int _14;
  _Bool iftmp.10_16;
  int iftmp.11_17;
  int iftmp.12_18;
  err_t _19;
  _Bool iftmp.10_28;
  _Bool iftmp.10_29;

  <bb 2> [local count: 219529524]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 21>; [100.00%]

  <bb 3> [local count: 858993460]:
  # DEBUG BEGIN_STMT
  _1 = (int) i_15;
  _2 = dns_table[_1].state;
  if (_2 == 3)
    goto <bb 4>; [20.24%]
  else
    goto <bb 20>; [79.76%]

  <bb 4> [local count: 173860276]:
  _4 = &dns_table[_1].name;
  _5 = lwip_strnicmp (name_25(D), _4, 256);
  if (_5 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 5> [local count: 86930138]:
  _7 = dns_table[_1].ipaddr.type;
  if (_7 == 6)
    goto <bb 6>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 6> [local count: 29556247]:
  if (dns_addrtype_27(D) == 3)
    goto <bb 9>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 7> [local count: 19507123]:
  if (dns_addrtype_27(D) == 1)
    goto <bb 9>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 8> [local count: 12874701]:

  <bb 9> [local count: 29556247]:
  # iftmp.11_17 = PHI <1(7), 0(8), 1(6)>
  iftmp.10_29 = (_Bool) iftmp.11_17;
  goto <bb 14>; [100.00%]

  <bb 10> [local count: 57373891]:
  if (dns_addrtype_27(D) != 3)
    goto <bb 11>; [66.00%]
  else
    goto <bb 12>; [34.00%]

  <bb 11> [local count: 37866768]:
  if (dns_addrtype_27(D) != 1)
    goto <bb 13>; [66.00%]
  else
    goto <bb 12>; [34.00%]

  <bb 12> [local count: 32381824]:

  <bb 13> [local count: 57373891]:
  # iftmp.12_18 = PHI <1(11), 0(12)>
  iftmp.10_28 = (_Bool) iftmp.12_18;

  <bb 14> [local count: 86930138]:
  # iftmp.10_16 = PHI <iftmp.10_29(9), iftmp.10_28(13)>
  if (iftmp.10_16 != 0)
    goto <bb 15>; [5.50%]
  else
    goto <bb 20>; [94.50%]

  <bb 15> [local count: 4781158]:
  # _3 = PHI <_1(14)>
  # _6 = PHI <_7(14)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (addr_30(D) != 0B)
    goto <bb 16>; [70.00%]
  else
    goto <bb 19>; [30.00%]

  <bb 16> [local count: 3346810]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_30(D)->type = _6;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = dns_table[_3].ipaddr.type;
  if (_8 == 6)
    goto <bb 17>; [34.00%]
  else
    goto <bb 18>; [66.00%]

  <bb 17> [local count: 1137916]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = dns_table[_3].ipaddr.u_addr.ip6.addr[0];
  addr_30(D)->u_addr.ip6.addr[0] = _9;
  # DEBUG BEGIN_STMT
  _10 = dns_table[_3].ipaddr.u_addr.ip6.addr[1];
  addr_30(D)->u_addr.ip6.addr[1] = _10;
  # DEBUG BEGIN_STMT
  _11 = dns_table[_3].ipaddr.u_addr.ip6.addr[2];
  addr_30(D)->u_addr.ip6.addr[2] = _11;
  # DEBUG BEGIN_STMT
  _12 = dns_table[_3].ipaddr.u_addr.ip6.addr[3];
  addr_30(D)->u_addr.ip6.addr[3] = _12;
  # DEBUG BEGIN_STMT
  _13 = dns_table[_3].ipaddr.u_addr.ip6.zone;
  addr_30(D)->u_addr.ip6.zone = _13;
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 18> [local count: 2208895]:
  # DEBUG BEGIN_STMT
  _14 = dns_table[_3].ipaddr.u_addr.ip4.addr;
  addr_30(D)->u_addr.ip4.addr = _14;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_30(D)->u_addr.ip6.addr[3] = 0;
  addr_30(D)->u_addr.ip6.addr[2] = 0;
  addr_30(D)->u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  addr_30(D)->u_addr.ip6.zone = 0;

  <bb 19> [local count: 4781158]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 22>; [100.00%]

  <bb 20> [local count: 854212303]:
  # DEBUG BEGIN_STMT
  i_42 = i_15 + 1;
  # DEBUG i => i_42

  <bb 21> [local count: 1073741824]:
  # i_15 = PHI <0(2), i_42(20)>
  # DEBUG i => i_15
  # DEBUG BEGIN_STMT
  if (i_15 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 22>; [20.00%]

  <bb 22> [local count: 219529522]:
  # _19 = PHI <0(19), -16(21)>
  return _19;

}



;; Function dns_backupserver_available (dns_backupserver_available, funcdef_no=13, decl_uid=7324, cgraph_uid=14, symbol_order=21)

Modification phase of node dns_backupserver_available/21
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
dns_backupserver_available (struct dns_table_entry * pentry)
{
  u8_t ret;
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (pentry_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = pentry_4(D)->server_idx;
  if (_1 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 375809639]:
  # DEBUG D#1 => pentry_4(D)
  ret_2 = dns_backupserver_available.part.0 ();

  <bb 5> [local count: 1073741824]:
  # ret_3 = PHI <0(2), 0(3), ret_2(4)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function dns_call_found.part.0 (dns_call_found.part.0, funcdef_no=22, decl_uid=7816, cgraph_uid=43, symbol_order=53)

Modification phase of node dns_call_found.part.0/53
dns_call_found.part.0 (u8_t idx, struct ip_addr_t * addr)
{
  u8_t i;
  int _2;
  void (*<T742>) (const char *, const struct ip_addr_t *, void *) _3;
  unsigned char _4;
  int _6;
  char[256] * _7;
  void * _8;
  int _12;
  unsigned char _13;
  unsigned char _14;
  int _15;
  unsigned char _16;
  int _17;
  int _19;
  unsigned char _20;
  int _21;
  struct udp_pcb * _22;
  unsigned char _23;
  int _24;

  <bb 19> [local count: 214748364]:

  <bb 2> [local count: 214748364]:
  # i_25 = PHI <0(19)>
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  _2 = (int) i_1;
  _3 = dns_requests[_2].found;
  if (_3 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 4> [local count: 601295421]:
  _4 = dns_requests[_2].dns_table_idx;
  if (_4 == idx_5(D))
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 204440443]:
  # DEBUG BEGIN_STMT
  _6 = (int) idx_5(D);
  _7 = &dns_table[_6].name;
  _8 = dns_requests[_2].arg;
  _3 (_7, addr_9(D), _8);
  # DEBUG BEGIN_STMT
  dns_requests[_2].found = 0B;

  <bb 6> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  i_10 = i_1 + 1;
  # DEBUG i => i_10

  <bb 7> [local count: 1073741824]:
  # i_1 = PHI <i_25(2), i_10(6)>
  # DEBUG i => i_1
  # DEBUG BEGIN_STMT
  if (i_1 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 8>; [20.00%]

  <bb 8> [local count: 214748365]:
  goto <bb 15>; [100.00%]

  <bb 9> [local count: 810630832]:
  # DEBUG BEGIN_STMT
  if (idx_5(D) == i_11)
    goto <bb 10>; [20.24%]
  else
    goto <bb 11>; [79.76%]

  <bb 10> [local count: 164071680]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 14>; [100.00%]

  <bb 11> [local count: 646559152]:
  # DEBUG BEGIN_STMT
  _12 = (int) i_11;
  _13 = dns_table[_12].state;
  if (_13 == 2)
    goto <bb 12>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 12> [local count: 219830111]:
  # DEBUG BEGIN_STMT
  _14 = dns_table[_12].pcb_idx;
  _15 = (int) idx_5(D);
  _16 = dns_table[_15].pcb_idx;
  if (_14 == _16)
    goto <bb 13>; [5.50%]
  else
    goto <bb 14>; [94.50%]

  <bb 13> [local count: 12090656]:
  # _17 = PHI <_15(12)>
  # DEBUG BEGIN_STMT
  dns_table[_17].pcb_idx = 4;
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 14> [local count: 798540176]:
  # DEBUG BEGIN_STMT
  i_18 = i_11 + 1;
  # DEBUG i => i_18

  <bb 15> [local count: 1013288540]:
  # i_11 = PHI <0(8), i_18(14)>
  # DEBUG i => i_11
  # DEBUG BEGIN_STMT
  if (i_11 != 4)
    goto <bb 9>; [80.00%]
  else
    goto <bb 16>; [20.00%]

  <bb 16> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  _19 = (int) idx_5(D);
  _20 = dns_table[_19].pcb_idx;
  if (_20 <= 3)
    goto <bb 17>; [33.00%]
  else
    goto <bb 18>; [67.00%]

  <bb 17> [local count: 70866960]:
  # DEBUG BEGIN_STMT
  _21 = (int) _20;
  _22 = dns_pcbs[_21];
  udp_remove (_22);
  # DEBUG BEGIN_STMT
  _23 = dns_table[_19].pcb_idx;
  _24 = (int) _23;
  dns_pcbs[_24] = 0B;
  # DEBUG BEGIN_STMT
  dns_table[_19].pcb_idx = 4;

  <bb 18> [local count: 214748364]:
  return;

}



;; Function dns_correct_response (dns_correct_response, funcdef_no=16, decl_uid=7349, cgraph_uid=17, symbol_order=24)

Modification phase of node dns_correct_response/24
Adjusting mask for param 0 to 0x3
Setting value range of param 0 [0, 3]
dns_correct_response (u8_t idx, u32_t ttl)
{
  int _1;
  struct ip_addr_t * _2;
  long unsigned int _3;
  unsigned char _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) idx_7(D);
  # DEBUG D#3 => &dns_table[_1]
  # DEBUG entry => D#3
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].ttl = ttl_10(D);
  # DEBUG BEGIN_STMT
  if (ttl_10(D) > 604800)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].ttl = 604800;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = &MEM[(struct dns_table_entry *)&dns_table][_1].ipaddr;
  dns_call_found (idx_7(D), _2);
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct dns_table_entry *)&dns_table][_1].ttl;
  if (_3 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _4 = MEM[(struct dns_table_entry *)&dns_table][_1].state;
  if (_4 == 3)
    goto <bb 6>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 6> [local count: 182536110]:
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 0;

  <bb 7> [local count: 1073741824]:
  return;

}



;; Function dns_send (dns_send, funcdef_no=8, decl_uid=7259, cgraph_uid=9, symbol_order=16)

Modification phase of node dns_send/16
dns_send (u8_t idx)
{
  const struct ip_addr_t * dst;
  u8_t pcb_idx;
  u8_t n;
  const char * hostname;
  u16_t copy_len;
  u16_t query_idx;
  struct pbuf * p;
  struct dns_query qry;
  struct dns_hdr hdr;
  err_t err;
  int _1;
  unsigned char _2;
  short unsigned int _3;
  int _4;
  unsigned char _5;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _13;
  char[256] * _14;
  unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  short unsigned int _19;
  char _20;
  int _21;
  int _22;
  int _23;
  int _24;
  short unsigned int _25;
  short unsigned int _26;
  short unsigned int _27;
  char _28;
  unsigned char _29;
  unsigned char _30;
  int _31;
  int _32;
  struct udp_pcb * _33;
  _Bool iftmp.5_38;
  int iftmp.6_39;
  err_t _40;
  _Bool iftmp.5_47;
  _Bool iftmp.5_48;

  <bb 2> [local count: 181990]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) idx_45(D);
  # DEBUG D#4 => &dns_table[_1]
  # DEBUG entry => D#4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct dns_table_entry *)&dns_table][_1].server_idx;
  if (_2 > 1)
    goto <bb 29>; [59.00%]
  else
    goto <bb 4>; [41.00%]

  <bb 29> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 30> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 74616]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = (int) _2;
  _5 = dns_servers[_4].type;
  if (_5 == 6)
    goto <bb 5>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 5> [local count: 25369]:
  _7 = dns_servers[_4].u_addr.ip6.addr[0];
  if (_7 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 6> [local count: 12685]:
  _8 = dns_servers[_4].u_addr.ip6.addr[1];
  if (_8 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 7> [local count: 6342]:
  _9 = dns_servers[_4].u_addr.ip6.addr[2];
  if (_9 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 3171]:
  _10 = dns_servers[_4].u_addr.ip6.addr[3];
  if (_10 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 23784]:

  <bb 10> [local count: 25369]:
  # iftmp.6_39 = PHI <1(8), 0(9)>
  iftmp.5_48 = (_Bool) iftmp.6_39;
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 49246]:
  _13 = dns_servers[_4].u_addr.ip4.addr;
  iftmp.5_47 = _13 == 0;

  <bb 12> [local count: 74616]:
  # iftmp.5_38 = PHI <iftmp.5_48(10), iftmp.5_47(11)>
  if (iftmp.5_38 != 0)
    goto <bb 13>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 13> [local count: 25369]:
  # DEBUG BEGIN_STMT
  # DEBUG idx => idx_45(D)
  # DEBUG addr => 0B
  # DEBUG INLINE_ENTRY dns_call_found
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dns_call_found.part.0 (idx_45(D), 0B);
  # DEBUG idx => NULL
  # DEBUG addr => NULL
  # DEBUG i => NULL
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 0;
  # DEBUG BEGIN_STMT
  goto <bb 28>; [100.00%]

  <bb 14> [local count: 49246]:
  # DEBUG BEGIN_STMT
  _14 = &MEM[(struct dns_table_entry *)&dns_table][_1].name;
  _15 = strlen (_14);
  _16 = (short unsigned int) _15;
  _17 = _16 + 18;
  p_50 = pbuf_alloc (74, _17, 640);
  # DEBUG p => p_50
  # DEBUG BEGIN_STMT
  if (p_50 != 0B)
    goto <bb 15>; [98.26%]
  else
    goto <bb 28>; [1.74%]

  <bb 15> [local count: 48390]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (&hdr, 0, 12);
  # DEBUG BEGIN_STMT
  _18 = MEM[(struct dns_table_entry *)&dns_table][_1].txid;
  _19 = lwip_htons (_18);
  hdr.id = _19;
  # DEBUG BEGIN_STMT
  hdr.flags1 = 1;
  # DEBUG BEGIN_STMT
  hdr.numquestions = 256;
  # DEBUG BEGIN_STMT
  pbuf_take (p_50, &hdr, 12);
  # DEBUG BEGIN_STMT
  # DEBUG hostname => _14
  # DEBUG BEGIN_STMT
  hostname_57 = _14 + 4294967295;
  # DEBUG hostname => hostname_57
  # DEBUG BEGIN_STMT
  # DEBUG query_idx => 12

  <bb 16> [local count: 452345]:
  # query_idx_34 = PHI <12(15), query_idx_64(31)>
  # hostname_35 = PHI <hostname_57(15), hostname_11(31)>
  # DEBUG hostname => hostname_35
  # DEBUG query_idx => query_idx_34
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  hostname_58 = hostname_35 + 1;
  # DEBUG hostname => hostname_58
  # DEBUG BEGIN_STMT
  # DEBUG hostname_part => hostname_58
  # DEBUG BEGIN_STMT
  # DEBUG n => 0
  goto <bb 18>; [100.00%]

  <bb 17> [local count: 3776163]:
  # DEBUG BEGIN_STMT
  n_59 = n_37 + 1;
  # DEBUG n => n_59
  # DEBUG BEGIN_STMT
  hostname_60 = hostname_36 + 1;
  # DEBUG hostname => hostname_60

  <bb 18> [local count: 4228507]:
  # hostname_36 = PHI <hostname_58(16), hostname_60(17)>
  # n_37 = PHI <0(16), n_59(17)>
  # DEBUG n => n_37
  # DEBUG hostname => hostname_36
  # DEBUG BEGIN_STMT
  _20 = *hostname_36;
  if (_20 != 46)
    goto <bb 19>; [94.50%]
  else
    goto <bb 20>; [5.50%]

  <bb 19> [local count: 3995939]:
  if (_20 != 0)
    goto <bb 17>; [94.50%]
  else
    goto <bb 20>; [5.50%]

  <bb 20> [local count: 452345]:
  # hostname_11 = PHI <hostname_36(18), hostname_36(19)>
  # n_12 = PHI <n_37(18), n_37(19)>
  # DEBUG BEGIN_STMT
  _21 = hostname_11 - hostname_58;
  copy_len_61 = (u16_t) _21;
  # DEBUG copy_len => copy_len_61
  # DEBUG BEGIN_STMT
  _22 = (int) query_idx_34;
  _23 = (int) n_12;
  _24 = _22 + _23;
  if (_24 > 65534)
    goto <bb 21>; [5.50%]
  else
    goto <bb 22>; [94.50%]

  <bb 21> [local count: 24879]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  # DEBUG overflow_return => NULL
  # DEBUG BEGIN_STMT
  pbuf_free (p_50);
  # DEBUG BEGIN_STMT
  goto <bb 28>; [100.00%]

  <bb 22> [local count: 427466]:
  # DEBUG BEGIN_STMT
  pbuf_put_at (p_50, query_idx_34, n_12);
  # DEBUG BEGIN_STMT
  _25 = query_idx_34 + 1;
  pbuf_take_at (p_50, hostname_58, copy_len_61, _25);
  # DEBUG BEGIN_STMT
  _26 = (short unsigned int) n_12;
  _27 = _26 + query_idx_34;
  query_idx_64 = _27 + 1;
  # DEBUG query_idx => query_idx_64
  # DEBUG BEGIN_STMT
  _28 = *hostname_11;
  if (_28 != 0)
    goto <bb 31>; [94.50%]
  else
    goto <bb 23>; [5.50%]

  <bb 31> [local count: 403955]:
  goto <bb 16>; [100.00%]

  <bb 23> [local count: 23511]:
  # _3 = PHI <_27(22)>
  # query_idx_6 = PHI <query_idx_64(22)>
  # DEBUG BEGIN_STMT
  pbuf_put_at (p_50, query_idx_6, 0);
  # DEBUG BEGIN_STMT
  query_idx_66 = _3 + 2;
  # DEBUG query_idx => query_idx_66
  # DEBUG BEGIN_STMT
  _29 = MEM[(struct dns_table_entry *)&dns_table][_1].reqaddrtype;
  if (_29 == 3)
    goto <bb 25>; [34.00%]
  else
    goto <bb 24>; [66.00%]

  <bb 24> [local count: 15517]:
  if (_29 == 1)
    goto <bb 25>; [34.00%]
  else
    goto <bb 26>; [66.00%]

  <bb 25> [local count: 13269]:
  # DEBUG BEGIN_STMT
  qry.type = 7168;
  goto <bb 27>; [100.00%]

  <bb 26> [local count: 10241]:
  # DEBUG BEGIN_STMT
  qry.type = 256;

  <bb 27> [local count: 23511]:
  # DEBUG BEGIN_STMT
  qry.cls = 256;
  # DEBUG BEGIN_STMT
  pbuf_take_at (p_50, &qry, 4, query_idx_66);
  # DEBUG BEGIN_STMT
  pcb_idx_71 = MEM[(struct dns_table_entry *)&dns_table][_1].pcb_idx;
  # DEBUG pcb_idx => pcb_idx_71
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG dst_port => 53
  # DEBUG BEGIN_STMT
  _30 = MEM[(struct dns_table_entry *)&dns_table][_1].server_idx;
  _31 = (int) _30;
  dst_72 = &dns_servers[_31];
  # DEBUG dst => dst_72
  # DEBUG BEGIN_STMT
  _32 = (int) pcb_idx_71;
  _33 = dns_pcbs[_32];
  err_74 = udp_sendto (_33, p_50, dst_72, 53);
  # DEBUG err => err_74
  # DEBUG BEGIN_STMT
  pbuf_free (p_50);

  <bb 28> [local count: 74616]:
  # _40 = PHI <0(13), -1(14), -6(21), err_74(27)>
  # DEBUG err => NULL
  hdr ={v} {CLOBBER};
  qry ={v} {CLOBBER};
  return _40;

}



;; Function dns_check_entry (dns_check_entry, funcdef_no=14, decl_uid=7328, cgraph_uid=15, symbol_order=22)

Modification phase of node dns_check_entry/22
dns_check_entry (u8_t i)
{
  struct dns_table_entry * entry;
  int _1;
  unsigned char _2;
  short unsigned int _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  unsigned char _8;
  unsigned char _9;
  unsigned char _10;
  long unsigned int _11;
  long unsigned int _12;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) i_18(D);
  entry_19 = &dns_table[_1];
  # DEBUG entry => entry_19
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (i_18(D) > 3)
    goto <bb 18>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 18> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 20> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct dns_table_entry *)&dns_table][_1].state;
  switch (_2) <default: <L31> [20.00%], case 0: <L27> [20.00%], case 1: <L3> [20.00%], case 2: <L6> [20.00%], case 3: <L17> [20.00%]>

  <bb 19> [local count: 21475]:
<L31>:
  goto <bb 16>; [100.00%]

  <bb 5> [local count: 21475]:
<L3>:
  # DEBUG BEGIN_STMT
  _3 = dns_create_txid ();
  MEM[(struct dns_table_entry *)&dns_table][_1].txid = _3;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 2;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].server_idx = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].tmr = 1;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].retries = 0;
  # DEBUG BEGIN_STMT
  dns_send (i_18(D));
  # DEBUG err => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 6> [local count: 21475]:
<L6>:
  # DEBUG BEGIN_STMT
  _4 = MEM[(struct dns_table_entry *)&dns_table][_1].tmr;
  _5 = _4 + 255;
  MEM[(struct dns_table_entry *)&dns_table][_1].tmr = _5;
  if (_5 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 7> [local count: 10737]:
  # DEBUG BEGIN_STMT
  _6 = MEM[(struct dns_table_entry *)&dns_table][_1].retries;
  _7 = _6 + 1;
  MEM[(struct dns_table_entry *)&dns_table][_1].retries = _7;
  if (_7 == 4)
    goto <bb 8>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 8> [local count: 3651]:
  # DEBUG BEGIN_STMT
  _8 = dns_backupserver_available (entry_19);
  if (_8 != 0)
    goto <bb 9>; [67.00%]
  else
    goto <bb 10>; [33.00%]

  <bb 9> [local count: 2446]:
  # DEBUG BEGIN_STMT
  _9 = MEM[(struct dns_table_entry *)&dns_table][_1].server_idx;
  _10 = _9 + 1;
  MEM[(struct dns_table_entry *)&dns_table][_1].server_idx = _10;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].tmr = 1;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].retries = 0;
  goto <bb 12>; [100.00%]

  <bb 10> [local count: 1205]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG idx => i_18(D)
  # DEBUG addr => 0B
  # DEBUG INLINE_ENTRY dns_call_found
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dns_call_found.part.0 (i_18(D), 0B);
  # DEBUG idx => NULL
  # DEBUG addr => NULL
  # DEBUG i => NULL
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 0;
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 11> [local count: 7087]:
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].tmr = _7;

  <bb 12> [local count: 9533]:
  # DEBUG BEGIN_STMT
  dns_send (i_18(D));
  # DEBUG err => NULL
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 13> [local count: 21475]:
<L17>:
  # DEBUG BEGIN_STMT
  _11 = MEM[(struct dns_table_entry *)&dns_table][_1].ttl;
  if (_11 == 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 14> [local count: 10737]:
  _12 = _11 + 4294967295;
  MEM[(struct dns_table_entry *)&dns_table][_1].ttl = _12;
  if (_12 == 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 15> [local count: 16106]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 0;
  goto <bb 17>; [100.00%]

  <bb 21> [local count: 214748365]:

  <bb 16> [local count: 214748365]:
<L28>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT
  goto <bb 21>; [100.00%]

  <bb 17> [local count: 85899]:
<L27>:
  return;

}



;; Function dns_recv (dns_recv, funcdef_no=17, decl_uid=7195, cgraph_uid=18, symbol_order=25)

Modification phase of node dns_recv/25
dns_recv (void * arg, struct udp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * addr, u16_t port)
{
  struct ip6_addr_p_t ip6addr;
  struct ip4_addr_t ip4addr;
  struct dns_table_entry * entry;
  u16_t nanswers;
  u16_t nquestions;
  struct dns_query qry;
  struct dns_answer ans;
  struct dns_hdr hdr;
  u16_t res_idx;
  u16_t txid;
  u8_t i;
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  int _4;
  unsigned char _5;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;
  unsigned char _9;
  signed char _10;
  unsigned char _11;
  unsigned char _12;
  int _13;
  unsigned char _14;
  long unsigned int _16;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  unsigned char _25;
  unsigned char _26;
  long unsigned int _27;
  long unsigned int _30;
  char[256] * _31;
  short unsigned int _32;
  short unsigned int _33;
  unsigned char _34;
  short unsigned int _35;
  short unsigned int _36;
  unsigned char _37;
  unsigned char _38;
  short unsigned int _39;
  short unsigned int _40;
  short unsigned int _41;
  short unsigned int _42;
  unsigned char _43;
  short unsigned int _44;
  long unsigned int _45;
  long unsigned int _46;
  long unsigned int _47;
  short unsigned int _48;
  unsigned char _49;
  short unsigned int _50;
  long unsigned int _51;
  long unsigned int _52;
  long unsigned int _53;
  long unsigned int _54;
  long unsigned int _55;
  long unsigned int _56;
  int _57;
  short unsigned int _58;
  short unsigned int _59;
  int _60;
  int _61;
  short unsigned int _62;
  short unsigned int _63;
  short unsigned int _64;
  unsigned char _65;
  unsigned char _66;
  _Bool iftmp.25_70;
  int iftmp.26_71;
  unsigned char _82;
  int _89;
  _Bool iftmp.25_90;
  _Bool iftmp.25_91;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_78(D)->tot_len;
  if (_1 <= 15)
    goto <bb 3>; [51.12%]
  else
    goto <bb 4>; [48.88%]

  <bb 3> [local count: 548896821]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 4> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _2 = pbuf_copy_partial (p_78(D), &hdr, 12, 0);
  if (_2 == 12)
    goto <bb 5>; [20.24%]
  else
    goto <bb 75>; [79.76%]

  <bb 5> [local count: 106228629]:
  # DEBUG BEGIN_STMT
  _3 = hdr.id;
  txid_81 = lwip_htons (_3);
  # DEBUG txid => txid_81
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 74>; [100.00%]

  <bb 6> [local count: 395342869]:
  # DEBUG BEGIN_STMT
  _4 = (int) i_67;
  entry_83 = &dns_table[_4];
  # DEBUG entry => entry_83
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct dns_table_entry *)&dns_table][_4].state;
  if (_5 == 2)
    goto <bb 7>; [34.00%]
  else
    goto <bb 73>; [66.00%]

  <bb 7> [local count: 134416575]:
  _6 = MEM[(struct dns_table_entry *)&dns_table][_4].txid;
  if (_6 == txid_81)
    goto <bb 8>; [5.50%]
  else
    goto <bb 73>; [94.50%]

  <bb 8> [local count: 7392912]:
  # _89 = PHI <_4(7)>
  # i_15 = PHI <i_67(7)>
  # entry_28 = PHI <entry_83(7)>
  # DEBUG BEGIN_STMT
  _7 = hdr.numquestions;
  nquestions_85 = lwip_htons (_7);
  # DEBUG nquestions => nquestions_85
  # DEBUG BEGIN_STMT
  _8 = hdr.numanswers;
  nanswers_87 = lwip_htons (_8);
  # DEBUG nanswers => nanswers_87
  # DEBUG BEGIN_STMT
  _9 = hdr.flags1;
  _10 = (signed char) _9;
  if (_10 >= 0)
    goto <bb 9>; [42.57%]
  else
    goto <bb 10>; [57.43%]

  <bb 9> [local count: 3147162]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 10> [local count: 4245749]:
  # DEBUG BEGIN_STMT
  if (nquestions_85 != 1)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 2122875]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 12> [local count: 2122875]:
  # DEBUG BEGIN_STMT
  _11 = addr_88(D)->type;
  _12 = MEM[(struct dns_table_entry *)&dns_table][_89].server_idx;
  _13 = (int) _12;
  _14 = dns_servers[_13].type;
  if (_11 == _14)
    goto <bb 13>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 13> [local count: 1061437]:
  if (_11 == 6)
    goto <bb 14>; [34.00%]
  else
    goto <bb 21>; [66.00%]

  <bb 14> [local count: 360889]:
  _16 = addr_88(D)->u_addr.ip6.addr[0];
  _18 = dns_servers[_13].u_addr.ip6.addr[0];
  if (_16 != _18)
    goto <bb 20>; [66.00%]
  else
    goto <bb 15>; [34.00%]

  <bb 15> [local count: 122702]:
  _19 = addr_88(D)->u_addr.ip6.addr[1];
  _20 = dns_servers[_13].u_addr.ip6.addr[1];
  if (_19 != _20)
    goto <bb 20>; [66.00%]
  else
    goto <bb 16>; [34.00%]

  <bb 16> [local count: 41719]:
  _21 = addr_88(D)->u_addr.ip6.addr[2];
  _22 = dns_servers[_13].u_addr.ip6.addr[2];
  if (_21 != _22)
    goto <bb 20>; [66.00%]
  else
    goto <bb 17>; [34.00%]

  <bb 17> [local count: 14184]:
  _23 = addr_88(D)->u_addr.ip6.addr[3];
  _24 = dns_servers[_13].u_addr.ip6.addr[3];
  if (_23 != _24)
    goto <bb 20>; [66.00%]
  else
    goto <bb 18>; [34.00%]

  <bb 18> [local count: 4823]:
  _25 = addr_88(D)->u_addr.ip6.zone;
  _26 = dns_servers[_13].u_addr.ip6.zone;
  if (_25 != _26)
    goto <bb 20>; [66.00%]
  else
    goto <bb 19>; [34.00%]

  <bb 19> [local count: 1640]:

  <bb 20> [local count: 360889]:
  # iftmp.26_71 = PHI <1(15), 0(19), 1(14), 1(18), 1(17), 1(16)>
  iftmp.25_91 = (_Bool) iftmp.26_71;
  goto <bb 22>; [100.00%]

  <bb 21> [local count: 700549]:
  _27 = addr_88(D)->u_addr.ip4.addr;
  _30 = dns_servers[_13].u_addr.ip4.addr;
  iftmp.25_90 = _27 != _30;

  <bb 22> [local count: 1061437]:
  # iftmp.25_70 = PHI <iftmp.25_91(20), iftmp.25_90(21)>
  if (iftmp.25_70 != 0)
    goto <bb 23>; [51.12%]
  else
    goto <bb 24>; [48.88%]

  <bb 23> [local count: 1604044]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 24> [local count: 518831]:
  # DEBUG BEGIN_STMT
  _31 = &MEM[(struct dns_table_entry *)&dns_table][_89].name;
  res_idx_93 = dns_compare_name (_31, p_78(D), 12);
  # DEBUG res_idx => res_idx_93
  # DEBUG BEGIN_STMT
  if (res_idx_93 == 65535)
    goto <bb 25>; [35.01%]
  else
    goto <bb 26>; [64.99%]

  <bb 25> [local count: 181643]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 26> [local count: 337188]:
  # DEBUG BEGIN_STMT
  _32 = pbuf_copy_partial (p_78(D), &qry, 4, res_idx_93);
  if (_32 != 4)
    goto <bb 27>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 27> [local count: 168594]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 28> [local count: 168594]:
  # DEBUG BEGIN_STMT
  _33 = qry.cls;
  if (_33 != 256)
    goto <bb 35>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 29> [local count: 84297]:
  _34 = MEM[(struct dns_table_entry *)&dns_table][_89].reqaddrtype;
  if (_34 == 3)
    goto <bb 31>; [34.00%]
  else
    goto <bb 30>; [66.00%]

  <bb 30> [local count: 55636]:
  if (_34 == 1)
    goto <bb 31>; [34.00%]
  else
    goto <bb 32>; [66.00%]

  <bb 31> [local count: 47577]:
  _35 = qry.type;
  if (_35 != 7168)
    goto <bb 35>; [50.00%]
  else
    goto <bb 32>; [50.00%]

  <bb 32> [local count: 60508]:
  if (_34 != 3)
    goto <bb 33>; [66.00%]
  else
    goto <bb 36>; [34.00%]

  <bb 33> [local count: 39936]:
  if (_34 != 1)
    goto <bb 34>; [66.00%]
  else
    goto <bb 36>; [34.00%]

  <bb 34> [local count: 26357]:
  _36 = qry.type;
  if (_36 != 256)
    goto <bb 35>; [50.00%]
  else
    goto <bb 36>; [50.00%]

  <bb 35> [local count: 121264]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 36> [local count: 47330]:
  # DEBUG BEGIN_STMT
  if (res_idx_93 > 65531)
    goto <bb 37>; [34.00%]
  else
    goto <bb 38>; [66.00%]

  <bb 37> [local count: 16092]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 38> [local count: 31238]:
  # DEBUG BEGIN_STMT
  res_idx_95 = res_idx_93 + 4;
  # DEBUG res_idx => res_idx_95
  # DEBUG BEGIN_STMT
  _37 = hdr.flags2;
  _82 = _37 & 15;
  if (_82 != 0)
    goto <bb 39>; [50.00%]
  else
    goto <bb 77>; [50.00%]

  <bb 77> [local count: 15619]:
  goto <bb 65>; [100.00%]

  <bb 39> [local count: 15619]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _38 = dns_backupserver_available (entry_28);
  if (_38 != 0)
    goto <bb 40>; [33.00%]
  else
    goto <bb 72>; [67.00%]

  <bb 40> [local count: 5154]:
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_89].retries = 3;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_89].tmr = 1;
  # DEBUG BEGIN_STMT
  dns_check_entry (i_15);
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 41> [local count: 128297]:
  # DEBUG BEGIN_STMT
  res_idx_97 = dns_skip_name (p_78(D), res_idx_68);
  # DEBUG res_idx => res_idx_97
  # DEBUG BEGIN_STMT
  if (res_idx_97 == 65535)
    goto <bb 42>; [2.00%]
  else
    goto <bb 43>; [98.00%]

  <bb 42> [local count: 2566]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 43> [local count: 125731]:
  # DEBUG BEGIN_STMT
  _39 = pbuf_copy_partial (p_78(D), &ans, 10, res_idx_97);
  if (_39 != 10)
    goto <bb 44>; [2.00%]
  else
    goto <bb 45>; [98.00%]

  <bb 44> [local count: 2515]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 45> [local count: 123216]:
  # DEBUG BEGIN_STMT
  if (res_idx_97 > 65525)
    goto <bb 46>; [2.00%]
  else
    goto <bb 47>; [98.00%]

  <bb 46> [local count: 2464]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 47> [local count: 120752]:
  # DEBUG BEGIN_STMT
  res_idx_99 = res_idx_97 + 10;
  # DEBUG res_idx => res_idx_99
  # DEBUG BEGIN_STMT
  _40 = ans.cls;
  if (_40 == 256)
    goto <bb 48>; [51.12%]
  else
    goto <bb 62>; [48.88%]

  <bb 48> [local count: 61728]:
  # DEBUG BEGIN_STMT
  _41 = ans.type;
  if (_41 == 256)
    goto <bb 49>; [34.00%]
  else
    goto <bb 55>; [66.00%]

  <bb 49> [local count: 20988]:
  _42 = ans.len;
  if (_42 == 1024)
    goto <bb 50>; [34.00%]
  else
    goto <bb 55>; [66.00%]

  <bb 50> [local count: 7136]:
  # DEBUG BEGIN_STMT
  _43 = MEM[(struct dns_table_entry *)&dns_table][_89].reqaddrtype;
  if (_43 != 3)
    goto <bb 51>; [66.00%]
  else
    goto <bb 55>; [34.00%]

  <bb 51> [local count: 4710]:
  if (_43 != 1)
    goto <bb 52>; [2.00%]
  else
    goto <bb 55>; [98.00%]

  <bb 52> [local count: 94]:
  # res_idx_29 = PHI <res_idx_99(51)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _44 = pbuf_copy_partial (p_78(D), &ip4addr, 4, res_idx_29);
  if (_44 != 4)
    goto <bb 53>; [79.76%]
  else
    goto <bb 54>; [20.24%]

  <bb 53> [local count: 75]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  ip4addr ={v} {CLOBBER};
  goto <bb 75>; [100.00%]

  <bb 54> [local count: 19]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _45 = ip4addr.addr;
  dns_table[_89].ipaddr.u_addr.ip4.addr = _45;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dns_table[_89].ipaddr.type = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dns_table[_89].ipaddr.u_addr.ip6.addr[3] = 0;
  dns_table[_89].ipaddr.u_addr.ip6.addr[2] = 0;
  dns_table[_89].ipaddr.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  dns_table[_89].ipaddr.u_addr.ip6.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_78(D));
  # DEBUG BEGIN_STMT
  _46 = ans.ttl;
  _47 = lwip_htonl (_46);
  dns_correct_response (i_15, _47);
  # DEBUG BEGIN_STMT
  ip4addr ={v} {CLOBBER};
  goto <bb 76>; [100.00%]

  <bb 55> [local count: 61634]:
  # DEBUG BEGIN_STMT
  if (_41 == 7168)
    goto <bb 56>; [34.00%]
  else
    goto <bb 62>; [66.00%]

  <bb 56> [local count: 20956]:
  _48 = ans.len;
  if (_48 == 4096)
    goto <bb 57>; [34.00%]
  else
    goto <bb 62>; [66.00%]

  <bb 57> [local count: 7125]:
  # DEBUG BEGIN_STMT
  _49 = MEM[(struct dns_table_entry *)&dns_table][_89].reqaddrtype;
  if (_49 == 3)
    goto <bb 59>; [2.00%]
  else
    goto <bb 58>; [98.00%]

  <bb 58> [local count: 6982]:
  if (_49 == 1)
    goto <bb 59>; [2.00%]
  else
    goto <bb 62>; [98.00%]

  <bb 59> [local count: 282]:
  # res_idx_17 = PHI <res_idx_99(57), res_idx_99(58)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _50 = pbuf_copy_partial (p_78(D), &ip6addr, 16, res_idx_17);
  if (_50 != 16)
    goto <bb 60>; [79.76%]
  else
    goto <bb 61>; [20.24%]

  <bb 60> [local count: 225]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  ip6addr ={v} {CLOBBER};
  goto <bb 75>; [100.00%]

  <bb 61> [local count: 57]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _51 = ip6addr.addr[0];
  dns_table[_89].ipaddr.u_addr.ip6.addr[0] = _51;
  # DEBUG BEGIN_STMT
  _52 = ip6addr.addr[1];
  dns_table[_89].ipaddr.u_addr.ip6.addr[1] = _52;
  # DEBUG BEGIN_STMT
  _53 = ip6addr.addr[2];
  dns_table[_89].ipaddr.u_addr.ip6.addr[2] = _53;
  # DEBUG BEGIN_STMT
  _54 = ip6addr.addr[3];
  dns_table[_89].ipaddr.u_addr.ip6.addr[3] = _54;
  # DEBUG BEGIN_STMT
  dns_table[_89].ipaddr.u_addr.ip6.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dns_table[_89].ipaddr.type = 6;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_78(D));
  # DEBUG BEGIN_STMT
  _55 = ans.ttl;
  _56 = lwip_htonl (_55);
  dns_correct_response (i_15, _56);
  # DEBUG BEGIN_STMT
  ip6addr ={v} {CLOBBER};
  goto <bb 76>; [100.00%]

  <bb 62> [local count: 120376]:
  # DEBUG BEGIN_STMT
  _57 = (int) res_idx_99;
  _58 = ans.len;
  _59 = lwip_htons (_58);
  _60 = (int) _59;
  _61 = _57 + _60;
  if (_61 > 65535)
    goto <bb 63>; [2.00%]
  else
    goto <bb 64>; [98.00%]

  <bb 63> [local count: 2408]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 75>; [100.00%]

  <bb 64> [local count: 117968]:
  # DEBUG BEGIN_STMT
  _62 = ans.len;
  _63 = lwip_htons (_62);
  res_idx_126 = _63 + res_idx_99;
  # DEBUG res_idx => res_idx_126
  # DEBUG BEGIN_STMT
  nanswers_127 = nanswers_69 + 65535;
  # DEBUG nanswers => nanswers_127

  <bb 65> [local count: 133587]:
  # res_idx_68 = PHI <res_idx_126(64), res_idx_95(77)>
  # nanswers_69 = PHI <nanswers_127(64), nanswers_87(77)>
  # DEBUG nanswers => nanswers_69
  # DEBUG res_idx => res_idx_68
  # DEBUG BEGIN_STMT
  if (nanswers_69 != 0)
    goto <bb 66>; [98.00%]
  else
    goto <bb 67>; [2.00%]

  <bb 66> [local count: 130915]:
  _64 = p_78(D)->tot_len;
  if (_64 > res_idx_68)
    goto <bb 41>; [98.00%]
  else
    goto <bb 67>; [2.00%]

  <bb 67> [local count: 5290]:
  # DEBUG BEGIN_STMT
  _65 = MEM[(struct dns_table_entry *)&dns_table][_89].reqaddrtype;
  _66 = _65 + 254;
  if (_66 <= 1)
    goto <bb 68>; [41.00%]
  else
    goto <bb 72>; [59.00%]

  <bb 68> [local count: 2169]:
  # DEBUG BEGIN_STMT
  if (_65 == 2)
    goto <bb 69>; [34.00%]
  else
    goto <bb 70>; [66.00%]

  <bb 69> [local count: 737]:
  # DEBUG BEGIN_STMT
  dns_table[_89].reqaddrtype = 1;
  goto <bb 71>; [100.00%]

  <bb 70> [local count: 1431]:
  # DEBUG BEGIN_STMT
  dns_table[_89].reqaddrtype = 0;

  <bb 71> [local count: 2169]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_78(D));
  # DEBUG BEGIN_STMT
  dns_table[_89].state = 1;
  # DEBUG BEGIN_STMT
  dns_check_entry (i_15);
  # DEBUG BEGIN_STMT
  goto <bb 76>; [100.00%]

  <bb 72> [local count: 13586]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_78(D));
  # DEBUG BEGIN_STMT
  # DEBUG idx => i_15
  # DEBUG addr => 0B
  # DEBUG INLINE_ENTRY dns_call_found
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dns_call_found.part.0 (i_15, 0B);
  # DEBUG idx => NULL
  # DEBUG addr => NULL
  # DEBUG i => NULL
  # DEBUG BEGIN_STMT
  dns_table[_89].state = 0;
  # DEBUG BEGIN_STMT
  goto <bb 76>; [100.00%]

  <bb 73> [local count: 387949957]:
  # DEBUG BEGIN_STMT
  i_138 = i_67 + 1;
  # DEBUG i => i_138

  <bb 74> [local count: 494178586]:
  # i_67 = PHI <0(5), i_138(73)>
  # DEBUG i => i_67
  # DEBUG BEGIN_STMT
  if (i_67 != 4)
    goto <bb 6>; [80.00%]
  else
    goto <bb 75>; [20.00%]

  <bb 75> [local count: 1073725993]:
ignore_packet:
  # DEBUG BEGIN_STMT
  pbuf_free (p_78(D));
  # DEBUG BEGIN_STMT

  <bb 76> [local count: 1073741824]:
  hdr ={v} {CLOBBER};
  ans ={v} {CLOBBER};
  qry ={v} {CLOBBER};
  return;

}



;; Function dns_init (dns_init, funcdef_no=1, decl_uid=7045, cgraph_uid=2, symbol_order=9)

Modification phase of node dns_init/9
dns_init ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function dns_setserver (dns_setserver, funcdef_no=2, decl_uid=7050, cgraph_uid=3, symbol_order=10)

Modification phase of node dns_setserver/10
dns_setserver (u8_t numdns, const struct ip_addr_t * dnsserver)
{
  int _1;
  int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (numdns_4(D) <= 1)
    goto <bb 3>; [41.00%]
  else
    goto <bb 6>; [59.00%]

  <bb 3> [local count: 440234148]:
  # DEBUG BEGIN_STMT
  if (dnsserver_6(D) != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 308163903]:
  # DEBUG BEGIN_STMT
  _1 = (int) numdns_4(D);
  dns_servers[_1] = *dnsserver_6(D);
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 132070244]:
  # DEBUG BEGIN_STMT
  _2 = (int) numdns_4(D);
  dns_servers[_2] = ip_addr_any;

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function dns_getserver (dns_getserver, funcdef_no=3, decl_uid=7052, cgraph_uid=4, symbol_order=11)

Modification phase of node dns_getserver/11
dns_getserver (u8_t numdns)
{
  int _1;
  const struct ip_addr_t * _2;
  const struct ip_addr_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (numdns_3(D) <= 1)
    goto <bb 3>; [41.00%]
  else
    goto <bb 4>; [59.00%]

  <bb 3> [local count: 440234148]:
  # DEBUG BEGIN_STMT
  _1 = (int) numdns_3(D);
  _4 = &dns_servers[_1];

  <bb 4> [local count: 1073741824]:
  # _2 = PHI <_4(3), &ip_addr_any(2)>
  return _2;

}



;; Function dns_tmr (dns_tmr, funcdef_no=4, decl_uid=7047, cgraph_uid=5, symbol_order=12)

Modification phase of node dns_tmr/12
dns_tmr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dns_check_entries ();
  return;

}



;; Function dns_gethostbyname_addrtype (dns_gethostbyname_addrtype, funcdef_no=20, decl_uid=7063, cgraph_uid=21, symbol_order=28)

Modification phase of node dns_gethostbyname_addrtype/28
dns_gethostbyname_addrtype (const char * hostname, struct ip_addr_t * addr, void (*dns_found_callback) (const char *, const struct ip_addr_t *, void *) found, void * callback_arg, u8_t dns_addrtype)
{
  u8_t fallback;
  size_t hostnamelen;
  char _1;
  int _2;
  unsigned char _3;
  unsigned char _4;
  signed char _5;
  unsigned char _6;
  signed char _7;
  unsigned char _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  err_t _15;
  _Bool iftmp.8_16;
  int iftmp.9_17;
  _Bool iftmp.8_28;
  _Bool iftmp.8_29;
  err_t _33;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (addr_20(D) == 0B)
    goto <bb 26>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  if (hostname_21(D) == 0B)
    goto <bb 26>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 1064099892]:
  _1 = *hostname_21(D);
  if (_1 == 0)
    goto <bb 26>; [1.04%]
  else
    goto <bb 5>; [98.96%]

  <bb 5> [local count: 1053033253]:
  # DEBUG BEGIN_STMT
  hostnamelen_23 = strlen (hostname_21(D));
  # DEBUG hostnamelen => hostnamelen_23
  # DEBUG BEGIN_STMT
  if (hostnamelen_23 > 255)
    goto <bb 26>; [2.09%]
  else
    goto <bb 6>; [97.91%]

  <bb 6> [local count: 1031024857]:
  # DEBUG BEGIN_STMT
  _2 = ipaddr_aton (hostname_21(D), addr_20(D));
  if (_2 != 0)
    goto <bb 7>; [67.00%]
  else
    goto <bb 11>; [33.00%]

  <bb 7> [local count: 690786655]:
  # DEBUG BEGIN_STMT
  _3 = addr_20(D)->type;
  if (_3 == 6)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 234867463]:
  if (dns_addrtype_25(D) != 0)
    goto <bb 26>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 9> [local count: 610931718]:
  _4 = addr_20(D)->type;
  if (_4 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 305465859]:
  if (dns_addrtype_25(D) != 1)
    goto <bb 26>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 11> [local count: 798436991]:
  # DEBUG BEGIN_STMT
  _5 = dns_lookup (hostname_21(D), addr_20(D), dns_addrtype_25(D));
  if (_5 == 0)
    goto <bb 26>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 12> [local count: 526968414]:
  # DEBUG BEGIN_STMT
  _6 = dns_addrtype_25(D) + 254;
  if (_6 <= 1)
    goto <bb 13>; [41.00%]
  else
    goto <bb 16>; [59.00%]

  <bb 13> [local count: 216057050]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (dns_addrtype_25(D) == 2)
    goto <bb 15>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 14> [local count: 142597653]:
  # DEBUG BEGIN_STMT
  # DEBUG fallback => 0

  <bb 15> [local count: 216057050]:
  # fallback_14 = PHI <1(13), 0(14)>
  # DEBUG fallback => fallback_14
  # DEBUG BEGIN_STMT
  _7 = dns_lookup (hostname_21(D), addr_20(D), fallback_14);
  if (_7 == 0)
    goto <bb 26>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 16> [local count: 453509017]:
  # DEBUG BEGIN_STMT
  _8 = dns_servers[0].type;
  if (_8 == 6)
    goto <bb 17>; [34.00%]
  else
    goto <bb 23>; [66.00%]

  <bb 17> [local count: 154193066]:
  _9 = dns_servers[0].u_addr.ip6.addr[0];
  if (_9 == 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 18> [local count: 77096533]:
  _10 = dns_servers[0].u_addr.ip6.addr[1];
  if (_10 == 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 19> [local count: 38548266]:
  _11 = dns_servers[0].u_addr.ip6.addr[2];
  if (_11 == 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 20> [local count: 19274133]:
  _12 = dns_servers[0].u_addr.ip6.addr[3];
  if (_12 == 0)
    goto <bb 22>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 21> [local count: 144555999]:

  <bb 22> [local count: 154193066]:
  # iftmp.9_17 = PHI <1(20), 0(21)>
  iftmp.8_29 = (_Bool) iftmp.9_17;
  goto <bb 24>; [100.00%]

  <bb 23> [local count: 299315951]:
  _13 = dns_servers[0].u_addr.ip4.addr;
  iftmp.8_28 = _13 == 0;

  <bb 24> [local count: 453509017]:
  # iftmp.8_16 = PHI <iftmp.8_29(22), iftmp.8_28(23)>
  if (iftmp.8_16 != 0)
    goto <bb 26>; [2.09%]
  else
    goto <bb 25>; [97.91%]

  <bb 25> [local count: 444030678]:
  # DEBUG BEGIN_STMT
  _33 = dns_enqueue (hostname_21(D), hostnamelen_23, found_30(D), callback_arg_31(D), dns_addrtype_25(D));

  <bb 26> [local count: 1073741824]:
  # _15 = PHI <-16(3), -16(5), 0(10), 0(11), 0(15), -6(24), _33(25), -16(2), -16(4), 0(8)>
  return _15;

}



;; Function dns_gethostbyname (dns_gethostbyname, funcdef_no=19, decl_uid=7057, cgraph_uid=20, symbol_order=27)

Modification phase of node dns_gethostbyname/27
dns_gethostbyname (const char * hostname, struct ip_addr_t * addr, void (*dns_found_callback) (const char *, const struct ip_addr_t *, void *) found, void * callback_arg)
{
  err_t _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 2);
  return _7;

}


