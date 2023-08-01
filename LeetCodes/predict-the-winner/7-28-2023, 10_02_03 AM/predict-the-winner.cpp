// Link: https://leetcode.com/problems/predict-the-winner

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: predict-the-winner
 *  RUNTIME: 0 ms
 *  MEMORY: 7.3 MB
 *  DATE: 7-28-2023, 10:02:03 AM
 *
 */

// Solution:

class Solution {
public:
    int dp[21][21];
    int find(int i, int j, vector<int> &nums) {
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(nums[i] - find(i+1, j, nums), nums[j] - find(i, j-1, nums));
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return (find(0, nums.size()-1, nums) >= 0);
    }
};
