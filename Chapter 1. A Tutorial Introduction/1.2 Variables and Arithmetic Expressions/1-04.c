/*
 * Exercise 1-4.
 *
 *  Write a program to print the corresponding Celcius to Fahrenheit
 *  table.
 */

#include <stdio.h>

int main()
{
	double upper, step;
	double celcius, fahr;
	
	upper = 300;
	step = 20;
	
	// HEADER
	printf("\n    F |     C\n");
	printf("—————————————\n");

	while (celcius <= upper) {
		fahr = (9.0/5.0 * celcius) + 32.0;
		printf("%5.0f | %5.1f\n", celcius, fahr);
		celcius += step;
	}
	printf("\n");
	return 0;
}
