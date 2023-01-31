#include <stdio.h>

/* Exercise 1-8:
	counts number of spaces in standard input */

main()
{
	int c, spacecount;
	
	spacecount = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ')
			++spacecount;
	
	printf("%d\n", spacecount);
}