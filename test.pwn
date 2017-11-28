#define RUN_TESTS
#include <YSI\y_testing>

#include "strcmpex.inc"

printArr(arr[], size = sizeof arr) {
    new str[128];
    for(new i; i < size; ++i) {
        if(i > 0) {
            strcat(str, ", ");
        }
        format(str, sizeof str, "%s%d", str, arr[i]);
    }
    print(str);
}

Test:strcmpex() {
    new
        truth[5],
        test[5],
        output[4];

    truth = {'1', '2', '3', '4', '0'};
    test = {'1', '3', '8', '8', '0'};
    output = {0,    2,   1,   1};

/*
[2:58 PM] Southclaws: if we define these symbols:
0 = correct
1 = correct, wrong position
2 = incorrect
and for example, 1234 is the "truth" and 1388 is the "test", the result would be: [0122], visualised:
['1', '2', '3', '4']
['1', '3', '8', '8']

*/

    strcmpex(truth, 5, test, 5, output, 4);
    printArr(output, 4);

    ASSERT(output[0] == 0);
    ASSERT(output[1] == 2);
    ASSERT(output[2] == 1);
    ASSERT(output[3] == 1);
}