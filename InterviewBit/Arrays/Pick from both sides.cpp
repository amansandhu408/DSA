#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &A,int B); // Declaration of the member function
};







int Solution::solve(vector<int> &A, int B) {
    int N = A.size();
    
    // Calculate the sum of the first B elements (initial window)
    int currentSum = 0;
    for (int i = 0; i < B; i++) {
        currentSum += A[i];
    }
    
    // Store the maximum sum found so far
    int maxSum = currentSum;
    
    // Now slide the window from left to right
    for (int i = 0; i < B; i++) {
        currentSum -= A[B-1-i];  // Remove one element from the left of the current window
        currentSum += A[N-1-i];  // Add one element from the right to the current window
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}
