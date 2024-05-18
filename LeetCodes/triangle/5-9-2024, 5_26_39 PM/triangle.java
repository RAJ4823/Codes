// Link: https://leetcode.com/problems/triangle

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: triangle
 *  RUNTIME: 3 ms
 *  MEMORY: 44.1 MB
 *  DATE: 5-9-2024, 5:26:39 PM
 *
 */

// Solution:

class Solution {
    int n, m;
    public int minimumTotal(List<List<Integer>> triangle) {
        n = triangle.size();
        m = triangle.get(n-1).size();
        int[][] dp = new int[n+1][m+1];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                dp[i][j] = (i < n && j < m) ? Integer.MIN_VALUE : 0;
            }
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                dp[i][j] = triangle.get(i).get(j) + Math.min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
}
