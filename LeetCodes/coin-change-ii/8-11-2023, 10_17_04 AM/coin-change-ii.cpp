// Link: https://leetcode.com/problems/coin-change-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: coin-change-ii
 *  RUNTIME: 8 ms
 *  MEMORY: 18.8 MB
 *  DATE: 8-11-2023, 10:17:04 AM
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
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return find(n-1, amount, coins, dp);;
    }
};
