#include<bits/stdc++.h>
using namespace std;

class Solution {
    string Solution::solve(string A) ;
};













string Solution::solve(string A) {
    vector<int> freq(26, 0);
    
    // Count frequencies
    for (char c : A) {
        freq[c - 'a']++;
    }
    
    string result = "";
    vector<bool> used(26, false);
    
    // Build the result in order of first appearance
    for (char c : A) {
        int idx = c - 'a';
        if (!used[idx]) {
            result += c;
            result += to_string(freq[idx]);
            used[idx] = true;
        }
    }
    
    return result;
}
