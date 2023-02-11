/* 
 *	Exercise 1-17:
 *	Write a program to print all input lines that are longer than 
 *	80 characters. 
 */
#include <stdio.h>
#define INDIV_LINE_SIZE	50000
#define BUFFER_SIZE	50000

int getLine(char s[]);

int main() {	
 	int i = 0, l = 0;
	char line[INDIV_LINE_SIZE];
 	char buffer[BUFFER_SIZE];

	/* Get a line, and if EOF is not reached, keep printing out all lines that exceed length 80 to the buffer. Maximum buffer size can be set as desired.*/
	while ((l = getLine(line)) >= 0) {
		if (l >= 80) {
			for (int j = 0; j < l; j++)
				buffer[i++] = line[j];
			buffer[i++] = '\n';
		}
	}
	buffer[i] = '\0';

	printf("%s\n", buffer); /* Final buffer must only contain lines exceeding 80 characters in length; print it out. */
	return 0;
}

/* Gets a line, then returns its length. */
int getLine(char s[]) {
	int i = 0;
	char c;
	while ((c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == EOF) return -1;
	return i;
}