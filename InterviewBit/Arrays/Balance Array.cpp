#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &A);  // Declaration of the member function
};






int Solution::solve(vector<int> &A) {
    int N = A.size();
    
    // Calculate initial sum of even and odd indexed elements
    long long totalEven = 0, totalOdd = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            totalEven += A[i];
        } else {
            totalOdd += A[i];
        }
    }
    
    long long leftEven = 0, leftOdd = 0;
    int specialCount = 0;
    
    // Iterate through the array to check for special elements
    for (int i = 0; i < N; i++) {
        long long rightEven = totalEven - leftEven;
        long long rightOdd = totalOdd - leftOdd;
        
        // If the element at index i is removed
        if (i % 2 == 0) {
            // Remove from the even sum
            rightEven -= A[i];
        } else {
            // Remove from the odd sum
            rightOdd -= A[i];
        }
        
        // Check if the array becomes balanced after removal
        if (leftEven + rightOdd == leftOdd + rightEven) {
            specialCount++;
        }
        
        // Update the left sums
        if (i % 2 == 0) {
            leftEven += A[i];
        } else {
            leftOdd += A[i];
        }
    }
    
    return specialCount;
}
