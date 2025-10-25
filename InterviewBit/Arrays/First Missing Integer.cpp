#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &A) ;  // Declaration of the member function
};











int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        // Place A[i] in its correct position if possible
        while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]) {
            swap(A[i], A[A[i] - 1]);
        }
    }

    // Now find the first place where index doesn't match the value
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) {
            return i + 1;
        }
    }

    // If all are in place, answer is n+1
    return n + 1;
}
