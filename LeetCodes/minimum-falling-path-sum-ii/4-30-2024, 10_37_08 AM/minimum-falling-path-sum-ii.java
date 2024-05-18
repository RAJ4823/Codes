// Link: https://leetcode.com/problems/minimum-falling-path-sum-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-falling-path-sum-ii
 *  RUNTIME: 187 ms
 *  MEMORY: 51.4 MB
 *  DATE: 4-30-2024, 10:37:08 AM
 *
 */

// Solution:

class Solution {
    int n,m;
    public int minFallingPathSum(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        int[][] dp = new int[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        int ans = Integer.MAX_VALUE;

        for(int k=0; k<m; k++) {
            if(n > 1) {
                ans = Math.min(ans, grid[0][k] + find(1, k, grid, dp));
            } else {
                ans = Math.min(ans, grid[0][k]);
            }
        }
        return ans;
    }

    public int find(int i, int j, int[][] grid, int[][] dp) {
        if(dp[i][j] != Integer.MAX_VALUE) {
            return dp[i][j];
        }

        int ans = Integer.MAX_VALUE;
        for(int k=0; k<m; k++) {
            if(k == j) continue;
            if(i < n-1) {
                ans = Math.min(ans, grid[i][k] + find(i+1, k, grid, dp));
            } else {
                ans = Math.min(ans, grid[i][k]);
            }
        }

        return dp[i][j] = ans;
    }
}
