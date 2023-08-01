// Link: https://leetcode.com/problems/coin-change

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: coin-change
 *  RUNTIME: 136 ms
 *  MEMORY: 45.2 MB
 *  DATE: 12-21-2022, 9:56:56 AM
 *
 */

// Solution:

class Solution {
private:
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
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = find(n-1, amount, coins, dp);
        if(ans == 1e9)
            return -1;
        return ans;
    }
};
