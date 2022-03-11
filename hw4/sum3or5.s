
//int sum3or5(int n){
//int tracker = 0;
//int index = 0;
//while (index < n){
//	if((index%3)==0){
//		tracker = tracker + index;
//	} else if((index%5)==0) {
//		tracker = tracker +index;
//	}
//	index++;
//}
//return tracker;
//}

.cpu cortex-a53
.global sum3or5
.text

mod: 
	sdiv r2, r0, r1
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr

sum3or5:
	push {r4-r8, lr}
	mov r4, #0 //tracker location and set starting value
	mov r5, #1 //index location and set starting value
	mov r6, r0 //n location to prevent clobbering
	mov r7, #3 //saved into register to be used in mod function
	mov r8, #5 //saved into register to be used in mod function

while:
	cmp r5, r6
	bge end
	mov r0, r5 //move index into r0 to set up for mod of 3
	mov r1, r7 //move 3 into r1 to set up for index%3
	bl mod // branch and link to mod function with index, 10
	cmp r0, #0 //compare the mod of the index 	
	bne check_five
	add r4, r4, r5
	add r5, r5, #1
	b while

	
check_five:	
	mov r0, r5 //move index into r0 to set up for mod of 5
	mov r1, r8 //move 5 into r1 to set up for index%5
	bl mod // mod of index %5
	cmp r0, #0 
	bne bwhile //if there equal go to add and add index to tracker otherwise advance here add 1 and rewhile
	add r4, r4, r5
	add r5, r5, #1
	b while

bwhile:
	add r5, r5, #1
	b while
	
end:
	mov r0, r4
	pop {r4-r8, lr}
	bx lr

