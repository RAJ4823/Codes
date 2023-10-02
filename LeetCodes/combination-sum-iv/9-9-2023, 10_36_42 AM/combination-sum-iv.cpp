// Link: https://leetcode.com/problems/combination-sum-iv

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: combination-sum-iv
 *  RUNTIME: 2 ms
 *  MEMORY: 6.8 MB
 *  DATE: 9-9-2023, 10:36:42 AM
 *
 */

// Solution:

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<__int128> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int val = 1; val <= target; ++val) {
            for (int &num : nums) {
                if (val - num >= 0) {
                    dp[val] += dp[val - num];
                }
            } 
        }
        
        return dp[target];
    }
};
