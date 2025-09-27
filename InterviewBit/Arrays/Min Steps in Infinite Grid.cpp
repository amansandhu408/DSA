#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coverPoints(vector<int> &A, vector<int> &B); // Declaration of the member function
};






int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int steps = 0; // Initialize total steps counter

    // Loop through each pair of consecutive points
    for (int i = 1; i < A.size(); ++i) {
        // Calculate the absolute difference in x and y coordinates
        int dx = abs(A[i] - A[i - 1]); // Change in x-direction
        int dy = abs(B[i] - B[i - 1]); // Change in y-direction

        // The minimum steps required to go from (A[i-1], B[i-1]) to (A[i], B[i])
        // using 8-directional movement is max(dx, dy)
        steps += max(dx, dy);
    }

    return steps; // Return the total minimum steps to cover all points
}