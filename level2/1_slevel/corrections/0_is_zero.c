// tis-analyzer -val -val-profile analyzer 0_is_zero.c -slevel 2
//
// C code structures create multiple states naturally, raising the SLevel limit
// allows these states to stay separated.
//
// Note that there is no impact with -slevel 100, or 1000000: the SLevel is a
// limiter on the amount of states, but not a creator of states on its own.
