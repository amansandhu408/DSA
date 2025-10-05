#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> allFactors(int A);
};








vector<int> Solution::allFactors(int A) {
    vector<int> factors;
    
    // Loop from 1 to sqrt(A)
    for (int i = 1; i <= sqrt(A); i++) {
        if (A % i == 0) {
            factors.push_back(i);  // i is a factor
            
            // If i and A/i are different, add A/i as well
            if (i != A / i) {
                factors.push_back(A / i);
            }
        }
    }
    
    // Sort the factors in ascending order
    sort(factors.begin(), factors.end());
    
    return factors;
}