// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: greatest-sum-divisible-by-three
 *  RUNTIME: 75 ms
 *  MEMORY: 38.7 MB
 *  DATE: 10-28-2023, 9:53:51 AM
 *
 */

// Solution:

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
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
