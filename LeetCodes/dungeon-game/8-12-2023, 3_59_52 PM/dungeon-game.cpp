// Link: https://leetcode.com/problems/dungeon-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: dungeon-game
 *  RUNTIME: 3 ms
 *  MEMORY: 9 MB
 *  DATE: 8-12-2023, 3:59:52 PM
 *
 */

// Solution:

class Solution {
public:
    int n, m;
    int find(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i == n || j == m) return 1e9; 
        if(i == n-1 && j == m-1) {
            if(grid[i][j] <= 0) return (1 - grid[i][j]);
            return 1;
        }
        if(dp[i][j] != 1e9) return dp[i][j];

        int down = find(i+1, j, grid, dp);
        int right= find(i, j+1, grid, dp);
        int ans = min(down, right) - grid[i][j];
        
        return dp[i][j] = (ans <= 0) ? 1 : ans;
    }

    int calculateMinimumHP(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 1e9));
        return find(0, 0, grid, dp);
    }
};
