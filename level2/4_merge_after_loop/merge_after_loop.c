// tis-analyzer -val -val-profile analyzer merge_after_loop.c
// How to get rid of the false alarm?

#include <string.h>
#include <tis_builtin.h>

int main(void) {
    char buffer[100];
    size_t len = tis_interval(0, sizeof buffer);
    memset(buffer, 1, len);
    int sum = 0;
    for (size_t i = 0; i < len; i++) {
        sum += buffer[i];
    }
    return sum;
}
