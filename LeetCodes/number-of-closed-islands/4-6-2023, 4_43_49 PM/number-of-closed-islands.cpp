// Link: https://leetcode.com/problems/number-of-closed-islands

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-closed-islands
 *  RUNTIME: 13 ms
 *  MEMORY: 9.5 MB
 *  DATE: 4-6-2023, 4:43:49 PM
 *
 */

// Solution:

class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1};
    int n = 0, m = 0;

    void visit(int row, int col, vector<vector<int>> &grid) {
        grid[row][col] = 2;
        for(int k=0; k<4; k++) {
            int x = row + dirs[k];
            int y = col + dirs[k+1];
            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0)
                visit(x, y, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
    
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == 0) {
                    visit(i, j, grid);
                }
            } 
        }

        for(int i = 0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    visit(i, j, grid); 
                    count++;
                }
            }
        }
        return count;
    }
};
