#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int l=0 , r=0 , len = s.length();
        for(int i= 0; i< len ; i++){
            while(i<len && s[i] != ' '){
                s[r++] =s[i++];
            }
            if(l < r){
                reverse(s.begin() + l,s.begin() + r);
                if(r == len){
                    break;
                }
                s[r++] = ' ';
                l =r;
            }
        }
        if(s[r-1]==' '){
            r--;
        }
        s.resize(r);
        return s;
    }
};