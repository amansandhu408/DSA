#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::solve(vector<int> &A, int B);
};











// Helper function for binary search on the increasing part
int binarySearchIncreasing(const vector<int>& A, int low, int high, int B) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == B) return mid;
        else if (A[mid] < B) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Helper function for binary search on the decreasing part
int binarySearchDecreasing(const vector<int>& A, int low, int high, int B) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == B) return mid;
        else if (A[mid] > B) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int findBitonicPoint(const vector<int>& A) {
    int low = 0, high = A.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((mid == 0 || A[mid - 1] < A[mid]) && (mid == A.size() - 1 || A[mid] > A[mid + 1])) {
            return mid; // mid is the bitonic point
        } else if (A[mid] < A[mid + 1]) {
            low = mid + 1; // peak is to the right
        } else {
            high = mid - 1; // peak is to the left
        }
    }
    return -1;
}

int Solution::solve(vector<int>& A, int B) {
    int n = A.size();
    
    // Step 1: Find the bitonic point
    int bitonicPoint = findBitonicPoint(A);
    
    // Step 2: Search in the increasing part (from 0 to bitonicPoint)
    int result = binarySearchIncreasing(A, 0, bitonicPoint, B);
    if (result != -1) return result;
    
    // Step 3: Search in the decreasing part (from bitonicPoint to n-1)
    return binarySearchDecreasing(A, bitonicPoint + 1, n - 1, B);
}
