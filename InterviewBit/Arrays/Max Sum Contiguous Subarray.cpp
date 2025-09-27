#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(const vector<int> &A); // Declaration of the member function
};







// Kadane's Algorithm 

int Solution::maxSubArray(const vector<int>& A) {
    int n = A.size();
    int current_sum = A[0]; // Start with the first element
    int max_sum = A[0]; // Also initialize max_sum as the first element
    
    for (int i = 1; i < n; i++) {
        // Update current_sum by including the current element or starting new subarray
        current_sum = max(A[i], current_sum + A[i]);
        
        // Update max_sum to the largest found so far
        max_sum = max(max_sum, current_sum);
    }
    
    return max_sum;
}