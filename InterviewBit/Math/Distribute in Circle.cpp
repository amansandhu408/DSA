#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int A , int B , int C);
};










int Solution::solve(int A, int B, int C) {
    return ((C + A - 2) % B) + 1;
}
