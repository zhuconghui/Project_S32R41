/* File: 
 * Purpose: get core index for armv8-r architecture devices.
 *          Should be used with GCC for ARM Embedded Processors
 */

	.arch	armv8-a
	.text
	.global get_core_index

get_core_index:
        /*
           Imprementation - defined
           For A53-based devices: core#n ~ 3b'Aff1[1]Aff0[1:0]
        */
        mrs     x1, mpidr_el1
        mrs     x0, midr_el1
        orr     x0, xzr, x0, lsr #4
        and     x0, x0, #0xFFF
        cmp     x0, #0xD03
        ble     .La53
.La57:
        orr     x0, x1, x1, lsr #7
        b       .Ldone
.La53:
        orr     x0, x1, x1, lsr #6
.Ldone:
        and     x0, x0, #0xFF
        ret


