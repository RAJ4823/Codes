// Link: https://leetcode.com/problems/house-robber

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: house-robber
 *  RUNTIME: 5 ms
 *  MEMORY: 7.8 MB
 *  DATE: 12-14-2022, 10:03:22 AM
 *
 */

// Solution:

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for(int i=2; i<=n; i++)
        {
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
        }
        return dp[n];
    }
};
