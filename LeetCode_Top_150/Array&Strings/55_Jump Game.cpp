#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxindex = 0;
        for(int i =0; i< nums.size(); i++){
            if (maxindex >= n - 1){
                return true;
            } else if(maxindex ==i && nums[i]==0){
                return false;
            }
            maxindex = max(maxindex , i + nums[i]);
        }
        return true;
    }
};