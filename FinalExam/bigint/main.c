#include "bigint.h"
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char *argv[]){
	//TODO sanitize command line
	if(argc != 2){
		printf("Error: no number specified or too many specifications\n");
		return 0;
	}
	BigInt *x = make_int(argv[1]);
	BigInt *z = mul10(x);	
	print_int(z);
	BigInt *c = div10(x);
	print_int(c);
	printf("%c\n", mod10(x));
	printf("%d\n", checksum(x));
	free(z);
	free(c);	
	free(x);
	return 0;
}