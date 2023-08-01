// Link: https://leetcode.com/problems/house-robber

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: house-robber
 *  RUNTIME: 6 ms
 *  MEMORY: 7.8 MB
 *  DATE: 12-14-2022, 10:00:57 AM
 *
 */

// Solution:

class Solution {
private:
    int find(int i, vector<int> &nums, vector<int> &dp) {
        if(i == 0)
            return nums[0];
        if(i == 1)
            return max(nums[0], nums[1]);
        if(dp[i] != -1)
            return dp[i];
        int nottake = -1e9, take = -1e9;
            nottake = find(i-1, nums, dp); 
            take = nums[i] + find(i-2, nums, dp);
        return dp[i] = max(take, nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return find(n-1, nums, dp);
    }
};
