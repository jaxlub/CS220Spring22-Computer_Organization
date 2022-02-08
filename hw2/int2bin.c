#include <stdio.h>
#include <string.h>

void int2bin(int n){
	char binary[50];
	int tracker = 0;	
	while(n > 0){	
		binary[tracker] = n % 2;
		tracker++;
		n = n / 2; 
	}
	binary[tracker] = '\0';
	char flip[tracker];
	for(int x = tracker+1; x > 0; x = x - 1){			
		flip[tracker-x] = binary[x];	
	}	
	for(int i = 0; i < tracker+1; i++){
		printf("%d", flip[i]);
	}
	printf("\n");
}




