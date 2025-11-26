#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::trailingZeroes(int A);
};








int Solution::trailingZeroes(int A) {
    int count = 0;
    int powerOfFive = 5;
    
    // Keep dividing A by powers of 5 and add the quotient to count
    while (A >= powerOfFive) {
        count += A / powerOfFive;
        powerOfFive *= 5; // Move to the next power of 5 (25, 125, etc.)
    }
    
    return count;
}
