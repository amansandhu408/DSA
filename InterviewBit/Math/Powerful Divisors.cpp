#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> Solution::powerfulDivisors(vector<int> &A);
};












vector<int> Solution::powerfulDivisors(vector<int> &A) {
    int maxA = *max_element(A.begin(), A.end());
    vector<int> divCount(maxA + 1, 0);

    // Step 1: Compute number of divisors for each number
    for (int i = 1; i <= maxA; i++) {
        for (int j = i; j <= maxA; j += i)
            divCount[j]++;
    }

    // Step 2: Precompute powerfulDivisors prefix
    auto isPowerOf2 = [](int x) {
        return x && ((x & (x - 1)) == 0);
    };

    vector<int> prefix(maxA + 1, 0);
    for (int i = 1; i <= maxA; i++) {
        prefix[i] = prefix[i - 1] + (isPowerOf2(divCount[i]) ? 1 : 0);
    }

    // Step 3: Answer queries
    vector<int> ans;
    ans.reserve(A.size());
    for (int x : A) ans.push_back(prefix[x]);

    return ans;
}
