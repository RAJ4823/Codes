// Link: https://leetcode.com/problems/shortest-bridge

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-bridge
 *  RUNTIME: 52 ms
 *  MEMORY: 19.6 MB
 *  DATE: 5-21-2023, 6:15:02 PM
 *
 */

// Solution:

class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1}, n = 0; 
    queue<pair<pair<int,int>, int>> q;
    vector<vector<bool>> vis;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        vis[i][j] = true;
        q.push({{i,j}, 0});
        for(int k=0; k<4; k++) {
            int row = i + dirs[k];
            int col = j + dirs[k+1];
            if(row < 0 || col < 0 || row >= n || col >= n)
                continue;
            if(!vis[row][col] && grid[row][col] == 1) {
                dfs(row, col, grid);
            }
        }
    }

    void fill(vector<vector<int>>& grid) {
        n = grid.size();
        vis.resize(n, vector<bool> (n, false));
        for(int i=0; i<n; i++) {
            for(int j=0;j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid);
                    return;
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        fill(grid);
  
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for(int k=0; k<4; k++) {
                int row = i + dirs[k];
                int col = j + dirs[k+1];
                if(row < 0 || col < 0 || row >= n || col >= n)
                    continue;
                if(!vis[row][col]) {
                    vis[row][col] = true;
                    if(grid[row][col] == 0)
                        q.push({{row, col}, steps + 1});
                    else
                        return steps;
                }
            }
        }
        return n*n;
    }
};
