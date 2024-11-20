// tis-analyzer -val -val-profile analyzer 1_init_buffer.c
// How to remove the false alarm?

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

int main(void) {
    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) return 1;

    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = i;
    }
    printf("%d\n", buffer[10]);
}
