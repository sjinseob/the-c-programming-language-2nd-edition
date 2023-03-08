/*
 * Exercise 1-3.
 *
 * Modify the temperature conversion program to print a heading
 * above the table.
 */

#include <stdio.h>

int main()
{
	double fahr, celcius;
	double lower, upper, step;
	
	upper = 300.0;			/* higher limit of temperature scale */
	step = 20.0;			/* increment */
	

	// HEADER
	printf("\n    F |     C\n");
	printf("—————————————\n");

	while (fahr <= upper) {
			celcius = (5.0/9.0) * (fahr-32.0);
			printf("%5.0f | %5.1f\n", fahr, celcius);
			fahr += step;
	}
	printf("\n");
	return 0;
}
