#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    printf("%d\n", strend("pineapple", "crapple"));
    return 0;
}

int strend(char *s, char *t)
{
    char *t_old = t;
    while (*s != '\0') s++;
    while (*t != '\0') t++;
    s -= t - t_old; 
    t = t_old;
    
    while (*t != '\0') {
        if (*s++ != *t++)
            return 0;
    }
    return 1;
}