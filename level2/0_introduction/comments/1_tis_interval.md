`int tis_interval(int min, int max)` is a built-in function of the analyzer. It
is one of the functions that let you manipulate generalized values in C code. To
use it, you have to include `tis_builtin.h`, and then you can call it like any C
function.

It takes a `min` and a `max` values, and returns a generalized value in the
interval `[min .. max]` (note that this interval includes both `min` and `max`).
Because C does not allow overloads for each type, if you wanted to generalize,
for example, an `unsigned long`, its bounds would not necessarily fit in the
`int` parameters of `tis_interval()`, that's why `tis_interval()` has lots of
siblings:
* `tis_char_interval()`,
* `tis_unsigned_char_interval()`,
* `tis_short_interval()`,
* `tis_unsigned_short_interval()`,
* `tis_int_interval()`,
* `tis_unsigned_int_interval()`,
* `tis_long_interval()`,
* `tis_unsigned_long_interval()`,
* `tis_long_long_interval()`,
* `tis_unsigned_long_long_interval()`,
* `tis_float_interval()`,
* `tis_double_interval()`
that each take parameters of the corresponding type, and return a value of the
corresponding type.

Look at the values of `x` at the beginning of function `f`: `[0..42]`. If you
switch the view to `Per Callstack`, `Per Call`, or `Per State`, you can now see
the two calls to `f`: one with 42, one with `[0..10]`. The values for each call
are propagated separately: inside the `else` branch, we can see both of them;
note that the interval has been reduced to `[1..10]` by the condition. In the
`then` branch, we only see the value 0, coming from the interval.

Look at stdout. We can see 3 calls to printf, but one is cut off. This is
because the TrustInSoft libC implementation of `printf()` is aware of
generalized values, and only prints up to the first one: this allows you to have
some readable output even in Level 2.
