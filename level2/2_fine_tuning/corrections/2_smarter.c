// tis-analyzer -val -val-profile analyzer corrections/2_smarter.c
//
// The initial issue was about removing a value from the middle of an interval,
// but the analyzer is capable of removing a value from the bounds of an
// interval.
//
// It allows for a simpler condition to be written, leveraging another split
// from the existing code.

#include <tis_builtin.h>

#define LARGE_NUMBER 10000

int main(void) {
    int x = tis_interval(-LARGE_NUMBER, LARGE_NUMBER);

    //@ slevel 2;
    //@ assert x < 0 || x >= 0;

    0; // Empty statement to show things in the GUI. No other effects.

    if (x == 0)
        return 0;

    return LARGE_NUMBER / x;
}
