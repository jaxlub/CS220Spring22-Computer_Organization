#include <stdio.h>
#include "sum3or5.h"
#include "sequence.h"
#include "verifyarg.h"
#include <stdlib.h>


int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Error: no number specified or too many specifications\n");
		return 0;
	}
	
	if(verifyarg(argv[1]) == 0){
		printf("Error: paramter entered contains an invalid character\n");
		return 0;
	}
   	printf("sum3or5 of 10 is %d and the sequence is %d\n", sum3or5(atoi(argv[1])), sequence(atoi(argv[1]))); // expect 23 and 7
}