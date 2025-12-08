#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::findRank(string A);
};










#define MOD 1000003

long long modpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
}

int Solution::findRank(string A) {
    int n = A.size();
    
    // Precompute factorials and inverse factorials
    vector<long long> fact(n + 1), invfact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    
    invfact[n] = modpow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    
    // Frequency array for ASCII chars
    vector<int> freq(256, 0);
    for (char c : A) freq[(unsigned char)c]++;
    
    // Compute denominator = product(freq[c]!)
    auto denom = [&]() {
        long long d = 1;
        for (int f : freq)
            if (f > 1)
                d = (d * invfact[f]) % MOD;
        return d;
    };
    
    long long rank = 1;

    for (int i = 0; i < n; i++) {
        int curr = (unsigned char)A[i];

        // Count chars smaller than A[i]
        for (int ch = 0; ch < curr; ch++) {
            if (freq[ch] > 0) {
                freq[ch]--;  // try using this smaller char

                long long ways = fact[n - i - 1];
                ways = (ways * denom()) % MOD;

                rank = (rank + ways) % MOD;

                freq[ch]++;  // undo
            }
        }

        // Use current character
        freq[curr]--;
    }

    return (int)(rank % MOD);
}