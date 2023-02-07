/*********************************************************************
	Ex.1-21 K&R <The C Programming Language, 2nd Edition>
	-----------------------------------------------------	
	This program replaces strings of blanks with the minimum number
	of tabs and blanks to achieve the same spacing.
	
	Example: 
	<assuming tabs are 4 spaces wide>
	hello   hello
 -> hello\thello	:: more economical to use a tab rather than use
					:: 3 spaces

	I Like Pie
 -> I Like Pie		:: better to use spaces - none of the words are
					:; on the tab stops!

	author: Jinseob Sohn
	e-mail: sjinseob@gmail.com
*********************************************************************/
#include <stdio.h>

#define TAB_WIDTH	4
#define NOT_SPACE	0
#define IS_SPACE	1 

int main(void)
{
	int c, s, space_length, tab_increment, state;
	tab_increment = space_length = 0;
	state = NOT_SPACE;

	while ((c = getchar()) != EOF) {
		if (tab_increment == TAB_WIDTH) {
			tab_increment = space_length = 0;
			state = NOT_SPACE;
		}
		if (c == ' ')  {
			state = IS_SPACE;
			if (tab_increment == TAB_WIDTH - 1) {
				if (space_length > 0)
					putchar('\t');
				else
					putchar(' ');	
			}
			++space_length;
		}
		else if (c != ' ') {
			if (state == IS_SPACE) {
				state = NOT_SPACE;
				for (s = 0; s < space_length; ++s)
					putchar(' ');
				putchar(c);
			}
			else
				putchar(c);
		}
		++tab_increment;
	}
	return 0;
}
