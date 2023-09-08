// Link: https://leetcode.com/problems/longest-increasing-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-increasing-subsequence
 *  RUNTIME: 944 ms
 *  MEMORY: 292.3 MB
 *  DATE: 8-13-2023, 2:30:49 PM
 *
 */

// Solution:

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(INT_MAX);
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        for(int i=0; i<n; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0) {
                    dp[i][j] = (nums[0] < nums[j]);
                }
                else if(nums[i] < nums[j]) {
                    dp[i][j] = max(1 + dp[i-1][i], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][n];
    }
};
