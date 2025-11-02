#include<bits/stdc++.h>
using namespace std;

class Solution {
    int reverse(int A);
};








int Solution::reverse(int A) {
    long long rev = 0;  // use long long to detect overflow
    int sign = (A < 0) ? -1 : 1;
    long long num = abs((long long)A);

    while (num > 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        if (rev > INT_MAX) return 0;  // overflow check
        num /= 10;
    }

    rev *= sign;

    // final overflow check
    if (rev < INT_MIN || rev > INT_MAX)
        return 0;

    return (int)rev;
}