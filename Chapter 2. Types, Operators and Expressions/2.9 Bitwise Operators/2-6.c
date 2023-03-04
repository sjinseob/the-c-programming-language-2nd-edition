#include <stdio.h>
#include <assert.h>

unsigned setbits(unsigned, int, int, unsigned);

/* setbits: returns x with the n bits that begin at position set to the rightmost n bits of y, leaving the other bits unchanged. */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // Isolate n bits from position p in unsigned x, shift the bits all the way to the right, and add it to y with the first n digits from position 0 turned to 0.
    return ((x >> (p+1-n)) & ~((unsigned) ~0 << n)) + (y & ((unsigned) ~0 << n));
}

int main() {
    assert(setbits(0b00101100, 3, 3, 0b10100010) == 166);
    assert(setbits(0b00101100, 3, 2, 0b10100010) == 163);
}