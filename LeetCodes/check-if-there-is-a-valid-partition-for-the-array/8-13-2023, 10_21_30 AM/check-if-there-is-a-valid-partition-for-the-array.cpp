// Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-there-is-a-valid-partition-for-the-array
 *  RUNTIME: 165 ms
 *  MEMORY: 87.5 MB
 *  DATE: 8-13-2023, 10:21:30 AM
 *
 */

// Solution:

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, -1); 
        nums.push_back(0);
        nums.push_back(0);
        dp[n] = dp[n+1] = true;

        for(int i=n-1; i>=0; --i) {
            bool case1 = (nums[i] == nums[i+1]);
            bool case2 = (nums[i] == nums[i+1] && nums[i+1] == nums[i+2]);
            bool case3 = (nums[i] + 1 == nums[i+1] && nums[i+1] + 1 == nums[i+2]);
            dp[i] = (case1 & dp[i+2]) || (case2 && dp[i+3]) || (case3 && dp[i+3]);
        }
        return dp[0];
    }
};
