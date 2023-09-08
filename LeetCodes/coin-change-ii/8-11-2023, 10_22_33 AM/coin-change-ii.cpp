// Link: https://leetcode.com/problems/coin-change-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: coin-change-ii
 *  RUNTIME: 35 ms
 *  MEMORY: 18.6 MB
 *  DATE: 8-11-2023, 10:22:33 AM
 *
 */

// Solution:

class Solution {
public:
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
