// tis gui out_of_bounds
// This a 1-char typo, could easily be missed in a code review.

#include <stdio.h>

int authorized_ids[4] = {0, 1, 2, 3};

int is_authorized(int id) {
    // Compilers can optimize this function to:
    // return 1;
    // https://gcc.godbolt.org/z/vq94xhfTM

    for (int i = 0; i <= 4; i++) {
        if (authorized_ids[i] == id) {return 1;}
    }
    return 0;
}

int main(void) {
    if (is_authorized(42)) {
        printf("The user is authorized\n");
    } else {
        printf("The user is NOT authorized\n");
    }
}
