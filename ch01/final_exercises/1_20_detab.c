#include <stdio.h>

/*  Exercise 1-20.
	Write a program detab that replaces tabs in the input with the 
	proper number of blanks to space to the next tab stop. 
	Assume a fixed set of tab stops, say every n columns. 
	Should n be a variable or a symbolic parameter?  */

#define TAB_WIDTH	4
#define MAXLINE		1000
	
void detab(char s[]);		/* detabs input */
	
int main()
{	
	char output[MAXLINE];	/* total text stream */
	
	detab(output);	
	printf("%s\n", output);
	return 0;				/* end program */
}

void detab(char output[])
{
	int i, c, tab_counter, loop;
	tab_counter = 0;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (tab_counter == TAB_WIDTH)
			tab_counter = 0;
		if (c == '\t') {
			loop = tab_counter;
			while (loop < TAB_WIDTH) {
				output[i] = ' ';
				++i;
				++tab_counter;
				++loop;
			}
		}
		else {
			output[i] = c;
			++tab_counter;
			if (c == '\n') 
				tab_counter = 0;
			++i;
		}
	}	
}
