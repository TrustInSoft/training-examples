// tis-analyzer -val -val-profile analyzer genstr2.c
// How to get rid of the false alarms?

#include <stdio.h>
#include <string.h>
#include <tis_builtin.h>

int main(void) {
    char src[4];
    tis_make_unknown(src, sizeof src - 1);
    src[3] = 0;
    printf("Contents of src: <%s>\n", src);
    size_t src_len = strlen(src);
    printf("The length is %zu\n", src_len);
    char dst[4];
    strcpy(dst, src);
    printf("Contents of dst: <%s>\n", dst);
    size_t dst_len = strlen(dst);
    printf("The length is %zu\n", dst_len);
}
