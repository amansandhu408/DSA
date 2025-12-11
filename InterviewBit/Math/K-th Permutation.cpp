#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> Solution::findPerm(int A, long B) ;
};














vector<int> Solution::findPerm(int A, long B) {
    // Precompute factorials up to 20 (since 21! > 1e18)
    vector<long long> fact(21, 1);
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;

    // Fenwick tree for maintaining available numbers 1..A
    vector<int> BIT(A + 1, 0);

    auto fenwick_add = [&](int idx, int val) {
        for (; idx <= A; idx += idx & -idx)
            BIT[idx] += val;
    };

    auto fenwick_sum = [&](int idx) {
        long long s = 0;
        for (; idx > 0; idx -= idx & -idx)
            s += BIT[idx];
        return s;
    };

    // Get k-th smallest available number using binary search on BIT
    auto fenwick_kth = [&](int k) {
        int idx = 0;
        int bitMask = 1 << 17;  // since A ≤ 100000 < 2^17
        for (; bitMask > 0; bitMask >>= 1) {
            int next = idx + bitMask;
            if (next <= A && BIT[next] < k) {
                k -= BIT[next];
                idx = next;
            }
        }
        return idx + 1;  // actual number
    };

    // Initialize BIT: all numbers 1..A available
    for (int i = 1; i <= A; i++)
        fenwick_add(i, 1);

    vector<int> result;
    long long K = B;

    for (int i = 1; i <= A; i++) {
        int remaining = A - i;

        // If factorial block size exceeds B, pick the smallest available element
        if (remaining >= 20) {
            int val = fenwick_kth(1);
            result.push_back(val);
            fenwick_add(val, -1);
            continue;
        }

        long long block = fact[remaining];
        long long index = (K - 1) / block + 1;  // 1-based rank in available numbers

        int val = fenwick_kth(index);
        result.push_back(val);
        fenwick_add(val, -1);

        K = (K - 1) % block + 1;  // reduce K inside the block
    }

    return result;
}
