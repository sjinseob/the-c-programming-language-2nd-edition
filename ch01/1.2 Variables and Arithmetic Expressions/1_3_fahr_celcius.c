/*
 * Exercise 1-3.
 *
 * Modify the temperature conversion program to print a heading
 * above the table.
 */

#include <stdio.h>

int main()
{
	float fahr, celcius;
	float lower, upper, step;
	
	lower = 0.0;			/* lower limit of temperature scale */
	upper = 300.0;			/* higher limit of temperature scale */
	step = 20.0;			/* increment */
	
	fahr = lower;
	printf("  F\t C\n");
	while (fahr <= upper) {
			celcius = (5.0/9.0) * (fahr-32.0);
			printf("%3.0f %6.1f\n", fahr, celcius);
			fahr += step;
	}
	return 0;
}
