// Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-ways-to-stay-in-the-same-place-after-some-steps
 *  RUNTIME: 19 ms
 *  MEMORY: 10.3 MB
 *  DATE: 10-15-2023, 10:32:34 AM
 *
 */

// Solution:

class Solution {
public:
    int MOD = 1e9 + 7, N;
    int find(int i, int steps, vector<vector<int>> &dp) {
        if(steps < i)
            return 0;
        if(steps == 0)
            return 1;
        if(dp[i][steps] != -1)
            return dp[i][steps];
        
        int ways1 = find(i, steps - 1, dp) % MOD;
        int ways2 = (i > 0) ? find(i-1, steps-1, dp) % MOD : 0;
        int ways3 = (i < N - 1) ? find(i+1, steps-1, dp) % MOD : 0;
        return dp[i][steps] = (((ways1 + ways2) % MOD) + ways3) % MOD;
    }
    int numWays(int steps, int arrLen) {
        N = min(arrLen , steps / 2 + 1);
        vector<vector<int>> dp(N, vector<int> (steps + 1, -1));
        return find(0, steps, dp);
    }
};
