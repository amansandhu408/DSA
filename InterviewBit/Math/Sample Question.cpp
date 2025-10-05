#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int A, int B);
};








int Solution::solve(int A, int B) {
    const int MOD = 10000000;
    return (A+B) % MOD;
}