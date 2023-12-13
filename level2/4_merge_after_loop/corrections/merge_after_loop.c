// tis-analyzer -val -val-profile analyzer corrections/merge_after_loop.c -slevel 6000 -val-slevel-merge-after-loop @all,-main
//
// Changes: slevel, tis_interval() -> tis_interval_split(), merge after loop
//
// First, we notice that there is not enough SLevel for the loop to be precise.
//
// Then, once the loop is precise, we still see uninitialized values in the
// buffer, even before we enter the loop. These values come from memset(): we
// asked memset to initialize 0 to 100 elements of our array, so each element is
// maybe initialized, maybe uninitialized. We use tis_interval_split() to have a
// precise length given to memset in each propagation.
//
// Then, we have 101 precise states, each with a precise length and buffer, up
// to the loop, but still imprecise inside of the loop. The red bar in the GUI
// states "Merged loop": by default, the analyzer merges all states, once at the
// entrace of a loop, once at the exit. We disable merging.
//
// Finally, the slevel gets reached. The analysis needs slevel for 1 turn of the
// loop in the len==1 state, 2 turns of the loop in the len==2 state, ... up to
// 100. 1 + 2 + 3 + ... + 100 = 5050, so we raise the SLevel to be higher.

#include <string.h>
#include <tis_builtin.h>

int main(void) {
    char buffer[100];
    size_t len = tis_interval_split(0, sizeof buffer);
    memset(buffer, 1, len);
    int sum = 0;
    for (size_t i = 0; i < len; i++) {
        sum += buffer[i];
    }
    return sum;
}
