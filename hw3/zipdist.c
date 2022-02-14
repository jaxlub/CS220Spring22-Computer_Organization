
//read a file of zipcode data and count the number of lines


#include <stdio.h>

// pre-processor command
# define ZIPLEN 6 // lengh of a zipcode including null-terminating byte
# define STATELEN 3 // length of a state includinh null byte
# define CITYLEN 128 // length of a city 

int main(int argc, char *argv[]) {   

	char code[ZIPLEN]; // zipcode
	char state[STATELEN]; // state
	char city[CITYLEN]; //city
	double lng, lat; //longitude latitude	
	unsigned int lc = 0; //line counter
	// open the zipcode file 
	FILE *f = fopen("../../CS220_data/zips.csv", "r");
	
	while(1){
	 	int rc =  fscanf(f, "%5s, %2s,%[^,],%lf,%lf", code,state,city,&lng,&lat);
		if (rc == EOF){
			break;
		}
		lc++;
	}
	printf("line count: %u\n",lc);
}