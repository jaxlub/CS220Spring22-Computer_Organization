// // Good James.
// Homework 1 Due Friday Jan 28th
// Jax Lubkowitz, CS220 Spring 22

// angle brackets around an header file indicate that
// it is a system header file.
#include <stdio.h>
#include "sum3or5.h"
#include "sequence.h"
#include "diamond.h"

int main(void){
   printf("sum3or5 of 10 is %d\n", sum3or5(10)); // expect 23
   printf("sum3or5 of 16 is %d\n", sum3or5(16)); // expect 16
   printf("sum3or5 of 1000 is %d\n", sum3or5(1000)); // expect 233168

   printf("sequence of 10 is %d\n", sequence(10)); // expect 7
   printf("longest sequence is %d\n", longest());

   diamond();
}
