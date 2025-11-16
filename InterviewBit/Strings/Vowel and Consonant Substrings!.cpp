#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::solve(string A) ;
};













const int MOD = 1e9 + 7;

int Solution::solve(string A) {
    int vowel_count_before = 0;
    int consonant_count_before = 0;
    long long valid_pairs = 0;
    
    // Set of vowels for quick lookup
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    // Traverse the string
    for (int i = 0; i < A.size(); ++i) {
        char ch = A[i];
        
        if (vowels.count(ch)) {
            // Current character is a vowel, valid pairs with consonants before it
            valid_pairs += consonant_count_before;
        } else {
            // Current character is a consonant, valid pairs with vowels before it
            valid_pairs += vowel_count_before;
        }
        
        // Update counts for vowels and consonants encountered so far
        if (vowels.count(ch)) {
            vowel_count_before++;
        } else {
            consonant_count_before++;
        }
        
        // Keep the result modulo 10^9 + 7
        valid_pairs %= MOD;
    }
    
    return valid_pairs;
}
