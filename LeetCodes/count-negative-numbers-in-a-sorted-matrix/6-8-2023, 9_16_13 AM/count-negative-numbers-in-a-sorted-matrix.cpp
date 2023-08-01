// Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-negative-numbers-in-a-sorted-matrix
 *  RUNTIME: 18 ms
 *  MEMORY: 10.3 MB
 *  DATE: 6-8-2023, 9:16:13 AM
 *
 */

// Solution:

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();

        for(int i=n-1; i>=0; i--) {
            int negIndex = m;
            for(int j=0; j<m; j++) {
                if(grid[i][j] < 0) {
                    negIndex = j;
                    break;
                }
            }
            if(negIndex == m) 
                break;
            cnt += (m - negIndex);
        }
        return cnt;
    }
};
