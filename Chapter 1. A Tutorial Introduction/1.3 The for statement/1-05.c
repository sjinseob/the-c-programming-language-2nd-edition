/*
 * 	Exercise 1-5.
 *	
 *	Modify the temperature conversion program to print the table in 
 *	reverse order, that is, from 300 degrees to 0.
 */

#include <stdio.h>

int main()
{
	double fahr;
	double upper, lower, step;
	
	upper = 300;
	lower = 0;
	step = 20;
	
	// HEADER
	printf("\n    F |     C\n");
	printf("—————————————\n");
	for (fahr = upper; fahr >= lower; fahr = fahr - step) {
			printf("%5.0f | %5.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
	}
	printf("\n");
	return 0;
}
