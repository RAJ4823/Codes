// Link: https://leetcode.com/problems/unique-paths-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: unique-paths-ii
 *  RUNTIME: 0 ms
 *  MEMORY: 7.8 MB
 *  DATE: 8-12-2023, 9:07:32 AM
 *
 */

// Solution:

class Solution {
public:
    int n, m;
    int find(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i == n || j == m) return 0;
        if(grid[i][j] == 1) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = find(i+1, j, grid, dp) + find(i, j+1, grid, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return find(0, 0, grid, dp);
    }
};
