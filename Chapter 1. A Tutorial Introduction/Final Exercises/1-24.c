#include <stdio.h>

int main() {
    int curly = 0; int bracket = 0; int parent = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '{') curly++;
        else if (c == '[') bracket++;
        else if (c == '(') parent++;
        else if (c == '}') curly--;
        else if (c == ']') bracket--;
        else if (c == ')') parent--;
    }
    printf("%s\n", (curly == 0) && (bracket == 0) && (parent == 0) ? "Syntactically correct!": "Synctatically incorrect");
}