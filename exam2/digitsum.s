.cpu cortex-a53 
.global digitsum
.text

mod: 
sdiv r2, r0, r1
mul r2, r2, r1
sub r0, r0, r2
bx lr

digitsum:
push {r4, r5, r6, lr}
mov r0, r5 //move r0 into r5 to prevent clobbering
mov r4, #0 // set up a counter for the total sum
mov r6, #10 //for mod stuff and sdiv
while:
cmp r5, #0
ble end
mov r1, r6 //move 10 into r1 to set up a mod 10
bl mod
add r4, r4, r0 //move into r4 the sum of r4 and the returned mod thus incrementing sum
sdiv r0, r5, r6 //chop off the last digit by dividing by 10 (ex 123/10 = 12)
mov r5, r0 // update the unclopperable updated tracker of the input 
bl while
end:
mov r0, r4 //move the addition tracker into r0 in order to return 
pop {r4, r5, r6, lr}
bx lr



