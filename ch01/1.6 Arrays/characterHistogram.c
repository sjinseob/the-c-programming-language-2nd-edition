/* 
 *	Exercise 1-14:
 *	Write a program to print a histogram of the frequencies of different 
 *	characters in its input.
 *	This version only takes cares of alphabet letters.
 */
	
#include <stdio.h>

#define CHAR_NUM	26

int main()
{
	int c, i, j;
	int nc[CHAR_NUM];
	for (i = 0; i < CHAR_NUM; i++) 
		nc[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if (c >= 'A' && c <= 'z') {
			if (c >= 'A' && c <= 'Z')		// uppercase characters
				++nc[c-'A'];
			else if (c >= 'a' && c <= 'z')	// lowercase characters
				++nc[c-'a'];
		}
	}
	
	/* Print histogram */
	printf("Number of characters:\n");
	for (i = 0; i < CHAR_NUM; i++) {
		printf("%c%c|| ", i+'A', i+'a');
		for (j = 0; j < nc[i]; j++) {
			printf("#");
		}
		printf("\n");
	}
	
	return 0;
}
