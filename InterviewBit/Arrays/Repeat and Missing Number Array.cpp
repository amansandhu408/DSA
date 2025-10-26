#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> repeatedNumber(const vector<int> &A);  // Declaration of the member function
};








vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    
    long long sumN = n * (n + 1) / 2;
    long long sumSqN = n * (n + 1) * (2 * n + 1) / 6;
    
    long long sumA = 0, sumSqA = 0;
    for (int num : A) {
        long long val = num;
        sumA += val;
        sumSqA += val * val;
    }
    
    long long diffSum = sumA - sumN;         // x - y
    long long diffSqSum = sumSqA - sumSqN;   // x^2 - y^2 = (x - y)(x + y)
    
    long long sumXY = diffSqSum / diffSum;   // x + y
    
    long long x = (diffSum + sumXY) / 2;
    long long y = x - diffSum;
    
    return {(int)x, (int)y};
}
