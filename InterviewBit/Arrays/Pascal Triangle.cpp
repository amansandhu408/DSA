#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> solve(int A);  // Declaration of the member function
};





vector<vector<int>> Solution::solve(int A) {
    // Initialize the result as an empty vector of vectors
    vector<vector<int>> triangle;
    
    // Special case: If A is 0, just return the empty triangle
    if (A == 0) {
        return triangle;
    }
    
    // First row is always [1]
    triangle.push_back({1});
    
    // Start constructing the subsequent rows
    for (int row = 1; row < A; ++row) {
        vector<int> currentRow(row + 1, 1);  // Initialize the current row with 1s
        
        // Fill in the inner elements of the row
        for (int col = 1; col < row; ++col) {
            currentRow[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
        }
        
        // Add the current row to the triangle
        triangle.push_back(currentRow);
    }
    
    return triangle;
}
