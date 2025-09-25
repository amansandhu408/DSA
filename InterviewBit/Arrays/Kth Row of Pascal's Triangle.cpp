#include <bits/stdc++.h>
#include <vector>   // for std::vector
using namespace std;

class Solution {
public:
    vector<int> getRow(int k);  // Declaration of the member function
};




vector<int> Solution::getRow(int k) {
    // Step 1: Initialize the row with k+1 elements, all set to 1
    vector<int> row(k + 1, 1);  // Each row starts and ends with 1

    // Step 2: Iterate through each row starting from row 1 to row k
    for (int i = 1; i <= k; i++) {
        
        // Step 3: Update each element in the row (except the first and last 1s)
        // We iterate backward to avoid overwriting values from the current row
        for (int j = i - 1; j > 0; j--) {
            
            // Step 4: Update the element by adding the value from the previous row
            row[j] = row[j] + row[j - 1];  // Sum of the two elements above
        }
    }

    // Step 5: Return the computed row
    return row;
};
