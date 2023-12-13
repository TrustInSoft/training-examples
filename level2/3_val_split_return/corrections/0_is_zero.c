// tis-analyzer -val -val-profile analyzer 0_is_zero.c -slevel 10 -val-split-return-function f:full
//
// The strategy is changed for the callee, propagating more states in the
// caller. Do not forget SLevel for the caller!
