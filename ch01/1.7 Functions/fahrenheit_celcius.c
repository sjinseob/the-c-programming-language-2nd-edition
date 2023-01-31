#include <stdio.h>

#define UPPER	300.0
#define LOWER 	0.0
#define STEP	20.0

float toCelcius(float F);
float toFahrenheit(float C);

/* Testing functions */
int main()
{
	float i;
	for (i = LOWER; i < UPPER; i += STEP)
		printf("%3.0f %6.1f\n", i, toCelcius(i));
	return 0;
}

float toCelcius(float fahr) 
{
	return (5.0/9.0) * (fahr-32.0);
}

float toFahrenheit(float celcius) 
{
	return (9.0/5.0 * celcius) + 32;
}