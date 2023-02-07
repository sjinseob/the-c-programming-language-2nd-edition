#include <stdio.h>

/* Exercise 1-12:
	Program that prints its input one word per line */

int main() {
	int ch;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ')
			putchar('\n');	/* write to stdout as newline */
		else	
			putchar(ch);		/* write character to stdout */
	}
	return 0;
}