#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int A);
};










#define MOD 1000000007

struct Matrix {
    long long a[2][2];
};

Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    C.a[0][0] = (A.a[0][0]*B.a[0][0] % MOD + A.a[0][1]*B.a[1][0] % MOD) % MOD;
    C.a[0][1] = (A.a[0][0]*B.a[0][1] % MOD + A.a[0][1]*B.a[1][1] % MOD) % MOD;
    C.a[1][0] = (A.a[1][0]*B.a[0][0] % MOD + A.a[1][1]*B.a[1][0] % MOD) % MOD;
    C.a[1][1] = (A.a[1][0]*B.a[0][1] % MOD + A.a[1][1]*B.a[1][1] % MOD) % MOD;
    return C;
}

Matrix power(Matrix base, long long exp) {
    if (exp == 1)
        return base;
    if (exp % 2 == 0) {
        Matrix half = power(base, exp / 2);
        return multiply(half, half);
    } else {
        return multiply(base, power(base, exp - 1));
    }
}

int Solution::solve(int A) {
    if (A <= 2) return 1;
    
    Matrix M = {{{1, 1}, {1, 0}}};
    Matrix result = power(M, A - 2);
    
    long long Fn = (result.a[0][0] + result.a[0][1]) % MOD; // F(n) = F(2)*M00 + F(1)*M01
    return (int)Fn;
}
