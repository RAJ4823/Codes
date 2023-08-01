// Link: https://leetcode.com/problems/number-of-ways-to-earn-points

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-ways-to-earn-points
 *  RUNTIME: 306 ms
 *  MEMORY: 8.2 MB
 *  DATE: 3-5-2023, 9:00:02 AM
 *
 */

// Solution:

class Solution {
public:
    
    int MOD = 1e9 + 7;
    void iterate_j(vector<int> &cm, vector<int> &dp, int i)
    {
        for (int j = 1; (i - j * cm[1] >= 0) && (j <= cm[0]); j++) {
            int new_val = dp[i - j * cm[1]];
            dp[i] = ((dp[i] + new_val) % MOD);
        }
    }
    void iterate_i(vector<int> &cm, vector<int> &dp, int tar)
    {
        for (int i = tar; i >= 0; i--)  iterate_j(cm, dp, i);
    }
    int solve(int tar, int n, vector<vector<int>> &types)
    {
        vector<int> DP(tar + 1);
        DP[0] = 1;
        for (int i=0; i<types.size(); i++)  iterate_i(types[i], DP, tar);
        return DP[tar];
    }
    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        int n = types.size(), t = target;
        return solve(t, n, types);
    }
};
