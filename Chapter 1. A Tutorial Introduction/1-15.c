#include <stdio.h>

#define UPPER	300.0
#define LOWER 	0.0
#define STEP	20.0

double toCelcius(double F);
double toFahrenheit(double C);

/* Testing functions */
int main() {
	double i;
	/* HEADER */
	printf("\n    F |     C\n");
	printf("—————————————\n");
	for (i = LOWER; i < UPPER; i += STEP)
		printf("%5.0f | %5.1f\n", i, toCelcius(i));
	return 0;
}

double toCelcius(double fahr) {
	return (5.0/9.0) * (fahr-32.0);
}

double toFahrenheit(double celcius) {
	return (9.0/5.0 * celcius) + 32;
}