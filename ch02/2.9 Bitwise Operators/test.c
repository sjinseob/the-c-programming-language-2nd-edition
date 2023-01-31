#include <stdio.h>

int main()
{
	int n;
	n = 0177;	/* octal number 127 */
	printf("%d\n", n);
	n = ~n;
	printf("%d\n", n);
	return 0;
}
