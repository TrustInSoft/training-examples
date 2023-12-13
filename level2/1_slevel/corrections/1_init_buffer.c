// tis-analyzer -val -val-profile analyzer 1_init_buffer.c -slevel 42
//
// The SLevel also describes how many turns of a loop are done precisely.
//
// Note that there is no impact with -slevel 1000000. Also note that there is no
// alarm at -slevel 11: the first 11 turns of the loop are precise, which is 
// what we need.
