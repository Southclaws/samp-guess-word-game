# `strcmpex`

`strcmpex` compares two strings, a 'truth' and a 'test' where the truth
represents the desired match and the test is a user-entered value. The goal of
this function is to facilitate a code comparison puzzle where the user enters a
number and is given feedback for each character in the test sequence, such as:

* correct value in the correct position
* incorrect value, not in the truth string at all
* partially incorrect value, is in the truth string but wrong pos the

inputs are character arrays (strings) and the output is an array of values from
0 to 2, where:

* 0 represents correctness
* 1 represents incorrectness
* 2 represents a valid character in the wrong position

To run tests:

```bash
sampctl package run
```
