// Link: https://leetcode.com/problems/number-of-islands

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-islands
 *  RUNTIME: 42 ms
 *  MEMORY: 12.5 MB
 *  DATE: 5-30-2022, 12:25:44 PM
 *
 */

// Solution:

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m)
            return;
        if(!vis[i][j])
            return;
        vis[i][j] = false;
        
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis;
        for(int i=0; i<n; i++)
        {
            vector<bool> temp(m,false);
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                    temp[j] = true;
            }
            vis.push_back(temp);
        }
        for(int i=0; i<n; i++)
        {
            
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j])
                    continue;
                count++;
                dfs(i,j,grid,vis);
            }
        }
        return count;
        
    }
};
