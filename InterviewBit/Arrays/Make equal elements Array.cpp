#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &A, int B);  // Declaration of the member function
};






int Solution::solve(vector<int> &A, int B) {
    vector<int> Bplus;
    vector<int> Cmin;
    for(int i =0 ; i<A.size();i++){
        Bplus.push_back(A[i]+B);
    }
    for(int i =0 ; i<A.size();i++){
        Cmin.push_back(A[i]-B);
    }
    unordered_set<int>s(Bplus.begin(),Bplus.end());
    int temp;
    for(int i=0; i<Cmin.size();i++){
        if(s.find(Cmin[i]) != s.end()){
            temp = Cmin[i];
        }
    }
    for(int i =0 ; i<A.size() ; i++){
        if(A[i]==temp){
            return 1;
        }
    }
    return 0;
}
