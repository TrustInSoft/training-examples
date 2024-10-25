// tis gui 1_full_vs_auto
// tis gui 1_full_vs_auto_split_full
// tis gui 1_full_vs_auto_split_auto
//
// The auto heuristic is based on data computed at the parsing phase.

#include <tis_builtin.h>

int f(void) {
    return tis_interval_split(4, 15);
}

int main(void) {
    int ret = f();
    tis_show_each("", ret);
    if (ret == 4) { }
}

void not_covered(void) {
    if (f() == 5) {}
}
