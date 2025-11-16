#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::findMinXor(vector<int> &A);
};










int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int minXor = INT_MAX;

    for (int i = 0; i < A.size() - 1; i++) {
        int val = A[i] ^ A[i + 1];
        if (val < minXor)
            minXor = val;
    }
    return minXor;
}
