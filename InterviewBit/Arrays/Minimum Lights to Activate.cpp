#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &A, int B); // Declaration of the member function
};







int Solution::solve(vector<int> &A, int B) {
    int N = A.size();
    int i = 0;
    int count = 0;

    while (i < N) {
        // Find the farthest light we can turn on that covers position i
        int left = max(0, i - B + 1);
        int right = min(N - 1, i + B - 1);
        int pos = -1;

        for (int j = right; j >= left; --j) {
            if (A[j] == 1) {
                pos = j;
                break;
            }
        }

        // No light found that can cover current position
        if (pos == -1) {
            return -1;
        }

        count++;
        i = pos + B;  // move to the position just after the light coverage
    }

    return count;
}
