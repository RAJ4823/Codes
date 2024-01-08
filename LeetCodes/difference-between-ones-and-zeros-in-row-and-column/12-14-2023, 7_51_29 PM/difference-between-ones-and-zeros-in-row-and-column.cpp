// Link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: difference-between-ones-and-zeros-in-row-and-column
 *  RUNTIME: 189 ms
 *  MEMORY: 116.5 MB
 *  DATE: 12-14-2023, 7:51:29 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n, 0), col(m, 0);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            } 
        } 
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                grid[i][j] = 2*(row[i] + col[j]) - (n + m); 
            }
        }
        
        return grid;
    }
};
