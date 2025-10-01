#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Solution::repeatedNumber(const vector<int> &A);  // Declaration of the member function
};














// Helper function to return the minimum of two numbers
int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int Solution::repeatedNumber(const vector<int> &A) {
    // Step 1: Calculate the block size (sqrt(n))
    // The length of the array is A.size(), but since the array contains n+1 elements, we calculate the block size.
    int sq = sqrt(A.size() - 1); // Block size based on square root of n (size of A minus 1)
    
    // Step 2: Calculate the number of blocks (ranges)
    int num_ranges = ceil((A.size() - 1) / (double)sq); // Number of ranges or blocks to divide the array into
    
    // Step 3: Initialize the 'hash' array to keep track of the count of elements in each block
    vector<int> hash(num_ranges + 1, 0); // 'hash' array to store the count of elements in each block
    
    // Step 4: Populate the 'hash' array by iterating through the input array
    for (int i = 0; i < A.size(); i++) {
        // Determine which block the current element belongs to
        int r_num = ceil(A[i] / (double)sq);  // 'r_num' is the block index of the current element
        
        // Increment the count of the block in the 'hash' array
        hash[r_num]++;
    }

    // Step 5: Identify which block contains the duplicate number by checking the 'hash' array
    int i;
    for (i = 1; i < hash.size(); i++) {
        if (hash[i] > sq) {  // If any block contains more than 'sq' elements, it's guaranteed to have a duplicate
            break;  // Exit the loop as we found the block containing the duplicate
        }
    }
    
    // Step 6: Adjust 'loc' to point to the block with the duplicate
    int loc = i;
    if (i == hash.size()) {
        loc = i - 1;  // If no duplicate block was found, set loc to the last block
    }

    // Step 7: Clear the 'hash' array and prepare for checking the actual duplicate within the found block
    hash.clear();

    // Step 8: Determine the range (beginning and end) of the found block
    int beg = sq * (loc - 1) + 1;  // The start of the range of the block
    int end = min(sq * loc, A.size() - 1);  // The end of the range of the block (ensure we don't go out of bounds)

    // Step 9: Initialize a new 'hash1' array to track the counts of elements in the specific block
    vector<int> hash1(sq, 0); // 'hash1' array to store the frequency of elements within the block

    // Step 10: Traverse the array and count how many elements fall within the current block's range
    for (int i = 0; i < A.size(); i++) {
        // Check if the current element lies within the current block's range
        if (A[i] <= end && (A[i] - beg) >= 0) {
            // Increment the count of the corresponding index in 'hash1'
            hash1[A[i] - beg]++;
        }
    }

    // Step 11: Check if any number in the block appears more than once
    for (int i = 0; i < hash1.size(); i++) {
        if (hash1[i] > 1) {  // If an element appears more than once, it is the duplicate
            return beg + i;  // Return the duplicate element
        }
    }

    // Step 12: If no duplicate is found (which shouldn't happen in the problem's context), return 0 (indicating no duplicates)
    return 0;
}
