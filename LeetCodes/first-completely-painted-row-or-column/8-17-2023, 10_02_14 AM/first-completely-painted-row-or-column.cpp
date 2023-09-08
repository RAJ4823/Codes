// Link: https://leetcode.com/problems/first-completely-painted-row-or-column

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: first-completely-painted-row-or-column
 *  RUNTIME: 277 ms
 *  MEMORY: 164.3 MB
 *  DATE: 8-17-2023, 10:02:14 AM
 *
 */

// Solution:

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, 0), col(m, 0);
        unordered_map<int,pair<int,int>> rc;

        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                rc[mat[i][j]] = {i, j};
    
        for(int i=0; i<n*m; i++) 
            if((row[rc[arr[i]].first]++) == (m-1) || (col[rc[arr[i]].second]++) == (n-1))
                return i;
        return 0;
    }   
};
