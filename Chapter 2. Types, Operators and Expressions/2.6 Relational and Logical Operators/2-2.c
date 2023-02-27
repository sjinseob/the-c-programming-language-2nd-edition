#include <stdio.h>

int main() {
    // For loop without && or || operators
    // for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    //    s[i] = c;
    // ————————————————————————————————————————————————————————————————————————
    // for (i=0; i < lim-1; ++i) {
    //     if ((c=getchar()) != '\n') {
    //         if (c != EOF) {
    //             s[i] = c;
    //         } else break;
    //     } else break;
    // }
    return 0;
}