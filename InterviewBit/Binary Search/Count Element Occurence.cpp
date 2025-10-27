#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::findCount(const vector<int>& A, int B) ;
};








int findFirst(const vector<int>& A, int B) {
    int left = 0, right = A.size() - 1;
    int first = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == B) {
            first = mid;
            right = mid - 1; // Continue searching in the left half
        } else if (A[mid] < B) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return first;
}

int findLast(const vector<int>& A, int B) {
    int left = 0, right = A.size() - 1;
    int last = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == B) {
            last = mid;
            left = mid + 1; // Continue searching in the right half
        } else if (A[mid] < B) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last;
}

int Solution::findCount(const vector<int>& A, int B) {
    // Find the first occurrence
    int first = findFirst(A, B);
    if (first == -1) {
        return 0; // If the element is not found at all
    }
    
    // Find the last occurrence
    int last = findLast(A, B);
    
    // The count is the difference between the last and first indices + 1
    return last - first + 1;
}
