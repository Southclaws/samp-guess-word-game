
// strcmpex compares two strings, a 'truth' and a 'test' where
// the truth represents the desired match and the test is a
// user-entered value. The goal of this function is to facilitate
// a code comparison puzzle where the user enters a number and is
// given feedback for each character in the test sequence, such as:
// - correct value in the correct position
// - incorrect value, not in the truth string at all
// - partially incorrect value, is in the truth string but wrong pos
// the inputs are character arrays (strings) and the output is an
// array of values from 0 to 2, where:
// - 0 represents correctness
// - 1 represents incorrectness
// - 2 represents a valid character in the wrong position
strcmpex(truth[], truthLen, test[], testLen, output[], outputLen) {
    new outIdx = 0;

    for(new i; i < truthLen; ++i) {
        // protect overflows
        if(outIdx == outputLen -1) {
            break;
        }

        if(truth[i] == test[i]) {
            output[outIdx++] = 0;
        } else {
            output[outIdx] = 1;
            // lazy re-parse
            for(new j; j < truthLen; ++j) {
                if(test[i] == truth[j]) {
                    output[outIdx] = 2;
                    break;
                }
            }
            outIdx++;
        }
    }
}
