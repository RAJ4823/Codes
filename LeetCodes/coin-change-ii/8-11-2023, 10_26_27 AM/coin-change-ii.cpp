// Link: https://leetcode.com/problems/coin-change-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: coin-change-ii
 *  RUNTIME: 11 ms
 *  MEMORY: 7.1 MB
 *  DATE: 8-11-2023, 10:26:27 AM
 *
 */

// Solution:

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);

        dp[0] = 1;
        for(int i=0; i<n; i++) {
            for(int sum = coins[i]; sum <= amount; sum++) {
                dp[sum] += dp[sum - coins[i]];
            }
        }
        return dp[amount];
    }
};
