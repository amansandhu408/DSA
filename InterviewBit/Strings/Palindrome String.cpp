#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::isPalindrome(string A);
};














int Solution::isPalindrome(string A) {
    int left = 0;
    int right = A.length() - 1;
    
    // Traverse the string from both ends
    while (left < right) {
        // Move left pointer to the next alphanumeric character
        while (left < right && !isalnum(A[left])) {
            left++;
        }
        
        // Move right pointer to the previous alphanumeric character
        while (left < right && !isalnum(A[right])) {
            right--;
        }
        
        // Compare the characters (case-insensitive)
        if (tolower(A[left]) != tolower(A[right])) {
            return 0;  // Not a palindrome
        }
        
        // Move both pointers
        left++;
        right--;
    }
    
    return 1;  // It's a palindrome
}
