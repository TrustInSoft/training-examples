// tis-analyzer -val -val-profile analyzer 2_absolute.c

#include <limits.h>
#include <tis_builtin.h>

int absolute(int a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

// test driver
int main(void) {
    int res;
    res = absolute(0);
    res = absolute(-13);
    res = absolute(42);

    res = absolute(tis_interval(-100, 100));

    // instead of edge case analysis
    // we test ALL possible values
    res = absolute(tis_interval(INT_MIN, INT_MAX));
}
