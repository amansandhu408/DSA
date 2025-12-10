#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::permuteStrings(string A, string B);
};












int Solution::permuteStrings(string A, string B) {
    // If lengths are not equal, no permutation is possible
    if (A.length() != B.length()) {
        return 0;
    }

    // Frequency maps for both strings
    unordered_map<char, int> freqA, freqB;

    // Fill frequency maps for both strings
    for (int i = 0; i < A.length(); i++) {
        freqA[A[i]]++;
        freqB[B[i]]++;
    }

    // Compare frequency maps
    if (freqA == freqB) {
        return 1; // A and B are permutations of each other
    } else {
        return 0; // A and B are not permutations of each other
    }
}
