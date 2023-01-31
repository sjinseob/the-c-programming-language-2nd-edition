/*********************************************************************
	Ex.1-22 K&R <The C Programming Language, 2nd Edition>
	-----------------------------------------------------	
	This program takes long lines of text and wraps them so that each
	line doesn't exceed a certain limit of characters.
	This behaviour is also present in text editors such as TextEdit 
	and Microsoft Word - if an input line reaches the end of the page
	/ window margin, the trailing word would be "folded" to the next
	line, thereby making text appear more clean and elegant.

	If an entire word is for some reason longer that the maximum line
	length (determined by FOLDTHRES), then the word is split so that 
	it can continue on without any problems.
	
	author: Jinseob Sohn
	e-mail: sjinseob@gmail.com
*********************************************************************/
#include <stdio.h>

#define FOLDTHRES	80
#define TABWIDTH	4
#define ENDWORD		0
#define STARTWORD	1

int main(void)
{	
	int c, d, i, l_line, l_word, state;
	i = l_word = l_line = 0;
	char wordbuffer[100];				// max length of word = 100
	state = STARTWORD;

	while ((c = getchar()) != EOF) {
		wordbuffer[i++] = c;
		// any of these characters would mean 
        // that the end of a word has been reached 
		if (c == ' ' || c == '\n' || c == '\t')
			state = ENDWORD;	                    
//		else if (c == '\n' || c == '\t') {
//			state = ENDWORD;
//			++l_word; // increment word length
//		}
		else
			++l_word; 

		if (state == ENDWORD) {
//			if (c == '\n') {
//				printf("NEWLINE");
//				l_line = 0;
//			}
			if (c == '\t')
				l_line += TABWIDTH;
			printf("w:%d ", l_word);
			printf("l:%d ", l_line);
			i = 0;
			// if the word might exceed the fold limit, then insert a newline
			// before so that it may continue on the next line
			if (l_line + l_word > FOLDTHRES) {	
				putchar('\n');                  
				l_line = 0;                     
			}                                   

			while ((d = wordbuffer[i++]) != ' ' && d != '\n' && d != '\t') {		
				// if the actual word is bigger than the entire line, split the
				// word so that it can span many lines
				if (l_word > FOLDTHRES && i % FOLDTHRES == 0) {	
					putchar('\n');                                  
					l_line = 0;                                     
				}                                                   
				putchar(d);
				++l_line;
			}
			if (c == '\n') {
//				printf("NEWLINE");
				l_line = 0;
			}
			if (c == '\t')
				l_line += TABWIDTH;

			state = STARTWORD;
			putchar(d);
//			++l_line;
			i = l_word = 0;
		}
	}

	return /* comment inside return statement */ 0;
}
