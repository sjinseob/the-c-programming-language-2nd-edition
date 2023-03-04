#include <stdio.h>
#include <assert.h>


unsigned invert(unsigned, int, int);

/* invert: returns x with the n bits that begin at position p inverted, leaving the others unchanged. */
unsigned invert(unsigned x, int p, int n) {
    return (((unsigned) ~0 << (p+1)) + ~((unsigned) ~0 << (p+1-n)) & x) + ~((((unsigned) ~0 << (p+1)) + ~(~0 << (p+1-n))) | x);
}

int main() {
    assert(52 == invert(0b00101100, 4, 2));
    assert(60 == invert(0b00101100, 4, 1));
    assert(50 == invert(0b00101100, 4, 4));
    return 0;
}