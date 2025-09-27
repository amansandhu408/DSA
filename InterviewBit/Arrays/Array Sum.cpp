#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addArrays(vector<int> &A, vector<int> &B);  // Declaration of the member function
};









vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    int i = A.size() - 1;
    int j = B.size() - 1;
    int carry = 0;
    vector<int> result;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        if (i >= 0) {
            sum += A[i];
            i--;
        }
        
        if (j >= 0) {
            sum += B[j];
            j--;
        }

        carry = sum / 10;  // Carry for next iteration
        result.push_back(sum % 10);  // Add the current digit (sum % 10)
    }

    // The result is constructed from least significant to most significant, so we reverse it.
    reverse(result.begin(), result.end());
    
    return result;
}
