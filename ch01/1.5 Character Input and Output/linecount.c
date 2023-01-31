#include <stdio.h>

/* counts number of lines in standard input */

main()
{
	int c, lines;
	
	lines = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++lines;
	printf("%d\n", lines);
}