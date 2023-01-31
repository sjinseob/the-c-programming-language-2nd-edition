#include <stdio.h>

/* copies input (getchar()) to output (putchar(c)) */

main()
{
	int c;
	
	while ((c = getchar()) != EOF)
		putchar(c);
}