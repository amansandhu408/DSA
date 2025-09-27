#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candycount(n, 1);
        int answer =0;
        for(int i =1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                candycount[i] = candycount[i-1] + 1;
            }
        }
        for(int i = n -2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i + 1]){
                candycount[i] = max(candycount[i], candycount[i+1] + 1 );
            }
        }
        for(int i = 0 ; i< n ; i++){
            answer += candycount[i];
        }
        return answer;
    }
};