#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &A);  // Declaration of the member function
};




vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    int carry = 1; // we need to add 1 initially
    
    // Traverse from the end
    for(int i = n -1; i >= 0 && carry; i--){
        int sum = A[i] + carry;
        A[i] = sum % 10;
        carry = sum / 10;
    }
    
    // If carry is still left
    if(carry){
        A.insert(A.begin(),1);
    }
    
    // Remove leading zeros
    int i = 0;
    while(i < A.size() && A[i] == 0){
        i++; 
    }
    
    // Return the vector from the first non- zero digit
    return vector<int>(A.begin() + i, A.end()); 
}
