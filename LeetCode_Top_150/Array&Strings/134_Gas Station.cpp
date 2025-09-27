#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0;
        int totalCost = 0;
        int fuelCapacity = 0;
        int requiredIndex = 0;
        for(int i = 0; i < n ; i++){
            totalGas += gas[i];
            totalCost += cost[i];
            fuelCapacity += gas[i] - cost[i];
            if(fuelCapacity < 0){
                requiredIndex = i+1;
                fuelCapacity = 0;
            }
        }
        if(totalCost > totalGas){
            return -1;
        }
        return requiredIndex;
    }
};