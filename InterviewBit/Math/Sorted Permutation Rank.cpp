#define MOD 1000003

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::findRank(string A) ;
};














int Solution::findRank(string A) {
    int n = A.size();

    // Precompute factorials mod MOD
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) 
        fact[i] = (fact[i - 1] * i) % MOD;

    long long rank = 0;

    // Frequency of characters (ASCII range 256)
    vector<int> freq(256, 0);
    for (char c : A) freq[(int)c]++;

    // Since problem guarantees no duplicate characters
    // we skip validation for duplicate chars

    // Build cumulative frequency
    for (int i = 1; i < 256; i++)
        freq[i] += freq[i - 1];

    for (int i = 0; i < n; i++) {
        char ch = A[i];

        // Characters smaller than ch still remaining
        int smaller = (ch > 0 ? freq[ch - 1] : 0);

        // Add contribution
        rank = (rank + smaller * fact[n - i - 1]) % MOD;

        // Remove current char from freq
        for (int j = (int)ch; j < 256; j++)
            freq[j]--;
    }

    return (rank + 1) % MOD; // +1 because rank is 1-based
}
