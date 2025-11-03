#include<bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int A,int B);
};









int Solution::gcd(int A, int B) {
    // Euclidean algorithm to find GCD
    while (B != 0) {
        A = A % B; // remainder when A is divided by B
        swap(A, B); // swap A and B
    }
    return A;
}