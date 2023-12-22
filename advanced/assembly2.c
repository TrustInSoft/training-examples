// make assembly2 && ./assembly2 && rm assembly2
// tis-analyzer -val -val-profile analyzer assembly2.c -machdep x86_64 -gui

#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint64_t cpu_time;
    for (int x = 0; x < 5; x++) {
        __asm__ (
            "rdtsc\n\t"           // Returns the time in EDX:EAX.
            "shl $32, %%rdx\n\t"  // Shift the upper bits left.
            "or %%rdx, %0"        // 'Or' in the lower bits.
            : "=a" (cpu_time)     // Output operands
            :                     // Input operands (none)
            : "rdx"               // Clobbers: the value in RDX is overwritten
        );

        printf("%lu\n", cpu_time);
    }
}
