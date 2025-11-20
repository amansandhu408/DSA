#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::findMin(const vector<int> &A);
};











int Solution::findMin(const vector<int> &A) {
    int l = 0, r = A.size() - 1;

    while (l < r) {
        // If the segment is already sorted, return the first element
        if (A[l] < A[r]) return A[l];

        int mid = l + (r - l) / 2;

        // If left part is sorted, minimum must be in right half
        if (A[mid] >= A[l]) {
            l = mid + 1;
        } 
        // Otherwise, minimum is in left half including mid
        else {
            r = mid;
        }
    }

    return A[l];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
}

