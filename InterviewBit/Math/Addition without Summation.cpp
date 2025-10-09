#include<bits/stdc++.h>
using namespace std;

class Solution {
    int addNumbers(int A,int B);
};


int Solution::addNumbers(int A, int B) {
    while (B != 0) {
        int carry = A & B;
        A = A ^ B;
        B = carry << 1;
    }
    return A;
}
