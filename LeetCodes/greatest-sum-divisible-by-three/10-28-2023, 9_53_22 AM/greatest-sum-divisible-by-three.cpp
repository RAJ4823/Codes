// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: greatest-sum-divisible-by-three
 *  RUNTIME: 71 ms
 *  MEMORY: 38.7 MB
 *  DATE: 10-28-2023, 9:53:22 AM
 *
 */

// Solution:

class Solution {
public:
    int n = 0;
    int find(int i, int rem, vector<int> &nums, vector<vector<int>> &dp) {
        if(i >= n) 
            return (rem) ? INT_MIN : 0;
        if(dp[i][rem] != -1)
            return dp[i][rem];
        
        int take = nums[i] + find(i + 1, (rem + nums[i]) % 3, nums, dp);
        int nottake = find(i + 1, rem, nums, dp);
        return dp[i][rem] = max(take, nottake);
    }

    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (3, -1));
        dp[n][0] = 0;
        dp[n][1] = dp[n][2] = INT_MIN;
        
        for(int i=n-1; i>=0; i--) {
            for(int rem=2; rem>=0; rem--) {
                dp[i][rem] = max(nums[i] + dp[i+1][(rem + nums[i]) % 3], dp[i+1][rem]);
            }
        } 
        return dp[0][0];
    }
};
