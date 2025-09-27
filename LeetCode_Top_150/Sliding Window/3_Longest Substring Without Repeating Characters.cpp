#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;  // Set to store the characters in the current window
        int left = 0;  // Left pointer of the window
        int maxLength = 0;  // Variable to store the maximum length

        // Iterate through the string with the right pointer
        for (int right = 0; right < s.size(); ++right) {
            // If the character is already in the set, move the left pointer
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);  // Remove character at left pointer
                left++;  // Move the left pointer to the right
            }
            
            // Add the current character to the set
            charSet.insert(s[right]);
            
            // Update the maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
