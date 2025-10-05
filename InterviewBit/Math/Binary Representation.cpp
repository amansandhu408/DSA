#include<bits/stdc++.h>
using namespace std;

class Solution {
    string findDigitsInBinary(int A);
};






string Solution::findDigitsInBinary(int A) {
    if (A == 0){
        return "0";
    }
    
    string binary = "";
    
    // Divide A by 2 untill N becomes 0;
    while (A >0 ){
        binary = to_string(A % 2) + binary;
        A /= 2;
    }
    
    return binary;
}