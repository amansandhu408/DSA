#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int a);  // Declaration of the member function
};





string multiply(string a, int b) {
    int carry = 0;
    string result = "";

    // Multiply each digit of the string by the integer b    
    for (int i = a.size() -1 ; i >= 0; i--){
        int product = (a[i] - '0') * b + carry;
        result += (product % 10) + '0'; // Append the last digit of the product
        carry = product /10; // Carry over the rest
    }

    // If there's any carry left, add it to the result
    while (carry) {
        result += (carry % 10) + '0';
        carry /= 10;
    }

    // Reverse the result since we've been adding digits from the least significant to the most
    reverse(result.begin(), result.end());
    return result;
}

string factorial(int A) {
    // Base case: factorial of 0 or 1 is 1
    if (A == 0 || A == 1) {
        return "1";
    }
    
    // Recursive case: calculate factorial of A-1 and multiply by A
    string prev_factorial = factorial(A - 1);
    return multiply(prev_factorial, A);
}

string Solution::solve(int A) {
    return factorial(A);
}