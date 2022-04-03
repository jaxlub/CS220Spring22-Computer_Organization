#include "simulate.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

	if(argc != 3){
		printf("Error: no number specified or too many specifications\n");
		return 0;
	}
	

	int n = atoi(argv[1]);
	int sum = 0;
	int runs = atoi(argv[2]);
	for(int x = 0; x < runs; x++){
		sum = sum + simulate(n);
	}	 
	printf("%.2f\n", sum/(double)runs);
}