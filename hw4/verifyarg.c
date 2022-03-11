#include <stdlib.h>
#include <string.h>

int verifyarg (char *n){
	int return_value = 1;	
	for(int x = 0; x < strlen(n); x++){
		if(!(n[x] >= '0' && n[x] <= '9')){
			return_value = 0;			
		}
	}
	return return_value;
}