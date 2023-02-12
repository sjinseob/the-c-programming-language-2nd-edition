#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define BUFSIZE 1000

char buf[BUFSIZE];      /* buffer for ungetch*/
int bufp = 0;           /* next free position in buf */

// Function Declarations
int getch(void);
void ungetch(int);
int getfloat(float *pn);

int main()
{
    float num;
    getfloat(&num);
    printf("Final number: %f\n", num);
    return 0;
}

int getfloat(float *pn)
{
    printf("Initial state of num: %f\n", *pn);
    int c, sign;
    float f;

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
    if (c == '.') {
        if (!isdigit(c = getch())) {
            ungetch(c);
            return 0;
        }
        float multi = 1.0/10.0;
        for (f = 0.0; isdigit(c); c = getch()) {
            f += multi * (c - '0');
            multi *= 1.0/10.0;
        }
    }
    *pn += f;
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