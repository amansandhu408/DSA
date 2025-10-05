#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> sieve(int A);
};






vector<int> Solution::sieve(int A) {
    // Create a boolean array "is_prime" and initialize all entries as true
    vector<bool> is_prime(A + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers

    // Sieve of Eratosthenes algorithm
    for (int i = 2; i * i <= A; ++i) {
        if (is_prime[i]) {
            // Mark multiples of i as false
            for (int j = i * i; j <= A; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Collect all prime numbers
    vector<int> primes;
    for (int i = 2; i <= A; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}
