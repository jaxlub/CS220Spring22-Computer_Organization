#include "digitsum.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 	
	printf("%d\n", digitsum(atoi(argv[1]))); //added the atoi and then had one of mov set ups
						 // to prevent clobbering moving r5 into r0 instead of 
						 // r0 into r5. 
}