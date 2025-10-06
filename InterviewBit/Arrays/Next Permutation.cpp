#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextPermutation(vector<int> &A);  // Declaration of the member function
};








vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the right
    while (i >= 0 && A[i] >= A[i + 1]) {
        i--;
    }

    // Step 2: If such an element is found
    if (i >= 0) {
        int j = n - 1;
        // Find the next greater element to the right
        while (j >= 0 && A[j] <= A[i]) {
            j--;
        }
        // Swap them
        swap(A[i], A[j]);
    }

    // Step 3: Reverse the elements after index i
    reverse(A.begin() + i + 1, A.end());

    return A;
}