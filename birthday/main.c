#include "simulate.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	// TODO verify command line is all good. 
	int n = atoi(argv[1]);
	int sum = 0;
	int runs = atoi(argv[2]);
	for(int x = 0; x < runs; x++){
		sum = sum + simulate(n);
	}	 
	printf("%.2f\n", sum/(double)runs);
}