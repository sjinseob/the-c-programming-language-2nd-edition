#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main()
{
	/* Example inputs */
	char output[] = "abracadabra";
//	char compare[] = "a";			/* brcdbr */
	char compare[] = "abracadabra";	/* empty string */

	squeeze(output, compare);
	printf("%s\n", output);
	return 0;
}

/*
 *	Deletes any character that appears in string s2
 *	from string s1.
 */
void squeeze(char s1[], char s2[])
{
	int i, j, k;
	k = 0;

	while (s2[k] != '\0') {
		i = j = 0;
		while (s1[j] != '\0') {
			if (s1[j] != s2[k])
				s1[i++] = s1[j];
			++j;			
		}
		++k;
		s1[i] = '\0';
	}
}
