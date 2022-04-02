// static variables are stored in global memory
// local variables that dont go in registers are stored on stack
// read-modify-write operation is a fundemntal cs concept (ldr, modify, str).
// and thus ARM processor is called a load/store processor.


.global simulate
.cpu cortex-a53
.data //allocate global memory

// a word is the width in bytes of the nutural size of the machine (ie 32 bit machine)
// 4 bytes
seedhack: .word 0;

.text

mod: 
	sdiv r2, r0, r1
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr

simulate:
	push { r4-r9,lr }
	mov r6, #366
	mov r5, r0 // n

	
	//local varibales get stored on the stack if u cant put them in a register	
	sub sp, sp, r6, lsl #2 //shift r1(6?) by 2 and then substract (what does this do?)
	mov r7, sp //store starting addy of array in r7
	// static variables are allocated to global memory
	ldr r4, =seedhack //put addy of seedhack in r4
	
// read-modify-write
	ldr r8, [r4] //get the value of seedhack
	add r8, r8, #1 //increment seedhack by 1 
	str r8, [r4] // take r3 and put it back into memory at address
	
	// call "time"
	mov r0, #0
	bl time
	add r0, r8, r0
	bl srand

//set up call to memset
	mov r0, r7
	mov r1, #0
	mov r2, r6, lsl #2
	bl memset

	mov r9, #0 //r9 = i	
	
while1:
	cmp r9, r5 //while (i < n)
	bge end1
	bl rand //returns random number to r0
	mov r1, r6 //set up 366 for mod
	bl mod // rand % mod	
	// times 4 to get byte sizes
	add r0, r7, r0, lsl #2 // add random number times 4 to stack adress
	ldr r1, [r0] // access the value from r0 into r1
	add r1, r1, #1 // add one to the value accessed
	str r1, [r0] // push value back to array at the same location 
	add r9, r9, #1 // add 1 to the i
	b while1 // loop

end1:
	mov r9, #0 //reset the i counter for the next while loop
	b while2

while2:
	cmp r9, r6 //while(i < 366)
	bge end2
	 // get the number of bytes back from the start of array i is
	add r0, r7, r9, lsl #2 // add the stack pointer
	ldr r0, [r0] //access value at r0
	cmp r0, #1
	ble endif
	mov r0, #1
	b return
	

endif:
	add r9, r9, #1
	b while2

end2:
	mov r0, #0

return:
	
	add sp, sp, r6, lsl #2
	pop { r4-r9,lr}
	bx lr

	





