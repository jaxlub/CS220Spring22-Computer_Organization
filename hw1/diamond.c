#include <stdio.h>

void diamond() {
int userInput = 0;


while(userInput >= 0){
	printf("Enter a non-negative odd int:");
	scanf("%d",&userInput);
	if(userInput <= -1){
		printf("Bye!");
		break;
	}
	for(int x = 1; x <= userInput; x= x+2){						
		for(int s = x; s < userInput; s = s+2){
			printf(" ");
		}
		for(int y = 0; y < x; y++){				
			printf("*");
		}
		printf("\n");
	}
	for (int z = userInput-2; z >= 0; z=z-2){
		for(int s = z; s < userInput; s = s+2){
			printf(" ");
		}
		for(int y = 0; y < z; y++){
			printf("*");
		}
		printf("\n");
	}
}
}