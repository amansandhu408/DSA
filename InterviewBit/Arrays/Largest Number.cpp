#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(const vector<int> &A);
};





string Solution::largestNumber(const vector<int> &A) {
    vector<string> nums;
    
    // Convert integers to strings
    for (int num : A) {
        nums.push_back(to_string(num));
    }
    
    // Custom comparator: if ab > ba, a comes before b
    sort(nums.begin(), nums.end(), [](string &a, string &b) {
        return a + b > b + a;
    });
    
    // Edge case: if the largest number is "0", then all numbers are zero
    if (nums[0] == "0") return "0";
    
    // Concatenate all sorted strings
    string result;
    for (const string &s : nums) {
        result += s;
    }
    
    return result;
}
