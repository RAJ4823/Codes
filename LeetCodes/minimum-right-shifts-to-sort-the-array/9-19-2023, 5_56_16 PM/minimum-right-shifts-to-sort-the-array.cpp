// Link: https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-right-shifts-to-sort-the-array
 *  RUNTIME: 4 ms
 *  MEMORY: 23.1 MB
 *  DATE: 9-19-2023, 5:56:16 PM
 *
 */

// Solution:

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] > nums[i]) {
                if(index == -1) {
                    index = i-1;
                } else {
                    return -1;
                }
            }
            if(index != -1 && nums[i] > nums[0]) {
                return -1;
            }
        }
        if(index == -1) return 0;
        return n - index - 1;
    }
};
