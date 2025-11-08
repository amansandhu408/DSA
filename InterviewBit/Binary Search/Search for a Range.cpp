#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> searchRange(const vector<int> &A, int B) ;
};













vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    int left = 0, right = n - 1;
    int first = -1, last = -1;
    
    // Find first occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == B) {
            first = mid;
            right = mid - 1;  // keep searching left side
        } 
        else if (A[mid] < B) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    // If element not found, return [-1, -1]
    if (first == -1)
        return {-1, -1};
    
    // Find last occurrence
    left = 0;
    right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == B) {
            last = mid;
            left = mid + 1;  // keep searching right side
        } 
        else if (A[mid] < B) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    return {first, last};
}
