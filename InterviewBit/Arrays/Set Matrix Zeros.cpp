#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &A);  // Declaration of the member function
};






void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    
    // Flags to check if the first row and first column need to be zeroed
    bool firstRowZero = false, firstColZero = false;
    
    // Step 1: Check if the first row contains any zero
    for (int j = 0; j < n; j++) {
        if (A[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }
    
    // Step 2: Check if the first column contains any zero
    for (int i = 0; i < m; i++) {
        if (A[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    
    // Step 3: Use the first row and first column to mark zeroes
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (A[i][j] == 0) {
                A[i][0] = 0;  // Mark the row
                A[0][j] = 0;  // Mark the column
            }
        }
    }
    
    // Step 4: Zero out the cells based on the marks in the first row and column
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }
    
    // Step 5: Zero out the first row if necessary
    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            A[0][j] = 0;
        }
    }
    
    // Step 6: Zero out the first column if necessary
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            A[i][0] = 0;
        }
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}