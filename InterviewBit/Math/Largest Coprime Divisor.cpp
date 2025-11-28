#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::cpFact(int A, int B);
};









int Solution::cpFact(int A, int B) {
  // Keep reducing A by dividing by the GCD of A and B until A and B are coprime
  while(__gcd(A, B) != 1) {
    A = A / __gcd(A, B);  // Reduce A by dividing it by the GCD of A and B
  } 
  return A;  // Return the largest divisor of A that is coprime with B
}
