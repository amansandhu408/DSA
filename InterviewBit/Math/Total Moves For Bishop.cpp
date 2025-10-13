#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int A,int B);
};










int Solution::solve(int A, int B) {
    // Calculate the number of squares the bishop can move in each direction
    int top_left = min(A - 1, B - 1);     // Top-left diagonal
    int top_right = min(A - 1, 8 - B);    // Top-right diagonal
    int bottom_left = min(8 - A, B - 1);  // Bottom-left diagonal
    int bottom_right = min(8 - A, 8 - B); // Bottom-right diagonal
    
    // Total moves is the sum of moves in all four diagonal directions
    return top_left + top_right + bottom_left + bottom_right;
}
