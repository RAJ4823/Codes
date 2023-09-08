// Link: https://leetcode.com/problems/minimum-path-cost-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-path-cost-in-a-grid
 *  RUNTIME: 263 ms
 *  MEMORY: 80.4 MB
 *  DATE: 8-12-2023, 10:43:26 AM
 *
 */

// Solution:

class Solution {
public:
    int n , m;
    int find(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& cost, vector<vector<int>>& dp) {
        if(i == n-1) return grid[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int minCost = INT_MAX;
        for(int k=0; k<m; k++) {
            minCost = min(minCost, grid[i][j] + cost[grid[i][j]][k] + find(i+1, k, grid, cost, dp));
        }
        return dp[i][j] = minCost;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, INT_MAX));
        
        int minCost = INT_MAX;
        for(int j=0; j<m; j++) {
            minCost = min(minCost, find(0, j, grid, moveCost, dp));
        }
        return minCost;
    }
};
