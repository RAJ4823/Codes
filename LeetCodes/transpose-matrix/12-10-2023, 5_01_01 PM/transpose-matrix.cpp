// Link: https://leetcode.com/problems/transpose-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: transpose-matrix
 *  RUNTIME: 7 ms
 *  MEMORY: 10.9 MB
 *  DATE: 12-10-2023, 5:01:01 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans(m, vector<int> (n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};
