#include <stdio.h>

/*	Exercise 1-22. 
	Write a program to ''fold'' long input lines into two or more 
	shorter lines after the last non-blank character that occurs 
	before the n-th column of input. 
	Make sure your program does something intelligent with very 
	long lines, and if there are no blanks or tabs before the 
	specified column.  */

#define MAXLINE		5000
#define MAXWIDTH	80		/* fold threshold */
#define TAB_WIDTH	4		/* tab width */
#define IS_WORD		1
#define NOT_WORD	0

void fold(char s[]);		/* "folds" text */

int main()
{
	char current[MAXLINE];
	char output[MAXLINE];

	while ((l = getLine(current)) > 1)
		fold(current, output);
		printf("%s", output);
	return 0;				/* end program */
}

void fold(char current[], char output[])
{
	while ((c = current[i]) != 
}

int getLine(char s[])
{
	int i, c;
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
