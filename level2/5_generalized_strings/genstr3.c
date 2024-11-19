// tis-analyzer -val -val-profile analyzer genstr3.c
// How to produce a properly generalized string with no unexpected '\0'?

#include <limits.h>
#include <string.h>
#include <tis_builtin.h>

int main(void) {
    char buffer[101];
    for (size_t i = 0; i < sizeof buffer - 1; i++) {
        buffer[i] = tis_nondet(tis_interval(CHAR_MIN, -1), tis_interval(1, CHAR_MAX));
    }
    buffer[sizeof buffer - 1] = 0;
    size_t len = strlen(buffer); // We want 100 and only 100
}
