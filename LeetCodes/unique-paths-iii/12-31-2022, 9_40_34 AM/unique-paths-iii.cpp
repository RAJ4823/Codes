// Link: https://leetcode.com/problems/unique-paths-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: unique-paths-iii
 *  RUNTIME: 0 ms
 *  MEMORY: 7 MB
 *  DATE: 12-31-2022, 9:40:34 AM
 *
 */

// Solution:

class Solution {
    int walks = 0, emptyCells = 1, n, m;
    int di[4] = {-1,0,1,0};
    int dj[4] = {0,-1,0,1};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int si, sj;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
                if(grid[i][j] == 0) {
                    emptyCells++;
                }
            }
        }

        
        dfs(si, sj, grid, 0);
        return walks;
    }

    void dfs(int i, int j, vector<vector<int>> &grid, int visitedCells) {
        if(grid[i][j] == 2){
            if (emptyCells == visitedCells) 
                walks++;
            return;
        }
        grid[i][j] = -1;
        visitedCells++;
        for(int k=0; k<4;k++) {
            int ni = i+di[k];
            int nj = j+dj[k];
            if (ni < 0 || ni >= m ||  nj < 0 || nj >= n)    continue;
            if (grid[ni][nj] == -1)                         continue;

            dfs(ni, nj, grid, visitedCells);
        }
        grid[i][j] = 0;
    }
};
