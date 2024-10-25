// tis gui 1_init_buffer
// How to remove the false alarm?

#include <stdio.h>

int main(void) {
    char buffer[42];
    for (int i = 0; i < sizeof buffer; i++) {
        buffer[i] = i;
    }
    printf("%d\n", buffer[10]);
}
