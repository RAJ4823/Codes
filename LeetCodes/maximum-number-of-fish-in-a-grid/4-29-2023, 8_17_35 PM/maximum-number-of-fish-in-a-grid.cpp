// Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-fish-in-a-grid
 *  RUNTIME: 87 ms
 *  MEMORY: 90.9 MB
 *  DATE: 4-29-2023, 8:17:35 PM
 *
 */

// Solution:

class Solution {
public:
    int dist[5] = {-1,0,1,0,-1};
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[row][col] = true;
        int sum = grid[row][col];
        
        for(int k =0; k< 4; k++) {
            int i = row + dist[k];;
            int j = col + dist[k+1];
            
            if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
                continue;
            if(!vis[i][j] && grid[i][j] > 0) {
                sum += dfs(i, j, grid, vis);
            }
        }
        return sum;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] > 0) {
                    ans = max(ans, dfs(i, j, grid, vis));
                }
            }
        }
        return ans;
    }
};
