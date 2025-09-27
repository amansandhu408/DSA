#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int A, vector<int> &B); // Declaration of the member function
};








int Solution::solve(int A, vector<int> &B) {
    long long totalSum = 0;
    for (int i = 0; i < A; i++) {
        totalSum += B[i];
    }

    // If totalSum is not divisible by 3, no valid partition
    if (totalSum % 3 != 0) {
        return 0;
    }

    long long partSum = totalSum / 3;
    long long currentSum = 0;
    int countFirstPart = 0;
    int ways = 0;

    // Go until A - 1 to ensure the third part is non-empty
    for (int i = 0; i < A - 1; ++i) {
        currentSum += B[i];

        if (currentSum == 2 * partSum) {
            // For second cut, add the number of ways first cut could have happened
            ways += countFirstPart;
        }

        if (currentSum == partSum) {
            // Valid position for first cut
            countFirstPart++;
        }
    }

    return ways;
}
