
typedef unsigned char byte;

typedef struct{ //like saying class in java
	byte *digits; //pointer to start of block of memory much like an array but with no size requirment
	int n; //length of array
} BigInt;

// make_int allocates memory for BigInt, it is the job of 
// the caller to free (deallocate) when done using it.
extern BigInt * make_int(const char *s);

extern void print_int(const BigInt *b);

extern BigInt * add(const BigInt *x, const BigInt *y);

extern BigInt * mul10(const BigInt *x);

extern BigInt * div10(const BigInt *x);

extern byte mod10(const BigInt *x);

extern int checksum(const BigInt *x);


