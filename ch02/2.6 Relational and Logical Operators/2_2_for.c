#include <stdio.h>

/*	Exercise 2-2. 
	Write a loop equivalent to the for loop above 
	without using && or ||.  */

/* 	Original for loop :
	for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;  */

int main()
{
	char s[10];
	int	i = 0;
	
	while (i < lim-1) {
		if ((c = getchar()) != '\n') {
			if (c != EOF)
				s[i] = c;
		}
	}

	return 0;	/* end program */
}
