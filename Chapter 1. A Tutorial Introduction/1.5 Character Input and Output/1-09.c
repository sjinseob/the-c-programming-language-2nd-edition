#include <stdio.h>

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(c);
			/* skip to first letter w/o space */
			while ((c = getchar()) == ' '); 
		}
		putchar(c);
	}

	return 0;
}	