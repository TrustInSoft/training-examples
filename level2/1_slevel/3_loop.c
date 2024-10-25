// tis gui 3_loop
// How to remove the false alarms?
#include <tis_builtin.h>

int main(void) {
    int a = 0, b = 0;
    // Set the i-th bit of a or b at each iteration
    for (int i = 0; i < 30; i++) {
        if (tis_nondet(0, 1))
          a += 1 << i;
        else
          b += 1 << i;
    }
    tis_show_each("", a, b);
}
