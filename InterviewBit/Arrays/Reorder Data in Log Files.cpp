#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> reorderLogs(vector<string> &A);  // Declaration of the member function
};






vector<string> Solution::reorderLogs(vector<string> &A) {
    int n = A.size();
    queue<string> q;
    set<string> s;
    vector<string> a;

    for (int i = 0; i < n; i++) {
        int dashPos = A[i].find('-');
       
            // Check if the character after the dash is a digit
            if (isdigit(A[i][dashPos + 1])) {
                // It's a digit log
                if (s.find(A[i]) == s.end()) {
                    q.push(A[i]);
                    s.insert(A[i]);
                }
            } else {
                // It's a letter log
                a.push_back(A[i]);
            }
       
    }

    // Sort letter logs lexicographically
    sort(a.begin(), a.end(), [](const string &log1, const string &log2) {
        int dashPos1 = log1.find('-');
        int dashPos2 = log2.find('-');
        string content1 = log1.substr(dashPos1 + 1);
        string content2 = log2.substr(dashPos2 + 1);
        string id1 = log1.substr(0, dashPos1);
        string id2 = log2.substr(0, dashPos2);
       
        if (content1 != content2) {
            return content1 < content2; // Sort by content
        }
        return id1 < id2; // Sort by identifier
    });

    // Prepare the result
    vector<string> ans = a;
    while (!q.empty()) {
        string f = q.front();
        q.pop();
        ans.push_back(f);
    }

    return ans;
   
}