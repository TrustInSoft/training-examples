// tis gui register
// gcc register.c -o /dev/null

#include <stdio.h>

int main(void) {
    // in C, register and auto are obsolete keywords, the analyzer ignores them
    auto int x = 4;
    register int y = 5;
    int z = x + y;

    printf("z = %d\n", z);

    // the analyzer does not detect these ; your compiler will
    int *px = &x; // not necessarily legal
    int *py = &y; // never legal
}
