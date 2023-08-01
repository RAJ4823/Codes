// Link: https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-jumps-to-reach-the-last-index
 *  RUNTIME: 114 ms
 *  MEMORY: 62.1 MB
 *  DATE: 7-10-2023, 4:51:34 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> dp;
    int find(int i, int tar, vector<int> &nums) {
        if(i == nums.size() - 1) return 0; 
        if(dp[i] != -1) return dp[i];
        
        int curr = INT_MIN;
        for(int j=i+1; j<nums.size(); j++) {
           if(abs(nums[i] - nums[j]) <= tar) {
               curr = max(curr, 1 + find(j, tar, nums));
           }
        }
        return dp[i] = curr;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n, -1);
        int ans = find(0, target, nums);
        if(ans > 0) return ans;
        return -1;
    }
};
