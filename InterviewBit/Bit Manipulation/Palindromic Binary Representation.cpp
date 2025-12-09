#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Solution::solve(int A) ;
};












int Solution::solve(int A) {
    long long a = A;

    long long length = 1;
    while (true) {
        long long half = (length + 1) / 2;
        long long count = 1LL << (half - 1);

        if (a > count) {
            a -= count;
            length++;
        } else {
            break;
        }
    }

    long long half = (length + 1) / 2;

    long long left = (1LL << (half - 1)) | (a - 1);

    long long res = left;

    long long tmp = left;
    if (length % 2 == 1) tmp >>= 1;    // for odd lengths, skip middle bit

    while (tmp > 0) {
        res = (res << 1) | (tmp & 1);
        tmp >>= 1;
    }

    return (int)res;
}