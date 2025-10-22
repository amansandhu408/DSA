#include<bits/stdc++.h>
using namespace std;

class Solution {
    int titleToNumber(string A);
};









int Solution::titleToNumber(string A) {
    int result = 0;
    int length = A.length();

    for (int i = 0; i < length; i++) {
        // Calculate the position of the current character (1 for 'A', 2 for 'B', ..., 26 for 'Z')
        int value = A[i] - 'A' + 1;
        
        // Shift the result and add the value of the current character
        result = result * 26 + value;
    }

    return result;
}
