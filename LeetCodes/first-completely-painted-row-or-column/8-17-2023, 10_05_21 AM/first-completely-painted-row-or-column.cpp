// Link: https://leetcode.com/problems/first-completely-painted-row-or-column

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: first-completely-painted-row-or-column
 *  RUNTIME: 194 ms
 *  MEMORY: 127.7 MB
 *  DATE: 8-17-2023, 10:05:21 AM
 *
 */

// Solution:

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int o = n * m;
        vector<int> row(n, 0), col(m, 0), r(o + 1), c(o + 1);

        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                r[mat[i][j]] = i, c[mat[i][j]] = j;
    
        for(int i=0; i<o; i++) 
            if((row[r[arr[i]]]++) == (m-1) || (col[c[arr[i]]]++) == (n-1))
                return i;
        return 0;
    }   
};
