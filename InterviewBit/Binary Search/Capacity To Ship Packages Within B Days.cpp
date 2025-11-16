#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::solve(vector<int> &A, int B) ;
};








int Solution::solve(vector<int> &A, int B) {
    long long low = *max_element(A.begin(), A.end());
    long long high = accumulate(A.begin(), A.end(), 0LL);
    long long ans = high;

    auto canShip = [&](long long capacity) {
        int days = 1;
        long long currLoad = 0;
        for (int w : A) {
            if (currLoad + w > capacity) {
                days++;
                currLoad = w;
                if (days > B) return false;
            } else {
                currLoad += w;
            }
        }
        return true;
    };

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canShip(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)ans;
}
