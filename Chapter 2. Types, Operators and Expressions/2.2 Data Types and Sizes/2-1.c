#include <stdio.h>
#include <limits.h>
#include <math.h>

long bpow(long, long);

int main() {
    printf("Implementation defined:\n");
    printf("Range of unsigned char: 0 to %d\n", UCHAR_MAX);
    printf("Range of unsigned short: 0 to %d\n", USHRT_MAX);
    printf("Range of unsigned int: 0 to %u\n", UINT_MAX);
    printf("Range of unsigned long: 0 to %lu\n", ULONG_MAX);
    printf("Range of signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of signed long: %ld to %ld \n", LONG_MIN, LONG_MAX);

    printf("\nDirect Computation (binary to dec computation):\n");
    unsigned char u_c = 0;
    for (int i = 0; i < sizeof(unsigned char) * 8; i++)
        u_c += bpow(2, i);
    printf("Range of unsigned char: 0 to %d\n", u_c);
    unsigned int u_s = 0;
    for (int i = 0; i < sizeof(unsigned short) * 8; i++)
        u_s += bpow(2, i);
    printf("Range of unsigned short: 0 to %d\n", u_s);
    unsigned int u_i = 0;
    for (int i = 0; i < sizeof(unsigned int) * 8; i++)
        u_i += bpow(2, i);
    printf("Range of unsigned int: 0 to %u\n", u_i);
    unsigned long u_l = 0;
    for (int i = 0; i < sizeof(unsigned long) * 8; i++)
        u_l += bpow(2, i);
    printf("Range of unsigned long: 0 to %lu\n", u_l);
    signed char s_c = 0;
    for (int i = 0; i < sizeof(signed char) * 8 - 1; i++)
        s_c += bpow(2, i);
    printf("Range of signed char: %ld to %d\n", (-1)*bpow(2, sizeof(signed char)*8-1), s_c);
    signed short s_s = 0;
    for (int i = 0; i < sizeof(signed short) * 8 - 1; i++)
        s_s += bpow(2, i);
    printf("Range of signed short: %ld to %d\n", (-1)*bpow(2, sizeof(signed short)*8-1), s_s);
    signed int s_i = 0;
    for (int i = 0; i < sizeof(signed int) * 8 - 1; i++)
        s_s += bpow(2, i);
    printf("Range of signed int: %ld to %d\n", (-1)*bpow(2, sizeof(signed int)*8-1), s_i);
    signed long s_l = 0;
    for (int i = 0; i < sizeof(signed long) * 8 - 1; i++)
        s_l += bpow(2, i);
    printf("Range of signed long: %ld to %ld\n", (-1)*bpow(2, sizeof(signed long)*8-1), s_l);
    return 0;
}

/* Custom helper function that recursively calculates powers. */
long bpow(long x, long y) {
    long res = x;
    if (y == 0) return 1;
    return res * bpow(x, y-1); 
}