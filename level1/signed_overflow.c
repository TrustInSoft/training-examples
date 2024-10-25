// tis gui signed_overflow

#include <limits.h>
#include <stdio.h>

int saturating_increment(int x) {
    // Compilers can optimize this function to:
    // return x + 1;
    // https://gcc.godbolt.org/z/P7G6z6j3z

    // check for overflow
    if (x + 1 < x) {
        return x;
    }
    return x + 1;
}

int main(void) {
    printf("%d\n", saturating_increment(1));
    printf("%d\n", saturating_increment(INT_MAX));
}
