#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> &A);  // Declaration of the member function
};







vector<int> Solution::solve(vector<int> &A) {
    int LastNonZeroIndex = 0;
    
    //Move all non-zero elements to the front of the array
    for (int i = 0; i < A.size(); i++){
        if( A[i] != 0){
            A[LastNonZeroIndex] = A[i];
            if(i != LastNonZeroIndex){
                A[i] = 0;
            }
            LastNonZeroIndex++;          
        }
    }
    return A;
}
