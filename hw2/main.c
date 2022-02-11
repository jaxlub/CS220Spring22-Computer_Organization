// int2bin doesn't seem to work? Try and get started earlier Jax.
// So you can stop in and ask questions. 10/20
#include "int2bin.h"
#include <stdio.h>

int main(void){	
	int userInput = 0;
	int boolean = 0; // 0 = true, 1 = false; true when number is positive integer.
	printf("Enter an Int:");
	scanf("%d",&userInput);
	if (userInput <= 0){
			boolean = 1;
			printf("Bye!");
		} 
	while (boolean == 0){
		if (userInput <= 0){
			boolean = 1;
			printf("Bye!");
			break;
		} 
		int2bin(userInput);
		//printf("\n");			
		printf("Enter an Int:");
		scanf("%d",&userInput);
	}

}
