/*  
 *	Exercise 1-20.
 *
 *	Write a program detab that replaces tabs in the input with the 
 *	proper number of blanks to space to the next tab stop. 
 *	Assume a fixed set of tab stops, say every n columns. 
 *	Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>

#define TAB_WIDTH	4
	
void detab();		/* detabs input */
	
int main(void)
{	
	detab();
	return 0;				/* end program */
}

void detab()
{
	int c, tab_counter, loop;
	tab_counter = 0;
	while ((c = getchar()) != EOF) {
		if (tab_counter == TAB_WIDTH)
			tab_counter = 0;
		if (c == '\t') {
			loop = tab_counter;
			while (loop < TAB_WIDTH) {
				putchar(' ');
				++tab_counter;
				++loop;
			}
		}
		else {
			putchar(c);
			++tab_counter;
			if (c == '\n') 
				tab_counter = 0;
		}
	}	
}
