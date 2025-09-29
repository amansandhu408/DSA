#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> &A);  // Declaration of the member function
};








vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> result(n);  // Array to store the squared elements in sorted order
    
    int left = 0, right = n - 1;
    int index = n - 1;  // Start filling the result array from the end
    
    while (left <= right) {
        int left_square = A[left] * A[left];   // Square of the element at the left pointer
        int right_square = A[right] * A[right]; // Square of the element at the right pointer
        
        // Compare squares and put the larger one at the current index of the result array
        if (left_square > right_square) {
            result[index] = left_square;
            left++;  // Move left pointer to the right
        } else {
            result[index] = right_square;
            right--;  // Move right pointer to the left
        }
        
        index--;  // Move to the next position in the result array
    }
    
    return result;
}
