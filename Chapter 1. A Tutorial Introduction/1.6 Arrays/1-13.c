#include <stdio.h>

#define IN	1	/* inside word */
#define OUT 0	/* outside word */
#define MAXLENGTH	20	/* maximum supported length of words */

/* Exercise 1-13:
	Print a histogram of the lengths of words in the
	standard input. (Horizontal) */
	
void main()
{
	int c, i, j;
	int length, state;
	int wordLen[MAXLENGTH];
	
	/* Initialize histogram values to 0 */
	for (i = 0; i < MAXLENGTH; i++) 
		wordLen[i] = 0;
	
	/* Get lengths of all words */
	state = OUT;
	length = 0;
	while ((c = getchar()) != EOF) {		
		++length;	/* increment length of word */
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				++wordLen[length-2];
				length = 0;
			}
			length = 0;
		}
		else if (state == OUT) {
			state = IN;
		}				
		
	}
	printf("\n");
			
	/* Print histogram */
	printf("Number of words with length:\n");
	for (i = 0; i < MAXLENGTH; i++) {
		printf("%3d ", i+1);
		for (j = 0; j < wordLen[i]; j++) {
			printf("* ");
		}
		printf("\n");
	} 
}