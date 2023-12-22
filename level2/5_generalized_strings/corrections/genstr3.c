// To properly split an interval, we need to propagate each sub-interval in its
// own state.
//
// 2 combinations for the first byte, 2 combinations for the second byte, ...
// For a string of length 100, we would need 2^100 states => this is not
// feasable.
//
// For generalized strings, or otherwise generalized buffers whose semantics
// depend on the contents of the buffer itself, use short buffers, smaller
// ranges, or adapt your analysis strategy: deal with all the combinations,
// fuzzing + level 1 analysis, ...
