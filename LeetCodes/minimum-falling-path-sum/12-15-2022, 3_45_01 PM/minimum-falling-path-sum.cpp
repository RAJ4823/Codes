// Link: https://leetcode.com/problems/minimum-falling-path-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-falling-path-sum
 *  RUNTIME: 15 ms
 *  MEMORY: 9.8 MB
 *  DATE: 12-15-2022, 3:45:01 PM
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
        int ans = INT_MAX;
        vector<int> dp(m), temp(m);

        for(int j=0; j<m; j++)
            
        temp = dp;

        for(int i=0 ;i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i == 0)
                    dp[j] = matrix[0][j];
                else {
                    int l = 1e9, r = 1e9;
                    if(j-1 >= 0)    l = temp[j-1];
                    if(j+1 < m )    r = temp[j+1];
                    dp[j] = matrix[i][j] + min(temp[j], min(l, r));
                }
            }
            temp = dp;
        }

        for(int j=0; j<m; j++)
            ans = min(ans, dp[j]);
        return ans;
    }
};
