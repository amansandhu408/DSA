#include <vector>
#include <climits>  // for INT_MAX
using namespace std;


/*
//Approach 1 :  Recursion with Memoization
//T.C : O(n^2) states in t[][]
//S.C : O(n^2)
class Solution {
public:
    int t[201][201];
    int n;
    int solve(vector<vector<int>>& triangle, int row, int col) {
        if (row == n-1)
            return triangle[row][col];

        if(t[row][col] != INT_MAX)
            return t[row][col];
        
        int minPath = triangle[row][col] + 
                      min(solve(triangle, row + 1, col),
                          solve(triangle, row + 1, col + 1));

        return t[row][col] = minPath;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
       
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                t[i][j] = INT_MAX;
            }
        }
        return solve(triangle, 0, 0);
    }
};


*/



//Approach-2 : Bottom Up - Just like "Minimum Falling Path Sum"
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> t = triangle;  // copy triangle for t

        // Start from second last row and move upwards
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) { //1st row me 1 column, 2nd Row me 2 Columns, and so on, that's why (col <= row)
                t[row][col] += min(t[row + 1][col], t[row + 1][col + 1]);
            }
        }

        return t[0][0];  // minimum path sum
    }
};
