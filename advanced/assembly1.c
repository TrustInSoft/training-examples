// tis gui assembly1

#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

int main(void) {
    int x = 4;
    int y = 5;
    int z;

#if 0
//#ifdef __TRUSTINSOFT_HELPER__
    z = x + y;
#else
    // The assembly code below just does “z = x + y;”
    // %0 refers to the first operand, i.e. z (output)
    // %1 refers to the second operand, i.e. x (input)
    // %2 refers to the third operand, i.e. y (input)
    // see https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html
    __asm__(
        "mov %1, %0\n\t"
        "add %2, %0"
        : "=r" (z)          // Output operands
        : "r" (x), "r" (y)  // Input operands
    );
#endif
    printf("z = %d\n", z);
    int w = z / 2;

#ifdef __TRUSTINSOFT_ANALYZER__
    // However, TrustInSoft Analyzer does not understand assembly
    // It only understand the specification of the operand
    // Here, it understands that z is set to _some_ values, but not which
    tis_show_each("x, y, z", x, y, z);
#endif
}
