
IPA constant propagation start:
Determining dynamic type for call: _5 = snmp_send_trap (0B, 6, specific_trap_2(D), varbinds_3(D));
  Starting walk at: _5 = snmp_send_trap (0B, 6, specific_trap_2(D), varbinds_3(D));
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = snmp_send_trap (0B, 6, specific_trap_2(D), varbinds_3(D));
  Starting walk at: _5 = snmp_send_trap (0B, 6, specific_trap_2(D), varbinds_3(D));
  instance pointer: varbinds_3(D)  Outer instance pointer: varbinds_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = snmp_send_trap (&oid, generic_trap_2(D), 0, 0B);
  Starting walk at: _4 = snmp_send_trap (&oid, generic_trap_2(D), 0, 0B);
  instance pointer: &oid  Outer instance pointer: oid offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = snmp_send_trap (&oid, generic_trap_2(D), 0, 0B);
  Starting walk at: _4 = snmp_send_trap (&oid, generic_trap_2(D), 0, 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Starting walk at: tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  instance pointer: &MEM[(short unsigned int *)&trap_msg + 50B]  Outer instance pointer: trap_msg offset: 400 (bits) vtbl reference: 
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:_11 = snmp_get_device_enterprise_oid ();
  Function call may change dynamic type:_10 = snmp_get_local_ip_for_dst (snmp_traps_handle.10_9, _2, &trap_msg.sip);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:pbuf_free (p_56);
  Function call may change dynamic type:snmp_sendto (snmp_traps_handle.13_20, p_56, _2, 162);
  Function call may change dynamic type:snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  Function call may change dynamic type:snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
Determining dynamic type for call: tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Starting walk at: tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  instance pointer: varbinds_50(D)  Outer instance pointer: varbinds_50(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:_11 = snmp_get_device_enterprise_oid ();
  Function call may change dynamic type:_10 = snmp_get_local_ip_for_dst (snmp_traps_handle.10_9, _2, &trap_msg.sip);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:pbuf_free (p_56);
  Function call may change dynamic type:snmp_sendto (snmp_traps_handle.13_20, p_56, _2, 162);
  Function call may change dynamic type:snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  Function call may change dynamic type:snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
Determining dynamic type for call: tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Starting walk at: tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  instance pointer: &trap_msg  Outer instance pointer: trap_msg offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:_11 = snmp_get_device_enterprise_oid ();
  Function call may change dynamic type:_10 = snmp_get_local_ip_for_dst (snmp_traps_handle.10_9, _2, &trap_msg.sip);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:pbuf_free (p_56);
  Function call may change dynamic type:snmp_sendto (snmp_traps_handle.13_20, p_56, _2, 162);
  Function call may change dynamic type:snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  Function call may change dynamic type:snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
Determining dynamic type for call: snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Starting walk at: snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  instance pointer: &trap_msg  Outer instance pointer: trap_msg offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:_11 = snmp_get_device_enterprise_oid ();
  Function call may change dynamic type:_10 = snmp_get_local_ip_for_dst (snmp_traps_handle.10_9, _2, &trap_msg.sip);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:pbuf_free (p_56);
  Function call may change dynamic type:snmp_sendto (snmp_traps_handle.13_20, p_56, _2, 162);
  Function call may change dynamic type:snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  Function call may change dynamic type:snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
Determining dynamic type for call: snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Starting walk at: snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  instance pointer: &pbuf_stream  Outer instance pointer: pbuf_stream offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:_11 = snmp_get_device_enterprise_oid ();
  Function call may change dynamic type:_10 = snmp_get_local_ip_for_dst (snmp_traps_handle.10_9, _2, &trap_msg.sip);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:pbuf_free (p_56);
  Function call may change dynamic type:snmp_sendto (snmp_traps_handle.13_20, p_56, _2, 162);
  Function call may change dynamic type:snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  Function call may change dynamic type:snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
Determining dynamic type for call: snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  Starting walk at: snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  instance pointer: &pbuf_stream  Outer instance pointer: pbuf_stream offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:_11 = snmp_get_device_enterprise_oid ();
  Function call may change dynamic type:_10 = snmp_get_local_ip_for_dst (snmp_traps_handle.10_9, _2, &trap_msg.sip);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:pbuf_free (p_56);
  Function call may change dynamic type:snmp_sendto (snmp_traps_handle.13_20, p_56, _2, 162);
  Function call may change dynamic type:snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  Function call may change dynamic type:snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
Determining dynamic type for call: snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  Starting walk at: snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  instance pointer: varbinds_50(D)  Outer instance pointer: varbinds_50(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:_11 = snmp_get_device_enterprise_oid ();
  Function call may change dynamic type:_10 = snmp_get_local_ip_for_dst (snmp_traps_handle.10_9, _2, &trap_msg.sip);
  Function call may change dynamic type:p_56 = pbuf_alloc (74, tot_len_54, 640);
  Function call may change dynamic type:tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  Function call may change dynamic type:tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  Function call may change dynamic type:_14 = sys_now ();
  Function call may change dynamic type:pbuf_free (p_56);
  Function call may change dynamic type:snmp_sendto (snmp_traps_handle.13_20, p_56, _2, 162);
  Function call may change dynamic type:snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  Function call may change dynamic type:snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  Function call may change dynamic type:snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  snmp_trap_varbind_enc.isra.0/39:
  Jump functions of caller  snmp_trap_varbind_sum.isra.0/38:
  Jump functions of caller  snmp_append_outbound_varbind/36:
  Jump functions of caller  snmp_asn1_enc_oid/35:
  Jump functions of caller  snmp_asn1_enc_raw/34:
  Jump functions of caller  snmp_asn1_enc_s32t/33:
  Jump functions of caller  snmp_ans1_enc_tlv/32:
  Jump functions of caller  strlen/31:
  Jump functions of caller  snmp_asn1_enc_oid_cnt/29:
  Jump functions of caller  snmp_asn1_enc_s32t_cnt/28:
  Jump functions of caller  snmp_asn1_enc_u32t_cnt/27:
  Jump functions of caller  snmp_asn1_enc_length_cnt/26:
  Jump functions of caller  snmp_varbind_length/25:
  Jump functions of caller  pbuf_free/24:
  Jump functions of caller  snmp_sendto/23:
  Jump functions of caller  snmp_pbuf_stream_init/21:
  Jump functions of caller  pbuf_alloc/20:
  Jump functions of caller  sys_now/19:
  Jump functions of caller  snmp_get_device_enterprise_oid/18:
  Jump functions of caller  snmp_get_local_ip_for_dst/17:
  Jump functions of caller  snmp_trap_header_enc/16:
  Jump functions of caller  snmp_trap_header_sum/14:
  Jump functions of caller  snmp_authfail_trap/12:
    callsite  snmp_authfail_trap/12 -> snmp_send_trap_generic/9 : 
       param 0: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
  Jump functions of caller  snmp_coldstart_trap/11:
    callsite  snmp_coldstart_trap/11 -> snmp_send_trap_generic/9 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  snmp_send_trap_specific/10:
    callsite  snmp_send_trap_specific/10 -> snmp_send_trap/8 : 
       param 0: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 1: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
       param 3: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  snmp_send_trap_generic/9:
    callsite  snmp_send_trap_generic/9 -> snmp_send_trap/8 : 
       param 0: CONST: &oid
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  snmp_send_trap/8:
    callsite  snmp_send_trap/8 -> snmp_trap_varbind_enc.isra.0/39 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  snmp_send_trap/8 -> snmp_trap_header_enc/16 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_send_trap/8 -> snmp_trap_header_sum/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  snmp_send_trap/8 -> snmp_trap_varbind_sum.isra.0/38 : 
       param 0: UNKNOWN
         value: 0x2, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  snmp_get_auth_traps_enabled/7:
  Jump functions of caller  snmp_set_auth_traps_enabled/6:
  Jump functions of caller  snmp_trap_dst_ip_set/5:
  Jump functions of caller  snmp_trap_dst_enable/4:

 Propagating constants:

Not considering snmp_authfail_trap for cloning; -fipa-cp-clone disabled.
Not considering snmp_coldstart_trap for cloning; -fipa-cp-clone disabled.
Not considering snmp_send_trap_specific for cloning; -fipa-cp-clone disabled.
Not considering snmp_send_trap_generic for cloning; -fipa-cp-clone disabled.
Not considering snmp_send_trap for cloning; -fipa-cp-clone disabled.
Not considering snmp_get_auth_traps_enabled for cloning; -fipa-cp-clone disabled.
Not considering snmp_set_auth_traps_enabled for cloning; -fipa-cp-clone disabled.
Not considering snmp_trap_dst_ip_set for cloning; -fipa-cp-clone disabled.
Not considering snmp_trap_dst_enable for cloning; -fipa-cp-clone disabled.

overall_size: 523, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: snmp_trap_varbind_enc.isra.0/39:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_pbuf_stream * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: snmp_trap_varbind_sum.isra.0/38:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x2, mask = 0xfffffffc
         u16_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: snmp_trap_header_enc/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_msg_trap * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_pbuf_stream * ~[0B, 0B]
        AGGS VARIABLE
  Node: snmp_trap_header_sum/14:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_msg_trap * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: snmp_authfail_trap/12:
  Node: snmp_coldstart_trap/11:
  Node: snmp_send_trap_specific/10:
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
  Node: snmp_send_trap_generic/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: snmp_send_trap/8:
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
  Node: snmp_get_auth_traps_enabled/7:
  Node: snmp_set_auth_traps_enabled/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: snmp_trap_dst_ip_set/5:
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
  Node: snmp_trap_dst_enable/4:
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

Propagated bits info for function snmp_trap_varbind_enc.isra.0/39:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_trap_varbind_sum.isra.0/38:
 param 0: value = 0x2, mask = 0xfffffffc
Propagated bits info for function snmp_trap_header_enc/16:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_trap_header_sum/14:
 param 0: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

snmp_trap_varbind_enc.isra.0/39 (snmp_trap_varbind_enc.isra.0) @06244380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:116070667 (estimated locally) body local optimize_size
  Called by: snmp_send_trap/8 (86338494 (estimated locally),0.16 per call) 
  Calls: snmp_append_outbound_varbind/36 (1014686024 (estimated locally),8.74 per call) snmp_ans1_enc_tlv/32 (116070667 (estimated locally),1.00 per call) 
snmp_trap_varbind_sum.isra.0/38 (snmp_trap_varbind_sum.isra.0) @05f548c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: snmp_send_trap/8 (161470906 (estimated locally),0.30 per call) 
  Calls: snmp_asn1_enc_length_cnt/26 (118111601 (estimated locally),1.00 per call) snmp_varbind_length/25 (955630223 (estimated locally),8.09 per call) 
oid.7161/37 (oid) @0616aa20
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: snmp_send_trap_generic/9 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
snmp_append_outbound_varbind/36 (snmp_append_outbound_varbind) @06156e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_varbind_enc.isra.0/39 (1014686024 (estimated locally),8.74 per call) 
  Calls: 
snmp_asn1_enc_oid/35 (snmp_asn1_enc_oid) @06156c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_header_enc/16 (926166833 (estimated locally),0.86 per call) 
  Calls: 
snmp_asn1_enc_raw/34 (snmp_asn1_enc_raw) @06156b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_header_enc/16 (592270221 (estimated locally),0.55 per call) snmp_trap_header_enc/16 (305108901 (estimated locally),0.28 per call) snmp_trap_header_enc/16 (986752130 (estimated locally),0.92 per call) 
  Calls: 
snmp_asn1_enc_s32t/33 (snmp_asn1_enc_s32t) @06156a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_header_enc/16 (799044379 (estimated locally),0.74 per call) snmp_trap_header_enc/16 (833521486 (estimated locally),0.78 per call) snmp_trap_header_enc/16 (869486210 (estimated locally),0.81 per call) snmp_trap_header_enc/16 (1029328438 (estimated locally),0.96 per call) 
  Calls: 
snmp_ans1_enc_tlv/32 (snmp_ans1_enc_tlv) @061569a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_varbind_enc.isra.0/39 (116070667 (estimated locally),1.00 per call) snmp_trap_header_enc/16 (816100887 (estimated locally),0.76 per call) snmp_trap_header_enc/16 (851313948 (estimated locally),0.79 per call) snmp_trap_header_enc/16 (888046380 (estimated locally),0.83 per call) snmp_trap_header_enc/16 (604912901 (estimated locally),0.56 per call) snmp_trap_header_enc/16 (311621797 (estimated locally),0.29 per call) snmp_trap_header_enc/16 (945936914 (estimated locally),0.88 per call) snmp_trap_header_enc/16 (966129011 (estimated locally),0.90 per call) snmp_trap_header_enc/16 (1007815473 (estimated locally),0.94 per call) snmp_trap_header_enc/16 (1051300621 (estimated locally),0.98 per call) snmp_trap_header_enc/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
strlen/31 (strlen) @06156620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
snmp_community_trap/30 (snmp_community_trap) @06157f78
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: snmp_trap_header_sum/14 (read)snmp_trap_header_enc/16 (read)
  Availability: not_available
  Varpool flags:
snmp_asn1_enc_oid_cnt/29 (snmp_asn1_enc_oid_cnt) @06156540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_header_enc/16 (945936914 (estimated locally),0.88 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
snmp_asn1_enc_s32t_cnt/28 (snmp_asn1_enc_s32t_cnt) @06156460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_header_enc/16 (816100887 (estimated locally),0.76 per call) snmp_trap_header_enc/16 (851313948 (estimated locally),0.79 per call) snmp_trap_header_enc/16 (888046380 (estimated locally),0.83 per call) snmp_trap_header_enc/16 (1051300621 (estimated locally),0.98 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
snmp_asn1_enc_u32t_cnt/27 (snmp_asn1_enc_u32t_cnt) @06156380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
snmp_asn1_enc_length_cnt/26 (snmp_asn1_enc_length_cnt) @061561c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_header_sum/14 (1073741824 (estimated locally),1.00 per call) snmp_trap_varbind_sum.isra.0/38 (118111601 (estimated locally),1.00 per call) 
  Calls: 
snmp_varbind_length/25 (snmp_varbind_length) @061560e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_trap_varbind_sum.isra.0/38 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pbuf_free/24 (pbuf_free) @06130460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_send_trap/8 (86338494 (estimated locally),0.16 per call) 
  Calls: 
snmp_sendto/23 (snmp_sendto) @06130ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_send_trap/8 (86338494 (estimated locally),0.16 per call) 
  Calls: 
snmp_stats/22 (snmp_stats) @06142e10
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: snmp_send_trap/8 (read)snmp_send_trap/8 (write)snmp_send_trap/8 (read)snmp_send_trap/8 (write)
  Availability: not_available
  Varpool flags:
snmp_pbuf_stream_init/21 (snmp_pbuf_stream_init) @06130d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_send_trap/8 (86338494 (estimated locally),0.16 per call) 
  Calls: 
pbuf_alloc/20 (pbuf_alloc) @06130c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_send_trap/8 (161470906 (estimated locally),0.30 per call) 
  Calls: 
sys_now/19 (sys_now) @06130b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_send_trap/8 (161470906 (estimated locally),0.30 per call) 
  Calls: 
snmp_get_device_enterprise_oid/18 (snmp_get_device_enterprise_oid) @06130a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_send_trap/8 (28144379 (estimated locally),0.05 per call) 
  Calls: 
snmp_get_local_ip_for_dst/17 (snmp_get_local_ip_for_dst) @061309a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_send_trap/8 (241001352 (estimated locally),0.45 per call) 
  Calls: 
snmp_trap_header_enc/16 (snmp_trap_header_enc) @060fc2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_community_trap/30 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: snmp_send_trap/8 (86338494 (estimated locally),0.16 per call) 
  Calls: snmp_asn1_enc_s32t/33 (799044379 (estimated locally),0.74 per call) snmp_ans1_enc_tlv/32 (816100887 (estimated locally),0.76 per call) snmp_asn1_enc_s32t_cnt/28 (816100887 (estimated locally),0.76 per call) snmp_asn1_enc_s32t/33 (833521486 (estimated locally),0.78 per call) snmp_ans1_enc_tlv/32 (851313948 (estimated locally),0.79 per call) snmp_asn1_enc_s32t_cnt/28 (851313948 (estimated locally),0.79 per call) snmp_asn1_enc_s32t/33 (869486210 (estimated locally),0.81 per call) snmp_ans1_enc_tlv/32 (888046380 (estimated locally),0.83 per call) snmp_asn1_enc_s32t_cnt/28 (888046380 (estimated locally),0.83 per call) snmp_asn1_enc_raw/34 (592270221 (estimated locally),0.55 per call) snmp_ans1_enc_tlv/32 (604912901 (estimated locally),0.56 per call) snmp_asn1_enc_raw/34 (305108901 (estimated locally),0.28 per call) snmp_ans1_enc_tlv/32 (311621797 (estimated locally),0.29 per call) snmp_asn1_enc_oid/35 (926166833 (estimated locally),0.86 per call) snmp_ans1_enc_tlv/32 (945936914 (estimated locally),0.88 per call) snmp_asn1_enc_oid_cnt/29 (945936914 (estimated locally),0.88 per call) snmp_ans1_enc_tlv/32 (966129011 (estimated locally),0.90 per call) snmp_asn1_enc_raw/34 (986752130 (estimated locally),0.92 per call) snmp_ans1_enc_tlv/32 (1007815473 (estimated locally),0.94 per call) snmp_asn1_enc_s32t/33 (1029328438 (estimated locally),0.96 per call) snmp_ans1_enc_tlv/32 (1051300621 (estimated locally),0.98 per call) snmp_asn1_enc_s32t_cnt/28 (1051300621 (estimated locally),0.98 per call) snmp_ans1_enc_tlv/32 (1073741824 (estimated locally),1.00 per call) 
snmp_trap_header_sum/14 (snmp_trap_header_sum) @060fc620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_community_trap/30 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: snmp_send_trap/8 (161470906 (estimated locally),0.30 per call) 
  Calls: snmp_asn1_enc_length_cnt/26 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_length_cnt/26 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_s32t_cnt/28 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_length_cnt/26 (1073741824 (estimated locally),1.00 per call) strlen/31 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_length_cnt/26 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_length_cnt/26 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_oid_cnt/29 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_length_cnt/26 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_length_cnt/26 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_s32t_cnt/28 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_length_cnt/26 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_s32t_cnt/28 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_length_cnt/26 (1073741824 (estimated locally),1.00 per call) snmp_asn1_enc_u32t_cnt/27 (1073741824 (estimated locally),1.00 per call) 
snmp_authfail_trap/12 (snmp_authfail_trap) @060e9d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_auth_traps_enabled/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: snmp_send_trap_generic/9 (354334802 (estimated locally),0.33 per call) 
snmp_coldstart_trap/11 (snmp_coldstart_trap) @060e92a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: snmp_send_trap_generic/9 (1073741824 (estimated locally),1.00 per call) 
snmp_send_trap_specific/10 (snmp_send_trap_specific) @060e9ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: snmp_send_trap/8 (1073741824 (estimated locally),1.00 per call) 
snmp_send_trap_generic/9 (snmp_send_trap_generic) @060e9c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: oid.7161/37 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: snmp_authfail_trap/12 (354334802 (estimated locally),0.33 per call) snmp_coldstart_trap/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: snmp_send_trap/8 (1073741824 (estimated locally),1.00 per call) 
snmp_send_trap/8 (snmp_send_trap) @060e99a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_traps_handle/1 (read)snmp_stats/22 (read)snmp_stats/22 (write)snmp_stats/22 (read)snmp_stats/22 (write)snmp_traps_handle/1 (read)trap_dst/2 (addr)
  Referring: 
  Availability: available
  Function flags: count:536870910 (estimated locally) body optimize_size
  Called by: snmp_send_trap_specific/10 (1073741824 (estimated locally),1.00 per call) snmp_send_trap_generic/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_free/24 (86338494 (estimated locally),0.16 per call) snmp_sendto/23 (86338494 (estimated locally),0.16 per call) snmp_trap_varbind_enc.isra.0/39 (86338494 (estimated locally),0.16 per call) snmp_trap_header_enc/16 (86338494 (estimated locally),0.16 per call) snmp_pbuf_stream_init/21 (86338494 (estimated locally),0.16 per call) pbuf_alloc/20 (161470906 (estimated locally),0.30 per call) snmp_trap_header_sum/14 (161470906 (estimated locally),0.30 per call) snmp_trap_varbind_sum.isra.0/38 (161470906 (estimated locally),0.30 per call) sys_now/19 (161470906 (estimated locally),0.30 per call) snmp_get_device_enterprise_oid/18 (28144379 (estimated locally),0.05 per call) snmp_get_local_ip_for_dst/17 (241001352 (estimated locally),0.45 per call) 
snmp_get_auth_traps_enabled/7 (snmp_get_auth_traps_enabled) @060e91c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_auth_traps_enabled/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
snmp_set_auth_traps_enabled/6 (snmp_set_auth_traps_enabled) @060df620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_auth_traps_enabled/3 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
snmp_trap_dst_ip_set/5 (snmp_trap_dst_ip_set) @060dfee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: trap_dst/2 (write)trap_dst/2 (write)trap_dst/2 (write)trap_dst/2 (write)trap_dst/2 (write)trap_dst/2 (write)trap_dst/2 (write)trap_dst/2 (write)trap_dst/2 (write)trap_dst/2 (write)trap_dst/2 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
snmp_trap_dst_enable/4 (snmp_trap_dst_enable) @060df540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: trap_dst/2 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
snmp_auth_traps_enabled/3 (snmp_auth_traps_enabled) @060d9708
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: snmp_set_auth_traps_enabled/6 (write)snmp_get_auth_traps_enabled/7 (read)snmp_authfail_trap/12 (read)
  Availability: available
  Varpool flags: initialized
trap_dst/2 (trap_dst) @060d9678
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: snmp_trap_dst_enable/4 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_trap_dst_ip_set/5 (write)snmp_send_trap/8 (addr)
  Availability: available
  Varpool flags:
snmp_traps_handle/1 (snmp_traps_handle) @060d9558
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: snmp_send_trap/8 (read)snmp_send_trap/8 (read)
  Availability: available
  Varpool flags:

;; Function snmp_trap_dst_enable (snmp_trap_dst_enable, funcdef_no=1, decl_uid=6687, cgraph_uid=2, symbol_order=4)

Modification phase of node snmp_trap_dst_enable/4
snmp_trap_dst_enable (u8_t dst_idx, u8_t enable)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (dst_idx_2(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  trap_dst[0].enable = enable_4(D);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function snmp_trap_dst_ip_set (snmp_trap_dst_ip_set, funcdef_no=2, decl_uid=6690, cgraph_uid=3, symbol_order=5)

Modification phase of node snmp_trap_dst_ip_set/5
snmp_trap_dst_ip_set (u8_t dst_idx, const struct ip_addr_t * dst)
{
  unsigned char _1;
  const long unsigned int iftmp.0_7;
  const long unsigned int iftmp.1_9;
  const long unsigned int iftmp.2_11;
  const long unsigned int iftmp.3_13;
  u8_t iftmp.4_15;
  const long unsigned int iftmp.5_17;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (dst_idx_3(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = dst_5(D)->type;
  trap_dst[0].dip.type = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_1 == 6)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 182536110]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iftmp.0_7 = dst_5(D)->u_addr.ip6.addr[0];
  trap_dst[0].dip.u_addr.ip6.addr[0] = iftmp.0_7;
  # DEBUG BEGIN_STMT
  iftmp.1_9 = dst_5(D)->u_addr.ip6.addr[1];
  trap_dst[0].dip.u_addr.ip6.addr[1] = iftmp.1_9;
  # DEBUG BEGIN_STMT
  iftmp.2_11 = dst_5(D)->u_addr.ip6.addr[2];
  trap_dst[0].dip.u_addr.ip6.addr[2] = iftmp.2_11;
  # DEBUG BEGIN_STMT
  iftmp.3_13 = dst_5(D)->u_addr.ip6.addr[3];
  trap_dst[0].dip.u_addr.ip6.addr[3] = iftmp.3_13;
  # DEBUG BEGIN_STMT
  iftmp.4_15 = dst_5(D)->u_addr.ip6.zone;
  trap_dst[0].dip.u_addr.ip6.zone = iftmp.4_15;
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  iftmp.5_17 = dst_5(D)->u_addr.ip4.addr;
  trap_dst[0].dip.u_addr.ip4.addr = iftmp.5_17;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  trap_dst[0].dip.u_addr.ip6.addr[3] = 0;
  trap_dst[0].dip.u_addr.ip6.addr[2] = 0;
  trap_dst[0].dip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  trap_dst[0].dip.u_addr.ip6.zone = 0;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function snmp_set_auth_traps_enabled (snmp_set_auth_traps_enabled, funcdef_no=3, decl_uid=6702, cgraph_uid=4, symbol_order=6)

Modification phase of node snmp_set_auth_traps_enabled/6
snmp_set_auth_traps_enabled (u8_t enable)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  snmp_auth_traps_enabled = enable_2(D);
  return;

}



;; Function snmp_get_auth_traps_enabled (snmp_get_auth_traps_enabled, funcdef_no=4, decl_uid=6704, cgraph_uid=5, symbol_order=7)

Modification phase of node snmp_get_auth_traps_enabled/7
snmp_get_auth_traps_enabled ()
{
  u8_t _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = snmp_auth_traps_enabled;
  return _2;

}



;; Function snmp_send_trap (snmp_send_trap, funcdef_no=5, decl_uid=6700, cgraph_uid=6, symbol_order=8)

Modification phase of node snmp_send_trap/8
snmp_send_trap (const struct snmp_obj_id * eoid, s32_t generic_trap, s32_t specific_trap, struct snmp_varbind * varbinds)
{
  struct snmp_pbuf_stream pbuf_stream;
  err_t err;
  u16_t tot_len;
  u16_t i;
  struct pbuf * p;
  struct snmp_trap_dst * td;
  struct snmp_msg_trap trap_msg;
  unsigned char _1;
  struct ip_addr_t * _2;
  unsigned char _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  void * snmp_traps_handle.10_9;
  unsigned char _10;
  const struct snmp_obj_id * _11;
  long unsigned int generic_trap.11_12;
  long unsigned int specific_trap.12_13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  void * snmp_traps_handle.13_20;
  _Bool iftmp.7_25;
  int iftmp.8_26;
  int iftmp.9_27;
  _Bool iftmp.7_36;
  _Bool iftmp.7_37;
  short unsigned int _66;

  <bb 2> [local count: 536870910]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  trap_msg.snmp_version = 0;
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  # DEBUG td => &trap_dst[0]
  goto <bb 25>; [100.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _1 = td_21->enable;
  if (_1 != 0)
    goto <bb 4>; [67.00%]
  else
    goto <bb 24>; [33.00%]

  <bb 4> [local count: 359703511]:
  _2 = &td_21->dip;
  _3 = td_21->dip.type;
  if (_3 == 6)
    goto <bb 5>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 5> [local count: 122299194]:
  _4 = td_21->dip.u_addr.ip6.addr[0];
  if (_4 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 61149597]:
  _5 = td_21->dip.u_addr.ip6.addr[1];
  if (_5 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 30574798]:
  _6 = td_21->dip.u_addr.ip6.addr[2];
  if (_6 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 15287399]:
  _7 = td_21->dip.u_addr.ip6.addr[3];
  if (_7 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 7643700]:

  <bb 10> [local count: 122299194]:
  # iftmp.8_26 = PHI <1(6), 0(9), 1(5), 1(8), 1(7)>
  iftmp.7_36 = (_Bool) iftmp.8_26;
  goto <bb 14>; [100.00%]

  <bb 11> [local count: 237404317]:
  _8 = td_21->dip.u_addr.ip4.addr;
  if (_8 != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 118702159]:

  <bb 13> [local count: 237404317]:
  # iftmp.9_27 = PHI <1(11), 0(12)>
  iftmp.7_37 = (_Bool) iftmp.9_27;

  <bb 14> [local count: 359703511]:
  # iftmp.7_25 = PHI <iftmp.7_36(10), iftmp.7_37(13)>
  if (iftmp.7_25 != 0)
    goto <bb 15>; [67.00%]
  else
    goto <bb 24>; [33.00%]

  <bb 15> [local count: 241001352]:
  # DEBUG BEGIN_STMT
  snmp_traps_handle.10_9 = snmp_traps_handle;
  _10 = snmp_get_local_ip_for_dst (snmp_traps_handle.10_9, _2, &trap_msg.sip);
  if (_10 != 0)
    goto <bb 16>; [67.00%]
  else
    goto <bb 24>; [33.00%]

  <bb 16> [local count: 161470906]:
  # DEBUG BEGIN_STMT
  if (eoid_39(D) == 0B)
    goto <bb 17>; [17.43%]
  else
    goto <bb 18>; [82.57%]

  <bb 17> [local count: 28144379]:
  # DEBUG BEGIN_STMT
  _11 = snmp_get_device_enterprise_oid ();
  trap_msg.enterprise = _11;
  goto <bb 19>; [100.00%]

  <bb 18> [local count: 133326527]:
  # DEBUG BEGIN_STMT
  trap_msg.enterprise = eoid_39(D);

  <bb 19> [local count: 161470906]:
  # DEBUG BEGIN_STMT
  generic_trap.11_12 = (long unsigned int) generic_trap_43(D);
  trap_msg.gen_trap = generic_trap.11_12;
  # DEBUG BEGIN_STMT
  if (generic_trap_43(D) == 6)
    goto <bb 20>; [34.00%]
  else
    goto <bb 21>; [66.00%]

  <bb 20> [local count: 54900108]:
  # DEBUG BEGIN_STMT
  specific_trap.12_13 = (long unsigned int) specific_trap_46(D);
  trap_msg.spc_trap = specific_trap.12_13;
  goto <bb 22>; [100.00%]

  <bb 21> [local count: 106570798]:
  # DEBUG BEGIN_STMT
  trap_msg.spc_trap = 0;

  <bb 22> [local count: 161470906]:
  # DEBUG BEGIN_STMT
  _14 = sys_now ();
  _15 = _14 / 10;
  trap_msg.ts = _15;
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => &trap_msg
  tot_len_52 = snmp_trap_varbind_sum.isra.0 (&MEM[(short unsigned int *)&trap_msg + 50B], varbinds_50(D));
  # DEBUG tot_len => tot_len_52
  # DEBUG BEGIN_STMT
  tot_len_54 = snmp_trap_header_sum (&trap_msg, tot_len_52);
  # DEBUG tot_len => tot_len_54
  # DEBUG BEGIN_STMT
  p_56 = pbuf_alloc (74, tot_len_54, 640);
  # DEBUG p => p_56
  # DEBUG BEGIN_STMT
  if (p_56 != 0B)
    goto <bb 23>; [53.47%]
  else
    goto <bb 24>; [46.53%]

  <bb 23> [local count: 86338494]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  snmp_pbuf_stream_init (&pbuf_stream, p_56, 0, tot_len_54);
  # DEBUG BEGIN_STMT
  snmp_trap_header_enc (&trap_msg, &pbuf_stream);
  # DEBUG BEGIN_STMT
  _66 = MEM[(short unsigned int *)&trap_msg + 50B];
  # DEBUG D#2 => &trap_msg
  snmp_trap_varbind_enc.isra.0 (_66, &pbuf_stream, varbinds_50(D));
  # DEBUG BEGIN_STMT
  _16 = snmp_stats.outtraps;
  _17 = _16 + 1;
  snmp_stats.outtraps = _17;
  # DEBUG BEGIN_STMT
  _18 = snmp_stats.outpkts;
  _19 = _18 + 1;
  snmp_stats.outpkts = _19;
  # DEBUG BEGIN_STMT
  snmp_traps_handle.13_20 = snmp_traps_handle;
  snmp_sendto (snmp_traps_handle.13_20, p_56, _2, 162);
  # DEBUG BEGIN_STMT
  pbuf_free (p_56);
  pbuf_stream ={v} {CLOBBER};

  <bb 24> [local count: 536870913]:
  # err_23 = PHI <err_24(3), err_24(14), -1(22), -4(15), err_24(23)>
  # DEBUG err => err_23
  # DEBUG BEGIN_STMT
  # DEBUG i => 1
  td_65 = td_21 + 28;
  # DEBUG td => td_65

  <bb 25> [local count: 1073741824]:
  # td_21 = PHI <&trap_dst[0](2), td_65(24)>
  # i_22 = PHI <0(2), 1(24)>
  # err_24 = PHI <0(2), err_23(24)>
  # DEBUG err => err_24
  # DEBUG i => i_22
  # DEBUG td => td_21
  # DEBUG BEGIN_STMT
  if (i_22 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 26>; [50.00%]

  <bb 26> [local count: 536870913]:
  # err_32 = PHI <err_24(25)>
  # DEBUG BEGIN_STMT
  trap_msg ={v} {CLOBBER};
  return err_32;

}



;; Function snmp_send_trap_generic (snmp_send_trap_generic, funcdef_no=6, decl_uid=6692, cgraph_uid=7, symbol_order=9)

Modification phase of node snmp_send_trap_generic/9
snmp_send_trap_generic (s32_t generic_trap)
{
  static const struct snmp_obj_id oid = {.len=7, .id={1, 3, 6, 1, 2, 1, 11}};
  err_t _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = snmp_send_trap (&oid, generic_trap_2(D), 0, 0B);
  return _4;

}



;; Function snmp_send_trap_specific (snmp_send_trap_specific, funcdef_no=7, decl_uid=6695, cgraph_uid=8, symbol_order=10)

Modification phase of node snmp_send_trap_specific/10
snmp_send_trap_specific (s32_t specific_trap, struct snmp_varbind * varbinds)
{
  err_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = snmp_send_trap (0B, 6, specific_trap_2(D), varbinds_3(D));
  return _5;

}



;; Function snmp_coldstart_trap (snmp_coldstart_trap, funcdef_no=8, decl_uid=6730, cgraph_uid=9, symbol_order=11)

Modification phase of node snmp_coldstart_trap/11
snmp_coldstart_trap ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  snmp_send_trap_generic (0);
  return;

}



;; Function snmp_authfail_trap (snmp_authfail_trap, funcdef_no=9, decl_uid=6732, cgraph_uid=10, symbol_order=12)

Modification phase of node snmp_authfail_trap/12
snmp_authfail_trap ()
{
  unsigned char snmp_auth_traps_enabled.41_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  snmp_auth_traps_enabled.41_1 = snmp_auth_traps_enabled;
  if (snmp_auth_traps_enabled.41_1 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  snmp_send_trap_generic (4);

  <bb 4> [local count: 1073741824]:
  return;

}


