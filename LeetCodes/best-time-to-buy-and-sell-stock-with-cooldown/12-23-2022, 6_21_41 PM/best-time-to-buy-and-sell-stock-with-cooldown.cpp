// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-time-to-buy-and-sell-stock-with-cooldown
 *  RUNTIME: 22 ms
 *  MEMORY: 12.1 MB
 *  DATE: 12-23-2022, 6:21:41 PM
 *
 */

// Solution:

class Solution {
private:
    int find(int i, int flag, vector<int> &values, int n, vector<vector<int>> &dp) {
        if (i >= n)             return 0;
        if (dp[i][flag] != -1)   return dp[i][flag];

        int profit = 0, skipit = 0;
        if (flag)
            profit = find(i + 1, !flag, values, n, dp) - values[i];
        else
            profit = find(i + 2, !flag, values, n, dp) + values[i];
        
        skipit = find(i + 1, flag, values, n, dp);
        return dp[i][flag] = max(profit, skipit);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        int ans = find(0, 1, prices, n, dp);
        return ans;
    }
};
