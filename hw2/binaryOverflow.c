#include <stdio.h>
#include <limits.h>
int main(void){
	signed char i = 127;
	i = i + 1;
	signed char xx = 0x7F;
	printf("%d\n",i);

	int j = 0b01111111111111111111111111111111;
	int k = INT_MAX; //largest possible int
	int kk = 0x7FFFFFFF;
	printf("%d %d\n",j+1,k);

	unsigned int z = UINT_MAX;
	unsigned int zz = 0xFFFFFFFF;
	printf("z=%u zz=%d\n",z+1, zz);

	int w = 79;
	printf("%d",w*-1);
	printf("%d",-w);
	printf("%d",~w+1);

	int q = -1;
	int qq = 0xFFFFFFFF;
}