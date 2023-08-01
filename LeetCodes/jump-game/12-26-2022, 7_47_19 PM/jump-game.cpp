// Link: https://leetcode.com/problems/jump-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: jump-game
 *  RUNTIME: 89 ms
 *  MEMORY: 48.4 MB
 *  DATE: 12-26-2022, 7:47:19 PM
 *
 */

// Solution:

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0, i = 0;
        while(i < nums.size() && i <= maxi) {
            maxi = max(i + nums[i], maxi);
            i++;
        }
        return (i == nums.size());
    }
};
