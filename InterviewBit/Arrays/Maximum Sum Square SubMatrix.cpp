#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve (vector<vector<int>> &A, int B);  // Declaration of the member function
};






int Solution::solve(vector<vector<int>> &A, int B) {
    int N = A.size();
    
    // Step 1: Build Prefix Sum Matrix
    vector<vector<int>> prefix(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            prefix[i][j] = A[i][j];
            if (i > 0) prefix[i][j] += prefix[i-1][j];
            if (j > 0) prefix[i][j] += prefix[i][j-1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    int maxSum = INT_MIN;

    // Step 2: Iterate over all possible BxB submatrices
    for (int i = B - 1; i < N; i++) {
        for (int j = B - 1; j < N; j++) {
            int total = prefix[i][j];
            if (i - B >= 0) total -= prefix[i - B][j];
            if (j - B >= 0) total -= prefix[i][j - B];
            if (i - B >= 0 && j - B >= 0) total += prefix[i - B][j - B];

            maxSum = max(maxSum, total);
        }
    }

    return maxSum;
}
