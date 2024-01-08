// Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-difficulty-of-a-job-schedule
 *  RUNTIME: 21 ms
 *  MEMORY: 11.9 MB
 *  DATE: 12-29-2023, 9:02:43 PM
 *
 */

// Solution:

class Solution {
public:
    int dp[301][301][11];

    int f(int ind, int prev, int d, vector<int>& nums) {
        if(d == 0) return 1e9;
        if(ind >= nums.size()) return d == 1 ? nums[prev] : 1e9;
        if(dp[ind][prev][d] != -1) return dp[ind][prev][d];
        int carry = f(ind+1, nums[ind] > nums[prev] ? ind : prev, d, nums);
        int finish = nums[prev] + f(ind+1, ind, d-1, nums); 
        return dp[ind][prev][d] = min(carry, finish);
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        memset(dp, -1, sizeof(dp));
        return f(1, 0, d, jobDifficulty);
    }
};
