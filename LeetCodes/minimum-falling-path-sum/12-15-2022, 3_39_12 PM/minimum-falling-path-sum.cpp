// Link: https://leetcode.com/problems/minimum-falling-path-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-falling-path-sum
 *  RUNTIME: 16 ms
 *  MEMORY: 10.2 MB
 *  DATE: 12-15-2022, 3:39:12 PM
 *
 */

// Solution:

class Solution {
private:
    int find(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if(j < 0 || j >= matrix[0].size()) return 1e9;
        if(i == 0) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int l = find(i-1,j-1,matrix,dp);
        int u = find(i-1,j, matrix,dp);
        int r = find(i-1,j+1,matrix,dp);

        return dp[i][j] = (matrix[i][j] + min(u, min(l,r)));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m));

        for(int i=0 ;i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i == 0) {
                    dp[i][j] = matrix[i][j];
                }
                else {
                    int l = 1e9, r = 1e9;
                    if(j-1 >= 0) l = dp[i-1][j-1];
                    if(j+1 < m ) r = dp[i-1][j+1];
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], min(l, r));
                }
            }
        }
        
        int ans = INT_MAX;
        for(int j=0; j<m; j++)
        {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};
