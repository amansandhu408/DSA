#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::solve(int A);
};












#define MOD 1000000007

long long countBits(long long A) {
    if (A == 0) return 0;

    // find highest power of 2 <= A
    long long p = 0;
    while ((1LL << (p + 1)) <= A) p++;

    long long powerOf2 = (1LL << p);

    // 1) Bits from MSB in all numbers less than powerOf2
    long long msbLess = (p * (powerOf2 >> 1)) % MOD;

    // 2) Bits from MSB in numbers from powerOf2 to A
    long long msbMore = (A - powerOf2 + 1) % MOD;

    // 3) Recurse for the remainder
    long long rest = countBits(A - powerOf2);

    return (msbLess + msbMore + rest) % MOD;
}

int Solution::solve(int A) {
    return countBits(A);
}
