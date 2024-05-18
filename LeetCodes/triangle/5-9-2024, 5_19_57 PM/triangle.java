// Link: https://leetcode.com/problems/triangle

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: triangle
 *  RUNTIME: 1 ms
 *  MEMORY: 43.8 MB
 *  DATE: 5-9-2024, 5:19:57 PM
 *
 */

// Solution:

class Solution {
    int n, m;
    public int findMin(int i, int j, List<List<Integer>> arr, int[][] dp) {
        if(i >= n || j >= m) 
            return 0;
        if(dp[i][j] != Integer.MIN_VALUE)     
            return dp[i][j];

        return dp[i][j] = arr.get(i).get(j) + Math.min(findMin(i+1, j, arr, dp), findMin(i+1, j+1, arr, dp));
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        n = triangle.size();
        m = triangle.get(n-1).size();
        int[][] dp = new int[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dp[i][j] = Integer.MIN_VALUE;
            }
        }

        return findMin(0, 0, triangle, dp);
    }
}
