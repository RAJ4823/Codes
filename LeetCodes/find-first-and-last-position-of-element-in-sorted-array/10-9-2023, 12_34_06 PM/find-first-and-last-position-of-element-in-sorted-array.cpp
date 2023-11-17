// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-first-and-last-position-of-element-in-sorted-array
 *  RUNTIME: 11 ms
 *  MEMORY: 14 MB
 *  DATE: 10-9-2023, 12:34:06 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), target)- nums.begin();
        if(first == nums.size() || nums[first] != target)
            return {-1, -1};
        return {first, last - 1};
    }
};
