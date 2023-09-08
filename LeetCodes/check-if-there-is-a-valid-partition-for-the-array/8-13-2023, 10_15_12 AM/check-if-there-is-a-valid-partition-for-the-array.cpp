// Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-there-is-a-valid-partition-for-the-array
 *  RUNTIME: 126 ms
 *  MEMORY: 92.3 MB
 *  DATE: 8-13-2023, 10:15:12 AM
 *
 */

// Solution:

class Solution {
public:
    int n;
    bool find(int i, vector<int> &nums, vector<int> &dp) {
        if(i >= n) return true;
        if(dp[i] != -1) return dp[i];

        bool case1 = false, case2 = false, case3 = false;
        if(i < n - 1) {
            case1 = (nums[i] == nums[i+1]) && find(i+2, nums, dp);
        }
        if(i < n - 2) {
            case2 = (nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) && find(i+3, nums, dp);
            case3 = (nums[i] + 1 == nums[i+1] && nums[i+1] + 1 == nums[i+2]) && find(i+3, nums, dp);
        }
        return dp[i] = (case1 || case2 || case3);
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);  
        return find(0, nums, dp);

    }
};
