// tis-analyzer -val -val-profile analyzer imprecise.c
// Hot to get rid of the false alarm?

#include <tis_builtin.h>

#define LARGE_NUMBER 10000

int main(void) {
    int x = tis_interval(-LARGE_NUMBER, LARGE_NUMBER);

    if (x == 0)
        return 0;

    return LARGE_NUMBER / x;
}
