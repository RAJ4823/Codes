// Link: https://leetcode.com/problems/predict-the-winner

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: predict-the-winner
 *  RUNTIME: 145 ms
 *  MEMORY: 7.3 MB
 *  DATE: 7-28-2023, 9:59:50 AM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, int j, vector<int> &nums) {
        if(i == j) return nums[i];
        return max(nums[i] - find(i+1, j, nums), nums[j] - find(i, j-1, nums));
    }
    bool PredictTheWinner(vector<int>& nums) {
        return (find(0, nums.size()-1, nums) >= 0);
    }
};
