#include<bits/stdc++.h>
using namespace std;

class Solution {
    string Solution::serialize(vector<string> &A) ;
};









string Solution::serialize(vector<string> &A) {
    string result = "";
    
    // Iterate over all the strings in the array
    for (const string& str : A) {
        // Append the string and its length followed by '~'
        result += str + to_string(str.length()) + "~";
    }
    
    return result;
}
