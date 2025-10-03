#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> prettyPrint(int A);  // Declaration of the member function
};





vector<vector<int> > Solution::prettyPrint(int A) {
    int size = 2 * A - 1; // Calculate the size of the matrix
    vector<vector<int>> result(size, vector<int>(size)); // Create a 2D vector of given size

    // Fill the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Calculate the value at position (i, j)
            result[i][j] = A - min(min(i, j), min(size - i - 1, size - j - 1));
        }
    }

    return result; // Return the filled matrix
}
