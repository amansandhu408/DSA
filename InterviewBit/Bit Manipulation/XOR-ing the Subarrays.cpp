#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::solve(vector<int> &A) ;
};









int Solution::solve(vector<int> &A) {
    int N = A.size();
    
    // If N is even, the result is 0
    if (N % 2 == 0) return 0;
    
    // If N is odd, XOR elements at even indices
    int ans = 0;
    for (int i = 0; i < N; i += 2) {
        ans ^= A[i];
    }
    
    return ans;
}
