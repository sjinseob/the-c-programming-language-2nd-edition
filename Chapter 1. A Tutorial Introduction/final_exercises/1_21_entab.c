#include <stdio.h>

/*	Exercise 1-21. 
	Write a program entab that replaces strings of blanks by the 
	minimum number of tabs and blanks to achieve the same spacing. 
	Use the same tab stops as for detab. 
	When either a tab or a single blank would suffice to 
	reach a tab stop, which should be given preference?  */

#define TAB_WIDTH	4
#define MAXLINE 	1000
#define NOT_SPACE	0
#define IS_SPACE	1 

void entab(char output[]);	/* entabs input */

int main()
{
	char output[MAXLINE];	
	
	entab(output);
	printf("%s\n", output);
	return 0;
}

void entab(char output[])
{
	int i, c, s, space_length, tab_increment, state;
	tab_increment = space_length = i = 0;
	state = NOT_SPACE;

	while ((c = getchar()) != EOF) {
		if (tab_increment == TAB_WIDTH) {
			tab_increment = space_length = 0;
			state = NOT_SPACE;
		}
		if (c == ' ')  {
			state = IS_SPACE;
			if (tab_increment == TAB_WIDTH - 1) {
				if (space_length > 0) {
					output[i] = '\t';
					++i;
				}
				else {
					output[i] = ' ';	
					++i;
				}
			}
			++space_length;
		}
		else if (c != ' ') {
			if (state == IS_SPACE) {
				state = NOT_SPACE;
				for (s = 0; s < space_length; ++s) {
					output[i] = ' ';
					++i;
				}
				output[i] = c;
				++i;
			}
			else {
				output[i] = c;
				++i;
			}
		}
		++tab_increment;
	}
}
