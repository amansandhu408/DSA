#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(const vector<int> &A);  // Declaration of the member function
};







int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    
    // Edge case: If the array has less than two elements, return 0
    if (n < 2) {
        return 0;
    }
    
    // Find the minimum and maximum elements in the array
    int min_val = *min_element(A.begin(), A.end());
    int max_val = *max_element(A.begin(), A.end());
    
    // Calculate the gap (bucket size)
    int bucket_size = max(1, (max_val - min_val) / (n - 1));
    
    // Calculate the number of buckets
    int bucket_count = (max_val - min_val) / bucket_size + 1;
    
    // Create buckets
    vector<pair<int, int>> buckets(bucket_count, {INT_MAX, INT_MIN});
    
    // Distribute elements into buckets
    for (int i = 0; i < n; ++i) {
        if (A[i] == min_val || A[i] == max_val) {
            continue; // We will handle min and max separately later
        }
        
        int bucket_index = (A[i] - min_val) / bucket_size;
        buckets[bucket_index].first = min(buckets[bucket_index].first, A[i]);
        buckets[bucket_index].second = max(buckets[bucket_index].second, A[i]);
    }
    
    // Initialize the previous maximum to the min element
    int prev_max = min_val;
    int max_gap = 0;
    
    // Traverse the buckets
    for (int i = 0; i < bucket_count; ++i) {
        if (buckets[i].first == INT_MAX) {
            continue; // Empty bucket, skip
        }
        
        // Calculate the gap between the current bucket's minimum and the previous bucket's maximum
        max_gap = max(max_gap, buckets[i].first - prev_max);
        
        // Update the previous maximum to the current bucket's maximum
        prev_max = buckets[i].second;
    }
    
    // Finally, calculate the gap between the max value and the previous maximum
    max_gap = max(max_gap, max_val - prev_max);
    
    return max_gap;
}
