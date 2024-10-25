// {
//   "val-profile": "analyzer"
// }

#include <stdlib.h>

int main(void) {
    int x = 0;

    while (rand() % 2 != 0)
        x++;

    int *p = malloc(sizeof (int));
    *p = x;

    return x;
}
