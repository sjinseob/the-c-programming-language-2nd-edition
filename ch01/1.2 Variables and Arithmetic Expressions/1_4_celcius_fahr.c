/*
 * Exercise 1-4.
 *
 *  Write a program to print the corresponding Celcius to Fahrenheit
 *  table.
 */

#include <stdio.h>

int main()
{
	float upper, lower, step;
	float celcius, fahr;
	
	lower = 0;
	upper = 300
	step = 20;
	
	celcius = lower;
	printf("  C\t F\n");
	while (celcius <= upper) {
			fahr = (9.0/5.0 * celcius) + 32;
			printf("%3.0f %6.1f\n", celcius, fahr);
			celcius += step;
	}
	return 0;
}
