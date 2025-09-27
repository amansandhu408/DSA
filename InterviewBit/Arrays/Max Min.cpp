#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &A);  // Declaration of the member function
};






int Solution::solve(vector<int> &A) {
    int n = A.size();
    int minimum, maximum;
    int i;

    // Initialize min and max based on even/odd size
    if (n % 2 == 0) {
        if (A[0] < A[1]) {
            minimum = A[0];
            maximum = A[1];
        } else {
            minimum = A[1];
            maximum = A[0];
        }
        i = 2;
    } else {
        minimum = maximum = A[0];
        i = 1;
    }

    // Traverse elements in pairs
    while (i < n - 1) {
        int local_min, local_max;
        if (A[i] < A[i + 1]) {
            local_min = A[i];
            local_max = A[i + 1];
        } else {
            local_min = A[i + 1];
            local_max = A[i];
        }

        if (local_min < minimum) minimum = local_min;
        if (local_max > maximum) maximum = local_max;

        i += 2;
    }

    return minimum + maximum;
}