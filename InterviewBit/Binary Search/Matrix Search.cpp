#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::searchMatrix(vector<vector<int>> &A, int B);
};






int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int N = A.size();      // Number of rows
    int M = A[0].size();   // Number of columns
    
    int low = 0;
    int high = N * M - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Find the row and column corresponding to mid
        int midValue = A[mid / M][mid % M];
        
        if (midValue == B) {
            return 1;
        } else if (midValue < B) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return 0;
}
