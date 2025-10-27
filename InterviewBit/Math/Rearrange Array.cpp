#include<bits/stdc++.h>
using namespace std;

class Solution {
    void arrange(vector<int> &A);
};








void Solution::arrange(vector<int> &A) {
    int N = A.size();
    
    // Step 1: Encode both the old value and the new value at each position.
    for (int i = 0; i < N; i++) {
        A[i] = A[i] + (A[A[i]] % N) * N;
    }
    
    // Step 2: Decode the final value by dividing each element by N.
    for (int i = 0; i < N; i++) {
        A[i] = A[i] / N;
    }
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

