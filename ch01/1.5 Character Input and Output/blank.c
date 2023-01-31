#include <stdio.h>
	
/* Exercise 1-9:
	replace one or more blanks by a single blank */

main()
{
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(c);
			/* skip to first letter w/o space */
			while ((c = getchar()) == ' '); 
		}
		putchar(c);
	}
}	