// Link: https://leetcode.com/problems/minimum-path-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-path-sum
 *  RUNTIME: 1070 ms
 *  MEMORY: 10 MB
 *  DATE: 3-27-2023, 10:16:13 AM
 *
 */

// Solution:

class Solution {
public:
    int dir[3] = {0, 1, 0};

    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& minDist) {
        for(int k=0; k<2; k++) {
            int nx = x + dir[k];
            int ny = y + dir[k+1];
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size())
                continue;
            int newDist = minDist[x][y] + grid[nx][ny];
            if(newDist < minDist[nx][ny]) {
                minDist[nx][ny] = newDist;
                dfs(nx, ny, grid, minDist);
            }
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> minDist(m, vector<int> (n, 1e9));
        minDist[0][0] = grid[0][0];
        dfs(0, 0, grid, minDist);
        return minDist[m-1][n-1];
    }
};
