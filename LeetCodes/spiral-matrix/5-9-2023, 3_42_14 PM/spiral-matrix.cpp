// Link: https://leetcode.com/problems/spiral-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: spiral-matrix
 *  RUNTIME: 4 ms
 *  MEMORY: 6.8 MB
 *  DATE: 5-9-2023, 3:42:14 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> seq;
        int row_start = 0, row_end = n-1;
        int col_start = 0, col_end = m-1;
        int size = 0;
        while(size < n*m) {
            // Phase:1 (Left to Right)
            for(int i = col_start; i <= col_end && size < n*m ;i++) {
                seq.push_back(mat[row_start][i]);
                size++;
            }
            row_start++;

            // Phase:2 (Top to Bottom)
            for(int i = row_start; i <= row_end && size < n*m ;i++) {
                seq.push_back(mat[i][col_end]);
                size++;
            }
            col_end--;

            // Phase:3 (Right to Left)
            for(int i = col_end; i >= col_start && size < n*m ;i--) {
                seq.push_back(mat[row_end][i]);
                size++;
            }
            row_end--;

            // Phase:3 (Bottom to Top)
            for(int i = row_end; i >= row_start && size < n*m ;i--) {
                seq.push_back(mat[i][col_start]);
                size++;
            }
            col_start++;
        }
        return seq;
    }
};
