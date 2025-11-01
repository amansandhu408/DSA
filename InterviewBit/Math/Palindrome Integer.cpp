#include<bits/stdc++.h>
using namespace std;

class Solution {
    int isPalindrome(int A);
};






int Solution::isPalindrome(int A) {
    // Negative numbers are not palindromic
    if (A < 0) return 0;

    // Numbers ending with 0 (except 0 itself) are not palindromic
    if (A % 10 == 0 && A != 0) return 0;

    int reversedHalf = 0;
    while (A > reversedHalf) {
        int digit = A % 10;
        reversedHalf = reversedHalf * 10 + digit;
        A /= 10;
    }

    // For odd digit count, reversedHalf/10 removes the middle digit
    if (A == reversedHalf || A == reversedHalf / 10)
        return 1;

    return 0;
}
