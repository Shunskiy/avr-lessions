	.file	"main.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__RAMPZ__ = 0x3b
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	read_adc
	.type	read_adc, @function
read_adc:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	lds r25,124
	andi r25,lo8(-32)
	mov r20,r24
	ldi r21,0
	movw r30,r20
	sbiw r30,1
	cpi r30,7
	cpc r31,__zero_reg__
	brsh .L2
	subi r30,lo8(-(gs(.L4)))
	sbci r31,hi8(-(gs(.L4)))
	jmp __tablejump2__
	.section	.progmem.gcc_sw_table,"a",@progbits
	.p2align	1
.L4:
	.word gs(.L3)
	.word gs(.L5)
	.word gs(.L6)
	.word gs(.L7)
	.word gs(.L8)
	.word gs(.L9)
	.word gs(.L10)
	.text
.L3:
	ori r25,lo8(1)
	rjmp .L2
.L5:
	ori r25,lo8(2)
	rjmp .L2
.L6:
	ori r25,lo8(3)
	rjmp .L2
.L7:
	ori r25,lo8(4)
	rjmp .L2
.L8:
	ori r25,lo8(5)
	rjmp .L2
.L9:
	ori r25,lo8(6)
	rjmp .L2
.L10:
	ori r25,lo8(7)
.L2:
	sts 124,r25
	ldi r18,lo8(16)
	ldi r24,0
	ldi r25,0
.L12:
	lds r19,122
	ori r19,lo8(64)
	sts 122,r19
.L11:
	lds r19,122
	sbrc r19,6
	rjmp .L11
	lds r20,120
	lds r21,120+1
	add r24,r20
	adc r25,r21
	subi r18,lo8(-(-1))
	brne .L12
	ldi r18,4
	1:
	lsr r25
	ror r24
	dec r18
	brne 1b
	ret
	.size	read_adc, .-read_adc
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	cbi 0xd,2
	sbi 0xe,2
	sbi 0xd,7
	cbi 0xe,7
	sbi 0xd,3
	cbi 0xe,3
	ldi r24,lo8(64)
	sts 124,r24
	ldi r24,lo8(-121)
	sts 122,r24
.L17:
	lds r24,123
	sbrc r24,5
	rjmp .L17
	ldi r29,0
.L28:
	ldi r28,0
.L18:
	ldi r24,0
	call read_adc
	sbic 0xc,2
	rjmp .L26
	ldi r24,lo8(-25537)
	ldi r25,hi8(-25537)
1:	sbiw r24,1
	brne 1b
	rjmp .
	nop
	cpse r29,__zero_reg__
	rjmp .L20
	subi r28,lo8(-(1))
	rjmp .L21
.L20:
	cpi r29,lo8(100)
	brsh .L19
.L21:
	subi r29,lo8(-(1))
	rjmp .L19
.L26:
	ldi r29,0
.L19:
	cpi r28,lo8(1)
	brne .L22
	ldi r24,0
	call read_adc
	cpi r24,lo8(60)
	brsh .L23
	sbi 0xe,3
	rjmp .L24
.L23:
	cbi 0xe,3
.L24:
	ldi r24,lo8(-25537)
	ldi r25,hi8(-25537)
1:	sbiw r24,1
	brne 1b
	rjmp .
	nop
	rjmp .L18
.L22:
	cpi r28,lo8(2)
	brne .L18
	ldi r24,lo8(1)
	call read_adc
	rjmp .L28
	.size	main, .-main
	.ident	"GCC: (GNU) 5.4.0"
