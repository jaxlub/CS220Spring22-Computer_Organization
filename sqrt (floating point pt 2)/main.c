#include <stdio.h>
#include <stdlib.h>
#include "sqrt.h"
#include "pow.h"
int main(int argc, char * argv[]){
	if (argc == 2){
		printf("%f\n", sqrt(atof(argv[1])));	
	} else if (argc == 3){
		printf("%d\n", mypow(atoi(argv[1]), atoi(argv[2])));	
	} else {		
		printf("invalid number of arguments entered");
		return 1;
	}
	return 0;
}