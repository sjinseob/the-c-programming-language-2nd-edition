#include <stdio.h>

/* Exercise 1-10:
	replace each tab with '\t', each backspace with '\b',
	and each backslash with '\\' */
	
main()
{
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t') putchar('\\t');
		if (c == '\b') putchar('\\b');
		if (c == '\\') putchar ('\\\\');
		putchar(c);
	}
}		