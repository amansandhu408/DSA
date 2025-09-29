#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<string> &A);  // Declaration of the member function
};








// Helper function to find the minimum element in a vector
double min_element(const vector<double>& A) {
    return *min_element(A.begin(), A.end());
}

int Solution::solve(vector<string> &a) {
    vector<double> A, B, C;

    // Step 1: Convert each string to double and categorize it into A, B, or C
    for (int i = 0; i < a.size(); ++i) {
        double value = stod(a[i]);  // Convert string to double using stod
        
        // Categorize the number into appropriate set based on its value
        if (value > 0.0 && value < 2.0 / 3.0) {
            A.push_back(value);  // 0 < value < 2/3 -> Set A
        } else if (2.0 / 3.0 <= value && value <= 1.0) {
            B.push_back(value);  // 2/3 <= value <= 1 -> Set B
        } else if (1.0 < value && value < 2.0) {
            C.push_back(value);  // 1 < value < 2 -> Set C
        }
    }

    int res = 0;  // Default result is 0 (no valid triplet)

    // Step 2: Check case 1: Can we find 3 elements from A whose sum > 1?
    if (A.size() >= 3) {
        sort(A.begin(), A.end(), greater<double>());  // Sort A in descending order
        double sum = A[0] + A[1] + A[2];  // Sum the largest 3 values from A
        if (sum > 1.0) {
            return 1;  // Found a valid triplet from A
        }
    }

    // Step 3: Check case 2: Can we find 2 elements from A and 1 from B whose sum > 1?
    if (A.size() >= 2 && B.size() >= 1) {
        sort(A.begin(), A.end(), greater<double>());  // Sort A in descending order
        double sumA = A[0] + A[1];  // Sum the largest 2 values from A
        // Now check for a value in B that satisfies the sum condition
        for (double b : B) {
            if (1.0 - sumA < b && b < 2.0 - sumA) {
                return 1;  // Found a valid triplet with 2 from A and 1 from B
            }
        }
    }

    // Step 4: Check case 3: Can we find 2 elements from A and 1 from C whose sum < 2?
    if (A.size() >= 2 && C.size() >= 1) {
        sort(A.begin(), A.end());  // Sort A in ascending order (for minimum sum)
        double sumA = A[0] + A[1];  // Sum the smallest 2 values from A
        double minC = min_element(C);  // Get the smallest element from C
        if (sumA + minC < 2.0) {
            return 1;  // Found a valid triplet with 2 from A and 1 from C
        }
    }

    // Step 5: Check case 4: Can we find 2 elements from B and 1 from A whose sum < 2?
    if (B.size() >= 2 && A.size() >= 1) {
        sort(B.begin(), B.end());  // Sort B in ascending order
        double sumB = B[0] + B[1];  // Sum the smallest 2 values from B
        // Now check for a value in A that satisfies the sum condition
        for (double aVal : A) {
            if (aVal < 2.0 - sumB) {
                return 1;  // Found a valid triplet with 2 from B and 1 from A
            }
        }
    }

    // Step 6: Check case 5: Can we find 1 element from each of A, B, and C whose sum is between 1 and 2?
    if (A.size() >= 1 && B.size() >= 1 && C.size() >= 1) {
        double minA = min_element(A);  // Get the smallest element from A
        double minB = min_element(B);  // Get the smallest element from B
        double minC = min_element(C);  // Get the smallest element from C
        if (minA + minB + minC > 1.0 && minA + minB + minC < 2.0) {
            return 1;  // Found a valid triplet with 1 from each of A, B, and C
        }
    }

    // If no valid triplet is found, return 0
    return res;
}
