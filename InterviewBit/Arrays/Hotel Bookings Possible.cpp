#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hotel(vector<int> &arrive, vector<int>&depart , int K);  // Declaration of the member function
};








bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    assert(K>0 && K<=1000000);
    for(int a:arrive)
        assert(a>=0 && a<=1e8);
    for(int a:depart)
        assert(a>=0 && a<=1e8);
    for(int i=0;i<arrive.size();i++)
        assert(arrive[i]<=depart[i]);
    if(K == 0)
            return false;

    int N = arrive.size();
    assert(N>=1 && N<=1e6);
    vector<pair<int, int> > vec;
    for(int i = 0; i < N; ++i) {
        vec.push_back(make_pair(arrive[i], 0));
        vec.push_back(make_pair(depart[i], 1));
    }
     
    sort(vec.begin(), vec.end());
    
    int curActive = 0;
    int maxAns = 0;
    for (int i = 0; i < vec.size(); i++) {
       if (vec[i].second == 0) { // arrival
           curActive++;
           maxAns = max(maxAns, curActive);
        } else {
            curActive--;
        }
    } 
    if (K >= maxAns) return true;
    return false;
}