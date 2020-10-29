.define sz = 2
MAIN:	mov	r9,LIST[sz]
LOOP:	jmp	L1
	prn	#-5
	mov	STR[TAL],STR[1]
	sub	r1,r4
	cmp	r3,,#sz
	cmp	STR[5] STR[3]
	bne	
L1:	inc	K
	bne	LOOP
END:		stop
mov#5, #6
.define len = A
.data 2, --9
LIST: .data 6,-9,len
STR:	.string "abcdef"ac
K:	.data 22A

