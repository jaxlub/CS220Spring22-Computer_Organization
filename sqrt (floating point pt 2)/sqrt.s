
.global sqrt
.global fabs
.cpu cortex-a53
.fpu neon-vfpv4
.text

fabs:
	ldr r0, =zero
	vldr.f64 d1, [r0]	
	vcmp.f64 d0, d1
	vmrs APSR_nzvc, FPSCR //copy fp flags to int cpu
	bge end_fabs //bgt uses integer program status register
	ldr r0, =neg_one // load address of -1 into r0 
	vldr.f64 d1, [r0] // load -1 from r0 adress into d1	
	vmul.f64 d0, d0, d1 
end_fabs:	
	bx lr

sqrt:
	push { lr }
	vpush { d8, d9 }
	vmov.f64 d8, d0 //n
	vmov.f64 d9, d8 //r

while:
	//set up for fabs
	vmul.f64 d1, d9, d9 // r*r
	vsub.f64 d0, d8, d1 //(n - (r*r)
	bl fabs
	ldr r0, =epsilon
	vldr.f64 d2, [r0]
	vcmp.f64 d0, d2
	vmrs APSR_nzvc, FPSCR
	ble endwhile
	vdiv.f64 d2, d8, d9 //(n/r)
	vadd.f64 d2, d9, d2 // r + (n/r)
	ldr r0, =two
	vldr.f64 d3, [r0]	
	vdiv.f64 d9, d2, d3
	b while

endwhile:
	vmov.f64 d0, d9
	vmrs APSR_nzvc, FPSCR 
	vpop { d8 , d9 }
	pop { lr }
	bx lr 
	
.data
.align 3
neg_one: .double -1.0
zero: .double 0.0
epsilon: .double 0.00001
two: .double 2.0


