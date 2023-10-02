// Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-hills-and-valleys-in-an-array
 *  RUNTIME: 5 ms
 *  MEMORY: 9.5 MB
 *  DATE: 9-29-2023, 10:11:40 AM
 *
 */

// Solution:

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0, curr = 1, prev = 0;

        while(curr < nums.size() - 1) {
            if((nums[prev] < nums[curr] && nums[curr] > nums[curr+1]) ||
            (nums[prev] > nums[curr] && nums[curr] < nums[curr+1])) {
                count++;
                prev = curr;
            }
            curr++;
        }          
        return count;
    }
};
