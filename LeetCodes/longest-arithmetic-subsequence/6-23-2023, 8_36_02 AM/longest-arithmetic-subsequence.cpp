// Link: https://leetcode.com/problems/longest-arithmetic-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-arithmetic-subsequence
 *  RUNTIME: 2981 ms
 *  MEMORY: 416.2 MB
 *  DATE: 6-23-2023, 8:36:02 AM
 *
 */

// Solution:

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<unordered_map<int,int>> dp(n);

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j][diff] + 1;
                ans = max(ans, dp[i][diff] + 1);
            }
        }

        return ans;
    }
};
