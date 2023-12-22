// tis-analyzer -val -val-profile analyzer genstr1.c
// How to get rid of the false alarms?

#include <stdio.h>
#include <string.h>
#include <tis_builtin.h>

int main(void) {
    char src[4];
    tis_make_unknown(src, sizeof src);
    printf("Contents of src: <%s>\n", src);
    size_t src_len = strlen(src);
    printf("The length is %zu\n", src_len);
}
