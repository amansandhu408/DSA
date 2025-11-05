#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNumber(const vector<int> &A); 
};











int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    if (n == 0) return -1;

    int candidate1 = -1, candidate2 = -1;
    int count1 = 0, count2 = 0;

    // Step 1: Find potential candidates
    for (int num : A) {
        if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
        else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify actual counts
    count1 = count2 = 0;
    for (int num : A) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }

    if (count1 > n / 3) return candidate1;
    if (count2 > n / 3) return candidate2;
    return -1;
}
