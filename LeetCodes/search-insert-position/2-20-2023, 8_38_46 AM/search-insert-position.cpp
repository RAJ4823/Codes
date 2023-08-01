// Link: https://leetcode.com/problems/search-insert-position

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: search-insert-position
 *  RUNTIME: 5 ms
 *  MEMORY: 9.7 MB
 *  DATE: 2-20-2023, 8:38:46 AM
 *
 */

// Solution:

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return index;
    }
};
