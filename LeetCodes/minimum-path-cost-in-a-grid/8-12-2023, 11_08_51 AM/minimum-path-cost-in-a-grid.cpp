// Link: https://leetcode.com/problems/minimum-path-cost-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-path-cost-in-a-grid
 *  RUNTIME: 259 ms
 *  MEMORY: 80.1 MB
 *  DATE: 8-12-2023, 11:08:51 AM
 *
 */

// Solution:

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m, INT_MAX), prev(m);
        
        prev = grid[0];
        for(int i=1; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                for(int k=0; k<m; ++k) {
                    int prevCost = (j == 0) ? INT_MAX : dp[k];
                    int newCost = grid[i][k] + cost[grid[i-1][j]][k] + prev[j];
                    dp[k] = min(prevCost, newCost);
                }
            }
            prev = dp;
        }
        int minCost = *min_element(dp.begin(), dp.end());
        return minCost;
    }
};
