#include <stdio.h>

int power(int m, int n);
int powerR(int m, int n);

/* testing the power function */
int main()
{
	int i;
	for (i = 0; i < 20; ++i)
		printf("%d %d %d\n", i, powerR(2, i), powerR(-3, i));
	return 0;
}

/* power: raise base to the nth power */
int power(int base, int n)
{
	int i, p;
	p = 1;
	for (i = 0; i < n; ++i)
		p = p * base;
	return p;
}

/* powerR: raise base to nth power recursively */
int powerR(int base, int n)
{
	if (n == 0)
		return 1;
	else
		return base * power(base, n-1);
}