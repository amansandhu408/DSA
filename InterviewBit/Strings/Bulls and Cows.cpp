#include<bits/stdc++.h>
using namespace std;

class Solution {
    string Solution::solve(string A, string B);
};

















string Solution::solve(string A, string B) {
    int bulls = 0;
    int cows = 0;
    
    // Maps to store the frequency of non-bull digits in A (secret) and B (guess)
    unordered_map<char, int> A_map;
    unordered_map<char, int> B_map;

    // First pass: count bulls and collect non-bull digits
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == B[i]) {
            bulls++;  // If digits are at the same position, count as bulls
        } else {
            A_map[A[i]]++;  // If not, track secret digits
            B_map[B[i]]++;  // Track guess digits
        }
    }
    
    // Second pass: count cows by comparing frequency of unmatched digits
    for (auto& entry : B_map) {
        char digit = entry.first;
        int B_count = entry.second;
        
        if (A_map.find(digit) != A_map.end()) {
            // Calculate cows as the minimum of matching frequencies
            cows += min(A_map[digit], B_count);
        }
    }

    // Return result in the format "xAyB"
    return to_string(bulls) + "A" + to_string(cows) + "B";
}
