
.cpu cortex-a53
.global mypow
.text

mod:
	sdiv r2, r0, r1
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr

mypow:
	push { r5,r6,r7, lr }
	mov r5, r0 // r5 = x
	mov r6, r1 // r6 = y
	mov r7, #2 //for sdiv

	cmp r6, #0 //base case, y=0
	beq ifzero

	cmp r6, #1 //base case, y=1
	beq ifone

	//set up for next if statement
	//set up for mod
	mov r0, r6
	mov r1, r7
	bl mod // y%2 in r0
	cmp r0, #0 //if( (y%2) == 0)
	bne else //branch to else if not even
	sdiv r1, r6, r7 //y/2
	mov r0, r5 // move x into r0 for set up
	bl mypow
	mul r0, r0, r0 // mypow(x, (y/2)) ^ 2 into r0
	pop { r5,r6, r7,lr }
	bx lr
	
ifzero:
	mov r0, #1
	pop { r4, r5,r6, r7, lr }
	bx lr

ifone:
	mov r0, r5
	pop { r5,r6, r7, lr }
	bx lr

else: 
	sub r1, r6, #1 //sub 1 from y and put into r1 for setup of mypow
	mov r0, r5 // set up my pow by moving x into r0
	bl mypow // whoopie recursion 
	mul r0, r0, r5 //multiply by x
	pop { r5,r6, r7, lr }
	bx lr

	