#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int perfectPeak(vector<int> &A);  // Declaration of the member function
};





int Solution::perfectPeak(vector<int> &A) {
    int N = A.size();
    
    // Step 1: Create left_max array
    vector<int> left_max(N, INT_MIN);
    for (int i = 1; i < N; i++) {
        left_max[i] = max(left_max[i-1], A[i-1]);
    }
    
    // Step 2: Create right_min array
    vector<int> right_min(N, INT_MAX);
    for (int i = N-2; i >= 0; i--) {
        right_min[i] = min(right_min[i+1], A[i+1]);
    }
    
    // Step 3: Check for the "perfect peak"
    for (int i = 1; i < N-1; i++) {
        if (A[i] > left_max[i] && A[i] < right_min[i]) {
            return 1;
        }
    }
    
    return 0;
}
