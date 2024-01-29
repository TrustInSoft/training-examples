// tis-analyzer -val -val-profile analyzer 0_is_zero.c -slevel-function f:10
// How to remove the false alarm?

#include <stdio.h>
#include <tis_builtin.h>

int f(int x) {
    int flag;
    if (x == 0) {
        printf("x == 0 (%d)\n", x);
        flag = 1;
    } else {
        printf("x != 0 (%d)\n", x);
        flag = 0;
        1 / x;
    }

    return flag;
}

int main(void) {
    int x = tis_interval(0, 10);
    int flag = f(x);
    0; // Empty statement to show things in the GUI. No other effects.

    if (flag == 1) {
        printf("x is zero! x == 0 (%d)\n", x);
    } else {
        printf("x is non-zero! x != 0 (%d)\n", x);
        1 / x;
    }
}
