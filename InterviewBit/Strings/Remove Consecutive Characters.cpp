#include<bits/stdc++.h>
using namespace std;

class Solution {
    string Solution::solve(string A, int B);
};








/* iB code
string Solution::solve(string A, int B) {
    string ans = "";
    for( int i = 0; i < A.size(); i++ ) {
        int j = i;
        string temp = "";
        while(j < A.size() && A[i] == A[j] ) {
            temp += A[i]; 
            j++;
        } 
        if( j - i != B ) ans += temp; 
        i = j - 1;
    }
    return ans;
}

*/





// correct code
string Solution::solve(string A, int B) {
    stack<pair<char, int>> st;  // Stack to store characters and their counts
    
    for (char c : A) {
        // If the stack is not empty and the top character is the same as the current one
        if (!st.empty() && st.top().first == c) {
            // Increase the count of the top character
            st.top().second++;
            
            // If the count reaches B, pop it (i.e., remove the group of B characters)
            if (st.top().second == B) {
                st.pop();
            }
        } else {
            // If the character is different, push it onto the stack with a count of 1
            st.push({c, 1});
        }
    }
    
    // Rebuild the result string from the stack
    string result = "";
    while (!st.empty()) {
        result = string(st.top().second, st.top().first) + result;
        st.pop();
    }
    
    return result;
}
