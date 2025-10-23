#include<bits/stdc++.h>
using namespace std;

class Solution {
    string solve(string A);
};









string Solution::solve(string A) {
    int n = A.size();
    int i = n - 2;
    
    // Step 1: Find first decreasing element from right
    while (i >= 0 && A[i] >= A[i + 1]) {
        i--;
    }
    
    // If no such element found, number is in descending order
    if (i < 0) return "-1";
    
    // Step 2: Find smallest element greater than A[i] on the right
    int j = n - 1;
    while (A[j] <= A[i]) {
        j--;
    }
    
    // Step 3: Swap them
    swap(A[i], A[j]);
    
    // Step 4: Reverse from i+1 to end
    reverse(A.begin() + i + 1, A.end());
    
    return A;
}
