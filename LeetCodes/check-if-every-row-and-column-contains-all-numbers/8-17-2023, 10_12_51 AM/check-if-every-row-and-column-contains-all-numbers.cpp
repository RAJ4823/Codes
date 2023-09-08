// Link: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-every-row-and-column-contains-all-numbers
 *  RUNTIME: 92 ms
 *  MEMORY: 37 MB
 *  DATE: 8-17-2023, 10:12:51 AM
 *
 */

// Solution:

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<bool>> row(n, vector<bool> (n+1, false)), col(n, vector<bool> (n+1, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(row[i][matrix[i][j]] || col[j][matrix[i][j]]) 
                    return false;
                row[i][matrix[i][j]] = true;
                col[j][matrix[i][j]] = true;
            }
        }
        return true;
    }
};
