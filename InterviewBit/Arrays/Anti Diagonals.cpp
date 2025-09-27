#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonal(vector<vector<int>> &A);  // Declaration of the member function
};






vector<vector<int>> Solution::diagonal(vector<vector<int>> &A) {
    int N = A.size();
    vector<vector<int>> result;
    
    // Loop through the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = i + j;
            
            // If the result vector doesn't have this anti-diagonal yet
            if (result.size() <= sum) {
                result.push_back({});
            }
            
            // Add the element to the corresponding anti-diagonal
            result[sum].push_back(A[i][j]);
        }
    }
    
    return result;
}
