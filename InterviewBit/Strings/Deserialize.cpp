#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> Solution::deserialize(string A) ;
};














vector<string> Solution::deserialize(string A) {
    vector<string> ans;
    int i = -1;
    int j = 0;
    while(j < A.size()){
        while(A[j] <= 122 && A[j] >= 97){
            j++;
        }
        ans.push_back(A.substr(i + 1, j - i - 1));
        while(j < A.size() && A[j] != '~'){
            j++;
        }
        i = j++;
    }   
    return ans;
}