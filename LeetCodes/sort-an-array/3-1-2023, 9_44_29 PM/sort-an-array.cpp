// Link: https://leetcode.com/problems/sort-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-an-array
 *  RUNTIME: 143 ms
 *  MEMORY: 61.3 MB
 *  DATE: 3-1-2023, 9:44:29 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};
