#include<bits/stdc++.h>
using namespace std;

class Solution {
    int hammingDistance(const vector<int> &A);
};








int Solution::hammingDistance(const vector<int> &A) {
    const int MOD = 1000000007;
    int n = A.size();
    long long total = 0;

    for (int bit = 0; bit < 32; bit++) {
        long long count_ones = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] & (1 << bit)) {
                count_ones++;
            }
        }
        long long count_zeros = n - count_ones;
        total = (total + (count_ones * count_zeros * 2) % MOD) % MOD;
    }

    return (int)total;
}
