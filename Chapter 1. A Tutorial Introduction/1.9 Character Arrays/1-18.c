/* 
 *	Exercise 1-18:
 */
#include <stdio.h>
#define INDIV_LINE_SIZE	50000
#define BUFFER_SIZE	50000

int getLine(char s[]);

int main() {	
 	int i = 0, l = 0;
	char line[INDIV_LINE_SIZE];
 	char buffer[BUFFER_SIZE];

    /* Removes tabs '\t' and trailing whitespaces*/
	while ((l = getLine(line)) >= 0) {
		if (l > 0) {
			for (int j = 0; j < l; j++) {
                if (line[j] != '\t')
                    buffer[i++] = line[j];
            }
            while (line[i] == ' ')
                --i;
            buffer[i++] = '\n';
		}
	}
	buffer[i] = '\0';

	printf("%s\n", buffer); 
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