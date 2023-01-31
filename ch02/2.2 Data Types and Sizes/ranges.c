#include <stdio.h>

/*	short : 16 bits long
	int : 16 bits long
	long : 32 bits long
	char : 8 bits long
	(signed) : has negative values
	(unsigned) : only has positive values  */

long power(int base, int exp);
	
int main()
{
	printf("Range of...\n");
	printf("unsigned\n");
	printf("short = [0, %ld]\n", power(2, 16) - 1);
	printf("int = [0, %ld]\n", power(2, 16) - 1);
	printf("long = [0, %ld]\n", power(2, 32) - 1);
	printf("-----\n");
	printf("signed\n");
	printf("short = [%ld, %ld]\n", -power(2, 16) / 2, -1 + power(2, 16)/2);
	printf("int = [%ld, %ld]\n", -power(2, 16) / 2, -1 + power(2, 16)/2);
	printf("long = [%ld, %ld]\n", -power(2, 32) / 2, -1 + power(2, 32)/2);
	return 0;
}

long power(int base, int exp)
{
	if (exp == 0)
		return 1;
	return base * power(base, exp-1);
}
