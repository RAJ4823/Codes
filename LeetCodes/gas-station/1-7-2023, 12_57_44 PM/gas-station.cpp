// Link: https://leetcode.com/problems/gas-station

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: gas-station
 *  RUNTIME: 65 ms
 *  MEMORY: 69.5 MB
 *  DATE: 1-7-2023, 12:57:44 PM
 *
 */

// Solution:

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int currGas = 0, start = 0;
        int n = cost.size();

        for(int i=0; i<n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            if(currGas < 0) {
                currGas = 0;
                start = i;
            }

            currGas += (gas[i] - cost[i]);
        }
        if(totalGas < totalCost) start = -1;
        return start;
    }
};
