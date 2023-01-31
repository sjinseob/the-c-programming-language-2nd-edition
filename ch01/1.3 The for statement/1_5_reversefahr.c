/*
 * 	Exercise 1-5.
 *	
 *	Modify the temperature conversion program to print the table in 
 *	reverse order, that is, from 300 degrees to 0.
 */

#include <stdio.h>

int main()
{
	float fahr;
	float upper, lower, step;
	
	upper = 300;
	lower = 0;
	step = 20;
	
	printf("  F\t C\n");
	for (fahr = upper; fahr >= lower; fahr = fahr - step) {
			printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
	}
	return 0;
}
