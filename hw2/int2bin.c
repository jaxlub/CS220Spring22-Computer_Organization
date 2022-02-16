#include <stdio.h>
#include <string.h>

void int2bin(int n){
	char binary[50];
	int tracker = 0;
	while(n > 0){	
		binary[tracker] = n&1;
		n = n / 2;
		tracker++; 
		
		
	}
	binary[tracker] = '\0';
	char flip[tracker];
	for(int x = tracker; x > 0; x = x - 1){			
		flip[tracker-x] = binary[x-1];	
	}	

	for(int i = 0; i < tracker; i++){
		printf("%d", flip[i]);
	}
	printf("\n");
}




