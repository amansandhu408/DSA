#include<bits/stdc++.h>
using namespace std;

class Solution {
    int searchInsert(vector<int> &A, int B) ;
};









int Solution::searchInsert(vector<int> &A, int B) {
    int left = 0, right = A.size() - 1;
    int ans = A.size();  // Default position: insert at the end
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (A[mid] == B)
            return mid; // Found target, return index
        else if (A[mid] > B) {
            ans = mid;      // Possible insert position
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return ans;
}