// Link: https://leetcode.com/problems/number-of-enclaves

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-enclaves
 *  RUNTIME: 80 ms
 *  MEMORY: 29.3 MB
 *  DATE: 4-7-2023, 9:26:02 AM
 *
 */

// Solution:

class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1}, n = 0, m = 0;

    void dfs(int row, int col, vector<vector<int>> &grid) {
        grid[row][col] = 2;
        for(int k=0; k<4; k++) {
            int x = row + dir[k];
            int y = col + dir[k+1];

            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1) {
                dfs(x, y, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1) {
                    dfs(i, j, grid);   
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};
