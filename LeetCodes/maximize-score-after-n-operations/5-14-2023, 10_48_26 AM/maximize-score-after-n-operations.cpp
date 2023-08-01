// Link: https://leetcode.com/problems/maximize-score-after-n-operations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximize-score-after-n-operations
 *  RUNTIME: 237 ms
 *  MEMORY: 13.7 MB
 *  DATE: 5-14-2023, 10:48:26 AM
 *
 */

// Solution:

class Solution {
public:
    int n, max_ops;
    int find(int ops, int mask, vector<int> &nums, vector<int> &dp) {
        if(ops > max_ops) return 0;
        if(dp[mask] != -1) return dp[mask];

        int maxScore = 0;
        for(int i=0; i<n; i++) {
            if(mask & (1<<i)) continue;
            for(int j=i+1; j<n; j++) {
                if(mask & (1<<j)) continue;

                int newMask = (1<<i) | (1<<j) | mask;
                int score = ops * __gcd(nums[i], nums[j]) + find(ops + 1, newMask, nums, dp);
                maxScore = max(maxScore, score);
            }
        }
        return dp[mask] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<14, -1);
        n = nums.size();
        max_ops = n/2;

        return find(1, 0, nums, dp);
    }
};

