// Link: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-increasing-paths-in-a-grid
 *  RUNTIME: 305 ms
 *  MEMORY: 43.5 MB
 *  DATE: 6-18-2023, 12:09:33 PM
 *
 */

// Solution:

class Solution {
private:
    int dirs[5] = {-1, 0, 1, 0, -1};
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>> &grid, int &mod) {
        if(dp[i][j] != -1) return dp[i][j];
        int count = 1;

        for(int k=0; k<4; k++) {
            int x = i + dirs[k];
            int y = j + dirs[k+1];

            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
                continue;
            if(grid[x][y] > grid[i][j])
                count = (count + dfs(x, y, grid, mod)) % mod;
        }    
        return dp[i][j] = count;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 1e9 + 7;

        dp.resize(n, vector<int> (m, -1));
        int totalPaths = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                totalPaths = (totalPaths + dfs(i, j, grid, mod)) % mod;
                // cout << dp[i][j] << ' ';
            }
            // cout << endl;
        }
        return totalPaths;
    }
};
