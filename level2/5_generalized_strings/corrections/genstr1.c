// In C, a string is valid only if it is terminated by a '\0' character. By
// generalizing all the bytes of the string, we simulate combinations of bytes
// where there could be a zero anywhere, but also combinations where there is
// never a zero, which would not be a valid string, and therefore UB to pass to
// printf's "%s" or to strlen.
//
// We overcome this by forcing the last byte to be a zero. That way, no matter
// the combinations of bytes, there is a guaranteed zero in the string, making
// it valid.
//
// Note that strlen returns `{0; 1; 2; 3}`: because there could be a zero
// anywhere, the string could have a zero in the first position, or second, or
// third, and a guaranteed zero in the fourth. The TrustInSoft libC
// implementation for strlen is a builtin that considers all these cases at
// once.
//
// Take a look at stdout: both printfs started printing properly, but then
// stopped: this is because the TrustInSoft libC implementation of printf
// deliberately stops at the first imprecise value to be printed. To display
// imprecise values in the console, use the builtin tis_show_each().

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
}
