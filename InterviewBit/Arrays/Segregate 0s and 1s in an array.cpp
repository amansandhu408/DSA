#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> &A);  // Declaration of the member function
};






vector<int> Solution::solve(vector<int> &A) {
    int i = 0;  // Left pointer
    int j = A.size() - 1;  // Right pointer

    while (i < j) {
        // If current element at i is 1 and element at j is 0, swap them
        if (A[i] == 1 && A[j] == 0) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
        
        // If A[i] is 0, move the left pointer
        else if (A[i] == 0) {
            i++;
        }
        
        // If A[j] is 1, move the right pointer
        else {
            j--;
        }
    }
    return A;
}
