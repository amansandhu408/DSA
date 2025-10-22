#include<bits/stdc++.h>
using namespace std;

class Solution {
    string convertToTitle(int A);
};







string Solution::convertToTitle(int A) {
    string result = "";
    
    while (A > 0) {
        // Adjust for 1-indexed column system
        A--; 
        // Find the current character and append to the result
        result += (char)(A % 26 + 'A');
        // Update A by dividing it by 26
        A /= 26;
    }

    // Since we were appending the least significant characters first, reverse the string
    reverse(result.begin(), result.end());

    return result;
}
