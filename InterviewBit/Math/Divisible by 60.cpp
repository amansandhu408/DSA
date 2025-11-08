#include<bits/stdc++.h>
using namespace std;

class Solution {
    int divisibleBy60(vector<int> &A);
};










int Solution::divisibleBy60(vector<int> &A) {
    int n = A.size();
    int sum = 0;
    int zeroCount = 0;
    int evenCount = 0;

    for (int d : A) {
        sum += d;
        if (d == 0) zeroCount++;
        if (d % 2 == 0) evenCount++;
    }

    // Special case: number is 0 (single digit zero)
    if (n == 1 && A[0] == 0)
        return 1;

    // Must have at least one zero
    if (zeroCount == 0)
        return 0;

    // Need at least one more even digit besides the zero
    if (evenCount < 2)
        return 0;

    // Sum of digits divisible by 3
    if (sum % 3 != 0)
        return 0;

    return 1;
}