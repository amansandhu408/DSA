#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOccurences(vector<int> &A); // Declaration of the member function
};


vector<int> Solution::findOccurences(vector<int> &A) {
    unordered_map<int, int> maps;
    
    // Step 1: count frequencies of each number
    for(int num : A){
        maps[num]++;
    }
    
    // Step 2: Extract and Sort the unique keys
    vector<int> keys;
    for(auto &entry : maps){
        keys.push_back(entry.first);
    }
    sort(keys.begin(), keys.end());
    
    // Step 3: Collect frequencies in sorted order
    vector<int> result;
    for(int key : keys){
        result.push_back(maps[key]);
    }
    
    // Step 4 : result
    return result;   
}