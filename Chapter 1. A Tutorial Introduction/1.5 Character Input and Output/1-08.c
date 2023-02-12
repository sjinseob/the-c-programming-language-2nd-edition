#include <stdio.h>

int main() {
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

    char c = getchar();
    while (c != EOF) {
        if (c == ' ')
            blanks++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n')
            newlines++; 
        c = getchar();
    }

    printf("\n\n%d blanks, %d tabs, and %d newlines.", blanks, tabs, newlines);

    return 0;
}