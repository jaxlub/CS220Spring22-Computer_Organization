//int sequence(long long n){
//int tracker = n;
//int counter = 1;   
//while(tracker != 1){
//	if((tracker%2)==0){
//		counter++;
//		tracker = tracker/2;
//	}else{
//		counter++;
//		tracker = (tracker*3) +1;
//	}
//}
//return counter;
//}
.cpu cortex-a53
.global sequence
.text

mod:
	sdiv r2, r0, r1
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr

sequence:
	push {r4, r5, r6, r7, lr}
	mov r4, r0 //tracker varible set equal to n
	mov r5, #1 // set up counter as 1
	mov r6, #2 // set up 2 for sdiv later
	mov r7, #3 // set up 3 for mul later
while:
	cmp r4, #1
	beq end 
	mov r0, r4 // set up mod for tracker%2
	mov r1, r6
	bl mod
	cmp r0, #0 //compare tracker%2 and 0
	bne else
	add r5, r5, #1 // add one to the counter
	sdiv r4, r4, r6	// tracker = tracker / 2
	b while

else:
	add r5, r5, #1 // add one to counter
	mul r4, r4, r7 //tracker *3
	add r4, r4, #1 // add one to tracker*3
	b while
	
end:
	mov r0, r5
	pop {r4, r5, r6, r7, lr}
	bx lr
