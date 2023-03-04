#include <stdio.h>
#include <assert.h>
#define INT_BITCT   4
unsigned rightrot(unsigned, int);

/* rightrot: returns the value of x rotated to the right by n bits. (assuming x is a INT_BITCT-bit integer) */
unsigned rightrot(unsigned x, int n) {
    return ((x << (INT_BITCT - n)) & ~((unsigned) ~0 << INT_BITCT)) | (x >> n);
}

int main() {
    printf("%u\n", rightrot(0b0001, 1));  // 144
    return 0;
}