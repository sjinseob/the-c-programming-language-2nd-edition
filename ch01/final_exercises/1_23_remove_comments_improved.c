/*********************************************************************
	Ex.1-23 K&R <The C Programming Language, 2nd Edition>
	-----------------------------------------------------	
	This program removes all comments from a C program.
	Works for both block comments and single line comments!	

	author: Jinseob Sohn
	e-mail: sjinseob@gmail.com
*********************************************************************/
#include <stdio.h>

#define COMMENT_STARTED		1
#define COMMENT_ENDED		0
#define LINE_FULL			1
#define LINE_EMPTY			0

int main(void)
{
	int c, state, lstate;
	
	while ((c = getchar()) != EOF)  {

		if (c == '\n')
			lstate = LINE_EMPTY;
		if (c != '\n' && c != '\t' && c != '/' && c != '*')
			lstate = LINE_FULL;

		if (c == '/') {
			c = getchar();
			// not a comment - just a solitary forward slash 
			if (c != '/' && c != '*') {
				putchar('/');
				putchar(c);
			}
			else {
				// multi-line comment
				if (c == '*') {
					state = COMMENT_STARTED;
					while (state == COMMENT_STARTED) {
						// keep searching until end of comment is found
						while ((c = getchar()) != '*');
						if ((c = getchar()) == '/')
							state = COMMENT_ENDED;
					}
				}
				// single-line comment
				else if (c == '/') {
					// keep searching until newline is found
					while ((c = getchar()) != '\n');
					if (lstate == LINE_FULL)
						putchar('\n');
					else
						putchar('\r');
				}
			}
		}
		else
			putchar(c);
	}
	return 0;
}
