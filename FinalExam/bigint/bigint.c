#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"
BigInt * make_int(const char *s){

	BigInt *b = malloc(sizeof(BigInt)); // new BigInt. malloc is equivilent of new in java
	//(*b).n = strlen(s); // size (n) = length of string
	b->n = strlen(s); //same thing as above^
	b->digits = malloc(b->n); // allocate enough area for digits array based on string size
	
	//copy digits from s into digits array
	for(int i = 0; i < b->n; i++){
		b->digits[i] = s[b->n -1 -i] - '0'; //set digits[i] = the string 
		//subtract out char 0 to get the actual number
	}
	return b;
}

BigInt * make_zero(int n){
	char tmp[n+1];
	memset(tmp,'0', n);
	tmp[n] = 0; //null terminating byte for string
	return make_int(tmp); // temp is on the stack and is freed when function returns.
}


BigInt * add (const BigInt *x, const BigInt *y){
	const BigInt *longer, *shorter;
	if(x->n > y->n){
		longer = x;
		shorter = y;
	} else {
		longer = y;
		shorter = x;
	}	
	
	BigInt *r = make_zero(longer->n + 1);
	int c = 0; // carry the 1 when adding
	int i = 0;
	while (i < shorter->n){
		byte s = shorter->digits[i] + longer->digits[i] + c;
		r->digits[i] = s % 10;
		c = s / 10;
		i++;
	}	
	//finish adding in rest of longer
	while(i < longer->n){
		byte s = longer->digits[i] + c;
		r->digits[i] = s % 10;
		c = s / 10;
		i++;
	}
	r->digits[i] = c;
	return r; 
}


void print_int(const BigInt *b){
	int leading_zero_bool = 0; // 0 = true, 1 = false	
	for(int i = b-> n - 1; i > -1 ; i --){
		if(b-> digits[i] != 0){ // if its not 0 print and change boolean as its not all 0's
			printf("%hhd", b->digits[i]);
			leading_zero_bool = 1;
		}
		if(leading_zero_bool == 1 && b-> digits[i] == 0){
			printf("%hhd", b->digits[i]);
		}
	}
	if(leading_zero_bool == 0){ // if this is true after for loop then big int is all 0s and only
					// one 0 should be printed. 
		printf("0");
	}

BigInt * mul10(const BigInt *x){
	BigInt *m = malloc(sizeof(BigInt)); 
	m->n = x->n+1; // new bigint, with size = olf BI+1 as multiplying by 10 only adds 1 digit 
		     // ex 75*10 = 750
	m->digits = malloc(m->n); // allocate enough memory for new bigInt based on size
	
	m->digits[0] = 0; //last digit is always 0 when multiplying by 10
	
	//copy digits from x into m digits array
	// i = 0 was already set to 0 so no need to loop it.
	for(int i = 1; i < m->n; i++){
		m->digits[i] = x->digits[i-1];
	}
	return m;
}

BigInt * div10(const BigInt *x){
	BigInt *d = malloc(sizeof(BigInt));
	d->n = x->n-1; //size of new big int has 1 less digit as dividing by 10 eleimates least sig
			// ex 75/10 = 7 
	d->digits = malloc(d->n); // allocate enough memory for new bigInt based on size
	for(int i = 0; i < d->n; i++){
		d->digits[i] = x->digits[i+1]; 
	// essentially logiically shifting x right by 1 tens place
	}
	return d;
}

byte mod10(const BigInt *x){
	return x->digits[0];
}

int checksum(const BigInt *x){
	int counter = 0;	
	for(int i = 0; i < x->n; i++){
		counter = (x->digits[i]-'0');
	}
	return counter;
}

}



