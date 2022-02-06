#include "int2bin.h"
#include <stdio.h>

int main(void){
	int userInput = 0;
	int boolean = 0; // 0 = true, 1 = negative; true when number is positive integer.
	printf("Enter an Int:");
	scanf("%d",&userInput);
	while (boolean == 0){
		if (userInput <= 0){
			boolean = 1;
			printf("Bye!");
			break;
		} 
		int2bin(userInput);
		printf("\n");			
		printf("Enter an Int:");
		scanf("%d",&userInput);
	}

}