
/* 
 * Sequence functions to take a number and then returns the number of times
 * it must be minupulated to get to 1. Numbers are minipulated by odds get multiplied by 3 and
 * add one while even numbers are just divided by 2. This is repetaed till the inputed number is
 * equal to 1.
 */

extern int sequence(long long n);

/*
 * Longest takes no parameters and looks for the number that has the longest sequence (read above)
 * under 100000 and returns it. 
 */
extern int longest(void);