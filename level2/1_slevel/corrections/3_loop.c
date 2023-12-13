// tis-analyzer -val -val-profile analyzer 3_loop.c -slevel 60
//
// `int tis_nondet(int a, int b)` is a built-in function of the analyzer. It
// takes in two values, and returns two states: one where the return value is
// `a`, one where it is `b`; if you do not put enough SLevel it is equivalent to
// creating a generalized value that encompasses both `a` and `b`. Like
// `tis_interval()`, it has some siblings:
// * `tis_nondet3()`, `tis_nondet4()`, `tis_nondet5()`, that take 3, 4, and 5
//   parameters respectively,
// * `tis_nondet_ptr()`, `tis_nondet_ptr3()`, ... that take pointers as
//   parameters, and return pointers.
// Unlike `tis_interval()`, there are no variants for the various integer types:
// it is very easy to get the same effect with `if (tis_nondet(0, 1))`.
//
// There are 30 turns of the loop, and up to 2 states at each turn, so some
// statements would have to be evaluated 60 times => SLevel set to 60.
