// Link: https://leetcode.com/problems/longest-increasing-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-increasing-subsequence
 *  RUNTIME: 673 ms
 *  MEMORY: 10.7 MB
 *  DATE: 8-13-2023, 2:32:34 PM
 *
 */

// Solution:

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(INT_MAX);
        vector<int> dp(n+1, -1), prev(n+1, -1);

        for(int i=0; i<n; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0) {
                    dp[j] = (nums[0] < nums[j]);
                }
                else if(nums[i] < nums[j]) {
                    dp[j] = max(1 + prev[i], prev[j]);
                } else {
                    dp[j] = prev[j];
                }
            }
            prev = dp;
        }
        return dp[n];
    }
};
