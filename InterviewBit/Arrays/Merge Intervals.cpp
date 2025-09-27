#include <bits/stdc++.h>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);  // Declaration of the member function
};






/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    int n = intervals.size();
    int i = 0;
    
    // Step 1 : Add all intervals that end before the new interval starts
    while(i< n && intervals[i].end < newInterval.start){
        result.push_back(intervals[i]);
        i++;
    }
    
    // Step 2 : Merge all intervals that overlap with the new interval
    while(i< n && intervals[i].start <= newInterval.end){
        newInterval.start = min(newInterval.start , intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
        i++;
    }
    
    //Add the merged interval
    result.push_back(newInterval);
    
    // Step 3 : Add all intervals that start after the new interval ends
    while( i< n){
        result.push_back(intervals[i]);
        i++;
    }
    
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}