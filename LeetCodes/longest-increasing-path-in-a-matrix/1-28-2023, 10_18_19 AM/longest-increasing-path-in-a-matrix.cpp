// Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-increasing-path-in-a-matrix
 *  RUNTIME: 53 ms
 *  MEMORY: 16.1 MB
 *  DATE: 1-28-2023, 10:18:19 AM
 *
 */

// Solution:

class Solution {
public:
    int n = 0, m = 0;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};

    int dfs(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& mat) {
        int maxlen = 1;
        if(dp[i][j] != -1) return dp[i][j];

        for(int k=0; k<4; k++) {
            int row = i + dx[k];
            int col = j + dy[k];
            if(row >= m || col >= n || row < 0 || col < 0)
                continue; 
            if(mat[row][col] > mat[i][j])
                maxlen = max(maxlen, 1 + dfs(row, col, dp, mat));
        }
        return dp[i][j] = maxlen;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0;j<n;j++) {
                if(dp[i][j] == -1) {
                    ans = max(ans, dfs(i, j, dp, mat));
                }
            }
        }
        // for(int i=0; i<m; i++) {
        //     for(int j=0;j<n;j++) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};
