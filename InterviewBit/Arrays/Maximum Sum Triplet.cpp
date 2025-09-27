#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &A); // Declaration of the member function
};






int Solution::solve(vector<int> &A) {
    int n = A.size();
    if (n < 3) return 0;
    
    vector<int> suffixMax(n, 0);
    suffixMax[n - 1] = A[n - 1];
    
    // Step 1: Build the suffix max array
    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], A[i]);
    }
    
    int maxSum = 0;
    set<int> leftElements; // Elements to the left of the current index
    leftElements.insert(A[0]);
    
    // Step 2: Traverse from 1 to n-2 for the middle Element
    for (int j = 1; j < n - 1; j++) {
        if (suffixMax[j + 1] <= A[j]) {
            leftElements.insert(A[j]);   
            continue;   
        }
        
        // Find the largest Ai < Aj using set
        auto it = leftElements.lower_bound(A[j]);
        if (it != leftElements.begin()) {
            it--; // Now *it < A[j]
            int Ai = *it;
            int Aj = A[j];
            int Ak = suffixMax[j + 1];
            int sum = Ai + Aj + Ak;
            maxSum = max(maxSum, sum);
        }
        
        leftElements.insert(A[j]);
    }
    return maxSum;
}
