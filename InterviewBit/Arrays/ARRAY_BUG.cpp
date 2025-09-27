#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateArray(vector<int> &A, int B);  // Declaration of the member function
};




vector<int> Solution::rotateArray(vector<int> &A, int B) {
	vector<int> ret; 
	for (int i = 0; i < A.size(); i++) {
        B = B % (A.size());  // handle B > n
		ret.push_back(A[(i + B)% (A.size())]);
	}
	return ret; 
}
