#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::solve(vector<int> &A, int B);
};







int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int low = 0, high = n - 1;
    int ans = -1;  // stores the last index where A[i] <= B

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] <= B) {
            ans = mid;          // mid is a valid index
            low = mid + 1;      // try to find a bigger one
        } else {
            high = mid - 1;     // search in the left half
        }
    }

    return ans + 1;  // because indices start from 0
}
