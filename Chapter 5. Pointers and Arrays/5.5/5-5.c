#include <stdio.h>

/* strncpy, strncat, strncmp */

char *str_ncpy(char *s, char *ct, int n);
char *str_ncat(char *s, char *ct, int n);
int str_ncmp(char *cs, char *ct, int n);

int main() {
    char s[] = "Lorem Ipsum Mit Dolor...";
    char ct[] = "Morem Ipsum Mit Dolor...";
    // str_ncpy(s,ct,20);
    // str_ncat(s,ct,20);
    // printf("%s\n", s);
    printf("%d\n", str_ncmp(s, ct, 20));
    return 0;
}

char *str_ncpy(char *s, char *ct, int n) {
    while (n-- > 0) {
        if (*ct != '\0') *s++ = *ct++;
        else *s++ = '\0';
    }
    return s;
}

char *str_ncat(char *s, char *ct, int n) {
    while (*s != '\0') s++;
    while (n-- > 0 && *ct != '\0') *s++ = *ct++;
    *s = '\0';
    return s;
}

int str_ncmp(char *cs, char *ct, int n) {
    while (n-- > 0 && *cs == *ct)
        if (*cs == '\0')
            return 0;
    return *cs - *ct;
}