
IPA constant propagation start:
Determining dynamic type for call: _14 = udp_Table_get_cell_value_core.isra.0 (pcb_12, _11, value_13(D));
  Starting walk at: _14 = udp_Table_get_cell_value_core.isra.0 (pcb_12, _11, value_13(D));
  instance pointer: pcb_12  Outer instance pointer: pcb_5 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_oid_to_ip4 (row_oid_1(D), &ip);
Determining dynamic type for call: _14 = udp_Table_get_cell_value_core.isra.0 (pcb_12, _11, value_13(D));
  Starting walk at: _14 = udp_Table_get_cell_value_core.isra.0 (pcb_12, _11, value_13(D));
  instance pointer: value_13(D)  Outer instance pointer: value_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_oid_to_ip4 (row_oid_1(D), &ip);
Determining dynamic type for call: _25 = udp_Table_get_cell_value_core.isra.0 (_10, _33, value_22(D));
  Starting walk at: _25 = udp_Table_get_cell_value_core.isra.0 (_10, _33, value_22(D));
  instance pointer: _10  Outer instance pointer: _10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_oid_assign (row_oid_16(D), _8, _9);
  Function call may change dynamic type:snmp_next_oid_init (&state, _1, _2, &result_temp, 5);
  Function call may change dynamic type:snmp_next_oid_check (&state, &test_oid, 5, pcb_11);
  Function call may change dynamic type:snmp_ip4_to_oid (_4, &test_oid[0]);
Determining dynamic type for call: _25 = udp_Table_get_cell_value_core.isra.0 (_10, _33, value_22(D));
  Starting walk at: _25 = udp_Table_get_cell_value_core.isra.0 (_10, _33, value_22(D));
  instance pointer: value_22(D)  Outer instance pointer: value_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_oid_assign (row_oid_16(D), _8, _9);
  Function call may change dynamic type:snmp_next_oid_init (&state, _1, _2, &result_temp, 5);
  Function call may change dynamic type:snmp_next_oid_check (&state, &test_oid, 5, pcb_11);
  Function call may change dynamic type:snmp_ip4_to_oid (_4, &test_oid[0]);
Determining dynamic type for call: _7 = udp_Table_get_cell_value.part.0 (column_8(D), row_oid_4(D), value_9(D));
  Starting walk at: _7 = udp_Table_get_cell_value.part.0 (column_8(D), row_oid_4(D), value_9(D));
  instance pointer: column_8(D)  Outer instance pointer: column_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = snmp_oid_in_range (row_oid_4(D), row_oid_len_5(D), &udp_Table_oid_ranges, 5);
Determining dynamic type for call: _7 = udp_Table_get_cell_value.part.0 (column_8(D), row_oid_4(D), value_9(D));
  Starting walk at: _7 = udp_Table_get_cell_value.part.0 (column_8(D), row_oid_4(D), value_9(D));
  instance pointer: row_oid_4(D)  Outer instance pointer: row_oid_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = snmp_oid_in_range (row_oid_4(D), row_oid_len_5(D), &udp_Table_oid_ranges, 5);
Determining dynamic type for call: _7 = udp_Table_get_cell_value.part.0 (column_8(D), row_oid_4(D), value_9(D));
  Starting walk at: _7 = udp_Table_get_cell_value.part.0 (column_8(D), row_oid_4(D), value_9(D));
  instance pointer: value_9(D)  Outer instance pointer: value_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = snmp_oid_in_range (row_oid_4(D), row_oid_len_5(D), &udp_Table_oid_ranges, 5);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  udp_Table_get_cell_value.part.0/38:
    callsite  udp_Table_get_cell_value.part.0/38 -> udp_Table_get_cell_value_core.isra.0/36 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  udp_Table_get_cell_value_core.isra.0/36:
  Jump functions of caller  snmp_oid_to_ip4/34:
  Jump functions of caller  snmp_oid_in_range/33:
  Jump functions of caller  snmp_ip4_to_oid/32:
  Jump functions of caller  snmp_oid_to_ip_port/31:
  Jump functions of caller  snmp_oid_assign/30:
  Jump functions of caller  snmp_next_oid_check/29:
  Jump functions of caller  snmp_ip_port_to_oid/28:
  Jump functions of caller  snmp_next_oid_init/26:
  Jump functions of caller  snmp_table_simple_get_next_instance/25:
  Jump functions of caller  snmp_table_simple_get_instance/24:
  Jump functions of caller  snmp_scalar_get_next_instance/22:
  Jump functions of caller  snmp_scalar_get_instance/21:
  Jump functions of caller  udp_Table_get_next_cell_instance_and_value/8:
    callsite  udp_Table_get_next_cell_instance_and_value/8 -> udp_Table_get_cell_value_core.isra.0/36 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  udp_Table_get_cell_value/7:
    callsite  udp_Table_get_cell_value/7 -> udp_Table_get_cell_value.part.0/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  udp_endpointTable_get_next_cell_instance_and_value/4:
  Jump functions of caller  udp_endpointTable_get_cell_value/3:
  Jump functions of caller  udp_get_value/1:

 Propagating constants:

Not considering udp_Table_get_next_cell_instance_and_value for cloning; -fipa-cp-clone disabled.
Not considering udp_Table_get_cell_value for cloning; -fipa-cp-clone disabled.
Not considering udp_endpointTable_get_next_cell_instance_and_value for cloning; -fipa-cp-clone disabled.
Not considering udp_endpointTable_get_cell_value for cloning; -fipa-cp-clone disabled.
Not considering udp_get_value for cloning; -fipa-cp-clone disabled.

overall_size: 287, max_new_size: 11001
 - context independent values, size: 43, time_benefit: 1.000000
 - context independent values, size: 16, time_benefit: 1.000000
 - context independent values, size: 47, time_benefit: 1.000000
 - context independent values, size: 108, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: udp_Table_get_cell_value.part.0/38:
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
  Node: udp_Table_get_cell_value_core.isra.0/36:
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
  Node: udp_Table_get_next_cell_instance_and_value/8:
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
  Node: udp_Table_get_cell_value/7:
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
  Node: udp_endpointTable_get_next_cell_instance_and_value/4:
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
  Node: udp_endpointTable_get_cell_value/3:
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
  Node: udp_get_value/1:
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


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

udp_Table_get_cell_value.part.0/38 (udp_Table_get_cell_value.part.0) @05fbc8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: udp_pcbs/27 (read)
  Referring: 
  Availability: local
  Function flags: count:68543114 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: udp_Table_get_cell_value/7 (68543115 (estimated locally),0.64 per call) 
  Calls: snmp_oid_to_ip4/34 (68543114 (estimated locally),1.00 per call) udp_Table_get_cell_value_core.isra.0/36 (9487314 (estimated locally),0.14 per call) 
udp_Table_get_cell_value_core.isra.0/36 (udp_Table_get_cell_value_core.isra.0) @063151c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: udp_Table_get_cell_value.part.0/38 (9487314 (estimated locally),0.14 per call) udp_Table_get_next_cell_instance_and_value/8 (56421912 (estimated locally),0.48 per call) 
  Calls: 
snmp_oid_to_ip4/34 (snmp_oid_to_ip4) @06217620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_Table_get_cell_value.part.0/38 (68543114 (estimated locally),1.00 per call) 
  Calls: 
snmp_oid_in_range/33 (snmp_oid_in_range) @06217540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_Table_get_cell_value/7 (107148842 (estimated locally),1.00 per call) 
  Calls: 
snmp_ip4_to_oid/32 (snmp_ip4_to_oid) @062172a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_Table_get_next_cell_instance_and_value/8 (315357973 (estimated locally),2.67 per call) 
  Calls: 
snmp_oid_to_ip_port/31 (snmp_oid_to_ip_port) @062170e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_endpointTable_get_cell_value/3 (124257949 (estimated locally),0.64 per call) udp_endpointTable_get_cell_value/3 (194244097 (estimated locally),1.00 per call) 
  Calls: 
snmp_oid_assign/30 (snmp_oid_assign) @061f4c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_Table_get_next_cell_instance_and_value/8 (56421912 (estimated locally),0.48 per call) udp_endpointTable_get_next_cell_instance_and_value/4 (56421912 (estimated locally),0.48 per call) 
  Calls: 
snmp_next_oid_check/29 (snmp_next_oid_check) @061f4b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_Table_get_next_cell_instance_and_value/8 (315357973 (estimated locally),2.67 per call) udp_endpointTable_get_next_cell_instance_and_value/4 (955630223 (estimated locally),8.09 per call) 
  Calls: 
snmp_ip_port_to_oid/28 (snmp_ip_port_to_oid) @061f4a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_endpointTable_get_next_cell_instance_and_value/4 (955630223 (estimated locally),8.09 per call) udp_endpointTable_get_next_cell_instance_and_value/4 (955630223 (estimated locally),8.09 per call) 
  Calls: 
udp_pcbs/27 (udp_pcbs) @061efcf0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: udp_endpointTable_get_cell_value/3 (read)udp_Table_get_next_cell_instance_and_value/8 (read)udp_endpointTable_get_next_cell_instance_and_value/4 (read)udp_Table_get_cell_value.part.0/38 (read)
  Availability: not_available
  Varpool flags:
snmp_next_oid_init/26 (snmp_next_oid_init) @061f49a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_Table_get_next_cell_instance_and_value/8 (118111602 (estimated locally),1.00 per call) udp_endpointTable_get_next_cell_instance_and_value/4 (118111600 (estimated locally),1.00 per call) 
  Calls: 
snmp_table_simple_get_next_instance/25 (snmp_table_simple_get_next_instance) @061f47e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: udp_endpointTable/18 (addr)udp_Table/16 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
snmp_table_simple_get_instance/24 (snmp_table_simple_get_instance) @061f4700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: udp_endpointTable/18 (addr)udp_Table/16 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
lwip_stats/23 (lwip_stats) @061ef948
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: udp_get_value/1 (read)udp_get_value/1 (read)udp_get_value/1 (read)udp_get_value/1 (read)udp_get_value/1 (read)udp_get_value/1 (read)
  Availability: not_available
  Varpool flags:
snmp_scalar_get_next_instance/22 (snmp_scalar_get_next_instance) @061f41c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: udp_HCOutDatagrams/14 (addr)udp_HCInDatagrams/13 (addr)udp_outDatagrams/12 (addr)udp_inErrors/11 (addr)udp_noPorts/10 (addr)udp_inDatagrams/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
snmp_scalar_get_instance/21 (snmp_scalar_get_instance) @061f40e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: udp_HCOutDatagrams/14 (addr)udp_HCInDatagrams/13 (addr)udp_outDatagrams/12 (addr)udp_inErrors/11 (addr)udp_noPorts/10 (addr)udp_inDatagrams/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
snmp_mib2_udp_root/20 (snmp_mib2_udp_root) @061ef3f0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: udp_nodes/19 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_nodes/19 (udp_nodes) @061ef2d0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: udp_inDatagrams/9 (addr)udp_noPorts/10 (addr)udp_inErrors/11 (addr)udp_outDatagrams/12 (addr)udp_Table/16 (addr)udp_endpointTable/18 (addr)udp_HCInDatagrams/13 (addr)udp_HCOutDatagrams/14 (addr)
  Referring: snmp_mib2_udp_root/20 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_endpointTable/18 (udp_endpointTable) @061ef1f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_table_simple_get_instance/24 (addr)snmp_table_simple_get_next_instance/25 (addr)udp_endpointTable_columns/17 (addr)udp_endpointTable_get_cell_value/3 (addr)udp_endpointTable_get_next_cell_instance_and_value/4 (addr)
  Referring: udp_nodes/19 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_endpointTable_columns/17 (udp_endpointTable_columns) @061ef120
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: udp_endpointTable/18 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_Table/16 (udp_Table) @061ef090
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_table_simple_get_instance/24 (addr)snmp_table_simple_get_next_instance/25 (addr)udp_Table_columns/15 (addr)udp_Table_get_cell_value/7 (addr)udp_Table_get_next_cell_instance_and_value/8 (addr)
  Referring: udp_nodes/19 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_Table_columns/15 (udp_Table_columns) @061aaf78
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: udp_Table/16 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_HCOutDatagrams/14 (udp_HCOutDatagrams) @061aaee8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_scalar_get_instance/21 (addr)snmp_scalar_get_next_instance/22 (addr)udp_get_value/1 (addr)
  Referring: udp_nodes/19 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_HCInDatagrams/13 (udp_HCInDatagrams) @061aae10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_scalar_get_instance/21 (addr)snmp_scalar_get_next_instance/22 (addr)udp_get_value/1 (addr)
  Referring: udp_nodes/19 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_outDatagrams/12 (udp_outDatagrams) @061aad38
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_scalar_get_instance/21 (addr)snmp_scalar_get_next_instance/22 (addr)udp_get_value/1 (addr)
  Referring: udp_nodes/19 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_inErrors/11 (udp_inErrors) @061aac60
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_scalar_get_instance/21 (addr)snmp_scalar_get_next_instance/22 (addr)udp_get_value/1 (addr)
  Referring: udp_nodes/19 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_noPorts/10 (udp_noPorts) @061aab88
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_scalar_get_instance/21 (addr)snmp_scalar_get_next_instance/22 (addr)udp_get_value/1 (addr)
  Referring: udp_nodes/19 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_inDatagrams/9 (udp_inDatagrams) @061aaab0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_scalar_get_instance/21 (addr)snmp_scalar_get_next_instance/22 (addr)udp_get_value/1 (addr)
  Referring: udp_nodes/19 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_Table_get_next_cell_instance_and_value/8 (udp_Table_get_next_cell_instance_and_value) @061e6620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: udp_pcbs/27 (read)
  Referring: udp_Table/16 (addr)
  Availability: available
  Function flags: count:118111602 (estimated locally) body optimize_size
  Called by: 
  Calls: udp_Table_get_cell_value_core.isra.0/36 (56421912 (estimated locally),0.48 per call) snmp_oid_assign/30 (56421912 (estimated locally),0.48 per call) snmp_next_oid_check/29 (315357973 (estimated locally),2.67 per call) snmp_ip4_to_oid/32 (315357973 (estimated locally),2.67 per call) snmp_next_oid_init/26 (118111602 (estimated locally),1.00 per call) 
udp_Table_get_cell_value/7 (udp_Table_get_cell_value) @061beee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: udp_Table_oid_ranges/5 (addr)
  Referring: udp_Table/16 (addr)
  Availability: available
  Function flags: count:107148842 (estimated locally) body optimize_size
  Called by: 
  Calls: udp_Table_get_cell_value.part.0/38 (68543115 (estimated locally),0.64 per call) snmp_oid_in_range/33 (107148842 (estimated locally),1.00 per call) 
udp_Table_oid_ranges/5 (udp_Table_oid_ranges) @061aa798
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: udp_Table_get_cell_value/7 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
udp_endpointTable_get_next_cell_instance_and_value/4 (udp_endpointTable_get_next_cell_instance_and_value) @061be2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: udp_pcbs/27 (read)
  Referring: udp_endpointTable/18 (addr)
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: snmp_oid_assign/30 (56421912 (estimated locally),0.48 per call) snmp_next_oid_check/29 (955630223 (estimated locally),8.09 per call) snmp_ip_port_to_oid/28 (955630223 (estimated locally),8.09 per call) snmp_ip_port_to_oid/28 (955630223 (estimated locally),8.09 per call) snmp_next_oid_init/26 (118111600 (estimated locally),1.00 per call) 
udp_endpointTable_get_cell_value/3 (udp_endpointTable_get_cell_value) @061abe00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: udp_pcbs/27 (read)
  Referring: udp_endpointTable/18 (addr)
  Availability: available
  Function flags: count:194244097 (estimated locally) body optimize_size
  Called by: 
  Calls: snmp_oid_to_ip_port/31 (124257949 (estimated locally),0.64 per call) snmp_oid_to_ip_port/31 (194244097 (estimated locally),1.00 per call) 
udp_get_value/1 (udp_get_value) @061ab1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: lwip_stats/23 (read)lwip_stats/23 (read)lwip_stats/23 (read)lwip_stats/23 (read)lwip_stats/23 (read)lwip_stats/23 (read)
  Referring: udp_HCOutDatagrams/14 (addr)udp_HCInDatagrams/13 (addr)udp_outDatagrams/12 (addr)udp_inErrors/11 (addr)udp_noPorts/10 (addr)udp_inDatagrams/9 (addr)
  Availability: available
  Function flags: count:1073419798 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function udp_get_value (udp_get_value, funcdef_no=1, decl_uid=7596, cgraph_uid=2, symbol_order=1)

Modification phase of node udp_get_value/1
udp_get_value (struct snmp_node_instance * instance, void * value)
{
  u64_t val64;
  u64_t val64;
  const struct snmp_node * _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  s16_t _9;

  <bb 2> [local count: 1073419798]:
  # DEBUG BEGIN_STMT
  # DEBUG uint_ptr => value_11(D)
  # DEBUG BEGIN_STMT
  _1 = instance_13(D)->node;
  _2 = _1->oid;
  switch (_2) <default: <L10> [14.29%], case 1: <L0> [14.29%], case 2: <L1> [14.29%], case 3: <L2> [14.29%], case 4: <L3> [14.29%], case 8: <L4> [14.29%], case 9: <L5> [14.29%]>

  <bb 3> [local count: 153391689]:
<L0>:
  # DEBUG BEGIN_STMT
  _3 = lwip_stats.mib2.udpindatagrams;
  MEM[(u32_t *)value_11(D)] = _3;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 4> [local count: 153391689]:
<L1>:
  # DEBUG BEGIN_STMT
  _4 = lwip_stats.mib2.udpnoports;
  MEM[(u32_t *)value_11(D)] = _4;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 5> [local count: 153391689]:
<L2>:
  # DEBUG BEGIN_STMT
  _5 = lwip_stats.mib2.udpinerrors;
  MEM[(u32_t *)value_11(D)] = _5;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 153391689]:
<L3>:
  # DEBUG BEGIN_STMT
  _6 = lwip_stats.mib2.udpoutdatagrams;
  MEM[(u32_t *)value_11(D)] = _6;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 153391689]:
<L4>:
  # DEBUG BEGIN_STMT
  _7 = lwip_stats.mib2.udpindatagrams;
  val64_16 = (u64_t) _7;
  # DEBUG val64 => val64_16
  # DEBUG BEGIN_STMT
  MEM[(u64_t *)value_11(D)] = val64_16;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 153391689]:
<L5>:
  # DEBUG BEGIN_STMT
  _8 = lwip_stats.mib2.udpoutdatagrams;
  val64_14 = (u64_t) _8;
  # DEBUG val64 => val64_14
  # DEBUG BEGIN_STMT
  MEM[(u64_t *)value_11(D)] = val64_14;
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  # _9 = PHI <4(3), 4(4), 4(5), 4(6), 8(7), 8(8), 0(2)>
<L10>:
  return _9;

}



;; Function udp_endpointTable_get_next_cell_instance_and_value (udp_endpointTable_get_next_cell_instance_and_value, funcdef_no=4, decl_uid=7636, cgraph_uid=5, symbol_order=4)

Modification phase of node udp_endpointTable_get_next_cell_instance_and_value/4
udp_endpointTable_get_next_cell_instance_and_value (const u32_t * column, struct snmp_obj_id * row_oid, union snmp_variant_value * value, u32_t * value_len)
{
  u8_t idx;
  u32_t test_oid[39];
  u32_t result_temp[39];
  struct snmp_next_oid_state state;
  struct udp_pcb * pcb;
  u32_t[50] * _1;
  unsigned char _2;
  struct ip_addr_t * _3;
  short unsigned int _4;
  struct ip_addr_t * _5;
  short unsigned int _6;
  int _7;
  u32_t * _8;
  int _9;
  <unnamed type> _10;
  u32_t * _11;
  unsigned char _12;
  snmp_err_t _14;
  unsigned char _27;
  unsigned char _29;
  long unsigned int _36;
  <unnamed type> _37;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &row_oid_17(D)->id;
  _2 = row_oid_17(D)->len;
  snmp_next_oid_init (&state, _1, _2, &result_temp, 39);
  # DEBUG BEGIN_STMT
  pcb_20 = udp_pcbs;
  # DEBUG pcb => pcb_20
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG idx => 0
  # DEBUG BEGIN_STMT
  _3 = &pcb_13->local_ip;
  _4 = pcb_13->local_port;
  _27 = snmp_ip_port_to_oid (_3, _4, &MEM[(void *)&test_oid]);
  # DEBUG idx => _27
  # DEBUG BEGIN_STMT
  _5 = &pcb_13->remote_ip;
  _6 = pcb_13->remote_port;
  _7 = (int) _27;
  _8 = &test_oid[_7];
  _29 = snmp_ip_port_to_oid (_5, _6, _8);
  idx_30 = _27 + _29;
  # DEBUG idx => idx_30
  # DEBUG BEGIN_STMT
  _9 = (int) idx_30;
  test_oid[_9] = 0;
  # DEBUG BEGIN_STMT
  idx_32 = idx_30 + 1;
  # DEBUG idx => idx_32
  # DEBUG BEGIN_STMT
  snmp_next_oid_check (&state, &test_oid, idx_32, 0B);
  # DEBUG BEGIN_STMT
  pcb_34 = pcb_13->next;
  # DEBUG pcb => pcb_34
  test_oid ={v} {CLOBBER};

  <bb 4> [local count: 1073741824]:
  # pcb_13 = PHI <pcb_20(2), pcb_34(3)>
  # DEBUG pcb => pcb_13
  # DEBUG BEGIN_STMT
  if (pcb_13 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  _10 = state.status;
  if (_10 == 0)
    goto <bb 6>; [47.77%]
  else
    goto <bb 9>; [52.23%]

  <bb 6> [local count: 56421912]:
  # DEBUG BEGIN_STMT
  _11 = state.next_oid;
  _12 = state.next_oid_len;
  snmp_oid_assign (row_oid_17(D), _11, _12);
  # DEBUG BEGIN_STMT
  _36 = *column_22(D);
  # DEBUG D#1 => column_22(D)
  # DEBUG D#2 => value_23(D)
  # DEBUG INLINE_ENTRY udp_endpointTable_get_cell_value_core
  # DEBUG column => D#1
  # DEBUG value => D#2
  # DEBUG BEGIN_STMT
  if (_36 == 8)
    goto <bb 7>; [48.89%]
  else
    goto <bb 8>; [51.11%]

  <bb 7> [local count: 27584673]:
<L7>:
  # DEBUG BEGIN_STMT
  MEM[(u32_t *)value_23(D)] = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 56421912]:
  # _37 = PHI <241(6), 0(7)>

  <bb 9> [local count: 118111601]:
  # _14 = PHI <_37(8), 241(5)>
  state ={v} {CLOBBER};
  result_temp ={v} {CLOBBER};
  return _14;

}



;; Function udp_endpointTable_get_cell_value (udp_endpointTable_get_cell_value, funcdef_no=3, decl_uid=7621, cgraph_uid=4, symbol_order=3)

Modification phase of node udp_endpointTable_get_cell_value/3
udp_endpointTable_get_cell_value (const u32_t * column, const u32_t * row_oid, u8_t row_oid_len, union snmp_variant_value * value, u32_t * value_len)
{
  u8_t idx;
  struct udp_pcb * pcb;
  u16_t remote_port;
  u16_t local_port;
  struct ip_addr_t remote_ip;
  struct ip_addr_t local_ip;
  unsigned int _1;
  unsigned int _2;
  const u32_t * _3;
  unsigned char _4;
  unsigned int _5;
  unsigned int _6;
  const u32_t * _7;
  long unsigned int _8;
  unsigned char _9;
  unsigned char _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  unsigned char _19;
  unsigned char _20;
  long unsigned int _21;
  long unsigned int _22;
  short unsigned int _23;
  short unsigned int local_port.4_24;
  unsigned char _25;
  unsigned char _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  long unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  unsigned char _35;
  unsigned char _36;
  long unsigned int _37;
  long unsigned int _38;
  short unsigned int _39;
  short unsigned int remote_port.8_40;
  snmp_err_t _42;
  _Bool iftmp.2_43;
  int iftmp.3_44;
  _Bool iftmp.6_45;
  int iftmp.7_46;
  unsigned char _52;
  unsigned char _54;
  _Bool iftmp.2_57;
  _Bool iftmp.2_58;
  _Bool iftmp.6_59;
  _Bool iftmp.6_60;
  long unsigned int _68;
  <unnamed type> _69;

  <bb 2> [local count: 194244097]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG idx => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _52 = snmp_oid_to_ip_port (row_oid_48(D), row_oid_len_49(D), &local_ip, &local_port);
  # DEBUG idx => _52
  # DEBUG BEGIN_STMT
  if (_52 == 0)
    goto <bb 36>; [36.03%]
  else
    goto <bb 3>; [63.97%]

  <bb 3> [local count: 124257949]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) _52;
  _2 = _1 * 4;
  _3 = row_oid_48(D) + _2;
  _4 = row_oid_len_49(D) - _52;
  _54 = snmp_oid_to_ip_port (_3, _4, &remote_ip, &remote_port);
  idx_55 = _52 + _54;
  # DEBUG idx => idx_55
  # DEBUG BEGIN_STMT
  if (idx_55 == 0)
    goto <bb 36>; [21.72%]
  else
    goto <bb 4>; [78.28%]

  <bb 4> [local count: 97269122]:
  # DEBUG BEGIN_STMT
  if (row_oid_len_49(D) <= idx_55)
    goto <bb 36>; [21.72%]
  else
    goto <bb 5>; [78.28%]

  <bb 5> [local count: 76142269]:
  # DEBUG BEGIN_STMT
  _5 = (unsigned int) idx_55;
  _6 = _5 * 4;
  _7 = row_oid_48(D) + _6;
  _8 = *_7;
  if (_8 != 0)
    goto <bb 36>; [21.72%]
  else
    goto <bb 6>; [78.28%]

  <bb 6> [local count: 59604168]:
  # DEBUG BEGIN_STMT
  pcb_56 = udp_pcbs;
  # DEBUG pcb => pcb_56
  # DEBUG BEGIN_STMT
  goto <bb 35>; [100.00%]

  <bb 7> [local count: 1014686023]:
  # DEBUG BEGIN_STMT
  _9 = local_ip.type;
  _10 = pcb_41->local_ip.type;
  if (_9 == _10)
    goto <bb 8>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 8> [local count: 344993248]:
  if (_9 == 6)
    goto <bb 9>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 9> [local count: 117297704]:
  _11 = local_ip.u_addr.ip6.addr[0];
  _12 = pcb_41->local_ip.u_addr.ip6.addr[0];
  if (_11 == _12)
    goto <bb 10>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 10> [local count: 39881219]:
  _13 = local_ip.u_addr.ip6.addr[1];
  _14 = pcb_41->local_ip.u_addr.ip6.addr[1];
  if (_13 == _14)
    goto <bb 11>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 11> [local count: 13559615]:
  _15 = local_ip.u_addr.ip6.addr[2];
  _16 = pcb_41->local_ip.u_addr.ip6.addr[2];
  if (_15 == _16)
    goto <bb 12>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 12> [local count: 4610269]:
  _17 = local_ip.u_addr.ip6.addr[3];
  _18 = pcb_41->local_ip.u_addr.ip6.addr[3];
  if (_17 == _18)
    goto <bb 13>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 13> [local count: 1567491]:
  _19 = local_ip.u_addr.ip6.zone;
  _20 = pcb_41->local_ip.u_addr.ip6.zone;
  if (_19 == _20)
    goto <bb 15>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 14> [local count: 116764757]:

  <bb 15> [local count: 117297704]:
  # iftmp.3_44 = PHI <1(13), 0(14)>
  iftmp.2_58 = (_Bool) iftmp.3_44;
  goto <bb 17>; [100.00%]

  <bb 16> [local count: 227695544]:
  _21 = local_ip.u_addr.ip4.addr;
  _22 = pcb_41->local_ip.u_addr.ip4.addr;
  iftmp.2_57 = _21 == _22;

  <bb 17> [local count: 344993248]:
  # iftmp.2_43 = PHI <iftmp.2_58(15), iftmp.2_57(16)>
  if (iftmp.2_43 != 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 34>; [50.00%]

  <bb 18> [local count: 172496624]:
  _23 = pcb_41->local_port;
  local_port.4_24 = local_port;
  if (_23 == local_port.4_24)
    goto <bb 19>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 19> [local count: 58648852]:
  _25 = remote_ip.type;
  _26 = pcb_41->remote_ip.type;
  if (_25 == _26)
    goto <bb 20>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 20> [local count: 19940610]:
  if (_25 == 6)
    goto <bb 21>; [34.00%]
  else
    goto <bb 28>; [66.00%]

  <bb 21> [local count: 6779807]:
  _27 = remote_ip.u_addr.ip6.addr[0];
  _28 = pcb_41->remote_ip.u_addr.ip6.addr[0];
  if (_27 == _28)
    goto <bb 22>; [34.00%]
  else
    goto <bb 26>; [66.00%]

  <bb 22> [local count: 2305134]:
  _29 = remote_ip.u_addr.ip6.addr[1];
  _30 = pcb_41->remote_ip.u_addr.ip6.addr[1];
  if (_29 == _30)
    goto <bb 23>; [34.00%]
  else
    goto <bb 26>; [66.00%]

  <bb 23> [local count: 783746]:
  _31 = remote_ip.u_addr.ip6.addr[2];
  _32 = pcb_41->remote_ip.u_addr.ip6.addr[2];
  if (_31 == _32)
    goto <bb 24>; [34.00%]
  else
    goto <bb 26>; [66.00%]

  <bb 24> [local count: 266474]:
  _33 = remote_ip.u_addr.ip6.addr[3];
  _34 = pcb_41->remote_ip.u_addr.ip6.addr[3];
  if (_33 == _34)
    goto <bb 25>; [34.00%]
  else
    goto <bb 26>; [66.00%]

  <bb 25> [local count: 90601]:
  _35 = remote_ip.u_addr.ip6.zone;
  _36 = pcb_41->remote_ip.u_addr.ip6.zone;
  if (_35 == _36)
    goto <bb 27>; [34.00%]
  else
    goto <bb 26>; [66.00%]

  <bb 26> [local count: 6749003]:

  <bb 27> [local count: 6779807]:
  # iftmp.7_46 = PHI <1(25), 0(26)>
  iftmp.6_60 = (_Bool) iftmp.7_46;
  goto <bb 29>; [100.00%]

  <bb 28> [local count: 13160802]:
  _37 = remote_ip.u_addr.ip4.addr;
  _38 = pcb_41->remote_ip.u_addr.ip4.addr;
  iftmp.6_59 = _37 == _38;

  <bb 29> [local count: 19940610]:
  # iftmp.6_45 = PHI <iftmp.6_60(27), iftmp.6_59(28)>
  if (iftmp.6_45 != 0)
    goto <bb 30>; [50.00%]
  else
    goto <bb 34>; [50.00%]

  <bb 30> [local count: 9970305]:
  _39 = pcb_41->remote_port;
  remote_port.8_40 = remote_port;
  if (_39 == remote_port.8_40)
    goto <bb 31>; [5.50%]
  else
    goto <bb 34>; [94.50%]

  <bb 31> [local count: 548367]:
  # DEBUG BEGIN_STMT
  _68 = *column_61(D);
  # DEBUG D#1 => column_61(D)
  # DEBUG D#2 => value_62(D)
  # DEBUG INLINE_ENTRY udp_endpointTable_get_cell_value_core
  # DEBUG column => D#1
  # DEBUG value => D#2
  # DEBUG BEGIN_STMT
  if (_68 == 8)
    goto <bb 32>; [48.89%]
  else
    goto <bb 33>; [51.11%]

  <bb 32> [local count: 268097]:
<L47>:
  # DEBUG BEGIN_STMT
  MEM[(u32_t *)value_62(D)] = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 33> [local count: 548367]:
  # _69 = PHI <241(31), 0(32)>
  goto <bb 36>; [100.00%]

  <bb 34> [local count: 1014137659]:
  # DEBUG BEGIN_STMT
  pcb_63 = pcb_41->next;
  # DEBUG pcb => pcb_63

  <bb 35> [local count: 1073741824]:
  # pcb_41 = PHI <pcb_56(6), pcb_63(34)>
  # DEBUG pcb => pcb_41
  # DEBUG BEGIN_STMT
  if (pcb_41 != 0B)
    goto <bb 7>; [94.50%]
  else
    goto <bb 36>; [5.50%]

  <bb 36> [local count: 194244096]:
  # _42 = PHI <241(2), 241(3), 241(4), 241(5), _69(33), 241(35)>
  local_ip ={v} {CLOBBER};
  remote_ip ={v} {CLOBBER};
  local_port ={v} {CLOBBER};
  remote_port ={v} {CLOBBER};
  return _42;

}



;; Function udp_Table_get_cell_value (udp_Table_get_cell_value, funcdef_no=6, decl_uid=7662, cgraph_uid=7, symbol_order=7)

Modification phase of node udp_Table_get_cell_value/7
udp_Table_get_cell_value (const u32_t * column, const u32_t * row_oid, u8_t row_oid_len, union snmp_variant_value * value, u32_t * value_len)
{
  unsigned char _1;
  snmp_err_t _2;
  <unnamed type> _7;

  <bb 2> [local count: 107148842]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = snmp_oid_in_range (row_oid_4(D), row_oid_len_5(D), &udp_Table_oid_ranges, 5);
  if (_1 == 0)
    goto <bb 4>; [36.03%]
  else
    goto <bb 3>; [63.97%]

  <bb 3> [local count: 68543115]:
  # DEBUG D#7 => row_oid_len_5(D)
  # DEBUG D#8 => value_len_10(D)
  _7 = udp_Table_get_cell_value.part.0 (column_8(D), row_oid_4(D), value_9(D));

  <bb 4> [local count: 107148842]:
  # _2 = PHI <241(2), _7(3)>
  return _2;

}



;; Function udp_Table_get_next_cell_instance_and_value (udp_Table_get_next_cell_instance_and_value, funcdef_no=7, decl_uid=7674, cgraph_uid=8, symbol_order=8)

Modification phase of node udp_Table_get_next_cell_instance_and_value/8
udp_Table_get_next_cell_instance_and_value (const u32_t * column, struct snmp_obj_id * row_oid, union snmp_variant_value * value, u32_t * value_len)
{
  u32_t test_oid[5];
  u32_t result_temp[5];
  struct snmp_next_oid_state state;
  struct udp_pcb * pcb;
  u32_t[50] * _1;
  unsigned char _2;
  unsigned char _3;
  struct ip4_addr_t * _4;
  short unsigned int _5;
  long unsigned int _6;
  <unnamed type> _7;
  u32_t * _8;
  unsigned char _9;
  void * _10;
  snmp_err_t _12;
  snmp_err_t _25;
  long unsigned int _33;

  <bb 2> [local count: 118111602]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &row_oid_16(D)->id;
  _2 = row_oid_16(D)->len;
  snmp_next_oid_init (&state, _1, _2, &result_temp, 5);
  # DEBUG BEGIN_STMT
  pcb_19 = udp_pcbs;
  # DEBUG pcb => pcb_19
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = pcb_11->local_ip.type;
  if (_3 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 315357973]:
  # DEBUG BEGIN_STMT
  _4 = &pcb_11->local_ip.u_addr.ip4;
  snmp_ip4_to_oid (_4, &test_oid[0]);
  # DEBUG BEGIN_STMT
  _5 = pcb_11->local_port;
  _6 = (long unsigned int) _5;
  test_oid[4] = _6;
  # DEBUG BEGIN_STMT
  snmp_next_oid_check (&state, &test_oid, 5, pcb_11);

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  pcb_31 = pcb_11->next;
  # DEBUG pcb => pcb_31
  test_oid ={v} {CLOBBER};

  <bb 6> [local count: 1073741824]:
  # pcb_11 = PHI <pcb_19(2), pcb_31(5)>
  # DEBUG pcb => pcb_11
  # DEBUG BEGIN_STMT
  if (pcb_11 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  _7 = state.status;
  if (_7 == 0)
    goto <bb 8>; [47.77%]
  else
    goto <bb 9>; [52.23%]

  <bb 8> [local count: 56421912]:
  # DEBUG BEGIN_STMT
  _8 = state.next_oid;
  _9 = state.next_oid_len;
  snmp_oid_assign (row_oid_16(D), _8, _9);
  # DEBUG BEGIN_STMT
  _10 = state.reference;
  _33 = *column_21(D);
  # DEBUG D#3 => column_21(D)
  # DEBUG D#4 => value_22(D)
  # DEBUG D#5 => value_len_23(D)
  _25 = udp_Table_get_cell_value_core.isra.0 (_10, _33, value_22(D));

  <bb 9> [local count: 118111601]:
  # _12 = PHI <_25(8), 241(7)>
  state ={v} {CLOBBER};
  result_temp ={v} {CLOBBER};
  return _12;

}


