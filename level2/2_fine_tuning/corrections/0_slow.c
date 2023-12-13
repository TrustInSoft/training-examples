// tis-analyzer -val -val-profile analyzer corrections/0_slow.c
//
// Changes: tis_interval() -> tis_interval_split(), slevel ACSL directive
//
// The slevel directive applies until the next slevel directive, or the end of
// the function. "@ slevel default;" would revert to the local or global SLevel.

#include <tis_builtin.h>

#define LARGE_NUMBER 10000

int main(void) {
    //@ slevel 2 * LARGE_NUMBER + 1;
    int x = tis_interval_split(-LARGE_NUMBER, LARGE_NUMBER);

    if (x == 0)
        return 0;

    return LARGE_NUMBER / x;
}
