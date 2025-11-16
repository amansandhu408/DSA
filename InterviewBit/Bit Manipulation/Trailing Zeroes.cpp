#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::solve(int A) ;
};









int Solution::solve(int A) {
    int count = 0;
    while ((A & 1) == 0) {  // while least significant bit is 0
        count++;
        A >>= 1;            // right shift A
    }
    return count;
}
