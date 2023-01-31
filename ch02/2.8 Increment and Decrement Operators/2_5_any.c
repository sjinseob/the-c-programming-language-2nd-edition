#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	char s1[] = "abracadabra";
//	char s2[] = "z";		/* -1 */
//	char s2[] = "a";		/* 	0 */
//	char s2[] = "r";		/* 	2 */
//	char s2[] = "roast";	/*	0 */
	char s2[] = "boolean";	/*	0 */

	printf("%d\n", any(s1, s2));
	return 0;
}

/* 
 *	Returns the first location in string s1 where any
 *	character from string s2 occurs. Note that this 
 *	function is actually case-senstive!	
 */
int any(char s1[], char s2[])
{
	int min;
	int j, k;
	
	min = -1;
	k = 0;
	while (s2[k] != '\0') {
		j = 0;
		while (s1[j] != '\0') {
			if (s1[j] == s2[k]) {
				if (min == -1)
					min = j;
				else if (j < min)
					min = j;
			}
			++j;
		}
		++k;
	}
	return min;
}
