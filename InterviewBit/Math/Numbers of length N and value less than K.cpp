#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> &A, int B, int C);
};

















int Solution::solve(vector<int> &A, int B, int C) {
    int D = A.size();
    if (D == 0) return 0;

    // Convert C into digits
    vector<int> digits;
    int temp = C;
    if (temp == 0) digits.push_back(0);
    while (temp > 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    reverse(digits.begin(), digits.end());

    int lenC = digits.size();

    // Case 1: B > length of C -> no possible numbers
    if (B > lenC) return 0;

    // Case 2: B < length of C -> all B-digit numbers valid
    if (B < lenC) {
        // If B == 1, zero is allowed
        if (B == 1) return D;

        // First digit cannot be zero
        int firstChoices = 0;
        for (int d : A) if (d != 0) firstChoices++;

        if (firstChoices == 0) return 0;

        long long ans = firstChoices;
        for (int i = 1; i < B; i++) ans *= D;
        return ans;
    }

    // Case 3: B == lenC -> Digit DP
    vector<int> lower(11, 0);
    for (int d : A) lower[d] = 1;

    // prefix count: smaller digits before each digit
    vector<int> prefix(11, 0);
    for (int i = 1; i < 11; i++)
        prefix[i] = prefix[i - 1] + lower[i - 1];

    long long ans = 0;

    for (int i = 0; i < B; i++) {
        int d = digits[i];

        // Count digits < d
        long long countLess = prefix[d];

        // Handle leading zeros
        if (i == 0 && B > 1 && lower[0])
            countLess -= 1; // cannot use 0 at first position

        // Add combinations
        long long powRemain = 1;
        for (int k = i + 1; k < B; k++) powRemain *= D;

        ans += countLess * powRemain;

        // If d is not available in A, stop further processing
        if (!lower[d]) break;

        // If it's last digit and equals C digit, it's okay; no addition needed
    }

    return ans;
}
