

.cpu cortex-a53
.global reverse
.text

reverse:
	push {r4, r5}
	cmp r0, #0 //if n == 0
	beq returnr //branch to return r if true
	lsr r4, r0, #1 // r4 = (n >> 1)
	lsl r1, #1 // r1 = (r << 1)
	and r5, r0, #1 //r5 = (n&1)
	and r1, r1, r5 // (r << 1) | (n&1)... r4 should have a 0 in least signifcant as it was j shifted
// and r5 should only by 1 digit so should be able to and them together.
	mov r0, r4 // set up for bl
	bl reverse

returnr:
	mov r0, r1
	pop {r4, r5}
	bx lr

