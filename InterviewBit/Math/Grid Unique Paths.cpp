#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::uniquePaths(int A, int B) ;
};




















int Solution::uniquePaths(int A, int B) {
    vector<int> dp(B, 1); // Only one row is needed

    // Compute the number of paths for each cell in the grid
    for (int i = 1; i < A; i++) {
        for (int j = 1; j < B; j++) {
            dp[j] += dp[j-1]; // Update the current cell based on the previous cells
        }
    }

    // The number of unique paths will be in the last element of dp array
    return dp[B-1];
}
