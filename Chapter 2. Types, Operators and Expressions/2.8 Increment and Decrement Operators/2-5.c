#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Returns the first location in the first string where any character from the second string occurs. Returns -1 if no such character exists*/
int any(char *, char *);

int main() {
    assert(any("apple", "lx") == 3);
    assert(any("pear", "pineapple") == 0);
    assert(any("supercalifragilisticexpialidocious", "cali") == 5);
    assert(any("hippo", "bag") == -1);
    return 0;
}

int any(char *s1, char *s2) {
    // if a character from s2 is in s1, find its location in s1.
    char *c;
    for (int i = 0; i < strlen(s2); i++) {
        if ((c = strchr(s1, s2[i])) != NULL)
            return strlen(s1) - strlen(c);
    }
    return -1;
}
