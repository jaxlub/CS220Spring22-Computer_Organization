#include <stdio.h>
#include "f2c.h"

int main(argc, argv){
printf("%lf\n", f2c(32)); // freezing point - expect 0
printf("%lf\n", f2c(212)); // boiling point - expect 100
printf("%lf\n", f2c(20)); // sub-freezing - expect low neg number
}