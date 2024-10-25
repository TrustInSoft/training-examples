// {
//   "val-profile": "analyzer"
// }

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
