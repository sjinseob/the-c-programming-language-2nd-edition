#include <stdio.h>
#include <assert.h>

int bitcount(unsigned);
/* 
 * Exercise 2-9.
 * In a two's complements system, x &= x-1 deletes the rightmost 1-bit.
 * 
 * If x were a number with the first bit set to 1, then the reason is straight-
 * forward: x will have the rightmost bit set to 1, while x-1 to 0, so the 
 * bitwise AND will yield xxxx...xx0, with 0 being the rightmost 1-bit.
 * 
 * However, if x has the rightmost bit set to 0, things get a little tricky.
 * Substracting 1 from 0 involves carrying; if the operation 0-1 is completed
 * on the rightmost bit, then the next digit in (x-1) will be set to 1 (if the
 * next digit in x is 0) or 0 (if the next digit in x is 1). If the result of
 * the carry is 0 then the carry-over to the next digit when subtracting stops.
 * 
 * So in (x-1) the carry will be performed from the right-most bit until the
 * digit in x is 1. Hence up to that digit, the bits between x and (x-1) will
 * be different and thus will yield a '0' after the bitwise AND. Since the 
 * digits of x and (x-1) will only differ up to (and including) the first '1'
 * from the right in x, the bitwise AND serves to strip this rightmost '1'.
 */

int bitcount(unsigned x) {
    int b = 0;
    while (x != 0) {
        x &= (x-1);
        b++;
    }
    return b;
}
int main() {
    printf("%d\n", bitcount(255));      // 8
    printf("%d\n", bitcount(8));        // 1
    return 0;
}