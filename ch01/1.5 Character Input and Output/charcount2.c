#include <stdio.h>

/* counts number of characters in standard input */

main()
{
	double nc;
	for (nc = 0; getchar() != EOF; ++nc);		
	printf("%.0f\n", nc);
}