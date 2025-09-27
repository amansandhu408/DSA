#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArr( vector<int> &A); // Declaration of the member function
};



int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    
    // Initialize min and max for the transformed arrays.
    int minB = INT_MAX , maxB = INT_MIN;
    int minC = INT_MAX , maxC = INT_MIN;
    
    // Calculate min/max for function : A[i] -  i and A[i] + i
    for(int i =0; i< n; ++i){
        minB =min(minB, A[i]-i);
        maxB =max(maxB, A[i]-i);
        minC =min(minC, A[i]+i);
        maxC =max(maxC, A[i]+i);
    }
    
    // the result is the maximum of the differences
    return max(maxB - minB, maxC - minC);
}
