// tis-analyzer -val -val-profile analyzer 1_init_buffer.c
// How to remove the false alarm?

#include <stdio.h>

int main(void) {
    char buffer[42];
    for (int i = 0; i < sizeof buffer; i++) {
        buffer[i] = i;
    }
    printf("%d\n", buffer[10]);
}
