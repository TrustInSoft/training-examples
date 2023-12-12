// tis-analyzer -val -val-profile interpreter invalid_pointer.c

#include <stddef.h>
#include <stdio.h>

int read_p(int *p) {
    // Compilers can optimize this function to:
    // return *p;
    // https://gcc.godbolt.org/z/GeEqcM1sv

    int x = *p;
    if (p == NULL) {
        return 0;
    } else {
        return x;
    }
}

int main(void) {
    int x = 42;
    printf("x = %d\n", read_p(&x));
    printf("NULL → %d\n", read_p(NULL));
}
