// Link: https://leetcode.com/problems/predict-the-winner

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: predict-the-winner
 *  RUNTIME: 0 ms
 *  MEMORY: 39.9 MB
 *  DATE: 7-28-2023, 11:11:46 AM
 *
 */

// Solution:

public class Solution {
    private int[][] dp;
    
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        dp = new int[n][n];
        return find(0, n - 1, nums) >= 0;
    }
    
    private int find(int i, int j, int[] nums) {
        if (i == j) return nums[i];
        if (dp[i][j] != 0) return dp[i][j];
        return dp[i][j] = Math.max(nums[i] - find(i + 1, j, nums), nums[j] - find(i, j - 1, nums));
    }
}

