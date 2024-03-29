In Level 1, the analyzer can only propagate one value at a time. The libC
function `rand()` is given a TrustInSoft implementation which is a small
pseudo-random number generator. The values returned by `rand()` are therefore
deterministic: 5757, then 10113, then 16837, then 17514. Since the loop stops at
the first even value, the Level 1 analysis exits the loop there.

Similarly, `malloc()` can only return one value, so it always returns a valid
pointer as it would in case of success.

---

In Level 2, the analyzer can propagate multiple values at a time. The
TrustInSoft libC takes advantage of this by having functions like `rand()`
return a generalized value, emulating any of the concrete values. This then
means that the condition can be true and false at every turn of the loop.

Looking at the values of `x` inside of the loop, we see that the values get more
and more imprecise for 3 turns, and then the analyzer _widens_ to the maximum
achieavable values: for `x` that is 2147483647, a.k.a. `INT_MAX` for this
platform. At the 4th turn of the loop, the analyzer detects a possible undefined
behavior, and concludes on the loop: no need to analyze it further.

`malloc()` also behaves differently in Level 2: it is now able to return NULL as
it would in case of failure, as well as a valid pointer. Because we do not check
the return value of `malloc()`, we have a possible null pointer dereference.

---

Note that these true UBs would have been almost impossible to detect using
concrete tests, or Level 1: for the first UB, not only would you need `rand()`
to only return odd values, but you would need it to do so for more than 2
billion turns of the loop; for the second UB, you would need to emulate an
allocation failure at any call to `malloc()`. With Level 2, we can reach a
conclusion without sacrificing any of the possible values for `rand()` or
`malloc()` nor our analysis time: the analysis takes less than 1 second.
