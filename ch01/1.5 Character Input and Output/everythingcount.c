#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */

/* counts lines, words and characters in standard input */
int main()
{
	int c, lines, words, characters, state;	
	lines = words = characters = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
			if (c == '\n')
				++lines;
		else if (state == OUT) {
			state = IN;
			++words;
		}
		else
			++characters;
	}
	printf("%d lines, %d words, %d chars\n", lines, words, characters);
	return 0;
}
