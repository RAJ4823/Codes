// Link: https://leetcode.com/problems/predict-the-winner

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: predict-the-winner
 *  RUNTIME: 11 ms
 *  MEMORY: 13.3 MB
 *  DATE: 7-28-2023, 11:10:50 AM
 *
 */

// Solution:

class Solution:
    def PredictTheWinner(self, nums):
        n = len(nums)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        return self.find(0, n - 1, nums, dp) >= 0

    def find(self, i, j, nums, dp):
        if i == j:           return nums[i]
        if dp[i][j] != 0:    return dp[i][j]
        dp[i][j] = max(nums[i] - self.find(i + 1, j, nums, dp), nums[j] - self.find(i, j - 1, nums, dp))
        return dp[i][j]

