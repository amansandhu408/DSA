#include<bits/stdc++.h>
using namespace std;

class Solution {
    int highestScore(vector<vector<string>> &A);
};






int Solution::highestScore(vector<vector<string>> &A) {
    unordered_map<string, pair<int, int>> studentScores; // name -> {total_marks, count}
    
    for (auto &entry : A) {
        string name = entry[0];
        int marks = stoi(entry[1]);
        
        studentScores[name].first += marks;  // total marks
        studentScores[name].second += 1;     // count
    }

    int maxAvg = 0;
    for (auto &it : studentScores) {
        int total = it.second.first;
        int count = it.second.second;
        int avg = total / count;  // integer division, rounds down
        maxAvg = max(maxAvg, avg);
    }
    
    return maxAvg;
}
