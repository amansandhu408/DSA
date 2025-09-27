#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0; // Left pointer for the sliding window
        int sumOfCurrentWindow = 0; // Sum of the current subarray
        int res = INT_MAX; // Variable to store the minimum length of a valid subarray

        // Iterate over the array with the right pointer
        for (int right = 0; right < nums.size(); right++) {
            // Add the current element to the sum of the window
            sumOfCurrentWindow += nums[right];

            // While the sum is greater than or equal to the target, shrink the window
            while (sumOfCurrentWindow >= target) {
                // Update the result with the minimum length of the valid subarray
                res = min(res, right - left + 1);
                
                // Shrink the window from the left
                sumOfCurrentWindow -= nums[left];
                left++;
            }
        }

        // If no valid subarray was found, return 0
        return res == INT_MAX ? 0 : res;
    }
};
