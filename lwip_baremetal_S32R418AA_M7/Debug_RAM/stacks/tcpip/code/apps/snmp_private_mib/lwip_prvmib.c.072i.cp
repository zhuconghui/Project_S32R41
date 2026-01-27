
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  snprintf/32:
  Jump functions of caller  __builtin_puts/31:
  Jump functions of caller  memset/30:
  Jump functions of caller  snmp_oid_in_range/29:
  Jump functions of caller  snmp_oid_assign/28:
  Jump functions of caller  snmp_next_oid_check/27:
  Jump functions of caller  snmp_next_oid_init/26:
  Jump functions of caller  memcpy/25:
  Jump functions of caller  strlen/24:
  Jump functions of caller  snmp_set_test_ok/23:
  Jump functions of caller  snmp_table_get_next_instance/22:
  Jump functions of caller  snmp_table_get_instance/21:
  Jump functions of caller  snmp_scalar_get_next_instance/20:
  Jump functions of caller  snmp_scalar_get_instance/19:
  Jump functions of caller  sensor_table_set_value/18:
  Jump functions of caller  sensor_table_get_value/17:
  Jump functions of caller  sensor_table_get_next_cell_instance/16:
  Jump functions of caller  sensor_table_get_cell_instance/15:
  Jump functions of caller  sensor_count_get_value/13:
  Jump functions of caller  lwip_privmib_init/12:

 Propagating constants:

Not considering sensor_table_set_value for cloning; -fipa-cp-clone disabled.
Not considering sensor_table_get_value for cloning; -fipa-cp-clone disabled.
Not considering sensor_table_get_next_cell_instance for cloning; -fipa-cp-clone disabled.
Not considering sensor_table_get_cell_instance for cloning; -fipa-cp-clone disabled.
Not considering sensor_count_get_value for cloning; -fipa-cp-clone disabled.
Not considering lwip_privmib_init for cloning; -fipa-cp-clone disabled.

overall_size: 114, max_new_size: 11001
 - context independent values, size: 6, time_benefit: 1.000000
 - context independent values, size: 33, time_benefit: 1.000000
 - context independent values, size: 21, time_benefit: 1.000000
 - context independent values, size: 10, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: sensor_table_set_value/18:
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
  Node: sensor_table_get_value/17:
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
  Node: sensor_table_get_next_cell_instance/16:
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
  Node: sensor_table_get_cell_instance/15:
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
  Node: sensor_count_get_value/13:
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
  Node: lwip_privmib_init/12:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

snprintf/32 (snprintf) @060ee460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_privmib_init/12 (858993459 (estimated locally),4.00 per call) 
  Calls: 
puts/31 (__builtin_puts) @060ee380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_privmib_init/12 (214748364 (estimated locally),1.00 per call) 
  Calls: 
memset/30 (memset) @060ee2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_privmib_init/12 (214748364 (estimated locally),1.00 per call) 
  Calls: 
snmp_oid_in_range/29 (snmp_oid_in_range) @060ee0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sensor_table_get_cell_instance/15 (158976681 (estimated locally),1.00 per call) 
  Calls: 
snmp_oid_assign/28 (snmp_oid_assign) @060e4ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sensor_table_get_next_cell_instance/16 (31262283 (estimated locally),0.32 per call) 
  Calls: 
snmp_next_oid_check/27 (snmp_next_oid_check) @060e4e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sensor_table_get_next_cell_instance/16 (322125769 (estimated locally),3.30 per call) 
  Calls: 
snmp_next_oid_init/26 (snmp_next_oid_init) @060e4d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sensor_table_get_next_cell_instance/16 (97603132 (estimated locally),1.00 per call) 
  Calls: 
memcpy/25 (memcpy) @060e4b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sensor_table_get_value/17 (357878150 (estimated locally),0.33 per call) 
  Calls: 
strlen/24 (strlen) @060e4a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sensor_table_get_value/17 (357878150 (estimated locally),0.33 per call) sensor_table_get_value/17 (357878150 (estimated locally),0.33 per call) 
  Calls: 
snmp_set_test_ok/23 (snmp_set_test_ok) @060e47e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: sensor_table/6 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
snmp_table_get_next_instance/22 (snmp_table_get_next_instance) @060e4620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: sensor_table/6 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
snmp_table_get_instance/21 (snmp_table_get_instance) @060e4540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: sensor_table/6 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
snmp_scalar_get_next_instance/20 (snmp_scalar_get_next_instance) @060e40e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: sensor_count/7 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
snmp_scalar_get_instance/19 (snmp_scalar_get_instance) @060e4000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: sensor_count/7 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
sensor_table_set_value/18 (sensor_table_set_value) @060ddd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: sensors/4 (write)
  Referring: sensor_table/6 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sensor_table_get_value/17 (sensor_table_get_value) @060dd0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: sensors/4 (read)sensors/4 (addr)
  Referring: sensor_table/6 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: strlen/24 (357878150 (estimated locally),0.33 per call) memcpy/25 (357878150 (estimated locally),0.33 per call) strlen/24 (357878150 (estimated locally),0.33 per call) 
sensor_table_get_next_cell_instance/16 (sensor_table_get_next_cell_instance) @060ddc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: sensors/4 (read)
  Referring: sensor_table/6 (addr)
  Availability: available
  Function flags: count:97603132 (estimated locally) body optimize_size
  Called by: 
  Calls: snmp_oid_assign/28 (31262283 (estimated locally),0.32 per call) snmp_next_oid_check/27 (322125769 (estimated locally),3.30 per call) snmp_next_oid_init/26 (97603132 (estimated locally),1.00 per call) 
sensor_table_get_cell_instance/15 (sensor_table_get_cell_instance) @060dd460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: sensor_table_oid_ranges/14 (addr)sensors/4 (read)
  Referring: sensor_table/6 (addr)
  Availability: available
  Function flags: count:158976681 (estimated locally) body optimize_size
  Called by: 
  Calls: snmp_oid_in_range/29 (158976681 (estimated locally),1.00 per call) 
sensor_table_oid_ranges/14 (sensor_table_oid_ranges) @060a1cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: sensor_table_get_cell_instance/15 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
sensor_count_get_value/13 (sensor_count_get_value) @060a7d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: sensors/4 (read)
  Referring: sensor_count/7 (addr)
  Availability: available
  Function flags: count:151290760 (estimated locally) body optimize_size
  Called by: 
  Calls: 
lwip_privmib_init/12 (lwip_privmib_init) @060a79a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sensors/4 (addr)sensors/4 (write)sensors/4 (addr)sensors/4 (write)
  Referring: 
  Availability: available
  Function flags: count:214748364 (estimated locally) body optimize_size
  Called by: 
  Calls: snprintf/32 (858993459 (estimated locally),4.00 per call) __builtin_puts/31 (214748364 (estimated locally),1.00 per call) memset/30 (214748364 (estimated locally),1.00 per call) 
mib_private/11 (mib_private) @060a1558
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: prvmib_base_oid/10 (addr)example_node/9 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
prvmib_base_oid/10 (prvmib_base_oid) @060a1480
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mib_private/11 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
example_node/9 (example_node) @060a13a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: example_nodes/8 (addr)
  Referring: mib_private/11 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
example_nodes/8 (example_nodes) @060a1318
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: sensor_table/6 (addr)sensor_count/7 (addr)
  Referring: example_node/9 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
sensor_count/7 (sensor_count) @060a1288
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_scalar_get_instance/19 (addr)snmp_scalar_get_next_instance/20 (addr)sensor_count_get_value/13 (addr)
  Referring: example_nodes/8 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
sensor_table/6 (sensor_table) @060a11b0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_table_get_instance/21 (addr)snmp_table_get_next_instance/22 (addr)sensor_table_columns/5 (addr)sensor_table_get_cell_instance/15 (addr)sensor_table_get_next_cell_instance/16 (addr)sensor_table_get_value/17 (addr)snmp_set_test_ok/23 (addr)sensor_table_set_value/18 (addr)
  Referring: example_nodes/8 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
sensor_table_columns/5 (sensor_table_columns) @060a10d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: sensor_table/6 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
sensors/4 (sensors) @06090ea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: sensor_table_get_next_cell_instance/16 (read)sensor_table_get_cell_instance/15 (read)sensor_table_get_value/17 (read)sensor_table_set_value/18 (write)sensor_table_get_value/17 (addr)sensor_count_get_value/13 (read)lwip_privmib_init/12 (addr)lwip_privmib_init/12 (write)lwip_privmib_init/12 (addr)lwip_privmib_init/12 (write)
  Availability: available
  Varpool flags:

;; Function sensor_count_get_value (sensor_count_get_value, funcdef_no=5, decl_uid=7269, cgraph_uid=6, symbol_order=13)

Modification phase of node sensor_count_get_value/13
sensor_count_get_value (struct snmp_node_instance * instance, void * value)
{
  size_t count;
  unsigned char _1;
  s16_t _3;

  <bb 2> [local count: 151290760]:
  # DEBUG BEGIN_STMT
  # DEBUG count => 0
  # DEBUG BEGIN_STMT
  # DEBUG uint_ptr => value_6(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG count => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 976138693]:
  # DEBUG BEGIN_STMT
  _1 = sensors[count_2].num;
  if (_1 == 0)
    goto <bb 4>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 4> [local count: 53687628]:
  # count_5 = PHI <count_2(3)>
  # DEBUG BEGIN_STMT
  MEM[(u32_t *)value_6(D)] = count_5;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 922451064]:
  # DEBUG BEGIN_STMT
  count_8 = count_2 + 1;
  # DEBUG count => count_8

  <bb 6> [local count: 1073741824]:
  # count_2 = PHI <0(2), count_8(5)>
  # DEBUG count => count_2
  # DEBUG BEGIN_STMT
  if (count_2 != 10)
    goto <bb 3>; [90.91%]
  else
    goto <bb 7>; [9.09%]

  <bb 7> [local count: 151290760]:
  # _3 = PHI <4(4), 0(6)>
  return _3;

}



;; Function sensor_table_set_value (sensor_table_set_value, funcdef_no=9, decl_uid=7285, cgraph_uid=10, symbol_order=18)

Modification phase of node sensor_table_set_value/18
sensor_table_set_value (struct snmp_node_instance * instance, u16_t len, void * value)
{
  u32_t i;
  long int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  i_4 = instance_3(D)->reference.u32;
  # DEBUG i => i_4
  # DEBUG BEGIN_STMT
  # DEBUG temperature => value_5(D)
  # DEBUG BEGIN_STMT
  _1 = MEM[(s32_t *)value_5(D)];
  sensors[i_4].value = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function sensor_table_get_value (sensor_table_get_value, funcdef_no=8, decl_uid=7281, cgraph_uid=9, symbol_order=17)

Modification phase of node sensor_table_get_value/17
sensor_table_get_value (struct snmp_node_instance * instance, void * value)
{
  u32_t i;
  long unsigned int _1;
  long int _2;
  char[21] * _3;
  unsigned int _4;
  unsigned int _5;
  s16_t _6;
  s16_t _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  i_10 = instance_9(D)->reference.u32;
  # DEBUG i => i_10
  # DEBUG BEGIN_STMT
  # DEBUG temperature => value_11(D)
  # DEBUG BEGIN_STMT
  _1 = instance_9(D)->instance_oid.id[1];
  switch (_1) <default: <L4> [33.33%], case 1: <L0> [33.33%], case 2: <L1> [33.33%]>

  <bb 3> [local count: 357878150]:
<L0>:
  # DEBUG BEGIN_STMT
  _2 = sensors[i_10].value;
  MEM[(s32_t *)value_11(D)] = _2;
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357878150]:
<L1>:
  # DEBUG BEGIN_STMT
  _3 = &sensors[i_10].file;
  _4 = strlen (_3);
  memcpy (value_11(D), _3, _4);
  # DEBUG BEGIN_STMT
  _5 = strlen (_3);
  _13 = (s16_t) _5;

  <bb 5> [local count: 1073634451]:
  # _6 = PHI <4(3), _13(4), 0(2)>
<L4>:
  return _6;

}



;; Function sensor_table_get_next_cell_instance (sensor_table_get_next_cell_instance, funcdef_no=7, decl_uid=7278, cgraph_uid=8, symbol_order=16)

Modification phase of node sensor_table_get_next_cell_instance/16
sensor_table_get_next_cell_instance (const u32_t * column, struct snmp_obj_id * row_oid, struct snmp_node_instance * cell_instance)
{
  u32_t test_oid[1];
  u32_t result_temp[1];
  struct snmp_next_oid_state state;
  size_t i;
  u32_t[50] * _1;
  unsigned char _2;
  unsigned char _3;
  long unsigned int _4;
  void * i.0_5;
  <unnamed type> _6;
  u32_t * _7;
  unsigned char _8;
  void * _9;
  long unsigned int _10;
  snmp_err_t _12;

  <bb 2> [local count: 97603132]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &row_oid_16(D)->id;
  _2 = row_oid_16(D)->len;
  snmp_next_oid_init (&state, _1, _2, &result_temp, 1);
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 976138694]:
  # DEBUG BEGIN_STMT
  _3 = sensors[i_11].num;
  if (_3 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 322125769]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = (long unsigned int) _3;
  test_oid[0] = _4;
  # DEBUG BEGIN_STMT
  i.0_5 = (void *) i_11;
  snmp_next_oid_check (&state, &test_oid, 1, i.0_5);
  test_oid ={v} {CLOBBER};

  <bb 5> [local count: 976138694]:
  # DEBUG BEGIN_STMT
  i_27 = i_11 + 1;
  # DEBUG i => i_27

  <bb 6> [local count: 1073741824]:
  # i_11 = PHI <0(2), i_27(5)>
  # DEBUG i => i_11
  # DEBUG BEGIN_STMT
  if (i_11 != 10)
    goto <bb 3>; [90.91%]
  else
    goto <bb 7>; [9.09%]

  <bb 7> [local count: 97603132]:
  # DEBUG BEGIN_STMT
  _6 = state.status;
  if (_6 == 0)
    goto <bb 8>; [32.03%]
  else
    goto <bb 9>; [67.97%]

  <bb 8> [local count: 31262283]:
  # DEBUG BEGIN_STMT
  _7 = state.next_oid;
  _8 = state.next_oid_len;
  snmp_oid_assign (row_oid_16(D), _7, _8);
  # DEBUG BEGIN_STMT
  _9 = state.reference;
  _10 = (long unsigned int) _9;
  cell_instance_20(D)->reference.u32 = _10;
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 97603132]:
  # _12 = PHI <0(8), 241(7)>
  state ={v} {CLOBBER};
  result_temp ={v} {CLOBBER};
  return _12;

}



;; Function sensor_table_get_cell_instance (sensor_table_get_cell_instance, funcdef_no=6, decl_uid=7274, cgraph_uid=7, symbol_order=15)

Modification phase of node sensor_table_get_cell_instance/15
sensor_table_get_cell_instance (const u32_t * column, const u32_t * row_oid, u8_t row_oid_len, struct snmp_node_instance * cell_instance)
{
  size_t i;
  u32_t sensor_num;
  unsigned char _1;
  unsigned char _2;
  long unsigned int _4;
  snmp_err_t _6;

  <bb 2> [local count: 158976681]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = snmp_oid_in_range (row_oid_9(D), row_oid_len_10(D), &sensor_table_oid_ranges, 1);
  if (_1 == 0)
    goto <bb 9>; [21.72%]
  else
    goto <bb 3>; [78.28%]

  <bb 3> [local count: 124446946]:
  # DEBUG BEGIN_STMT
  sensor_num_12 = *row_oid_9(D);
  # DEBUG sensor_num => sensor_num_12
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 976138694]:
  # DEBUG BEGIN_STMT
  _2 = sensors[i_5].num;
  if (_2 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 488069347]:
  # DEBUG BEGIN_STMT
  _4 = (long unsigned int) _2;
  if (_4 == sensor_num_12)
    goto <bb 6>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 6> [local count: 26843814]:
  # i_3 = PHI <i_5(5)>
  # DEBUG BEGIN_STMT
  cell_instance_13(D)->reference.u32 = i_3;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 949294880]:
  # DEBUG BEGIN_STMT
  i_15 = i_5 + 1;
  # DEBUG i => i_15

  <bb 8> [local count: 1073741824]:
  # i_5 = PHI <0(3), i_15(7)>
  # DEBUG i => i_5
  # DEBUG BEGIN_STMT
  if (i_5 != 10)
    goto <bb 4>; [90.91%]
  else
    goto <bb 9>; [9.09%]

  <bb 9> [local count: 158976681]:
  # _6 = PHI <241(2), 0(6), 241(8)>
  return _6;

}



;; Function lwip_privmib_init (lwip_privmib_init, funcdef_no=4, decl_uid=6541, cgraph_uid=5, symbol_order=12)

Modification phase of node lwip_privmib_init/12
lwip_privmib_init ()
{
  u8_t i;
  int _1;
  unsigned char _2;
  char[21] * _3;
  int _4;
  int _5;

  <bb 2> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (&sensors, 0, 280);
  # DEBUG BEGIN_STMT
  __builtin_puts (&"SNMP private MIB start, detecting sensors."[0]);
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  _1 = (int) i_6;
  _2 = i_6 + 1;
  sensors[_1].num = _2;
  # DEBUG BEGIN_STMT
  _3 = &sensors[_1].file;
  snprintf (_3, 21, "%d.txt", _1);
  # DEBUG BEGIN_STMT
  _4 = _1 + 1;
  _5 = _4 * 11;
  sensors[_1].value = _5;
  # DEBUG BEGIN_STMT
  # DEBUG i => _2

  <bb 4> [local count: 1073741824]:
  # i_6 = PHI <0(2), _2(3)>
  # DEBUG i => i_6
  # DEBUG BEGIN_STMT
  if (i_6 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 5>; [20.00%]

  <bb 5> [local count: 214748365]:
  return;

}


