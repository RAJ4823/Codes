// Link: https://leetcode.com/problems/min-cost-climbing-stairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: min-cost-climbing-stairs
 *  RUNTIME: 5 ms
 *  MEMORY: 13.9 MB
 *  DATE: 10-13-2023, 9:40:44 AM
 *
 */

// Solution:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1, prev2, curr;
        prev1 = cost[1];
        prev2 = cost[0];
        cost.push_back(0);
        for(int i=2; i<n+1; i++) {
            curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
