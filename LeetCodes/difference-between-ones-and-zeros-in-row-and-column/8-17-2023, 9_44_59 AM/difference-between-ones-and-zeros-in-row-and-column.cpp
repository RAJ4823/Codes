// Link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: difference-between-ones-and-zeros-in-row-and-column
 *  RUNTIME: 203 ms
 *  MEMORY: 116.2 MB
 *  DATE: 8-17-2023, 9:44:59 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n, 0), col(m, 0);

        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                row[i] += grid[i][j], col[j] += grid[i][j];
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++)
                grid[i][j] = 2*(row[i] + col[j]) - (n + m); 
        return grid;
    }
};
