#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 1000

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

// Function Declarations
int getch(void);
void ungetch(int);
int getint(int *pn);

int main()
{
    int num;
    getint(&num);
    printf("Final number: %d\n", num);
}

int getint(int *pn)
{
    printf("Initial state of num: %d\n", *pn);
    int c, sign;

    while (isspace(c = getch()));    /* skip whitespace */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number*/
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        if (!isdigit(c = getch())) {
            ungetch(c);
            ungetch((sign == 1) ? '+' : '-');
            return 0;
        }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void) /* Get a (possibly pushed-back) character. */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* Push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}