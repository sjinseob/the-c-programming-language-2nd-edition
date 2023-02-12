#include <stdio.h>
#define MAXLINE 1000

int get_line(char *s, int lim);

int main() {
    char line[MAXLINE];
    printf("%d\n", get_line(line, MAXLINE));
    return 0;
}

int get_line(char *s, int lim) {
    int c, i;
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        *s = c;
    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
    
}