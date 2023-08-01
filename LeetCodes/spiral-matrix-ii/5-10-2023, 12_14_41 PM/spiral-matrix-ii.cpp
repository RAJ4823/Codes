// Link: https://leetcode.com/problems/spiral-matrix-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: spiral-matrix-ii
 *  RUNTIME: 0 ms
 *  MEMORY: 6.6 MB
 *  DATE: 5-10-2023, 12:14:41 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int> (n, 0));

        int row_start = 0, row_end = n-1;
        int col_start = 0, col_end = n-1;
        int val = 1;
        while(val <= n*n) {
            //Phase1
            for(int i = col_start; i <= col_end && val <= n*n; i++) {
                mat[row_start][i] = val++;
            }
            row_start++;
            //Phase2
            for(int i = row_start; i <= row_end && val <= n*n; i++) {
                mat[i][col_end] = val++;
            }
            col_end--;
            //Phase3
            for(int i = col_end; i >= col_start && val <= n*n; i--) {
                mat[row_end][i] = val++;
            }
            row_end--;
            //Phase4
            for(int i = row_end; i >= row_start && val <= n*n; i--) {
                mat[i][col_start] = val++;
            }
            col_start++;
        }
        return mat;
    }
};
