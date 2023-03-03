#include <stdio.h>
#include <assert.h>


unsigned invert(unsigned, int, int);

unsigned invert(unsigned x, int p, int n) {
    return ((~0 << (n+p-1)) + ~(~0 << (p-1)) & x) /*+ (~((x >> (p+1-n)) & ~(~0 << n)) << (n+p-1))*/;
}

int main() {
    printf("%d\n", invert(0b00101100, 4, 2));
    return 0;
}