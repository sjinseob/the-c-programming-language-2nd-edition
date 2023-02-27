#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

/* Converts a string of hexademical digits to its equivalent integer value.*/
int htoi(char []);
/* Custom helper function that recursively calculates powers.*/
long bpow(long, long);

int main() {
    assert(1 == htoi("0X1"));
    assert(1 == htoi("0x1"));
    assert(1 == htoi("1"));
    assert(1984 == htoi("0x7C0"));
    assert(1984 == htoi("7C0"));
    assert(1984 == htoi("7c0"));
    assert(192382933 == htoi("0xB7787D5"));
    printf("All tests successful.\n");
    return 0;
}

/* Converts a string of hexademical digits to its equivalent integer value.*/
int htoi(char s[]) {
    int len = strlen(s);
    int final_result = 0;       // final converted number
    int final_string_i = 0;     // string traversal endpoint
    int hex_spec = ((s[1]-'x' == 0) || (s[1]-'X' == 0));  // check whether '0x' or '0X' is specified.
    if (hex_spec) final_string_i = 2;

    // Move through string, calculating number along the way.
    char c;
    for (int i = len-1; i >= final_string_i; i--) {
        c = s[i];
        if (isalpha(c)) {
            // Character indexed from string is a alphabetical letter.
            // Simple error checking whether the character in string is valid.
            assert((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
                if (c-'a' >= 0 && c-'a' <= 5)
                    final_result += (c-'a'+10) * bpow(16, len-1-i);
                else final_result += (c-'A'+10) * bpow(16, len-1-i);
        } else {
            // Character indexed from string is a numeral.
            // Simple error checking whether the numeral in string is valid.
            assert(c >= '0' && c <= '9');
            final_result += (c-'0') * bpow(16, len-1-i);
        }
    }
    return final_result;
}

/* Custom helper function that recursively calculates powers. */
long bpow(long x, long y) {
    long res = x;
    if (y == 0) return 1;
    return res * bpow(x, y-1); 
}