#include "simulate.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define DAYS 366 - same thing as const



int simulate(int n){
	const int DAYS = 366; // declaring constant variable	
	int cal[DAYS];
	static int seedhack = 0; //static variable retains value and memory across function calls
	srand(time(NULL) + seedhack++);

	memset(cal, 0, DAYS*sizeof(int)); // int size can vary based off computer
	
	// assign n birthdays
	int i = 0;
	while(i<n){
		int bday = rand() % DAYS; //in assembly multipleby 4 to get address		
		cal[bday]++;
		i++;	
	}

	i = 0;
	while (i < DAYS){
		if(cal[i] > 1){
			return 1;
		}
		i++;
	}
	return 0;
}