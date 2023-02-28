#include <stdio.h>
#include <string.h>
#include <assert.h>

void squeeze(char *, char *);

int main() {
    char s1[] = "apple";
    char s2[] = "supercalifragilisticexpialidocious";
    squeeze(s1, s2);
    assert(strcmp(s1, "") == 0);   // Done.
    return 0;
}

void squeeze(char *s1, char *s2) {
    int i, j;
    char *c;
    for (i=j=0; s1[i] != '\0'; i++) {
        if ((c = strchr(s2, s1[i])) == NULL)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}