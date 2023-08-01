// Link: https://leetcode.com/problems/predict-the-winner

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: predict-the-winner
 *  RUNTIME: 134 ms
 *  MEMORY: 7.4 MB
 *  DATE: 7-28-2023, 9:45:35 AM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, int j, vector<int> &nums) {
        if(i > j)  return 0;
        if(i == j) return nums[i];

        int take_first = nums[i] - find(i+1, j, nums);
        int take_last  = nums[j] - find(i, j-1, nums);
        return max(take_first, take_last);
    }
    bool PredictTheWinner(vector<int>& nums) {
        return (find(0, nums.size()-1, nums) >= 0);
    }
};
