#include "sqrt.h"

double fabs(double n){
	if( n < 0){
		n = -n;
	}
	return n;
}

#define epsilon .00001

double sqrt(double n){
	
	double r = n; // initial guess
	
	while (fabs(n -  r*r) > epsilon){
		r = (r + n/r) / 2.0;
	}

	return r;
}