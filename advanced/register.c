// tis-analyzer -val -val-profile analyzer register.c
// gcc register.c -o /dev/null

#include <stdio.h>

int main(void) {
    // in C, register and auto are obsolete keywords, tis-analyzer ignores them
    auto int x = 4;
    register int y = 5;
    int z = x + y;

    printf("z = %d\n", z);

    // tis-analyzer does not detect these ; your compiler will
    int *px = &x; // not necessarily legal
    int *py = &y; // never legal
}
