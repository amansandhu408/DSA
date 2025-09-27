#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> subUnsort(vector<int> &A);  // Declaration of the member function
};






vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int left = -1, right = -1;
    
    // Step 1: Find the first out-of-order element from the left
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            left = i;
            break;
        }
    }
    
    // If no out-of-order element is found, the array is already sorted
    if (left == -1) return {-1};
    
    // Step 2: Find the first out-of-order element from the right
    for (int i = n - 1; i > 0; i--) {
        if (A[i] < A[i - 1]) {
            right = i;
            break;
        }
    }
    
    // Step 3: Find the min and max values in the subarray A[left..right]
    int minVal = *min_element(A.begin() + left, A.begin() + right + 1);
    int maxVal = *max_element(A.begin() + left, A.begin() + right + 1);
    
    // Step 4: Adjust left boundary if needed
    while (left > 0 && A[left - 1] > minVal) {
        left--;
    }
    
    // Step 5: Adjust right boundary if needed
    while (right < n - 1 && A[right + 1] < maxVal) {
        right++;
    }
    
    // Step 6: Return the indices of the unsorted subarray
    return {left, right};
}
