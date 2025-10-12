#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int A,int B,int C, int D);
};







int Solution::solve(int A, int B, int C, int D) {
    // Create an array to store the sides
    int sides[4] = {A, B, C, D};
    
    // Sort the array
    sort(sides, sides + 4);
    
    // Check if the first two and the last two sides are equal
    if (sides[0] == sides[1] && sides[2] == sides[3]) {
        return 1; // It's a rectangle
    } else {
        return 0; // Not a rectangle
    }
}
