// Link: https://leetcode.com/problems/count-sub-islands

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-sub-islands
 *  RUNTIME: 225 ms
 *  MEMORY: 90.6 MB
 *  DATE: 9-15-2023, 10:55:48 AM
 *
 */

// Solution:

class Solution {
public:
    int dirs[5] = {-1, 0, 1, 0, -1}, n, m;
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool &ans) {
        grid2[i][j] = -1;

        if(grid1[i][j] == 0) {
            ans = false;
        }

        for(int k=0; k<4; k++) {
            int row = i + dirs[k];
            int col = j + dirs[k + 1];

            if(row >= 0 && row < n && col >= 0 && col < m && grid2[row][col] == 1) {
                dfs(row, col, grid1, grid2, ans);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        n = grid1.size();
        m = grid1[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid1[i][j] == 1 && grid2[i][j] == 1) {
                    bool check = true;
                    dfs(i, j, grid1, grid2, check);
                    ans += check;
                }
            }
        }
        return ans;
    }
};
