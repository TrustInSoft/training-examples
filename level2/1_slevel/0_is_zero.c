// tis gui 0_is_zero
// How to remove the false alarm?

#include <stdio.h>
#include <tis_builtin.h>

void f(int x) {
    int flag;
    if (x == 0) {
        printf("x == 0 (%d)\n", x);
        flag = 1;
    } else {
        printf("x != 0 (%d)\n", x);
        flag = 0;
        1 / x;
    }
    0; // Empty statement to show things in the GUI. No other effects.
    if (flag == 1) {
        printf("x is zero! x == 0 (%d)\n", x);
    } else {
        printf("x is non-zero! x != 0 (%d)\n", x);
        1 / x;
    }
}

int main(void) {
    int x = tis_interval(0, 10);
    f(x);
}
