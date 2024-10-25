// tis gui genstr3
// How to produce a properly generalized string with no unexpected '\0'?

#include <string.h>
#include <tis_builtin.h>

int main(void) {
    char buffer[101];
    for (size_t i = 0; i < sizeof buffer - 1; i++) {
        buffer[i] = tis_nondet(tis_interval(-128, -1), tis_interval(1, 127));
    }
    buffer[sizeof buffer - 1] = 0;
    size_t len = strlen(buffer); // We want 100 and only 100
}
