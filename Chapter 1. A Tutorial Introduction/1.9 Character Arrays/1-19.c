#include <stdio.h>

#define MAXLEN	1000		/* maximum supported length for string */

int getLine(char str[]);
void reverse(char in[], char out[]);

/* Exercise 1-19
	Write a function reverse(s) that reverses the character
	string s. */
	
/* main control flow */
int main()
{	
	char input[MAXLEN];
	char reversedString[MAXLEN];
	int length;
	
	/* general flow of program */
	while ((length = getLine(input)) > 0) {			// get input line
		reverse(input, reversedString);				// reverse input line
		printf("reversed: %s\n", reversedString);	// stdout
	}
	
}

/* function that receives input - returns input length */
int getLine(char str[]) 
{
	int c, i;
	
	/* get input from user */
	i = 0;
	while (i < MAXLEN-2 && (c = getchar()) != EOF && c != '\n') {
		str[i] = c;
		++i;
	}
	if (c == '\n' && c != EOF) {
		str[i] = c;	/* manually add newline character */
		++i;
	}
	str[i] = '\0';	/* end of string */
	
	return i;		/* return length of string */
}
	
/* reverses a character array */
void reverse(char orig[], char result[])
{
	int i, length;
	
	i = 0;
	while (orig[i] != '\0')
		++i;	
	i -= 2;			// length of character excluding \n, \0
	length = i;
	while (i >= 0) {
		result[-(i - length)] = orig[i];	/* reverse the string */
		--i;
	}
	result[length + 1] = '\0';
	
	return;
}