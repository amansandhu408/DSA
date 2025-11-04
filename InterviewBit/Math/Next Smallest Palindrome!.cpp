#include<bits/stdc++.h>
using namespace std;

class Solution {
    string solve(string A);
};










string Solution::solve(string A) {
    int n = A.size();
    
    // Edge case: if all digits are '9', the result is simple
    if (A == string(n, '9')) {
        return "1" + string(n - 1, '0') + "1";
    }
    
    // Split A into two halves
    string left = A.substr(0, (n + 1) / 2); // left half, including the middle if odd length
    string right = A.substr(n / 2);  // right half
    
    // Step 1: Mirror the left half to form a potential palindrome
    string palindrome = left;
    if (n % 2 == 1) {
        palindrome += string(left.rbegin() + 1, left.rend());  // Odd length, skip middle char
    } else {
        palindrome += string(left.rbegin(), left.rend());  // Even length, mirror exactly
    }
    
    // Step 2: If the mirrored palindrome is greater than the original A, return it
    if (palindrome > A) {
        return palindrome;
    }
    
    // Step 3: If the palindrome is not greater, increment the left half
    // Increment the left part
    int left_half_len = (n + 1) / 2;
    for (int i = left_half_len - 1; i >= 0; --i) {
        if (left[i] != '9') {
            left[i]++;
            break;
        }
        left[i] = '0'; // If '9', reset to '0' and carry the increment
    }
    
    // Construct the palindrome again after increment
    palindrome = left;
    if (n % 2 == 1) {
        palindrome += string(left.rbegin() + 1, left.rend());
    } else {
        palindrome += string(left.rbegin(), left.rend());
    }
    
    return palindrome;
}