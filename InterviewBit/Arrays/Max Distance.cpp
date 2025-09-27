#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(const vector<int> &A);  // Declaration of the member function
};






int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if (n == 0) return 0;

    vector<int> LMin(n);
    vector<int> RMax(n);

    // Step 1: Fill LMin[]
    LMin[0] = A[0];
    for (int i = 1; i < n; i++) {
        LMin[i] = min(A[i], LMin[i - 1]);
    }

    // Step 2: Fill RMax[]
    RMax[n - 1] = A[n - 1];
    for (int j = n - 2; j >= 0; j--) {
        RMax[j] = max(A[j], RMax[j + 1]);
    }

    // Step 3: Traverse both arrays to find maximum j - i
    int i = 0, j = 0, maxDiff = 0;
    while (i < n && j < n) {
        if (LMin[i] <= RMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j++;
        } else {
            i++;
        }
    }

    return maxDiff;
}
