#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &A);  // Declaration of the member function
};






void Solution::rotate(vector<vector<int> > &A) {
    
    int N = A.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            swap(A[i][j], A[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < N; ++i) {
        reverse(A[i].begin(), A[i].end());
    }
    
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}