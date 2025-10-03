#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrime(int A);  // Declaration of the member function
};







int Solution::isPrime(int A) {
    if (A <= 1) return 0;       // 0 and 1 are not prime
    if (A == 2) return 1;       // 2 is the only even prime number
    if (A % 2 == 0) return 0;   // other even numbers are not prime

    // Only check odd numbers up to sqrt(A)
    for (int i = 3; i * i <= A; i += 2) {
        if (A % i == 0) return 0;
    }

    return 1; // A is prime
}
