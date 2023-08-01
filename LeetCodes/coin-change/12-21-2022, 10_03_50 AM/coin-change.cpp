// Link: https://leetcode.com/problems/coin-change

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: coin-change
 *  RUNTIME: 183 ms
 *  MEMORY: 45.3 MB
 *  DATE: 12-21-2022, 10:03:50 AM
 *
 */

// Solution:

class Solution {
private:
    // Recursive DP
    int find(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if(amount == 0) return 0;
        if(i == 0) {
            if(amount % coins[i] == 0)
                return (amount / coins[i]);
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];

        int pick = 1e9, notpick = 1e9;
        if(amount >= coins[i])
            pick = 1 + find(i, amount - coins[i], coins, dp);
        notpick = find(i-1, amount, coins, dp);

        return dp[i][amount] = min(pick, notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1));
        // int ans = find(n-1, amount, coins, dp);

        // Iterative DP
        for(int i=0; i<n; i++)
            dp[i][0] = 0;
        for(int j=0; j<=amount; j++) {
            if(j % coins[0] == 0)
                dp[0][j] = (j / coins[0]);
            else
                dp[0][j] = 1e9;
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=amount; j++) {
                int pick = 1e9, notpick = 1e9;
                if(j >= coins[i])
                    pick = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(pick, dp[i-1][j]);
            }
        }
        int ans = dp[n-1][amount];
        if(ans == 1e9)
            return -1;
        return ans;
    }
};
