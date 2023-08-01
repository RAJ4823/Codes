// Link: https://leetcode.com/problems/unique-paths-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: unique-paths-ii
 *  RUNTIME: 3 ms
 *  MEMORY: 7.5 MB
 *  DATE: 12-31-2022, 10:02:24 AM
 *
 */

// Solution:

class Solution {
    int paths = 0, n, m;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if(grid[0][0] == 1) return 0;

        grid[0][0] = 1;
        for(int i=1; i<m; i++) {
            grid[i][0] = (grid[i][0] == 0 && grid[i-1][0] == 1);
        }
        for(int j=1; j<n; j++) {
            grid[0][j] = (grid[0][j] == 0 && grid[0][j-1] == 1);
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(grid[i][j] == 0)
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                else
                    grid[i][j] = 0;
            }
        }
        return grid[m-1][n-1];
    }
};
