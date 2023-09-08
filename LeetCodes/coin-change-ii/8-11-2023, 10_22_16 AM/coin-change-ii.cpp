// Link: https://leetcode.com/problems/coin-change-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: coin-change-ii
 *  RUNTIME: 40 ms
 *  MEMORY: 18.5 MB
 *  DATE: 8-11-2023, 10:22:16 AM
 *
 */

// Solution:

class Solution {
public:
    int ways = 0;
    int find(int i, int sum, vector<int> &coins, vector<vector<int>> &dp) {
        if(i < 0) return (sum == 0);
        if(sum == 0) return 1;

        if(dp[i][sum] != -1) return dp[i][sum];

        int take = 0, nottake = 0;
        if(sum >= coins[i]) take = find(i, sum - coins[i], coins, dp);
        nottake = find(i-1, sum, coins, dp);

        return dp[i][sum] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));

        dp[0][0] = 1;
        for(int i=1; i<=n; i++) {
            dp[i][0] = 1;
            for(int sum=1; sum <= amount; sum++) {
                if(sum >= coins[i-1]) {
                    dp[i][sum] = dp[i][sum - coins[i-1]] + dp[i-1][sum];
                } else {
                    dp[i][sum] = dp[i-1][sum];
                }
            }
        }
        return dp[n][amount];
    }
};
