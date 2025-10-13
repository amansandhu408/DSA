#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int A);
};









int Solution::solve(int A) {
    // Absolute value of the target position
    int target = abs(A);
    
    // Calculate the smallest n such that sum of first n numbers >= target
    int n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);
    
    // Calculate the sum of first n numbers
    int sum = n * (n + 1) / 2;
    
    // If sum exactly matches the target, return n
    if (sum == target)
        return n;

    // Calculate the difference between sum and target
    int d = sum - target;
    
    // If the difference is even, no additional moves are needed
    if ((d & 1) == 0)
        return n;
    else
        // If the difference is odd, return n + 2 or n + 1 depending on the parity of n
        return n + ((n & 1) ? 2 : 1);
}
