#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int range = 0;
        int maxindex = 0;
        int n = nums.size();
        if(n==1){
            return 0;
        }
        for(int i = 0; i<n ; i++){
            range =max(range , i + nums[i]);
            if(i== maxindex){
                maxindex =range;
                jumps++;
                if(maxindex >= n-1){
                    return jumps;
                }
            }
        }
        return jumps;
    }
};