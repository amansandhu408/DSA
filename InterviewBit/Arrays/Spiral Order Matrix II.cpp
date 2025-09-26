#include <bits/stdc++.h>
#include <vector>   // for std::vector
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int A);  // Declaration of the member function
};




vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> matrix(A, vector<int>(A));
    int top = 0, bottom = A - 1;
    int left = 0, right = A - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        // Fill top row
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // Fill right column
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Fill bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        // Fill left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    return matrix;
}
