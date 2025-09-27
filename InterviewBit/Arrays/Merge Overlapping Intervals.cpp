#include <bits/stdc++.h>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> merge(vector<Interval> &A);  // Declaration of the member function
};





/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    if (A.empty()) return {};

    // Step 1: Sort the intervals based on start time
    sort(A.begin(), A.end(), [](const Interval &a, const Interval &b) {
        return a.start < b.start;
    });

    // Step 2: Initialize result list with the first interval
    vector<Interval> result;
    result.push_back(A[0]);

    // Step 3: Traverse and merge
    for (int i = 1; i < A.size(); ++i) {
        Interval &last = result.back();
        Interval &current = A[i];

        // Overlap condition
        if (current.start <= last.end) {
            // Merge the current interval with the last one
            last.end = max(last.end, current.end);
        } else {
            // No overlap, add to result
            result.push_back(current);
        }
    }

    return result;
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
