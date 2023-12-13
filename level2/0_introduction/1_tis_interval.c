// tis-analyzer -val -val-profile analyzer 1_tis_interval.c

#include <stdio.h>
#include <tis_builtin.h>

void f(int x) {
    if (x == 0) {
        printf("x == 0 (%d)\n", x);
    } else {
        printf("x != 0 (%d)\n", x);
    }
}

int main(void) {
    int x = 42;
    f(x);

    x = tis_interval(0, 10);
    f(x);
}
