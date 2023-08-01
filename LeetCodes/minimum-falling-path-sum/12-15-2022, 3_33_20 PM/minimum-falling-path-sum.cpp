// Link: https://leetcode.com/problems/minimum-falling-path-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-falling-path-sum
 *  RUNTIME: 11 ms
 *  MEMORY: 10.4 MB
 *  DATE: 12-15-2022, 3:33:20 PM
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
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        int ans = INT_MAX;
        for(int j=0; j<m; j++)
        {
            ans = min(ans, find(n-1,j,matrix,dp));
        }
        return ans;
    }
};
