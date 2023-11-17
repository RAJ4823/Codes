// Link: https://leetcode.com/problems/min-cost-climbing-stairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: min-cost-climbing-stairs
 *  RUNTIME: 0 ms
 *  MEMORY: 14 MB
 *  DATE: 10-13-2023, 9:39:26 AM
 *
 */

// Solution:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = cost[0];
        dp[1] = cost[1];
        cost.push_back(0);
        for(int i=2; i<n+1; i++) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return dp[n];
    }
};
