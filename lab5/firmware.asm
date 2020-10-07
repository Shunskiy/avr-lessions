	.file	"main.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__RAMPZ__ = 0x3b
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	switch_sides
	.type	switch_sides, @function
switch_sides:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	cpi r24,3
	cpc r25,__zero_reg__
	breq .L3
	brge .L4
	cpi r24,1
	cpc r25,__zero_reg__
	breq .L5
	sbiw r24,2
	breq .L6
	ret
.L4:
	cpi r24,4
	cpc r25,__zero_reg__
	breq .L7
	sbiw r24,5
	breq .L8
	ret
.L5:
	sbi 0xb,4
	sbi 0xb,3
	ret
.L6:
	sbi 0xb,2
	sbi 0xb,3
	sbi 0x5,5
	sbi 0xb,5
	sbi 0x5,6
	ret
.L3:
	sbi 0xb,2
	sbi 0xb,3
	rjmp .L9
.L7:
	sbi 0x5,4
	sbi 0x5,5
	sbi 0xb,3
	sbi 0xb,4
	ret
.L8:
	sbi 0xb,2
	sbi 0x5,4
.L9:
	sbi 0x5,5
	sbi 0xb,4
	sbi 0xb,5
	ret
	.size	switch_sides, .-switch_sides
.global	clear_shit
	.type	clear_shit, @function
clear_shit:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	cbi 0x5,4
	cbi 0x5,5
	cbi 0xb,2
	cbi 0xb,3
	cbi 0xb,4
	cbi 0xb,5
	ret
	.size	clear_shit, .-clear_shit
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	in r24,__SREG__
	andi r24,lo8(127)
	out __SREG__,r24
	sbi 0xd,6
	cbi 0xe,6
	sbi 0x4,4
	cbi 0x5,4
	sbi 0x4,5
	cbi 0x5,5
	sbi 0xa,2
	cbi 0xb,2
	sbi 0xa,3
	cbi 0xb,3
	sbi 0xa,4
	cbi 0xb,4
	sbi 0xa,5
	cbi 0xb,5
	sts 128,__zero_reg__
	ldi r24,lo8(5)
	sts 129,r24
	ldi r24,lo8(9)
	ldi r25,lo8(61)
	sts 136+1,r25
	sts 136,r24
	sts 132+1,__zero_reg__
	sts 132,__zero_reg__
	ldi r24,lo8(2)
	sts 111,r24
	in r24,__SREG__
	ori r24,lo8(-128)
	out __SREG__,r24
.L13:
	lds r24,counter
	cpi r24,lo8(5)
	brne .L14
	sbi 0xe,6
	ldi r28,lo8(5)
	ldi r29,0
.L15:
	movw r24,r28
	call switch_sides
	ldi r18,lo8(3199999)
	ldi r24,hi8(3199999)
	ldi r25,hlo8(3199999)
1:	subi r18,1
	sbci r24,0
	sbci r25,0
	brne 1b
	rjmp .
	nop
	call clear_shit
	sbiw r28,1
	brne .L15
	rjmp .L13
.L14:
	lds r24,counter
	cpi r24,lo8(10)
	brne .L13
	cbi 0xe,6
	sts counter,__zero_reg__
	rjmp .L13
	.size	main, .-main
	.text
.global	__vector_17
	.type	__vector_17, @function
__vector_17:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	push r24
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 4 */
.L__stack_usage = 4
	lds r24,counter
	subi r24,lo8(-(1))
	sts counter,r24
	sts 132+1,__zero_reg__
	sts 132,__zero_reg__
/* epilogue start */
	pop r24
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_17, .-__vector_17
.global	counter
	.section .bss
	.type	counter, @object
	.size	counter, 1
counter:
	.zero	1
	.ident	"GCC: (GNU) 5.4.0"
.global __do_clear_bss
