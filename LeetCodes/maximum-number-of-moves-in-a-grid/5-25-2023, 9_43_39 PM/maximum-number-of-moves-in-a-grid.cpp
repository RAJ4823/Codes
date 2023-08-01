// Link: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-moves-in-a-grid
 *  RUNTIME: 2527 ms
 *  MEMORY: 384.4 MB
 *  DATE: 5-25-2023, 9:43:39 PM
 *
 */

// Solution:

class Solution {
public:
    int dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid, vector<vector<int>> &dist) {
        vis[i][j] = true;
        if(dist[i][j] != -1) return dist[i][j];
        
        int steps = 0;
        for(int x=-1; x<=1; x++) {
            int row = i + x;
            int col = j + 1;
            
            if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) 
                continue;
            if(grid[row][col] > grid[i][j] && !vis[row][col]) {
                steps = max(steps, 1 + dfs(row, col, vis, grid, dist));
            }
        }
        return dist[i][j] = steps;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        vector<vector<int>> dist(n, vector<int> (m, -1));
        for(int i=0; i<n; i++) {
            vector<vector<bool>> vis(n, vector<bool> (m, false));
            ans = max(ans, dfs(i, 0, vis, grid, dist));
        }
        return ans;
    }
};
