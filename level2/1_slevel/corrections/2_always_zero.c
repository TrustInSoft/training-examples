// tis-analyzer -val -val-profile analyzer corrections/2_always_zero.c -slevel 11
//
// Changes: tis_interval() -> tis_interval_split(), added SLevel.
//
// tis_interval_split() acts like tis_interval(), but each resulting value is
// put in a separate state. Each state is propagated independently, essentially
// in its own little analysis. tis_interval_split() does not raise the SLevel on
// its own: you need to also specify a high enough limit.

#include <tis_builtin.h>

int main(void) {
    int x = tis_interval_split(0, 10);
    int y = x;
    int z = x - y;
    if (z != 0)
        1 / 0;
}
