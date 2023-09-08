// Link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: paths-in-matrix-whose-sum-is-divisible-by-k
 *  RUNTIME: 405 ms
 *  MEMORY: 134.9 MB
 *  DATE: 9-3-2023, 10:32:01 AM
 *
 */

// Solution:

class Solution {
public:
    int MOD = 1000000007, K;
    int find(int i, int j, int sum, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        if (i == 0 && j == 0) return (sum % K == 0);
        if (dp[i][j][sum] != -1) return dp[i][j][sum];

        int val1 = 0, val2 = 0;
        if(i > 0 && j >= 0) val1 = find(i-1, j, (sum + grid[i-1][j]) % K, grid, dp);
        if(i >= 0 && j > 0) val2 = find(i, j-1, (sum + grid[i][j-1]) % K, grid, dp);
        return dp[i][j][sum] = (val1 + val2) % MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {\
        K = k;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (k+1, -1)));

        return find(m-1, n-1, (grid[m-1][n-1] % K), grid, dp);
    }
};
