// Link: https://leetcode.com/problems/dungeon-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: dungeon-game
 *  RUNTIME: 3 ms
 *  MEMORY: 8.7 MB
 *  DATE: 8-12-2023, 4:01:09 PM
 *
 */

// Solution:

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {

        int N = grid.size(), M = grid[0].size();
        vector<int> dp(M);
        
        dp[M - 1] = max(1, 1 - grid[N - 1][M - 1]);
        
        for (int i = M - 2; i > -1; --i)
            dp[i] = max(1, dp[i + 1] - grid[N - 1][i]);

        for (int i = N - 2; i > -1; --i)
        {
            dp[M - 1] = max(1, dp[M - 1] - grid[i][M - 1]);
            for (int j = M - 2; j > -1; --j)
                dp[j] = max(1, min(dp[j], dp[j + 1]) - grid[i][j]);
        }

        return dp[0];
    }
};
