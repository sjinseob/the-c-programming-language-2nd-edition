#include <stdio.h>

void str_cat(char *s, char *t);

int main(void) {
    char s[] = "apple";
    char t[] = "banana";
    str_cat(s, t);
    printf("%s\n", s);
    return 0;
}

/* Pointer version of strcat, as stated in book. */
void str_cat(char *s, char *t) {
    while (*s != '\0')
        s++;
    while ((*s++ = *t++) != '\0')
        ;
}