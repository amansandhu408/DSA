#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPerm(const string A,int B);  // Declaration of the member function
};








vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans(B);
    for (int i = 0; i < B; i++) ans[i] = i + 1;

    int i = 0;
    while (i < B - 1) {
        if (A[i] == 'D') {
            int start = i;
            while (i < B - 1 && A[i] == 'D') i++;
            reverse(ans.begin() + start, ans.begin() + i + 1);
        } else {
            i++;
        }
    }
    return ans;
}
