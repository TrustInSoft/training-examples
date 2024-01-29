// tis-analyzer -val -val-profile analyzer corrections/genstr2.c -slevel 4 -val-split-return-function my_strcpy:full
//
// Similarly to strlen, strcpy has a TrustInSoft libC implementation that
// considers all cases at once:
// * the case where there is a zero in the first position, resulting in just a
//   zero being copied, and the rest of dst left uninitialized,
// * the case where there is a zero in the second position, resulting in one
//   generalized byte, then a zero, then uninitialized values in dst,
// * the case where there is a zero in the third position, similar to the
//   second case, with two generalized bytes,
// * the case where there is a zero in the fourth position, resulting in three
//   generalized bytes then a zero in dst.
// All in all, this means that the buffer resulting from the copy has:
// * any possible value in the first position,
// * any possible value or uninitialized in the second and third positions,
// * a zero or uninitialized in the fourth position.
// This is not a valid string: the first character could be non-zero, then the
// second uninitialized.
//
// To overcome this problem, we would need to separate all four cases in
// independent states before the call to strcpy; this is a complicated task, and
// does not easily scale with larger buffers.
//
// An unexpected solution comes if we use our own C implementation instead of
// strcpy: the behavior is the same with 4 resulting cases, but this time we
// can, with the help of SLevel and return strategy, keep those cases separated.


#include <stdio.h>
#include <string.h>
#include <tis_builtin.h>

char* my_strcpy(char *dst, const char *src) {
    char *p = dst;
    while (*src) {
        *p++ = *src++;
    }
    *p = 0;
    return dst;
}

int main(void) {
    char src[4];
    tis_make_unknown(src, sizeof src - 1);
    src[3] = 0;
    printf("Contents of src: <%s>\n", src);
    size_t src_len = strlen(src);
    printf("The length is %zu\n", src_len);
    char dst[4];
    my_strcpy(dst, src);
    printf("Contents of dst: <%s>\n", dst);
    size_t dst_len = strlen(dst);
    printf("The length is %zu\n", dst_len);
}
