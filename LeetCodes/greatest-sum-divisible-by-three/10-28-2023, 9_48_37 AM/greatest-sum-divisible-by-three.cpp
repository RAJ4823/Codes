// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: greatest-sum-divisible-by-three
 *  RUNTIME: 71 ms
 *  MEMORY: 42.5 MB
 *  DATE: 10-28-2023, 9:48:37 AM
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
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return find(0, 0, nums, dp);
    }
};
