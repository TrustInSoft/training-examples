// tis gui 2_always_zero
// How to remove the false alarm?
#include <tis_builtin.h>

int main(void) {
    int x = tis_interval(0, 10);
    int y = x;
    int z = x - y;
    if (z != 0)
        1 / 0;
}
