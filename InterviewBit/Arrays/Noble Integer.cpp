#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &A);  // Declaration of the member function
};





int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    
    for (int i = 0; i < n; ) {
        int current = A[i];
        
        // Count of numbers greater than current is n - index of first number > current
        int greaterCount = n - (upper_bound(A.begin(), A.end(), current) - A.begin());

        if (greaterCount == current) {
            return 1;
        }

        // Skip duplicates
        while (i < n && A[i] == current) {
            i++;
        }
    }

    return -1;
}
