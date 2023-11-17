// Link: https://leetcode.com/problems/find-a-peak-element-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-a-peak-element-ii
 *  RUNTIME: 147 ms
 *  MEMORY: 46.9 MB
 *  DATE: 10-14-2023, 10:18:45 AM
 *
 */

// Solution:

class Solution {
public:
    bool isPeak(int i, int j, vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        for(int k=0; k<4; k++) {
            int x = i + dirs[k];
            int y = j + dirs[k+1];
            if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] > mat[i][j]) {
                return false;
            }
        }
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(isPeak(i, j, mat)) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};
