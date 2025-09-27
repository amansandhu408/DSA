#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxset(vector<int> &A);  // Declaration of the member function
};






vector<int> Solution::maxset(vector<int> &A) {
    long long maxSum = -1;
    int maxStart = -1;
    int maxLen =0;
    
    long long currentSum =0;
    int currentStart =0;
    
    vector <int> result;
    vector<int> currentSubArray;
    
    for(int i=0 ; i< A.size(); i++){
       if(A[i] >= 0){
           currentSum += A[i];
           currentSubArray.push_back(A[i]);
       } else {
           // check if current subarray is better than the best so far
           if (
               currentSum > maxSum || 
               (currentSum == maxSum && currentSubArray.size() > maxLen) || 
               (currentSum == maxSum && currentSubArray.size() == maxLen && currentStart < maxStart) 
            ){
                maxSum = currentSum;
                maxStart = currentStart;
                maxLen = currentSubArray.size();
                result = currentSubArray;
            }
            
            // Reset current subarray 
            currentSum = 0;
            currentStart = i +1;
            currentSubArray.clear();
       }
    }
    
    // Final check for last subarray(in case it doesn't end with a negative number)
    if (
        currentSum > maxSum || 
        (currentSum == maxSum && currentSubArray.size() > maxLen) || 
        (currentSum == maxSum && currentSubArray.size() == maxLen && currentStart < maxStart) 
    ){
        result = currentSubArray;
    }
    
    return result;
}