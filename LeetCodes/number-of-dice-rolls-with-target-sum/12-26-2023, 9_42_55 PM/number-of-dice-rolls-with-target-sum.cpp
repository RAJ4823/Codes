// Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-dice-rolls-with-target-sum
 *  RUNTIME: 11 ms
 *  MEMORY: 7.4 MB
 *  DATE: 12-26-2023, 9:42:55 PM
 *
 */

// Solution:

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;
        if (n * k < target)    return 0;
        
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= min(i * k, target); j++) {
                for (int temp = 1; temp <= min(k, j); temp++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - temp]) % MOD;
                }
            }
        }
        return dp[n][target];
    }
};
