#include<bits/stdc++.h>
using namespace std;

class Solution {
    unsigned int Solution::reverse(unsigned int A);
};









unsigned int Solution::reverse(unsigned int A) {
    unsigned int result = 0;

    for (int i = 0; i < 32; i++) {
        result <<= 1;           // Make space for next bit
        result |= (A & 1);      // Copy last bit of A
        A >>= 1;                // Move to next bit
    }

    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

