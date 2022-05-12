#include "reverse.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	//TODO properly sanitize 	
	if(argc != 3){
		printf("Error: no number specified or too many specifications\n");
		return 0;
	}
	printf("%d\n", reverse(atoi(argv[1]),atoi(argv[2])));
}