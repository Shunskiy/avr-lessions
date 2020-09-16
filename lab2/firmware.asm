	.file	"main.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__RAMPZ__ = 0x3b
__tmp_reg__ = 0
__zero_reg__ = 1
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	sbi 0xd,0
	cbi 0xd,5
	cbi 0xe,0
	sbi 0xe,5
	ldi r24,0
.L10:
	ldi r18,0
.L2:
	sbic 0xc,5
	rjmp .L9
	ldi r30,lo8(-25537)
	ldi r31,hi8(-25537)
1:	sbiw r30,1
	brne 1b
	rjmp .
	nop
	cpse r24,__zero_reg__
	rjmp .L4
	subi r18,lo8(-(1))
	rjmp .L5
.L4:
	cpi r24,lo8(10)
	brsh .L2
.L5:
	subi r24,lo8(-(1))
	cpi r24,lo8(9)
	brne .L2
	ldi r20,lo8(1)
	ldi r21,0
	ldi r19,0
.L7:
	cp r20,r18
	cpc r21,r19
	brge .L10
	sbi 0xe,0
	ldi r31,lo8(319999)
	ldi r22,hi8(319999)
	ldi r23,hlo8(319999)
1:	subi r31,1
	sbci r22,0
	sbci r23,0
	brne 1b
	rjmp .
	nop
	cbi 0xe,0
	ldi r25,lo8(319999)
	ldi r30,hi8(319999)
	ldi r31,hlo8(319999)
1:	subi r25,1
	sbci r30,0
	sbci r31,0
	brne 1b
	rjmp .
	nop
	subi r20,-1
	sbci r21,-1
	rjmp .L7
.L9:
	ldi r24,0
	rjmp .L2
	.size	main, .-main
	.ident	"GCC: (GNU) 5.4.0"
