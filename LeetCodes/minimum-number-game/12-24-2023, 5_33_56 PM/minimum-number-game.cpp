// Link: https://leetcode.com/problems/minimum-number-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-game
 *  RUNTIME: 13 ms
 *  MEMORY: 24.2 MB
 *  DATE: 12-24-2023, 5:33:56 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i+=2) {
            swap(nums[i], nums[i+1]);
        }
        return nums;
    }
};
