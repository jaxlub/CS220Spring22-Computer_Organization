# include <stdio.h>

void int2bin(int n){
// base case
if (n==0){
	printf("0");
} else {
	int2bin(n/2);
	printf("%d", n%2);
}
}