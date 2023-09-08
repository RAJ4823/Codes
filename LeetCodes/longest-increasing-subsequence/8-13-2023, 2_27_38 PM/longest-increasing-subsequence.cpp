// Link: https://leetcode.com/problems/longest-increasing-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-increasing-subsequence
 *  RUNTIME: 835 ms
 *  MEMORY: 292.3 MB
 *  DATE: 8-13-2023, 2:27:38 PM
 *
 */

// Solution:

class Solution {
public:
    int find(int curr, int prev, vector<int> &nums, vector<vector<int>> &dp) {
        if(curr == 0) return nums[0] < nums[prev];
        if(dp[curr][prev] != -1) return dp[curr][prev];

        int take = 0, nottake = 0;
        if(nums[curr] < nums[prev]) {
            take = 1 + find(curr - 1, curr, nums, dp);
        }
        nottake = find(curr - 1, prev, nums, dp);
        return dp[curr][prev] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(INT_MAX);
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return find(n-1, n, nums, dp);
    }
};
