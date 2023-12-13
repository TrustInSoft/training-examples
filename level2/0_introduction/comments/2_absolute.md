In Level 2, you can write a single call to an entrypoint to analyze *all*
possible inputs. The 5th call to `absolute()` analyzes simultaneously 2^32
distinct values (for this platform). This would be unfeasible using traditional
testing.

This robustness analysis highlights a UB in `absolute()`: the absolute value of
`INT_MIN` is not representable on an `int` in 2's complement. Possible
solutions are:
* leaving it as is,
* adding a special case for `INT_MIN`, which would return a fixed value,
* removing `INT_MIN` from the analysis, by using
  `tis_interval(-INT_MAX, INT_MAX)`.
Any choice of solution should be documented, and its impact assessed. It may not
be the job of the analyst to take the final decision, and a temporary solution
may be taken to avoid the alarm in a first pass.
