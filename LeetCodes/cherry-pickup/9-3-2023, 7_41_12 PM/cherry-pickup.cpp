// Link: https://leetcode.com/problems/cherry-pickup

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: cherry-pickup
 *  RUNTIME: 91 ms
 *  MEMORY: 398.2 MB
 *  DATE: 9-3-2023, 7:41:12 PM
 *
 */

// Solution:

class Solution {
public:
    int n;
    int find(int i, int j, int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i >= n || j >= n || x >= n || y >= n || grid[i][j] == -1 || grid[x][y] == -1) return -1e9;

        int c1 = (i*n + j), c2 = (x*n + y);
        if(dp[c1][c2] != -1) return dp[c1][c2];
        if(i == n-1 && j == n-1) return grid[i][j];
        if(x == n-1 && y == n-1) return grid[x][y];


        int cherries = (i == x && j == y) ? grid[i][j] : grid[i][j] + grid[x][y];
        int case1 = find(i+1, j, x+1, y, grid, dp);
        int case2 = find(i+1, j, x, y+1, grid, dp);
        int case3 = find(i, j+1, x, y+1, grid, dp);
        int case4 = find(i, j+1, x+1, y, grid, dp);
        cherries += max({case1, case2, case3, case4});

        return dp[c1][c2] = cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dp(n*n, vector<int> (n*n, -1));
        int ans = max(0, find(0, 0, 0, 0, grid, dp));
        return ans;
    }
}; 
