// tis-analyzer -val -val-profile analyzer tis_address.c
// With pointer -> int conversions, the analyzer will try its best to keep the
// value precise

#include <assert.h>
#include <stdint.h>
#include <tis_builtin.h>

// Precise tis_address for pointer -> int and int -> pointer conversions
int x __attribute__((tis_address(0x1000)));
// Imprecise tis_address for pointer -> int conversions
int y __attribute__((tis_address("[0x2000..0x3000]")));

int main(void) {
    // int -> pointer
    int *p = (int *) 0x1000;
    *p = 3;
    tis_show_each_x(x);

    // pointer -> int
    uintptr_t i = &y;
    uintptr_t j = tis_force_ival_representation(i);
    assert(i < 0x4000);
}
