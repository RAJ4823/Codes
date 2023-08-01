// Link: https://leetcode.com/problems/next-permutation

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: next-permutation
 *  RUNTIME: 4 ms
 *  MEMORY: 11.9 MB
 *  DATE: 8-1-2023, 10:25:54 AM
 *
 */

// Solution:

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
