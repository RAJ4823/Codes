// Link: https://leetcode.com/problems/maximal-square

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximal-square
 *  RUNTIME: 7 ms
 *  MEMORY: 57.3 MB
 *  DATE: 5-9-2024, 6:02:04 PM
 *
 */

// Solution:

class Solution {
    public int maximalSquare(char[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int[][] dp = new int[n+1][m+1];
        int maxi = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') {
                    dp[i+1][j+1] = Math.min(dp[i][j], Math.min(dp[i+1][j], dp[i][j+1])) + 1;
                    maxi = Math.max(maxi, dp[i+1][j+1]);
                }
            }
        }

        return maxi * maxi;
       
    }
}
