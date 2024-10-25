// corrections/1_smart.c
//
// The analyzer splits the states on any condition: this includes ACSL
// assertions. We isolate a 0 state that gets eliminated, all other values are
// still propagated to the end of the function. Note that we need SLevel,
// otherwise the states would get merged back immediately.
//
// A non-trivially true condition could affect the Value analysis, but a
// tautology is harmless.

#include <tis_builtin.h>

#define LARGE_NUMBER 10000

int main(void) {
    int x = tis_interval(-LARGE_NUMBER, LARGE_NUMBER);

    //@ slevel 3;
    //@ assert x < 0 || x == 0 || x > 0;

    0; // Empty statement to show things in the GUI. No other effects.

    if (x == 0)
        return 0;

    return LARGE_NUMBER / x;
}
