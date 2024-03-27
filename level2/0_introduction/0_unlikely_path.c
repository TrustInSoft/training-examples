// tis-analyzer -val -val-profile interpreter 0_unlikely_path.c
// tis-analyzer -val -val-profile analyzer 0_unlikely_path.c

#include <stdlib.h>

int main(void) {
    int x = 0;

    while (rand() % 2 != 0)
        x++;

    int *p = malloc(sizeof (int));
    *p = x;

    return x;
}
