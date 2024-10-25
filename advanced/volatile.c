// tis gui volatile
//
// Volatile variables are assumed to be always generalized, even after an
// assignment. To control this behavior, use `-remove-volatile` or the Volatile
// plugin.

#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

int main(void) {
    volatile int x = 42;
    printf("x = %d\n", x);
#ifdef __TRUSTINSOFT_ANALYZER__
    tis_show_each("x", x);
#endif

    x = x / 2;

    x = 10;
    printf("x = %d\n", x);
#ifdef __TRUSTINSOFT_ANALYZER__
    tis_show_each("x", x);
#endif

    int y = x;
    // y is a regular variable, its value can be changed.
    y = 10;
    printf("y = %d\n", y);
#ifdef __TRUSTINSOFT_ANALYZER__
    tis_show_each("x", x);
#endif
}
