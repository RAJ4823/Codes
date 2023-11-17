// Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-ways-to-stay-in-the-same-place-after-some-steps
 *  RUNTIME: 25 ms
 *  MEMORY: 6.5 MB
 *  DATE: 10-15-2023, 10:40:28 AM
 *
 */

// Solution:

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(steps / 2 + 1, arrLen);
        
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = 1;
        
        int mod = 1000000007; 
        for (int i = 1; i <= steps; i++) {
            int curr = i % 2;
            int prev = (i - 1) % 2;

            for (int j = 0; j < n; j++) {
                dp[curr][j] = dp[prev][j] % mod;
                if (j > 0) {
                    dp[curr][j] = (dp[curr][j] + dp[prev][j - 1]) % mod;
                }
                if (j < n - 1) {
                    dp[curr][j] = (dp[curr][j] + dp[prev][j + 1]) % mod;
                }
            }
        }
        
        return dp[steps % 2][0];
    }
};
