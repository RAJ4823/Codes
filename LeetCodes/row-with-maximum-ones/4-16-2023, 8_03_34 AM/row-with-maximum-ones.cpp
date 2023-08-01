// Link: https://leetcode.com/problems/row-with-maximum-ones

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: row-with-maximum-ones
 *  RUNTIME: 143 ms
 *  MEMORY: 60.8 MB
 *  DATE: 4-16-2023, 8:03:34 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n, 0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                row[i] += mat[i][j];
            }
        }
        
        int maxi = 0, index = 0;
        for(int i=0; i<n; i++) {
            if(row[i] > maxi) {
                maxi = row[i];
                index = i;
            }
        }
        return {index, maxi};
    }
};
