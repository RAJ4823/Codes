// Link: https://leetcode.com/problems/find-a-peak-element-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-a-peak-element-ii
 *  RUNTIME: 121 ms
 *  MEMORY: 46.7 MB
 *  DATE: 10-14-2023, 10:24:01 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1;

        while(low <= high) {
            int maxRow = 0, col = (low + high) / 2;

            for(int row=0; row<n; row++) {
                if(mat[row][col] > mat[maxRow][col]) 
                    maxRow = row;
            }

            int curr = mat[maxRow][col];
            int left = (col == 0) ? -1 : mat[maxRow][col-1];
            int right = (col == m-1) ? -1 : mat[maxRow][col+1];

            if(curr > left && curr > right) 
                return {maxRow, col};
            else if(curr < left) 
                high = col - 1;
            else
                low = col + 1;
        }
        return {-1, -1};
    }
};
