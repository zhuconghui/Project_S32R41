
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  ip4_input/14:
  Jump functions of caller  ip6_input/13:
  Jump functions of caller  ip4addr_aton/12:
  Jump functions of caller  ip6addr_aton/11:
  Jump functions of caller  ip4addr_ntoa_r/10:
  Jump functions of caller  ip6addr_ntoa_r/9:
  Jump functions of caller  ip4addr_ntoa/8:
  Jump functions of caller  ip6addr_ntoa/7:
  Jump functions of caller  ip_input/6:
  Jump functions of caller  ipaddr_aton/5:
  Jump functions of caller  ipaddr_ntoa_r/4:
  Jump functions of caller  ipaddr_ntoa/3:

 Propagating constants:

Not considering ip_input for cloning; -fipa-cp-clone disabled.
Not considering ipaddr_aton for cloning; -fipa-cp-clone disabled.
Not considering ipaddr_ntoa_r for cloning; -fipa-cp-clone disabled.
Not considering ipaddr_ntoa for cloning; -fipa-cp-clone disabled.

overall_size: 77, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: ip_input/6:
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
  Node: ipaddr_aton/5:
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
  Node: ipaddr_ntoa_r/4:
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
  Node: ipaddr_ntoa/3:
    param [0]: BOTTOM
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

ip4_input/14 (ip4_input) @060bae00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip_input/6 (702504179 (estimated locally),0.65 per call) 
  Calls: 
ip6_input/13 (ip6_input) @060bad20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip_input/6 (361896092 (estimated locally),0.34 per call) 
  Calls: 
ip4addr_aton/12 (ip4addr_aton) @060bab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipaddr_aton/5 (75773862 (estimated locally),0.47 per call) 
  Calls: 
ip6addr_aton/11 (ip6addr_aton) @060baa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipaddr_aton/5 (37860609 (estimated locally),0.23 per call) 
  Calls: 
ip4addr_ntoa_r/10 (ip4addr_ntoa_r) @060ba8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipaddr_ntoa_r/4 (650062628 (estimated locally),0.61 per call) 
  Calls: 
ip6addr_ntoa_r/9 (ip6addr_ntoa_r) @060ba7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipaddr_ntoa_r/4 (334880748 (estimated locally),0.31 per call) 
  Calls: 
ip4addr_ntoa/8 (ip4addr_ntoa) @060ba620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipaddr_ntoa/3 (650062628 (estimated locally),0.61 per call) 
  Calls: 
ip6addr_ntoa/7 (ip6addr_ntoa) @060ba540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipaddr_ntoa/3 (334880748 (estimated locally),0.31 per call) 
  Calls: 
ip_input/6 (ip_input) @060ba0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ip4_input/14 (702504179 (estimated locally),0.65 per call) ip6_input/13 (361896092 (estimated locally),0.34 per call) 
ipaddr_aton/5 (ipaddr_aton) @060b29a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:162334957 (estimated locally) body optimize_size
  Called by: 
  Calls: ip4addr_aton/12 (75773862 (estimated locally),0.47 per call) ip6addr_aton/11 (37860609 (estimated locally),0.23 per call) 
ipaddr_ntoa_r/4 (ipaddr_ntoa_r) @060b2c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ip4addr_ntoa_r/10 (650062628 (estimated locally),0.61 per call) ip6addr_ntoa_r/9 (334880748 (estimated locally),0.31 per call) 
ipaddr_ntoa/3 (ipaddr_ntoa) @060b28c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ip4addr_ntoa/8 (650062628 (estimated locally),0.61 per call) ip6addr_ntoa/7 (334880748 (estimated locally),0.31 per call) 
ip_addr_any_type/2 (ip_addr_any_type) @060af9d8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
ip_data/1 (ip_data) @060af990
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags:

;; Function ipaddr_ntoa (ipaddr_ntoa, funcdef_no=1, decl_uid=6283, cgraph_uid=2, symbol_order=3)

Modification phase of node ipaddr_ntoa/3
ipaddr_ntoa (const struct ip_addr_t * addr)
{
  unsigned char _1;
  const struct ip6_addr_t * _2;
  const struct ip4_addr_t * _3;
  char * _4;
  char * _9;
  char * _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (addr_6(D) == 0B)
    goto <bb 6>; [8.27%]
  else
    goto <bb 3>; [91.73%]

  <bb 3> [local count: 984943376]:
  # DEBUG BEGIN_STMT
  _1 = addr_6(D)->type;
  if (_1 == 6)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 334880748]:
  # DEBUG BEGIN_STMT
  _2 = &addr_6(D)->u_addr.ip6;
  _9 = ip6addr_ntoa (_2);
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 650062628]:
  # DEBUG BEGIN_STMT
  _3 = &addr_6(D)->u_addr.ip4;
  _11 = ip4addr_ntoa (_3);

  <bb 6> [local count: 1073741824]:
  # _4 = PHI <0B(2), _9(4), _11(5)>
  return _4;

}



;; Function ipaddr_ntoa_r (ipaddr_ntoa_r, funcdef_no=2, decl_uid=6287, cgraph_uid=3, symbol_order=4)

Modification phase of node ipaddr_ntoa_r/4
ipaddr_ntoa_r (const struct ip_addr_t * addr, char * buf, int buflen)
{
  unsigned char _1;
  const struct ip6_addr_t * _2;
  const struct ip4_addr_t * _3;
  char * _4;
  char * _11;
  char * _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (addr_6(D) == 0B)
    goto <bb 6>; [8.27%]
  else
    goto <bb 3>; [91.73%]

  <bb 3> [local count: 984943376]:
  # DEBUG BEGIN_STMT
  _1 = addr_6(D)->type;
  if (_1 == 6)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 334880748]:
  # DEBUG BEGIN_STMT
  _2 = &addr_6(D)->u_addr.ip6;
  _11 = ip6addr_ntoa_r (_2, buf_8(D), buflen_9(D));
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 650062628]:
  # DEBUG BEGIN_STMT
  _3 = &addr_6(D)->u_addr.ip4;
  _13 = ip4addr_ntoa_r (_3, buf_8(D), buflen_9(D));

  <bb 6> [local count: 1073741824]:
  # _4 = PHI <0B(2), _11(4), _13(5)>
  return _4;

}



;; Function ipaddr_aton (ipaddr_aton, funcdef_no=3, decl_uid=6290, cgraph_uid=4, symbol_order=5)

Modification phase of node ipaddr_aton/5
ipaddr_aton (const char * cp, struct ip_addr_t * addr)
{
  const char * c;
  struct ip6_addr_t * _1;
  char _2;
  struct ip4_addr_t * _3;
  int _5;
  int _15;
  int _18;

  <bb 2> [local count: 162334957]:
  # DEBUG BEGIN_STMT
  if (cp_9(D) != 0B)
    goto <bb 14>; [70.00%]
  else
    goto <bb 13>; [30.00%]

  <bb 14> [local count: 113634470]:
  goto <bb 9>; [100.00%]

  <bb 3> [local count: 1034442875]:
  # DEBUG BEGIN_STMT
  if (_2 == 58)
    goto <bb 4>; [3.66%]
  else
    goto <bb 7>; [96.34%]

  <bb 4> [local count: 37860609]:
  # DEBUG BEGIN_STMT
  if (addr_12(D) != 0B)
    goto <bb 5>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 5> [local count: 26502426]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_12(D)->type = 6;

  <bb 6> [local count: 37860609]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &addr_12(D)->u_addr.ip6;
  _15 = ip6addr_aton (cp_9(D), _1);
  goto <bb 13>; [100.00%]

  <bb 7> [local count: 996582265]:
  # DEBUG BEGIN_STMT
  if (_2 == 46)
    goto <bb 10>; [3.66%]
  else
    goto <bb 8>; [96.34%]

  <bb 8> [local count: 960107355]:
  # DEBUG BEGIN_STMT
  c_11 = c_4 + 1;
  # DEBUG c => c_11

  <bb 9> [local count: 1073741824]:
  # c_4 = PHI <c_11(8), cp_9(D)(14)>
  # DEBUG c => c_4
  # DEBUG BEGIN_STMT
  _2 = *c_4;
  if (_2 != 0)
    goto <bb 3>; [96.34%]
  else
    goto <bb 10>; [3.66%]

  <bb 10> [local count: 75773862]:
  # DEBUG BEGIN_STMT
  if (addr_12(D) != 0B)
    goto <bb 11>; [70.00%]
  else
    goto <bb 12>; [30.00%]

  <bb 11> [local count: 53041703]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_12(D)->type = 0;

  <bb 12> [local count: 75773862]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = &addr_12(D)->u_addr.ip4;
  _18 = ip4addr_aton (cp_9(D), _3);

  <bb 13> [local count: 162334958]:
  # _5 = PHI <_15(6), _18(12), 0(2)>
  return _5;

}



;; Function ip_input (ip_input, funcdef_no=4, decl_uid=6955, cgraph_uid=5, symbol_order=6)

Modification phase of node ip_input/6
ip_input (struct pbuf * p, struct netif * inp)
{
  void * _1;
  unsigned char _2;
  unsigned char _3;
  err_t _4;
  err_t _10;
  err_t _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (p_6(D) != 0B)
    goto <bb 3>; [99.13%]
  else
    goto <bb 6>; [0.87%]

  <bb 3> [local count: 1064400271]:
  # DEBUG BEGIN_STMT
  _1 = p_6(D)->payload;
  _2 = MEM[(u8_t *)_1];
  _3 = _2 >> 4;
  if (_3 == 6)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 361896092]:
  # DEBUG BEGIN_STMT
  _12 = ip6_input (p_6(D), inp_8(D));
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 702504179]:
  # DEBUG BEGIN_STMT
  _10 = ip4_input (p_6(D), inp_8(D));

  <bb 6> [local count: 1073741824]:
  # _4 = PHI <_12(4), _10(5), -6(2)>
  return _4;

}


