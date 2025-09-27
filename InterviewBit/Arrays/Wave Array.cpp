#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> wave(vector<int> &A);  // Declaration of the member function
};





vector<int> Solution::wave(vector<int> &A) {
    // Step 1: Sort the array
    sort(A.begin(), A.end());
    
    // Step 2: Swap adjacent elements (pairwise swap)
    for (int i = 0; i < A.size() - 1; i += 2) {
        // Swap elements at index i and i+1
        swap(A[i], A[i+1]);
    }
    
    // Return the modified array
    return A;
}
