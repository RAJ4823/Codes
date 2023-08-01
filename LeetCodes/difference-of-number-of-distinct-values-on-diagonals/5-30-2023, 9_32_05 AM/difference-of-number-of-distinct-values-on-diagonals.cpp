// Link: https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: difference-of-number-of-distinct-values-on-diagonals
 *  RUNTIME: 265 ms
 *  MEMORY: 78.7 MB
 *  DATE: 5-30-2023, 9:32:05 AM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, int j, vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_set<int> TL, BR;
        int row = i-1, col = j-1;
        while(row >= 0 && col >= 0) {
            TL.insert(grid[row--][col--]);
        }
        row = i+1;
        col = j+1;
        while(row < n && col < m) {
            BR.insert(grid[row++][col++]);
        }
        int a  = TL.size();
        int b = BR.size();
        return abs(a- b);
    }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n, vector<int> (m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = find(i, j, grid);
            }
        }
        return ans;
    }
};
