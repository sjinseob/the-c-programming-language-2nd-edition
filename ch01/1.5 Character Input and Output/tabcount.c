#include <stdio.h>

/* Exercise 1-8:
	counts number of tabs in standard input */

main()
{
	int c, tabcount;
	
	tabcount = 0;
	while ((c = getchar()) != EOF)
		if (c == '\t')
			++tabcount;
	
	printf("%d\n", tabcount);
}