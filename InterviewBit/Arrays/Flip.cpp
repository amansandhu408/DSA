
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> flip(string A);  // Declaration of the member function
};



vector<int> Solution::flip(string A) {
    int n = A.size();
    int max_gain = 0;
    int current_gain = 0;
    int start = 0;
    int best_start = -1;
    int best_end = -1;

    for (int i = 0; i < n; ++i) {
        // Convert character to +1 for '0' and -1 for '1'
        int value = (A[i] == '0') ? 1 : -1;

        if (current_gain + value < value) {
            current_gain = value;
            start = i;
        } else {
            current_gain += value;
        }

        if (current_gain > max_gain) {
            max_gain = current_gain;
            best_start = start;
            best_end = i;
        }
    }

    if (max_gain <= 0) {
        return {}; // No valid flip improves the number of 1s
    } else {
        // +1 to convert from 0-based to 1-based indices
        return {best_start + 1, best_end + 1};
    }
}