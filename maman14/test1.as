.define sz = 2
.entry LIST
.extern W
MAIN:	mov	r3,LIST[sz]
LOOP:	jmp	W
	prn	#-5
mov	STR[5],STR[2]
	sub	r1,            r4
	cmp	K,#sz
	bne	W
L1:	inc	L3
.entry LOOP
	bne	LOOP
END:		stop
.define len = 4
LIST: .data 6,-9,len
STR:	.string "ab"c:"def"
K:	.data 22
.extern L3
