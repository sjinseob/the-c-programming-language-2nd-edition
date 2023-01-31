#include <stdio.h>

/*	Exercise 1-23. Write a program to remove all comments from a C program. 
	Don't forget to handle quoted strings and character constants properly. 
	C comments don't nest.	*/

#define MAXLINE				5000
#define COMMENT_STARTED		1
#define COMMENT_ENDED		0

void remove_comments();
int main()
{
	remove_comments();	
	return 0;
}

void remove_comments()
{
	int c, state;
	
	while ((c = getchar()) != EOF)  {
		if (c == '/') {
			c = getchar();
			if (c != '/' && c != '*') {
				putchar('/');
				putchar(c);
			}
			else {
				if (c == '*') {
					state = COMMENT_STARTED;
					while (state == COMMENT_STARTED) {
						while ((c = getchar()) != '*');
						if ((c = getchar()) == '/')
							state = COMMENT_ENDED;
					}
				}
				else if (c == '/')
					while ((c = getchar()) != '\n');
					putchar(c);
			}
		}
		else {
			putchar(c);
		}
	}
}
