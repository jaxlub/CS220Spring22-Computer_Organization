#include <string.h>
#include <stdio.h>
#include "distance.h"

// pre-processor command
# define ZIPLEN 6 // lengh of a zipcode including null-terminating byte
# define STATELEN 3 // length of a state includinh null byte
# define CITYLEN 128 // length of a city 

int main(int argc, char *argv[]) {   
	
	// variables for location1
	char code1[ZIPLEN]; // zipcode for location 1
	char state1[STATELEN]; // state for location 1
	char city1[CITYLEN]; // city for location 1
	double lng1, lat1; // longitude latitude for location 1	
	
	char code2[ZIPLEN]; // zipcode for location 2 
	char state2[STATELEN]; // state for location 2
	char city2[CITYLEN]; // city for location 2
	double lng2, lat2; // longitude latitude for location 2	

	// check if right number of command line arguments is specified.
	if(argc < 3 || argc > 3){
		printf("Error: no file and/or zipcode specified or too many specifications\n");
		return 0;
	}

	char *fname = "../../CS220_data/zips.csv" ; // name of file
	char *key1 = argv[1]; // zipcode for location one
	char *key2 = argv[2]; //zipcode for location 2
	
	// open the zipcode file 
	FILE *f = fopen(fname, "r");
	if(f==NULL){
		printf("Error: file %s not found\n", fname); 
		return 0;	
	}	
	int locations_found = 0;
	while(locations_found != 2){
		// temporary variables to hold values and compare "code" in next 
		//if state-ments to key. 
		char code[ZIPLEN]; // zipcode for location
		char state[STATELEN]; // state for location
		char city[CITYLEN]; // city for location 
		double lng, lat; // longitude latitude for location		 	
		
		int rc =  fscanf(f, "%5s, %2s,%[^,],%lf,%lf", code, state, city, &lng, &lat);
		
		if (rc == EOF){
			printf("Error: zipcode was not found in file"); 
			return 0;			
		}

		// check if key zipcode is same as this lines zip for both locations
		// if it its then set all the varibles to the data at the temp variables and update the 
		if(strcmp(key1,code)==0){		
			strncpy(city1, city, CITYLEN);
			strncpy(state1, state, STATELEN);
			strncpy(code1, code, ZIPLEN);
			lng1 = lng;
			lat1 = lat;
			locations_found = locations_found + 1;
		}

		if(strcmp(key2,code)==0){		
			strncpy(city2, city, CITYLEN);
			strncpy(state2, state, STATELEN);
			strncpy(code2, code, ZIPLEN);
			lng2 = lng;
			lat2 = lat;
			locations_found = locations_found + 1;
		}
	}

//
	printf ("The distance between %s, %s and %s, %s is %lf\n", city1, state1, city2, state2, distance(lat1, lng1, lat2, lng2));
	
}