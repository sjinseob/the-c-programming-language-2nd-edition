#include <stdio.h>

#define OVER	80
#define MAXLINE	1000

int getLine(char s[]);
void copy(char dest[], char orig[]);

/* Note: Strings in C are actually arrays of characters */

/* 
 *	Exercise 1-17:
 *	Write a program to print all input lines that are longer than 
 *	80 characters. 
 */
 
 /* main control flow */
int main()
{	
 	int i, length;
 	char currentLine[MAXLINE];     /* current line */
 	char longerthan80[MAXLINE];    /* line with more than 80 chars */
 	char allLinesOver80[10];       /* All lines more than 80 */
 	
 	for (i = 0; i < 10; ++i) {
 	   allLinesOver80[i] = '\0';
 	}
 	  
 	while ((length = getLine(currentLine)) > 0) {
 		if (length >= 80) {
 		   copy(longerthan80, currentLine);
 		   i = 0;
 		   while (longerthan80[i] != '\0') {
 		       putchar(longerthan80[i]);   /* write line to stdout */
 		       ++i;
 		   }
 		}
    }
    return 0;
}
 
/* Function that parses the current line, returns its length */
int getLine(char line[])
{
 	int i, c;
 	i = 0;
 	while (i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n') {
 		line[i] = c;
 		++i;
 	}
 	if (c == '\n') {
 		line[i] = c;
 		++i;
 	}
 	line[i] = '\0';
 	return i;
}
 
/* helper function for copying char array */
void copy(char to[], char from[]) {
 	int i;
 	i = 0;
 	
 	while ((to[i] = from[i]) != '\0')
 	   ++i;
 	return;
 }
 
 