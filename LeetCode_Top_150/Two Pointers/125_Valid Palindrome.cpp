#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";

        // Remove non-alphanumeric and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                s1 += tolower(c);
            }
        }

        // Compare with reverse
        string rev = s1;
        reverse(rev.begin(), rev.end());

        return s1 == rev;
    }
};
