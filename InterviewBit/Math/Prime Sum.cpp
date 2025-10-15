#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> primesum(int A);
};







vector<int> Solution::primesum(int A) {
    // Step 1: Sieve of Eratosthenes to find all primes up to A
    vector<bool> isPrime(A + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

    for (int i = 2; i * i <= A; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= A; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Step 2: Find two primes whose sum is A
    for (int i = 2; i <= A / 2; i++) {
        if (isPrime[i] && isPrime[A - i]) {
            return {i, A - i};
        }
    }

    // Step 3: As per the problem statement, a solution always exists, so no need for further handling
    return {};
}