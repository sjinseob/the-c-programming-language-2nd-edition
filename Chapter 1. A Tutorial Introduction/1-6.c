#include <stdio.h>

int main() {
	/* 
	 *	Sending an EOF signal to the terminal differs by operating 
	 *	system : for instance, on Linux and macOS (OS X) Terminal its 
	 *	character is <C-d>, while on Windows it is <C-z>.
	 */
	printf("Press a key to print a value\n");
	printf("%d\n", (getchar() != EOF));			/* 1 or 0 */
	return 0;
}
