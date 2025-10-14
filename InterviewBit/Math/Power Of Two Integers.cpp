#include<bits/stdc++.h>
using namespace std;

class Solution {
    int isPower(int A );
};





int Solution::isPower(int A) {
    if (A == 1) return 1;  // 1 is always a power (1^P for any P)
    
    for (int base = 2; base * base <= A; base++) { // Start from base 2 and check till base^2 <= A
        long long power = base;
        while (power <= A) {
            power *= base;
            if (power == A) {
                return 1;
            }
        }
    }
    return 0;
}
