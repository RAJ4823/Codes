// Link: https://leetcode.com/problems/minimum-path-cost-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-path-cost-in-a-grid
 *  RUNTIME: 252 ms
 *  MEMORY: 80.6 MB
 *  DATE: 8-12-2023, 10:42:35 AM
 *
 */

// Solution:

class Solution {
public:
    int n , m;
    int find(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& cost, vector<vector<int>>& dp) {
        if(i == n) return 0;
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int minCost = INT_MAX;
        for(int k=0; k<m; k++) {
            int moveCost = (i == n-1) ? 0 : cost[grid[i][j]][k];
            minCost = min(minCost, grid[i][j] + moveCost + find(i+1, k, grid, cost, dp));
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
