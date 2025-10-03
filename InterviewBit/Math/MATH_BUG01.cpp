#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrime(int A);  // Declaration of the member function
};








// Return 1 if A is prime, else 0
int Solution::isPrime(int A) {
    // handle edge case.
    if (A <= 1) return 0; // 0 and 1 are not prime numbers

	int upperLimit = (int)(sqrt(A));
	for (int i = 2; i <= upperLimit; i++) {
		if (A % i == 0) return 0;
	}
	return 1;
}
